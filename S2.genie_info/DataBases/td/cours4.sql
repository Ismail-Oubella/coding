select last_name, manager_id
from employees
where manager_id is NULL;


LAST_NAME                 MANAGER_ID
------------------------- ----------
King                                

------------------------------------------------
operators AND OR NOT IN

SELECT last_name, job_id, salary, employee_id
from employees
where salary >= 10000
or job_id like '%Man%'


-- !result : 

LAST_NAME                 JOB_ID         SALARY EMPLOYEE_ID
------------------------- ---------- ---------- -----------
Hartstein                 MK_MAN          13000         201
Baer                      PR_REP          10000         204
Higgins                   AC_MGR          12008         205
King                      AD_PRES         24000         100
Kochhar                   AD_VP           17000         101
De Haan                   AD_VP           17000         102
Greenberg                 FI_MGR          12008         108
Raphaely                  PU_MAN          11000         114
Russell                   SA_MAN          14000         145
Partners                  SA_MAN          13500         146
Errazuriz                 SA_MAN          12000         147

LAST_NAME                 JOB_ID         SALARY EMPLOYEE_ID
------------------------- ---------- ---------- -----------
Cambrault                 SA_MAN          11000         148
Zlotkey                   SA_MAN          10500         149
Tucker                    SA_REP          10000         150
King                      SA_REP          10000         156
Vishney                   SA_REP          10500         162
Ozer                      SA_REP          11500         168
Bloom                     SA_REP          10000         169
Abel                      SA_REP          11000         174

19 rows selected. 

----------

Clause order by let as to do the sort 

SELECT last_name, job_id, department_id, hire_date
from employees
order by hire_date ASC

--! result : 


LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
De Haan                   AD_VP                 90 13-JAN-01
Mavris                    HR_REP                40 07-JUN-02
Baer                      PR_REP                70 07-JUN-02
Higgins                   AC_MGR               110 07-JUN-02
Gietz                     AC_ACCOUNT           110 07-JUN-02
Faviet                    FI_ACCOUNT           100 16-AUG-02
Greenberg                 FI_MGR               100 17-AUG-02
Raphaely                  PU_MAN                30 07-DEC-02
Kaufling                  ST_MAN                50 01-MAY-03
Khoo                      PU_CLERK              30 18-MAY-03
King                      AD_PRES               90 17-JUN-03

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Ladwig                    ST_CLERK              50 14-JUL-03
Whalen                    AD_ASST               10 17-SEP-03
Rajs                      ST_CLERK              50 17-OCT-03
Sarchand                  SH_CLERK              50 27-JAN-04
King                      SA_REP                80 30-JAN-04
Bell                      SH_CLERK              50 04-FEB-04
Hartstein                 MK_MAN                20 17-FEB-04
Sully                     SA_REP                80 04-MAR-04
Abel                      SA_REP                80 11-MAY-04
Mallin                    ST_CLERK              50 14-JUN-04
Weiss                     ST_MAN                50 18-JUL-04

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
McEwen                    SA_REP                80 01-AUG-04
Russell                   SA_MAN                80 01-OCT-04
Partners                  SA_MAN                80 05-JAN-05
Davies                    ST_CLERK              50 29-JAN-05
Tucker                    SA_REP                80 30-JAN-05
Marlow                    ST_CLERK              50 16-FEB-05
Bull                      SH_CLERK              50 20-FEB-05
Everett                   SH_CLERK              50 03-MAR-05
Errazuriz                 SA_MAN                80 10-MAR-05
Smith                     SA_REP                80 10-MAR-05
Ozer                      SA_REP                80 11-MAR-05

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Hutton                    SA_REP                80 19-MAR-05
Bernstein                 SA_REP                80 24-MAR-05
Fripp                     ST_MAN                50 10-APR-05
Chung                     SH_CLERK              50 14-JUN-05
Austin                    IT_PROG               60 25-JUN-05
Nayer                     ST_CLERK              50 16-JUL-05
Tobias                    PU_CLERK              30 24-JUL-05
Dilly                     SH_CLERK              50 13-AUG-05
Fay                       MK_REP                20 17-AUG-05
Bissot                    ST_CLERK              50 20-AUG-05
Hall                      SA_REP                80 20-AUG-05

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Kochhar                   AD_VP                 90 21-SEP-05
Chen                      FI_ACCOUNT           100 28-SEP-05
Sciarra                   FI_ACCOUNT           100 30-SEP-05
Vollman                   ST_MAN                50 10-OCT-05
Stiles                    ST_CLERK              50 26-OCT-05
Atkinson                  ST_CLERK              50 30-OCT-05
Vishney                   SA_REP                80 11-NOV-05
Doran                     SA_REP                80 15-DEC-05
Baida                     PU_CLERK              30 24-DEC-05
Hunold                    IT_PROG               60 03-JAN-06
Taylor                    SH_CLERK              50 24-JAN-06

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Fox                       SA_REP                80 24-JAN-06
Pataballa                 IT_PROG               60 05-FEB-06
Seo                       ST_CLERK              50 12-FEB-06
Fleaur                    SH_CLERK              50 23-FEB-06
Urman                     FI_ACCOUNT           100 07-MAR-06
Matos                     ST_CLERK              50 15-MAR-06
Bloom                     SA_REP                80 23-MAR-06
Taylor                    SA_REP                80 24-MAR-06
Olsen                     SA_REP                80 30-MAR-06
Patel                     ST_CLERK              50 06-APR-06
Livingston                SA_REP                80 23-APR-06

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Walsh                     SH_CLERK              50 24-APR-06
Feeney                    SH_CLERK              50 23-MAY-06
Dellinger                 SH_CLERK              50 24-JUN-06
McCain                    SH_CLERK              50 01-JUL-06
Vargas                    ST_CLERK              50 09-JUL-06
Gates                     SH_CLERK              50 11-JUL-06
Rogers                    ST_CLERK              50 26-AUG-06
Mikkilineni               ST_CLERK              50 28-SEP-06
Sewall                    SA_REP                80 03-NOV-06
Himuro                    PU_CLERK              30 15-NOV-06
Cambrault                 SA_REP                80 09-DEC-06

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Landry                    ST_CLERK              50 14-JAN-07
Cabrio                    SH_CLERK              50 07-FEB-07
Lorentz                   IT_PROG               60 07-FEB-07
Smith                     SA_REP                80 23-FEB-07
Jones                     SH_CLERK              50 17-MAR-07
Greene                    SA_REP                80 19-MAR-07
Bates                     SA_REP                80 24-MAR-07
Olson                     ST_CLERK              50 10-APR-07
Ernst                     IT_PROG               60 21-MAY-07
Grant                     SA_REP                   24-MAY-07
OConnell                  SH_CLERK              50 21-JUN-07

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Sullivan                  SH_CLERK              50 21-JUN-07
Colmenares                PU_CLERK              30 10-AUG-07
Cambrault                 SA_MAN                80 15-OCT-07
Mourgos                   ST_MAN                50 16-NOV-07
Tuvault                   SA_REP                80 23-NOV-07
Popp                      FI_ACCOUNT            70 07-DEC-07
Gee                       ST_CLERK              50 12-DEC-07
Perkins                   SH_CLERK              50 19-DEC-07
Johnson                   SA_REP                80 04-JAN-08
Grant                     SH_CLERK              50 13-JAN-08
Marvins                   SA_REP                80 24-JAN-08

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Zlotkey                   SA_MAN                80 29-JAN-08
Geoni                     SH_CLERK              50 03-FEB-08
Philtanker                ST_CLERK              50 06-FEB-08
Lee                       SA_REP                80 23-FEB-08
Markle                    ST_CLERK              50 08-MAR-08
Ande                      SA_REP                80 24-MAR-08
Banda                     SA_REP                80 21-APR-08
Kumar                     SA_REP                80 21-APR-08
Erling                    AC_ACCOUNT            50 28-FEB-23

108 rows selected. 



but ---

SELECT last_name, job_id, department_id, hire_date
from employees
order by hire_date DESC

--! result :


LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Erling                    AC_ACCOUNT            50 28-FEB-23
Banda                     SA_REP                80 21-APR-08
Kumar                     SA_REP                80 21-APR-08
Ande                      SA_REP                80 24-MAR-08
Markle                    ST_CLERK              50 08-MAR-08
Lee                       SA_REP                80 23-FEB-08
Philtanker                ST_CLERK              50 06-FEB-08
Geoni                     SH_CLERK              50 03-FEB-08
Zlotkey                   SA_MAN                80 29-JAN-08
Marvins                   SA_REP                80 24-JAN-08
Grant                     SH_CLERK              50 13-JAN-08

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Johnson                   SA_REP                80 04-JAN-08
Perkins                   SH_CLERK              50 19-DEC-07
Gee                       ST_CLERK              50 12-DEC-07
Popp                      FI_ACCOUNT            70 07-DEC-07
Tuvault                   SA_REP                80 23-NOV-07
Mourgos                   ST_MAN                50 16-NOV-07
Cambrault                 SA_MAN                80 15-OCT-07
Colmenares                PU_CLERK              30 10-AUG-07
Sullivan                  SH_CLERK              50 21-JUN-07
OConnell                  SH_CLERK              50 21-JUN-07
Grant                     SA_REP                   24-MAY-07

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Ernst                     IT_PROG               60 21-MAY-07
Olson                     ST_CLERK              50 10-APR-07
Bates                     SA_REP                80 24-MAR-07
Greene                    SA_REP                80 19-MAR-07
Jones                     SH_CLERK              50 17-MAR-07
Smith                     SA_REP                80 23-FEB-07
Lorentz                   IT_PROG               60 07-FEB-07
Cabrio                    SH_CLERK              50 07-FEB-07
Landry                    ST_CLERK              50 14-JAN-07
Cambrault                 SA_REP                80 09-DEC-06
Himuro                    PU_CLERK              30 15-NOV-06

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Sewall                    SA_REP                80 03-NOV-06
Mikkilineni               ST_CLERK              50 28-SEP-06
Rogers                    ST_CLERK              50 26-AUG-06
Gates                     SH_CLERK              50 11-JUL-06
Vargas                    ST_CLERK              50 09-JUL-06
McCain                    SH_CLERK              50 01-JUL-06
Dellinger                 SH_CLERK              50 24-JUN-06
Feeney                    SH_CLERK              50 23-MAY-06
Walsh                     SH_CLERK              50 24-APR-06
Livingston                SA_REP                80 23-APR-06
Patel                     ST_CLERK              50 06-APR-06

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Olsen                     SA_REP                80 30-MAR-06
Taylor                    SA_REP                80 24-MAR-06
Bloom                     SA_REP                80 23-MAR-06
Matos                     ST_CLERK              50 15-MAR-06
Urman                     FI_ACCOUNT           100 07-MAR-06
Fleaur                    SH_CLERK              50 23-FEB-06
Seo                       ST_CLERK              50 12-FEB-06
Pataballa                 IT_PROG               60 05-FEB-06
Fox                       SA_REP                80 24-JAN-06
Taylor                    SH_CLERK              50 24-JAN-06
Hunold                    IT_PROG               60 03-JAN-06

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Baida                     PU_CLERK              30 24-DEC-05
Doran                     SA_REP                80 15-DEC-05
Vishney                   SA_REP                80 11-NOV-05
Atkinson                  ST_CLERK              50 30-OCT-05
Stiles                    ST_CLERK              50 26-OCT-05
Vollman                   ST_MAN                50 10-OCT-05
Sciarra                   FI_ACCOUNT           100 30-SEP-05
Chen                      FI_ACCOUNT           100 28-SEP-05
Kochhar                   AD_VP                 90 21-SEP-05
Bissot                    ST_CLERK              50 20-AUG-05
Hall                      SA_REP                80 20-AUG-05

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Fay                       MK_REP                20 17-AUG-05
Dilly                     SH_CLERK              50 13-AUG-05
Tobias                    PU_CLERK              30 24-JUL-05
Nayer                     ST_CLERK              50 16-JUL-05
Austin                    IT_PROG               60 25-JUN-05
Chung                     SH_CLERK              50 14-JUN-05
Fripp                     ST_MAN                50 10-APR-05
Bernstein                 SA_REP                80 24-MAR-05
Hutton                    SA_REP                80 19-MAR-05
Ozer                      SA_REP                80 11-MAR-05
Errazuriz                 SA_MAN                80 10-MAR-05

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Smith                     SA_REP                80 10-MAR-05
Everett                   SH_CLERK              50 03-MAR-05
Bull                      SH_CLERK              50 20-FEB-05
Marlow                    ST_CLERK              50 16-FEB-05
Tucker                    SA_REP                80 30-JAN-05
Davies                    ST_CLERK              50 29-JAN-05
Partners                  SA_MAN                80 05-JAN-05
Russell                   SA_MAN                80 01-OCT-04
McEwen                    SA_REP                80 01-AUG-04
Weiss                     ST_MAN                50 18-JUL-04
Mallin                    ST_CLERK              50 14-JUN-04

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Abel                      SA_REP                80 11-MAY-04
Sully                     SA_REP                80 04-MAR-04
Hartstein                 MK_MAN                20 17-FEB-04
Bell                      SH_CLERK              50 04-FEB-04
King                      SA_REP                80 30-JAN-04
Sarchand                  SH_CLERK              50 27-JAN-04
Rajs                      ST_CLERK              50 17-OCT-03
Whalen                    AD_ASST               10 17-SEP-03
Ladwig                    ST_CLERK              50 14-JUL-03
King                      AD_PRES               90 17-JUN-03
Khoo                      PU_CLERK              30 18-MAY-03

LAST_NAME                 JOB_ID     DEPARTMENT_ID HIRE_DATE
------------------------- ---------- ------------- ---------
Kaufling                  ST_MAN                50 01-MAY-03
Raphaely                  PU_MAN                30 07-DEC-02
Greenberg                 FI_MGR               100 17-AUG-02
Faviet                    FI_ACCOUNT           100 16-AUG-02
Higgins                   AC_MGR               110 07-JUN-02
Baer                      PR_REP                70 07-JUN-02
Mavris                    HR_REP                40 07-JUN-02
Gietz                     AC_ACCOUNT           110 07-JUN-02
De Haan                   AD_VP                 90 13-JAN-01

108 rows selected. 


--

SELECT employee_id, last_name, salary*12 annsal
from employees
order by annsal

--! result :


EMPLOYEE_ID LAST_NAME                     ANNSAL
----------- ------------------------- ----------
        132 Olson                          25200
        136 Philtanker                     26400
        128 Markle                         26400
        127 Landry                         28800
        135 Gee                            28800
        191 Perkins                        30000
        119 Colmenares                     30000
        140 Patel                          30000
        144 Vargas                         30000
        182 Sullivan                       30000
        131 Marlow                         30000

EMPLOYEE_ID LAST_NAME                     ANNSAL
----------- ------------------------- ----------
        198 OConnell                       31200
        199 Grant                          31200
        118 Himuro                         31200
        143 Matos                          31200
        139 Seo                            32400
        126 Mikkilineni                    32400
        195 Jones                          33600
        183 Geoni                          33600
        117 Tobias                         33600
        130 Atkinson                       33600
        116 Baida                          34800

EMPLOYEE_ID LAST_NAME                     ANNSAL
----------- ------------------------- ----------
        190 Gates                          34800
        134 Rogers                         34800
        197 Feeney                         36000
        187 Cabrio                         36000
        181 Fleaur                         37200
        142 Davies                         37200
        196 Walsh                          37200
        115 Khoo                           37200
        125 Nayer                          38400
        180 Taylor                         38400
        138 Stiles                         38400

EMPLOYEE_ID LAST_NAME                     ANNSAL
----------- ------------------------- ----------
        194 McCain                         38400
        129 Bissot                         39600
        133 Mallin                         39600
        186 Dellinger                      40800
        141 Rajs                           42000
        137 Ladwig                         43200
        189 Dilly                          43200
        188 Chung                          45600
        193 Everett                        46800
        192 Bell                           48000
        207 Erling                         48024

EMPLOYEE_ID LAST_NAME                     ANNSAL
----------- ------------------------- ----------
        185 Bull                           49200
        107 Lorentz                        50400
        184 Sarchand                       50400
        200 Whalen                         52800
        105 Austin                         57600
        106 Pataballa                      57600
        124 Mourgos                        69600
        202 Fay                            72000
        104 Ernst                          72000
        173 Kumar                          73200
        179 Johnson                        74400

EMPLOYEE_ID LAST_NAME                     ANNSAL
----------- ------------------------- ----------
        167 Banda                          74400
        166 Ande                           76800
        203 Mavris                         78000
        123 Vollman                        78000
        165 Lee                            81600
        113 Popp                           82800
        155 Tuvault                        84000
        161 Sewall                         84000
        178 Grant                          84000
        164 Marvins                        86400
        172 Bates                          87600

EMPLOYEE_ID LAST_NAME                     ANNSAL
----------- ------------------------- ----------
        171 Smith                          88800
        154 Cambrault                      90000
        160 Doran                          90000
        111 Sciarra                        92400
        112 Urman                          93600
        122 Kaufling                       94800
        120 Weiss                          96000
        153 Olsen                          96000
        159 Smith                          96000
        121 Fripp                          98400
        110 Chen                           98400

EMPLOYEE_ID LAST_NAME                     ANNSAL
----------- ------------------------- ----------
        206 Gietz                          99600
        177 Livingston                    100800
        176 Taylor                        103200
        175 Hutton                        105600
        152 Hall                          108000
        109 Faviet                        108000
        103 Hunold                        108000
        158 McEwen                        108000
        151 Bernstein                     114000
        157 Sully                         114000
        163 Greene                        114000

EMPLOYEE_ID LAST_NAME                     ANNSAL
----------- ------------------------- ----------
        170 Fox                           115200
        204 Baer                          120000
        150 Tucker                        120000
        156 King                          120000
        169 Bloom                         120000
        162 Vishney                       126000
        149 Zlotkey                       126000
        114 Raphaely                      132000
        174 Abel                          132000
        148 Cambrault                     132000
        168 Ozer                          138000

EMPLOYEE_ID LAST_NAME                     ANNSAL
----------- ------------------------- ----------
        147 Errazuriz                     144000
        205 Higgins                       144096
        108 Greenberg                     144096
        201 Hartstein                     156000
        146 Partners                      162000
        145 Russell                       168000
        102 De Haan                       204000
        101 Kochhar                       204000
        100 King                          288000

108 rows selected. 


--

SELECT department_id, last_name, salary
from employees
order by department_id, salary DESC;

--!result :


DEPARTMENT_ID LAST_NAME                     SALARY
------------- ------------------------- ----------
           10 Whalen                          4400
           20 Hartstein                      13000
           20 Fay                             6000
           30 Raphaely                       11000
           30 Khoo                            3100
           30 Baida                           2900
           30 Tobias                          2800
           30 Himuro                          2600
           30 Colmenares                      2500
           40 Mavris                          6500
           50 Fripp                           8200

DEPARTMENT_ID LAST_NAME                     SALARY
------------- ------------------------- ----------
           50 Weiss                           8000
           50 Kaufling                        7900
           50 Vollman                         6500
           50 Mourgos                         5800
           50 Sarchand                        4200
           50 Bull                            4100
           50 Erling                          4002
           50 Bell                            4000
           50 Everett                         3900
           50 Chung                           3800
           50 Ladwig                          3600

DEPARTMENT_ID LAST_NAME                     SALARY
------------- ------------------------- ----------
           50 Dilly                           3600
           50 Rajs                            3500
           50 Dellinger                       3400
           50 Mallin                          3300
           50 Bissot                          3300
           50 Taylor                          3200
           50 Nayer                           3200
           50 McCain                          3200
           50 Stiles                          3200
           50 Fleaur                          3100
           50 Davies                          3100

DEPARTMENT_ID LAST_NAME                     SALARY
------------- ------------------------- ----------
           50 Walsh                           3100
           50 Cabrio                          3000
           50 Feeney                          3000
           50 Gates                           2900
           50 Rogers                          2900
           50 Geoni                           2800
           50 Atkinson                        2800
           50 Jones                           2800
           50 Seo                             2700
           50 Mikkilineni                     2700
           50 OConnell                        2600

DEPARTMENT_ID LAST_NAME                     SALARY
------------- ------------------------- ----------
           50 Grant                           2600
           50 Matos                           2600
           50 Sullivan                        2500
           50 Patel                           2500
           50 Marlow                          2500
           50 Perkins                         2500
           50 Vargas                          2500
           50 Gee                             2400
           50 Landry                          2400
           50 Philtanker                      2200
           50 Markle                          2200

DEPARTMENT_ID LAST_NAME                     SALARY
------------- ------------------------- ----------
           50 Olson                           2100
           60 Hunold                          9000
           60 Ernst                           6000
           60 Pataballa                       4800
           60 Austin                          4800
           60 Lorentz                         4200
           70 Baer                           10000
           70 Popp                            6900
           80 Russell                        14000
           80 Partners                       13500
           80 Errazuriz                      12000

DEPARTMENT_ID LAST_NAME                     SALARY
------------- ------------------------- ----------
           80 Ozer                           11500
           80 Abel                           11000
           80 Cambrault                      11000
           80 Vishney                        10500
           80 Zlotkey                        10500
           80 Tucker                         10000
           80 Bloom                          10000
           80 King                           10000
           80 Fox                             9600
           80 Sully                           9500
           80 Greene                          9500

DEPARTMENT_ID LAST_NAME                     SALARY
------------- ------------------------- ----------
           80 Bernstein                       9500
           80 Hall                            9000
           80 McEwen                          9000
           80 Hutton                          8800
           80 Taylor                          8600
           80 Livingston                      8400
           80 Smith                           8000
           80 Olsen                           8000
           80 Cambrault                       7500
           80 Doran                           7500
           80 Smith                           7400

DEPARTMENT_ID LAST_NAME                     SALARY
------------- ------------------------- ----------
           80 Bates                           7300
           80 Marvins                         7200
           80 Tuvault                         7000
           80 Sewall                          7000
           80 Lee                             6800
           80 Ande                            6400
           80 Johnson                         6200
           80 Banda                           6200
           80 Kumar                           6100
           90 King                           24000
           90 De Haan                        17000

DEPARTMENT_ID LAST_NAME                     SALARY
------------- ------------------------- ----------
           90 Kochhar                        17000
          100 Greenberg                      12008
          100 Faviet                          9000
          100 Chen                            8200
          100 Urman                           7800
          100 Sciarra                         7700
          110 Higgins                        12008
          110 Gietz                           8300
              Grant                           7000

108 rows selected. 


---- *ASC croissant trie , and DESC decroissant 



--? Fnctions  SQL : monoligne or multilignes 

-- * Lower , Upper function

where last_name='higgins'

--! result : 

no rows selected


--

SELECT employee_id, last_name, department_id
from employees
where LOWER(last_name)='higgins'

--! result : 


EMPLOYEE_ID LAST_NAME                 DEPARTMENT_ID
----------- ------------------------- -------------
        205 Higgins                             110


--* Concat , Subster('name','start n ','end n'), lenghth , inster(name,'char')=> pos of char in name , LPAD and RPAD

--! error : 
SELECT employee_id, Concat(first_name, last_name), Name, job_id, length(last_name), instr(last_name, 'a')
from employees

where SUBSTR (job_id, 4) = 'REP';

--*  ROUND function

SELECT ROUND(45.923,2) , ROUND(45.923,0) , ROUND(45.923,-1)
from DUAL

--! result : 


ROUND(45.923,2) ROUND(45.923,0) ROUND(45.923,-1)
--------------- --------------- ----------------
          45.92              46               50

--

SELECT ROUND(45.923,2) , ROUND(45.923,0) , ROUND(40.923,-1)
from DUAL

--! result : 

ROUND(45.923,2) ROUND(45.923,0) ROUND(40.923,-1)
--------------- --------------- ----------------
          45.92              46               40



--* TRUNC function

SELECT TRUNC(45.923,2) , TRUNC(45.923,0) , TRUNC(45.923,-1)
from DUAL

--! result : 

TRUNC(45.923,2) TRUNC(45.923,0) TRUNC(45.923,-1)
--------------- --------------- ----------------
          45.92              45               40



--* MOD function

....

--? Use dates : 

--* Sysdate function

SELECT last_name, (SYSDATE-hire_date)/7 AS WEEKS
from employees
where department_id = 90;

--! result : 


LAST_NAME                      WEEKS
------------------------- ----------
King                      1029.05239
Kochhar                   910.909534
De Haan                   1155.48096

--* Months_betwwen, ADD_Months, next_day, last_day...

--

select MONTHS_BETWEEN ('01-SEP-95','11-JAN-94'), ADD_MONTHS('11-JAN-94',6), NEXT_DAY('01-SEP-95','FRIDAY'), LAST_DAY('01-FEB-95')
from dual

--! result : 


MONTHS_BETWEEN('01-SEP-95','11-JAN-94') ADD_MONTH NEXT_DAY( LAST_DAY(
--------------------------------------- --------- --------- ---------
                             19.6774194 11-JUL-94 08-SEP-95 28-FEB-95


-- 

Select SYSDATE
from dual


--! result : 

SYSDATE  
---------
07-MAR-23







