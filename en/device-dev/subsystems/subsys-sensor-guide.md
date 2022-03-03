# Sensor Usage Guidelines<a name="EN-US_TOPIC_0000001077367158"></a>

The following steps use the sensor whose  **sensorTypeId**  is  **0**  as an example. The guidelines for other sensor types are similar.

## How to Use<a name="section18816105182315"></a>

1.  Import the required header files.

```
#include "sensor_agent.h"
#include "sensor_agent_type.h"
```

1.  Create a sensor callback.

```
void SensorDataCallbackImpl(SensorEvent *event)
{
    if(event == NULL){
        return;
    }
    float *sensorData=(float *)event->data;
}
```

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>The callback must be of the RecordSensorCallback type.

1.  Obtain the list of sensors supported by the device.

```
SensorInfo *sensorInfo = (SensorInfo *)NULL;
int32_t count = 0;
int32_t ret = GetAllSensors(&sensorInfo, &count);
```

1.  Create a sensor user.

```
SensorUser sensorUser;
sensorUser.callback = SensorDataCallbackImpl; // Assign the created callback SensorDataCallbackImpl to the member variable callback.
```

1.  Enable the sensor.

```
int32_t ret = ActivateSensor(0, &sensorUser);
```

1.  Subscribe to sensor data.

```
int32_t ret = SubscribeSensor(0, &sensorUser);
```

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>Till now, you can obtain the sensor data via the callback.

1.  Unsubscribe from the sensor data.

```
int32_t ret = UnsubscribeSensor(0, &sensorUser);
```

1.  Disable the sensor.

```
int32_t ret = DeactivateSensor(0, &sensorUser);
```

