# 传感器开发指导
<!--Kit: Sensor Service Kit-->
<!--Subsystem: Sensors-->
<!--Owner: @dilligencer-->
<!--SE: @butterls-->
<!--TSE: @murphy84-->

## 场景介绍

当设备需要获取传感器数据时，可以使用sensor模块，例如：通过订阅方向传感器数据感知用户设备当前的朝向。

详细的接口介绍请参考[Sensor接口](../../reference/apis-sensor-service-kit/js-apis-sensor.md)。


## 接口说明

| 名称 | 描述 |
| -------- | -------- |
| sensor.on(sensorId, callback:AsyncCallback&lt;Response&gt;): void | 持续监听传感器数据变化。 |
| sensor.off(sensorId, callback?:AsyncCallback&lt;void&gt;): void | 注销传感器数据的监听。 |


## 开发步骤

开发步骤以加速度传感器ACCELEROMETER为例。

1. 导入模块。

    ```ts
    import { sensor } from '@kit.SensorServiceKit';
    ```

2. 检查是否已经配置相应权限，具体配置方式请参考[声明权限](../../security/AccessToken/declare-permissions.md)。

3. 注册监听。

    通过on()接口，实现对传感器的持续监听，将传感器上报频率等级设为”game“。

    ```ts    
    sensor.on(sensor.SensorId.ACCELEROMETER, (data: sensor.AccelerometerResponse) => {
        console.info("Succeeded in obtaining data. x: " + data.x + " y: " + data.y + " z: " + data.z);
    }, { interval: 'game' });
    ```

    ![输入图片说明](figures/002.png)

4. 取消持续监听。

    ```ts
    sensor.off(sensor.SensorId.ACCELEROMETER);
    ```