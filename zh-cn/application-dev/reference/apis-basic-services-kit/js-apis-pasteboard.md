# @ohos.pasteboard (剪贴板)

本模块主要提供管理系统剪贴板的能力，为系统复制、粘贴功能提供支持。系统剪贴板支持对文本、HTML、URI、Want、PixelMap等内容的操作。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { pasteboard } from '@kit.BasicServicesKit';
```

## 常量

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称 | 类型 | 值            | 说明                                                                                                                                        |
| -------- | -------- |--------------|-------------------------------------------------------------------------------------------------------------------------------------------|
| MAX_RECORD_NUM<sup>7+</sup> | number | -            | API version 10之前，此常量值为512，表示单个PasteData中所能包含的最大条目数为512。当剪贴板内容中添加的条目达到数量上限512后，后续的添加操作无效。<br>从API version 10开始，不再限制单个PasteData中所能包含的最大条目数。 |
| MIMETYPE_TEXT_HTML<sup>7+</sup> | string | 'text/html'  | HTML内容的MIME类型定义。                                                                                                                          |
| MIMETYPE_TEXT_WANT<sup>7+</sup> | string | 'text/want'  | Want内容的MIME类型定义。                                                                                                                          |
| MIMETYPE_TEXT_PLAIN<sup>7+</sup> | string | 'text/plain' | 纯文本内容的MIME类型定义。                                                                                                                           |
| MIMETYPE_TEXT_URI<sup>7+</sup> | string | 'text/uri'   | URI内容的MIME类型定义。                                                                                                                           |
| MIMETYPE_PIXELMAP<sup>9+</sup> | string | 'pixelMap'   | PixelMap内容的MIME类型定义。                                                                                                                      |

## ValueType<sup>9+</sup>

type ValueType = string | image.PixelMap | Want | ArrayBuffer

用于表示允许的数据字段类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 类型 | 说明 |
| -------- | -------- |
| string | 表示string的类型。 |
| image.PixelMap | 表示[image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7)的类型。 |
| Want | 表示[Want](../apis-ability-kit/js-apis-app-ability-want.md)的类型。 |
| ArrayBuffer | 表示ArrayBuffer的类型。 |

## pasteboard.createData<sup>9+</sup>

createData(mimeType: string, value: ValueType): PasteData

构建一个自定义类型的剪贴板内容对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                                                                     |
| -------- | -------- | -------- |--------------------------------------------------------------------------------------------------------|
| mimeType | string | 是 | 剪贴板数据对应的MIME类型，可以是[常量](#常量)中已定义的类型，包括HTML类型，WANT类型，纯文本类型，URI类型，PIXELMAP类型；也可以是自定义的MIME类型，开发者可自定义此参数值, mimeType长度不能超过1024字节。 |
| value | [ValueType](#valuetype9) | 是 | 自定义数据内容。                                                                                               |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteData](#pastedata) |  剪贴板内容对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

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


## pasteboard.createRecord<sup>9+</sup>

createRecord(mimeType: string, value: ValueType):PasteDataRecord;

创建一条自定义数据内容条目。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明                |
| -------- | -------- | -------- |-------------------|
| mimeType | string | 是 | 剪贴板数据对应的MIME类型，可以是[常量](#常量)中已定义的类型，包括HTML类型，WANT类型，纯文本类型，URI类型，PIXELMAP类型；也可以是自定义的MIME类型，开发者可自定义此参数值，mimeType长度不能超过1024个字节。  |
| value | [ValueType](#valuetype9) | 是 | 自定义数据内容。          |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | 一条新建的自定义数据内容条目。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types;  3. Parameter verification failed. |

**示例1：**

  ```ts
let dataXml = new ArrayBuffer(256);
let pasteDataRecord: pasteboard.PasteDataRecord = pasteboard.createRecord('app/xml', dataXml);
  ```

**示例2：**

  ```ts
let dataUri = 'dataability:///com.example.myapplication1/user.txt';
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, dataUri);
  ```

## pasteboard.getSystemPasteboard

getSystemPasteboard(): SystemPasteboard

获取系统剪贴板对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [SystemPasteboard](#systempasteboard) | 系统剪贴板对象。 |

**示例：**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
```

## ShareOption<sup>9+</sup>

可粘贴数据的范围类型枚举。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称                               | 值  | 说明                                                                                  |
| ---------------------------------- | --- | ------------------------------------------------------------------------------------- |
| INAPP                              | 0   | 表示仅允许同应用内粘贴。                                                              |
| LOCALDEVICE                        | 1   | 表示允许在此设备中任何应用内粘贴。                                                    |
| CROSSDEVICE<sup>(deprecated)</sup> | 2   | 表示允许跨设备在任何应用内粘贴。<br/>从API Version 12开始废弃，无替代接口和替代方法，后续由用户在“设置-多设备协同-跨设备剪切板开关”选项中控制是否允许跨设备粘贴。 |

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

```ts
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let pasteData: pasteboard.PasteData = pasteboard.createHtmlData(html);
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
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | Want内容。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteData](#pastedata) | 剪贴板内容对象。 |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';

let object: Want = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
let pasteData: pasteboard.PasteData = pasteboard.createWantData(object);
```

## pasteboard.createPlainTextData<sup>(deprecated)</sup>

createPlainTextData(text: string): PasteData

构建一个纯文本剪贴板内容对象。
> **说明：**
>
> 从 API Version 6 开始支持，从 API Version 9 开始废弃，建议使用[pasteboard.createData](#pasteboardcreatedata9)替代。

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

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('content');
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

```ts
let pasteData: pasteboard.PasteData = pasteboard.createUriData('dataability:///com.example.myapplication1/user.txt');
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

```ts
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let record: pasteboard.PasteDataRecord = pasteboard.createHtmlTextRecord(html);
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
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | Want内容。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataRecord](#pastedatarecord7) | 一条新建的Want内容条目。 |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';

let object: Want = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
let record: pasteboard.PasteDataRecord = pasteboard.createWantRecord(object);
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

```ts
let record: pasteboard.PasteDataRecord = pasteboard.createPlainTextRecord('hello');
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

```ts
let record: pasteboard.PasteDataRecord = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
```


## PasteDataProperty<sup>7+</sup>

定义了剪贴板中所有内容条目的属性，包含时间戳、数据类型、粘贴范围以及一些附加数据等，
该属性必须通过[setProperty](#setproperty9)方法，才能设置到剪贴板中。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称 | 类型 | 可读 | 可写 | 说明                                                                                                                                                                                                                                       |
| -------- | -------- | -------- | -------- |------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------|
| additions<sup>7+</sup> | {[key:string]:object} | 是 | 是 | 设置其他附加属性数据。不支持动态追加属性，只能通过重新赋值的方式修改附加值，具体见相关示例setProperty。                                                                                                                                                                                                                              |
| mimeTypes<sup>7+</sup> | Array&lt;string&gt; | 是 | 否 | 剪贴板内容条目的数据类型，非重复的类型列表。                                                                                                                                                                                                                   |
| tag<sup>7+</sup> | string | 是 | 是 | 用户自定义标签。                                                                                                                                                                                                                                 |
| timestamp<sup>7+</sup> | number | 是 | 否 | 剪贴板数据的写入时间戳（单位：ms）。                                                                                                                                                                                                                      |
| localOnly<sup>7+</sup> | boolean | 是 | 是 | 配置剪贴板内容是否为“仅在本地”，默认值为false。其值会被shareOption属性覆盖，推荐使用shareOption属性。ShareOption.INAPP、ShareOption.LOCALDEVICE会将localOnly设置为true，ShareOption.CROSSDEVICE会将localOnly设置为false。<br/>- 配置为true时，表示内容仅在本地，不会在设备之间传递。<br/>- 配置为false时，表示内容将在设备间传递。 |
| shareOption<sup>9+</sup> | [ShareOption](#shareoption9) | 是 | 是 | 指示剪贴板数据可以粘贴到的范围，如果未设置或设置不正确，则默认值为CROSSDEVICE。                                                                                                                                                                                            |

## PasteDataRecord<sup>7+</sup>

对于剪贴板中内容记录的抽象定义，称之为条目。剪贴板内容部分由一个或者多个条目构成，例如一条文本内容、一份HTML、一个URI或者一个Want。

### 属性

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| htmlText<sup>7+</sup> | string | 是 | 否 | HTML内容。 |
| want<sup>7+</sup> | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | 否 | Want内容。 |
| mimeType<sup>7+</sup> | string | 是 | 否 | 数据类型。 |
| plainText<sup>7+</sup> | string | 是 | 否 | 纯文本内容。 |
| uri<sup>7+</sup> | string | 是 | 否 | URI内容。 |
| pixelMap<sup>9+</sup> | [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | 是 | 否 | PixelMap内容。 |
| data<sup>9+</sup> | {[mimeType:&nbsp;string]:&nbsp;ArrayBuffer} | 是 | 否 | 自定义数据内容。 |

### toPlainText<sup>9+</sup>

toPlainText(): string

将一个PasteData中的内容强制转换为文本内容。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 纯文本内容。 |

**示例：**

```ts
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
let data: string = record.toPlainText();
console.info(`Succeeded in converting to text. Data: ${data}`);
```

### convertToText<sup>(deprecated)</sup>

convertToText(callback: AsyncCallback&lt;string&gt;): void

将一个PasteData中的内容强制转换为文本内容，使用callback异步回调。
> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[toPlainText](#toplaintext9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数，当转换成功，err为undefined，data为强制转换的文本内容；否则返回错误信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: Incorrect parameters types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let record: pasteboard.PasteDataRecord = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
record.convertToText((err: BusinessError, data: string) => {
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
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[toPlainText](#toplaintext9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | Promise对象，返回强制转换的文本内容。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let record: pasteboard.PasteDataRecord = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
record.convertToText().then((data: string) => {
    console.info(`Succeeded in converting to text. Data: ${data}`);
}).catch((err: BusinessError) => {
    console.error(`Failed to convert to text. Cause: ${err.message}`);
});
```

## PasteData

剪贴板内容对象。剪贴板内容包含一个或者多个内容条目（[PasteDataRecord](#pastedatarecord7)）以及属性描述对象（[PasteDataProperty](#pastedataproperty7)）。

在调用PasteData的接口前，需要先通过[createData()](#pasteboardcreatedata9)或[getData()](#getdata9)获取一个PasteData对象。

**系统能力：** SystemCapability.MiscServices.Pasteboard

### getPrimaryText

getPrimaryText(): string

获取首个条目的纯文本内容。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 纯文本内容。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let plainText: string = pasteData.getPrimaryText();
```

### getPrimaryHtml<sup>7+</sup>

getPrimaryHtml(): string

获取首个条目的HTML内容。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | HTML内容。 |

**示例：**

```ts
let html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_HTML, html);
let htmlText: string = pasteData.getPrimaryHtml();
```

### getPrimaryWant<sup>7+</sup>

getPrimaryWant(): Want

获取首个条目的Want对象内容。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Want对象内容。 |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';

let object: Want = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_WANT, object);
let want: Want = pasteData.getPrimaryWant();
```

### getPrimaryUri<sup>7+</sup>

getPrimaryUri(): string

获取首个条目的URI内容。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | URI内容。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
let uri: string = pasteData.getPrimaryUri();
```

### getPrimaryPixelMap<sup>9+</sup>

getPrimaryPixelMap(): image.PixelMap

获取首个条目的PixelMap内容。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [image.PixelMap](../apis-image-kit/js-apis-image.md#pixelmap7) | PixelMap内容。 |

**示例：**

```ts
import { image } from '@kit.ImageKit';

let buffer = new ArrayBuffer(128);
let realSize: image.Size = { height: 3, width: 5 };
let opt: image.InitializationOptions = {
    size: realSize,
    pixelFormat: 3,
    editable: true,
    alphaType: 1,
    scaleMode: 1
};
image.createPixelMap(buffer, opt).then((pixelMap: image.PixelMap) => {
    let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_PIXELMAP, pixelMap);
    let PixelMap: image.PixelMap = pasteData.getPrimaryPixelMap();
});
```

### addRecord<sup>7+</sup>

addRecord(record: PasteDataRecord): void

向当前剪贴板内容中添加一条条目，同时也会将条目类型添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| record | [PasteDataRecord](#pastedatarecord7) | 是 | 待添加的条目。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
let textRecord: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let html: string = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
let htmlRecord: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_HTML, html);
pasteData.addRecord(textRecord);
pasteData.addRecord(htmlRecord);
```
### addRecord<sup>9+</sup>

addRecord(mimeType: string, value: ValueType): void

向当前剪贴板内容中添加一条自定义数据内容条目，同时也会将自定义数据类型添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mimeType | string | 是 | 自定义数据的MIME类型， 其长度不能超过1024个字节。 |
| value | [ValueType](#valuetype9) | 是 | 自定义数据内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types; 3. Parameter verification failed. |

**示例：**

  ```ts
  let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
  let dataXml = new ArrayBuffer(256);
  pasteData.addRecord('app/xml', dataXml);
  ```

### getMimeTypes<sup>7+</sup>

getMimeTypes(): Array&lt;string&gt;

获取剪贴板中[PasteDataProperty](#pastedataproperty7)的mimeTypes列表，当剪贴板内容为空时，返回列表为空。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array&lt;string&gt; | 剪贴板内容条目的数据类型，非重复的类型列表。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let types: string[] = pasteData.getMimeTypes();
```

### getPrimaryMimeType<sup>7+</sup>

getPrimaryMimeType(): string

获取剪贴板内容中首个条目的数据类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 首个条目的数据类型。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let type: string = pasteData.getPrimaryMimeType();
```

### getProperty<sup>7+</sup>

getProperty(): PasteDataProperty

获取剪贴板内容的属性描述对象。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [PasteDataProperty](#pastedataproperty7) | 属性描述对象。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let property: pasteboard.PasteDataProperty = pasteData.getProperty();
```

### setProperty<sup>9+</sup>

setProperty(property: PasteDataProperty): void

设置剪贴板内容的属性描述对象[PasteDataProperty](#pastedataproperty7)。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| property | [PasteDataProperty](#pastedataproperty7) | 是 | 属性描述对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
type AdditionType = Record<string, Record<string, Object>>;

let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_HTML, 'application/xml');
let prop: pasteboard.PasteDataProperty = pasteData.getProperty();
prop.shareOption = pasteboard.ShareOption.INAPP;
// 需要注意，不支持对addition进行追加属性的操作，只能通过重新赋值的方式达到追加属性的目的。
prop.additions = { 'TestOne': { 'Test': 123 }, 'TestTwo': { 'Test': 'additions' } } as AdditionType;
prop.tag = 'TestTag';
pasteData.setProperty(prop);
```
[PasteDataProperty](#pastedataproperty7)的localOnly与shareOption属性互斥，最终结果以shareOption为准，shareOption会影响localOnly的值。
```ts
(async () => {
    let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
    let prop: pasteboard.PasteDataProperty = pasteData.getProperty();
    prop.shareOption = pasteboard.ShareOption.INAPP;
    prop.localOnly = false;
    pasteData.setProperty(prop);
    let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();

    await systemPasteboard.setData(pasteData).then(async () => {
        console.info('Succeeded in setting PasteData.');
        await systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
            let prop: pasteboard.PasteDataProperty = pasteData.getProperty();
            prop.localOnly; // true
        });
    });

    prop.shareOption = pasteboard.ShareOption.LOCALDEVICE;
    prop.localOnly = false;
    pasteData.setProperty(prop);

    await systemPasteboard.setData(pasteData).then(async () => {
        console.info('Succeeded in setting PasteData.');
        await systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
            let prop: pasteboard.PasteDataProperty = pasteData.getProperty();
            prop.localOnly; // true
        });
    });

    prop.shareOption = pasteboard.ShareOption.CROSSDEVICE;
    prop.localOnly = true;
    pasteData.setProperty(prop);

    await systemPasteboard.setData(pasteData).then(async () => {
        console.info('Succeeded in setting PasteData.');
        await systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
            let prop: pasteboard.PasteDataProperty = pasteData.getProperty();
            prop.localOnly; // false
        });
    });
})()
```

### getRecord<sup>9+</sup>

getRecord(index: number): PasteDataRecord

获取剪贴板内容中指定下标的条目。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900001 | The index is out of the record. |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let record: pasteboard.PasteDataRecord = pasteData.getRecord(0);
```

### getRecordCount<sup>7+</sup>

getRecordCount(): number

获取剪贴板内容中条目的个数。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 条目的个数。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let count: number = pasteData.getRecordCount();
```

### getTag<sup>7+</sup>

getTag(): string

获取剪贴板内容中用户自定义的标签内容，如果没有设置用户自定义的标签内容将返回空。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回用户自定义的标签内容，如果没有设置用户自定义的标签内容，将返回空。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let tag: string = pasteData.getTag();
```

### hasType<sup>9+</sup>

hasType(mimeType: string): boolean

检查剪贴板内容中是否有指定的MIME数据类型。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| mimeType | string | 是 | 待查询的数据类型。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 有指定的数据类型返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let hasType: boolean = pasteData.hasType(pasteboard.MIMETYPE_TEXT_PLAIN);
```

### removeRecord<sup>9+</sup>

removeRecord(index: number): void

移除剪贴板内容中指定下标的条目。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定的下标。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900001 | The index is out of the record. |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
pasteData.removeRecord(0);
```

### replaceRecord<sup>9+</sup>

replaceRecord(index: number, record: PasteDataRecord): void

替换剪贴板内容中指定下标的条目。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定的下标。 |
| record | [PasteDataRecord](#pastedatarecord7) | 是 | 新条目的内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900001 | The index is out of the record. |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'hello');
let record: pasteboard.PasteDataRecord = pasteboard.createRecord(pasteboard.MIMETYPE_TEXT_URI, 'dataability:///com.example.myapplication1/user.txt');
pasteData.replaceRecord(0, record);
```

### pasteStart<sup>12+</sup>

pasteStart(): void

读取剪贴板数据前，通知剪贴板服务保留跨设备通道。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData((err: BusinessError, pasteData: pasteboard.PasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    pasteData.pasteStart();
    console.log(`using data: ${pasteData.getPrimaryText()}`);
    pasteData.pasteComplete();
});
```

### pasteComplete<sup>12+</sup>

pasteComplete(): void

通知剪贴板服务数据使用已完成。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData((err: BusinessError, pasteData: pasteboard.PasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    pasteData.pasteStart();
    console.log(`using data: ${pasteData.getPrimaryText()}`);
    pasteData.pasteComplete();
});
```

### addHtmlRecord<sup>(deprecated)</sup>

addHtmlRecord(htmlText: string): void

向当前剪贴板内容中添加一条HTML内容条目，并将MIMETYPE_TEXT_HTML添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[addRecord](#addrecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| htmlText | string | 是 | HTML内容。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let html: string = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
pasteData.addHtmlRecord(html);
```

### addWantRecord<sup>(deprecated)</sup>

addWantRecord(want: Want): void

向当前剪贴板内容中添加一条Want条目，并将MIMETYPE_TEXT_WANT添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[addRecord](#addrecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| want | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | 是 | Want对象内容。 |

**示例：**

```ts
import { Want } from '@kit.AbilityKit';

let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let object: Want = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
pasteData.addWantRecord(object);
```

### addTextRecord<sup>(deprecated)</sup>

addTextRecord(text: string): void

向当前剪贴板内容中添加一条纯文本条目，并将MIME_TEXT_PLAIN添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[addRecord](#addrecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| text | string | 是 | 纯文本内容。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
pasteData.addTextRecord('good');
```

### addUriRecord<sup>(deprecated)</sup>

addUriRecord(uri: string): void

向当前剪贴板内容中添加一条URI条目，并将MIMETYPE_TEXT_URI添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

> **说明：**
>
> 从 API Version 7 开始支持，从 API Version 9 开始废弃，建议使用[addRecord](#addrecord9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | URI内容。 |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let record: pasteboard.PasteDataRecord = pasteData.getRecordAt(0);
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let hasType: boolean = pasteData.hasMimeType(pasteboard.MIMETYPE_TEXT_PLAIN);
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let isRemove: boolean = pasteData.removeRecordAt(0);
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

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('hello');
let record: pasteboard.PasteDataRecord = pasteboard.createUriRecord('dataability:///com.example.myapplication1/user.txt');
let isReplace: boolean = pasteData.replaceRecordAt(0, record);
```

## SystemPasteboard

系统剪贴板对象。

在调用SystemPasteboard的接口前，需要先通过[getSystemPasteboard](#pasteboardgetsystempasteboard)获取系统剪贴板。

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
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

| 参数名 | 类型 | 必填 | 说明                                                      |
| -------- | -------- | -------- |---------------------------------------------------------|
| type | string | 是 | 取值为'update'，表示系统剪贴板内容变化事件。                              |
| callback | function | 否 | 剪贴板中内容变化时触发的用户程序的回调。如果此参数未填，表明清除本应用的所有监听回调，否则表示清除指定监听回调。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
let listener = () => {
    console.info('The system pasteboard has changed.');
};
systemPasteboard.off('update', listener);
```

### clearData<sup>9+</sup>

clearData(callback: AsyncCallback&lt;void&gt;): void

清空系统剪贴板内容，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。当成功清空时，err为undefined；否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
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

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.clearData().then((data: void) => {
    console.info('Succeeded in clearing the pasteboard.');
}).catch((err: BusinessError) => {
    console.error(`Failed to clear the pasteboard. Cause: ${err.message}`);
});
```

### setData<sup>9+</sup>

setData(data: PasteData, callback: AsyncCallback&lt;void&gt;): void

将数据写入系统剪贴板，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | 是 | PasteData对象。 |
| callback | AsyncCallback&lt;void> | 是 | 回调函数。当写入成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900003 | Another copy or paste operation is in progress. |
| 12900004 | Replication is prohibited. |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

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

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900003 | Another copy or paste operation is in progress. |
| 12900004 | Replication is prohibited. |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let pasteData: pasteboard.PasteData = pasteboard.createData(pasteboard.MIMETYPE_TEXT_PLAIN, 'content');
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setData(pasteData).then((data: void) => {
    console.info('Succeeded in setting PasteData.');
}).catch((err: BusinessError) => {
    console.error('Failed to set PasteData. Cause: ' + err.message);
});
```

### getData<sup>9+</sup>

getData( callback: AsyncCallback&lt;PasteData&gt;): void

读取系统剪贴板内容，使用callback异步回调。

**需要权限**：ohos.permission.READ_PASTEBOARD

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;[PasteData](#pastedata)&gt; | 是 | 回调函数。当读取成功，err为undefined，data为返回的系统剪贴板数据；否则返回错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900003 | Another copy or paste operation is in progress. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData((err: BusinessError, pasteData: pasteboard.PasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    let text: string = pasteData.getPrimaryText();
});
```

### getData<sup>9+</sup>

getData(): Promise&lt;PasteData&gt;

读取系统剪贴板内容，使用Promise异步回调。

**需要权限**：ohos.permission.READ_PASTEBOARD

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[PasteData](#pastedata)&gt; | Promise对象，返回系统剪贴板数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900003 | Another copy or paste operation is in progress. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getData().then((pasteData: pasteboard.PasteData) => {
    let text: string = pasteData.getPrimaryText();
}).catch((err: BusinessError) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
});
```

### hasData<sup>9+</sup>

hasData(callback:  AsyncCallback&lt;boolean&gt;): void

判断系统剪贴板中是否有内容，使用callback异步回调。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;boolean&gt; | 是 | 返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.hasData((err: BusinessError, data: boolean) => {
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

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;boolean&gt; | 返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.hasData().then((data: boolean) => {
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
}).catch((err: BusinessError) => {
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.clear().then((data) => {
    console.info('Succeeded in clearing the PasteData.');
}).catch((err: BusinessError) => {
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getPasteData((err: BusinessError, pasteData: pasteboard.PasteData) => {
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    let text: string = pasteData.getPrimaryText();
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getPasteData().then((pasteData: pasteboard.PasteData) => {
    let text: string = pasteData.getPrimaryText();
}).catch((err: BusinessError) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
});
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

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.hasPasteData((err: BusinessError, data: boolean) => {
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

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.hasPasteData().then((data: boolean) => {
    console.info(`Succeeded in checking the PasteData. Data: ${data}`);
}).catch((err: BusinessError) => {
    console.error(`Failed to check the PasteData. Cause: ${err.message}`);
});
```

### setPasteData<sup>(deprecated)</sup>

setPasteData(data: PasteData, callback: AsyncCallback&lt;void&gt;): void

将数据写入系统剪贴板，使用callback异步回调。
> **说明：**
>
> 从 API Version 6 开始支持，从 API Version 9 开始废弃，建议使用[setData](#setdata9)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | 是 | PasteData对象。 |
| callback | AsyncCallback&lt;void> | 是 | 回调函数。当写入成功，err为undefined，否则为错误对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |

**示例：**

```ts
let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('content');
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
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
> 从 API Version 6 开始支持，从 API Version 9 开始废弃，建议使用[setData](#setdata9-1)替代。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| data | [PasteData](#pastedata) | 是 | PasteData对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let pasteData: pasteboard.PasteData = pasteboard.createPlainTextData('content');
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setPasteData(pasteData).then((data: void) => {
    console.info('Succeeded in setting PasteData.');
}).catch((err: BusinessError) => {
    console.error('Failed to set PasteData. Cause: ' + err.message);
});
```
### isRemoteData<sup>11+</sup>

isRemoteData(): boolean

判断剪贴板中的数据是否来自其他设备。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型    | 说明                                  |
| ------- | ------------------------------------- |
| boolean | 是来自其他设备返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900005 | Request timed out. |

**示例：**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: boolean = systemPasteboard.isRemoteData();
    console.info(`Succeeded in checking the RemoteData. Result: ${result}`);
} catch (err) {
    console.error('Failed to check the RemoteData. Cause:' + err.message);
};
```

### getDataSource<sup>11+</sup>

getDataSource(): string

获取数据来源。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型   | 说明   |
| ------ | ------ |
| string | 数据来源。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900005 | Request timed out. |

**示例：**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: string = systemPasteboard.getDataSource();
    console.info(`Succeeded in getting DataSource. Result: ${result}`);
} catch (err) { 
    console.error('Failed to get DataSource. Cause:' + err.message);
};
```

### hasDataType<sup>11+</sup>

hasDataType(mimeType: string): boolean

检查剪贴板内容中是否有指定类型的数据。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名   | 类型   | 必填 | 说明               |
| -------- | ------ | ---- | ------------------ |
| mimeType | string | 是   | 数据类型。 |

**返回值：**

| 类型    | 说明                                        |
| ------- | ------------------------------------------- |
| boolean | 有指定类型的数据返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 12900005 | Request timed out. |

**示例：**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: boolean = systemPasteboard.hasDataType(pasteboard.MIMETYPE_TEXT_PLAIN);
    console.info(`Succeeded in checking the DataType. Result: ${result}`);
} catch (err) {
    console.error('Failed to check the DataType. Cause:' + err.message);
};
```

### clearDataSync<sup>11+</sup>

clearDataSync(): void

清空系统剪贴板内容, 此接口为同步接口。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900005 | Request timed out. |

**示例：**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    systemPasteboard.clearDataSync();
    console.info('Succeeded in clearing the pasteboard.');
} catch (err) {
    console.error('Failed to clear the pasteboard. Cause:' + err.message);
};
```

### getDataSync<sup>11+</sup>

getDataSync(): PasteData

读取系统剪贴板内容, 此接口为同步接口。

**需要权限**：ohos.permission.READ_PASTEBOARD

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型                    | 说明                 |
| ----------------------- | -------------------- |
| [PasteData](#pastedata) | 返回系统剪贴板数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900005 | Request timed out. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

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

### setDataSync<sup>11+</sup>

setDataSync(data: PasteData): void

将数据写入系统剪贴板, 此接口为同步接口。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型                    | 必填 | 说明             |
| ------ | ----------------------- | ---- | ---------------- |
| data   | [PasteData](#pastedata) | 是   | 需要写入剪贴板中的数据。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 12900005 | Request timed out. |

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

### hasDataSync<sup>11+</sup>

hasDataSync(): boolean

判断系统剪贴板中是否有内容, 此接口为同步接口。

**原子化服务API：** 从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型    | 说明                                                                    |
| ------- | ----------------------------------------------------------------------- |
| boolean | 返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 12900005 | Request timed out. |

**示例：**

```ts
let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: boolean = systemPasteboard.hasDataSync();
    console.info(`Succeeded in checking the PasteData. Result: ${result}`);
} catch (err) {
    console.error('Failed to check the PasteData. Cause:' + err.message);
};    
```

### getUnifiedData<sup>12+</sup>

getUnifiedData(): Promise&lt;unifiedDataChannel.UnifiedData&gt;

读取系统剪贴板内容，使用Promise异步回调。

**需要权限**：ohos.permission.READ_PASTEBOARD

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[unifiedDataChannel.UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata)&gt; | Promise对象，返回系统剪贴板数据。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 12900003 | Another copy or paste operation is in progress. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { unifiedDataChannel } from '@kit.ArkData';
import { uniformTypeDescriptor } from '@kit.ArkData';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getUnifiedData().then((data) => {
    let records: Array<unifiedDataChannel.UnifiedRecord> = data.getRecords();
    for (let j = 0; j < records.length; j++) {
        if (records[j].getType() === uniformTypeDescriptor.UniformDataType.PLAIN_TEXT) {
            let text = records[j] as unifiedDataChannel.PlainText;
            console.info(`${j + 1}.${text.textContent}`);
        }
    }
}).catch((err: BusinessError) => {
    console.error('Failed to get UnifiedData. Cause: ' + err.message);
});
```

### getUnifiedDataSync<sup>12+</sup>

getUnifiedDataSync(): unifiedDataChannel.UnifiedData

读取系统剪贴板内容, 此接口为同步接口。

**需要权限**：ohos.permission.READ_PASTEBOARD

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型                 | 说明                 |
| -------------------- | -------------------- |
| [unifiedDataChannel.UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata) | 返回系统剪贴板数据。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 12900005 | Request timed out. |

**示例：**

```ts
import { unifiedDataChannel } from '@kit.ArkData';

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    let result: unifiedDataChannel.UnifiedData = systemPasteboard.getUnifiedDataSync();
    console.info('Succeeded in getting UnifiedData.');
} catch (err) {
    console.error('Failed to get UnifiedData. Cause:' + err.message);
};   
```

### setUnifiedData<sup>12+</sup>

setUnifiedData(data: unifiedDataChannel.UnifiedData): Promise&lt;void&gt;

将数据写入系统剪贴板，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| data | [unifiedDataChannel.UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata) | 是 | 	需要写入剪贴板中的数据。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 12900003 | Another copy or paste operation is in progress. |
| 12900004 | Replication is prohibited. |

**示例：**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { unifiedDataChannel } from '@kit.ArkData';

let plainTextData = new unifiedDataChannel.UnifiedData();
let plainText = new unifiedDataChannel.PlainText();
plainText.details = {
    Key: 'delayPlaintext',
    Value: 'delayPlaintext',
};
plainText.textContent = 'delayTextContent';
plainText.abstract = 'delayTextContent';
plainTextData.addRecord(plainText);

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setUnifiedData(plainTextData).then((data: void) => {
    console.info('Succeeded in setting UnifiedData.');
}).catch((err: BusinessError) => {
    console.error('Failed to set UnifiedData. Cause: ' + err.message);
});
```

### setUnifiedDataSync<sup>12+</sup>

setUnifiedDataSync(data: unifiedDataChannel.UnifiedData): void

将数据写入系统剪贴板, 此接口为同步接口。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型        | 必填 | 说明             |
| ------ | ----------- | ---- | ---------------- |
| data   | [unifiedDataChannel.UnifiedData](../apis-arkdata/js-apis-data-unifiedDataChannel.md#unifieddata) | 是   | 需要写入剪贴板中的数据。 |

**错误码：**

以下错误码的详细介绍请参见[剪贴板错误码](errorcode-pasteboard.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameters types. |
| 12900005 | Request timed out. |

**示例：**

```ts
import { unifiedDataChannel } from '@kit.ArkData';

let plainTextData = new unifiedDataChannel.UnifiedData();
let plainText = new unifiedDataChannel.PlainText();
plainText.details = {
    Key: 'delayPlaintext',
    Value: 'delayPlaintext',
};
plainText.textContent = 'delayTextContent';
plainText.abstract = 'delayTextContent';
plainTextData.addRecord(plainText);

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
try {
    systemPasteboard.setUnifiedDataSync(plainTextData);
    console.info('Succeeded in setting UnifiedData.');
} catch (err) {
    console.error('Failed to set UnifiedData. Cause:' + err.message);
};  
```
### Pattern<sup>13+</sup>
剪贴板支持检测的模式类型。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称                               | 值  | 说明                                                                                  |
| ---------------------------------- | --- | ------------------------------------------------------------------------------------- |
| URL                              | 0   | URL类型。                                                              |
| NUMBER                        | 1   | 数字类型。                                                    |
| EMAIL_ADDRESS | 2   | 邮箱地址类型。 |

### detectPatterns<sup>13+</sup>

detectPatterns(patterns: Array&lt;Pattern&gt;): Promise&lt;Array&lt;Pattern&gt;&gt;

检测**本地**剪贴板中存在的模式，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| patterns | [Array&lt;Pattern&gt;](#pattern13) | 是 | 	需要在剪贴板中检测的模式。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;Pattern&gt;&gt; | Promise对象，返回检测到的模式 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. 3. Parameter verification failed. |

**示例：**

```ts
import { pasteboard } from '@kit.BasicServicesKit'

let systemPasteboard: pasteboard.SystemPasteboard = pasteboard.getSystemPasteboard();
let patterns: Array<pasteboard.Pattern> = [pasteboard.Pattern.URL, pasteboard.Pattern.EMAIL_ADDRESS];

systemPasteboard.detectPatterns(patterns).then((data: Array<pasteboard.Pattern>) => {
    if (patterns.sort().join('')==data.sort().join('')) {
      console.info('All needed patterns detected, next get data');
      try {
        let result: pasteboard.PasteData = systemPasteboard.getDataSync();
        console.info('Succeeded in getting PasteData.');
      } catch (err) {
        console.error('Failed to get PasteData. Cause:' + err.message);
      };
    } else {
      console.info("Not all needed patterns detected, no need to get data.");
    }
});
```