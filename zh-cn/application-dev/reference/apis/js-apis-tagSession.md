# 标准NFC-Tag  TagSession

本模块是对NFC TagSession的使用说明。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## **导入模块**

```
import tag from '@ohos.nfc.tag';
```

## tagSession

tagSession是所有[Nfc tag 技术类型](js-apis-nfctech.md)的基类， 提供建立连接和发送数据等共同接口。

需要通过其子类来访问以下接口。在下面的示例中 统一用 getXXTag表示获取子类实例的方法。

具体使用时,请根据实际采用的Nfc tag技术，选择对应的方法，具体请参见[nfcTag](js-apis-nfcTag.md)文档。

### tagSession.connectTag

connectTag(): boolean;

和标签建立连接；
在从标签读取数据或将数据写入标签之前，必须调用此方法。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| boolean  | 连接建立成功返回 true，失败返回false。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let isNfcConnected = tag.getXXXTag(taginfo).connectTag(); 
console.log("isNfcConnected:" +isNfcConnected);
```

### tagSession.reset()

reset(): void

重置与标签的连接，并恢复将数据写入标签的默认超时时间。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| boolean  | 方法执行成功返回 true，失败返回false。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let reset = tag.getXXXTag(taginfo).reset(); 
console.log("reset:" +reset);
```

### tagSession.isTagConnected

isTagConnected(): boolean

检查是否已与标签建立连接。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| boolean  | 已建立连接返回 true，未建立连接返回false。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let isTagConnected = tag.getXXXTag(taginfo).isTagConnected(); 
console.log("isTagConnected:" +isTagConnected);
```

### tagSession.getMaxSendLength

getMaxSendLength(): number

查询可以发送到标签的最大数据长度。

**需要权限**：ohos.permission.NFC_TAG

**系统能力**：SystemCapability.Communication.NFC.Core

**返回值：**

| **类型** | **说明**                             |
| ------------------ | --------------------------|
| number  | 可以发送到标签的最大数据长度。 |

**示例：**

```js
import tag from '@ohos.nfc.tag';

// tagInfo is an Object given by nfc service when tag is dispatched.
let mazSendLen = tag.getXXXTag(taginfo).getMaxSendLength(); 
console.log("mazSendLen:" +mazSendLen);
```