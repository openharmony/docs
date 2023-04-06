# Sensor服务使用指导


下面使用步骤以sensorTypeId为0的传感器为例，其他类型的传感器使用方式类似。


## 使用步骤

1. 导入需要的包

  
    ```c
    #include "sensor_agent.h"
    #include "sensor_agent_type.h"
    ```

2. 创建传感器回调函数



    ```c
    void SensorDataCallbackImpl(SensorEvent *event)
    {
        if(event == NULL){
            return;
        }
        float *sensorData=(float *)event->data;
    }
    ```
    
    > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
    > 回调函数的格式为RecordSensorCallback类型。

3. 获取设备支持sensor列表



    ```c
    SensorInfo *sensorInfo = (SensorInfo *)NULL;
    int32_t count = 0;
    int32_t ret = GetAllSensors(&sensorInfo, &count);
    ```

4. 创建的传感器用户


    
    ```c
    SensorUser sensorUser;
    sensorUser.callback = SensorDataCallbackImpl; //成员变量callback指向创建的回调方法
    ```

5. 使能传感器


    
    ```c
    int32_t ret = ActivateSensor(0, &sensorUser);
    ```

6. 订阅传感器数据



    ```c
    int32_t ret = SubscribeSensor(0, &sensorUser);
    ```
    
    > ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
    > 到这步就可以在实现的回调方法中获取到传感器数据。

7. 取消传感器数据订阅



    ```c
    int32_t ret = UnsubscribeSensor(0, &sensorUser);
    ```

8. 去使能一个传感器



    ```c
    int32_t ret = DeactivateSensor(0, &sensorUser);
    ```
