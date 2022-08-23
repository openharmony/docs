# Standard NFC Tag Technologies

The **nfctech** module provides methods for reading and writing tags that use different Near-Field Communication (NFC) technologies.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## **Modules to Import**

```js
import tag from '@ohos.nfc.tag';
```

## NfcATag

Provides access to NFC-A (ISO 14443-3A) properties and I/O operations. **NfcATag** inherits from **TagSession**.

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
| number  | SAK value obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let sak = tag.getNfcATag(taginfo).getSak(); 
console.log("sak:" +sak);
```

### NfcATag.getAtqa

getAtqa(): number[]

Obtains the ATQA value of this NFC-A tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[]  | ATQA value obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let atqa = tag.getNfcATag(taginfo).getAtqa();
console.log("atqa:" +atqa);
```

## NfcBTag

Provides access to NFC-B (ISO 14443-3B) properties and I/O operations. **NfcBTag** inherits from **TagSession**.

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
| number[]  | Application data obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let appData = tag.getNfcBTag(taginfo).getRespAppData();  
console.log("appData:" +appData);
```

### NfcBTag.getRespProtocol

getRespProtocol(): number[]

Obtains protocol information of this NFC-B tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[]  | Protocol information obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let protocol = tag.getNfcBTag(taginfo).getRespProtocol();
console.log("appData:" +protocol);
```

## NfcFTag

Provides access to NFC-F(JIS 6319-4) properties and I/O operations. **NfcFTag** inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique interfaces of **NfcFTag**.

### NfcFTag.getSystemCode

getSystemCode(): number[]

Obtains the system code from the tag instance.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                           |
| ------------------ | --------------------------|
| number[]  | System code obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let systemCode = tag.getNfcFTag(taginfo).getSystemCode();  
console.log("systemCode:" +systemCode);
```

### NfcFTag.getPmm

getPmm(): number[]

Obtains the PMm (consisting of the IC code and manufacturer parameters) information from the tag instance.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[]  | PMm information obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let pmm = tag.getNfcFTag(taginfo).getPmm();
console.log("pmm:" +pmm);
```

## NfcVTag

Provides access to NFC-V (ISO 15693) properties and I/O operations. **NfcVTag** inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique interfaces of **NfcVTag**.

### NfcvTag.getResponseFlags

getResponseFlags(): number

Obtains the response flags from the tag instance.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Response flags obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let flags = tag.getNfcVTag(taginfo).getResponseFlags();  
console.log("flags:" +flags);
```

### NfcvTag.getDsfId

getDsfId(): number

Obtains the data storage format identifier (DSFID) from the tag instance.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | DSFID obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let dsfId = tag.getNfcVTag(taginfo).getDsfId();
console.log("dsfId:" +dsfId);
```

## IsoDepTag<sup>9+</sup> 

Provides access to ISO-DEP (ISO 14443-4) properties and I/O operations. **IsoDepTag** inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique interfaces of **IsoDepTag**.

### IsoDepTag.getHistoricalBytes<sup>9+</sup>

getHistoricalBytes(): string

Obtains the historical bytes of this tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| string | Historical bytes obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let historicalBytes = tag.getIsoDepTag(taginfo).getHistoricalBytes();
console.log("historicalBytes:" +historicalBytes);
```

### IsoDepTag.getHiLayerResponse<sup>9+</sup>

getHiLayerResponse(): string

Obtains the HiLayer response of this tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| string | HiLayer response obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let hiLayerResponse = tag.getIsoDepTag(taginfo).getHiLayerResponse();
console.log("hiLayerResponse:" +hiLayerResponse);
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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.getIsoDepTag(taginfo).isExtendedApduSupported().then(function (has) {
    console.log('has: ' + has)
}) 
```

### IsoDepTag.isExtendedApduSupported<sup>9+</sup>

isExtendedApduSupported(callback: AsyncCallback\<boolean>): void

Checks whether an extended application protocol data unit (APDU) is supported. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback invoked to return the result. If the extended APDU is supported, **true** is returned; otherwise, **false** is returned.|

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.getIsoDepTag(taginfo).isExtendedApduSupported(function (error, has) {
    console.log(JSON.stringify(error))
    console.log('has: ' + has)
}) 
```

## NdefTag<sup>9+</sup>

Provides access to the tags in the NFC Data Exchange Format (NDEF). **NdefTag** inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique interfaces of **NdefTag**.

### NdefTag.createNdefMessage<sup>9+</sup>

createNdefMessage(data: string): [NdefMessage](#ndefmessage9)

Creates an NDEF message using raw bytes.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| data | string | Yes| Raw bytes of the string type.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefMessage](#ndefmessage9) | NDEF message created.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let NdefMessage = tag.NdefTag(taginfo).createNdefMessage(data);
```

## NdefMessage<sup>9+</sup>

### NdefMessage.getNdefRecords<sup>9+</sup>

getNdefRecords(): [NdefRecord](#ndefrecord9)[ ]

Obtains all NDEF records.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefRecord](#ndefrecord9)[ ] | All records obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let NdefRecord = tag.NdefTag(taginfo).getNdefRecords();
```

## NdefRecord<sup>9+</sup>

| **Name**| **Type**|  **Description**|
| -------- | -------- | -------- |
| tnf | number |  UID of the tag.|
| [rtdType](#rtdtype9) | string |  NFC Record Type Definition (RTD) supported by the tag.|
| id | string |  Additional information about the tag.|
| payload | string |  RF discovery ID of the tag.|

## RtdType<sup>9+</sup>

| **Name**| **Type**|  **Description**|
| -------- | -------- | -------- |
| RTD_TEXT | 'T' |  Text information.|
| RTD_URI  | 'U' |  Network address, email, or phone number.|

### NdefTag.createNdefMessage<sup>9+</sup>

createNdefMessage(ndefRecords: NdefRecord[]): [NdefMessage](#ndefmessage9)

Creates an NDEF message using the NDEF records.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**
| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| ndefRecords | [NdefRecord](#ndefrecord9)[] | Yes| A list of NDEF records.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefMessage](#ndefmessage9) | NDEF message created.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let NdefMessage = tag.NdefTag(taginfo).createNdefMessage(ndefRecords);
```

### NdefTag.getNdefTagType<sup>9+</sup>

getNdefTagType(): NfcForumType

Obtains the type of this NDEF tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NfcForumType](#nfcforumtype9) | NDEF tag type obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let NfcForumType = tag.NdefTag(taginfo).getNdefTagType();
```

### NdefTag.getNdefMessage<sup>9+</sup>

getNdefMessage(): NdefMessage

Obtains the NDEF message from the tag discovered.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefMessage](#ndefmessage9)  | NDEF message created.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let NdefMessage = tag.NdefTag(taginfo).getNdefMessage();
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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.NdefTag(taginfo).isNdefWritable().then(function (has) {
    console.log(JSON.stringify(has))
})
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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.NdefTag(taginfo).isNdefWritable(function (error, has) {
    console.log(JSON.stringify(error))
    console.log('has: ' + has)
})
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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.NdefTag(taginfo).readNdef().then(function (ndefMessage) {
    console.log(JSON.stringify(ndefMessage))
})
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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.NdefTag(taginfo).readNdef(function (error, ndefMessage) {
    console.log(JSON.stringify(error))
    console.log('ndefMessage: ' + ndefMessage)
})
```

### NdefTag.writeNdef<sup>9+</sup>

writeNdef(msg: NdefMessage): Promise\<number>;

Write an NDEF message to this tag. This API uses a promise to return the result.

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

// tagInfo is an object given by the NFC service when a tag is dispatched.
NdefTag.writeNdef(msg).then(function (netHandle) {
    console.log(JSON.stringify(netHandle))
})
```

### NdefTag.writeNdef<sup>9+</sup>

writeNdef(msg: NdefMessage, callback: AsyncCallback\<number>): void

Write an NDEF message to this tag. This API uses an asynchronous callback to return the result.

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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.NdefTag(taginfo).write(msg, function (error, has) {
    console.log(JSON.stringify(error))
    console.log('has: ' + has)
})
```

### NdefTag.canSetReadOnly<sup>9+</sup>

canSetReadOnly(): Promise\<boolean>

Checks whether this NDEF tag can be set to read-only. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise&lt;boolean&gt; | Promise used to return the result. If the tag can be set to read-only, **true** is returned; otherwise, **false** is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.NdefTag(taginfo).canSetReadOnly().then(function (has) {
    console.log(JSON.stringify(has))
})
```

### NdefTag.canSetReadOnly<sup>9+</sup>

canSetReadOnly()(callback: AsyncCallback&lt;boolean&gt;): void;

Checks whether this NDEF tag can be set to read-only. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback invoked to return the result. If the tag can be set to read-only, **true** is returned; otherwise, **false** is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.NdefTag(taginfo).canSetReadOnly(function (error, has) {
    console.log(JSON.stringify(error))
    console.log('has: ' + has)
})
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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.NdefTag(taginfo).setReadOnly().then(function (errcode) {
    console.log(JSON.stringify(errcode))
})
```

### NdefTag.setReadOnly<sup>9+</sup>

setReadOnly(callback: AsyncCallback<number>): void

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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.NdefTag(taginfo).setReadOnly(function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log('has: ' + errcode)
})
```

### NdefTag.getNdefTagTypeString<sup>9+</sup>

getNdefTagTypeString(type: [NfcForumType](#nfcforumtype9)): string

Converts the NFC Forum Type to a byte array defined in the NFC Forum.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| type | [NfcForumType](#nfcforumtype9) | Yes  | NFC Forum Type.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| string | Byte array obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let ndefTypeString= tag.NdefTag(taginfo).getNdefTagTypeString(type); 
```

## NfcForumType<sup>9+</sup>

| **Name**| **Type**|  **Description**|
| -------- | -------- | -------- |
| NFC_FORUM_TYPE_1 | 1 |  NFC Forum Type 1.|
| NFC_FORUM_TYPE_2 | 2 |  NFC Forum Type 2.|
| NFC_FORUM_TYPE_3  | 3 |  NFC Forum Type 3.|
| NFC_FORUM_TYPE_4  | 4 |  NFC Forum Type 4.|
| MIFARE_CLASSIC  | 101 |   MIFARE Classic.|

## MifareClassicTag <sup>9+</sup>

Provides access to MIFARE Classic properties and I/O operations. **MifareClassicTag** inherits from **TagSession**.

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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareClassicTag(taginfo).authenticateSector(sectorIndex, key).then(function (isKeyA) {
        console.log(JSON.stringify(isKeyA))
        })
```

### MifareClassicTag.authenticateSector<sup>9+</sup>

authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback<boolean>): void

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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareClassicTag(taginfo).authenticateSector(sectorIndex, key, function (error, has) {
    console.log(JSON.stringify(error))
    console.log('has: ' + has)
})
```

### MifareClassicTag.readSingleBlock<sup>9+</sup>

readSingleBlock(blockIndex: number): Promise\<string>

Reads a block on the tag. The size of a block is 16 bytes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to read.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<string> | Promise used to return the block data read.|

**Example**

```js
import tag from '@ohos.nfc.tag';

let data = "xxx";
// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareClassicTag(taginfo).readSingleBlock(blockIndex).then(function (data){
    console.log('data: ' + data)
    })
```

### MifareClassicTag.readSingleBlock<sup>9+</sup>

readSingleBlock(blockIndex: number, callback: AsyncCallback\<string>): void

Reads a block on the tag. The size of a block is 16 bytes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to read.|
| callback | AsyncCallback\<string> | Yes  | Callback invoked to return the block read.|

**Example**

```js
import tag from '@ohos.nfc.tag';

let data = "xxx";
// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareClassicTag(taginfo).readSingleBlock(blockIndex, function (error, data) {
    console.log(JSON.stringify(error))
    console.log('data: ' + data)
})
```

### MifareClassicTag.writeSingleBlock<sup>9+</sup>

writeSingleBlock(blockIndex: number, data: string): Promise\<number>

Writes data to a block on the tag. The size of a block is 16 bytes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the target block.|
| data | string | Yes  | Data to write.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number> | Promise used to return the result. If **0** is returned, the operation is successful. If the operation fails, an error code is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

let data = "xxx";
// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareClassicTag(taginfo).writeSingleBlock(blockIndex, data).then(function (errcode){
    console.log(JSON.stringify(errcode))
    })
```

### MifareClassicTag.writeSingleBlock<sup>9+</sup>

writeSingleBlock(blockIndex: number, data: string, callback: AsyncCallback\<number>): void

Writes data to a block on the tag. The size of a block is 16 bytes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the target block.|
| data | string | Yes  | Data to write.|
| callback | AsyncCallback\<number> | Yes  | Callback invoked to return the result.|

**Example**

```js
import tag from '@ohos.nfc.tag';

let data = "xxx";
// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareClassicTag(taginfo).writeSingleBlock(blockIndex, data, function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(errcode))
})
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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareClassicTag(taginfo).incrementBlock(blockIndex, value).then(function (errcode){
    console.log(JSON.stringify(errcode))
    })
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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareClassicTag(taginfo).incrementBlock(blockIndex, value, function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(errcode))
})
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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareClassicTag(taginfo).decrementBlock(blockIndex, value).then(function (errcode){
    console.log(JSON.stringify(errcode))
    })
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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareClassicTag(taginfo).decrementBlock(blockIndex, value, function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(errcode))
})
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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareClassicTag(taginfo).transferToBlock(blockIndex).then(function (errcode){
    console.log(JSON.stringify(errcode))
    })
```

### MifareClassicTag.transferToBlock

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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareClassicTag(taginfo).transferToBlock(blockIndex, function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(errcode))
})
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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareClassicTag(taginfo).restoreFromBlock(blockIndex).then(function (errcode){
    console.log(JSON.stringify(errcode))
    })
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

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareClassicTag(taginfo).restoreFromBlock(blockIndex, function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(errcode))
})
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

// tagInfo is an object given by the NFC service when a tag is dispatched.
let setorCount = tag.MifareClassicTag(taginfo).getSectorCount();
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

// tagInfo is an object given by the NFC service when a tag is dispatched.
let blockNumber = tag.MifareClassicTag(taginfo).getBlockCountInSector(sectorIndex);
```

### MifareClassicTag.getType<sup>9+</sup>

getType(): [MifareClassicType](#mifareclassictype9)

Obtains the type of this MIFARE Classic tag.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [MifareClassicType](#mifareclassictype9) | Type of the MIFARE Classic tag obtained.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let type = tag.MifareClassicTag(taginfo).getType(); 
```

### MifareClassicTag.getTagSize<sup>9+</sup>

getTagSize(): number

Obtains the tag size (in bytes). For details, see [MifareTagSize](#mifaretagsize9).

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Tag size obtained, in bytes. For details, see [MifareTagSize](#mifaretagsize9).|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let size = tag.MifareClassicTag(taginfo).getTagSize();
```

## MifareClassicType<sup>9+</sup>

| **Name**| **Value**|  **Description**|
| -------- | -------- | -------- |
| TYPE_UNKNOWN | -1 |  Unknown type.|
| TYPE_CLASSIC | 0 |  MIFARE Classic.|
| TYPE_PLUS   | 1 |  MIFARE Plus.|
| TYPE_PRO  | 2 |  MIFARE Pro.|

## MifareTagSize<sup>9+</sup>

| **Name**| **Value**|  **Description**|
| -------- | -------- | -------- |
| MC_SIZE_MINI | 320 |  Each tag has five sectors, and each sector has four blocks.|
| MC_SIZE_1K  | 1024 |  Each tag has 16 sectors, and each sector has four blocks.|
| MC_SIZE_2K   | 2048 |  Each tag has 32 sectors, and each sector has four blocks.|
| MC_SIZE_4K   | 4096 |  Each tag has 40 sectors, and each sector has four blocks.|

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

// tagInfo is an object given by the NFC service when a tag is dispatched.
let isEmulated = tag.MifareClassicTag(taginfo).isEmulatedTag();
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

// tagInfo is an object given by the NFC service when a tag is dispatched.
let index = tag.MifareClassicTag(taginfo).getBlockIndex(sectorIndex);
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

// tagInfo is an object given by the NFC service when a tag is dispatched.
let index = tag.MifareClassicTag(taginfo).getSectorIndex(blockIndex);
```

## MifareUltralightTag<sup>9+</sup>

Provides access to MIFARE Ultralight properties and I/O operations. **MifareUltralightTag** inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique interfaces of **MifareUltralightTag**.

### MifareUltralightTag.readMultiplePages<sup>9+</sup>

readMultiplePages(pageIndex: number): Promise\<string>

Reads multiple pages. The size of each page is 4 bytes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | ------------------------------ |
| pageIndex | number | Yes  | Indexes of the pages to read.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<string> | Promise used to return the data read.|

**Example**

```js

import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareUltralightTag(taginfo).readMultiplePages(pageIndex).then(function (data){
    console.log("data: " + data)
    })
```

### MifareUltralightTag.readMultiplePages<sup>9+</sup>

readMultiplePages(pageIndex: number, callback: AsyncCallback\<string>): void

Reads multiple pages. The size of each page is 4 bytes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| pageIndex | number | Yes  | Indexes of the pages to read.|
| callback | AsyncCallback\<string> | Yes  | Callback invoked to return the data read.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareUltralightTag(taginfo).readMultiplePages(pageIndex, function (error, data) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

### MifareUltralightTag.writeSinglePages<sup>9+</sup>

writeSinglePages(pageIndex: number, data: string): Promise\<number>

Writes a page of data. The size of each page is 4 bytes. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| pageIndex | number | Yes  | Index of the page.|
| data | string | Yes  | Data to write.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number> | Promise used to return the result. If **0** is returned, the operation is successful. If the operation fails, an error code is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareUltralightTag(taginfo).writeSinglePages(pageIndex, data).then(function (errcode){
    console.log(JSON.stringify(errcode))
    })
```

### MifareUltralightTag.writeSinglePages<sup>9+</sup>

writeSinglePages(pageIndex: number, data: string, callback: AsyncCallback\<number>): void

Writes a page of data. The size of each page is 4 bytes. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                    |
| -------- | ----------------------- | ---- | ------------------------ |
| pageIndex | number | Yes  | Index of the page.|
| data | string | Yes  | Data to write.|
| callback|AsyncCallback\<number> |Yes| Callback invoked to return the result.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.MifareUltralightTag(taginfo).writeSinglePages(pageIndex, data, function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(errcode))
})
```

### MifareUltralightTag.getType<sup>9+</sup>

getType(): MifareUltralightType

Obtains the MIFARE Ultralight tag type, in bytes. For details, see [MifareUltralightType](#mifareultralighttype9).

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| MifareUltralightType | Type of the MIFARE Ultralight tag. For details, see [MifareUltralightType](#mifareultralighttype9).|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
let type = tag.MifareUltralightType(taginfo).getType(); 
```

### MifareUltralightType<sup>9+</sup>

| **Name**| **Value**|  **Description**|
| -------- | -------- | -------- |
| TYPE_UNKOWN  | -1 |  Unknown type.|
| TYPE_ULTRALIGHT   | 1 |  MIFARE Ultralight.|
| TYPE_ULTRALIGHT_C    | 2 |  MIFARE Ultralight C.|

## NdefFormatableTag<sup>9+</sup>

Provides methods for operating NDEF formattable tags. **NdefFormatableTag** inherits from **TagSession**.

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
| message | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write when the formatting is successful. If it is **null**, the tag is formatted only and no data will be written.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number> | Promise used to return the result. If **0** is returned, the operation is successful. If the operation fails, an error code is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.NdefFormatableTag(taginfo).format(message).then(function (errcode){
    console.log(JSON.stringify(errcode))
    })
```

### NdefFormatableTag.format<sup>9+</sup>

format(message: [NdefMessage](#ndefmessage9), callback: AsyncCallback\<number>): void

Formats this tag as an NDEF tag, and writes an NDEF message to the tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write when the formatting is successful. If it is **null**, the tag is formatted only and no data will be written.|
| callback: AsyncCallback\<number> | Callback invoked to return the result.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.NdefFormatableTag(taginfo).format(message, function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(errcode))
})
```

### NdefFormatableTag.formatReadOnly<sup>9+</sup>

formatReadOnly(message: [NdefMessage](#ndefmessage9)): Promise\<number>

Formats this tag as an NDEF tag, writes an NDEF message to the NDEF tag, and then sets the tag to read-only. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write when the formatting is successful. If it is **null**, the tag is formatted only and no data will be written.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number> | Promise used to return the result. If **0** is returned, the operation is successful. If the operation fails, an error code is returned.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.NdefFormatableTag(taginfo).formatReadOnly(message).then(function (errcode){
    console.log(JSON.stringify(errcode))
    })
```

### NdefFormatableTag.formatReadOnly<sup>9+</sup>

formatReadOnly(message: [NdefMessage](#ndefmessage9), callback: AsyncCallback\<number>): void

Formats this tag as an NDEF tag, writes an NDEF message to the NDEF tag, and then sets the tag to read-only. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write when the formatting is successful. If it is **null**, the tag is formatted only and no data will be written.|
| callback: AsyncCallback\<number> | Callback invoked to return the result.|

**Example**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an object given by the NFC service when a tag is dispatched.
tag.NdefFormatableTag(taginfo).formatReadOnly(message, function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(errcode))
})
```
