# NFC Tags

The **nfcTag** module provides APIs for managing Near-Field Communication (NFC) tags.

> **NOTE**<br>
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
>
> - The **actions** field is mandatory. It must be **ohos.nfc.tag.action.TAG_FOUND** and cannot be changed.
> - The **name** field of **metadata** is mandatory. It must be **tag-tech** and cannot be changed.
> - The **value** field of **metadata** is mandatory. It can be **NfcA**, **NfcB**, **NfcF**, **NfcV**, **IsoDep**, **Ndef**, **MifareClassic**, **MifareUL**, **NdefFormatable** or their combinations. Incorrect setting of this field will cause a parsing failure.
> - The **name** field of **requestPermissions** is mandatory. It must be **ohos.permission.NFC_TAG** and cannot be changed.


## **Modules to Import**

```js
import tag from '@ohos.nfc.tag';
```

## **tag.TagInfo**
Before reading or writing data to a card with tags, the application must obtain **TagInfo** to determine the tag technologies supported by the card. Then, the application can invoke the correct API to communicate with the card.
```js
import tag from '@ohos.nfc.tag';

onCreate(want, launchParam) {
    // Add other code here.

    // want is initialized by the NFC service and contains taginfo.
    var tagInfo = tag.getTagInfo(want);
    if (tagInfo == undefined) {
        console.log("no TagInfo to be created, ignore it.");
        return;
    }
    var isNfcATag =  false;
    for (var i = 0; i < tagInfo.technology.length; i++) {
        if (tagInfo.technology[i] == tag.NFC_A) {
            isNfcATag = true;
            break;
        }
        // Also check for technology tag.NFC_B, NFC_F, NFC_V, ISO_DEP, NDEF, MIFARE_CLASSIC, MIFARE_ULTRALIGHT, and NDEF_FORMATABLE.
    }
    if (isNfcATag) {
        var nfcA = tag.getNfcATag(taginfo);
        // Other code to read or write this tag.
    }

    // use the same code to handle "NfcA/NfcB/NfcF/NfcV/IsoDep/Ndef/MifareClassic/MifareUL/NdefFormatable", such as,
    // var isoDep = tag.getIsoDepTag(taginfo);
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

## tag.getIsoDepTag<sup>9+</sup>

getIsoDepTag(tagInfo: [TagInfo](#taginfo)): [IsoDepTag](js-apis-nfctech.md#isoDepTag9 )

Obtains an **IsoDepTag** object, which allows access to the tags that use the ISO-DEP technology.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**           |
| ---------- | ------------------|
| [IsoDepTag](js-apis-nfctech.md#isodeptag9)  | **IsoDepTag** object obtained.|

## tag.getNdefTag<sup>9+</sup>

getNdefTag(tagInfo: [TagInfo](#taginfo)): [NdefTag](js-apis-nfctech.md#ndeftag9)

Obtains an **NdefTag** object, which allows access to the tags in the NFC Data Exchange Format (NDEF).


**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**       |
| ---------| -------------- |
| [NdefTag](js-apis-nfctech.md#ndeftag9)  | **NdefTag** object obtained.|

## tag.getMifareClassicTag<sup>9+</sup>

getMifareClassicTag(tagInfo: [TagInfo](#taginfo)): [MifareClassicTag](js-apis-nfctech.md#mifareclassictag-9)

Obtains a **MifareClassicTag** object, which allows access to the tags that use MIFARE Classic.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                         |
| ----------------- | ------------------------|
| [MifareClassicTag](js-apis-nfctech.md#mifareclassictag-9)  | **MifareClassicTag** object obtained.|

## tag.getMifareUltralightTag<sup>9+</sup>

getMifareUltralightTag(tagInfo: [TagInfo](#taginfo)): [MifareUltralightTag](js-apis-nfctech.md#mifareultralighttag9)

Obtains a **MifareUltralightTag** object, which allows access to the tags that use MIFARE Ultralight.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                               |
| -------------------- | ---------------------------|
| [MifareUltralightTag](js-apis-nfctech.md#mifareultralighttag9)  | **MifareUltralightTag** object obtained.|

## tag.getNdefFormatableTag<sup>9+</sup>

getNdefFormatableTag(tagInfo: [TagInfo](#taginfo)): [NdefFormatableTag](js-apis-nfctech.md#ndefformatabletag9)

Obtains an **NdefFormatableTag** object, which allows access to the tags that are NDEF formattable.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefFormatableTag](js-apis-nfctech.md#ndefformatabletag)  | **NdefFormatableTag** object obtained.|

## tag.getTagInfo<sup>9+</sup>

getTagInfo(want: Want): [TagInfo](#taginfo)

Obtains **TagInfo** from **Want**, which is initialized by the NFC service and contains the attributes required by **TagInfo**.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [TagInfo](#taginfo) | **TagInfo** object obtained.|

## TagInfo

Defines the **TagInfo** object, which provides information about the tag technologies supported by a card.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

| **Name**| **Type**|  **Description**|
| -------- | -------- | -------- |
| uid<sup>9+</sup> | number[] |  Tag unique identifier (UID). Each number of the UID is a hexadecimal number ranging from **0x00** to **0xFF**.|
| technology<sup>9+</sup> | number[] |  Supported technologies. Each number is a constant indicating the supported technology.|
| supportedProfiles | number[] |  Supported technologies. This parameter is not supported since API version 9 and is replaced by **technology**.|

## NdefRecord<sup>9+</sup>
Defines an NDEF tag record. For details, see *NFCForum-TS-NDEF_1.0*.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core
| **Name**| **Type**|  **Description**|
| -------- | -------- | -------- |
| tnf | number |  Type name field (TNF) of an NDEF record.|
| rtdType| number[] |  Record type definition (RTD) of an NDEF record. Each number is a hexadecimal number ranging from **0x00** to **0xFF**.|
| id | number[] |  ID of an NDEF record. Each number is a hexadecimal number ranging from **0x00** to **0xFF**.|
| payload | number[] |  Payload of an NDEF record. Each number is a hexadecimal number ranging from **0x00** to **0xFF**.|

## Technology Type Definition
Enumerates the tag technology types.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core
| **Name**| **Value**|  **Description**|
| -------- | -------- | -------- |
| NFC_A | 1 | NFC-A (ISO 14443-3A).|
| NFC_B  | 2 | NFC-A (ISO 14443-3B).|
| ISO_DEP | 3 | ISO-DEP (ISO 14443-4).|
| NFC_F  | 4 | NFC-F (JIS 6319-4).|
| NFC_V | 5 | NFC-V (ISO 15693).|
| NDEF  | 6 | NDEF.|
| MIFARE_CLASSIC | 8 | MIFARE Classic.|
| MIFARE_ULTRALIGHT | 9 | MIFARE Ultralight.|
| NDEF_FORMATABLE<sup>9+</sup> | 10 | NDEF formattable.|

## TnfType<sup>9+</sup>
Enumerates the TNF types. For details, see *NFCForum-TS-NDEF_1.0*.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core
| **Name**| **Value**|  **Description**|
| -------- | -------- | -------- |
| TNF_EMPTY | 0x0 | Empty.|
| TNF_WELL_KNOWN  | 0x01 | NFC Forum Well Known Type [NFC RTD].|
| TNF_MEDIA | 0x02 | Media-type as defined in RFC 2046 [RFC 2046].|
| TNF_ABSOLUTE_URI  | 0x03 | Absolute URI as defined in RFC 3986 [RFC 3986].|
| TNF_EXT_APP | 0x04 | NFC Forum external type [NFC RTD].|
| TNF_UNKNOWN  | 0x05 | Unknown.|
| TNF_UNCHANGED | 0x06 | Unchanged (see section 2.3.3).|

## NDEF Record RTD
Enumerates the NDEF record types. For details about the RTD, see *NFCForum-TS-NDEF_1.0*.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core
| **Name**| **Value**|  **Description**|
| -------- | -------- | -------- |
| RTD_TEXT<sup>9+</sup> | [0x54] | NDEF record of the text type.|
| RTD_URI<sup>9+</sup>  | [0x55] | NDEF record of the URI type.|

## NfcForumType<sup>9+</sup>
Enumerates the NFC Forum tag types.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core
| **Name**| **Value**|  **Description**|
| -------- | -------- | -------- |
| NFC_FORUM_TYPE_1 | 1 |  NFC Forum tag type 1.|
| NFC_FORUM_TYPE_2 | 2 |  NFC Forum tag type 2.|
| NFC_FORUM_TYPE_3  | 3 |  NFC Forum tag type 3.|
| NFC_FORUM_TYPE_4  | 4 |  NFC Forum tag type 4.|
| MIFARE_CLASSIC  | 101 |   MIFARE Classic type.|

## MifareClassicType<sup>9+</sup>
Enumerates the MIFARE Classic tag types.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core
| **Name**| **Value**|  **Description**|
| -------- | -------- | -------- |
| TYPE_UNKNOWN | -1 |  Unknown type.|
| TYPE_CLASSIC | 0 |  MIFARE Classic.|
| TYPE_PLUS   | 1 |  MIFARE Plus.|
| TYPE_PRO  | 2 |  MIFARE Pro.|

## MifareClassicSize<sup>9+</sup>
Enumerates the storage sizes of MIFARE Classic tags.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core
| **Name**| **Value**|  **Description**|
| -------- | -------- | -------- |
| MC_SIZE_MINI | 320 |  Each tag has 5 sectors, and each sector has 4 blocks.|
| MC_SIZE_1K  | 1024 |  Each tag has 16 sectors, and each sector has 4 blocks.|
| MC_SIZE_2K   | 2048 |  Each tag has 32 sectors, and each sector has 4 blocks.|
| MC_SIZE_4K   | 4096 |  Each tag has 40 sectors, and each sector has 4 blocks.|

### MifareUltralightType<sup>9+</sup>
Enumerates the MIFARE Ultralight tag types.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core
| **Name**| **Value**|  **Description**|
| -------- | -------- | -------- |
| TYPE_UNKOWN  | -1 |  Unknown type.|
| TYPE_ULTRALIGHT   | 1 |  MIFARE Ultralight.|
| TYPE_ULTRALIGHT_C    | 2 |  MIFARE Ultralight C.|
<!--no_check-->
