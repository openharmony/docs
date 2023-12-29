# @ohos.bluetooth.a2dp (蓝牙a2dp模块)

a2dp模块提供了访问蓝牙音频接口的方法。

> **说明：**
>
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。



## 导入模块

```js
import a2dp from '@ohos.bluetooth.a2dp';
```

## a2dp.createA2dpSrcProfile<a name="createA2dpSrcProfile"></a>

createA2dpSrcProfile(): A2dpSourceProfile

创建a2dp profile实例。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| A2dpSourceProfile | 返回该profile的实例。 |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpProfile = a2dp.createA2dpSrcProfile();
    console.info('a2dp success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## A2dpSourceProfile

使用A2dpSourceProfile方法之前需要创建该类的实例进行操作，通过createA2dpSrcProfile()方法构造此实例。


### connect<a name="a2dp-connect"></a>

connect(deviceId: string): void

发起设备的A2dp服务连接请求。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.               |
|2900003 | Bluetooth switch is off.       |
|2900004 | Profile is not supported.      |
|2900099 | Operation failed.              |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.connect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### disconnect<a name="a2dp-disconnect"></a>

disconnect(deviceId: string): void

断开设备的a2dp服务连接。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.disconnect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### getPlayingState

getPlayingState(deviceId: string): PlayingState

获取设备的播放状态。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| [PlayingState](#PlayingState) | 远端设备的播放状态。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    let state = a2dpSrc.getPlayingState('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### isAbsoluteVolumeSupported<sup>11+</sup><a name="isAbsoluteVolumeSupported"></a>

isAbsoluteVolumeSupported(deviceId: string, callback: AsyncCallback&lt;boolean&gt;): void

获取设备是否支持绝对音量能力。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 通过注册回调函数获取设备是否支持绝对音量。如果成功，值在supported中返回。 |


**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.isAbsoluteVolumeSupported('XX:XX:XX:XX:XX:XX', (err, supported) => {
        console.info('device support absolute volume ' + supported);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### isAbsoluteVolumeSupported<sup>11+</sup>

isAbsoluteVolumeSupported(deviceId: string): Promise&lt;boolean&gt;

获取设备是否支持绝对音量能力。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| Promise&lt;boolean&gt; | 通过promise形式获取设备是否支持绝对音量。如果成功，值在supported中返回。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.isAbsoluteVolumeSupported('XX:XX:XX:XX:XX:XX').then((supported) => {
        console.info('device support absolute volume ' + supported);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### isAbsoluteVolumeEnabled<sup>11+</sup>

isAbsoluteVolumeEnabled(deviceId: string, callback: AsyncCallback&lt;boolean&gt;): void

获取设备绝对音量能力是否开启。需要在设备支持绝对音量的情况下（参考[isAbsoluteVolumeSupported](#isabsolutevolumesupported11)），再获取设备绝对音量能力是否开启。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 通过注册回调函数获取设备绝对音量是否开启。如果成功，值在enabled中返回。 |


**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.isAbsoluteVolumeEnabled('XX:XX:XX:XX:XX:XX', (err, enabled) => {
        console.info('device absolute volume enable ' + enabled);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### isAbsoluteVolumeEnabled<sup>11+</sup><a name="isAbsoluteVolumeEnabled"></a>

isAbsoluteVolumeEnabled(deviceId: string): Promise&lt;boolean&gt;

获取设备绝对音量能力是否开启。需要在设备支持绝对音量的情况下（参考[isAbsoluteVolumeSupported](#isabsolutevolumesupported11)），再获取设备绝对音量能力是否开启。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| Promise&lt;boolean&gt; | 通过promise形式获取设备绝对音量是否开启。如果成功，值在enabled中返回。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.isAbsoluteVolumeEnabled('XX:XX:XX:XX:XX:XX').then((enabled) => {
        console.info('device absolute volume enable ' + enabled);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### enableAbsoluteVolume<sup>11+</sup>

enableAbsoluteVolume(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

开启设备绝对音量能力。需要在设备支持绝对音量的情况下（参考[isAbsoluteVolumeSupported](#isabsolutevolumesupported11)），再开启设备绝对音量能力。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。如果成功，err为undefined，否则为错误对象。 |


**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.enableAbsoluteVolume('XX:XX:XX:XX:XX:XX', (err) => {
        if (err) {
            console.error("enableAbsoluteVolume error");
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### enableAbsoluteVolume<sup>11+</sup>

enableAbsoluteVolume(deviceId: string): Promise&lt;void&gt;

开启设备绝对音量能力。需要在设备支持绝对音量的情况下（参考[isAbsoluteVolumeSupported](#isabsolutevolumesupported11)），再开启设备绝对音量能力。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| Promise&lt;void&gt; | 以Promise的形式返回结果。如果成功，err为undefine的，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.enableAbsoluteVolume('XX:XX:XX:XX:XX:XX').then(() => {
            console.info("enableAbsoluteVolume");
        }
    );
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### disableAbsoluteVolume<sup>11+</sup>

disableAbsoluteVolume(deviceId: string, callback: AsyncCallback&lt;void&gt;): void

关闭设备绝对音量能力。需要在设备支持绝对音量的情况下（参考[isAbsoluteVolumeSupported](#isabsolutevolumesupported11)），再关闭设备绝对音量能力。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。如果成功，err为undefined，否则为错误对象。 |


**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.disableAbsoluteVolume('XX:XX:XX:XX:XX:XX', (err) => {
        if (err) {
            console.error("disableAbsoluteVolume error");
        }
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### disableAbsoluteVolume<sup>11+</sup>

disableAbsoluteVolume(deviceId: string): Promise&lt;void&gt;

关闭设备绝对音量能力。需要在设备支持绝对音量的情况下（参考[isAbsoluteVolumeSupported](#isabsolutevolumesupported11)），再关闭设备绝对音量能力。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| Promise&lt;void&gt; | 以Promise的形式返回结果。如果成功，err为undefine的，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    a2dpSrc.disableAbsoluteVolume('XX:XX:XX:XX:XX:XX').then(() => {
        console.info("disableAbsoluteVolume");
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getCurrentCodecInfo<sup>11+</sup>

getCurrentCodecInfo(deviceId: string): CodecInfo

获取当前编码器信息。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |

**返回值：**

| 类型                            | 说明         |
| ----------------------------- | ---------- |
| [CodecInfo](#CodecInfo)| 当前编码器信息。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    let codecInfo : a2dp.CodecInfo = a2dpSrc.getCurrentCodecInfo('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### setCurrentCodecInfo<sup>11+</sup>

setCurrentCodecInfo(deviceId: string, codecInfo: CodecInfo): void

获取当前编码器信息。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.ACCESS_BLUETOOTH 和 ohos.permission.MANAGE_BLUETOOTH

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

**参数：**

| 参数名    | 类型     | 必填   | 说明      |
| ------ | ------ | ---- | ------- |
| deviceId | string | 是    | 远端设备地址。 |
| codecInfo | [CodecInfo](#codecinfo) | 是    | 编码器信息。 |

**错误码**：

以下错误码的详细介绍请参见[蓝牙服务子系统错误码](../errorcodes/errorcode-bluetoothManager.md)。

| 错误码ID | 错误信息 |
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900099 | Operation failed.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
try {
    let a2dpSrc = a2dp.createA2dpSrcProfile();
    let codecInfo : a2dp.CodecInfo = {
        codecType: 0,
        codecBitsPerSample: 1,
        codecChannelMode: 2,
        codecSampleRate: 1,
    }
    a2dpSrc.setCurrentCodecInfo('XX:XX:XX:XX:XX:XX', codecInfo);
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## PlayingState<a name="PlayingState"></a>

枚举，蓝牙A2DP 播放状态。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| STATE_NOT_PLAYING | 0x0000 | 表示未播放。  |
| STATE_PLAYING     | 0x0001 | 表示正在播放。 |


## CodecInfo<sup>11+</sup><a name="CodecInfo"></a>

编码器信息。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称        | 类型                    | 可读   | 可写   | 说明                                     |
| ------------------- | ----------------------- | ---- | ---- | -------------------------------------- |
| codecType<sup>11+</sup>           | [CodecType](#codectype)      | 是    | 是    | 表示编码器类型，默认值为CODEC_TYPE_SBC。 |
| codecBitsPerSample<sup>11+</sup>  | [CodecBitsPerSample](#codecbitspersample)  | 是    | 是    | 表示每个采样点的位数，默认值为SCAN_MODE_LOW_POWER。 |
| codecChannelMode<sup>11+</sup>    | [CodecChannelMode](#codecchannelmode) | 是    | 是    | 表示编码器的声道模式，默认值为CODEC_CHANNEL_MODE_NONE。 |
| codecSampleRate<sup>11+</sup>     | [CodecSampleRate](#codecsamplerate) | 是    | 是    | 表示编码器的采样率，默认值为CODEC_BITS_PER_SAMPLE_NONE。 |


## CodecType<sup>11+</sup><a name="CodecType"></a>

枚举，蓝牙编码器类型。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| CODEC_TYPE_INVALID<sup>11+</sup> | -1 | 位置编码类型。  |
| CODEC_TYPE_SBC<sup>11+</sup>     | 0 | SBC。 |
| CODEC_TYPE_AAC<sup>11+</sup>     | 1 | AAC。 |
| CODEC_TYPE_L2HC<sup>11+</sup>    | 2 | L2HC。|


## CodecChannelMode<sup>11+</sup><a name="CodecChannelMode"></a>

枚举，蓝牙编码器的声道模式。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| CODEC_CHANNEL_MODE_NONE<sup>11+</sup>   | 0 | 未知声道。|
| CODEC_CHANNEL_MODE_MONO<sup>11+</sup>   | 1 | 单声道。  |
| CODEC_CHANNEL_MODE_STEREO<sup>11+</sup> | 2 | 双声道。  |


## CodecBitsPerSample<sup>11+</sup><a name="CodecBitsPerSample"></a>

枚举，蓝牙编码器每个采样点的位数。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| CODEC_BITS_PER_SAMPLE_NONE<sup>11+</sup> | 0 | 未知采样点的位数。|
| CODEC_BITS_PER_SAMPLE_16<sup>11+</sup>   | 1 | 16位采样点的位数。|
| CODEC_BITS_PER_SAMPLE_24<sup>11+</sup>   | 2 | 24位采样点的位数。|
| CODEC_BITS_PER_SAMPLE_32<sup>11+</sup>   | 3 | 32位采样点的位数。|


## CodecSampleRate<sup>11+</sup><a name="CodecSampleRate"></a>

枚举，蓝牙编码器的采样率。

**系统能力**：SystemCapability.Communication.Bluetooth.Core。

| 名称                | 值    | 说明      |
| ----------------- | ------ | ------- |
| CODEC_SAMPLE_RATE_NONE<sup>11+</sup>    | 0 | 未知采样率。|
| CODEC_SAMPLE_RATE_44100<sup>11+</sup>   | 1 | 44.1k采样率。|
| CODEC_SAMPLE_RATE_48000<sup>11+</sup>   | 2 | 48k采样率。|
| CODEC_SAMPLE_RATE_88200<sup>11+</sup>   | 3 | 88.2k采样率。|
| CODEC_SAMPLE_RATE_96000<sup>11+</sup>   | 4 | 96k位采样率。|
| CODEC_SAMPLE_RATE_176400<sup>11+</sup>  | 5 | 176.4k位采样率。|
| CODEC_SAMPLE_RATE_192000<sup>11+</sup>  | 6 | 192k位采样率。|