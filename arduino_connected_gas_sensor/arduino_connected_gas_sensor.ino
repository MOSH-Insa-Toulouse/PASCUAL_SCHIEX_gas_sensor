#include <SoftwareSerial.h>

int sensorPin = A0;
int txPin = 11;
int rxPin = 10;
int resetPin = 12;
int prevSend = 0;

SoftwareSerial loraInter(rxPin,txPin);

void setup() {
  Serial.begin(57600);
  loraInter.begin(57600);
  pinMode(resetPin, OUTPUT);
  pinMode(sensorPin, INPUT);

  // Commandes
  digitalWrite(resetPin, LOW);
  delay(15);
  digitalWrite(resetPin, HIGH);
  delay(500);
  loraInter.println("mac set devaddr 26011629");
  delay(100);
  loraInter.println("mac set nwkskey EE16CF5C0A472943DB79AD76661C663F");
  delay(100);
  loraInter.println("mac set appskey 0E0BA5CD1CA720DAECAF132B36ADD34A");
  delay(100);
  loraInter.println("mac join abp");
  delay(100);  
}

void loop() {
  // Sending value if > 400
  int value = analogRead(sensorPin);
  int currTime = millis();
  
  // Sending new value only if 5sec has passed since prev send
  if(value > 400 && (currTime-prevSend>5000) ){
    Serial.print("Previous send was ");
    Serial.print(currTime-prevSend);
    Serial.println(" ago.");
    prevSend = millis();
    String message = "mac tx uncnf 48 ";
    message += value;
    Serial.println("Sending message " + message + " to LoRa chip.");
    loraInter.println(message);
  }

  // Forwarding message from LoRa chip to arduino serial
  if(loraInter.available()){
    String response;
    char currChar = loraInter.read();
    while(currChar!='\n'){
      response += currChar;
      currChar = loraInter.read();
    }
    Serial.println(response);
  }  
}
