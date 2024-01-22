# @ohos.pasteboard (剪贴板)

本模块主要提供管理系统剪贴板的能力，为系统复制、粘贴功能提供支持。系统剪贴板支持对文本、HTML、URI、Want、PixelMap等内容的操作。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import pasteboard from '@ohos.pasteboard';
```

## 常量

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称 | 类型 | 值            | 说明                                                                                                                                        |
| -------- | -------- |--------------|-------------------------------------------------------------------------------------------------------------------------------------------|
| MIMETYPE_TEXT_HTML<sup>7+</sup> | string | 'text/html'  | HTML内容的MIME类型定义。                                                                                                                          |
| MIMETYPE_TEXT_WANT<sup>7+</sup> | string | 'text/want'  | Want内容的MIME类型定义。                                                                                                                          |
| MIMETYPE_TEXT_PLAIN<sup>7+</sup> | string | 'text/plain' | 纯文本内容的MIME类型定义。                                                                                                                           |
| MIMETYPE_TEXT_URI<sup>7+</sup> | string | 'text/uri'   | URI内容的MIME类型定义。                                                                                                                           |
| MIMETYPE_PIXELMAP<sup>9+</sup> | string | 'pixelMap'   | PixelMap内容的MIME类型定义。                                                                                                                      |

## ValueType<sup>9+</sup>

用于表示允许的数据字段类型。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 类型 | 说明 |
| -------- | -------- |
| string | 表示string的类型。 |
| image.PixelMap | 表示[image.PixelMap](js-apis-image.md#pixelmap7)的类型。 |
| Want | 表示[Want](js-apis-app-ability-want.md)的类型。 |
| ArrayBuffer | 表示ArrayBuffer的类型。 |

## pasteboard.createData<sup>9+</sup>

createData(mimeType: string, value: ValueType): PasteData

构建一个自定义类型的剪贴板内容对象。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                                                                     |
| -------- | -------- | -------- |--------------------------------------------------------------------------------------------------------|
| mimeType | string | 是 | 剪贴板数据对应的MIME类型，可以是[常量](#常量)中已定义的类型，包括HTML类型，WANT类型，纯文本类型，URI类型，PIXELMAP类型；也可以是自定义的MIME类型，开发者可自定义此参数值。 |
| value | [ValueType](#valuetype9) | 是 | 自定义数据内容。                                                                                               |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteData](#pastedata) |  剪贴板内容对象。 |

**示例1：**

  ```ts
  let dataXml = new ArrayBuffer(256);
  let pasteData: pasteboard.PasteData = pasteboard.createData('app/xml', dataXml);
  ```

**示例2：**

  ```ts
 let dataText = 'hello';
 let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, dataText);
  ```

## pasteboard.getSystemPasteboard

getSystemPasteboard(): SystemPasteboard

获取系统剪贴板对象。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [SystemPasteboard](#systempasteboard) | 系统剪贴板对象。 |

**示例：**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
```
## PasteData

剪贴板内容对象。


## SystemPasteboard

系统剪贴板对象。在调用SystemPasteboard的接口前，需要先通过[getSystemPasteboard](#pasteboardgetsystempasteboard)获取系统剪贴板。

### getData<sup>9+</sup>

getData(callback: AsyncCallback&lt;PasteData&gt;): void

读取系统剪贴板内容，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[PasteData](#pastedata)&gt; | 是 | 回调函数。当读取成功，err为undefined，data为返回的系统剪贴板数据；否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](../errorcodes/errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900003 | Another copy or paste is in progress. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData((err: BusinessError, pasteData: pasteboard.PasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
});
```


### getData<sup>9+</sup>

getData(): Promise&lt;PasteData&gt;

读取系统剪贴板内容，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[PasteData](#pastedata)&gt; | Promise对象，返回系统剪贴板数据。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](../errorcodes/errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900003 | Another copy or paste is in progress. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
}).catch((err: BusinessError) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
});
```

### getDataSync<sup>11+</sup>

getDataSync(): PasteData

读取系统剪贴板内容, 此接口为同步接口。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型                    | 说明                 |
| ----------------------- | -------------------- |
| [PasteData](#pastedata) | 返回系统剪贴板数据。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](../errorcodes/errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900005 | Request time out. |

**示例：**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: pasteboard.PasteData = systemPasteboard.getDataSync();
    console.info('Succeeded in getting PasteData.');
} catch (err) {
    console.error('Failed to get PasteData. Cause:' + err.message);
};   
```

### setData<sup>9+</sup>

setData(data: PasteData, callback: AsyncCallback&lt;void&gt;): void

将数据写入系统剪贴板，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | 是 | PasteData对象。 |
| callback | AsyncCallback&lt;void> | 是 | 回调函数。当写入成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](../errorcodes/errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900003 | Another copy or paste is in progress. |
| 12900004 | Replication is prohibited. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'content');
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setData(pasteData, (err, data) => {
    if (err) {
        console.error('Failed to set PasteData. Cause: ' + err.message);
        return;
    }
    console.info('Succeeded in setting PasteData.');
});
```

### setData<sup>9+</sup>

setData(data: PasteData): Promise&lt;void&gt;

将数据写入系统剪贴板，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | 是 | PasteData对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](../errorcodes/errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900003 | Another copy or paste is in progress. |
| 12900004 | Replication is prohibited. |

**示例：**

```ts
import { BusinessError } from '@ohos.base';

let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'content');
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setData(pasteData).then((data: void) => {
    console.info('Succeeded in setting PasteData.');
}).catch((err: BusinessError) => {
    console.error('Failed to set PasteData. Cause: ' + err.message);
});
```

### setDataSync<sup>11+</sup>

setDataSync(data: PasteData): void

将数据写入系统剪贴板, 此接口为同步接口。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型                    | 必填 | 说明             |
| ------ | ----------------------- | ---- | ---------------- |
| data   | [PasteData](#pastedata) | 是   | 需要写入剪贴板中的数据。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](../errorcodes/errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Type of data is not PasteData. |
| 12900005 | Request time out. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    systemPasteboard.setDataSync(pasteData);
    console.info('Succeeded in setting PasteData.');
} catch (err) {
    console.error('Failed to set PasteData. Cause:' + err.message);
};  
```