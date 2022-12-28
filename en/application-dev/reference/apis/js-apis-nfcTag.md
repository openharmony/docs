# @ohos.nfc.tag

The **nfcTag** module provides APIs for managing Near-Field Communication (NFC) tags.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## **Declaration**

Before developing applications related to tag read and write, you must declare NFC-related attributes in the attribute configuration file of the applications. For example, declare the following attributes in the **module.json5** file:
```js
{
    "module": {
        // Attributes to declare.

        "abilities": [
            {
                "skills": [
                    {
                        "actions": [
                            // Actions to declare.

                            // Add the nfc tag action.
                            "ohos.nfc.tag.action.TAG_FOUND"
                        ]
                    }
                ],
                "metadata": [
                    {
                        "name": "tag-tech",
                        "value": "NfcA"
                    },
                    {
                        "name": "tag-tech",
                        "value": "IsoDep"
                    },
                    // Add other technologies,
                    // such as NfcB, NfcF, NfcV, Ndef, MifareClassic, MifareUL, and NdefFormatable.
                ]
            }
        ],
        "requestPermissions": [
            "name": "ohos.permission.NFC_TAG",
            "reason": "tag",
        ]
    }
}
```
> **CAUTION**<br>
1. The **actions** field is mandatory. It must be **ohos.nfc.tag.action.TAG_FOUND** and cannot be changed.
2. The **name** field under **metadata** is mandatory. It must be **tag-tech** and cannot be changed.
3. The **value** field under **metadata** is mandatory. It can be **NfcA**, **NfcB**, **NfcF**, **NfcV**, **IsoDep**, **Ndef**, **MifareClassic**, **MifareUL**, **NdefFormatable** or any of their combinations. Incorrect settings of this field will cause a parsing failure.
4. The **name** field under **requestPermissions** is mandatory. It must be **ohos.permission.NFC_TAG** and cannot be changed.

## **Modules to Import**

```js
import tag from '@ohos.nfc.tag';
```

## **tag.TagInfo**

Before a card with tags is read or written, **TagInfo** must be obtained to determine the tag technologies supported by the card. In this way, the application can invoke the correct API to communicate with the card.
```js
import tag from '@ohos.nfc.tag';

onCreate(want, launchParam) {
    // Add other code here.

    // want is initialized by the NFC service and contains tagInfo.
    var tagInfo;
    try {
        tagInfo = tag.getTagInfo(want);
    } catch (error) {
        console.log("tag.getTagInfo catched error: " + error);
    }
    if (tagInfo == null || tagInfo == undefined) {
        console.log("no TagInfo to be created, ignore it.");
        return;
    }

    // get the supported technologies for this found tag.
    var isNfcATag =  false;
    var isIsoDepTag =  false;
    for (var i = 0; i < tagInfo.technology.length; i++) {
        if (tagInfo.technology[i] == tag.NFC_A) {
            isNfcATag = true;
        }

        if (tagInfo.technology[i] == tag.ISO_DEP) {
            isIsoDepTag = true;
        }
        // Also check for technology tag.NFC_B, NFC_F, NFC_V, ISO_DEP, NDEF, MIFARE_CLASSIC, MIFARE_ULTRALIGHT, and NDEF_FORMATABLE.
    }

    // use NfcA APIs to access the found tag.
    if (isNfcATag) {
        var nfcA;
        try {
            nfcA = tag.getNfcATag(taginfo);
        } catch (error) {
            console.log("tag.getNfcATag catched error: " + error);
        }
        // Other code to read or write this tag.
    }

    // use getIsoDep APIs to access the found tag.
    if (isIsoDepTag) {
        var isoDep;
        try {
            isoDep = tag.getIsoDep(taginfo);
        } catch (error) {
            console.log("tag.getIsoDep catched error: " + error);
        }
        // Other code to read or write this tag.
    }

    // Use the same code to handle "NfcA/NfcB/NfcF/NfcV/Ndef/MifareClassic/MifareUL/NdefFormatable".
}
```

## tag.getNfcATag

getNfcATag(tagInfo: [TagInfo](#taginfo)): [NfcATag](js-apis-nfctech.md#nfcatag)

Obtains an **NfcATag** object, which allows access to the tags that use the NFC-A technology.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| [NfcATag](js-apis-nfctech.md#nfcatag) | **NfcATag** object obtained.|

## tag.getNfcBTag

getNfcBTag(tagInfo: [TagInfo](#taginfo)): [NfcBTag](js-apis-nfctech.md#nfcbtag)

Obtains an **NfcBTag** object, which allows access to the tags that use the NFC-B technology.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**        |
| -------- | ---------------- |
| [NfcBTag](js-apis-nfctech.md#nfcbtag)  | **NfcBTag** object obtained.|

## tag.getNfcFTag

getNfcFTag(tagInfo: [TagInfo](#taginfo)): [NfcFTag](js-apis-nfctech.md#nfcftag)

Obtains an **NfcFTag** object, which allows access to the tags that use the NFC-F technology.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**        |
| -------- | ---------------- |
| [NfcFTag](js-apis-nfctech.md#nfcftag)  | **NfcFTag** object obtained.|

## tag.getNfcVTag

getNfcVTag(tagInfo: [TagInfo](#taginfo)): [NfcVTag](js-apis-nfctech.md#nfcvtag)

Obtains an **NfcVTag** object, which allows access to the tags that use the NFC-V technology.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**        |
| -------- | ---------------- |
| [NfcVTag](js-apis-nfctech.md#nfcvtag)  | **NfcVTag** object obtained.|

## tag.getIsoDep<sup>9+</sup>

getIsoDep(tagInfo: [TagInfo](#taginfo)): [IsoDepTag](js-apis-nfctech.md#isoDepTag9 )

Obtains an **IsoDepTag** object, which allows access to the tags that use the ISO-DEP technology.

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name      | Type                       | Mandatory  | Description                                      |
| --------- | ------------------------- | ---- | ---------------------------------------- |
| taginfo      | [TagInfo](#taginfo)                   | Yes| Tag information including the technology type and related parameters, which are obtained from **tag.getTagInfo(want: Want)**.                             |

**Return value**

| **Type**| **Description**           |
| ---------- | ------------------|
| [IsoDepTag](js-apis-nfctech.md#isodeptag9)  | **IsoDepTag** object obtained.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

## tag.getNdef<sup>9+</sup>

getNdef(tagInfo: [TagInfo](#taginfo)): [NdefTag](js-apis-nfctech.md#ndeftag9)

Obtains an **NdefTag** object, which allows access to the tags in the NFC Data Exchange Format (NDEF).

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name      | Type                       | Mandatory  | Description                                      |
| --------- | ------------------------- | ---- | ---------------------------------------- |
| taginfo      | [TagInfo](#taginfo)                   | Yes   | Tag information including the technology type and related parameters, which are obtained from **tag.getTagInfo(want: Want)**.                             |

**Return value**

| **Type**| **Description**       |
| ---------| -------------- |
| [NdefTag](js-apis-nfctech.md#ndeftag9)  | **NdefTag** object obtained.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

## tag.getMifareClassic<sup>9+</sup>

getMifareClassic(tagInfo: [TagInfo](#taginfo)): [MifareClassicTag](js-apis-nfctech.md#mifareclassictag-9)

Obtains a **MifareClassicTag** object, which allows access to the tags that use MIFARE Classic.

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name      | Type                       | Mandatory  | Description                                      |
| --------- | ------------------------- | ---- | ---------------------------------------- |
| taginfo      | [TagInfo](#taginfo)                   | Yes   | Tag information including the technology type and related parameters, which are obtained from **tag.getTagInfo(want: Want)**.                             |

**Return value**

| **Type**| **Description**                         |
| ----------------- | ------------------------|
| [MifareClassicTag](js-apis-nfctech.md#mifareclassictag-9)  | **MifareClassicTag** object obtained.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

## tag.getMifareUltralight<sup>9+</sup>

getMifareUltralight(tagInfo: [TagInfo](#taginfo)): [MifareUltralightTag](js-apis-nfctech.md#mifareultralighttag9)

Obtains a **MifareUltralightTag** object, which allows access to the tags that use MIFARE Ultralight.

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**
| Name      | Type                       | Mandatory  | Description                                      |
| --------- | ------------------------- | ---- | ---------------------------------------- |
| taginfo      | [TagInfo](#taginfo)                   | Yes   | Tag information including the technology type and related parameters, which are obtained from **tag.getTagInfo(want: Want)**.                             |

**Return value**

| **Type**| **Description**                               |
| -------------------- | ---------------------------|
| [MifareUltralightTag](js-apis-nfctech.md#mifareultralighttag9)  | **MifareUltralightTag** object obtained.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

## tag.getNdefFormatable<sup>9+</sup>

getNdefFormatable(tagInfo: [TagInfo](#taginfo)): [NdefFormatableTag](js-apis-nfctech.md#ndefformatabletag9)

Obtains an **NdefFormatableTag** object, which allows access to the tags that are NDEF formattable.

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefFormatableTag](js-apis-nfctech.md#ndefformatabletag)  | **NdefFormatableTag** object obtained.|

**Error codes**

For details about the error codes, see [NFC Error Codes](../errorcodes/errorcode-nfc.md).

| ID| Error Message|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

## tag.getTagInfo<sup>9+</sup>

getTagInfo(want: [Want](js-apis-app-ability-want.md#Want)): [TagInfo](#taginfo)

Obtains **TagInfo** from **Want**, which is initialized by the NFC service and contains the attributes required by **TagInfo**.

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name      | Type                       | Mandatory  | Description                                      |
| --------- | ------------------------- | ---- | ---------------------------------------- |
| want      | [Want](js-apis-app-ability-want.md#Want)                   | Yes   | Data obtained from the parameters of the **onCreate** entry function when an ability is dispatched.                             |

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [TagInfo](#taginfo) | **TagInfo** object obtained.|


## tag.ndef.makeUriRecord<sup>9+</sup>

makeUriRecord(uri: string): [NdefRecord](#ndefrecord9);

Creates an NDEF record based on the specified URI.

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| uri | string | Yes| Data to write to the NDEF record.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefRecord](#ndefrecord9) | NDEF record created. For details, see *NFCForum-TS-NDEF_1.0*.|

**Example**

```js
import tag from '@ohos.nfc.tag';

try {
    let uri = "https://gitee.com/openharmony"; // change it to be correct.
    let ndefRecord = tag.ndef.makeUriRecord(uri);
    if (ndefRecord != undefined) {
        console.log("ndefMessage makeUriRecord rtdType: " + ndefRecord.rtdType);
        console.log("ndefMessage makeUriRecord payload: " + ndefRecord.payload);
    } else {
        console.log("ndefMessage makeUriRecord ndefRecord: " + ndefRecord);
    }
} catch (busiError) {
    console.log("ndefMessage makeUriRecord catched busiError: " + busiError);
}
```

## tag.ndef.makeTextRecord<sup>9+</sup>

makeTextRecord(text: string, locale: string): [NdefRecord](#ndefrecord9);

Creates an NDEF record based on the specified text data and encoding type.

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| text | string | Yes  | Text to write to the NDEF record.|
| locale | string | Yes  | Encoding mode of the text.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefRecord](#ndefrecord9) | NDEF record created. For details, see *NFCForum-TS-NDEF_1.0*.|

**Example**

```js
import tag from '@ohos.nfc.tag';

try {
    let text = "Hello World";   // change it to be correct.
    let locale = "en"; // change it to be correct.
    let ndefRecord = tag.ndef.makeTextRecord(text, locale);
    if (ndefRecord != undefined) {
        console.log("ndefMessage makeTextRecord rtdType: " + ndefRecord.rtdType);
        console.log("ndefMessage makeTextRecord payload: " + ndefRecord.payload);
    } else {
        console.log("ndefMessage makeTextRecord ndefRecord: " + ndefRecord);
    }
} catch (busiError) {
    console.log("ndefMessage makeTextRecord catched busiError: " + busiError);
}
```


## tag.ndef.makeMimeRecord<sup>9+</sup>

makeMimeRecord(mimeType: string, mimeData: number[]): [NdefRecord](#ndefrecord9);

Creates an NDEF record based on the specified MIME data and type.

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| mimeType | string | Yes  | MIME type that complies with RFC rules, for example, **text/plain** or **image/jpeg**.|
| mimeData | number[] | Yes  | MIME data, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefRecord](#ndefrecord9) | NDEF record created. For details, see *NFCForum-TS-NDEF_1.0*.|

**Example**

```js
import tag from '@ohos.nfc.tag';

try {
    let mimeType = "text/plain";   // change it to be correct.
    let mimeData = [0x01, 0x02, 0x03, 0x04]; // change it to be correct.
    let ndefRecord = tag.ndef.makeMimeRecord(mimeType, mimeData);
    if (ndefRecord != undefined) {
        console.log("ndefMessage makeMimeRecord rtdType: " + ndefRecord.rtdType);
        console.log("ndefMessage makeMimeRecord payload: " + ndefRecord.payload);
    } else {
        console.log("ndefMessage makeMimeRecord ndefRecord: " + ndefRecord);
    }
} catch (busiError) {
    console.log("ndefMessage makeMimeRecord catched busiError: " + busiError);
}
```
## tag.ndef.makeExternalRecord<sup>9+</sup>

makeExternalRecord(domainName: string, type: string, externalData: number[]): [NdefRecord](#ndefrecord9);

Creates an NDEF record based on application-specific data.

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| domainName | string | Yes  | Bundle name of the application or domain name of the organization that releases the applications.|
| type | string | Yes  | Type of the application data.|
| externalData | number[] | Yes  | Application data, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefRecord](#ndefrecord9) | NDEF record created. For details, see *NFCForum-TS-NDEF_1.0*.|

**Example**

```js
import tag from '@ohos.nfc.tag';

try {
    let domainName = "ohos.nfc.application"; // change it to be correct.
    let type = "test"; // change it to be correct.
    let externalData = [0x01, 0x02, 0x03, 0x04]; // change it to be correct.
    let ndefRecord = tag.ndef.makeExternalRecord(domainName, type, externalData);
    if (ndefRecord != undefined) {
        console.log("ndefMessage makeExternalRecord rtdType: " + ndefRecord.rtdType);
        console.log("ndefMessage makeExternalRecord payload: " + ndefRecord.payload);
    } else {
        console.log("ndefMessage makeExternalRecord ndefRecord: " + ndefRecord);
    }
} catch (busiError) {
    console.log("ndefMessage makeExternalRecord catched busiError: " + busiError);
}
```

## tag.ndef.messageToBytes<sup>9+</sup>

messageToBytes(ndefMessage: [NdefMessage](js-apis-nfctech.md#ndefmessage9)): number[];

Converts an NDEF message to bytes.

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                  |
| -------- | ----------------------- | ---- | -------------------------------------- |
| ndefMessage | [NdefMessage](js-apis-nfctech.md#ndefmessage9) | Yes  | NDEF message to convert.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| number[] | NDEF message in bytes, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

**Example**

```js
import tag from '@ohos.nfc.tag';

let rawData = [0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]; // MUST can be parsed as NDEF Record.
let ndefMessage;
try {
    ndefMessage = tag.ndef.createNdefMessage(rawData);
    console.log("ndef createNdefMessage, ndefMessage: " + ndefMessage);
} catch (busiError) {
    console.log("ndef createNdefMessage busiError: " + busiError);
}

try {
    let rawData2 = tag.ndef.messageToBytes(ndefMessage);
    console.log("ndefMessage messageToBytes rawData2: " + rawData2);
} catch (busiError) {
    console.log("ndefMessage messageToBytes catched busiError: " + busiError);
}
```
## tag.ndef.createNdefMessage<sup>9+</sup>

createNdefMessage(data: number[]): [NdefMessage](js-apis-nfctech.md#ndefmessage9)

Creates an NDEF message from raw byte data. The data must comply with the NDEF record format. Otherwise, the NDE record list contained in the **NdefMessage** object will be empty.

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| data | number[] | Yes| Raw byte data, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**. The data must comply with the NDEF record format.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefMessage](js-apis-nfctech.md#ndefmessage9) | NDEF message created. For details, see *NFCForum-TS-NDEF_1.0*.|

**Example**
```js
import tag from '@ohos.nfc.tag';

let rawData = [0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43];  // MUST can be parsed as NDEF Record.
let ndefMessage;
try {
    ndefMessage = tag.ndef.createNdefMessage(rawData);
    console.log("ndef createNdefMessage, ndefMessage: " + ndefMessage);
} catch (busiError) {
    console.log("ndef createNdefMessage busiError: " + busiError);
}
```

## tag.ndef.createNdefMessage<sup>9+</sup>

createNdefMessage(ndefRecords: NdefRecord[]): [NdefMessage](js-apis-nfctech.md#ndefmessage9)

Creates an NDEF message from the NDEF records list.

**System capability**: SystemCapability.Communication.NFC.Core

**Parameters**

| **Name**| **Type**| **Mandatory**| **Description**|
| -------- | -------- | -------- | -------- |
| ndefRecords | [NdefRecord](js-apis-nfcTag.md#ndefrecord9)[] | Yes| NDEF record list used to create the NDEF message. For details, see *NFCForum-TS-NDEF_1.0*.|

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefMessage](js-apis-nfctech.md#ndefmessage9) | NDEF message created. For details, see *NFCForum-TS-NDEF_1.0*.|

**Example**

```js
import tag from '@ohos.nfc.tag';

let uriRecord = tag.ndef.makeUriRecord("https://gitee.com/openharmony");
let textRecord = tag.ndef.makeTextRecord("Hello World", "en");
let ndefRecords = [uriRecord, textRecord];
let ndefMessage;
try {
    ndefMessage = tag.ndef.createNdefMessage(ndefRecords);
    console.log("ndef createNdefMessage ndefMessage: " + ndefMessage);
} catch (busiError) {
    console.log("ndef createNdefMessage busiError: " + busiError);
}
```

## TagInfo

Defines the **TagInfo** object, which provides information about the tag technologies supported by a card.

**System capability**: SystemCapability.Communication.NFC.Core

**Required permissions**: ohos.permission.NFC_TAG

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| uid<sup>9+</sup> | number[] | Yes| No| Tag unique identifier (UID), which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|
| technology<sup>9+</sup> | number[] | Yes| No| Supported technologies. Each number is a constant indicating the supported technology.|
| supportedProfiles | number[] | Yes| No|  Supported profiles. This parameter is not supported since API version 9. Use [tag.TagInfo#technology](#taginfo) instead.|
| extrasData<sup>9+</sup> | [PacMap](js-apis-inner-ability-dataAbilityHelper.md#pacmap)[] | Yes| No|  Extended attribute value of the tag technology.<br>**System API**: This is a system API.|
| tagRfDiscId<sup>9+</sup> | number | Yes| No|  ID allocated when the tag is discovered.<br>**System API**: This is a system API.|
| remoteTagService<sup>9+</sup> | [rpc.RemoteObject](js-apis-rpc.md#remoteobject) | Yes| No| Remote object of the NFC service process used for interface communication between the client and the service.<br>**System API**: This is a system API.|
## NdefRecord<sup>9+</sup>
Defines an NDEF record. For details, see *NFCForum-TS-NDEF_1.0*.

**System capability**: SystemCapability.Communication.NFC.Core

| **Name**| **Type**| **Readable**| **Writable**| **Description**|
| -------- | -------- | -------- | -------- | -------- |
| tnf | number | Yes| No| Type name field (TNF) of the NDEF record.|
| rtdType| number[] | Yes| No| Record type definition (RTD) of the NDEF record. It consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|
| id | number[] | Yes| No| NDEF record ID, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|
| payload | number[] | Yes| No| NDEF payload, which consists of hexadecimal numbers ranging from **0x00** to **0xFF**.|

## Technology Type Definition
Enumerates the tag technology types.

**System capability**: SystemCapability.Communication.NFC.Core

| **Name**| **Value**|  **Description**|
| -------- | -------- | -------- |
| NFC_A | 1 | NFC-A (ISO 14443-3A).|
| NFC_B  | 2 | NFC-B (ISO 14443-3B).|
| ISO_DEP | 3 | ISO-DEP (ISO 14443-4).|
| NFC_F  | 4 | NFC-F (JIS 6319-4).|
| NFC_V | 5 | NFC-V (ISO 15693).|
| NDEF  | 6 | NDEF.|
| NDEF_FORMATABLE<sup>9+</sup> | 7 | NDEF formattable.|
| MIFARE_CLASSIC | 8 | MIFARE Classic.|
| MIFARE_ULTRALIGHT | 9 | MIFARE Ultralight.|

## TnfType<sup>9+</sup>
Enumerates the TNF types. For details, see *NFCForum-TS-NDEF_1.0*.

**System capability**: SystemCapability.Communication.NFC.Core

| **Name**| **Value**|  **Description**|
| -------- | -------- | -------- |
| TNF_EMPTY | 0x0 | Empty.|
| TNF_WELL_KNOWN  | 0x1 | NFC Forum Well Known Type [NFC RTD].|
| TNF_MEDIA | 0x2 | Media-type as defined in RFC 2046 [RFC 2046].|
| TNF_ABSOLUTE_URI  | 0x3 | Absolute URI as defined in RFC 3986 [RFC 3986].|
| TNF_EXT_APP | 0x4 | NFC Forum external type [NFC RTD].|
| TNF_UNKNOWN  | 0x5 | Unknown.|
| TNF_UNCHANGED | 0x6 | Unchanged (see section 2.3.3 in *NFCForum-TS-NDEF_1.0*).|

## NDEF Record RTD
Enumerates the NDEF record types. For details about the RTD, see *NFCForum-TS-NDEF_1.0*.

**System capability**: SystemCapability.Communication.NFC.Core

| **Name**| **Value**|  **Description**|
| -------- | -------- | -------- |
| RTD_TEXT<sup>9+</sup> | [0x54] | NDEF record of the text type.|
| RTD_URI<sup>9+</sup>  | [0x55] | NDEF record of the URI type.|

## NfcForumType<sup>9+</sup>
Enumerates the NFC Forum tag types.

**System capability**: SystemCapability.Communication.NFC.Core

| **Name**| **Value**|  **Description**|
| -------- | -------- | -------- |
| NFC_FORUM_TYPE_1 | 1 |  NFC Forum tag type 1.|
| NFC_FORUM_TYPE_2 | 2 |  NFC Forum tag type 2.|
| NFC_FORUM_TYPE_3  | 3 |  NFC Forum tag type 3.|
| NFC_FORUM_TYPE_4  | 4 |  NFC Forum tag type 4.|
| MIFARE_CLASSIC  | 101 |   MIFARE Classic.|

## MifareClassicType<sup>9+</sup>
Enumerates the MIFARE Classic tag types.

**System capability**: SystemCapability.Communication.NFC.Core

| **Name**| **Value**|  **Description**|
| -------- | -------- | -------- |
| TYPE_UNKNOWN | 0 |  Unknown type.|
| TYPE_CLASSIC | 1 |  MIFARE Classic.|
| TYPE_PLUS   | 2 |  MIFARE Plus.|
| TYPE_PRO  | 3 |  MIFARE Pro.|

## MifareClassicSize<sup>9+</sup>
Enumerates the sizes of MIFARE Classic tags.

**System capability**: SystemCapability.Communication.NFC.Core

| **Name**| **Value**|  **Description**|
| -------- | -------- | -------- |
| MC_SIZE_MINI | 320 |  Each tag has 5 sectors, and each sector has 4 blocks.|
| MC_SIZE_1K  | 1024 |  Each tag has 16 sectors, and each sector has 4 blocks.|
| MC_SIZE_2K   | 2048 |  Each tag has 32 sectors, and each sector has 4 blocks.|
| MC_SIZE_4K   | 4096 |  Each tag has 40 sectors, and each sector has 4 blocks.|

## MifareUltralightType<sup>9+</sup>
Enumerates the MIFARE Ultralight tag types.

**System capability**: SystemCapability.Communication.NFC.Core

| **Name**| **Value**|  **Description**|
| -------- | -------- | -------- |
| TYPE_UNKNOWN  | 0 |  Unknown type.|
| TYPE_ULTRALIGHT   | 1 |  MIFARE Ultralight.|
| TYPE_ULTRALIGHT_C    | 2 |  MIFARE Ultralight C.|
<!--no_check-->
