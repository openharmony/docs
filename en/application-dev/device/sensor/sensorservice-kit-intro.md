# Introduction to Sensor Service Kit

## When to Use

Sensor Service Kit enables applications to obtain raw data from sensors and provides vibration control capabilities.

- The sensor module provides APIs for applications to access the underlying sensor hardware. Using these APIs, you can query sensors on your device and subscribe to sensor data. Based on the sensor data obtained, you can customize algorithms and develop various sensor-based applications, such as compass, motion-controlled games, and fitness and health applications.
  - Local sensors: sensors built into the device. Typical examples include accelerometers, gyroscopes, and temperature sensors.
  - Dynamic sensors: external sensors. The sensor module supports refined control over dynamic sensors, To manage dynamically connected devices, use **sensor.on()** to enable listening for device status change events. When receiving a device disconnection event, you must call **sensor.off()** to disable event listening for this device to prevent memory leaks or API call exceptions.

- The vibrator module maximally unlocks the capabilities of the vibrator device. By expanding the vibrator services, it achieves an integrated design of vibration and interaction, creating a delicate and sophisticated vibration experience that takes user interaction efficiency and usability to the next level.
  - Local vibrators: vibrators built into the device. Typical examples include rotor vibrators and linear vibrators.
  - Dynamic vibrators: external vibrators, which support independent control and management based on information such as device connection status and vibrator status. Dynamic vibrators are widely used in connected devices, such as joysticks, remote controls, and external vibrators. To manage these devices, use **vibrator.on('vibratorStateChange', callback)** to enable listening for device connection and disconnection events.


## Constraints

### Sensor

- To use sensor functions, ensure that the device where your application runs has the required sensor components.

- To obtain data of certain sensors, you need to request the required permissions.

- The **on** and **off** APIs work in pairs. If listening for sensor data is no longer needed, call the **off** API to disable event listening.

- If a dynamic sensor is disconnected, the application needs to disable listening for sensor data changes.

### Vibrator

- To use vibrator functions, ensure that the device where your application runs has the required misc components.
- To use vibrators, you need to request the required permissions.
- When there are multiple vibrators, your application needs to call **getVibratorInfoSync()** to query the list of available vibrators. When calling **startVibration** or **stopVibration**, you need to pass parameters such as **deviceId** and **vibratorId** to identify the target vibrator.
