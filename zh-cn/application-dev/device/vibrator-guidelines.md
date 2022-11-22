# Vibrator开发指导


## 场景介绍

当设备需要设置不同的振动效果时，可以调用Vibrator模块，例如：设备的按键可以设置不同强度和不同时长的振动，闹钟和来电可以设置不同强度和时长的单次或周期振动。

详细的接口介绍请参考[Vibrator接口](../reference/apis/js-apis-vibrator.md)。


## 接口说明

| 模块            | 接口名                                      | 描述                              |
| ------------- | ---------------------------------------- | ------------------------------- |
| ohos.vibrator | vibrate(duration:&nbsp;number):&nbsp;Promise&lt;void&gt; | 触发马达按照时长振动，使用Promise异步回调。       |
| ohos.vibrator | vibrate(duration:&nbsp;number,&nbsp;callback?:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 触发马达按照时长振动，使用Callback异步回调。      |
| ohos.vibrator | vibrate(effectId:&nbsp;EffectId):&nbsp;Promise&lt;void&gt; | 触发马达按照开发者传递效果振动，使用Promise异步回调。  |
| ohos.vibrator | vibrate(effectId:&nbsp;EffectId,&nbsp;callback?:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 触发马达按照开发者传递效果振动，使用Callback异步回调。 |
| ohos.vibrator | stop(stopMode:&nbsp;VibratorStopMode):&nbsp;Promise&lt;void&gt; | 停止振动。                           |
| ohos.vibrator | stop(stopMode:&nbsp;VibratorStopMode,&nbsp;callback?:&nbsp;AsyncCallback&lt;void&gt;):&nbsp;void | 停止振动。                           |


## 开发步骤

1. 控制设备上的振动器，需要申请权限ohos.permission.VIBRATE。具体配置方式请参考[权限申请声明](../security/accesstoken-guidelines.md)。

2. 触发设备振动。

   ```
   import vibrator from "@ohos.vibrator"
   vibrator.vibrate(1000).then((error) => {
       if (error) { //调用失败，打印error.code和error.message
          console.log("Promise return failed.error.code " + error.code + "error.message " + error.message);  
       } else { //调用成功,设备开始振动
          console.log("Promise returned to indicate a successful vibration.")  
       }
   })
   ```

3. 停止设备振动。

   ```
   import vibrator from "@ohos.vibrator"
   vibrator.stop(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET).then((error) => {
      if (error) { //调用失败，打印error.code和error.message
          console.log("Promise return failed.error.code " + error.code + "error.message " + error.message);
      } else { //调用成功，设备停止振动
          console.log("Promise returned to indicate successful.");
      }
   })
   ```

## 相关实例

针对振动开发，有以下相关实例可供参考：

- [`Vibrator`：振动（ArkTS）（API8）](https://gitee.com/openharmony/applications_app_samples/tree/master/device/Vibrator)