#ifndef MICROCONTROLLER_CONFIG_H
#define MICROCONTROLLER_CONFIG_H

// Define microcontroller-specific settings
#ifdef ESP32
    #define ADC_RESOLUTION 12        // 12-bit ADC resolution
    #define PWM_RESOLUTION 8         // 8-bit PWM resolution
    #define MAX_MEMORY_USAGE 32000   // 32 KB max memory
#elif STM32
    #define ADC_RESOLUTION 16        // 16-bit ADC resolution
    #define PWM_RESOLUTION 16        // 16-bit PWM resolution
    #define MAX_MEMORY_USAGE 64000   // 64 KB max memory
#else
    #error "Unsupported microcontroller!"
#endif

#endif // MICROCONTROLLER_CONFIG_H