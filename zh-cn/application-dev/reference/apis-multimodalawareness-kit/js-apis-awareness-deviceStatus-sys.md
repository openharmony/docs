# @ohos.multimodalAwareness.deviceStatus（设备状态感知）（系统接口）
<!--Kit: Multimodal Awareness Kit-->
<!--Subsystem: MultimodalAwareness-->
<!--Owner: @dilligencer-->
<!--Designer: @zou_ye-->
<!--Tester: @judan-->
<!--Adviser: @hu-zhiqiong-->

本模块提供对设备状态的感知能力。

> **说明：**
>
> 本模块首批接口从API version 20开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> 本模块为系统接口。

## 导入模块

   ```ts
   import { deviceStatus } from '@kit.MultimodalAwarenessKit';
   ```

## deviceStatus.getDeviceRotationRadian()

getDeviceRotationRadian(): Promise&lt;DeviceRotationRadian&gt;

获取设备的姿态数据。

姿态数据包含x、y、z三轴的姿态旋转角，即三轴的欧拉角，三轴定义与设备sensor定义相同，为右手系。姿态旋转角在ZXY旋转顺序、内旋下计算，通过传感器融合获取的四元数计算得到结果。

**系统能力**：SystemCapability.MultimodalAwareness.DeviceStatus

**系统API**：此接口为系统接口

**错误码**：

以下错误码的详细介绍请参见[设备状态感知错误码](errorcode-deviceStatus.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 202      | Permission check failed. A non-system application uses the system API. |
| 801      | Capability not supported. Function can not work correctly due to limited device capabilities. |
| 32500001 | Service exception. |

**示例**：

   ```ts
   import { deviceStatus } from '@kit.MultimodalAwarenessKit';
   import { BusinessError } from '@kit.BasicServicesKit';

   try {
      deviceStatus.getDeviceRotationRadian().then((radian: deviceStatus.DeviceRotationRadian) => {
         console.info('x:' + radian.x + ' y:' + radian.y + ' z:' + radian.z);
      }).catch((err: BusinessError) => {
         console.error('get device rotation radian failed, errmsg:' + err);
      })
   } catch (err) {
      console.error('invoke failed, errmsg:' + err)
   }
   ```
