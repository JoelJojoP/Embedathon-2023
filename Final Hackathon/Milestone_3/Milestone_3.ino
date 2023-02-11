#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <Wire.h>

float x = 0;
float y = 0;
float z = 0;

float err_x, err_y, err_z;

Adafruit_MPU6050 mpu;

void setup(void) {
  Serial.begin(115200);
  mpu.begin();
  mpu.setAccelerometerRange(MPU6050_RANGE_8_G);
  mpu.setGyroRange(MPU6050_RANGE_500_DEG);
  mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  Serial.println("");
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
  //Printing the relative angle
  Serial.print("X: ");
  Serial.print(round(x));
  Serial.print(", Y: ");
  Serial.print(round(y));
  Serial.print(", Z: ");
  Serial.println(round(z));
  delay(10);
}