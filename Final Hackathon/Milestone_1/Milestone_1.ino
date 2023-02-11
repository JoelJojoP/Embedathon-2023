#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(115200);
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.println("");
  delay(100);
}

void loop() {
  sensors_event_t a, g, temp;
  //Getting data from MPU6050
  mpu.getEvent(&a, &g, &temp);
  //Printing the data
  Serial.print("accel X: ");
  Serial.print(a.acceleration.x);
  Serial.print(", accel Y: ");
  Serial.print(a.acceleration.y);
  Serial.print(", accel Z: ");
  Serial.print(a.acceleration.z);
  Serial.print(" m/s^2");
  Serial.print(", rot X: ");
  Serial.print(g.gyro.x);
  Serial.print(", rot Y: ");
  Serial.print(g.gyro.y);
  Serial.print(", rot Z: ");
  Serial.print(g.gyro.z);
  Serial.println(" rad/s");
  delay(500);
}