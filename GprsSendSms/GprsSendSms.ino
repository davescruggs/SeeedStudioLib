/*
GPRS Connect TCP

This sketch is used to test seeeduino GPRS_Shield's send SMS func.
to make it work, you should insert SIM card to Seeeduino GPRS 
and replace the phoneNumber,enjoy it!

create on 2013/12/5, version: 0.1
by lawliet.zou(lawliet.zou@gmail.com)
*/
#include <GPRS_Shield_Arduino.h>
#include <SoftwareSerial.h>
#include <Wire.h>
#include <Suli.h>

#define PIN_TX    7
#define PIN_RX    8
#define BAUDRATE  9600
// send the SMS to Jasper
#define PHONE_NUMBER "5277" 
#define MESSAGE  "Sending SMS via Arduino and Jasper"
#define APN  "jaspermo.apn" 

GPRS gprsTest(PIN_TX,PIN_RX,BAUDRATE, APN);//RX,TX,BaudRate

void setup() {
  Serial.begin(9600);
  while(0 != gprsTest.init()) {
      delay(1000);
      Serial.print("init error\r\n");
  }  
  Serial.println("gprs init success");
  Serial.println("start to send message ...");
  int smsCode = gprsTest.sendSMS(PHONE_NUMBER,MESSAGE); //define phone number and text
  Serial.println("SMS Result Code: " + smsCode );
  if (smsCode == 0){
    Serial.println("SMS Sent successfully");
  } else {
    Serial.println("SMS Failed to send");
  }
}

void loop() {
  //nothing to do
}

