# 💡 IoT-Based Smart LED Control Using Blynk Cloud

An IoT-based LED control project using **ESP32** and **Blynk Cloud**, allowing users to remotely turn an LED **ON/OFF** through the **Blynk mobile dashboard** in real time.

This project was developed as part of learning **cloud-based IoT device control** in a workshop organized by the IEEE DIU Student Branch.

---

## 🚀 Features

- 📱 Control LED remotely using the **Blynk App**
- ☁️ Cloud-based communication using **Blynk Cloud**
- ⚡ Real-time LED ON/OFF control
- 🔌 Wireless operation using **ESP32 WiFi**
- 🛠 Beginner-friendly IoT project

---

## 🧰 Components Used

- **ESP32 Development Board**
- **LED**
- **Jumper Wires**
- **Breadboard**
- **Blynk Mobile App**
- **WiFi Connection**

---

## ⚙️ Working Principle

The ESP32 connects to a WiFi network and communicates with **Blynk Cloud**.  
A button widget in the **Blynk Dashboard** sends a signal through **Virtual Pin V0**.

- **Button ON → LED turns ON**
- **Button OFF → LED turns OFF**

This enables real-time wireless control of an LED from anywhere with an internet connection.

---

## 🔌 Circuit Connection

| Component | ESP32 Pin |
|------------|------------|
| LED Positive (+) | GPIO 23 |
| LED Negative (-) | GND (through resistor) |

---

## 📲 Blynk Dashboard Setup

1. Create a new template in **Blynk IoT**
2. Add a **Button Widget**
3. Set the widget to:
   - **Virtual Pin:** `V0`
   - **Mode:** `Switch`
4. Copy the:
   - `BLYNK_TEMPLATE_ID`
   - `BLYNK_TEMPLATE_NAME`
   - `BLYNK_AUTH_TOKEN`

5. Replace them in the code.

---

## 📦 Required Libraries

Install the following libraries in **Arduino IDE**:

- `WiFi.h`
- `WiFiClient.h`
- `BlynkSimpleEsp32.h`

You can install the **Blynk Library** from the Arduino Library Manager.

---

## 🖥️ Code Overview

The project works by listening to the state of a **Blynk button widget** connected to **Virtual Pin V0**.

```cpp
BLYNK_WRITE(V0)
{
  int switchState = param.asInt();

  if (switchState == 1)
  {
    digitalWrite(ledPin, HIGH);
  }
  else
  {
    digitalWrite(ledPin, LOW);
  }
}
```

When the button state changes:

- `1` → LED turns **ON**
- `0` → LED turns **OFF**

---

## 🛠 Setup Instructions

1. Clone this repository:

```bash
git clone https://github.com/CoderTahmid/IoT-Based-LED-Control
```

2. Open the project in **Arduino IDE**

3. Update your WiFi credentials:

```cpp
char ssid[] = "Your_WiFi_Name";
char pass[] = "Your_WiFi_Password";
```

4. Add your **Blynk Credentials**:

```cpp
#define BLYNK_TEMPLATE_ID "YOUR_TEMPLATE_ID"
#define BLYNK_TEMPLATE_NAME "YOUR_TEMPLATE_NAME"
#define BLYNK_AUTH_TOKEN "YOUR_AUTH_TOKEN"
```

5. Select your ESP32 board and upload the code.

6. Open the **Blynk App** and control the LED remotely 🎉

---

## 🎯 Learning Outcome

Through this project, I learned:

- Basics of **IoT Communication**
- Working with **Blynk Cloud**
- Connecting **ESP32 with WiFi**
- Remote hardware control using **cloud platforms**
- Real-time device interaction

---

## 📚 Project Inspiration

This project was developed while learning IoT cloud integration concepts in a workshop organized by the **IEEE DIU Student Branch**.

---

## 📄 License

This project is released under the **[MIT License](LICENSE)**.

---

### ⭐ If you found this project helpful, consider giving it a star!