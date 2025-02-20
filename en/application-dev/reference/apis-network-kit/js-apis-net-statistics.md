# @ohos.net.statistics (Traffic Management)

The **statistics** module provides APIs to query real-time or historical data traffic by the specified network interface card (NIC) or user ID (UID).

> **NOTE**
> The initial APIs of this module are supported since API version 10. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { statistics } from '@kit.NetworkKit';
```

## statistics.getIfaceRxBytes<sup>10+</sup>

getIfaceRxBytes(nic: string, callback: AsyncCallback\<number>): void;

Obtains the real-time downlink data traffic of the specified NIC. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                                                                                   |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| nic      | string                 | Yes  | NIC name.                                                                                                     |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the real-time downlink data traffic of the NIC in bytes. Otherwise, **error** is an error object.   |

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |
| 2103012   | Failed to obtain the NIC name.               |

**Example**

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

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |
| 2103012   | Failed to obtain the NIC name.               |

**Example**

```js
import { statistics } from '@kit.NetworkKit';

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
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| nic      | string                 | Yes  | NIC name.                                                                                                     |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the real-time uplink data traffic of the NIC in bytes. Otherwise, **error** is an error object.   |

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |
| 2103012   | Failed to obtain the NIC name.               |

**Example**

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

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |
| 2103012   | Failed to obtain the NIC name.               |

**Example**

```js
import { statistics } from '@kit.NetworkKit';

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
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the real-time downlink data traffic of the cellular network in bytes. Otherwise, **error** is an error object.   |

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |
| 2103012   | Failed to obtain the NIC name.               |

**Example**

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

Obtains the real-time downlink data traffic of a cellular network. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**
| Type| Description|
| -------- | -------- |
| Promise\<number> | Promise used to return the result, which is the real-time downlink data traffic of the cellular network in bytes.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |
| 2103012   | Failed to obtain the NIC name.               |

**Example**

```js
import { statistics } from '@kit.NetworkKit';

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
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the real-time uplink data traffic of the cellular network in bytes. Otherwise, **error** is an error object.   |

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |
| 2103012   | Failed to obtain the NIC name.               |

**Example**

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

Obtains the real-time uplink data traffic of a cellular network. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**
| Type| Description|
| -------- | -------- |
| Promise\<number> | Promise used to return the result, which is the real-time uplink data traffic of the cellular network in bytes.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |
| 2103012   | Failed to obtain the NIC name.               |

**Example**

```js
import { statistics } from '@kit.NetworkKit';

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
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the real-time downlink data traffic of all NICs in bytes. Otherwise, **error** is an error object.   |

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service. |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**Example**

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

Obtains the real-time downlink data traffic of all NICs. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**
| Type| Description|
| -------- | -------- |
| Promise\<number> | Promise used to return the result, which is the real-time downlink data traffic of all NICs in bytes.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**Example**

```js
import { statistics } from '@kit.NetworkKit';

statistics.getAllRxBytes().then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```

## statistics.getAllTxBytes<sup>10+</sup>

getAllTxBytes(callback: AsyncCallback\<number>): void;

Obtains the real-time uplink data traffic of all NICs. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                                                                                         |
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the real-time uplink data traffic of all NICs in bytes. Otherwise, **error** is an error object.   |

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**Example**

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

Obtains the real-time uplink data traffic of all NICs. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Return value**
| Type| Description|
| -------- | -------- |
| Promise\<number> | Promise used to return the result, which is the real-time uplink data traffic of all NICs in bytes.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**Example**

```js
import { statistics } from '@kit.NetworkKit';

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
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| uid      | number                 | Yes  | Application UID.                                                                                                   |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the real-time downlink data traffic of the application in bytes. Otherwise, **error** is an error object.   |

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**Example**

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

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**Example**

```js
import { statistics } from '@kit.NetworkKit';

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
| -------- | ---------------------- | ---- | ---------------------------------------------------------------------------------------------------------------------- |
| uid      | number                 | Yes  | Application UID.                                                                                                   |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the real-time uplink data traffic of the application in bytes. Otherwise, **error** is an error object.   |

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**Example**

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

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |
| 2103005   | Failed to read the system map.               |
| 2103011   | Failed to create a system map.               |

**Example**

```js
import { statistics } from '@kit.NetworkKit';

statistics.getUidTxBytes(20010038).then((stats: number) => {
  console.log(JSON.stringify(stats));
});
```


## statistics.getSockfdRxBytes<sup>11+</sup>

getSockfdRxBytes(sockfd: number, callback: AsyncCallback\<number\>): void;

Obtains the downlink data traffic (in bytes) of the specified socket. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| sockfd   | number                 | Yes  | FD of the socket.                    |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the downlink data traffic of the socket. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

let sockfd = 50; // FD of the socket you created.
statistics.getSockfdRxBytes(sockfd, (error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});
```

## statistics.getSockfdRxBytes<sup>11+</sup>

getSockfdRxBytes(sockfd: number): Promise\<number\>;

Obtains the downlink data traffic (in bytes) of the specified socket. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| sockfd | number | Yes  | FD of the socket.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise\<number> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

let sockfd = 50; // FD of the socket you created.
statistics.getSockfdRxBytes(sockfd).then((stats: number) => {
  console.log(JSON.stringify(stats));
}).catch((err: BusinessError) => {
  console.error(JSON.stringify(err));
});
```

## statistics.getSockfdTxBytes<sup>11+</sup>

getSockfdTxBytes(sockfd: number, callback: AsyncCallback\<number\>): void;

Obtains the uplink data traffic (in bytes) of the specified socket. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name  | Type                  | Mandatory| Description                                                        |
| -------- | ---------------------- | ---- | ------------------------------------------------------------ |
| sockfd   | number                 | Yes  | FD of the socket.                    |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the result. Callback used to return the result. If the operation is successful, **error** is **undefined** and **stats** is the uplink data traffic of the socket. Otherwise, **error** is an error object.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

let sockfd = 50; // FD of the socket you created.
statistics.getSockfdTxBytes(sockfd, (error: BusinessError, stats: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(stats));
});
```

## statistics.getSockfdTxBytes<sup>11+</sup>

getSockfdTxBytes(sockfd: number): Promise\<number\>;

Obtains the uplink data traffic (in bytes) of the specified socket. This API uses a promise to return the result.

**System capability**: SystemCapability.Communication.NetManager.Core

**Parameters**

| Name| Type  | Mandatory| Description                                    |
| ------ | ------ | ---- | ---------------------------------------- |
| sockfd | number | Yes  | FD of the socket.|

**Return value**

| Type            | Description                                                        |
| ---------------- | ------------------------------------------------------------ |
| Promise\<number> | Promise used to return the result.|

**Error codes**

For details about the error codes, see [Traffic Management Error Codes](errorcode-net-statistics.md).

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 401       | Parameter error.                             |
| 2100001   | Invalid parameter value.                     |
| 2100002   | Failed to connect to the service.            |
| 2100003   | System internal error.                       |

**Example**

```js
import { BusinessError } from '@kit.BasicServicesKit';
import { statistics } from '@kit.NetworkKit';

let sockfd = 50; // FD of the socket you created.
statistics.getSockfdTxBytes(sockfd).then((stats: number) => {
  console.log(JSON.stringify(stats));
}).catch((err: BusinessError) => {
  console.error(JSON.stringify(err));
});
```

## NetBearType

type NetBearType = connection.NetBearType

Enumerates network types.

**System capability**: SystemCapability.Communication.NetStack

|       Type      |            Description            |
| ---------------- | --------------------------- |
| connection.NetBearType | Network type.   |
