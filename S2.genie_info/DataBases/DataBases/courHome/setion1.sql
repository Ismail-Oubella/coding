select *
from employees
-- This statement is often used to view all the data in a table. When executed, it will return a result set that contains all the rows and columns of data from the "employees" table.

select department_id, location_id
from departments

--  selcts only rows indecated in the select order

select first_name, last_name, salary/2 half  
from employees

-- also we can create temperary heads for arithmetic operations and instesd of showing the operation in the title we can change the name by add it in front of it

select last_name, job_id, salary, commission_pct
from employees

-- comission_pct in this example has the null value that is defferent than the 0 and the empty char

select last_name, job_id, salary, commission_pct*12
from employees

-- any operation arithmetic with the null value will return the null like in this example


                            --? Alias :

-- we use the alias to rename the head of the cellule, and it is really useful in the case of operation arithmetic instead of writing the ugly mathematic expression we can give it a nice name that give it sence 

select last_name as name, commission_pct comm
from employees

--!

select last_name as "Name", salary*12 "Annual Salary"
from employees

-- like in this ex we use the AS keyword to rename the column

                            --? Concatination 
-- concate columns with each other specialy in the case of a last name with the first name , it make sense to represent them in one column instead of two


select last_name||first_name as "Employees"
from employees

    --*Result!

Employees                                    
---------------------------------------------
GrantKimberely

-- if we want just to concate without anything between them we use this expression

select last_name||' '||first_name as "Employees"
from employees

    --*Result!

Employees                                     
----------------------------------------------
Grant Kimberely

-- so we use double || and inside it , or inside the double quotes we enter the text or separator between the two data of the concatinited columns

                            --? Duplicated rows 

-- how to eliminate the duplicated rows 

select distinct department_id
from employees

    --*Result!

DEPARTMENT_ID
-------------
             
80
50
50
50
50

--!

select distinct department_id
from employees

    --*Result!

EPARTMENT_ID
-------------
50
10
20
40
70
110
90
60
100
30
80

-- You can use the DISTINCT keyword with a SELECT statement to eliminate duplicate rows from the result set

describe employees

    --*Result!

Name           Null?    Type         
-------------- -------- ------------ 
EMPLOYEE_ID    NOT NULL NUMBER(6)    
FIRST_NAME              VARCHAR2(20) 
LAST_NAME      NOT NULL VARCHAR2(25) 
EMAIL          NOT NULL VARCHAR2(25) 
PHONE_NUMBER            VARCHAR2(20) 
HIRE_DATE      NOT NULL DATE         
JOB_ID         NOT NULL VARCHAR2(10) 
SALARY                  NUMBER(8,2)  
COMMISSION_PCT          NUMBER(2,2)  
MANAGER_ID              NUMBER(6)    
DEPARTMENT_ID           NUMBER(4)    


--the keyword Describe is used to discribe  a table

--*Summary:
        --*returns all rows and columns from a table
        --*returns specific columns from a table
        --*uses column aliases as descriptive column headers