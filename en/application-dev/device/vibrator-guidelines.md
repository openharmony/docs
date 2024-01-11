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
| ohos.vibrator | isSupportEffect(effectId: string): Promise&lt;boolean&gt;    | Checks whether an effect ID is supported. This API uses a promise to return the result. The value **true** means that the effect ID is supported, and **false** means the opposite.|
| ohos.vibrator | isSupportEffect(effectId: string, callback: AsyncCallback&lt;boolean&gt;): void | Checks whether an effect ID is supported. This API uses an asynchronous callback to return the result. The value **true** means that the effect ID is supported, and **false** means the opposite.|


## Vibration Effect Description

Currently, three types of vibration effects are supported.

### Fixed-Duration Vibration

Only a fixed duration is passed in, and the device vibrates based on the default intensity and frequency. For details about the vibration effect, see [VibrateTime](../reference/apis/js-apis-vibrator.md#vibratetime9).

### Preset Vibration

Certain [vibration effects are preset](../reference/apis/js-apis-vibrator.md#effectid) for fixed scenes. For example, the effect "haptic.clock.timer" is preset to provide feedback when a user adjusts the timer. For details about the vibration effect, see [VibratePreset](../reference/apis/js-apis-vibrator.md#vibratepreset9).

### Custom Vibration

Custom vibration enables you to design vibration effects by customizing a vibration configuration file and orchestrating vibration forms based on the corresponding rules. For details about the vibration effect, see [VibrateFromFile](../reference/apis/js-apis-vibrator.md#vibratefromfile10).

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
- **MetaData** contains information about the file header. You can add the following attributes under **MetaData**:
  - **Version**: mandatory; version number of the file format, which is forward compatible. Currently, only version 1.0 is supported.
  - **ChannelNumber**: mandatory; number of channels for vibration. A maximum of two channels are supported.
  - **Create**: optional; time when the file was created.
  - **Description**: optional; additional information such as the vibration effect and creation information.
- **Channels** provides information about the vibration channel. It is a JSON array that holds information about each channel. It contains two attributes: **Parameters** and **Pattern**.
  - **Parameters** provides parameters related to the channel. Among them, **Index** indicates the channel ID and is mandatory. The value **0** indicates both channels, **1** indicates the left channel, and **2** indicates the right channel.
  - **Pattern** indicates the vibration sequence.It is a JSON array that holds the vibration events. Under it, **Event** indicates a vibration event, which contains the following attributes:
    - **Type**: mandatory; type of the vibration event, which can be **transient** or **continuous**.
    - **StartTime**: mandatory; vibration start time. The value range is [0, 1800000], in ms.
- **Duration**: vibration duration. This parameter is valid and mandatory only when **Type** is set to **continuous**. The value range is [0, 5000], in ms.
    - **Parameters**: mandatory; parameters related to the vibration event. You can set the following parameters:
       - **Intensity**: mandatory; vibration intensity. The value range is [0, 100].
       - **Frequency**: mandatory; vibration frequency. The value range is [0, 100].
       - **Curve**: optional; vibration curve. This parameter is valid only when **Type** is set to **continuous**. It is a JSON array that holds 4 to 16 adjustment points. Each adjustment point must contain the following attributes:
         * **Time**: offset relative to the event start time. The value ranges from 0 to the vibration duration.
         * **Intensity**: gain relative to the vibration intensity. The value range is [0, 1]. This value multiplied by the vibration intensity is the adjusted intensity at the corresponding time point.
         * **Frequency**: change relative to the vibration frequency. The value range is [-100, 100]. This value plus the vibration frequency is the adjusted frequency at the corresponding time point.

The following requirements must be met:

| Item| Description                |
| -------- | ------------------------ |
| Number of vibration events| No more than 128|
| Length of the vibration configuration file| Not greater than 64 KB|


## How to Develop

1. Before using the vibrator on a device, you must declare the **ohos.permission.VIBRATE** permission. For details about how to configure a permission, see [Declaring Permissions](../security/accesstoken-guidelines.md).

2. Start vibration with the specified effect and attribute.

- Scenario 1: Trigger vibration with the specified duration.

  ```ts
  import vibrator from '@ohos.vibrator';
  import { BusinessError } from '@ohos.base';
  
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

- Scenario 2: Trigger vibration with a preset effect. You can check whether the preset effect is supported before calling **startVibration()**.

  ```ts
  import vibrator from '@ohos.vibrator';
  import { BusinessError } from '@ohos.base';
  
  try {
    // Check whether 'haptic.clock.timer' is supported.
    vibrator.isSupportEffect('haptic.clock.timer', (err: BusinessError, state: boolean) => {
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
            effectId: 'haptic.clock.timer',
            count: 1,
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

- Scenario 3: Trigger vibration according to a custom vibration configuration file.

  ```ts
  import vibrator from '@ohos.vibrator';
  import resourceManager from '@ohos.resourceManager';
  import { BusinessError } from '@ohos.base';
  
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

- Method 1: Stop vibration in the specified mode. This method is invalid for custom vibration.

   - Stop fixed-duration vibration.

      ```ts
      import vibrator from '@ohos.vibrator';
      import { BusinessError } from '@ohos.base';
      
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

   - Stop preset vibration.

     ```ts
     import vibrator from '@ohos.vibrator';
     import { BusinessError } from '@ohos.base';
     
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

- Method 2: Stop vibration in all modes, including custom vibration.

  ```ts
  import vibrator from '@ohos.vibrator';
  import { BusinessError } from '@ohos.base';
  
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

