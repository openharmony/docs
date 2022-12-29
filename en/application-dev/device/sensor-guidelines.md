# Sensor Development


## When to Use

With the sensor module, a device can obtain sensor data. For example, the device can subscribe to data of the orientation sensor to detect its own orientation, and data of the pedometer sensor to learn the number of steps the user walks every day.

For details about the APIs, see [Sensor](../reference/apis/js-apis-sensor.md).


## Available APIs

| Module| API| Description|
| -------- | -------- | -------- |
| ohos.sensor | sensor.on(sensorId, callback:AsyncCallback&lt;Response&gt;): void | Subscribes to data changes of a type of sensor.|
| ohos.sensor | sensor.once(sensorId, callback:AsyncCallback&lt;Response&gt;): void | Subscribes to only one data change of a type of sensor.|
| ohos.sensor | sensor.off(sensorId, callback?:AsyncCallback&lt;void&gt;): void | Unsubscribes from sensor data changes.|


## How to Develop

1. Before obtaining data from a type of sensor, check whether the required permission has been configured.<br>
     The system provides the following sensor-related permissions:
   - ohos.permission.ACCELEROMETER

   - ohos.permission.GYROSCOPE

   - ohos.permission.ACTIVITY_MOTION

   - ohos.permission.READ_HEALTH_DATA

   For details about how to configure a permission, see [Declaring Permissions](../security/accesstoken-guidelines.md).
   
2. Subscribe to data changes of a type of sensor. The following uses the acceleration sensor as an example. 
  
   ```js
   import sensor from "@ohos.sensor";
   sensor.on(sensor.SensorId.ACCELEROMETER, function(data){
      console.info("Data obtained successfully. x: " + data.x + "y: " + data.y + "z: " + data.z); // Data is obtained.
   });
   ```
   
   ![171e6f30-a8d9-414c-bafa-b430340305fb](figures/171e6f30-a8d9-414c-bafa-b430340305fb.png)

3. Unsubscribe from sensor data changes.
  
   ```js
   import sensor from "@ohos.sensor";
   sensor.off(sensor.SensorId.ACCELEROMETER);
   ```
   
   ![65d69983-29f6-4381-80a3-f9ef2ec19e53](figures/65d69983-29f6-4381-80a3-f9ef2ec19e53.png)

4. Subscribe to only one data change of a type of sensor.
  
   ```js
   import sensor from "@ohos.sensor";
   sensor.once(sensor.SensorId.ACCELEROMETER, function(data) {
      console.info("Data obtained successfully. x: " + data.x + "y: " + data.y + "z: " + data.z); // Data is obtained.
   });
   ```
   
   ![db5d017d-6c1c-4a71-a2dd-f74b7f23239e](figures/db5d017d-6c1c-4a71-a2dd-f74b7f23239e.png)

   If the API fails to be called, you are advised to use the **try/catch** statement to capture error information that may occur in the code. Example:

    ```js
   import sensor from "@ohos.sensor";
    try {
      sensor.once(sensor.SensorId.ACCELEROMETER, function(data) {
          console.info("Data obtained successfully. x: " + data.x + "y: " + data.y + "z: " + data.z); // Data is obtained.
      });
    } catch (error) {
      console.error("Get sensor data error. data:" + error.data, " msg:", error.message);
    }
    ```
