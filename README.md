# IoT Water Quality Monitoring System
A real-time water quality monitoring system built with Arduino Uno R3, featuring pH and Total Dissolved Solids (TDS) sensors with an OLED display interface.
- Real-time pH level monitoring.
- TDS (Total Dissolved Solids) measurement in PPM.
- Visual data output on a 0.96" I2C OLED display.
- Serial data logging for PC-based monitoring.

# Hardware Requirements
- Microcontroller: Arduino Uno R3.
- pH Sensor: Analog pH Sensor Kit.
- TDS Sensor: Analog TDS Meter Sensor.
- Display: OLED 0.96 inch (SSD1306) via I2C.
- Power Supply: 5V DC.

# Connection Diagram
| Component         | Sensor Pin     | Arduino Pin |
| OLED Display      | VCC/GND/SCL/SDA| 5V/GND/A5/A4|
| pH Sensor         | Analog Out (Po)| A0          |
| TDS Sensor        | Analog Out     | A1          |

# Library Dependencies
Install the following libraries via Arduino Library Manager:
1. Adafruit SSD1306
2. Adafruit GFX Library`
3. Wire (Built-in)

# How to Use
1. Install the required libraries in your Arduino IDE.
2. Connect the hardware according to the wiring table.
3. Upload the `main.ino` sketch to your Arduino Uno.
4. Submerge the sensor probes into the water sample and view the results on the OLED screen.

# Important Notes
- Calibration: Ensure you calibrate the pH sensor using standard buffer solutions (pH 4.0/7.0) before use.
- Safety: Keep the electronic circuit dry; only the sensor probes should be submerged.
- Temperature: For better accuracy, consider adding a DS18B20 sensor for temperature compensation.
