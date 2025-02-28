# tagSession (Standard NFC Tag Session) 

The **tagSession** module provides common APIs for establishing connections and transferring data.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## **Modules to Import**

```js
import { tag } from '@kit.ConnectivityKit';
```

## TagSession

Provides common APIs for establishing connections and transferring data. **TagSession** is the base class of all [NFC tag technologies](js-apis-nfctech.md).

A child class instance is required to access the following interfaces. You can use **get**XXX() to obtain a child class instance.

The specific API varies with the NFC tag technology in use. For details, see [NFC Tags](js-apis-nfcTag.md).

### getTagInfo<sup>(deprecated)</sup>

getTagInfo(): tag.TagInfo

Obtains the **tagInfo** object provided by the NFC service when the tag is dispatched.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. Use [tag.getTagInfo](js-apis-nfcTag.md#taggettaginfo9) instead.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| TagInfo  | **Taginfo** object obtained.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// the following getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

let tagInfo : TagInfo = tag.getIsoDep(tagInfo).getTagInfo();
console.info("tag tagInfo: " + tagInfo);
```

### connectTag<sup>(deprecated)</sup>

connectTag(): boolean;

Connects to this tag. Call this API to set up a connection before reading data from or writing data to a tag.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. Use [tagSession.connect](#connect9) instead.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean  | Returns **true** if the operation is successful; returns **false** otherwise.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// the following getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

let connectStatus : boolean = tag.getIsoDep(tagInfo).connectTag();
console.info("connectStatus: " + connectStatus);
```

### connect<sup>9+</sup>

connect(): void;

Connects to this tag. Call this API to set up a connection before reading data from or writing data to a tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
|201 | Permission denied.                 |
|801 | Capability not supported.          |
| 3100201 | The tag running state is abnormal in the service. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// the following getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

try {
    tag.getIsoDep(tagInfo).connect(); 
    console.info("tag connect success");
} catch (businessError) {
    console.error("tag connect businessError: " + businessError);
}
```

### reset()<sup>(deprecated)</sup>

reset(): void

Resets the connection to this tag.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. Use [tagSession.resetConnection](#resetconnection9) instead.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// the following getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

tag.getIsoDep(tagInfo).reset(); 
```

### resetConnection()<sup>9+</sup>

resetConnection(): void

Resets the connection to this tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
|201 | Permission denied.                 |
|801 | Capability not supported.          |
| 3100201 | The tag running state is abnormal in the service. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// the following getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

try {
    tag.getIsoDep(tagInfo).resetConnection(); 
    console.info("tag resetConnection success");
} catch (businessError) {
    console.error("tag resetConnection businessError: " + businessError);
}
```

### isTagConnected<sup>(deprecated)</sup>

isTagConnected(): boolean

Checks whether the tag is connected.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. Use [tagSession.isConnected](#isconnected9) instead.

**System capability**: SystemCapability.Communication.NFC.Tag

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean  | Returns **true** if the tag is connected; returns **false** otherwise.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// the following getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

let isTagConnected = tag.getIsoDep(tagInfo).isTagConnected(); 
console.info("isTagConnected: " + isTagConnected);
```

### isConnected<sup>9+</sup>

isConnected(): boolean

Checks whether the tag is connected.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean  | Returns **true** if the tag is connected; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
|801 | Capability not supported.          |


**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// the following getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

try {
    let isConnected = tag.getIsoDep(tagInfo).isConnected(); 
    console.info("tag isConnected = " + isConnected);
} catch (businessError) {
    console.error("tag isConnected businessError: " + businessError);
}
```

### getMaxSendLength<sup>(deprecated)</sup>

getMaxSendLength(): number

Obtains the maximum length of the data that can be sent to this tag.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. Use [tagSession.getMaxTransmitSize](#getmaxtransmitsize9) instead.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number  | Maximum data length obtained. The value cannot be a negative number.|

**Example**
```js
import { tag } from '@kit.ConnectivityKit';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// the following getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

let maxSendLen = tag.getIsoDep(tagInfo).getMaxSendLength(); 
console.info("tag maxSendLen: " + maxSendLen);
```

### getMaxTransmitSize<sup>9+</sup>

getMaxTransmitSize(): number

Obtains the maximum length of the data that can be sent to this tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number  | Maximum data length obtained. The value cannot be a negative number.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
|201 | Permission denied.                 |
|801 | Capability not supported.          |
| 3100201 | The tag running state is abnormal in the service. |

**Example**
```js
import { tag } from '@kit.ConnectivityKit';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// the following getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

try {
    let maxTransmitSize = tag.getIsoDep(tagInfo).getMaxTransmitSize(); 
    console.info("tag maxTransmitSize = " + maxTransmitSize);
} catch (businessError) {
    console.error("tag getMaxTransmitSize businessError: " + businessError);
}
```

### getSendDataTimeout<sup>(deprecated)</sup>

getSendDataTimeout(): number

Obtains the timeout period for sending data to this tag, in milliseconds.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. Use [tagSession.getTimeout](#gettimeout9) instead.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number  | Timeout period obtained, in milliseconds. The value cannot be a negative number.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// the following getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

let sendDataTimeout = tag.getIsoDep(tagInfo).getSendDataTimeout(); 
console.info("tag sendDataTimeout: " + sendDataTimeout);
```

### getTimeout<sup>9+</sup>

getTimeout(): number

Obtains the timeout period for sending data to this tag, in milliseconds.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number  | Timeout period obtained, in milliseconds. The value cannot be a negative number.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
|201 | Permission denied.                 |
|801 | Capability not supported.          |
| 3100201 | The tag running state is abnormal in the service. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// the following getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

try {
    let timeout = tag.getIsoDep(tagInfo).getTimeout(); 
    console.info("tag timeout = " + timeout);
} catch (businessError) {
    console.error("tag getTimeout businessError: " + businessError);
}
```

### setSendDataTimeout<sup>(deprecated)</sup>

setSendDataTimeout(timeout: number): boolean

Sets the maximum time allowed for sending data to this tag, in ms.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. Use [tagSession.setTimeout](#settimeout9) instead.

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
import { tag } from '@kit.ConnectivityKit';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// the following getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

let timeoutMs = 700;  // Change it as required.
let setStatus = tag.getIsoDep(tagInfo).setSendDataTimeout(timeoutMs); 
console.info("tag setSendDataTimeout setStatus: " + setStatus);
```

### setTimeout<sup>9+</sup>

setTimeout(timeout: number): void

Sets the maximum time allowed for sending data to this tag, in ms.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| timeout | number | Yes| Timeout period to set, in milliseconds. The value cannot be a negative number.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
|201 | Permission denied.                 |
|401 | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
|801 | Capability not supported.          |
| 3100201 | The tag running state is abnormal in the service. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// the following getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

let timeoutMs = 700;  // Change it as required.
try {
    tag.getIsoDep(tagInfo).setTimeout(timeoutMs); 
    console.info("tag setTimeout success");
} catch (businessError) {
    console.error("tag setTimeout businessError: " + businessError);
}
```

### sendData<sup>(deprecated)</sup>

sendData(data: number[]): Promise<number[]>

Sends data to this tag. This API uses a promise to return the result.

> **NOTE**
> This API is supported since API version 7 and deprecated since API version 9. Use [tagSession.transmit](#transmit9) instead.

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
import tag from '@kit.ConnectivityKit';
import { BusinessError } from '@ohos.base';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// the following getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

function tagSessionDemo() {
    // Connect to the tag if it is not connected.
    if (!tag.getIsoDep(tagInfo).isTagConnected()) {
        if (!tag.getIsoDep(tagInfo).connectTag()) {
            console.error("tagSession connectTag failed.");
            return;
        }
    }  

    let cmdData = [0x01, 0x02, 0x03, 0x04]; // Change it as required.
    tag.getIsoDep(tagInfo).sendData(cmdData).then((response) => {
    console.info("tagSession sendData Promise response: " + response);
    }).catch((err : BusinessError)=> {
    console.error("tagSession sendData Promise err: " + err);
    });
}
```

### sendData<sup>(deprecated)</sup>

sendData(data: number[], callback: AsyncCallback<number[]>): void

Sends data to this tag. This API uses an asynchronous callback to return the result.

> **NOTE**
> This parameter is supported since API version 7 and deprecated since API version 9. Use [tagSession.transmit](#transmit9-1) instead.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| data | number[] | Yes| Data to send. The data consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|
| callback | AsyncCallback<number[]> | Yes| Callback used to return the response from the tag. The response consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// the following getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

function tagSessionDemo() {
    // Connect to the tag if it is not connected.
    if (!tag.getIsoDep(tagInfo).isTagConnected()) {
        if (!tag.getIsoDep(tagInfo).connectTag()) {
            console.error("tagSession connectTag failed.");
            return;
        }
    }

    let cmdData = [0x01, 0x02, 0x03, 0x04]; // Change it as required.
    tag.getIsoDep(tagInfo).sendData(cmdData, (err, response)=> {
        if (err) {
            console.error("tagSession sendData AsyncCallback err: " + err);
        } else {
            console.info("tagSession sendData AsyncCallback response: " + response);
        }
    });
}
```

### transmit<sup>9+</sup>

transmit(data: number[]): Promise<number[]>

Transmits data to this tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| data | number[] | Yes| Data to send. The data consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise<number[]> | Promise used to return the response from the tag. The response consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
|201 | Permission denied.                 |
|401 | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
|801 | Capability not supported.          |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// the following getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

function tagSessionDemo() {
// Connect to the tag if it is not connected.
    try {
        if (!tag.getIsoDep(tagInfo).isConnected()) {
            tag.getIsoDep(tagInfo).connect();
        }
    } catch (businessError) {
        console.error("tag connect businessError: " + businessError);
        return;
    }

    let cmdData = [0x01, 0x02, 0x03, 0x04]; // Change it as required.
    try {
    tag.getIsoDep(tagInfo).transmit(cmdData).then((response) => {
        console.info("tagSession transmit Promise response: " + response);
    }).catch((err : BusinessError)=> {
        console.error("tagSession transmit Promise err: " + err);
    });
    } catch (businessError) {
        console.error("tag transmit businessError: " + businessError);
        return;
    }
}
```

### transmit<sup>9+</sup>

transmit(data: number[], callback: AsyncCallback<number[]>): void

Transmits data to this tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| data | number[] | Yes| Data to send. The data consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|
| callback | AsyncCallback<number[]> | Yes| Callback used to return the response from the tag. The response consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
|201 | Permission denied.                 |
|401 | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
|801 | Capability not supported.          |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | Tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// tagInfo is an object provided by the NFC service when a tag is dispatched.
// the following getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

function tagSessionDemo() {
    // Connect to the tag if it is not connected.
    try {
        if (!tag.getIsoDep(tagInfo).isConnected()) {
            tag.getIsoDep(tagInfo).connect();
        }
    } catch (businessError) {
        console.error("tag connect businessError: " + businessError);
        return;
    }

    let cmdData = [0x01, 0x02, 0x03, 0x04]; // Change it as required.
    try {
        tag.getIsoDep(tagInfo).transmit(cmdData, (err, response)=> {
            if (err) {
                console.error("tagSession transmit AsyncCallback err: " + err);
            } else {
                console.info("tagSession transmit AsyncCallback response: " + response);
            }
        });
    } catch (businessError) {
        console.error("tag transmit businessError: " + businessError);
        return;
    }
}

```
