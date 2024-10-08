# Waldo :computer_mouse:

**Waldo** is a wireless 3D pen designed for intuitive manipulation of 3D objects in digital environments such as VR, AR, and traditional computer screens. This device integrates motion tracking with wireless communication for seamless user interaction.

## Features

- **Microcontroller:** Arduino Nano (or any Arduino model) as transmitter + Arduino Leonardo (or any Arduino model with HID support) as receiver
- **HID Support:** Compatible with Windows, macOS, and Linux using standard HID protocols. 💻🖥️
- **3D Motion Tracking:** Utilizes MPU6050 sensor for accurate motion capture. 🎯
- **Button Inputs:** Includes left and right click buttons.
- **LED Feedback:** Provides visual indicators for device status.
- **Wireless Communication:** Employs nRF24L01 modules for data transmission.📡

## Hardware Details

- **Microcontroller Pinout:**
  - **VCC:** Power supply
  - **GND:** Ground
  - **SDA:** I2C Data
  - **SCL:** I2C Clock
  - **Buttons:** Connect to digital inputs

## Installation

1. **Pairing:** Connect the transmitter and receiver using nRF24L01 modules. Ensure both devices are powered and within communication range.
2. **Driver Installation:** No additional drivers are required due to HID support.
3. **Calibration:** Power cycle the device to reset the tracking if needed. 🔄

## Usage

- **Power On:** Turn on the pen using the power switch.
- **Motion Control:** Move the pen to interact with 3D objects on your screen.
- **Button Functions:** Use the buttons for left and right click actions.
- **Feedback:** Monitor the Blue LED for device status indicators.

## Troubleshooting

- **Connection Issues:** Ensure wireless module is correctly paired and within range.
- **Tracking Problems:** Recalibrate if motion tracking appears inaccurate.

## License

This project is licensed under the [GNU General Public License (GPL) Version 3](https://www.gnu.org/licenses/gpl-3.0.html). See the LICENSE file for details.

---

Feel free to modify any sections as needed!
