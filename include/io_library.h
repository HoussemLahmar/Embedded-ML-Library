#ifndef IO_LIBRARY_H
#define IO_LIBRARY_H

#include <stdint.h>

// Initialize sensors and actuators
void io_init();

// Read sensor data (e.g., ADC)
int32_t read_sensor_data();

// Write actuator data (e.g., PWM, DAC)
void write_actuator_data(int32_t value);

#endif // IO_LIBRARY_H