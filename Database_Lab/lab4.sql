-- LAB 4: Advanced SQL Queries on Accident Database

-- ====================================
-- Q1. Find the total number of people who owned cars that were involved in accidents in 2008.
-- ====================================

SELECT COUNT(DISTINCT PARTICIPATED.driver_id) AS total_people
FROM ACCIDENT, PARTICIPATED
WHERE ACCIDENT.report_number = PARTICIPATED.report_number
  AND EXTRACT(YEAR FROM accd_date) = '2008';

-- ====================================
-- Q2. Find the number of accidents in which cars belonging to a specific model were involved.
-- (Example model: 'Hyundai Creta')
-- ====================================

SELECT COUNT(PARTICIPATED.regno) AS total_accidents
FROM PARTICIPATED, CAR
WHERE PARTICIPATED.regno = CAR.regno
  AND CAR.model = 'Hyundai Creta';

-- ====================================
-- Q3. Produce a listing with header as OWNER_NAME, No. of Accidents, and Total Damage Amount
--     in descending order of total damage.
-- ====================================

SELECT 
    PERSON.name AS OWNER_NAME,
    COUNT(PARTICIPATED.report_number) AS NO_OF_ACCIDENT,
    SUM(PARTICIPATED.damage_amount) AS TOTAL_DAMAGE
FROM PARTICIPATED, PERSON
WHERE PERSON.driver_id = PARTICIPATED.driver_id
GROUP BY PERSON.driver_id, PERSON.name
ORDER BY TOTAL_DAMAGE DESC;

-- ====================================
-- Q4. List the owners who made more than 2 accidents in a year.
-- ====================================

SELECT NAME
FROM PERSON
WHERE DRIVER_ID IN (
    SELECT DRIVER_ID
    FROM PARTICIPATED
    GROUP BY DRIVER_ID
    HAVING COUNT(DRIVER_ID) > 2
);

-- ====================================
-- Q5. List the owners who are not involved in any accident.
-- ====================================

SELECT PERSON.name
FROM PERSON
MINUS
SELECT DISTINCT PERSON.name
FROM PERSON, PARTICIPATED
WHERE PERSON.driver_id = PARTICIPATED.driver_id;
