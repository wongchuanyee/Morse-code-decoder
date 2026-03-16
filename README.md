# 📡 Arduino Morse Code Decoder

Hi! This is my **first project — a Morse code decoder**.
This project is a great way for beginners like me to explore **Arduino, electronics, and Morse code communication**. Even if you are already an experienced Arduino user, it can still be an interesting project to build and experiment with.

---

## 👋 Introduction

This project uses **Arduino** to decode Morse code signals and display the decoded letters on a **16×2 LCD screen**.

Users can input Morse code using a **push button**, where:

* Short press → Dot (`.`)
* Long press → Dash (`-`)

The Arduino reads the input sequence and converts it into readable characters.

---

## 🔧 Components

The project uses simple and common components:

* Arduino Uno R3
* 16×2 LCD Display
* 2 × 10k Resistors
* 2 × 10k Variable Resistors (or fixed resistors)
* 2 × Push Buttons
* Breadboard
* Jumper Wires

---

## ⚙️ How It Works

1. Morse code is entered using a **push button**.
2. The Arduino measures the **length of each press**.
3. A short press represents a **dot (`.`)**.
4. A long press represents a **dash (`-`)**.
5. The Arduino converts the Morse sequence into letters.
6. The decoded characters are displayed on the **LCD screen**.

Example Morse decoding:

```
....  -> H
.     -> E
.-..  -> L
.-..  -> L
---   -> O
```

Output:

```
HELLO
```

---

## 🔗 Tinkercad Simulation

You can view the circuit simulation here:

👉 https://www.tinkercad.com/things/h6U81zsr8rP-morse-code-decoder?sharecode=esabLiUHCMmMo1DvcWM9cBhjdUSc721NHDpZMq7un0U

---

## ⭐ Support

If you like this project, consider giving it a **⭐ Star on GitHub**.
It helps others discover this project and supports my learning journey.

---

## 👨‍💻 Author

Created by **Wong Chuan Yee**

GitHub:
https://github.com/wongchuanyee
