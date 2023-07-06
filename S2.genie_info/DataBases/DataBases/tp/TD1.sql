--! 1 = last names wher salary > 10000
    select last_name ,salary
    from employees
    where salary > 10000;

--! 2 = Date d'embauche entre 
    SELECT last_name, hire_date
    FROM employees
    WHERE hire_date BETWEEN '17-FEB-97' AND '30-OCT-97';

--! 3 = Starting by letter 'J'

select last_name
from employees
WHERE  last_name like 'J%';

--! 4 = have letter 'a' twice

select last_name
from employees
WHERE  last_name like '%a%a%';

-- * only 2

SELECT last_name
FROM employees
WHERE REGEXP_LIKE(last_name, '^([^a]*a){2}[^a]*$');

--! 5 = names where nbr de chef est 114

    select last_name
    from employees
    where manager_id = 114;

--! 6 = names of services where nbr de chef est 114 or doooon't have  chef

    select last_name ,  manager_id
    from employees
    where manager_id = 114 or manager_id is null;

--! 7 = names of job_id that aren't in seatlle

    select last_name ,  job_id
    from employees
    where job_id != 'SA_REP';
