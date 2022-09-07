# Sensor服务使用实例


  使用实例以sensorTypeId为0的传感器为例，其他类型的传感器使用方式类似。
  
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

/* 测试用例函数 */
static int32_t TestSensorService(void)
{
    SensorUser sensorUser;
    sensorUser.callback = SensorDataCallbackImpl;
    SensorInfo *sensorInfo = (SensorInfo *)NULL;
    int32_t count = 0;
    // 获取设备的sensor列表
    int32_t ret = GetAllSensors(&sensorInfo, &count);
    if (ret != 0) {
        printf("GetAllSensors failed! ret: %d", ret);
        return ret;
    }
    // 使能传感器
    ret = ActivateSensor(0, &sensorUser);
    if (ret != 0) {
        printf("ActivateSensorfailed! ret: %d", ret);
        return ret;
    }
    // 订阅传感器数据
    ret = SubscribeSensor(0, &sensorUser);
    if (ret != 0) {
        printf("SubscribeSensor! ret: %d", ret);
        return ret;
    }
    sleep(10);
    // 取消传感器数据订阅
    ret = UnsubscribeSensor(0, &sensorUser);
    if (ret != 0) {
        printf("UnsubscribeSensor! ret: %d", ret);
        return ret;
    }
    // 去使能传感器
    ret = DeactivateSensor(0, &sensorUser);
    if (ret != 0) {
        printf("DeactivateSensor! ret: %d", ret);
        return ret;
    }
}
```
