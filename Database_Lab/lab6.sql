-- LAB 6: PROCEDURES AND FUNCTIONS FOR ACCIDENT DATABASE

-- ====================================
-- 1. Function to return total number of accidents in a particular year
-- ====================================

CREATE OR REPLACE FUNCTION get_total_accidents_by_year(p_year INT)
RETURN INT
IS
    total_accidents INT;
BEGIN
    SELECT COUNT(*) INTO total_accidents
    FROM ACCIDENT
    WHERE EXTRACT(YEAR FROM accd_date) = p_year;

    RETURN total_accidents;
END;
/

-- Example usage:
-- SELECT get_total_accidents_by_year(2020) FROM dual;

-- ====================================
-- 2. Procedure to display total damage for a driver in a specific year
-- ====================================

CREATE OR REPLACE PROCEDURE show_total_damage_by_driver_year (
    p_driver_id IN VARCHAR,
    p_year IN INT
)
IS
    total_damage INT;
BEGIN
    SELECT NVL(SUM(p.damage_amount), 0) INTO total_damage
    FROM PARTICIPATED p
    JOIN ACCIDENT a ON p.report_number = a.report_number
    WHERE p.driver_id = p_driver_id AND EXTRACT(YEAR FROM a.accd_date) = p_year;

    DBMS_OUTPUT.PUT_LINE('Total damage for driver ' || p_driver_id || ' in year ' || p_year || ' is: ' || total_damage);
END;
/

-- Example usage:
-- BEGIN show_total_damage_by_driver_year('1234', 2020); END;

-- ====================================
-- 3. Procedure to display accident info in a specific location
-- ====================================

CREATE OR REPLACE PROCEDURE show_accidents_by_location (
    p_location IN VARCHAR
)
IS
BEGIN
    FOR rec IN (
        SELECT * FROM ACCIDENT WHERE LOWER(location) = LOWER(p_location)
    )
    LOOP
        DBMS_OUTPUT.PUT_LINE('Report #: ' || rec.report_number || ', Date: ' || rec.accd_date || ', Location: ' || rec.location);
    END LOOP;
END;
/

-- Example usage:
-- BEGIN show_accidents_by_location('westroad'); END;

-- ====================================
-- 4. Procedure to display all drivers never involved in any accidents
-- ====================================

CREATE OR REPLACE PROCEDURE show_drivers_without_accidents
IS
BEGIN
    FOR rec IN (
        SELECT driver_id, name, address 
        FROM PERSON 
        WHERE driver_id NOT IN (SELECT DISTINCT driver_id FROM PARTICIPATED)
    )
    LOOP
        DBMS_OUTPUT.PUT_LINE('Driver ID: ' || rec.driver_id || ', Name: ' || rec.name || ', Address: ' || rec.address);
    END LOOP;
END;
/

-- Example usage:
-- BEGIN show_drivers_without_accidents; END;

-- ====================================
-- 5. Function to return total number of accidents involving a car (by regno)
-- ====================================

CREATE OR REPLACE FUNCTION get_accident_count_by_car (
    p_regno IN VARCHAR
)
RETURN INT
IS
    total_accidents INT;
BEGIN
    SELECT COUNT(*) INTO total_accidents
    FROM PARTICIPATED
    WHERE regno = p_regno;

    RETURN total_accidents;
END;
/

-- Example usage:
-- SELECT get_accident_count_by_car('abc123') FROM dual;
