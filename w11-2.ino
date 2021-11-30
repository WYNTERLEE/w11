#include <BluetoothSerial.h>
BluetoothSerial BT;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  BT.begin("003");//請改名
  pinMode(12,OUTPUT);
  pinMode(13,OUTPUT);
  pinMode(14,OUTPUT);
  pinMode(27,OUTPUT);
}
int i=0,j=0;
void loop() {
  // put your main code here, to run repeatedly:
  while (BT.available()) {
    //讀取藍芽資料
    String BTdata=BT.readString();
    if( BTdata=="P1 gets one point") {
      i++;
      if(i==1)digitalWrite(12,HIGH);
      else if(i==2){
        digitalWrite(13,HIGH);
        i=0;
      }
    }
    else if( BTdata=="P2 gets one point") {
      j++;
      if(j==1)digitalWrite(14,HIGH);
      else if(j==2){
        digitalWrite(27,HIGH);
        j=0;
      }
    }
    else if( BTdata=="new game") {
      digitalWrite(27,LOW);
      digitalWrite(12,LOW);
      digitalWrite(13,LOW);
      digitalWrite(14,LOW);
      i=0;
      j=0;
    }
    //顯示在序列視窗
    Serial.println(BTdata);
  }
  delay(1);
 

}
