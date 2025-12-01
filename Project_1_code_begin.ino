//35 is dood
//34 is reload
//2 is shoot
//5 is revive
const int reset = digitalRead(5);
const int  doodknop = digitalRead(35);
int  reload;
int vorigeleven  = 1;
int levens = 1;
int ammo = 0;
int magazine;
int magazineuit = 1;
int trigactive;
int shot;
const int  trigger = digitalRead(2);
const int  reloadknop = digitalRead(34);

void setup() {
Serial.begin(9600);
pinMode(35, INPUT_PULLUP); //tempdoodknop
pinMode(34, INPUT_PULLUP); //reload knop
pinMode(2, INPUT_PULLUP); //trigger
pinMode(5, INPUT_PULLUP); //"reset"
//pinMode(2, INPUT); TEMP
}
void loop() {
/*trigger indrukken*/
if (trigger == HIGH && shot == 0 && trigactive == 0){
  trigactive = 1;
  shot = 1;
}
/*trigger loslaten*/
if (trigger == LOW){
  trigactive = 0;
}
/*reload sequence start*/
if (reloadknop == HIGH){
  reload = 1;
  magazine = 1;
  }else{
    reload = 0;
}
/*if (digitalRead(2) HIGH){
magazine = 1
}else{
magazine = 0
Serial.println();
Serial.print(geen magazijn);
}
  
/*reload sequence controlle*/
if (magazine == 1 && magazineuit == 1 && levens == 1){
  ammo = 6;
  magazineuit = 0;
  Serial.println();
  Serial.print(ammo);
  }
/*tijdelijke out of ammo*/
if (ammo == 0){
  magazine = 0;
   magazineuit = 1;
  Serial.println();
  Serial.print("kogels op");
  }
/*nu dood maar wordt levens-1 knop*/
if (doodknop == HIGH){
  levens = 0;
}
/*0 levens? dood*/
if (levens != vorigeleven && levens == 0){
  Serial.println();
  Serial.print("dood");
  vorigeleven = levens;
}
/*temp reset sequence*/
if(reset == 1 && levens == 0){
  levens = 1;
  vorigeleven = levens;
  ammo = 0;
  Serial.println();
  Serial.print("Back in the game, Ammo = 0");


}
/*schiet = -1 ammo met delay*/
if(shot == 1 && ammo != 0 && levens == 1){
  ammo = ammo - 1;
  delay(250);
  Serial.println();
  Serial.print(ammo);
}
if(shot == 1){
  shot = 0;
}
/*nog kogels = trage reload*/
if (reload == 1 && ammo != 0 && ammo != 6 && levens == 1){
  delay(1500); 
  magazineuit = 1;
}
}





