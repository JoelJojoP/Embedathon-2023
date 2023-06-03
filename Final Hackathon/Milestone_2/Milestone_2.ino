#include <ArduinoWebsockets.h>
#include <ESP8266WiFi.h>

const char* ssid = ""; 
const char* password = ""; 

int isConnected = 0;

using namespace websockets;

WebsocketsServer server;
WebsocketsClient client;

void setup() {
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  for(int i = 0; i < 15 && WiFi.status() != WL_CONNECTED; i++) {
      Serial.print(".");
      delay(1000);
  }
  
  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); 
  server.listen(80);
  Serial.print("Is server live? ");
  Serial.println(server.available());
}

void loop() {
  if(isConnected == 0){
    client = server.accept();
    isConnected = 1;
  }
  if(client.available()) {
    client.send("Hello World");
    Serial.println("Sent: Hello World");
  }
  else {
    isConnected = 0;
  }
  delay(1000);
}
