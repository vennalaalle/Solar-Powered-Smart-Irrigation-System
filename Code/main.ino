#include <SoftwareSerial.h>

int sensor;
int data;
int pump_status;

SoftwareSerial esp8266(3, 4);

#define DEBUG true
#define SSID "your_ssid"
#define PASS "your_password"

void sendAT(String command, const int timeout, boolean debug) {
  String response = "";
  esp8266.print(command);
  long int time = millis();
  while ((time + timeout) > millis()) {
    while (esp8266.available()) {
      char c = esp8266.read();
      response += c;
    }
  }
  if (debug) {
    Serial.print(response);
  }
}

void setup() {
  Serial.begin(9600);
  esp8266.begin(9600);
  sendAT("AT+RST\r\n", 2000, DEBUG);
  sendAT("AT\r\n", 1000, DEBUG);
  sendAT("AT+CWMODE=1\r\n", 1000, DEBUG);
  sendAT("AT+CWJAP=\""SSID"\",\""PASS"\"\r\n", 2000, DEBUG);
  while(!esp8266.find("OK")) {}
  sendAT("AT+CIFSR\r\n", 1000, DEBUG);
  sendAT("AT+CIPMUX=0\r\n", 1000, DEBUG);
}

void loop() {
  sensor = analogRead(A0);
  data = map(sensor, 0, 1023, 100, 0);
  String sensor_value = String(data);
  Serial.print("Soil Moisture: ");
  Serial.println(data);
  if (data < 50) {
    digitalWrite(8, HIGH);
    digitalWrite(9, LOW);
    pump_status = 100;
  } else {
    digitalWrite(8, LOW);
    digitalWrite(9, LOW);
    pump_status = 0;
  }
  String pump = String(pump_status);
  updateTS(sensor_value, pump);
  delay(1000);
}

void updateTS(String T, String P) {
  sendAT("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",80\r\n", 1000, DEBUG);
  delay(2000);
  String cmd = "GET /update?key=YOUR_API_KEY&field1=" + T + "&field2=" + P + "\r\n";
  String cmdlen = String(cmd.length());
  sendAT("AT+CIPSEND=" + cmdlen + "\r\n", 2000, DEBUG);
  esp8266.print(cmd);
  sendAT("AT+CIPCLOSE\r\n", 2000, DEBUG);
  delay(1500);
}
