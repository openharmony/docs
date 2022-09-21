# 标准NFC-Tag  Nfc 技术

本模块主要用于采用不同Nfc技术的Tag的读写操作。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## **导入模块**

```js
import tag from '@ohos.nfc.tag';
```

## NfcATag

NfcATag 提供 NFC-A(ISO 14443-3A)技术的属性和I/O操作的访问，继承自TagSession。

TagSession是所有Nfc tag 技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是NfcATag的独有接口。

### NfcATag.getSak

getSak(): number

获取NFC-A标签的SAK值。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number  | NfcA 标签的SAK值。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let sak = tag.getNfcATag(taginfo).getSak(); 
console.log("sak:" +sak);
```

### NfcATag.getAtqa

getAtqa(): number[]

获取NFC-A标签的Atqa值。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number[]  | NfcA 标签的Atqa值。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let atqa = tag.getNfcATag(taginfo).getAtqa();
console.log("atqa:" +atqa);
```

## NfcBTag

NfcBTag 提供对NFC-B(ISO 14443-3B)技术的属性和I/O操作的访问，继承自TagSession。

TagSession是所有Nfc tag 技术类型的基类，提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是NfcBTag的独有接口。

### NfcBTag.getRespAppData

getRespAppData(): number[]

获取标签的应用程序数据。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number[]  | NfcB 标签的应用程序数据。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let appData = tag.getNfcBTag(taginfo).getRespAppData();  
console.log("appData:" +appData);
```

### NfcBTag.getRespProtocol

getRespProtocol(): number[]

获取标签的协议信息。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number[]  | NfcB 标签的协议信息。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let protocol = tag.getNfcBTag(taginfo).getRespProtocol();
console.log("appData:" +protocol);
```

## NfcFTag

NfcFTag 提供对NFC-F(JIS 6319-4)技术的属性和I/O操作的访问，继承自TagSession。

TagSession是所有Nfc tag 技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是NfcFTag的独有接口。

### NfcFTag.getSystemCode

getSystemCode(): number[]

从标签实例获取系统代码。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                            |
| ------------------ | --------------------------|
| number[]  | NfcF 标签的系统代码。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let systemCode = tag.getNfcFTag(taginfo).getSystemCode();  
console.log("systemCode:" +systemCode);
```

### NfcFTag.getPmm

getPmm(): number[]

从标签实例获取PMm（由IC代码和制造商参数组成）。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number[]  | NfcF 标签的PMm信息。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let pmm = tag.getNfcFTag(taginfo).getPmm();
console.log("pmm:" +pmm);
```

## NfcVTag

NfcVTag 提供对NFC-V(ISO 15693)技术的属性和I/O操作的访问，继承自TagSession。

TagSession是所有Nfc tag 技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是NfcVTag的独有接口。

### NfcvTag.getResponseFlags

getResponseFlags(): number

从标签实例实例获取响应标志。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number | NfcV 标签的响应标志。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let flags = tag.getNfcVTag(taginfo).getResponseFlags();  
console.log("flags:" +flags);
```

### NfcvTag.getDsfId

getDsfId(): number

从标签实例实例获取数据存储格式标识符（DSFID）。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number | NfcV 标签的数据存储格式标识符。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let dsfId = tag.getNfcVTag(taginfo).getDsfId();
console.log("dsfId:" +dsfId);
```

## IsoDepTag<sup>9+</sup> 

IsoDepTag 提供对ISO-DEP(ISO 14443-4)技术的属性和I/O操作的访问，继承自TagSession。

TagSession是所有Nfc tag 技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是IsoDepTag的独有接口。

### IsoDepTag.getHistoricalBytes<sup>9+</sup>

getHistoricalBytes(): string

获取标签的历史字节。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| string | IsoDepTag 标签的历史字节。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let historicalBytes = tag.getIsoDepTag(taginfo).getHistoricalBytes();
console.log("historicalBytes:" +historicalBytes);
```

### IsoDepTag.getHiLayerResponse<sup>9+</sup>

getHiLayerResponse(): string

获取标签的HiLayer响应字节。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| string | IsoDepTag 标签的HiLayer响应字节。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let hiLayerResponse = tag.getIsoDepTag(taginfo).getHiLayerResponse();
console.log("hiLayerResponse:" +hiLayerResponse);
```

### IsoDepTag.isExtendedApduSupported<sup>9+</sup>

isExtendedApduSupported(): Promise&lt;boolean&gt;

检查是否支持外部apdu长度，使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise&lt;boolean&gt; | 检查结果，true: 支持， false: 不支持。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.getIsoDepTag(taginfo).isExtendedApduSupported().then(function (has) {
    console.log('has: ' + has)
}) 
```

### IsoDepTag.isExtendedApduSupported<sup>9+</sup>

isExtendedApduSupported(callback: AsyncCallback\<boolean>): void

检查是否支持外部apdu长度，使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，true: 支持， false: 不支持。 |

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.getIsoDepTag(taginfo).isExtendedApduSupported(function (error, has) {
    console.log(JSON.stringify(error))
    console.log('has: ' + has)
}) 
```

## NdefTag<sup>9+</sup>

提供对已格式化为NDEF的NFC标签的数据和操作的访问，继承自TagSession。

TagSession是所有Nfc tag 技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是NdefTag的独有接口。

### NdefTag.createNdefMessage<sup>9+</sup>

createNdefMessage(data: string): [NdefMessage](#ndefmessage9)

使用原始字节创建ndef消息。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| data | string | 是 | 字符串类型的原始字节 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefMessage](#ndefmessage9) | Ndef消息 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let NdefMessage = tag.NdefTag(taginfo).createNdefMessage(data);
```

## NdefMessage<sup>9+</sup>

### NdefMessage.getNdefRecords<sup>9+</sup>

getNdefRecords(): [NdefRecord](#ndefrecord9)[ ]

获取ndef消息的所有记录。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefRecord](#ndefrecord9)[ ] | Ndef消息所包含的所有记录。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let NdefRecord = tag.NdefTag(taginfo).getNdefRecords();
```

## NdefRecord<sup>9+</sup>

| **参数名** | **类型** |  **说明** |
| -------- | -------- | -------- |
| tnf | number |  标签的uid。 |
| [rtdType](#rtdtype9) | string |  支持的技术类型。 |
| id | string |  标签的额外信息。 |
| payload | string |  标签的RF discovery id。 |

## RtdType<sup>9+</sup>

| **参数名** | **类型** |  **说明** |
| -------- | -------- | -------- |
| RTD_TEXT | 'T' |  记录描述文本信息。|
| RTD_URI  | 'U' |  存储网络地址，邮件或者电话号码。|

### NdefTag.createNdefMessage<sup>9+</sup>

createNdefMessage(ndefRecords: NdefRecord[]): [NdefMessage](#ndefmessage9)

使用记录列表创建ndef消息。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| ndefRecords | [NdefRecord](#ndefrecord9)[] | 是 | NdefRecord记录列表。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefMessage](#ndefmessage9) | Ndef消息。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let NdefMessage = tag.NdefTag(taginfo).createNdefMessage(ndefRecords);
```

### NdefTag.getNdefTagType<sup>9+</sup>

getNdefTagType(): NfcForumType

获取Ndef标签的类型。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NfcForumType](#nfcforumtype9) | Ndef标签类型。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let NfcForumType = tag.NdefTag(taginfo).getNdefTagType();
```

### NdefTag.getNdefMessage<sup>9+</sup>

getNdefMessage(): NdefMessage

获取发现标签时，从ndef标签读取的ndef消息。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefMessage](#ndefmessage9)  | Ndef消息。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let NdefMessage = tag.NdefTag(taginfo).getNdefMessage();
```

### NdefTag.isNdefWritable<sup>9+</sup>

isNdefWritable(): Promise&lt;boolean&gt;

检查ndef标签是否可写，使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise&lt;boolean&gt; | 检查结果，true: 可写， false: 不可写。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.NdefTag(taginfo).isNdefWritable().then(function (has) {
    console.log(JSON.stringify(has))
})
```

### NdefTag.isNdefWritable<sup>9+</sup>

isNdefWritable(callback: AsyncCallback&lt;boolean&gt;): void;

检查ndef标签是否可写，使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，ndef标签可写，返回true。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.NdefTag(taginfo).isNdefWritable(function (error, has) {
    console.log(JSON.stringify(error))
    console.log('has: ' + has)
})
```

### NdefTag.readNdef<sup>9+</sup>

readNdef(): Promise\<NdefMessage>

读取标签上的ndef消息，使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<[NdefMessage](#ndefmessage9)> | 以Promise形式返回从标签中读取到的NdefMessage信息。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.NdefTag(taginfo).readNdef().then(function (ndefMessage) {
    console.log(JSON.stringify(ndefMessage))
})
```

### NdefTag.readNdef<sup>9+</sup>

readNdef(callback: AsyncCallback\<[NdefMessage](#ndefmessage9)>): void

读取标签上的ndef消息，使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<[NdefMessage](#ndefmessage9)> | 是   | 回调函数。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.NdefTag(taginfo).readNdef(function (error, ndefMessage) {
    console.log(JSON.stringify(error))
    console.log('ndefMessage: ' + ndefMessage)
})
```

### NdefTag.writeNdef<sup>9+</sup>

writeNdef(msg: NdefMessage): Promise\<number>;

将ndef消息写入标签，使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| msg | NdefMessage | 是   | Ndef消息。|

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<number> | 以Promise形式返回，写入执行后的错误代码。如果返回0，则表示成功。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
NdefTag.writeNdef(msg).then(function (netHandle) {
    console.log(JSON.stringify(netHandle))
})
```

### NdefTag.writeNdef<sup>9+</sup>

writeNdef(msg: NdefMessage, callback: AsyncCallback\<number>): void

将ndef消息写入此标签，使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| msg | NdefMessage | 是   | Ndef消息 |
| callback | AsyncCallback\<number> | 是   | 回调函数。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.NdefTag(taginfo).write(msg，function (error, has) {
    console.log(JSON.stringify(error))
    console.log('has: ' + has)
})
```

### NdefTag.canSetReadOnly<sup>9+</sup>

canSetReadOnly(): Promise\<boolean>

检查ndef标签是否可以设置为只读，使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise&lt;boolean&gt; | true: 标签可设置为只读， false: 标签不可设置为只读。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.NdefTag(taginfo).canSetReadOnly().then(function (has) {
    console.log(JSON.stringify(has))
})
```

### NdefTag.canSetReadOnly<sup>9+</sup>

canSetReadOnly(callback: AsyncCallback&lt;boolean&gt;): void;

检查ndef标签是否可以设置为只读，使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，ndef标签可设置为只读，返回true。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.NdefTag(taginfo).canSetReadOnly(function (error, has) {
    console.log(JSON.stringify(error))
    console.log('has: ' + has)
})
```

### NdefTag.setReadOnly<sup>9+</sup>

setReadOnly(): Promise\<number>

将Ndef标签设置为只读，使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise&lt;number&gt; | 0: 设置成功， 其它: 错误编码。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.NdefTag(taginfo).setReadOnly().then(function (errcode) {
    console.log(JSON.stringify(errcode))
})
```

### NdefTag.setReadOnly<sup>9+</sup>

setReadOnly(callback: AsyncCallback<number>): void

将Ndef标签设置为只读，使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<number> | 是   | 回调函数。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.NdefTag(taginfo).setReadOnly(function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log('has: ' + errcode)
})
```

### NdefTag.getNdefTagTypeString<sup>9+</sup>

getNdefTagTypeString(type: [NfcForumType](#nfcforumtype9)): string

将Nfc论坛类型转换为Nfc论坛中定义的字节数组。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| type | [NfcForumType](#nfcforumtype9) | 是   | NfcForum论坛类型。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| string | Nfc论坛类型字节数组。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let ndefTypeString= tag.NdefTag(taginfo).getNdefTagTypeString(type); 
```

## NfcForumType<sup>9+</sup>

| **参数名** | **类型** |  **说明** |
| -------- | -------- | -------- |
| NFC_FORUM_TYPE_1 | 1 |  NFC论坛类型1。 |
| NFC_FORUM_TYPE_2 | 2 |  NFC论坛类型2。 |
| NFC_FORUM_TYPE_3  | 3 |  NFC论坛类型3。 |
| NFC_FORUM_TYPE_4  | 4 |  NFC论坛类型4。 |
| MIFARE_CLASSIC  | 101 |   Mifare Classic类型。 |

## MifareClassicTag <sup>9+</sup>

MifareClassicTag提供对MIFARE经典属性和I/O操作的访问，继承自TagSession。

TagSession是所有Nfc tag 技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是MifareClassicTag的独有接口。

### MifareClassicTag.authenticateSector<sup>9+</sup>

authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean): Promise\<boolean>

使用密钥对扇区进行身份验证，只有身份验证成功的扇区可以进行操作。使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | 是   | 待验证的扇区索引 |
| key | number[]| 是   | 用于身份验证的密钥（6字节） |
| isKeyA | boolean | 是   | isKeyA标志。true 表示KeyA，false 表示KeyB。|

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<boolean> | 身份验证结果，成功返回true，失败返回false。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareClassicTag(taginfo).authenticateSector(sectorIndex, key).then(function (isKeyA) {
        console.log(JSON.stringify(isKeyA))
        })
```

### MifareClassicTag.authenticateSector<sup>9+</sup>

authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback<boolean>): void

使用密钥对扇区进行身份验证，只有身份验证成功的扇区可以进行操作。使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | 是   | 待验证的扇区索引。 |
| key | number[]| 是   | 用于身份验证的密钥（6字节）。 |
| isKeyA | boolean | 是   | isKeyA标志。true 表示KeyA，false 表示KeyB。|
| callback | AsyncCallback\<boolean> | 是   | 回调函数。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareClassicTag(taginfo).authenticateSector(sectorIndex, key, function (error, has) {
    console.log(JSON.stringify(error))
    console.log('has: ' + has)
})
```

### MifareClassicTag.readSingleBlock<sup>9+</sup>

readSingleBlock(blockIndex: number): Promise\<string>

读取标签中一个块存储的内容，一个块大小为16字节。使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要读取的块索引。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<string> | 读取的块数据。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

let data = "xxx";
// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareClassicTag(taginfo).readSingleBlock(blockIndex).then(function (data){
    console.log('data: ' + data)
    })
```

### MifareClassicTag.readSingleBlock<sup>9+</sup>

readSingleBlock(blockIndex: number, callback: AsyncCallback\<string>): void

读取标签中一个块存储的内容，一个块大小为16字节。使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要读取的块索引 |
| callback | AsyncCallback\<string> | 是   | 回调函数。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

let data = "xxx";
// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareClassicTag(taginfo).readSingleBlock(blockIndex, function (error, data) {
    console.log(JSON.stringify(error))
    console.log('data: ' + data)
})
```

### MifareClassicTag.writeSingleBlock<sup>9+</sup>

writeSingleBlock(blockIndex: number, data: string): Promise\<number>

向标签中一个块存储写入内容，一个块大小为16字节。使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要写入的块索引。 |
| data | string | 是   | 要写入的数据。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<number> | 执行写入操作返回的错误代码。如果返回0，则表示成功。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

let data = "xxx";
// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareClassicTag(taginfo).writeSingleBlock(blockIndex, data).then(function (errcode){
    console.log(JSON.stringify(errcode))
    })
```

### MifareClassicTag.writeSingleBlock<sup>9+</sup>

writeSingleBlock(blockIndex: number, data: string, callback: AsyncCallback\<number>): void

向标签中一个块存储写入内容，一个块大小为16字节。使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要写入的块索引 |
| data | string | 是   | 要写入的数据 |
| callback | AsyncCallback\<number> | 是   | 回调函数。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

let data = "xxx";
// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareClassicTag(taginfo).writeSingleBlock(blockIndex, data, function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(errcode))
})
```

### MifareClassicTag.incrementBlock<sup>9+</sup>

incrementBlock(blockIndex: number, value: number): Promise\<number>

增加一块带值的区域块。使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要增加的块索引。 |
| value | number | 是   | 要增加的块数据，非负值。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<number> | 执行新增操作返回的错误代码。如果返回0，则表示成功。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareClassicTag(taginfo).incrementBlock(blockIndex, value).then(function (errcode){
    console.log(JSON.stringify(errcode))
    })
```

### MifareClassicTag.incrementBlock<sup>9+</sup>

incrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<number>): void

增加一块带值的区域块。使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要增加的块索引。 |
| value | number | 是   | 要增加的块数据，非负值。 |
| callback | AsyncCallback\<number> | 是   | 回调函数。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareClassicTag(taginfo).incrementBlock(blockIndex, value, function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(errcode))
})
```

### MifareClassicTag.decrementBlock<sup>9+</sup>

decrementBlock(blockIndex: number, value: number): Promise\<number>

递减一块带值的区域块。使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要递减的块索引。 |
| value | number | 是   | 要递减的块数据，非负值。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<number> | 执行递减操作返回的错误代码。如果返回0，则表示成功。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareClassicTag(taginfo).decrementBlock(blockIndex, value).then(function (errcode){
    console.log(JSON.stringify(errcode))
    })
```

### MifareClassicTag.decrementBlock<sup>9+</sup>

decrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<number>): void

递减一块带值的区域块。使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要递减的块索引。 |
| value | number | 是   | 要递减的块数据，非负值。 |
| callback | AsyncCallback\<number> | 是   | 回调函数。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareClassicTag(taginfo).decrementBlock(blockIndex, value, function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(errcode))
})
```

### MifareClassicTag.transferToBlock<sup>9+</sup>

transferToBlock(blockIndex: number): Promise\<number>

将寄存器的值复制到块。使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 复制的目的块索引。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<number> | 执行复制操作返回的错误代码。如果返回0，表示成功；否则返回错误码。|

**示例：**

```js

import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareClassicTag(taginfo).transferToBlock(blockIndex).then(function (errcode){
    console.log(JSON.stringify(errcode))
    })
```

### MifareClassicTag.transferToBlock

transferToBlock(blockIndex: number, callback: AsyncCallback\<number>): void

将寄存器的值复制到块。使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 复制的目的块索引 |
| callback | AsyncCallback\<number> | 是   | 回调函数。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareClassicTag(taginfo).transferToBlock(blockIndex, function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(errcode))
})
```

### MifareClassicTag.restoreFromBlock<sup>9+</sup>

restoreFromBlock(blockIndex: number): Promise\<number>

将块的值复制到寄存器。使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 复制的源块索引。|

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<number> | 执行复制操作返回的错误代码。如果返回0，表示成功;否则返回错误码。|

**示例：**

```js

import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareClassicTag(taginfo).restoreFromBlock(blockIndex).then(function (errcode){
    console.log(JSON.stringify(errcode))
    })
```

### MifareClassicTag.restoreFromBlock<sup>9+</sup>

restoreFromBlock(blockIndex: number, callback: AsyncCallback\<number>): void

将块的值复制到寄存器。使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 复制的源块索引 |
| callback | AsyncCallback\<number> | 是   | 回调函数。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareClassicTag(taginfo).restoreFromBlock(blockIndex, function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(errcode))
})
```

### MifareClassicTag.getSectorCount<sup>9+</sup>

getSectorCount(): number

获取mifare classic标签中的扇区数。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number | 扇区数量。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let setorCount = tag.MifareClassicTag(taginfo).getSectorCount();
```

### MifareClassicTag.getBlockCountInSector<sup>9+</sup>

getBlockCountInSector(sectorIndex: number): number

获取扇区中的块数。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | 是   | 扇区序号。|

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number | 该扇区内的块数量。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let blockNumber = tag.MifareClassicTag(taginfo).getBlockCountInSector(sectorIndex);
```

### MifareClassicTag.getType<sup>9+</sup>

getType(): [MifareClassicType](#mifareclassictype9)

获取MifareClassic标签的类型。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [MifareClassicType](#mifareclassictype9) | MifareClassic标签的类型。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let type = tag.MifareClassicTag(taginfo).getType(); 
```

### MifareClassicTag.getTagSize<sup>9+</sup>

getTagSize(): number

获取标签的大小（字节），具体请参见[MifareTagSize](#mifaretagsize9)。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number | 标签的大小，单位为字节，请参见[MifareTagSize](#mifaretagsize9)。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let size = tag.MifareClassicTag(taginfo).getTagSize();
```

## MifareClassicType<sup>9+</sup>

| **参数名** | **值** |  **说明** |
| -------- | -------- | -------- |
| TYPE_UNKNOWN | -1 |  未知Mifare类型。 |
| TYPE_CLASSIC | 0 |  Mifare Classic类型。|
| TYPE_PLUS   | 1 |  Mifare Plus类型。|
| TYPE_PRO  | 2 |  Mifare Pro类型。 |

## MifareTagSize<sup>9+</sup>

| **参数名** | **值** |  **说明** |
| -------- | -------- | -------- |
| MC_SIZE_MINI | 320 |  每个标签5个扇区，每个扇区4个块。 |
| MC_SIZE_1K  | 1024 |  每个标签16个扇区，每个扇区4个块。|
| MC_SIZE_2K   | 2048 |  每个标签32个扇区，每个扇区4个块。 |
| MC_SIZE_4K   | 4096 |  每个标签40个扇区，每个扇区4个块。|

### MifareClassicTag.isEmulatedTag<sup>9+</sup>

isEmulatedTag(): boolean

检查标签是否已模拟。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| boolean |检查结果，true: 是；false：否。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let isEmulated = tag.MifareClassicTag(taginfo).isEmulatedTag();
```

### MifareClassicTag.getBlockIndex<sup>9+</sup>

getBlockIndex(sectorIndex: number): number

获取特定扇区的第一个块。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | 是   | 扇区序号。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number | 该扇区内的第一个块的序列号。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let index = tag.MifareClassicTag(taginfo).getBlockIndex(sectorIndex);
```

### MifareClassicTag.getSectorIndex<sup>9+</sup>

getSectorIndex(blockIndex: number): number

获取扇区索引，该扇区包含特定块。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 块序号。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number | 扇区序号。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let index = tag.MifareClassicTag(taginfo).getSectorIndex(blockIndex);
```

## MifareUltralightTag<sup>9+</sup>

MifareUltralightTag 提供对MIFARE超轻属性和I/O操作的访问，继承自TagSession。

TagSession是所有Nfc tag 技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是MifareUltralightTag的独有接口。

### MifareUltralightTag.readMultiplePages<sup>9+</sup>

readMultiplePages(pageIndex: number): Promise\<string>

阅读4页，共16字节。页面大小为4字节。使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | ------------------------------ |
| pageIndex | number | 是   | 要读取页面的索引。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<string> | 读取的4页的数据。 |

**示例：**

```js

import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareUltralightTag(taginfo).readMultiplePages(pageIndex).then(function (data){
    console.log("data: " + data)
    })
```

### MifareUltralightTag.readMultiplePages<sup>9+</sup>

readMultiplePages(pageIndex: number, callback: AsyncCallback\<string>): void

阅读4页，共16字节。页面大小为4字节。使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| pageIndex | number | 是   | 要读取页面的索引 |
| callback | AsyncCallback\<string> | 是   | 回调函数。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareUltralightTag(taginfo).readMultiplePages(pageIndex, function (error, data) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(data))
})
```

### MifareUltralightTag.writeSinglePages<sup>9+</sup>

writeSinglePages(pageIndex: number, data: string): Promise\<number>

写入一页数据，页面大小为4字节。使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| pageIndex | number | 是   | 要写入页面的索引。 |
| data | string | 是   | 要写入页面的数据内容。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<number> | 执行写入操作返回的错误代码。如果返回0，则表示成功。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareUltralightTag(taginfo).writeSinglePages(pageIndex, data).then(function (errcode){
    console.log(JSON.stringify(errcode))
    })
```

### MifareUltralightTag.writeSinglePages<sup>9+</sup>

writeSinglePages(pageIndex: number, data: string, callback: AsyncCallback\<number>): void

写入一页数据，页面大小为4字节。使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                     |
| -------- | ----------------------- | ---- | ------------------------ |
| pageIndex | number | 是   | 要写入页面的索引。 |
| data | string | 是   | 要写入页面的数据内容。 |
| callback|AsyncCallback\<number> |是| 回调函数。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.MifareUltralightTag(taginfo).writeSinglePages(pageIndex, data, function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(errcode))
})
```

### MifareUltralightTag.getType<sup>9+</sup>

getType(): MifareUltralightType

获取MifareUltralight标签的类型，以字节形式返回，具体请参见 [MifareUltralightType](#mifareultralighttype9)。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| MifareUltralightType | MifareUltralight标签的类型, 具体请参见 [MifareUltralightType](#mifareultralighttype9)。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let type = tag.MifareUltralightType(taginfo).getType(); 
```

### MifareUltralightType<sup>9+</sup>

| **参数名** | **值** |  **说明** |
| -------- | -------- | -------- |
| TYPE_UNKOWN  | -1 |  未知的 Mifare 类型。 |
| TYPE_ULTRALIGHT   | 1 |  Mifare Ultralight类型。|
| TYPE_ULTRALIGHT_C    | 2 |  Mifare UltralightC 类型。 |

## NdefFormatableTag<sup>9+</sup>

NdefFormatableTag为NDEF formattable的标签提供格式化操作，继承自TagSession。

TagSession是所有Nfc tag 技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是NdefFormatableTag的独有接口。

### NdefFormatableTag.format<sup>9+</sup>

format(message: [NdefMessage](#ndefmessage9)): Promise\<number>

将标签格式化为NDEF标签，然后将NDEF消息写入NDEF标签。使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | 是   | 格式化成功时要写入的Ndef消息。可以为null，为null时仅格式化标签，不写入内容。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<number> | 执行操作后返回的错误代码。如果返回0，则表示成功。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.NdefFormatableTag(taginfo).format(message).then(function (errcode){
    console.log(JSON.stringify(errcode))
    })
```

### NdefFormatableTag.format<sup>9+</sup>

format(message: [NdefMessage](#ndefmessage9), callback: AsyncCallback\<number>): void

将标签格式化为NDEF标签，然后将NDEF消息写入NDEF标签。使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | 是   | 格式化成功时要写入的Ndef消息。可以为null，为null时仅格式化标签，不写入内容。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| callback: AsyncCallback\<number> | 回调函数。 |


**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.NdefFormatableTag(taginfo).format(message, function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(errcode))
})
```

### NdefFormatableTag.formatReadOnly<sup>9+</sup>

formatReadOnly(message: [NdefMessage](#ndefmessage9)): Promise\<number>

将标签格式化为NDEF标签，然后将NDEF消息写入NDEF标签，之后将标签设置为只读。使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | 是   | 格式化成功时要写入的Ndef消息。可以为null，为null时仅格式化标签，不写入内容。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<number> | 执行操作后返回的错误代码。如果返回0，则表示成功。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.NdefFormatableTag(taginfo).formatReadOnly(message).then(function (errcode){
    console.log(JSON.stringify(errcode))
    })
```

### NdefFormatableTag.formatReadOnly<sup>9+</sup>

formatReadOnly(message: [NdefMessage](#ndefmessage9), callback: AsyncCallback\<number>): void

将标签格式化为NDEF标签，然后将NDEF消息写入NDEF标签，之后将标签设置为只读。使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | 是   | 格式化成功时要写入的Ndef消息。可以为null，为null时仅格式化标签，不写入内容。|

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| callback: AsyncCallback\<number> | 回调函数。 |


**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
tag.NdefFormatableTag(taginfo).formatReadOnly(message, function (error, errcode) {
    console.log(JSON.stringify(error))
    console.log(JSON.stringify(errcode))
})
```
