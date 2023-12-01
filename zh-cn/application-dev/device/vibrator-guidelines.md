# Vibrator开发指导


## 场景介绍

当设备需要设置不同的振动效果时，可以调用Vibrator模块，例如：设备的按键可以设置不同强度和不同时长的振动，闹钟和来电可以设置不同强度和时长的单次或周期振动。

详细的接口介绍请参考[Vibrator接口](../reference/apis/js-apis-vibrator.md)。


## 接口说明

| 模块          | 接口名                                                       | 描述                                                         |
| ------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ohos.vibrator | startVibration(effect: VibrateEffect, attribute: VibrateAttribute): Promise&lt;void&gt; | 根据指定振动效果和振动属性触发马达振动，使用Promise异步回调。 |
| ohos.vibrator | startVibration(effect: VibrateEffect, attribute: VibrateAttribute, callback: AsyncCallback&lt;void&gt;): void | 根据指定振动效果和振动属性触发马达振动，使用Callback异步回调。 |
| ohos.vibrator | stopVibration(stopMode: VibratorStopMode): Promise&lt;void&gt; | 按照指定模式停止马达的振动。                                 |
| ohos.vibrator | stopVibration(stopMode: VibratorStopMode, callback: AsyncCallback&lt;void&gt;): void | 按照指定模式停止马达的振动。                                 |
| ohos.vibrator | stopVibration(): Promise&lt;void&gt;                         | 停止所有模式的马达振动。                                     |
| ohos.vibrator | stopVibration(callback: AsyncCallback&lt;void&gt;): void     | 停止所有模式的马达振动。                                     |
| ohos.vibrator | isSupportEffect(effectId: string): Promise&lt;boolean&gt;    | 查询是否支持传入的参数effectId。返回true则表示支持，否则不支持 |
| ohos.vibrator | isSupportEffect(effectId: string, callback: AsyncCallback&lt;boolean&gt;): void | 查询是否支持传入的参数effectId。返回true则表示支持，否则不支持 |


## 振动效果说明

目前支持3类振动效果，如下所示。

### 固定时长振动

传入一个固定时长，马达按照默认强度和频率触发振动，振动效果描述请参考[VibrateTime](../reference/apis/js-apis-vibrator.md#vibratetime9)。

### 预置振动

系统中的[预置振动效果](../reference/apis/js-apis-vibrator.md#effectid)，这些效果适用于某些固定场景，比如效果"haptic.clock.timer"通常用于用户调整计时器时的振感反馈，振动效果描述请参考[VibratePreset](../reference/apis/js-apis-vibrator.md#vibratepreset9)。

### 自定义振动

自定义振动提供给用户设计自己所需振动效果的能力，用户可通过自定义振动配置文件，并遵循相应规则编排所需振动形式，使能更加开放的振感交互体验，效果描述请参考[VibrateFromFile](../reference/apis/js-apis-vibrator.md#vibratefromfile10)。

自定义振动配置文件为Json格式，在形式上如下所示：

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

Json文件共包含2个属性。
- "MetaData"属性中为文件头信息，可在如下属性中添加描述。<br>
"Version"：必填项，文件格式的版本号，向前兼容，目前支持版本1.0；<br>
"ChannelNumber"：必填项，表示马达振动的通道数，最大支持双马达通道；<br>
"Create"：可选项，可记录文件创作时间；<br>
"Description"：可选项，可指明振动效果、创建信息等附加说明。<br>
- "Channels"属性中为马达振动通道的相关信息。<br>

"Channels"是Json数组，表示各个通道的信息，包含2个属性。
- "Parameters"属性中为通道参数。<br>
"Index"：必填项，表示通道编号，0是全通道发送，1，2分别对应左右马达。<br>
- "Pattern"属性中为马达振动序列。<br>

"Pattern"是Json数组，包含振动事件序列，每个"Event"属性代表1个振动事件，支持添加2种振动类型。
- 类型1："transient"类型，瞬态短振动，干脆有力；<br>
- 类型2："continuous"类型，稳态长振动，具备长时间输出强劲有力振动的能力。<br>

"Event"表示一个振动事件，包含如下属性：<br>
- "Type"：振动事件类型，必填项，为"transient" 或"continuous"；<br>
- "StartTime"：振动的起始时间，必填项，单位ms，有效范围为[0, 1800 000];<br>
- "Duration"：振动持续时间，仅当类型为"continuous"时有效且为必填项，单位ms，有效范围为[0, 5000]；<br>
- "Parameters"：振动事件参数设置，必填项，可设置以下属性参数：<br>
"Intensity"：振动事件强度，必填，有效范围为[0, 100]；<br>
"Frequency"：振动事件频率，必填，有效范围为[0, 100]；<br>
"Curve"：振动曲线，当类型为"continuous"时有效且为可选项，为Json数组，支持设置一组调节点，调节点数量最大支持16个，最小为4个，
每个调节点需包含如下属性：<br>
  - "Time"：相对事件起始时间的偏移，最小为0，最大不能超过事件振动时长；<br>
  - "Intensity"：相对事件振动强度的增益，范围为[0, 1]，此值乘上振动事件强度为对应时间点调节后的强度；<br>
  - "Frequency"：相对事件振动频率的变化，范围为[-100, 100]，此值加上振动事件频率为对应时间点调节后的频率。<br>

其他要求：

| 参数 | 要求                 |
| -------- | ------------------------ |
| 振动事件(event)的数量 | 不得超过128个 |
| 振动配置文件长度 | 不得超过64KB |


## 开发步骤

1. 控制设备上的振动器，需要申请权限ohos.permission.VIBRATE。具体配置方式请参考[权限申请声明](../security/accesstoken-guidelines.md)。

2. 根据指定振动效果和振动属性触发马达振动。

- 情形一，按照指定持续时间触发马达振动：

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  // 触发马达振动
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

- 情形二，按照预置振动效果触发马达振动，可先查询振动效果是否被支持，再调用振动接口：

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  // 查询是否支持'haptic.clock.timer'
  vibrator.isSupportEffect('haptic.clock.timer', (err: BusinessError, state: boolean) => {
    if (err) {
      console.error(`Failed to query effect. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeed in querying effect');
    if (state) {
      try {
        // 触发马达振动
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

- 情形三，按照自定义振动配置文件触发马达振动：

```ts
import vibrator from '@ohos.vibrator';
import resourceManager from '@ohos.resourceManager';
import { BusinessError } from '@ohos.base';

const fileName: string = 'xxx.json';

// 获取文件资源描述符
let rawFd: resourceManager.RawFileDescriptor = getContext().resourceManager.getRawFdSync(fileName);

// 触发马达振动
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

// 关闭文件资源描述符
getContext().resourceManager.closeRawFdSync(fileName);
```

3. 停止马达的振动。

- 方式一，按照指定模式停止对应的马达振动，自定义振动不支持此类停止方式：

停止固定时长振动：

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  // 按照VIBRATOR_STOP_MODE_TIME模式停止振动
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

停止预置振动：

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  // 按照VIBRATOR_STOP_MODE_PRESET模式停止振动
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

- 方式二，停止所有模式的马达振动，包括自定义振动：

```ts
import vibrator from '@ohos.vibrator';
import { BusinessError } from '@ohos.base';

try {
  // 停止所有模式的马达振动
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


## 相关实例

针对振动开发，有以下相关实例可供参考：

- [振动（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/Vibrator/BasicVibration)

- [自定义振动（ArkTS）(Full SDK)（API10）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/Vibrator/CustomHaptic)
