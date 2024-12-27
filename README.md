# Hydrogen Gas Detection System with MQ2 Sensor

This project uses an MQ2 sensor to monitor hydrogen gas concentration levels. When the concentration exceeds a defined threshold, the system triggers a buzzer and a red LED alert. The gas concentration is displayed on an LCD screen for real-time monitoring.

---

## Features
- **Hydrogen Gas Monitoring**: Measures hydrogen gas concentration using the MQ2 sensor.
- **LCD Display**: Real-time display of hydrogen gas readings on a 16x2 LiquidCrystal display.
- **Alert System**: Activates a buzzer and a red LED if the hydrogen gas concentration exceeds the set threshold.
- **Serial Output**: Logs the sensor readings to the serial monitor for debugging and analysis.

---

## Components Required
1. **Arduino Board** (e.g., Uno, Mega, etc.)
2. **MQ2 Sensor**
3. **16x2 LCD Display**
4. **Red LED**
5. **Buzzer**
6. **Resistors** (for LED and sensor connections)
7. **Connecting Wires**
8. **Power Supply**

---

## Pin Configuration
| Component           | Pin Name         | Arduino Pin |
|----------------------|------------------|-------------|
| MQ2 Sensor Signal    | `hydrogenSensor` | A1          |
| Red LED              | `redLed`         | 13          |
| Buzzer               | `buzzer`         | 7           |
| LCD RS               | `rs`             | 12          |
| LCD Enable           | `en`             | 11          |
| LCD Data 4           | `d4`             | 5           |
| LCD Data 5           | `d5`             | 4           |
| LCD Data 6           | `d6`             | 3           |
| LCD Data 7           | `d7`             | 2           |

---

## Setup Instructions
1. **Hardware Setup**:
   - Connect the MQ2 sensor's signal pin to analog pin A1.
   - Connect the red LED to digital pin 13 through a resistor.
   - Connect the buzzer to digital pin 7.
   - Wire the 16x2 LCD as per the pin configuration table.
   - Ensure a stable power supply for the components.

2. **Software Setup**:
   - Install the **MQ2 library** for Arduino. Use `Tools > Manage Libraries` to search and install the library.
   - Upload the provided code to your Arduino board.

---

## Threshold Customization
The default threshold for triggering alerts is set to `100`. You can adjust this value by modifying the `sensorThresh` variable:
```cpp
float sensorThresh = 100; // Adjust this value as needed
```

---

## Troubleshooting
1. No Sensor Reading: Ensure the MQ2 sensor is connected properly and powered. Check the serial monitor for debugging output.
1. Alert Not Triggering: Verify the threshold value and ensure the sensor is detecting gas concentration above this level.
1. LCD Not Working: Double-check wiring and ensure the LiquidCrystal library is installed.

---

## License
This project is licensed under the MIT License.

---

## Acknowledgments
This system demonstrates an easy and effective method to monitor hydrogen gas levels using the MQ2 sensor and Arduino. Customize it further to meet specific use cases!