# @ohos.net.statistics (流量管理)

流量管理模块，支持基于网卡/UID 的实时流量统计和历史流量统计查询能力。

> **说明：**
> 本模块首批接口从 API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import statistics from "@ohos.net.statistics";
```

## statistics.getIfaceRxBytes<sup>10+</sup>

getIfaceRxBytes(nic: string, callback: AsyncCallback\<number>): void;

获取指定网卡实时下行流量，使用 callback 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                                                                                    |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| nic      | string                 | 是   | 指定查询的网卡名。                                                                                                      |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取网卡实时下行流量时，error 为 undefined，stats 为获取到的网卡实时下行流量(单位:字节)；否则为错误对象。    |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |
| 2103012   | Get iface name failed.                       |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import statistics from '@ohos.net.statistics';

statistics.getIfaceRxBytes("wlan0", (error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});
```

## statistics.getIfaceRxBytes<sup>10+</sup>

getIfaceRxBytes(nic: string): Promise\<number>;

获取指定网卡实时下行流量，使用 Promise 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| nic    | string | 是   | 指定查询的网卡名。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以 Promise 形式返回获取结果。返回网卡实时下行流量(单位:字节)。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |
| 2103012   | Get iface name failed.                       |

**示例：**

```js
import statistics from '@ohos.net.statistics';

statistics.getIfaceRxBytes("wlan0").then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```

## statistics.getIfaceTxBytes<sup>10+</sup>

getIfaceTxBytes(nic: string, callback: AsyncCallback\<number>): void;

获取指定网卡实时上行流量，使用 callback 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                                                                                    |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| nic      | string                 | 是   | 指定查询的网卡名。                                                                                                      |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取网卡实时上行流量时，error 为 undefined，stats 为获取到的网卡实时上行流量(单位:字节)；否则为错误对象。    |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |
| 2103012   | Get iface name failed.                       |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import statistics from '@ohos.net.statistics';

statistics.getIfaceTxBytes("wlan0", (error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});
```

## statistics.getIfaceTxBytes<sup>10+</sup>

getIfaceTxBytes(nic: string): Promise\<number>;

获取指定网卡实时上行流量，使用 Promise 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| nic    | string | 是   | 指定查询的网卡名。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以 Promise 形式返回获取结果。返回网卡实时上行流量(单位:字节)。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |
| 2103012   | Get iface name failed.                       |

**示例：**

```js
import statistics from '@ohos.net.statistics';

statistics.getIfaceTxBytes("wlan0").then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```

## statistics.getCellularRxBytes<sup>10+</sup>

getCellularRxBytes(callback: AsyncCallback\<number>): void;

获取蜂窝实时下行流量，使用 callback 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                                                                                    |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取蜂窝实时下行流量时，error 为 undefined，stats 为获取到的蜂窝实时下行流量(单位:字节)；否则为错误对象。    |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |
| 2103012   | Get iface name failed.                       |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import statistics from '@ohos.net.statistics';

statistics.getCellularRxBytes((error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});
```

## statistics.getCellularRxBytes<sup>10+</sup>

getCellularRxBytes(): Promise\<number>;

获取蜂窝实时下行流量，使用 Promise 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以 Promise 形式返回获取结果。返回蜂窝实时下行流量(单位:字节)。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |
| 2103012   | Get iface name failed.                       |

**示例：**

```js
import statistics from '@ohos.net.statistics';

statistics.getCellularRxBytes().then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```

## statistics.getCellularTxBytes<sup>10+</sup>

getCellularTxBytes(callback: AsyncCallback\<number>): void;

获取蜂窝实时上行流量，使用 callback 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                                                                                    |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取蜂窝实时上行流量时，error 为 undefined，stats 为获取到的蜂窝实时上行流量(单位:字节)；否则为错误对象。    |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |
| 2103012   | Get iface name failed.                       |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import statistics from '@ohos.net.statistics';

statistics.getCellularTxBytes((error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});
```

## statistics.getCellularTxBytes<sup>10+</sup>

getCellularTxBytes(): Promise\<number>;

获取蜂窝实时上行流量，使用 Promise 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以 Promise 形式返回获取结果。返回蜂窝实时上行流量(单位:字节)。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |
| 2103012   | Get iface name failed.                       |

**示例：**

```js
import statistics from '@ohos.net.statistics';

statistics.getCellularTxBytes().then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```

## statistics.getAllRxBytes<sup>10+</sup>

getAllRxBytes(callback: AsyncCallback\<number>): void;

获取所有网卡实时下行流量，使用 callback 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                                                                                          |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取所有网卡实时下行流量，error 为 undefined，stats 为获取到的所有网卡实时下行流量(单位:字节)；否则为错误对象。    |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |

**示例：**

```js
import statistics from '@ohos.net.statistics';
import { BusinessError } from '@ohos.base';

statistics.getAllRxBytes((error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});
```

## statistics.getAllRxBytes<sup>10+</sup>

getAllRxBytes(): Promise\<number>;

获取所有网卡实时下行流量，使用 Promise 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以 Promise 形式返回获取结果。返回所有网卡实时下行流量(单位:字节)。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |

**示例：**

```js
import statistics from '@ohos.net.statistics';

statistics.getCellularRxBytes().then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```

## statistics.getAllTxBytes<sup>10+</sup>

getAllTxBytes(callback: AsyncCallback\<number>): void;

获取所有网卡实时上行流量，使用 callback 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                                                                                          |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取所有网卡实时上行流量，error 为 undefined，stats 为获取到的所有网卡实时上行流量(单位:字节)；否则为错误对象。    |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import statistics from '@ohos.net.statistics';

statistics.getAllTxBytes((error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});
```

## statistics.getAllTxBytes<sup>10+</sup>

getAllTxBytes(): Promise\<number>;

获取所有网卡实时上行流量，使用 Promise 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以 Promise 形式返回获取结果。返回所有网卡实时上行流量(单位:字节)。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |

**示例：**

```js
import statistics from '@ohos.net.statistics';

statistics.getAllTxBytes().then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```

## statistics.getUidRxBytes<sup>10+</sup>

getUidRxBytes(uid: number, callback: AsyncCallback\<number>): void;

获取指定应用实时下行流量，使用 callback 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                                                                                    |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| uid      | number                 | 是   | 指定查询的应用 uid。                                                                                                    |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取应用实时下行流量时，error 为 undefined，stats 为获取到的应用实时下行流量(单位:字节)；否则为错误对象。    |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import statistics from '@ohos.net.statistics';

statistics.getUidRxBytes(20010038, (error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});
```

## statistics.getUidRxBytes<sup>10+</sup>

getUidRxBytes(uid: number): Promise\<number>;

获取指定应用实时下行流量，使用 Promise 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| uid    | number | 是   | 指定查询的应用 uid。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以 Promise 形式返回获取结果。返回指定应用实时下行流量(单位:字节)。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |

**示例：**

```js
import statistics from '@ohos.net.statistics';

statistics.getUidRxBytes(20010038).then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```

## statistics.getUidTxBytes<sup>10+</sup>

getUidTxBytes(uid: number, callback: AsyncCallback\<number>): void;

获取指定应用实时上行流量，使用 callback 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                                                                                    |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| uid      | number                 | 是   | 指定查询的应用 uid。                                                                                                    |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取应用实时上行流量时，error 为 undefined，stats 为获取到的应用实时上行流量(单位:字节)；否则为错误对象。    |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import statistics from '@ohos.net.statistics';

statistics.getUidTxBytes(20010038, (error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});
```

## statistics.getUidTxBytes<sup>10+</sup>

getUidTxBytes(uid: number): Promise\<number>;

获取指定应用实时上行流量，使用 Promise 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| uid    | number | 是   | 指定查询的应用 uid。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以 Promise 形式返回获取结果。返回指定应用实时上行流量(单位:字节)。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |

**示例：**

```js
import statistics from '@ohos.net.statistics';

statistics.getUidTxBytes(20010038).then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```

## statistics.on('netStatsChange')<sup>10+</sup>

on(type: 'netStatsChange', callback: Callback\<{ iface: string, uid?: number }>): void

订阅流量改变事件通知。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_STATS

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                               |
| -------- | ------------------------------------------- | ---- | ----------------------------------------------------------------- |
| type     | string                                      | 是   | 订阅事件，固定为'netStatsChange'。                                 |
| callback | Callback\<{ iface: string, uid?: number }\> | 是   | 当流量有改变时触发回调函数。<br>iface：网卡名称。<br>uid：应用 uid。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |

**示例：**

```js
import statistics from '@ohos.net.statistics';

class IFace {
  iface: string = ""
  uid?: number = 0
}
statistics.on('netStatsChange', (data: IFace) => {
  console.log('on netStatsChange' + JSON.stringify(data));
});
```

## statistics.off('netStatsChange')<sup>10+</sup>

off(type: 'netStatsChange', callback?: Callback\<{ iface: string, uid?: number }>): void;

取消订阅流量改变事件通知。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_STATS

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                        | 必填 | 说明                                                               |
| -------- | ------------------------------------------- | ---- | ----------------------------------------------------------------- |
| type     | string                                      | 是   | 注销订阅事件，固定为'netStatsChange'。                             |
| callback | Callback\<{ iface: string, uid?: number }\> | 否   | 当流量有改变时触发回调函数。<br>iface：网卡名称。<br>uid：应用 uid。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |

**示例：**

```js
import statistics from '@ohos.net.statistics';

class IFace {
  iface: string = ""
  uid?: number = 0
}
let callback: (data: IFace) => void = (data: IFace) => {
    console.log("on netStatsChange, iFace:" + data.iface + " uid: " + data.uid);
}
statistics.on('netStatsChange', callback);
// 可以指定传入on中的callback取消一个订阅，也可以不指定callback清空所有订阅。
statistics.off('netStatsChange', callback);
statistics.off('netStatsChange');
```

## statistics.getTrafficStatsByIface<sup>10+</sup>

getTrafficStatsByIface(ifaceInfo: IfaceInfo, callback: AsyncCallback\<NetStatsInfo>): void;

获取指定网卡历史流量信息，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_STATS

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名    | 类型                                            | 必填 | 说明                                                                                    |
| --------- | ----------------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
| ifaceInfo | [IfaceInfo](#ifaceinfo10)                       | 是   | 指定查询的网卡信息，参见[IfaceInfo](#ifaceinfo10)。                                     |
| callback  | AsyncCallback\<[NetStatsInfo](#netstatsinfo10)> | 是   | 回调函数。成功时 statsInfo 返回包含网卡历史流量信息，error 为 undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103017   | Read data from database failed.              |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import statistics from '@ohos.net.statistics';

let iFaceInfo: statistics.IfaceInfo | null = null;
if (iFaceInfo) {
  statistics.getTrafficStatsByIface(iFaceInfo as statistics.IfaceInfo, (error: BusinessError, statsInfo: statistics.NetStatsInfo) => {
    console.log(JSON.stringify(error));
    console.log(
      "getTrafficStatsByIface bytes of received = " +
      JSON.stringify(statsInfo.rxBytes)
    );
    console.log(
      "getTrafficStatsByIface bytes of sent = " +
      JSON.stringify(statsInfo.txBytes)
    );
    console.log(
      "getTrafficStatsByIface packets of received = " +
      JSON.stringify(statsInfo.rxPackets)
    );
    console.log(
      "getTrafficStatsByIface packets of sent = " +
      JSON.stringify(statsInfo.txPackets)
    );
  });
}
```

## statistics.getTrafficStatsByIface<sup>10+</sup>

getTrafficStatsByIface(ifaceInfo: IfaceInfo): Promise\<NetStatsInfo>;

获取指定网卡历史流量信息，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_STATS

**系统能力**：SystemCapability.Communication.NetManager.Core

| 参数名    | 类型                      | 必填 | 说明                                                |
| --------- | ------------------------- | ---- | --------------------------------------------------- |
| ifaceInfo | [IfaceInfo](#ifaceinfo10) | 是   | 指定查询的网卡信息，参见[IfaceInfo](#ifaceinfo10)。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<[NetStatsInfo](#netstatsinfo10)> | 以 Promise 形式返回获取结果,返回网卡历史流量信息。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103017   | Read data from database failed.              |

**示例：**

```js
import statistics from '@ohos.net.statistics';

let iFaceInfo: statistics.IfaceInfo | null = null;
if (iFaceInfo) {
  statistics.getTrafficStatsByIface(iFaceInfo as statistics.IfaceInfo).then((statsInfo: statistics.NetStatsInfo) => {
    console.log(
      "getTrafficStatsByIface bytes of received = " +
      JSON.stringify(statsInfo.rxBytes)
    );
    console.log(
      "getTrafficStatsByIface bytes of sent = " +
      JSON.stringify(statsInfo.txBytes)
    );
    console.log(
      "getTrafficStatsByIface packets of received = " +
      JSON.stringify(statsInfo.rxPackets)
    );
    console.log(
      "getTrafficStatsByIface packets of sent = " +
      JSON.stringify(statsInfo.txPackets)
    );
  });
}
```

## statistics.getTrafficStatsByUid<sup>10+</sup>

getTrafficStatsByUid(uidInfo: UidInfo, callback: AsyncCallback\<NetStatsInfo>): void;

获取指定应用历史流量信息，使用 callback 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_STATS

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                                            | 必填 | 说明                                                                                    |
| -------- | ----------------------------------------------- | ---- | -------------------------------------------------------------------------------------- |
| uidInfo  | [UidInfo](#uidinfo10)                           | 是   | 指定查询的应用信息，参见[UidInfo](#uidinfo10)。                                         |
| callback | AsyncCallback\<[NetStatsInfo](#netstatsinfo10)> | 是   | 回调函数。成功时 statsInfo 返回包含应用历史流量信息，error 为 undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103017   | Read data from database failed.              |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import statistics from '@ohos.net.statistics';

let uidInfo: statistics.UidInfo
uidInfo.uid = 20010037

statistics.getTrafficStatsByUid(
  uidInfo,
  (error: BusinessError, statsInfo: statistics.NetStatsInfo) => {
    console.log(JSON.stringify(error));
    console.log(
      "getTrafficStatsByUid bytes of received = " +
      JSON.stringify(statsInfo.rxBytes)
    );
    console.log(
      "getTrafficStatsByUid bytes of sent = " +
      JSON.stringify(statsInfo.txBytes)
    );
    console.log(
      "getTrafficStatsByUid packets of received = " +
      JSON.stringify(statsInfo.rxPackets)
    );
    console.log(
      "getTrafficStatsByUid packets of sent = " +
      JSON.stringify(statsInfo.txPackets)
    );
  }
);
```

## statistics.getTrafficStatsByUid<sup>10+</sup>

getTrafficStatsByUid(uidInfo: UidInfo): Promise\<NetStatsInfo>;

获取指定应用历史流量信息，使用 Promise 方式作为异步方法。

**系统接口**：此接口为系统接口。

**需要权限**：ohos.permission.GET_NETWORK_STATS

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名  | 类型                  | 必填 | 说明                                            |
| ------- | --------------------- | ---- | ----------------------------------------------- |
| uidInfo | [UidInfo](#uidinfo10) | 是   | 指定查询的应用信息，参见[UidInfo](#uidinfo10)。 |

**返回值：**

| 类型                                      | 说明                                               |
| ----------------------------------------- | -------------------------------------------------- |
| Promise\<[NetStatsInfo](#netstatsinfo10)> | 以 Promise 形式返回获取结果,返回应用历史流量信息。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103017   | Read data from database failed.              |

**示例：**

```js
import statistics from '@ohos.net.statistics'

let uidInfo: statistics.UidInfo
uidInfo.uid = 20010037

statistics.getTrafficStatsByUid(uidInfo).then((statsInfo: statistics.NetStatsInfo) => {
  console.log("getTrafficStatsByUid bytes of received = " + JSON.stringify(statsInfo.rxBytes));
  console.log("getTrafficStatsByUid bytes of sent = " + JSON.stringify(statsInfo.txBytes));
  console.log("getTrafficStatsByUid packets of received = " + JSON.stringify(statsInfo.rxPackets));
  console.log("getTrafficStatsByUid packets of sent = " + JSON.stringify(statsInfo.txPackets));
})
```

## statistics.getSockfdRxBytes<sup>11+</sup>

getSockfdRxBytes(sockfd: number, callback: AsyncCallback\<number\>): void;

获取指定socket的下行流量信息，使用 callback 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| sockfd   | number                 | 是   | 指定查询的socket的fd(file description)。                     |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取socket的下行流量时，error 为 undefined，stats 为获取到的该socket的实时下行流量(单位:字节)；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import statistics from '@ohos.net.statistics';

let sockfd = 50; // 实际开发中需要先根据自己创建的socket获取到
statistics.getSockfdRxBytes(sockfd, (error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});
```

## statistics.getSockfdRxBytes<sup>11+</sup>

getSockfdRxBytes(sockfd: number): Promise\<number\>;

获取指定socket的下行流量信息，使用 Promise 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| sockfd | number | 是   | 指定查询的socket的fd(file description)。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise\<number> | 以 Promise 形式返回获取结果，返回该socket的实时下行流量(单位:字节)。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import statistics from '@ohos.net.statistics';

let sockfd = 50; // 实际开发中需要先根据自己创建的socket获取到
statistics.getSockfdRxBytes(sockfd).then((stats: number) => {
  console.log(JSON.stringify(stats));
}).catch((err: BusinessError) => {
  console.error(JSON.stringify(err));
});
```

## statistics.getSockfdTxBytes<sup>11+</sup>

getSockfdTxBytes(sockfd: number, callback: AsyncCallback\<number\>): void;

获取指定socket的上行流量信息，使用 callback 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| sockfd   | number                 | 是   | 指定查询的socket的fd(file description)。                     |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取socket的上行流量时，error 为 undefined，stats 为获取到的该socket的实时上行流量(单位:字节)；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import statistics from '@ohos.net.statistics';

let sockfd = 50; // 实际开发中需要先根据自己创建的socket获取到
statistics.getSockfdTxBytes(sockfd, (error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});
```

## statistics.getSockfdTxBytes<sup>11+</sup>

getSockfdTxBytes(sockfd: number): Promise\<number\>;

获取指定socket的上行流量信息，使用 Promise 方式作为异步方法。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| sockfd | number | 是   | 指定查询的socket的fd(file description)。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise\<number> | 以 Promise 形式返回获取结果，返回该socket的实时上行流量(单位:字节)。 |

**错误码：**

以下错误码的详细介绍参见[statistics 错误码](../errorcodes/errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |

**示例：**

```js
import { BusinessError } from '@ohos.base';
import statistics from '@ohos.net.statistics';

let sockfd = 50; // 实际开发中需要先根据自己创建的socket获取到
statistics.getSockfdTxBytes(sockfd).then((stats: number) => {
  console.log(JSON.stringify(stats));
}).catch((err: BusinessError) => {
  console.error(JSON.stringify(err));
});
```

## IfaceInfo<sup>10+</sup>

查询网卡历史流量参数信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称      | 类型   | 必填 | 说明                              |
| --------- | ------ | ---- | --------------------------------- |
| iface     | string | 是   | 查询的网卡名。                    |
| startTime | number | 是   | 查询的开始时间(时间戳;单位：秒)。 |
| endTime   | number | 是   | 查询的结束时间(时间戳;单位：秒)。 |

## UidInfo<sup>10+</sup>

查询应用历史流量参数信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称      | 类型                                  | 必填 | 说明                        |
| --------- | ------------------------------------- | ---- | -------------------------- |
| ifaceInfo | IfaceInfo\<[IfaceInfo](#ifaceinfo10)> | 是   | 需查询的网卡和时间参数信息。 |
| uid       | number                                | 是   | 需查询的应用 uid。          |

## NetStatsInfo<sup>10+</sup>

获取的历史流量信息。

**系统接口**：此接口为系统接口。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称      | 类型   | 必填 | 说明                      |
| --------- | ------ | ---- | ------------------------ |
| rxBytes   | number | 是   | 流量下行数据(单位:字节)。 |
| txBytes   | number | 是   | 流量上行数据(单位:字节)。 |
| rxPackets | number | 是   | 流量下行包个数。          |
| txPackets | number | 是   | 流量上行包个数。          |
