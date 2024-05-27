# MSP430x2xx-C-Based-State-Machine-Timers-Lab-2-

Welcome to my GitHub repository showcasing an advanced embedded system programmed in C, focusing on a finite state machine (FSM) for managing various peripherals on MSP430x2xx microcontrollers. This project demonstrates how to handle complex hardware interactions through state-driven logic, promoting efficient and modular code architecture ideal for educational and development purposes.

# Features

Modular Design: Organized into multiple layers including Application (APP), Board Support Package (BSP), Hardware Abstraction Layer (HAL), and Application Programming Interface (API), enhancing maintainability and scalability.

Finite State Machine (FSM): Manages system states and transitions to handle different operational modes effectively, ensuring a robust and responsive system.

Peripheral Management: Utilizes GPIOs for controlling devices like LEDs, LCDs, and other hardware components based on the system state, showcasing direct hardware control in a low-level embedded environment.

Low Power Management: Implements various low-power modes to optimize power consumption, crucial for battery-operated and energy-efficient applications.

# FSM States and Operations

The FSM in this project employs multiple states to facilitate detailed system control:

state0 (Idle State): The default state post-reset where the system remains until user interaction or an external event triggers a transition.

state1 to state4: These states are tasked with specific operational roles including input reading, output management, setting adjustments, and handling alerts or errors.

State transitions are event-driven, providing a predictable and structured system response.

# Interrupt Handling

Efficient interrupt management ensures that the system promptly addresses hardware events without delay, which is vital for maintaining real-time performance and reliability.

# Project Structure

api.h & api.c: Define the application programming interface for peripheral interaction.

app.h: Declares global variables, FSM states, and system modes.

bsp.h & bsp.c: Contains hardware-specific configurations and initializations for the MSP430x2xx.

halGPIO.h & halGPIO.c: Hardware abstraction functions for GPIO management and other basic hardware functionalities.

main.c: The main executable file that sets up the system and hosts the operational loop.

# Getting Started

To get this project up and running on your MSP430 device:

1. Set up your MSP430 development environment using tools like Code Composer Studio or MSPGCC.
2. Clone this repository to your local machine.
3. Open the project in your IDE and navigate to the main directory.
4. Compile the code using an MSP430-compatible compiler.
5. Flash the compiled binary to your MSP430 microcontroller.
6. Reset the device to start the application in its default state.
