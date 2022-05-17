# 热管理

该模块提供热管理相关的接口，包括热档位查询及注册回调等功能。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import thermal from '@ohos.thermal';
```


## ThermalLevel

热档位信息。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.PowerManager.ThermalManager

| 名称         | 默认值  | 描述                                       |
| ---------- | ---- | ---------------------------------------- |
| COOL       | 0    | 表明设备处于低温的状态，业务执行不受热控的限制。 |
| NORMAL     | 1    | 表明设备处于正常工作状态，但温度不低，需要注意是否临近发热状态 |
| WARM       | 2    | 表明设备已经进入温热状态，部分无感知业务需要考虑停止或延迟执行。 |
| HOT        | 3    | 表明设备已经明显发热，无感知业务应全面停止，其他业务应考虑降规格及负载。 |
| OVERHEATED | 4    | 表明设备已经发热严重，无感知业务应全面停止，主要业务需降低规格及负载。 |
| WARNING    | 5    | 表明设备已经发热严重并且即将进入紧急状态，无感知业务应全面停止，主要业务应降低至最低规格。 |
| EMERGENCY  | 6    | 表明设备已经进入紧急状态，所有业务应当全面停止工作，可保留部分紧急求助功能。 |


## thermal.subscribeThermalLevel

subscribeThermalLevel(callback: AsyncCallback&lt;ThermalLevel&gt;): void

订阅热档位变化时的回调提醒。

**系统能力：** SystemCapability.PowerManager.ThermalManager

**参数：**

| 参数名      | 类型                                | 必填   | 说明                                       |
| -------- | --------------------------------- | ---- | ---------------------------------------- |
| callback | AsyncCallback&lt;ThermalLevel&gt; | 是    | 指定的callback回调方法，用于获取返回值。<br/>callback返回值：热档位信息。 |

**示例：**

```js
var lev = 0;
thermal.subscribeThermalLevel((lev) => {
    console.info("Thermal level is: " + lev);
})
```

## thermal.unsubscribeThermalLevel

unsubscribeThermalLevel(callback?: AsyncCallback\<void>): void

取消订阅热档位变化时的回调提醒。

**系统能力：** SystemCapability.PowerManager.ThermalManager

**参数：**

| 参数名      | 类型                        | 必填   | 说明                    |
| -------- | ------------------------- | ---- | --------------------- |
| callback | AsyncCallback&lt;void&gt; | 可选   | 指定的callback回调方法，无返回值。 |

**示例：**

```js
thermal.unsubscribeThermalLevel(() => {
    console.info("Unsubscribe completed.");
});
```

## thermal.getThermalLevel

getThermalLevel(): ThermalLevel

获取当前热档位信息。

**系统能力：** SystemCapability.PowerManager.ThermalManager

**返回值：**

| 类型           | 说明     |
| ------------ | ------ |
| ThermalLevel | 热档位信息。 |

**示例：**

```js
var lev = thermal.getThermalLevel();
console.info("Thermal level is: " + lev);
```
