#include <LedControl.h>

int DIN = 12;
int CS =  11;
int CLK = 10;


const int TriggerPin = 8;      //Trig pin
const int EchoPin = 9;         //Echo pin
const int TriggerPin1 = 5;      //Trig pin
const int EchoPin1 = 6;         //Echo pin
long Duration = 0;
long Duration1 = 0;
byte m0[8]= {0x1C,0x22,0x41,0x41,0x41,0x41,0x22,0x1C,};
byte m4[8]=     {0x00,0x04,0x08,0x10,0x20,0x48,0x7E,0x08,};
byte m3[8]=   {0x38,0x44,0x04,0x1C,0x04,0x44,0x38,0x00,};
byte m1[8]=     {0x08,0x18,0x28,0x08,0x08,0x08,0x08,0x3C,};
byte m2[8]=     {0x38,0x44,0x44,0x08,0x10,0x20,0x7C,0x00,};
byte m5[8]=     {0x7C,0x40,0x40,0x78,0x04,0x04,0x44,0x38,};
byte m6[8]=     {0x3C,0x42,0x40,0x5C,0x62,0x42,0x42,0x3C,};
byte m7[8]=     {0x00,0x7E,0x02,0x04,0x08,0x10,0x20,0x40,};
byte m8[8]=     {0x3C,0x42,0x42,0x42,0x3C,0x42,0x42,0x3C,};
byte m9[8]=     {0x3C,0x42,0x42,0x42,0x3E,0x02,0x02,0x3C,};
byte m10[8]=     {0x40,0xC0,0x46,0x49,0x49,0x49,0xE6,0x00,};
byte m11[8]=     {0x22,0x66,0xAA,0x22,0x22,0x22,0x22,0x77,};
byte m12[8]=     {0x00,0x46,0xC9,0x49,0x42,0x44,0xEF,0x00,};
byte m13[8]=     {0x00,0x4E,0xC1,0x41,0x4E,0x41,0x41,0xEE,};
byte m14[8]=     {0x00,0x42,0xC4,0x48,0x50,0x52,0x4F,0xE2,};
byte m15[8]=     {0x00,0x5F,0xD0,0x50,0x4E,0x41,0x51,0xEE,};
byte m16[8]=     {0x00,0x4F,0xD0,0x50,0x57,0x59,0x51,0xEE,};
byte m17[8]=     {0x00,0x40,0xDE,0x41,0x41,0x42,0x44,0xE8,};
byte m18[8]=     {0x00,0x4E,0xD1,0x51,0x4E,0x51,0x51,0xEE,};
byte m19[8]=     {0x00,0x4E,0xD1,0x51,0x4F,0x41,0x51,0xEE,};
byte m20[8]=     {0x00,0x66,0x99,0x99,0x29,0x49,0xF6,0x00,};
byte m21[8]=     {0x00,0x72,0x8A,0x8A,0x12,0x22,0x42,0xFB,};
LedControl lc=LedControl(DIN,CLK,CS,0);

void setup() {
  // put your setup code here, to run once:
  pinMode(TriggerPin,OUTPUT);  // Trigger is an output pin
  pinMode(EchoPin,INPUT);      // Echo is an input pin
  pinMode(TriggerPin1,OUTPUT);  // Trigger is an output pin
  pinMode(EchoPin1,INPUT);      // Echo is an input pin
  pinMode(2,OUTPUT);      // Echo is an input pin
  Serial.begin(9600);          // Serial Output

 lc.shutdown(0,false);       //The MAX72XX is in power-saving mode on startup
 lc.setIntensity(0,15);      // Set the brightness to maximum value
 lc.clearDisplay(0);         // and clear the display
}
unsigned int gi=0;
int cik=0;  
void loop() {
  if(gi>22){
    gi=0;
  }
  // put your main code here, to run repeatedly:
  digitalWrite(TriggerPin, LOW);                   
  delayMicroseconds(2);
  digitalWrite(TriggerPin, HIGH);          
  delayMicroseconds(10);                   
  digitalWrite(TriggerPin, LOW);     
  Duration = pulseIn(EchoPin,HIGH);       
  long Distance_cm = Distance(Duration);    
  if(Distance_cm<30){
          gi++;
          digitalWrite(2,LOW);
          delay(500);
  }
    if(gi>0) {
         digitalWrite(TriggerPin1, LOW);                   
          delayMicroseconds(2);
          digitalWrite(TriggerPin1, HIGH);          
          delayMicroseconds(10);                   
          digitalWrite(TriggerPin1, LOW);    
         Duration1 = pulseIn(EchoPin1,HIGH);       
          long Distance_cm1 = Distance(Duration1);   
          Serial.println(Distance_cm1);
              if(Distance_cm1<30){
                  gi--;
                  if(gi==0){
                  digitalWrite(2,HIGH); 
                  }
                  delay(200);
                }
        } 
 hangiRakam();
 } 
void hangiRakam(){
   switch(gi){
      case 0:
      printByte(m0);
      break;
      case 1:
      printByte(m1);
      break;
      case 2:
      printByte(m2);
      break;
      case 3:
      printByte(m3);
      break;
      case 4:
      printByte(m4);
      break;
      case 5:
      printByte(m5);
      break;
      case 6:
      printByte(m6);
      break;
      case 7:
      printByte(m7);
      break;
      case 8:
      printByte(m8);
      break;
      case 9:
      printByte(m9);
      break;
      case 10:
      printByte(m10);
      break;
      case 11:
      printByte(m11);
      break;
      case 12:
      printByte(m12);
      break;
      case 13:
      printByte(m13);
      break;
      case 14:
      printByte(m14);
      break;
      case 15:
      printByte(m15);
      break;
      case 16:
      printByte(m16);
      break;
      case 17:
      printByte(m17);
      break;
      case 18:
      printByte(m18);
      break;
      case 19:
      printByte(m19);
      break;
      case 20:
      printByte(m20);
      break;
      case 21:
      printByte(m21);
      break;       
    } 
}
 void printByte(byte character [])
{
  int i = 0;
  for(i=0;i<8;i++)
  {
    lc.setRow(0,i,character[i]);
  }
}
long Distance(long time)
{
  long DistanceCalc;                      // Calculation variable
   
  DistanceCalc = ((time * 0.034) / 2);     // Actual calculation in cm
    //DistanceCalc = time / 74 / 2;         // Actual calculation in inches
  return DistanceCalc;                    // return calculated value
}
