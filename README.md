# Arduino Servo Control with PS2 Controller

This repository contains Arduino code for controlling multiple servo motors using a PS2 controller. The project is structured with modular header files to manage different servo functions and testing scripts for debugging and validation.

---

## File Structure

- **`test.ino`**  
  Main Arduino sketch. Integrates all servo control functions and handles input logic.

- **`PS2_test.ino`**  
  Test program for verifying PS2 controller input and communication.

- **`functions.h`**  
  General utility functions shared across the project.

- **`AroundServo_function.h`**  
  Functions related to the control logic of the propellors.

- **`DownServo_function.h`**  
  Functions related to the control logic of the wheels.

---

## Hardware Requirements

- Arduino board (e.g., Arduino Uno / Mega)
- 4 propellors
- 4 wheels
- PS2 controller
- HC12 Blueotooth module for recieving and sending signals
- External power supply for servos
- Wires

---

## How to Use

1. Download this repository.
2. Open `test.ino` in the Arduino IDE.
3. Make sure all `.h` files are in the same folder as the `.ino` file.
4. Connect the PS2 controller according to your wiring setup.
5. Upload the code to your Arduino board.
6. Use `PS2_test.ino` if you need to debug controller input.


---<img width="560" height="360" alt="Program_design_diagram" src="https://github.com/user-attachments/assets/3ef45882-fc2b-4ab1-8cde-7c7fde9927d0" />
<img width="714" height="404" alt="Robot_scheme_design" src="https://github.com/user-attachments/assets/cfb8ea39-e347-4d54-be96-91dc02aa0bec" />
