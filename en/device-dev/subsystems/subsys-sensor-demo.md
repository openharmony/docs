# Sensor Usage Example

The following sample code uses the sensor whose **sensorTypeId** is **0** as an example. The code for other sensor types is similar.

```c
#include "sensor_agent.h"
#include "sensor_agent_type.h"
#include "stdio.h"

void SensorDataCallbackImpl(SensorEvent *event)
{
    if(event == NULL){
        return;
    }
    float *sensorData=(float *)event->data;
    for(int32_t i = 0; i < (int32_t)(event->dataLen / sizeof(uint8_t *)); i++){
        printf("SensorDataCallbackImpl data: %f", *(sensorData + i));
    }
}

/* Test case function */
static int32_t TestSensorService(void)
{
    SensorUser sensorUser;
    sensorUser.callback = SensorDataCallbackImpl;
    SensorInfo *sensorInfo = (SensorInfo *)NULL;
    int32_t count = 0;
    // Obtain the list of sensors on the device.
    int32_t ret = GetAllSensors(&sensorInfo, &count);
    if (ret != 0) {
        printf("GetAllSensors failed! ret: %d", ret);
        return ret;
    }
    // Enable the sensor.
    ret = ActivateSensor(0, &sensorUser);
    if (ret != 0) {
        printf("ActivateSensorfailed! ret: %d", ret);
        return ret;
    }
     // Subscribe to sensor data.
    ret = SubscribeSensor(0, &sensorUser);
    if (ret != 0) {
        printf("SubscribeSensor! ret: %d", ret);
        return ret;
    }
    sleep(10);
    // Unsubscribe from the sensor data.
    ret = UnsubscribeSensor(0, &sensorUser);
    if (ret != 0) {
        printf("UnsubscribeSensor! ret: %d", ret);
        return ret;
    }
    // Disable the sensor.
    ret = DeactivateSensor(0, &sensorUser);
    if (ret != 0) {
        printf("DeactivateSensor! ret: %d", ret);
        return ret;
    }
}
```

