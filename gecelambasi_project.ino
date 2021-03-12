#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <virtuabotixRTC.h>
#include <IRremote.h>
int RECV_PIN = 2;
int RED_PIN = 3;
int GREEN_PIN = 4;
int BLUE_PIN = 5;
int CLK_PIN = 6;
int DAT_PIN = 7;
int RST_PIN = 8;
int ON_OFF_PIN = 10;
int i;
virtuabotixRTC myRTC(CLK_PIN, DAT_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 20, 4);
decode_results results;
IRrecv irrecv(RECV_PIN);
#define BUTON0 16750695
#define BUTON1 16753245
#define BUTON2 16736925
#define BUTON3 16769565
#define BUTON4 16720605
#define BUTON5 16712445
#define BUTON6 16761405
#define BUTON7 16769055
#define BUTON8 16754775
#define BUTON9 16748655
#define SAGBUT 16734885
#define SOLBUT 16716015
#define YUKARIBUT 16718055
#define ASAGIBUT 16730805
#define OKBUTON 16726215

int dak = 0;
int saat = 0;
int day = 0;
int month = 0;
int year = 2021;
int buttonState = 1;
void setup() {
  Serial.begin(9600);
  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
  lcd.begin();
  irrecv.enableIRIn();
  pinMode(ON_OFF_PIN,OUTPUT);
  digitalWrite(ON_OFF_PIN,HIGH);

}

void loop() {
  if (irrecv.decode(&results)){
    Serial.println(results.value);
    if(results.value == BUTON1){
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, HIGH);
      
    }
    if(results.value == BUTON2){
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);
      
    }
    if(results.value == BUTON3){
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, HIGH);
      digitalWrite(BLUE_PIN, LOW);
      
    }
    if(results.value == BUTON4){
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, HIGH);
    }
    if(results.value == BUTON5){
      digitalWrite(RED_PIN, HIGH);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, HIGH);
    }
    if(results.value == BUTON0){
      digitalWrite(RED_PIN, LOW);
      digitalWrite(GREEN_PIN, LOW);
      digitalWrite(BLUE_PIN, LOW);
    }
    if(results.value == OKBUTON){
      if(buttonState == 1){
        buttonState = 0;
        digitalWrite(ON_OFF_PIN,LOW);
      }
      else if(buttonState == 0){
        buttonState = 1;
        digitalWrite(ON_OFF_PIN,HIGH);
      }
    }
    if(results.value == SAGBUT){
      while(1){
        if(irrecv.decode(&results)){
          if(results.value == BUTON1){
            day = 10;
            while(1){
              if(irrecv.decode(&results)){
                if(results.value == SAGBUT){
                  day = day + 1 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON2){
                  day = day + 2 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON3){
                  day = day + 3 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON4){
                  day = day + 4 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON5){
                  day = day + 5 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON6){
                  day = day + 6 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON7){
                  day = day + 7 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON8){
                  day = day + 8 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON9){
                  day = day + 9 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON0){
                  day = day;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                irrecv.resume();
              }
            }
            break;
          }
          if(results.value == BUTON2){
            day = 20;
            while(1){
              if(irrecv.decode(&results)){
                if(results.value == BUTON1){
                  day = day + 1 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == SAGBUT){
                  day = day + 2 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON3){
                  day = day + 3 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON4){
                  day = day + 4 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON5){
                  day = day + 5 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON6){
                  day = day + 6 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON7){
                  day = day + 7 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON8){
                  day = day + 8 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON9){
                  day = day + 9 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON0){
                  day = day;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                irrecv.resume();
              }
            }
            break;
          }
          if(results.value == BUTON3){
            day = 30;
            while(1){
              if(irrecv.decode(&results)){
                if(results.value == BUTON1){
                  day = day + 1 ;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                if(results.value == BUTON0){
                  day = day;
                  myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
                  break;
                }
                irrecv.resume();
              }
            }
            break;
          }
          irrecv.resume();
        }
      }
    }
    if(results.value == ASAGIBUT){
      month++;
      myRTC.setDS1302Time(0, dak, saat, 12, day, month, year);
      if(month >= 12){
        month = 0;
      }
      
    }
    if(results.value == SOLBUT){
      while(1){
        if(irrecv.decode(&results)){
          if(results.value == BUTON1){
            saat = 10;
            while(1){
              if(irrecv.decode(&results)){
                if(results.value == SAGBUT){
                  saat = saat + 1;
                  myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                  break;
                }
                if(results.value == BUTON2){
                  saat = saat + 2;
                  myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                  break;
                }
                if(results.value == BUTON3){
                  saat = saat + 3;
                  myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                  break;
                }
                if(results.value == BUTON4){
                  saat = saat + 4;
                  myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                  break;
                }
                if(results.value == BUTON5){
                  saat = saat + 5;
                  myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                  break;
                }
                if(results.value == BUTON6){
                  saat = saat + 6;
                  myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                  break;
                }
                if(results.value == BUTON7){
                  saat = saat + 7;
                  myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                  break;
                }
                if(results.value == BUTON8){
                  saat = saat + 8;
                  myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                  break;
                }
                if(results.value == BUTON9){
                  saat = saat + 9;
                  myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                  break;
                }
                if(results.value == BUTON0){
                  saat = saat + 0;
                  myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                  break;
                }
                irrecv.resume();
              }
            }
            break;
          }
          if(results.value == BUTON2){
            saat = 20;
            while(1){
              if(irrecv.decode(&results)){
                if(results.value == BUTON1){
                  saat = saat + 1;
                  myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                  break;
                }
                if(results.value == SAGBUT){
                  saat = saat + 2;
                  myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                  break;
                }
                if(results.value == BUTON3){
                  saat = saat + 3;
                  myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                  break;
                }
                if(results.value == BUTON4){
                  saat = 0;
                  myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                  break;
                }
                irrecv.resume();
              }
            }
            break;
          }
          irrecv.resume();
        }
      }
    }
   
    if(results.value == YUKARIBUT){
      while(1){
        if (irrecv.decode(&results)){
          if(results.value == BUTON1){
            dak = 10;
            while(1){
              if(irrecv.decode(&results)){
              if(results.value == SAGBUT){
                dak = dak+1;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON2){
                dak = dak+2;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON3){
                dak = dak+3;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON4){
                dak = dak+4;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON5){
                dak = dak+5;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON6){
                dak = dak+6;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON7){
                dak = dak+7;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON8){
                dak = dak+8;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON9){
                dak = dak+9;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON0){
                dak = dak;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              irrecv.resume();
            }
            }
            break;
          }
          if(results.value == BUTON2){
            dak = 20;
            while(1){
              if(irrecv.decode(&results)){
              if(results.value == BUTON1){
                dak = dak+1;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == SAGBUT){
                dak = dak+2;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON3){
                dak = dak+3;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON4){
                dak = dak+4;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON5){
                dak = dak+5;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON6){
                dak = dak+6;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON7){
                dak = dak+7;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON8){
                dak = dak+8;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON9){
                dak = dak+9;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON0){
                dak = dak;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              irrecv.resume();
            }
            }
            break;
          }
          if(results.value == BUTON3){
            dak = 30;
           while(1){
              if(irrecv.decode(&results)){
              if(results.value == BUTON1){
                dak = dak+1;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON2){
                dak = dak+2;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == SAGBUT){
                dak = dak+3;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON4){
                dak = dak+4;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON5){
                dak = dak+5;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON6){
                dak = dak+6;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON7){
                dak = dak+7;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON8){
                dak = dak+8;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON9){
                dak = dak+9;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON0){
                dak = dak;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              irrecv.resume();
            }
            }
            break;
          }
          if(results.value == BUTON4){
            dak = 40;
            while(1){
              if(irrecv.decode(&results)){
              if(results.value == BUTON1){
                dak = dak+1;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON2){
                dak = dak+2;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON3){
                dak = dak+3;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == SAGBUT){
                dak = dak+4;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON5){
                dak = dak+5;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON6){
                dak = dak+6;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON7){
                dak = dak+7;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON8){
                dak = dak+8;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON9){
                dak = dak+9;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON0){
                dak = dak;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              irrecv.resume();
            }
            }
            break;
          }
          if(results.value == BUTON5){
            dak = 50;
            while(1){
              if(irrecv.decode(&results)){
              if(results.value == BUTON1){
                dak = dak+1;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON2){
                dak = dak+2;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON3){
                dak = dak+3;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON4){
                dak = dak+4;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == SAGBUT){
                dak = dak+5;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON6){
                dak = dak+6;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON7){
                dak = dak+7;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON8){
                dak = dak+8;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON9){
                dak = dak+9;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              if(results.value == BUTON0){
                dak = dak;
                myRTC.setDS1302Time(0, dak, saat, 10, 10, 2, 2021);
                break;
              }
              irrecv.resume();
            }
            }
            break;
          }
          irrecv.resume();
        }
        }
        
      }  
      
    
    irrecv.resume();
  }
  myRTC.updateTime();
  if(buttonState == 1){
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Tarih>");
    lcd.print(myRTC.dayofmonth);
    lcd.print("/");
    lcd.print(myRTC.month);
    lcd.print("/");
    lcd.print(myRTC.year);
    lcd.setCursor(0,1);
    lcd.print("Saat>");
    lcd.print(myRTC.hours);
    lcd.print(":");
    lcd.print(myRTC.minutes);
    lcd.print(":");
    lcd.print(myRTC.seconds);
  }
  Serial.println(buttonState);
  delay(1000);

}
