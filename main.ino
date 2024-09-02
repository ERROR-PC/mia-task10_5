Requirements
• Write an Arduino code (.ino) that reads yaw from an MPU6050 IMU
using I2C without using any library for IMU. [ONLY Wire.h Library is
allowed]

#include <Wire.h>

const int MPU_ADDR = 0x68;  // MPU-6050 I2C address
int16_t gyro_x, gyro_y, gyro_z; // Raw gyro values
float gyro_yaw; // Calculated yaw angle

unsigned long prev_time = 0;
float yaw = 0.0;
float gyro_sensitivity = 131.0;  // Sensitivity scale factor for ±250°/s

void setup() {
  Wire.begin();
  Serial.begin(9600);

  // Wake up the MPU-6050 (it starts in sleep mode)
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x6B);  // Power Management 1 register
  Wire.write(0);     // Set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
}

void loop() {
  // Read gyroscope data
  Wire.beginTransmission(MPU_ADDR);
  Wire.write(0x43);  // Starting with the register 0x43 (GYRO_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU_ADDR, 6, true);  // Request a total of 6 registers

  gyro_x = Wire.read() << 8 | Wire.read();  // GYRO_XOUT_H and GYRO_XOUT_L
  gyro_y = Wire.read() << 8 | Wire.read();  // GYRO_YOUT_H and GYRO_YOUT_L
  gyro_z = Wire.read() << 8 | Wire.read();  // GYRO_ZOUT_H and GYRO_ZOUT_L

  // Convert raw gyroscope value to yaw rate (°/s)
  gyro_yaw = gyro_z / gyro_sensitivity;

  // Calculate elapsed time in seconds
  unsigned long curr_time = millis();
  float elapsed_time = (curr_time - prev_time) / 1000.0;
  prev_time = curr_time;

  // Integrate the yaw rate to get the yaw angle
  yaw += gyro_yaw * elapsed_time;

  // Print yaw angle
  Serial.print("Yaw: ");
  Serial.println(yaw);

  delay(100);
}
