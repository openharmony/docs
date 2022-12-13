# @ohos.thermal (热管理)

该模块提供热管理相关的接口，包括热档位查询及注册回调等功能。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import thermal from '@ohos.thermal';
```

## thermal.registerThermalLevelCallback<sup>9+</sup>

registerThermalLevelCallback(callback: Callback&lt;ThermalLevel&gt;): void

订阅热档位变化时的回调提醒。

**系统能力：** SystemCapability.PowerManager.ThermalManager

**参数：**

| 参数名   | 类型                         | 必填 | 说明                           |
| -------- | ---------------------------- | ---- | ------------------------------ |
| callback | Callback&lt;ThermalLevel&gt; | 是   | 回调函数，返回变化后的热档位。 |

**错误码：**

以下错误码的详细介绍请参见[耗电统计错误码](../errorcodes/errorcode-thermal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4800101 | 连接服务失败。 |

**示例：**

```js
try {
    thermal.registerThermalLevelCallback(level => {
        console.info('thermal level is: ' + level);
    });
    console.info('register thermal level callback success.');
} catch(err) {
    console.error('register thermal level callback failed, err: ' + err);
}
```

## thermal.unregisterThermalLevelCallback<sup>9+</sup>

unregisterThermalLevelCallback(callback?: Callback\<void>): void

取消订阅热档位变化时的回调提醒。

**系统能力：** SystemCapability.PowerManager.ThermalManager

**参数：**

| 参数名   | 类型                 | 必填 | 说明                                           |
| -------- | -------------------- | ---- | ---------------------------------------------- |
| callback | Callback&lt;void&gt; | 否   | 回调函数，无返回值。不填该参数则取消所有回调。 |

**错误码：**

以下错误码的详细介绍请参见[热管理错误码](../errorcodes/errorcode-thermal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4800101 | 连接服务失败。 |

**示例：**

```js
try {
    thermal.unregisterThermalLevelCallback(() => {
        console.info('unsubscribe thermal level success.');
    });
    console.info('unregister thermal level callback success.');
} catch(err) {
    console.error('unregister thermal level callback failed, err: ' + err);
}
```

## thermal.getLevel<sup>9+</sup>

getLevel(): ThermalLevel

获取当前热档位信息。

**系统能力：** SystemCapability.PowerManager.ThermalManager

**返回值：**

| 类型         | 说明         |
| ------------ | ------------ |
| ThermalLevel | 热档位信息。 |

**错误码：**

以下错误码的详细介绍请参见[热管理错误码](../errorcodes/errorcode-thermal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4800101 | 连接服务失败。 |

**示例：**

```js
try {
    var level = thermal.getLevel();
    console.info('thermal level is: ' + level);
} catch(err) {
    console.error('get thermal level failed, err: ' + err);
}
```

## thermal.subscribeThermalLevel<sup>(deprecated)</sup>

subscribeThermalLevel(callback: AsyncCallback&lt;ThermalLevel&gt;): void

> 从API version 9开始不再维护，建议使用[thermal.registerThermalLevelCallback](#thermalregisterthermallevelcallback9)替代。

订阅热档位变化时的回调提醒。

**系统能力：** SystemCapability.PowerManager.ThermalManager

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                                         |
| -------- | --------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;ThermalLevel&gt; | 是   | 回调函数。AsyncCallback只返回一个参数，为热档位信息，此时可能会产生告警，可通过`// @ts-ignore`进行抑制。 |

**示例：**

```js
thermal.subscribeThermalLevel((level) => {
    console.info('thermal level is: ' + level);
});
```

## thermal.unsubscribeThermalLevel<sup>(deprecated)</sup>

unsubscribeThermalLevel(callback?: AsyncCallback\<void>): void

> 从API version 9开始不再维护，建议使用[thermal.unregisterThermalLevelCallback](#thermalunregisterthermallevelcallback9)替代。

取消订阅热档位变化时的回调提醒。

**系统能力：** SystemCapability.PowerManager.ThermalManager

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                           |
| -------- | ------------------------- | ---- | ---------------------------------------------- |
| callback | AsyncCallback&lt;void&gt; | 否   | 回调函数，无返回值。不填该参数则取消所有回调。 |

**示例：**

```js
thermal.unsubscribeThermalLevel(() => {
    console.info('unsubscribe thermal level success.');
});
```

## thermal.getThermalLevel<sup>(deprecated)</sup>

getThermalLevel(): ThermalLevel

> 从API version 9开始不再维护，建议使用[thermal.getLevel](#thermalgetlevel9)替代。

获取当前热档位信息。

**系统能力：** SystemCapability.PowerManager.ThermalManager

**返回值：**

| 类型           | 说明     |
| ------------ | ------ |
| ThermalLevel | 热档位信息。 |

**示例：**

```js
var level = thermal.getThermalLevel();
console.info('thermal level is: ' + level);
```

## ThermalLevel

热档位信息。

**系统能力：** SystemCapability.PowerManager.ThermalManager

| 名称       | 值   | 说明                                                         |
| ---------- | ---- | ------------------------------------------------------------ |
| COOL       | 0    | 表明设备处于低温的状态，业务执行不受热控的限制。             |
| NORMAL     | 1    | 表明设备处于正常工作状态，但温度不低，需要注意是否临近发热状态 |
| WARM       | 2    | 表明设备已经进入温热状态，部分无感知业务需要考虑停止或延迟执行。 |
| HOT        | 3    | 表明设备已经明显发热，无感知业务应全面停止，其他业务应考虑降规格及负载。 |
| OVERHEATED | 4    | 表明设备已经发热严重，无感知业务应全面停止，主要业务需降低规格及负载。 |
| WARNING    | 5    | 表明设备已经发热严重并且即将进入紧急状态，无感知业务应全面停止，主要业务应降低至最低规格。 |
| EMERGENCY  | 6    | 表明设备已经进入紧急状态，所有业务应当全面停止工作，可保留部分紧急求助功能。 |
