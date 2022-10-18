# 剪贴板

本模块主要提供管理系统剪贴板的能力，为系统复制、粘贴功能提供支持。系统剪贴板支持对文本、HTML、URI、Want、PixelMap等内容的操作。

> **说明：**
> 
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import pasteboard from '@ohos.pasteboard';
```

## 常量

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称 | 参数类型 | 值 | 说明 |
| -------- | -------- | -------- | -------- |
| MAX_RECORD_NUM<sup>7+</sup> | number | 512 | 单个PasteData中所能包含的最大条目数。 |
| MIMETYPE_TEXT_HTML<sup>7+</sup> | string | 'text/html' | HTML内容的MIME类型定义。 |
| MIMETYPE_TEXT_WANT<sup>7+</sup> | string | 'text/want' | Want内容的MIME类型定义。 |
| MIMETYPE_TEXT_PLAIN<sup>7+</sup> | string | 'text/plain' | 纯文本内容的MIME类型定义。 |
| MIMETYPE_TEXT_URI<sup>7+</sup> | string | 'text/uri' | URI内容的MIME类型定义。 |
| MIMETYPE_PIXELMAP<sup>9+</sup> | string | 'pixelMap' | PixelMap内容的MIME类型定义。 |

## ValueType<sup>9+</sup>

用于表示允许的数据字段类型。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.MiscServices.Pasteboard

| 类型 | 说明 |
| -------- | -------- |
| string | 表示string的类型。 |
| image.PixelMap | 表示[image.PixelMap](js-apis-image.md#pixelmap7)的类型。 |
| Want | 表示[Want](js-apis-application-Want.md)的类型。 |
| ArrayBuffer | 表示ArrayBuffer的类型。 |

## pasteboard.createData<sup>9+</sup>

createData(mimeType: string, value: ValueType): PasteData

构建一个自定义类型的剪贴板内容对象。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mimeType | string | 是 | 自定义数据的MIME类型。 |
| value | [ValueType](#valuetype9) | 是 | 自定义数据内容。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteData](#pastedata) |  剪贴板内容对象。 |

**示例：**

  ```js
  let dataXml = new ArrayBuffer(256);
  let pasteData = pasteboard.createData('app/xml', dataXml);
  ```

## pasteboard.createRecord<sup>9+</sup>

createRecord(mimeType: string, value: ValueType):PasteDataRecord;

创建一条自定义数据内容条目。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mimeType | string | 是 | 自定义数据的MIME类型。 |
| value | [ValueType](#valuetype9) | 是 | 自定义数据内容。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | 一条新建的自定义数据内容条目。 |

**示例：**

  ```js
  let dataXml = new ArrayBuffer(256);
  let pasteDataRecord = pasteboard.createRecord('app/xml', dataXml);
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

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
```

## ShareOption<sup>9+</sup>

可粘贴数据的范围类型枚举。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称  | 说明                    |
| -----  | ----------------------- |
| InApp  |表示仅允许同应用内粘贴。 |
| LocalDevice  |表示允许在此设备中任何应用内粘贴。 |
| CrossDevice  |表示允许跨设备在任何应用内粘贴。 |

## pasteboard.createHtmlData<sup>(deprecated)</sup>

createHtmlData(htmlText: string): PasteData

构建一个HTML剪贴板内容对象。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[pasteboard.createData](#pasteboardcreatedata9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| htmlText | string | 是 | HTML内容。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteData](#pastedata) | 剪贴板内容对象。 |

**示例：**

```js
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let pasteData = pasteboard.createHtmlData(html);
```

## pasteboard.createWantData<sup>(deprecated)</sup>

createWantData(want: Want): PasteData

构建一个Want剪贴板内容对象。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[pasteboard.createData](#pasteboardcreatedata9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | Want内容。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteData](#pastedata) | 剪贴板内容对象。 |

**示例：**

```js
let object = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
let pasteData = pasteboard.createWantData(object);
```

## pasteboard.createPlainTextData<sup>(deprecated)</sup>

createPlainTextData(text: string): PasteData

构建一个纯文本剪贴板内容对象。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[pasteboard.createData](#pasteboardcreatedata9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 纯文本内容。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteData](#pastedata) | 剪贴板内容对象。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('content');
```

## pasteboard.createUriData<sup>(deprecated)</sup>

createUriData(uri: string): PasteData

构建一个URI剪贴板内容对象。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[pasteboard.createData](#pasteboardcreatedata9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | URI内容。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteData](#pastedata) | 剪贴板内容对象。 |

**示例：**

```js
let pasteData = pasteboard.createUriData('dataability:///com.example.myapplication1/user.txt');
```
## pasteboard.createHtmlTextRecord<sup>(deprecated)</sup>

createHtmlTextRecord(htmlText: string): PasteDataRecord

创建一条HTML内容的条目。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[pasteboard.createRecord](#pasteboardcreaterecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| htmlText | string | 是 | HTML内容。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | 一条新建的HTML内容条目。 |

**示例：**

```js
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let record = pasteboard.createHtmlTextRecord(html);
```

## pasteboard.createWantRecord<sup>(deprecated)</sup>

createWantRecord(want: Want): PasteDataRecord

创建一条Want内容条目。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[pasteboard.createRecord](#pasteboardcreaterecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | Want内容。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | 一条新建的Want内容条目。 |

**示例：**

```js
let object = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
let record = pasteboard.createWantRecord(object);
```

## pasteboard.createPlainTextRecord<sup>(deprecated)</sup>

createPlainTextRecord(text: string): PasteDataRecord

创建一条纯文本内容条目。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[pasteboard.createRecord](#pasteboardcreaterecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 纯文本内容。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | 一条新建的纯文本内容条目。 |

**示例：**

```js
let record = pasteboard.createPlainTextRecord('hello');
```

## pasteboard.createUriRecord<sup>(deprecated)</sup>

createUriRecord(uri: string): PasteDataRecord

创建一条URI内容的条目。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[pasteboard.createRecord](#pasteboardcreaterecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | URI内容。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | 一条新建的URI内容条目。 |

**示例：**

```js
let record = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
```


## PasteDataProperty<sup>7+</sup>

定义了剪贴板中所有内容条目的属性，包含时间戳、数据类型、粘贴范围以及一些附加数据等。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| additions<sup>7+</sup> | {[key:string]:object} | 是 | 是 | 设置的其他附加属性数据。 |
| mimeTypes<sup>7+</sup> | Array&lt;string&gt; | 是 | 否 | 剪贴板内容条目的数据类型，非重复的类型列表。 |
| tag<sup>7+</sup> | string | 是 | 是 | 用户自定义标签。 |
| timestamp<sup>7+</sup> | number | 是 | 否 | 剪贴板数据的写入时间戳（单位：ms）。 |
| localOnly<sup>7+</sup> | boolean | 是 | 是 | 配置剪贴板内容是否为“仅在本地”。默认值为true。<br/>- 配置为true时，表示内容仅在本地，不会在设备之间传递。<br/>- 配置为false时，表示内容将在设备间传递。 |
| shareOption<sup>9+</sup> | [ShareOption](#shareoption9) | 是 | 是 | 指示剪贴板数据可以粘贴到的范围，如果未设置或设置不正确，则默认值为CrossDevice。 |

## PasteDataRecord<sup>7+</sup>

对于剪贴板中内容记录的抽象定义，称之为条目。剪贴板内容部分由一个或者多个条目构成，例如一条文本内容、一份HTML、一个URI或者一个Want。

### 属性

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| htmlText<sup>7+</sup> | string | 是 | 否 | HTML内容。 |
| want<sup>7+</sup> | [Want](js-apis-application-Want.md) | 是 | 否 | Want内容。 |
| mimeType<sup>7+</sup> | string | 是 | 否 | 数据类型。 |
| plainText<sup>7+</sup> | string | 是 | 否 | 纯文本内容。 |
| uri<sup>7+</sup> | string | 是 | 否 | URI内容。 |
| pixelMap<sup>9+</sup> | [image.PixelMap](js-apis-image.md#pixelmap7) | 是 | 否 | PixelMap内容。 |
| data<sup>9+</sup> | {[mimeType:&nbsp;string]:&nbsp;ArrayBuffer} | 是 | 否 | 自定义数据内容。 |

### convertToTextV9<sup>9+</sup>

convertToTextV9(callback: AsyncCallback&lt;string&gt;): void

将一个PasteData中的内容强制转换为文本内容，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数，当转换成功，err为undefined，data为强制转换的文本内容；否则返回错误信息。 |

**示例：**

```js
let record = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
record.convertToTextV9((err, data) => {
    if (err) {
        console.error(`Failed to convert to text. Cause: ${err.message}`);
        return;
    }
    console.info(`Succeeded in converting to text. Data: ${data}`);
});
```

### convertToTextV9<sup>9+</sup>

convertToTextV9(): Promise&lt;string&gt;

将一个PasteData中的内容强制转换为文本内容，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | Promise对象，返回强制转换的文本内容。 |

**示例：**

```js
let record = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
record.convertToTextV9().then((data) => {
    console.info(`Succeeded in converting to text. Data: ${data}`);
}).catch((err) => {
    console.error(`Failed to convert to text. Cause: ${err.message}`);
});
```

### convertToText<sup>(deprecated)</sup>

convertToText(callback: AsyncCallback&lt;string&gt;): void

将一个PasteData中的内容强制转换为文本内容，使用callback异步回调。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[convertToTextV9](#converttotextv99)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数，当转换成功，err为undefined，data为强制转换的文本内容；否则返回错误信息。 |

**示例：**

```js
let record = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
record.convertToText((err, data) => {    
    if (err) {        
        console.error(`Failed to convert to text. Cause: ${err.message}`);
        return;   
      }
    console.info(`Succeeded in converting to text. Data: ${data}`);
});
```

### convertToText<sup>(deprecated)</sup>

convertToText(): Promise&lt;string&gt;

将一个PasteData中的内容强制转换为文本内容，使用Promise异步回调。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[convertToTextV9](#converttotextv99-1)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | Promise对象，返回强制转换的文本内容。 |

**示例：**

```js
let record = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
record.convertToText().then((data) => {
    console.info(`Succeeded in converting to text. Data: ${data}`);
}).catch((err) => {
    console.error(`Failed to convert to text. Cause: ${err.message}`);
});
```

## PasteData

剪贴板内容对象。

在调用PasteData的接口前，需要先获取一个PasteData对象。

**系统能力：** SystemCapability.MiscServices.Pasteboard

### getPrimaryText

getPrimaryText(): string

获取首个条目的纯文本内容。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 纯文本内容。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let plainText = pasteData.getPrimaryText();
```

### getPrimaryHtml<sup>7+</sup>

getPrimaryHtml(): string

获取首个条目的HTML内容。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | HTML内容。 |

**示例：**

```js
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let pasteData = pasteboard.createHtmlData(html);
let htmlText = pasteData.getPrimaryHtml();
```

### getPrimaryWant<sup>7+</sup>

getPrimaryWant(): Want

获取首个条目的Want对象内容。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [Want](js-apis-application-Want.md) | Want对象内容。 |

**示例：**

```js
let object = { 
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
let pasteData = pasteboard.createWantData(object);
let want = pasteData.getPrimaryWant();
```

### getPrimaryUri<sup>7+</sup>

getPrimaryUri(): string

获取首个条目的URI内容。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | URI内容。 |

**示例：**

```js
let pasteData = pasteboard.createUriData('dataability:///com.example.myapplication1/user.txt');
let uri = pasteData.getPrimaryUri();
```

### getPrimaryPixelMap<sup>9+</sup>

getPrimaryPixelMap(): image.PixelMap

获取首个条目的PixelMap内容。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [image.PixelMap](js-apis-image.md#pixelmap7) | PixelMap内容。 |

**示例：**

```js
import image from '@ohos.multimedia.image';

let buffer = new ArrayBuffer(128);
let opt = {
  size: { height: 3, width: 5 },
  pixelFormat: 3,
  editable: true,
  alphaType: 1,
  scaleMode: 1
};
image.createPixelMap(buffer, opt).then((pixelMap) => {
    let pasteData = pasteboard.createPixelMapData(pixelMap);
    let pixelMap = pasteData.getPrimaryPixelMap();
});
```

### addRecord<sup>7+</sup>

addRecord(record: PasteDataRecord): void

向当前剪贴板内容中添加一条条目，同时也会将条目类型添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

剪贴板内容中添加的条目达到数量上限512后，后续的添加操作无效。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| record | [PasteDataRecord](#pastedatarecord7) | 是 | 待添加的条目。 |

**示例：**

```js
let pasteData = pasteboard.createUriData('dataability:///com.example.myapplication1/user.txt');
let textRecord = pasteboard.createPlainTextRecord('hello');
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let htmlRecord = pasteboard.createHtmlTextRecord(html);
pasteData.addRecord(textRecord);
pasteData.addRecord(htmlRecord);
```
### addRecord<sup>9+</sup>

addRecord(mimeType: string, value: ValueType): void

向当前剪贴板内容中添加一条自定义数据内容条目，同时也会将自定义数据类型添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

剪贴板内容中添加的条目达到数量上限512后，后续的添加操作无效。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mimeType | string | 是 | 自定义数据的MIME类型。 |
| value | [ValueType](#valuetype9) | 是 | 自定义数据内容。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](../errorcodes/errorcode-pasteboard.md)。
| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900002 | The number of record exceeds the maximum limit. |

**示例：**

  ```js
  let pasteData = pasteboard.createUriData('dataability:///com.example.myapplication1/user.txt');
  let dataXml = new ArrayBuffer(256);
  pasteData.addRecord('app/xml', dataXml);
  ```

### getMimeTypes<sup>7+</sup>

getMimeTypes(): Array&lt;string&gt;

获取剪贴板中[PasteDataProperty](#pastedataproperty7)的mimeTypes列表，当剪贴板内容为空时，返回列表为空。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array&lt;string&gt; | 剪贴板内容条目的数据类型，非重复的类型列表。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let types = pasteData.getMimeTypes();
```

### getPrimaryMimeType<sup>7+</sup>

getPrimaryMimeType(): string

获取剪贴板内容中首个条目的数据类型。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 首个条目的数据类型。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let type = pasteData.getPrimaryMimeType();
```

### getProperty<sup>7+</sup>

getProperty(): PasteDataProperty

获取剪贴板内容的属性描述对象。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataProperty](#pastedataproperty7) | 属性描述对象。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let property = pasteData.getProperty();
```

### setProperty<sup>9+</sup>

setProperty(property: PasteDataProperty): void

设置剪贴板内容的属性描述对象，当前仅支持设置shareOption属性。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| property | [PasteDataProperty](#pastedataproperty7) | 是 | 属性描述对象。 |

**示例：**

```js
let pasteData = pasteboard.createHtmlData('application/xml');
let prop = pasteData.getProperty();
prop.shareOption = pasteboard.ShareOption.InApp;
pasteData.setProperty(prop);
```

### getRecord<sup>9+</sup>

getRecord(index: number): PasteDataRecord

获取剪贴板内容中指定下标的条目。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定条目的下标。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | 指定下标的条目。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](../errorcodes/errorcode-pasteboard.md)。
| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900001 | The index is out of range. |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let record = pasteData.getRecord(0);
```

### getRecordCount<sup>7+</sup>

getRecordCount(): number

获取剪贴板内容中条目的个数。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 条目的个数。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let count = pasteData.getRecordCount();
```

### getTag<sup>7+</sup>

getTag(): string

获取剪贴板内容中用户自定义的标签内容，如果没有设置用户自定义的标签内容将返回空。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回用户自定义的标签内容，如果没有设置用户自定义的标签内容，将返回空。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let tag = pasteData.getTag();
```

### hasType<sup>9+</sup>

hasType(mimeType: string): boolean

检查剪贴板内容中是否有指定的MIME数据类型。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mimeType | string | 是 | 待查询的数据类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 有指定的数据类型返回true，否则返回false。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let hasType = pasteData.hasType(pasteboard.MIMETYPE_TEXT_PLAIN);
```

### removeRecord<sup>9+</sup>

removeRecord(index: number): void

移除剪贴板内容中指定下标的条目。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定的下标。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](../errorcodes/errorcode-pasteboard.md)。
| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900001 | The index is out of range. |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
pasteData.removeRecord(0);
```

### replaceRecord<sup>9+</sup>

replaceRecord(index: number, record: PasteDataRecord): void

替换剪贴板内容中指定下标的条目。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定的下标。 |
| record | [PasteDataRecord](#pastedatarecord7) | 是 | 新条目的内容。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](../errorcodes/errorcode-pasteboard.md)。
| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900001 | The index is out of range. |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let record = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
pasteData.replaceRecord(0, record);
```
### addHtmlRecord<sup>(deprecated)</sup>

addHtmlRecord(htmlText: string): void

向当前剪贴板内容中添加一条HTML内容条目，并将MIMETYPE_TEXT_HTML添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

剪贴板内容中添加的条目达到数量上限512后，后续的添加操作无效。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[addRecord](#addrecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| htmlText | string | 是 | HTML内容。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
pasteData.addHtmlRecord(html);
```

### addWantRecord<sup>(deprecated)</sup>

addWantRecord(want: Want): void

向当前剪贴板内容中添加一条Want条目，并将MIMETYPE_TEXT_WANT添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

剪贴板内容中添加的条目达到数量上限512后，后续的添加操作无效。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[addRecord](#addrecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](js-apis-application-Want.md) | 是 | Want对象内容。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let object = { 
    bundleName: "com.example.aafwk.test",    
    abilityName: "com.example.aafwk.test.TwoAbility"
};
pasteData.addWantRecord(object);
```

### addTextRecord<sup>(deprecated)</sup>

addTextRecord(text: string): void

向当前剪贴板内容中添加一条纯文本条目，并将MIME_TEXT_PLAIN添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

剪贴板内容中添加的条目达到数量上限512后，后续的添加操作无效。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[addRecord](#addrecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 纯文本内容。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
pasteData.addTextRecord('good');
```

### addUriRecord<sup>(deprecated)</sup>

addUriRecord(uri: string): void

向当前剪贴板内容中添加一条URI条目，并将MIMETYPE_TEXT_URI添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

剪贴板内容中添加的条目达到数量上限512后，后续的添加操作无效。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[addRecord](#addrecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | URI内容。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
pasteData.addUriRecord('dataability:///com.example.myapplication1/user.txt');
```
### getRecordAt<sup>(deprecated)</sup>

getRecordAt(index: number): PasteDataRecord

获取剪贴板内容中指定下标的条目。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[getRecord](#getrecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定条目的下标。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | 指定下标的条目。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let record = pasteData.getRecordAt(0);
```

### hasMimeType<sup>(deprecated)</sup>

hasMimeType(mimeType: string): boolean

检查剪贴板内容中是否有指定的数据类型。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[hasType](#hastype9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mimeType | string | 是 | 待查询的数据类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 有指定的数据类型返回true，否则返回false。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let hasType = pasteData.hasMimeType(pasteboard.MIMETYPE_TEXT_PLAIN);
```
### removeRecordAt<sup>(deprecated)</sup>

removeRecordAt(index: number): boolean

移除剪贴板内容中指定下标的条目。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[removeRecord](#removerecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定的下标。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 成功移除返回true，失败返回false。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let isRemove = pasteData.removeRecordAt(0);
```
### replaceRecordAt<sup>(deprecated)</sup>

replaceRecordAt(index: number, record: PasteDataRecord): boolean

替换剪贴板内容中指定下标的条目。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[replaceRecord](#replacerecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定的下标。 |
| record | [PasteDataRecord](#pastedatarecord7) | 是 | 替换后的条目。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 成功替换返回true，失败返回false。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('hello');
let record = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
let isReplace = pasteData.replaceRecordAt(0, record);
```

## SystemPasteboard

系统剪贴板对象。

在调用SystemPasteboard的接口前，需要先通过[getSystemPasteboard](#pasteboardgetsystempasteboard)获取系统剪贴板。

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
```

### on('update')<sup>7+</sup>

on(type:  'update', callback: () =&gt;void ): void

订阅系统剪贴板内容变化事件，当系统剪贴板中内容变化时触发用户程序的回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 取值为'update'，表示系统剪贴板内容变化事件。 |
| callback | function | 是 | 剪贴板中内容变化时触发的用户程序的回调。 |

**示例：**

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
let listener = () => {
    console.info('The system pasteboard has changed.');
};
systemPasteboard.on('update', listener);
```

### off('update')<sup>7+</sup>

off(type:  'update', callback?: () =&gt;void ): void

取消订阅系统剪贴板内容变化事件。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| type | string | 是 | 取值为'update'，表示系统剪贴板内容变化事件。 |
| callback | function | 否 | 剪贴板中内容变化时触发的用户程序的回调。 |

**示例：**

```js
let listener = () => {
    console.info('The system pasteboard has changed.');
};
systemPasteboard.off('update', listener);
```

### clearData<sup>9+</sup>

clearData(callback: AsyncCallback&lt;void&gt;): void

清空系统剪贴板内容，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当成功清空时，err为undefined；否则为错误对象。 |

**示例：**

```js
systemPasteboard.clearData((err, data) => { 
    if (err) {
        console.error(`Failed to clear the pasteboard. Cause: ${err.message}`);
        return;
    }
    console.info('Succeeded in clearing the pasteboard.');
});
```

### clearData<sup>9+</sup>

clearData(): Promise&lt;void&gt;

清空系统剪贴板内容，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
systemPasteboard.clearData().then((data) => { 
    console.info('Succeeded in clearing the pasteboard.');
}).catch((err) => {
    console.error(`Failed to clear the pasteboard. Cause: ${err.message}`);
});
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

```js
let pasteData = pasteboard.createPlainTextData('content');
let systemPasteboard = pasteboard.getSystemPasteboard();
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

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| data | [PasteData](#pastedata) | PasteData对象。 |

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

```js
let pasteData = pasteboard.createPlainTextData('content');
let systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setData(pasteData).then((data) => {
    console.info('Succeeded in setting PasteData.');
}).catch((err) => {
    console.error('Failed to set PasteData. Cause: ' + err.message);
});
```

### getData<sup>9+</sup>

getData( callback: AsyncCallback&lt;PasteData&gt;): void

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

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData((err, pasteData) => {  
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    let text = pasteData.getPrimaryText();
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

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData().then((pasteData) => { 
    let text = pasteData.getPrimaryText();
}).catch((err) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
})
```

### hasData<sup>9+</sup>

hasData(callback:  AsyncCallback&lt;boolean&gt;): void

判断系统剪贴板中是否有内容，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |

**示例：**

```js
systemPasteboard.hasData((err, data) => {
    if (err) {
        console.error(`Failed to check the PasteData. Cause: ${err.message}`);
        return;
    }
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
});
```

### hasData<sup>9+</sup>

hasData(): Promise&lt;boolean&gt;

判断系统剪贴板中是否有内容，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | 返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |

**示例：**

```js
systemPasteboard.hasData().then((data) => { 
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
}).catch((err) => {
    console.error(`Failed to check the PasteData. Cause: ${err.message}`);
});
```

### clear<sup>(deprecated)</sup>

clear(callback: AsyncCallback&lt;void&gt;): void

清空系统剪贴板内容，使用callback异步回调。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[pasteboard.clearData](#cleardata9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当成功清空时，err为undefined；否则为错误对象。 |

**示例：**

```js
systemPasteboard.clear((err, data) => { 
    if (err) {        
        console.error(`Failed to clear the PasteData. Cause: ${err.message}`);
        return;
    }
    console.info('Succeeded in clearing the PasteData.');
});
```

### clear<sup>(deprecated)</sup>

clear(): Promise&lt;void&gt;

清空系统剪贴板内容，使用Promise异步回调。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[pasteboard.clearData](#cleardata9-1)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
systemPasteboard.clear().then((data) => { 
    console.info('Succeeded in clearing the PasteData.');
}).catch((err) => {    
    console.error(`Failed to clear the PasteData. Cause: ${err.message}`);
});
```

### getPasteData<sup>(deprecated)</sup>

getPasteData( callback: AsyncCallback&lt;PasteData&gt;): void

读取系统剪贴板内容，使用callback异步回调。
> **说明：**
>
> 从 API Version 6 开始支持，从 API Version 9 开始废弃，建议使用[getData](#getdata9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[PasteData](#pastedata)&gt; | 是 | 回调函数。当读取成功，err为undefined，data为返回的系统剪贴板数据；否则返回错误对象。 |

**示例：**

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getPasteData((err, pasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    let text = pasteData.getPrimaryText();
});
```

### getPasteData<sup>(deprecated)</sup>

getPasteData(): Promise&lt;PasteData&gt;

读取系统剪贴板内容，使用Promise异步回调。
> **说明：**
>
> 从 API Version 6 开始支持，从 API Version 9 开始废弃，建议使用[getData](#getdata9-1)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[PasteData](#pastedata)&gt; | Promise对象，返回系统剪贴板数据。 |

**示例：**

```js
let systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getPasteData().then((pasteData) => { 
    let text = pasteData.getPrimaryText();
}).catch((err) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
})
```

### hasPasteData<sup>(deprecated)</sup>

hasPasteData(callback:  AsyncCallback&lt;boolean&gt;): void

判断系统剪贴板中是否有内容，使用callback异步回调。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[hasData](#hasdata9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |

**示例：**

```js
systemPasteboard.hasPasteData((err, data) => {
    if (err) {
        console.error(`Failed to check the PasteData. Cause: ${err.message}`);
        return;
    }
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
});
```

### hasPasteData<sup>(deprecated)</sup>

hasPasteData(): Promise&lt;boolean&gt;

判断系统剪贴板中是否有内容，使用Promise异步回调。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[hasData](#hasdata9-1)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | 返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |

**示例：**

```js
systemPasteboard.hasPasteData().then((data) => { 
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
}).catch((err) => {
    console.error(`Failed to check the PasteData. Cause: ${err.message}`);
});
```

### setPasteData<sup>(deprecated)</sup>

setPasteData(data: PasteData, callback: AsyncCallback&lt;void&gt;): void

将数据写入系统剪贴板，使用callback异步回调。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[setData](#setdata9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | 是 | PasteData对象。 |
| callback | AsyncCallback&lt;void> | 是 | 回调函数。当写入成功，err为undefined，否则为错误对象。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('content');
let systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setPasteData(pasteData, (err, data) => { 
    if (err) {
        console.error('Failed to set PasteData. Cause: ' + err.message);
        return;
    }
    console.info('Succeeded in setting PasteData.');
});
```
### setPasteData<sup>(deprecated)</sup>

setPasteData(data: PasteData): Promise&lt;void&gt;

将数据写入系统剪贴板，使用Promise异步回调。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[setData](#setdata9-1)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 说明 |
| -------- | -------- | -------- |
| data | [PasteData](#pastedata) | PasteData对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
let pasteData = pasteboard.createPlainTextData('content');
let systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setPasteData(pasteData).then((data) => {
    console.info('Succeeded in setting PasteData.');
}).catch((err) => {
    console.error('Failed to set PasteData. Cause: ' + err.message);
});
```
