// original part for scrolling part by Liviu Roman
// adapted sketch for Arduino by Nicu Florica (aka niq_ro)

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// Set the LCD address to ox3F or 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x3F , 16, 2);


String randulUnu = "ArduinoteNiq.com";
String randulDoi = "made by niq_ro";
int lengthRandulUnu = randulUnu.length();
int lengthRandulDoi = randulDoi.length();

int timp = 500;
int start;
int finish;

void setup()
{
	// initialize the LCD
	lcd.begin();

	// Turn on the blacklight and print a message.
	lcd.backlight();
	lcd.print("Hello, world!");
}

void loop()
{
  lcd.setCursor(0,0);
  lcd.print("STM32F103C board");
  lcd.setCursor(0,1);
  lcd.print("with i2c LCD1602");
  lcd.setCursor(0,2);
  delay (3000);
  lcd.clear();

start = 0;
 finish = 1;
 for (int i=15; i >= 0; i--){
  lcd.setCursor(i,0);
  lcd.print(randulUnu.substring(start,finish)); 
  ++finish;
    delay(timp);
  } 
 delay(1000);

 start = 0;
 finish = 1;
 for (int i=15; i >=0; i--){
  lcd.setCursor(i,1);
  lcd.print(randulDoi.substring(start,finish)); 
  if (i<2) lcd.print(" ");
  ++finish;
  delay(timp);
 }

 delay(1000); 

 for (int i=0; i <= lengthRandulDoi; i++){
  lcd.setCursor(0,1);
  lcd.print(randulDoi.substring(i,lengthRandulDoi)); 
  lcd.print(" ");            
  delay(timp);
 }

 delay(1000); 
 
 for (int i=0; i <= lengthRandulUnu; i++){
  lcd.setCursor(0,0);
  lcd.print(randulUnu.substring(i,lengthRandulUnu)); 
  lcd.print(" "); 
  delay(timp);
 }
 
}  // end main loop
