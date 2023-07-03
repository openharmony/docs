# Pan-sensor Subsystem Changelog


## cl.vibrator.1 Added Attributes Related to Custom Vibration

The attributes **VibrateFromFile** (custom vibration effect) and **HapticFileDescriptor** (file descriptor of the custom vibration configuration file) are added. The vibration effect supported by **startVibration** is extended from **VibrateEffect = VibrateTime | VibratePreset** to **VibrateEffect = VibrateTime | VibratePreset | VibrateFromFile**.

**Change Impact**

When developing applications based on OpenHarmony4.0.8.2 and later SDK versions, you can use the **VibrateFromFile** attribute to enable devices that support custom vibration to trigger vibration according to the vibration sequence configured in the custom vibration configuration file.

**Key API/Component Changes**

Added the **VibrateFromFile** and **HapticFileDescriptor** attributes to **@ohos.vibrator.d.ts**.

| Module| Class| Method/Attribute/Enum/Constant| Change Type|
|  -- | -- | -- | -- |
| @ohos.vibrator.d.ts | vibrator | HapticFileDescriptor | Added|
| @ohos.vibrator.d.ts | vibrator | VibrateFromFile | Added|

**Adaptation Guide**

Obtain the resources in the vibration configuration file through the resource management API, and start or stop custom vibration as required.

```ts
import vibrator from '@ohos.vibrator';
import resourceManager from '@ohos.resourceManager';

const FILE_NAME = "xxx.json";

async function openResource(fileName) {
    let fileDescriptor = undefined;
    let mgr = await resourceManager.getResourceManager();
    await mgr.getRawFd(fileName).then(value => {
        fileDescriptor = {fd: value.fd, offset: value.offset, length: value.length};
        console.log('openResource success fileName: ' + fileName);
    }).catch(error => {
        console.log('openResource err: ' + error);
    });
    return fileDescriptor;
}

async function closeResource(fileName) {
    let mgr = await resourceManager.getResourceManager();
    await mgr.closeRawFd(fileName).then(()=> {
        console.log('closeResource success fileName: ' + fileName);
    }).catch(error => {
        console.log('closeResource err: ' + error);
    });
}

// Obtain the file descriptor of the vibration configuration file.
let rawFd = openResource(FILE_NAME);
// To use startVibration and stopVibration, you must configure the ohos.permission.VIBRATE permission.
try {
    // Start custom vibration.
    vibrator.startVibration({
        type: "file",
        hapticFd: { fd: rawFd.fd, offset: rawFd.offset, length: rawFd.length }
    }, {
        usage: "alarm"
    }).then(() => {
        console.info('startVibration success');
    }, (error) => {
        console.info('startVibration error');
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
// Close the vibration configuration file.
closeResource(FILE_NAME);
```
