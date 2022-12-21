# @ohos.connectedTag

The **connectedTag** module provides APIs for using active tags. You can use the APIs to initialize the active tag chip and read and write active tags.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import connectedTag from '@ohos.connectedTag';
```

## connectedTag.init

init(): boolean

Initializes the active tag chip.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

## connectedTag.uninit

uninit(): boolean

Uninitializes the active tag resources.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

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
import connectedTag from '@ohos.connectedTag';

connectedTag.readNdefTag().then((data) => {
    console.log("connectedTag readNdefTag Promise data = " + data);
}).catch((err)=> {
    console.log("connectedTag readNdefTag Promise err: " + err);
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
| callback | AsyncCallback&lt;string&gt; | Yes| Callback invoked to return the active tag content obtained.|

**Example**

```js
import connectedTag from '@ohos.connectedTag';

connectedTag.readNdefTag((err, data)=> {
    if (err) {
        console.log("connectedTag readNdefTag AsyncCallback err: " + err);
    } else {
        console.log("connectedTag readNdefTag AsyncCallback data: " + data);
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
| data | string | Yes| Data to write. The maximum length is 1024 bytes.|

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```js
import connectedTag from '@ohos.connectedTag';

var rawData = "010203"; // change it tobe correct.
connectedTag.writeNdefTag(rawData).then(() => {
    console.log("connectedTag writeNdefTag Promise success.");
}).catch((err)=> {
    console.log("connectedTag writeNdefTag Promise err: " + err);
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
| data | string | Yes| Data to write. The maximum length is 1024 bytes.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback invoked to return the active tag content obtained.|

**Example**

```js
import connectedTag from '@ohos.connectedTag';

var rawData = "010203"; // change it tobe correct.
connectedTag.writeNdefTag(rawData, (err)=> {
    if (err) {
        console.log("connectedTag writeNdefTag AsyncCallback err: " + err);
    } else {
        console.log("connectedTag writeNdefTag AsyncCallback success.");
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
| type | string | Yes| Event type. The value is **notify**.|
| callback | Callback&lt;number&gt; | Yes| Callback used to return the [NfcRfType](#nfcrftype).|

## connectedTag.off('notify')

off(type: "notify", callback?: Callback&lt;number&gt;): void

Unregisters the NFC field strength state events.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.ConnectedTag

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Event type. The value is **notify**.|
| callback | Callback&lt;number&gt; | No| Callback used to return the field strength state. If this parameter is not specified, all callbacks associated with the specified event will be unregistered.|

**Example**

```js
import connectedTag from '@ohos.connectedTag';

// Register the event.
connectedTag.on("notify", (err, rfState)=> {
    if (err) {
        console.log("connectedTag on Callback err: " + err);
    } else {
        console.log("connectedTag on Callback rfState: " + rfState);
    }
});

var initStatus = connectedTag.init();
console.log("connectedTag init status: " + initStatus);

// Add nfc connecected tag business oprations here...
// connectedTag.writeNdefTag(rawData)
// connectedTag.readNdefTag()

var uninitStatus = connectedTag.uninit();
console.log("connectedTag uninit status: " + uninitStatus);

// Unregister the event.
connectedTag.off("notify", (err, rfState)=> {
    if (err) {
        console.log("connectedTag off Callback err: " + err);
    } else {
        console.log("connectedTag off Callback rfState: " + rfState);
    }
});
```

## NfcRfType

Enumerates the NFC field strength states.

**System capability**: SystemCapability.Communication.ConnectedTag

| Name| Value| Description|
| -------- | -------- | -------- |
| NFC_RF_LEAVE | 0 | Field off.|
| NFC_RF_ENTER | 1 | Field on.|
