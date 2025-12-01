// Pin definities
const int PIN_DOOD    = 35;
const int PIN_RELOAD  = 34;
const int PIN_TRIGGER = 2;
const int PIN_RESET   = 5;

// States
enum State {
  ALIVE,
  DEAD,
  RELOADING,
  SHOOTING
};

State currentState = ALIVE;

// Variabelen
int ammo = 0;
int magazineUit = 1;

void setup() {
  Serial.begin(9600);
  pinMode(PIN_DOOD, INPUT_PULLUP);
  pinMode(PIN_RELOAD, INPUT_PULLUP);
  pinMode(PIN_TRIGGER, INPUT_PULLUP);
  pinMode(PIN_RESET, INPUT_PULLUP);
}

void loop() {
  // Lees inputs
  bool doodKnop   = digitalRead(PIN_DOOD);
  bool reloadKnop = digitalRead(PIN_RELOAD);
  bool trigger    = digitalRead(PIN_TRIGGER);
  bool resetKnop  = digitalRead(PIN_RESET);

  switch (currentState) {
    case ALIVE:
      if (doodKnop == HIGH) {
        currentState = DEAD;
        Serial.println("dood");
      } else if (reloadKnop == HIGH) {
        currentState = RELOADING;
      } else if (trigger == HIGH && ammo > 0) {
        currentState = SHOOTING;
      }
      break;

    case DEAD:
      if (resetKnop == HIGH) {
        currentState = ALIVE;
        ammo = 0;
        magazineUit = 1;
        Serial.println("Back in the game, Ammo = 0");
      }
      break;

    case RELOADING:
      if (ammo == 0 && magazineUit == 1) {
        ammo = 6;
        magazineUit = 0;
        Serial.print("Reloaded, ammo = ");
        Serial.println(ammo);
      }
      delay(1500); // trage reload
      currentState = ALIVE;
      break;

    case SHOOTING:
      ammo--;
      Serial.print("Ammo: ");
      Serial.println(ammo);
      delay(250);
      if (ammo == 0) {
        Serial.println("kogels op");
        magazineUit = 1;
      }
      currentState = ALIVE;
      break;
  }
}
