# Project1
Tijdens dit project moeten we een spel maken
shootoff--> aantal levens = 1 (int levens = 1)
deathmatch -- aantal levens = 3 (werkt nog niet, is nog geen code voor
zit er magazijn in wapen? ja(magazine = 1) nee(magazine = 0 en Serial.print(geen magazijn);)
status wapen = actief (moet nog)
target geraakt = ja(digitalRead(35) HIGH) --> levens over(moet nog), is nu levens = 0 = Serial.print("dood")
zijn kogels op? (nee -->) (ja = (tijdelijk moet nog aangepast worden)magazine = 0 en magazineuit = 1 (werkt niet samen met magazijn aanwezig controle) = Serial.print("kogels op") -->herladen met 2de magazijn moet nog in code
trigger indrukken wordt ir (is nu if (ammo != 0 && levens == 1){ammo = ammo - 1;)
