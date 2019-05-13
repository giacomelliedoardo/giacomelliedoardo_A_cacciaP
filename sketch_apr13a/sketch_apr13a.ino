#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
int btn1;
int btn2;
int btn3;
int btn4;
int btn5;
int b00;
int b01;
int vite;
int punti;
int record;
byte Cuore[8] = {B00000, B01010, B11111, B11111, B11111, B01110, B00100, B00000 };
byte Pigreco[8] = {B00000, B01100, B10011, B01010, B01010, B01010, B01010, B01010 };

void setup() {
  // put your setup code here, to run once:
  b00    = ;
  b01    = ; 
  btn1   = ;
  btn2   = ;
  btn3   = ;
  btn4   = ;
  btn5   = ;
  vite   = 5;
  punti  = 0;
  record = 0;
  
  pinMode(btn1, INPUT);
  pinMode(btn2, INPUT);
  pinMode(btn3, INPUT);
  pinMode(btn4, INPUT);
  pinMode(btn5, INPUT);
  pinMode(b00, INPUT);
  pinMode(b01, INPUT);

  lcd.createChar(0, Cuore); 
  lcd.createChar(1, Pigreco);

}

void loop() {
  // put your main code here, to run repeatedly:
  inizio();
  if (vite > 0){
    compare();
    game();
    game();
    game();
    game();
    game();
  }
  else {
    lcd.setCursor(2, 0);
    lcd.print("...!GAME!...");
    lcd.setCursor(3, 1);
    lcd.print("..!OVER!..");
  }
}

void inizio() {
  while(digitalRead(b00) != HIGH){}
  
  lcd.setCursor(0, 0);
  lcd.write(byte(0));
  lcd.setCursor(1, 0);
  lcd.print("=");
  lcd.setCursor(3, 0);
  lcd.print(vite);
  lcd.setCursor(8, 0);
  lcd.print("Match: ");
  lcd.setCursor(15, 0);
  lcd.print(punti);
  
}

void compare() {
  int rnd = random(1, 5);
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
}

void game(int P, int B) {
  if (P != "" && B == HIGH) {
    punti = punti + 1;
  }
  else {
    vite = vite - 1;
  }
}
