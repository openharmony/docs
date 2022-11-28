# 振动

vibrator模块提供控制马达振动启、停的能力。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import vibrator from '@ohos.vibrator';
```

## vibrator.startVibration<sup>9+</sup>

startVibration(effect: VibrateEffect, attribute: VibrateAttribute, callback: AsyncCallback&lt;void&gt;): void

根据指定振动效果和振动属性触发马达振动。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：**

| 参数名    | 类型                                   | 必填 | 说明                                                       |
| --------- | -------------------------------------- | ---- | :--------------------------------------------------------- |
| effect    | [VibrateEffect](#vibrateeffect9)       | 是   | 马达振动效果。                                             |
| attribute | [VibrateAttribute](#vibrateattribute9) | 是   | 马达振动属性。                                             |
| callback  | AsyncCallback&lt;void&gt;              | 是   | 回调函数，当马达振动成功，err为undefined，否则为错误对象。 |

**错误码**：

以下错误码的详细介绍请参见 [ohos.vibrator错误码](../errorcodes/errorcode-vibrator.md)

| 错误码ID | 错误信息                  |
| -------- | ------------------------- |
| 14600101 | Device operation failed。 |

示例：

```js
try {
    vibrator.startVibration({
        type: 'time',
        duration: 1000,
    }, {
        id: 0,
        usage: 'alarm'
    }, (error) => {
        if (error) {
            console.error('vibrate fail, error.code: ' + error.code + 'error.message: ', + error.message);
            return;
        }
        console.log('Callback returned to indicate a successful vibration.');
    });
} catch (err) {
    console.error('errCode: ' + err.code + ' ,msg: ' + err.message);
}
```

## vibrator.startVibration<sup>9+</sup>

startVibration(effect: VibrateEffect, attribute: VibrateAttribute): Promise&lt;void&gt;

根据指定振动效果和振动属性触发马达振动。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：** 

| 参数名    | 类型                                   | 必填 | 说明           |
| --------- | -------------------------------------- | ---- | -------------- |
| effect    | [VibrateEffect](#vibrateeffect9)       | 是   | 马达振动效果。 |
| attribute | [VibrateAttribute](#vibrateattribute9) | 是   | 马达振动属性。 |

**返回值：** 

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。 |

**错误码**：

以下错误码的详细介绍请参见 [ohos.vibrator错误码](../errorcodes/errorcode-vibrator.md)

| 错误码ID | 错误信息                  |
| -------- | ------------------------- |
| 14600101 | Device operation failed。 |

**示例：** 

  ```js
try {
    vibrator.startVibration({
        type: 'time',
        duration: 1000
    }, {
        id: 0,
        usage: 'alarm'
    }).then(() => {
        console.log('Promise returned to indicate a successful vibration');
    }, (error) => {
        console.error('error.code' + error.code + 'error.message' + error.message);
    });
} catch (err) {
    console.error('errCode: ' + err.code + ' ,msg: ' + err.message);
}
  ```

## vibrator.stopVibration<sup>9+</sup>

stopVibration(stopMode: VibratorStopMode, callback: AsyncCallback&lt;void&gt;): void

按照指定模式停止马达的振动。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：** 

| 参数名   | 类型                                  | 必填 | 说明                                                         |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| stopMode | [VibratorStopMode](#vibratorstopmode) | 是   | 指定的停止振动模式。                                     |
| callback | AsyncCallback&lt;void&gt;             | 是   | 回调函数。当马达停止振动成功，err为undefined，否则为错误对象。 |

**示例：** 

  ```js
try {
    // 按照固定时长振动
    vibrator.startVibration({
        type: 'time',
        duration: 1000,
    }, {
        id: 0,
        usage: 'alarm'
    }, (error) => {
        if (error) {
            console.error('vibrate fail, error.code: ' + error.code + 'error.message: ', + error.message);
            return;
        }
        console.log('Callback returned to indicate a successful vibration.');
    });
} catch (err) {
    console.error('errCode: ' + err.code + ' ,msg: ' + err.message);
}

try {
    // 按照VIBRATOR_STOP_MODE_TIME模式停止振动
    vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_TIME, function (error) {
        if (error) {
            console.log('error.code' + error.code + 'error.message' + error.message);
            return;
        }
        console.log('Callback returned to indicate successful.');
    })
} catch (err) {
    console.info('errCode: ' + err.code + ' ,msg: ' + err.message);
}
  ```

## vibrator.stopVibration<sup>9+</sup>

stopVibration(stopMode: VibratorStopMode): Promise&lt;void&gt;

按照指定模式停止马达的振动。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：** 

| 参数名   | 类型                                  | 必填 | 说明                     |
| -------- | ------------------------------------- | ---- | ------------------------ |
| stopMode | [VibratorStopMode](#vibratorstopmode) | 是   | 马达停止指定的振动模式。 |

**返回值：** 

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。 |

**示例：** 

  ```js
try {
    // 按照固定时长振动
    vibrator.startVibration({
        type: 'time',
        duration: 1000
    }, {
        id: 0,
        usage: 'alarm'
    }).then(() => {
        console.log('Promise returned to indicate a successful vibration');
    }, (error) => {
        console.error('error.code' + error.code + 'error.message' + error.message);
    });
} catch (err) {
    console.error('errCode: ' + err.code + ' ,msg: ' + err.message);
}

try {
    // 按照VIBRATOR_STOP_MODE_TIME模式停止振动
    vibrator.stopVibration(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET).then(() => {
        console.log('Promise returned to indicate a successful vibration.');
    }, (error) => {
        console.log('error.code' + error.code + 'error.message' + error.message);
    });
} catch (err) {
    console.info('errCode: ' + err.code + ' ,msg: ' + err.message);
}
  ```

## EffectId

预置的振动效果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.MiscDevice

| 名称               | 值                   | 说明                             |
| ------------------ | -------------------- | -------------------------------- |
| EFFECT_CLOCK_TIMER | "haptic.clock.timer" | 描述用户调整计时器时的振动效果。 |


## VibratorStopMode

停止的振动模式。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.MiscDevice

| 名称                      | 值       | 说明                           |
| ------------------------- | -------- | ------------------------------ |
| VIBRATOR_STOP_MODE_TIME   | "time"   | 停止模式为duration模式的振动。 |
| VIBRATOR_STOP_MODE_PRESET | "preset" | 停止模式为预置EffectId的振动。 |

## VibrateEffect<sup>9+</sup>

马达振动效果。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.MiscDevice

| 类型                             | 说明                           |
| -------------------------------- | ------------------------------ |
| [VibrateTime](#vibratetime9)     | 按照指定持续时间触发马达振动。 |
| [VibratePreset](#vibratepreset9) | 按照预置振动类型触发马达振动。 |

## VibrateTime<sup>9+</sup>

马达振动时长。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.MiscDevice

| 名称     | 值 | 说明                           |
| -------- | ------ | ------------------------------ |
| type     | "time" | 按照指定持续时间触发马达振动。 |
| duration | -      | 马达持续振动时长, 单位ms。         |

## VibratePreset<sup>9+</sup>

马达预置振动类型。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.MiscDevice

| 名称     | 值       | 说明                           |
| -------- | -------- | ------------------------------ |
| type     | "preset" | 按照预置振动效果触发马达振动。 |
| effectId | -        | 预置的振动效果ID。             |
| count    | -        | 重复振动的次数。               |

## VibrateAttribute<sup>9+</sup>

马达振动属性。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.MiscDevice

| 名称  | 值 | 说明           |
| ----- | ------ | -------------- |
| id    | 0      | 振动器id。     |
| usage | -      | 马达振动的使用场景。 |

## Usage<sup>9+</sup>

振动使用场景。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Sensors.MiscDevice

| 名称             | 类型   | 说明                           |
| ---------------- | ------ | ------------------------------ |
| unknown          | string | 没有明确使用场景，最低优先级。 |
| alarm            | string | 用于警报场景。           |
| ring             | string | 用于铃声场景。           |
| notification     | string | 用于通知场景。           |
| communication    | string | 用于通信场景。           |
| touch            | string | 用于触摸场景。           |
| media            | string | 用于多媒体场景。         |
| physicalFeedback | string | 用于物理反馈场景。       |
| simulateReality  | string | 用于模拟现实场景。       |

## vibrator.vibrate<sup>(deprecated)</sup>

vibrate(duration: number): Promise&lt;void&gt;

按照指定持续时间触发马达振动。

从API version 9 开始不再维护，建议使用 [vibrator.startVibration](#vibratorstartvibration9-1) 代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：** 

| 参数名   | 类型   | 必填 | 说明                   |
| -------- | ------ | ---- | ---------------------- |
| duration | number | 是   | 马达振动时长, 单位ms。 |

**返回值：** 

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。 |

**示例：** 

  ```js
vibrator.vibrate(1000).then(() => {
    console.log('Promise returned to indicate a successful vibration.');
}, (error) => {
    console.log('error.code' + error.code + 'error.message' + error.message);
});
  ```

## vibrator.vibrate<sup>(deprecated)</sup>

vibrate(duration: number, callback?: AsyncCallback&lt;void&gt;): void

按照指定持续时间触发马达振动。

从API version 9 开始不再维护，建议使用 [vibrator.startVibration](#vibratorstartvibration9) 代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：** 

| 参数名   | 类型                      | 必填 | 说明                                                       |
| -------- | ------------------------- | ---- | ---------------------------------------------------------- |
| duration | number                    | 是   | 马达振动时长, 单位ms。                                     |
| callback | AsyncCallback&lt;void&gt; | 否   | 回调函数。当马达振动成功，err为undefined，否则为错误对象。 |

**示例：** 

  ```js
vibrator.vibrate(1000, function (error) {
    if (error) {
        console.log('error.code' + error.code + 'error.message' + error.message);
    } else {
        console.log('Callback returned to indicate a successful vibration.');
    }
})
  ```


## vibrator.vibrate<sup>(deprecated)</sup>

vibrate(effectId: EffectId): Promise&lt;void&gt;

按照预置振动效果触发马达振动。

从API version 9 开始不再维护，建议使用 [vibrator.startVibration](#vibratorstartvibration9-1) 代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：** 

| 参数名   | 类型                  | 必填 | 说明               |
| -------- | --------------------- | ---- | ------------------ |
| effectId | [EffectId](#effectid) | 是   | 预置的振动效果ID。 |

**返回值：** 

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。 |

**示例：** 

  ```js
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER).then(() => {
    console.log('Promise returned to indicate a successful vibration.');
}, (error) => {
    console.log('error.code' + error.code + 'error.message' + error.message);
});
  ```


## vibrator.vibrate<sup>(deprecated)</sup>

vibrate(effectId: EffectId, callback?: AsyncCallback&lt;void&gt;): void

按照指定振动效果触发马达振动。

从API version 9 开始不再维护，建议使用 [vibrator.startVibration](#vibratorstartvibration9) 代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：** 

| 参数名   | 类型                      | 必填 | 说明                                                       |
| -------- | ------------------------- | ---- | ---------------------------------------------------------- |
| effectId | [EffectId](#effectid)     | 是   | 预置的振动效果ID。                                         |
| callback | AsyncCallback&lt;void&gt; | 否   | 回调函数。当马达振动成功，err为undefined，否则为错误对象。 |

**示例：** 

  ```js
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, function (error) {
    if (error) {
        console.log('error.code' + error.code + 'error.message' + error.message);
    } else {
        console.log('Callback returned to indicate a successful vibration.');
    }
})
  ```

## vibrator.stop<sup>(deprecated)</sup>

stop(stopMode: VibratorStopMode): Promise&lt;void&gt;

按照指定模式停止马达的振动。

从API version 9 开始不再维护，建议使用 [vibrator.stopVibration](#vibratorstopvibration9-1) 代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：** 

| 参数名   | 类型                                  | 必填 | 说明                     |
| -------- | ------------------------------------- | ---- | ------------------------ |
| stopMode | [VibratorStopMode](#vibratorstopmode) | 是   | 马达停止指定的振动模式。 |

**返回值：** 

| 类型                | 说明                                   |
| ------------------- | -------------------------------------- |
| Promise&lt;void&gt; | Promise对象。 |

**示例：** 

  ```js
// 按照effectId类型启动振动
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, function (error) {
    if (error) {
        console.log('error.code' + error.code + 'error.message' + error.message);
    } else {
        console.log('Callback returned to indicate a successful vibration.');
    }
})
// 使用VIBRATOR_STOP_MODE_PRESET模式停止振动
vibrator.stop(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET).then(() => {
    console.log('Promise returned to indicate a successful vibration.');
}, (error) => {
    console.log('error.code' + error.code + 'error.message' + error.message);
});
  ```


## vibrator.stop<sup>(deprecated)</sup>

stop(stopMode: VibratorStopMode, callback?: AsyncCallback&lt;void&gt;): void

按照指定模式停止马达的振动。

从API version 9 开始不再维护，建议使用 [vibrator.stopVibration](#vibratorstopvibration9) 代替。

**需要权限**：ohos.permission.VIBRATE

**系统能力**：SystemCapability.Sensors.MiscDevice

**参数：** 

| 参数名   | 类型                                  | 必填 | 说明                                                         |
| -------- | ------------------------------------- | ---- | ------------------------------------------------------------ |
| stopMode | [VibratorStopMode](#vibratorstopmode) | 是   | 马达停止指定的振动模式。                                     |
| callback | AsyncCallback&lt;void&gt;             | 否   | 回调函数。当马达停止振动成功，err为undefined，否则为错误对象。 |

**示例：** 

  ```js
// 按照effectId类型启动振动
vibrator.vibrate(vibrator.EffectId.EFFECT_CLOCK_TIMER, function (error) {
    if (error) {
        console.log('error.code' + error.code + 'error.message' + error.message);
    } else {
        console.log('Callback returned to indicate a successful vibration.');
    }
})
// 使用VIBRATOR_STOP_MODE_PRESET模式停止振动
vibrator.stop(vibrator.VibratorStopMode.VIBRATOR_STOP_MODE_PRESET, function (error) {
    if (error) {
        console.log('error.code' + error.code + 'error.message' + error.message);
    } else {
        console.log('Callback returned to indicate successful.');
    }
})
  ```
