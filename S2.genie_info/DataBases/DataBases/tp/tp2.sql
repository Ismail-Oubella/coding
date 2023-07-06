                                                    --! Create New Tables

create table Vol (
   Novol char(6) PRIMARY KEY ,
   Vildep varchar2(30),
    Vilar VARCHAR2(30),
    Depart Date,
    Arrivee DATE
);

-- Novol, Vildep, Vilar, Depart, Arrivee

create table Polote(
    nopilot char(4) primary KEY,
    nomp varchar2(35),
    prenomp VARCHAR2(35),
    Adresse VARCHAR2(30),
    sal NUMBER(8,2),
    comm NUMBER(8,2),
    embauche date
);

create table Appareil (
    codetype char(3) PRIMARY KEY,
    Nbplace NUMBER(3),
    design VARCHAR(50)
);

create table avion (
    Nuavion  char(6) PRIMARY KEY,
    codeType ,
   FOREIGN key (codeType) REFERENCES Appareil(codetype),
    Annserv date, 
    Nom VARCHAR(50),
    nbvol date
);

create table affectation (
    Vol,
    FOREIGN KEY (Vol) REFERENCES Vol(Novol),
    Date_vol DATE PRIMARY KEY,
    nopilote,
    FOREIGN KEY (nopilote) REFERENCES Polote(nopilot),
   nuavion, 
    FOREIGN KEY (nuavion) REFERENCES avion(Nuavion),
    nbpass NUMBER(3)
);

alter table Polote
rename to Pilote;

                                                    --! Fill Data


INSERT INTO Vol (Novol, Vildep, Vilar, Depart, Arrivee)
VALUES 
    ('AF8809', 'DJERBA', 'PARIS', TO_DATE('12:45', 'HH24:MI'), TO_DATE('15:40', 'HH24:MI'));
    ('IW201', 'LYON', 'FORT DE FRANCE', TO_DATE('09:45', 'HH24:MI'), TO_DATE('15:25', 'HH24:MI')),;
    ('IW655', 'LA HAVANE', 'PARIS', TO_DATE('19:55', 'HH24:MI'), TO_DATE('12:35', 'HH24:MI'));
    ('IW433', 'PARIS', 'ST-MARTIN', TO_DATE('17:00', 'HH24:MI'), TO_DATE('08:20', 'HH24:MI'));
    ('IW924', 'SYDNEY', 'COLOMBO', TO_DATE('17:25', 'HH24:MI'), TO_DATE('22:30', 'HH24:MI'));
    ('IT319', 'BORDEAUX', 'NICE', TO_DATE('10:35', 'HH24:MI'), TO_DATE('11:45', 'HH24:MI'));
    ('AF3218', 'MARSEILLE', 'FRANCFORT', TO_DATE('16:45', 'HH24:MI'), TO_DATE('19:10', 'HH24:MI'));
    ('AF3530', 'LYON', 'LONDRES', TO_DATE('08:00', 'HH24:MI'), TO_DATE('08:40', 'HH24:MI'));
    ('AF3538', 'LYON', 'LONDRES', TO_DATE('18:35', 'HH24:MI'), TO_DATE('19:15', 'HH24:MI'));
    ('AF3570', 'MARSEILLE', 'LONDRES', TO_DATE('09:35', 'HH24:MI'), TO_DATE('10:20', 'HH24:MI'));

INSERT into Polote (nopilot, nomp, Adresse, sal, comm, embauche)
VALUES 
    ('1333', 'FEDOI', 'NANTES', 24000.00, 0.00, TO_DATE('01-Mar-92', 'DD-Mon-YY'));
    ('6589', 'DUVAL', 'PARIS', 18600.00, 5580.00, TO_DATE('12-Mar-92', 'DD-Mon-YY'));
    ('7100', 'MARTIN', 'LYON', 15600.00, 16000.00, TO_DATE('01-Apr-93', 'DD-Mon-YY'));
    ('3452', 'ANDRE', 'NICE', 22670.00 , TO_DATE('12-Dec-92', 'DD-Mon-YY'));
    ('3421', 'BERGER', 'REIMS', 18700.00, TO_DATE('28-Dec-92', 'DD-Mon-YY'));
    ('6548', 'BARRE', 'LYON', 22680.00, 8600.00, TO_DATE('01-Dec-92', 'DD-Mon-YY'));
    ('1243', 'COLLET', 'PARIS', 19000.00, 0.00, TO_DATE('01-Feb-90', 'DD-Mon-YY'));
    ('5643', 'DELORME', 'PARIS', 21580.00, 9850.00, TO_DATE('01-Feb-92', 'DD-Mon-YY'));
    ('6723', 'MARTIN', 'ORSAY', 23150.00, TO_DATE('15-May-92', 'DD-Mon-YY'));
    ('8843', 'GAUCHER', 'CACHAN', 17600.00, TO_DATE('20-Nov-92', 'DD-Mon-YY'));
    ('3465', 'PIC', 'TOURS', 18650.00, TO_DATE('15-Jul-93', 'DD-Mon-YY'));
    

INSERT INTO appareil(codetype, Nbplace, design) 
VALUES 
('74E', 150, '74E BOEING 747-400 COMBI');
('AB3', 180, 'AIRBUS A300');
('741', 100, 'BOEING 747-100');
('SSC', 80, 'CONCORDE'); 
('734', 450, 'BOEING 737-400');

insert into avion (Nuavion, Annserv, Nom,nbvol, codeType)
VALUES 
('8832',TO_DATE('1988','YYYY'), 'Ville de paris', 16000,  '734');
('8567',TO_DATE('1988','YYYY'), 'Ville de reims', 8000, '734' );
('8476',TO_DATE('1995','YYYY'), 'le sud', 600, '734');
('7693',TO_DATE('1988','YYYY'), 'pacifique', 34000, '734');
('8556',TO_DATE('1989','YYYY'), NULL, 12000, 'AB3');
('8432',TO_DATE('1991','YYYY'), 'malte', 10600, 'AB3');
('8118',TO_DATE('1992','YYYY'), NULL, 11800, '74E');

insert into affectation(Vol, nopilote, nuavion,date_vol,nbpass)
values
-- ( 'IW201', 6723,8567 , to_date('01-MAR-94','DD,MM,YY'),310);
-- ( 'IW201', 6723, 8832, to_date('02-MAR-94','DD,MM,YY'),265);
-- ( 'AF3218', 6723, 7693,to_date('12-JUN-94','DD,MM,YY'),83);
-- ( 'AF3530', 6723, 8432, to_date('12-NOV-94','DD,MM,YY'),178);
-- ( 'AF3530', 6723, 8432, to_date('13-NOV-94','DD,MM,YY'),156);
-- ( 'AF3538', 6723,8118 , to_date('21-DEC-94','DD,MM,YY'),110);
-- ( 'IW201', 1333, 8567, to_date('03-MAR-94','DD,MM,YY'),356);
-- ( 'IW201', 6589, 8467, to_date('12-MAR-94','DD,MM,YY'),211);
-- ( 'AF8809', 7100, 8556, to_date('02-MAR-94','DD,MM,YY'),160); 



                                --! q1

SELECT *
FROM Vol
WHERE Depart < TO_DATE('12:00', 'HH24:MI')
AND vilar = 'LONDRES'
ORDER BY Depart , Vildep ;


                                --! q2

SELECT *
     FROM avion
where codetype LIKE '7%'

                                --! q3


SELECT vol
FROM affectation
where TO_CHAR(date_vol, 'DD-Mon-YYYY') = '02-Mar-1994';


                                --! q4

SELECT pilote.nomp, affectation.vol, vol.vildep, vol.vilar 
FROM VOL, AFFECTATION, PILOTE 
WHERE
affectation.vol = vol.novol 
AND affectation.nopilote = pilote.nopilot
AND affectation.date_vol='2-MAR-94' 
ORDER BY pilote.nomp ;

                                --! q5

SELECT vildep, depart
from vol
ORDER BY vildep, depart ASC


                                --! q6

select nomp, sal
from  pilote
WHERE comm IS NULL
and sal > 20000 

                                --! q7


SELECT pilote.nomp, vol.novol, vol.vildep, vol.vilar
FROM vol, pilote, affectation
WHERE affectation.nopilote = pilote.nopilot
AND affectation.vol = vol.novol
AND to_char(affectation.date_vol, 'DD-MON-yy') = '02-MAR-94';

OR 

SELECT pilote.nomp, vol.novol, vol.vildep, vol.vilar
FROM vol, pilote, affectation
WHERE affectation.nopilote = pilote.nopilot
AND affectation.vol = vol.novol
AND affectation.date_vol= '02-MAR-94';

                                --! q8




lkfqjsjfmljqskjds
dslmjfdsmljqmds





lksqjdfmlkdjd
dlfsqlkdsjdsj