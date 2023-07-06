insert into TAB1 (CIN, NOM, PRENOM)
VALUES (2223,'Oubella','Ismail');

insert into departments (department_id, department_name, manager_id, location_id)
VALUES (2223,'Public Relations',100, 1700);

 --insert a new column


Insert into departments(department_id, department_name)
VALUES (1111,'Purchasing');

or 

Insert into departments
VALUES (1111, 'Purchasing', NULL, NULL);

--Insert into NULL values


select * from departments --> show all table using '*' symbole;

    or //

select 'column name '
from 'table name';

--Show or describe the table

Insert into employees
Values (207, 'Halaand', 'Erling', 'ST', '650.508.4533', SYSDATE, 'AC_ACCOUNT', 4002, NULL, 124, 50);

--use also function TO_DATE;

-- we used the SYSDATE function is used to retrieve the current system date and time from the database server's operating system.

    113 Luis                 Popp                      LPOPP                     515.124.4567         07-DEC-07 FI_ACCOUNT       6900                       108           100


update employees 
set department_id =70
where employee_id = 113;  -- Condition statement;

    113 Luis                 Popp                      LPOPP                     515.124.4567         07-DEC-07 FI_ACCOUNT       6900                       108            70

--we use UPDATE to update the database so changing the content;

select last_name, 12*salary * commission_pct
from employees


result : 

LAST_NAME                 12*SALARY*COMMISSION_PCT
------------------------- ------------------------
OConnell                                          
Grant                                             
Whalen                                            
Hartstein                                         
Fay                                               
Mavris                                            
Baer                                              
Higgins                                           
Gietz                                             
Erling                                            
King



    --to change name and we want that " 12*SALARY*COMMISSION_PCT" appers as a tiltle we use : 

    SELECT last_name "Nom de l'employee", salary*12 "Annual Salary"
    from employees


    result : 

        Nom de "l'employee"         Annual Salary
        ------------------------- -------------
        Grant                             84000
        Johnson                           74400
        Taylor                            38400
        Fleaur                            37200
        Sullivan                          30000
        Geoni                             33600
        Sarchand                          50400
        Bull                              49200
        Dellinger                         40800
        Cabrio                            36000
        Chung                             45600

-- commission_pct == NULL the result wil be NULL;


SELECT last_name||job_id as "Employees"
from employees

result :
Employees                          
-----------------------------------
DillySH_CLERK
GatesSH_CLERK
PerkinsSH_CLERK
BellSH_CLERK
EverettSH_CLERK
McCainSH_CLERK
JonesSH_CLERK
WalshSH_CLERK
FeeneySH_CLERK

or : 

if we want to make some content or something like space we use double "||...||"
exemple : 

SELECT last_name ||' '|| job_id as "Employees"
from employees

result :

Employees                           
------------------------------------
Dilly SH_CLERK
Gates SH_CLERK
Perkins SH_CLERK
Bell SH_CLERK
Everett SH_CLERK
McCain SH_CLERK
Jones SH_CLERK
Walsh SH_CLERK
Feeney SH_CLERK


-- we use '||' pour contatiner or merge between two or more columns;

select department_id
from employees

result : 

DEPARTMENT_ID
-------------
             
           80
           50
           50
           50
           50
           50
           50
           50
           50
           50


we use distinct to  only appear one element and dont repeat the same one 

select  distinct  department_id
from employees

result :

DEPARTMENT_ID
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


--eleminer le sdoublons par distinct

where always indicates the condition in the row;

select employee_id, last_name, job_id, department_id
from employees
where department_id = 90;

result :

EMPLOYEE_ID LAST_NAME                 JOB_ID     DEPARTMENT_ID
----------- ------------------------- ---------- -------------
        100 King                      AD_PRES               90
        101 Kochhar                   AD_VP                 90
        102 De Haan                   AD_VP                 90


select employee_id, last_name, job_id, department_id
from employees
where last_name = 'King';


EMPLOYEE_ID LAST_NAME                 JOB_ID     DEPARTMENT_ID
----------- ------------------------- ---------- -------------
        100 King                      AD_PRES               90
        156 King                      SA_REP                80

select last_name, salary
from employees
WHERE salary = 3000;


LAST_NAME                     SALARY
------------------------- ----------
Cabrio                          3000
Feeney                          3000

we can use operators to search in the table : 

like -> between ... and ...

select last_name, salary
from employees
WHERE salary BETWEEN 2500 and 2800;

result


LAST_NAME                     SALARY
------------------------- ----------
OConnell                        2600
Grant                           2600
Tobias                          2800
Himuro                          2600
Colmenares                      2500
Mikkilineni                     2700
Atkinson                        2800
Marlow                          2500
Seo                             2700
Patel                           2500
Matos                           2600

LAST_NAME                     SALARY
------------------------- ----------
Vargas                          2500
Sullivan                        2500
Geoni                           2800
Perkins                         2500
Jones                           2800

like -> in (..,...,...) its like the "or " operator

select last_name, manager_id
from employees
WHERE  manager_id in (100,101,201);


LAST_NAME                 MANAGER_ID
------------------------- ----------
Whalen                           101
Hartstein                        100
Fay                              201
Mavris                           101
Baer                             101
Higgins                          101
Kochhar                          100
De Haan                          100
Greenberg                        101
Raphaely                         100
Weiss                            100

LAST_NAME                 MANAGER_ID
------------------------- ----------
Fripp                            100
Kaufling                         100
Vollman                          100
Mourgos                          100
Russell                          100
Partners                         100
Errazuriz                        100
Cambrault                        100
Zlotkey                          100

like -> like ' %' % : ignorer les autres char puisque il represente quil ya plusieurs chars; and '_' represente un char

select first_name
from employees
WHERE  first_name like 'S%';



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

FIRST_NAME          
--------------------
Sarah
Samuel


select last_name
from employees
WHERE  last_name like '_o%';


LAST_NAME                
-------------------------
Kochhar
Lorentz
Popp
Tobias
Colmenares
Vollman
Mourgos
Rogers
Doran
Fox
Johnson

LAST_NAME                
-------------------------
Jones





--we use where to locate in the rows;

