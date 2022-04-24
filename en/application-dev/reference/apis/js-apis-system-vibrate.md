# Vibrator


> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
> - The initial APIs of this module are supported since API version 4. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module are no longer maintained since API version 8. You are advised to use [`@ohos.vibrator`](js-apis-vibrator.md) instead.
> - This module requires hardware support and can only be debugged on real devices.


## Modules to Import


```
import vibrator from '@system.vibrator';
```


## vibrator.vibrate

vibrate(Object): void

Triggers device vibration.

**System capability**: SystemCapability.Sensors.MiscDevice

**Required permissions**: ohos.permission.VIBRATE (a system permission)

**Parameters**

| Name| Type| Mandatory| Description| 
| -------- | -------- | -------- | -------- |
| mode | string | No| Vibration mode. The value **long** indicates long vibration, and **short** indicates short vibration. The default value is **long**.|

**Example**

```
vibrator.vibrate({
  mode: 'short',
  success: function() {
    console.log('vibrate is successful');
  },
  fail: function(data, code) {
    console.log("vibrate is failed, data: " + data + ", code: " + code);
  },
  complete: function() {
    console.log('vibrate is completed');
  }
});
```
