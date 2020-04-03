#include <LiquidCrystal.h>
const int rs = 5, en = 3, d4 = 2, d5 = 16, d6 = 15, d7 = 14;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
const int button1 = 7;    
const int button2 = 8;
const int button3 = 12; 
const int button4 = 13;  
const int led1 =  10;  
const int led2 =  6;
const int led3 =  9; 
const int led4 =  11; 
const int buzzer =  04; 

int buttonState1=0,buttonState2=0,buttonState3=0,buttonState4 = 0;        

void setup() 
{
  lcd.begin(16, 2);
  lcd.print("    WELCOME  ");//printing message "HELLO WORLD" on LCD Screen 
  delay(2000);
  lcd.clear();
  lcd.display();//LCD will display message on line 1
  
  lcd.print( "Kit Developed by");
  lcd.setCursor(0, 1);
  lcd.print( "   Nielit CHD  ");
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(buzzer, OUTPUT);
  
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(button3, INPUT);
  pinMode(button4, INPUT);
}

void loop() 
{
   buttonState1 = digitalRead(button1);
   buttonState2 = digitalRead(button2);
   buttonState3 = digitalRead(button3);
   buttonState4 = digitalRead(button4);
  if (buttonState1 == HIGH)
  {
    digitalWrite(led1, HIGH);
    digitalWrite(buzzer, HIGH);
    delay(50);
  }
  else if(buttonState1==LOW)
  {
    digitalWrite(buzzer, LOW);
   digitalWrite(led1, LOW); 
  }
  if (buttonState2 == HIGH)
  {digitalWrite(buzzer, HIGH);
    digitalWrite(led2, HIGH);
    delay(50);
  }
  else if(buttonState2==LOW)
  {digitalWrite(buzzer, LOW);
    digitalWrite(led2, LOW);
  }
  if (buttonState3 == HIGH)
  {digitalWrite(buzzer, HIGH);
    digitalWrite(led3, HIGH);
    delay(50);
  }
  else if(buttonState3==LOW)
  {digitalWrite(buzzer, LOW);
    digitalWrite(led3, LOW);
  }
  if (buttonState4 == HIGH)
  {digitalWrite(buzzer, HIGH);
    digitalWrite(led4, HIGH);
    delay(50);
  } 
  else 
  {digitalWrite(buzzer, LOW);
    digitalWrite(led4, LOW);
  }
}
