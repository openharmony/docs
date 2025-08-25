# 振动开发指导
<!--Kit: Sensor Service Kit-->
<!--Subsystem: Sensors-->
<!--Owner: @dilligencer-->
<!--Designer: @butterls-->
<!--Tester: @murphy84-->
<!--Adviser: @hu-zhiqiong-->

## 场景介绍

当设备需要振动固定时长时，可以调用Vibrator模块，例如：设备的按键可以设置不同时长的振动。

详细的接口介绍请参考[Vibrator接口](../../reference/apis-sensor-service-kit/js-apis-vibrator.md)。


## 接口说明

| 名称                                                         | 描述                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| startVibration(effect: VibrateTime, attribute: VibrateAttribute): Promise&lt;void&gt; | 根据指定振动效果和振动属性触发马达振动，使用Promise异步回调。 |
| startVibration(effect: VibrateTime, attribute: VibrateAttribute, callback: AsyncCallback&lt;void&gt;): void | 根据指定振动效果和振动属性触发马达振动，使用Callback异步回调。 |
| stopVibration(): Promise&lt;void&gt;                         | 停止所有模式的马达振动，使用Promise异步回调。                |
| stopVibration(callback: AsyncCallback&lt;void&gt;): void     | 停止所有模式的马达振动，使用Callback异步回调。               |


## 开发步骤

1. 控制设备上的振动器，需要申请权限ohos.permission.VIBRATE。具体配置方式请参考[声明权限](../../security/AccessToken/declare-permissions.md)。

2. 根据指定振动时长和振动属性触发马达振动。

    ```ts
    import { vibrator } from '@kit.SensorServiceKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    try {
      // 触发马达振动
      vibrator.startVibration({
        type: 'time',
        duration: 1000,
      }, {
        id: 0,
        usage: 'alarm'
      }, (error: BusinessError) => {
        if (error) {
          console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
          return;
        }
        console.info('Succeed in starting vibration');
      });
    } catch (err) {
      let e: BusinessError = err as BusinessError;
      console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
    }
    ```

3. 停止马达的振动。

    ```ts
    import { vibrator } from '@kit.SensorServiceKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    try {
      // 停止所有模式的马达振动
      vibrator.stopVibration((error: BusinessError) => {
        if (error) {
          console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
          return;
        }
        console.info('Succeed in stopping vibration');
      })
    } catch (error) {
      let e: BusinessError = error as BusinessError;
      console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
    }
    ```
