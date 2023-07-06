                            --? Lign limitation 
 
-- we use the Where keyword to filter the rows returned or affected by the query.

select employee_id, last_name, job_id, department_id
from employees
where department_id = 90

    --*Result!

EMPLOYEE_ID LAST_NAME                 JOB_ID     DEPARTMENT_ID
----------- ------------------------- ---------- -------------
        100 King                      AD_PRES               90
        101 Kochhar                   AD_VP                 90
        102 De Haan                   AD_VP                 90

-- the where keyword was used to filter all the rows that doesn't have a department id equal to 90

SELECT column1, column2, ... FROM table_name WHERE date_column >= '01-Jan-22';

-- dates and strings must be between double quotes and the default format of date is DD-MON-YY => '08-Apr-23'

                            --? Some KeyWords Used To Compare
    --* Between...And

select last_name, salary
from employees
where salary between 2500 and 3500

    --*Result!

LAST_NAME                     SALARY
------------------------- ----------
Fleaur                          3100
Sullivan                        2500
Geoni                           2800
Dellinger                       3400
Cabrio                          3000
Gates                           2900
Perkins                         2500
McCain                          3200
Jones                           2800
Walsh                           3100
Feeney                          3000

33 rows selected. 

-- the BETWEEN...AND operator is used to filter rows based on a range of values for a column.

    --* IN

select employee_id, last_name, salary, manager_id
from employees
where manager_id in(100)

    --*Result!

EMPLOYEE_ID LAST_NAME                     SALARY MANAGER_ID
----------- ------------------------- ---------- ----------
        147 Errazuriz                      12000        100
        148 Cambrault                      11000        100
        149 Zlotkey                        10500        100

14 rows selected. 

--!

select employee_id, last_name, salary, manager_id
from employees
where manager_id in(100, 201)

    --*Result!

EMPLOYEE_ID LAST_NAME                     SALARY MANAGER_ID
----------- ------------------------- ---------- ----------
        201 Hartstein                      13000        100
        202 Fay                             6000        201

--he IN operator is used to filter rows based on a list of values for a column.

    --* LIKE

select first_name
from employees
where first_name like 'S%'

    --*Result!

FIRST_NAME          
--------------------
Susan
Shelley
Steven
Shelli
Sigal
Shanta
Steven
Stephen
Sarath
Sundar
Sundita

--!

select first_name
from employees
where first_name like 'S_s__'

    --*Result!


FIRST_NAME          
--------------------
Susan


-- the LIKE operator is used to filter rows based on a pattern of characters in a column.
-- The % sign matches any string of zero or more characters, while the underscore (_) matches any single character
--Note : we use the sigle quotes wihle using the strings 

    --* IS NULL/ IS NOT NULL

SELECT last_name, manager_id
from employees
where manager_id is null

    --*Result!

LAST_NAME                 MANAGER_ID
------------------------- ----------
King                                


-- The IS NULL operator is used to find rows where the value in a specific column is NULL
-- the IS NOT NULL operator is used to find rows where the value in a specific column is not NULL


                            --? Logical Operators

    --* AND

select employee_id, last_name, job_id, salary
from employees
where salary >= 10000
and job_id like '%MAN%'

    --*Result!

EMPLOYEE_ID LAST_NAME                 JOB_ID         SALARY
----------- ------------------------- ---------- ----------
        201 Hartstein                 MK_MAN          13000
        114 Raphaely                  PU_MAN          11000
        145 Russell                   SA_MAN          14000
        146 Partners                  SA_MAN          13500
        147 Errazuriz                 SA_MAN          12000
        148 Cambrault                 SA_MAN          11000
        149 Zlotkey                   SA_MAN          10500

7 rows selected

-- This operator is used to combine two or more conditions where all the conditions must be true to select a row

    --* OR

select employee_id, last_name, job_id, salary
from employees
where salary >= 10000
OR job_id like '%MAN%'
   
    --*Result!

EMPLOYEE_ID LAST_NAME                 JOB_ID         SALARY
----------- ------------------------- ---------- ----------
        201 Hartstein                 MK_MAN          13000
        204 Baer                      PR_REP          10000
        205 Higgins                   AC_MGR          12008
        100 King                      AD_PRES         24000
        101 Kochhar                   AD_VP           17000
        102 De Haan                   AD_VP           17000
        108 Greenberg                 FI_MGR          12008
        114 Raphaely                  PU_MAN          11000
        120 Weiss                     ST_MAN           8000
        121 Fripp                     ST_MAN           8200

-- This operator is used to combine two or more conditions where at least one condition must be true to select a row 
    
    --* NOT

SELECT * FROM students WHERE NOT age > 18;

--!

select last_name, job_id
from employees
where job_id not in ('IT_PROG', 'ST_CLERK', 'SA_REP')

    --*Result!


LAST_NAME                 JOB_ID    
------------------------- ----------
Baida                     PU_CLERK  
Baida                     PU_CLERK  
Cambrault                 SA_MAN    
Taylor                    SH_CLERK  
...

--This operator is used to negate a condition.
    
                            --? the order of priority

    /*
        1-Parentheses: Expressions within parentheses are evaluated first.
        2-Multiplication, division, and modulus: These operators are evaluated next, from left to right.
        3-Addition and subtraction: These operators are evaluated next, from left to right.
        4-Comparison operators: These operators are evaluated next, from left to right. Examples include =, !=, >, <, >=, and <=.
        5-IS [NOT] NULL, LIKE, [NOT] IN
        6-[NOT] BETWEEN
        7-NOT
        8-AND
        9-OR
    */

select last_name, job_id, salary
from employees
where job_id = 'SA_REP' or job_id = 'AD_PRES'
and salary > 15000

--> because the priority of and on or the condition was converted to : 
    where job_id = 'SA_REP' 
    or
    job_id = 'AD_PRESS' and salary = 15000
    
    --*Result!
   
LAST_NAME                 JOB_ID         SALARY
------------------------- ---------- ----------
King                      AD_PRES         24000 

Smith                     SA_REP           7400
Bates                     SA_REP           7300
Kumar                     SA_REP           6100
Abel                      SA_REP          11000
Hutton                    SA_REP           8800
Taylor                    SA_REP           8600
Livingston                SA_REP           8400
Grant                     SA_REP           7000
Johnson                   SA_REP           6200

31 rows selected. 

--!

select last_name, job_id, salary
from employees
where (job_id = 'SA_REP'
or job_id = 'AD_PRES')
and salary > 15000

    --*Result!

LAST_NAME                 JOB_ID         SALARY
------------------------- ---------- ----------
King                      AD_PRES         24000 --> this was the only output;

   
-- so to fix the problem of prioroty we use the power of parentheses
   
   
                            --? Sorting

    --* ORDER BY

   
--Sort rows using the ORDER BY clause.

select last_name, job_id, department_id, hire_date
from employees
order by hire_date

    --*Result!

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Zlotkey                   SA_MAN                80 29-JAN-08
Geoni                     SH_CLERK              50 03-FEB-08
Philtanker                ST_CLERK              50 06-FEB-08
Lee                       SA_REP                80 23-FEB-08
Markle                    ST_CLERK              50 08-MAR-08
Ande                      SA_REP                80 24-MAR-08
Banda                     SA_REP                80 21-APR-08
Kumar                     SA_REP                80 21-APR-08
Erling                    AC_ACCOUNT            50 28-FEB-23

--! Compare between the two results;

select last_name, job_id, department_id, hire_date
from employees
order by hire_date desc

    --*Result!


LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Erling                    AC_ACCOUNT            50 28-FEB-23
Banda                     SA_REP                80 21-APR-08
Kumar                     SA_REP                80 21-APR-08
Ande                      SA_REP                80 24-MAR-08
Markle                    ST_CLERK              50 08-MAR-08
Lee                       SA_REP                80 23-FEB-08
Philtanker                ST_CLERK              50 06-FEB-08
Geoni                     SH_CLERK              50 03-FEB-08
Zlotkey                   SA_MAN                80 29-JAN-08

--ASC: ascending order (default) 
--DESC: descending order

select employee_id, last_name, salary*12 as annsal
from employees
order by annsal

    --*Result!

EMPLOYEE_ID LAST_NAME                     ANNSAL
----------- ------------------------- ----------
        147 Errazuriz                     144000
        205 Higgins                       144096
        108 Greenberg                     144096
        201 Hartstein                     156000
        146 Partners                      162000
        145 Russell                       168000
        102 De Haan                       204000
        101 Kochhar                       204000
        100 King                          288000

--!

select last_name, department_id, salary
from employees
order by department_id, salary desc

    --*Result!


LAST_NAME                 DEPARTMENT_ID     SALARY
------------------------- ------------- ----------
Bates                                80       7300
Marvins                              80       7200
Tuvault                              80       7000
Sewall                               80       7000
Lee                                  80       6800
Ande                                 80       6400
Johnson                              80       6200
Banda                                80       6200
Kumar                                80       6100
King                                 90      24000
De Haan                              90      17000


--We can also sort by alias like in this example, or multiple

--*Summary:
        --*Use the WHERE clause to limit the number of result rows:
            --*Use comparison conditions
            --*Use BETWEEN, IN, LIKE, and NULL conditions
            --*Apply logical operators AND, OR, and NOT
        --*Use the ORDER BY clause to sort the result rows.




