# tagSession (Standard NFC Tag Session) 

The **tagSession** module provides common APIs for establishing connections and transferring data.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## **Modules to Import**

```js
import tag from '@ohos.nfc.tag';
```

## tagSession

Provides common APIs for establishing connections and transferring data. **tagSession** is the base class of all [NFC tag technologies](js-apis-nfctech.md).

A child class instance is required to access the following interfaces. You can use **get**XXX() to obtain a child class instance.

The specific API varies with the NFC tag technology in use. For details, see [NFC Tags](js-apis-nfcTag.md).

### tagSession.getTagInfo

getTagInfo(): tag.TagInfo

Obtains the **tagInfo** object provided by the NFC service when the tag is dispatched.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [tag.getTagInfo](js-apis-nfcTag.md#taggettaginfo9).

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| TagInfo  | **Taginfo** object obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// getXXX can be getIsoDep, getNdef, getMifareClassic, or any other getter for NFC tags.

let tagInfo = tag.getIsoDep(tagInfo).getTagInfo(); 
console.log("tag tagInfo: " + tagInfo);
```

### tagSession.connectTag

connectTag(): boolean;

Connects to this tag. Call this API to set up a connection before reading data from or writing data to a tag.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [tagSession.connect](#tagsessionconnect9).

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean  | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// getXXX can be getIsoDep, getNdef, getMifareClassic, or any other getter for NFC tags.

let connectStatus = tag.getIsoDep(tagInfo).connectTag(); 
console.log("connectStatus: " + connectStatus);
```

### tagSession.connect<sup>9+</sup>

connect(): void;

Connects to this tag. Call this API to set up a connection before reading data from or writing data to a tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// getXXX can be getIsoDep, getNdef, getMifareClassic, or any other getter for NFC tags.

try {
    tag.getIsoDep(tagInfo).connect(); 
    console.log("tag connect success");
} catch (busiError) {
    console.log("tag connect busiError: " + busiError);
}
```

### tagSession.reset()

reset(): void

Resets the connection to this tag.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [tagSession.resetConnection](#tagsessionresetconnection9).

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// getXXX can be getIsoDep, getNdef, getMifareClassic, or any other getter for NFC tags.

tag.getIsoDep(tagInfo).reset(); 
```

### tagSession.resetConnection()<sup>9+</sup>

resetConnection(): void

Resets the connection to this tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// getXXX can be getIsoDep, getNdef, getMifareClassic, or any other getter for NFC tags.

try {
    tag.getIsoDep(tagInfo).resetConnection(); 
    console.log("tag resetConnection success");
} catch (busiError) {
    console.log("tag resetConnection busiError: " + busiError);
}
```

### tagSession.isTagConnected

isTagConnected(): boolean

Checks whether the tag is connected.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [tagSession.isConnected](#tagsessionisconnected9).

**System capability**: SystemCapability.Communication.NFC.Tag

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean  | Returns **true** if the tag is connected; returns **false** otherwise.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// getXXX can be getIsoDep, getNdef, getMifareClassic, or any other getter for NFC tags.

let isTagConnected = tag.getIsoDep(tagInfo).isTagConnected(); 
console.log("isTagConnected: " + isTagConnected);
```

### tagSession.isConnected<sup>9+</sup>

isConnected(): boolean

Checks whether the tag is connected.

**System capability**: SystemCapability.Communication.NFC.Tag

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean  | Returns **true** if the tag is connected; returns **false** otherwise.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// getXXX can be getIsoDep, getNdef, getMifareClassic, or any other getter for NFC tags.

try {
    var isConnected = tag.getIsoDep(tagInfo).isConnected(); 
    console.log("tag isConnected = " + isConnected);
} catch (busiError) {
    console.log("tag isConnected busiError: " + busiError);
}
```

### tagSession.getMaxSendLength

getMaxSendLength(): number

Obtains the maximum length of the data that can be sent to this tag.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [tagSession.getMaxTransmitSize](#tagsessiongetmaxtransmitsize9).

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number  | Maximum data length obtained. The value cannot be a negative number.|

**Example**
```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// getXXX can be getIsoDep, getNdef, getMifareClassic, or any other getter for NFC tags.

let maxSendLen = tag.getIsoDep(tagInfo).getMaxSendLength(); 
console.log("tag maxSendLen: " + maxSendLen);
```

### tagSession.getMaxTransmitSize<sup>9+</sup>

getMaxTransmitSize(): number

Obtains the maximum length of the data that can be sent to this tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number  | Maximum data length obtained. The value cannot be a negative number.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**
```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// getXXX can be getIsoDep, getNdef, getMifareClassic, or any other getter for NFC tags.

try {
    var maxTransmitSize = tag.getIsoDep(tagInfo).getMaxTransmitSize(); 
    console.log("tag maxTransmitSize = " + maxTransmitSize);
} catch (busiError) {
    console.log("tag getMaxTransmitSize busiError: " + busiError);
}
```

### tagSession.getSendDataTimeout

getSendDataTimeout(): number

Obtains the timeout period for sending data to this tag, in milliseconds.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [tagSession.getTimeout](#tagsessiongettimeout9).

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number  | Timeout period obtained, in milliseconds. The value cannot be a negative number.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// getXXX can be getIsoDep, getNdef, getMifareClassic, or any other getter for NFC tags.

let sendDataTimeout = tag.getIsoDep(tagInfo).getSendDataTimeout(); 
console.log("tag sendDataTimeout: " + sendDataTimeout);
```

### tagSession.getTimeout<sup>9+</sup>

getTimeout(): number

Obtains the timeout period for sending data to this tag, in milliseconds.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number  | Timeout period obtained, in milliseconds. The value cannot be a negative number.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// getXXX can be getIsoDep, getNdef, getMifareClassic, or any other getter for NFC tags.

try {
    var timeout = tag.getIsoDep(tagInfo).getTimeout(); 
    console.log("tag timeout = " + timeout);
} catch (busiError) {
    console.log("tag getTimeout busiError: " + busiError);
}
```

### tagSession.setSendDataTimeout

setSendDataTimeout(timeout: number): boolean

Sets the timeout period for sending data to this tag, in milliseconds.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [tagSession.setTimeout](#tagsessionsettimeout9).

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| timeout | number | Yes| Timeout period to set, in milliseconds. The value cannot be a negative number.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean  | Returns **true** if the timeout period is set successfully; returns **false** otherwise.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// getXXX can be getIsoDep, getNdef, getMifareClassic, or any other getter for NFC tags.

let timeoutMs = 700;  // Change it as required.
let setStatus = tag.getIsoDep(tagInfo).setSendDataTimeout(timeoutMs); 
console.log("tag setSendDataTimeout setStatus: " + setStatus);
```

### tagSession.setTimeout<sup>9+</sup>

setTimeout(timeout: number): void

Sets the timeout period for sending data to this tag, in milliseconds.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| timeout | number | Yes| Timeout period to set, in milliseconds. The value cannot be a negative number.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// getXXX can be getIsoDep, getNdef, getMifareClassic, or any other getter for NFC tags.

let timeoutMs = 700;  // Change it as required.
try {
    tag.getIsoDep(tagInfo).setTimeout(timeoutMs); 
    console.log("tag setTimeout success");
} catch (busiError) {
    console.log("tag setTimeout busiError: " + busiError);
}
```

### tagSession.sendData

sendData(data: number[]): Promise<number[]>

Sends data to this tag. This API uses a promise to return the result.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [tagSession.transmit](#tagsessiontransmit9).

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| data | number[] | Yes| Data to send. The data consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise<number[]> | Promise used to return the response from the tag. The response consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// getXXX can be getIsoDep, getNdef, getMifareClassic, or any other getter for NFC tags.

// Connect to the tag if it is not connected.
if (!tag.getIsoDep(tagInfo).isTagConnected()) {
    if (!tag.getIsoDep(tagInfo).connectTag()) {
        console.log("tagSession connectTag failed.");
        return;
    }
}

let cmdData = [0x01, 0x02, 0x03, 0x04]; // Change it as required.
tag.getIsoDep(tagInfo).sendData(cmdData).then((response) => {
    console.log("tagSession sendData Promise response: " + response);
}).catch((err)=> {
    console.log("tagSession sendData Promise err: " + err);
});
```

### tagSession.sendData

sendData(data: number[], callback: AsyncCallback<number[]>): void

Sends data to this tag. This API uses an asynchronous callback to return the result.

> **NOTE**
> This parameter is supported since API version 7 and discarded since API version 9. You are advised to use [tagSession.transmit](#tagsessiontransmit9-1).

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| data | number[] | Yes| Data to send. The data consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|
| callback | AsyncCallback<number[]> | Yes| Callback invoked to return the response from the tag. The response consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// getXXX can be getIsoDep, getNdef, getMifareClassic, or any other getter for NFC tags.

// Connect to the tag if it is not connected.
if (!tag.getIsoDep(tagInfo).isTagConnected()) {
    if (!tag.getIsoDep(tagInfo).connectTag()) {
        console.log("tagSession connectTag failed.");
        return;
    }
}

let cmdData = [0x01, 0x02, 0x03, 0x04]; // Change it as required.
tag.getIsoDep(tagInfo).sendData(cmdData, (err, response)=> {
    if (err) {
        console.log("tagSession sendData AsyncCallback err: " + err);
    } else {
        console.log("tagSession sendData AsyncCallback response: " + response);
    }
});
```

### tagSession.transmit<sup>9+</sup>

transmit(data: number[]): Promise<number[]>

Transmits data to this tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| data | number[] | Yes| Data to transmit. The data consists of hexadecimal numbers ranging from **0x00** to **0xFF**. |

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise<number[]> | Promise used to return the response from the tag. The response consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// getXXX can be getIsoDep, getNdef, getMifareClassic, or any other getter for NFC tags.

// Connect to the tag if it is not connected.
try {
    if (!tag.getIsoDep(tagInfo).isConnected()) {
        tag.getIsoDep(tagInfo).connect();
    }
} catch (busiError) {
    console.log("tag connect busiError: " + busiError);
    return;
}

let cmdData = [0x01, 0x02, 0x03, 0x04]; // Change it as required.
try {
    tag.getIsoDep(tagInfo).transmit(cmdData).then((response) => {
        console.log("tagSession transmit Promise response: " + response);
    }).catch((err)=> {
        console.log("tagSession transmit Promise err: " + err);
    });
} catch (busiError) {
    console.log("tag transmit busiError: " + busiError);
    return;
}
```

### tagSession.transmit<sup>9+</sup>

transmit(data: number[], callback: AsyncCallback<number[]>): void

Transmits data to this tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| data | number[] | Yes| Data to transmit. The data consists of hexadecimal numbers ranging from **0x00** to **0xFF**. |
| callback | AsyncCallback<number[]> | Yes| Callback invoked to return the response from the tag. The response consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// getXXX can be getIsoDep, getNdef, getMifareClassic, or any other getter for NFC tags.

// Connect to the tag if it is not connected.
try {
    if (!tag.getIsoDep(tagInfo).isConnected()) {
        tag.getIsoDep(tagInfo).connect();
    }
} catch (busiError) {
    console.log("tag connect busiError: " + busiError);
    return;
}

let cmdData = [0x01, 0x02, 0x03, 0x04]; // Change it as required.
try {
    tag.getIsoDep(tagInfo).transmit(cmdData, (err, response)=> {
        if (err) {
            console.log("tagSession transmit AsyncCallback err: " + err);
        } else {
            console.log("tagSession transmit AsyncCallback response: " + response);
        }
    });
} catch (busiError) {
    console.log("tag transmit busiError: " + busiError);
    return;
}

```
