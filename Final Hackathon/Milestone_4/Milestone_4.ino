#include <ArduinoWebsockets.h>
#include <ESP8266WiFi.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

#define ButtonPin D0

const char* ssid = "";
const char* password = "";

int isConnected = 0;

using namespace websockets;

WebsocketsServer server;
WebsocketsClient client;

float x = 0;
float y = 0;
float z = 0;
float err_x, err_y, err_z;

Adafruit_MPU6050 mpu;

int prevButtonState = 0;

void setup() {
  pinMode(ButtonPin, INPUT);
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  for (int i = 0; i < 15 && WiFi.status() != WL_CONNECTED; i++) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  server.listen(80);
  Serial.println("");
  //Disable sleep mode in MPU6050
  Wire.begin();
  Wire.beginTransmission(0x68);
  Wire.write(0x6B); 
  Wire.write(0);     
  Wire.endTransmission(true);
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  delay(1000);
  //Calibration
  Serial.println("Calibrating....Do not move mpu6050");
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);
  err_x = g.gyro.x;
  err_y = g.gyro.y;
  err_z = g.gyro.z;
  Serial.println("Done");
  Serial.println("");
}

void loop() {
  sensors_event_t a, g, temp;
  //Getting various values from MPU6050
  mpu.getEvent(&a, &g, &temp);
  //Calculating relative angle
  float vel_x = g.gyro.x - err_x;
  float vel_y = g.gyro.y - err_y;
  float vel_z = g.gyro.z - err_z;
  float cur_x = vel_x * 0.573;
  float cur_y = vel_y * 0.573;
  float cur_z = vel_z * 0.573;
  x = (cur_x >= 0.03 || cur_x <= -0.03) ? (x + cur_x * 1.36) : x;
  y = (cur_y >= 0.03 || cur_y <= -0.03) ? (y + cur_y * 1.36) : y;
  z = (cur_z >= 0.03 || cur_z <= -0.03) ? (z + cur_z * 1.36) : z;
  //Storing all values to a String
  String msg = "X:" + String(round(x)) + ",Y:" + String(round(y)) + ",Z:" + String(round(z));
  if (isConnected == 0) {
    client = server.accept();
    isConnected = 1;
  }
  if (client.available()) {
    if (digitalRead(ButtonPin) == 1 && prevButtonState == 0) {
      client.send("Button Pressed");
      Serial.println("Sent: Button Pressed");
      prevButtonState = 1;
    } else if(digitalRead(ButtonPin) == 0){
      client.send(msg);
      Serial.print("Sent: ");
      Serial.println(msg);
      prevButtonState = 0;
    }
  } else {
    isConnected = 0;
  }
  delay(10);
}
