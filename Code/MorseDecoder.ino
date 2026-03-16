/*==========================
Name: Morse decoder
Date: 11 Mar 2026
Author: Wong Chuan Yee
============================*/

// Library
#include <LiquidCrystal.h> // For 16 x 2 Display

// Pinout(Before you upload your code please check your pinout)
const int buzzer = 9;
const int iButton = 8;
const int cButton = 10; 
// LCD Pinout
const int lcdRS = 2;
const int lcdE = 3;
const int lcdD4 = 4;
const int lcdD5 = 5;
const int lcdD6 = 6;
const int lcdD7 = 7;

// Variable
int time = 0;
bool lastState = LOW;
int num = 0;
String morse = "";

//LCD begin
LiquidCrystal lcd (lcdRS,lcdE,lcdD4,lcdD5,lcdD6,lcdD7);

String decode(String code){ // Font Library
  if(code == ".-") return "A";
  if(code == "-...") return "B";
  if(code == "-.-.") return "C";
  if(code == "-..") return "D";
  if(code == ".") return "E";
  if(code == "..-.") return "F";
  if(code == "--.") return "G";
  if(code == "....") return "H";
  if(code == "..") return "I";
  if(code == ".---") return "J";
  if(code == "-.-") return "K";
  if(code == ".-..") return "L";
  if(code == "--") return "M";
  if(code == "-.") return "N";
  if(code == "---") return "O";
  if(code == ".--.") return "P";
  if(code == "--.-") return "Q";
  if(code == ".-.") return "R";
  if(code == "...") return "S";
  if(code == "-") return "T";
  if(code == "..-") return "U";
  if(code == "...-") return "V";
  if(code == ".--") return "W";
  if(code == "-..-") return "X";
  if(code == "-.--") return "Y";
  if(code == "--..") return "Z";

  if(code == "-----") return "0";
  if(code == ".----") return "1";
  if(code == "..---") return "2";
  if(code == "...--") return "3";
  if(code == "....-") return "4";
  if(code == ".....") return "5";
  if(code == "-....") return "6";
  if(code == "--...") return "7";
  if(code == "---..") return "8";
  if(code == "----.") return "9";

  if(code == "......") return " ";

  return "?"; // if not match return ?
}

void setup() {
  // put your setup code here, to run once:

  pinMode(iButton, INPUT); // For input button
  pinMode(cButton, INPUT); // For OK Button
  pinMode(buzzer, OUTPUT); // For buzzer

  Serial.begin(9600);// Serial Monitor setup

  lcd.begin(16,2); // lcd setup

}

void loop() {
  // put your main code here, to run repeatedly:

  bool state = digitalRead(iButton); // Input Button State

  if(state){ // get the press time of Input Button 
    time++; 
     digitalWrite(buzzer, HIGH);  // Buzzer
  } else {
    digitalWrite(buzzer, LOW); // Buzzer
  }

  if(lastState == HIGH && state == LOW){ 
    if(time < 100 && time > 0){ // Get the Input Button is Long Press or Short Press
      morse += ".";  // Short Press
    }
    else if(time >= 40){
      morse += "-"; // Long Press
    }
    lcd.setCursor(0, 2); 
    lcd.print(morse);
    time = 0; // Reset timer
  }

  if(time > 200 && morse.length() > 0){ // When Input Button is press is Longer Press
    Serial.print(decode(morse)); // Print it out at Serial Monitor
    if (num > 15){ // When the length is out of range, it will reset it
      lcd.clear();
      num = 0;
    }
    lcd.setCursor(num, 0); 
    lcd.print(decode(morse)); // Print it at LCD
    lcd.setCursor(0, 2); 
    lcd.print("                "); // Print it at LCD

    morse = ""; // Reset font
    time = 0; // Reset timer
    num++; 
    delay(500);
  }

  lastState = state;

  if (digitalRead(cButton)){ // When OK Button
    lcd.clear(); // Clear LCD
    num = 0; // Reset LCD font
    morse = "";
    for(int times = 0; times <= 3; times++){ // Buzzer
      digitalWrite(buzzer, HIGH);
      delay(50);
      digitalWrite(buzzer, LOW);
      delay(50);
    }

  }

  delay(1); // delay times

}
