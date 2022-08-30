# Sensor Usage Guidelines

The following steps use the sensor whose **sensorTypeId** is **0** as an example. The guidelines for other sensor types are similar.

## How to Use

1.  Import the required header files.


    ```c
    #include "sensor_agent.h"
    #include "sensor_agent_type.h"
    ```

2. Create a sensor callback.

    ```c
    void SensorDataCallbackImpl(SensorEvent *event)
    {
        if(event == NULL){
            return;
        }
        float *sensorData=(float *)event->data;
    }
    ```
    
    > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
    > The callback must be of the RecordSensorCallback type.

3. Obtain the list of sensors supported by the device.

    ```c
    SensorInfo *sensorInfo = (SensorInfo *)NULL;
    int32_t count = 0;
    int32_t ret = GetAllSensors(&sensorInfo, &count);
    ```

4. Create a sensor user.   

    ```c
    SensorUser sensorUser;
    sensorUser.callback = SensorDataCallbackImpl; // Assign the created callback SensorDataCallbackImpl to the member variable callback.
    ```

5. Enable the sensor.    

    ```c
    int32_t ret = ActivateSensor(0, &sensorUser);
    ```

6. Subscribe to sensor data.

    ```c
    int32_t ret = SubscribeSensor(0, &sensorUser);
    ```
    
    > ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
    > Till now, you can obtain the sensor data via the callback.

7. Unsubscribe from the sensor data.

    ```c
    int32_t ret = UnsubscribeSensor(0, &sensorUser);
    ```

8. Disable the sensor.

    ```c
    int32_t ret = DeactivateSensor(0, &sensorUser);
    ```
