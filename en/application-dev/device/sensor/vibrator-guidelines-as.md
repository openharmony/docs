# Vibrator Development


## When to Use

You can set different vibration effects for your device, for example, you can set vibration effects with different intensities and durations for buttons on the device.

For details about the APIs, see [Vibrator](../../reference/apis-sensor-service-kit/js-apis-vibrator.md).


## Available APIs

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| startVibration(effect: VibrateTime, attribute: VibrateAttribute): Promise&lt;void&gt; | Starts vibration with the specified effect and attribute. This API uses a promise to return the result.|
| startVibration(effect: VibrateTime, attribute: VibrateAttribute, callback: AsyncCallback&lt;void&gt;): void | Starts vibration with the specified effect and attribute. This API uses an asynchronous callback to return the result.|
| stopVibration(): Promise&lt;void&gt;                         | Stops vibration in all modes. This API uses a promise to return the result.               |
| stopVibration(callback: AsyncCallback&lt;void&gt;): void     | Stops vibration in all modes. This API uses an asynchronous callback to return the result.              |


## How to Develop

1. Before using the vibrator on a device, you must declare the **ohos.permission.VIBRATE** permission. For details, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

2. Configure the vibrator to vibrate with the specified duration and attribute.

    ```ts
    import { vibrator } from '@kit.SensorServiceKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    try {
      // Start vibration.
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

3. Stop vibration.

    ```ts
    import { vibrator } from '@kit.SensorServiceKit';
    import { BusinessError } from '@kit.BasicServicesKit';

    try {
      // Stop vibration in all modes.
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
