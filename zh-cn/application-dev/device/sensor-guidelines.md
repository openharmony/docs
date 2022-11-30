# 传感器开发指导


## 场景介绍

- 通过指南针传感器数据，感知用户设备当前的朝向，从而达到为用户指明方向的目的。

- 通过接近光传感器数据，感知距离遮挡物的距离，使设备能够自动亮灭屏，达到防误触目的。

- 通过气压计传感器数据，准确的判断设备当前所处的海拔。

- 通过环境光传感器数据，设备能够实现背光自动调节。

- 通过霍尔传感器数据，设备实现皮套功能等。

- 通过心率传感器数据，感知用户当前的心率。

- 通过计步传感器数据，可以统计用户的步数。

- 通过佩戴检测传感器，可以检测用户是否佩戴。


## 接口说明

| 模块 | 接口名 | 描述 |
| -------- | -------- | -------- |
| ohos.sensor | sensor.on(sensorId, callback:AsyncCallback&lt;Response&gt;): void | 持续监听传感器数据变化 |
| ohos.sensor | sensor.once(sensorId, callback:AsyncCallback&lt;Response&gt;): void | 获取一次传感器数据变化 |
| ohos.sensor | sensor.off(sensorId, callback?:AsyncCallback&lt;void&gt;): void | 注销传感器数据的监听 |


## 开发步骤

1. 获取设备上传感器的数据前，需要检查是否已经配置请求相应的权限。 <br>
     系统提供的传感器权限有：
   - ohos.permission.ACCELEROMETER

   - ohos.permission.GYROSCOPE

   - ohos.permission.ACTIVITY_MOTION

   - ohos.permission.READ_HEALTH_DATA

   具体配置方式请参考[权限申请声明](../security/accesstoken-guidelines.md)。
   
2. 持续监听传感器数据变化。
  
   ```js
   import sensor from "@ohos.sensor";
   sensor.on(sensor.SensorId.ACCELEROMETER, function(data){
      console.info("Data obtained successfully. x: " + data.x + "y: " + data.y + "z: " + data.z);// 获取数据成功
   });
   ```
   
   以SensorId为ACCELEROMETER为例展示运行结果，持续监听传感器接口的结果如下图所示：
   
   ![171e6f30-a8d9-414c-bafa-b430340305f](D:\docs\docs\zh-cn\figures\171e6f30-a8d9-414c-bafa-b430340305fb.png)

3. 注销传感器数据监听。
  
   ```js
   import sensor from "@ohos.sensor";
   sensor.off(sensor.SensorId.ACCELEROMETER);
   ```
   
   以SensorId为ACCELEROMETER为例展示运行结果，注销传感器成功结果如下图所示：
   
   ![65d69983-29f6-4381-80a3-f9ef2ec19e53](D:\docs\docs\zh-cn\figures\65d69983-29f6-4381-80a3-f9ef2ec19e53.png)

4. 获取一次传感器数据变化。
  
   ```js
   import sensor from "@ohos.sensor";
   sensor.once(sensor.SensorId.ACCELEROMETER, function(data) {
      console.info("Data obtained successfully. x: " + data.x + "y: " + data.y + "z: " + data.z);// 获取数据成功
   });
   ```
   
   以SensorId为ACCELEROMETER为例展示运行结果，获取数据成功日志如下图所示：
   
   ![db5d017d-6c1c-4a71-a2dd-f74b7f23239e](D:\docs\docs\zh-cn\figures\db5d017d-6c1c-4a71-a2dd-f74b7f23239e.png)

   若接口调用不成功，建议使用try/catch语句捕获代码中可能出现的错误信息。例如：

    ```js
   import sensor from "@ohos.sensor";
    try {
      sensor.once(sensor.SensorId.ACCELEROMETER, function(data) {
          console.info("Data obtained successfully. x: " + data.x + "y: " + data.y + "z: " + data.z);// 获取数据成功
      });
    } catch (error) {
      console.error("Get sensor data fail");
    }
    ```
## 相关实例

针对传感器开发，有以下相关实例可供参考：

- [`Sensor`：传感器（ArkTS）（API8）](https://gitee.com/openharmony/applications_app_samples/tree/master/device/Sensor)