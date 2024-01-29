# @ohos.bluetooth.pbap (Bluetooth PBAP Module)

The **pbap** module provides APIs for accessing the phone book of a device using the Bluetooth Phone Book Access Profile (PBAP).

> **NOTE**
>
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.



## Modules to Import

```js
import pbap from '@ohos.bluetooth.pbap';
```


## pbap.createPbapServerProfile<a name="createPbapServerProfile"></a>

createPbapServerProfile(): PbapServerProfile

Create a **PbapServerProfile** instance.

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Return value**

| Type                           | Description        |
| ----------------------------- | ---------- |
| PbapServerProfile | **PbapServerProfile** instance created.|

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let pbapServerProfile = pbap.createPbapServerProfile();
    console.info('pbapServer success');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


## PbapServerProfile

Provides APIs for accessing the phone book of a device. Before using any API of **PbapServerProfile**, you need to create an instance of this class by using **createPbapServerProfile()**.


### disconnect<a name="PbapServerProfile-disconnect"></a>

disconnect(deviceId: string): void

Disconnects the PBAP service for a device.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name   | Type    | Mandatory  | Description     |
| ------ | ------ | ---- | ------- |
| deviceId | string | Yes   | Address of the remote device.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let pbapServerProfile = pbap.createPbapServerProfile();
    pbapServerProfile.disconnect('XX:XX:XX:XX:XX:XX');
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### setShareType<a name="PbapServerProfile-setShareType"></a>

setShareType(deviceId: string, type: ShareType, callback: AsyncCallback&lt;void&gt;): void

Sets the share type of the phone book information for a device. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|
| type | [ShareType](#ShareType) | Yes   | Share type to set.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result.<br> If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.  |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let pbapServerProfile = pbap.createPbapServerProfile();
    pbapServerProfile.setShareType('XX:XX:XX:XX:XX:XX', 0, (err: BusinessError) => {
       console.info('setShareType'); 
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### setShareType<a name="PbapServerProfile-setShareType"></a>

setShareType(deviceId: string, type: ShareType): Promise&lt;void&gt;

Sets the share type of the phone book information for a device. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|
| type | [ShareType](#ShareType) | Yes   | Share type to set.|

**Return value**

| Type                                             | Description               |
| ------------------------------------------------- | ------------------- |
| Promise&lt;void&gt; | Promise used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let pbapServerProfile = pbap.createPbapServerProfile();
    pbapServerProfile.setShareType('XX:XX:XX:XX:XX:XX', 0).then(() => {
        console.info('setShareType');
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getShareType<a name="PbapServerProfile-getShareType"></a>

getShareType(deviceId: string, callback: AsyncCallback&lt;ShareType&gt;): void

Obtains the phone book share type of a device. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|
| callback | AsyncCallback&lt;[ShareType](#ShareType)&gt; | Yes   | Callback invoked to return the result.<br> If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.  |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let pbapServerProfile = pbap.createPbapServerProfile();
    pbapServerProfile.getShareType('XX:XX:XX:XX:XX:XX', (err, type) => {
        console.info('getShareType ' + type);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getShareType<a name="PbapServerProfile-getShareType"></a>

getShareType(deviceId: string): Promise&lt;ShareType&gt;

Obtains the phone book share type of a device. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type                                             | Description               |
| ------------------------------------------------- | ------------------- |
| Promise&lt;[ShareType](#ShareType)&gt; | Promise used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let pbapServerProfile = pbap.createPbapServerProfile();
    pbapServerProfile.getShareType('XX:XX:XX:XX:XX:XX').then((type) => {
        console.info('getShareType ' + type);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### setPhoneBookAccessAuthorization<a name="PbapServerProfile-setPhoneBookAccessAuthorization"></a>

setPhoneBookAccessAuthorization(deviceId: string, authorization: AccessAuthorization, callback: AsyncCallback&lt;void&gt;): void

Sets the phone book access authorization for a device. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|
| authorization | [AccessAuthorization](js-apis-bluetooth-constant.md#AccessAuthorization) | Yes   | Phone book access authorization to set.|
| callback | AsyncCallback&lt;void&gt; | Yes   | Callback invoked to return the result.<br> If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.  |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let pbapServerProfile = pbap.createPbapServerProfile();
    pbapServerProfile.setPhoneBookAccessAuthorization('XX:XX:XX:XX:XX:XX', 0, (err: BusinessError) => {
       console.info('setPhoneBookAccessAuthorization'); 
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```


### setPhoneBookAccessAuthorization<a name="PbapServerProfile-setPhoneBookAccessAuthorization"></a>

setPhoneBookAccessAuthorization(deviceId: string, authorization: AccessAuthorization): Promise&lt;void&gt;

Sets the phone book access authorization for a device. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|
| authorization | [AccessAuthorization](js-apis-bluetooth-constant.md#AccessAuthorization) | Yes   | Phone book access authorization to set.|

**Return value**

| Type                                             | Description               |
| ------------------------------------------------- | ------------------- |
| Promise&lt;void&gt; | Promise used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let pbapServerProfile = pbap.createPbapServerProfile();
    pbapServerProfile.setPhoneBookAccessAuthorization('XX:XX:XX:XX:XX:XX', 0).then(() => {
        console.info('setPhoneBookAccessAuthorization');
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getPhoneBookAccessAuthorization<a name="PbapServerProfile-getPhoneBookAccessAuthorization"></a>

getPhoneBookAccessAuthorization(deviceId: string, callback: AsyncCallback&lt;AccessAuthorization&gt;): void

Obtains the phone book access authorization of a device. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|
| callback | AsyncCallback&lt;[AccessAuthorization](js-apis-bluetooth-constant.md#AccessAuthorization)&gt; | Yes   | Callback invoked to return the result.<br> If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.  |

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let pbapServerProfile = pbap.createPbapServerProfile();
    pbapServerProfile.getPhoneBookAccessAuthorization('XX:XX:XX:XX:XX:XX', (err, authorization) => {
        console.info('authorization ' + authorization);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

### getPhoneBookAccessAuthorization<a name="PbapServerProfile-getPhoneBookAccessAuthorization"></a>

getPhoneBookAccessAuthorization(deviceId: string): Promise&lt;AccessAuthorization&gt;

Obtains the phone book access authorization of a device. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.ACCESS_BLUETOOTH and ohos.permission.MANAGE_BLUETOOTH

**System capability**: SystemCapability.Communication.Bluetooth.Core

**Parameters**

| Name     | Type    | Mandatory  | Description                                 |
| -------- | ------ | ---- | ----------------------------------- |
| deviceId | string | Yes   | Address of the remote device, for example, XX:XX:XX:XX:XX:XX.|

**Return value**

| Type                                             | Description               |
| ------------------------------------------------- | ------------------- |
| Promise&lt;[AccessAuthorization](js-apis-bluetooth-constant.md#AccessAuthorization)&gt; | Promise used to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [Bluetooth Error Codes](../errorcodes/errorcode-bluetoothManager.md).

| ID| Error Message|
| -------- | ---------------------------- |
|2900001 | Service stopped.                         |
|2900003 | Bluetooth switch is off.                 |
|2900004 | Profile is not supported.                |
|2900099 | Operation failed.                        |

**Example**

```js
import { BusinessError } from '@ohos.base';
try {
    let pbapServerProfile = pbap.createPbapServerProfile();
    pbapServerProfile.getPhoneBookAccessAuthorization('XX:XX:XX:XX:XX:XX').then((authorization) => {
        console.info('authorization ' + authorization);
    });
} catch (err) {
    console.error('errCode: ' + (err as BusinessError).code + ', errMessage: ' + (err as BusinessError).message);
}
```

## ShareType<a name="ShareType"></a>

Enumerates the phone book share types.

**System API**: This is a system API.

**System capability**: SystemCapability.Communication.Bluetooth.Core

| Name                | Value | Description    |
| ------------------ | ---- | ------ |
| SHARE_NAME_AND_PHONE_NUMBER | 0    | Share the name and number.<br>This is a system API.|
| SHARE_ALL | 1    | Share all information.<br>This is a system API. |
| SHARE_NOTHING  | 2    | Share nothing.<br>This is a system API.  |
