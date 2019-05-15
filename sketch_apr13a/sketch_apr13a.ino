#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int btn1;
int btn2;
int btn3;
int btn4;
int btn5;
int b00;
int vite;
int punti;
int tempo;
byte Cuore[8] = {B00000, B01010, B11111, B11111, B11111, B01110, B00100, B00000 };
byte Pigreco[8] = {B00000, B01100, B10011, B01010, B01010, B01010, B01010, B01010 };

void setup() {
  // put your setup code here, to run once:
  lcd.init();
  lcd.backlight();

  tempo  = 1500;
  b00    = 2;
  btn1   = 4;
  btn2   = 6;
  btn3   = 8;
  btn4   = 10;
  btn5   = 12;
  vite   = 5;
  punti  = 0;

  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn5, INPUT);
  pinMode(b00, INPUT);

  lcd.createChar(0, Cuore);
  lcd.createChar(1, Pigreco);
  lcd.setCursor(0,0);
  lcd.print("Inizia a giocare");

}

void loop() {
  // put your main code here, to run repeatedly:
  vite = 5;
  punti = 0;
  inizio();
  while (vite > 0) {
    int pos = compare();
    int premuto = assegno();
    game(pos, premuto);
  }
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("...!GAME!...");
    lcd.setCursor(3, 1);
    lcd.print("..!OVER!..");
}

void inizio() {
  while (digitalRead(b00) != HIGH) {}
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.setCursor(1, 0);
  lcd.print(" =");
  lcd.setCursor(4, 0);
  lcd.print(vite);
  lcd.setCursor(8, 0);
  lcd.print("Punti: ");
  lcd.setCursor(15, 0);
  lcd.print(punti);
}

int assegno() {
  int pos = -1;
  for (int i = 0; i < tempo; i++) {
    if (digitalRead(btn1) == HIGH) {
      pos = 0;
      break;
    }
    else if (digitalRead(btn2) == HIGH) {
      pos = 4;
      break;
    }
    else if (digitalRead(btn3) == HIGH) {
      pos = 8;
      break;
    }
    else if (digitalRead(btn4) == HIGH) {
      pos = 11;
      break;
    }
    else if (digitalRead(btn5) == HIGH) {
      pos = 15;
      break;
    }
    delay(1);
  }
  lcd.clear();
  return pos;
}

int compare() {
  int rnd = random(1, 6);
  int pos = 0;
  if (rnd == 1) {
    pos = 0;
  }
  else if (rnd == 2) {
    pos = 4;
  }
  else if (rnd == 3) {
    pos = 8;
  }
  else if (rnd == 4) {
    pos = 11;
  }
  else if (rnd == 5) {
    pos = 15;
  }
  delay(1000);
  lcd.setCursor(pos, 1);
  lcd.write(byte(1));
  return pos;
}

void game(int P, int B) {
  if (P == B) {
    punti = punti + 1;
    if (tempo > 200) {
    tempo = tempo - 50;
    }
  }
  else {
    vite = vite - 1;
  } 
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.setCursor(1, 0);
  lcd.print(" =");
  lcd.setCursor(4, 0);
  lcd.print(vite);
  lcd.setCursor(8, 0);
  lcd.print("Punti: ");
  lcd.setCursor(14, 0);
  lcd.print(punti);
}
