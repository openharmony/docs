# Vibrator Development (ArkTS)


## When to Use

You can set different vibration effects as needed, for example, customizing the vibration intensity, frequency, and duration for button touches, alarm clocks, and incoming calls.

For details about the APIs, see [Vibrator](../../reference/apis-sensor-service-kit/js-apis-vibrator.md).


## Available APIs

| Name                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| startVibration(effect: VibrateEffect, attribute: VibrateAttribute): Promise&lt;void&gt; | Starts vibration with the specified effect and attribute. This API uses a promise to return the result.|
| startVibration(effect: VibrateEffect, attribute: VibrateAttribute, callback: AsyncCallback&lt;void&gt;): void | Starts vibration with the specified effect and attribute. This API uses an asynchronous callback to return the result.|
| stopVibration(stopMode: VibratorStopMode): Promise&lt;void&gt; | Stops vibration in the specified mode. This API uses a promise to return the result.           |
| stopVibration(stopMode: VibratorStopMode, callback: AsyncCallback&lt;void&gt;): void | Stops vibration in the specified mode. This API uses an asynchronous callback to return the result.          |
| stopVibration(): Promise&lt;void&gt;                         | Stops vibration in all modes. This API uses a promise to return the result.               |
| stopVibration(callback: AsyncCallback&lt;void&gt;): void     | Stops vibration in all modes. This API uses an asynchronous callback to return the result.              |
| isSupportEffect(effectId: string): Promise&lt;boolean&gt;    | Checks whether an effect ID is supported. This API uses a promise to return the result. This API uses a promise to return the result. The return value **true** means that the effect ID is supported, and **false** means the opposite.|
| isSupportEffect(effectId: string, callback: AsyncCallback&lt;boolean&gt;): void | Checks whether an effect ID is supported. This API uses an asynchronous callback to return the result. This API uses an asynchronous callback to return the result. The return value **true** means that the effect ID is supported, and **false** means the opposite.|


## Vibration Effect Description

Currently, three types of vibration effects are supported.

| Name        | Description                                                        |
| ------------ | ------------------------------------------------------------ |
| Fixed-Duration Vibration| Only a fixed duration is passed in, and the device vibrates based on the default intensity and frequency. For details about the vibration effect, see [VibrateTime](../../reference/apis-sensor-service-kit/js-apis-vibrator.md#vibratetime9).|
| Preset Vibration    | Certain [vibration effects are preset](../../reference/apis-sensor-service-kit/js-apis-vibrator.md#effectid) for fixed scenes. For example, the effect "haptic.clock.timer" is preset to provide feedback when a user adjusts the timer. For details about the vibration effect, see [VibratePreset](../../reference/apis-sensor-service-kit/js-apis-vibrator.md#vibratepreset9).|
| Custom Vibration  | Custom vibration enables you to design vibration effects by customizing a vibration configuration file and orchestrating vibration forms based on the corresponding rules. For details about the vibration effect, see [VibrateFromFile](../../reference/apis-sensor-service-kit/js-apis-vibrator.md#vibratefromfile10).|

The custom vibration configuration file is in JSON format. An example file is as follows:

```json
{
    "MetaData": {
        "Create": "2023-01-09",
        "Description": "a haptic case",
        "Version": 1.0,
        "ChannelNumber": 1
    },
    "Channels": [
        {
            "Parameters": {
                "Index": 0
            },
            "Pattern": [
                {
                    "Event": {
                        "Type": "transient",
                        "StartTime": 0,
                        "Parameters": {
                            "Frequency": 31,
                            "Intensity": 100
                        }
                    }
                },
                {
                    "Event": {
                        "Type": "continuous",
                        "StartTime": 40,
                        "Duration": 54,
                        "Parameters": {
                            "Frequency": 30,
                            "Intensity": 38,
                            "Curve": [
                                {
                                    "Time": 0,
                                    "Frequency": 0,
                                    "Intensity": 0
                                },
                                {
                                    "Time": 1,
                                    "Frequency": 15,
                                    "Intensity": 0.5
                                },
                                {
                                    "Time": 40,
                                    "Frequency": -8,
                                    "Intensity": 1.0
                                },
                                {
                                    "Time": 54,
                                    "Frequency": 0,
                                    "Intensity": 0
                                }
                            ]
                        }
                    }
                }
            ]
        }
    ]
}
```

This JSON file contains two attributes: **MetaData** and **Channels**.
1. **MetaData** contains information about the file header. You can add the following attributes under **MetaData**.

     | Name         | Mandatory| Description                                         |
     | ------------- | ------ | --------------------------------------------- |
     | Version       | Yes    | Version number of the file format, which is forward compatible. Currently, only version 1.0 is supported.|
     | ChannelNumber | Yes    | Number of channels for vibration. A maximum of two channels are supported.   |
     | Create        | No    | Time when the file was created.                         |
     | Description   | No    | Additional information such as the vibration effect and creation information.         |

2. **Channels** provides information about the vibration channel.

     It is a JSON array that holds information about each channel. It contains two attributes: **Parameters** and **Pattern**.

     | Name      | Mandatory| Description                                                        |
     | ---------- | ------ | ------------------------------------------------------------ |
     | Parameters | Yes    | Channel parameters. Among them, **Index** indicates the channel ID. The value **0** indicates both channels, **1** indicates the left channel, and **2** indicates the right channel.|
     | Pattern    | No    | Vibration sequence.                                              |

     **Pattern** is a JSON array that holds the vibration events. Under it, **Event** indicates a vibration event, which can be either of the following types:

     | Vibration Type  | Description                                          |
     | ---------- | ---------------------------------------------- |
     | transient  | Short vibration.                        |
     | continuous | Long vibration.|

     A vibration event contains the following attributes:

     | Name     | Mandatory| Description                                                        |
     | --------- | ------ | ------------------------------------------------------------ |
     | Type      | Yes    | Type of the vibration event, which can be **transient** or **continuous**.                |
     | StartTime | Yes    | Vibration start time. The value range is [0, 1800000], in ms.           |
     | Duration  | Yes    | Vibration duration. This parameter is valid only when **Type** is set to **continuous**. The value range is [0, 5000], in ms.|

3. **Parameters** provides the following parameters related to the vibration event and is mandatory.

     | Name     | Mandatory| Description                                                        |
     | --------- | ------ | ------------------------------------------------------------ |
     | Intensity | Yes    | Vibration intensity. The value range is [0, 100].                          |
     | Frequency | Yes    | Vibration frequency. The value range is [0, 100].                          |
     | Curve     | No    | Vibration curve. This parameter is valid only when **Type** is set to **continuous**. It is a JSON array that holds 4 to 16 adjustment points. Each adjustment point must contain the following attributes:<br>**Time**: offset relative to the event start time. The value ranges from 0 to the vibration duration.<br>**Intensity**: gain relative to the vibration intensity. The value range is [0, 1]. This value multiplied by the vibration intensity is the adjusted intensity at the corresponding time point.<br>**Frequency**: change relative to the vibration frequency. The value range is [-100, 100]. This value plus the vibration frequency is the adjusted frequency at the corresponding time point.|

The following requirements must be met:

| Item| Description                |
| -------- | ------------------------ |
| Number of vibration events| No more than 128|
| Length of the vibration configuration file| Not greater than 64 KB|


## How to Develop

1. Before using the vibrator on a device, you must declare the **ohos.permission.VIBRATE** permission. For details, see [Declaring Permissions](../../security/AccessToken/declare-permissions.md).

2. Start vibration with the specified effect and attribute.

   Scenario 1: Trigger vibration with the specified duration.

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

   Scenario 2: Trigger vibration with a preset effect. You can check whether the preset effect is supported before calling **startVibration()**.

   ```ts
   import { vibrator } from '@kit.SensorServiceKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   try {
     // Check whether 'haptic.effect.soft' is supported.
     vibrator.isSupportEffect('haptic.effect.soft', (err: BusinessError, state: boolean) => {
       if (err) {
         console.error(`Failed to query effect. Code: ${err.code}, message: ${err.message}`);
         return;
       }
       console.info('Succeed in querying effect');
       if (state) {
         try {
           // Start vibration.
           vibrator.startVibration({
             type: 'preset',
             effectId: 'haptic.effect.soft',
             count: 1,
             intensity: 50,
           }, {
             usage: 'unknown'
           }, (error: BusinessError) => {
             if (error) {
               console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
             } else {
               console.info('Succeed in starting vibration');
             }
           });
         } catch (error) {
           let e: BusinessError = error as BusinessError;
           console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
         }
       }
     })
   } catch (error) {
     let e: BusinessError = error as BusinessError;
     console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
   }
   ```

   Scenario 3: Trigger vibration according to a custom vibration configuration file.

   ```ts
   import { vibrator } from '@kit.SensorServiceKit';
   import { resourceManager } from '@kit.LocalizationKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   const fileName: string = 'xxx.json';
   
   // Obtain the file descriptor of the vibration configuration file.
   let rawFd: resourceManager.RawFileDescriptor = getContext().resourceManager.getRawFdSync(fileName);
   
   // Start vibration.
   try {
     vibrator.startVibration({
       type: "file",
       hapticFd: { fd: rawFd.fd, offset: rawFd.offset, length: rawFd.length }
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
   
   // Close the file descriptor of the vibration configuration file.
   getContext().resourceManager.closeRawFdSync(fileName);
   ```

3. Stop vibration.

   Method 1: Stop vibration in the specified mode. This method is invalid for custom vibration.

   ​	Stop fixed-duration vibration.

   ```ts
   import { vibrator } from '@kit.SensorServiceKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   try {
     // Stop vibration in VIBRATOR_STOP_MODE_TIME mode.
     vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_TIME, (error: BusinessError) => {
       if (error) {
         console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
         return;
       }
       console.info('Succeed in stopping vibration');
     })
   } catch (err) {
     let e: BusinessError = err as BusinessError;
     console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
   }
   ```

   ​	Stop preset vibration.

   ```ts
   import { vibrator } from '@kit.SensorServiceKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   
   try {
     // Stop vibration in VIBRATOR_STOP_MODE_PRESET mode.
     vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET, (error: BusinessError) => {
       if (error) {
         console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
         return;
       }
       console.info('Succeed in stopping vibration');
     })
   } catch (err) {
     let e: BusinessError = err as BusinessError;
     console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
   }
   ```

   Method 2: Stop vibration in all modes, including custom vibration.

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


## Samples

The following sample is provided to help you better understand how to develop vibrators:

- [Vibrator (ArkTS, API version 9)](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/Vibrator/BasicVibration)

- [CustomHaptic (ArkTS, Full SDK, API version 10)](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/Vibrator/CustomHaptic)
