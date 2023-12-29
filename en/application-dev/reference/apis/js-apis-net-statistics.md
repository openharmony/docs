# @ohos.net.statistics (Traffic Management)

The **statistics** module provides APIs to query real-time or historical data traffic by the specified network interface card (NIC) or user ID (UID).

> **NOTE**
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import statistics from "@ohos.net.statistics";
```

## statistics.getIfaceRxBytes<sup>10+</sup>

getIfaceRxBytes(nic: string, callback: AsyncCallback\<number>): void;

Obtains the real-time downlink data traffic of the specified NIC. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                                                                                   |
| -------- | ---------------------- | ---- | ----------------------------------------------------------------------------------------------------------------------- |
| nic      | string                 | Yes  | NIC name.                                                                                                     |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the real-time downlink data traffic of the NIC in bytes. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |
| 2103012   | Get iface name failed.                       |

**Example**

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

Obtains the real-time downlink data traffic of the specified NIC. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| nic    | string | Yes  | NIC name.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise\<number> | Promise used to return the result, which is the real-time downlink data traffic of the NIC in bytes.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |
| 2103012   | Get iface name failed.                       |

**Example**

```js
import statistics from '@ohos.net.statistics';

statistics.getIfaceRxBytes("wlan0").then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```

## statistics.getIfaceTxBytes<sup>10+</sup>

getIfaceTxBytes(nic: string, callback: AsyncCallback\<number>): void;

Obtains the real-time uplink data traffic of the specified NIC. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                                                                                   |
| -------- | ---------------------- | ---- | ----------------------------------------------------------------------------------------------------------------------- |
| nic      | string                 | Yes  | NIC name.                                                                                                     |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the real-time uplink data traffic of the NIC in bytes. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |
| 2103012   | Get iface name failed.                       |

**Example**

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

Obtains the real-time uplink data traffic of the specified NIC. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| nic    | string | Yes  | NIC name.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise\<number> | Promise used to return the result, which is the real-time uplink data traffic of the NIC in bytes.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |
| 2103012   | Get iface name failed.                       |

**Example**

```js
import statistics from '@ohos.net.statistics';

statistics.getIfaceTxBytes("wlan0").then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```

## statistics.getCellularRxBytes<sup>10+</sup>

getCellularRxBytes(callback: AsyncCallback\<number>): void;

Obtains the real-time downlink data traffic of a cellular network. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                                                                                   |
| -------- | ---------------------- | ---- | ----------------------------------------------------------------------------------------------------------------------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the real-time downlink data traffic of the cellular network in bytes. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |
| 2103012   | Get iface name failed.                       |

**Example**

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

Obtains the real-time downlink data traffic of a cellular network. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**
| Type| Description|
| -------- | -------- |
| Promise\<number> | Promise used to return the result, which is the real-time downlink data traffic of the cellular network in bytes.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |
| 2103012   | Get iface name failed.                       |

**Example**

```js
import statistics from '@ohos.net.statistics';

statistics.getCellularRxBytes().then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```

## statistics.getCellularTxBytes<sup>10+</sup>

getCellularTxBytes(callback: AsyncCallback\<number>): void;

Obtains the real-time uplink data traffic of a cellular network. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                                                                                   |
| -------- | ---------------------- | ---- | ----------------------------------------------------------------------------------------------------------------------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the real-time uplink data traffic of the cellular network in bytes. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |
| 2103012   | Get iface name failed.                       |

**Example**

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

Obtains the real-time uplink data traffic of a cellular network. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**
| Type| Description|
| -------- | -------- |
| Promise\<number> | Promise used to return the result, which is the real-time uplink data traffic of the cellular network in bytes.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |
| 2103012   | Get iface name failed.                       |

**Example**

```js
import statistics from '@ohos.net.statistics';

statistics.getCellularTxBytes().then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```

## statistics.getAllRxBytes<sup>10+</sup>

getAllRxBytes(callback: AsyncCallback\<number>): void;

Obtains the real-time downlink data traffic of all NICs. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                                                                                         |
| -------- | ---------------------- | ---- | ----------------------------------------------------------------------------------------------------------------------------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the real-time downlink data traffic of all NICs in bytes. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |

**Example**

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

Obtains the real-time downlink data traffic of all NICs. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**
| Type| Description|
| -------- | -------- |
| Promise\<number> | Promise used to return the result, which is the real-time downlink data traffic of all NICs in bytes.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |

**Example**

```js
import statistics from '@ohos.net.statistics';

statistics.getCellularRxBytes().then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```

## statistics.getAllTxBytes<sup>10+</sup>

getAllTxBytes(callback: AsyncCallback\<number>): void;

Obtains the real-time uplink data traffic of all NICs. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                                                                                         |
| -------- | ---------------------- | ---- | ----------------------------------------------------------------------------------------------------------------------------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the real-time uplink data traffic of all NICs in bytes. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |

**Example**

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

Obtains the real-time uplink data traffic of all NICs. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**
| Type| Description|
| -------- | -------- |
| Promise\<number> | Promise used to return the result, which is the real-time uplink data traffic of all NICs in bytes.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |

**Example**

```js
import statistics from '@ohos.net.statistics';

statistics.getAllTxBytes().then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```

## statistics.getUidRxBytes<sup>10+</sup>

getUidRxBytes(uid: number, callback: AsyncCallback\<number>): void;

Obtains the real-time downlink data traffic of the specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                                                                                   |
| -------- | ---------------------- | ---- | ----------------------------------------------------------------------------------------------------------------------- |
| uid      | number                 | Yes  | Application UID.                                                                                                   |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the real-time downlink data traffic of the application in bytes. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |

**Example**

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

Obtains the real-time downlink data traffic of the specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| uid    | number | Yes  | Application UID.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise\<number> | Promise used to return the result, which is the real-time downlink data traffic of the application in bytes.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |

**Example**

```js
import statistics from '@ohos.net.statistics';

statistics.getUidRxBytes(20010038).then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```

## statistics.getUidTxBytes<sup>10+</sup>

getUidTxBytes(uid: number, callback: AsyncCallback\<number>): void;

Obtains the real-time uplink data traffic of the specified application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                                                                                   |
| -------- | ---------------------- | ---- | ----------------------------------------------------------------------------------------------------------------------- |
| uid      | number                 | Yes  | Application UID.                                                                                                   |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the real-time uplink data traffic of the application in bytes. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |

**Example**

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

Obtains the real-time uplink data traffic of the specified application. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| uid    | number | Yes  | Application UID.|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise\<number> | Promise used to return the result, which is the real-time uplink data traffic of the application in bytes.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read map.                          |
| 2103011   | Failed to create map.                        |

**Example**

```js
import statistics from '@ohos.net.statistics';

statistics.getUidTxBytes(20010038).then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```

## statistics.on('netStatsChange')<sup>10+</sup>

on(type: 'netStatsChange', callback: Callback\<{ iface: string, uid?: number }>): void

Subscribes to traffic change events.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_NETWORK_STATS

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                              |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------------ |
| type     | string                                      | Yes  | Event type. This field has a fixed value of **netStatsChange**.                                |
| callback | Callback\<{ iface: string, uid?: number }\> | Yes  | Callback invoked when the traffic changes.<br>**iface**: NIC name.<br>**uid**: application UID.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |

**Example**

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

Unsubscribes from traffic change events.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_NETWORK_STATS

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                       | Mandatory| Description                                                              |
| -------- | ------------------------------------------- | ---- | ------------------------------------------------------------------ |
| type     | string                                      | Yes  | Event type. This field has a fixed value of **netStatsChange**.                            |
| callback | Callback\<{ iface: string, uid?: number }\> | No  | Callback invoked when the traffic changes.<br>**iface**: NIC name.<br>**uid**: application UID.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |

**Example**

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
// You can pass the callback of the on method to cancel listening for a certain type of callback. If you do not pass the callback, you will cancel listening for all callbacks.
statistics.off('netStatsChange', callback);
statistics.off('netStatsChange');
```

## statistics.getTrafficStatsByIface<sup>10+</sup>

getTrafficStatsByIface(ifaceInfo: IfaceInfo, callback: AsyncCallback\<NetStatsInfo>): void;

Obtains the historical data traffic of the specified NIC. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_NETWORK_STATS

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name   | Type                                           | Mandatory| Description                                                                                   |
| --------- | ----------------------------------------------- | ---- | --------------------------------------------------------------------------------------- |
| ifaceInfo | [IfaceInfo](#ifaceinfo10)                       | Yes  | NIC information. For details, see [IfaceInfo](#ifaceinfo10).                                    |
| callback  | AsyncCallback\<[NetStatsInfo](#netstatsinfo10)> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **statsInfo** is the historical data traffic of the NIC. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103017   | Read data from database failed.              |

**Example**

```js
import { BusinessError } from '@ohos.base';
import statistics from '@ohos.net.statistics';

let iFaceInfo: statistics.IfaceInfo

statistics.getTrafficStatsByIface(iFaceInfo, (error: BusinessError, statsInfo: statistics.NetStatsInfo) => {
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
```

## statistics.getTrafficStatsByIface<sup>10+</sup>

getTrafficStatsByIface(ifaceInfo: IfaceInfo): Promise\<NetStatsInfo>;

Obtains the historical data traffic of the specified NIC. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_NETWORK_STATS

**System capability**: SystemCapability.Communication.NetManager.Core

| Name   | Type                     | Mandatory| Description                                               |
| --------- | ------------------------- | ---- | --------------------------------------------------- |
| ifaceInfo | [IfaceInfo](#ifaceinfo10) | Yes  | NIC information. For details, see [IfaceInfo](#ifaceinfo10).|

**Return value**
| Type| Description|
| -------- | -------- |
| Promise\<[NetStatsInfo](#netstatsinfo10)> | Promise used to return the result, which is the historical data traffic of the specified NIC.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103017   | Read data from database failed.              |

**Example**

```js
import statistics from '@ohos.net.statistics';

let iFaceInfo: statistics.IfaceInfo
statistics.getTrafficStatsByIface(iFaceInfo).then((statsInfo: statistics.NetStatsInfo) => {
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
```

## statistics.getTrafficStatsByUid<sup>10+</sup>

getTrafficStatsByUid(uidInfo: UidInfo, callback: AsyncCallback\<NetStatsInfo>): void;

Obtains the historical data traffic of the specified application. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_NETWORK_STATS

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                                           | Mandatory| Description                                                                                   |
| -------- | ----------------------------------------------- | ---- | --------------------------------------------------------------------------------------- |
| uidInfo  | [UidInfo](#uidinfo10)                           | Yes  | Application information. For details, see [UidInfo](#uidinfo10).                                        |
| callback | AsyncCallback\<[NetStatsInfo](#netstatsinfo10)> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **statsInfo** is the historical data traffic of the application. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103017   | Read data from database failed.              |

**Example**

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

Obtains the historical data traffic of the specified application. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.GET_NETWORK_STATS

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name | Type                 | Mandatory| Description                                           |
| ------- | --------------------- | ---- | ----------------------------------------------- |
| uidInfo | [UidInfo](#uidinfo10) | Yes  | Application information. For details, see [UidInfo](#uidinfo10).|

**Return value**

| Type                                     | Description                                              |
| ----------------------------------------- | -------------------------------------------------- |
| Promise\<[NetStatsInfo](#netstatsinfo10)> | Promise used to return the result, which is the historical data traffic of the specified NIC.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](../errorcodes/errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Operation failed. Cannot connect to service. |
| 2100003   | System internal error.                       |
| 2103017   | Read data from database failed.              |

**Example**

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

## IfaceInfo<sup>10+</sup>

Defines the parameters for querying historical traffic of an NIC.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name     | Type  | Mandatory| Description                             |
| --------- | ------ | ---- | --------------------------------- |
| iface     | string | Yes  | NIC name.                   |
| startTime | number | Yes  | Start time of the query, which is a timestamp in seconds.|
| endTime   | number | Yes  | End time of the query, which is a timestamp in seconds.|

## UidInfo<sup>10+</sup>

Defines the parameters for querying historical traffic of an application.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name     | Type                                 | Mandatory| Description                      |
| --------- | ------------------------------------- | ---- | -------------------------- |
| ifaceInfo | IfaceInfo\<[IfaceInfo](#ifaceinfo10)> | Yes  | NIC name and query time range.|
| uid       | number                                | Yes  | Application UID.          |

## NetStatsInfo<sup>10+</sup>

Defines the historical traffic information.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.Core

| Name     | Type  | Mandatory| Description                   |
| --------- | ------ | ---- | ----------------------- |
| rxBytes   | number | Yes  | Downlink traffic data, in bytes.|
| txBytes   | number | Yes  | Uplink traffic data, in bytes.|
| rxPackets | number | Yes  | Number of downlink packets.         |
| txPackets | number | Yes  | Number of uplink packets.         |
