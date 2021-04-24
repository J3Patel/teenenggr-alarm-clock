#include <DS3231.h>

#include <Wire.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

DS3231 rtc(SDA, SCL);

Time  t;

#define buz 11

int Hor;

int Min;

int Sec;




void setup()

{  

  Wire.begin();

  rtc.begin();

  Serial.begin(9600);

  pinMode(buz, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);

  digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);

  lcd.begin(16,2);     

  lcd.setCursor(0,0);

  lcd.print("TEENENGGR");

  lcd.setCursor(0,1);

  lcd.print("Teenenggr Alarm ");

  // The following lines can be uncommented to set the date and time

  //rtc.setDOW(WEDNESDAY);     // Set Day-of-Week to SUNDAY

  rtc.setTime(5, 12, 0);     // Set the time to 12:00:00 (24hr format)

  rtc.setDate(23, 4, 2021);   // Set the date to January 1st, 2014

  delay(2000);

}




void loop()

{

  t = rtc.getTime();

  Hor = t.hour;

  Min = t.min;

  Sec = t.sec;

  lcd.setCursor(0,0);

  lcd.print("Time: ");

  lcd.print(rtc.getTimeStr());

 lcd.setCursor(0,1);

 lcd.print("Date: ");

 lcd.print(rtc.getDateStr());




 if( Hor == 5 &&  (Min == 13 || Min == 12)) //Comparing the current time with the Alarm time

{

Buzzer1();

Buzzer1();

lcd.clear();

lcd.print("Alarm ON");

lcd.setCursor(0,1);

lcd.print("Alarming");

Buzzer1();

Buzzer1();

fire();

} 

 delay(1000); 

}




void Buzzer()

{

digitalWrite(8,LOW);

delay(1000);

digitalWrite(8, HIGH);

delay(1000);

}

void Buzzer1()

{

digitalWrite(9,LOW);

delay(500);

digitalWrite(9, HIGH);

delay(500);

}

void fire()

{

digitalWrite(10,LOW);

delay(5000);
digitalWrite(10,HIGH);

}

//void setup() {
//  // put your setup code here, to run once:
// pinMode(2, OUTPUT);
//  pinMode(3, OUTPUT);
//  pinMode(4, OUTPUT);
//
//   
//  digitalWrite(2, HIGH);
//  digitalWrite(3, HIGH);
//  digitalWrite(4, HIGH);
//}
//int d = 300;
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  digitalWrite(3, LOW);
//  delay(100 + d);
//  digitalWrite(3, HIGH);
//  digitalWrite(2, LOW);
//  delay(80);
//  digitalWrite(2, HIGH);
//  digitalWrite(3, LOW);
//  delay(70);
//  digitalWrite(3, HIGH);
//  digitalWrite(2, LOW);
//  delay(300 + d);
//  digitalWrite(2, HIGH);
// delay(1000); 
//}
