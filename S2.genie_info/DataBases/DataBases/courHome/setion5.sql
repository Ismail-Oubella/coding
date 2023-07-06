                               --? Grouping Functions

        /*
            --!GOUPING STRUCTURE

            SELECT clumn, group_function(column)
            from table
            [where condition]
            [GROUP BY group_by_expression]
            [HAVING group_condition]
            [ORDER BY clumn]
        */


    /*
        --*COUNT -> returns the number of rows that match a specified condition.
            -COUNT(*) ->counts the total number of rows in a table, regardless 
                        of whether there are any NULL values in the columns. 
                        It counts each row as long as it is not NULL.

            -COUNT(EXP)->counts the number of non-NULL values in a particular 
                        column or expression. It only counts rows where the specified column or 
                        expression is not NULL.
        --*SUM() -> calculates the sum of a specified column.
        --*AVG() -> calculates the average of a specified column, but it had an issue if there 
                    is null values it egnore them but it this affects on the calcul so we 
                    have to use the nvl function to replace every null value to 0 for 
                    example 
        --*MAX() -> returns the maximum value in a specified column.
        --*MIN() -> returns the minimum value in a specified column.

    */
select  
    avg(salary) as average, max(salary) as maximum, min(salary) as minimum, sum(salary) as summ
from employees
where job_id like '%REP%'
    
    --*Result!
    

   AVERAGE    MAXIMUM    MINIMUM       SUMM
---------- ---------- ---------- ----------
8272.72727      11500       6000     273000

--!

select min(hire_date), max(hire_date)
from employees
    
    --*Result!
    
MIN(HIRE_ MAX(HIRE_
--------- ---------
13-JAN-01 28-FEB-23


--!

select count(*)
from employees
where department_id = 50

    --*Result!    

  COUNT(*)
----------
        46

--!

select count(commission_pct)
from employees
where department_id = 80

    --*Result!

COUNT(COMMISSION_PCT)
---------------------
                   34
    
--!

select count(distinct department_id) from employees

    --*Result!

COUNT(DISTINCTDEPARTMENT_ID)
----------------------------
                          11

--!

select avg(nvl(commission_pct, 0))/avg(commission_pct)
from employees

    --*Result!    


AVG(NVL(COMMISSION_PCT,0))
--------------------------
               .0722222222


AVG(COMMISSION_PCT)
-------------------
         .222857143


    --*Group by
select department_id, max(salary)
from employees
group by department_id
 
    --*Result!

DEPARTMENT_ID MAX(SALARY)
------------- -----------
           50        8200
           10        4400
           20       13000
           40        6500
           70       10000
          110       12008
           90       24000
           60        9000
          100       12008
           30       11000
           80       14000

DEPARTMENT_ID MAX(SALARY)
------------- -----------
                     7000

/*
    is used to group together rows that share the same values in one or more columns. 
    This is often used in combination with an aggregate function, such as SUM, AVG, 
    COUNT, MAX or MIN, to calculate summary statistics for each group.
*/

    --*HAVIG

select department_id, max(salary)
from employees
group by department_id
having max(salary) > 10000

    --*Result!

DEPARTMENT_ID MAX(SALARY)
------------- -----------
           20       13000
          110       12008
           90       24000
          100       12008
           30       11000
           80       14000

--!

SELECT job_id, sum(salary) PAYROLL
from employees
where job_id not like '%REP%'
group by job_id
having sum(salary) > 13000
order by sum(salary)

    --*Result!

JOB_ID        PAYROLL
---------- ----------
PU_CLERK        13900
AD_PRES         24000
IT_PROG         28800
AD_VP           34000
ST_MAN          36400
FI_ACCOUNT      39600
ST_CLERK        55700
SA_MAN          61000
SH_CLERK        64300

/*
    The HAVING clause in SQL is used in conjunction with the GROUP BY clause to filter 
    the results of a grouped query based on a specific condition. The HAVING clause 
    allows you to filter the grouped data based on an aggregate function, which is not 
    possible using the WHERE clause.

    The main difference between the WHERE and HAVING clauses is that WHERE is used to 
    filter individual rows before they are grouped, while HAVING is used to filter the 
    groups themselves based on an aggregate condition.


*/


