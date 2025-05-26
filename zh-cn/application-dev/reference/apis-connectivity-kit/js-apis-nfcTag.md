# @ohos.nfc.tag (标准NFC-Tag)

本模块主要用于操作及管理NFC Tag，提供后台读卡和前台应用优先分发两种读卡模式。
后台读卡是指不需要打开应用程序，电子设备通过NFC读取标签卡片后，根据标签卡片的类型匹配到一个或多个应用程序。如果仅匹配到一个，则直接拉起应用程序的读卡页面；如果是多个则弹出应用选择器，让用户选择指定的读卡应用。
前台读卡是指提前打开应用程序，并进入对应的NFC读卡页面后读卡，只会把读到的标签卡片信息分发给前台应用程序。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 后台读卡方式的声明

应用程序需要支持后台读卡时，需要在应用的属性配置文件中，声明与NFC相关的属性值。比如，在module.json5文件中，声明下面属性值：
```json
{
    "module": {
        //其他已声明的属性

        "abilities": [
            {
                "skills": [
                    {
                        "actions": [
                            // 其它已经声明的actions

                            // 添加nfc tag的 action
                            "ohos.nfc.tag.action.TAG_FOUND"
                        ],
                        "uris": [
                            {
                                "type":"tag-tech/NfcA"
                            },
                            {
                                "type":"tag-tech/IsoDep"
                            }
                            // 有必要可添加其他技术
                            // 比如: NfcB/NfcF/NfcV/Ndef/MifareClassic/MifareUL/NdefFormatable
                        ]
                    }
                ]
            }
        ],
        "requestPermissions": [
            {
                "name": "ohos.permission.NFC_TAG",
                "reason": "$string:app_name",
            }
        ]
    }
}
```
> **注意：**
>
>1. 声明"actions"字段的内容填写，必须包含"ohos.nfc.tag.action.TAG_FOUND"，不能更改。
>2. 声明技术时"uris"中"type"字段的内容填写，前缀必须是"tag-tech/"，后面接着NfcA/NfcB/NfcF/NfcV/IsoDep/Ndef/MifareClassic/MifareUL/NdefFormatable"中的一个。如果存在多个"type"时，需要分行填写。填写错误会造成解析失败。
>3. 声明权限时"requestPermissions"中的"name"字段的内容填写，必须是"ohos.permission.NFC_TAG"，不能更改。
>4. 调用本模块接口和常量时请使用canIUse("SystemCapability.Communication.NFC.Tag")判断设备是否支持NFC能力，否则可能导致应用运行稳定性问题，参考[nfc-tag开发指南](../../connectivity/nfc/nfc-tag-access-guide.md)。
>5. 导入tag模块编辑器报错，在某个具体设备型号上能力可能超出工程默认设备定义的能力集范围，如需要使用此部分能力需额外配置自定义syscap，参考[syscap开发指南](https://developer.huawei.com/consumer/cn/doc/harmonyos-references/syscap#syscap开发指导)。

## **导入模块**

```js
import { tag } from '@kit.ConnectivityKit';
```

## **tag.TagInfo**

在对相关Tag类型卡片进行读写之前，必须先获取[TagInfo](#taginfo)相关属性值，以确认设备读取到的Tag卡片支持哪些技术类型。这样Tag应用程序才能调用正确的接口和所读取到的Tag卡片进行通信。
```js
import { tag } from '@kit.ConnectivityKit';
import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';

export default class EntryAbility extends UIAbility {
    onCreate(want : Want, launchParam: AbilityConstant.LaunchParam) {
        // 添加其他功能代码...

        // want由nfc服务初始化，包含找到的tag
        let tagInfo : tag.TagInfo | null = null;
        try {
            tagInfo = tag.getTagInfo(want);
        } catch (error) {
            console.error("tag.getTagInfo catch error: " + error);
        }
        if (tagInfo == null || tagInfo == undefined) {
            console.log("no TagInfo to be created, ignore it.");
            return;
        }

        // 获取发现标签的支持技术
        let isNfcATag =  false;
        let isIsoDepTag =  false;
        for (let i = 0; i < tagInfo.technology.length; i++) {
            if (tagInfo.technology[i] == tag.NFC_A) {
                isNfcATag = true;
            }
            if (tagInfo.technology[i] == tag.ISO_DEP) {
                isIsoDepTag = true;
            }
        // 检查其他技术类型: tag.NFC_B/NFC_F/NFC_V/NDEF/MIFARE_CLASSIC/MIFARE_ULTRALIGHT/NDEF_FORMATABLE
        }

        // 使用 NfcA APIs 去访问发现的标签
        if (isNfcATag) {
            let nfcA : tag.NfcATag | null = null;
            try {
                nfcA = tag.getNfcA(tagInfo);
            } catch (error) {
                console.error("tag.getNfcA catch error: " + error);
            }
            // 其他代码：对发现的标签执行读取或写入
        }

        // 使用 IsoDep APIs 去访问发现的标签
        if (isIsoDepTag) {
            let isoDep : tag.IsoDepTag | null = null;
            try {
                isoDep = tag.getIsoDep(tagInfo);
            } catch (error) {
                console.error("tag.getIsoDep catch error: " + error);
            }
            // 其他代码：对发现的标签执行读取或写入
        }
        // 使用相同的代码来处理 "NfcA/NfcB/NfcF/NfcV/Ndef/MifareClassic/MifareUL/NdefFormatable".
    }
}
```

## tag.getNfcATag<sup>(deprecated)</sup>

getNfcATag(tagInfo: [TagInfo](#taginfo)): [NfcATag](js-apis-nfctech.md#nfcatag)

获取NFC A类型Tag对象，通过该对象可访问NfcA技术类型的Tag。

> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[tag.getNfcA](#taggetnfca9)替代。

**系统能力：** SystemCapability.Communication.NFC.Tag

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                          |
| ------- | ------------------- | ---- | ------------------------------------------------------------- |
| tagInfo | [TagInfo](#taginfo) | 是   | 包含Tag技术类型和相关参数，从[tag.getTagInfo(want: Want)](#taggettaginfo9)获取。 |

**返回值：**

| **类型**                              | **说明**           |
| ------------------------------------- | ------------------ |
| [NfcATag](js-apis-nfctech.md#nfcatag) | NFC A类型Tag对象。 |

## tag.getNfcA<sup>9+</sup>

getNfcA(tagInfo: [TagInfo](#taginfo)): [NfcATag](js-apis-nfctech.md#nfcatag)

获取NFC A类型Tag对象，通过该对象可访问NfcA技术类型的Tag。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                          |
| ------- | ------------------- | ---- | ------------------------------------------------------------- |
| tagInfo | [TagInfo](#taginfo) | 是   | 包含Tag技术类型和相关参数，从[tag.getTagInfo(want: Want)](#taggettaginfo9)获取。 |

**返回值：**

| **类型**                              | **说明**           |
| ------------------------------------- | ------------------ |
| [NfcATag](js-apis-nfctech.md#nfcatag) | NFC A类型Tag对象。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 801  | Capability not supported. |
| 3100201  | The tag running state is abnormal in the service. |

## tag.getNfcBTag<sup>(deprecated)</sup>

getNfcBTag(tagInfo: [TagInfo](#taginfo)): [NfcBTag](js-apis-nfctech.md#nfcbtag)

获取NFC B类型Tag对象，通过该对象可访问NfcB技术类型的Tag。

> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[tag.getNfcB](#taggetnfcb9)替代。

**系统能力：** SystemCapability.Communication.NFC.Tag

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                          |
| ------- | ------------------- | ---- | ------------------------------------------------------------- |
| tagInfo | [TagInfo](#taginfo) | 是   | 包含Tag技术类型和相关参数，从[tag.getTagInfo(want: Want)](#taggettaginfo9)获取。 |

**返回值：**

| **类型**                              | **说明**           |
| ------------------------------------- | ------------------ |
| [NfcBTag](js-apis-nfctech.md#nfcbtag) | NFC B类型Tag对象。 |

## tag.getNfcB<sup>9+</sup>

getNfcB(tagInfo: [TagInfo](#taginfo)): [NfcBTag](js-apis-nfctech.md#nfcbtag)

获取NFC B类型Tag对象，通过该对象可访问NfcB技术类型的Tag。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                          |
| ------- | ------------------- | ---- | ------------------------------------------------------------- |
| tagInfo | [TagInfo](#taginfo) | 是   | 包含Tag技术类型和相关参数，从[tag.getTagInfo(want: Want)](#taggettaginfo9)获取。 |

**返回值：**

| **类型**                              | **说明**           |
| ------------------------------------- | ------------------ |
| [NfcBTag](js-apis-nfctech.md#nfcbtag) | NFC B类型Tag对象。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 801  | Capability not supported. |
| 3100201  | The tag running state is abnormal in the service. |

## tag.getNfcFTag<sup>(deprecated)</sup>

getNfcFTag(tagInfo: [TagInfo](#taginfo)): [NfcFTag](js-apis-nfctech.md#nfcftag)

获取NFC F类型Tag对象，通过该对象可访问NfcF技术类型的Tag。

> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[tag.getNfcF](#taggetnfcf9)替代。

**系统能力：** SystemCapability.Communication.NFC.Tag

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                          |
| ------- | ------------------- | ---- | ------------------------------------------------------------- |
| tagInfo | [TagInfo](#taginfo) | 是   | 包含Tag技术类型和相关参数，从[tag.getTagInfo(want: Want)](#taggettaginfo9)获取。 |

**返回值：**

| **类型**                              | **说明**           |
| ------------------------------------- | ------------------ |
| [NfcFTag](js-apis-nfctech.md#nfcftag) | NFC F类型Tag对象。 |

## tag.getNfcF<sup>9+</sup>

getNfcF(tagInfo: [TagInfo](#taginfo)): [NfcFTag](js-apis-nfctech.md#nfcftag)

获取NFC F类型Tag对象，通过该对象可访问NfcF技术类型的Tag。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                          |
| ------- | ------------------- | ---- | ------------------------------------------------------------- |
| tagInfo | [TagInfo](#taginfo) | 是   | 包含Tag技术类型和相关参数，从[tag.getTagInfo(want: Want)](#taggettaginfo9)获取。 |

**返回值：**

| **类型**                              | **说明**           |
| ------------------------------------- | ------------------ |
| [NfcFTag](js-apis-nfctech.md#nfcftag) | NFC F类型Tag对象。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 801  | Capability not supported. |
| 3100201  | The tag running state is abnormal in the service. |

## tag.getNfcVTag<sup>(deprecated)</sup>

getNfcVTag(tagInfo: [TagInfo](#taginfo)): [NfcVTag](js-apis-nfctech.md#nfcvtag)

获取NFC V类型Tag对象，通过该对象可访问NfcV技术类型的Tag。

> **说明：**
>
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[tag.getNfcV](#taggetnfcv9)替代。

**系统能力：** SystemCapability.Communication.NFC.Tag

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                          |
| ------- | ------------------- | ---- | ------------------------------------------------------------- |
| tagInfo | [TagInfo](#taginfo) | 是   | 包含Tag技术类型和相关参数，从[tag.getTagInfo(want: Want)](#taggettaginfo9)获取。 |

**返回值：**

| **类型**                              | **说明**           |
| ------------------------------------- | ------------------ |
| [NfcVTag](js-apis-nfctech.md#nfcvtag) | NFC V类型Tag对象。 |

## tag.getNfcV<sup>9+</sup>

getNfcV(tagInfo: [TagInfo](#taginfo)): [NfcVTag](js-apis-nfctech.md#nfcvtag)

获取NFC V类型Tag对象，通过该对象可访问NfcV技术类型的Tag。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                          |
| ------- | ------------------- | ---- | ------------------------------------------------------------- |
| tagInfo | [TagInfo](#taginfo) | 是   | 包含Tag技术类型和相关参数，从[tag.getTagInfo(want: Want)](#taggettaginfo9)获取。 |

**返回值：**

| **类型**                              | **说明**           |
| ------------------------------------- | ------------------ |
| [NfcVTag](js-apis-nfctech.md#nfcvtag) | NFC V类型Tag对象。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 801  | Capability not supported. |
| 3100201  | The tag running state is abnormal in the service. |

## tag.getIsoDep<sup>9+</sup>

getIsoDep(tagInfo: [TagInfo](#taginfo)): [IsoDepTag](js-apis-nfctech.md#isoDepTag9 )

获取IsoDep类型Tag对象，通过该对象可访问支持IsoDep技术类型的Tag。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                          |
| ------- | ------------------- | ---- | ------------------------------------------------------------- |
| tagInfo | [TagInfo](#taginfo) | 是   | 包含Tag技术类型和相关参数，从[tag.getTagInfo(want: Want)](#taggettaginfo9)获取。 |

**返回值：**

| **类型**                                   | **说明**                                                |
| ------------------------------------------ | ------------------------------------------------------- |
| [IsoDepTag](js-apis-nfctech.md#isodeptag9) | IsoDep类型Tag对象，通过该对象访问IsoDep类型的相关接口。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 801  | Capability not supported. |
| 3100201  | The tag running state is abnormal in the service. |

## tag.getNdef<sup>9+</sup>

getNdef(tagInfo: [TagInfo](#taginfo)): [NdefTag](js-apis-nfctech.md#ndeftag9)

获取NDEF类型Tag对象，通过该对象可访问支持NDEF技术类型的Tag。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                          |
| ------- | ------------------- | ---- | ------------------------------------------------------------- |
| tagInfo | [TagInfo](#taginfo) | 是   | 包含Tag技术类型和相关参数，从[tag.getTagInfo(want: Want)](#taggettaginfo9)获取。 |

**返回值：**

| **类型**                               | **说明**                                            |
| -------------------------------------- | --------------------------------------------------- |
| [NdefTag](js-apis-nfctech.md#ndeftag9) | NDEF类型Tag对象，通过该对象访问NDEF类型的相关接口。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 801  | Capability not supported. |
| 3100201  | The tag running state is abnormal in the service. |

## tag.getMifareClassic<sup>9+</sup>

getMifareClassic(tagInfo: [TagInfo](#taginfo)): [MifareClassicTag](js-apis-nfctech.md#mifareclassictag9)

获取MIFARE Classic类型Tag对象，通过该对象访问支持MIFARE Classic技术类型的Tag。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型                | 必填 | 说明                                                          |
| ------- | ------------------- | ---- | ------------------------------------------------------------- |
| tagInfo | [TagInfo](#taginfo) | 是   | 包含Tag技术类型和相关参数，从[tag.getTagInfo(want: Want)](#taggettaginfo9)获取。 |

**返回值：**

| **类型**                                                  | **说明**                                                                |
| --------------------------------------------------------- | ----------------------------------------------------------------------- |
| [MifareClassicTag](js-apis-nfctech.md#mifareclassictags9) | MIFARE Classic类型Tag对象，通过该对象访问MIFARE Classic类型的相关接口。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 801  | Capability not supported. |
| 3100201  | The tag running state is abnormal in the service. |

## tag.getMifareUltralight<sup>9+</sup>

getMifareUltralight(tagInfo: [TagInfo](#taginfo)): [MifareUltralightTag](js-apis-nfctech.md#mifareultralighttag9)

获取MIFARE Ultralight类型Tag对象，通过该对象可访问支持MIFARE Ultralight技术类型的Tag。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**
| 参数名  | 类型                | 必填 | 说明                                                          |
| ------- | ------------------- | ---- | ------------------------------------------------------------- |
| tagInfo | [TagInfo](#taginfo) | 是   | 包含Tag技术类型和相关参数，从[tag.getTagInfo(want: Want)](#taggettaginfo9)获取。 |

**返回值：**

| **类型**                                                       | **说明**                                                                      |
| -------------------------------------------------------------- | ----------------------------------------------------------------------------- |
| [MifareUltralightTag](js-apis-nfctech.md#mifareultralighttag9) | MIFARE Ultralight类型Tag对象，通过该对象访问MIFARE Ultralight类型的相关接口。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 801  | Capability not supported. |
| 3100201  | The tag running state is abnormal in the service. |

## tag.getNdefFormatable<sup>9+</sup>

getNdefFormatable(tagInfo: [TagInfo](#taginfo)): [NdefFormatableTag](js-apis-nfctech.md#ndefformatabletag9)

获取NDEF Formatable类型Tag对象，通过该对象可访问支持NDEF Formatable技术类型的Tag。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**
| 参数名  | 类型                | 必填 | 说明                                                          |
| ------- | ------------------- | ---- | ------------------------------------------------------------- |
| tagInfo | [TagInfo](#taginfo) | 是   | 包含Tag技术类型和相关参数，从[tag.getTagInfo(want: Want)](#taggettaginfo9)获取。 |

**返回值：**

| **类型**                                                  | **说明**                                                                  |
| --------------------------------------------------------- | ------------------------------------------------------------------------- |
| [NdefFormatableTag](js-apis-nfctech.md#ndefformatabletag) | NDEF Formatable类型Tag对象，通过该对象访问NDEF Formatable类型的相关接口。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 801  | Capability not supported. |
| 3100201  | The tag running state is abnormal in the service. |

## tag.getBarcodeTag<sup>18+</sup>

getBarcodeTag(tagInfo: [TagInfo](#taginfo)): [BarcodeTag](js-apis-nfctech.md#barcodetag18)

获取BarcodeTag类型Tag对象，通过该对象可访问BarcodeTag技术类型的Tag。


**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**参数：**
| 参数名  | 类型                | 必填 | 说明                                                          |
| ------- | ------------------- | ---- | ------------------------------------------------------------- |
| tagInfo | [TagInfo](#taginfo) | 是   | 包含Tag技术类型和相关参数，从[tag.getTagInfo(want: Want)](#taggettaginfo9)获取。 |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| [BartcodeTag](js-apis-nfctech.md#barcodetag18) | BarcodeTag类型Tag对象。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 801  | Capability not supported. |
| 3100201 | The tag running state is abnormal in the service. |


## tag.getTagInfo<sup>9+</sup>

getTagInfo(want: [Want](../apis-ability-kit/js-apis-app-ability-want.md#want)): [TagInfo](#taginfo)

从Want中获取TagInfo，Want是被NFC服务初始化，包含了TagInfo所需的属性值。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型                                     | 必填 | 说明                                                |
| ------ | ---------------------------------------- | ---- | --------------------------------------------------- |
| want   | [Want](../apis-ability-kit/js-apis-app-ability-want.md#want) | 是   | 分发Ability时，在系统onCreate入口函数的参数中获取。 |

**返回值：**

| **类型**            | **说明**                                     |
| ------------------- | -------------------------------------------- |
| [TagInfo](#taginfo) | TagInfo对象，用于获取不同技术类型的Tag对象。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 801  | Capability not supported. |

## tag.registerForegroundDispatch<sup>10+</sup>

registerForegroundDispatch(elementName: [ElementName](../apis-ability-kit/js-apis-bundleManager-elementName.md), discTech: number[], callback: AsyncCallback&lt;[TagInfo](#taginfo)&gt;): void

注册对NFC Tag读卡事件的监听，实现前台应用优先分发的目的。通过discTech设置支持的读卡技术类型，通过Callback方式获取读取到Tag的[TagInfo](#taginfo)信息。应用必须在前台才能调用。需要与取消监听接口[tag.unregisterForegroundDispatch](#tagunregisterforegrounddispatch10)成对使用。如果已注册事件监听，需要在页面退出前台或页面销毁前调用取消注册。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名       | 类型     | 必填 | 说明                                                    |
| ------------ | -------- | ---- | ------------------------------------------------------- |
| elementName   |  [ElementName](../apis-ability-kit/js-apis-bundleManager-elementName.md)   | 是   | 所属应用读卡的页面信息（至少包含bundleName、abilityName这两项的赋值），不可以为空。          |
| discTech         |  number[]   | 是   | 前台应用指定的NFC读卡技术类型，不可以为空，至少指定一种读卡技术类型。每个number值表示所支持技术类型的常量值型，根据number值设置NFC读卡轮询的Tag技术类型（仅包含[NFC_A](#常量), [NFC_B](#常量), [NFC_F](#常量), [NFC_V](#常量)中的一种或多种）。 |
| callback | AsyncCallback&lt;[TagInfo](#taginfo)&gt; | 是   | 前台读卡监听回调函数，返回读到的Tag信息，不可以为空。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 801  | Capability not supported. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100202  | The element state is invalid. |

**示例：**

示例请参见[tag.unregisterForegroundDispatch](#tagunregisterforegrounddispatch10)接口的示例。

## tag.unregisterForegroundDispatch<sup>10+</sup>

unregisterForegroundDispatch(elementName: [ElementName](../apis-ability-kit/js-apis-bundleManager-elementName.md)): void

取消注册对NFC Tag读卡事件的监听，退出前台应用优先分发。如果已注册事件监听，需要在页面退出前台或页面销毁前调用取消注册。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名       | 类型     | 必填 | 说明                                                    |
| ------------ | -------- | ---- | ------------------------------------------------------- |
| elementName   |  [ElementName](../apis-ability-kit/js-apis-bundleManager-elementName.md)   | 是   | 所属应用读卡的页面信息（至少包含bundleName、abilityName这两项的赋值），不可以为空。           |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 801  | Capability not supported. |
| 3100201 | The tag running state is abnormal in the service. |

**示例：**

```js

import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want, bundleManager } from '@kit.AbilityKit';

let discTech : number[] = [tag.NFC_A, tag.NFC_B]; // 用前台ability时所需要的技术代替
let elementName : bundleManager.ElementName;
function foregroundCb(err : BusinessError, tagInfo : tag.TagInfo) {
    if (!err) {
        console.log("foreground callback: tag found tagInfo = ", JSON.stringify(tagInfo));
    } else {
        console.log("foreground callback err: " + err.message);
        return;
    }
  // taginfo的其他操作
}

export default class MainAbility extends UIAbility {
    OnCreate(want : Want, launchParam : AbilityConstant.LaunchParam) {
        console.log("OnCreate");
        elementName = {
            bundleName: want.bundleName as string,
            abilityName: want.abilityName as string,
            moduleName: want.moduleName as string
        }
    }

    onForeground() {
        console.log("onForeground");
        try {
            tag.registerForegroundDispatch(elementName, discTech, foregroundCb);
        } catch (e) {
            console.error("registerForegroundDispatch error: " + (e as BusinessError).message);
        }
    }

    onBackground() {
        console.log("onBackground");
        try {
            tag.unregisterForegroundDispatch(elementName);
        } catch (e) {
            console.error("registerForegroundDispatch error: " + (e as BusinessError).message);
        }
    }

    onWindowStageDestroy() {
        console.log("onWindowStageDestroy");
        try {
            tag.unregisterForegroundDispatch(elementName);
        } catch (e) {
            console.error("registerForegroundDispatch error: " + (e as BusinessError).message);
        }
    }

  // ability生命周期内的其他功能
}
```

## tag.on<sup>11+</sup>

on(type: 'readerMode', elementName: [ElementName](../apis-ability-kit/js-apis-bundleManager-elementName.md), discTech: number[], callback: AsyncCallback&lt;[TagInfo](#taginfo)&gt;): void

订阅NFC Tag读卡事件，实现前台应用优先分发。设备会进入读卡器模式，同时关闭卡模拟。通过discTech设置支持的读卡技术类型，通过Callback方式获取到Tag的[TagInfo](#taginfo)信息。需要与取消读卡器模式的[tag.off](#tagoff11)成对使用，如果已通过on进行设置，需要在页面退出前台或页面销毁时调用[tag.off](#tagoff11)。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名       | 类型     | 必填 | 说明                                                    |
| ------------ | -------- | ---- | ------------------------------------------------------- |
| type    | string  | 是   | 要注册的回调类型，固定填"readerMode"字符串。 |
| elementName   |  [ElementName](../apis-ability-kit/js-apis-bundleManager-elementName.md)   | 是   | 所属应用读卡的页面信息（至少包含bundleName、abilityName这两项的赋值），不可以为空。          |
| discTech         |  number[]   | 是   | 前台应用指定的NFC读卡技术类型，不可以为空，至少指定一种读卡技术类型。每个number值表示所支持技术类型的常量值型，根据number值设置NFC读卡轮询的Tag技术类型（仅包含[NFC_A](#常量), [NFC_B](#常量), [NFC_F](#常量), [NFC_V](#常量)中的一种或多种）。 |
| callback | AsyncCallback&lt;[TagInfo](#taginfo)&gt; | 是   | 读卡器模式监听回调函数，返回读到的Tag信息，不可以为空。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 801  | Capability not supported. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100202  | The element state is invalid. |

**示例：**

示例请参见[tag.off](#tagoff11)接口的示例。

## tag.off<sup>11+</sup>

off(type: 'readerMode', elementName: [ElementName](../apis-ability-kit/js-apis-bundleManager-elementName.md), callback?: AsyncCallback&lt;[TagInfo](#taginfo)&gt;): void

取消订阅NFC Tag读卡事件。设备退出读卡模式，并恢复卡模拟。如果已通过[tag.on](#tagon11)设置NFC的读卡器模式，需要在页面退出前台或页面销毁时调用off进行取消。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名       | 类型     | 必填 | 说明                                                    |
| ------------ | -------- | ---- | ------------------------------------------------------- |
| type    | string  | 是   | 要注销的回调类型，固定填"readerMode"字符串。|
| elementName   |  [ElementName](../apis-ability-kit/js-apis-bundleManager-elementName.md)   | 是   | 所属应用读卡的页面信息（至少包含bundleName、abilityName这两项的赋值），不可以为空。          |
| callback | AsyncCallback&lt;[TagInfo](#taginfo)&gt; | 否   | 前台读卡监听回调函数，返回读到的Tag信息。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 801  | Capability not supported. |
| 3100201 | The tag running state is abnormal in the service. |
| 3100203  | The off() API can be called only when the on() has been called. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { AbilityConstant, UIAbility, Want, bundleManager } from '@kit.AbilityKit';

let discTech : number[] = [tag.NFC_A, tag.NFC_B]; // 用前台ability时所需要的技术代替
let elementName : bundleManager.ElementName;

function readerModeCb(err : BusinessError, tagInfo : tag.TagInfo) {
    if (!err) {
        console.log("offCallback: tag found tagInfo = ", JSON.stringify(tagInfo));
    } else {
        console.error("offCallback err: " + err.message);
        return;
    }
  // taginfo的其他操作
}

export default class MainAbility extends UIAbility {
    OnCreate(want : Want, launchParam : AbilityConstant.LaunchParam) {
        console.log("OnCreate");
        elementName = {
            bundleName: want.bundleName as string,
            abilityName: want.abilityName as string,
            moduleName: want.moduleName as string
        }
    }

    onForeground() {
        console.log("on start");
        try {
            tag.on('readerMode', elementName, discTech, readerModeCb);
        } catch (e) {
            console.error("tag.on error: " + (e as BusinessError).message);
        }
    }

    onBackground() {
        console.log("onBackground");
        try {
            tag.off('readerMode', elementName, readerModeCb);
        } catch (e) {
            console.error("tag.off error: " + (e as BusinessError).message);
        }
    }

    onWindowStageDestroy() {
        console.log("onWindowStageDestroy");
        try {
            tag.off('readerMode', elementName, readerModeCb);
        } catch (e) {
            console.error("tag.off error: " + (e as BusinessError).message);
        }
    }

  // ability生命周期内的其他功能
}
```

## tag.ndef.makeUriRecord<sup>9+</sup>

makeUriRecord(uri: string): NdefRecord

根据输入的URI，构建NDEF标签的Record数据对象。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型   | 必填 | 说明                              |
| ------ | ------ | ---- | --------------------------------- |
| uri    | string | 是   | 写入到NDEF Record里面的数据内容。 |

**返回值：**

| **类型**                   | **说明**                                                     |
| -------------------------- | ------------------------------------------------------------ |
| [NdefRecord](#ndefrecord9) | NDEF标签的Record，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

try {
    let uri = "https://www.example.com"; // 修改为正确可用的uri
    let ndefRecord : tag.NdefRecord = tag.ndef.makeUriRecord(uri);
    if (ndefRecord != undefined) {
        console.log("ndefMessage makeUriRecord rtdType: " + ndefRecord.rtdType);
        console.log("ndefMessage makeUriRecord payload: " + ndefRecord.payload);
    } else {
        console.log("ndefMessage makeUriRecord ndefRecord: " + ndefRecord);
    }
} catch (businessError) {
    console.error("ndefMessage makeUriRecord catch businessError: " + businessError);
}
```

## tag.ndef.makeTextRecord<sup>9+</sup>

makeTextRecord(text: string, locale: string): NdefRecord

根据输入的文本数据和编码类型，构建NDEF标签的Record。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型   | 必填 | 说明                                  |
| ------ | ------ | ---- | ------------------------------------- |
| text   | string | 是   | 写入到NDEF Record里面的文本数据内容。 |
| locale | string | 是   | 文本数据内容的编码方式。              |

**返回值：**

| **类型**                   | **说明**                                                     |
| -------------------------- | ------------------------------------------------------------ |
| [NdefRecord](#ndefrecord9) | NDEF标签的Record，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

try {
    let text = "Hello World";   // 修改为想要写入的文本
    let locale = "en"; // 修改为预期的编码格式
    let ndefRecord : tag.NdefRecord = tag.ndef.makeTextRecord(text, locale);
    if (ndefRecord != undefined) {
        console.log("ndefMessage makeTextRecord rtdType: " + ndefRecord.rtdType);
        console.log("ndefMessage makeTextRecord payload: " + ndefRecord.payload);
    } else {
        console.log("ndefMessage makeTextRecord ndefRecord: " + ndefRecord);
    }
} catch (businessError) {
    console.error("ndefMessage makeTextRecord catch businessError: " + businessError);
}
```

## tag.ndef.makeApplicationRecord<sup>18+</sup>

makeApplicationRecord(bundleName: string): NdefRecord

根据OpenHarmony应用的bundlename，构建NDEF标签的Record。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型   | 必填 | 说明                                  |
| ------ | ------ | ---- | ------------------------------------- |
| bundleName   | string | 是   | 要创建标签的应用包名。 |

**返回值：**

| **类型**                   | **说明**                                                     |
| -------------------------- | ------------------------------------------------------------ |
| [NdefRecord](#ndefrecord9) | NDEF标签的Record，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

try {
    let bundleName: string = 'com.demo.test';
    let ndefRecord : tag.NdefRecord = tag.ndef.makeApplicationRecord(bundleName);
    if (ndefRecord != undefined) {
        console.log("ndefMessage makeApplicationRecord rtdType: " + ndefRecord.rtdType);
        console.log("ndefMessage makeApplicationRecord payload: " + ndefRecord.payload);
    } else {
        console.log("ndefMessage makeApplicationRecord ndefRecord: " + ndefRecord);
    }
} catch (businessError) {
    console.error("ndefMessage makeApplicationRecord catch businessError: " + businessError);
}
```

## tag.ndef.makeMimeRecord<sup>9+</sup>

makeMimeRecord(mimeType: string, mimeData: number[]): NdefRecord

根据输入的MIME数据和类型，构建NDEF标签的Record。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                    |
| -------- | -------- | ---- | ------------------------------------------------------- |
| mimeType | string   | 是   | 符合RFC规则的MIME类型，比如"text/plain"或"image/jpeg"。 |
| mimeData | number[] | 是   | MIME数据内容，每个number十六进制表示，范围是0x00~0xFF。 |

**返回值：**

| **类型**                   | **说明**                                                     |
| -------------------------- | ------------------------------------------------------------ |
| [NdefRecord](#ndefrecord9) | NDEF标签的Record，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

try {
    let mimeType = "text/plain";   // 修改为预期的符合规则的MIME类型
    let mimeData = [0x01, 0x02, 0x03, 0x04]; // 修改为预期的符合格式的数据
    let ndefRecord : tag.NdefRecord = tag.ndef.makeMimeRecord(mimeType, mimeData);
    if (ndefRecord != undefined) {
        console.log("ndefMessage makeMimeRecord rtdType: " + ndefRecord.rtdType);
        console.log("ndefMessage makeMimeRecord payload: " + ndefRecord.payload);
    } else {
        console.log("ndefMessage makeMimeRecord ndefRecord: " + ndefRecord);
    }
} catch (businessError) {
    console.error("ndefMessage makeMimeRecord catch businessError: " + businessError);
}
```
## tag.ndef.makeExternalRecord<sup>9+</sup>

makeExternalRecord(domainName: string, type: string, externalData: number[]): NdefRecord

根据应用程序特定的外部数据，构建NDEF标签的Record。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名       | 类型     | 必填 | 说明                                                    |
| ------------ | -------- | ---- | ------------------------------------------------------- |
| domainName   | string   | 是   | 外部数据发布组织的域名，一般是应用程序的包名。          |
| type         | string   | 是   | 外部数据的指定类型。                                    |
| externalData | number[] | 是   | 外部数据内容，每个number十六进制表示，范围是0x00~0xFF。 |

**返回值：**

| **类型**                   | **说明**                                                     |
| -------------------------- | ------------------------------------------------------------ |
| [NdefRecord](#ndefrecord9) | NDEF标签的Record，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

try {
    let domainName = "ohos.nfc.application"; // 修改为符合规范的包名
    let type = "test"; // 修改为正确的数据类型
    let externalData = [0x01, 0x02, 0x03, 0x04]; // 修改为正确的外部数据内容
    let ndefRecord : tag.NdefRecord = tag.ndef.makeExternalRecord(domainName, type, externalData);
    if (ndefRecord != undefined) {
        console.log("ndefMessage makeExternalRecord rtdType: " + ndefRecord.rtdType);
        console.log("ndefMessage makeExternalRecord payload: " + ndefRecord.payload);
    } else {
        console.log("ndefMessage makeExternalRecord ndefRecord: " + ndefRecord);
    }
} catch (businessError) {
    console.error("ndefMessage makeExternalRecord catch businessError: " + businessError);
}
```

## tag.ndef.messageToBytes<sup>9+</sup>

messageToBytes(ndefMessage: [NdefMessage](js-apis-nfctech.md#ndefmessage9)): number[]

把输入的NDEF消息数据对象，转换为字节格式的数据。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名      | 类型                                           | 必填 | 说明               |
| ----------- | ---------------------------------------------- | ---- | ------------------ |
| ndefMessage | [NdefMessage](js-apis-nfctech.md#ndefmessage9) | 是   | NDEF消息数据对象。 |

**返回值：**

| **类型** | **说明**                                                                              |
| -------- | ------------------------------------------------------------------------------------- |
| number[] | NDEF消息数据对象，所转换成的字节格式的数据。每个number十六进制表示，范围是0x00~0xFF。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

let rawData = [0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]; // 必须符合NDEF格式的数据
try {
    let ndefMessage : tag.NdefMessage = tag.ndef.createNdefMessage(rawData);
    console.log("ndef createNdefMessage, ndefMessage: " + ndefMessage);
    let rawData2 : number[] = tag.ndef.messageToBytes(ndefMessage);
    console.log("ndefMessage messageToBytes rawData2: " + rawData2);
} catch (businessError) {
    console.error("ndef createNdefMessage businessError: " + businessError);
}
```
## tag.ndef.createNdefMessage<sup>9+</sup>

createNdefMessage(data: number[]): [NdefMessage](js-apis-nfctech.md#ndefmessage9)

使用原始字节数据创建NDEF标签的Message。该数据必须符合NDEF Record数据格式，如果不符合格式，则返回的NdeMessage数据对象，所包含的NDE Record列表会为空。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| **参数名** | **类型** | **必填** | **说明**                                                                           |
| ---------- | -------- | -------- | ---------------------------------------------------------------------------------- |
| data       | number[] | 是       | 原始字节，每个number十六进制表示，范围是0x00~0xFF。要求必须满足NDEF Record的格式。 |

**返回值：**

| **类型**                                       | **说明**                                                      |
| ---------------------------------------------- | ------------------------------------------------------------- |
| [NdefMessage](js-apis-nfctech.md#ndefmessage9) | NDEF标签的Message，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |

**示例：**
```js
import { tag } from '@kit.ConnectivityKit';

let rawData = [0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43];  //必须是可以被解析的NDEF记录
try {
    let ndefMessage : tag.NdefMessage = tag.ndef.createNdefMessage(rawData);
    console.log("ndef createNdefMessage, ndefMessage: " + ndefMessage);
} catch (businessError) {
    console.error("ndef createNdefMessage businessError: " + businessError);
}
```

## tag.ndef.createNdefMessage<sup>9+</sup>

createNdefMessage(ndefRecords: NdefRecord[]): [NdefMessage](js-apis-nfctech.md#ndefmessage9)

使用NDEF Records列表，创建NDEF Message。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| **参数名**  | **类型**                                      | **必填** | **说明**                                                         |
| ----------- | --------------------------------------------- | -------- | ---------------------------------------------------------------- |
| ndefRecords | [NdefRecord](js-apis-nfcTag.md#ndefrecord9)[] | 是       | NDEF标签的Record列表，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**返回值：**

| **类型**                                       | **说明**                                                      |
| ---------------------------------------------- | ------------------------------------------------------------- |
| [NdefMessage](js-apis-nfctech.md#ndefmessage9) | NDEF标签的Message，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息                                  |
| -------- | ----------------------------------------- |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

let uriRecord : tag.NdefRecord = tag.ndef.makeUriRecord("https://www.example.com");
let textRecord : tag.NdefRecord = tag.ndef.makeTextRecord("Hello World", "en");
let ndefRecords : tag.NdefRecord[] = [uriRecord, textRecord];
try {
    let ndefMessage : tag.NdefMessage = tag.ndef.createNdefMessage(ndefRecords);
    console.log("ndef createNdefMessage ndefMessage: " + ndefMessage);
} catch (businessError) {
    console.error("ndef createNdefMessage businessError: " + businessError);
}
```

## TagInfo

NFC服务在读取到标签时给出的对象，通过改对象属性，应用知道该标签支持哪些技术类型，并使用匹配的技术类型来调用相关接口。

**系统能力：** SystemCapability.Communication.NFC.Tag

**需要权限：** ohos.permission.NFC_TAG

| **名称**                      | **类型**                                                      | **可读** | **可写** | **说明**                                                                                     |
| ----------------------------- | ------------------------------------------------------------- | -------- | -------- | -------------------------------------------------------------------------------------------- |
| uid<sup>9+</sup>              | number[]                                                      | 是       | 否       | 标签的uid，每个number值是十六进制表示，范围是0x00~0xFF。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                     |
| technology<sup>9+</sup>       | number[]                                                      | 是       | 否       | 支持的技术类型，每个number值表示所支持技术类型的常量值。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                                     |
| supportedProfiles             | number[]                                                      | 是       | 否       | 支持的技术类型，从API9开始不支持，使用[tag.TagInfo#technology](#taginfo)替代。            |

## NdefRecord<sup>9+</sup>
NDEF标签Record属性的定义，参考NDEF标签技术规范《NFCForum-TS-NDEF_1.0》的定义细节。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| **名称** | **类型** | **可读** | **可写** | **说明**                                                                                  |
| -------- | -------- | -------- | -------- | ----------------------------------------------------------------------------------------- |
| tnf      | number   | 是       | 否       | NDEF Record的TNF(Type Name Field)。                                                       |
| rtdType  | number[] | 是       | 否       | NDEF Record的RTD(Record Type Definition)类型值，每个number十六进制表示，范围是0x00~0xFF。 |
| id       | number[] | 是       | 否       | NDEF Record的ID，每个number十六进制表示，范围是0x00~0xFF。                                |
| payload  | number[] | 是       | 否       | NDEF Record的PAYLOAD，每个number十六进制表示，范围是0x00~0xFF。                           |

## 常量
NFC Tag有多种不同的技术类型，定义常量描述不同的技术类型。

**系统能力：** SystemCapability.Communication.NFC.Tag

| **名称**                     |**类型**| **值** | **说明**                    |
| ---------------------------- | ------ | ------ | --------------------------- |
| NFC_A<sup>12+</sup>                        |  number | 1      | NFC-A (ISO 14443-3A)技术。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。  |
| NFC_B<sup>12+</sup>                        |  number | 2      | NFC-B (ISO 14443-3B)技术。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。  |
| ISO_DEP<sup>12+</sup>                      |  number | 3      | ISO-DEP (ISO 14443-4)技术。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。 |
| NFC_F<sup>12+</sup>                        |  number | 4      | NFC-F (JIS 6319-4)技术。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。    |
| NFC_V<sup>12+</sup>                        |  number | 5      | NFC-V (ISO 15693)技术。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。     |
| NDEF<sup>12+</sup>                         |  number | 6      | NDEF技术。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。                  |
| NDEF_FORMATABLE<sup>9+</sup> |  number | 7      | 可以格式化的NDEF技术。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。       |
| MIFARE_CLASSIC<sup>12+</sup>               |  number | 8      | MIFARE Classic技术。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。        |
| MIFARE_ULTRALIGHT<sup>12+</sup>            |  number | 9      | MIFARE Utralight技术。<br>**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。      |
| NFC_BARCODE<sup>18+</sup>    |  number | 10     | BARCODE技术。<br>**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。               |

## TnfType<sup>9+</sup>
NDEF Record的TNF(Type Name Field)类型值，参考NDEF标签技术规范《NFCForum-TS-NDEF_1.0》的定义细节。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| **名称**         | **值** | **说明**                                         |
| ---------------- | ------ | ------------------------------------------------ |
| TNF_EMPTY        | 0x0    | Empty。                                          |
| TNF_WELL_KNOWN   | 0x1    | NFC Forum well-known type [NFC RTD]。            |
| TNF_MEDIA        | 0x2    | Media-type as defined in RFC 2046 [RFC 2046]。   |
| TNF_ABSOLUTE_URI | 0x3    | Absolute URI as defined in RFC 3986 [RFC 3986]。 |
| TNF_EXT_APP      | 0x4    | NFC Forum external type [NFC RTD]。              |
| TNF_UNKNOWN      | 0x5    | Unknown。                                        |
| TNF_UNCHANGED    | 0x6    | Unchanged (see section 2.3.3)。                  |

## NDEF Record RTD类型定义
NDEF Record的RTD(Record Type Definition)类型值，参考NDEF标签技术规范《NFCForum-TS-NDEF_1.0》的定义细节。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| **名称**              |**类型**| **值** | **说明**                |
| --------------------- | ------ | ------ | ----------------------- |
| RTD_TEXT<sup>9+</sup> |number[]| [0x54] | 文本类型的NDEF Record。 |
| RTD_URI<sup>9+</sup>  |number[]| [0x55] | URI类型的NDEF Record。  |

## NfcForumType<sup>9+</sup>
NFC Forum标准里面Tag类型的定义。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| **名称**         | **值** | **说明**             |
| ---------------- | ------ | -------------------- |
| NFC_FORUM_TYPE_1 | 1      | NFC论坛类型1。       |
| NFC_FORUM_TYPE_2 | 2      | NFC论坛类型2。       |
| NFC_FORUM_TYPE_3 | 3      | NFC论坛类型3。       |
| NFC_FORUM_TYPE_4 | 4      | NFC论坛类型4。       |
| MIFARE_CLASSIC   | 101    | MIFARE Classic类型。 |

## MifareClassicType<sup>9+</sup>
MIFARE Classic标签类型的定义。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| **名称**     | **值** | **说明**             |
| ------------ | ------ | -------------------- |
| TYPE_UNKNOWN | 0      | 未知的MIFARE类型。   |
| TYPE_CLASSIC | 1      | MIFARE Classic类型。 |
| TYPE_PLUS    | 2      | MIFARE Plus类型。    |
| TYPE_PRO     | 3      | MIFARE Pro类型。     |

## MifareClassicSize<sup>9+</sup>
MIFARE Classic标签存储大小的定义。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| **名称**     | **值** | **说明**                          |
| ------------ | ------ | --------------------------------- |
| MC_SIZE_MINI | 320    | 每个标签5个扇区，每个扇区4个块。  |
| MC_SIZE_1K   | 1024   | 每个标签16个扇区，每个扇区4个块。 |
| MC_SIZE_2K   | 2048   | 每个标签32个扇区，每个扇区4个块。 |
| MC_SIZE_4K   | 4096   | 每个标签40个扇区，每个扇区4个块。 |

## MifareUltralightType<sup>9+</sup>
MIFARE Ultralight标签类型的定义。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| **名称**          | **值** | **说明**                  |
| ----------------- | ------ | ------------------------- |
| TYPE_UNKNOWN      | 0      | 未知的 MIFARE 类型。      |
| TYPE_ULTRALIGHT   | 1      | MIFARE Ultralight类型。   |
| TYPE_ULTRALIGHT_C | 2      | MIFARE UltralightC 类型。 |

## NfcATag<sup>7+</sup>

type NfcATag = _NfcATag

获取NfcATag。

**系统能力**：SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| [_NfcATag](./js-apis-nfctech.md#nfcatag) | NfcATag 提供 NFC-A(ISO 14443-3A)技术的属性和I/O操作的访问。 |

## NfcBTag<sup>7+</sup>

type NfcBTag = _NfcBTag

获取NfcBTag。

**系统能力**：SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| [_NfcBTag](./js-apis-nfctech.md#nfcbtag) | NfcBTag 提供 NFC-B(ISO 14443-3B)技术的属性和I/O操作的访问。 |

## NfcFTag<sup>7+</sup>

type NfcFTag = _NfcFTag

获取NfcFTag。

**系统能力**：SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| [_NfcFTag](./js-apis-nfctech.md#nfcftag) | NfcFTag 提供对 NFC-F(JIS 6319-4)技术的属性和I/O操作的访问。 |

## NfcVTag<sup>7+</sup>

type NfcVTag = _NfcVTag

获取NfcVTag。

**系统能力**：SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| [_NfcVTag](./js-apis-nfctech.md#nfcvtag) | NfcVTag 提供对 NFC-V(ISO 15693)技术的属性和I/O操作的访问。 |

## IsoDepTag<sup>9+</sup>

type IsoDepTag = _IsoDepTag

获取IsoDepTag。

**系统能力**：SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| [_IsoDepTag](./js-apis-nfctech.md#isodeptag9) | IsoDepTag 提供 ISO-DEP(ISO 14443-4)技术的属性和I/O操作的访问。 |

## NdefTag<sup>9+</sup>

type NdefTag = _NdefTag

获取NdefTag。

**系统能力**：SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| [_NdefTag](./js-apis-nfctech.md#ndeftag9) | 提供对已格式化为NDEF的NFC标签的数据和操作的访问。 |

## MifareClassicTag<sup>9+</sup>

type MifareClassicTag = _MifareClassicTag

获取MifareClassicTag。

**系统能力**：SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| [_MifareClassicTag](./js-apis-nfctech.md#mifareclassictag9) | MifareClassicTag提供对MIFARE Classic属性和I/O操作的访问。 |

## MifareUltralightTag<sup>9+</sup>

type MifareUltralightTag = _MifareUltralightTag;

获取MifareUltralightTag。

**系统能力**：SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| [_MifareUltralightTag](./js-apis-nfctech.md#mifareultralighttag9) | MifareUltralightTag 提供对MIFARE Ultralight属性和I/O操作的访问。 |

## NdefFormatableTag<sup>9+</sup>

type NdefFormatableTag = _NdefFormatableTag

获取NdefFormatableTag。

**系统能力**：SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| [_NdefFormatableTag](./js-apis-nfctech.md#ndefformatabletag9) | NdefFormatableTag为NDEF Formattable的标签提供格式化操作。 |

## BarcodeTag<sup>18+</sup>

type BarcodeTag = _BarcodeTag

获取BarcodeTag。

**系统能力**：SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 18开始，该接口支持在原子化服务中使用。

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| [_BarcodeTag](./js-apis-nfctech.md#barcodetag18) | 提供对条形码标签的属性和I/O操作的访问。 |

## NdefMessage<sup>9+</sup>

type NdefMessage = _NdefMessage

获取NdefMessage。

**系统能力**：SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| [_NdefMessage](./js-apis-nfctech.md#ndefmessage9) | 获取NDEF消息中的所有记录。 |

## TagSession<sup>7+</sup>

type TagSession = _TagSession

获取TagSession。

**系统能力**：SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| [_TagSession](./js-apis-tagSession.md#tagsession) | TagSession是所有[NFC Tag技术类型](js-apis-nfctech.md)的基类， 提供建立连接和发送数据等共同接口。 |
<!--no_check-->