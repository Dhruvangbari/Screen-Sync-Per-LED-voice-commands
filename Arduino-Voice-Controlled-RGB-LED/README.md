# Arduino Voice Controlled RGB LED Strip 🎤💡

Control WS2812B RGB LED strip using voice commands via Python and Arduino.
# Screen Sync Per LED ⚡🎨  
Turn your screen into light.

Screen Sync Per LED is a real-time ambient lighting system where every LED reacts instantly to what’s happening on your display. Colors are sampled directly from the screen and mapped per LED, creating an immersive “screen comes alive” experience.

This project blends **hardware precision**, **Python performance**, and **Arduino reliability** into a smooth, high-FPS visual system.

---

## 🚀 What Makes This Project Special
- Each LED represents a **specific region of the screen**
- Ultra-smooth color transitions with frame-rate control
- Gamma correction for accurate, eye-pleasing colors
- Noise filtering to eliminate flicker and unwanted glow
- Designed for real-time performance, not demos

This is not a static LED effect — it is **live screen intelligence**.

---

## 🔧 Hardware Requirements
- Arduino Uno / Nano  
- WS2812B RGB LED Strip (34 LEDs)  
- External 5V Power Supply  
- USB Cable  
- Common Ground Connection  

⚠️ External power supply is mandatory for stable LED operation.

---

## 🔌 Wiring
| Arduino | WS2812B |
|------|---------|
| D6   | DIN     |
| GND  | GND     |
| 5V PSU | VCC  |

---

## 💻 Software Stack
### Arduino
- Arduino IDE
- Adafruit NeoPixel Library

### Python
- numpy
- mss
- pyserial

Install dependencies:
```bash
pip install -r requirements.txt


## Requirements
- Arduino Uno
- WS2812B LED Strip
- Python + VOSK

## Author
Dhruvang Bari
