# @ohos.net.statistics (流量管理)

流量管理模块提供获取指定网卡实时上行、下行流量等能力。

> **说明：**
>
> 本模块首批接口从 API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { statistics } from '@kit.NetworkKit';
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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |
| 2103012   | Failed to obtain the NIC name.               |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |
| 2103012   | Failed to obtain the NIC name.               |

**示例：**

```js
import { statistics } from '@kit.NetworkKit';

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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |
| 2103012   | Failed to obtain the NIC name.               |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |
| 2103012   | Failed to obtain the NIC name.               |

**示例：**

```js
import { statistics } from '@kit.NetworkKit';

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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |
| 2103012   | Failed to obtain the NIC name.               |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |
| 2103012   | Failed to obtain the NIC name.               |

**示例：**

```js
import { statistics } from '@kit.NetworkKit';

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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |
| 2103012   | Failed to obtain the NIC name.               |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |
| 2103012   | Failed to obtain the NIC name.               |

**示例：**

```js
import { statistics } from '@kit.NetworkKit';

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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**示例：**

```js
import { statistics } from '@kit.NetworkKit';
import { BusinessError } from '@kit.BasicServicesKit';

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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**示例：**

```js
import { statistics } from '@kit.NetworkKit';

statistics.getAllRxBytes().then((stats: number) => {
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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**示例：**

```js
import { statistics } from '@kit.NetworkKit';

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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**示例：**

```js
import { statistics } from '@kit.NetworkKit';

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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**示例：**

```js
import { statistics } from '@kit.NetworkKit';

statistics.getUidTxBytes(20010038).then((stats: number) => {
  console.log(JSON.stringify(stats));
});
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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

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

以下错误码的详细介绍参见[statistics 错误码](errorcode-net-statistics.md)。

| 错误码 ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

let sockfd = 50; // 实际开发中需要先根据自己创建的socket获取到
statistics.getSockfdTxBytes(sockfd).then((stats: number) => {
  console.log(JSON.stringify(stats));
}).catch((err: BusinessError) => {
  console.error(JSON.stringify(err));
});
```

## NetBearType<sup>12+</sup>

type NetBearType = connection.NetBearType

网络类型。

**系统能力**：SystemCapability.Communication.NetManager

|       类型       |            说明             |
| ---------------- | --------------------------- |
| [connection.NetBearType](js-apis-net-connection.md#netbeartype) | 枚举网络类型。    |
