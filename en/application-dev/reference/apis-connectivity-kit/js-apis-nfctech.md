# nfctech (Standard NFC Technologies)

The **nfctech** module provides APIs for reading and writing tags that use different Near-Field Communication (NFC) technologies.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import { tag } from '@kit.ConnectivityKit';
```

## NfcATag

Provides APIs to access NFC-A (ISO 14443-3A) properties and perform I/O operations on a tag. This class inherits from **[TagSession](js-apis-tagSession.md)**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **NfcATag**.

### NfcATag.getSak

getSak(): number

Obtains the SAK value of this NFC-A tag.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number  | SAK value obtained. The SAK is a hexadecimal number ranging from **0x00** to **0xFF**.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// Obtain the correct nfcA tag by using the tag.TagInfo API in @ohos.nfc.tag.
let sak : number = nfcA.getSak();
console.info("nfcA sak: " + sak);
```

### NfcATag.getAtqa

getAtqa(): number[]

Obtains the ATQA value of this NFC-A tag.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[]  | ATQA value obtained. Each number of the ATQA is a hexadecimal number ranging from **0x00** to **0xFF**.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// Obtain the correct nfcA tag by using the tag.TagInfo API in @ohos.nfc.tag.
let atqa : number[] = nfcA.getAtqa();
console.info("nfcA atqa: " + atqa);
```

## NfcBTag

Provides APIs to access NFC-B (ISO 14443-3B) properties and perform I/O operations on a tag. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **NfcBTag**.

### NfcBTag.getRespAppData

getRespAppData(): number[]

Obtains the application data of this NFC-B tag.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[]  | Application data obtained, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// Obtain the correct nfcB tag by using the tag.TagInfo API in @ohos.nfc.tag.
let respAppData : number[] = nfcB.getRespAppData();
console.info("nfcB respAppData: " + respAppData);
```

### NfcBTag.getRespProtocol

getRespProtocol(): number[]

Obtains the protocol information of this NFC-B tag.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[]  | Protocol information obtained, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// Obtain the correct nfcB tag by using the tag.TagInfo API in @ohos.nfc.tag.
let respProtocol : number[] = nfcB.getRespProtocol();
console.info("nfcB respProtocol: " + respProtocol);
```

## NfcFTag

Provides APIs to access NFC-F (JIS 6319-4) properties and perform I/O operations on a tag. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **NfcFTag**.

### NfcFTag.getSystemCode

getSystemCode(): number[]

Obtains the system code from this NFC-F tag.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                           |
| ------------------ | --------------------------|
| number[]  | System code obtained, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// Obtain the correct nfcF tag by using the tag.TagInfo API in @ohos.nfc.tag.
let systemCode : number[] = nfcF.getSystemCode();
console.info("nfcF systemCode: " + systemCode);
```

### NfcFTag.getPmm

getPmm(): number[]

Obtains the PMm (consisting of the IC code and manufacturer parameters) information from this NFC-F tag.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[]  | PMm information obtained, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// Obtain the correct nfcF tag by using the tag.TagInfo API in @ohos.nfc.tag.
let pmm : number[] = nfcF.getPmm();
console.info("nfcF pmm: " + pmm);
```

## NfcVTag

Provides APIs to access NFC-V (ISO 15693) properties and perform I/O operations on a tag. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **NfcVTag**.

### NfcvTag.getResponseFlags

getResponseFlags(): number

Obtains the response flags from this NFC-V tag.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Response flags obtained, which consist of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// Obtain the correct nfcV tag by using the tag.TagInfo API in @ohos.nfc.tag.
let responseFlags : number = nfcV.getResponseFlags();
console.info("nfcV responseFlags: " + responseFlags);
```

### NfcvTag.getDsfId

getDsfId(): number

Obtains the data storage format identifier (DSFID) from this NFC-V tag.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | DSFID obtained, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// Obtain the correct nfcV tag by using the tag.TagInfo API in @ohos.nfc.tag.
let dsfId : number = nfcV.getDsfId();
console.info("nfcV dsfId: " + dsfId);
```

## IsoDepTag<sup>9+</sup> 

Provides APIs to access ISO-DEP (ISO 14443-4) properties and I/O operations on a tag. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **IsoDepTag**.

### IsoDepTag.getHistoricalBytes<sup>9+</sup>

getHistoricalBytes(): number[]

Obtains the historical bytes for the given tag. This API applies only to the IsoDep tags that use the NFC-A technology.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[] | Historical bytes obtained, which consist of hexadecimal numbers ranging from **0x00** to **0xFF**. If the IsoDep tag uses the NFC-B technology, **null** will be returned.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// Obtain the correct isoDep tag by using the tag.TagInfo API in @ohos.nfc.tag.
let historicalBytes : number[] = isoDep.getHistoricalBytes();
console.info("isoDep historicalBytes: " + historicalBytes);
```

### IsoDepTag.getHiLayerResponse<sup>9+</sup>

getHiLayerResponse(): number[]

Obtains the higher-layer response bytes for the given tag. This API applies only to the IsoDep tags that use the NFC-B technology.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[] | Higher-layer response bytes obtained, which consist of hexadecimal numbers ranging from **0x00** to **0xFF**. If the IsoDep tag uses the NFC-A technology, **null** will be returned.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// Obtain the correct isoDep tag by using the tag.TagInfo API in @ohos.nfc.tag.
let hiLayerResponse : number[] = isoDep.getHiLayerResponse();
console.info("isoDep hiLayerResponse: " + hiLayerResponse);
```

### IsoDepTag.isExtendedApduSupported<sup>9+</sup>

isExtendedApduSupported(): Promise&lt;boolean&gt;

Checks whether an extended application protocol data unit (APDU) is supported. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the extended APDU is supported; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct isoDep tag by using the tag.TagInfo API in @ohos.nfc.tag.
function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!isoDep.isTagConnected()) {
        if (!isoDep.connectTag()) {
            console.error("isoDep connectTag failed.");
            return;
        }
    }

    try {
        isoDep.isExtendedApduSupported().then((response: boolean) => {
            console.info("isoDep isExtendedApduSupported Promise response: " + response);
        }).catch((err: BusinessError) => {
            console.error("isoDep isExtendedApduSupported Promise Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("isoDep isExtendedApduSupported Promise Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}

```

### IsoDepTag.isExtendedApduSupported<sup>9+</sup>

isExtendedApduSupported(callback: AsyncCallback\<boolean>): void

Checks whether an extended APDU is supported. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | Yes  | Callback used to return the result. If the extended APDU is supported, **true** is returned; otherwise, **false** is returned.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct isoDep tag by using the tag.TagInfo API in @ohos.nfc.tag.
function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!isoDep.isTagConnected()) {
        if (!isoDep.connectTag()) {
            console.error("isoDep connectTag failed.");
            return;
        }
    }

    try {
        isoDep.isExtendedApduSupported((err: BusinessError, response: boolean) => {
            if (err) {
                console.error("isoDep isExtendedApduSupported AsyncCallback Code: ${err.code}, message: ${err. message}");
            } else {
                console.info("isoDep isExtendedApduSupported AsyncCallback response: " + response);
            }
        });
    } catch (busiErr) {
        console.error("isoDep isExtendedApduSupported AsyncCallback Code: ${(businessError as Business).code}, " + "message: ${(businessError as Business).message}");
    }
}

```

## NdefMessage<sup>9+</sup>

### NdefMessage.getNdefRecords<sup>9+</sup>

getNdefRecords(): [tag.NdefRecord](js-apis-nfcTag.md#ndefrecord9)[]

Obtains all NDEF records.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [tag.NdefRecord](js-apis-nfcTag.md#ndefrecord9)[] | List of NDEF records obtained. For details, see *NFCForum-TS-NDEF_1.0*.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// Obtain ndefMessage from tag.ndef.createNdefMessage or ndefTag.getNdefMessage.
// let ndefMessage : tag.NdefMessage = tag.ndef.createNdefMessage(...);
// let ndefMessage : tag.NdefMessage = ndefTag.getNdefMessage();

let ndefRecords : tag.NdefRecord[] = ndefMessage.getNdefRecords();
console.info("ndef ndefRecords number: " + ndefRecords.length);
```

## NdefTag<sup>9+</sup>

Provides APIs to access the tags in the NFC Data Exchange Format (NDEF). This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **NdefTag**.

### NdefTag.getNdefTagType<sup>9+</sup>

getNdefTagType(): [tag.NfcForumType](js-apis-nfcTag.md#nfcforumtype9)

Obtains the NDEF tag type.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [tag.NfcForumType](js-apis-nfcTag.md#nfcforumtype9) | NDEF tag type obtained. It can be NFC FORUM TYPE 1, 2, 3, or 4.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// Obtain the correct ndefTag tag by using the tag.TagInfo API in @ohos.nfc.tag.
let ndefTagType : tag.NfcForumType = ndefTag.getNdefTagType();
console.info("ndef ndefTagType: " + ndefTagType);
```

### NdefTag.getNdefMessage<sup>9+</sup>

getNdefMessage(): [NdefMessage](#ndefmessage9)

Obtains the NDEF message from this NDEF tag.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefMessage](#ndefmessage9)  | NDEF message created. For details, see *NFCForum-TS-NDEF_1.0*.|

**Example**
```js
import { tag } from '@kit.ConnectivityKit';

// Obtain the correct ndefTag tag by using the tag.TagInfo API in @ohos.nfc.tag.
let ndefMessage : tag.NdefMessage = ndefTag.getNdefMessage();
console.info("ndef ndefMessage: " + ndefMessage);
```

### NdefTag.isNdefWritable<sup>9+</sup>

isNdefWritable(): boolean

Check whether this NDEF tag is writable. Before calling the data write API, check whether the write operation is supported.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean | Promise used to return the result. If the tag is writable, **true** is returned; otherwise, **false** is returned.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// Obtain the correct ndefTag tag by using the tag.TagInfo API in @ohos.nfc.tag.
let isWritable : boolean = ndefTag.isNdefWritable();
console.info("ndef isNdefWritable: " + isWritable);
```

### NdefTag.readNdef<sup>9+</sup>

readNdef(): Promise\<[NdefMessage](#ndefmessage9)>

Reads the NDEF message from this tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<[NdefMessage](#ndefmessage9)> | Promise used to return the message object read.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct ndefTag tag by using the tag.TagInfo API in @ohos.nfc.tag.
function nfcTechDemo(){
    // Connect the tag if it has not been connected.
    if (!ndefTag.isTagConnected()) {
        if (!ndefTag.connectTag()) {
            console.error("ndefTag connectTag failed.");
            return;
        }
    }

    try {
        ndefTag.readNdef().then((ndefmessage : tag.NdefMessage) => {
            console.info("ndef readNdef Promise ndefmessage: " + ndefmessage);
        }).catch((err : BusinessError)=> {
            console.error("ndef readNdef Promise err Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("ndef readNdef Promise catch businessError Code: ${(businessError as BusinessError).code}, " +
        "message: ${(businessError as BusinessError).message}");
    }
}

```

### NdefTag.readNdef<sup>9+</sup>

readNdef(callback: AsyncCallback\<[NdefMessage](#ndefmessage9)>): void

Reads the NDEF message from this tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<[NdefMessage](#ndefmessage9)> | Yes  | Callback used to return the NDEF message read.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct ndefTag tag by using the tag.TagInfo API in @ohos.nfc.tag.
function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!ndefTag.isTagConnected()) {
        if (!ndefTag.connectTag()) {
            console.error("ndefTag connectTag failed.");
            return;
        }
    }

    try {
        ndefTag.readNdef((err : BusinessError, ndefmessage : tag.NdefMessage)=> {
            if (err) {
                console.error("ndef readNdef AsyncCallback err Code: ${err.code}, message: ${err.message}");
            } else {
                console.info("ndef readNdef AsyncCallback ndefmessage: " + ndefmessage);
            }
        });
    } catch (businessError) {
        console.error("ndef readNdef AsyncCallback catch Code: ${(businessError : BusinessError).code}," +
        " message: ${(businessError : BusinessError).message}");
    }
}

```

### NdefTag.writeNdef<sup>9+</sup>

writeNdef(msg: [NdefMessage](#ndefmessage9)): Promise\<void>

Writes an NDEF message to this tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| msg | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct ndefTag tag by using the tag.TagInfo API in @ohos.nfc.tag.
// ndefMessage created from the raw data. For example:
let ndefMessage : tag.NdefMessage =
    tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]); // The NDEF data must be resolvable.
// Or create ndefMessage from tag.ndef.createNdefMessage (ndefRecords:NdefRecord[]).

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!ndefTag.isTagConnected()) {
        if (!ndefTag.connectTag()) {
            console.error("ndefTag connectTag failed.");
            return;
        }
    }

    try {
        ndefTag.writeNdef(ndefMessage).then(() => {
            console.info("ndef writeNdef Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("ndef writeNdef err Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("ndef writeNdef Promise catch businessError Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### NdefTag.writeNdef<sup>9+</sup>

writeNdef(msg: [NdefMessage](#ndefmessage9), callback: AsyncCallback\<void>): void

Writes an NDEF message to this tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| msg | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct ndefTag tag by using the tag.TagInfo API in @ohos.nfc.tag.
// ndefMessage created from the raw data. For example:
let ndefMessage : tag.NdefMessage = 
    tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]); // The NDEF data must be resolvable.
// Or create ndefMessage from tag.ndef.createNdefMessage (ndefRecords:NdefRecord[]).

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!ndefTag.isTagConnected()) {
        if (!ndefTag.connectTag()) {
            console.error("ndefTag connectTag failed.");
            return;
        }
    }

    try {
        ndefTag.writeNdef(ndefMessage, (err : BusinessError)=> {
            if (err) {
                console.error("ndef writeNdef AsyncCallback Code: ${err.code}, message: ${err.message}");
            } else {
                console.info("ndef writeNdef AsyncCallback success.");
            }
        }); 
    } catch (businessError) {
        console.error("ndef writeNdef AsyncCallback catch businessError Code: ${(businessError as Businsess).code}," +
            " message: ${(businessError as Businsess).message}");
    }
}
```

### NdefTag.canSetReadOnly<sup>9+</sup>

canSetReadOnly(): boolean

Checks whether this NDEF tag can be set to read-only.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean| Returns **true** if the tag can be set to read-only; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 3100201 | The tag running state is abnormal in the service. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// Obtain the correct ndefTag tag by using the tag.TagInfo API in @ohos.nfc.tag.
let canSetReadOnly : boolean = ndefTag.canSetReadOnly();
console.info("ndef canSetReadOnly: " + canSetReadOnly);
```

### NdefTag.setReadOnly<sup>9+</sup>

setReadOnly(): Promise\<void>

Sets this NDEF tag to read-only. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct ndefTag tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!ndefTag.isTagConnected()) {
        if (!ndefTag.connectTag()) {
            console.error("ndefTag connectTag failed.");
            return;
        }
    }

    try {
        ndefTag.setReadOnly().then(() => {
            console.info("ndef setReadOnly Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("ndef setReadOnly Promise err Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("ndef setReadOnly Promise catch businessError Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### NdefTag.setReadOnly<sup>9+</sup>

setReadOnly(callback: AsyncCallback\<void>): void

Sets this NDEF tag to read-only. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct ndefTag tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!ndefTag.isTagConnected()) {
        if (!ndefTag.connectTag()) {
            console.error("ndefTag connectTag failed.");
            return;
        }
    }

    try {
        ndefTag.setReadOnly((err : BusinessError)=> {
            if (err) {
                console.error("ndef setReadOnly AsyncCallback err Code: ${err.code}, message: ${err.message}");
            } else {
                console.info("ndef setReadOnly AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("ndef setReadOnly AsyncCallback catch businessError Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### NdefTag.getNdefTagTypeString<sup>9+</sup>

getNdefTagTypeString(type: [tag.NfcForumType](js-apis-nfcTag.md#nfcforumtype9)): string

Converts an NFC Forum Type tag to a string defined in the NFC Forum.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| type | [tag.NfcForumType](js-apis-nfcTag.md#nfcforumtype9) | Yes  | NDEF tag type. It can be NFC FORUM type 1, 2, 3, or 4.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| string | Byte array obtained.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct ndefTag tag by using the tag.TagInfo API in @ohos.nfc.tag.

try {
    let ndefTypeString : string = ndefTag.getNdefTagTypeString(tag.NfcForumType.NFC_FORUM_TYPE_1);
    console.info("ndef ndefTypeString: " + ndefTypeString);
} catch (businessError) {
    console.error("ndef getNdefTagTypeString catch businessError Code: ${(businessError as Businsess).code}, " +
        "message: ${(businessError as Businsess).message}");
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

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | Yes  | Index of the sector to authenticate. The sector indexes start from **0**.|
| key | number[]| Yes  | Key (6 bytes) used for sector authentication.|
| isKeyA | boolean | Yes  | Whether the key is key A. The value **true** indicates key A, and **false** indicates key B.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let sectorIndex = 1; // Set a correct index.
        let key = [0x01, 0x02, 0x03, 0x04, 0x05, 0x06] // Set a correct key. The value must contain six bytes. 
        mifareClassic.authenticateSector(sectorIndex, key, true).then(() => {
            console.info("mifareClassic authenticateSector Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("mifareClassic authenticateSector Promise errCode: ${err.code}, " + "message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareClassic authenticateSector Promise catch businessError Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.authenticateSector<sup>9+</sup>

authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback\<void>): void

Authenticates a sector using a key. The sector can be accessed only after the authentication is successful. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | Yes  | Index of the sector to authenticate. The sector indexes start from **0**.|
| key | number[]| Yes  | Key (6 bytes) used for sector authentication.|
| isKeyA | boolean | Yes  | Whether the key is key A. The value **true** indicates key A, and **false** indicates key B.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the authentication result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**
```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let sectorIndex = 1; // Set a correct index.
        let key = [0x01, 0x02, 0x03, 0x04, 0x05, 0x06]  // Set a correct key. The value must contain six bytes. 
        mifareClassic.authenticateSector(sectorIndex, key, true, (err : BusinessError)=> {
            if (err) {
                console.error("mifareClassic authenticateSector AsyncCallback errCode: ${err.code}, message: ${err.message}");
            } else {
                console.info("mifareClassic authenticateSector AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("mifareClassic authenticateSector AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.readSingleBlock<sup>9+</sup>

readSingleBlock(blockIndex: number): Promise\<number[]>

Reads a block (16 bytes) on this tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to read. The block indexes start from **0**.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number[]> | Promise used to return the block read.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // Set a correct index.
        mifareClassic.readSingleBlock(blockIndex).then((data : number[]) => {
            console.info("mifareClassic readSingleBlock Promise data: " + data);
        }).catch((err : BusinessError)=> {
            console.error("mifareClassic readSingleBlock Promise errCode: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareClassic readSingleBlock Promise catch businessError Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.readSingleBlock<sup>9+</sup>

readSingleBlock(blockIndex: number, callback: AsyncCallback\<number[]>): void

Reads a block (16 bytes) on this tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to read. The block indexes start from **0**.|
| callback | AsyncCallback\<number[]> | Yes  |Callback used to return the block data read.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1;  // Set a correct index.
        mifareClassic.readSingleBlock(blockIndex, (err : BusinessError, data : number[])=> {
            if (err) {
                console.error("mifareClassic readSingleBlock AsyncCallback err: " + err);
            } else {
                console.info("mifareClassic readSingleBlock AsyncCallback data: " + data);
            }
        });
    } catch (businessError) {
        console.error("mifareClassic readSingleBlock AsyncCallback catch businessError Code: " + 
        " ${(businessError as Businsess).code}, message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.writeSingleBlock<sup>9+</sup>

writeSingleBlock(blockIndex: number, data: number[]): Promise\<void>

Writes data to a block on this tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to write. The block indexes start from **0**.|
| data | number[] | Yes  | 16-byte data to write.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // Set a correct index.
        let rawData = [0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A,
            0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10]; // Set a correct key. The value must contain 16 bytes.
        mifareClassic.writeSingleBlock(blockIndex, rawData).then(() => {
            console.info("mifareClassic writeSingleBlock Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("mifareClassic writeSingleBlock Promise errCode: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareClassic writeSingleBlock Promise catch businessError Code: ${(businessError as Businsess).code}, "
        + "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.writeSingleBlock<sup>9+</sup>

writeSingleBlock(blockIndex: number, data: number[], callback: AsyncCallback\<void>): void

Writes data to a block on this tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to write. The block indexes start from **0**.|
| data | number[] | Yes  | 16-byte data to write.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // Set a correct index.
        let rawData = [0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A,
            0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10]; // Set the correct data. The value must contain 16 bytes.
        mifareClassic.writeSingleBlock(blockIndex, rawData, (err : BusinessError)=> {
            if (err) {
                console.error("mifareClassic writeSingleBlock AsyncCallback err Code:" +
                "${err.code}, message: ${err.message}");
            } else {
                console.info("mifareClassic writeSingleBlock AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("mifareClassic writeSingleBlock AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.incrementBlock<sup>9+</sup>

incrementBlock(blockIndex: number, value: number): Promise\<void>

Increments a block with the specified value and saves the result in a buffer for internal transmission. This API uses a promise to return the result. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to increment. The block indexes start from **0**.|
| value | number | Yes  | Block data to increment. The value cannot be a negative number.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // Set a correct index.
        let value = 0x20; // Set the correct data.
        mifareClassic.incrementBlock(blockIndex, value).then(() => {
            console.info("mifareClassic incrementBlock Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("mifareClassic incrementBlock Promise err Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareClassic incrementBlock Promise catch Code: ${(businessError as Businsess).code}, " +
           "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.incrementBlock<sup>9+</sup>

incrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void

Increments a block with the specified value and saves the result in a buffer for internal transmission. This API uses an asynchronous callback to return the result. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to increment. The block indexes start from **0**.|
| value | number | Yes  | Block data to increment. The value cannot be a negative number.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // Set a correct index.
        let value = 0x20; // Set the correct data.
        mifareClassic.incrementBlock(blockIndex, value, (err : BusinessError)=> {
            if (err) {
                console.error("mifareClassic incrementBlock AsyncCallback err Code: ${err.code}, message: ${err.message}");
            } else {
                console.info("mifareClassic incrementBlock AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("mifareClassic incrementBlock AsyncCallback catch businessError Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.decrementBlock<sup>9+</sup>

decrementBlock(blockIndex: number, value: number): Promise\<void>

Decrements a block with the specified value and saves the result in a buffer for internal transmission. This API uses a promise to return the result. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to increment. The block indexes start from **0**.|
| value | number | Yes  | Block data to decrement. The value cannot be a negative number.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // Set a correct index.
        let value = 0x20; // Set the correct data.
        mifareClassic.decrementBlock(blockIndex, value).then(() => {
            console.info("mifareClassic decrementBlock Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("mifareClassic decrementBlock Promise errCode: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareClassic decrementBlock Promise catch businessError: Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.decrementBlock<sup>9+</sup>

decrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void

Decrements a block with the specified value. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the block to increment. The block indexes start from **0**.|
| value | number | Yes  | Block data to decrement. The value cannot be a negative number.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // Set a correct index.
        let value = 0x20; // Set the correct data.
        mifareClassic.decrementBlock(blockIndex, value, (err : BusinessError)=> {
            if (err) {
                console.error("mifareClassic decrementBlock AsyncCallback errCode:" + 
                  "${err.code}, message: ${err.message}");
            } else {
                console.info("mifareClassic decrementBlock AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("mifareClassic decrementBlock AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
          "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.transferToBlock<sup>9+</sup>

transferToBlock(blockIndex: number): Promise\<void>

Transfers data from the temporary register to a block. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes | Index of the destination block. The value starts form **0**.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // Set a correct index.
        mifareClassic.transferToBlock(blockIndex).then(() => {
            console.info("mifareClassic transferToBlock Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("mifareClassic transferToBlock Promise err Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareClassic transferToBlock Promise catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.transferToBlock<sup>9+</sup>

transferToBlock(blockIndex: number, callback: AsyncCallback\<void>): void

Transfers data from the temporary register to a block. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the destination block. The value starts form **0**.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // Set a correct index.
        mifareClassic.transferToBlock(blockIndex, (err : BusinessError)=> {
            if (err) {
                console.error("mifareClassic transferToBlock AsyncCallback errCode: ${err.code}," +
                    "message: ${err.message}");
            } else {
                console.info("mifareClassic transferToBlock AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("mifareClassic transferToBlock AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.restoreFromBlock<sup>9+</sup>

restoreFromBlock(blockIndex: number): Promise\<void>

Restores data in the temporary register from a block. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the destination block. The value starts form **0**.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }   
    }

    try {
        let blockIndex = 1; // Set a correct index.
        mifareClassic.restoreFromBlock(blockIndex).then(() => {
            console.info("mifareClassic restoreFromBlock Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("mifareClassic restoreFromBlock Promise errCode: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareClassic restoreFromBlock Promise catch businessError Code: ${(businessError as Businsess).code}," +
            " message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.restoreFromBlock<sup>9+</sup>

restoreFromBlock(blockIndex: number, callback: AsyncCallback\<void>): void

Restores data in the temporary register from a block. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes  | Index of the destination block. The value starts form **0**.|
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // Set a correct index.
        mifareClassic.restoreFromBlock(blockIndex, (err : BusinessError)=> {
            if (err) {
                console.error("mifareClassic restoreFromBlock AsyncCallback err Code: ${err.code}," +
                    " message: ${err.message}");
            } else {
                console.info("mifareClassic restoreFromBlock AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("mifareClassic restoreFromBlock AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.getSectorCount<sup>9+</sup>

getSectorCount(): number

Obtains the number of sectors in this MIFARE Classic tag.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Number of sectors obtained.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.
let sectorCount : number = mifareClassic.getSectorCount();
console.info("mifareClassic sectorCount: " + sectorCount);
```

### MifareClassicTag.getBlockCountInSector<sup>9+</sup>

getBlockCountInSector(sectorIndex: number): number

Obtains the number of blocks in a sector.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | Yes  | Index of the target sector. The sector indexes start from **0**.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Number of blocks obtained.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.

try {
    let sectorIndex = 1; // Set a correct index.
    let blockCnt : number = mifareClassic.getBlockCountInSector(sectorIndex);
    console.info("mifareClassic blockCnt: " + blockCnt);
} catch (businessError) {
    console.error("mifareClassic getBlockCountInSector catch businessError Code: ${(businessError as Businsess).code}, " +
        "message: ${(businessError as Businsess).message}");
}
```

### MifareClassicTag.getType<sup>9+</sup>

getType(): [tag.MifareClassicType](js-apis-nfcTag.md#mifareclassictype9)

Obtains the type of this MIFARE Classic tag.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [tag.MifareClassicType](js-apis-nfcTag.md#mifareclassictype9) | Type of the MIFARE Classic tag obtained.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.
let getType : tag.MifareClassicType = mifareClassic.getType();
console.info("mifareClassic getType: " + getType);
```

### MifareClassicTag.getTagSize<sup>9+</sup>

getTagSize(): number

Obtains the size of this tag. For details, see [MifareClassicSize](js-apis-nfcTag.md#mifareclassicsize9).

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Tag size obtained, in bytes. For details, see [MifareClassicSize](js-apis-nfcTag.md#mifareclassicsize9).|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.
let tagSize : number = mifareClassic.getTagSize();
console.info("mifareClassic tagSize: " + tagSize);
```

### MifareClassicTag.isEmulatedTag<sup>9+</sup>

isEmulatedTag(): boolean

Checks whether it is an emulated tag.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| boolean |Returns **true** if the tag is an emulated tag; returns **false** otherwise.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.
let isEmulatedTag : boolean = mifareClassic.isEmulatedTag();
console.info("mifareClassic isEmulatedTag: " + isEmulatedTag);
```

### MifareClassicTag.getBlockIndex<sup>9+</sup>

getBlockIndex(sectorIndex: number): number

Obtains the index of the first block in a sector.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | Yes  | Index of the target sector. The sector indexes start from **0**.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Index of the first block obtained.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.

try {
    let sectorIndex = 1; // Set a correct index.
    let blockIndex : number = mifareClassic.getBlockIndex(sectorIndex);
    console.info("mifareClassic blockIndex: " + blockIndex);
} catch (businessError) {
    console.error("mifareClassic getBlockIndex catch businessError Code: ${(businessError as Businsess).code}, " +
        "message: ${(businessError as Businsess).message}");
}
```

### MifareClassicTag.getSectorIndex<sup>9+</sup>

getSectorIndex(blockIndex: number): number

Obtains the index of the sector that holds the specified block.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | Yes| Index of the block. The block indexes start from **0**.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number | Index of the sector obtained.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Classic tag by using the tag.TagInfo API in @ohos.nfc.tag.

try {
    let blockIndex = 1; // Set a correct index.
    let sectorIndex : number = mifareClassic.getSectorIndex(blockIndex);
    console.info("mifareClassic sectorIndex: " + sectorIndex);
} catch (businessError) {
    console.error("mifareClassic getSectorIndex catch businessError Code: ${(businessError as Businsess).code}, " +
       "message: ${(businessError as Businsess).message}");
}
```

## MifareUltralightTag<sup>9+</sup>

Provides APIs to access MIFARE Ultralight properties and perform I/O operations on a tag. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **MifareUltralightTag**.

### MifareUltralightTag.readMultiplePages<sup>9+</sup>

readMultiplePages(pageIndex: number): Promise\<number[]>

Reads four pages of data (16 bytes in total) from the tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | ------------------------------ |
| pageIndex | number | Yes  | Index of the first page to read. The page indexes start from **0**.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| Promise\<number[]> | Promise used to return the data read.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js

import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Ultralight tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareUltralight.isTagConnected()) {
        if (!mifareUltralight.connectTag()) {
            console.error("mifareUltralight connectTag failed.");
            return;
        }
    }

    try {
        let pageIndex = 1; // Set a correct index.
        mifareUltralight.readMultiplePages(pageIndex).then((data : number[]) => {
            console.info("mifareUltralight readMultiplePages Promise data = " + data);
        }).catch((err : BusinessError)=> {
            console.error("mifareUltralight readMultiplePages Promise Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareUltralight readMultiplePages Promise catch businessError" +
            " Code: ${(businessError as Businsess).code}, message: ${(businessError as Businsess).message}");
    }
}
```

### MifareUltralightTag.readMultiplePages<sup>9+</sup>

readMultiplePages(pageIndex: number, callback: AsyncCallback\<number[]>): void

Reads four pages of data (16 bytes in total) from the tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| pageIndex | number | Yes  | Index of the first page to read. The page indexes start from **0**.|
| callback | AsyncCallback\<number[]> | Yes  | Callback used to return the data (16 bytes in size) read.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Ultralight tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareUltralight.isTagConnected()) {
        if (!mifareUltralight.connectTag()) {
            console.error("mifareUltralight connectTag failed.");
            return;
        }
    }

    try {
        let pageIndex = 1; // Set a correct index.
        mifareUltralight.readMultiplePages(pageIndex, (err : BusinessError, data : number[])=> {
            if (err) {
                console.log("mifareUltralight readMultiplePages AsyncCallback Code: ${err.code}, message: ${err.message}");
            } else {
                console.info("mifareUltralight readMultiplePages AsyncCallback data: " + data);
            }
        });
    } catch (businessError) {
        console.error("mifareUltralight readMultiplePages AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareUltralightTag.writeSinglePage<sup>9+</sup>

writeSinglePage(pageIndex: number, data: number[]): Promise\<void>

Writes one page (4 bytes) of data to this tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| pageIndex | number | Yes  | Index of the page to write. The page indexes start from **0**.|
| data | number[] | Yes  | 4-byte data to write.|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Ultralight tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareUltralight.isTagConnected()) {
        if (!mifareUltralight.connectTag()) {
            console.error("mifareUltralight connectTag failed.");
            return;
        }
    }

    try {
        let pageIndex = 1; // Set a correct index.
        let rawData = [0x01, 0x02, 0x03, 0x04]; // Set the correct data. The value must contain 4 bytes. 
        mifareUltralight.writeSinglePage(pageIndex, rawData).then(() => {
            console.info("mifareUltralight writeSinglePage Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("mifareUltralight writeSinglePage Promise err Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareUltralight writeSinglePage Promise catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareUltralightTag.writeSinglePage<sup>9+</sup>

writeSinglePage(pageIndex: number, data: number[], callback: AsyncCallback\<void>): void

Writes one page (4 bytes) of data to this tag. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                    |
| -------- | ----------------------- | ---- | ------------------------ |
| pageIndex | number | Yes  | Index of the page to write. The page indexes start from **0**.|
| data | number[] | Yes  | 4-byte data to write.|
| callback|AsyncCallback\<void> |Yes| Callback used to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct MIFARE Ultralight tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!mifareUltralight.isTagConnected()) {
        if (!mifareUltralight.connectTag()) {
            console.error("mifareUltralight connectTag failed.");
            return;
        }
    }

    try {
        let pageIndex = 1; // Set a correct index.
        let rawData = [0x01, 0x02, 0x03, 0x04];  // Set the correct data. The value must contain 4 bytes. 
        mifareUltralight.writeSinglePage(pageIndex, rawData, (err : BusinessError)=> {
        if (err) {
                console.error("mifareUltralight writeSinglePage AsyncCallback Code: ${err.code}," +
                    "message: ${err.message}");
            } else {
                console.info("mifareUltralight writeSinglePage AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("mifareUltralight writeSinglePage AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareUltralightTag.getType<sup>9+</sup>

getType(): [tag.MifareUltralightType](js-apis-nfcTag.md#mifareultralighttype9)

Obtains the type of this MIFARE Ultralight tag.

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [tag.MifareUltralightType](js-apis-nfcTag.md#mifareultralighttype9) | Type of the MIFARE Ultralight tag obtained.|

**Example**

```js
import { tag } from '@kit.ConnectivityKit';

// Obtain the correct MIFARE Ultralight tag by using the tag.TagInfo API in @ohos.nfc.tag.
let getType : tag.MifareUltralightType = mifareClassic.getType();
console.info("mifareUltralight getType: " + getType);
```

## NdefFormatableTag<sup>9+</sup>

Provides APIs for formatting NDEF formattable tags. This class inherits from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **NdefFormatableTag**.

### NdefFormatableTag.format<sup>9+</sup>

format(message: [NdefMessage](#ndefmessage9)): Promise\<void>

Formats this tag as an NDEF tag, and writes an NDEF message to it. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write. If this parameter is **null**, the tag is formatted only (no data will be written).|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct NDEF Formatable tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!ndefFormatable.isTagConnected()) {
        if (!ndefFormatable.connectTag()) {
            console.error("ndefFormatable connectTag failed.");
            return;
        }
    }

    try {
        // ndefMessage created from the raw data. For example:
        let ndefMessage = tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]);  
        // The NDEF data must be resolvable.
        // Or create ndefMessage from tag.ndef.createNdefMessage (ndefRecords:NdefRecord[]).

        ndefFormatable.format(ndefMessage).then(() => {
            console.info("ndefFormatable format Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("ndefFormatable format Promise err Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("ndefFormatable format Promise catch businessError Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### NdefFormatableTag.format<sup>9+</sup>

format(message: [NdefMessage](#ndefmessage9), callback: AsyncCallback\<void>): void

Formats this tag as an NDEF tag, and writes an NDEF message to it. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write when the formatting is successful. If this parameter is **null**, the tag is formatted only (no data will be written).|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| callback: AsyncCallback\<void> | Callback used to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct NDEF Formatable tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!ndefFormatable.isTagConnected()) {
        if (!ndefFormatable.connectTag()) {
            console.error("ndefFormatable connectTag failed.");
            return;
        }
    }

    try {
        // ndefMessage created from the raw data. For example:
        let ndefMessage = tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]);  // The NDEF data must be resolvable.
        // Or create ndefMessage from tag.ndef.createNdefMessage (ndefRecords:NdefRecord[]).

        ndefFormatable.format(ndefMessage, (err : BusinessError)=> {
            if (err) {
                console.error("ndefFormatable format AsyncCallback Code: ${err.code}, message: ${err.message}");
            } else {
                console.info("ndefFormatable format AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("ndefFormatable format AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### NdefFormatableTag.formatReadOnly<sup>9+</sup>

formatReadOnly(message: [NdefMessage](#ndefmessage9)): Promise\<void>

Formats this tag as an NDEF tag, writes an NDEF message to it, and then sets the tag to read-only. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write. If this parameter is **null**, the tag is formatted only (no data will be written).|

**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<void> | Promise that returns no value.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct NDEF Formatable tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!ndefFormatable.isTagConnected()) {
        if (!ndefFormatable.connectTag()) {
            console.error("ndefFormatable connectTag failed.");
            return;
        }
    }

    try {
        // ndefMessage created from the raw data. For example:
        let ndefMessage = tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]);
        // The NDEF data must be resolvable.
        // Or create ndefMessage from tag.ndef.createNdefMessage (ndefRecords:NdefRecord[]).

        ndefFormatable.formatReadOnly(ndefMessage).then(() => {
            console.info("ndefFormatable formatReadOnly Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("ndefFormatable formatReadOnly Promise Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("ndefFormatable formatReadOnly Promise catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### NdefFormatableTag.formatReadOnly<sup>9+</sup>

formatReadOnly(message: [NdefMessage](#ndefmessage9), callback: AsyncCallback\<void>): void

Formats this tag as an NDEF tag, writes an NDEF message to the NDEF tag, and then sets the tag to read-only. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | Yes  | NDEF message to write. If this parameter is **null**, the tag is formatted only (no data will be written).|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| callback: AsyncCallback\<void> | Callback used to return the result.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |

**Example**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// Obtain the correct NDEF Formatable tag by using the tag.TagInfo API in @ohos.nfc.tag.

function nfcTechDemo() {
    // Connect the tag if it has not been connected.
    if (!ndefFormatable.isTagConnected()) {
        if (!ndefFormatable.connectTag()) {
            console.error("ndefFormatable connectTag failed.");
            return;
        }
    }

    try {
        // ndefMessage created from the raw data. For example:
        let ndefMessage = tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]);
        // The NDEF data must be resolvable.
        // Or create ndefMessage from tag.ndef.createNdefMessage (ndefRecords:NdefRecord[]).

        ndefFormatable.formatReadOnly(ndefMessage, (err : BusinessError)=> {
            if (err) {
                console.error("ndefFormatable formatReadOnly AsyncCallback err Code: ${err.code}, message: ${err.message}");
            } else {
                console.info("ndefFormatable formatReadOnly AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("ndefFormatable formatReadOnly AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

## BarcodeTag<sup>18+</sup>

Provides the capability of reading barcode label attributes and accessing I/O operations. It is inherited from **TagSession**.

**TagSession** is the base class of all NFC tag technologies. It provides common interfaces for establishing connections and transferring data. For more details, see [TagSession](js-apis-tagSession.md).

The following describes the unique APIs of **BarcodeTag**.

### BarcodeTag.getBarcode<sup>18+</sup>

getBarcode(): Promise\<ArrayBuffer>

Obtains a complete barcode tag. This API uses a promise to return the result.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Tag

**Atomic service API**: This API can be used in atomic services since API version 18.


**Return value**

| Type                       | Description                |
| ------------------------- | ------------------ |
| Promise\<ArrayBuffer> | Promise used to return the barcode tag read.|

**Error codes**

For details about the error codes, see [NFC Error Codes](errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 201  | Permission denied. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100204 | The tag I/O operation failed. |
| 3100205 | The tag leaves the field. |
