# Simple multithreaded sensor-actuator system

## Overview
This project is a multi-threaded simulation of various tasks, implemented in C using `pthread` for concurrency. The application simulates multiple real-world processes running concurrently, including:

1. Blinking LEDs connected to GPIO pins.
2. Temperature readings from two sensors.
3. Logging system uptime.

Each task is run as a separate thread, and the application demonstrates how to use threads for concurrent execution in an embedded systems simulation.

---

## Features

1. **LED Blink Simulation**:
   - Two tasks simulate LEDs connected to GPIO pins 13 and 14.
   - LEDs blink on and off at a specified interval (500ms).

2. **Temperature Reading**:
   - Two tasks simulate temperature sensors.
   - Each sensor generates a random temperature value between 20°C and 30°C, converted to Fahrenheit.

3. **System Uptime Logging**:
   - Logs the time elapsed since the application started, every 3 seconds.

---

## Code Description

### Global Variables
- `time_t startTime`: Stores the application start time for calculating system uptime.

### Threads and Tasks
1. **Task 1: LED Blink (GPIO Pin 13)**
   - Simulates a blinking LED by printing messages to the console.
   - Uses a sleep interval of 500ms.

2. **Task 2: Temperature Reading (Sensor 1)**
   - Simulates a temperature sensor generating random values between 20°C and 30°C.
   - Converts the temperature to Fahrenheit and prints it.
   - Runs every 1 second.

3. **Task 3: System Uptime Logger**
   - Logs the system uptime in seconds, calculated using the difference between the current time and `startTime`.
   - Logs uptime every 3 seconds.

4. **Task 4: LED Blink (GPIO Pin 14)**
   - Simulates a second blinking LED on a different GPIO pin.
   - Uses a sleep interval of 500ms.

5. **Task 5: Temperature Reading (Sensor 2)**
   - Simulates a second temperature sensor with the same behavior as Sensor 1.

### Main Function
- Initializes `startTime`.
- Creates threads for all tasks using `pthread_create`.
- Each thread runs its corresponding task function.
- Waits for threads to finish using `pthread_join` (not applicable as tasks run infinitely).

---

## How to Build and Run

### Prerequisites
- GCC compiler with pthread support.
- Linux or Unix-based operating system (threads are POSIX-compliant).

### Build
To compile the program, use the following command:
```bash
gcc -std=c11 -pthread -o simulation simulation.c
```

### Run
Execute the program using:
```bash
./simulation
```

### Expected Output
The program will print outputs from all tasks to the console:

1. LED blinking messages:
   ```
   LED on GPIO Pin 13 is ON
   LED on GPIO Pin 13 is OFF
   LED on GPIO Pin 14 is ON
   LED on GPIO Pin 14 is OFF
   ```

2. Temperature readings:
   ```
   Temperature: 25°C (77.0°F)
   Temperature Sensor 2: 27°C (80.6°F)
   ```

3. Uptime log:
   ```
   System Uptime: 3 seconds
   System Uptime: 6 seconds
   ```

---

## File Structure
```plaintext
simulation.c  // Main program file containing all task functions and threading logic.
```

---

## Key Concepts Demonstrated

1. **Multi-threading**:
   - Using `pthread_create` to create concurrent tasks.
   - Managing shared resources across threads.

2. **Random Number Generation**:
   - Simulating temperature readings with `rand()`.

3. **Concurrency Control**:
   - Demonstrating independent execution of multiple tasks.

4. **POSIX Threads (pthreads)**:
   - Usage of POSIX-compliant threading API for embedded systems simulations.

---

## Limitations
- Tasks run infinitely, so the application does not terminate on its own.
- No thread synchronization is used as tasks operate independently.

---

## Potential Improvements
- Add thread synchronization mechanisms if shared resources are introduced.
- Use configuration files or command-line arguments to set GPIO pins or intervals dynamically.
- Allow user input to control tasks (e.g., toggle LED blinking).
- Add a mechanism to gracefully stop threads and terminate the program.


