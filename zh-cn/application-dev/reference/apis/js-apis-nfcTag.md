# @ohos.nfc.tag (标准NFC-Tag)

本模块主要用于操作及管理NFC Tag。

> **说明：**
>
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
    // add other code here...

    // want is initialized by nfc service, contains tag info for this found tag
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
        // also check for technology: tag.NFC_B/NFC_F/NFC_V/NDEF/MIFARE_CLASSIC/MIFARE_ULTRALIGHT/NDEF_FORMATABLE
    }

    // use NfcA APIs to access the found tag.
    if (isNfcATag) {
        var nfcA;
        try {
            nfcA = tag.getNfcATag(taginfo);
        } catch (error) {
            console.log("tag.getNfcATag catched error: " + error);
        }
        // other code to read or write this found tag.
    }

    // use getIsoDep APIs to access the found tag.
    if (isIsoDepTag) {
        var isoDep;
        try {
            isoDep = tag.getIsoDep(taginfo);
        } catch (error) {
            console.log("tag.getIsoDep catched error: " + error);
        }
        // other code to read or write this found tag.
    }

    // use the same code to handle for "NfcA/NfcB/NfcF/NfcV/Ndef/MifareClassic/MifareUL/NdefFormatable".
}
```

## tag.getNfcATag

getNfcATag(tagInfo: [TagInfo](#taginfo)): [NfcATag](js-apis-nfctech.md#nfcatag)

获取NFC A类型Tag对象，通过该对象可访问NfcA技术类型的Tag。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明** |
| -------- | -------- |
| [NfcATag](js-apis-nfctech.md#nfcatag) | NFC A类型Tag对象。 |

## tag.getNfcBTag

getNfcBTag(tagInfo: [TagInfo](#taginfo)): [NfcBTag](js-apis-nfctech.md#nfcbtag)

获取NFC B类型Tag对象，通过该对象可访问NfcB技术类型的Tag。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**         |
| -------- | ---------------- |
| [NfcBTag](js-apis-nfctech.md#nfcbtag)  | NFC B类型Tag对象。 |

## tag.getNfcFTag

getNfcFTag(tagInfo: [TagInfo](#taginfo)): [NfcFTag](js-apis-nfctech.md#nfcftag)

获取NFC F类型Tag对象，通过该对象可访问NfcF技术类型的Tag。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**         |
| -------- | ---------------- |
| [NfcFTag](js-apis-nfctech.md#nfcftag)  | NFC F类型Tag对象。 |

## tag.getNfcVTag

getNfcVTag(tagInfo: [TagInfo](#taginfo)): [NfcVTag](js-apis-nfctech.md#nfcvtag)

获取NFC V类型Tag对象，通过该对象可访问NfcV技术类型的Tag。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**         |
| -------- | ---------------- |
| [NfcVTag](js-apis-nfctech.md#nfcvtag)  | NFC V类型Tag对象。 |

## tag.getIsoDep<sup>9+</sup>

getIsoDep(tagInfo: [TagInfo](#taginfo)): [IsoDepTag](js-apis-nfctech.md#isoDepTag9 )

获取IsoDep类型Tag对象，通过该对象可访问支持IsoDep技术类型的Tag。

**系统能力：** SystemCapability.Communication.NFC.Core

**参数：**

| 参数名       | 类型                        | 必填   | 说明                                       |
| --------- | ------------------------- | ---- | ---------------------------------------- |
| taginfo      | [TagInfo](#taginfo)                   | 是 | 包含Tag技术类型和相关参数，从tag.getTagInfo(want: Want)获取。                              |

**返回值：**

| **类型** | **说明**            |
| ---------- | ------------------|
| [IsoDepTag](js-apis-nfctech.md#isodeptag9)  | IsoDep类型Tag对象，通过该对象访问IsoDep类型的相关接口。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](../errorcodes/errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

## tag.getNdef<sup>9+</sup>

getNdef(tagInfo: [TagInfo](#taginfo)): [NdefTag](js-apis-nfctech.md#ndeftag9)

获取NDEF类型Tag对象，通过该对象可访问支持NDEF技术类型的Tag。

**系统能力：** SystemCapability.Communication.NFC.Core

**参数：**

| 参数名       | 类型                        | 必填   | 说明                                       |
| --------- | ------------------------- | ---- | ---------------------------------------- |
| taginfo      | [TagInfo](#taginfo)                   | 是    | 包含Tag技术类型和相关参数，从tag.getTagInfo(want: Want)获取。                              |

**返回值：**

| **类型** | **说明**        |
| ---------| -------------- |
| [NdefTag](js-apis-nfctech.md#ndeftag9)  | NDEF类型Tag对象，通过该对象访问NDEF类型的相关接口。|

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](../errorcodes/errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

## tag.getMifareClassic<sup>9+</sup>

getMifareClassic(tagInfo: [TagInfo](#taginfo)): [MifareClassicTag](js-apis-nfctech.md#mifareclassictag-9)

获取MIFARE Classic类型Tag对象，通过该对象访问支持MIFARE Classic技术类型的Tag。

**系统能力：** SystemCapability.Communication.NFC.Core

**参数：**

| 参数名       | 类型                        | 必填   | 说明                                       |
| --------- | ------------------------- | ---- | ---------------------------------------- |
| taginfo      | [TagInfo](#taginfo)                   | 是    | 包含Tag技术类型和相关参数，从tag.getTagInfo(want: Want)获取。                              |

**返回值：**

| **类型** | **说明**                          |
| ----------------- | ------------------------|
| [MifareClassicTag](js-apis-nfctech.md#mifareclassictag-9)  | MIFARE Classic类型Tag对象，通过该对象访问MIFARE Classic类型的相关接口。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](../errorcodes/errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

## tag.getMifareUltralight<sup>9+</sup>

getMifareUltralight(tagInfo: [TagInfo](#taginfo)): [MifareUltralightTag](js-apis-nfctech.md#mifareultralighttag9)

获取MIFARE Ultralight类型Tag对象，通过该对象可访问支持MIFARE Ultralight技术类型的Tag。

**系统能力：** SystemCapability.Communication.NFC.Core

**参数：**
| 参数名       | 类型                        | 必填   | 说明                                       |
| --------- | ------------------------- | ---- | ---------------------------------------- |
| taginfo      | [TagInfo](#taginfo)                   | 是    | 包含Tag技术类型和相关参数，从tag.getTagInfo(want: Want)获取。                              |

**返回值：**

| **类型** | **说明**                                |
| -------------------- | ---------------------------|
| [MifareUltralightTag](js-apis-nfctech.md#mifareultralighttag9)  | MIFARE Ultralight类型Tag对象，通过该对象访问MIFARE Ultralight类型的相关接口。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](../errorcodes/errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

## tag.getNdefFormatable<sup>9+</sup>

getNdefFormatable(tagInfo: [TagInfo](#taginfo)): [NdefFormatableTag](js-apis-nfctech.md#ndefformatabletag9)

获取NDEF Formatable类型Tag对象，通过该对象可访问支持NDEF Formatable技术类型的Tag。

**系统能力：** SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefFormatableTag](js-apis-nfctech.md#ndefformatabletag)  | NDEF Formatable类型Tag对象，通过该对象访问NDEF Formatable类型的相关接口。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](../errorcodes/errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

## tag.getTagInfo<sup>9+</sup>

getTagInfo(want: [Want](js-apis-app-ability-want.md#Want)): [TagInfo](#taginfo)

从Want中获取TagInfo，Want是被NFC服务初始化，包含了TagInfo所需的属性值。

**系统能力：** SystemCapability.Communication.NFC.Core

**参数：**

| 参数名       | 类型                        | 必填   | 说明                                       |
| --------- | ------------------------- | ---- | ---------------------------------------- |
| want      | [Want](js-apis-app-ability-want.md#Want)                   | 是    | 分发Ability时，在系统onCreate入口函数的参数中获取。                              |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [TagInfo](#taginfo) | TagInfo对象，用于获取不同技术类型的Tag对象。 |


## tag.ndef.makeUriRecord<sup>9+</sup>

makeUriRecord(uri: string): [NdefRecord](#ndefrecord9);

根据输入的URI，构建NDEF标签的Record数据对象。

**系统能力：** SystemCapability.Communication.NFC.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| uri | string | 是 | 写入到NDEF Record里面的数据内容。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefRecord](#ndefrecord9) | NDEF标签的Record，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**示例：**

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

根据输入的文本数据和编码类型，构建NDEF标签的Record。

**系统能力：** SystemCapability.Communication.NFC.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| text | string | 是   | 写入到NDEF Record里面的文本数据内容。 |
| locale | string | 是   | 文本数据内容的编码方式。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefRecord](#ndefrecord9) | NDEF标签的Record，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**示例：**

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

根据输入的MIME数据和类型，构建NDEF标签的Record。

**系统能力：** SystemCapability.Communication.NFC.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| mimeType | string | 是   | 符合RFC规则的MIME类型，比如"text/plain"或"image/jpeg"。 |
| mimeData | number[] | 是   | MIME数据内容，每个number十六进制表示，范围是0x00~0xFF。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefRecord](#ndefrecord9) | NDEF标签的Record，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**示例：**

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

根据应用程序特定的外部数据，构建NDEF标签的Record。

**系统能力：** SystemCapability.Communication.NFC.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| domainName | string | 是   | 外部数据发布组织的域名，一般是应用程序的包名。 |
| type | string | 是   | 外部数据的指定类型。 |
| externalData | number[] | 是   | 外部数据内容，每个number十六进制表示，范围是0x00~0xFF。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefRecord](#ndefrecord9) | NDEF标签的Record，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**示例：**

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

把输入的NDEF消息数据对象，转换为字节格式的数据。

**系统能力：** SystemCapability.Communication.NFC.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| ndefMessage | [NdefMessage](js-apis-nfctech.md#ndefmessage9) | 是   | NDEF消息数据对象。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number[] | NDEF消息数据对象，所转换成的字节格式的数据。每个number十六进制表示，范围是0x00~0xFF。 |

**示例：**

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

使用原始字节数据创建NDEF标签的Message。该数据必须符合NDEF Record数据格式，如果不符合格式，则返回的NdeMessage数据对象，所包含的NDE Record列表会为空。

**系统能力：** SystemCapability.Communication.NFC.Core

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| data | number[] | 是 | 原始字节，每个number十六进制表示，范围是0x00~0xFF。要求必须满足NDEF Record的格式。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefMessage](js-apis-nfctech.md#ndefmessage9) | NDEF标签的Message，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**示例：**
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

使用NDEF Records列表，创建NDEF Message。

**系统能力：** SystemCapability.Communication.NFC.Core

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| ndefRecords | [NdefRecord](js-apis-nfcTag.md#ndefrecord9)[] | 是 | NDEF标签的Record列表，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefMessage](js-apis-nfctech.md#ndefmessage9) | NDEF标签的Message，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。|

**示例：**

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

NFC服务在读取到标签时给出的对象，通过改对象属性，应用知道该标签支持哪些技术类型，并使用匹配的技术类型来调用相关接口。

**系统能力：** SystemCapability.Communication.NFC.Core

**需要权限：** ohos.permission.NFC_TAG

| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| uid<sup>9+</sup> | number[] | 是 | 否 | 标签的uid，每个number值是十六进制表示，范围是0x00~0xFF。|
| technology<sup>9+</sup> | number[] | 是 | 否 | 支持的技术类型，每个number值表示所支持技术类型的常量值。 |
| supportedProfiles | number[] | 是 | 否 |  支持的技术类型，从API9开始不支持，使用[tag.TagInfo#technology](#taginfo)替代。|
| extrasData<sup>9+</sup> | [PacMap](js-apis-inner-ability-dataAbilityHelper.md#pacmap)[] | 是 | 否 |  标签所支持技术的扩展属性值。<br>**系统接口：** 此接口为系统接口。|
| tagRfDiscId<sup>9+</sup> | number | 是 | 否 |  标签发现时分配的ID值。<br>**系统接口：** 此接口为系统接口。|
| remoteTagService<sup>9+</sup> | [rpc.RemoteObject](js-apis-rpc.md#remoteobject) | 是 | 否 | NFC服务进程的远端对象，用于客户端和服务之间的接口通信。<br>**系统接口：** 此接口为系统接口。|
## NdefRecord<sup>9+</sup>
NDEF标签Record属性的定义，参考NDEF标签技术规范《NFCForum-TS-NDEF_1.0》的定义细节。

**系统能力：** SystemCapability.Communication.NFC.Core

| **名称** | **类型** | **可读** | **可写** | **说明** |
| -------- | -------- | -------- | -------- | -------- |
| tnf | number | 是 | 否 | NDEF Record的TNF(Type Name Field)。 |
| rtdType| number[] | 是 | 否 | NDEF Record的RTD(Record Type Definition)类型值，每个number十六进制表示，范围是0x00~0xFF。 |
| id | number[] | 是 | 否 | NDEF Record的ID，每个number十六进制表示，范围是0x00~0xFF。|
| payload | number[] | 是 | 否 | NDEF Record的PAYLOAD，每个number十六进制表示，范围是0x00~0xFF。 |

## 技术类型定义
NFC Tag有多种不同的技术类型，定义常量描述不同的技术类型。

**系统能力：** SystemCapability.Communication.NFC.Core

| **名称** | **值** |  **说明** |
| -------- | -------- | -------- |
| NFC_A | 1 | NFC-A (ISO 14443-3A)技术。|
| NFC_B  | 2 | NFC-A (ISO 14443-3B)技术。|
| ISO_DEP | 3 | ISO-DEP (ISO 14443-4)技术。|
| NFC_F  | 4 | NFC-F (JIS 6319-4)技术。|
| NFC_V | 5 | NFC-V (ISO 15693)技术。|
| NDEF  | 6 | NDEF技术。|
| NDEF_FORMATABLE<sup>9+</sup> | 7 | 可以格式化的NDEF技术。|
| MIFARE_CLASSIC | 8 | MIFARE Classic技术。|
| MIFARE_ULTRALIGHT | 9 | MIFARE Utralight技术。|

## TnfType<sup>9+</sup>
NDEF Record的TNF(Type Name Field)类型值，参考NDEF标签技术规范《NFCForum-TS-NDEF_1.0》的定义细节。

**系统能力：** SystemCapability.Communication.NFC.Core

| **名称** | **值** |  **说明** |
| -------- | -------- | -------- |
| TNF_EMPTY | 0x0 | Empty。|
| TNF_WELL_KNOWN  | 0x1 | NFC Forum well-known type [NFC RTD]。|
| TNF_MEDIA | 0x2 | Media-type as defined in RFC 2046 [RFC 2046]。|
| TNF_ABSOLUTE_URI  | 0x3 | Absolute URI as defined in RFC 3986 [RFC 3986]。|
| TNF_EXT_APP | 0x4 | NFC Forum external type [NFC RTD]。|
| TNF_UNKNOWN  | 0x5 | Unknown。|
| TNF_UNCHANGED | 0x6 | Unchanged (see section 2.3.3)。|

## NDEF Record RTD类型定义
NDEF Record的RTD(Record Type Definition)类型值，参考NDEF标签技术规范《NFCForum-TS-NDEF_1.0》的定义细节。

**系统能力：** SystemCapability.Communication.NFC.Core

| **名称** | **值** |  **说明** |
| -------- | -------- | -------- |
| RTD_TEXT<sup>9+</sup> | [0x54] | 文本类型的NDEF Record。|
| RTD_URI<sup>9+</sup>  | [0x55] | URI类型的NDEF Record。|

## NfcForumType<sup>9+</sup>
NFC Forum标准里面Tag类型的定义。

**系统能力：** SystemCapability.Communication.NFC.Core

| **名称** | **值** |  **说明** |
| -------- | -------- | -------- |
| NFC_FORUM_TYPE_1 | 1 |  NFC论坛类型1。 |
| NFC_FORUM_TYPE_2 | 2 |  NFC论坛类型2。 |
| NFC_FORUM_TYPE_3  | 3 |  NFC论坛类型3。 |
| NFC_FORUM_TYPE_4  | 4 |  NFC论坛类型4。 |
| MIFARE_CLASSIC  | 101 |   MIFARE Classic类型。 |

## MifareClassicType<sup>9+</sup>
MIFARE Classic标签类型的定义。

**系统能力：** SystemCapability.Communication.NFC.Core

| **名称** | **值** |  **说明** |
| -------- | -------- | -------- |
| TYPE_UNKNOWN | 0 |  未知的MIFARE类型。 |
| TYPE_CLASSIC | 1 |  MIFARE Classic类型。|
| TYPE_PLUS   | 2 |  MIFARE Plus类型。|
| TYPE_PRO  | 3 |  MIFARE Pro类型。 |

## MifareClassicSize<sup>9+</sup>
MIFARE Classic标签存储大小的定义。

**系统能力：** SystemCapability.Communication.NFC.Core

| **名称** | **值** |  **说明** |
| -------- | -------- | -------- |
| MC_SIZE_MINI | 320 |  每个标签5个扇区，每个扇区4个块。 |
| MC_SIZE_1K  | 1024 |  每个标签16个扇区，每个扇区4个块。|
| MC_SIZE_2K   | 2048 |  每个标签32个扇区，每个扇区4个块。 |
| MC_SIZE_4K   | 4096 |  每个标签40个扇区，每个扇区4个块。|

## MifareUltralightType<sup>9+</sup>
MIFARE Ultralight标签类型的定义。

**系统能力：** SystemCapability.Communication.NFC.Core

| **名称** | **值** |  **说明** |
| -------- | -------- | -------- |
| TYPE_UNKNOWN  | 0 |  未知的 MIFARE 类型。 |
| TYPE_ULTRALIGHT   | 1 |  MIFARE Ultralight类型。|
| TYPE_ULTRALIGHT_C    | 2 |  MIFARE UltralightC 类型。 |
<!--no_check-->