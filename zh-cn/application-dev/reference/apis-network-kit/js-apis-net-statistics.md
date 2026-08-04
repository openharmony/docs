# @ohos.net.statistics (流量管理)

<!--Kit: Network Kit-->
<!--Subsystem: Communication-->
<!--Owner: @wmyao_mm-->
<!--Designer: @guo-min_net-->
<!--Tester: @tongxilin-->
<!--Adviser: @zhang_yixin13-->

流量管理模块提供获取设备网络流量数据的能力。该模块支持从多个维度查询数据包的流量使用情况，例如：
- 支持获取指定网卡的上/下行流量数据；
- 支持获取所有网卡的总流量数据，便于查看设备整体网络使用情况；
- 支持根据应用uid获取指定应用的流量数据，帮助开发者监控应用的网络资源消耗；
- 支持获取指定socket的流量统计，为细粒度的网络性能分析提供数据基础；
- 支持获取应用在指定时间段内的历史流量使用情况，便于分析应用的长期网络使用趋势。

> **说明：**
>
> 本模块首批接口从 API version 10 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { statistics } from '@kit.NetworkKit';
```

## statistics.getIfaceRxBytes

getIfaceRxBytes(nic: string, callback: AsyncCallback\<number>): void

获取指定网卡从最近一次开机开始至接口调用时刻的下行流量总和（单位：字节）。使用callback异步回调。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                                                                                    |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| nic      | string                 | 是   | 指定查询的网卡名。                                                                                                      |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取到流量数据时，error为undefined，否则为错误对象。    |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
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
  if (error) {
    console.error(`getIfaceRxBytes error, ${JSON.stringify(error)}`);
    return;
  }
  console.info(`getIfaceRxBytes success, ${JSON.stringify(stats)}`);
});
```

## statistics.getIfaceRxBytes

getIfaceRxBytes(nic: string): Promise\<number>

获取指定网卡从最近一次开机开始至接口调用时刻的下行流量总和（单位：字节）。使用Promise异步回调。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| nic    | string | 是   | 指定查询的网卡名。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | Promise对象。返回指定网卡从最近一次开机开始到现在的下行流量总和（单位：字节）。 |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
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
import { BusinessError } from '@kit.BasicServicesKit';

statistics.getIfaceRxBytes("wlan0").then((stats: number) => {
  console.info(JSON.stringify(stats));
}).catch((err: BusinessError) => {
  console.error(JSON.stringify(err));
});
```

## statistics.getIfaceTxBytes

getIfaceTxBytes(nic: string, callback: AsyncCallback\<number>): void

获取指定网卡从最近一次开机开始至接口调用时刻的上行流量总和（单位：字节）。使用callback异步回调。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                                                                                    |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| nic      | string                 | 是   | 指定查询的网卡名。                                                                                                      |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取到流量数据时，error为undefined，否则为错误对象。    |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
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
  if (error) {
    console.error(`getIfaceTxBytes error, ${JSON.stringify(error)}`);
    return;
  }
  console.info(`getIfaceTxBytes success, ${JSON.stringify(stats)}`);
});
```

## statistics.getIfaceTxBytes

getIfaceTxBytes(nic: string): Promise\<number>

获取指定网卡从最近一次开机开始至接口调用时刻的上行流量总和（单位：字节）。使用Promise异步回调。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| nic    | string | 是   | 指定查询的网卡名。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | Promise对象。返回指定网卡从最近一次开机开始至接口调用时刻的上行流量总和（单位：字节）。 |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
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
import { BusinessError } from '@kit.BasicServicesKit';

statistics.getIfaceTxBytes("wlan0").then((stats: number) => {
  console.info(`getIfaceTxBytes success, ${JSON.stringify(stats)}`);
}).catch((err: BusinessError) => {
   console.error(`getIfaceTxBytes error, ${JSON.stringify(err)}`);
});
```

## statistics.getCellularRxBytes

getCellularRxBytes(callback: AsyncCallback\<number>): void

获取当前已处于连接状态的蜂窝网络对应的网卡从最近一次开机开始至接口调用时刻的下行流量总和（单位：字节）。使用callback异步回调。

> **说明：**
>
> 本接口建议在蜂窝网络处于连接状态时调用，否则会抛出2103012错误码。<br>

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                                                                                    |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取到流量数据时，error为undefined，否则为错误对象。    |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)。

| 错误码ID | 错误信息                                     |
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
  if (error) {
    console.error(`getCellularRxBytes error, ${JSON.stringify(error)}`);
    return;
  }
  console.info(`getCellularRxBytes success, ${JSON.stringify(stats)}`);
});
```

## statistics.getCellularRxBytes

getCellularRxBytes(): Promise\<number>

获取当前已处于连接状态的蜂窝网络对应的网卡从最近一次开机开始至接口调用时刻的下行流量总和（单位：字节）。使用Promise异步回调。

> **说明：**
>
> 本接口建议在蜂窝网络处于连接状态时调用，否则会抛出2103012错误码。<br>

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | Promise对象。返回指定网卡从最近一次开机开始至接口调用时刻的下行流量总和（单位：字节）。 |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)。

| 错误码ID | 错误信息                                     |
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
  console.info('getCellularRxBytes success', JSON.stringify(stats));
}).catch((error: Error) => {
   console.error('getCellularRxBytes error', JSON.stringify(error));
});
```

## statistics.getCellularTxBytes

getCellularTxBytes(callback: AsyncCallback\<number>): void

获取当前已处于连接状态的蜂窝网络对应的网卡从最近一次开机开始至接口调用时刻的上行流量总和（单位：字节）。使用callback异步回调。

> **说明：**
>
> 本接口建议在蜂窝网络处于连接状态时调用，否则会抛出2103012错误码。<br>

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                                                                                    |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取到流量数据时，error为undefined，否则为错误对象。    |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)。

| 错误码ID | 错误信息                                     |
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
   if (error) {
    console.error(`getCellularTxBytes error, ${JSON.stringify(error)}`);
    return;
  }
  console.info(`getCellularTxBytes success, ${JSON.stringify(stats)}`);
});
```

## statistics.getCellularTxBytes

getCellularTxBytes(): Promise\<number>

获取当前已处于连接状态的蜂窝网络对应的网卡从最近一次开机开始至接口调用时刻的上行流量总和（单位：字节）。使用Promise异步回调。

> **说明：**
>
> 本接口建议在蜂窝网络处于连接状态时调用，否则会抛出2103012错误码。<br>

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | Promise对象。返回从最近一次开机开始到现在，蜂窝上所消耗的上行流量总和（单位：字节）。 |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)。

| 错误码ID | 错误信息                                     |
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
  console.info('getCellularTxBytes success', JSON.stringify(stats));
}).catch((error: Error) => {
   console.error('getCellularTxBytes error', JSON.stringify(error));
});
```

## statistics.getAllRxBytes

getAllRxBytes(callback: AsyncCallback\<number>): void

获取所有网卡从最近一次开机开始至接口调用时刻的下行流量总和（单位：字节）。使用callback异步回调。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                                                                                          |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取到流量数据时，error为undefined，否则为错误对象。    |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)。

| 错误码ID | 错误信息                                     |
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
  if (error) {
    console.error(JSON.stringify(error));
    return;
  }
  console.info(JSON.stringify(stats));
});
```

## statistics.getAllRxBytes

getAllRxBytes(): Promise\<number>

获取所有网卡从最近一次开机开始至接口调用时刻的下行流量总和（单位：字节）。使用Promise异步回调。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | Promise对象。返回所有网卡从最近一次开机开始到现在的下行流量总和（单位：字节）。 |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)。

| 错误码ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**示例：**

```js
import { statistics } from '@kit.NetworkKit';

statistics.getAllRxBytes().then((stats: number) => {
  console.info('getAllRxBytes success', JSON.stringify(stats));
}).catch((error: Error) => {
   console.error('getAllRxBytes error', JSON.stringify(error));
});
```

## statistics.getAllTxBytes

getAllTxBytes(callback: AsyncCallback\<number>): void

获取所有网卡从最近一次开机开始至接口调用时刻的上行流量总和（单位：字节）。使用callback异步回调。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                                                                                          |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取到流量数据时，error为undefined，否则为错误对象。    |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)。

| 错误码ID | 错误信息                                     |
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
  if (error) {
    console.error(JSON.stringify(error));
    return;
  }
  console.info(JSON.stringify(stats));
});
```

## statistics.getAllTxBytes

getAllTxBytes(): Promise\<number>

获取所有网卡从最近一次开机开始至接口调用时刻的上行流量总和（单位：字节）。使用Promise异步回调。

**原子化服务API：** 从API version 15开始，该接口支持在原子化服务中使用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | 以Promise 形式返回获取结果。返回所有网卡实时上行流量（单位：字节）。 |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)。

| 错误码ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**示例：**

```js
import { statistics } from '@kit.NetworkKit';

statistics.getAllTxBytes().then((stats: number) => {
  console.info(JSON.stringify(stats));
});
```

## statistics.getUidRxBytes

getUidRxBytes(uid: number, callback: AsyncCallback\<number>): void

获取指定应用从最近一次开机开始至接口调用时刻的下行流量总和（单位：字节）。使用callback异步回调。

> **说明：**
>
> 若重启后该应用未产生流量消耗，则会抛出2103005错误码。<br>

**需要权限：**

- API版本26.0.0之前：N/A
- API版本26.0.0+：ohos.permission.GET_NETWORK_STATS（仅当参数uid数值与接口调用方uid不同时需要申请，即查询非自身应用流量数据时需要申请）

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                                                                                    |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| uid      | number                 | 是   | 指定查询的应用 uid。                                                                                                    |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取到流量数据时，error为undefined，否则为错误对象。    |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied. <br>  适用版本：26.0.0+    |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

let uid = 123456789;  // uid示例，请传入正确的uid
statistics.getUidRxBytes(uid, (error: BusinessError, stats: number) => {
  if (error) {
     console.error(JSON.stringify(error));
     return;
  }
  console.info(JSON.stringify(stats));
});
```

## statistics.getUidRxBytes

getUidRxBytes(uid: number): Promise\<number>

获取指定应用从最近一次开机开始至接口调用时刻的下行流量总和（单位：字节）。使用Promise异步回调。

> **说明：**
>
> 若重启后该应用未产生流量消耗，则会抛出2103005错误码。<br>

**系统能力**：SystemCapability.Communication.NetManager.Core

**需要权限：**

- API版本26.0.0之前：N/A
- API版本26.0.0+：ohos.permission.GET_NETWORK_STATS（仅当参数uid数值与接口调用方uid不同时需要申请，即查询非自身应用流量数据时需要申请）

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| uid    | number | 是   | 指定查询的应用 uid。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | Promise对象。返回指定应用从最近一次开机开始到现在的下行流量总和（单位：字节）。 |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied. <br>  适用版本：26.0.0+    |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**示例：**

```js
import { statistics } from '@kit.NetworkKit';

let uid = 123456789;  // uid示例，请传入正确的uid
statistics.getUidRxBytes(uid).then((stats: number) => {
  console.info(JSON.stringify(stats));
});
```

## statistics.getUidTxBytes

getUidTxBytes(uid: number, callback: AsyncCallback\<number>): void

获取指定应用从最近一次开机开始至接口调用时刻的上行流量总和（单位：字节）。使用callback异步回调。

> **说明：**
>
> 若重启后该应用未产生流量消耗，则会抛出2103005错误码。<br>

**系统能力**：SystemCapability.Communication.NetManager.Core

**需要权限：**

- API版本26.0.0之前：N/A
- API版本26.0.0+：ohos.permission.GET_NETWORK_STATS（仅当参数uid数值与接口调用方uid不同时需要申请，即查询非自身应用流量数据时需要申请）

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                                                                                    |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| uid      | number                 | 是   | 指定查询的应用 uid。                                                                                                    |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取应用实时上行流量时，error为undefined，stats为获取到的应用上行流量（单位：字节）；否则为错误对象。    |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied. <br>  适用版本：26.0.0+    |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

let uid = 123456789;  // uid示例，请传入正确的uid
statistics.getUidTxBytes(uid, (error: BusinessError, stats: number) => {
  if (error) {
    console.error(JSON.stringify(error));
    return;
  }
  console.info(JSON.stringify(stats));
});
```

## statistics.getUidTxBytes

getUidTxBytes(uid: number): Promise\<number>

获取指定应用从最近一次开机开始至接口调用时刻的上行流量总和（单位：字节）。使用Promise异步回调。

> **说明：**
>
> 若重启后该应用未产生流量消耗，则会抛出2103005错误码。<br>

**系统能力**：SystemCapability.Communication.NetManager.Core

**需要权限：**

- API版本26.0.0之前：N/A
- API版本26.0.0+：ohos.permission.GET_NETWORK_STATS（仅当参数uid数值与接口调用方uid不同时需要申请，即查询非自身应用流量数据时需要申请）

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| uid    | number | 是   | 指定查询的应用 uid。 |

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| Promise\<number> | Promise对象。返回指定应用从最近一次开机开始至接口调用时刻的上行流量总和（单位：字节）。 |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 201       | Permission denied. <br>  适用版本：26.0.0+    |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**示例：**

```js
import { statistics } from '@kit.NetworkKit';

let uid = 123456789;  // uid示例，请传入正确的uid
statistics.getUidTxBytes(uid).then((stats: number) => {
  console.info(JSON.stringify(stats));
});
```


## statistics.getSockfdRxBytes<sup>11+</sup>

getSockfdRxBytes(sockfd: number, callback: AsyncCallback\<number\>): void

获取指定Socket的下行流量（单位：字节）。使用callback异步回调。

> **说明：**
>
> 推荐在Socket连接时使用，否则Socket已经关闭后无法查询到对应流量数据。<br>

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| sockfd   | number                 | 是   | 指定查询的Socket的FD(file description)。                     |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取Socket的下行流量时，error为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

let sockfd = 50; // 实际开发中需要先根据自己创建的Socket获取到。
statistics.getSockfdRxBytes(sockfd, (error: BusinessError, stats: number) => {
  if (error) {
    console.error(JSON.stringify(error));
    return;
  }
  console.info(JSON.stringify(stats));
});
```

## statistics.getSockfdRxBytes<sup>11+</sup>

getSockfdRxBytes(sockfd: number): Promise\<number\>

获取指定Socket的下行流量（单位：字节）。使用Promise异步回调。

> **说明：**
>
> 推荐在Socket连接时使用，否则Socket已经关闭后无法查询到对应流量数据。<br>

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| sockfd | number | 是   | 指定查询的Socket的FD(file description)。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise\<number> | Promise对象。返回该Socket的下行流量（单位：字节）。 |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

let sockfd = 50; // 实际开发中需要先根据自己创建的Socket获取到。
statistics.getSockfdRxBytes(sockfd).then((stats: number) => {
  console.info(JSON.stringify(stats));
}).catch((err: BusinessError) => {
  console.error(JSON.stringify(err));
});
```

## statistics.getSockfdTxBytes<sup>11+</sup>

getSockfdTxBytes(sockfd: number, callback: AsyncCallback\<number\>): void

获取指定Socket的上行流量（单位：字节）。使用callback异步回调。

> **说明：**
>
> 推荐在Socket连接时使用，否则Socket已经关闭后无法查询到对应流量数据。<br>

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名   | 类型                   | 必填 | 说明                                                         |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| sockfd   | number                 | 是   | 指定查询的Socket的FD(file description)。                     |
| callback | AsyncCallback\<number> | 是   | 回调函数。当成功获取Socket的上行流量时，error为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

let sockfd = 50; // 实际开发中需要先根据自己创建的Socket获取到。
statistics.getSockfdTxBytes(sockfd, (error: BusinessError, stats: number) => {
  if (error) {
    console.error(JSON.stringify(error));
    return;
  }
  console.info(JSON.stringify(stats));
});
```

## statistics.getSockfdTxBytes<sup>11+</sup>

getSockfdTxBytes(sockfd: number): Promise\<number\>

获取指定Socket的上行流量（单位：字节）。使用Promise异步回调。

> **说明：**
>
> 推荐在Socket连接时使用，否则Socket已经关闭后无法查询到对应流量数据。<br>

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| sockfd | number | 是   | 指定查询的Socket的FD(file description)。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise\<number> | Promise对象。返回该Socket的上行流量（单位：字节）。 |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)和[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

let sockfd = 50; // 实际开发中需要先根据自己创建的Socket获取到。
statistics.getSockfdTxBytes(sockfd).then((stats: number) => {
  console.info(JSON.stringify(stats));
}).catch((err: BusinessError) => {
  console.error(JSON.stringify(err));
});
```
            
## statistics.getSelfTrafficStats<sup>22+</sup>

getSelfTrafficStats(networkInfo: NetworkInfo): Promise\<NetStatsInfo\>

获取指定时间段内，本应用在指定网络中的流量使用情况。使用Promise异步回调。

> **说明：**
>
>- 当前只支持获取蜂窝和Wi-Fi流量使用情况。<br>
>- 当前只支持获取31天之内的流量使用情况，如果参数中传入的时间戳早于当前系统时间31天，会返回错误码2103019。
>- 本接口会有一定耗时，调用时请注意切勿频繁调用。

**系统能力**：SystemCapability.Communication.NetManager.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明                                     |
| ------ | ------ | ---- | ---------------------------------------- |
| networkInfo | [NetworkInfo](#networkinfo22) | 是   | 指定查询的网络信息。 |

**返回值：**

| 类型             | 说明                                                         |
| ---------------- | ------------------------------------------------------------ |
| Promise\<[NetStatsInfo](#netstatsinfo22)> | Promise对象，返回应用历史流量统计信息。 |

**错误码：**

以下错误码的详细介绍参见[流量管理错误码](errorcode-net-statistics.md)。

| 错误码ID | 错误信息                                     |
| --------- | -------------------------------------------- |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103017   | Failed to read the database.                      |
| 2103019   | The timestamp in param is invalid.                      |

**示例：**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { connection, statistics } from '@kit.NetworkKit';

let networkInfo: statistics.NetworkInfo = {
    type: connection.NetBearType.BEARER_CELLULAR,
    startTime: Math.floor(Date.now() / 1000) - 86400 * 31,
    endTime: Math.floor(Date.now() / 1000),
    simId: 1,
}

statistics.getSelfTrafficStats(networkInfo).then((stats: statistics.NetStatsInfo) => {
    console.info('getSelfTrafficStats success : ' + JSON.stringify(stats));
}).catch((err: BusinessError) => {
    console.error('getSelfTrafficStats error. code: ' + `${err.code}` + ', message: ' + `${err.message}`);
});
```

## NetBearType<sup>12+</sup>

type NetBearType = connection.NetBearType

网络类型。

**系统能力**：SystemCapability.Communication.NetManager.Core

|       类型       |            说明             |
| ---------------- | --------------------------- |
| [connection.NetBearType](js-apis-net-connection.md#netbeartype) | 枚举网络类型。    |

## NetworkInfo<sup>22+</sup>

网络信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称        | 类型                                                   | 只读 |可选| 说明           |
|-----------|------------------------------------------------------|----|---|--------------|
| type      | [NetBearType](#netbeartype12) | 否  | 否|网络类型。<br>**注意：** 当type为蜂窝网络时，需指定simId字段。       |
| startTime | number                                               | 否  |否| 开始时间戳（单位：秒）。 |
| endTime   | number                                               | 否  |否 |结束时间戳（单位：秒）。 |
| simId     | number                                               | 否  | 是|SIM卡ID。默认值为uint32_t类型最大值。<br>**注意：** 当type为蜂窝网络时，需指定本字段。   |

## NetStatsInfo<sup>22+</sup>

获取的历史流量信息。

**系统能力**：SystemCapability.Communication.NetManager.Core

| 名称      | 类型   | 只读 |可选| 说明                      |
| --------- | ------ | ---- |---| ------------------------ |
| rxBytes   | number | 否   |否 |流量下行数据（单位：字节）。 |
| txBytes   | number | 否   |否 |流量上行数据（单位：字节）。 |
| rxPackets | number | 否   |否 |流量下行包个数。          |
| txPackets | number | 否   |否 |流量上行包个数。          |