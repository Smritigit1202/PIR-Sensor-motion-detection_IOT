# 🚨 IoT Motion Detection System using ESP32, PIR Sensor, and Firebase (REST API)


Project link - https://wokwi.com/projects/436290906667118593



This project detects motion using a PIR sensor connected to an ESP32 microcontroller. When motion is detected, an LED is turned on and the motion status (`true` or `false`) is sent to Firebase Realtime Database using REST API (`HTTPClient`). Built and tested on Wokwi and can be deployed to a real ESP32 board.

---

## 🔧 Components Used

- ESP32 Dev Module
- PIR Motion Sensor
- LED (with 220Ω resistor)
- Firebase Realtime Database
- Wokwi Simulator / Arduino IDE

---

## Output



https://github.com/user-attachments/assets/c6794cbc-c05d-4772-9856-97b759a3b98c


---

## 📡 Circuit Diagram (Wokwi)

Wiring used:

| Component    | ESP32 Pin |
|--------------|-----------|
| PIR OUT      | D13       |
| LED (via resistor) | D2   |
| VCC/GND      | 3V3 / GND |

---

## 💻 How It Works

1. ESP32 connects to Wi-Fi.
2. PIR detects motion.
3. If motion is detected:
   - LED turns ON.
   - ESP32 sends `true` to Firebase.
4. If no motion:
   - LED turns OFF.
   - Sends `false` to Firebase.

---

## 🔗 Firebase Integration

- Uses **Firebase Realtime Database**
- Sends motion data via **HTTP REST API**
- Example path in DB:

```json
{
  "motion": true
}
