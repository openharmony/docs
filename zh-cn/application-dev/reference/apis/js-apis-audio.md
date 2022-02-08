# 音频管理

## 导入模块

```
import audio from '@ohos.multimedia.audio';
```


## 权限

无


## getAudioManager

getAudioManager(): AudioManager

获取音频管理器。

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| [AudioManager](#audiomanager) | 音频管理类。 |

**示例：**
```
var audioManager = audio.getAudioManager();
```


## AudioVolumeType

枚举，音频流类型。

| 名称 | 默认值 | 描述 |
| -------- | -------- | -------- |
| RINGTONE | 2 | 表示铃声。 |
| MEDIA | 3 | 表示媒体。 |


## DeviceFlag

枚举，可获取的设备种类。

| 名称 | 默认值 | 描述 |
| -------- | -------- | -------- |
| OUTPUT_DEVICES_FLAG | 1 | 表示输出设备种类。 |
| INPUT_DEVICES_FLAG | 2 | 表示输入设备种类。 |
| ALL_DEVICES_FLAG | 3 | 表示所有设备种类。 |


## DeviceRole

枚举，设备角色。

| 名称 | 默认值 | 描述 |
| -------- | -------- | -------- |
| INPUT_DEVICE | 1 | 输入设备角色。 |
| OUTPUT_DEVICE | 2 | 输出设备角色。 |


## DeviceType

枚举，设备类型。

| 名称           | 默认值 | 描述                                                    |
| -------------- | ------ | ------------------------------------------------------- |
| INVALID        | 0      | 无效设备。                                              |
| EARPIECE       | 1      | 听筒。                                                  |
| SPEAKER        | 2      | 扬声器。                                                |
| WIRED_HEADSET  | 3      | 有线耳机。                                              |
| BLUETOOTH_SCO  | 7      | 蓝牙设备SCO连接(Synchronous Connection Oriented)。      |
| BLUETOOTH_A2DP | 8      | 蓝牙设备A2DP连接(Advanced Audio Distribution Profile)。 |
| MIC            | 15     | 麦克风。                                                |

## ActiveDeviceType<sup>7+</sup>

枚举，活跃设备类型。

| 名称          | 默认值 | 描述                                               |
| ------------- | ------ | -------------------------------------------------- |
| SPEAKER       | 2      | 扬声器。                                           |
| BLUETOOTH_SCO | 7      | 蓝牙设备SCO连接(Synchronous Connection Oriented)。 |

## AudioRingMode<sup>7+</sup><a name="audioringmode"></a>

枚举，铃声模式。

| 名称 | 默认值 | 描述 |
| -------- | -------- | -------- |
| RINGER_MODE_SILENT | 0 | 静音模式 |
| RINGER_MODE_VIBRATE | 1 | 震动模式 |
| RINGER_MODE_NORMAL | 2 | 响铃模式 |


## AudioManager

管理音频音量和音频设备。

### setVolume

setVolume(volumeType: AudioVolumeType, volume: number, callback: AsyncCallback&lt;void&gt;): void

设置指定流的音量，使用callback方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是 | 音量流类型。 |
| volume | number | 是 | 音量等级，可设置范围通过getMinVolume和getMaxVolume获取。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调表示成功还是失败。 |

**示例：**

```
audioManager.setVolume(audio.AudioVolumeType.MEDIA, 10, (err)=>{
   if (err) {
	   console.error('Failed to set the volume. ${err.message}');
	   return;
   }
   console.log('Callback invoked to indicate a successful volume setting.');
})
```

### setVolume

setVolume(volumeType: AudioVolumeType, volume: number): Promise&lt;void&gt;

设置指定流的音量，使用promise方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是 | 音量流类型。 |
| volume | number | 是 | 音量等级，可设置范围通过getMinVolume和getMaxVolume获取。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise回调表示成功还是失败。 |

**示例：**

```
audioManager.setVolume(audio.AudioVolumeType.MEDIA, 10).then(()=>
    console.log('Promise returned to indicate a successful volume setting.');
)
```

### getVolume

getVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

获取指定流的音量，使用callback方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是 | 音量流类型。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调返回音量大小。 |

**示例：**

```
audioManager.getVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
   if (err) {
	   console.error('Failed to obtain the volume. ${err.message}');
	   return;
   }
   console.log('Callback invoked to indicate that the volume is obtained.');
})
```

### getVolume

getVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

获取指定流的音量，使用promise方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是 | 音量流类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | Promise回调返回音量大小。 |

**示例：**

```
audioManager.getVolume(audio.AudioVolumeType.MEDIA).then((value) =>
    console.log('Promise returned to indicate that the volume is obtained.' + value);
)
```

### getMinVolume

getMinVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

获取指定流的最小音量，使用callback方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是 | 音量流类型。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调返回最小音量。 |

**示例：**

```
audioManager.getMinVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
    if (err) {
        console.error('Failed to obtain the minimum volume. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the minimum volume is obtained.' + value);
})
```

### getMinVolume

getMinVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

获取指定流的最小音量，使用promise方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是 | 音量流类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | Promise回调返回最小音量。 |

**示例：**

```
audioManager.getMinVolume(audio.AudioVolumeType.MEDIA).then((value) =>
    console.log('Promised returned to indicate that the minimum  volume is obtained.' + value);
)
```

### getMaxVolume

getMaxVolume(volumeType: AudioVolumeType, callback: AsyncCallback&lt;number&gt;): void

获取指定流的最大音量，使用callback方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是 | 音量流类型。 |
| callback | AsyncCallback&lt;number&gt; | 是 | 回调返回最大音量大小。 |

**示例：**

```
audioManager.getMaxVolume(audio.AudioVolumeType.MEDIA, (err, value) => {
    if (err) {
        console.error('Failed to obtain the maximum volume. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the maximum volume is obtained.' + value);
})
```

### getMaxVolume

getMaxVolume(volumeType: AudioVolumeType): Promise&lt;number&gt;

获取指定流的最大音量，使用promise方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是 | 音量流类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;number&gt; | Promise回调返回最大音量大小。 |

**示例：**

```
audioManager.getMaxVolume(audio.AudioVolumeType.MEDIA).then((data)=>
    console.log('Promised returned to indicate that the maximum volume is obtained.');
)
```

### mute<sup>7+</sup>

mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback&lt;void&gt;): void

设置指定音量流静音，使用callback方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是 | 音量流类型。 |
| mute | boolean | 是 | 静音状态，true为静音，false为非静音。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调表示成功还是失败。 |

**示例：**

```
audioManager.mute(audio.AudioVolumeType.MEDIA, true, (err) => {
    if (err) {
        console.error('Failed to mute the stream. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the stream is muted.');
})
```

### mute<sup>7+</sup>

mute(volumeType: AudioVolumeType, mute: boolean): Promise&lt;void&gt;

设置指定音量流静音，使用promise方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是 | 音量流类型。 |
| mute | boolean | 是 | 静音状态，true为静音，false为非静音。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise回调表示成功还是失败。 |

**示例：**


```
audioManager.mute(audio.AudioVolumeType.MEDIA, true).then(() =>
    console.log('Promise returned to indicate that the stream is muted.');
)
```


### isMute<sup>7+</sup>

isMute(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

获取指定音量流是否被静音，使用callback方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是 | 音量流类型。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调返回流静音状态，true为静音，false为非静音。 |

**示例：**

```
audioManager.isMute(audio.AudioVolumeType.MEDIA, (err, value) => {
   if (err) {
	   console.error('Failed to obtain the mute status. ${err.message}');
	   return;
   }
   console.log('Callback invoked to indicate that the mute status of the stream is obtained.' + value);
})
```


### isMute<sup>7+</sup>

isMute(volumeType: AudioVolumeType): Promise&lt;boolean&gt;

获取指定音量流是否被静音，使用promise方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是 | 音量流类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise回调返回流静音状态，true为静音，false为非静音。 |

**示例：**

```
audioManager.isMute(audio.AudioVolumeType.MEDIA).then((value) =>
    console.log('Promise returned to indicate that the mute status of the stream is obtained.' + value);
)
```

### isActive<sup>7+</sup>

isActive(volumeType: AudioVolumeType, callback: AsyncCallback&lt;boolean&gt;): void

获取指定音量流是否为活跃状态，使用callback方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是 | 音量流类型。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调返回流的活跃状态，true为活跃，false为不活跃。 |

**示例：**

```
audioManager.isActive(audio.AudioVolumeType.MEDIA, (err, value) => {
    if (err) {
        console.error('Failed to obtain the active status of the stream. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the active status of the stream is obtained.' + value);
})
```

### isActive<sup>7+</sup>

isActive(volumeType: AudioVolumeType): Promise&lt;boolean&gt;

获取指定音量流是否为活跃状态，使用promise方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| volumeType | [AudioVolumeType](#audiovolumetype) | 是 | 音量流类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise回调返回流的活跃状态，true为活跃，false为不活跃。 |

**示例：**

```
audioManager.isActive(audio.AudioVolumeType.MEDIA).then((value) =>
    console.log('Promise returned to indicate that the active status of the stream is obtained.' + value);
)
```

### setRingerMode<sup>7+</sup>

setRingerMode(mode: AudioRingMode, callback: AsyncCallback&lt;void&gt;): void

设置铃声模式，使用callback方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mode | [AudioRingMode](#audioringmode) | 是 | 音频铃声模式。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调返回设置成功或失败。 |

**示例：**

```
audioManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL, (err) => {
   if (err) {
       console.error('Failed to set the ringer mode.​ ${err.message}');
       return;
    }
    console.log('Callback invoked to indicate a successful setting of the ringer mode.');
})
```

### setRingerMode<sup>7+</sup>

setRingerMode(mode: AudioRingMode): Promise&lt;void&gt;

设置铃声模式，使用promise方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mode | [AudioRingMode](#audioringmode) | 是 | 音频铃声模式。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。 |

**示例：**

```
audioManager.setRingerMode(audio.AudioRingMode.RINGER_MODE_NORMAL).then(() =>
    console.log('Promise returned to indicate a successful setting of the ringer mode.');
)
```


### getRingerMode<sup>7+</sup>

getRingerMode(callback: AsyncCallback&lt;AudioRingMode&gt;): void

获取铃声模式，使用callback方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[AudioRingMode](#audioringmode)&gt; | 是 | 回调返回系统的铃声模式。 |

**示例：**

```
audioManager.getRingerMode((err, value) => {
   if (err) {
	   console.error('Failed to obtain the ringer mode.​ ${err.message}');
	   return;
   }
   console.log('Callback invoked to indicate that the ringer mode is obtained.' + value);
})
```


### getRingerMode<sup>7+</sup>

getRingerMode(): Promise&lt;AudioRingMode&gt;

获取铃声模式，使用promise方式返回异步结果。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[AudioRingMode](#audioringmode)&gt; | Promise回调返回系统的铃声模式。 |

**示例：**

```
audioManager.getRingerMode().then((value) =>
    console.log('Promise returned to indicate that the ringer mode is obtained.' + value);
)
```

### setAudioParameter<sup>7+</sup>

setAudioParameter(key: string, value: string, callback: AsyncCallback&lt;void&gt;): void

音频参数设置，使用callback方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 被设置的音频参数的键。 |
| value | string | 是 | 被设置的音频参数的值。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调返回设置成功或失败。 |

**示例：**

```
audioManager.setAudioParameter('PBits per sample', '8 bit', (err) => {
    if (err) {
        console.error('Failed to set the audio parameter. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate a successful setting of the audio parameter.');
})
```

### setAudioParameter<sup>7+</sup>

setAudioParameter(key: string, value: string): Promise&lt;void&gt;

音频参数设置，使用promise方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 被设置的音频参数的键。 |
| value | string | 是 | 被设置的音频参数的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。 |

**示例：**

```
audioManager.setAudioParameter('PBits per sample', '8 bit').then(() =>
    console.log('Promise returned to indicate a successful setting of the audio parameter.');
)
```

### getAudioParameter<sup>7+</sup>

getAudioParameter(key: string, callback: AsyncCallback&lt;string&gt;): void

获取指定音频参数值，使用callback方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待获取的音频参数的键。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调返回获取的音频参数的值。 |

**示例：**

```
audioManager.getAudioParameter('PBits per sample', (err, value) => {
    if (err) {
        console.error('Failed to obtain the value of the audio parameter. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the value of the audio parameter is obtained.' + value);
})
```

### getAudioParameter<sup>7+</sup>

getAudioParameter(key: string): Promise&lt;string&gt;

获取指定音频参数值，使用promise方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待获取的音频参数的键。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | Promise回调返回获取的音频参数的值。 |

**示例：**

```
audioManager.getAudioParameter('PBits per sample').then((value) =>
    console.log('Promise returned to indicate that the value of the audio parameter is obtained.' + value);
)
```

### getDevices

getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback&lt;AudioDeviceDescriptors&gt;): void

获取音频设备列表，使用callback方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceFlag | [DeviceFlag](#deviceflag) | 是 | 设备类型的flag。 |
| callback | AsyncCallback&lt;[AudioDeviceDescriptors](#audiodevicedescriptors)&gt; | 是 | 回调，返回设备列表。 |

**示例：**
```
audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG, (err, value)=>{
   if (err) {
	   console.error('Failed to obtain the device list. ${err.message}');
	   return;
   }
   console.log('Callback invoked to indicate that the device list is obtained.');
})
```

### getDevices

(deviceFlag: DeviceFlag): Promise&lt;AudioDeviceDescriptors&gt;

获取音频设备列表，使用promise方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceFlag | [DeviceFlag](#deviceflag) | 是 | 设备类型的flag。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[AudioDeviceDescriptors](#audiodevicedescriptors)&gt; | Promise回调返回设备列表。 |

**示例：**

```
audioManager.getDevices(audio.DeviceFlag.OUTPUT_DEVICES_FLAG).then((data)=>
    console.log('Promise returned to indicate that the device list is obtained.');
)
```

### setDeviceActive<sup>7+</sup>

setDeviceActive(deviceType: DeviceType, active: boolean, callback: AsyncCallback&lt;void&gt;): void

设置设备激活状态，使用callback方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceType | [DeviceType](#devicetype) | 是 | 音频设备类型。 |
| active | boolean | 是 | 设备激活状态。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调返回设置成功或失败。 |

**示例：**

```
audioManager.setDeviceActive(audio.DeviceType.SPEAKER, true, (err)=> {
    if (err) {
        console.error('Failed to set the active status of the device. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the device is set to the active status.');
})
```

### setDeviceActive<sup>7+</sup>

setDeviceActive(deviceType: DeviceType, active: boolean): Promise&lt;void&gt;

设置设备激活状态，使用promise方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceType | [DeviceType](#devicetype) | 是 | 音频设备类型。 |
| active | boolean | 是 | 设备激活状态。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。 |

**示例：**


```
audioManager.setDeviceActive(audio.DeviceType.SPEAKER, true).then(()=>
    console.log('Promise returned to indicate that the device is set to the active status.');
)
```

### isDeviceActive<sup>7+</sup>

isDeviceActive(deviceType: DeviceType, callback: AsyncCallback&lt;boolean&gt;): void

获取指定设备的激活状态，使用callback方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceType | [DeviceType](#devicetype) | 是 | 音频设备类型。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调返回设备的激活状态。 |

**示例：**

```
audioManager.isDeviceActive(audio.DeviceType.SPEAKER, (err, value) => {
    if (err) {
        console.error('Failed to obtain the active status of the device. ${err.message}');
	return;
    }
    console.log('Callback invoked to indicate that the active status of the device is obtained.');
})
```


### isDeviceActive<sup>7+</sup>

isDeviceActive(deviceType: DeviceType): Promise&lt;boolean&gt;

获取指定设备的激活状态，使用promise方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| deviceType | [DeviceType](#devicetype) | 是 | 音频设备类型。 |

**返回值：**

| Type | Description |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise回调返回设备的激活状态。 |

**示例：**

```
audioManager.isDeviceActive(audio.DeviceType.SPEAKER).then((value) =>
    console.log('Promise returned to indicate that the active status of the device is obtained.' + value);
)
```

### setMicrophoneMute<sup>7+</sup>

setMicrophoneMute(mute: boolean, callback: AsyncCallback&lt;void&gt;): void

设置麦克风静音状态，使用callback方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mute | boolean | 是 | 待设置的静音状态，true为静音，false为非静音。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调返回设置成功或失败。 |

**示例：**

```
audioManager.setMicrophoneMute(true, (err) => {
    if (err) {
        console.error('Failed to mute the microphone. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the microphone is muted.');
})
```

### setMicrophoneMute<sup>7+</sup>

setMicrophoneMute(mute: boolean): Promise&lt;void&gt;

设置麦克风静音状态，使用promise方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mute | boolean | 是 | 待设置的静音状态，true为静音，false为非静音。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise回调返回设置成功或失败。 |

**示例：**

```
audioManager.setMicrophoneMute(true).then(() =>
    console.log('Promise returned to indicate that the microphone is muted.');
)
```

### isMicrophoneMute<sup>7+</sup>

isMicrophoneMute(callback: AsyncCallback&lt;boolean&gt;): void

获取麦克风静音状态，使用callback方式返回异步结果。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 回调返回系统麦克风静音状态，true为静音，false为非静音。 |

**示例：**

```
audioManager.isMicrophoneMute((err, value) => {
    if (err) {
        console.error('Failed to obtain the mute status of the microphone. ${err.message}');
        return;
    }
    console.log('Callback invoked to indicate that the mute status of the microphone is obtained.' + value);
})
```

### isMicrophoneMute<sup>7+</sup>

isMicrophoneMute(): Promise&lt;boolean&gt;

获取麦克风静音状态，使用promise方式返回异步结果。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | Promise回调返回系统麦克风静音状态，true为静音，false为非静音。 |

**示例：**


```
audioManager.isMicrophoneMute().then((value) =>
    console.log('Promise returned to indicate that the mute status of the microphone is obtained.', + value);
)
```


## AudioDeviceDescriptor

描述音频设备。

| 名称 | 参数型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| deviceRole | [DeviceRole](#devicerole) | 是 | 否 | 设备角色。 |
| deviceType | [DeviceType](#devicetype) | 是 | 否 | 设备类型。 |


## AudioDeviceDescriptors

| 名称 | 描述 |
| -------- | -------- |
| 设备属性数组 | AudioDeviceDescriptor的数组，只读。 |
