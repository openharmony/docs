# 标准NFC-Tag

本模块主要用于操作及管理NFC Tag。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## **声明技术**

开发Tag读写相关应用时，需要在应用的属性配置文件中，声明与NFC相关的属性值，比如，在module.json5文件中，声明下面属性值：
```js
{
    "module": {
        // other declared attributes.

        "abilities": [
            {
                "skills": [
                    {
                        "actions": [
                            // other declared actions,

                            // add the nfc tag action
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
                    // add other technology if neccessary,
                    // such as: NfcB/NfcF/NfcV/Ndef/MifareClassic/MifareUL/NdefFormatable
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
> **注意：**
1. 声明"actions"字段的内容填写，必须是"ohos.nfc.tag.action.TAG_FOUND"，不能更改。
2. 声明技术时"metadata"中的"name"字段的内容填写，必须是"tag-tech"，不能更改。
3. 声明技术时"metadata"中的"value"字段的内容填写，必须是"NfcA/NfcB/NfcF/NfcV/IsoDep/Ndef/MifareClassic/MifareUL/NdefFormatable"中的一个或多个。填写错误会造成解析失败。
4. 声明权限时"requestPermissions"中的"name"字段的内容填写，必须是"ohos.permission.NFC_TAG"，不能更改。

## **导入模块**

```js
import tag from '@ohos.nfc.tag';
```

## **tag.TagInfo**
在对相关Tag类型卡片进行读写之前，必须先获取TagInfo相关属性值，以确认设备读取到的Tag卡片支持哪些技术类型。这样Tag应用程序才能调用正确的接口和所读取到的Tag卡片进行通信。
```js
import tag from '@ohos.nfc.tag';

onCreate(want, launchParam) {
    // add other code here

    // want is initialized by nfc service, contains tag info for this found tag
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
        // also check for technology: tag.NFC_B/NFC_F/NFC_V/ISO_DEP/NDEF/MIFARE_CLASSIC/MIFARE_ULTRALIGHT/NDEF_FORMATABLE
    }
    if (isNfcATag) {
        var nfcA = tag.getNfcATag(taginfo);
        // other code to read or write this found tag.
    }

    // use the same code to handle for "NfcA/NfcB/NfcF/NfcV/IsoDep/Ndef/MifareClassic/MifareUL/NdefFormatable", such as:
    // var isoDep = tag.getIsoDepTag(taginfo);
}
```

## tag.getNfcATag

getNfcATag(tagInfo: [TagInfo](#taginfo)): [NfcATag](js-apis-nfctech.md#nfcatag)

获取NFC A类型Tag对象，通过该对象可访问NfcA技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| [NfcATag](js-apis-nfctech.md#nfcatag) | NFC A类型Tag对象。 |

## tag.getNfcBTag

getNfcBTag(tagInfo: [TagInfo](#taginfo)): [NfcBTag](js-apis-nfctech.md#nfcbtag)

获取NFC B类型Tag对象，通过该对象可访问NfcB技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**         |
| -------- | ---------------- |
| [NfcBTag](js-apis-nfctech.md#nfcbtag)  | NFC B类型Tag对象。 |

## tag.getNfcFTag

getNfcFTag(tagInfo: [TagInfo](#taginfo)): [NfcFTag](js-apis-nfctech.md#nfcftag)

获取NFC F类型Tag对象，通过该对象可访问NfcF技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**         |
| -------- | ---------------- |
| [NfcFTag](js-apis-nfctech.md#nfcftag)  | NFC F类型Tag对象。 |

## tag.getNfcVTag

getNfcVTag(tagInfo: [TagInfo](#taginfo)): [NfcVTag](js-apis-nfctech.md#nfcvtag)

获取NFC V类型Tag对象，通过该对象可访问NfcV技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**         |
| -------- | ---------------- |
| [NfcVTag](js-apis-nfctech.md#nfcvtag)  | NFC V类型Tag对象。 |

## tag.getIsoDepTag<sup>9+</sup>

getIsoDepTag(tagInfo: [TagInfo](#taginfo)): [IsoDepTag](js-apis-nfctech.md#isoDepTag9 )

获取IsoDep类型Tag对象，通过该对象可访问Iso Dep技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**            |
| ---------- | ------------------|
| [IsoDepTag](js-apis-nfctech.md#isodeptag9)  | Iso Dep类型Tag对象。 |

## tag.getNdefTag<sup>9+</sup>

getNdefTag(tagInfo: [TagInfo](#taginfo)): [NdefTag](js-apis-nfctech.md#ndeftag9)

获取Ndef类型Tag对象，通过该对象可访问Ndef技术类型的Tag。


**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**        |
| ---------| -------------- |
| [NdefTag](js-apis-nfctech.md#ndeftag9)  | Ndef类型Tag对象。|

## tag.getMifareClassicTag<sup>9+</sup>

getMifareClassicTag(tagInfo: [TagInfo](#taginfo)): [MifareClassicTag](js-apis-nfctech.md#mifareclassictag-9)

获取Mifare Classic类型Tag对象，通过该对象访问Mifare Classic技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                          |
| ----------------- | ------------------------|
| [MifareClassicTag](js-apis-nfctech.md#mifareclassictag-9)  | Mifare Classic类型Tag对象。 |

## tag.getMifareUltralightTag<sup>9+</sup>

getMifareUltralightTag(tagInfo: [TagInfo](#taginfo)): [MifareUltralightTag](js-apis-nfctech.md#mifareultralighttag9)

获取Mifare Ultralight类型Tag对象，通过该对象可访问Mifare Ultralight技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                                |
| -------------------- | ---------------------------|
| [MifareUltralightTag](js-apis-nfctech.md#mifareultralighttag9)  | Mifare Ultralight类型Tag对象。 |

## tag.getNdefFormatableTag<sup>9+</sup>

getNdefFormatableTag(tagInfo: [TagInfo](#taginfo)): [NdefFormatableTag](js-apis-nfctech.md#ndefformatabletag9)

获取Ndef Formatable类型Tag对象，通过该对象可访问Ndef Formatable技术类型的Tag。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefFormatableTag](js-apis-nfctech.md#ndefformatabletag)  | Ndef Formatable类型Tag对象。 |

## tag.getTagInfo<sup>9+</sup>

getTagInfo(want: Want): [TagInfo](#taginfo)

从Want中获取TagInfo，Want是被NFC服务初始化，包含了TagInfo所需的属性值。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [TagInfo](#taginfo) | TagInfo对象，用于获取不同技术类型的Tag对象。 |

## TagInfo

NFC服务在读取到标签时给出的对象，通过改对象属性，应用知道该标签支持哪些技术类型，并使用匹配的技术类型来调用相关接口。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

| **参数名** | **类型** |  **说明** |
| -------- | -------- | -------- |
| uid<sup>9+</sup> | number[] |  标签的uid，每个number值是十六进制表示，范围是0x00~0xFF。 |
| technology<sup>9+</sup> | number[] |  支持的技术类型，每个number值表示所支持技术类型的常量值。 |
| supportedProfiles | number[] |  支持的技术类型，从API9开始不支持，使用technology替代。 |

## NdefRecord<sup>9+</sup>
NDEF标签Record属性的定义，参考NDEF标签技术规范《NFCForum-TS-NDEF_1.0》的定义细节。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core
| **参数名** | **类型** |  **说明** |
| -------- | -------- | -------- |
| tnf | number |  NDEF Record的TNF(Type Name Field)。 |
| rtdType| number[] |  NDEF Record的RTD(Record Type Definition)类型值，每个number十六进制表示，范围是0x00~0xFF。 |
| id | number[] |  NDEF Record的ID，每个number十六进制表示，范围是0x00~0xFF。|
| payload | number[] |  NDEF Record的PAYLOAD，每个number十六进制表示，范围是0x00~0xFF。 |

## 技术类型定义
NFC Tag有多种不同的技术类型，定义常量描述不同的技术类型。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core
| **参数名** | **常量值** |  **说明** |
| -------- | -------- | -------- |
| NFC_A | 1 | NFC-A(ISO 14443-3A)技术。|
| NFC_B  | 2 | NFC-A(ISO 14443-3B)技术。|
| ISO_DEP | 3 | ISO-DEP(ISO 14443-4)技术。|
| NFC_F  | 4 | NFC-F(JIS 6319-4)技术。|
| NFC_V | 5 | NFC-V(ISO 15693)技术。|
| NDEF  | 6 | NDEF技术。|
| MIFARE_CLASSIC | 8 | Mifare Classic技术。|
| MIFARE_ULTRALIGHT | 9 | Mifare Utralight技术。|
| NDEF_FORMATABLE<sup>9+</sup> | 10 | 可以格式化的NDEF技术。|

## TnfType<sup>9+</sup>
NDEF Record的TNF(Type Name Field)类型值，参考NDEF标签技术规范《NFCForum-TS-NDEF_1.0》的定义细节。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core
| **参数名** | **常量值** |  **说明** |
| -------- | -------- | -------- |
| TNF_EMPTY | 0x0 | Empty。|
| TNF_WELL_KNOWN  | 0x01 | NFC Forum well-known type [NFC RTD]。|
| TNF_MEDIA | 0x02 | Media-type as defined in RFC 2046 [RFC 2046]。|
| TNF_ABSOLUTE_URI  | 0x03 | Absolute URI as defined in RFC 3986 [RFC 3986]。|
| TNF_EXT_APP | 0x04 | NFC Forum external type [NFC RTD]。|
| TNF_UNKNOWN  | 0x05 | Unknown。|
| TNF_UNCHANGED | 0x06 | Unchanged (see section 2.3.3)。|

## RtdType<sup>9+</sup>
NDEF Record的RTD(Record Type Definition)类型值，参考NDEF标签技术规范《NFCForum-TS-NDEF_1.0》的定义细节。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core
| **参数名** | **常量值** |  **说明** |
| -------- | -------- | -------- |
| RTD_TEXT | 常量 'T' |  文本类型的NDEF Record。|
| RTD_URI  | 常量 'U' |  URI类型的NDEF Record。|

## NfcForumType<sup>9+</sup>
NFC Forum标准里面Tag类型的定义。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core
| **参数名** | **常量值** |  **说明** |
| -------- | -------- | -------- |
| NFC_FORUM_TYPE_1 | 1 |  NFC论坛类型1。 |
| NFC_FORUM_TYPE_2 | 2 |  NFC论坛类型2。 |
| NFC_FORUM_TYPE_3  | 3 |  NFC论坛类型3。 |
| NFC_FORUM_TYPE_4  | 4 |  NFC论坛类型4。 |
| MIFARE_CLASSIC  | 101 |   Mifare Classic类型。 |

## MifareClassicType<sup>9+</sup>
MifareClassic标签类型的定义。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core
| **参数名** | **常量值** |  **说明** |
| -------- | -------- | -------- |
| TYPE_UNKNOWN | -1 |  未知Mifare类型。 |
| TYPE_CLASSIC | 0 |  Mifare Classic类型。|
| TYPE_PLUS   | 1 |  Mifare Plus类型。|
| TYPE_PRO  | 2 |  Mifare Pro类型。 |

## MifareClassicSize<sup>9+</sup>
MifareClassic标签存储大小的定义。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core
| **参数名** | **常量值** |  **说明** |
| -------- | -------- | -------- |
| MC_SIZE_MINI | 320 |  每个标签5个扇区，每个扇区4个块。 |
| MC_SIZE_1K  | 1024 |  每个标签16个扇区，每个扇区4个块。|
| MC_SIZE_2K   | 2048 |  每个标签32个扇区，每个扇区4个块。 |
| MC_SIZE_4K   | 4096 |  每个标签40个扇区，每个扇区4个块。|

### MifareUltralightType<sup>9+</sup>
MifareUltralight标签类型的定义。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core
| **参数名** | **常量值** |  **说明** |
| -------- | -------- | -------- |
| TYPE_UNKOWN  | -1 |  未知的 Mifare 类型。 |
| TYPE_ULTRALIGHT   | 1 |  Mifare Ultralight类型。|
| TYPE_ULTRALIGHT_C    | 2 |  Mifare UltralightC 类型。 |
<!--no_check-->