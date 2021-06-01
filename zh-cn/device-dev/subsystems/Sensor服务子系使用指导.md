# Sensor服务子系使用指导<a name="ZH-CN_TOPIC_0000001077367158"></a>

-   [使用步骤](#section18816105182315)

下面使用步骤以sensorTypeId为0的传感器为例，其他类型的传感器使用方式类似。

## 使用步骤<a name="section18816105182315"></a>

1.  导入需要的包

```
#include "sensor_agent.h"
#include "sensor_agent_type.h"
```

1.  创建传感器回调函数

```
void SensorDataCallbackImpl(SensorEvent *event)
{
    if(event == NULL){
        return;
    }
    float *sensorData=(float *)event->data;
}
```

>![](public_sys-resources/icon-note.gif) **说明：** 
>回调函数的格式为RecordSensorCallback类型。

1.  获取设备支持sensor列表

```
SensorInfo *sensorInfo = (SensorInfo *)NULL;
int32_t count = 0;
int32_t ret = GetAllSensors(&sensorInfo, &count);
```

1.  创建的传感器用户

```
SensorUser sensorUser;
sensorUser.callback = SensorDataCallbackImpl; //成员变量callback指向创建的回调方法
```

1.  使能传感器

```
int32_t ret = ActivateSensor(0, &sensorUser);
```

1.  订阅传感器数据

```
int32_t ret = SubscribeSensor(0, &sensorUser);
```

>![](public_sys-resources/icon-note.gif) **说明：** 
>到这步就可以在实现的回调方法中获取到传感器数据。

1.  取消传感器数据订阅

```
int32_t ret = UnsubscribeSensor(0, &sensorUser);
```

1.  去使能一个传感器

```
int32_t ret = DeactivateSensor(0, &sensorUser);
```

