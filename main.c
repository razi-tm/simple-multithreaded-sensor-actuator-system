#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

// Global variable to store start time
time_t startTime;

// Simulate task 1: LED Blink (Just printing to simulate)
void* taskBlinkLED(void* arg) {
    const int ledPin = *((int*)arg);
    while (1) {
        printf("LED on GPIO Pin %d is ON\n", ledPin);
        usleep(200000); // Sleep for 500ms
        printf("LED on GPIO Pin %d is OFF\n", ledPin);
        usleep(200000); // Sleep for 500ms
    }
}

// Simulate task 2: Temperature reading (Random temperature)
void* taskReadTemperature(void* arg) {
    srand(time(NULL));
    while (1) {
        int tempC = rand() % 11 + 20; // Random temperature in range [20, 30]
        float tempF = tempC * 9.0 / 5.0 + 32; // Convert to Fahrenheit
        printf("Temperature: %d°C (%.1f°F)\n", tempC, tempF);
        usleep(1000000); // Sleep for 1 second
    }
}

// Task 3: Log system uptime every 2 seconds
void* taskLogUptime(void* arg) {
    while (1) {
        time_t currentTime = time(NULL);
        printf("System Uptime: %ld seconds\n", currentTime - startTime);
        usleep(3000000); // Sleep for 2 seconds
    }
}

// Task 4: Simulate LED on Pin 14
void* taskBlinkLED2(void* arg) {
    const int ledPin = *((int*)arg);
    while (1) {
        printf("LED on GPIO Pin %d is ON\n", ledPin);
        usleep(500000); // Sleep for 500ms
        printf("LED on GPIO Pin %d is OFF\n", ledPin);
        usleep(500000); // Sleep for 500ms
    }
}

// Task 5: Simulate another temperature sensor
void* taskReadTemperature2(void* arg) {
    srand(time(NULL));
    while (1) {
        int tempC = rand() % 11 + 20; // Random temperature in range [20, 30]
        float tempF = tempC * 9.0 / 5.0 + 32; // Convert to Fahrenheit
        printf("Temperature Sensor 2: %d°C (%.1f°F)\n", tempC, tempF);
        usleep(1000000); // Sleep for 1 second
    }
}

int main() {
    startTime = time(NULL);  // Record start time

    pthread_t task1, task2, task3, task4, task5;
    int ledPin1 = 13, ledPin2 = 14;

    // Create the tasks (threads)
    pthread_create(&task1, NULL, taskBlinkLED, &ledPin1);
    pthread_create(&task2, NULL, taskReadTemperature, NULL);
    pthread_create(&task3, NULL, taskLogUptime, NULL);
    pthread_create(&task4, NULL, taskBlinkLED2, &ledPin2);  // New LED task
    pthread_create(&task5, NULL, taskReadTemperature2, NULL);  // New temperature sensor task

    // Wait for the tasks to finish (they won't in this case as they run infinitely)
    pthread_join(task1, NULL);
    pthread_join(task2, NULL);
    pthread_join(task3, NULL);
    pthread_join(task4, NULL);
    pthread_join(task5, NULL);

    return 0;
}
