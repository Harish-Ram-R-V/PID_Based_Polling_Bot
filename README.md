# PID_Based_Polling_Bot

#Dual Motor Encoder PID Control (Arduino)

This project controls two DC motors with quadrature encoders using an Arduino.
The motors are driven using PWM signals with direction control, and a PID algorithm ensures that each motor reaches its target position.
Encoder readings are polled manually (no interrupts).
The Serial Monitor displays real-time encoder positions.
The bot movement is controlled by pid control and will succeed to trace back to target position

## Features

    - Dual DC motor control
    - Quadrature encoder feedback (manual polling)
    - PID controller for precise positioning
    - Automatic stop when target is reached
    - Serial monitoring of motor positions

## ⚙️ Hardware Requirements and Software Details
    
    - Arduino Uno (or compatible board)
    - L298N Motor Driver Module (or equivalent)
    - 2x DC motors with encoders
    - Jumper wires and breadboard
    - External power supply for motors (recommended)
    - Language: C++ (Arduino)
    - PID Control Constants:
        - `kp = 1.5`
        - `ki = 0`
        - `kd = 0.5`
    - Position control with encoder-based feedback
    - Adjustable target positions

## 🔌 Pin Connections

| Arduino Pin | Function                 |
|-------------|--------------------------|
| 6           | Motor A IN1              |
| 7           | Motor A IN2              |
| 9           | Motor A ENA (PWM)        |
| 8           | Motor B IN3              |
| 11          | Motor B IN4              |
| 10          | Motor B ENB (PWM)        |
| 2, 3        | Encoder A (ENCA1, ENCA2) |
| 4, 5        | Encoder B (ENCB1, ENCB2) |

## YOU CAN CHECK MY TINKERCAD CIRCUIT SIMULATION HERE:
        https://www.tinkercad.com/things/92b8tpUfThh-pid-based-polling-bot?sharecode=t6l-8ypFhXxbnMB33Pp8_BPIvskeuukTTiN317-wItk

## Future Plan

- Add UI to change target position via Serial
- Add limit switches or safety checks
- Enable interrupt-based encoder reading for better performance

## 📄 License

This project is open-source under the MIT License.

