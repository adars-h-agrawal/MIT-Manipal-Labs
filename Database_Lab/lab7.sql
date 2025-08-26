-- LAB 7: TRIGGERS & ANALYTICAL QUERIES ON ACCIDENT DATABASE

-- ====================================
-- 1. Trigger: Display driver info upon accident participation
-- ====================================

CREATE OR REPLACE TRIGGER trg_show_driver_info
AFTER INSERT ON PARTICIPATED
FOR EACH ROW
DECLARE
    v_name PERSON.name%TYPE;
    v_address PERSON.address%TYPE;
BEGIN
    SELECT name, address INTO v_name, v_address
    FROM PERSON
    WHERE driver_id = :NEW.driver_id;

    DBMS_OUTPUT.PUT_LINE('Driver participated in accident:');
    DBMS_OUTPUT.PUT_LINE('Driver ID: ' || :NEW.driver_id);
    DBMS_OUTPUT.PUT_LINE('Name: ' || v_name);
    DBMS_OUTPUT.PUT_LINE('Address: ' || v_address);
END;
/

-- Test:
-- INSERT INTO PARTICIPATED(driver_id, regno, report_number, damage_amount) VALUES ('1234', 'abc123', 12, 10000);

-- ====================================
-- 2. Trigger: Update total_damage in ACCIDENT table on PARTICIPATED change
-- ====================================

-- First, ensure ACCIDENT table has a total_damage column
ALTER TABLE ACCIDENT ADD (total_damage INT DEFAULT 0);

-- Trigger for INSERT
CREATE OR REPLACE TRIGGER trg_update_damage_insert
AFTER INSERT ON PARTICIPATED
FOR EACH ROW
BEGIN
    UPDATE ACCIDENT
    SET total_damage = total_damage + :NEW.damage_amount
    WHERE report_number = :NEW.report_number;
END;
/

-- Trigger for DELETE
CREATE OR REPLACE TRIGGER trg_update_damage_delete
AFTER DELETE ON PARTICIPATED
FOR EACH ROW
BEGIN
    UPDATE ACCIDENT
    SET total_damage = total_damage - :OLD.damage_amount
    WHERE report_number = :OLD.report_number;
END;
/

-- ====================================
-- 3. List cars involved in accidents with cumulative damage exceeding a specific amount (e.g. 20,000)
-- ====================================

SELECT regno, SUM(damage_amount) AS total_damage
FROM PARTICIPATED
GROUP BY regno
HAVING SUM(damage_amount) > 20000;

-- ====================================
-- 4. Identify cars involved in more than one accident and calculate total damage
-- ====================================

SELECT regno, COUNT(report_number) AS num_accidents, SUM(damage_amount) AS total_damage
FROM PARTICIPATED
GROUP BY regno
HAVING COUNT(report_number) > 1;

-- ====================================
-- 5. Calculate average damage per accident at each location
-- ====================================

SELECT a.location, ROUND(AVG(p.damage_amount), 2) AS avg_damage
FROM ACCIDENT a
JOIN PARTICIPATED p ON a.report_number = p.report_number
GROUP BY a.location;