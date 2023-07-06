--!q1

select nomp, sal
from pilote
where sal between 19000 and 23000

--!q2

select novol, vildep, depart, arrivee
from vol
where vilar like 'LONDRES'
AND arrivee < to_date('12:00', 'HH24:MI')
order by depart, depart


--!q3

select nuavion, codeType
from avion
where codetype like '7%'

--!q4

select vol
from affectation
where date_vol ='02-MAR-94';

--!q5

select nomp, embauche
from pilote
where adresse like 'PARIS'
and (
    embauche < '01-JAN-91'
    OR embauche > '01-JAN-92'
    )
order by nomp

--!q6

select *
from vol
order by vildep, depart

--!q7

select p.nomp, a.vol, v.depart, v.arrivee
from affectation a, pilote p, vol v
where a.nopilote=p.nopilot
and a.vol = v.novol
and a.date_vol = '02-MAR-94'


--!q8

select p.nomp, a.codetype
from pilote p, avion a, affectation av, appareil ap
where p.nopilot = av.nopilote
and ap.codetype= a.codetype
and av.nuavion= a.nuavion 
and p.adresse like 'LYON'
and nbvol < 12000


--!q9

select pilote.nopilot, pilote.nomp, vol.depart 
from pilote, vol, affectation
where pilote.nopilot=affectation.nopilote
and affectation.vol= vol.novol

--!q 10

SELECT PILOTE.NumPilote, Nom, VilDep
FROM PILOTE, VOL
where (pilote.numpilote,vol.vildep) 
not in (
    SELECT P2.NumPilote, v2.VilDep
    from PILOTE p2, AFFECTATION a2, VOL v2
    WHERE V2.NumVol=A2.NumVol
    AND p2.NumPilote=A2.NumPilote);

--!q 11

select vol1.novol, vol1.vilar, vol1.vildep
from vol vol1, vol vol2
where vol1.vildep= vol2.vilar 
and vol2.vildep= vol1.vilar 

--!q 12

select p.nopilot, p.nomp, a.vol, a.date_vol
from pilote p, affectation a, vol v
where p.nopilot=a.nopilote
and v.novol=a.vol
and( v.vilar = 'PARIS' 
OR v.vildep='PARIS')


--!q 13

select a.nuavion
from affectation a, vol v 
where a.vol=v.novol
and (v.depart like 'PARIS' OR v.depart LIKE 'LYON')

--!q 1

--!q 1

--!q 1

--!q 1

--!q 1

--!q 1

--!q

--!q

--!q

--!q

--!q

--!q





















