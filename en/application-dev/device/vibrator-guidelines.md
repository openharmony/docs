# Vibrator Development


## When to Use

You can set different vibration effects as needed, for example, customizing the vibration intensity, frequency, and duration for button touches, alarm clocks, and incoming calls.

For details about the APIs, see [Vibrator](../reference/apis/js-apis-vibrator.md).


## Available APIs

| Module         | API                                                      | Description                                                        |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ohos.vibrator | startVibration(effect: VibrateEffect, attribute: VibrateAttribute): Promise&lt;void&gt; | Starts vibration with the specified effect and attribute. This API uses a promise to return the result.|
| ohos.vibrator | startVibration(effect: VibrateEffect, attribute: VibrateAttribute, callback: AsyncCallback&lt;void&gt;): void | Starts vibration with the specified effect and attribute. This API uses an asynchronous callback to return the result.|
| ohos.vibrator | stopVibration(stopMode: VibratorStopMode): Promise&lt;void&gt; | Stops vibration in the specified mode. This API uses a promise to return the result.                                |
| ohos.vibrator | stopVibration(stopMode: VibratorStopMode, callback: AsyncCallback&lt;void&gt;): void | Stops vibration in the specified mode. This API uses an asynchronous callback to return the result.                                |
| ohos.vibrator | stopVibration(): Promise&lt;void&gt;                         | Stops vibration in all modes. This API uses a promise to return the result.                                    |
| ohos.vibrator | stopVibration(callback: AsyncCallback&lt;void&gt;): void     | Stops vibration in all modes. This API uses an asynchronous callback to return the result.                                    |
| ohos.vibrator | isSupportEffect(effectId: string): Promise&lt;boolean&gt;    | Checks whether the passed effect ID is supported. This API uses a promise to return the result. The value **true** means that the passed effect ID is supported, and **false** means the opposite. |
| ohos.vibrator | isSupportEffect(effectId: string, callback: AsyncCallback&lt;boolean&gt;): void | Checks whether the passed effect ID is supported. This API uses an asynchronous callback to return the result. The value **true** means that the passed effect ID is supported, and **false** means the opposite. |


## How to Develop

1. Before using the vibrator on a device, you must declare the **ohos.permission.VIBRATE** permission. For details about how to configure a permission, see [Declaring Permissions](../security/accesstoken-guidelines.md).

2. Start vibration with the specified effect and attribute.

   ```js
   import vibrator from '@ohos.vibrator';
   try {
       vibrator.startVibration({ // To use startVibration, you must configure the ohos.permission.VIBRATE permission.
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

3. Stop vibration in the specified mode.

   ```js
   import vibrator from '@ohos.vibrator';
   try {
     // Stop vibration in VIBRATOR_STOP_MODE_TIME mode. To use stopVibration, you must configure the ohos.permission.VIBRATE permission.
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
   
4. Stop vibration in all modes.

   ```js
   import vibrator from '@ohos.vibrator';
   // To use startVibration and stopVibration, you must configure the ohos.permission.VIBRATE permission.
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
       // Stop vibration in all modes.
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

5. Check whether the passed effect ID is supported.

   ```js
   import vibrator from '@ohos.vibrator';
   try {
       // Check whether 'haptic.clock.timer' is supported.
       vibrator.isSupportEffect('haptic.clock.timer', function (err, state) {
           if (err) {
               console.error('isSupportEffect failed, error:' + JSON.stringify(err));
               return;
           }
           console.log('The effectId is ' + (state ? 'supported' : 'unsupported'));
           if (state) {
               try {
                   vibrator.startVibration({ // To use startVibration, you must configure the ohos.permission.VIBRATE permission.
                       type: 'preset',
                       effectId: 'haptic.clock.timer',
                       count: 1,
                   }, {
                       usage: 'unknown'
                   }, (error) => {
                       if(error) {
                           console.error('haptic.clock.timer vibrator error:'  + JSON.stringify(error));
                       } else {
                           console.log('haptic.clock.timer vibrator success');
                       }
                   });
               } catch (error) {
                   console.error('Exception in, error:' + JSON.stringify(error));
               }
           }
       })
   } catch (error) {
       console.error('Exception in, error:' + JSON.stringify(error));
   }
   ```
