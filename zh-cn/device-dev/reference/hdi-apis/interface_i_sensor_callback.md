# ISensorCallback


## **概述**

定义用于上报传感器数据的回调函数。

传感器用户订阅传感器数据，只在使能传感器后，传感器数据订阅者才能接收传感器数据。

**相关模块:**

[Sensor](sensor.md)


## **汇总**


### Public 成员函数

  | 名称 | 描述 | 
| -------- | -------- |
| [OnDataEvent](#ondataevent)&nbsp;([in]&nbsp;struct&nbsp;[HdfSensorEvents](_hdf_sensor_events.md)&nbsp;event) | 定义上报传感器数据的功能。 | 


## **成员函数说明**


### OnDataEvent()

  
```
ISensorCallback::OnDataEvent ([in] struct HdfSensorEvents event)
```

**描述：**

定义上报传感器数据的功能。

**参数:**

  | 名称 | 描述 | 
| -------- | -------- |
| event | 上报的传感器数据，详见[HdfSensorEvents](_hdf_sensor_events.md)。 | 

**返回:**

如果操作成功，则返回0。

如果操作失败，则返回负值。
