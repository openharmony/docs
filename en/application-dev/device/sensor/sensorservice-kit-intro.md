# Introduction to Sensor Service Kit

## When to Use

Sensor Service Kit enables applications to obtain raw data from sensors and provides vibration control capabilities.

- The sensor module provides APIs for applications to access the underlying sensor hardware. Using these APIs, you can query sensors on your device and subscribe to sensor data. Based on the sensor data obtained, you can customize algorithms and develop various sensor-based applications, such as compass, motion-controlled games, and fitness and health applications.
  - Local sensors: sensors built into the device. Typical examples include accelerometers, gyroscopes, and temperature sensors.
  - Dynamic sensors: external sensors. The sensor module supports refined control over dynamic sensors, and listening for status changes (such as connection and disconnection) of dynamic sensors can be enabled or disabled via the **on** or **off** API.

- The vibrator module maximally unlocks the capabilities of the vibrator device. By expanding the vibrator services, it achieves an integrated design of vibration and interaction, creating a delicate and sophisticated vibration experience that takes user interaction efficiency and usability to the next level.
  - Local vibrators: vibrators built into the device. Typical examples include rotor vibrators and linear vibrators.
  - Dynamic vibrators: external vibrators, which support independent control and management based on information such as device connection status and vibrator status. Dynamic vibrators are widely used in peripherals, including game controllers and external vibrators.


## Constraints

### Sensor

- To use sensor functions, ensure that the device where your application runs has the required sensor components.

- To obtain data of some sensors, you need to request the required permissions.

- The APIs for subscribing to and unsubscribing from sensor data work in pairs. If you do not need sensor data, call the unsubscription API to stop sensor data reporting.

- If a dynamic sensor is disconnected, the application needs to disable listening for sensor data changes.

### Vibrator

- To use vibrator functions, ensure that the device where your application runs has the required misc components.
- To use vibrators, you need to request the required permissions.
- If there are multiple devices and vibrators, the application must determine which vibrator to use.
