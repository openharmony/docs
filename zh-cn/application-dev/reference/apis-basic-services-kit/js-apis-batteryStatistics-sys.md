# @ohos.batteryStatistics (耗电统计)(系统接口)

<!--Kit: Basic Services Kit-->
<!--Subsystem: PowerManager-->
<!--Owner: @zhang-yinglie; @volcano_wang-->
<!--Designer: @wangyantian0-->
<!--Tester: @alien0208-->
<!--Adviser: @w_Machine_cc-->

该模块提供软硬件耗电统计信息的查询接口。

> **说明：**
>
> - 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> - 本模块接口为系统接口。

## 导入模块

```js
import {batteryStats} from '@kit.BasicServicesKit';
```

## batteryStats.getBatteryStats

getBatteryStats(): Promise<Array&lt;BatteryStatsInfo&gt;>

获取耗电信息列表。使用Promise异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.PowerManager.BatteryStatistics

**返回值：**

| 类型                                                  | 说明                            |
| ----------------------------------------------------- | ------------------------------- |
| Promise<Array<[BatteryStatsInfo](#batterystatsinfo)>> | Promise对象，返回耗电信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[耗电统计错误码](errorcode-batteryStatistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4600101 | Failed to connect to the service. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**示例：**

```js
batteryStats.getBatteryStats()
.then((data: batteryStats.BatteryStatsInfo[]) => {
    console.info('battery statistics info: ' + data);
})
.catch((err: Error) => {
    console.error('get battery statistics failed, err: ' + err);
});
```

## batteryStats.getBatteryStats

getBatteryStats(callback: AsyncCallback<Array&lt;BatteryStatsInfo&gt;>): void

获取耗电信息列表。使用callback异步回调。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.PowerManager.BatteryStatistics

**参数：**

| 参数名   | 类型                                                        | 必填 | 说明                                                         |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback<Array<[BatteryStatsInfo](#batterystatsinfo)>> | 是   | 回调函数。当获取耗电信息列表成功，err为undefined，data为获取到的Array<[BatteryStatsInfo](#batterystatsinfo)>>；否则为错误对象；AsyncCallback封装了一个BatteryStatsInfo类型的接口。 |

**错误码：**

以下错误码的详细介绍请参见[耗电统计错误码](errorcode-batteryStatistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4600101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**示例：**

```js
batteryStats.getBatteryStats((err: Error, data : batteryStats.BatteryStatsInfo[]) => {
    if (typeof err === 'undefined') {
        console.info('battery statistics info: ' + data);
    } else {
        console.error('get battery statistics failed, err: ' + err);
    }
});
```

## batteryStats.getAppPowerValue

getAppPowerValue(uid: number): number

获取应用的耗电量。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.PowerManager.BatteryStatistics

**参数：**

| 参数名 | 类型   | 必填 | 说明        |
| ------ | ------ | ---- | ----------- |
| uid    | number | 是   | 应用的UID。 |

**返回值：**

| 类型   | 说明                              |
| ------ | --------------------------------- |
| number | UID对应应用的耗电量，单位毫安时。 |

**错误码：**

以下错误码的详细介绍请参见[耗电统计错误码](errorcode-batteryStatistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4600101 | Failed to connect to the service. |
| 202     | Permission verification failed. A non-system application calls a system API.  |
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |

**示例：**

```js
try {
    let value = batteryStats.getAppPowerValue(10021);
    console.info('battery statistics value of app is: ' + value);
} catch(err) {
    console.error('get battery statistics value of app failed, err: ' + err);
}
```

## batteryStats.getAppPowerPercent

getAppPowerPercent(uid: number): number

获取应用的耗电百分比。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.PowerManager.BatteryStatistics

**参数：**

| 参数名 | 类型   | 必填 | 说明        |
| ------ | ------ | ---- | ----------- |
| uid    | number | 是   | 应用的UID。 |

**返回值：**

| 类型   | 说明                      |
| ------ | ------------------------- |
| number | UID对应应用的耗电百分比。 |

**错误码：**

以下错误码的详细介绍请参见[耗电统计错误码](errorcode-batteryStatistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4600101 | Failed to connect to the service. |
| 202     | Permission verification failed. A non-system application calls a system API.  |
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |

**示例：**

```js
try {
    let percent = batteryStats.getAppPowerPercent(10021);
    console.info('battery statistics percent of app is: ' + percent);
} catch(err) {
    console.error('get battery statistics percent of app failed, err: ' + err);
}
```

## batteryStats.getHardwareUnitPowerValue

getHardwareUnitPowerValue(type: ConsumptionType): number

根据耗电类型获取硬件单元的耗电量。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.PowerManager.BatteryStatistics

**参数：**

| 参数名 | 类型                                | 必填 | 说明           |
| ------ | ----------------------------------- | ---- | -------------- |
| type   | [ConsumptionType](#consumptiontype) | 是   | 电量消耗类型；该参数类型是枚举类。 |

**返回值：**

| 类型   | 说明                                       |
| ------ | ------------------------------------------ |
| number | 电量消耗类型对应硬件的耗电量，单位毫安时。 |

**错误码：**

以下错误码的详细介绍请参见[耗电统计错误码](errorcode-batteryStatistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4600101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |
| 202     | Permission verification failed. A non-system application calls a system API.  |

**示例：**

```js
try {
    let value = batteryStats.getHardwareUnitPowerValue(batteryStats.ConsumptionType.CONSUMPTION_TYPE_SCREEN);
    console.info('battery statistics value of hardware is: ' + value);
} catch(err) {
    console.error('get battery statistics percent of hardware failed, err: ' + err);
}
```

## batteryStats.getHardwareUnitPowerPercent

getHardwareUnitPowerPercent(type: ConsumptionType): number

根据耗电类型获取硬件单元的耗电百分比。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.PowerManager.BatteryStatistics

**参数：**

| 参数名 | 类型                                | 必填 | 说明           |
| ------ | ----------------------------------- | ---- | -------------- |
| type   | [ConsumptionType](#consumptiontype) | 是   | 电量消耗类型；该参数类型是枚举类。 |

**返回值：**

| 类型   | 说明                               |
| ------ | ---------------------------------- |
| number | 电量消耗类型对应硬件的耗电百分比。 |

**错误码：**

以下错误码的详细介绍请参见[耗电统计错误码](errorcode-batteryStatistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID   | 错误信息    |
|---------|---------|
| 4600101 | Failed to connect to the service. |
| 401     | Parameter error. Possible causes: 1.Parameter verification failed. |
| 202     | Permission verification failed. A non-system application calls a system API. |

**示例：**

```js
try {
    let percent = batteryStats.getHardwareUnitPowerPercent(batteryStats.ConsumptionType.CONSUMPTION_TYPE_SCREEN);
    console.info('battery statistics percent of hardware is: ' + percent);
} catch(err) {
    console.error('get battery statistics percent of hardware failed, err: ' + err);
}
```

## BatteryStatsInfo

设备的耗电信息。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.PowerManager.BatteryStatistics

### 属性

| 名称  | 类型                                | 只读 | 可选 | 说明                   |
| ----- | ----------------------------------- | ---- | ---- | ---------------------- |
| uid   | number                              | 是   | 否   | 耗电信息相关的UID。    |
| type  | [ConsumptionType](#consumptiontype) | 是   | 否   | 耗电信息相关的类型。   |
| power | number                              | 是   | 否   | 耗电的值，单位毫安时。 |

## ConsumptionType

表示电量消耗类型的枚举值。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.PowerManager.BatteryStatistics

| 名称                       | 值   | 说明                          |
| -------------------------- | ---- | ----------------------------- |
| CONSUMPTION_TYPE_INVALID   | -17  | 表示电量消耗类型未知。        |
| CONSUMPTION_TYPE_APP       | -16  | 表示应用消耗的电量类型。      |
| CONSUMPTION_TYPE_BLUETOOTH | -15  | 表示蓝牙消耗的电量类型。      |
| CONSUMPTION_TYPE_IDLE      | -14  | 表示CPU空闲时消耗的电量类型。 |
| CONSUMPTION_TYPE_PHONE     | -13  | 表示通话来电消耗的电量类型。  |
| CONSUMPTION_TYPE_RADIO     | -12  | 表示无线通讯消耗的电量类型。  |
| CONSUMPTION_TYPE_SCREEN    | -11  | 表示屏幕消耗的电量类型。      |
| CONSUMPTION_TYPE_USER      | -10  | 表示用户消耗的电量类型。      |
| CONSUMPTION_TYPE_WIFI      | -9   | 表示无线网消耗的电量类型。    |
