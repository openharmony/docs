# @system.vibrator (Vibrator)

The **Vibrator** module provides APIs for controlling LED lights and vibrators. You can use the APIs to query the LED light list, turn on and off the LED light, query the vibrator list, query the vibrator effect, and trigger and turn off the vibrator.

Misc devices refer to LED lights and vibrators on devices. LED lights are mainly used for indication (for example, indicating the charging state) and blinking (such as tri-colored lights). Vibrators are mainly used in scenarios such as the alarm clock, power-on/off, and incoming call vibration.


> **NOTE**
> - The initial APIs of this module are supported since API version 3. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module are no longer maintained since API version 8. You are advised to use [`@ohos.vibrator`](js-apis-vibrator.md) instead.
> - This module requires hardware support and can only be debugged on real devices.


## Modules to Import


```ts
import { Vibrator } from '@kit.SensorServiceKit';
```

## Vibrator.vibrate

 vibrate(options?: VibrateOptions): void

Triggers device vibration.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice.Lite

**Parameters**

| Name | Type                             | Mandatory| Description      |
| ------- | --------------------------------- | ---- | ---------- |
| options | [VibrateOptions](#vibrateoptions) | No  | Vibration options.|

**Example**

```ts
import { Vibrator, VibrateOptions } from '@kit.SensorServiceKit';

let vibrateOptions: VibrateOptions = {
  mode: 'short',
  success: () => {
    console.info('Succeed in vibrating');
  },
  fail: (data: string, code: number) => {
    console.info(`Failed to vibrate. Data: ${data}, code: ${code}`);
  },
  complete: () => {
    console.info('completed in vibrating');
  }
};
Vibrator.vibrate(vibrateOptions);
```

## VibrateOptions

Defines the vibration options.

**Required permissions**: ohos.permission.VIBRATE

**System capability**: SystemCapability.Sensors.MiscDevice.Lite

| Name    | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| mode     | string   | No  | Vibration mode. The value **long** indicates long vibration, and **short** indicates short vibration. The default value is **long**.|
| success  | Function | No  | Called when the vibrator data changes.                            |
| fail     | Function | No  | Called when the API call fails.                                    |
| complete | Function | No  | Called when the API call is complete.                                    |
