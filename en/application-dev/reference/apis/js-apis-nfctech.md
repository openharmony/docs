# nfctech

The **nfctech** module provides APIs for reading and writing tags that use different Near-Field Communication (NFC) technologies.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import tag from '@ohos.nfc.tag';
```

## NfcATag

Provides APIs to access NFC-A (ISO 14443-3A) properties and perform I/O operations on a tag. This class inherits from **[TagSession](js-apis-tagSession.md)**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **NfcATag**.

### NfcATag.getSak

getSak(): number

Obtains the SAK value of this NFC-A tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number  | SAK value obtained. The SAK is a hexadecimal number ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'nfcA' correctly.
let sak = nfcA.getSak();
console.log("nfcA sak: " + sak);
```

### NfcATag.getAtqa

getAtqa(): number[]

Obtains the ATQA value of this NFC-A tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[]  | ATQA value obtained. Each number of the ATQA is a hexadecimal number ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'nfcA' correctly.
let atqa = nfcA.getAtqa();
console.log("nfcA atqa: " + atqa);
```

## NfcBTag

Provides APIs to access NFC-B (ISO 14443-3B) properties and perform I/O operations on a tag. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **NfcBTag**.

### NfcBTag.getRespAppData

getRespAppData(): number[]

Obtains the application data of this NFC-B tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[]  | Application data obtained, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'nfcB' correctly.
let respAppData = nfcB.getRespAppData();
console.log("nfcB respAppData: " + respAppData);
```

### NfcBTag.getRespProtocol

getRespProtocol(): number[]

Obtains the protocol information of this NFC-B tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[]  | Protocol information obtained, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'nfcB' correctly.
let respProtocol = nfcB.getRespProtocol();
console.log("nfcB respProtocol: " + respProtocol);
```

## NfcFTag

Provides APIs to access NFC-F (JIS 6319-4) properties and perform I/O operations on a tag. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **NfcFTag**.

### NfcFTag.getSystemCode

getSystemCode(): number[]

Obtains the system code from this NFC-F tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                           |
| ------------------ | --------------------------|
| number[]  | System code obtained, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'nfcF' correctly.
let systemCode = nfcF.getSystemCode();
console.log("nfcF systemCode: " + systemCode);
```

### NfcFTag.getPmm

getPmm(): number[]

Obtains the PMm (consisting of the IC code and manufacturer parameters) information from this NFC-F tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[]  | PMm information obtained, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'nfcF' correctly.
let pmm = nfcF.getPmm();
console.log("nfcF pmm: " + pmm);
```

## NfcVTag

Provides APIs to access NFC-V (ISO 15693) properties and perform I/O operations on a tag. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **NfcVTag**.

### NfcvTag.getResponseFlags

getResponseFlags(): number

Obtains the response flags from this NFC-V tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Response flags obtained, which consist of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'nfcV' correctly.
let responseFlags = nfcV.getResponseFlags();
console.log("nfcV responseFlags: " + responseFlags);
```

### NfcvTag.getDsfId

getDsfId(): number

Obtains the data storage format identifier (DSFID) from this NFC-V tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | DSFID obtained, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'nfcV' correctly.
let dsfId = nfcV.getDsfId();
console.log("nfcV dsfId: " + dsfId);
```

## IsoDepTag<sup>9+</sup> 

Provides APIs to access ISO-DEP (ISO 14443-4) properties and I/O operations on a tag. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **IsoDepTag**.

### IsoDepTag.getHistoricalBytes<sup>9+</sup>

getHistoricalBytes(): number[]

Obtains the historical bytes for the given tag. This API applies only to the IsoDep cards that use the NFC-A technology.

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[] | Historical bytes obtained, which consist of hexadecimal numbers ranging from **0x00** to **0xFF**. If the IsoDep tag uses the NFC-B technology, **null** will be returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'isoDep' correctly.
let historicalBytes = isoDep.getHistoricalBytes();
console.log("isoDep historicalBytes: " + historicalBytes);
```

### IsoDepTag.getHiLayerResponse<sup>9+</sup>

getHiLayerResponse(): number[]

Obtains the higher-layer response bytes for the given tag. This API applies only to the IsoDep cards that use the NFC-B technology.

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[] | Higher-layer response bytes obtained, which consist of hexadecimal numbers ranging from **0x00** to **0xFF**. If the IsoDep tag uses the NFC-A technology, **null** will be returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'isoDep' correctly.
let hiLayerResponse = isoDep.getHiLayerResponse();
console.log("isoDep hiLayerResponse: " + hiLayerResponse);
```

### IsoDepTag.isExtendedApduSupported<sup>9+</sup>

isExtendedApduSupported(): Promise&lt;boolean&gt;

Checks whether an extended application protocol data unit (APDU) is supported. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise&lt;boolean&gt; | Promise used to return the result. If the extended APDU is supported, **true** is returned; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'isoDep' correctly.

// Connect to the tag if it is not connected.
if (!isoDep.isTagConnected()) {
    if (!isoDep.connectTag()) {
        console.log("isoDep connectTag failed.");
        return;
    }
}

try {
    isoDep.isExtendedApduSupported().then((response) => {
        console.log("isoDep isExtendedApduSupported Promise response: " + response);
    }).catch((err)=> {
        console.log("isoDep isExtendedApduSupported Promise err: " + err);
    });
} catch (busiError) {
    console.log("isoDep isExtendedApduSupported Promise busiError: " + busiError);
}

```

### IsoDepTag.isExtendedApduSupported<sup>9+</sup>

isExtendedApduSupported(callback: AsyncCallback\<boolean>): void

Checks whether an extended APDU is supported. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback invoked to return the result. If the extended APDU is supported, **true** is returned; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'isoDep' correctly.

// Connect to the tag if it is not connected.
if (!isoDep.isTagConnected()) {
    if (!isoDep.connectTag()) {
        console.log("isoDep connectTag failed.");
        return;
    }
}

try {
    isoDep.isExtendedApduSupported((err, response)=> {
        if (err) {
            console.log("isoDep isExtendedApduSupported AsyncCallback err: " + err);
        } else {
            console.log("isoDep isExtendedApduSupported AsyncCallback response: " + response);
        }
    });
} catch (busiError) {
    console.log("isoDep isExtendedApduSupported AsyncCallback busiError: " + busiError);
}
```

## NdefMessage<sup>9+</sup>

### NdefMessage.getNdefRecords<sup>9+</sup>

getNdefRecords(): [tag.NdefRecord](js-apis-nfcTag.md#ndefrecord9)[]

Obtains all NDEF records.

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [tag.NdefRecord](js-apis-nfcTag.md#ndefrecord9)[] | List of NDEF records obtained. For details, see *NFCForum-TS-NDEF_1.0*.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Obtain ndefMessage from tag.ndef.createNdefMessage or ndefTag.getNdefMessage.
// var ndefMessage = tag.ndef.createNdefMessage(...);
// var ndefMessage = ndefTag.getNdefMessage();

let ndefRecords = ndefMessage.getNdefRecords();
console.log("ndef ndefRecords number: " + ndefRecords.length);
```

## NdefTag<sup>9+</sup>

Provides APIs to access the tags in the NFC Data Exchange Format (NDEF). This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **NdefTag**.

### NdefTag.getNdefTagType<sup>9+</sup>

getNdefTagType(): [tag.NfcForumType](js-apis-nfcTag.md#nfcforumtype9)

Obtains the NDEF tag type.

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [tag.NfcForumType](js-apis-nfcTag.md#nfcforumtype9) | NDEF tag type obtained. It can be NFC FORUM TYPE 1, 2, 3, or 4.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'ndefTag' correctly.
let ndefTagType = ndefTag.getNdefTagType();
console.log("ndef ndefTagType: " + ndefTagType);
```

### NdefTag.getNdefMessage<sup>9+</sup>

getNdefMessage(): [NdefMessage](#ndefmessage9)

Obtains the NDEF message from this NDEF tag.

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefMessage](#ndefmessage9)  | NDEF message created. For details, see *NFCForum-TS-NDEF_1.0*.|

**Example**
```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'ndefTag' correctly.
let ndefMessage = ndefTag.getNdefMessage();
console.log("ndef ndefMessage: " + ndefMessage);
```

### NdefTag.isNdefWritable<sup>9+</sup>

isNdefWritable(): boolean;

Check whether this NDEF tag is writable. Before calling the data write API, check whether the write operation is supported.

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean | Promise used to return the result. If the tag is writable, **true** is returned; otherwise, **false** is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'ndefTag' correctly.
var isWritable = ndefTag.isNdefWritable();
console.log("ndef isNdefWritable: " + isWritable);
```

### NdefTag.readNdef<sup>9+</sup>

readNdef(): Promise\<[NdefMessage](#ndefmessage9)>

Reads the NDEF message from this tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<[NdefMessage](#ndefmessage9)> | Promise used to return the message read.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'ndefTag' correctly.

// Connect to the tag if it is not connected.
if (!ndefTag.isTagConnected()) {
    if (!ndefTag.connectTag()) {
        console.log("ndefTag connectTag failed.");
        return;
    }
}

try {
    ndefTag.readNdef().then((ndefmessage) => {
        console.log("ndef readNdef Promise ndefmessage: " + ndefmessage);
    }).catch((err)=> {
        console.log("ndef readNdef Promise err: " + err);
    });
} catch (busiError) {
    console.log("ndef readNdef Promise catched busiError: " + busiError);
}
```

### NdefTag.readNdef<sup>9+</sup>

readNdef(callback: AsyncCallback\<[NdefMessage](#ndefmessage9)>): void

Reads the NDEF message from this tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<[NdefMessage](#ndefmessage9)> | Yes  | Callback invoked to return the NDEF message read.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'ndefTag' correctly.

// Connect to the tag if it is not connected.
if (!ndefTag.isTagConnected()) {
    if (!ndefTag.connectTag()) {
        console.log("ndefTag connectTag failed.");
        return;
    }
}

try {
    ndefTag.readNdef((err, ndefmessage)=> {
        if (err) {
            console.log("ndef readNdef AsyncCallback err: " + err);
        } else {
            console.log("ndef readNdef AsyncCallback ndefmessage: " + ndefmessage);
        }
    });
} catch (busiError) {
    console.log("ndef readNdef AsyncCallback catched busiError: " + busiError);
}
```

### NdefTag.writeNdef<sup>9+</sup>

writeNdef(msg: NdefMessage): Promise\<void>;

Writes an NDEF message to this tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| msg | NdefMessage | Yes  | NDEF message to write.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'ndefTag' correctly.
// NDEF message created from raw data, such as:
let ndefMessage = tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]);  // It must be parsed as NDEF Record.
// or ndefMessage created from tag.ndef.createNdefMessage(ndefRecords: NdefRecord[])

// Connect to the tag if it is not connected.
if (!ndefTag.isTagConnected()) {
    if (!ndefTag.connectTag()) {
        console.log("ndefTag connectTag failed.");
        return;
    }
}

try {
    ndefTag.writeNdef(ndefMessage).then(() => {
        console.log("ndef writeNdef Promise success.");
    }).catch((err)=> {
        console.log("ndef writeNdef err: " + err);
    });
} catch (busiError) {
    console.log("ndef writeNdef Promise catch busiError: " + busiError);
}
```

### NdefTag.writeNdef<sup>9+</sup>

writeNdef(msg: [NdefMessage](#ndefmessage9), callback: AsyncCallback\<void>): void

Writes an NDEF message to this tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| msg | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'ndefTag' correctly.
// NDEF message created from raw data, such as:
let ndefMessage = tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]);  // It must be parsed as NDEF Record.
// or ndefMessage created from tag.ndef.createNdefMessage(ndefRecords: NdefRecord[])

// Connect to the tag if it is not connected.
if (!ndefTag.isTagConnected()) {
    if (!ndefTag.connectTag()) {
        console.log("ndefTag connectTag failed.");
        return;
    }
}

try {
    ndefTag.writeNdef(ndefMessage, (err)=> {
        if (err) {
            console.log("ndef writeNdef AsyncCallback err: " + err);
        } else {
            console.log("ndef writeNdef AsyncCallback success.");
        }
    });
} catch (busiError) {
    console.log("ndef writeNdef AsyncCallback catch busiError: " + busiError);
}
```

### NdefTag.canSetReadOnly<sup>9+</sup>

canSetReadOnly(): boolean

Checks whether this NDEF tag can be set to read-only.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean| Returns **true** if the tag can be set to read-only; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'ndefTag' correctly.
var canSetReadOnly = ndefTag.canSetReadOnly();
console.log("ndef canSetReadOnly: " + canSetReadOnly);
```

### NdefTag.setReadOnly<sup>9+</sup>

setReadOnly(): Promise\<void>

Sets this NDEF tag to read-only. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'ndefTag' correctly.

// Connect to the tag if it is not connected.
if (!ndefTag.isTagConnected()) {
    if (!ndefTag.connectTag()) {
        console.log("ndefTag connectTag failed.");
        return;
    }
}

try {
    ndefTag.setReadOnly().then(() => {
        console.log("ndef setReadOnly Promise success.");
    }).catch((err)=> {
        console.log("ndef setReadOnly Promise err: " + err);
    });
} catch (busiError) {
    console.log("ndef setReadOnly Promise catch busiError: " + busiError);
}
```

### NdefTag.setReadOnly<sup>9+</sup>

setReadOnly(callback: AsyncCallback\<void>): void

Sets this NDEF tag to read-only. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'ndefTag' correctly.

// Connect to the tag if it is not connected.
if (!ndefTag.isTagConnected()) {
    if (!ndefTag.connectTag()) {
        console.log("ndefTag connectTag failed.");
        return;
    }
}

try {
    ndefTag.setReadOnly((err)=> {
        if (err) {
            console.log("ndef setReadOnly AsyncCallback err: " + err);
        } else {
            console.log("ndef setReadOnly AsyncCallback success.");
        }
    });
} catch (busiError) {
    console.log("ndef setReadOnly AsyncCallback catch busiError: " + busiError);
}
```

### NdefTag.getNdefTagTypeString<sup>9+</sup>

getNdefTagTypeString(type: [tag.NfcForumType](js-apis-nfcTag.md#nfcforumtype9)): string

Converts an NFC Forum Type tag to a string defined in the NFC Forum.

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| type | [tag.NfcForumType](js-apis-nfcTag.md#nfcforumtype9) | Yes  | NDEF tag type. It can be NFC FORUM type 1, 2, 3, or 4.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| string | Byte array obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'ndefTag' correctly.

try {
    let ndefTypeString = ndefTag.getNdefTagTypeString(tag.NFC_FORUM_TYPE_1);
    console.log("ndef ndefTypeString: " + ndefTypeString);
} catch (busiError) {
    console.log("ndef getNdefTagTypeString catch busiError: " + busiError);
}
```

## MifareClassicTag<sup>9+</sup>

Provides APIs to access MIFARE Classic properties and perform I/O operations on a tag. This class inherits from [TagSession](js-apis-tagSession.md).

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **MifareClassicTag**.

### MifareClassicTag.authenticateSector<sup>9+</sup>

authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean): Promise\<void>

Authenticates a sector using a key. The sector can be accessed only after the authentication is successful. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | Yes  | Index of the sector to authenticate. The sector indexes start from **0**.|
| key | number[]| Yes  | Key (6 bytes) used for sector authentication.|
| isKeyA | boolean | Yes  | Whether the key is key A. The value **true** indicates key A, and **false** indicates key B.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.

// Connect to the tag if it is not connected.
if (!mifareClassic.isTagConnected()) {
    if (!mifareClassic.connectTag()) {
        console.log("mifareClassic connectTag failed.");
        return;
    }
}

try {
    let sectorIndex = 1; // Change it as required.
    let key = [0x01, 0x02, 0x03, 0x04, 0x05, 0x06]  // The key must be of 6 bytes.
    mifareClassic.authenticateSector(sectorIndex, key, true).then(() => {
        console.log("mifareClassic authenticateSector Promise success.");
    }).catch((err)=> {
        console.log("mifareClassic authenticateSector Promise err: " + err);
    });
} catch (busiError) {
    console.log("mifareClassic authenticateSector Promise catch busiError: " + busiError);
}
```

### MifareClassicTag.authenticateSector<sup>9+</sup>

authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback\<void>): void

Authenticates a sector using a key. The sector can be accessed only after the authentication is successful. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | Yes  | Index of the sector to authenticate. The sector indexes start from **0**.|
| key | number[]| Yes  | Key (6 bytes) used for sector authentication.|
| isKeyA | boolean | Yes  | Whether the key is key A. The value **true** indicates key A, and **false** indicates key B.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**
```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.

// Connect to the tag if it is not connected.
if (!mifareClassic.isTagConnected()) {
    if (!mifareClassic.connectTag()) {
        console.log("mifareClassic connectTag failed.");
        return;
    }
}

try {
    let sectorIndex = 1; // Change it as required.
    let key = [0x01, 0x02, 0x03, 0x04, 0x05, 0x06]  // The key must be of 6 bytes.
    mifareClassic.authenticateSector(sectorIndex, key, true, (err)=> {
        if (err) {
            console.log("mifareClassic authenticateSector AsyncCallback err: " + err);
        } else {
            console.log("mifareClassic authenticateSector AsyncCallback success.");
        }
    });
} catch (busiError) {
    console.log("mifareClassic authenticateSector AsyncCallback catch busiError: " + busiError);
}
```

### MifareClassicTag.readSingleBlock<sup>9+</sup>

readSingleBlock(blockIndex: number): Promise\<number[]>

Reads a block (16 bytes) on this tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to read. The block indexes start from **0**.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number[]> | Promise used to return the block data read.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.

// Connect to the tag if it is not connected.
if (!mifareClassic.isTagConnected()) {
    if (!mifareClassic.connectTag()) {
        console.log("mifareClassic connectTag failed.");
        return;
    }
}

try {
    let blockIndex = 1; // Change it as required.
    mifareClassic.readSingleBlock(blockIndex).then((data) => {
        console.log("mifareClassic readSingleBlock Promise data: " + data);
    }).catch((err)=> {
        console.log("mifareClassic readSingleBlock Promise err: " + err);
    });
} catch (busiError) {
    console.log("mifareClassic readSingleBlock Promise catch busiError: " + busiError);
}
```

### MifareClassicTag.readSingleBlock<sup>9+</sup>

readSingleBlock(blockIndex: number, callback: AsyncCallback\<number[]>): void

Reads a block (16 bytes) on this tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to read. The block indexes start from **0**.|
| callback | AsyncCallback\<number[]> | Yes  | Callback invoked to return the block read.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.

// Connect to the tag if it is not connected.
if (!mifareClassic.isTagConnected()) {
    if (!mifareClassic.connectTag()) {
        console.log("mifareClassic connectTag failed.");
        return;
    }
}

try {
    let blockIndex = 1; // Change it as required.
    mifareClassic.readSingleBlock(blockIndex, (err, data)=> {
        if (err) {
            console.log("mifareClassic readSingleBlock AsyncCallback err: " + err);
        } else {
            console.log("mifareClassic readSingleBlock AsyncCallback data: " + data);
        }
    });
} catch (busiError) {
    console.log("mifareClassic readSingleBlock AsyncCallback catch busiError: " + busiError);
}
```

### MifareClassicTag.writeSingleBlock<sup>9+</sup>

writeSingleBlock(blockIndex: number, data: number[]): Promise\<void>

Writes data to a block on this tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the target block. The block indexes start from **0**.|
| data | number[] | Yes  | 16-byte data to write.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.

// Connect to the tag if it is not connected.
if (!mifareClassic.isTagConnected()) {
    if (!mifareClassic.connectTag()) {
        console.log("mifareClassic connectTag failed.");
        return;
    }
}

try {
    let blockIndex = 1; // Change it as required.
    let rawData = [0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A,
        0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10]; // MUST be 16 bytes, change it to be correct data.
    mifareClassic.writeSingleBlock(blockIndex, rawData).then(() => {
        console.log("mifareClassic writeSingleBlock Promise success.");
    }).catch((err)=> {
        console.log("mifareClassic writeSingleBlock Promise err: " + err);
    });
} catch (busiError) {
    console.log("mifareClassic writeSingleBlock Promise catch busiError: " + busiError);
}
```

### MifareClassicTag.writeSingleBlock<sup>9+</sup>

writeSingleBlock(blockIndex: number, data: number[], callback: AsyncCallback\<void>): void

Writes data to a block on this tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the target block. The block indexes start from **0**.|
| data | number[] | Yes  | 16-byte data to write.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.

// Connect to the tag if it is not connected.
if (!mifareClassic.isTagConnected()) {
    if (!mifareClassic.connectTag()) {
        console.log("mifareClassic connectTag failed.");
        return;
    }
}

try {
    let blockIndex = 1; // Change it as required.
    let rawData = [0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A,
        0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10]; // MUST be 16 bytes, change it to be correct data.
    mifareClassic.writeSingleBlock(blockIndex, rawData, (err)=> {
        if (err) {
            console.log("mifareClassic writeSingleBlock AsyncCallback err: " + err);
        } else {
            console.log("mifareClassic writeSingleBlock AsyncCallback success.");
        }
    });
} catch (busiError) {
    console.log("mifareClassic writeSingleBlock AsyncCallback catch busiError: " + busiError);
}
```

### MifareClassicTag.incrementBlock<sup>9+</sup>

incrementBlock(blockIndex: number, value: number): Promise\<void>

Increments a block with data. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to increment. The block indexes start from **0**.|
| value | number | Yes  | Block data to increment. The value cannot be a negative number.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.

// Connect to the tag if it is not connected.
if (!mifareClassic.isTagConnected()) {
    if (!mifareClassic.connectTag()) {
        console.log("mifareClassic connectTag failed.");
        return;
    }
}

try {
    let blockIndex = 1; // Change it as required.
    let value = 0x20; // Change it as required.
    mifareClassic.incrementBlock(blockIndex, value).then(() => {
        console.log("mifareClassic incrementBlock Promise success.");
    }).catch((err)=> {
        console.log("mifareClassic incrementBlock Promise err: " + err);
    });
} catch (busiError) {
    console.log("mifareClassic incrementBlock Promise catch busiError: " + busiError);
}
```

### MifareClassicTag.incrementBlock<sup>9+</sup>

incrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void

Increments a block with data. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to increment. The block indexes start from **0**.|
| value | number | Yes  | Block data to increment. The value cannot be a negative number.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.

// Connect to the tag if it is not connected.
if (!mifareClassic.isTagConnected()) {
    if (!mifareClassic.connectTag()) {
        console.log("mifareClassic connectTag failed.");
        return;
    }
}

try {
    let blockIndex = 1; // Change it as required.
    let value = 0x20; // Change it as required.
    mifareClassic.incrementBlock(blockIndex, value, (err)=> {
        if (err) {
            console.log("mifareClassic incrementBlock AsyncCallback err: " + err);
        } else {
            console.log("mifareClassic incrementBlock AsyncCallback success.");
        }
    });
} catch (busiError) {
    console.log("mifareClassic incrementBlock AsyncCallback catch busiError: " + busiError);
}
```

### MifareClassicTag.decrementBlock<sup>9+</sup>

decrementBlock(blockIndex: number, value: number): Promise\<void>

Decrements a block. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to decrement. The block indexes start from **0**.|
| value | number | Yes  | Block data to decrement. The value cannot be a negative number.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.

// Connect to the tag if it is not connected.
if (!mifareClassic.isTagConnected()) {
    if (!mifareClassic.connectTag()) {
        console.log("mifareClassic connectTag failed.");
        return;
    }
}

try {
    let blockIndex = 1; // Change it as required.
    let value = 0x20; // Change it as required.
    mifareClassic.decrementBlock(blockIndex, value).then(() => {
        console.log("mifareClassic decrementBlock Promise success.");
    }).catch((err)=> {
        console.log("mifareClassic decrementBlock Promise err: " + err);
    });
} catch (busiError) {
    console.log("mifareClassic decrementBlock Promise catch busiError: " + busiError);
}
```

### MifareClassicTag.decrementBlock<sup>9+</sup>

decrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void

Decrements a block. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to decrement. The block indexes start from **0**.|
| value | number | Yes  | Block data to decrement. The value cannot be a negative number.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.

// Connect to the tag if it is not connected.
if (!mifareClassic.isTagConnected()) {
    if (!mifareClassic.connectTag()) {
        console.log("mifareClassic connectTag failed.");
        return;
    }
}

try {
    let blockIndex = 1; // Change it as required.
    let value = 0x20; // Change it as required.
    mifareClassic.decrementBlock(blockIndex, value, (err)=> {
        if (err) {
            console.log("mifareClassic decrementBlock AsyncCallback err: " + err);
        } else {
            console.log("mifareClassic decrementBlock AsyncCallback success.");
        }
    });
} catch (busiError) {
    console.log("mifareClassic decrementBlock AsyncCallback catch busiError: " + busiError);
}
```

### MifareClassicTag.transferToBlock<sup>9+</sup>

transferToBlock(blockIndex: number): Promise\<void>

Transfers data from the temporary register to a block. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes | Index of the destination block. The value starts form **0**.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.

// Connect to the tag if it is not connected.
if (!mifareClassic.isTagConnected()) {
    if (!mifareClassic.connectTag()) {
        console.log("mifareClassic connectTag failed.");
        return;
    }
}

try {
    let blockIndex = 1; // Change it as required.
    mifareClassic.transferToBlock(blockIndex).then(() => {
        console.log("mifareClassic transferToBlock Promise success.");
    }).catch((err)=> {
        console.log("mifareClassic transferToBlock Promise err: " + err);
    });
} catch (busiError) {
    console.log("mifareClassic transferToBlock Promise catch busiError: " + busiError);
}
```

### MifareClassicTag.transferToBlock<sup>9+</sup>

transferToBlock(blockIndex: number, callback: AsyncCallback\<void>): void

Transfers data from the temporary register to a block. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the destination block. The value starts form **0**.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.

// Connect to the tag if it is not connected.
if (!mifareClassic.isTagConnected()) {
    if (!mifareClassic.connectTag()) {
        console.log("mifareClassic connectTag failed.");
        return;
    }
}

try {
    let blockIndex = 1; // Change it as required.
    mifareClassic.transferToBlock(blockIndex, (err)=> {
        if (err) {
            console.log("mifareClassic transferToBlock AsyncCallback err: " + err);
        } else {
            console.log("mifareClassic transferToBlock AsyncCallback success.");
        }
    });
} catch (busiError) {
    console.log("mifareClassic transferToBlock AsyncCallback catch busiError: " + busiError);
}
```

### MifareClassicTag.restoreFromBlock<sup>9+</sup>

restoreFromBlock(blockIndex: number): Promise\<void>

Restores data in the temporary register from a block. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the target block. The value starts form **0**.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.

// Connect to the tag if it is not connected.
if (!mifareClassic.isTagConnected()) {
    if (!mifareClassic.connectTag()) {
        console.log("mifareClassic connectTag failed.");
        return;
    }
}

try {
    let blockIndex = 1; // Change it as required.
    mifareClassic.restoreFromBlock(blockIndex).then(() => {
        console.log("mifareClassic restoreFromBlock Promise success.");
    }).catch((err)=> {
        console.log("mifareClassic restoreFromBlock Promise err: " + err);
    });
} catch (busiError) {
    console.log("mifareClassic restoreFromBlock Promise catch busiError: " + busiError);
}
```

### MifareClassicTag.restoreFromBlock<sup>9+</sup>

restoreFromBlock(blockIndex: number, callback: AsyncCallback\<void>): void

Restores data in the temporary register from a block. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the target block. The value starts form **0**.|
| callback | AsyncCallback\<void> | Yes  | Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.

// Connect to the tag if it is not connected.
if (!mifareClassic.isTagConnected()) {
    if (!mifareClassic.connectTag()) {
        console.log("mifareClassic connectTag failed.");
        return;
    }
}

try {
    let blockIndex = 1; // Change it as required.
    mifareClassic.restoreFromBlock(blockIndex, (err)=> {
        if (err) {
            console.log("mifareClassic restoreFromBlock AsyncCallback err: " + err);
        } else {
            console.log("mifareClassic restoreFromBlock AsyncCallback success.");
        }
    });
} catch (busiError) {
    console.log("mifareClassic restoreFromBlock AsyncCallback catch busiError: " + busiError);
}
```

### MifareClassicTag.getSectorCount<sup>9+</sup>

getSectorCount(): number

Obtains the number of sectors in this MIFARE Classic tag.

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Number of sectors obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.
let sectorCount = mifareClassic.getSectorCount();
console.log("mifareClassic sectorCount: " + sectorCount);
```

### MifareClassicTag.getBlockCountInSector<sup>9+</sup>

getBlockCountInSector(sectorIndex: number): number

Obtains the number of blocks in a sector.

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | Yes  | Index of the target sector. The sector indexes start from **0**.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Number of blocks obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.

try {
    let sectorIndex = 1; // Change it as required.
    let blockCnt = mifareClassic.getBlockCountInSector(sectorIndex);
    console.log("mifareClassic blockCnt: " + blockCnt);
} catch (busiError) {
    console.log("mifareClassic getBlockCountInSector catch busiError: " + busiError);
}
```

### MifareClassicTag.getType<sup>9+</sup>

getType(): [tag.MifareClassicType](js-apis-nfcTag.md#mifareclassictype9)

Obtains the type of this MIFARE Classic tag.

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [tag.MifareClassicType](js-apis-nfcTag.md#mifareclassictype9) | Type of the MIFARE Classic tag obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.
let getType = mifareClassic.getType();
console.log("mifareClassic getType: " + getType);
```

### MifareClassicTag.getTagSize<sup>9+</sup>

getTagSize(): number

Obtains the size of this tag. For details, see [MifareClassicSize](js-apis-nfcTag.md#mifareclassicsize9).

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Tag size obtained, in bytes. For details, see [MifareClassicSize](js-apis-nfcTag.md#mifareclassicsize9).|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.
let tagSize = mifareClassic.getTagSize();
console.log("mifareClassic tagSize: " + tagSize);
```

### MifareClassicTag.isEmulatedTag<sup>9+</sup>

isEmulatedTag(): boolean

Checks whether it is an emulated tag.

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean |Returns **true** if the tag is an emulated tag; returns **false** otherwise.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.
let isEmulatedTag = mifareClassic.isEmulatedTag();
console.log("mifareClassic isEmulatedTag: " + isEmulatedTag);
```

### MifareClassicTag.getBlockIndex<sup>9+</sup>

getBlockIndex(sectorIndex: number): number

Obtains the index of the first block in a sector.

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | Yes  | Index of the target sector. The sector indexes start from **0**.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Index of the first block obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.

try {
    let sectorIndex = 1; // Change it as required.
    let blockIndex = mifareClassic.getBlockIndex(sectorIndex);
    console.log("mifareClassic blockIndex: " + blockIndex);
} catch (busiError) {
    console.log("mifareClassic getBlockIndex catch busiError: " + busiError);
}
```

### MifareClassicTag.getSectorIndex<sup>9+</sup>

getSectorIndex(blockIndex: number): number

Obtains the index of a sector that holds the specified block.

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes| Index of the block. The block indexes start from **0**.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Index of the sector obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareClassic' correctly.

try {
    let blockIndex = 1; // Change it as required.
    let sectorIndex = mifareClassic.getSectorIndex(blockIndex);
    console.log("mifareClassic sectorIndex: " + sectorIndex);
} catch (busiError) {
    console.log("mifareClassic getSectorIndex catch busiError: " + busiError);
}
```

## MifareUltralightTag<sup>9+</sup>

Provides APIs to access MIFARE Ultralight properties and perform I/O operations on a tag. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **MifareUltralightTag**.

### MifareUltralightTag.readMultiplePages<sup>9+</sup>

readMultiplePages(pageIndex: number): Promise\<number[]>

Reads four pages (4 bytes per page) from this tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | ------------------------------ |
| pageIndex | number | Yes  | Index of the first page to read. The page indexes start from **0**.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number[]> | Promise used to return the data read, which is 16 bytes in total.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js

import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareUltralight' correctly.

// Connect to the tag if it is not connected.
if (!mifareUltralight.isTagConnected()) {
    if (!mifareUltralight.connectTag()) {
        console.log("mifareUltralight connectTag failed.");
        return;
    }
}

try {
    let pageIndex = 1; // Change it as required.
    mifareUltralight.readMultiplePages(pageIndex).then((data) => {
        console.log("mifareUltralight readMultiplePages Promise data = " + data);
    }).catch((err)=> {
        console.log("mifareUltralight readMultiplePages Promise err: " + err);
    });
} catch (busiError) {
    console.log("mifareUltralight readMultiplePages Promise catch busiError: " + busiError);
}
```

### MifareUltralightTag.readMultiplePages<sup>9+</sup>

readMultiplePages(pageIndex: number, callback: AsyncCallback\<number[]>): void

Reads four pages (4 bytes per page) from this tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| pageIndex | number | Yes  | Index of the first page to read. The page indexes start from **0**.|
| callback | AsyncCallback\<number[]> | Yes  | Callback invoked to return the data read, which is 16 bytes in total.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareUltralight' correctly.

// Connect to the tag if it is not connected.
if (!mifareUltralight.isTagConnected()) {
    if (!mifareUltralight.connectTag()) {
        console.log("mifareUltralight connectTag failed.");
        return;
    }
}

try {
    let pageIndex = 1; // Change it as required.
    mifareUltralight.readMultiplePages(pageIndex, (err, data)=> {
        if (err) {
            console.log("mifareUltralight readMultiplePages AsyncCallback err: " + err);
        } else {
            console.log("mifareUltralight readMultiplePages AsyncCallback data: " + data);
        }
    });
} catch (busiError) {
    console.log("mifareUltralight readMultiplePages AsyncCallback catch busiError: " + busiError);
}
```

### MifareUltralightTag.writeSinglePage<sup>9+</sup>

writeSinglePage(pageIndex: number, data: number[]): Promise\<void>

Writes one page (4 bytes) of data to this tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| pageIndex | number | Yes  | Index of the page to write. The page indexes start from **0**.|
| data | number[] | Yes  | 4-byte data to write.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareUltralight' correctly.

// Connect to the tag if it is not connected.
if (!mifareUltralight.isTagConnected()) {
    if (!mifareUltralight.connectTag()) {
        console.log("mifareUltralight connectTag failed.");
        return;
    }
}

try {
    let pageIndex = 1; // Change it as required.
    let rawData = [0x01, 0x02, 0x03, 0x04]; // MUST be 4 bytes, change it to be correct raw data.
    mifareUltralight.writeSinglePage(pageIndex, rawData).then(() => {
        console.log("mifareUltralight writeSinglePage Promise success.");
    }).catch((err)=> {
        console.log("mifareUltralight writeSinglePage Promise err: " + err);
    });
} catch (busiError) {
    console.log("mifareUltralight writeSinglePage Promise catch busiError: " + busiError);
}
```

### MifareUltralightTag.writeSinglePage<sup>9+</sup>

writeSinglePage(pageIndex: number, data: number[], callback: AsyncCallback\<void>): void

Writes one page (4 bytes) of data to this tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                    |
| -------- | ----------------------- | ---- | ------------------------ |
| pageIndex | number | Yes  | Index of the page to write. The page indexes start from **0**.|
| data | number[] | Yes  | 4-byte data to write.|
| callback|AsyncCallback\<void> |Yes| Callback invoked to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareUltralight' correctly.

// Connect to the tag if it is not connected.
if (!mifareUltralight.isTagConnected()) {
    if (!mifareUltralight.connectTag()) {
        console.log("mifareUltralight connectTag failed.");
        return;
    }
}

try {
    let pageIndex = 1; // Change it as required.
    let rawData = [0x01, 0x02, 0x03, 0x04]; // MUST be 4 bytes, change it to be correct raw data.
    mifareUltralight.writeSinglePage(pageIndex, rawData, (err)=> {
        if (err) {
            console.log("mifareUltralight writeSinglePage AsyncCallback err: " + err);
        } else {
            console.log("mifareUltralight writeSinglePage AsyncCallback success.");
        }
    });
} catch (busiError) {
    console.log("mifareUltralight writeSinglePage AsyncCallback catch busiError: " + busiError);
}
```

### MifareUltralightTag.getType<sup>9+</sup>

getType(): [tag.MifareUltralightType](js-apis-nfcTag.md#mifareultralighttype9)

Obtains the type of this MIFARE Ultralight tag.

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [tag.MifareUltralightType](js-apis-nfcTag.md#mifareultralighttype9) | Type of the MIFARE Ultralight tag obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'mifareUltralight' correctly.
let getType = mifareClassic.getType();
console.log("mifareUltralight getType: " + getType);
```

## NdefFormatableTag<sup>9+</sup>

Provides APIs for formatting NDEF formattable tags. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **NdefFormatableTag**.

### NdefFormatableTag.format<sup>9+</sup>

format(message: [NdefMessage](#ndefmessage9)): Promise\<void>

Formats this tag as an NDEF tag, and writes an NDEF message to it. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write. If this parameter is **null**, the tag is formatted only (no data will be written).|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'ndefFormatable' correctly.

// Connect to the tag if it is not connected.
if (!ndefFormatable.isTagConnected()) {
    if (!ndefFormatable.connectTag()) {
        console.log("ndefFormatable connectTag failed.");
        return;
    }
}

try {
    // NDEF message created from raw data, such as:
    let ndefMessage = tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]);  // It must be parsed as NDEF Record.
    // or ndefMessage created from tag.ndef.createNdefMessage(ndefRecords: NdefRecord[])

    ndefFormatable.format(ndefMessage).then(() => {
        console.log("ndefFormatable format Promise success.");
    }).catch((err)=> {
        console.log("ndefFormatable format Promise err: " + err);
    });
} catch (busiError) {
    console.log("ndefFormatable format Promise catch busiError: " + busiError);
}
```

### NdefFormatableTag.format<sup>9+</sup>

format(message: [NdefMessage](#ndefmessage9), callback: AsyncCallback\<void>): void

Formats this tag as an NDEF tag, and writes an NDEF message to it. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write when the formatting is successful. If this parameter is **null**, the tag is formatted only (no data will be written).|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| callback: AsyncCallback\<void> | Callback invoked to return the result.|


**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'ndefFormatable' correctly.

// Connect to the tag if it is not connected.
if (!ndefFormatable.isTagConnected()) {
    if (!ndefFormatable.connectTag()) {
        console.log("ndefFormatable connectTag failed.");
        return;
    }
}

try {
    // NDEF message created from raw data, such as:
    let ndefMessage = tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]);  // It must be parsed as NDEF Record.
    // or ndefMessage created from tag.ndef.createNdefMessage(ndefRecords: NdefRecord[])

    ndefFormatable.format(ndefMessage, (err)=> {
        if (err) {
            console.log("ndefFormatable format AsyncCallback err: " + err);
        } else {
            console.log("ndefFormatable format AsyncCallback success.");
        }
    });
} catch (busiError) {
    console.log("ndefFormatable format AsyncCallback catch busiError: " + busiError);
}
```

### NdefFormatableTag.formatReadOnly<sup>9+</sup>

formatReadOnly(message: [NdefMessage](#ndefmessage9)): Promise\<void>

Formats this tag as an NDEF tag, writes an NDEF message to it, and then sets the tag to read-only. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write. If this parameter is **null**, the tag is formatted only (no data will be written).|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'ndefFormatable' correctly.

// Connect to the tag if it is not connected.
if (!ndefFormatable.isTagConnected()) {
    if (!ndefFormatable.connectTag()) {
        console.log("ndefFormatable connectTag failed.");
        return;
    }
}

try {
    // NDEF message created from raw data, such as:
    let ndefMessage = tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]);  // It must be parsed as NDEF Record.
    // or ndefMessage created from tag.ndef.createNdefMessage(ndefRecords: NdefRecord[])

    ndefFormatable.formatReadOnly(ndefMessage).then(() => {
        console.log("ndefFormatable formatReadOnly Promise success.");
    }).catch((err)=> {
        console.log("ndefFormatable formatReadOnly Promise err: " + err);
    });
} catch (busiError) {
    console.log("ndefFormatable formatReadOnly Promise catch busiError: " + busiError);
}
```

### NdefFormatableTag.formatReadOnly<sup>9+</sup>

formatReadOnly(message: [NdefMessage](#ndefmessage9), callback: AsyncCallback\<void>): void

Formats this tag as an NDEF tag, writes an NDEF message to the NDEF tag, and then sets the tag to read-only. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write. If this parameter is **null**, the tag is formatted only (no data will be written).|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| callback: AsyncCallback\<void> | Callback invoked to return the result.|


**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' in 'js-apis-nfcTag.md' has obtained 'ndefFormatable' correctly.

// Connect to the tag if it is not connected.
if (!ndefFormatable.isTagConnected()) {
    if (!ndefFormatable.connectTag()) {
        console.log("ndefFormatable connectTag failed.");
        return;
    }
}

try {
    // NDEF message created from raw data, such as:
    let ndefMessage = tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]);  // It must be parsed as NDEF Record.
    // or ndefMessage created from tag.ndef.createNdefMessage(ndefRecords: NdefRecord[])

    ndefFormatable.formatReadOnly(ndefMessage, (err)=> {
        if (err) {
            console.log("ndefFormatable formatReadOnly AsyncCallback err: " + err);
        } else {
            console.log("ndefFormatable formatReadOnly AsyncCallback success.");
        }
    });
} catch (busiError) {
    console.log("ndefFormatable formatReadOnly AsyncCallback catch busiError: " + busiError);
}
```
