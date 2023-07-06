                               --? Create a Table

    --* Create Table

CREATE TABLE customers (
   customer_id NUMBER(5),
   first_name VARCHAR2(50),
   last_name VARCHAR2(50),
   email VARCHAR2(100),
   phone_number VARCHAR2(20),
   address VARCHAR2(200)
);

DESCRIBE customers

    --*Result!

Name         Null? Type          
------------ ----- ------------- 
CUSTOMER_ID        NUMBER(5)     
FIRST_NAME         VARCHAR2(50)  
LAST_NAME          VARCHAR2(50)  
EMAIL              VARCHAR2(100) 
PHONE_NUMBER       VARCHAR2(20)  
ADDRESS            VARCHAR2(200) 

/*
    CREATE TABLE - This SQL clause is used to create a new table in the database. 
    It is followed by the name of the new table and a list of columns with their data 
    types and constraints.
*/

    --*ALTER TABLE ADD/MODIFY/DROP

-- ADD

ALTER TABLE customers
ADD date_created DATE;

    --*Result!

Table CUSTOMERS altered.

Name         Null? Type          
------------ ----- ------------- 
CUSTOMER_ID        NUMBER(5)     
FIRST_NAME         VARCHAR2(50)  
LAST_NAME          VARCHAR2(50)  
EMAIL              VARCHAR2(100) 
PHONE_NUMBER       VARCHAR2(20)  
ADDRESS            VARCHAR2(200) 
DATE_CREATED       DATE   
   
    /*
        ADD - This SQL clause is used with the ALTER TABLE statement to add a new 
        column to an existing table. It is followed by the name of the new column and 
        its data type.
    */

--MODIFY

ALTER TABLE customers
MODIFY date_created VARCHAR2(8);

DESCRIBE customers

    --*Result!


Table CUSTOMERS altered.

Name         Null? Type          
------------ ----- ------------- 
CUSTOMER_ID        NUMBER(5)     
FIRST_NAME         VARCHAR2(50)  
LAST_NAME          VARCHAR2(50)  
EMAIL              VARCHAR2(100) 
PHONE_NUMBER       VARCHAR2(20)  
ADDRESS            VARCHAR2(200) 
DATE_CREATED       VARCHAR2(8)   

    /*
        MODIFY - This SQL clause is used with the ALTER TABLE statement to modify the 
        data type or size of an existing column in a table.
    */

--DROP
ALTER TABLE customers
DROP COLUMN date_created;

DESCRIBE customers

    --*Result!    

Table CUSTOMERS altered.

Name         Null? Type          
------------ ----- ------------- 
CUSTOMER_ID        NUMBER(5)     
FIRST_NAME         VARCHAR2(50)  
LAST_NAME          VARCHAR2(50)  
EMAIL              VARCHAR2(100) 
PHONE_NUMBER       VARCHAR2(20)  
ADDRESS            VARCHAR2(200) 

    /*
        DROP - This SQL clause is used with the ALTER TABLE statement to remove a 
        column from an existing table. It is followed by the name of the column to be 
        removed.
    */

                --! WE CAN USE DESC INSTEAD OF DESCRIBE

    --* SET UNUSED

-- Drop the salary column and mark it as unused
ALTER TABLE employees SET UNUSED salary;

-- Describe the table to confirm that the column is marked as unused
DESCRIBE employees;

-- Restore the salary column
ALTER TABLE employees DROP UNUSED COLUMNS;


/*
    However, if you want to drop the column but still have the option to restore it 
    later, you can use the SET UNUSED clause. This option marks the column as unused, 
    but it does not physically remove the column from the table. The column metadata 
    is still kept in the data dictionary, which allows you to restore the column 
    later if you need to.
*/

    --* RENAME TABLE

RENAME MINE TO YOURS

    --*Result!
Table renamed.

    --* TRUNCATE

TRUNCATE TABLE employees

/*
    TRUNCATE removes all rows from a table, but keeps the table structure intact. It 
    is equivalent to a DELETE statement with no WHERE clause, but much faster since 
    it does not generate undo and redo logs for each individual row. So, to answer 
    your question, TRUNCATE only deletes the rows of a table and not the table 
    structure.
*/

    --* DROP TABLE

DROP TABLE CUSTOMERS
  
    --*Result!

Table CUSTOMERS dropped.  
    


