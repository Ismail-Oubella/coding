                               --? Conditional Expressions

    --! FULL GUIDE OF FORIGN KEY :

/*
    To declare a foreign key in SQL, you would typically include a constraint in the 
    table creation statement that references the primary key in another table. 
    For example:
        CREATE TABLE orders (
            order_id INT PRIMARY KEY,
            customer_id INT,
            order_date DATE,
            FOREIGN KEY (customer_id) REFERENCES customers(customer_id)
        );

    
    In this example, the orders table includes a foreign key constraint that 
    references the customer_id column in the customers table. This ensures that any 
    value inserted into the customer_id column in the orders table must match an 
    existing value in the customer_id column in the customers table.

    When you insert data into the orders table, you would need to include a valid 
    customer_id value that corresponds to an existing record in the customers table. 
    The foreign key constraint does not automatically fill in data from the other 
    table - it simply enforces referential integrity between the two tables.

    To use the foreign key in a join, you would typically join the two tables on 
    the columns that correspond to the primary key and foreign key. For example:

        SELECT o.order_id, o.order_date, c.customer_name
        FROM orders o
        JOIN customers c ON o.customer_id = c.customer_id
        WHERE c.customer_country = 'USA';

    In this example, the orders table is joined to the customers table using the 
    customer_id column in each table, which is the primary key in the customers 
    table and the foreign key in the orders table. The result set includes the 
    order_id, order_date, and customer_name columns for all orders placed by customers 
    in the USA.
*/

    --* Equijoin
    
select e.employee_id, e.last_name, e.department_id, departments.department_id, departments.location_id
from employees e, departments
where e.department_id= departments.department_id

    --! OR 

select e.employee_id, e.last_name, e.department_id, d.department_id, d.location_id
from employees e, departments d
where e.department_id= d.department_id

    --*Result!   

EMPLOYEE_ID LAST_NAME                 DEPARTMENT_ID DEPARTMENT_ID LOCATION_ID
----------- ------------------------- ------------- ------------- -----------
        198 OConnell                             50            50        1500
        199 Grant                                50            50        1500
        200 Whalen                               10            10        1700
        201 Hartstein                            20            20        1800
        202 Fay                                  20            20        1800
        203 Mavris                               40            40        2400
        204 Baer                                 70            70        2700
        205 Higgins                             110           110        1700
        206 Gietz                               110           110        1700
        207 Erling                               50            50        1500
        100 King                                 90            90        1700 

/*
    An equijoin is a type of join in SQL where two tables are joined based on the 
    equality of values in their corresponding columns. In other words, an equijoin 
    returns only the records where the values in the specified columns match between 
    two tables.

    The syntax of an equijoin in SQL is as follows:

        SELECT column_list
        FROM table1
        INNER JOIN table2
        ON table1.column_name = table2.column_name;

    or :

        SELECT column_list
        FROM table1, table2
        ON table1.column_name = table2.column_name;

*/


   --*  non-equi join

select e.last_name, e.salary, j.job_title
from employees e, jobs j
where e.salary
        between j.min_salary and j.max_salary

    --*Result!

        
LAST_NAME                     SALARY JOB_TITLE                          
------------------------- ---------- -----------------------------------
Kochhar                        17000 Administration Vice President      
King                           24000 Administration Vice President      
King                           24000 President                          


/*
    Non-equijoin is still a type of join, but it involves matching rows from two 
    tables based on conditions that are not equality conditions. In other words, 
    non-equijoin is a join operation that uses operators other than equals (=) to 
    match rows between tables
*/


    --* outer join RIGHT/LEFT/FULL
select e.last_name, e.department_id, d.department_name
from employees e
right outer join departments d  
on  e.department_id=d.department_id  

    --! OR

select e.last_name, e.department_id, d.department_name
from employees e, departments d
where e.department_id (+) = d.department_id

   
    --*Result!
    

LAST_NAME                 DEPARTMENT_ID DEPARTMENT_NAME               
------------------------- ------------- ------------------------------
Gates                                50 Shipping                      
Perkins                              50 Shipping                      
Bell                                 50 Shipping                      
Everett                              50 Shipping                      
McCain                               50 Shipping                      
Jones                                50 Shipping                      
Walsh                                50 Shipping                      
Feeney                               50 Shipping                      
                                        IT Support                    
                                        Operations                    
                                        Payroll                       
    
/*
    In an outer join, not all rows are required to have matching values in both 
    tables. A left outer join returns all the rows from the left table and the matching 
    rows from the right table, while a right outer join returns all the rows from the 
    right table and the matching rows from the left table. If there is no match, NULL 
    values are returned.


    table (+)=tableX  => right outer join
    table =(+)tableX  => left outer join
*/
    
    --* Cross join

SELECT *
FROM employees
CROSS JOIN departments;


    --*Result!   
--!Produit cartisieene of the first table and the other;
3,132 rows selected. 


/*
    A cross join, also known as a cartesian product, is a type of join in SQL that 
    returns all possible combinations of rows from two or more tables. It doesn't 
    require a join condition because it generates a result set that includes every 
    row from the first table with every row from the second table.
*/
select department_id, department_name, location_id, city
from departments
natural join locations

    --*Result!
DEPARTMENT_ID DEPARTMENT_NAME                LOCATION_ID CITY                          
------------- ------------------------------ ----------- ------------------------------
          210 IT Support                            1700 Seattle                       
          220 NOC                                   1700 Seattle                       
           20 Marketing                             1800 Toronto                       
           40 Human Resources                       2400 London                        
           80 Sales                                 2500 Oxford                        
           70 Public Relations                      2700 Munich                        

/*

    NATURAL JOIN is a type of JOIN in SQL that allows you to combine rows from two 
    tables based on matching column names. It automatically matches the columns with 
    the same names in both tables and returns a result set that contains only those rows
    where the column values match.

    A NATURAL JOIN is similar to an EQUIJOIN in that it also matches rows based on 
    matching values in specified columns. However, the difference is that in a NATURAL 
    JOIN, the columns to be matched are not specified explicitly. Instead, the join 
    condition is implicitly defined by matching all columns with the same name in 
    both tables.

*/

    --* USING

select e.employee_id, e.last_name, d.location_id
from employees e 
join departments d
using (department_id)

    --*Result!

EMPLOYEE_ID LAST_NAME                 LOCATION_ID
----------- ------------------------- -----------
        190 Gates                            1500
        191 Perkins                          1500
        192 Bell                             1500
        193 Everett                          1500
        194 McCain                           1500
        195 Jones                            1500
        196 Walsh                            1500
        197 Feeney                           1500

/*
    Yes, that's correct. The USING keyword in SQL is used to specify the join 
    condition between two tables, that have the same column name
*/

select e.employee_id, e.last_name, d.location_id
from employees e 
join departments d
on (e.department_id= d.department_id) 

    --*Result!    

EMPLOYEE_ID LAST_NAME                 LOCATION_ID
----------- ------------------------- -----------
        190 Gates                            1500
        191 Perkins                          1500
        192 Bell                             1500
        193 Everett                          1500
        194 McCain                           1500
        195 Jones                            1500
        196 Walsh                            1500
        197 Feeney                           1500


    --! multiple joins
select e.employee_id, city, d.department_name
from employees e 
join departments d
on (e.department_id= d.department_id) 
join locations l 
on (d.location_id= l.location_id) 

    --*Result!

EMPLOYEE_ID CITY                           DEPARTMENT_NAME               
----------- ------------------------------ ------------------------------
        112 Seattle                        Finance                       
        113 Munich                         Public Relations              
        114 Seattle                        Purchasing                    
        115 Seattle                        Purchasing                    
        116 Seattle                        Purchasing                    
        117 Seattle                        Purchasing                    
        118 Seattle                        Purchasing                    
        119 Seattle                        Purchasing                    
        120 South San Francisco            Shipping                      
        121 South San Francisco            Shipping                      
        122 South San Francisco            Shipping          

/*  
    Yes, the ON statement in a SQL join is used to specify the condition that 
    determines how the two tables are related to each other.
*/

