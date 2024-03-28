# Sensor Development


## When to Use

With the sensor module, a device can obtain sensor data. For example, the device can subscribe to data of the orientation sensor to detect its own orientation, and data of the pedometer sensor to learn the number of steps the user walks every day.

For details about the APIs, see [Sensor](../../reference/apis-sensor-service-kit/js-apis-sensor.md).


## Available APIs

| Module| API| Description|
| -------- | -------- | -------- |
| ohos.sensor | sensor.on(sensorId, callback:AsyncCallback&lt;Response&gt;): void | Subscribes to data changes of a type of sensor.|
| ohos.sensor | sensor.once(sensorId, callback:AsyncCallback&lt;Response&gt;): void | Subscribes to only one data change of a type of sensor.|
| ohos.sensor | sensor.off(sensorId, callback?:AsyncCallback&lt;void&gt;): void | Unsubscribes from sensor data changes.|
| ohos.sensor | sensor.getSensorList(callback: AsyncCallback\<Array\<Sensor>>): void| Obtains information about all sensors on the device. This API uses an asynchronous callback to return the result.|


## How to Develop

The acceleration sensor is used as an example.

1. Import the module.

   ```ts
   import sensor from '@ohos.sensor';
   import { BusinessError } from '@ohos.base';
   ```

2. Obtain information about all sensors on the device.

    ```ts    
    sensor.getSensorList((error: BusinessError, data: Array<sensor.Sensor>) => {
        if (error) {
            console.info('getSensorList failed');
        } else {
            console.info('getSensorList success');
            for (let i = 0; i < data.length; i++) {
                console.info(JSON.stringify(data[i]));
            }
        }
    });
    ```

    ![](figures/001.png)

    The minimum and the maximum sampling periods supported by the sensor are 5000000 ns and 200000000 ns, respectively. Therefore, the value of **interval** must be within this range.

3. Check whether the corresponding permission has been configured. For details, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

4. Register a listener. You can call **on()** or **once()** to listen for sensor data changes.

- The **on()** API is used to continuously listen for data changes of the sensor. The sensor reporting interval is set to 100000000 ns.

   ```ts    
   sensor.on(sensor.SensorId.ACCELEROMETER, (data: sensor.AccelerometerResponse) => {
        console.info("Succeeded in obtaining data. x: " + data.x + " y: " + data.y + " z: " + data.z);
   }, { interval: 100000000 });
   ```

    ![](figures/002.png)

- The **once()** API is used to listen for only one data change of the sensor.

   ```ts
   sensor.once(sensor.SensorId.ACCELEROMETER, (data: sensor.AccelerometerResponse) => {
       console.info("Succeeded in obtaining data. x: " + data.x + " y: " + data.y + " z: " + data.z);
   });
   ```

   ![](figures/003.png)

5. Cancel continuous listening.

    ```ts
    sensor.off(sensor.SensorId.ACCELEROMETER);
    ```
