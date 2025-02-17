# @ohos.vibrator (振动)

vibrator模块提供控制马达振动启、停的能力。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { vibrator } from '@kit.SensorServiceKit';
```

## vibrator.startVibration<sup>9+</sup>

startVibration(effect: VibrateEffect, attribute: VibrateAttribute, callback: AsyncCallback&lt;void&gt;): void

根据指定的振动效果和振动属性触发马达振动。使用callback异步回调。

**需要权限**：ohos.permission.VIBRATE

**原子化服务API**：从API Version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

| 参数名    | 类型                                   | 必填 | 说明                                                         |
| --------- | -------------------------------------- | ---- | :----------------------------------------------------------- |
| effect    | [VibrateEffect](#vibrateeffect9)       | 是   | 马达振动效果，支持四种：<br>1、[VibrateTime](#vibratetime9)：按照指定持续时间触发马达振动；<br>2、[VibratePreset](#vibratepreset9)：按照预置振动效果触发马达振动；<br>3、[VibrateFromFile](#vibratefromfile10)：按照自定义振动配置文件触发马达振动。<br/>4、[VibrateFromPattern<sup>16+</sup>](#vibratefrompattern16)：按照自定义振动效果触发马达振动。 |
| attribute | [VibrateAttribute](#vibrateattribute9) | 是   | 马达振动属性。                                               |
| callback  | AsyncCallback&lt;void&gt;              | 是   | 回调函数，当马达振动成功，err为undefined，否则为错误对象。   |

**错误码**：

以下错误码的详细介绍请参见[振动错误码](errorcode-vibrator.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 801      | Capability not supported.                                    |
| 14600101 | Device operation failed.                                     |

**示例**：

按照指定持续时间触发马达振动：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  vibrator.startVibration({
    type: 'time',
    duration: 1000,
  }, {
    id: 0,
    usage: 'alarm' // 根据实际选择类型归属不同的开关管控
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

按照预置振动效果触发马达振动：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  vibrator.startVibration({
    type: 'preset',
    effectId: 'haptic.clock.timer',
    count: 1,
  }, {
    id: 0,
    usage: 'alarm' // 根据实际选择类型归属不同的开关管控
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

按照自定义振动配置文件触发马达振动：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { resourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';

const fileName: string = 'xxx.json';

let rawFd: resourceManager.RawFileDescriptor = getContext().resourceManager.getRawFdSync(fileName);

try {
  vibrator.startVibration({
    type: "file",
    hapticFd: { fd: rawFd.fd, offset: rawFd.offset, length: rawFd.length }
  }, {
    id: 0,
    usage: 'alarm' // 根据实际选择类型归属不同的开关管控
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

getContext().resourceManager.closeRawFdSync(fileName);
```

## vibrator.startVibration<sup>9+</sup>

startVibration(effect: VibrateEffect, attribute: VibrateAttribute): Promise&lt;void&gt;

根据指定的振动效果和振动属性触发马达振动。使用promise异步回调。

**需要权限**：ohos.permission.VIBRATE

**原子化服务API**：从API Version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

| 参数名    | 类型                                   | 必填 | 说明                                                         |
| --------- | -------------------------------------- | ---- | ------------------------------------------------------------ |
| effect    | [VibrateEffect](#vibrateeffect9)       | 是   | 马达振动效果，支持四种：<br>1、[VibrateTime](#vibratetime9)：按照指定持续时间触发马达振动；<br>2、[VibratePreset](#vibratepreset9)：按照预置振动效果触发马达振动；<br>3、[VibrateFromFile](#vibratefromfile10)：按照自定义振动配置文件触发马达振动。<br/>4、[VibrateFromPattern<sup>16+</sup>](#vibratefrompattern16)：按照自定义振动效果触发马达振动。 |
| attribute | [VibrateAttribute](#vibrateattribute9) | 是   | 马达振动属性。                                               |

**返回值**：

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[振动错误码](errorcode-vibrator.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 801      | Capability not supported.                                    |
| 14600101 | Device operation failed.                                     |

**示例**：

按照指定持续时间触发马达振动：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  vibrator.startVibration({
    type: 'time',
    duration: 1000
  }, {
    id: 0,
    usage: 'alarm' // 根据实际选择类型归属不同的开关管控
  }).then(() => {
    console.info('Succeed in starting vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

按照预置振动效果触发马达振动：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  vibrator.startVibration({
    type: 'preset',
    effectId: 'haptic.clock.timer',
    count: 1,
  }, {
    id: 0,
    usage: 'alarm' // 根据实际选择类型归属不同的开关管控
  }).then(() => {
    console.info('Succeed in starting vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

按照自定义振动配置文件触发马达振动：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { resourceManager } from '@kit.LocalizationKit';
import { BusinessError } from '@kit.BasicServicesKit';

const fileName: string = 'xxx.json';

let rawFd: resourceManager.RawFileDescriptor = getContext().resourceManager.getRawFdSync(fileName);

try {
  vibrator.startVibration({
    type: "file",
    hapticFd: { fd: rawFd.fd, offset: rawFd.offset, length: rawFd.length }
  }, {
    id: 0,
    usage: 'alarm' // 根据实际选择类型归属不同的开关管控
  }).then(() => {
    console.info('Succeed in starting vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}

getContext().resourceManager.closeRawFdSync(fileName);
```

## vibrator.stopVibration<sup>9+</sup>

stopVibration(stopMode: VibratorStopMode, callback: AsyncCallback&lt;void&gt;): void

按照指定模式停止马达振动。使用callback异步回调。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

| 参数名   | 类型                                  | 必填 | 说明                                                         |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| stopMode | [VibratorStopMode](#vibratorstopmode) | 是   | 指定的停止振动模式，支持两种：<br>VIBRATOR_STOP_MODE_TIME：停止固定时长振动；<br>VIBRATOR_STOP_MODE_PRESET：停止预置振动。<br>此接口无法停止自定义振动，请使用[vibrator.stopVibration<sup>10+</sup>](#vibratorstopvibration10)。                                  |
| callback | AsyncCallback&lt;void&gt;             | 是   | 回调函数，当马达停止振动成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |

**示例**：

停止固定时长振动：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 按照固定时长振动
  vibrator.startVibration({
    type: 'time',
    duration: 1000,
  }, {
    id: 0,
    usage: 'alarm' // 根据实际选择类型归属不同的开关管控
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
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 按照预置效果振动
  vibrator.startVibration({
    type: 'preset',
    effectId: 'haptic.clock.timer',
    count: 1,
  }, {
    id: 0,
    usage: 'alarm' // 根据实际选择类型归属不同的开关管控
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

## vibrator.stopVibration<sup>9+</sup>

stopVibration(stopMode: VibratorStopMode): Promise&lt;void&gt;

按照指定模式停止马达的振动。使用promise异步回调。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

| 参数名   | 类型                                  | 必填 | 说明                     |
| -------- | ------------------------------------- | ---- | ------------------------ |
| stopMode | [VibratorStopMode](#vibratorstopmode) | 是   | 指定的停止振动模式，支持两种：<br>VIBRATOR_STOP_MODE_TIME：停止固定时长振动；<br>VIBRATOR_STOP_MODE_PRESET：停止预置振动。<br>此接口无法停止自定义振动，请使用[vibrator.stopVibration<sup>10+</sup>](#vibratorstopvibration10-1)。 |

**返回值**：

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |

**示例**：

停止固定时长振动：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 按照固定时长振动
  vibrator.startVibration({
    type: 'time',
    duration: 1000,
  }, {
    id: 0,
    usage: 'alarm' // 根据实际选择类型归属不同的开关管控
  }).then(() => {
    console.info('Succeed in starting vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}

try {
  // 按照VIBRATOR_STOP_MODE_TIME模式停止振动
  vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_TIME).then(() => {
    console.info('Succeed in stopping vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

停止预置振动：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 按照预置效果振动
  vibrator.startVibration({
    type: 'preset',
    effectId: 'haptic.clock.timer',
    count: 1,
  }, {
    id: 0,
    usage: 'alarm' // 根据实际选择类型归属不同的开关管控
  }).then(() => {
    console.info('Succeed in starting vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}

try {
  // 按照VIBRATOR_STOP_MODE_PRESET模式停止振动
  vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET).then(() => {
    console.info('Succeed in stopping vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (err) {
  let e: BusinessError = err as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.stopVibration<sup>10+</sup>

stopVibration(callback: AsyncCallback&lt;void&gt;): void

停止所有模式的马达振动。使用callback异步回调。

**需要权限**：ohos.permission.VIBRATE

**原子化服务API**：从API Version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

| 参数名   | 类型                      | 必填 | 说明                                                         |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数，当马达停止振动成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |

**示例**：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

## vibrator.stopVibration<sup>10+</sup>

stopVibration(): Promise&lt;void&gt;

停止所有模式的马达振动。使用promise异步回调。

**需要权限**：ohos.permission.VIBRATE

**原子化服务API**：从API Version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Sensors.MiscDevice

**返回值**：

| 类型                | 说明          |
| ------------------- | ------------- |
| Promise&lt;void&gt; | Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息           |
| -------- | ------------------ |
| 201      | Permission denied. |

**示例**：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 停止所有模式的马达振动
  vibrator.stopVibration().then(() => {
    console.info('Succeed in stopping vibration');
  }, (error: BusinessError) => {
    console.error(`Failed to stop vibration. Code: ${error.code}, message: ${error.message}`);
  });
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.stopVibrationSync<sup>12+</sup>

stopVibrationSync(): void

停止任何形式的马达振动。

**需要权限**：ohos.permission.VIBRATE

**原子化服务API**：从API Version 12开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Sensors.MiscDevice

**错误码**：

以下错误码的详细介绍请参见[振动错误码](errorcode-vibrator.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                 |
| -------- | ------------------------ |
| 201      | Permission denied.       |
| 14600101 | Device operation failed. |

**示例**：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 停止任何形式的马达振动
    vibrator.stopVibrationSync()
    console.info('Succeed in stopping vibration');
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.isSupportEffect<sup>10+</sup>

isSupportEffect(effectId: string, callback: AsyncCallback&lt;boolean&gt;): void

查询是否支持传入参数effectId。使用callback异步回调。

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

| 参数名   | 类型                         | 必填 | 说明                                                   |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| effectId | string                       | 是   | 预置的振动效果。                                           |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 回调函数，当返回true则表示支持该effectId，否则不支持。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |

**示例**：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

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
        // 使用startVibration需要添加ohos.permission.VIBRATE权限
        vibrator.startVibration({
          type: 'preset',
          effectId: 'haptic.clock.timer',
          count: 1,
        }, {
          usage: 'unknown' // 根据实际选择类型归属不同的开关管控
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

## vibrator.isSupportEffect<sup>10+</sup>

isSupportEffect(effectId: string): Promise&lt;boolean&gt;

查询是否支持传入参数effectId。使用promise异步回调。

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

| 参数名   | 类型   | 必填 | 说明         |
| -------- | ------ | ---- | ------------ |
| effectId | string | 是   | 预置的振动效果。 |

**返回值**： 

| 类型                   | 说明                                                      |
| ---------------------- | --------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise对象。当返回true则表示支持该effectId，否则不支持。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 201      | Permission denied.                                           |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |

**示例**：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
  // 查询是否支持'haptic.clock.timer'
  vibrator.isSupportEffect('haptic.clock.timer').then((state: boolean) => {
    console.info(`The query result is ${state}`);
    if (state) {
      try {
        vibrator.startVibration({
          type: 'preset',
          effectId: 'haptic.clock.timer',
          count: 1,
        }, {
          usage: 'unknown' // 根据实际选择类型归属不同的开关管控
        }).then(() => {
          console.info('Succeed in starting vibration');
        }).catch((error: BusinessError) => {
          console.error(`Failed to start vibration. Code: ${error.code}, message: ${error.message}`);
        });
      } catch (error) {
        let e: BusinessError = error as BusinessError;
        console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
      }
    }
  }, (error: BusinessError) => {
    console.error(`Failed to query effect. Code: ${error.code}, message: ${error.message}`);
  })
} catch (error) {
  let e: BusinessError = error as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.isSupportEffectSync<sup>12+</sup>

isSupportEffectSync(effectId: string): boolean

查询是否支持预设的振动效果。

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

| 参数名   | 类型   | 必填 | 说明                 |
| -------- | ------ | ---- | -------------------- |
| effectId | string | 是   | 是否预设的振动效果。 |

**返回值**：

| 类型    | 说明                                                   |
| ------- | ------------------------------------------------------ |
| boolean | 返回对象。当返回true则表示支持该effectId，否则不支持。 |

**错误码**：

以下错误码的详细介绍请参见[振动错误码](errorcode-vibrator.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error.Possible causes:1. Mandatory parameters are left unspecified;2. Incorrect parameter types;3. Parameter verification failed. |
| 14600101 | Device operation failed.                                     |

**示例**：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    // 查询是否支持预设'haptic.clock.timer'
    let ret = vibrator.isSupportEffectSync('haptic.clock.timer');
    console.info(`The query result is ${ret}`);
} catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.isHdHapticSupported<sup>12+</sup>

isHdHapticSupported(): boolean

查询是否支持高清振动。

**系统能力**：SystemCapability.Sensors.MiscDevice

**返回值**：

| 类型    | 说明       |
| ------- | ---------- |
| boolean | 返回对象。 |

**错误码**：

以下错误码的详细介绍请参见[振动错误码](errorcode-vibrator.md)。

| 错误码ID | 错误信息                 |
| -------- | ------------------------ |
| 14600101 | Device operation failed. |

**示例**：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

try {
    // 查询是否支持高清振动
    let ret = vibrator.isHdHapticSupported();
    console.info(`The query result is ${ret}`);
} catch (error) {
    let e: BusinessError = error as BusinessError;
    console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.VibratorPatternBuilder<sup>16+</sup>

addContinuousEvent(time: number, duration: number, options?: ContinuousParam): VibratorPatternBuilder;

添加长振事件的方法成VibratorPattern对象。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

| 参数名   | 类型                                  | 必填 | 说明                     |
| -------- | ------------------------------------- | ---- | ------------------------ |
| time     | number                                | 是   | 长期振动的起始时间。     |
| duration | number                                | 是   | 长期振动的持续时间。     |
| options  | [ContinuousParam](#continuousparam16) | 否   | 可选参数，可选参数对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例**：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let builder = new vibrator.VibratorPatternBuilder();
try {
  let pointsMe: vibrator.VibratorCurvePoint[] = [
	{ time: 0, intensity: 0, frequency: -7 },
	{ time: 42, intensity: 1, frequency: -6 },
	{ time: 128, intensity: 0.94, frequency: -4 },
	{ time: 217, intensity: 0.63, frequency: -14 },
	{ time: 763, intensity: 0.48, frequency: -14 },
	{ time: 1125, intensity: 0.53, frequency: -10 },
	{ time: 1503, intensity: 0.42, frequency: -14 },
	{ time: 1858, intensity: 0.39, frequency: -14 },
	{ time: 2295, intensity: 0.34, frequency: -17 },
	{ time: 2448, intensity: 0.21, frequency: -14 },
	{ time: 2468, intensity: 0, frequency: -21 }
  ] // VibratorCurvePoint参数最少设置4个，最大设置16个
  let param: vibrator.ContinuousParam = {
	intensity: 97,
	frequency: 34,
	points:pointsMe,
	index: 0
  }
  builder.addContinuousEvent(0, 2468, param);
  console.info(`addContinuousEvent builder is ${builder.build()}`);
} catch(error) {
  let e: BusinessError = error as BusinessError;
  console.error(`Exception. Code ${e.code}`);
}
```

## vibrator.addTransientEvent<sup>16+</sup>

addTransientEvent(time: number, options?: TransientParam): VibratorPatternBuilder;

添加短振事件的方法成VibratorPattern对象。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

| 参数名  | 类型                                | 必填 | 说明                     |
| ------- | ----------------------------------- | ---- | ------------------------ |
| time    | number                              | 是   | 长期振动的起始时间。     |
| options | [TransientParam](#transientparam16) | 否   | 可选参数，可选参数对象。 |

**错误码**：

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息         |
| -------- | ---------------- |
| 401      | Parameter error. |

**示例**：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let builder = new vibrator.VibratorPatternBuilder();
try {
  let param: vibrator.TransientParam = {
	intensity: 80,
	frequency: 70,
	index: 0
  }
  builder.addTransientEvent(0, param);
  console.log(`addTransientEvent builder is ${builder.build()}`);
} catch(error) {
  let e: BusinessError = error as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## vibrator.build<sup>16+</sup>

build(): VibratorPattern;

构造组合短事件或长事件的振动序列的方法。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**返回值**：

| 类型                                  | 说明                               |
| ------------------------------------- | ---------------------------------- |
| [VibratorPattern](#vibratorpattern16) | 构造组合短振或长振的振动序列方法。 |

**示例**：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

let builder = new vibrator.VibratorPatternBuilder();
try {
  let param: vibrator.TransientParam = {
	intensity: 80,
	frequency: 70,
	index: 0
  }
  builder.addTransientEvent(0, param);
  console.log(`addTransientEvent builder is ${builder.build()}`);
} catch(error) {
  let e: BusinessError = error as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
try {
  vibrator.startVibration({
	type: "pattern",
	pattern: builder.build()
  }, {
	usage: "alarm", // 根据实际选择类型归属不同的开关管控
  }, (error) => {
	if (error) {
	  let e: BusinessError = error as BusinessError;
	  console.error(`Vibrate fail. Code: ${e.code}, message: ${e.message}`);
	} else {
	  console.info(`vibrate success`);
	}
  });
} catch(error) {
  let e: BusinessError = error as BusinessError;
  console.error(`An unexpected error occurred. Code: ${e.code}, message: ${e.message}`);
}
```

## EffectId

预置的振动效果。

**系统能力**：SystemCapability.Sensors.MiscDevice

| 名称               | 值                   | 说明                             |
| ------------------ | -------------------- | -------------------------------- |
| EFFECT_CLOCK_TIMER | 'haptic.clock.timer' | 描述用户调整计时器时的振动效果。|

## HapticFeedback<sup>12+</sup>

简单而通用的振动效果。

**系统能力**：SystemCapability.Sensors.MiscDevice

| 名称                                | 值                      | 说明                         |
| ----------------------------------- | ----------------------- | ---------------------------- |
| EFFECT_SOFT                         | 'haptic.effect.soft'    | 较松散的振动效果，频率偏低。 |
| EFFECT_HARD                         | 'haptic.effect.hard'    | 较沉重的振动效果，频率居中。 |
| EFFECT_SHARP                        | 'haptic.effect.sharp'   | 较尖锐的振动效果，频率偏高。 |
| EFFECT_NOTICE_SUCCESS<sup>16+</sup> | 'haptic.notice.success' | 描述成功通知的振动效果。     |
| EFFECT_NOTICE_FAILURE<sup>16+</sup> | 'haptic.notice.fail'    | 描述失败通知的振动效果。     |
| EFFECT_NOTICE_WARNING<sup>16+</sup> | 'haptic.notice.warning' | 描述警告通知的振动效果。     |

## VibratorStopMode

停止振动的模式。

**系统能力**：SystemCapability.Sensors.MiscDevice

| 名称                      | 值       | 说明                           |
| ------------------------- | -------- | ------------------------------ |
| VIBRATOR_STOP_MODE_TIME   | 'time'   | 停止duration模式的振动。 |
| VIBRATOR_STOP_MODE_PRESET | 'preset' | 停止预置EffectId的振动。|

## VibrateEffect<sup>9+</sup>

马达振动效果，支持以下三种。

**系统能力**：SystemCapability.Sensors.MiscDevice

| 类型                             | 说明                           |
| -------------------------------- | ------------------------------ |
| [VibrateTime](#vibratetime9) | 按照指定持续时间触发马达振动。<br/>**原子化服务API：** 从API Version 11开始，该接口支持在原子化服务中使用。 |
| [VibratePreset](#vibratepreset9) | 按照预置振动类型触发马达振动。 |
| [VibrateFromFile](#vibratefromfile10) | 按照自定义振动配置文件触发马达振动。 |
| VibrateFromPattern<sup>16+</sup> | 按照自定义振动效果触发马达振动。 |

## VibrateTime<sup>9+</sup>

固定时长振动类型。

**原子化服务API**：从API Version 11开始，该接口在支持原子化服务中使用。

**系统能力**：SystemCapability.Sensors.MiscDevice

| 名称     | 类型    | 必填 | 说明                           |
| -------- | ------ | ----- | ------------------------------ |
| type     | 'time' |  是   | 值为'time'，按照指定持续时间触发马达振动。 |
| duration | number |  是   | 马达持续振动时长, 单位ms。         |

## VibratePreset<sup>9+</sup>

预置振动类型。

**系统能力**：SystemCapability.Sensors.MiscDevice

| 名称     | 类型      | 必填 | 说明                           |
| -------- | -------- | ---- |------------------------------ |
| type     | 'preset' |  是  | 值为'preset'，按照预置振动效果触发马达振动。 |
| effectId | string   |  是  | 预置的振动效果ID。             |
| count    | number   |  否  | 可选参数，振动的重复次数，默认值为1。 |
| intensity<sup>12+</sup> | number | 否 | 可选参数，振动调节强度，范围为0到100，默认值为100。若振动效果不支持强度调节或设备不支持时，则按默认强度振动。 |

## VibrateFromFile<sup>10+</sup>

自定义振动类型，仅部分设备支持，当设备不支持此振动类型时，返回[设备不支持错误码](../errorcode-universal.md)。

**系统能力**：SystemCapability.Sensors.MiscDevice

| 名称     | 类型       | 必填 | 说明                           |
| -------- | --------  | ---- | ------------------------------ |
| type     | 'file' |  是  | 值为'file'，按照振动配置文件触发马达振动。 |
| hapticFd | [HapticFileDescriptor](#hapticfiledescriptor10)<sup>10+</sup> | 是 | 振动配置文件的描述符。|

## HapticFileDescriptor<sup>10+</sup>

自定义振动配置文件的描述符，必须确认资源文件可用，其参数可通过[文件管理API](../apis-core-file-kit/js-apis-file-fs.md#fsopen)从沙箱路径获取或者通过[资源管理API](../apis-localization-kit/js-apis-resource-manager.md#getrawfd9)从HAP资源获取。使用场景：振动序列被存储在一个文件中，需要根据偏移量和长度进行振动，振动序列存储格式，请参考[自定义振动格式](../../device/sensor/vibrator-guidelines.md#自定义振动)。

**系统能力**：SystemCapability.Sensors.MiscDevice

| 名称     | 类型      |  必填  | 说明                           |
| -------- | -------- |--------| ------------------------------|
| fd       | number   |  是    | 资源文件描述符。                |
| offset   | number   |  否    | 距文件起始位置的偏移量，单位为字节，默认为文件起始位置，不可超出文件有效范围。|
| length   | number   |  否    | 资源长度，单位为字节，默认值为从偏移位置至文件结尾的长度，不可超出文件有效范围。|

## VibratorEventType<sup>16+</sup>

振动事件类型。

**系统能力**：SystemCapability.Sensors.MiscDevice

| 名称       | 类型   | 必填 | 说明              |
| ---------- | ------ | ---- | ----------------- |
| CONTINUOUS | number | 是   | 值为0，表示长振。 |
| TRANSIENT  | number | 是   | 值为1，表示短振。 |

## VibratorCurvePoint<sup>16+</sup>

相对事件振动强度的增益。

**系统能力**：SystemCapability.Sensors.MiscDevice

| 名称      | 类型   | 必填 | 说明                                                         |
| --------- | ------ | ---- | ------------------------------------------------------------ |
| time      | number | 是   | 起始时间偏移。                                               |
| intensity | number | 否   | 可选参数，相对事件振动强度增益，取值范围为0-1，省略时默认值为1。 |
| frequency | number | 否   | 可选参数，相对事件振动频率变化，取值范围为-100-100，省略时默认值为0。 |

## VibratorEvent<sup>16+</sup>

振动事件。

**系统能力**：SystemCapability.Sensors.MiscDevice

| 名称      | 类型                            | 必填 | 说明                                                         |
| --------- | ------------------------------- | ---- | ------------------------------------------------------------ |
| eventType | VibratorEventType               | 是   | 振动事件类型。                                               |
| time      | number                          | 是   | 振动起始时间。                                               |
| duration  | number                          | 否   | 可选参数，表示振动持续时间，取值范围为0-5000，短振默认值为48，长振默认值为1000。 |
| intensity | number                          | 否   | 可选参数，表示振动强度，取值范围为0-100，省略时默认值为100。 |
| frequency | number                          | 否   | 可选参数，表示振动频率，取值范围为0-100，省略时默认值为50。  |
| index     | number                          | 否   | 可选参数，表示通道编号，省略时默认值为0。                    |
| points    | Array&lt;VibratorCurvePoint&gt; | 否   | 可选参数，表示振动调节曲线数组。                             |

## VibratorPattern<sup>16+</sup>

马达振动序列，每个events代表一个振动事件。

**系统能力**：SystemCapability.Sensors.MiscDevice

| 名称   | 类型                       | 必填 | 说明                                                 |
| ------ | -------------------------- | ---- | ---------------------------------------------------- |
| time   | time                       | 是   | 振动绝对起始时间。                                   |
| events | Array&lt;VibratorEvent&gt; | 是   | 振动事件数组，build()方法返回的VibratorPattern对象。 |

## ContinuousParam<sup>16+</sup>

连续振动参数。

**系统能力**：SystemCapability.Sensors.MiscDevice

| 名称      | 类型                 | 必填 | 说明                                                         |
| --------- | -------------------- | ---- | ------------------------------------------------------------ |
| intensity | number               | 否   | 可选参数，表示振动强度，取值范围为0-100，省略时默认值为100。 |
| frequency | number               | 否   | 可选参数，表示振动频率，取值范围为0-100，省略时默认值为50。  |
| points    | VibratorCurvePoint[] | 否   | 可选参数，表示振动调节曲线数组。                             |
| index     | number               | 否   | 可选参数，表示通道编号，省略时默认值为0。                    |

## TransientParam<sup>16+</sup>

瞬态振动参数。

**系统能力**：SystemCapability.Sensors.MiscDevice

| 名称      | 类型   | 必填 | 说明                                        |
| --------- | ------ | ---- | ------------------------------------------- |
| intensity | number | 否   | 可选参数，表示振动强度，省略时默认值为100。 |
| frequency | number | 否   | 可选参数，表示振动频率，省略时默认值为50。  |
| index     | number | 否   | 可选参数，表示通道编号，省略时默认值为0。   |

## VibrateFromPattern<sup>16+</sup>

自定义振动效果触发马达振动。

**系统能力**：SystemCapability.Sensors.MiscDevice

| 名称    | 类型            | 必填 | 说明                                                 |
| ------- | --------------- | ---- | ---------------------------------------------------- |
| type    | 'pattern'       | 是   | 值为“pattern”，根据组合模式触发电机振动。            |
| pattern | VibratorPattern | 是   | 振动事件数组，build()方法返回的VibratorPattern对象。 |

## VibrateAttribute<sup>9+</sup>

马达振动属性。

**原子化服务API**：从API Version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Sensors.MiscDevice

| 名称  | 类型 | 必填 | 说明           |
| ----- | ------ | ---- | -------------- |
| id    | number      |  否 | 振动器id， 默认值为0。    |
| usage | [Usage](#usage9) | 是 | 马达振动的使用场景。 |

## Usage<sup>9+</sup>

type Usage = 'unknown' | 'alarm' | 'ring' | 'notification' | 'communication' | 'touch' | 'media' | 'physicalFeedback' | 'simulateReality'

振动使用场景。

**原子化服务API**：从API Version 11开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Sensors.MiscDevice
<!--RP1-->

| 类型     | 说明                           |
| ---------------- | ------------------------------ |
| 'unknown'     | 没有明确使用场景，最低优先级，值固定为'unknown'字符串。 |
| 'alarm'      | 用于警报场景，值固定为'alarm'字符串。 |
| 'ring'         | 用于铃声场景，值固定为'ring'字符串。 |
| 'notification' | 用于通知场景，值固定为'notification'字符串。 |
| 'communication' | 用于通信场景，值固定为'communication'字符串。 |
| 'touch'        | 用于触摸场景，值固定为'touch'字符串。 |
| 'media'        | 用于多媒体场景，值固定为'media'字符串。 |
| 'physicalFeedback' | 用于物理反馈场景，值固定为'physicalFeedback'字符串。 |
| 'simulateReality' | 用于模拟现实场景，值固定为'simulateReality'字符串。 |
<!--RP1End-->

## vibrator.vibrate<sup>(deprecated)</sup>

vibrate(duration: number): Promise&lt;void&gt;

按照指定持续时间触发马达振动。

从API version 9 开始不再维护，建议使用 [vibrator.startVibration](#vibratorstartvibration9-1)<sup>9+</sup>代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

| 参数名   | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| duration | number | 是   | 马达振动时长, 单位ms。 |

**返回值**： 

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。 |

**示例**：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

vibrator.vibrate(1000).then(() => {
  console.info('Succeed in vibrating');
}, (error: BusinessError) => {
  console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
});
```

## vibrator.vibrate<sup>(deprecated)</sup>

vibrate(duration: number, callback?: AsyncCallback&lt;void&gt;): void

按照指定持续时间触发马达振动。

从API version 9 开始不再维护，建议使用 [vibrator.startVibration](#vibratorstartvibration9)<sup>9+</sup>代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

| 参数名   | 类型                      | 必填 | 说明                                                       |
| -------- | ------------------------- | ---- | ---------------------------------------------------------- |
| duration | number                    | 是   | 马达振动时长, 单位ms。                                     |
| callback | AsyncCallback&lt;void&gt; | 否   | 回调函数，当马达振动成功，err为undefined，否则为错误对象。 |

**示例**：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

vibrator.vibrate(1000, (error: BusinessError) => {
  if (error) {
    console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
  } else {
    console.info('Succeed in vibrating');
  }
})
```


## vibrator.vibrate<sup>(deprecated)</sup>

vibrate(effectId: EffectId): Promise&lt;void&gt;

按照预置振动效果触发马达振动。

从API version 9 开始不再维护，建议使用 [vibrator.startVibration](#vibratorstartvibration9-1)<sup>9+</sup>代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| effectId | [EffectId](#effectid) | 是   | 预置的振动效果ID。 |

**返回值**：

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。 |

**示例**：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER).then(() => {
  console.info('Succeed in vibrating');
}, (error: BusinessError) => {
  console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
});
```


## vibrator.vibrate<sup>(deprecated)</sup>

vibrate(effectId: EffectId, callback?: AsyncCallback&lt;void&gt;): void

按照指定振动效果触发马达振动。

从API version 9 开始不再维护，建议使用 [vibrator.startVibration](#vibratorstartvibration9)<sup>9+</sup>代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

| 参数名   | 类型                      | 必填 | 说明                                                       |
| -------- | ------------------------- | ---- | ---------------------------------------------------------- |
| effectId | [EffectId](#effectid)     | 是   | 预置的振动效果ID。                                         |
| callback | AsyncCallback&lt;void&gt; | 否   | 回调函数，当马达振动成功，err为undefined，否则为错误对象。 |

**示例**：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, (error: BusinessError) => {
  if (error) {
    console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
  } else {
    console.info('Succeed in vibrating');
  }
})
```

## vibrator.stop<sup>(deprecated)</sup>

stop(stopMode: VibratorStopMode): Promise&lt;void&gt;

按照指定模式停止马达的振动。

从API version 9 开始不再维护，建议使用 [vibrator.stopVibration](#vibratorstopvibration9-1)<sup>9+</sup>代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

| 参数名   | 类型                                  | 必填 | 说明                     |
| -------- | ------------------------------------- | ---- | ------------------------ |
| stopMode | [VibratorStopMode](#vibratorstopmode) | 是   | 马达停止指定的振动模式。 |

**返回值**：

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。 |

**示例**：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 按照effectId类型启动振动
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, (error: BusinessError) => {
  if (error) {
    console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
  } else {
    console.info('Succeed in vibrating');
  }
})
// 使用VIBRATOR_STOP_MODE_PRESET模式停止振动
vibrator.stop(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET).then(() => {
  console.info('Succeed in stopping');
}, (error: BusinessError) => {
  console.error(`Failed to stop. Code: ${error.code}, message: ${error.message}`);
});
```


## vibrator.stop<sup>(deprecated)</sup>

stop(stopMode: VibratorStopMode, callback?: AsyncCallback&lt;void&gt;): void

按照指定模式停止马达的振动。

从API version 9 开始不再维护，建议使用 [vibrator.stopVibration](#vibratorstopvibration9)<sup>9+</sup>代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数**：

| 参数名   | 类型                                  | 必填 | 说明                                                         |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| stopMode | [VibratorStopMode](#vibratorstopmode) | 是   | 马达停止指定的振动模式。                                     |
| callback | AsyncCallback&lt;void&gt;             | 否   | 回调函数，当马达停止振动成功，err为undefined，否则为错误对象。 |

**示例**：

```ts
import { vibrator } from '@kit.SensorServiceKit';
import { BusinessError } from '@kit.BasicServicesKit';

// 按照effectId类型启动振动
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, (error: BusinessError) => {
  if (error) {
    console.error(`Failed to vibrate. Code: ${error.code}, message: ${error.message}`);
  } else {
    console.info('Succeed in vibrating');
  }
})
// 使用VIBRATOR_STOP_MODE_PRESET模式停止振动
vibrator.stop(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET, (error: BusinessError) => {
  if (error) {
    console.error(`Failed to stop. Code: ${error.code}, message: ${error.message}`);
  } else {
    console.info('Succeed in stopping');
  }
})
```
