# tagSession (标准NFC-Tag TagSession)

本模块是对NFC TagSession的使用说明。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## **导入模块**

```js
import tag from '@ohos.nfc.tag';
```

## tagSession

tagSession是所有[NFC Tag技术类型](js-apis-nfctech.md)的基类， 提供建立连接和发送数据等共同接口。

需要通过其子类来访问以下接口。在下面的示例中 统一用 getXXX()表示获取子类实例的方法。

具体使用时,请根据实际采用的Nfc tag技术，选择对应的方法，具体请参见[nfcTag](js-apis-nfcTag.md)文档。

### tagSession.getTagInfo

getTagInfo(): tag.TagInfo

获取该Tag被分发时，NFC服务所提供的Tag数据对象。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[tag.getTagInfo](js-apis-nfcTag.md#taggettaginfo9)替代。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| TagInfo  | NFC服务所提供的Tag数据对象。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

let tagInfo = tag.getIsoDep(tagInfo).getTagInfo(); 
console.log("tag tagInfo: " + tagInfo);
```

### tagSession.connectTag

connectTag(): boolean;

和标签建立连接。在从标签读取数据或将数据写入标签之前，必须调用此方法。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[tagSession.connect](#tagsessionconnect9)替代。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| boolean  | 连接建立成功返回true，失败返回false。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

let connectStatus = tag.getIsoDep(tagInfo).connectTag(); 
console.log("connectStatus: " + connectStatus);
```

### tagSession.connect<sup>9+</sup>

connect(): void;

和标签建立连接。在从标签读取数据或将数据写入标签之前，必须调用此方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](../errorcodes/errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

try {
    tag.getIsoDep(tagInfo).connect(); 
    console.log("tag connect success");
} catch (busiError) {
    console.log("tag connect busiError: " + busiError);
}
```

### tagSession.reset()

reset(): void

重置与标签的连接。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[tagSession.resetConnection](#tagsessionresetconnection9)替代。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

tag.getIsoDep(tagInfo).reset(); 
```

### tagSession.resetConnection()<sup>9+</sup>

resetConnection(): void

重置与标签的连接。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](../errorcodes/errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

try {
    tag.getIsoDep(tagInfo).resetConnection(); 
    console.log("tag resetConnection success");
} catch (busiError) {
    console.log("tag resetConnection busiError: " + busiError);
}
```

### tagSession.isTagConnected

isTagConnected(): boolean

检查是否已与标签建立连接。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[tagSession.isConnected](#tagsessionisconnected9)替代。

**系统能力：** SystemCapability.Communication.NFC.Tag

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| boolean  | 已建立连接返回 true，未建立连接返回false。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

let isTagConnected = tag.getIsoDep(tagInfo).isTagConnected(); 
console.log("isTagConnected: " + isTagConnected);
```

### tagSession.isConnected<sup>9+</sup>

isConnected(): boolean

检查是否已与标签建立连接。

**系统能力：** SystemCapability.Communication.NFC.Tag

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| boolean  | 已建立连接返回 true，未建立连接返回false。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

try {
    var isConnected = tag.getIsoDep(tagInfo).isConnected(); 
    console.log("tag isConnected = " + isConnected);
} catch (busiError) {
    console.log("tag isConnected busiError: " + busiError);
}
```

### tagSession.getMaxSendLength

getMaxSendLength(): number

查询可以发送到标签的最大数据长度。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[tagSession.getMaxTransmitSize](#tagsessiongetmaxtransmitsize9)替代。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number  | 可以发送到标签的最大数据长度，非负数。 |

**示例：**
```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

let maxSendLen = tag.getIsoDep(tagInfo).getMaxSendLength(); 
console.log("tag maxSendLen: " + maxSendLen);
```

### tagSession.getMaxTransmitSize<sup>9+</sup>

getMaxTransmitSize(): number

查询可以发送到标签的最大数据长度。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number  | 可以发送到标签的最大数据长度，非负数。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](../errorcodes/errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**示例：**
```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

try {
    var maxTransmitSize = tag.getIsoDep(tagInfo).getMaxTransmitSize(); 
    console.log("tag maxTransmitSize = " + maxTransmitSize);
} catch (busiError) {
    console.log("tag getMaxTransmitSize busiError: " + busiError);
}
```

### tagSession.getSendDataTimeout

getSendDataTimeout(): number

查询发送数据到Tag的等待超时时间，单位是毫秒。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[tagSession.getTimeout](#tagsessiongettimeout9)替代。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number  | 发送数据到Tag的等待超时时间，单位是毫秒，非负数。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

let sendDataTimeout = tag.getIsoDep(tagInfo).getSendDataTimeout(); 
console.log("tag sendDataTimeout: " + sendDataTimeout);
```

### tagSession.getTimeout<sup>9+</sup>

getTimeout(): number

查询发送数据到Tag的等待超时时间，单位是毫秒。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number  | 发送数据到Tag的等待超时时间，单位是毫秒，非负数。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](../errorcodes/errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

try {
    var timeout = tag.getIsoDep(tagInfo).getTimeout(); 
    console.log("tag timeout = " + timeout);
} catch (busiError) {
    console.log("tag getTimeout busiError: " + busiError);
}
```

### tagSession.setSendDataTimeout

setSendDataTimeout(timeout: number): boolean

查询发送数据到Tag的等待超时时间，单位是毫秒。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[tagSession.setTimeout](#tagsessionsettimeout9)替代。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| timeout | number | 是 | 超时时间，单位毫秒，非负值。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| boolean  | 设置超时时间成功返回true，设置失败返回false。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

let timeoutMs = 700;  // change it to be correct.
let setStatus = tag.getIsoDep(tagInfo).setSendDataTimeout(timeoutMs); 
console.log("tag setSendDataTimeout setStatus: " + setStatus);
```

### tagSession.setTimeout<sup>9+</sup>

setTimeout(timeout: number): void

查询发送数据到Tag的等待超时时间，单位是毫秒。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| timeout | number | 是 | 超时时间，单位毫秒，非负值。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](../errorcodes/errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

let timeoutMs = 700;  // change it to be correct.
try {
    tag.getIsoDep(tagInfo).setTimeout(timeoutMs); 
    console.log("tag setTimeout success");
} catch (busiError) {
    console.log("tag setTimeout busiError: " + busiError);
}
```

### tagSession.sendData

sendData(data: number[]): Promise<number[]>

发送指令到Tag上，使用Promise方式作为异步方法。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[tagSession.transmit](#tagsessiontransmit9)替代。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| data | number[] | 是 | 要发送的指令。每个number十六进制表示，范围是0x00~0xFF。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise<number[]> | 对端Tag对指令的响应数据。每个number十六进制表示，范围是0x00~0xFF。|

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

// connect the tag at first if not connected.
if (!tag.getIsoDep(tagInfo).isTagConnected()) {
    if (!tag.getIsoDep(tagInfo).connectTag()) {
        console.log("tagSession connectTag failed.");
        return;
    }
}

let cmdData = [0x01, 0x02, 0x03, 0x04]; // change the raw data to be correct.
tag.getIsoDep(tagInfo).sendData(cmdData).then((response) => {
    console.log("tagSession sendData Promise response: " + response);
}).catch((err)=> {
    console.log("tagSession sendData Promise err: " + err);
});
```

### tagSession.sendData

sendData(data: number[], callback: AsyncCallback<number[]>): void

发送指令到Tag上，使用AsyncCallback方式作为异步方法。

> **说明：**
> 从 API version 7 开始支持，从 API version 9 开始废弃，建议使用[tagSession.transmit](#tagsessiontransmit9-1)替代。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| data | number[] | 是 | 要发送的指令。每个number十六进制表示，范围是0x00~0xFF。 |
| callback | AsyncCallback<number[]> | 是 | 回调函数，返回响应数据。每个number十六进制表示，范围是0x00~0xFF。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

// connect the tag at first if not connected.
if (!tag.getIsoDep(tagInfo).isTagConnected()) {
    if (!tag.getIsoDep(tagInfo).connectTag()) {
        console.log("tagSession connectTag failed.");
        return;
    }
}

let cmdData = [0x01, 0x02, 0x03, 0x04]; // change the raw data to be correct.
tag.getIsoDep(tagInfo).sendData(cmdData, (err, response)=> {
    if (err) {
        console.log("tagSession sendData AsyncCallback err: " + err);
    } else {
        console.log("tagSession sendData AsyncCallback response: " + response);
    }
});
```

### tagSession.transmit<sup>9+</sup>

transmit(data: number[]): Promise<number[]>

发送指令到Tag上，使用Promise方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| data | number[] | 是 | 要发送的指令。每个number十六进制表示，范围是0x00~0xFF。 |

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| Promise<number[]> | 对端Tag对指令的响应数据。每个number十六进制表示，范围是0x00~0xFF。|

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](../errorcodes/errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

// connect the tag at first if not connected.
try {
    if (!tag.getIsoDep(tagInfo).isConnected()) {
        tag.getIsoDep(tagInfo).connect();
    }
} catch (busiError) {
    console.log("tag connect busiError: " + busiError);
    return;
}

let cmdData = [0x01, 0x02, 0x03, 0x04]; // change the raw data to be correct.
try {
    tag.getIsoDep(tagInfo).transmit(cmdData).then((response) => {
        console.log("tagSession transmit Promise response: " + response);
    }).catch((err)=> {
        console.log("tagSession transmit Promise err: " + err);
    });
} catch (busiError) {
    console.log("tag transmit busiError: " + busiError);
    return;
}
```

### tagSession.transmit<sup>9+</sup>

transmit(data: number[], callback: AsyncCallback<number[]>): void

发送指令到Tag上，使用AsyncCallback方式作为异步方法。

**需要权限：** ohos.permission.NFC_TAG

**系统能力：** SystemCapability.Communication.NFC.Tag

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                   |
| -------- | ----------------------- | ---- | -------------------------------------- |
| data | number[] | 是 | 要发送的指令。每个number十六进制表示，范围是0x00~0xFF。 |
| callback | AsyncCallback<number[]> | 是 | 回调函数，返回响应数据。每个number十六进制表示，范围是0x00~0xFF。 |

**错误码：**

以下错误码的详细介绍请参见[NFC错误码](../errorcodes/errorcode-nfc.md)。

| 错误码ID | 错误信息|
| ------- | -------|
| 3100201 | Tag running state is abnormal in service. |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// see 'tag.TagInfo' at 'js-apis-nfcTag.md', tagInfo is an Object given by nfc service when tag is dispatched.
// the folowing getXXX, can be one of getIsoDep, getNdef, getMifareClassic, ...

// connect the tag at first if not connected.
try {
    if (!tag.getIsoDep(tagInfo).isConnected()) {
        tag.getIsoDep(tagInfo).connect();
    }
} catch (busiError) {
    console.log("tag connect busiError: " + busiError);
    return;
}

let cmdData = [0x01, 0x02, 0x03, 0x04]; // change the raw data to be correct.
try {
    tag.getIsoDep(tagInfo).transmit(cmdData, (err, response)=> {
        if (err) {
            console.log("tagSession transmit AsyncCallback err: " + err);
        } else {
            console.log("tagSession transmit AsyncCallback response: " + response);
        }
    });
} catch (busiError) {
    console.log("tag transmit busiError: " + busiError);
    return;
}

```
