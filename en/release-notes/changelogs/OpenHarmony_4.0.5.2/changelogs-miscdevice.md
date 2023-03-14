# Pan-sensor Subsystem Changelog

## cl.vibrator Added isSupportEffect

The **isSupportEffect** API is added.

**Change Impact**

Applications developed based on OpenHarmony4.0.5.2 or a later SDK version can use **isSupportEffect** to check whether the passed effect ID is supported.

**Key API/Component Changes**

The **isSupportEffect** API is added in **@ohos.vibrator.d.ts**.

| Module| Class| Method/Attribute/Enum/Constant| Change Type|
|  -- | -- | -- | -- |
| @ohos.vibrator.d.ts | vibrator | isSupportEffect(effectId: string, callback: AsyncCallback&lt;boolean&gt;): void | Added|
| @ohos.vibrator.d.ts | vibrator | isSupportEffect(effectId: string): Promise&lt;boolean&gt; | Added|

**Adaptation Guide**

Call **isSupportEffect** to check whether the passed effect ID is supported.

```ts
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

## cl.vibrator Added stopVibration

The **stopVibration** API is added.

**Change Impact**

Applications developed based on OpenHarmony4.0.5.2 or a later SDK version can use **stopVibration** to stop vibration in all modes.

**Key API/Component Changes**

The **stopVibration** API is added in **@ohos.vibrator.d.ts**.

| Module             | Class    | Method/Attribute/Enum/Constant                                     | Change Type|
| ------------------- | -------- | -------------------------------------------------------- | -------- |
| @ohos.vibrator.d.ts | vibrator | stopVibration(callback: AsyncCallback&lt;void&gt;): void | Added    |
| @ohos.vibrator.d.ts | vibrator | stopVibration(): Promise&lt;void&gt;                     | Added    |

**Adaptation Guide**

Call **stopVibration** to stop vibration in all modes.

```ts
import vibrator from '@ohos.vibrator';
try {
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
