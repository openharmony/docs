# @ohos.connectedTag (Active Tags)

The **connectedTag** module provides APIs for using active tags. You can use the APIs to initialize the active tag chip and read and write active tags.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { connectedTag } from '@kit.ConnectivityKit';
```

## connectedTag.init

init(): boolean

Initializes the active tag chip.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. Use [initialize](#connectedtaginitialize9) instead.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | **true**: The initialization is successful.&nbsp;<br>**false**: The initialization fails.|

## connectedTag.initialize<sup>9+</sup>

initialize(): void

Initializes the active tag chip.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| -------- | -------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|3200101 | Connected NFC tag running state is abnormal in service. |

## connectedTag.uninit

uninit(): boolean

Uninitializes the active tag resources.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | **true**: The uninstallation is successful.&nbsp;<br>**false**: The uninstallation fails.|

## connectedTag.uninitialize<sup>9+</sup>

uninitialize(): void

Uninitializes the active tag resources.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| -------- | -------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|3200101 | Connected NFC tag running state is abnormal in service. |

## connectedTag.readNdefTag

readNdefTag(): Promise&lt;string&gt;

Reads the content of this active tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;string&gt; | Promise used to return the content of the active tag.|

**Example**

```js
import { connectedTag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

connectedTag.readNdefTag().then((data) => {
    console.log("connectedTag readNdefTag Promise data = " + data);
}).catch((err: BusinessError)=> {
    console.log("connectedTag readNdefTag Promise err: " + err);
});
```

## connectedTag.read<sup>9+</sup>

read(): Promise&lt;number[]&gt;

Reads the content of this active tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;number[]&gt; | Promise used to return the content of the active tag.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| -------- | -------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|3200101 | Connected NFC tag running state is abnormal in service. |

**Example**

```js
import { connectedTag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

connectedTag.read().then((data) => {
    console.log("connectedTag read Promise data = " + data);
}).catch((err: BusinessError)=> {
    console.log("connectedTag read Promise err: " + err);
});
```

## connectedTag.readNdefTag

readNdefTag(callback: AsyncCallback&lt;string&gt;): void

Reads the content of this active tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the active tag content obtained.|

**Example**

```js
import { connectedTag } from '@kit.ConnectivityKit';

connectedTag.readNdefTag((err, data)=> {
    if (err) {
        console.log("connectedTag readNdefTag AsyncCallback err: " + err);
    } else {
        console.log("connectedTag readNdefTag AsyncCallback data: " + data);
    }
});
```

## connectedTag.read<sup>9+</sup>

read(callback: AsyncCallback&lt;number[]&gt;): void

Reads the content of this active tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;number[]&gt; | Yes| Callback used to return the active tag content obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| -------- | -------- |
|201 | Permission denied.                 |
|801 | Capability not supported.          |
|3200101 | Connected NFC tag running state is abnormal in service. |

**Example**

```js
import { connectedTag } from '@kit.ConnectivityKit';

connectedTag.read((err, data)=> {
    if (err) {
        console.log("connectedTag read AsyncCallback err: " + err);
    } else {
        console.log("connectedTag read AsyncCallback data: " + data);
    }
});
```

## connectedTag.writeNdefTag

writeNdefTag(data: string): Promise&lt;void&gt;

Writes data to this active tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| data | string | Yes| Data to be written to the active tag. The maximum length is 1024 bytes.|

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
import { connectedTag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rawData = "010203"; // change it to be correct.
connectedTag.writeNdefTag(rawData).then(() => {
    console.log("connectedTag writeNdefTag Promise success.");
}).catch((err: BusinessError)=> {
    console.log("connectedTag writeNdefTag Promise err: " + err);
});
```

## connectedTag.write<sup>9+</sup>

write(data: number[]): Promise&lt;void&gt;

Writes data to this active tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| data | number[] | Yes| Data to be written to the active tag. The value is a hexadecimal number ranging from 0x00 to 0xFF.|

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| -------- | -------- |
|201 | Permission denied.                 |
|401 | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
|801 | Capability not supported.          |
|3200101 | Connected NFC tag running state is abnormal in service. |

**Example**

```js
import { connectedTag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let rawData = [0x01, 0x02, 0x03]; // change it to be correct.
connectedTag.write(rawData).then(() => {
    console.log("connectedTag write NdefTag Promise success.");
}).catch((err: BusinessError)=> {
    console.log("connectedTag write NdefTag Promise err: " + err);
});
```

## connectedTag.writeNdefTag

writeNdefTag(data: string, callback: AsyncCallback&lt;void&gt;): void

Writes data to this active tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| data | string | Yes| Content of the active tag. The maximum length is 1024 bytes.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the active tag content obtained.|

**Example**

```js
import { connectedTag } from '@kit.ConnectivityKit';

let rawData = "010203"; // change it to be correct.
connectedTag.writeNdefTag(rawData, (err)=> {
    if (err) {
        console.log("connectedTag writeNdefTag AsyncCallback err: " + err);
    } else {
        console.log("connectedTag writeNdefTag AsyncCallback success.");
    }
});
```

## connectedTag.write<sup>9+</sup>

write(data: number[], callback: AsyncCallback&lt;void&gt;): void

Writes data to this active tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| data | number[] | Yes| Data to be written to the active tag. The value is a hexadecimal number ranging from 0x00 to 0xFF.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the active tag content obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| -------- | -------- |
|201 | Permission denied.                 |
|401 | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
|801 | Capability not supported.          |
|3200101 | Connected NFC tag running state is abnormal in service. |

**Example**

```js
import { connectedTag } from '@kit.ConnectivityKit';

let rawData = [0x01, 0x02, 0x03]; // change it to be correct.
connectedTag.write(rawData, (err)=> {
    if (err) {
        console.log("connectedTag write NdefTag AsyncCallback err: " + err);
    } else {
        console.log("connectedTag write NdefTag AsyncCallback success.");
    }
});
```

## connectedTag.on('notify')

on(type: "notify", callback: Callback&lt;number&gt;): void

Registers the NFC field strength state events.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. This parameter has a fixed value of **notify**.|
| callback | Callback&lt;number&gt; | Yes| Callback used to return the [NfcRfType](#nfcrftype).|

## connectedTag.off('notify')

off(type: "notify", callback?: Callback&lt;number&gt;): void

Unregisters the NFC field strength state events.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. This parameter has a fixed value of **notify**.|
| callback | Callback&lt;number&gt; | No| Callback used to return the field strength state. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Example**

```js
import { connectedTag } from '@kit.ConnectivityKit';

// Register the event.
connectedTag.on("notify", (rfState : number)=> {
  console.log("connectedTag on Callback rfState: " + rfState);
});

let initStatus = connectedTag.init();
console.log("connectedTag init status: " + initStatus);

// Add nfc connected tag business operations here...
// connectedTag.writeNdefTag(rawData)
// connectedTag.readNdefTag()

let uninitStatus = connectedTag.uninit();
console.log("connectedTag uninit status: " + uninitStatus);

// Unregister the event.
connectedTag.off("notify", (rfState : number)=> {
  console.log("connectedTag off Callback rfState: " + rfState);
});
```

## NfcRfType

Enumerates the NFC field strength states.

**System capability**: SystemCapability.Communication.ConnectedTag

| Name| Value| Description|
| -------- | -------- | -------- |
| NFC_RF_LEAVE | 0 | NFC exit.|
| NFC_RF_ENTER | 1 | NFC entry.|
