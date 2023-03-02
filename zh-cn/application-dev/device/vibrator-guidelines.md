# Vibrator开发指导


## 场景介绍

当设备需要设置不同的振动效果时，可以调用Vibrator模块，例如：设备的按键可以设置不同强度和不同时长的振动，闹钟和来电可以设置不同强度和时长的单次或周期振动。

详细的接口介绍请参考[Vibrator接口](../reference/apis/js-apis-vibrator.md)。


## 接口说明

| 模块          | 接口名                                                       | 描述                                                         |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ohos.vibrator | startVibration(effect: VibrateEffect, attribute: VibrateAttribute): Promise&lt;void&gt; | 根据指定振动效果和振动属性触发马达振动，使用Promise异步回调。 |
| ohos.vibrator | startVibration(effect: VibrateEffect, attribute: VibrateAttribute, callback: AsyncCallback&lt;void&gt;): void | 根据指定振动效果和振动属性触发马达振动，使用Callback异步回调。 |
| ohos.vibrator | stopVibration(stopMode: VibratorStopMode): Promise&lt;void&gt; | 按照指定模式停止马达的振动。                                 |
| ohos.vibrator | stopVibration(stopMode: VibratorStopMode, callback: AsyncCallback&lt;void&gt;): void | 按照指定模式停止马达的振动。                                 |
| ohos.vibrator | stopVibration(callback: AsyncCallback&lt;void&gt;): void     | 停止所有模式的马达振动。                                     |
| ohos.vibrator | stopVibration(): Promise&lt;void&gt;                         | 停止所有模式的马达振动。                                     |
| ohos.vibrator | isSupportEffect(effectId: string, callback: AsyncCallback&lt;boolean&gt;): void | 查询是否支持传入的参数effectId。                             |
| ohos.vibrator | isSupportEffect(effectId: string): Promise&lt;void&gt;       | 查询是否支持传入的参数effectId。                             |


## 开发步骤

1. 控制设备上的振动器，需要申请权限ohos.permission.VIBRATE。具体配置方式请参考[权限申请声明](../security/accesstoken-guidelines.md)。

2. 根据指定振动效果和振动属性触发马达振动。

   ```js
   import vibrator from '@ohos.vibrator';
   try {
       vibrator.startVibration({
           type: 'time',
           duration: 1000,
       }, {
           id: 0,
           usage: 'alarm'
       }, (error) => {
           if (error) {
               console.error('vibrate fail, error.code: ' + error.code + 'error.message: ', + error.message);
               return;
           }
           console.log('Callback returned to indicate a successful vibration.');
       });
   } catch (err) {
       console.error('errCode: ' + err.code + ' ,msg: ' + err.message);
   }
   ```

3. 按照指定模式停止马达的振动。 

   ```js
   import vibrator from '@ohos.vibrator';
   try {
     // 按照VIBRATOR_STOP_MODE_TIME模式停止振动
     vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_TIME, function (error) {
         if (error) {
             console.log('error.code' + error.code + 'error.message' + error.message);
             return;
         }
         console.log('Callback returned to indicate successful.');
     })
   } catch (err) {
     console.info('errCode: ' + err.code + ' ,msg: ' + err.message);
   }
   ```
   
4. 停止所有模式的马达振动。

   ```js
   import vibrator from '@ohos.vibrator';
   try {
       // 停止所有模式的马达振动
       vibrator.stopVibration(function (error) {
           if (error) {
               console.log('error.code' + error.code + 'error.message' + error.message);
               return;
           }
           console.log('Callback returned to indicate successful.');
       })
   } catch (error) {
       console.info('errCode: ' + error.code + ' ,msg: ' + error.message);
   }
   ```

5. 查询是否支持传入的参数effectId。

   ```js
   import vibrator from '@ohos.vibrator';
   try {
       // 查询是否支持'haptic.clock.timer'
       vibrator.isSupportEffect('haptic.clock.timer', function (state) {
           console.log('The effectId is ' + (state ? 'supported' : 'unsupported'));
           if (state) {
               try {
       		    vibrator.startVibration({
                   type: 'preset',
                   effectId: 'haptic.clock.timer',
                   count: 1,
                   }, {
                       usage: 'unknown'
                   }, (error) => {
                       if(error) {
                           console.log('haptic.clock.timer vibrator error');
                       } else {
                           console.log('haptic.clock.timer vibrator success');
                       }
                   });
               } catch (error) {
                   console.error('errCode: ' + error.code + ' ,msg: ' + error.message);
               }
           }
       })
   } catch (error) {
       console.error('exception in, error:' + JSON.stringify(error));
   }
   ```

   

## 相关实例

针对振动开发，有以下相关实例可供参考：

- [`Vibrator`：振动（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/Vibrator)