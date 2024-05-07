# Sensor Overview

## Sensor Types


Sensors are an abstraction of underlying sensor hardware. Your application can access the underlying sensor hardware via the sensors. Using the [Sensor](../../reference/apis-sensor-service-kit/js-apis-sensor.md) APIs, you can query sensors on your device, subscribe to sensor data, customize algorithms based on sensor data, and develop various sensor-based applications, such as compass, motion-controlled games, and fitness and health applications.

| Type                 | Name              | Description                                                        | Usage                                  |
| --------------------------- | ------------------ | ------------------------------------------------------------ | ------------------------------------------ |
| ACCELEROMETER               | Acceleration sensor      | Measures the acceleration (including the gravity acceleration) applied to a device on three physical axes (X, Y, and Z), in the unit of m/s<sup>2</sup>.| Detecting the motion status                            |
| ACCELEROMETER_UNCALIBRATED  | Uncalibrated acceleration sensor| Measures the uncalibrated acceleration (including the gravity acceleration) applied to a device on three physical axes (X, Y, and Z), in the unit of m/s<sup>2</sup>.| Measuring the acceleration bias estimation                      |
| LINEAR_ACCELERATION         | Linear acceleration sensor  | Measures the linear acceleration (excluding the gravity acceleration) applied to a device on three physical axes (X, Y, and Z), in the unit of m/s<sup>2</sup>.| Detecting the linear acceleration in each axis          |
| GRAVITY                     | Gravity sensor        | Measures the gravity acceleration applied to a device on three physical axes (X, Y, and Z), in the unit of m/s<sup>2</sup>.| Measuring the gravity                            |
| GYROSCOPE                   | Gyroscope sensor      | Measures the rotation angular velocity of a device on three physical axes (X, Y, and Z), in the unit of rad/s.| Measuring the rotation angular velocity                        |
| GYROSCOPE_UNCALIBRATED      | Uncalibrated gyroscope sensor| Measures the uncalibrated rotation angular velocity of a device on three physical axes (X, Y, and Z), in the unit of rad/s.| Measuring the bias estimation of the rotation angular velocity              |
| SIGNIFICANT_MOTION          | Significant motion sensor  | Checks whether a device has a significant motion on three physical axes (X, Y, and Z). The value **0** means that the device does not have a significant motion, and **1** means the opposite.| Detecting significant motions of a device          |
| PEDOMETER_DETECTION         | Pedometer detection sensor  | Detects whether a user takes a step. The value can be **0** (the user does not take a step) or **1** (the user takes a step).| Detecting whether a user takes a step            |
| PEDOMETER                   | Pedometer sensor      | Records the number of steps a user has walked.                                        | Providing the number of steps a user has walked              |
| AMBIENT_TEMPERATURE         | Ambient temperature sensor    | Measures the ambient temperature, in the unit of degree Celsius (°C).           | Measuring the ambient temperature                            |
| MAGNETIC_FIELD              | Magnetic field sensor        | Measures the magnetic field on three physical axes (X, Y, and Z), in the unit of μT.| Creating a compass                              |
| MAGNETIC_FIELD_UNCALIBRATED | Uncalibrated magnetic field sensor  | Measures the uncalibrated magnetic field on three physical axes (X, Y, and Z), in the unit of μT.| Measuring the magnetic field bias estimation                        |
| HUMIDITY                    | Humidity sensor        | Measures the ambient relative humidity, in a percentage (%).           | Monitoring the dew point, absolute humidity, and relative humidity            |
| BAROMETER                   | Barometer sensor      | Measures the barometric pressure, in the unit of hPa or mbar.      | Measuring the barometric pressure                            |
| ORIENTATION                 | Orientation sensor        | Measures the rotation angles of a device on three physical axes (Z, X, and Y), in the unit of rad.| Measuring the three orientation angles of the screen             |
| ROTATION_VECTOR             | Rotation vector sensor    | Measures the rotation vector of a device. It is a composite sensor that generates data from the acceleration sensor, magnetic field sensor, and gyroscope sensor.| Detecting the orientation of a device in the East, North, Up (ENU) Cartesian coordinate system        |
| PROXIMITY                   | Proximity sensor      | Measures the distance between a visible object and the device screen.              | Measuring the distance between a person and the device during a call                  |
| AMBIENT_LIGHT               | Ambient light sensor      | Measures the ambient light intensity of a device, in the unit of lux.                           | Automatically adjusting the screen brightness and checking whether the screen is covered on the top|
| HEART_RATE                  | Heart rate sensor        | Measures the heart rate of a user.                                        | Providing users' heart rate data              |
| WEAR_DETECTION              | Wear detection sensor    | Checks whether a user is wearing a wearable device.                                          | Detecting wearables            |
| HALL                        | Hall effect sensor        | Detects a magnetic field around a device.                              | Smart cover mode of the device                          |


## Working Principles

The following modules work cooperatively to implement sensors: Sensor API, Sensor Framework, Sensor Service, and HDF layer.

**Figure 1** How the sensor works

![fad1a124-a90e-460f-84fc-e87d6caebb21](figures/fad1a124-a90e-460f-84fc-e87d6caebb21.png)

- Sensor API: provides APIs for performing basic operations on sensors, including querying the sensor list, subscribing to or unsubscribing from sensor data, and executing control commands. This module makes application development simpler.

- Sensor Framework: manages sensor data subscription, creates and destroys data channels, subscribes to or unsubscribes from sensor data, and implements communication with the Sensor Service module.

- Sensor Service: interacts with the HD_IDL module to receive, parse, and distribute data, manages foreground and background policies and sensors of a device, and controls sensor permissions.

- HDF layer: selects proper policies based on the hardware first in first out (FIFO) and frequency, and adapts to different devices.


## Constraints

To obtain data of the following sensors, you must request the required permissions.

    | Sensor                                            | Permission                          | Sensitivity    | Permission Description                                                    |
    | -------------------------------------------------- | -------------------------------- | ------------ | ------------------------------------------------------------ |
    | Acceleration sensor, uncalibrated acceleration sensor, and linear acceleration sensor| ohos.permission.ACCELEROMETER    | system_grant | The permission allows an application to read data from acceleration sensors, uncalibrated acceleration sensors, and linear acceleration sensors.|
    | Gyroscope sensor and uncalibrated gyroscope sensor                  | ohos.permission.GYROSCOPE        | system_grant | The permission allows an application to read data from gyroscope sensors and uncalibrated gyroscope sensors.|
    | Pedometer sensor                                            | ohos.permission.ACTIVITY_MOTION  | user_grant   | The permission allows an application to read an end user's motion status, for example, to determine whether the user is in motion or to record the number of steps that the user has walked. |
    | Heart rate sensor                                            | ohos.permission.READ_HEALTH_DATA | user_grant   | The permission allows an application to obtain an end user's health data, such as heart rate data.          |
    
The APIs for subscribing to and unsubscribing from sensor data work in pairs. If you do not need sensor data, call the unsubscription API to stop sensor data reporting.
