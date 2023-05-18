# 剪贴板

本模块主要提供管理系统剪贴板的能力，为系统复制、粘贴功能提供支持。系统剪贴板支持对文本、HTML、URI、Want等内容的操作。

> **说明：**
>
> 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import pasteboard from '@ohos.pasteboard';
```

## 属性

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称                             | 参数类型 | 可读 | 可写 | 说明                                  |
| -------------------------------- | -------- | ---- | ---- | ------------------------------------- |
| MAX_RECORD_NUM<sup>7+</sup>      | number   | 是   | 否   | 单个PasteData中所能包含的最大条目数。 |
| MIMETYPE_TEXT_HTML<sup>7+</sup>  | string   | 是   | 否   | HTML内容的MIME类型定义。              |
| MIMETYPE_TEXT_WANT<sup>7+</sup>  | string   | 是   | 否   | Want内容的MIME类型定义。              |
| MIMETYPE_TEXT_PLAIN<sup>7+</sup> | string   | 是   | 否   | 纯文本内容的MIME类型定义。            |
| MIMETYPE_TEXT_URI<sup>7+</sup>   | string   | 是   | 否   | URI内容的MIME类型定义。               |


## pasteboard.createPlainTextData<sup>6+</sup>

createPlainTextData(text:string): PasteData

构建一个纯文本剪贴板内容对象。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| text   | string | 是   | 纯文本内容。 |

**返回值：**

| 类型                    | 说明             |
| ----------------------- | ---------------- |
| [PasteData](#pastedata) | 剪贴板内容对象。 |

**示例：**

```js
var pasteData = pasteboard.createPlainTextData("content");
```


## pasteboard.createHtmlData<sup>7+</sup>

createHtmlData(htmlText:string): PasteData

构建一个HTML剪贴板内容对象。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名   | 类型   | 必填 | 说明       |
| -------- | ------ | ---- | ---------- |
| htmlText | string | 是   | HTML内容。 |

**返回值：**

| 类型                    | 说明             |
| ----------------------- | ---------------- |
| [PasteData](#pastedata) | 剪贴板内容对象。 |

**示例：**

```js
var html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
var pasteData = pasteboard.createHtmlData(html);
```


## pasteboard.createWantData<sup>7+</sup>

createWantData(want:Want): PasteData

构建一个Want剪贴板内容对象。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型                                | 必填 | 说明       |
| ------ | ----------------------------------- | ---- | ---------- |
| want   | [Want](js-apis-featureAbility.md#want) | 是   | Want内容。 |

**返回值：**

| 类型                    | 说明             |
| ----------------------- | ---------------- |
| [PasteData](#pastedata) | 剪贴板内容对象。 |

**示例：**

```js
var object = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
var pasteData = pasteboard.createWantData(object);
```


## pasteboard.createUriData<sup>7+</sup>

createUriData(uri:string): PasteData

构建一个URI剪贴板内容对象。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型   | 必填 | 说明      |
| ------ | ------ | ---- | --------- |
| uri    | string | 是   | URI内容。 |

**返回值：**

| 类型                    | 说明             |
| ----------------------- | ---------------- |
| [PasteData](#pastedata) | 剪贴板内容对象。 |

**示例：**

```js
var pasteData = pasteboard.createUriData("dataability:///com.example.myapplication1/user.txt");
```

## pasteboard.createPlainTextRecord<sup>7+</sup>

createPlainTextRecord(text:string): PasteDataRecord

创建一条纯文本内容条目。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| text   | string | 是   | 纯文本内容。 |

**返回值：**

| 类型                                 | 说明                       |
| ------------------------------------ | -------------------------- |
| [PasteDataRecord](#pastedatarecord7) | 一条新建的纯文本内容条目。 |

**示例：**

```js
var record = pasteboard.createPlainTextRecord("hello");
```


## pasteboard.createHtmlTextRecord<sup>7+</sup>

createHtmlTextRecord(htmlText:string): PasteDataRecord

创建一条HTML内容的条目。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名   | 类型   | 必填 | 说明       |
| -------- | ------ | ---- | ---------- |
| htmlText | string | 是   | HTML内容。 |

**返回值：**

| 类型                                 | 说明                     |
| ------------------------------------ | ------------------------ |
| [PasteDataRecord](#pastedatarecord7) | 一条新建的HTML内容条目。 |

**示例：**

```js
var html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
var record = pasteboard.createHtmlTextRecord(html);
```


## pasteboard.createWantRecord<sup>7+</sup>

createWantRecord(want:Want): PasteDataRecord

创建一条Want内容条目。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型                                | 必填 | 说明       |
| ------ | ----------------------------------- | ---- | ---------- |
| want   | [Want](js-apis-featureAbility.md#want) | 是   | Want内容。 |

**返回值：**

| 类型                                 | 说明                     |
| ------------------------------------ | ------------------------ |
| [PasteDataRecord](#pastedatarecord7) | 一条新建的Want内容条目。 |

**示例：**

```js
var object = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
var record = pasteboard.createWantRecord(object);
```

## pasteboard.createUriRecord<sup>7+</sup>

createUriRecord(uri:string): PasteDataRecord

创建一条URI内容的条目。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型   | 必填 | 说明      |
| ------ | ------ | ---- | --------- |
| uri    | string | 是   | URI内容。 |

**返回值：**

| 类型                                 | 说明                    |
| ------------------------------------ | ----------------------- |
| [PasteDataRecord](#pastedatarecord7) | 一条新建的URI内容条目。 |

**示例：**

```js
var record = pasteboard.createUriRecord("dataability:///com.example.myapplication1/user.txt");
```

## pasteboard.getSystemPasteboard

getSystemPasteboard(): SystemPasteboard

获取系统剪贴板对象。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型                                  | 说明             |
| ------------------------------------- | ---------------- |
| [SystemPasteboard](#systempasteboard) | 系统剪切板对象。 |

**示例：**

```js
var systemPasteboard = pasteboard.getSystemPasteboard();
```


## PasteDataProperty<sup>7+</sup>

定义了剪贴板中所有内容条目的属性，包含时间戳、数据类型以及一些附加数据等。

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称      | 参数类型              | 可读 | 可写 | 说明                                                         |
| --------- | --------------------- | ---- | ---- | ------------------------------------------------------------ |
| additions | {[key:string]:object} | 是   | 是   | 设置的其他附加属性数据, 暂不支持。                            |
| mimeTypes | Array&lt;string&gt;   | 是   | 否   | 剪贴板内容条目的数据类型，非重复的类型列表。                 |
| tag       | string                | 是   | 是   | 用户自定义标签, 暂不支持。                                   |
| timestamp | number                | 是   | 否   | 剪贴板数据的写入时间戳（单位：ms）。                         |
| localOnly | boolean               | 是   | 是   | 配置剪贴板内容是否为“仅在本地”, 默认值为true。暂不支持<br/>- 配置为true时，表示内容仅在本地，不会在设备之间传递。<br/>- 配置为false时，表示内容将在设备间传递。 |


## PasteDataRecord<sup>7+</sup>

对于剪贴板中内容记录的抽象定义，称之为条目。剪贴板内容部分由一个或者多个条目构成，例如一条文本内容、一份HTML、一个URI或者一个Want。


### 属性

**系统能力：** SystemCapability.MiscServices.Pasteboard

| 名称                   | 参数类型                            | 可读 | 可写 | 说明         |
| ---------------------- | ----------------------------------- | ---- | ---- | ------------ |
| htmlText<sup>7+</sup>  | string                              | 是   | 否   | HTML内容。   |
| want<sup>7+</sup>      | [Want](js-apis-featureAbility.md#want) | 是   | 否   | Want内容。   |
| mimeType<sup>7+</sup>  | string                              | 是   | 否   | 数据类型。   |
| plainText<sup>7+</sup> | string                              | 是   | 否   | 纯文本内容。 |
| uri<sup>7+</sup>       | string                              | 是   | 否   | URI内容。    |


### convertToText<sup>7+</sup>

convertToText(): Promise&lt;string&gt;

将一个PasteData中的内容强制转换为文本内容，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型                  | 说明                                  |
| --------------------- | ------------------------------------- |
| Promise&lt;string&gt; | Promise对象，返回强制转换的文本内容。 |

**示例：**

```js
var record = pasteboard.createUriRecord("dataability:///com.example.myapplication1/user.txt");
record.convertToText().then((data) => {
    console.info('Succeeded in converting to text. Data: ' + JSON.stringify(data));
}).catch((err) => {
    console.error('Failed to convert to text. Cause: ' + JSON.stringify(err));
});
```


### convertToText<sup>7+</sup>

convertToText(callback: AsyncCallback&lt;string&gt;): void

将一个PasteData中的内容强制转换为文本内容，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名   | 类型                        | 必填 | 说明                                                         |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;string&gt; | 是   | 回调函数，当转换成功，err为undefined，data为强制转换的文本内容；否则返回错误信息。 |

**示例：**

```js
var record = pasteboard.createUriRecord("dataability:///com.example.myapplication1/user.txt");
record.convertToText((err, data) => {
    if (err) {
        console.error('Failed to convert to text. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in converting to text. Data: ' + JSON.stringify(data));
});
```


## PasteData<sup>6+</sup>

剪贴板内容对象。剪贴板内容包含一个或者多个内容条目（[PasteDataRecord](#pastedatarecord7)）以及属性描述对象（[PasteDataProperty](#pastedataproperty7)）。

在调用PasteData的接口前，需要先通过[createPlainTextData()](#pasteboardcreateplaintextdata6)、[createHtmlData()](#pasteboardcreatehtmldata7)、[createUriData()](#pasteboardcreateuridata7)、[createWantData()](#pasteboardcreatewantdata7)或[getPasteData()](#getpastedata)获取一个PasteData对象。

**系统能力：** SystemCapability.MiscServices.Pasteboard


### getPrimaryText<sup>6+</sup>


getPrimaryText(): string


获取首个条目的纯文本内容。

**系统能力：** SystemCapability.MiscServices.Pasteboard


**返回值：**

| 类型   | 说明         |
| ------ | ------------ |
| string | 纯文本内容。 |

**示例：**

```js
var pasteData = pasteboard.createPlainTextData("hello");
var plainText = pasteData.getPrimaryText();
```


### getPrimaryHtml<sup>7+</sup>

getPrimaryHtml(): string

获取首个条目的HTML内容。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型   | 说明       |
| ------ | ---------- |
| string | HTML内容。 |

**示例：**

```js
var html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
var pasteData = pasteboard.createHtmlData(html);
var htmlText = pasteData.getPrimaryHtml();
```


### getPrimaryWant<sup>7+</sup>

getPrimaryWant(): Want

获取首个条目的Want对象内容。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型                                | 说明           |
| ----------------------------------- | -------------- |
| [Want](js-apis-featureAbility.md#want) | Want对象内容。 |

**示例：**

```js
var object = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
var pasteData = pasteboard.createWantData(object);
var want = pasteData.getPrimaryWant();
```


### getPrimaryUri<sup>7+</sup>

getPrimaryUri(): string

获取首个条目的URI内容。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型   | 说明      |
| ------ | --------- |
| string | URI内容。 |

**示例：**

```js
var pasteData = pasteboard.createUriData("dataability:///com.example.myapplication1/user.txt");
var uri = pasteData.getPrimaryUri();
```


### addTextRecord<sup>7+</sup>

addTextRecord(text: string): void

向当前剪贴板内容中添加一条纯文本条目，并将MIME_TEXT_PLAIN添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

剪贴板内容中添加的条目达到数量上限128后，后续的添加操作无效。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| text   | string | 是   | 纯文本内容。 |

**示例：**

```js
var pasteData = pasteboard.createPlainTextData("hello");
pasteData.addTextRecord("good");
```


### addHtmlRecord<sup>7+</sup>

addHtmlRecord(htmlText: string): void

向当前剪贴板内容中添加一条HTML内容条目，并将MIMETYPE_TEXT_HTML添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

剪贴板内容中添加的条目达到数量上限128后，后续的添加操作无效。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名   | 类型   | 必填 | 说明       |
| -------- | ------ | ---- | ---------- |
| htmlText | string | 是   | HTML内容。 |

**示例：**

```js
var pasteData = pasteboard.createPlainTextData("hello");
var html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
pasteData.addHtmlRecord(html);
```


### addWantRecord<sup>7+</sup>

addWantRecord(want: Want): void

向当前剪贴板内容中添加一条Want条目，并将MIMETYPE_TEXT_WANT添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

剪贴板内容中添加的条目达到数量上限128后，后续的添加操作无效。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型                                | 必填 | 说明           |
| ------ | ----------------------------------- | ---- | -------------- |
| want   | [Want](js-apis-featureAbility.md#want) | 是   | Want对象内容。 |

**示例：**

```js
var pasteData = pasteboard.createPlainTextData("hello");
var object = {
    bundleName: "com.example.aafwk.test",
    abilityName: "com.example.aafwk.test.TwoAbility"
};
pasteData.addWantRecord(object);
```


### addUriRecord<sup>7+</sup>

addUriRecord(uri: string): void

向当前剪贴板内容中添加一条URI条目，并将MIMETYPE_TEXT_URI添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

剪贴板内容中添加的条目达到数量上限128后，后续的添加操作无效。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型   | 必填 | 说明      |
| ------ | ------ | ---- | --------- |
| uri    | string | 是   | URI内容。 |

**示例：**

```js
var pasteData = pasteboard.createPlainTextData("hello");
pasteData.addUriRecord("dataability:///com.example.myapplication1/user.txt");
```


### addRecord<sup>7+</sup>

addRecord(record: PasteDataRecord): void

向当前剪贴板内容中添加一条条目，同时也会将条目类型添加到[PasteDataProperty](#pastedataproperty7)的mimeTypes中。入参均不能为空，否则添加失败。

剪贴板内容中添加的条目达到数量上限128后，后续的添加操作无效。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型                                 | 必填 | 说明           |
| ------ | ------------------------------------ | ---- | -------------- |
| record | [PasteDataRecord](#pastedatarecord7) | 是   | 待添加的条目。 |

**示例：**

```js
var pasteData = pasteboard.createUriData("dataability:///com.example.myapplication1/user.txt");
var textRecord = pasteboard.createPlainTextRecord("hello");
var html = "<!DOCTYPE html>\n" + "<html>\n" + "<head>\n" + "<meta charset=\"utf-8\">\n" + "<title>HTML-PASTEBOARD_HTML</title>\n" + "</head>\n" + "<body>\n" + "    <h1>HEAD</h1>\n" + "    <p></p>\n" + "</body>\n" + "</html>";
var htmlRecord = pasteboard.createHtmlTextRecord(html);
pasteData.addRecord(textRecord);
pasteData.addRecord(htmlRecord);
```

### getMimeTypes<sup>7+</sup>

getMimeTypes(): Array&lt;string&gt;

获取剪贴板中[PasteDataProperty](#pastedataproperty7)的mimeTypes列表，当剪贴板内容为空时，返回列表为空。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型                | 说明                                         |
| ------------------- | -------------------------------------------- |
| Array&lt;string&gt; | 剪贴板内容条目的数据类型，非重复的类型列表。 |

**示例：**

```js
var pasteData = pasteboard.createPlainTextData("hello");
var types = pasteData.getMimeTypes();
```

### getPrimaryMimeType<sup>7+</sup>

getPrimaryMimeType(): string

获取剪贴板内容中首个条目的数据类型。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| string | 首个条目的数据类型。 |

**示例：**

```js
var pasteData = pasteboard.createPlainTextData("hello");
var type = pasteData.getPrimaryMimeType();
```

### getProperty<sup>7+</sup>

getProperty(): PasteDataProperty

获取剪贴板内容的属性描述对象。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型                                     | 说明           |
| ---------------------------------------- | -------------- |
| [PasteDataProperty](#pastedataproperty7) | 属性描述对象。 |

**示例：**

```js
var pasteData = pasteboard.createPlainTextData("hello");
var property = pasteData.getProperty();
```

### getRecordAt<sup>7+</sup>

getRecordAt(index: number): PasteDataRecord

获取剪贴板内容中指定下标的条目。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| index  | number | 是   | 指定条目的下标。 |

**返回值：**

| 类型                                 | 说明             |
| ------------------------------------ | ---------------- |
| [PasteDataRecord](#pastedatarecord7) | 指定下标的条目。 |

**示例：**

```js
var pasteData = pasteboard.createPlainTextData("hello");
var record = pasteData.getRecordAt(0);
```


### getRecordCount<sup>7+</sup>

getRecordCount(): number

获取剪贴板内容中条目的个数。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型   | 说明         |
| ------ | ------------ |
| number | 条目的个数。 |

**示例：**

```js
var pasteData = pasteboard.createPlainTextData("hello");
var count = pasteData.getRecordCount();
```


### getTag<sup>7+</sup>

getTag(): string

获取剪贴板内容中用户自定义的标签内容，如果没有设置用户自定义的标签内容将返回空。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| string | 返回用户自定义的标签内容，如果没有设置用户自定义的标签内容，将返回空。 |

**示例：**

```js
var pasteData = pasteboard.createPlainTextData("hello");
var tag = pasteData.getTag();
```


### hasMimeType<sup>7+</sup>

hasMimeType(mimeType: string): boolean

检查剪贴板内容中是否有指定的数据类型。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名   | 类型   | 必填 | 说明               |
| -------- | ------ | ---- | ------------------ |
| mimeType | string | 是   | 待查询的数据类型。 |

**返回值：**

| 类型    | 说明                                      |
| ------- | ----------------------------------------- |
| boolean | 有指定的数据类型返回true，否则返回false。 |

**示例：**

```js
var pasteData = pasteboard.createPlainTextData("hello");
var hasType = pasteData.hasMimeType(pasteboard.MIMETYPE_TEXT_PLAIN);
```


### removeRecordAt<sup>7+</sup>

removeRecordAt(index: number): boolean

移除剪贴板内容中指定下标的条目。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型   | 必填 | 说明         |
| ------ | ------ | ---- | ------------ |
| index  | number | 是   | 指定的下标。 |

**返回值：**

| 类型    | 说明                              |
| ------- | --------------------------------- |
| boolean | 成功移除返回true，失败返回false。 |

**示例：**

```js
var pasteData = pasteboard.createPlainTextData("hello");
var isRemove = pasteData.removeRecordAt(0);
```


### replaceRecordAt<sup>7+</sup>

replaceRecordAt(index: number, record: PasteDataRecord): boolean

替换剪贴板内容中指定下标的条目。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型                                 | 必填 | 说明           |
| ------ | ------------------------------------ | ---- | -------------- |
| index  | number                               | 是   | 指定的下标。   |
| record | [PasteDataRecord](#pastedatarecord7) | 是   | 替换后的条目。 |

**返回值：**

| 类型    | 说明                              |
| ------- | --------------------------------- |
| boolean | 成功替换返回true，失败返回false。 |

**示例：**

```js
var pasteData = pasteboard.createPlainTextData("hello");
var record = pasteboard.createUriRecord("dataability:///com.example.myapplication1/user.txt");
var isReplace = pasteData.replaceRecordAt(0, record);
```

## SystemPasteboard

系统剪贴板对象。

在调用SystemPasteboard的接口前，需要先通过[getSystemPasteboard](#pasteboardgetsystempasteboard)获取系统剪贴板。

```js
var systemPasteboard = pasteboard.getSystemPasteboard();
```


### setPasteData<sup>6+</sup>

setPasteData(data:PasteData, callback:AsyncCallback&lt;void&gt;): void

将数据写入系统剪贴板，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                   |
| -------- | ----------------------- | ---- | ------------------------------------------------------ |
| data     | [PasteData](#pastedata) | 是   | PasteData对象。                                        |
| callback | AsyncCallback&lt;void>  | 是   | 回调函数。当写入成功，err为undefined，否则为错误对象。 |

**示例：**

```js
var pasteData = pasteboard.createPlainTextData("content");
var systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setPasteData(pasteData, (err, data) => { 
    if (err) {
        console.error('Failed to set PasteData. Cause: ' + err.message);
        return;
    }
    console.info('Succeeded in setting PasteData.');
});
```


### setPasteData<sup>6+</sup>

setPasteData(data:PasteData): Promise&lt;void&gt;

将数据写入系统剪贴板，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名 | 类型                    | 说明            |
| ------ | ----------------------- | --------------- |
| data   | [PasteData](#pastedata) | PasteData对象。 |

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
var pasteData = pasteboard.createPlainTextData("content");
var systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.setPasteData(pasteData).then((data) => {
    console.info('Succeeded in setting PasteData.');
}).catch((err) => {
    console.error('Failed to set PasteData. Cause: ' + err.message);
});
```


### getPasteData<sup>6+</sup>

getPasteData( callback:AsyncCallback&lt;PasteData&gt;): void

读取系统剪贴板内容，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名   | 类型                                         | 必填 | 说明                                                         |
| -------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;[PasteData](#pastedata)&gt; | 是   | 回调函数。当读取成功，err为undefined，data为返回的系统剪贴板数据；否则返回错误对象。 |

**示例：**

```js
var systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getPasteData((err, pasteData) => {  
    if (err) {
        console.error('Failed to get PasteData. Cause: ' + err.message);
        return;
    }
    var text = pasteData.getPrimaryText();
});
```


### getPasteData<sup>6+</sup>

getPasteData(): Promise&lt;PasteData&gt;

读取系统剪贴板内容，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型                                   | 说明                              |
| -------------------------------------- | --------------------------------- |
| Promise&lt;[PasteData](#pastedata)&gt; | Promise对象，返回系统剪贴板数据。 |

**示例：**

```js
var systemPasteboard = pasteboard.getSystemPasteboard();
systemPasteboard.getPasteData().then((pasteData) => { 
    var text = pasteData.getPrimaryText();
}).catch((err) => {
    console.error('Failed to get PasteData. Cause: ' + err.message);
})
```


### on('update')<sup>7+</sup>

on(type:  'update', callback: () =&gt;void ): void

订阅系统剪贴板内容变化事件，当系统剪贴板中内容变化时触发用户程序的回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名   | 类型     | 必填 | 说明                                         |
| -------- | -------- | ---- | -------------------------------------------- |
| type     | string   | 是   | 取值为'update'，表示系统剪贴板内容变化事件。 |
| callback | function | 是   | 剪贴板中内容变化时触发的用户程序的回调。     |

**示例：**

```js
var systemPasteboard = pasteboard.getSystemPasteboard();
var listener = () => {
    console.info('The system pasteboard has changed.');
};
systemPasteboard.on('update', listener);
```


### off('update')<sup>7+</sup>

off(type:  'update', callback?: () =&gt;void ): void

取消订阅系统剪贴板内容变化事件。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名   | 类型     | 必填 | 说明                                                       |
| -------- | -------- | ---- |----------------------------------------------------------|
| type     | string   | 是   | 取值为'update'，表示系统剪贴板内容变化事件。                               |
| callback | function | 否   | 剪贴板中内容变化时触发的用户程序的回调。如果此参数未填，表明清除本应用的所有监听回调，否则表示清除指定监听回调。 |

**示例：**

```js
let listener = () => {
    console.info('The system pasteboard has changed.');
};    
systemPasteboard.off('update', listener);
```


### hasPasteData<sup>7+</sup>

hasPasteData(callback:  AsyncCallback&lt;boolean&gt;): void

判断系统剪贴板中是否有内容，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名   | 类型                         | 必填 | 说明                                                         |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | 是   | 返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |

**示例：**

```js
systemPasteboard.hasPasteData((err, data) => {
    if (err) {
        console.error('Failed to check the PasteData. Cause: ' + JSON.stringify(err));
        return;
    }
    console.info('Succeeded in checking the PasteData. Data: ' + JSON.stringify(data));
});
```


### hasPasteData<sup>7+</sup>

hasPasteData():  Promise&lt;boolean&gt;

判断系统剪贴板中是否有内容，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型                   | 说明                                                         |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | 返回true表示系统剪贴板中有内容，返回false表示系统剪贴板中没有内容。 |

**示例：**

```js
systemPasteboard.hasPasteData().then((data) => { 
    console.info('Succeeded in checking the PasteData. Data: ' + JSON.stringify(data));
}).catch((err) => {
    console.error('Failed to check the PasteData. Cause: ' + JSON.stringify(err));
});
```


### clear<sup>7+</sup>

clear(callback:  AsyncCallback&lt;void&gt;): void

清空系统剪贴板内容，使用callback异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**参数：**

| 参数名   | 类型                      | 必填 | 说明                                                     |
| -------- | ------------------------- | ---- | -------------------------------------------------------- |
| callback | AsyncCallback&lt;void&gt; | 是   | 回调函数。当成功清空时，err为undefined；否则为错误对象。 |

**示例：**

```js
systemPasteboard.clear((err, data) => { 
    if (err) {        
        console.error('Failed to clear the PasteData. Cause: ' + JSON.stringify(err));        
        return;    
    }
    console.info('Succeeded in clearing the PasteData.');
});
```


### clear<sup>7+</sup>

clear():  Promise&lt;void&gt;

清空系统剪贴板内容，使用Promise异步回调。

**系统能力：** SystemCapability.MiscServices.Pasteboard

**返回值：**

| 类型                | 说明                      |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | 无返回结果的Promise对象。 |

**示例：**

```js
systemPasteboard.clear().then((data) => {
    console.info('Succeeded in clearing the PasteData.');
}).catch((err) => {
    console.error('Failed to clear the PasteData. Cause: ' + JSON.stringify(err));
});
```