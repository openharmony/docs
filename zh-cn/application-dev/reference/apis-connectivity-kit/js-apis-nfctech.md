# nfctech (标准NFC-Tag Nfc 技术)

本模块主要用于采用不同Nfc技术的Tag的读写操作。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import { tag } from '@kit.ConnectivityKit';
```

## NfcATag

NfcATag 提供 NFC-A(ISO 14443-3A)技术的属性和I/O操作的访问，继承自[TagSession](js-apis-tagSession.md)。

TagSession是所有NFC Tag技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是NfcATag的独有接口。

### NfcATag.getSak

getSak(): number

获取NFC-A标签的SAK值。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number  | NfcA 标签的SAK值，十六进制表示，范围是0x00~0xFF。 |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'nfcA' correctly.
let sak : number = nfcA.getSak();
console.info("nfcA sak: " + sak);
```

### NfcATag.getAtqa

getAtqa(): number[]

获取NFC-A标签的Atqa值。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number[]  | NfcA 标签的Atqa值，每个number十六进制表示，范围是0x00~0xFF。 |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'nfcA' correctly.
let atqa : number[] = nfcA.getAtqa();
console.info("nfcA atqa: " + atqa);
```

## NfcBTag

NfcBTag 提供对NFC-B(ISO 14443-3B)技术的属性和I/O操作的访问，继承自TagSession。

TagSession是所有NFC Tag技术类型的基类，提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是NfcBTag的独有接口。

### NfcBTag.getRespAppData

getRespAppData(): number[]

获取标签的应用程序数据。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number[]  | NfcB 标签的应用程序数据，每个number十六进制表示，范围是0x00~0xFF。 |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'nfcB' correctly.
let respAppData : number[] = nfcB.getRespAppData();
console.info("nfcB respAppData: " + respAppData);
```

### NfcBTag.getRespProtocol

getRespProtocol(): number[]

获取标签的协议信息。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number[]  | NfcB 标签的协议信息，每个number十六进制表示，范围是0x00~0xFF。|

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'nfcB' correctly.
let respProtocol : number[] = nfcB.getRespProtocol();
console.info("nfcB respProtocol: " + respProtocol);
```

## NfcFTag

NfcFTag 提供对NFC-F(JIS 6319-4)技术的属性和I/O操作的访问，继承自TagSession。

TagSession是所有NFC Tag技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是NfcFTag的独有接口。

### NfcFTag.getSystemCode

getSystemCode(): number[]

从标签实例获取系统代码。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                            |
| ------------------ | --------------------------|
| number[]  | NfcF 标签的系统代码，每个number十六进制表示，范围是0x00~0xFF。|

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'nfcF' correctly.
let systemCode : number[] = nfcF.getSystemCode();
console.info("nfcF systemCode: " + systemCode);
```

### NfcFTag.getPmm

getPmm(): number[]

从标签实例获取PMm（由IC代码和制造商参数组成）。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number[]  | NfcF 标签的PMm信息，每个number十六进制表示，范围是0x00~0xFF。|

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'nfcF' correctly.
let pmm : number[] = nfcF.getPmm();
console.info("nfcF pmm: " + pmm);
```

## NfcVTag

NfcVTag 提供对NFC-V(ISO 15693)技术的属性和I/O操作的访问，继承自TagSession。

TagSession是所有NFC Tag技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是NfcVTag的独有接口。

### NfcvTag.getResponseFlags

getResponseFlags(): number

从标签实例实例获取响应标志。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number | NfcV 标签的响应标志，十六进制表示，范围是0x00~0xFF。|

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'nfcV' correctly.
let responseFlags : number = nfcV.getResponseFlags();
console.info("nfcV responseFlags: " + responseFlags);
```

### NfcvTag.getDsfId

getDsfId(): number

从标签实例实例获取数据存储格式标识符（DSFID）。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number | NfcV 标签的数据存储格式标识符，十六进制表示，范围是0x00~0xFF。|

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'nfcV' correctly.
let dsfId : number = nfcV.getDsfId();
console.info("nfcV dsfId: " + dsfId);
```

## IsoDepTag<sup>9+</sup> 

IsoDepTag 提供对ISO-DEP(ISO 14443-4)技术的属性和I/O操作的访问，继承自TagSession。

TagSession是所有NFC Tag技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是IsoDepTag的独有接口。

### IsoDepTag.getHistoricalBytes<sup>9+</sup>

getHistoricalBytes(): number[]

获取标签的历史字节，针对基于NfcA通信技术的IsoDep卡片。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number[] | IsoDepTag 标签的历史字节，每个number十六进制表示，范围是0x00~0xFF。如果该IsoDep类型Tag是基于NfcB技术的，则该返回值为空。|

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'isoDep' correctly.
let historicalBytes : number[] = isoDep.getHistoricalBytes();
console.info("isoDep historicalBytes: " + historicalBytes);
```

### IsoDepTag.getHiLayerResponse<sup>9+</sup>

getHiLayerResponse(): number[]

获取标签的更高层响应字节，针对基于NfcB通信技术的IsoDep卡片。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number[] | IsoDepTag 标签的更高层响应字节，每个number十六进制表示，范围是0x00~0xFF。如果该IsoDep类型Tag是基于NfcA技术的，则该返回值为空。|

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'isoDep' correctly.
let hiLayerResponse : number[] = isoDep.getHiLayerResponse();
console.info("isoDep hiLayerResponse: " + hiLayerResponse);
```

### IsoDepTag.isExtendedApduSupported<sup>9+</sup>

isExtendedApduSupported(): Promise&lt;boolean&gt;

检查是否支持扩展的APDU，使用Promise方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise&lt;boolean&gt; | 以Promise形式返回检查结果，true: 支持， false: 不支持。|

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'isoDep' correctly.
function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!isoDep.isTagConnected()) {
        if (!isoDep.connectTag()) {
            console.error("isoDep connectTag failed.");
            return;
        }
    }

    try {
        isoDep.isExtendedApduSupported().then((response: boolean) => {
            console.info("isoDep isExtendedApduSupported Promise response: " + response);
        }).catch((err: BusinessError) => {
            console.error("isoDep isExtendedApduSupported Promise Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("isoDep isExtendedApduSupported Promise Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}

```

### IsoDepTag.isExtendedApduSupported<sup>9+</sup>

isExtendedApduSupported(callback: AsyncCallback\<boolean>): void

检查是否支持扩展的APDU，使用AsyncCallback方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<boolean> | 是   | 回调函数，true: 支持， false: 不支持。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'isoDep' correctly.
function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!isoDep.isTagConnected()) {
        if (!isoDep.connectTag()) {
            console.error("isoDep connectTag failed.");
            return;
        }
    }

    try {
        isoDep.isExtendedApduSupported((err: BusinessError, response: boolean) => {
            if (err) {
                console.error("isoDep isExtendedApduSupported AsyncCallback Code: ${err.code}, message: ${err. message}");
            } else {
                console.info("isoDep isExtendedApduSupported AsyncCallback response: " + response);
            }
        });
    } catch (busiErr) {
        console.error("isoDep isExtendedApduSupported AsyncCallback Code: ${(businessError as Business).code}, " + "message: ${(businessError as Business).message}");
    }
}

```

## NdefMessage<sup>9+</sup>

### NdefMessage.getNdefRecords<sup>9+</sup>

getNdefRecords(): [tag.NdefRecord](js-apis-nfcTag.md#ndefrecord9)[]

获取NDEF消息中的所有记录。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [tag.NdefRecord](js-apis-nfcTag.md#ndefrecord9)[] | NDEF标签的Record列表，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。 |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

// Obtains ndefMessage from tag.ndef.createNdefMessage or ndefTag.getNdefMessage.
// let ndefMessage : tag.NdefMessage = tag.ndef.createNdefMessage(...);
// let ndefMessage : tag.NdefMessage = ndefTag.getNdefMessage();

let ndefRecords : tag.NdefRecord[] = ndefMessage.getNdefRecords();
console.info("ndef ndefRecords number: " + ndefRecords.length);
```

## NdefTag<sup>9+</sup>

提供对已格式化为NDEF的NFC标签的数据和操作的访问，继承自TagSession。

TagSession是所有NFC Tag技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是NdefTag的独有接口。

### NdefTag.getNdefTagType<sup>9+</sup>

getNdefTagType(): [tag.NfcForumType](js-apis-nfcTag.md#nfcforumtype9)

获取NDEF标签的类型。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [tag.NfcForumType](js-apis-nfcTag.md#nfcforumtype9) | NDEF标签类型，包括NFC FORUM TYPE 1/2/3/4等。|

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'ndefTag' correctly.
let ndefTagType : tag.NfcForumType = ndefTag.getNdefTagType();
console.info("ndef ndefTagType: " + ndefTagType);
```

### NdefTag.getNdefMessage<sup>9+</sup>

getNdefMessage(): [NdefMessage](#ndefmessage9)

获取发现NDEF标签时，从标签读取的Message。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [NdefMessage](#ndefmessage9)  | NDEF标签的Message，详见NDEF技术规范《NFCForum-TS-NDEF_1.0》。|

**示例：**
```js
import { tag } from '@kit.ConnectivityKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'ndefTag' correctly.
let ndefMessage : tag.NdefMessage = ndefTag.getNdefMessage();
console.info("ndef ndefMessage: " + ndefMessage);
```

### NdefTag.isNdefWritable<sup>9+</sup>

isNdefWritable(): boolean

检查NDEF标签是否可写。在调用写数据接口前，需要先判断是否支持写操作。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| boolean | 检查结果，true: 可写， false: 不可写。|

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'ndefTag' correctly.
let isWritable : boolean = ndefTag.isNdefWritable();
console.info("ndef isNdefWritable: " + isWritable);
```

### NdefTag.readNdef<sup>9+</sup>

readNdef(): Promise\<[NdefMessage](#ndefmessage9)>

读取标签上的NDEF消息，使用Promise方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<[NdefMessage](#ndefmessage9)> | 以Promise形式返回从NDEF标签中读取到的Message数据对象。|

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'ndefTag' correctly.
function nfcTechDemo(){
    // connect the tag at first if not connected.
    if (!ndefTag.isTagConnected()) {
        if (!ndefTag.connectTag()) {
            console.error("ndefTag connectTag failed.");
            return;
        }
    }

    try {
        ndefTag.readNdef().then((ndefmessage : tag.NdefMessage) => {
            console.info("ndef readNdef Promise ndefmessage: " + ndefmessage);
        }).catch((err : BusinessError)=> {
            console.error("ndef readNdef Promise err Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("ndef readNdef Promise catch businessError Code: ${(businessError as BusinessError).code}, " +
        "message: ${(businessError as BusinessError).message}");
    }
}

```

### NdefTag.readNdef<sup>9+</sup>

readNdef(callback: AsyncCallback\<[NdefMessage](#ndefmessage9)>): void

读取标签上的NDEF消息，使用AsyncCallback方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<[NdefMessage](#ndefmessage9)> | 是   | 回调函数，返回从NDEF标签中读取到的Message信息。|

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'ndefTag' correctly.
function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!ndefTag.isTagConnected()) {
        if (!ndefTag.connectTag()) {
            console.error("ndefTag connectTag failed.");
            return;
        }
    }

    try {
        ndefTag.readNdef((err : BusinessError, ndefmessage : tag.NdefMessage)=> {
            if (err) {
                console.error("ndef readNdef AsyncCallback err Code: ${err.code}, message: ${err.message}");
            } else {
                console.info("ndef readNdef AsyncCallback ndefmessage: " + ndefmessage);
            }
        });
    } catch (businessError) {
        console.error("ndef readNdef AsyncCallback catch Code: ${(businessError : BusinessError).code}," +
        " message: ${(businessError : BusinessError).message}");
    }
}

```

### NdefTag.writeNdef<sup>9+</sup>

writeNdef(msg: [NdefMessage](#ndefmessage9)): Promise\<void>

将NDEF Message数据对象写入标签，使用Promise方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| msg | [NdefMessage](#ndefmessage9) | 是   | NDEF Message数据对象。|

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'ndefTag' correctly.
// ndefMessage created from raw data, such as:
let ndefMessage : tag.NdefMessage =
    tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]);  // MUST can be parsed as NDEF Record.
// or ndefMessage created from tag.ndef.createNdefMessage(ndefRecords: NdefRecord[])

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!ndefTag.isTagConnected()) {
        if (!ndefTag.connectTag()) {
            console.error("ndefTag connectTag failed.");
            return;
        }
    }

    try {
        ndefTag.writeNdef(ndefMessage).then(() => {
            console.info("ndef writeNdef Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("ndef writeNdef err Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("ndef writeNdef Promise catch businessError Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### NdefTag.writeNdef<sup>9+</sup>

writeNdef(msg: [NdefMessage](#ndefmessage9), callback: AsyncCallback\<void>): void

将NDEF Message数据对象写入此标签，使用AsyncCallback方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| msg | [NdefMessage](#ndefmessage9) | 是   | NDEF Message数据对象。 |
| callback | AsyncCallback\<void> | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'ndefTag' correctly.
// ndefMessage created from raw data, such as:
let ndefMessage : tag.NdefMessage = 
    tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]);  // MUST can be parsed as NDEF Record.
// or ndefMessage created from tag.ndef.createNdefMessage(ndefRecords: NdefRecord[])

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!ndefTag.isTagConnected()) {
        if (!ndefTag.connectTag()) {
            console.error("ndefTag connectTag failed.");
            return;
        }
    }

    try {
        ndefTag.writeNdef(ndefMessage, (err : BusinessError)=> {
            if (err) {
                console.error("ndef writeNdef AsyncCallback Code: ${err.code}, message: ${err.message}");
            } else {
                console.info("ndef writeNdef AsyncCallback success.");
            }
        }); 
    } catch (businessError) {
        console.error("ndef writeNdef AsyncCallback catch businessError Code: ${(businessError as Businsess).code}," +
            " message: ${(businessError as Businsess).message}");
    }
}
```

### NdefTag.canSetReadOnly<sup>9+</sup>

canSetReadOnly(): boolean

检查NDEF标签是否可以设置为只读。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| boolean| true: NDEF标签可设置为只读， false: NDEF标签不可设置为只读。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 3100201 | Tag running state is abnormal in service. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'ndefTag' correctly.
let canSetReadOnly : boolean = ndefTag.canSetReadOnly();
console.info("ndef canSetReadOnly: " + canSetReadOnly);
```

### NdefTag.setReadOnly<sup>9+</sup>

setReadOnly(): Promise\<void>

将NDEF标签设置为只读，使用Promise方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'ndefTag' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!ndefTag.isTagConnected()) {
        if (!ndefTag.connectTag()) {
            console.error("ndefTag connectTag failed.");
            return;
        }
    }

    try {
        ndefTag.setReadOnly().then(() => {
            console.info("ndef setReadOnly Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("ndef setReadOnly Promise err Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("ndef setReadOnly Promise catch businessError Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### NdefTag.setReadOnly<sup>9+</sup>

setReadOnly(callback: AsyncCallback\<void>): void

将NDEF标签设置为只读，使用AsyncCallback方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| callback | AsyncCallback\<void> | 是   | 回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'ndefTag' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!ndefTag.isTagConnected()) {
        if (!ndefTag.connectTag()) {
            console.error("ndefTag connectTag failed.");
            return;
        }
    }

    try {
        ndefTag.setReadOnly((err : BusinessError)=> {
            if (err) {
                console.error("ndef setReadOnly AsyncCallback err Code: ${err.code}, message: ${err.message}");
            } else {
                console.info("ndef setReadOnly AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("ndef setReadOnly AsyncCallback catch businessError Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### NdefTag.getNdefTagTypeString<sup>9+</sup>

getNdefTagTypeString(type: [tag.NfcForumType](js-apis-nfcTag.md#nfcforumtype9)): string

将NFC论坛类型，转换为NFC论坛中定义的字符串描述。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| type | [tag.NfcForumType](js-apis-nfcTag.md#nfcforumtype9) | 是   | NDEF标签类型，包括NFC FORUM TYPE 1/2/3/4等。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| string | NFC论坛类型的字符串描述。|

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'ndefTag' correctly.

try {
    let ndefTypeString : string = ndefTag.getNdefTagTypeString(tag.NfcForumType.NFC_FORUM_TYPE_1);
    console.info("ndef ndefTypeString: " + ndefTypeString);
} catch (businessError) {
    console.error("ndef getNdefTagTypeString catch businessError Code: ${(businessError as Businsess).code}, " +
        "message: ${(businessError as Businsess).message}");
}
```

## MifareClassicTag<sup>9+</sup>

MifareClassicTag提供对MIFARE Classic属性和I/O操作的访问，继承自[TagSession](js-apis-tagSession.md)。

TagSession是所有NFC Tag技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是MifareClassicTag的独有接口。

### MifareClassicTag.authenticateSector<sup>9+</sup>

authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean): Promise\<void>

使用密钥对扇区进行身份验证，只有身份验证成功的扇区可以进行操作。使用Promise方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | 是   | 待验证的扇区索引，从0开始。 |
| key | number[]| 是   | 用于扇区验证的密钥（6字节）。 |
| isKeyA | boolean | 是   | isKeyA标志。true 表示KeyA，false 表示KeyB。|

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let sectorIndex = 1; // change it to be correct index.
        let key = [0x01, 0x02, 0x03, 0x04, 0x05, 0x06]  // MUST be 6 bytes, change it to be correct key.
        mifareClassic.authenticateSector(sectorIndex, key, true).then(() => {
            console.info("mifareClassic authenticateSector Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("mifareClassic authenticateSector Promise errCode: ${err.code}, " + "message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareClassic authenticateSector Promise catch businessError Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.authenticateSector<sup>9+</sup>

authenticateSector(sectorIndex: number, key: number[], isKeyA: boolean, callback: AsyncCallback\<void>): void

使用密钥对扇区进行身份验证，只有身份验证成功的扇区可以进行操作。使用AsyncCallback方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | 是   | 待验证的扇区索引，从0开始。 |
| key | number[]| 是   | 用于扇区验证的密钥（6字节）。 |
| isKeyA | boolean | 是   | isKeyA标志。true 表示KeyA，false 表示KeyB。|
| callback | AsyncCallback\<void> | 是   | 以callback形式异步返回扇区验证结果。|

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**
```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let sectorIndex = 1; // change it to be correct index.
        let key = [0x01, 0x02, 0x03, 0x04, 0x05, 0x06]  // MUST be 6 bytes, change it to be correct key.
        mifareClassic.authenticateSector(sectorIndex, key, true, (err : BusinessError)=> {
            if (err) {
                console.error("mifareClassic authenticateSector AsyncCallback errCode: ${err.code}, message: ${err.message}");
            } else {
                console.info("mifareClassic authenticateSector AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("mifareClassic authenticateSector AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.readSingleBlock<sup>9+</sup>

readSingleBlock(blockIndex: number): Promise\<number[]>

读取标签中一个块存储的内容，一个块大小为16字节。使用Promise方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要读取的块索引，从0开始。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<number[]> | 以Promise形式返回读取的块数据。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // change it to be correct index.
        mifareClassic.readSingleBlock(blockIndex).then((data : number[]) => {
            console.info("mifareClassic readSingleBlock Promise data: " + data);
        }).catch((err : BusinessError)=> {
            console.error("mifareClassic readSingleBlock Promise errCode: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareClassic readSingleBlock Promise catch businessError Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.readSingleBlock<sup>9+</sup>

readSingleBlock(blockIndex: number, callback: AsyncCallback\<number[]>): void

读取标签中一个块存储的内容，一个块大小为16字节。使用AsyncCallback方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要读取的块索引，从0开始。 |
| callback | AsyncCallback\<number[]> | 是   |以callback形式异步返回读取到的块数据。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // change it to be correct index.
        mifareClassic.readSingleBlock(blockIndex, (err : BusinessError, data : number[])=> {
            if (err) {
                console.error("mifareClassic readSingleBlock AsyncCallback err: " + err);
            } else {
                console.info("mifareClassic readSingleBlock AsyncCallback data: " + data);
            }
        });
    } catch (businessError) {
        console.error("mifareClassic readSingleBlock AsyncCallback catch businessError Code: " + 
        " ${(businessError as Businsess).code}, message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.writeSingleBlock<sup>9+</sup>

writeSingleBlock(blockIndex: number, data: number[]): Promise\<void>

向标签中一个块存储写入内容，一个块大小为16字节。使用Promise方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要写入的块索引，从0开始。 |
| data | number[] | 是   | 要写入的数据，大小必须是16个字节。 |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // change it to be correct index.
        let rawData = [0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A,
            0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10]; // MUST be 16 bytes, change it to be correct data.
        mifareClassic.writeSingleBlock(blockIndex, rawData).then(() => {
            console.info("mifareClassic writeSingleBlock Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("mifareClassic writeSingleBlock Promise errCode: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareClassic writeSingleBlock Promise catch businessError Code: ${(businessError as Businsess).code}, "
        + "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.writeSingleBlock<sup>9+</sup>

writeSingleBlock(blockIndex: number, data: number[], callback: AsyncCallback\<void>): void

向标签中一个块存储写入内容，一个块大小为16字节。使用AsyncCallback方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要写入的块索引，从0开始。 |
| data | number[] | 是   | 要写入的数据，大小必须是16个字节。 |
| callback | AsyncCallback\<void> | 是   | 以callback形式异步返回块操作结果。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // change it to be correct index.
        let rawData = [0x01, 0x02, 0x03, 0x04, 0x05, 0x06, 0x07, 0x08, 0x09, 0x0A,
            0x0B, 0x0C, 0x0D, 0x0E, 0x0F, 0x10]; // MUST be 16 bytes, change it to be correct data.
        mifareClassic.writeSingleBlock(blockIndex, rawData, (err : BusinessError)=> {
            if (err) {
                console.error("mifareClassic writeSingleBlock AsyncCallback err Code:" +
                "${err.code}, message: ${err.message}");
            } else {
                console.info("mifareClassic writeSingleBlock AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("mifareClassic writeSingleBlock AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.incrementBlock<sup>9+</sup>

incrementBlock(blockIndex: number, value: number): Promise\<void>

对指定块的内容，增加指定的数值，并将结果存储在内部传输缓冲器中。使用Promise方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要指定增加的块索引，从0开始。 |
| value | number | 是   | 要指定增加的数据，非负数。 |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // change it to be correct index.
        let value = 0x20; // change it to be correct data.
        mifareClassic.incrementBlock(blockIndex, value).then(() => {
            console.info("mifareClassic incrementBlock Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("mifareClassic incrementBlock Promise err Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareClassic incrementBlock Promise catch Code: ${(businessError as Businsess).code}, " +
           "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.incrementBlock<sup>9+</sup>

incrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void

对指定块的内容，增加指定的数值，并将结果存储在内部传输缓冲器中。使用AsyncCallback方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要被运算的块索引，从0开始。 |
| value | number | 是   | 要增加的数值，非负数。 |
| callback | AsyncCallback\<void> | 是   | 以callback形式异步返回块操作结果。。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // change it to be correct index.
        let value = 0x20; // change it to be correct data.
        mifareClassic.incrementBlock(blockIndex, value, (err : BusinessError)=> {
            if (err) {
                console.error("mifareClassic incrementBlock AsyncCallback err Code: ${err.code}, message: ${err.message}");
            } else {
                console.info("mifareClassic incrementBlock AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("mifareClassic incrementBlock AsyncCallback catch businessError Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.decrementBlock<sup>9+</sup>

decrementBlock(blockIndex: number, value: number): Promise\<void>

对指定块的内容，减少指定的数值，并将结果存储在内部传输缓冲器中。使用Promise方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要被运算的块索引，从0开始。 |
| value | number | 是   | 要减少的数值，非负数。 |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // change it to be correct index.
        let value = 0x20; // change it to be correct data.
        mifareClassic.decrementBlock(blockIndex, value).then(() => {
            console.info("mifareClassic decrementBlock Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("mifareClassic decrementBlock Promise errCode: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareClassic decrementBlock Promise catch businessError: Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.decrementBlock<sup>9+</sup>

decrementBlock(blockIndex: number, value: number, callback: AsyncCallback\<void>): void

对指定块的内容，减少指定的数值。使用AsyncCallback方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 要被运算的块索引，从0开始。 |
| value | number | 是   | 要减少的数值，非负数。 |
| callback | AsyncCallback\<void> | 是   | 以callback形式异步返回块操作结果。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // change it to be correct index.
        let value = 0x20; // change it to be correct data.
        mifareClassic.decrementBlock(blockIndex, value, (err : BusinessError)=> {
            if (err) {
                console.error("mifareClassic decrementBlock AsyncCallback errCode:" + 
                  "${err.code}, message: ${err.message}");
            } else {
                console.info("mifareClassic decrementBlock AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("mifareClassic decrementBlock AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
          "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.transferToBlock<sup>9+</sup>

transferToBlock(blockIndex: number): Promise\<void>

将临时寄存器的值转移到指定的块。使用Promise方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是  | 被操作的块的索引，从0开始。 |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // change it to be correct index.
        mifareClassic.transferToBlock(blockIndex).then(() => {
            console.info("mifareClassic transferToBlock Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("mifareClassic transferToBlock Promise err Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareClassic transferToBlock Promise catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.transferToBlock<sup>9+</sup>

transferToBlock(blockIndex: number, callback: AsyncCallback\<void>): void

将临时寄存器的值转移到指定的块。使用AsyncCallback方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 被操作的块的索引，从0开始。 |
| callback | AsyncCallback\<void> | 是   | 以callback形式异步返回块操作结果。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // change it to be correct index.
        mifareClassic.transferToBlock(blockIndex, (err : BusinessError)=> {
            if (err) {
                console.error("mifareClassic transferToBlock AsyncCallback errCode: ${err.code}," +
                    "message: ${err.message}");
            } else {
                console.info("mifareClassic transferToBlock AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("mifareClassic transferToBlock AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.restoreFromBlock<sup>9+</sup>

restoreFromBlock(blockIndex: number): Promise\<void>

将指定块的值复制到临时寄存器。使用Promise方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 被操作的块的索引，从0开始。|

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }   
    }

    try {
        let blockIndex = 1; // change it to be correct index.
        mifareClassic.restoreFromBlock(blockIndex).then(() => {
            console.info("mifareClassic restoreFromBlock Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("mifareClassic restoreFromBlock Promise errCode: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareClassic restoreFromBlock Promise catch businessError Code: ${(businessError as Businsess).code}," +
            " message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.restoreFromBlock<sup>9+</sup>

restoreFromBlock(blockIndex: number, callback: AsyncCallback\<void>): void

将指定块的值复制到临时寄存器。使用AsyncCallback方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是   | 被操作的块的索引，从0开始。 |
| callback | AsyncCallback\<void> | 是   | 以callback形式异步返回块操作结果。|

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareClassic.isTagConnected()) {
        if (!mifareClassic.connectTag()) {
            console.error("mifareClassic connectTag failed.");
            return;
        }
    }

    try {
        let blockIndex = 1; // change it to be correct index.
        mifareClassic.restoreFromBlock(blockIndex, (err : BusinessError)=> {
            if (err) {
                console.error("mifareClassic restoreFromBlock AsyncCallback err Code: ${err.code}," +
                    " message: ${err.message}");
            } else {
                console.info("mifareClassic restoreFromBlock AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("mifareClassic restoreFromBlock AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareClassicTag.getSectorCount<sup>9+</sup>

getSectorCount(): number

获取MIFARE Classic标签中的扇区数。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number | 标签中的扇区数量。|

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.
let sectorCount : number = mifareClassic.getSectorCount();
console.info("mifareClassic sectorCount: " + sectorCount);
```

### MifareClassicTag.getBlockCountInSector<sup>9+</sup>

getBlockCountInSector(sectorIndex: number): number

获取指定扇区中的块数。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | 是   | 扇区序号，从0开始。|

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number | 该扇区内的块数量。|

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.

try {
    let sectorIndex = 1; // change it to be correct index.
    let blockCnt : number = mifareClassic.getBlockCountInSector(sectorIndex);
    console.info("mifareClassic blockCnt: " + blockCnt);
} catch (businessError) {
    console.error("mifareClassic getBlockCountInSector catch businessError Code: ${(businessError as Businsess).code}, " +
        "message: ${(businessError as Businsess).message}");
}
```

### MifareClassicTag.getType<sup>9+</sup>

getType(): [tag.MifareClassicType](js-apis-nfcTag.md#mifareclassictype9)

获取MIFARE Classic标签的类型。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [tag.MifareClassicType](js-apis-nfcTag.md#mifareclassictype9) | MifareClassic标签的类型。|

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.
let getType : tag.MifareClassicType = mifareClassic.getType();
console.info("mifareClassic getType: " + getType);
```

### MifareClassicTag.getTagSize<sup>9+</sup>

getTagSize(): number

获取标签的存储空间大小，具体请参见[MifareClassicSize](js-apis-nfcTag.md#mifareclassicsize9)。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number | 标签的大小，单位为字节，请参见[MifareClassicSize](js-apis-nfcTag.md#mifareclassicsize9)。|

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.
let tagSize : number = mifareClassic.getTagSize();
console.info("mifareClassic tagSize: " + tagSize);
```

### MifareClassicTag.isEmulatedTag<sup>9+</sup>

isEmulatedTag(): boolean

检查标签是不是被模拟的。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| boolean |检查结果，true: 是；false：否。 |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.
let isEmulatedTag : boolean = mifareClassic.isEmulatedTag();
console.info("mifareClassic isEmulatedTag: " + isEmulatedTag);
```

### MifareClassicTag.getBlockIndex<sup>9+</sup>

getBlockIndex(sectorIndex: number): number

获取特定扇区的第一个块的序号。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| sectorIndex | number | 是   | 扇区序号，从0开始。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number | 该扇区内的第一个块的序号，从0开始。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.

try {
    let sectorIndex = 1; // change it to be correct index.
    let blockIndex : number = mifareClassic.getBlockIndex(sectorIndex);
    console.info("mifareClassic blockIndex: " + blockIndex);
} catch (businessError) {
    console.error("mifareClassic getBlockIndex catch businessError Code: ${(businessError as Businsess).code}, " +
        "message: ${(businessError as Businsess).message}");
}
```

### MifareClassicTag.getSectorIndex<sup>9+</sup>

getSectorIndex(blockIndex: number): number

获取包含指定块号的扇区序号。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| blockIndex | number | 是 | 块序号，从0开始。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number | 扇区序号，从0开始。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareClassic' correctly.

try {
    let blockIndex = 1; // change it to be correct index.
    let sectorIndex : number = mifareClassic.getSectorIndex(blockIndex);
    console.info("mifareClassic sectorIndex: " + sectorIndex);
} catch (businessError) {
    console.error("mifareClassic getSectorIndex catch businessError Code: ${(businessError as Businsess).code}, " +
       "message: ${(businessError as Businsess).message}");
}
```

## MifareUltralightTag<sup>9+</sup>

MifareUltralightTag 提供对MIFARE Ultralight属性和I/O操作的访问，继承自TagSession。

TagSession是所有NFC Tag技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是MifareUltralightTag的独有接口。

### MifareUltralightTag.readMultiplePages<sup>9+</sup>

readMultiplePages(pageIndex: number): Promise\<number[]>

读取标签的4页数据，共16字节的数据。每个页面数据大小为4字节。使用Promise方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | ------------------------------ |
| pageIndex | number | 是   | 要读取页面的索引，从0开始。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise\<number[]> | 以Promise形式返回读取的4页的数据，共16字节。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js

import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareUltralight' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareUltralight.isTagConnected()) {
        if (!mifareUltralight.connectTag()) {
            console.error("mifareUltralight connectTag failed.");
            return;
        }
    }

    try {
        let pageIndex = 1; // change it to be correct index.
        mifareUltralight.readMultiplePages(pageIndex).then((data : number[]) => {
            console.info("mifareUltralight readMultiplePages Promise data = " + data);
        }).catch((err : BusinessError)=> {
            console.error("mifareUltralight readMultiplePages Promise Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareUltralight readMultiplePages Promise catch businessError" +
            " Code: ${(businessError as Businsess).code}, message: ${(businessError as Businsess).message}");
    }
}
```

### MifareUltralightTag.readMultiplePages<sup>9+</sup>

readMultiplePages(pageIndex: number, callback: AsyncCallback\<number[]>): void

读取标签的4页数据，共16字节的数据。每个页面数据大小为4字节。使用AsyncCallback方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| pageIndex | number | 是   | 要读取页面的索引，从0开始。 |
| callback | AsyncCallback\<number[]> | 是   | 以callback形式异步返回页操作结果。返回读取到的数据，共16字节。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareUltralight' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareUltralight.isTagConnected()) {
        if (!mifareUltralight.connectTag()) {
            console.error("mifareUltralight connectTag failed.");
            return;
        }
    }

    try {
        let pageIndex = 1; // change it to be correct index.
        mifareUltralight.readMultiplePages(pageIndex, (err : BusinessError, data : number[])=> {
            if (err) {
                console.log("mifareUltralight readMultiplePages AsyncCallback Code: ${err.code}, message: ${err.message}");
            } else {
                console.info("mifareUltralight readMultiplePages AsyncCallback data: " + data);
            }
        });
    } catch (businessError) {
        console.error("mifareUltralight readMultiplePages AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareUltralightTag.writeSinglePage<sup>9+</sup>

writeSinglePage(pageIndex: number, data: number[]): Promise\<void>

写入一页数据，数据大小为4字节。使用Promise方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| pageIndex | number | 是   | 要写入页面的索引，从0开始。 |
| data | number[] | 是   | 要写入页面的数据内容，必须是4个字节大小。 |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareUltralight' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareUltralight.isTagConnected()) {
        if (!mifareUltralight.connectTag()) {
            console.error("mifareUltralight connectTag failed.");
            return;
        }
    }

    try {
        let pageIndex = 1; // change it to be correct index.
        let rawData = [0x01, 0x02, 0x03, 0x04]; // MUST be 4 bytes, change it to be correct raw data.
        mifareUltralight.writeSinglePage(pageIndex, rawData).then(() => {
            console.info("mifareUltralight writeSinglePage Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("mifareUltralight writeSinglePage Promise err Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("mifareUltralight writeSinglePage Promise catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareUltralightTag.writeSinglePage<sup>9+</sup>

writeSinglePage(pageIndex: number, data: number[], callback: AsyncCallback\<void>): void

写入一页数据，数据大小为4字节。使用AsyncCallback方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                     |
| -------- | ----------------------- | ---- | ------------------------ |
| pageIndex | number | 是   | 要写入页面的索引，从0开始。 |
| data | number[] | 是   | 要写入页面的数据内容，必须是4个字节大小。 |
| callback|AsyncCallback\<void> |是| 以callback形式异步返回页操作结果。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareUltralight' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!mifareUltralight.isTagConnected()) {
        if (!mifareUltralight.connectTag()) {
            console.error("mifareUltralight connectTag failed.");
            return;
        }
    }

    try {
        let pageIndex = 1; // change it to be correct index.
        let rawData = [0x01, 0x02, 0x03, 0x04]; // MUST be 4 bytes, change it to be correct raw data.
        mifareUltralight.writeSinglePage(pageIndex, rawData, (err : BusinessError)=> {
        if (err) {
                console.error("mifareUltralight writeSinglePage AsyncCallback Code: ${err.code}," +
                    "message: ${err.message}");
            } else {
                console.info("mifareUltralight writeSinglePage AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("mifareUltralight writeSinglePage AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### MifareUltralightTag.getType<sup>9+</sup>

getType(): [tag.MifareUltralightType](js-apis-nfcTag.md#mifareultralighttype9)

获取MIFARE Ultralight标签的类型。

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| [tag.MifareUltralightType](js-apis-nfcTag.md#mifareultralighttype9) | MIFARE Ultralight标签的类型。|

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'mifareUltralight' correctly.
let getType : tag.MifareUltralightType = mifareClassic.getType();
console.info("mifareUltralight getType: " + getType);
```

## NdefFormatableTag<sup>9+</sup>

NdefFormatableTag为NDEF Formattable的标签提供格式化操作，继承自TagSession。

TagSession是所有NFC Tag 技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是NdefFormatableTag的独有接口。

### NdefFormatableTag.format<sup>9+</sup>

format(message: [NdefMessage](#ndefmessage9)): Promise\<void>

将标签格式化为NDEF标签，将NDEF消息写入NDEF标签。使用Promise方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | 是   | 格式化成功时要写入的NDEF消息。可以为null，为null时仅格式化标签，不写入内容。 |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'ndefFormatable' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!ndefFormatable.isTagConnected()) {
        if (!ndefFormatable.connectTag()) {
            console.error("ndefFormatable connectTag failed.");
            return;
        }
    }

    try {
        // ndefMessage created from raw data, such as:
        let ndefMessage = tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]);  
        // MUST can be parsed as NDEF Record.
        // or ndefMessage created from tag.ndef.createNdefMessage(ndefRecords: NdefRecord[])

        ndefFormatable.format(ndefMessage).then(() => {
            console.info("ndefFormatable format Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("ndefFormatable format Promise err Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("ndefFormatable format Promise catch businessError Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### NdefFormatableTag.format<sup>9+</sup>

format(message: [NdefMessage](#ndefmessage9), callback: AsyncCallback\<void>): void

将标签格式化为NDEF标签，然后将NDEF消息写入NDEF标签。使用AsyncCallback方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | 是   | 格式化成功时要写入的Ndef消息。可以为null，为null时仅格式化标签，不写入内容。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| callback: AsyncCallback\<void> | 以callback形式异步返回格式化操作结果。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'ndefFormatable' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!ndefFormatable.isTagConnected()) {
        if (!ndefFormatable.connectTag()) {
            console.error("ndefFormatable connectTag failed.");
            return;
        }
    }

    try {
        // ndefMessage created from raw data, such as:
        let ndefMessage = tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]);  // MUST can be parsed as NDEF Record.
        // or ndefMessage created from tag.ndef.createNdefMessage(ndefRecords: NdefRecord[])

        ndefFormatable.format(ndefMessage, (err : BusinessError)=> {
            if (err) {
                console.error("ndefFormatable format AsyncCallback Code: ${err.code}, message: ${err.message}");
            } else {
                console.info("ndefFormatable format AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("ndefFormatable format AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### NdefFormatableTag.formatReadOnly<sup>9+</sup>

formatReadOnly(message: [NdefMessage](#ndefmessage9)): Promise\<void>

将标签格式化为NDEF标签，将NDEF消息写入NDEF标签，之后将标签设置为只读。使用Promise方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | 是   | 格式化成功时要写入的NDEF消息。可以为null，为null时仅格式化标签，不写入内容。 |

**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<void> | Promise对象。无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'ndefFormatable' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!ndefFormatable.isTagConnected()) {
        if (!ndefFormatable.connectTag()) {
            console.error("ndefFormatable connectTag failed.");
            return;
        }
    }

    try {
        // ndefMessage created from raw data, such as:
        let ndefMessage = tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]);
        // MUST can be parsed as NDEF Record.
        // or ndefMessage created from tag.ndef.createNdefMessage(ndefRecords: NdefRecord[])

        ndefFormatable.formatReadOnly(ndefMessage).then(() => {
            console.info("ndefFormatable formatReadOnly Promise success.");
        }).catch((err : BusinessError)=> {
            console.error("ndefFormatable formatReadOnly Promise Code: ${err.code}, message: ${err.message}");
        });
    } catch (businessError) {
        console.error("ndefFormatable formatReadOnly Promise catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

### NdefFormatableTag.formatReadOnly<sup>9+</sup>

formatReadOnly(message: [NdefMessage](#ndefmessage9), callback: AsyncCallback\<void>): void

将标签格式化为NDEF标签，然后将NDEF消息写入NDEF标签，之后将标签设置为只读。使用callback方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| message | [NdefMessage](#ndefmessage9) | 是   | 格式化成功时要写入的NDEF消息。可以为null，为null时仅格式化标签，不写入内容。|

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| callback: AsyncCallback\<void> | 以callback形式异步返回格式化操作结果。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 401  | The parameter check failed. Possible causes: <br>1. Mandatory parameters are left unspecified.<br>2. Incorrect parameters types.<br>3. Parameter verification failed. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |

**示例：**

```js
import { tag } from '@kit.ConnectivityKit';
import { BusinessError } from '@kit.BasicServicesKit';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', obtains the 'ndefFormatable' correctly.

function nfcTechDemo() {
    // connect the tag at first if not connected.
    if (!ndefFormatable.isTagConnected()) {
        if (!ndefFormatable.connectTag()) {
            console.error("ndefFormatable connectTag failed.");
            return;
        }
    }

    try {
        // ndefMessage created from raw data, such as:
        let ndefMessage = tag.ndef.createNdefMessage([0xD1, 0x01, 0x03, 0x54, 0x4E, 0x46, 0x43]);
        // MUST can be parsed as NDEF Record.
        // or ndefMessage created from tag.ndef.createNdefMessage(ndefRecords: NdefRecord[])

        ndefFormatable.formatReadOnly(ndefMessage, (err : BusinessError)=> {
            if (err) {
                console.error("ndefFormatable formatReadOnly AsyncCallback err Code: ${err.code}, message: ${err.message}");
            } else {
                console.info("ndefFormatable formatReadOnly AsyncCallback success.");
            }
        });
    } catch (businessError) {
        console.error("ndefFormatable formatReadOnly AsyncCallback catch Code: ${(businessError as Businsess).code}, " +
            "message: ${(businessError as Businsess).message}");
    }
}
```

## BarcodeTag<sup>16+</sup>

BarcodeTag提供对条形码标签的属性和I/O操作的访问，继承自TagSession。

TagSession是所有NFC Tag 技术类型的基类， 提供建立连接和发送数据等共同接口。具体请参见[TagSession](js-apis-tagSession.md)。

以下是BarcodeTag的独有接口。

### BarcodeTag.getBarcode<sup>16+</sup>

getBarcode(): Promise\<ArrayBuffer>

获取读到的Barcode类型的完整Tag。使用Promise方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。


**返回值：**

| 类型                        | 说明                 |
| ------------------------- | ------------------ |
| Promise\<ArrayBuffer> | Promise对象。返回BarCode类型的 tag。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 201  | Permission denied. |
| 3100201 | Tag running state is abnormal in service. |
| 3100204 | Tag I/O operation failed. |
| 3100205 | The tag leaves the field. |
