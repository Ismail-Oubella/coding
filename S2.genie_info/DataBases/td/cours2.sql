CREATE TABLE new_employees (
    employee_id NUMBER,
    first_name varchar2(15),
    last_name varchar2(15),
    start_date TIMESTAMP (7),     -- date => par defaut 6 dd-MM-yyyy HH.mm.ss AM/PM
    
);

-- ALTER TABLE permet do modifier sur l'objet table "ADD,MODIFY,DROP"

-- DESCRIBE COMMAND TO DESCRIBE TABLE;

ALTER TABLE new_employees 
    ADD job_id varchar2(9);     --  add a colon to table;



ALTER TABLE new_employees 
MODIFY (last_name varchar2(30));  --modify size to 30

 ALTER TABLE new_employees
 DROP COLUMN job_id;  --delete column "job_id"; 


-- SET UNUSED  i dont know but search about

DROP TABLE new_employees --delete table;

ALTER RENAME dept TO detail_dept; --Rename my table

TRUNCATE TABLE detail_dept; --vider table;

COMMENT ON TABLE detail_dept
IS 'dlkdjlkdjlkd'  ; --ADD comments;


CONSTRAINT => W3SCHOOL CASCADE CONSTRAINT

--Ajouter une contrainte;

ALTER TABLE employees 
ADD CONSTRAINT emp_manager_fk 
FOREIGN KEY (manager_id)
REFERENCES employees (employee_id);


