# Sensor Overview


Sensors in OpenHarmony are an abstraction of underlying hardware-based sensors. Your application can access the underlying sensors via OpenHarmony sensors. Using the APIs provided by OpenHarmony sensors, you can query sensors on your device, subscribe to sensor data, customize algorithms based on sensor data, and develop various sensor-based applications, such as compass, fitness and health, and games applications.


The sensors are classified into the following categories based on their functions: motion, environment, orientation, light, body, and other categories (such as Hall effect sensors). Each category includes different sensor types. A sensor type may be a single physical sensor or a composite of multiple physical sensors.


  **Table1** Motion - ohos.sensor.agent.CategoryMotionAgent

| Sensor Type | Sensor Name | Description | Usage | 
| -------- | -------- | -------- | -------- |
| SENSOR_TYPE_ACCELEROMETER | Acceleration sensor | Measures the acceleration (including the gravity acceleration) applied to a device on three physical axes (X, Y, and Z), in the unit of m/s<sup>2</sup>. | Detecting the motion status | 
| SENSOR_TYPE_ACCELEROMETER_UNCALIBRATED | Uncalibrated acceleration sensor | Measures the uncalibrated acceleration (including the gravity acceleration) applied to a device on three physical axes (X, Y, and Z), in the unit of m/s<sup>2</sup>. | Measuring the acceleration bias estimation | 
| SENSOR_TYPE_LINEAR_ACCELERATION | Linear acceleration sensor | Measures the linear acceleration (excluding the gravity acceleration) applied to a device on three physical axes (X, Y, and Z), in the unit of m/s<sup>2</sup>. | Detecting the linear acceleration in each axis | 
| SENSOR_TYPE_GRAVITY | Gravity sensor | Measures the gravity acceleration applied to a device on three physical axes (X, Y, and Z), in the unit of m/s<sup>2</sup>. | Measuring the gravity | 
| SENSOR_TYPE_GYROSCOPE | Gyroscope sensor | Measures the rotation angular velocity of a device on three physical axes (X, Y, and Z), in the unit of rad/s. | Measuring the rotation angular velocity | 
| SENSOR_TYPE_GYROSCOPE_UNCALIBRATED | Uncalibrated gyroscope sensor | Measures the uncalibrated rotation angular velocity of a device on three physical axes (X, Y, and Z), in the unit of rad/s. | Measuring the bias estimation of the rotation angular velocity | 
| SENSOR_TYPE_SIGNIFICANT_MOTION | Significant motion sensor | Checks whether a device has a significant motion on three physical axes (X, Y, and Z). The value can be **0** (having no significant motion) or **1** (having a significant motion). | Detecting significant motions of a device | 
| SENSOR_TYPE_DROP_DETECTION | Drop detection sensor | Detects the device drop status. The value can be **0** (the device is not dropped) or **1** (the device is dropped). | Detecting whether a device is dropped | 
| SENSOR_TYPE_PEDOMETER_DETECTION | Pedometer detection sensor | Detects whether a user takes a step. The value can be **0** (the user does not take a step) or **1** (the user takes a step). | Detecting whether a user takes a step | 
| SENSOR_TYPE_PEDOMETER | Pedometer sensor | Records the number of steps a user has walked. | Providing the number of steps a user has walked | 


  **Table2** Environment - ohos.sensor.agent.CategoryOrientationAgent

| Sensor Type | Sensor Name | Description | Usage | 
| -------- | -------- | -------- | -------- |
| SENSOR_TYPE_AMBIENT_TEMPERATURE | Ambient temperature sensor. | Measures the ambient temperature, in the unit of degree Celsius (°C). | Measuring the ambient temperature | 
| SENSOR_TYPE_MAGNETIC_FIELD | Magnetic field sensor | Measures the magnetic field on three physical axes (X, Y, and Z), in the unit of μT. | Creating a compass | 
| SENSOR_TYPE_MAGNETIC_FIELD_UNCALIBRATED | Uncalibrated magnetic field sensor | Measures the uncalibrated magnetic field on three physical axes (X, Y, and Z), in the unit of μT. | Measuring the magnetic field bias estimation | 
| SENSOR_TYPE_HUMIDITY | Humidity sensor | Measures the ambient relative humidity, in a percentage (%). | Monitoring the dew point, absolute humidity, and relative humidity | 
| SENSOR_TYPE_BAROMETER | Barometer sensor | Measures the barometric pressure, in the unit of hPa or mbar. | Measuring the barometric pressure | 
| SENSOR_TYPE_SAR | Specific Absorption Rate (SAR) sensor | Measures the SAR, in the unit of W/kg. | Measuring the SAR of electromagnetic waves for a device | 


  **Table3** Orientation - ohos.sensor.agent.CategoryOrientationAgent

| Sensor Type | Sensor Name | Description | Usage | 
| -------- | -------- | -------- | -------- |
| SENSOR_TYPE_6DOF | Degrees of Freedom (DoF) sensor | Measures the forward/backward, up/down, and left/right translational movement of a device on the three axes (X, Y, and Z) in the unit of m or mm as well as the roll, pitch, and yaw rotation angles on the three axes (X, Y, and Z) in the unit of rad. | Positioning an object by detecting its freedom of translational and rotational motions, for example, VR | 
| SENSOR_TYPE_SCREEN_ROTATION | Screen rotation sensor | Checks the rotation status of the device screen. | Detecting whether the device screen is rotating | 
| SENSOR_TYPE_DEVICE_ORIENTATION | Device orientation sensor | Measures the rotation angles of the device, in the unit of rad. | Measuring the angles that a device has rotated | 
| SENSOR_TYPE_ORIENTATION | Orientation sensor | Measures the rotation angles of a device on three physical axes (X, Y, and Z), in the unit of rad. | Providing the three orientation angles of the screen | 
| SENSOR_TYPE_ROTATION_VECTOR | Rotation vector sensor | Measures the rotation vector of a device. It is a composite sensor that generates data from the acceleration sensor, magnetic field sensor, and gyroscope sensor. | Detecting the orientation of a device in the East, North, Up (ENU) Cartesian coordinate system | 
| SENSOR_TYPE_GAME_ROTATION_VECTOR<br/>SENSOR_TYPE_GEOMAGNETIC_ROTATION_VECTOR | Game rotation vector sensor<br/>Geomagnetic rotation vector sensor | Measures the game rotation vector of a device. It is a composite sensor that generates data from the acceleration sensor and gyroscope sensor.<br/>Measures the geomagnetic rotation vector of a device. It is a composite sensor that generates data from the acceleration sensor and magnetic field sensor. | Applied in games<br/>Measuring the geomagnetic rotation vector | 


  **Table4** Light - ohos.sensor.agent.CategoryLightAgent

| Sensor Type | Sensor Name | Description | Usage | 
| -------- | -------- | -------- | -------- |
| SENSOR_TYPE_PROXIMITY | Proximity sensor | Measures the distance between a visible object and the device screen. | Measuring the distance between a person and the device during a call | 
| SENSOR_TYPE_TOF | Time of flight (ToF) sensor | Measures the time required for light to travel a distance in the medium. | Facial recognition | 
| SENSOR_TYPE_AMBIENT_LIGHT | Ambient light sensor | Measures the ambient light intensity of a device, in the unit of lux. | Automatically adjusting the screen brightness and checking whether the screen is covered on the top | 
| SENSOR_TYPE_COLOR_TEMPERATURE | Color temperature sensor | Measures the ambient color temperature. | Image processing on the device | 
| SENSOR_TYPE_COLOR_RGB | RGB color sensor | Measures the ambient RGB color values. | Color detection implemented by the reflectance of RGB colors | 
| SENSOR_TYPE_COLOR_XYZ | XYZ color sensor | Measures the ambient XYZ color values. | Identifying true-color spots to reproduce more natural colors | 


  **Table5** Body - ohos.sensor.agent.CategoryBodyAgent

| Sensor Type | Sensor Name | Description | Usage | 
| -------- | -------- | -------- | -------- |
| SENSOR_TYPE_HEART_RATE | Heart rate sensor | Measures the heart rate of a user. | Providing users' heart rate data | 
| SENSOR_TYPE_WEAR_DETECTION | Wear detection sensor | Checks whether a user is wearing a wearable device. | Detecting wearables | 


  **Table6** Others

| Sensor Type | Sensor Name | Description | Usage | 
| -------- | -------- | -------- | -------- |
| SENSOR_TYPE_HALL | Hall effect sensor | Detects a magnetic field around a device. | Smart cover mode of the device | 
| SENSOR_TYPE_GRIP_DETECTOR | Grip detection sensor | Detects grip force applied on a device. | Detecting whether the device is gripped on its sides | 
| SENSOR_TYPE_MAGNET_BRACKET | Magnet bracket sensor | Checks whether a device is magnetized. | Detecting an in-vehicle or indoor device | 
| SENSOR_TYPE_PRESSURE_DETECTOR | Pressure detection sensor | Detects pressure force applied on a device. | Detecting pressure on the top of the device | 


## How a Service Is Shared Using Huawei Share

The following modules work cooperatively to implement OpenHarmony sensors: Sensor API, Sensor Framework, Sensor Service, and HD_IDL.

  **Figure1** Working principles for OpenHarmony sensors
  ![en-us_image_0000001226521897](figures/en-us_image_0000001226521897.png)

- Sensor API: provides APIs for performing basic operations on sensors, including querying the sensor list, subscribing to or unsubscribing from sensor data, and executing control commands. This module makes application development simpler.

- Sensor Framework: manages sensor data subscription, creates and destroys data channels, subscribes to or unsubscribes from sensor data, and implements communication with the Sensor Service module.

- Sensor Service: interacts with the HD_IDL module to receive, parse, and distribute data, manages foreground and background policies and sensors of a device, and controls sensor permissions.

- HD_IDL: selects proper policies based on the hardware first in first out (FIFO) and frequency, and adapts to different devices.


## Limitations and Constraints

To obtain data of the following sensors, you must claim the required permissions.


  **Table7** Sensor data permission

| Sensor | Permission Name | Sensitivity | Permission Description | 
| -------- | -------- | -------- | -------- |
| Acceleration sensor, uncalibrated acceleration sensor, and linear acceleration sensor | ohos.permission.ACCELEROMETER | system_grant | Allows your application to subscribe to data of these acceleration-related sensors in the motion category. | 
| Gyroscope sensor and uncalibrated gyroscope sensor | ohos.permission.GYROSCOPE | system_grant | Allows your application to subscribe to data of these gyroscope-related sensors in the motion category. | 
| Pedometer sensor | ohos.permission.ACTIVITY_MOTION | user_grant | Allows your application to subscribe to the motion status. | 
| Heart rate sensor | ohos.permission.READ_HEALTH_DATA | user_grant | Allows your application to read health data. | 


The APIs for subscribing to and unsubscribing from sensor data work in pairs. If you do not need sensor data, call the unsubscription API to stop sensor data reporting.
