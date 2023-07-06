CREATE TABLE tab1 (CIN number(5), nom varchar2(30) , prenom varchar2(30) );

insert into tab1 (CIN,nom,prenom) 

values ("653270","OUBELLA","Ismail");

CREATE TABLE dept2 (
    deptno NUMBER(2),
    dname varchar2(14),
    loc varchar2(13),
    embauch date default sysdate);
    
    DESCRIBE dept2
