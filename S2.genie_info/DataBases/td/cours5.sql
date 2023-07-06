select round (SYSDATE, 'MONTH')
from dual

    --! result : 

ROUND(SYS
---------
01-MAR-23

select round (SYSDATE, 'YEAR')
from dual

    --! result : 

ROUND(SYS
---------
01-JAN-23


select trunc (SYSDATE, 'MONTH')
from dual

    --! result : 

TRUNC(SYS
---------
01-MAR-23

    --?Conversion de type 

TO_CHAR (date, 'format_model')

--date
    YYYY : 4 chifres anne
    YEAR : year by letters
    mm : mois par 2 numbers
    month : letters
    MON : 3 leeters format of month
    dy : jour en 3 letters


    HH24 : mi : ss am  1 => 5 : 24 : 32 am
    DD "of" MONTH => 12 OF OCTOBER
    ddspth => fourtheenth
    --* exemple

Select last_name, to_char(hire_date, 'fmDD Month YYYY') as HIREDATE
from employees

    --! result 


LAST_NAME                 HIREDATE                                    
------------------------- --------------------------------------------
Dilly                     13 August 2005                              
Gates                     11 July 2006                                
Perkins                   19 December 2007                            
Bell                      4 February 2004                             
Everett                   3 March 2005                                
McCain                    1 July 2006                                 
Jones                     17 March 2007                               
Walsh                     24 April 2006                               
Feeney                    23 May 2006       

    --! ff in date egnore spaces is exemple above

Select last_name, to_char(hire_date, 'fm ddspth "of" MONTH YYYY  fmHH:MI:SS AM') as HIREDATE
from employees

    --! result  : 

Walsh                      twenty-fourth of APRIL 2006  12:00:00 AM                                
Feeney                     twenty-third of MAY 2006  12:00:00 AM    


    --?-----------------------------------------------------------------------------------------------

TO_CHAR(number, 'format_model')

    9 represente number
    0 force display zero
    $ place un signe dollar flottant

    --* exemple

Select TO_CHAR(salary, '$99,999.00')
from employees
where last_name = 'Ernst'

    --! result : 
    

TO_CHAR(SAL
-----------
$6,000.00

    --?-----------------------------------------------------------------------------------------------

TO_NUMBER(char[, 'format')

    --* exemple

Select last_name, nvl(to_char(manager_id), 'No Message')
from employees
where manager_id is null

    --! result 
    

LAST_NAME                 NVL(TO_CHAR(MANAGER_ID),'NOMESSAGE')    
------------------------- ----------------------------------------
King                      No Message                              



        --* Cours exemple 

Select last_name, to_char( NEXT_DAY(ADD_MONTHS(hire_date, 6), 'Friday') , 'fmDay , Month DDth, YYYY') "Nect 6 months Review"
from employees
order by hire_date;

        --! result : 

Banda                     Friday , October 24TH, 2008                                                           
Kumar                     Friday , October 24TH, 2008     

------------------------------------------


-- TO_CHAR, TO_DATE, TO_NUMBER

    --?-----------------------------------------------------------------------------------------------


    NVl(commission_pct, 0) => if commission is null it will be replaced by null


    --* exemple

Select last_name, salary, nvl(commission_pct, 0), (salary*12) + (salary*12*NVL(commission_pct, 0)) AN_SAL
from employees

    --! result : 

Everett                         3900                     0      46800
McCain                          3200                     0      38400
Jones                           2800                     0      33600
Walsh                           3100                     0      37200
Feeney                          3000                     0      36000




--* NVL Function



    --?-----------------------------------------------------------------------------------------------

    
    SELECT NVL2(NULL, 'Value if null', 'Value if not null') as Example
    FROM dual;

--* NVL2 Function

    --?-----------------------------------------------------------------------------------------------


    SELECT NULLIF(5, 5); -- Returns NULL
    SELECT NULLIF(5, 10); -- Returns 5
    SELECT NULLIF('hello', 'hello'); -- Returns NULL
    SELECT NULLIF('hello', 'world'); -- Returns 'hello'


-- NULLIF function


    --?-----------------------------------------------------------------------------------------------

SELECT COALESCE(NULL, 5, NULL, 'hello'); -- Returns 5
SELECT COALESCE(NULL, NULL, NULL, NULL); -- Returns NULL
SELECT COALESCE(NULL, 'world', 'hello'); -- Returns 'world'

    --*exemple

select last_name, commission_pct, salary,
    COALESCE(commission_pct, commission_pct*0.2, salary, 10) comm
from employees

order by commission_pct

    --! result : 

LAST_NAME                 COMMISSION_PCT     SALARY       COMM
------------------------- -------------- ---------- ----------
Dilly                                          3600       3600
Gates                                          2900       2900
Perkins                                        2500       2500
Bell                                           4000       4000
Everett                                        3900       3900
McCain                                         3200       3200
Jones                                          2800       2800
Walsh                                          3100       3100
Feeney                                         3000       3000

--* coalsce function

    --?-----------------------------------------------------------------------------------------------





    --*exemple

select last_name, job_id, salary,
    case job_id when 'IT_PROG' THEN 1.10 * salary
                when 'SA_REP' THEN 1.15 * salary
                else salary END "REVISED_SALARY"

from employees

    --! result : 

LAST_NAME                 JOB_ID         SALARY REVISED_SALARY
------------------------- ---------- ---------- --------------
Dilly                     SH_CLERK         3600           3600
Gates                     SH_CLERK         2900           2900
Perkins                   SH_CLERK         2500           2500
Bell                      SH_CLERK         4000           4000
Everett                   SH_CLERK         3900           3900
McCain                    SH_CLERK         3200           3200
Jones                     SH_CLERK         2800           2800
Walsh                     SH_CLERK         3100           3100
Feeney                    SH_CLERK         3000           3000



--* Case && Decode functions