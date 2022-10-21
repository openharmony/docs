# NFC Tags

The **nfcTag** module provides APIs for managing Near-Field Communication (NFC) tags.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## **Modules to Import**

```js
import tag from '@ohos.nfc.tag';
```

## tag.getNfcATag

getNfcATag(tagInfo: [TagInfo](#taginfo9)): [NfcATag](js-apis-nfctech.md#nfcatag)

Obtains an **NfcATag** object, which allows access to the tags that use the NFC-A technology.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**|
| -------- | -------- |
| [NfcATag](js-apis-nfctech.md#nfcatag) | **NfcATag** object obtained.|

## tag.getNfcBTag

getNfcBTag(tagInfo: [TagInfo](#taginfo9)): [NfcBTag](js-apis-nfctech.md#nfcbtag)

Obtains an **NfcBTag** object, which allows access to the tags that use the NFC-B technology.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**        |
| -------- | ---------------- |
| [NfcBTag](js-apis-nfctech.md#nfcbtag)  | **NfcBTag** object obtained.|

## tag.getNfcFTag

getNfcFTag(tagInfo: [TagInfo](#taginfo9)): [NfcFTag](js-apis-nfctech.md#nfcftag)

Obtains an **NfcFTag** object, which allows access to the tags that use the NFC-F technology.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**        |
| -------- | ---------------- |
| [NfcFTag](js-apis-nfctech.md#nfcftag)  | **NfcFTag** object obtained.|

## tag.getNfcVTag

getNfcVTag(tagInfo: [TagInfo](#taginfo9)): [NfcVTag](js-apis-nfctech.md#nfcvtag)

Obtains an **NfcVTag** object, which allows access to the tags that use the NFC-V technology.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**        |
| -------- | ---------------- |
| [NfcVTag](js-apis-nfctech.md#nfcvtag)  | **NfcVTag** object obtained.|

## tag.getIsoDepTag<sup>9+</sup>

getIsoDepTag(tagInfo: [TagInfo](#taginfo9)): [IsoDepTag](js-apis-nfctech.md#isodeptag9 )

Obtains an **IsoDepTag** object, which allows access to the tags that use the ISO-DEP technology.


**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**           |
| ---------- | ------------------|
| [IsoDepTag](js-apis-nfctech.md#isodeptag9)  | **IsoDepTag** object obtained.|

## tag.getNdefTag<sup>9+</sup>

getNdefTag(tagInfo: [TagInfo](#taginfo9)): [NdefTag](js-apis-nfctech.md#ndeftag9)

Obtains an **NdefTag** object, which allows access to the tags in the NFC Data Exchange Format (NDEF).


**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**       |
| ---------| -------------- |
| [NdefTag](js-apis-nfctech.md#ndeftag9)  | **NdefTag** object obtained.|

## tag.getMifareClassicTag<sup>9+</sup>

getMifareClassicTag(tagInfo: [TagInfo](#taginfo9)): [MifareClassicTag](js-apis-nfctech.md#mifareclassictag-9)

Obtains a **MifareClassicTag** object, which allows access to the tags that use MIFARE Classic.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                         |
| ----------------- | ------------------------|
| [MifareClassicTag](js-apis-nfctech.md#mifareclassictag-9)  | **MifareClassicTag** object obtained.|

## tag.getMifareUltralightTag<sup>9+</sup>

getMifareUltralightTag(tagInfo: [TagInfo](#taginfo9)): [MifareUltralightTag](js-apis-nfctech.md#mifareultralighttag9)

Obtains a **MifareUltralightTag** object, which allows access to the tags that use MIFARE Ultralight.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                               |
| -------------------- | ---------------------------|
| [MifareUltralightTag](js-apis-nfctech.md#mifareultralighttag9)  | **MifareUltralightTag** object obtained.|

## tag.getNdefFormatableTag<sup>9+</sup>

getNdefFormatableTag(tagInfo: [TagInfo](#taginfo9)): [NdefFormatableTag](js-apis-nfctech.md#ndefformatabletag9)

Obtains an **NdefFormatableTag** object, which allows access to the tags that are NDEF formattable.

**Required permissions**: ohos.permission.NFC_TAG

**System capability**: SystemCapability.Communication.NFC.Core

**Return value**

| **Type**| **Description**                            |
| ------------------ | --------------------------|
| [NdefFormatableTag](js-apis-nfctech.md#ndefformatabletag)  | **NdefFormatableTag** object obtained.|

## TagInfo<sup>9+</sup>

Represents the NFC tag information.

| **Name**| **Type**|  **Description**|
| -------- | -------- | -------- |
| uid | string |  UID of the tag.|
| technology | number[] |  Technology supported by the tag.|
| extrasData | PacMap[] |  Additional information about the tag.|
| tagRfDiscId | number |  RF discovery ID of the tag.|
| remoteTagService | rpc.RemoteObject |  RPC remote object of the tag service.|
| supportedProfiles | number[] |  Profiles supported by the tag.|
