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


## 自定义振动格式

自定义振动提供给用户设计自己所需振动效果的能力，用户可通过自定义振动配置文件，并遵循相应规则编排所需振动形式，使能更加开放的振感交互体验。

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
                "Index": 1
            },
            "Pattern": [
                {
                    "Event": {
                        "Type": "transient",
                        "StartTime": 0,
                        "Parameters": {
                            "Intensity": 100,
                            "Frequency": 31
                        }
                    }
                },
                {
                    "Event": {
                        "Type": "continuous",
                        "StartTime": 100,
                        "Duration": 54,
                        "Parameters": {
                            "Intensity": 38,
                            "Frequency": 30
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
"Version"：必填项，文件格式的版本号，向前兼容，目前起步仅支持版本1.0；<br>
"ChannelNumber"：必填项，表示马达振动的通道数，目前仅支持单通道，规定为1；<br>
"Create"：可选项，可记录文件创作时间；<br>
"Description"：可选项，可指明振动效果、创建信息等附加说明。<br>
- "Channels"属性中为马达振动通道的相关信息。<br>

"Channels"是Json数组，表示各个通道的信息，包含2个属性。
- "Parameters"属性中为通道参数。<br>
"Index"：必填项，表示通道编号，单通道下规定为1。<br>
- "Pattern"属性中为马达振动序列。<br>

"Pattern"是Json数组，每个"Event"属性代表1个振动事件，支持添加2种振动类型。
- 类型1："transient"类型，瞬态短振动，干脆有力；<br>
- 类型2："continuous"类型，稳态长振动，具备长时间输出强劲有力振动的能力。<br>

振动事件参数信息具体如下表：

| 参数 | 说明 | 范围|
| --- | ------------------------ | ---|
| Type | 振动事件类型，必填 | "transient" 或"continuous"|
| StartTime | 振动的起始时间，必填 | 单位ms，有效范围为[0, 1800 000]，振动事件不能重叠|
| Duration | 振动持续时间，仅当类型为"continuous"时有效 | 单位ms，有效范围为(10, 1600)|
| Intensity | 振动强度，必填 | 有效范围为[0, 100]，这里的强度值为相对值，并不代表真实强度|
| Frequency | 振动频率，必填 | 有效范围为[0, 100]，这里的频率值为相对值，并不代表真实频率|

其他要求：

| 参数 | 要求                 |
| -------- | ------------------------ |
| 振动事件(event)的数量 | 不得超过128个 |
| 振动配置文件长度 | 不得超过64KB |


## 开发步骤

1. 控制设备上的振动器，需要申请权限ohos.permission.VIBRATE。具体配置方式请参考[权限申请声明](../security/accesstoken-guidelines.md)。

2. 根据指定振动效果和振动属性触发马达振动。

```ts
import vibrator from '@ohos.vibrator';

try {
  vibrator.startVibration({ // 使用startVibration需要添加ohos.permission.VIBRATE权限
    type: 'time',
    duration: 1000,
  }, {
    id: 0,
    usage: 'alarm'
  }, (error) => {
    if (error) {
      console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info('Succeed in starting vibration.');
  });
} catch (err) {
  console.error(`An unexpected error occurred. Code: ${err.code}, message: ${err.message}`);
}
```

3. 按照指定模式停止马达的振动。 

```ts
import vibrator from '@ohos.vibrator';

try {
  // 按照VIBRATOR_STOP_MODE_TIME模式停止振动， 使用stopVibration需要添加ohos.permission.VIBRATE权限
  vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_TIME, function (error) {
    if (error) {
      console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info('Succeeded in stopping vibration.');
  })
} catch (err) {
  console.error(`An unexpected error occurred. Code: ${err.code}, message: ${err.message}`);
}
```

4. 停止所有模式的马达振动。

```ts
import vibrator from '@ohos.vibrator';
// 使用startVibration、stopVibration需要添加ohos.permission.VIBRATE权限
try {
  vibrator.startVibration({
    type: 'time',
    duration: 1000,
  }, {
    id: 0,
    usage: 'alarm'
  }, (error) => {
    if (error) {
      console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info('Succeed in starting vibration');
  });
  // 停止所有类型的马达振动
  vibrator.stopVibration(function (error) {
    if (error) {
      console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
      return;
    }
    console.info('Succeed in stopping vibration');
  })
} catch (error) {
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

5. 查询是否支持传入的参数effectId。

```ts
import vibrator from '@ohos.vibrator';

try {
  // 查询是否支持'haptic.clock.timer'
  vibrator.isSupportEffect('haptic.clock.timer', function (err, state) {
    if (err) {
      console.error(`Failed to query effect. Code: ${err.code}, message: ${err.message}`);
      return;
    }
    console.info('Succeed in querying effect');
    if (state) {
      try {
        vibrator.startVibration({ // 使用startVibration需要添加ohos.permission.VIBRATE权限
          type: 'preset',
          effectId: 'haptic.clock.timer',
          count: 1,
        }, {
          usage: 'unknown'
        }, (error) => {
          if (error) {
            console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
          } else {
            console.info('Succeed in starting vibration');
          }
        });
      } catch (error) {
        console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
      }
    }
  })
} catch (error) {
  console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
}
```

6. 启动和停止自定义振动

```ts
import vibrator from '@ohos.vibrator';

// 获取振动文件资源描述符
async function getRawfileFd(fileName) {
  let rawFd = await globalThis.getContext().resourceManager.getRawFd(fileName);
  return rawFd;
}

// 关闭振动文件资源描述符
async function closeRawfileFd(fileName) {
  await globalThis.getContext().resourceManager.closeRawFd(fileName)
}

// 播放自定义振动，使用startVibration、stopVibration需要添加ohos.permission.VIBRATE权限
async function playCustomHaptic(fileName) {
  try {
    let rawFd = await getRawfileFd(fileName);
    vibrator.startVibration({
      type: "file",
      hapticFd: { fd: rawFd.fd, offset: rawFd.offset, length: rawFd.length }
    }, {
      usage: "alarm"
    }).then(() => {
      console.info('Succeed in starting vibration');
    }, (error) => {
      console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
    });
    vibrator.stopVibration(function (error) {
      if (error) {
        console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
        return;
      }
      console.info('Succeed in stopping vibration');
    })
    await closeRawfileFd(fileName);
  } catch (error) {
    console.error(`An unexpected error occurred. Code: ${error.code}, message: ${error.message}`);
  }
}
```


## 相关实例

针对振动开发，有以下相关实例可供参考：

- [`Vibrator`：振动（ArkTS）（API9）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/Vibrator/BasicVibration)
- [`CustomHaptic`：自定义振动（ArkTS）（API10）](https://gitee.com/openharmony/applications_app_samples/tree/master/code/BasicFeature/DeviceManagement/Vibrator/CustomHaptic)
