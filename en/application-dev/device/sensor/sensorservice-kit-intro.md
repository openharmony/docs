# Introduction to Sensor Service Kit

## When to Use

Sensor Service Kit enables applications to obtain raw data from sensors and provides vibration control capabilities.

- The sensor module provides APIs for applications to access the underlying sensor hardware. Using these APIs, you can query sensors on your device and subscribe to sensor data. Based on the sensor data obtained, you can customize algorithms and develop various sensor-based applications, such as compass, motion-controlled games, and fitness and health applications.

- The vibrator module maximally unlocks the capabilities of the vibrator device. By expanding the vibrator services, it achieves an integrated design of vibration and interaction, creating a delicate and sophisticated vibration experience that takes user interaction efficiency and usability to the next level.

## Constraints

### Sensor

- To use sensor functions, ensure that the device where your application runs has the required sensor components.

- To obtain data of some sensors, you need to request the required permissions.

- The APIs for subscribing to and unsubscribing from sensor data work in pairs. If you do not need sensor data, call the unsubscription API to stop sensor data reporting.


### Vibrator

- To use vibrator functions, ensure that the device where your application runs has the required misc components.
- To use vibrators, you need to request the required permissions.
