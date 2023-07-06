set serveroutput on 
declare
x varchar2(20);
begin
x:='Hello, World!';
DBMS_OUTPUT.PUT_LINE(x);
end;
/

    --* RESULT : 

Hello, World!

PL/SQL procedure successfully completed.


    --! example 2

set serveroutput on 
declare
type revenue is record (
    nom employees.first_name%TYPE,
    salaire employees.salary%TYPE);
rev_emp revenue;
begin
DBMS_OUTPUT.PUT_LINE(rev_emp.nom || ' ' ||rev_emp.salaire);
end;
/
    --* RESULT : 

PL/SQL procedure successfully completed.

    --! example 3

set serveroutput on 
declare
  type revenue is record (
    nom employees.first_name%TYPE,
    salaire employees.salary%TYPE
  );
  rev_emp revenue;
begin
  rev_emp.nom := 'Ismail';
  rev_emp.salaire := 999;
  
  DBMS_OUTPUT.PUT_LINE('Name: ' || rev_emp.nom || ', Salary: ' || rev_emp.salaire);
end;
/

    --* RESULT : 

Name: Ismail, Salary: 999


PL/SQL procedure successfully completed.

    --! example 3

set serveroutput on 
declare
  type revenue is record (
    nom employees.first_name%TYPE:='&nom',
    salaire employees.salary%TYPE
  );
  rev_emp revenue;
begin
  
  rev_emp.salaire := 999;
  
  DBMS_OUTPUT.PUT_LINE('Name: ' || rev_emp.nom || ', Salary: ' || rev_emp.salaire);
end;
/

    --* RESULT : 

Name: ismail, Salary: 999

-- we use the & to read the value from the user

    --! example 4


set serveroutput on 
declare
  u_name employees.first_name%type;
  u_salary employees.salary%type;
begin
  SELECT first_name, salary
  into u_name, u_salary
  from employees
  where employee_id = 198;
  
  dbms_output.put_line(u_name || ' ' || u_salary);
end;
/

    --* RESULT : 


Donald 2600


PL/SQL procedure successfully completed.

--! fix this code : 

/*
set serveroutput on 
declare
u_name employees.first_name%type;
u_salary employees.salary%type;
begin
SELECT frist_name, salary
into u_name, u_salary
from employees
where employee_id = 198;
dbms_output.put_line(u_name || ' ' || u_sal);
end;
/
*/


                                        --! u have to update the table of employees to add 1000 to employyes that have a salary between 19000 and 23000


--! CURSOR 

set SERVEROUTPUT on;
declare
    CURSOR c_emp
    is
        select first_name  from employees where department_id  = 30;
    v_name employees.first_name% TYPE;
    
BEGIN
    open c_emp;
    loop 
        fetch c_emp into v_name;
        exit when c_emp%notfound;
        dbms_output.put_line('nom: ' || v_name);
    end loop;
    close c_emp;
end;
/

    --* RESULT

nom: Den
nom: Alexander
nom: Shelli
nom: Sigal
nom: Guy
nom: Karen


PL/SQL procedure successfully completed.

