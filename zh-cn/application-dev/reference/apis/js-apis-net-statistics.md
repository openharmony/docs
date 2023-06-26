# @ohos.net.statistics (流量管理)

流量管理模块，支持基于网卡/UID的实时流量统计和历史流量统计查询能力。

> **说明：**
> 本模块首批接口从API version 10开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import statistics from '@ohos.net.statistics'
```

## statistics.getIfaceRxBytes<sup>10+</sup>

getIfaceRxBytes(nic: string, callback: AsyncCallback\<number>): void;

获取指定网卡实时下行流量。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| nic | string | 是   | 指定查询的网卡名。                   |
| callback | AsyncCallback\<number>         | 是   | 回调函数。当成功获取网卡实时下行流量时，err为undefined，stats为获取到的网卡实时下行流量；否则为错误对象|

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401     | Parameter error.             |
| 2100002 | Operation failed. Cannot connect to service.             |
| 2100003 | System internal error.         |
| 2103005 | Failed to read map.             |
| 2103011 | Failed to create map.             |
| 2103012 | Get iface name failed.         |

> **错误码说明：**
> 以上错误码的详细介绍参见[statistics错误码](../errorcodes/errorcode-net-statistics)。

**示例：**

```js
  statistics.getIfaceRxBytes("wlan0", (error, data) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(stats))
  })
```

## statistics.getIfaceRxBytes<sup>10+</sup>

getIfaceRxBytes(nic: string): Promise\<number>;

获取指定网卡实时下行流量。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| nic | string | 是   | 指定查询的网卡名。                   |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以Promise形式返回获取结果。返回网卡实时下行流量 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401     | Parameter error.             |
| 2100002 | Operation failed. Cannot connect to service.             |
| 2100003 | System internal error.         |
| 2103005 | Failed to read map.             |
| 2103011 | Failed to create map.             |
| 2103012 | Get iface name failed.         |

> **错误码说明：**
> 以上错误码的详细介绍参见[statistics错误码](../errorcodes/errorcode-net-statistics)。

**示例：**

```js
  statistics.getIfaceRxBytes("wlan0").then(function (stats) {
    console.log(JSON.stringify(stats))
  })
```

## statistics.getIfaceTxBytes<sup>10+</sup>

getIfaceTxBytes(nic: string, callback: AsyncCallback\<number>): void;

获取指定网卡实时上行流量。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| nic | string | 是   | 指定查询的网卡名。                   |
| callback | AsyncCallback\<number>         | 是   | 回调函数。当成功获取网卡实时上行流量时，err为undefined，stats为获取到的网卡实时下行流量；否则为错误对象|

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401     | Parameter error.             |
| 2100002 | Operation failed. Cannot connect to service.             |
| 2100003 | System internal error.         |
| 2103005 | Failed to read map.             |
| 2103011 | Failed to create map.             |
| 2103012 | Get iface name failed.         |

> **错误码说明：**
> 以上错误码的详细介绍参见[statistics错误码](../errorcodes/errorcode-net-statistics)。

**示例：**

```js
  statistics.getIfaceTxBytes("wlan0", (error, data) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(stats))
  })
```

## statistics.getIfaceTxBytes<sup>10+</sup>

getIfaceTxBytes(nic: string): Promise\<number>;

获取指定网卡实时上行流量。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| nic | string | 是   | 指定查询的网卡名。                   |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以Promise形式返回获取结果。返回网卡实时上行流量 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401     | Parameter error.             |
| 2100002 | Operation failed. Cannot connect to service.             |
| 2100003 | System internal error.         |
| 2103005 | Failed to read map.             |
| 2103011 | Failed to create map.             |
| 2103012 | Get iface name failed.         |

> **错误码说明：**
> 以上错误码的详细介绍参见[statistics错误码](../errorcodes/errorcode-net-statistics)。

**示例：**

```js
  statistics.getIfaceTxBytes("wlan0").then(function (stats) {
    console.log(JSON.stringify(stats))
  })
```

## statistics.getCellularRxBytes<sup>10+</sup>

getCellularRxBytes(callback: AsyncCallback\<number>): void;

获取蜂窝实时下行流量。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<number>         | 是   | 回调函数。当成功获取蜂窝实时下行流量时，err为undefined，stats为获取到的蜂窝实时下行流量；否则为错误对象|

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 2100002 | Operation failed. Cannot connect to service.             |
| 2100003 | System internal error.         |
| 2103005 | Failed to read map.             |
| 2103011 | Failed to create map.             |
| 2103012 | Get iface name failed.         |

**示例：**

```js
  statistics.getCellularRxBytes((error, data) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(stats))
  })
```

## statistics.getCellularRxBytes<sup>10+</sup>

getCellularRxBytes(): Promise\<number>;

获取蜂窝实时下行流量。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以Promise形式返回获取结果。返回蜂窝实时下行流量 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 2100002 | Operation failed. Cannot connect to service.             |
| 2100003 | System internal error.         |
| 2103005 | Failed to read map.             |
| 2103011 | Failed to create map.             |
| 2103012 | Get iface name failed.         |

> **错误码说明：**
> 以上错误码的详细介绍参见[statistics错误码](../errorcodes/errorcode-net-statistics)。

**示例：**

```js
  statistics.getCellularRxBytes().then(function (stats) {
    console.log(JSON.stringify(stats))
  })
```

## statistics.getCellularTxBytes<sup>10+</sup>

getCellularTxBytes(callback: AsyncCallback\<number>): void;

获取蜂窝实时上行流量。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<number>         | 是   | 回调函数。当成功获取蜂窝实时上行流量时，err为undefined，stats为获取到的蜂窝实时上行流量；否则为错误对象|

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 2100002 | Operation failed. Cannot connect to service.             |
| 2100003 | System internal error.         |
| 2103005 | Failed to read map.             |
| 2103011 | Failed to create map.             |
| 2103012 | Get iface name failed.         |

> **错误码说明：**
> 以上错误码的详细介绍参见[statistics错误码](../errorcodes/errorcode-net-statistics)。

**示例：**

```js
  statistics.getCellularTxBytes((error, stats) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(stats))
  })
```

## statistics.getCellularTxBytes<sup>10+</sup>

getCellularTxBytes(): Promise\<number>;

获取蜂窝实时上行流量。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以Promise形式返回获取结果。返回蜂窝实时上行流量 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 2100002 | Operation failed. Cannot connect to service.             |
| 2100003 | System internal error.         |
| 2103005 | Failed to read map.             |
| 2103011 | Failed to create map.             |
| 2103012 | Get iface name failed.         |

> **错误码说明：**
> 以上错误码的详细介绍参见[statistics错误码](../errorcodes/errorcode-net-statistics)。

**示例：**

```js
  statistics.getCellularTxBytes().then(function (stats) {
    console.log(JSON.stringify(stats))
  })
```

## statistics.getAllRxBytes<sup>10+</sup>

getAllRxBytes(callback: AsyncCallback\<number>): void;

获取所有网卡实时下行流量。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<number>         | 是   | 回调函数。当成功获取所有网卡实时下行流量，err为undefined，stats为获取到的所有网卡实时下行流量；否则为错误对象|

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 2100002 | Operation failed. Cannot connect to service.             |
| 2100003 | System internal error.         |
| 2103005 | Failed to read map.             |
| 2103011 | Failed to create map.             |

> **错误码说明：**
> 以上错误码的详细介绍参见[statistics错误码](../errorcodes/errorcode-net-statistics)。

**示例：**

```js
  statistics.getAllRxBytes((error, stats) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(stats))
  })
```

## statistics.getAllRxBytes<sup>10+</sup>

getAllRxBytes(): Promise\<number>;

获取所有网卡实时下行流量。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以Promise形式返回获取结果。返回所有网卡实时下行流量。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 2100002 | Operation failed. Cannot connect to service.             |
| 2100003 | System internal error.         |
| 2103005 | Failed to read map.             |
| 2103011 | Failed to create map.             |

> **错误码说明：**
> 以上错误码的详细介绍参见[statistics错误码](../errorcodes/errorcode-net-statistics)。

**示例：**

```js
  statistics.getCellularRxBytes().then(function (stats) {
    console.log(JSON.stringify(stats))
  })
```

## statistics.getAllTxBytes<sup>10+</sup>

getAllTxBytes(callback: AsyncCallback\<number>): void;

获取所有网卡实时上行流量。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback\<number>         | 是   | 回调函数。当成功获取所有网卡实时上行流量，err为undefined，stats为获取到的所有网卡实时上行流量；否则为错误对象|

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 2100002 | Operation failed. Cannot connect to service.             |
| 2100003 | System internal error.         |
| 2103005 | Failed to read map.             |
| 2103011 | Failed to create map.             |

> **错误码说明：**
> 以上错误码的详细介绍参见[statistics错误码](../errorcodes/errorcode-net-statistics)。

**示例：**

```js
  statistics.getAllTxBytes((error, stats) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(stats))
  })
```

## statistics.getAllTxBytes<sup>10+</sup>

getAllTxBytes(): Promise\<number>;

获取所有网卡实时上行流量。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以Promise形式返回获取结果。返回所有网卡实时上行流量。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 2100002 | Operation failed. Cannot connect to service.             |
| 2100003 | System internal error.         |
| 2103005 | Failed to read map.             |
| 2103011 | Failed to create map.             |

> **错误码说明：**
> 以上错误码的详细介绍参见[statistics错误码](../errorcodes/errorcode-net-statistics)。

**示例：**

```js
  statistics.getAllTxBytes().then(function (stats) {
    console.log(JSON.stringify(stats))
  })
```

## statistics.getUidRxBytes<sup>10+</sup>

getUidRxBytes(uid: number, callback: AsyncCallback\<number>): void;

获取指定应用实时下行流量。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| uid | number | 是   | 指定查询的应用uid。                   |
| callback | AsyncCallback\<number>         | 是   | 回调函数。当成功获取应用实时下行流量时，err为undefined，stats为获取到的应用实时下行流量；否则为错误对象|

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401     | Parameter error.             |
| 2100002 | Operation failed. Cannot connect to service.             |
| 2100003 | System internal error.         |
| 2103005 | Failed to read map.             |
| 2103011 | Failed to create map.             |

> **错误码说明：**
> 以上错误码的详细介绍参见[statistics错误码](../errorcodes/errorcode-net-statistics)。

**示例：**

```js
  statistics.getUidRxBytes(20010038, (error, stats) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(stats))
  })
```

## statistics.getUidRxBytes<sup>10+</sup>

getUidRxBytes(uid: number): Promise\<number>;

获取指定应用实时下行流量。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| uid | number | 是   | 指定查询的应用uid。                   |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以Promise形式返回获取结果。返回指定应用实时下行流量。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401     | Parameter error.             |
| 2100002 | Operation failed. Cannot connect to service.             |
| 2100003 | System internal error.         |
| 2103005 | Failed to read map.             |
| 2103011 | Failed to create map.             |

> **错误码说明：**
> 以上错误码的详细介绍参见[statistics错误码](../errorcodes/errorcode-net-statistics)。

**示例：**

```js
  statistics.getUidRxBytes(20010038).then(function (stats) {
    console.log(JSON.stringify(stats))
  })
```

## statistics.getUidTxBytes<sup>10+</sup>

getUidTxBytes(uid: number, callback: AsyncCallback\<number>): void;

获取指定应用实时上行流量。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| uid | number | 是   | 指定查询的应用uid。                   |
| callback | AsyncCallback\<number>         | 是   | 回调函数。当成功获取应用实时上行流量时，err为undefined，stats为获取到的应用实时上行流量；否则为错误对象|

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401     | Parameter error.             |
| 2100002 | Operation failed. Cannot connect to service.             |
| 2100003 | System internal error.         |
| 2103005 | Failed to read map.             |
| 2103011 | Failed to create map.             |

> **错误码说明：**
> 以上错误码的详细介绍参见[statistics错误码](../errorcodes/errorcode-net-statistics)。

**示例：**

```js
  statistics.getUidTxBytes(20010038, (error, stats) => {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(stats))
  })
```

## statistics.getUidTxBytes<sup>10+</sup>

getUidTxBytes(uid: number): Promise\<number>;

获取指定应用实时上行流量。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名       | 类型                          | 必填 | 说明                                                         |
| ------------ | ----------------------------- | ---- | ------------------------------------------------------------ |
| uid | number | 是   | 指定查询的应用uid。                   |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以Promise形式返回获取结果。返回指定应用实时上行流量。 |

**错误码：**

| 错误码ID | 错误信息                        |
| ------- | -----------------------------  |
| 401     | Parameter error.             |
| 2100002 | Operation failed. Cannot connect to service.             |
| 2100003 | System internal error.         |
| 2103005 | Failed to read map.             |
| 2103011 | Failed to create map.             |

> **错误码说明：**
> 以上错误码的详细介绍参见[statistics错误码](../errorcodes/errorcode-net-statistics)。

**示例：**

```js
  statistics.getUidTxBytes(20010038).then(function (stats) {
    console.log(JSON.stringify(stats))
  })
```
