    --?  -Q1

select last_name, salary
from employees
where salary > 10000 ;

    --?  -Q2

select last_name, HIRE_DATE  
from employees
where  HIRE_DATE >  '17-FEB-97' AND 
        hire_date < '30-OCT-97'

--* No row selected

    --?  -Q3

select last_name
from employees
where last_name like 'J%' ;

    --? -Q4

select last_name
from employees
where last_name like '%a%a%'

    --? -Q5

select first_name, last_name, manager_id 
from employees
where manager_id = 114

    --? -Q6

select last_name, first_name, job_id, manager_id 
from employees
where manager_id = 114 or manager_id is NULL ; 
    
    --?  -Q7


