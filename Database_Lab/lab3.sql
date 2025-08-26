-- LAB 3: Accident Database Management

-- ====================================
-- i) CREATE TABLES
-- ====================================

CREATE TABLE PERSON (
    driver_id VARCHAR(30) PRIMARY KEY,
    name VARCHAR(50),
    address VARCHAR(100)
);

CREATE TABLE CAR (
    regno VARCHAR(20) PRIMARY KEY,
    model VARCHAR(30),
    Year INT
);

CREATE TABLE ACCIDENT (
    report_number INT PRIMARY KEY,
    accd_date DATE,
    location VARCHAR(50)
);

CREATE TABLE OWNS (
    driver_id VARCHAR(30),
    regno VARCHAR(20)
);

CREATE TABLE PARTICIPATED (
    driver_id VARCHAR(30) PRIMARY KEY,
    regno VARCHAR(20),
    report_number INT,
    damage_amount INT,
    FOREIGN KEY (regno) REFERENCES PERSON(driver_id),
    FOREIGN KEY (report_number) REFERENCES ACCIDENT(report_number)
);

-- ====================================
-- ii) INSERT VALUES
-- ====================================

-- Inserting into PERSON
INSERT INTO PERSON(driver_id, name, address) VALUES 
('1234', 'chirag', '35 hometown'),
('1235', 'devansh', '67 eastnagar'),
('1236', 'vedant', '12 saltlake'),
('1237', 'shaket', '100 bangur'),
('1238', 'debadrit', '15 dumdum');

-- Inserting into CAR
INSERT INTO CAR(regno, model, Year) VALUES 
('abc123', 'S', 2020),
('def450', 'A', 2021),
('xyz345', 'D', 2018),
('ijklmno1', 'B', 2019),
('qwerty', 'Z', 2024);

-- Inserting into ACCIDENT
INSERT INTO ACCIDENT(report_number, accd_date, location) VALUES 
(12, TO_DATE('2020-10-25','YYYY-MM-DD'), 'parkstreet'),
(24, TO_DATE('2020-10-31','YYYY-MM-DD'), 'westroad'),
(1, TO_DATE('2019-06-12','YYYY-MM-DD'), 'westroad'),
(109, TO_DATE('2023-01-15','YYYY-MM-DD'), 'westroad'),
(110, TO_DATE('2023-01-16','YYYY-MM-DD'), 'westroad');

-- Inserting into OWNS
INSERT INTO OWNS(driver_id, regno) VALUES 
('1234', 'abc123'),
('1235', 'def450'),
('1236', 'xyz345'),
('1237', 'ijklmno1'),
('1238', 'qwerty');

-- Inserting into PARTICIPATED
INSERT INTO PARTICIPATED(driver_id, regno, report_number, damage_amount) VALUES 
('1234', 'abc123', 12, 21000),
('1235', 'def450', 24, 18000),
('1236', 'xyz345', 1, 189000),
('1237', 'ijklmno1', 109, 5000),
('1238', 'qwerty', 110, 11000);

-- ====================================
-- iii) UPDATE
-- ====================================

UPDATE PARTICIPATED 
SET damage_amount = 25000 
WHERE report_number = 12;

-- ====================================
-- iv) DELETE
-- ====================================

DELETE FROM PARTICIPATED 
WHERE report_number = (
    SELECT report_number 
    FROM ACCIDENT 
    WHERE EXTRACT(YEAR FROM accd_date) = '2018'
);

DELETE FROM ACCIDENT 
WHERE EXTRACT(YEAR FROM accd_date) = '2018';

-- ====================================
-- v) ALTER TABLE
-- ====================================

ALTER TABLE PERSON ADD age INT;
ALTER TABLE PERSON ADD gender VARCHAR(10); -- assumed datatype
ALTER TABLE PERSON DROP COLUMN gender;

-- ====================================
-- vi) ADD CONSTRAINT
-- ====================================

ALTER TABLE PARTICIPATED 
ADD CONSTRAINT chk_damage CHECK (damage_amount > 0);
