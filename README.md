## **README.md for Timer Project**

# ⏲️ Timer Charging Unit

> A simple Arduino-based timer that indicates charge status via an LED and enforces a cooldown period.

---

## 📖 Description

When powered on, the **LED** glows continuously for **1 minute** to indicate startup.
After this initial period, the unit enters a **1-hour charging** cycle; during this time the LED remains on.
Once charging is complete, the LED turns off automatically, and the system locks out for **24 hours**, during which the LED remains off and charging is disabled.

---

## 📂 Project Files

```
Timer_Project/
├── Timer.ino       # Arduino sketch implementing LED timing logic
└── README.md       # This documentation file
```

---

## ⚙️ Hardware Setup

* **Arduino UNO** (or compatible board)
* **LED** with appropriate resistor
* **Power supply** (e.g., USB or battery pack)

---

## 🚀 Installation & Usage

1. **Open** `Timer.ino` in the Arduino IDE.
2. **Connect** your Arduino board via USB.
3. **Select** the correct board and port under **Tools**.
4. **Upload** the sketch.
5. **Power cycle** the unit to start the timing sequence.

---

## 📷 Circuit Diagram

> *Insert your circuit schematic here*


![Timer Charging Unit ](https://github.com/user-attachments/assets/ba5833c1-ff16-437f-8f9e-ff53e74009d0)

---

## 🔧 Configuration

Within `Timer.ino`, you can adjust the timing constants near the top of the file:

```cpp
const unsigned long STARTUP_DELAY = 60000UL;      // 1 minute in milliseconds
const unsigned long CHARGE_DURATION = 3600000UL;  // 1 hour in milliseconds
const unsigned long COOLDOWN_PERIOD = 86400000UL; // 24 hours in milliseconds
const int LED_PIN = 13;                           // On-board LED pin
```

Modify these values to change durations or LED pin assignments.

---

## 🛠️ How It Works

1. **Power On** →  waits `STARTUP_DELAY`, LED on
2. **Charging Phase** →  runs for `CHARGE_DURATION`, LED on
3. **Cooldown Phase** →  runs for `COOLDOWN_PERIOD`, LED off
4. **Cycle Reset** → repeats from step 1 after cooldown

---

## 📜 License

MIT © 2025 Tharindu Chanaka

---

> Built with Arduino and 💡 by \Tharindu Chanaka
