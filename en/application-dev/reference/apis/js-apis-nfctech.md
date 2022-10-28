# NFC Tag Technologies

The **nfctech** module provides APIs for reading and writing tags that use different Near-Field Communication (NFC) technologies.

> **NOTE**
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## **Modules to Import**

```js
import tag from '@ohos.nfc.tag';
```

## NfcATag

Provides access to NFC-A (ISO 14443-3A) properties and I/O operations. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique interfaces of **NfcATag**.

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

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'nfcA' correctly.

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

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'nfcA' correctly.
let atqa = nfcA.getAtqa();
console.log("nfcA atqa: " + atqa);
```

## NfcBTag

Provides access to NFC-B (ISO 14443-3B) properties and I/O operations. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique interfaces of **NfcBTag**.

### NfcBTag.getRespAppData

getRespAppData(): number[]

Obtains the application data of this NFC-B tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[]  | Application data obtained. Each number in the return result is a hexadecimal number ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'nfcB' correctly.
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
| number[]  | Protocol information obtained. Each number in the return result is a hexadecimal number ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'nfcB' correctly.
let respProtocol = nfcB.getRespProtocol();
console.log("nfcB respProtocol: " + respProtocol);
```

## NfcFTag

Provides access to NFC-F (JIS 6319-4) properties and I/O operations. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique interfaces of **NfcFTag**.

### NfcFTag.getSystemCode

getSystemCode(): number[]

Obtains the system code from this NFC-F tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                           |
| ------------------ | --------------------------|
| number[]  | System code obtained. Each number in the system code is a hexadecimal number ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'nfcF' correctly.
let systemCode = nfcF.getSystemCode();
console.log("nfcF systemCode: " + systemCode);
```

### NfcFTag.getPmm

getPmm(): number[]

Obtains the PMm (consisting of the IC code and manufacturer parameters) information from this NFC-F tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[]  | PMm information obtained. Each number in the return result is a hexadecimal number ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'nfcF' correctly.
let pmm = nfcF.getPmm();
console.log("nfcF pmm: " + pmm);
```

## NfcVTag

Provides access to NFC-V (ISO 15693) properties and I/O operations. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique interfaces of **NfcVTag**.

### NfcvTag.getResponseFlags

getResponseFlags(): number

Obtains the response flags from this NFC-V tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Response flags obtained. The value is a hexadecimal number ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'nfcV' correctly.
let responseFlags = nfcV.getResponseFlags();
console.log("nfcV responseFlags: " + responseFlags);
```

### NfcvTag.getDsfId

getDsfId(): number

Obtains the data storage format identifier (DSFID) from this NFC-V tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | DSFID obtained. The value is a hexadecimal number ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'nfcV' correctly.
let dsfId = nfcV.getDsfId();
console.log("nfcV dsfId: " + dsfId);
```

## IsoDepTag<sup>9+</sup> 

Provides access to ISO-DEP (ISO 14443-4) properties and I/O operations. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique interfaces of **IsoDepTag**.

### IsoDepTag.getHistoricalBytes<sup>9+</sup>

getHistoricalBytes(): number[]

Obtains the historical bytes of this tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[] | Historical bytes obtained. Each number in the return result is a hexadecimal number ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'isoDep' correctly.
let historicalBytes = isoDep.getHistoricalBytes();
console.log("isoDep historicalBytes: " + historicalBytes);
```

### IsoDepTag.getHiLayerResponse<sup>9+</sup>

getHiLayerResponse(): number[]

Obtains the HiLayer response of this tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[] | HiLayer response obtained. Each number in the return result is a hexadecimal number ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'isoDep' correctly.
let hiLayerResponse = isoDep.getHiLayerResponse();
console.log("isoDep hiLayerResponse: " + hiLayerResponse);
```

### IsoDepTag.isExtendedApduSupported<sup>9+</sup>

isExtendedApduSupported(): Promise&lt;boolean&gt;

Checks whether an extended application protocol data unit (APDU) is supported. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise&lt;boolean&gt; | Promise used to return the result. If the extended APDU is supported, **true** is returned; otherwise, **false** is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'isoDep' correctly.
isoDep.isExtendedApduSupported()
    .then((data) => {
        console.log("isoDep isExtendedApduSupported data: " + data);
    }).catch((err)=> {
        console.log("isoDep isExtendedApduSupported err: " + err);
    });
```

### IsoDepTag.isExtendedApduSupported<sup>9+</sup>

isExtendedApduSupported(callback: AsyncCallback\<boolean>): void

Checks whether an extended APDU is supported. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback invoked to return the result. If the extended APDU is supported, **true** is returned; otherwise, **false** is returned.|

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'isoDep' correctly.
isoDep.isExtendedApduSupported((err, data)=> {
    if (err) {
        console.log("isoDep isExtendedApduSupported err: " + err);
    } else {
        console.log("isoDep isExtendedApduSupported data: " + data);
    }
});
```

## NdefTag<sup>9+</sup>

Provides access to the tags in the NFC Data Exchange Format (NDEF). This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique interfaces of **NdefTag**.

### NdefTag.createNdefMessage<sup>9+</sup>

createNdefMessage(data: number[]): [NdefMessage](#ndefmessage9)

Creates an NDEF message using raw bytes.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| data | number[] | Yes| Raw bytes used to create the message. Each number is a hexadecimal number ranging from **0x00** to **0xFF**.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefMessage](#ndefmessage9) | NDEF message created. For details, see *NFCForum-TS-NDEF_1.0*.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
let rawData = [0x00, 0xa4, 0x04, ......]; // change the raw data bytes tobe correct.
let ndefMessage = ndef.createNdefMessage(rawData);
console.log("ndef ndefMessage: " + ndefMessage);
```

## NdefMessage<sup>9+</sup>

### NdefMessage.getNdefRecords<sup>9+</sup>

getNdefRecords(): [NdefRecord](js-apis-nfcTag.md#ndefrecord9)[ ]

Obtains all NDEF records.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefRecord](js-apis-nfcTag.md#ndefrecord9)[ ] | List of NDEF records obtained. For details, see *NFCForum-TS-NDEF_1.0*.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
let ndefRecords = ndef.getNdefRecords();
console.log("ndef ndefRecords number: " + ndefRecords.length);
```

### NdefTag.createNdefMessage<sup>9+</sup>

createNdefMessage(ndefRecords: NdefRecord[]): [NdefMessage](#ndefmessage9)

Creates an NDEF message using the NDEF records.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| ndefRecords | [NdefRecord](js-apis-nfcTag.md#ndefrecord9)[] | Yes| NDEF records used to create the NDEF message. For details, see *NFCForum-TS-NDEF_1.0*.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefMessage](#ndefmessage9) | NDEF message created. For details, see *NFCForum-TS-NDEF_1.0*.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
let ndefRecords = [
    // record format: tnf, rtdType, id, payload
    // 1st record:
    {tnf: 0x01, rtdType: [0x54], id: [0x01, 0x02, ...], payload: [0x00, 0xa4, 0x04, ...]},

    // 2nd record:
    {tnf: 0x02, rtdType: [0x55], id: [0x03, 0x04, ...], payload: [0x00, 0xa4, 0x04, ...]},

    // other record if has one ...
];
let ndefMessage = ndef.createNdefMessage(ndefRecords);
console.log("ndef ndefMessage: " + ndefMessage);
```

### NdefTag.getNdefTagType<sup>9+</sup>

getNdefTagType(): NfcForumType

Obtains the type of this NDEF tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NfcForumType](js-apis-nfcTag.md#nfcforumtype9) | NDEF tag type obtained. It can be NFC FORUM TYPE 1, 2, 3, or 4.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
let ndefTagType = ndef.getNdefTagType();
console.log("ndef ndefTagType: " + ndefTagType);
```

### NdefTag.getNdefMessage<sup>9+</sup>

getNdefMessage(): NdefMessage

Obtains the NDEF message.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefMessage](#ndefmessage9)  | NDEF message obtained. For details, see *NFCForum-TS-NDEF_1.0*.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
let ndefMessage = ndef.getNdefMessage();
console.log("ndef ndefMessage: " + ndefMessage);
```

### NdefTag.isNdefWritable<sup>9+</sup>

isNdefWritable(): Promise&lt;boolean&gt;

Checks whether the NDEF tag is writable. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise&lt;boolean&gt; | Promise used to return the result. If the tag is writable, **true** is returned; otherwise, **false** is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
ndef.isNdefWritable()
    .then((data) => {
        console.log("ndef isNdefWritable data: " + data);
    }).catch((err)=> {
        console.log("ndef isNdefWritable err: " + err);
    });
```

### NdefTag.isNdefWritable<sup>9+</sup>

isNdefWritable(callback: AsyncCallback&lt;boolean&gt;): void;

Checks whether the NDEF tag is writable. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback invoked to return the result. If the tag is writable, **true** is returned; otherwise, **false** is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
ndef.isNdefWritable((err, data)=> {
    if (err) {
        console.log("ndef isNdefWritable err: " + err);
    } else {
        console.log("ndef isNdefWritable data: " + data);
    }
});
```

### NdefTag.readNdef<sup>9+</sup>

readNdef(): Promise\<NdefMessage>

Reads the NDEF message from this tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<[NdefMessage](#ndefmessage9)> | Promise used to return the message read.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
ndef.readNdef()
    .then((data) => {
        console.log("ndef readNdef data: " + data);
    }).catch((err)=> {
        console.log("ndef readNdef err: " + err);
    });
```

### NdefTag.readNdef<sup>9+</sup>

readNdef(callback: AsyncCallback\<[NdefMessage](#ndefmessage9)>): void

Reads the NDEF message from this tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<[NdefMessage](#ndefmessage9)> | Yes  | Callback invoked to return the result.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
ndef.readNdef((err, data)=> {
    if (err) {
        console.log("ndef readNdef err: " + err);
    } else {
        console.log("ndef readNdef data: " + data);
    }
});
```

### NdefTag.writeNdef<sup>9+</sup>

writeNdef(msg: NdefMessage): Promise\<number>;

Writes an NDEF message to this tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| msg | NdefMessage | Yes  | NDEF message to write.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number> | Promise used to return the result. If **0** is returned, the operation is successful. If the operation fails, an error code is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
let ndefMessage = ndef.createNdefMessage([0x01, 0x02, ...]); // change the raw data to be correct.

ndef.writeNdef(ndefMessage)
    .then((data) => {
        console.log("ndef writeNdef data: " + data);
    }).catch((err)=> {
        console.log("ndef writeNdef err: " + err);
    });
```

### NdefTag.writeNdef<sup>9+</sup>

writeNdef(msg: NdefMessage, callback: AsyncCallback\<number>): void

Writes an NDEF message to this tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| msg | NdefMessage | Yes  | NDEF message to write.|
| callback | AsyncCallback\<number> | Yes  | Callback invoked to return the result.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
let ndefMessage = ndef.createNdefMessage([0x01, 0x02, ...]); // change the raw data to be correct.
ndef.writeNdef(ndefMessage, (err, data)=> {
    if (err) {
        console.log("ndef writeNdef err: " + err);
    } else {
        console.log("ndef writeNdef data: " + data);
    }
});
```

### NdefTag.canSetReadOnly<sup>9+</sup>

canSetReadOnly(): boolean

Checks whether this NDEF tag can be set to read-only.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean| Returns **true** if the tag can be set to read-only; returns **false** otherwise.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
var canSetReadOnly = ndef.canSetReadOnly();
console.log("ndef canSetReadOnly: " + canSetReadOnly);
```

### NdefTag.setReadOnly<sup>9+</sup>

setReadOnly(): Promise\<number>

Sets this NDEF tag to read-only. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise&lt;number&gt; | Promise used to return the result. If the operation is successful, **0** is returned; otherwise, an error code is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
ndef.setReadOnly()
    .then((data) => {
        console.log("ndef setReadOnly data: " + data);
    }).catch((err)=> {
        console.log("ndef setReadOnly err: " + err);
    });
```

### NdefTag.setReadOnly<sup>9+</sup>

setReadOnly(callback: AsyncCallback\<number>): void

Sets this NDEF tag to read-only. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<number> | Yes  | Callback invoked to return the result.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
ndef.setReadOnly((err, data)=> {
    if (err) {
        console.log("ndef setReadOnly err: " + err);
    } else {
        console.log("ndef setReadOnly data: " + data);
    }
});
```

### NdefTag.getNdefTagTypeString<sup>9+</sup>

getNdefTagTypeString(type: [NfcForumType](js-apis-nfcTag.md#nfcforumtype9)): string

Converts an NFC Forum Type tag to a byte array defined in the NFC Forum.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| type | [NfcForumType](js-apis-nfcTag.md#nfcforumtype9) | Yes  | NDEF tag type. It can be NFC FORUM type 1, 2, 3, or 4.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| string | Byte array obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
let ndefTypeString = ndef.getNdefTagTypeString(tag.NFC_FORUM_TYPE_1);
console.log("ndef ndefTypeString: " + ndefTypeString);
```

## MifareClassicTag<sup>9+</sup>

Provides access to MIFARE Classic properties and I/O operations. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique interfaces of **MifareClassicTag**.

### MifareClassicTag.authenticateSector<sup>9+</sup>

authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean): Promise\<boolean>

Authenticates a sector using the key. The sector can be accessed only after the authentication is successful. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | Yes  | Index of the sector to authenticate.|
| key | number[]| Yes  | Key (6 bytes) used for authentication.|
| isKeyA | boolean | Yes  | Whether the key is key A. The value **true** indicates key A, and **false** indicates key B.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<boolean> | Promise used to return the result. If the authentication is successful, **true** is returned. Otherwise, **false** is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let sectorIndex = 1; // change it to be correct index.
let key = [0x04, 0x05, ....];  // change it to be correct key.
mifareClassic.authenticateSector(sectorIndex, key, true);
    .then((data) => {
        console.log("mifareClassic authenticateSector data: " + data);
    }).catch((err)=> {
        console.log("mifareClassic authenticateSector err: " + err);
    });
```

### MifareClassicTag.authenticateSector<sup>9+</sup>

authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback\<boolean>): void

Authenticates a sector using the key. The sector can be accessed only after the authentication is successful. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | Yes  | Index of the sector to authenticate.|
| key | number[]| Yes  | Key (6 bytes) used for authentication.|
| isKeyA | boolean | Yes  | Whether the key is key A. The value **true** indicates key A, and **false** indicates key B.|
| callback | AsyncCallback\<boolean> | Yes  | Callback invoked to return the result.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let sectorIndex = 1; // change it to be correct index.
let key = [0x04, 0x05, ....];  // change it to be correct key.
mifareClassic.authenticateSector(sectorIndex, key, true, (err, data)=> {
    if (err) {
        console.log("mifareClassic authenticateSector err: " + err);
    } else {
        console.log("mifareClassic authenticateSector data: " + data);
    }
});
```

### MifareClassicTag.readSingleBlock<sup>9+</sup>

readSingleBlock(blockIndex: number): Promise\<number[]>

Reads a block (16 bytes) on the tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to read.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number[]> | Promise used to return the block data read.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
mifareClassic.readSingleBlock(blockIndex, (err, data)=> {
    if (err) {
        console.log("mifareClassic readSingleBlock err: " + err);
    } else {
        console.log("mifareClassic readSingleBlock data: " + data);
    }
});
```

### MifareClassicTag.readSingleBlock<sup>9+</sup>

readSingleBlock(blockIndex: number, callback: AsyncCallback\<number[]>): void

Reads a block (16 bytes) on the tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to read.|
| callback | AsyncCallback\<number[]> | Yes  | Callback invoked to return the block read.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
mifareClassic.readSingleBlock(blockIndex, (err, data)=> {
    if (err) {
        console.log("mifareClassic readSingleBlock err: " + err);
    } else {
        console.log("mifareClassic readSingleBlock data: " + data);
    }
});
```

### MifareClassicTag.writeSingleBlock<sup>9+</sup>

writeSingleBlock(blockIndex: number, data: number[]): Promise\<number>

Writes data to a block on the tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the target block.|
| data | number[] | Yes  | Data to write.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number> | Promise used to return the result. If **0** is returned, the operation is successful. If the operation fails, an error code is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
let rawData = [0x0a, 0x14, ...]; // change it to be correct data.
mifareClassic.writeSingleBlock(blockIndex, rawData, (err, data)=> {
    if (err) {
        console.log("mifareClassic writeSingleBlock err: " + err);
    } else {
        console.log("mifareClassic writeSingleBlock data: " + data);
    }
});
```

### MifareClassicTag.writeSingleBlock<sup>9+</sup>

writeSingleBlock(blockIndex: number, data: number[], callback: AsyncCallback\<number>): void

Writes data to a block on the tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the target block.|
| data | number[] | Yes  | Data to write.|
| callback | AsyncCallback\<number> | Yes  | Callback invoked to return the result.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
let rawData = [0x0a, 0x14, ...]; // change it to be correct data.
mifareClassic.writeSingleBlock(blockIndex, rawData, (err, data)=> {
    if (err) {
        console.log("mifareClassic writeSingleBlock err: " + err);
    } else {
        console.log("mifareClassic writeSingleBlock data: " + data);
    }
});
```

### MifareClassicTag.incrementBlock<sup>9+</sup>

incrementBlock(blockIndex: number, value: number): Promise\<number>

Increments a block with data. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to increment.|
| value | number | Yes  | Block data to increment. The value is a non-negative number.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number> | Promise used to return the result. If **0** is returned, the operation is successful. If the operation fails, an error code is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
let value = 0x20; // change it to be correct data.
mifareClassic.incrementBlock(blockIndex, value, (err, data)=> {
    if (err) {
        console.log("mifareClassic incrementBlock err: " + err);
    } else {
        console.log("mifareClassic incrementBlock data: " + data);
    }
});
```

### MifareClassicTag.incrementBlock<sup>9+</sup>

incrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<number>): void

Increments a block with data. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to increment.|
| value | number | Yes  | Block data to increment. The value is a non-negative number.|
| callback | AsyncCallback\<number> | Yes  | Callback invoked to return the result.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
let value = 0x20; // change it to be correct data.
mifareClassic.incrementBlock(blockIndex, value, (err, data)=> {
    if (err) {
        console.log("mifareClassic incrementBlock err: " + err);
    } else {
        console.log("mifareClassic incrementBlock data: " + data);
    }
});
```

### MifareClassicTag.decrementBlock<sup>9+</sup>

decrementBlock(blockIndex: number, value: number): Promise\<number>

Decrements a block with data. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to decrement.|
| value | number | Yes  | Block data to decrement. The value is a non-negative number.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number> | Promise used to return the result. If **0** is returned, the operation is successful. If the operation fails, an error code is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
let value = 0x20; // change it to be correct data.
mifareClassic.decrementBlock(blockIndex, value, (err, data)=> {
    if (err) {
        console.log("mifareClassic decrementBlock err: " + err);
    } else {
        console.log("mifareClassic decrementBlock data: " + data);
    }
});
```

### MifareClassicTag.decrementBlock<sup>9+</sup>

decrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<number>): void

Decrements a block with data. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to decrement.|
| value | number | Yes  | Block data to decrement. The value is a non-negative number.|
| callback | AsyncCallback\<number> | Yes  | Callback invoked to return the result.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
let value = 0x20; // change it to be correct data.
mifareClassic.decrementBlock(blockIndex, value, (err, data)=> {
    if (err) {
        console.log("mifareClassic decrementBlock err: " + err);
    } else {
        console.log("mifareClassic decrementBlock data: " + data);
    }
});
```

### MifareClassicTag.transferToBlock<sup>9+</sup>

transferToBlock(blockIndex: number): Promise\<number>

Copies data from the register to a block. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the destination block.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number> | Promise used to return the result. If **0** is returned, the operation is successful. If the operation fails, an error code is returned.|

**Example**

```js

import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
mifareClassic.transferToBlock(blockIndex, (err, data)=> {
    if (err) {
        console.log("mifareClassic transferToBlock err: " + err);
    } else {
        console.log("mifareClassic transferToBlock data: " + data);
    }
});
```

### MifareClassicTag.transferToBlock<sup>9+</sup>

transferToBlock(blockIndex: number, callback: AsyncCallback\<number>): void

Copies data from the register to a block. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the destination block.|
| callback | AsyncCallback\<number> | Yes  | Callback invoked to return the result.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
mifareClassic.transferToBlock(blockIndex, (err, data)=> {
    if (err) {
        console.log("mifareClassic transferToBlock err: " + err);
    } else {
        console.log("mifareClassic transferToBlock data: " + data);
    }
});
```

### MifareClassicTag.restoreFromBlock<sup>9+</sup>

restoreFromBlock(blockIndex: number): Promise\<number>

Copies data from a block to the register. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the source block.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number> | Promise used to return the result. If **0** is returned, the operation is successful. If the operation fails, an error code is returned.|

**Example**

```js

import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
mifareClassic.restoreFromBlock(blockIndex)
    .then((data) => {
        console.log("mifareClassic restoreFromBlock data: " + data);
    }).catch((err)=> {
        console.log("mifareClassic isExtendrestoreFromBlockedApduSupported err: " + err);
    });
```

### MifareClassicTag.restoreFromBlock<sup>9+</sup>

restoreFromBlock(blockIndex: number, callback: AsyncCallback\<number>): void

Copies data from a block to the register. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the source block.|
| callback | AsyncCallback\<number> | Yes  | Callback invoked to return the result.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
mifareClassic.restoreFromBlock(blockIndex, (err, data)=> {
    if (err) {
        console.log("mifareClassic restoreFromBlock err: " + err);
    } else {
        console.log("mifareClassic restoreFromBlock data: " + data);
    }
});
```

### MifareClassicTag.getSectorCount<sup>9+</sup>

getSectorCount(): number

Obtains the number of sectors in this MIFARE Classic tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Number of sectors obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let sectorCount = mifareClassic.getSectorCount();
console.log("mifareClassic sectorCount: " + sectorCount);
```

### MifareClassicTag.getBlockCountInSector<sup>9+</sup>

getBlockCountInSector(sectorIndex: number): number

Obtains the number of blocks in a sector.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | Yes  | Index of the sector.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Number of blocks obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let blockCountInSector = mifareClassic.getBlockCountInSector();
console.log("mifareClassic blockCountInSector: " + blockCountInSector);
```

### MifareClassicTag.getType<sup>9+</sup>

getType(): [MifareClassicType](js-apis-nfcTag.md#mifareclassictype9)

Obtains the type of this MIFARE Classic tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [MifareClassicType](js-apis-nfcTag.md#mifareclassictype9) | Type of the MIFARE Classic tag obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let getType = mifareClassic.getType();
console.log("mifareClassic getType: " + getType);
```

### MifareClassicTag.getTagSize<sup>9+</sup>

getTagSize(): number

Obtains the tag size (in bytes). For details, see [MifareClassicSize](js-apis-nfcTag.md#mifareclassicsize9).

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Tag size obtained, in bytes. For details, see [MifareClassicSize](js-apis-nfcTag.md#mifareclassicsize9).|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let tagSize = mifareClassic.getTagSize();
console.log("mifareClassic tagSize: " + tagSize);
```

### MifareClassicTag.isEmulatedTag<sup>9+</sup>

isEmulatedTag(): boolean

Checks whether the tag is an emulated tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean |Returns **true** if the tag is an emulated tag; returns **false** otherwise.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let isEmulatedTag = mifareClassic.isEmulatedTag();
console.log("mifareClassic isEmulatedTag: " + isEmulatedTag);
```

### MifareClassicTag.getBlockIndex<sup>9+</sup>

getBlockIndex(sectorIndex: number): number

Obtains the first block of a sector.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | Yes  | Index of the sector.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Index of the first block obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let sectorIndex = 1; // change it to be correct index.
let blockIndex = mifareClassic.getBlockIndex(sectorIndex);
console.log("mifareClassic blockIndex: " + blockIndex);
```

### MifareClassicTag.getSectorIndex<sup>9+</sup>

getSectorIndex(blockIndex: number): number

Obtains the index of a sector that contains the specified block.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block contained in the sector.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Index of the sector obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
let sectorIndex = mifareClassic.getSectorIndex(blockIndex);
console.log("mifareClassic sectorIndex: " + sectorIndex);
```

## MifareUltralightTag<sup>9+</sup>

Provides access to MIFARE Ultralight properties and I/O operations. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique interfaces of **MifareUltralightTag**.

### MifareUltralightTag.readMultiplePages<sup>9+</sup>

readMultiplePages(pageIndex: number): Promise\<number[]>

Reads multiple pages (4 bytes per page). This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | ------------------------------ |
| pageIndex | number | Yes  | Indexes of the pages to read.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number[]> | Promise used to return the data read.|

**Example**

```js

import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareUltralight' correctly.
let pageIndex = 1; // change it to be correct index.
mifareUltralight.readMultiplePages(pageIndex)
    .then((data) => {
        console.log("mifareUltralight readMultiplePages data: " + data);
    }).catch((err)=> {
        console.log("mifareUltralight readMultiplePages err: " + err);
    });
```

### MifareUltralightTag.readMultiplePages<sup>9+</sup>

readMultiplePages(pageIndex: number, callback: AsyncCallback\<number[]>): void

Reads multiple pages (4 bytes per page). This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| pageIndex | number | Yes  | Indexes of the pages to read.|
| callback | AsyncCallback\<number[]> | Yes  | Callback invoked to return the result.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareUltralight' correctly.
let pageIndex = 1; // change it to be correct index.
mifareUltralight.readMultiplePages(pageIndex, (err, data)=> {
    if (err) {
        console.log("mifareUltralight readMultiplePages err: " + err);
    } else {
        console.log("mifareUltralight readMultiplePages data: " + data);
    }
});
```

### MifareUltralightTag.writeSinglePages<sup>9+</sup>

writeSinglePages(pageIndex: number, data: number[]): Promise\<number>

Writes a page of data. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| pageIndex | number | Yes  | Index of the page.|
| data | number[] | Yes  | Data to write.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number> | Promise used to return the result. If **0** is returned, the operation is successful. If the operation fails, an error code is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareUltralight' correctly.
let pageIndex = 1; // change it to be correct index.
let data = [0x01, 0x02, ...]; // change it to be correct raw data.
mifareUltralight.writeSinglePages(pageIndex, data)
    .then((data) => {
        console.log("mifareUltralight writeSinglePages data: " + data);
    }).catch((err)=> {
        console.log("mifareUltralight writeSinglePages err: " + err);
    });
```

### MifareUltralightTag.writeSinglePages<sup>9+</sup>

writeSinglePages(pageIndex: number, data: number[], callback: AsyncCallback\<number>): void

Writes a page of data. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                    |
| -------- | ----------------------- | ---- | ------------------------ |
| pageIndex | number | Yes  | Index of the page.|
| data | number[] | Yes  | Data to write.|
| callback|AsyncCallback\<number> |Yes| Callback invoked to return the result.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareUltralight' correctly.
let pageIndex = 1; // change it to be correct index.
let data = [0x01, 0x02, ...]; // change it to be correct raw data.
mifareUltralight.writeSinglePages(pageIndex, data, (err, data)=> {
    if (err) {
        console.log("mifareUltralight writeSinglePages err: " + err);
    } else {
        console.log("mifareUltralight writeSinglePages data: " + data);
    }
});
```

### MifareUltralightTag.getType<sup>9+</sup>

getType(): MifareUltralightType

Obtains the MIFARE Ultralight tag type, in bytes. For details, see [MifareUltralightType](js-apis-nfcTag.md#mifareultralighttype9).

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| MifareUltralightType | MIFARE Ultralight tag type obtained. For details, see [MifareUltralightType](js-apis-nfcTag.md#mifareultralighttype9).|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'mifareUltralight' correctly.
let getType = mifareClassic.getType();
console.log("mifareUltralight getType: " + getType);
```

## NdefFormatableTag<sup>9+</sup>

Provides APIs for operating NDEF formattable tags. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique interfaces of **NdefFormatableTag**.

### NdefFormatableTag.format<sup>9+</sup>

format(message: [NdefMessage](#ndefmessage9)): Promise\<number>

Formats this tag as an NDEF tag, and writes an NDEF message to the tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write when the formatting is successful. If this parameter is **null**, the tag is formatted only (no data will be written).|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number> | Promise used to return the result. If **0** is returned, the operation is successful. If the operation fails, an error code is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
let data = [0x01, 0x02, ...]; // change it to be correct raw data.
let ndefmessage = ndef.createNdefMessage(data);

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndefFormatable' correctly.
ndefFormatable.format(ndefmessage, (err, data)=> {
    if (err) {
        console.log("ndefFormatable format err: " + err);
    } else {
        console.log("ndefFormatable format data: " + data);
    }
});
```

### NdefFormatableTag.format<sup>9+</sup>

format(message: [NdefMessage](#ndefmessage9), callback: AsyncCallback\<number>): void

Formats this tag as an NDEF tag, and writes an NDEF message to the tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write when the formatting is successful. If this parameter is **null**, the tag is formatted only (no data will be written).|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| callback: AsyncCallback\<number> | Callback invoked to return the result.|


**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
let data = [0x01, 0x02, ...]; // change it to be correct raw data.
let ndefmessage = ndef.createNdefMessage(data);

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndefFormatable' correctly.
ndefFormatable.format(ndefmessage, (err, data)=> {
    if (err) {
        console.log("ndefFormatable format err: " + err);
    } else {
        console.log("ndefFormatable format data: " + data);
    }
});
```

### NdefFormatableTag.formatReadOnly<sup>9+</sup>

formatReadOnly(message: [NdefMessage](#ndefmessage9)): Promise\<number>

Formats this tag as an NDEF tag, writes an NDEF message to the NDEF tag, and then sets the tag to read-only. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write when the formatting is successful. If this parameter is **null**, the tag is formatted only (no data will be written).|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number> | Promise used to return the result. If **0** is returned, the operation is successful. If the operation fails, an error code is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
let data = [0x01, 0x02, ...]; // change it to be correct raw data.
let ndefmessage = ndef.createNdefMessage(data);

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndefFormatable' correctly.
ndefFormatable.formatReadOnly(ndefmessage, (err, data)=> {
    if (err) {
        console.log("ndefFormatable formatReadOnly err: " + err);
    } else {
        console.log("ndefFormatable formatReadOnly data: " + data);
    }
});
```

### NdefFormatableTag.formatReadOnly<sup>9+</sup>

formatReadOnly(message: [NdefMessage](#ndefmessage9), callback: AsyncCallback\<number>): void

Formats this tag as an NDEF tag, writes an NDEF message to the NDEF tag, and then sets the tag to read-only. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write when the formatting is successful. If this parameter is **null**, the tag is formatted only (no data will be written).|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| callback: AsyncCallback\<number> | Callback invoked to return the result.|


**Example**

```js
import tag from '@ohos.nfc.tag';

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndef' correctly.
let data = [0x01, 0x02, ...]; // change it to be correct raw data.
let ndefmessage = ndef.createNdefMessage(data);

// Check whether 'tag.TagInfo' at 'js-apis-nfcTag' has obtained the 'ndefFormatable' correctly.
ndefFormatable.formatReadOnly(ndefmessage, (err, data)=> {
    if (err) {
        console.log("ndefFormatable formatReadOnly err: " + err);
    } else {
        console.log("ndefFormatable formatReadOnly data: " + data);
    }
});
```
