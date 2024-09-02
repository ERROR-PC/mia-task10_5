# MPU6050 Yaw Reader with Wire.h

This repository contains an Arduino sketch for reading the yaw angle from an MPU6050 IMU using I2C communication without using any third-party libraries for the IMU. The only library used is the standard `Wire.h` library, which handles the I2C communication between the Arduino and the MPU6050.

## Features
- **No external libraries**: The code directly interacts with the MPU6050 registers, making it a lightweight and educational example.
- **Yaw calculation**: The yaw (rotation around the Z-axis) is computed by integrating the gyroscope's angular velocity data.
- **Simple setup**: The wiring and code are straightforward, making it easy to understand and modify.

## Requirements
- **Arduino**: Any Arduino board (e.g., Uno, Nano, Mega, Leonardo) with I2C support.
- **MPU6050**: An MPU6050 IMU sensor module.
- **Arduino IDE**: Version 1.8.0 or later.

## Circuit Diagram

### Arduino Uno/Nano/Pro Mini:

| **MPU6050 Pin** | **Arduino Pin** |
|-----------------|-----------------|
| VCC             | 5V/3.3V         |
| GND             | GND             |
| SCL             | A5              |
| SDA             | A4              |

### Arduino Mega:

| **MPU6050 Pin** | **Arduino Pin** |
|-----------------|-----------------|
| VCC             | 5V/3.3V         |
| GND             | GND             |
| SCL             | Pin 21          |
| SDA             | Pin 20          |

### Arduino Leonardo/Micro:

| **MPU6050 Pin** | **Arduino Pin** |
|-----------------|-----------------|
| VCC             | 5V/3.3V         |
| GND             | GND             |
| SCL             | Pin 3           |
| SDA             | Pin 2           |

## Usage

1. **Clone the Repository**:
    ```bash
    git clone https://github.com/ERROR-PC/mia-task10_5.git
    ```
2. **Open the Project**:
   - Open the `.ino` file in the Arduino IDE.

3. **Upload the Sketch**:
   - Select the appropriate board and port from the Arduino IDE.
   - Click on the "Upload" button.

4. **Monitor Serial Output**:
   - Open the Serial Monitor in the Arduino IDE to see the yaw angle being printed out.

## How It Works

1. **I2C Communication**: The `Wire.h` library is used to communicate with the MPU6050 via I2C.
2. **Gyroscope Data**: The sketch reads the raw gyroscope data from the MPU6050's registers.
3. **Yaw Calculation**: The yaw rate is calculated from the gyroscope data, and the yaw angle is determined by integrating this rate over time.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
