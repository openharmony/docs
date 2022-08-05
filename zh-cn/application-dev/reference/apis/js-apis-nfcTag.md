# 标准NFC-Tag

本模块主要用于操作及管理NFC Tag。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## **导入模块**

```
import tag from '@ohos.nfc.tag';
```

## tag.getNfcATag

getNfcATag(tagInfo: [TagInfo](#TagInfo<sup>9+</sup>)): [NfcATag](js-apis-nfctech.md#NfcATag)

获取NFC A类型Tag对象，通过该对象可访问NfcA技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| [NfcATag](js-apis-nfctech.md#NfcATag) | NFC A类型Tag对象。 |

## tag.getNfcBTag

getNfcBTag(tagInfo: [TagInfo](#TagInfo<sup>9+</sup>)): [NfcBTag](js-apis-nfctech.md#NfcBTag)

获取NFC B类型Tag对象，通过该对象可访问NfcB技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**         |
| -------- | ---------------- |
| [NfcBTag](js-apis-nfctech.md#NfcBTag)  | NFC B类型Tag对象。 |

## tag.getNfcFTag

getNfcFTag(tagInfo: [TagInfo](#TagInfo<sup>9+</sup>)): [NfcFTag](js-apis-nfctech.md#NfcFTag)

获取NFC F类型Tag对象，通过该对象可访问NfcF技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**         |
| -------- | ---------------- |
| [NfcFTag](js-apis-nfctech.md#NfcFTag)  | NFC F类型Tag对象。 |

## tag.getNfcVTag

getNfcVTag(tagInfo: [TagInfo](#TagInfo<sup>9+</sup>)): [NfcVTag](js-apis-nfctech.md#NfcVTag)

获取NFC V类型Tag对象，通过该对象可访问NfcV技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**         |
| -------- | ---------------- |
| [NfcVTag](js-apis-nfctech.md#NfcVTag)  | NFC V类型Tag对象。 |

## tag.getIsoDepTag<sup>9+</sup>

getIsoDepTag(tagInfo: [TagInfo](#TagInfo<sup>9+</sup>)): [IsoDepTag](js-apis-nfctech.md#IsoDepTag )

获取IsoDep类型Tag对象，通过该对象可访问Iso Dep技术类型的Tag。


**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**            |
| ---------- | ------------------|
| [IsoDepTag](js-apis-nfctech.md#IsoDepTag>)  | Iso Dep类型Tag对象。 |

## tag.getNdefTag<sup>9+</sup>

getNdefTag(tagInfo: [TagInfo](#TagInfo<sup>9+</sup>)): [NdefTag](js-apis-nfctech.md#NdefTag-5)

获取Ndef类型Tag对象，通过该对象可访问Ndef技术类型的Tag。


**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**        |
| ---------| -------------- |
| [NdefTag](js-apis-nfctech.md#NdefTag)  | Ndef类型Tag对象。|

## tag.getMifareClassicTag<sup>9+</sup>

getMifareClassicTag(tagInfo: [TagInfo](#TagInfo<sup>9+</sup>)): [MifareClassicTag](js-apis-nfctech.md#MifareClassicTag)

获取Mifare Classic类型Tag对象，通过该对象访问Mifare Classic技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                          |
| ----------------- | ------------------------|
| [MifareClassicTag](js-apis-nfctech.md#MifareClassicTag)  | Mifare Classic类型Tag对象 |

## tag.getMifareUltralightTag<sup>9+</sup>

getMifareUltralightTag(tagInfo: [TagInfo](#TagInfo<sup>9+</sup>)): [MifareUltralightTag](js-apis-nfctech.md#MifareUltralightTag)

获取Mifare Ultralight类型Tag对象，通过该对象可访问Mifare Ultralight技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                                |
| -------------------- | ---------------------------|
| [MifareUltralightTag](js-apis-nfctech.md#MifareUltralightTag)  | Mifare Ultralight类型Tag对象 |

## tag.getNdefFormatableTag<sup>9+</sup>

getNdefFormatableTag(tagInfo: [TagInfo](#TagInfo<sup>9+</sup>)): [NdefFormatableTag](js-apis-nfctech.md#NdefFormatableTag)

获取Ndef Formatable类型Tag对象，通过该对象可访问Ndef Formatable技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefFormatableTag](js-apis-nfctech.md#NdefFormatableTag)  | Ndef Formatable类型Tag对象。 |

## TagInfo<sup>9+</sup>

nfc服务在调度标签时给出的对象。

| **参数名** | **类型** |  **说明** |
| -------- | -------- | -------- |
| uid | string |  标签的uid。 |
| technology | number[] |  支持的技术类型。 |
| extrasData | PacMap[] |  标签的额外信息。 |
| tagRfDiscId | number |  标签的RF discovery id。 |
| remoteTagService | rpc.RemoteObject |  标签服务的rpc远程对象。 |
| supportedProfiles | number[] |  支持的技术类型。 |