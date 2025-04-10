# 设备状态感知开发指导

DeviceStatus（设备状态感知）模块提供设备状态感知能力，可以获取到设备的状态感知信息，例如：获取设备静止姿态感知状态（支架态）。

详细的接口介绍请参考[deviceStatus接口](../../reference/apis-multimodalawareness-kit/js-apis-awareness-deviceStatus.md)。

## 基本概念

在进行设备状态感知模块的使用前，开发者应了解以下基本概念：

- 支架态

    设备进入支架态指设备静止，且屏幕与水平面角度处于45度-135度。折叠屏手机需处于折叠状态或者完全展开状态。

## 获取设备静止姿态感知状态（支架态）开发指导

### 场景介绍

开发过程中，需要订阅设备静止姿态（支架态）感知，并且通过订阅时传入的回调函数来获取到当前的状态值。

### 约束与限制

<!--RP1-->设备需要支持加速度计，并支持特定芯片。<!--RP1End-->

### 接口说明

| 接口名                                                       | 描述                                   |
| ------------------------------------------------------------ | -------------------------------------- |
| on(type: 'steadyStandingDetect', callback: Callback&lt;SteadyStandingStatus&gt;): void; | 订阅设备静止姿态（支架态）感知，结果通过callback返回。 |
| off(type: 'steadyStandingDetect', callback: Callback&lt;SteadyStandingStatus&gt;): void; | 取消订阅设备静止姿态（支架态）感知。                   |

### 开发步骤

1. 导入模块。

  ```ts
  import { deviceStatus } from '@kit.MultimodalAwarenessKit';
  ```

2. 订阅设备静止姿态（支架态）感知事件。

  ```ts
  try {
    deviceStatus.on('steadyStandingDetect', (data:deviceStatus.SteadyStandingStatus) => {
      console.info('now status = ' + data);
    });
  } catch (err) {
    console.info('on failed, err = ' + err);
  }
  ```

3. 取消订阅本客户端订阅的所有设备静止姿态（支架态）感知事件。

  ```ts
  try {
    deviceStatus.off('steadyStandingDetect');
  } catch (err) {
    console.info('off failed, err = ' + err);
  }
  ```

4. 取消订阅设备静止姿态（支架态）感知事件的特定回调。

  ```ts
  import { Callback } from '@ohos.base';
  // 定义callback变量
  let callback : Callback<deviceStatus.SteadyStandingStatus> = (data : deviceStatus.SteadyStandingStatus) => {
    console.info('now status = ' + data);
  };
  // 以callback为回调函数，订阅设备静止姿态感知（支架态）事件
  try {
    deviceStatus.on('steadyStandingDetect', callback);
  } catch (err) {
    console.info('on failed, err = ' + err);
  }
  // 取消该客户端订阅设备静止姿态感知（支架态）事件的特定回调函数
  try {
    deviceStatus.off('steadyStandingDetect', callback);
  } catch (err) {
    console.info('off failed, err = ' + err);
  }
  ```