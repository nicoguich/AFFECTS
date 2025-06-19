
#define CH1 4
#define CH2 5
#define CH3 6
#define CH4 9
#define CH5 10
int ch1Value, ch2Value , ch3Value ;
int roue_gauche=3;
int roue_droite=11;
float vitesse_roue_gauche, vitesse_roue_droite;


int readChannel(int channelInput, int minLimit, int maxLimit, int defaultValue){
  int ch = pulseIn(channelInput, HIGH);

  if (ch < 100) return defaultValue;
 if(channelInput==CH1)return map(ch, 880, 2100, minLimit, maxLimit);
  if(channelInput==CH2) return map(ch, 1150, 1700, minLimit, maxLimit);
  if(channelInput==CH3) {
   if ((ch<2000)&&(ch>1000)){
    return 0;
   } 
   else{
    return 1;
   }
  }
}




void setup() {
    Serial.begin(115200);
pinMode(12,OUTPUT);
pinMode(13,OUTPUT);
pinMode(roue_gauche,OUTPUT);
pinMode(roue_droite,OUTPUT);



  pinMode(CH1, INPUT);



}

void loop() {


 ch1Value = readChannel(CH1, -255, 255, 0);
 ch2Value = readChannel(CH2, -255, 255, 0);
  ch3Value = readChannel(CH3, -255, 255, 0);

 if (ch1Value>255) ch1Value=255;
  if (ch1Value<-255) ch1Value=-255;
   if (ch2Value>255) ch2Value=255;
  if (ch2Value<-255) ch2Value=-255;

if (ch1Value>0){ ////AVANCE
digitalWrite(12,HIGH);
digitalWrite(13,LOW);
}
else {////RECUL
  digitalWrite(13,HIGH);
digitalWrite(12,LOW);
}

if((ch1Value>-80)&&(ch1Value<80)){
  ch1Value=0;
}

vitesse_roue_gauche=abs(ch1Value)*ch3Value;
vitesse_roue_droite=abs(ch1Value)*ch3Value;
if( ch2Value<0){
vitesse_roue_gauche= float(abs(ch1Value))* (map(ch2Value,-255,0,10,100)/100.0)*ch3Value;
}
else{
 vitesse_roue_droite= float(abs(ch1Value))* (map(ch2Value,255,0,10,100)/100.0)*ch3Value; 
}
 analogWrite(roue_gauche,vitesse_roue_gauche);
 analogWrite(roue_droite,vitesse_roue_droite);



}
