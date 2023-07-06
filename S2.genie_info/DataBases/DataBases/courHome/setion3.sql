                               --? Functions Type

    /*
        In SQL, there are two types of functions: single-row functions and multi-row functions.

        Single-row functions operate on a single row and return a single result for each row processed. Examples of single-row functions include:

            -UPPER and LOWER: Convert character values to uppercase or lowercase
            -SUBSTR: Extract a substring from a string
            -ROUND and TRUNC: Round or truncate a numeric value
            -TO_CHAR: Convert a value to a character string
        
        Multi-row functions operate on a group of rows and return a single result for the group. Examples of multi-row functions include:

            -SUM, AVG, MIN, and MAX: Perform aggregate calculations on a set of values
            -COUNT: Count the number of rows in a group
            -GROUP_CONCAT: Concatenate values from multiple rows into a single string
        
        Both types of functions can be used in SQL queries to manipulate data and generate useful information.
    */

                               --? Functions Single-row

                        --* Alphanumeric functions

--todo : Uppercase/Lowercase Manipulation:
    
    --* LOWER

select LOWER ('SQL Course') as lower
from dual

    --*Result!

LOWER     
----------
sql course

-- Converts a string to lowercase

    --*UPPER

select UPPER ('SQL Course') as UPPER
from dual

    --*Result!

UPPER     
----------
SQL COURSE

-- Converts a string to uppercase

    --INITCAP "Initial Capitalization"

select INITCAP ('SQL Course') as INITCAP
from dual

    --*Result!


INITCAP   
----------
Sql Course

-- The INITCAP "Initial Capitalization" function in SQL is used to capitalize the first letter of each word in a given string, while converting all other letters to lowercase.


--!


select employee_id, last_name, department_id
from employees
where last_name = 'higgins'

    --*Result!

no rows selected

--!

select employee_id, last_name, department_id
from employees
where last_name = 'higgins'

    --*Result!

EMPLOYEE_ID LAST_NAME                 DEPARTMENT_ID
----------- ------------------------- -------------
        205 Higgins                             110

--todo : Character Manipulation:

    --*CONCAT

SELECT concat('HELLO ', 'WORLD') Rez
from dual

    --*Result!

REZ        
-----------
HELLO WORLD

-- it is used to concatenate (combine) two or more strings into a single string

    --*SUBSTR

select substr('Ismail Oubella', 1, 6) as firstName
from dual

    --*Result!
    
FIRSTN
------
Ismail

--  Returns a substring from within a string  ("string", "start" ,"number of char") 

    --*LENGTH

select LENGTH('Ismail Oubella') as LENGTH
from dual

    --*Result!

    LENGTH
----------
        14

--It claclulare the length of the string giving

    --* INSTR
select INSTR('Ismail Oubella', 'Oubella') as indexof
from dual

    --*Result!


   INDEXOF
----------
        8


--!

select INSTR('Ismail Oubella', 'Oubellda') as indexof
from dual

    --*Result!

   INDEXOF
----------
        0

--returns an integer value stating the index of the first occurrence of the string to be searched, it returns 0 if it is not founded
   
    --LPAD/RPAD

select LPAD('Ismail', 10, '#') LPAD
from dual

    --*Result!

LPAD      
----------
####Ismail

--!

select RPAD('Ismail', 10, '#') RPAD
from dual

    --*Result!

RPAD      
----------
Ismail####

-- The LPAD and RPAD functions in SQL are used to pad a string with a specified character or set of characters, either to the left or right of the string.

    --*TRIM
   
SELECT TRIM('   Hello, World!   ') as noSpaces
from dual 

    --*Result!

NOSPACES     
-------------
Hello, World!

--!

SELECT TRIM( 'H' from 'Hello, World!') as noHChar
from dual 

    --*Result!

NOHCHAR     
------------
ello, World!

/*
    The TRIM function is used to remove specified characters from the beginning and end of a string.
    By default, the TRIM function removes whitespace characters (spaces, tabs, line breaks) from both ends of the string.
    You can specify the characters to be removed by using the optional second argument of the TRIM function. For example, TRIM('abc' FROM 'abcxyzabc') would remove 'abc' from both ends of the string, resulting in 'xyz'.
    The TRIM function only removes characters from the beginning and end of the string, not from the middle.
*/

--todo :  numeric functions

    --* ROUND

SELECT  ROUND(3.14159, 2) AS RoundedN
FROM dual;

    --*Result!

 ROUNDEDN
----------
      3.14

--The ROUND function returns a number rounded to a specified number of decimal places.

    --* TRUNC

SELECT  TRUNC(3.14959, 2) AS Trunced
FROM dual;

    --*Result!

   TRUNCED
----------
      3.14

--The TRUNC function returns a number truncated to a specified number of decimal places.

    --* MOD

SELECT  MOD(4, 2) AS Modolu
FROM dual;

    --*Result!

    MODOLU
----------
         0


-- Modulu of two numbers


                        --* Date Functions

    --* SYSDATE

select sysdate as now
from dual

    --*Result!

NOW      
---------
09-APR-23

-- The SYSDATE function is a built-in date and time function in SQL that returns the current date and time on the database server. 
    
select last_name, (sysdate-hire_date)/7 as weeks
from employees
where department_id = 90

    --*Result!

LAST_NAME                      WEEKS
------------------------- ----------
King                      1033.78693
Kochhar                   915.644069
De Haan                    1160.2155


-- Dates can be used also in arithmetic operations like in the prev example 

    --* MONTHES_BETWEEN

select MONTHS_BETWEEN('9-May-2024', SYSDATE) as monthes
from dual 

    --*Result!

   MONTHES
----------
        13


-- this function  is used to calculate the number of months between two dates.
-- Note that this function just do the arithmetic operation minus, if the first argument is lower that the second the result will be negative, so always put the greatest in the first arg;
    
    --* ADD_MONTHES
select employee_id, first_name || ' ' || last_name as fullName,hire_date as new_hire_date
from employees
where lower(first_name) like 'kelly'

    --*Result!

EMPLOYEE_ID FULLNAME                                       NEW_HIRE_
----------- ---------------------------------------------- ---------
        188 Kelly Chung                                    14-JUN-05

--! USING THE ADD_MONTHES 

select employee_id, first_name || ' ' || last_name as fullName, add_months(hire_date, 6) as new_hire_date
from employees
where lower(first_name) like 'kelly'

    --*Result!

EMPLOYEE_ID FULLNAME                                       NEW_HIRE_
----------- ---------------------------------------------- ---------
        188 Kelly Chung                                    14-DEC-05


--  to add a specific number of months to a given date

    --* NEXT_DAY

select next_day(sysdate, 'friday') as nextFriday
from dual

    --*Result!

NEXTFRIDA
---------
14-APR-23

-- Returns the date of the next specified day of the week
    
    --* LAST_DAY
    
select last_day(sysdate) last
from dual

    --*Result!

LAST     
---------
30-APR-23

-- return the date of the last day of the month for a given date.

    --* ROUND/TRUNC
    
select ROUND(SYSDATE,'MONTH')as RoundMon,
    ROUND(SYSDATE ,'YEAR')as RoundYY,
    TRUNC(SYSDATE ,'MONTH') as TruncMon,
    TRUNC(SYSDATE ,'YEAR') as TruncYY
from dual 

    --*Result!
ROUNDMON  ROUNDYY   TRUNCMON  TRUNCYY  
--------- --------- --------- ---------
01-APR-23 01-JAN-23 01-APR-23 01-JAN-23


/* 
    ROUND/TRUNC (date [, fmt]) --> 
    The date parameter is the date value that you want to round, 
    and fmt is an optional parameter that specifies the precision to which the date 
    should be rounded. The fmt parameter can take the same values as for 
    numeric values, such as YYYY, MM, DD, HH, MI, and SS.
*/


                        --* Conversion Functions

    /*
        The main difference between implicit and explicit conversion is that implicit 
        conversion is done automatically by the database system, while explicit 
        conversion requires the user to specify the conversion using SQL functions. 
        Implicit conversion can sometimes lead to unexpected results, while explicit 
        conversion provides more control over the conversion process.
    */

-- todo : implicit Conversion 

    --* assignments    

VARCHAR2 or CHAR --> NUMBER
VARCHAR2 or CHAR --> DATE
NUMBER --> VARCHAR2
DATE --> VARCHAR2

    --* expressions

VARCHAR2 or CHAR --> NUMBER
VARCHAR2 or CHAR --> DATE


-- todo : explicit Conversion 

/*
    In the explicit conversion in SQL, there are three main functions: 
    TO_CHAR, TO_NUMBER, and TO_DATE. These functions allow you to convert data from 
    one data type to another explicitly, based on the specific format you provide. 
    For example, you can use TO_CHAR to convert a number to a string, TO_NUMBER to 
    convert a string to a number, and TO_DATE to convert a string to a date.
*/

    --* TO_CHAR

-- WITH DATES : TO_CHAR(date, 'format_model') 

    /*
        YYYY - 4-digit year -> 2023
        YY - 2-digit year -> 23
        MM - Month (numeric, with leading zero) -> 04
        MON - Abbreviated month name  -> APR
        MONTH - Full month name -> APRIL
        DD - Day of the month (numeric, with leading zero) -> 09
        DY - Abbreviated name of the day of the week -> SUN
        DAY - Full name of the day of the week -> SUNDAY
        HH - Hour (12-hour clock, with leading zero) -> 03
        HH12 - Hour (12-hour clock) -> 03
        HH24 - Hour (24-hour clock) -> 15
        MI - Minute (with leading zero) -> 37
        SS - Second (with leading zero) -> 41
        AM - Returns either "AM" or "PM" -> 
        A.M. - Returns either "A.M." or "P.M." ->
        PM - Returns either "PM" or "AM" ->
        P.M. - Returns either "P.M." or "A.M." ->
        ddspth - returns the day with th -> ninth to day number 9
        fmdd -  the fm in fmDD is a prefix that stands for "fill mode" and it ensures that there are no leading spaces in the output string. 
    */

SELECT TO_CHAR(SYSDATE, 'DAY "OF" MONTH HH24-MI-SS AM') AS current_date_time
FROM DUAL;

    --*Result!        

CURRENT_DATE_TIME                                                                       
----------------------------------------------------------------------------------------
SUNDAY    OF APRIL     15-40-38 PM

--!
SELECT TO_CHAR(SYSDATE, 'ddspth "of" month') AS current_date_time
FROM DUAL;

    --*Result!

CURRENT_DATE_TIME                                     
------------------------------------------------------
ninth of april    



-- WITH NUMBERS TO_CHAR(number, 'format_model')

select to_char(salary, '$999,999.00') as salary
from employees
where last_name  like 'Grant';

    --*Result!

SALARY      
------------
   $2,600.00
   $7,000.00

/*
    with my experience we can use only the dollar sign and format number, 
    and everything else will not work with this, so keep using this format    
*/

    --* TO_NUMBER

SELECT TO_NUMBER('123.45') AS num FROM dual;

    --*Result!

NUM
---
123.45

-- Convert a character string to a number format using the TO_NUMBER function

    
    --* TO_DATE
    
SELECT TO_DATE('01-JAN-21', 'DD-MON-RR') as date_rr,
    TO_DATE('01-JAN-55', 'DD-MON-RR') as date_rr_2
FROM DUAL;


    --*Result!

DATE_RR   DATE_RR_2
--------- ---------
01-JAN-21 01-JAN-55
    

/*
    RR FORMAT 
    If the input year is between 00 and 49, it will be interpreted as 20xx.
    If the input year is between 50 and 99, it will be interpreted as 19xx.

    YY FORMAT : 
    If the specified two-digit year is 00 to 49, then
        If the last two digits of the current year are 00 to 49, then the returned year has the same first two digits as the current year.
        If the last two digits of the current year are 50 to 99, then the first 2 digits of the returned year are 1 greater than the first 2 digits of the current year.
    If the specified two-digit year is 50 to 99, then
        If the last two digits of the current year are 00 to 49, then the first 2 digits of the returned year are 1 less than the first 2 digits of the current year.
        If the last two digits of the current year are 50 to 99, then the returned year has the same first two digits as the current year.
*/

                               --? General Functions
    
    --* NVL

SELECT DISTINCT last_name, manager_id, salary, commission_pct, NVL(commission_pct, 0), 
(salary*12) + (salary*12*NVL(commission_pct, 0)) AN_SAL 
FROM employees
WHERE manager_id = 124;

    --*Result!    

LAST_NAME                 MANAGER_ID     SALARY COMMISSION_PCT NVL(COMMISSION_PCT,0)     AN_SAL
------------------------- ---------- ---------- -------------- --------------------- ----------
OConnell                         124       2600                                    0      31200
Grant                            124       2600                                    0      31200
Erling                           124       4002                                    0      48024
Rajs                             124       3500                                    0      42000
Davies                           124       3100                                    0      37200
Matos                            124       2600                                    0      31200
Vargas                           124       2500                                    0      30000
Walsh                            124       3100                                    0      37200
Feeney                           124       3000                                    0      36000

/*
    is used to replace NULL values with a specific value. It takes two arguments, 
    the first argument is the column or expression that needs to be checked for NULL 
    value, and the second argument is the value that will replace the NULL value if 
    it exists.
*/

    --* NVL2
select last_name, salary, commission_pct, nvl2(commission_pct, 'SAL+COMM', 'SAL') income
from employees 
where department_id in (50, 80);

    --*Result!
LAST_NAME                     SALARY COMMISSION_PCT INCOME  
------------------------- ---------- -------------- --------    
Matos                           2600                SAL     
Vargas                          2500                SAL     
Russell                        14000             .4 SAL+COMM
Partners                       13500             .3 SAL+COMM

/*
    The NVL2 function in SQL is used to test a value, and if it is not null, 
    returns one expression, otherwise, returns another expression. 
    The syntax for NVL2 is:
    NVL2(expr1, expr2, expr3)
        where expr1 is the input value to be tested, expr2 is the return value if expr1 
        is not null, and expr3 is the return value if expr1 is null.
*/   

    --* NULLIF
select first_name, length(first_name) as "firstLength",
        last_name, length(last_name) as "lastLength",
        nullif(length(first_name), length(last_name)) as result
from employees

    --*Result!

FIRST_NAME           firstLength LAST_NAME                 lastLength     RESULT
-------------------- ----------- ------------------------- ---------- ----------
Jennifer                       8 Dilly                              5          8
Timothy                        7 Gates                              5          7
Randall                        7 Perkins                            7           
Sarah                          5 Bell                               4          5
Britney                        7 Everett                            7           
Samuel                         6 McCain                             6           
Vance                          5 Jones                              5           
Alana                          5 Walsh                              5           
Kevin                          5 Feeney                             6          5

-- The NULLIF function in SQL takes two arguments and returns null if the two arguments are equal, otherwise, it returns the first argument.

    --* COALESCE

SELECT last_name,
    commission_pct,
    salary,
    coalesce(commission_pct, salary, 10) as function
from employees;

    --*Result!    

LAST_NAME                 COMMISSION_PCT     SALARY   FUNCTION
------------------------- -------------- ---------- ----------
Grant                                .15       7000        .15
Johnson                               .1       6200         .1
Taylor                                         3200       3200
Fleaur                                         3100       3100

/*
    is used to return the first non-null value in a list of expressions. 
    It takes a variable number of arguments and returns the first non-null value from 
    the arguments. If all arguments are null, it returns null
*/   

                               --? Conditional Expressions

    --* CASE

select distinct job_id, 
    case job_id when 'IT_PROG' THEN 'PROG'
                when 'ST_CLERK' THEN 'CLERK'
    ELSE 'DEFAULT'
    END
FROM employees

    --*Result!

JOB_ID     CASEJOB
---------- -------
SH_CLERK   DEFAULT
AD_ASST    DEFAULT
MK_MAN     DEFAULT
MK_REP     DEFAULT
HR_REP     DEFAULT
PR_REP     DEFAULT
AC_MGR     DEFAULT
AC_ACCOUNT DEFAULT
AD_PRES    DEFAULT
AD_VP      DEFAULT
IT_PROG    PROG   

JOB_ID     CASEJOB
---------- -------
FI_MGR     DEFAULT
FI_ACCOUNT DEFAULT
PU_MAN     DEFAULT
PU_CLERK   DEFAULT
ST_MAN     DEFAULT
ST_CLERK   CLERK  
SA_MAN     DEFAULT
SA_REP     DEFAULT

/*
    CASE is a conditional expression in SQL that allows you to perform different 
    actions based on different conditions. It has two formats: 
    simple CASE and searched CASE.

    SIMPLE CASE : 
        In the simple CASE format, you specify a single expression to be evaluated 
        and then use WHEN/THEN statements to define the conditions and corresponding 
        values to be returned when the expression matches each condition. 
        The general syntax for a simple CASE statement is:

            CASE expression
                WHEN value1 THEN result1
                WHEN value2 THEN result2
                ...
                ELSE default_result
                END

    SEARCHED CASE : 

        In the searched CASE format, you use boolean expressions in each WHEN condition, 
        rather than a single expression to be evaluated. The general syntax for a 
        searched CASE statement is:

            CASE
                WHEN condition1 THEN result1
                WHEN condition2 THEN result2
                ...
                ELSE default_result
                END

*/

    --* DECODE

select distinct job_id, 
    decode(job_id,
        'IT_PROG', 'PROG',
        'ST_CLERK', 'CLERK',
        'DEFAULT') as job_title        
FROM employees

    --*Result!

JOB_ID     JOB_TIT
---------- -------
SH_CLERK   DEFAULT
AD_ASST    DEFAULT
MK_MAN     DEFAULT
MK_REP     DEFAULT
HR_REP     DEFAULT
PR_REP     DEFAULT
AC_MGR     DEFAULT
AC_ACCOUNT DEFAULT
AD_PRES    DEFAULT
AD_VP      DEFAULT
IT_PROG    PROG   

JOB_ID     JOB_TIT
---------- -------
FI_MGR     DEFAULT
FI_ACCOUNT DEFAULT
PU_MAN     DEFAULT
PU_CLERK   DEFAULT
ST_MAN     DEFAULT
ST_CLERK   CLERK  
SA_MAN     DEFAULT
SA_REP     DEFAULT


/*
    DECODE is a function similar to the CASE expression, but CASE expression is 
    more versatile and supports more complex conditional statements than DECODE.

    DECODE(expression, 
        search_value1, result1, 
        search_value2, result2,
        ..., 
        default_result)

*/














