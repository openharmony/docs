# Audio Management<a name="EN-US_TOPIC_0000001149807881"></a>


## Modules to Import<a name="modules-to-import"></a>

```
import audio from '@ohos.multimedia.audio';
```

## Required Permissions<a name="required-permissions"></a>

None

## getAudioManager\(\): AudioManager<a name="getaudiomanager-audiomanager"></a>

Obtains an  **AudioManager**  instance.

**Return values**

| Type           | Description                                                           |
| -------------- | -------------------------- |
| <a href="#section8265143814015">AudioManager</a>        | Audio manager.                                                        |


**Example**

```
var audioManager = audio.getAudioManager();
```

## AudioVolumeType<a name="audiovolumetype"></a>

Enumerates audio stream types.

| Name           | Default Value | Description                                                           |
| -------------- | ------------- | --------------------------------------------------------------------- |
| RINGTONE       | 2             | Audio stream for ringtones.                                                              |
| MEDIA        | 3             | Audio stream for media purpose.                                                               |

## DeviceFlag<a name="deviceflag"></a>

Enumerates audio device flags.

| Name           | Default Value | Description                                                           |
| -------------- | ------------- | --------------------------------------------------------------------- |
| OUTPUT_DEVICES_FLAG        | 1             | Output device.                                                        |
| INPUT_DEVICES_FLAG       | 2             | Input device.                                                              |
| ALL_DEVICES_FLAG        | 3             | All devices.                                                               |


## DeviceRole<a name="devicerole"></a>

Enumerates audio device roles.

| Name           | Default Value | Description                                                           |
| -------------- | ------------- | --------------------------------------------------------------------- |
| INPUT_DEVICE        | 1             | Input role.                                                        |
| OUTPUT_DEVICE       | 2             | Output role.                                                              |

## DeviceType<a name="devicetype"></a>

Enumerates audio device types.

| Name           | Default Value | Description                                                           |
| -------------- | ------------- | --------------------------------------------------------------------- |
| INVALID        | 0             | Invalid device.                                                        |
| EARPIECE       | 1             | Earpiece.                                                              |
| SPEAKER        | 2             | Speaker.                                                               |
| WIRED_HEADSET  | 3             | Wired headset.                                                         |
| BLUETOOTH_SCO  | 7             | Bluetooth device using the synchronous connection oriented (SCO) link. |
| BLUETOOTH_A2DP | 8             | Bluetooth device using the advanced audio distribution profile (A2DP). |
| MIC            | 15            | Microphone.                                                            |


## ActiveDeviceType<sup>7+</sup><a name="activedevicetype"></a>

Enumerates active device types.

| Name           | Default Value | Description                                                           |
| -------------- | ------------- | --------------------------------------------------------------------- |
| SPEAKER        | 2             | Speaker.                                                               |
| BLUETOOTH_SCO  | 7             | Bluetooth device using the SCO link. |

## AudioRingMode<sup>7+</sup><a name="audioringmode"></a>

Enumerates ringer modes.

| Name          | Default Value | Description                                                           |
| ------------- | ------------- | --------------------------------------------------------------------- |
| RINGER_MODE_SILENT       | 0             | Silence mode.                                                               |
| RINGER_MODE_VIBRATE | 1             | Vibration mode. |
| RINGER_MODE_NORMAL | 2             | Normal mode. |

## AudioManager<a name="section8265143814015"></a>

Implements audio volume and audio device management.

### setVolume\(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback<void\>\): void<a name="setvolume-asynccallback"></a>

Sets the volume for a stream. This method uses an asynchronous callback to return the execution result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| volumeType       | <a href="#audiovolumetype">AudioVolumeType</a>             | Yes        | Audio stream type.                                                       |
| volume       | number              | Yes        | Volume to set. The value range can be obtained by calling **getMinVolume** and **getMaxVolume**.                                                       |
| callback       | AsyncCallback<void\>              | Yes        | Callback used to return the execution result.                                                       |

**Return values**

None

**Example**

```
audioManager.setVolume(audio.AudioVolumeType.MEDIA, 10, (err)=>{
   if (err) {
	   console.error('Failed to set the volume. ${err.message}');
	   return;
   }
   console.log('Callback invoked to indicate a successful volume setting.');
})
```

### setVolume\(volumeType: AudioVolumeType, volume: number\): Promise<void\><a name="setvolume-promise"></a>

Sets the volume for a stream. This method uses a promise to return the execution result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| volumeType       | <a href="#audiovolumetype">AudioVolumeType</a>             | Yes        | Audio stream type.                                                       |
| volume       | number              | Yes        | Volume to set. The value range can be obtained by calling **getMinVolume** and **getMaxVolume**.                                                       |

**Return values**

| Name          | Description                                   | 
| ------------- | -------------------------------------------------------- |
| Promise<void\>       | Promise used to return the execution result.                                                       |

**Example**

```
audioManager.setVolume(audio.AudioVolumeType.MEDIA, 10).then(()=>
    console.log('Promise returned to indicate a successful volume setting.');
)
```

### getVolume\(volumeType: AudioVolumeType, callback: AsyncCallback<number\>\): void<a name="getvolume-asynccallback"></a>

Obtains the volume of a stream. This method uses an asynchronous callback to return the query result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| volumeType       | <a href="#audiovolumetype">AudioVolumeType</a>             | Yes        | Audio stream type.                                                       |
| callback       | AsyncCallback<number\>              | Yes        | Callback used to return the volume.                                                       |

**Return values**

None

**Example**

```
audioManager.getVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
   if (err) {
	   console.error('Failed to obtain the volume. ${err.message}');
	   return;
   }
   console.log('Callback invoked to indicate that the volume is obtained.');
})
```

### getVolume\(volumeType: AudioVolumeType\): Promise<number\><a name="getvolume-promise"></a>

Obtains the volume of a stream. This method uses a promise to return the query result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| volumeType       | <a href="#audiovolumetype">AudioVolumeType</a>             | Yes        | Audio stream type.                                                       |

**Return values**

| Name          | Description                                   | 
| ------------- | -------------------------------------------------------- |
| Promise<number\>       | Promise used to return the volume.                                                       |

**Example**

```
audioManager.getVolume(audio.AudioVolumeType.MEDIA).then((value) =>
    console.log('Promise returned to indicate that the volume is obtained.' + value);
)
```

### getMinVolume\(volumeType: AudioVolumeType, callback: AsyncCallback<number\>\): void<a name="getminvolume-asynccallback"></a>

Obtains the minimum volume allowed for a stream. This method uses an asynchronous callback to return the query result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| volumeType       | <a href="#audiovolumetype">AudioVolumeType</a>             | Yes        | Audio stream type.                                                       |
| callback       | AsyncCallback<number\>              | Yes        | Callback used to return the minimum volume.                                                       |

**Return values**

None

**Example**

```
audioManager.getMinVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
    if (err) {
        console.error('Failed to obtain the minimum volume. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the minimum volume is obtained.' + value);
})
```

### getMinVolume\(volumeType: AudioVolumeType\): Promise<number\><a name="getminvolume-promise"></a>

Obtains the minimum volume allowed for a stream. This method uses a promise to return the query result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| volumeType       | <a href="#audiovolumetype">AudioVolumeType</a>             | Yes        | Audio stream type.                                                       |

**Return values**

| Name          | Description                                   | 
| ------------- | -------------------------------------------------------- |
| Promise<number\>       | Promise used to return the minimum volume.                                                       |


**Example**

```
audioManager.getMinVolume(audio.AudioVolumeType.MEDIA).then((value) =>
    console.log('Promised returned to indicate that the minimum volume is obtained.' + value);
)
```

### getMaxVolume\(volumeType: AudioVolumeType, callback: AsyncCallback<number\>\): void<a name="getmaxvolume-asynccallback"></a>

Obtains the maximum volume allowed for a stream. This method uses an asynchronous callback to return the query result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| volumeType       | <a href="#audiovolumetype">AudioVolumeType</a>             | Yes        | Audio stream type.                                                       |
| callback       | AsyncCallback<number\>              | Yes        | Callback used to return the maximum volume.                                                       |

**Return values**

None

**Example**

```
audioManager.getMaxVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
    if (err) {
        console.error('Failed to obtain the maximum volume. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the maximum volume is obtained.' + value);
})
```

### getMaxVolume\(volumeType: AudioVolumeType\): Promise<number\><a name="getmaxvolume-promise"></a>

Obtains the maximum volume allowed for a stream. This method uses a promise to return the query result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| volumeType       | <a href="#audiovolumetype">AudioVolumeType</a>             | Yes        | Audio stream type.                                                       |


**Return values**

| Name          | Description                                   | 
| ------------- | -------------------------------------------------------- |
| Promise<number\>       | Promise used to return the maximum volume.                                                       |

**Example**

```
audioManager.getMaxVolume(audio.AudioVolumeType.MEDIA).then((data)=>
    console.log('Promised returned to indicate that the maximum volume is obtained.');
)
```

### mute\(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback<void\>\): void<sup>7+</sup><a name="mute-asynccallback"></a>

Mutes a stream. This method uses an asynchronous callback to return the execution result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| volumeType       | <a href="#audiovolumetype">AudioVolumeType</a>             | Yes        | Audio stream type.                                                       |
| mute       | boolean              | Yes        | Mute status to set. The value **true** means to mute the stream, and **false** means the opposite.                                                       |
| callback       | AsyncCallback<void\>              | Yes        | Callback used to return the execution result.                                                       |

**Return values**

None

**Example**

```
audioManager.mute(audio.AudioVolumeType.MEDIA, true, (err) => {
    if (err) {
        console.error('Failed to mute the stream. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the stream is muted.');
})
```

### mute\(volumeType: AudioVolumeType, mute: boolean\): Promise<void\><sup>7+</sup><a name="mute-promise"></a>

Mutes a stream. This method uses a promise to return the execution result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| volumeType       | <a href="#audiovolumetype">AudioVolumeType</a>             | Yes        | Audio stream type.                                                       |
| mute       | boolean              | Yes        | Mute status to set. The value **true** means to mute the stream, and **false** means the opposite.                                                       |

**Return values**

| Name          | Description                                   | 
| ------------- | -------------------------------------------------------- |
| Promise<void\>       | Promise used to return the execution result.                                                       |

**Example**

```
audioManager.mute(audio.AudioVolumeType.MEDIA, true).then(() =>
    console.log('Promise returned to indicate that the stream is muted.');
)
```

### isMute\(volumeType: AudioVolumeType, callback: AsyncCallback<boolean\>\): void<sup>7+</sup><a name="ismute-asynccallback"></a>

Checks whether a stream is muted. This method uses an asynchronous callback to return the query result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| volumeType       | <a href="#audiovolumetype">AudioVolumeType</a>             | Yes        | Audio stream type.                                                       |
| callback       | AsyncCallback<boolean\>              | Yes        | Callback used to return the mute status of the stream. The value **true** means that the stream is muted, and **false** means the opposite.                                                       |

**Return values**

None

**Example**

```
audioManager.isMute(audio.AudioVolumeType.MEDIA, (err, value) => {
   if (err) {
	   console.error('Failed to obtain the mute status. ${err.message}');
	   return;
   }
   console.log('Callback invoked to indicate that the mute status of the stream is obtained.' + value);
})
```

### isMute\(volumeType: AudioVolumeType\): Promise<boolean\><sup>7+</sup><a name="ismute-promise"></a>

Checks whether a stream is muted. This method uses a promise to return the execution result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| volumeType       | <a href="#audiovolumetype">AudioVolumeType</a>             | Yes        | Audio stream type.                                                       |


**Return values**

| Name          | Description                                   | 
| ------------- | -------------------------------------------------------- |
| Promise<boolean\>       | Promise used to return the mute status of the stream. The value **true** means that the stream is muted, and **false** means the opposite.                                                       |

**Example**

```
audioManager.isMute(audio.AudioVolumeType.MEDIA).then((value) =>
    console.log('Promise returned to indicate that the mute status of the stream is obtained.' + value);
)
```

### isActive\(volumeType: AudioVolumeType, callback: AsyncCallback<boolean\>\): void<sup>7+</sup><a name="isactive-asynccallback"></a>

Checks whether a stream is active. This method uses an asynchronous callback to return the query result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| volumeType       | <a href="#audiovolumetype">AudioVolumeType</a>             | Yes        | Audio stream type.                                                       |
| callback       | AsyncCallback<boolean\>              | Yes        | Callback used to return the active status of the stream. The value **true** means that the stream is active, and **false** means the opposite.                                                       |

**Return values**

None

**Example**

```
audioManager.isActive(audio.AudioVolumeType.MEDIA, (err, value) => {
    if (err) {
        console.error('Failed to obtain the active status of the stream. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the active status of the stream is obtained.' + value);
})
```

### isActive\(volumeType: AudioVolumeType\): Promise<boolean\><sup>7+</sup><a name="isactive-promise"></a>

Checks whether a stream is active. This method uses a promise to return the query result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| volumeType       | <a href="#audiovolumetype">AudioVolumeType</a>             | Yes        | Audio stream type.                                                       |

**Return values**


| Name          | Description                                   | 
| ------------- | -------------------------------------------------------- |
| Promise<boolean\>       | Promise used to return the active status of the stream. The value **true** means that the stream is active, and **false** means the opposite.                                                       |

**Example**

```
audioManager.isActive(audio.AudioVolumeType.MEDIA).then((value) =>
    console.log('Promise returned to indicate that the active status of the stream is obtained.' + value);
)
```

### setRingerMode\(mode: AudioRingMode, callback: AsyncCallback<void\>\): void<sup>7+</sup><a name="setringermode-asynccallback"></a>

Sets the ringer mode. This method uses an asynchronous callback to return the execution result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| mode       | <a href="#audioringmode">AudioRingMode</a>             | Yes        | Ringer mode.                                                       |
| callback       | AsyncCallback<void\>              | Yes        | Callback used to return the execution result.                                                       |

**Return values**

None

**Example**

```
audioManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL, (err) => {
   if (err) {
       console.error('Failed to set the ringer mode.​ ${err.message}');
       return;
    }
    console.log('Callback invoked to indicate a successful setting of the ringer mode.');
})
```

### setRingerMode\(mode: AudioRingMode\): Promise<void\><sup>7+</sup><a name="setringermode-promise"></a>

Sets the ringer mode. This method uses a promise to return the execution result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| mode       | <a href="#audioringmode">AudioRingMode</a>             | Yes        | Ringer mode.                                                       |


**Return values**

| Name          | Description                                   | 
| ------------- | -------------------------------------------------------- |
| Promise<void\>       | Promise used to return the execution result.                                                       |

**Example**

```
audioManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL).then(() =>
    console.log('Promise returned to indicate a successful setting of the ringer mode.');
)
```

### getRingerMode\(callback: AsyncCallback<AudioRingMode\>\): void<sup>7+</sup><a name="getringermode-asynccallback"></a>

Obtains the ringer mode. This method uses an asynchronous callback to return the query result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| callback       | AsyncCallback&lt;<a href="#audioringmode">AudioRingMode</a>&gt;              | Yes        | Callback used to return the ringer mode.                                                       |

**Return values**

None

**Example**

```
audioManager.getRingerMode((err, value) => {
   if (err) {
	   console.error('Failed to obtain the ringer mode.​ ${err.message}');
	   return;
   }
   console.log('Callback invoked to indicate that the ringer mode is obtained.' + value);
})
```

### getRingerMode\(\): Promise<AudioRingMode\><sup>7+</sup><a name="getringermode-promise"></a>

Obtains the ringer mode. This method uses a promise to return the query result.

**Parameters**

None

**Return values**

| Name          | Description                                   | 
| ------------- | -------------------------------------------------------- |
| Promise&lt;<a href="#audioringmode">AudioRingMode</a>&gt;       | Promise used to return the ringer mode.                                                       |

**Example**

```
audioManager.getRingerMode().then((value) =>
    console.log('Promise returned to indicate that the ringer mode is obtained.' + value);
)
```

### setAudioParameter\(key: string, value: string, callback: AsyncCallback<void\>\): void<sup>7+</sup><a name="setaudioparameter-asynccallback"></a>

Sets an audio parameter. This method uses an asynchronous callback to return the execution result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| key       | string              | Yes        | Key of the audio parameter to set.                                                       |
| value       | string              | Yes        | Value of the audio parameter to set.                                                       |
| callback       | AsyncCallback<void\>              | Yes        | Callback used to return the execution result.                                                       |

**Return values**

None

**Example**

```
audioManager.setAudioParameter('PBits per sample', '8 bit', (err) => {
    if (err) {
        console.error('Failed to set the audio parameter. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate a successful setting of the audio parameter.');
})
```

### setAudioParameter\(key: string, value: string\): Promise<void\><sup>7+</sup><a name="setaudioparameter-promise"></a>

Sets an audio parameter. This method uses a promise to return the execution result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| key       | string              | Yes        | Key of the audio parameter to set.                                                       |
| value       | string              | Yes        | Value of the audio parameter to set.                                                       |

**Return values**

| Name          | Description                                   | 
| ------------- | -------------------------------------------------------- |
| Promise<void\>      | Promise used to return the execution result.                                                       |

**Example**

```
audioManager.setAudioParameter('PBits per sample', '8 bit').then(() =>
    console.log('Promise returned to indicate a successful setting of the audio parameter.');
)
```

### getAudioParameter\(key: string, callback: AsyncCallback<string\>\): void<sup>7+</sup><a name="getaudioparameter-asynccallback"></a>

Obtains the value of an audio parameter. This method uses an asynchronous callback to return the query result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| key       | string              | Yes        | Key of the audio parameter whose value is to be obtained.                                                       |
| callback       | AsyncCallback<string\>              | Yes        | Callback used to return the value of the audio parameter.                                                       |

**Return values**

None

**Example**

```
audioManager.getAudioParameter('PBits per sample', (err, value) => {
    if (err) {
        console.error('Failed to obtain the value of the audio parameter. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the value of the audio parameter is obtained.' + value);
})
```

### getAudioParameter\(key: string\): Promise<string\><sup>7+</sup><a name="getaudioparameter-promise"></a>

Obtains the value of an audio parameter. This method uses a promise to return the query result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| key       | string              | Yes        | Key of the audio parameter whose value is to be obtained.                                                       |

**Return values**

| Name          | Description                                   | 
| ------------- | -------------------------------------------------------- |
| Promise<string\>      | Promise used to return the value of the audio parameter.                                                       |

**Example**

```
audioManager.getAudioParameter('PBits per sample').then((value) =>
    console.log('Promise returned to indicate that the value of the audio parameter is obtained.' + value);
)
```

### getDevices\(deviceFlag: DeviceFlag, callback: AsyncCallback<AudioDeviceDescriptors\>\): void<a name="getdevices-asynccallback"></a>

Obtains the audio devices with a specific flag. This method uses an asynchronous callback to return the query result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| deviceFlag       | <a href="#deviceflag">DeviceFlag</a>              | Yes        | Audio device flag.                                                       |
| callback       | AsyncCallback&lt;<a href="#audiodevicedescriptors">AudioDeviceDescriptors</a>&gt;              | Yes        | Callback used to return the device list.                                                       |

**Return values**

None

**Example**

```
audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG, (err, value)=>{
   if (err) {
	   console.error('Failed to obtain the device list. ${err.message}');
	   return;
   }
   console.log('Callback invoked to indicate that the device list is obtained.');
})
```

### getDevices\(deviceFlag: DeviceFlag\): Promise<AudioDeviceDescriptors\><a name="getdevices-promise"></a>

Obtains the audio devices with a specific flag. This method uses a promise to return the query result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| deviceFlag       | <a href="#deviceflag">DeviceFlag</a>              | Yes        | Audio device flag.                                                       |

**Return values**

| Name          | Description                                   | 
| ------------- | -------------------------------------------------------- |
| Promise&lt;<a href="#audiodevicedescriptors">AudioDeviceDescriptors</a>&gt;      | Promise used to return the device list.                                                       |

**Example**

```
audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data)=>
    console.log('Promise returned to indicate that the device list is obtained.');
)
```

### setDeviceActive\(deviceType: ActiveDeviceType, active: boolean, callback: AsyncCallback<void\>\): void<sup>7+</sup><a name="setdeviceactive-asynccallback"></a>

Sets a device to the active state. This method uses an asynchronous callback to return the execution result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| deviceType       | <a href="#activedevicetype">ActiveDeviceType</a>              | Yes        | Audio device type.                                                       |
| active       | boolean              | Yes        | Active status to set. The value **true** means to set the device to the active status, and **false** means the opposite.                                                      |
| callback       | AsyncCallback<void\>              | Yes        | Callback used to return the execution result.                                                       |

**Return values**

None

**Example**

```
audioManager.setDeviceActive(audio.ActiveDeviceType.SPEAKER, true, (err)=> {
    if (err) {
        console.error('Failed to set the active status of the device. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the device is set to the active status.');
})
```

### setDeviceActive\(deviceType: ActiveDeviceType, active: boolean\): Promise<void\><sup>7+</sup><a name="setdeviceactive-promise"></a>

Sets a device to the active state. This method uses a promise to return the execution result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| deviceType       | <a href="#activedevicetype">ActiveDeviceType</a>              | Yes        | Audio device type.                                                       |
| active       | boolean              | Yes        | Active status to set. The value **true** means to set the device to the active status, and **false** means the opposite.                                                      |

**Return values**

| Name          | Description                                   | 
| ------------- | -------------------------------------------------------- |
| Promise<void\>      | Promise used to return the execution result.                                                       |

**Example**

```
audioManager.setDeviceActive(audio.ActiveDeviceType.SPEAKER, true).then(()=>
    console.log('Promise returned to indicate that the device is set to the active status.');
)
```

### isDeviceActive\(deviceType: DeviceType, callback: AsyncCallback<boolean\>\): void<sup>7+</sup><a name="isdeviceactive-asynccallback"></a>

Checks whether a device is active. This method uses an asynchronous callback to return the query result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| deviceType       | <a href="#activedevicetype">ActiveDeviceType</a>              | Yes        | Audio device type.                                                       |
| callback       | AsyncCallback<boolean\>              | Yes        | Callback used to return the active status of the device.                                                       |

**Return values**

None

**Example**

```
audioManager.isDeviceActive(audio.ActiveDeviceType.SPEAKER, (err, value) => {
    if (err) {
        console.error('Failed to obtain the active status of the device. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the active status of the device is obtained.');
})
```

### isDeviceActive\(deviceType: ActiveDeviceType\): Promise<boolean\><sup>7+</sup><a name="isdeviceactive-promise"></a>

Checks whether a device is active. This method uses a promise to return the query result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| deviceType       | <a href="#activedevicetype">ActiveDeviceType</a>              | Yes        | Audio device type.                                                       |


**Return values**

| Name          | Description                                   | 
| ------------- | -------------------------------------------------------- |
| Promise<boolean\>      | Promise used to return the active status of the device.                                                       |

**Example**

```
audioManager.isDeviceActive(audio.ActiveDeviceType.SPEAKER).then((value) =>
    console.log('Promise returned to indicate that the active status of the device is obtained.' + value);
)
```

### setMicrophoneMute\(mute: boolean, callback: AsyncCallback<void\>\): void<sup>7+</sup><a name="setmicrophonemute-asynccallback"></a>

Mutes or unmutes the microphone. This method uses an asynchronous callback to return the execution result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| mute       | boolean              | Yes        | Mute status to set. The value **true** means to mute the microphone, and **false** means the opposite.                                                       |
| callback       | AsyncCallback<void\>              | Yes        | Callback used to return the execution result.                                                       |

**Return values**

None

**Example**

```
audioManager.setMicrophoneMute(true, (err) => {
    if (err) {
        console.error('Failed to mute the microphone. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the microphone is muted.');
})
```

### setMicrophoneMute\(mute: boolean\): Promise<void\><sup>7+</sup><a name="setmicrophonemute-promise"></a>

Mutes or unmutes the microphone. This method uses a promise to return the execution result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| mute       | boolean              | Yes        | Mute status to set. The value **true** means to mute the microphone, and **false** means the opposite.                                                       |

**Return values**

| Name          | Description                                   | 
| ------------- | -------------------------------------------------------- |
| Promise<void\>      | Promise used to return the execution result.                                                       |

**Example**

```
audioManager.setMicrophoneMute(true).then(() =>
    console.log('Promise returned to indicate that the microphone is muted.');
)
```

### isMicrophoneMute\(callback: AsyncCallback<boolean\>\): void<sup>7+</sup><a name="ismicrophonemute-asynccallback"></a>

Checks whether the microphone is muted. This method uses an asynchronous callback to return the query result.

**Parameters**

| Name          | Type | Mandatory            | Description                                   | 
| ------------- | ------------- | ---------------|------------------------------------------------------ |
| callback       | AsyncCallback<boolean\>              | Yes        | Callback used to return the mute status of the microphone. The value **true** means that the microphone is muted, and **false** means the opposite.                                                       |

**Return values**

None

**Example**

```
audioManager.isMicrophoneMute((err, value) => {
    if (err) {
        console.error('Failed to obtain the mute status of the microphone. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the mute status of the microphone is obtained.' + value);
})
```

### isMicrophoneMute\(\): Promise<boolean\><sup>7+</sup><a name="ismicrophonemute-promise"></a>

Checks whether the microphone is muted. This method uses a promise to return the query result.

**Parameters**

None

**Return values**

| Name          | Description                                   | 
| ------------- | -------------------------------------------------------- |
| Promise<boolean\>      | Promise used to return the mute status of the microphone. The value **true** means that the microphone is muted, and **false** means the opposite.                                                       |

**Example**

```
audioManager.isMicrophoneMute().then((value) =>
    console.log('Promise returned to indicate that the mute status of the microphone is obtained.', + value);
)
```

## AudioDeviceDescriptor<a name="audiodevicedescriptor"></a>

Describes an audio device.

### Attributes<a name="attributes"></a>

| Name          | Type | Readable            | Writable                                   | Description                                   |
| ------------- | ------------- | ---------------|--------------------------------|------------------------ |
| deviceRole       | <a href="#devicerole">DeviceRole</a>              | Yes        | No                                                   | Audio device role.  | 
| deviceType       | <a href="#devicetype">DeviceType</a>              | Yes        | No                                                   | Audio device type.  | 

## AudioDeviceDescriptors<a name="audiodevicedescriptors"></a>

| Name          | Description                                   | 
| ------------- | -------------------------------------------------------- |
| Device attribute array      | Array of **AudioDeviceDescriptors**, which is read-only.                                                       |


