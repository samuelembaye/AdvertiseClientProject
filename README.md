Advertise Client Project

This repository contains the source code and implementation for the Advertise Client Project, designed to run on an Arduino Uno microcontroller. The project utilizes an HD44780 LCD display and push buttons to facilitate advertising functions.

Features

Arduino Uno-based: Utilizes the Arduino Uno microcontroller for processing.

HD44780 LCD Display: Displays advertisements and relevant messages.

Push Buttons: Enables user interaction and control.

Randomized Advertisement Display: Advertisements are shown with a weighted random frequency based on the amount paid by the client.

Payment-Based Weighting: The more a client pays, the more frequently their advertisement is displayed compared to others.

Real-Time Functionality: Ensures timely updates and smooth operation.

UART Communication for Developers: Provides serial output for debugging and monitoring advertisement display behavior.

Wokwi Simulation

The project is available for simulation on Wokwi:
Wokwi Simulation https://wokwi.com/projects/416265405337257985

Components Used

Arduino Uno

HD44780 LCD Display (16x2 or 20x4)

Push Buttons

Resistors & Other Supporting Components

Installation & Setup

Clone the repository:

git clone https://github.com/samuelembaye/AdvertiseClientProject.git
cd AdvertiseClientProject

Install Required Libraries:
Ensure you have the following Arduino libraries installed:

LiquidCrystal

Upload to Arduino Uno:

Open the project hex file in Arduino IDE.

Select the appropriate board (Arduino Uno).

Upload the code.

Usage

Power on the Arduino Uno.

The LCD will display initial boot messages.

Advertisements will be displayed with a frequency weighted by the amount the client has paid.

Clients who pay more will have their advertisements displayed more frequently than those who pay less.

Use push buttons to navigate through advertisements manually if needed.

Monitor Serial Output: Connect to the Arduino Uno via UART (Serial Monitor in Arduino IDE) to view debugging messages and advertisement display logs.


Author

Developed by Samuel Embaye.


