# ISensorCallback


## 概述

定义用于上报传感器数据的回调函数。

传感器用户订阅传感器数据，只在使能传感器后，传感器数据订阅者才能接收传感器数据。

**起始版本：** 2.2

**相关模块：**[Sensor](_hdi_sensor_v10.md)


## 汇总


### Public 成员函数

| 名称 | 描述 | 
| -------- | -------- |
| [OnDataEvent](#ondataevent) ([in] struct [HdfSensorEvents](_hdf_sensor_events_v10.md) event) | 定义上报传感器数据的功能。 | 


## 成员函数说明


### OnDataEvent()

```
ISensorCallback::OnDataEvent ([in] struct HdfSensorEvents event)
```

**描述**


定义上报传感器数据的功能。

**起始版本：** 2.2

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| event | 上报的传感器数据，详见[HdfSensorEvents](_hdf_sensor_events_v10.md)。 | 

**返回：**

如果操作成功，则返回0。

如果操作失败，则返回负值。
