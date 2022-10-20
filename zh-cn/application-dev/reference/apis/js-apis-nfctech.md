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
| number  | NfcA 标签的SAK值，十六进制表示，范围是0x00~0xFF。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'nfcA' correctly.

let sak = nfcA.getSak();
console.log("nfcA sak: " + sak);
```

### NfcATag.getAtqa

getAtqa(): number[]

获取NFC-A标签的Atqa值。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number[]  | NfcA 标签的Atqa值，每个number十六进制表示，范围是0x00~0xFF。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'nfcA' correctly.
let atqa = nfcA.getAtqa();
console.log("nfcA atqa: " + atqa);
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
| number[]  | NfcB 标签的应用程序数据，每个number十六进制表示，范围是0x00~0xFF。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'nfcB' correctly.
let respAppData = nfcB.getRespAppData();
console.log("nfcB respAppData: " + respAppData);
```

### NfcBTag.getRespProtocol

getRespProtocol(): number[]

获取标签的协议信息。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number[]  | NfcB 标签的协议信息，每个number十六进制表示，范围是0x00~0xFF。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'nfcB' correctly.
let respProtocol = nfcB.getRespProtocol();
console.log("nfcB respProtocol: " + respProtocol);
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
| number[]  | NfcF 标签的系统代码，每个number十六进制表示，范围是0x00~0xFF。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'nfcF' correctly.
let systemCode = nfcF.getSystemCode();
console.log("nfcF systemCode: " + systemCode);
```

### NfcFTag.getPmm

getPmm(): number[]

从标签实例获取PMm（由IC代码和制造商参数组成）。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number[]  | NfcF 标签的PMm信息，每个number十六进制表示，范围是0x00~0xFF。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'nfcF' correctly.
let pmm = nfcF.getPmm();
console.log("nfcF pmm: " + pmm);
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
| number | NfcV 标签的响应标志，十六进制表示，范围是0x00~0xFF。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'nfcV' correctly.
let responseFlags = nfcV.getResponseFlags();
console.log("nfcV responseFlags: " + responseFlags);
```

### NfcvTag.getDsfId

getDsfId(): number

从标签实例实例获取数据存储格式标识符（DSFID）。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number | NfcV 标签的数据存储格式标识符，十六进制表示，范围是0x00~0xFF。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'nfcV' correctly.
let dsfId = nfcV.getDsfId();
console.log("nfcV dsfId: " + dsfId);
```

## IsoDepTag<sup>9+</sup> 

IsoDepTag 提供对ISO-DEP(ISO 14443-4)技术的属性和I/O操作的访问，继承自TagSession。

TagSession是所有Nfc tag 技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是IsoDepTag的独有接口。

### IsoDepTag.getHistoricalBytes<sup>9+</sup>

getHistoricalBytes(): number[]

获取标签的历史字节。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number[] | IsoDepTag 标签的历史字节，每个number十六进制表示，范围是0x00~0xFF。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'isoDep' correctly.
let historicalBytes = isoDep.getHistoricalBytes();
console.log("isoDep historicalBytes: " + historicalBytes);
```

### IsoDepTag.getHiLayerResponse<sup>9+</sup>

getHiLayerResponse(): number[]

获取标签的HiLayer响应字节。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number[] | IsoDepTag 标签的HiLayer响应字节，每个number十六进制表示，范围是0x00~0xFF。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'isoDep' correctly.
let hiLayerResponse = isoDep.getHiLayerResponse();
console.log("isoDep hiLayerResponse: " + hiLayerResponse);
```

### IsoDepTag.isExtendedApduSupported<sup>9+</sup>

isExtendedApduSupported(): Promise&lt;boolean&gt;

检查是否支持扩展的APDU，使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise&lt;boolean&gt; | 检查结果，true: 支持， false: 不支持。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'isoDep' correctly.
isoDep.isExtendedApduSupported()
    .then((data) => {
        console.log("isoDep isExtendedApduSupported data: " + data);
    }).catch((err)=> {
        console.log("isoDep isExtendedApduSupported err: " + err);
    });
```

### IsoDepTag.isExtendedApduSupported<sup>9+</sup>

isExtendedApduSupported(callback: AsyncCallback\<boolean>): void

检查是否支持扩展的APDU，使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，true: 支持， false: 不支持。 |

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'isoDep' correctly.
isoDep.isExtendedApduSupported((err, data)=> {
    if (err) {
        console.log("isoDep isExtendedApduSupported err: " + err);
    } else {
        console.log("isoDep isExtendedApduSupported data: " + data);
    }
});
```

## NdefTag<sup>9+</sup>

提供对已格式化为NDEF的NFC标签的数据和操作的访问，继承自TagSession。

TagSession是所有NFC Tag技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是NdefTag的独有接口。

### NdefTag.createNdefMessage<sup>9+</sup>

createNdefMessage(data: number[]): [NdefMessage](#ndefmessage9)

使用原始字节创建ndef消息。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| data | number[] | 是 | 原始字节，每个number十六进制表示，范围是0x00~0xFF |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefMessage](#ndefmessage9) | NDEF标签的Message，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
let rawData = [0x00, 0xa4, 0x04, ......]; // change the raw data bytes tobe correct.
let ndefMessage = ndef.createNdefMessage(rawData);
console.log("ndef ndefMessage: " + ndefMessage);
```

## NdefMessage<sup>9+</sup>

### NdefMessage.getNdefRecords<sup>9+</sup>

getNdefRecords(): [NdefRecord](js-apis-nfcTag.md#ndefrecord9)[ ]

获取ndef消息的所有记录。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefRecord](js-apis-nfcTag.md#ndefrecord9)[ ] | NDEF标签的Record列表，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
let ndefRecords = ndef.getNdefRecords();
console.log("ndef ndefRecords number: " + ndefRecords.length);
```

### NdefTag.createNdefMessage<sup>9+</sup>

createNdefMessage(ndefRecords: NdefRecord[]): [NdefMessage](#ndefmessage9)

使用记录列表创建NDEF消息。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**
| **参数名** | **类型** | **必填** | **说明** |
| -------- | -------- | -------- | -------- |
| ndefRecords | [NdefRecord](js-apis-nfcTag.md#ndefrecord9)[] | 是 | NDEF标签的Record列表，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefMessage](#ndefmessage9) | NDEF标签的Message，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
let ndefRecords = [
    // record format: tnf, rtdType, id, payload
    // 1st record:
    {tnf: 0x01, rtdType: [0x54], id: [0x01, 0x02, ...], payload: [0x00, 0xa4, 0x04, ...]},

    // 2nd record:
    {tnf: 0x02, rtdType: [0x55], id: [0x03, 0x04, ...], payload: [0x00, 0xa4, 0x04, ...]},

    // other record if has one ...
];
let ndefMessage = ndef.createNdefMessage(ndefRecords);
console.log("ndef ndefMessage: " + ndefMessage);
```

### NdefTag.getNdefTagType<sup>9+</sup>

getNdefTagType(): NfcForumType

获取Ndef标签的类型。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NfcForumType](js-apis-nfcTag.md#nfcforumtype9) | NDEF标签类型，包括NFC FORUM TYPE 1/2/3/4等。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
let ndefTagType = ndef.getNdefTagType();
console.log("ndef ndefTagType: " + ndefTagType);
```

### NdefTag.getNdefMessage<sup>9+</sup>

getNdefMessage(): NdefMessage

获取发现NDEF标签时，从标签读取的Message。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefMessage](#ndefmessage9)  | NDEF标签的Message，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
let ndefMessage = ndef.getNdefMessage();
console.log("ndef ndefMessage: " + ndefMessage);
```

### NdefTag.isNdefWritable<sup>9+</sup>

isNdefWritable(): Promise&lt;boolean&gt;

检查NDEF标签是否可写，使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise&lt;boolean&gt; | 检查结果，true: 可写， false: 不可写。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
ndef.isNdefWritable()
    .then((data) => {
        console.log("ndef isNdefWritable data: " + data);
    }).catch((err)=> {
        console.log("ndef isNdefWritable err: " + err);
    });
```

### NdefTag.isNdefWritable<sup>9+</sup>

isNdefWritable(callback: AsyncCallback&lt;boolean&gt;): void;

检查ndef标签是否可写，使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，NDEF标签可写，返回true。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
ndef.isNdefWritable((err, data)=> {
    if (err) {
        console.log("ndef isNdefWritable err: " + err);
    } else {
        console.log("ndef isNdefWritable data: " + data);
    }
});
```

### NdefTag.readNdef<sup>9+</sup>

readNdef(): Promise\<NdefMessage>

读取标签上的ndef消息，使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<[NdefMessage](#ndefmessage9)> | 以Promise形式返回从NDEF标签中读取到的Message信息。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
ndef.readNdef()
    .then((data) => {
        console.log("ndef readNdef data: " + data);
    }).catch((err)=> {
        console.log("ndef readNdef err: " + err);
    });
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
ndef.readNdef((err, data)=> {
    if (err) {
        console.log("ndef readNdef err: " + err);
    } else {
        console.log("ndef readNdef data: " + data);
    }
});
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
let ndefMessage = ndef.createNdefMessage([0x01, 0x02, ...]); // change the raw data to be correct.

ndef.writeNdef(ndefMessage)
    .then((data) => {
        console.log("ndef writeNdef data: " + data);
    }).catch((err)=> {
        console.log("ndef writeNdef err: " + err);
    });
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
let ndefMessage = ndef.createNdefMessage([0x01, 0x02, ...]); // change the raw data to be correct.
ndef.writeNdef(ndefMessage, (err, data)=> {
    if (err) {
        console.log("ndef writeNdef err: " + err);
    } else {
        console.log("ndef writeNdef data: " + data);
    }
});
```

### NdefTag.canSetReadOnly<sup>9+</sup>

canSetReadOnly(): boolean

检查NDEF标签是否可以设置为只读。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| boolean| true: NDEF标签可设置为只读， false: NDEF标签不可设置为只读。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
var canSetReadOnly = ndef.canSetReadOnly();
console.log("ndef canSetReadOnly: " + canSetReadOnly);
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
ndef.setReadOnly()
    .then((data) => {
        console.log("ndef setReadOnly data: " + data);
    }).catch((err)=> {
        console.log("ndef setReadOnly err: " + err);
    });
```

### NdefTag.setReadOnly<sup>9+</sup>

setReadOnly(callback: AsyncCallback\<number>): void

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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
ndef.setReadOnly((err, data)=> {
    if (err) {
        console.log("ndef setReadOnly err: " + err);
    } else {
        console.log("ndef setReadOnly data: " + data);
    }
});
```

### NdefTag.getNdefTagTypeString<sup>9+</sup>

getNdefTagTypeString(type: [NfcForumType](js-apis-nfcTag.md#nfcforumtype9)): string

将Nfc论坛类型转换为Nfc论坛中定义的字节数组。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| type | [NfcForumType](js-apis-nfcTag.md#nfcforumtype9) | 是   | NDEF标签类型，包括NFC FORUM TYPE 1/2/3/4等。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| string | NFC论坛类型的字符串描述。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
let ndefTypeString = ndef.getNdefTagTypeString(tag.NFC_FORUM_TYPE_1);
console.log("ndef ndefTypeString: " + ndefTypeString);
```

## MifareClassicTag<sup>9+</sup>

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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let sectorIndex = 1; // change it to be correct index.
let key = [0x04, 0x05, ....];  // change it to be correct key.
mifareClassic.authenticateSector(sectorIndex, key, true);
    .then((data) => {
        console.log("mifareClassic authenticateSector data: " + data);
    }).catch((err)=> {
        console.log("mifareClassic authenticateSector err: " + err);
    });
```

### MifareClassicTag.authenticateSector<sup>9+</sup>

authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback\<boolean>): void

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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let sectorIndex = 1; // change it to be correct index.
let key = [0x04, 0x05, ....];  // change it to be correct key.
mifareClassic.authenticateSector(sectorIndex, key, true, (err, data)=> {
    if (err) {
        console.log("mifareClassic authenticateSector err: " + err);
    } else {
        console.log("mifareClassic authenticateSector data: " + data);
    }
});
```

### MifareClassicTag.readSingleBlock<sup>9+</sup>

readSingleBlock(blockIndex: number): Promise\<number[]>

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
| Promise\<number[]> | 读取的块数据。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
mifareClassic.readSingleBlock(blockIndex, (err, data)=> {
    if (err) {
        console.log("mifareClassic readSingleBlock err: " + err);
    } else {
        console.log("mifareClassic readSingleBlock data: " + data);
    }
});
```

### MifareClassicTag.readSingleBlock<sup>9+</sup>

readSingleBlock(blockIndex: number, callback: AsyncCallback\<number[]>): void

读取标签中一个块存储的内容，一个块大小为16字节。使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要读取的块索引 |
| callback | AsyncCallback\<number[]> | 是   | 回调函数。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
mifareClassic.readSingleBlock(blockIndex, (err, data)=> {
    if (err) {
        console.log("mifareClassic readSingleBlock err: " + err);
    } else {
        console.log("mifareClassic readSingleBlock data: " + data);
    }
});
```

### MifareClassicTag.writeSingleBlock<sup>9+</sup>

writeSingleBlock(blockIndex: number, data: number[]): Promise\<number>

向标签中一个块存储写入内容，一个块大小为16字节。使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要写入的块索引。 |
| data | number[] | 是   | 要写入的数据。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<number> | 执行写入操作返回的错误代码。如果返回0，则表示成功。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
let rawData = [0x0a, 0x14, ...]; // change it to be correct data.
mifareClassic.writeSingleBlock(blockIndex, rawData, (err, data)=> {
    if (err) {
        console.log("mifareClassic writeSingleBlock err: " + err);
    } else {
        console.log("mifareClassic writeSingleBlock data: " + data);
    }
});
```

### MifareClassicTag.writeSingleBlock<sup>9+</sup>

writeSingleBlock(blockIndex: number, data: number[], callback: AsyncCallback\<number>): void

向标签中一个块存储写入内容，一个块大小为16字节。使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要写入的块索引 |
| data | number[] | 是   | 要写入的数据 |
| callback | AsyncCallback\<number> | 是   | 回调函数。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
let rawData = [0x0a, 0x14, ...]; // change it to be correct data.
mifareClassic.writeSingleBlock(blockIndex, rawData, (err, data)=> {
    if (err) {
        console.log("mifareClassic writeSingleBlock err: " + err);
    } else {
        console.log("mifareClassic writeSingleBlock data: " + data);
    }
});
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
let value = 0x20; // change it to be correct data.
mifareClassic.incrementBlock(blockIndex, value, (err, data)=> {
    if (err) {
        console.log("mifareClassic incrementBlock err: " + err);
    } else {
        console.log("mifareClassic incrementBlock data: " + data);
    }
});
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
let value = 0x20; // change it to be correct data.
mifareClassic.incrementBlock(blockIndex, value, (err, data)=> {
    if (err) {
        console.log("mifareClassic incrementBlock err: " + err);
    } else {
        console.log("mifareClassic incrementBlock data: " + data);
    }
});
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
let value = 0x20; // change it to be correct data.
mifareClassic.decrementBlock(blockIndex, value, (err, data)=> {
    if (err) {
        console.log("mifareClassic decrementBlock err: " + err);
    } else {
        console.log("mifareClassic decrementBlock data: " + data);
    }
});
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
let value = 0x20; // change it to be correct data.
mifareClassic.decrementBlock(blockIndex, value, (err, data)=> {
    if (err) {
        console.log("mifareClassic decrementBlock err: " + err);
    } else {
        console.log("mifareClassic decrementBlock data: " + data);
    }
});
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
mifareClassic.transferToBlock(blockIndex, (err, data)=> {
    if (err) {
        console.log("mifareClassic transferToBlock err: " + err);
    } else {
        console.log("mifareClassic transferToBlock data: " + data);
    }
});
```

### MifareClassicTag.transferToBlock<sup>9+</sup>

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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
mifareClassic.transferToBlock(blockIndex, (err, data)=> {
    if (err) {
        console.log("mifareClassic transferToBlock err: " + err);
    } else {
        console.log("mifareClassic transferToBlock data: " + data);
    }
});
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
mifareClassic.restoreFromBlock(blockIndex)
    .then((data) => {
        console.log("mifareClassic restoreFromBlock data: " + data);
    }).catch((err)=> {
        console.log("mifareClassic isExtendrestoreFromBlockedApduSupported err: " + err);
    });
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
mifareClassic.restoreFromBlock(blockIndex, (err, data)=> {
    if (err) {
        console.log("mifareClassic restoreFromBlock err: " + err);
    } else {
        console.log("mifareClassic restoreFromBlock data: " + data);
    }
});
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let sectorCount = mifareClassic.getSectorCount();
console.log("mifareClassic sectorCount: " + sectorCount);
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let blockCountInSector = mifareClassic.getBlockCountInSector();
console.log("mifareClassic blockCountInSector: " + blockCountInSector);
```

### MifareClassicTag.getType<sup>9+</sup>

getType(): [MifareClassicType](js-apis-nfcTag.md#mifareclassictype9)

获取MifareClassic标签的类型。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [MifareClassicType](js-apis-nfcTag.md#mifareclassictype9) | MifareClassic标签的类型。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let getType = mifareClassic.getType();
console.log("mifareClassic getType: " + getType);
```

### MifareClassicTag.getTagSize<sup>9+</sup>

getTagSize(): number

获取标签的大小（字节），具体请参见[MifareClassicSize](js-apis-nfcTag.md#mifareclassicsize9)。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number | 标签的大小，单位为字节，请参见[MifareClassicSize](js-apis-nfcTag.md#mifareclassicsize9)。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let tagSize = mifareClassic.getTagSize();
console.log("mifareClassic tagSize: " + tagSize);
```

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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let isEmulatedTag = mifareClassic.isEmulatedTag();
console.log("mifareClassic isEmulatedTag: " + isEmulatedTag);
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let sectorIndex = 1; // change it to be correct index.
let blockIndex = mifareClassic.getBlockIndex(sectorIndex);
console.log("mifareClassic blockIndex: " + blockIndex);
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareClassic' correctly.
let blockIndex = 1; // change it to be correct index.
let sectorIndex = mifareClassic.getSectorIndex(blockIndex);
console.log("mifareClassic sectorIndex: " + sectorIndex);
```

## MifareUltralightTag<sup>9+</sup>

MifareUltralightTag 提供对MIFARE超轻属性和I/O操作的访问，继承自TagSession。

TagSession是所有Nfc tag 技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是MifareUltralightTag的独有接口。

### MifareUltralightTag.readMultiplePages<sup>9+</sup>

readMultiplePages(pageIndex: number): Promise\<number[]>

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
| Promise\<number[]> | 读取的4页的数据。 |

**示例：**

```js

import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareUltralight' correctly.
let pageIndex = 1; // change it to be correct index.
mifareUltralight.readMultiplePages(pageIndex)
    .then((data) => {
        console.log("mifareUltralight readMultiplePages data: " + data);
    }).catch((err)=> {
        console.log("mifareUltralight readMultiplePages err: " + err);
    });
```

### MifareUltralightTag.readMultiplePages<sup>9+</sup>

readMultiplePages(pageIndex: number, callback: AsyncCallback\<number[]>): void

阅读4页，共16字节。页面大小为4字节。使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| pageIndex | number | 是   | 要读取页面的索引 |
| callback | AsyncCallback\<number[]> | 是   | 回调函数。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareUltralight' correctly.
let pageIndex = 1; // change it to be correct index.
mifareUltralight.readMultiplePages(pageIndex, (err, data)=> {
    if (err) {
        console.log("mifareUltralight readMultiplePages err: " + err);
    } else {
        console.log("mifareUltralight readMultiplePages data: " + data);
    }
});
```

### MifareUltralightTag.writeSinglePages<sup>9+</sup>

writeSinglePages(pageIndex: number, data: number[]): Promise\<number>

写入一页数据，页面大小为4字节。使用promise方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| pageIndex | number | 是   | 要写入页面的索引。 |
| data | number[] | 是   | 要写入页面的数据内容。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<number> | 执行写入操作返回的错误代码。如果返回0，则表示成功。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareUltralight' correctly.
let pageIndex = 1; // change it to be correct index.
let data = [0x01, 0x02, ...]; // change it to be correct raw data.
mifareUltralight.writeSinglePages(pageIndex, data)
    .then((data) => {
        console.log("mifareUltralight writeSinglePages data: " + data);
    }).catch((err)=> {
        console.log("mifareUltralight writeSinglePages err: " + err);
    });
```

### MifareUltralightTag.writeSinglePages<sup>9+</sup>

writeSinglePages(pageIndex: number, data: number[], callback: AsyncCallback\<number>): void

写入一页数据，页面大小为4字节。使用callback方式作为异步方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**参数：**

| 参数名   | 类型                    | 必填 | 说明                     |
| -------- | ----------------------- | ---- | ------------------------ |
| pageIndex | number | 是   | 要写入页面的索引。 |
| data | number[] | 是   | 要写入页面的数据内容。 |
| callback|AsyncCallback\<number> |是| 回调函数。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareUltralight' correctly.
let pageIndex = 1; // change it to be correct index.
let data = [0x01, 0x02, ...]; // change it to be correct raw data.
mifareUltralight.writeSinglePages(pageIndex, data, (err, data)=> {
    if (err) {
        console.log("mifareUltralight writeSinglePages err: " + err);
    } else {
        console.log("mifareUltralight writeSinglePages data: " + data);
    }
});
```

### MifareUltralightTag.getType<sup>9+</sup>

getType(): MifareUltralightType

获取MifareUltralight标签的类型，以字节形式返回，具体请参见 [MifareUltralightType](js-apis-nfcTag.md#mifareultralighttype9)。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| MifareUltralightType | MifareUltralight标签的类型, 具体请参见 [MifareUltralightType](js-apis-nfcTag.md#mifareultralighttype9)。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'mifareUltralight' correctly.
let getType = mifareClassic.getType();
console.log("mifareUltralight getType: " + getType);
```

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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
let data = [0x01, 0x02, ...]; // change it to be correct raw data.
let ndefmessage = ndef.createNdefMessage(data);

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndefFormatable' correctly.
ndefFormatable.format(ndefmessage, (err, data)=> {
    if (err) {
        console.log("ndefFormatable format err: " + err);
    } else {
        console.log("ndefFormatable format data: " + data);
    }
});
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
let data = [0x01, 0x02, ...]; // change it to be correct raw data.
let ndefmessage = ndef.createNdefMessage(data);

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndefFormatable' correctly.
ndefFormatable.format(ndefmessage, (err, data)=> {
    if (err) {
        console.log("ndefFormatable format err: " + err);
    } else {
        console.log("ndefFormatable format data: " + data);
    }
});
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
let data = [0x01, 0x02, ...]; // change it to be correct raw data.
let ndefmessage = ndef.createNdefMessage(data);

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndefFormatable' correctly.
ndefFormatable.formatReadOnly(ndefmessage, (err, data)=> {
    if (err) {
        console.log("ndefFormatable formatReadOnly err: " + err);
    } else {
        console.log("ndefFormatable formatReadOnly data: " + data);
    }
});
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

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndef' correctly.
let data = [0x01, 0x02, ...]; // change it to be correct raw data.
let ndefmessage = ndef.createNdefMessage(data);

// see 'tag.TagInfo' at 'js-apis-nfcTag', has obtained the 'ndefFormatable' correctly.
ndefFormatable.formatReadOnly(ndefmessage, (err, data)=> {
    if (err) {
        console.log("ndefFormatable formatReadOnly err: " + err);
    } else {
        console.log("ndefFormatable formatReadOnly data: " + data);
    }
});
```
