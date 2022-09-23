# 标准NFC-Tag

本模块主要用于操作及管理NFC Tag。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## **导入模块**

```js
import tag from '@ohos.nfc.tag';
```

## tag.getNfcATag

getNfcATag(tagInfo: [TagInfo](#taginfo7)): [NfcATag](js-apis-nfctech.md#nfcatag)

获取NFC A类型Tag对象，通过该对象可访问NfcA技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| [NfcATag](js-apis-nfctech.md#nfcatag) | NFC A类型Tag对象。 |

## tag.getNfcBTag

getNfcBTag(tagInfo: [TagInfo](#taginfo7)): [NfcBTag](js-apis-nfctech.md#nfcbtag)

获取NFC B类型Tag对象，通过该对象可访问NfcB技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**         |
| -------- | ---------------- |
| [NfcBTag](js-apis-nfctech.md#nfcbtag)  | NFC B类型Tag对象。 |

## tag.getNfcFTag

getNfcFTag(tagInfo: [TagInfo](#taginfo7)): [NfcFTag](js-apis-nfctech.md#nfcftag)

获取NFC F类型Tag对象，通过该对象可访问NfcF技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**         |
| -------- | ---------------- |
| [NfcFTag](js-apis-nfctech.md#nfcftag)  | NFC F类型Tag对象。 |

## tag.getNfcVTag

getNfcVTag(tagInfo: [TagInfo](#taginfo7)): [NfcVTag](js-apis-nfctech.md#nfcvtag)

获取NFC V类型Tag对象，通过该对象可访问NfcV技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**         |
| -------- | ---------------- |
| [NfcVTag](js-apis-nfctech.md#nfcvtag)  | NFC V类型Tag对象。 |

## tag.getIsoDepTag<sup>9+</sup>

getIsoDepTag(tagInfo: [TagInfo](#taginfo7)): [IsoDepTag](js-apis-nfctech.md#isoDepTag9 )

获取IsoDep类型Tag对象，通过该对象可访问Iso Dep技术类型的Tag。


**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**            |
| ---------- | ------------------|
| [IsoDepTag](js-apis-nfctech.md#isodeptag9)  | Iso Dep类型Tag对象。 |

## tag.getNdefTag<sup>9+</sup>

getNdefTag(tagInfo: [TagInfo](#taginfo7)): [NdefTag](js-apis-nfctech.md#ndeftag9)

获取Ndef类型Tag对象，通过该对象可访问Ndef技术类型的Tag。


**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**        |
| ---------| -------------- |
| [NdefTag](js-apis-nfctech.md#ndeftag9)  | Ndef类型Tag对象。|

## tag.getMifareClassicTag<sup>9+</sup>

getMifareClassicTag(tagInfo: [TagInfo](#taginfo7)): [MifareClassicTag](js-apis-nfctech.md#mifareclassictag-9)

获取Mifare Classic类型Tag对象，通过该对象访问Mifare Classic技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                          |
| ----------------- | ------------------------|
| [MifareClassicTag](js-apis-nfctech.md#mifareclassictag-9)  | Mifare Classic类型Tag对象。 |

## tag.getMifareUltralightTag<sup>9+</sup>

getMifareUltralightTag(tagInfo: [TagInfo](#taginfo7)): [MifareUltralightTag](js-apis-nfctech.md#mifareultralighttag9)

获取Mifare Ultralight类型Tag对象，通过该对象可访问Mifare Ultralight技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                                |
| -------------------- | ---------------------------|
| [MifareUltralightTag](js-apis-nfctech.md#mifareultralighttag9)  | Mifare Ultralight类型Tag对象。 |

## tag.getNdefFormatableTag<sup>9+</sup>

getNdefFormatableTag(tagInfo: [TagInfo](#taginfo7)): [NdefFormatableTag](js-apis-nfctech.md#ndefformatabletag9)

获取Ndef Formatable类型Tag对象，通过该对象可访问Ndef Formatable技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefFormatableTag](js-apis-nfctech.md#ndefformatabletag)  | Ndef Formatable类型Tag对象。 |

## TagInfo<sup>7+</sup>

nfc服务在调度标签时给出的对象。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

| **参数名** | **类型** |  **说明** |
| -------- | -------- | -------- |
| uid<sup>9+</sup> | string |  标签的uid。 |
| technology<sup>9+</sup> | number[] |  支持的技术类型。 |
| supportedProfiles<sup>7+</sup> | number[] |  支持的技术类型。 |
<!--no_check-->