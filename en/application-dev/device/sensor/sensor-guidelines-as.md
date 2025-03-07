# Sensor Development


## When to Use

With the sensor module, a device can obtain sensor data. For example, the device can subscribe to data of the orientation sensor to detect its own orientation.

For details about the APIs, see [Sensor](../../reference/apis-sensor-service-kit/js-apis-sensor.md).


## Available APIs

| Name| Description|
| -------- | -------- |
| sensor.on(sensorId, callback:AsyncCallback&lt;Response&gt;): void | Subscribes to data changes of a type of sensor.|
| sensor.off(sensorId, callback?:AsyncCallback&lt;void&gt;): void | Unsubscribes from sensor data changes.|


## How to Develop

The acceleration sensor is used as an example.

1. Import modules.

    ```ts
    import { sensor } from '@kit.SensorServiceKit';
    ```

2. Check whether the corresponding permission has been configured. For details, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

3. Register a listener.

    The **on()** API is used to continuously listen for data changes of the sensor. The sensor reporting interval is set to **game**.

    ```ts    
    sensor.on(sensor.SensorId.ACCELEROMETER, (data: sensor.AccelerometerResponse) => {
        console.info("Succeeded in obtaining data. x: " + data.x + " y: " + data.y + " z: " + data.z);
    }, { interval: 'game' });
    ```

    ![](figures/002.png)

4. Cancel continuous listening.

    ```ts
    sensor.off(sensor.SensorId.ACCELEROMETER);
    ```
