# # @ohos.net.sharing (Network Sharing)

The Network Sharing module allows you to share your device's Internet connection with other connected devices by means of Wi-Fi hotspot, Bluetooth, and USB sharing. It also allows you to query the network sharing state and shared mobile data volume.

> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import sharing from '@ohos.net.sharing';
```

## sharing.isSharingSupported<sup>9+</sup>

isSharingSupported(callback: AsyncCallback\<boolean>): void

Checks whether network sharing is supported. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The value **true** means that network sharing is supported, and **false** means the opposite.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |
| 2202011   | Cannot get network sharing configuration.    |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

sharing.isSharingSupported((error: BusinessError, data: boolean) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## sharing.isSharingSupported<sup>9+</sup>

isSharingSupported(): Promise\<boolean>

Checks whether network sharing is supported. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Return value**

| Type             | Description                                 |
| ----------------- | ------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that network sharing is supported, and **false** means the opposite.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |
| 2202011   | Cannot get network sharing configuration.    |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

sharing
  .isSharingSupported()
  .then((data: boolean) => {
    console.log(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.log(JSON.stringify(error));
  });
```

## sharing.isSharing<sup>9+</sup>

isSharing(callback: AsyncCallback\<boolean>): void

Checks whether network sharing is in progress. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name  | Type                   | Mandatory| Description                                |
| -------- | ----------------------- | ---- | ------------------------------------ |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. The value **true** means that network sharing is in progress, and **false** means the opposite.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |
| 2202011   | Cannot get network sharing configuration.    |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

sharing.isSharing((error: BusinessError, data: boolean) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## sharing.isSharing<sup>9+</sup>

isSharing(): Promise\<boolean>

Checks whether network sharing is in progress. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Return value**

| Type             | Description                                                           |
| ----------------- | --------------------------------------------------------------- |
| Promise\<boolean> | Promise used to return the result. The value **true** means that network sharing is in progress, and **false** means the opposite.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |
| 2202011   | Cannot get network sharing configuration.    |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

sharing
  .isSharing()
  .then((data: boolean) => {
    console.log(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.log(JSON.stringify(error));
  });
```

## sharing.startSharing<sup>9+</sup>

startSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void

Starts network sharing of a specified type. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name  | Type                                 | Mandatory| Description                                    |
| -------- | ------------------------------------- | ---- | ---------------------------------------- |
| type     | [SharingIfaceType](#sharingifacetype) | Yes  | Sharing type. The value **0** means Wi-Fi hotspot sharing, **1** means USB sharing, and **2** means Bluetooth sharing.|
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result.        |

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |
| 2202004   | Try to share an unavailable iface.           |
| 2202005   | WiFi sharing failed.                         |
| 2202006   | Bluetooth sharing failed.                    |
| 2202009   | Network share enable forwarding error.       |
| 2202011   | Cannot get network sharing configuration.    |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

let SHARING_WIFI = 0;
sharing.startSharing(SHARING_WIFI, (error: BusinessError) => {
  console.log(JSON.stringify(error));
});
```

## sharing.startSharing<sup>9+</sup>

startSharing(type: SharingIfaceType): Promise\<void>

Starts network sharing of a specified type. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name| Type                                 | Mandatory| Description                                    |
| ------ | ------------------------------------- | ---- | ---------------------------------------- |
| type   | [SharingIfaceType](#sharingifacetype) | Yes  | Sharing type. The value **0** means Wi-Fi hotspot sharing, **1** means USB sharing, and **2** means Bluetooth sharing.|

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 202       | Non-system applications use system APIs.     |
| 201       | Permission denied.                           |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |
| 2202004   | Try to share an unavailable iface.           |
| 2202005   | WiFi sharing failed.                         |
| 2202006   | Bluetooth sharing failed.                    |
| 2202009   | Network share enable forwarding error.       |
| 2202011   | Cannot get network sharing configuration.    |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

let SHARING_WIFI = 0;
sharing
  .startSharing(SHARING_WIFI)
  .then(() => {
    console.log('start wifi sharing successful');
  })
  .catch((error: BusinessError) => {
    console.log('start wifi sharing failed');
  });
```

## sharing.stopSharing<sup>9+</sup>

stopSharing(type: SharingIfaceType, callback: AsyncCallback\<void>): void

Stops network sharing of a specified type. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name  | Type                                 | Mandatory| Description                                    |
| -------- | ------------------------------------- | ---- | ---------------------------------------- |
| type     | [SharingIfaceType](#sharingifacetype) | Yes  | Sharing type. The value **0** means Wi-Fi hotspot sharing, **1** means USB sharing, and **2** means Bluetooth sharing.|
| callback | AsyncCallback\<void>                  | Yes  | Callback used to return the result.         |

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |
| 2202004   | Try to share an unavailable iface.           |
| 2202005   | WiFi sharing failed.                         |
| 2202006   | Bluetooth sharing failed.                    |
| 2202011   | Cannot get network sharing configuration.    |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

let SHARING_WIFI = 0;
sharing.stopSharing(SHARING_WIFI, (error: BusinessError) => {
  console.log(JSON.stringify(error));
});
```

## sharing.stopSharing<sup>9+</sup>

stopSharing(type: SharingIfaceType): Promise\<void>

Stops network sharing of a specified type. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name| Type                                 | Mandatory| Description                                    |
| ------ | ------------------------------------- | ---- | ---------------------------------------- |
| type   | [SharingIfaceType](#sharingifacetype) | Yes  | Sharing type. The value **0** means Wi-Fi hotspot sharing, **1** means USB sharing, and **2** means Bluetooth sharing.|

**Return value**

| Type          | Description                                 |
| -------------- | ------------------------------------- |
| Promise\<void> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |
| 2202004   | Try to share an unavailable iface.           |
| 2202005   | WiFi sharing failed.                         |
| 2202006   | Bluetooth sharing failed.                    |
| 2202011   | Cannot get network sharing configuration.    |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

let SHARING_WIFI = 0;
sharing
  .stopSharing(SHARING_WIFI)
  .then(() => {
    console.log('stop wifi sharing successful');
  })
  .catch((error: BusinessError) => {
    console.log('stop wifi sharing failed');
  });
```

## sharing.getStatsRxBytes<sup>9+</sup>

getStatsRxBytes(callback: AsyncCallback\<number>): void

Obtains the volume of mobile data traffic received via network sharing. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name  | Type                  | Mandatory| Description                                   |
| -------- | ---------------------- | ---- | --------------------------------------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the data volume, in KB.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

sharing.getStatsRxBytes((error: BusinessError, data: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## sharing.getStatsRxBytes<sup>9+</sup>

getStatsRxBytes(): Promise\<number>

Obtains the volume of mobile data traffic received via network sharing. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Return value**

| Type            | Description                                             |
| ---------------- | ------------------------------------------------- |
| Promise\<number> | Promise used to return the data volume, in KB.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

sharing
  .getStatsRxBytes()
  .then((data: number) => {
    console.log(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.log(JSON.stringify(error));
  });
```

## sharing.getStatsTxBytes<sup>9+</sup>

getStatsTxBytes(callback: AsyncCallback\<number>): void

Obtains the volume of mobile data traffic sent via network sharing. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name  | Type                  | Mandatory| Description                                   |
| -------- | ---------------------- | ---- | --------------------------------------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the data volume, in KB.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

sharing.getStatsTxBytes((error: BusinessError, data: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## sharing.getStatsTxBytes<sup>9+</sup>

getStatsTxBytes(): Promise\<number>

Obtains the volume of mobile data traffic sent via network sharing. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Return value**

| Type            | Description                                             |
| ---------------- | ------------------------------------------------- |
| Promise\<number> | Promise used to return the data volume, in KB.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

sharing
  .getStatsTxBytes()
  .then((data: number) => {
    console.log(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.log(JSON.stringify(error));
  });
```

## sharing.getStatsTotalBytes<sup>9+</sup>

getStatsTotalBytes(callback: AsyncCallback\<number>): void

Obtains the volume of mobile data traffic sent and received via network sharing. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name  | Type                  | Mandatory| Description                                   |
| -------- | ---------------------- | ---- | --------------------------------------- |
| callback | AsyncCallback\<number> | Yes  | Callback used to return the data volume, in KB.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

sharing.getStatsTotalBytes((error: BusinessError, data: number) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## sharing.getStatsTotalBytes<sup>9+</sup>

getStatsTotalBytes(): Promise\<number>

Obtains the volume of mobile data traffic sent and received via network sharing. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Return value**

| Type            | Description                                           |
| ---------------- | ----------------------------------------------- |
| Promise\<number> | Promise used to return the data volume, in KB.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

sharing
  .getStatsTotalBytes()
  .then((data: number) => {
    console.log(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.log(JSON.stringify(error));
  });
```

## sharing.getSharingIfaces<sup>9+</sup>

getSharingIfaces(state: SharingIfaceState, callback: AsyncCallback\<Array\<string>>): void

Obtains the names of NICs in the specified network sharing state. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name  | Type                                   | Mandatory| Description                                  |
| -------- | --------------------------------------- | ---- | -------------------------------------- |
| state    | [SharingIfaceState](#sharingifacestate) | Yes  | Network sharing state.                        |
| callback | AsyncCallback\<Array\<string>>          | Yes  | Callback used to return an array of NIC names.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

let SHARING_BLUETOOTH = 2;
sharing.getSharingIfaces(SHARING_BLUETOOTH, (error: BusinessError, data: string[]) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## sharing.getSharingIfaces<sup>9+</sup>

getSharingIfaces(state: SharingIfaceState): Promise\<Array\<string>>

Obtains the names of NICs in the specified network sharing state. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name| Type                                   | Mandatory| Description          |
| ------ | --------------------------------------- | ---- | -------------- |
| state  | [SharingIfaceState](#sharingifacestate) | Yes  | Network sharing state.|

**Return value**

| Type                    | Description                                     |
| ------------------------ | ----------------------------------------- |
| Promise\<Array\<string>> | Promise used to return an array of NIC names.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

let SHARING_BLUETOOTH = 2;
sharing
  .getSharingIfaces(SHARING_BLUETOOTH)
  .then((data: string[]) => {
    console.log(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.log(JSON.stringify(error));
  });
```

## sharing.getSharingState<sup>9+</sup>

getSharingState(type: SharingIfaceType, callback: AsyncCallback\<SharingIfaceState\>): void

Obtains the network sharing state of the specified type. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name  | Type                                                   | Mandatory| Description                                    |
| -------- | ------------------------------------------------------- | ---- | ---------------------------------------- |
| type     | [SharingIfaceType](#sharingifacetype)                   | Yes  | Sharing type. The value **0** means Wi-Fi hotspot sharing, **1** means USB sharing, and **2** means Bluetooth sharing.|
| callback | AsyncCallback\<[SharingIfaceState](#sharingifacestate)> | Yes  | Callback used to return the network sharing state.    |

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

let SHARING_WIFI = 0;
sharing.getSharingState(SHARING_WIFI, (error: BusinessError, data: sharing.SharingIfaceState) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## sharing.getSharingState<sup>9+</sup>

getSharingState(type: SharingIfaceType): Promise\<SharingIfaceState\>

Obtains the network sharing state of the specified type. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name| Type                                 | Mandatory| Description                                    |
| ------ | ------------------------------------- | ---- | ---------------------------------------- |
| type   | [SharingIfaceType](#sharingifacetype) | Yes  | Sharing type. The value **0** means Wi-Fi hotspot sharing, **1** means USB sharing, and **2** means Bluetooth sharing.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**Return value**

| Type                                             | Description                                     |
| ------------------------------------------------- | ----------------------------------------- |
| Promise\<[SharingIfaceState](#sharingifacestate)> | Promise used to return the network sharing state.|

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

let SHARING_WIFI = 0;
sharing
  .getSharingState(SHARING_WIFI)
  .then((data: sharing.SharingIfaceState) => {
    console.log(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.log(JSON.stringify(error));
  });
```

## sharing.getSharableRegexes<sup>9+</sup>

getSharableRegexes(type: SharingIfaceType, callback: AsyncCallback\<Array\<string\>\>): void

Obtains regular expressions of NICs of a specified type. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name  | Type                                 | Mandatory| Description                                          |
| -------- | ------------------------------------- | ---- | ---------------------------------------------- |
| type     | [SharingIfaceType](#sharingifacetype) | Yes  | Sharing type. The value **0** means Wi-Fi hotspot sharing, **1** means USB sharing, and **2** means Bluetooth sharing.      |
| callback | AsyncCallback\<Array\<string>>        | Yes  | Callback used to return an array of regular expressions.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

let SHARING_WIFI = 0;
sharing.getSharableRegexes(SHARING_WIFI, (error: BusinessError, data: string[]) => {
  console.log(JSON.stringify(error));
  console.log(JSON.stringify(data));
});
```

## sharing.getSharableRegexes<sup>9+</sup>

getSharableRegexes(type: SharingIfaceType): Promise\<Array\<string>>

Obtains regular expressions of NICs of a specified type. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name| Type                                 | Mandatory| Description                                    |
| ------ | ------------------------------------- | ---- | ---------------------------------------- |
| type   | [SharingIfaceType](#sharingifacetype) | Yes  | Sharing type. The value **0** means Wi-Fi hotspot sharing, **1** means USB sharing, and **2** means Bluetooth sharing.|

**Return value**

| Type                    | Description                               |
| ------------------------ | ----------------------------------- |
| Promise\<Array\<string>> | Promise used to return an array of regular expressions.|

**Error codes**

| ID| Error Message                                    |
| --------- | -------------------------------------------- |
| 201       | Permission denied.                           |
| 202       | Non-system applications use system APIs.     |
| 401       | Parameter error.                             |
| 2200001   | Invalid parameter value.                     |
| 2200002   | Operation failed. Cannot connect to service. |
| 2200003   | System internal error.                       |

**Example**

```js
import sharing from '@ohos.net.sharing';
import { BusinessError } from '@ohos.base';

let SHARING_WIFI = 0;
sharing
  .getSharableRegexes(SHARING_WIFI)
  .then((data: string[]) => {
    console.log(JSON.stringify(data));
  })
  .catch((error: BusinessError) => {
    console.log(JSON.stringify(error));
  });
```

## sharing.on('sharingStateChange')<sup>9+</sup>

on(type: 'sharingStateChange', callback: Callback\<boolean>): void

Subscribes to network sharing state changes. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name  | Type                   | Mandatory| Description                        |
| -------- | ----------------------- | ---- | ---------------------------- |
| type     | string                  | Yes  | Event name.                  |
| callback | AsyncCallback\<boolean> | Yes  | Callback invoked when the network sharing state changes.|

**Error codes**

| ID| Error Message                                |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**Example**

```js
import sharing from '@ohos.net.sharing';

sharing.on('sharingStateChange', (data: boolean) => {
  console.log('on sharingStateChange: ' + JSON.stringify(data));
});
```

## sharing.off('sharingStateChange')<sup>9+</sup>

off(type: 'sharingStateChange', callback?: Callback\<boolean>): void

Unsubscribes from network sharing state changes. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name  | Type                   | Mandatory| Description                        |
| -------- | ----------------------- | ---- | ---------------------------- |
| type     | string                  | Yes  | Event name.                  |
| callback | AsyncCallback\<boolean> | No  | Callback invoked when the network sharing state changes.|

**Error codes**

| ID| Error Message                                |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**Example**

```js
import sharing from '@ohos.net.sharing';

sharing.off('sharingStateChange', (data: boolean) => {
  console.log(JSON.stringify(data));
});
```

## sharing.on('interfaceSharingStateChange')<sup>9+</sup>

on(type: 'interfaceSharingStateChange', callback: Callback\<{ type: SharingIfaceType, iface: string, state:
SharingIfaceState }>): void

Subscribes to network sharing state changes of a specified NIC. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name  | Type                                                                                                                        | Mandatory| Description                                 |
| -------- | ---------------------------------------------------------------------------------------------------------------------------- | ---- | ------------------------------------- |
| type     | string                                                                                                                       | Yes  | Event name.                           |
| callback | AsyncCallback\<{ type: [SharingIfaceType](#sharingifacetype), iface: string, state: SharingIfaceState(#sharingifacestate) }> | Yes  | Callback invoked when the network sharing state of the specified NIC changes.|

**Error codes**

| ID| Error Message                                |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**Example**

```js
import sharing from '@ohos.net.sharing';

sharing.on('interfaceSharingStateChange', (data: object) => {
  console.log('on interfaceSharingStateChange:' + JSON.stringify(data));
});
```

## sharing.off('interfaceSharingStateChange')<sup>9+</sup>

off(type: 'interfaceSharingStateChange', callback?: Callback\<{ type: SharingIfaceType, iface: string, state:
SharingIfaceState }>): void

Unsubscribes from network sharing status changes of a specified NIC. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name  | Type                                                                                                                        | Mandatory| Description                                    |
| -------- | ---------------------------------------------------------------------------------------------------------------------------- | ---- | ---------------------------------------- |
| type     | string                                                                                                                       | Yes  | Event name.                              |
| callback | AsyncCallback\<{ type: [SharingIfaceType](#sharingifacetype), iface: string, state: SharingIfaceState(#sharingifacestate) }> | No  | Callback used to return the result.|

**Error codes**

| ID| Error Message                                |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**Example**

```js
import sharing from '@ohos.net.sharing';

sharing.off('interfaceSharingStateChange', (data: object) => {
  console.log(JSON.stringify(data));
});
```

## sharing.on('sharingUpstreamChange')<sup>9+</sup>

on(type: 'sharingUpstreamChange', callback: Callback\<NetHandle>): void

Subscribes to upstream network changes. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name  | Type                     | Mandatory| Description                          |
| -------- | ------------------------- | ---- | ------------------------------ |
| type     | string                    | Yes  | Event name.                    |
| callback | AsyncCallback\<NetHandle> | Yes  | Callback invoked when the upstream network changes.|

**Error codes**

| ID| Error Message                                |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**Example**

```js
import sharing from '@ohos.net.sharing';

sharing.on('sharingUpstreamChange', (data: object) => {
  console.log('on sharingUpstreamChange:' + JSON.stringify(data));
});
```

## sharing.off('sharingUpstreamChange')<sup>9+</sup>

off(type: 'sharingUpstreamChange', callback?: Callback\<NetHandle>): void

Unsubscribes from upstream network changes. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.CONNECTIVITY_INTERNAL

**System capability**: SystemCapability.Communication.NetManager.NetSharing

**Parameters**

| Name  | Type                     | Mandatory| Description                            |
| -------- | ------------------------- | ---- | -------------------------------- |
| type     | string                    | Yes  | Event name.                      |
| callback | AsyncCallback\<NetHandle> | No  | Callback used for unsubscription from upstream network changes.|

**Error codes**

| ID| Error Message                                |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**Example**

```js
import sharing from '@ohos.net.sharing';

sharing.off('sharingUpstreamChange', (data: object) => {
  console.log(JSON.stringify(data));
});
```

## SharingIfaceState<sup>9+</sup>

Enumerates the network sharing states of an NIC.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetSharing

| Name                  | Value | Description            |
| ---------------------- | --- | ---------------- |
| SHARING_NIC_SERVING    | 1   | Network sharing is in progress.  |
| SHARING_NIC_CAN_SERVER | 2   | Network sharing is supported.|
| SHARING_NIC_ERROR      | 3   | An error occurred during network sharing.  |

## SharingIfaceType<sup>9+</sup>

Enumerates the network sharing types of an NIC.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.NetManager.NetSharing

| Name             | Value | Description                |
| ----------------- | --- | -------------------- |
| SHARING_WIFI      | 0   | Wi-Fi hotspot sharing.|
| SHARING_USB       | 1   | USB sharing.  |
| SHARING_BLUETOOTH | 2   | Bluetooth sharing.  |
