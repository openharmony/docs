# xml解析与生成

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import xml from '@ohos.xml';
```

## XmlSerializer


### constructor

constructor(buffer: ArrayBuffer | DataView, encoding?: string)

XmlSerializer的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                             |
| -------- | --------------------------------- | ---- | ------------------------------------------------ |
| buffer   | ArrayBuffer \| DataView | 是   | 用于接收写入xml信息的ArrayBuffer或DataView内存。 |
| encoding | string                            | 否   | 编码格式。                                       |

**示例：**

```js
let arrayBuffer = new ArrayBuffer(1024);
let bufView = new DataView(arrayBuffer);
let thatSer = new xml.XmlSerializer(bufView);
```


### setAttributes

setAttributes(name: string, value: string): void

设置Attributes方法。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明            |
| ------ | ------ | ---- | --------------- |
| name   | string | 是   | 属性的key值。   |
| value  | string | 是   | 属性的value值。 |

**示例：**

```js
let arrayBuffer = new ArrayBuffer(1024);
let bufView = new DataView(arrayBuffer);
let thatSer = new xml.XmlSerializer(bufView);
thatSer.startElement("note");
thatSer.setAttributes("importance", "high"); 
thatSer.endElement(); 
```


### addEmptyElement

addEmptyElement(name: string): void

写入一个空元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| name   | string | 是   | 该空元素的元素名。 |

**示例：**

```js
let arrayBuffer = new ArrayBuffer(1024);
let bufView = new DataView(arrayBuffer);
let thatSer = new xml.XmlSerializer(bufView);
thatSer.addEmptyElement("b"); // => <b/>
```


### setDeclaration

setDeclaration(): void

设置Declaration方法。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```js
let arrayBuffer = new ArrayBuffer(1024);
let bufView = new DataView(arrayBuffer);
let thatSer = new xml.XmlSerializer(bufView);
thatSer.setDeclaration() // => <?xml version="1.0" encoding="utf-8"?>;
```


### startElement

startElement(name: string): void

根据给定名称写入元素开始标记。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明               |
| ------ | ------ | ---- | ------------------ |
| name   | string | 是   | 当前元素的元素名。 |

**示例：**

```js
let arrayBuffer = new ArrayBuffer(1024);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.startElement("notel");
thatSer.endElement();// => '<notel/>';
```


### endElement

endElement(): void

写入元素结束标记。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```js
let arrayBuffer = new ArrayBuffer(1024);
let bufView = new DataView(arrayBuffer);
let thatSer = new xml.XmlSerializer(bufView);
thatSer.setNamespace("h", "https://www.w3.org/TR/html4/");
thatSer.startElement("table");
thatSer.setAttributes("importance", "high");
thatSer.setText("Happy");
thatSer.endElement(); // => <h:table importance="high" xmlns:h="https://www.w3.org/TR/html4/">Happy</h:table>
```


### setNamespace

setNamespace(prefix: string, namespace: string): void

写入当前元素标记的命名空间。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型   | 必填 | 说明                           |
| --------- | ------ | ---- | ------------------------------ |
| prefix    | string | 是   | 当前元素及其子元素的前缀。     |
| namespace | string | 是   | 当前元素及其子元素的命名空间。 |

**示例：**

```js
let arrayBuffer = new ArrayBuffer(1024);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.setDeclaration();
thatSer.setNamespace("h", "https://www.w3.org/TR/html4/");
thatSer.startElement("note");
thatSer.endElement();// = >'<?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="https://www.w3.org/TR/html4/"/>';
```

### setComment

setComment(text: string): void

写入comment属性。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| text   | string | 是   | 当前元素的注释内容。 |

**示例：**

```js
let arrayBuffer = new ArrayBuffer(1024);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.startElement("note");
thatSer.setComment("Hi!");
thatSer.endElement(); // => '<note>\r\n  <!--Hi!-->\r\n</note>';
```


### setCDATA

setCDATA(text: string): void

写入CDATA属性。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明              |
| ------ | ------ | ---- | ----------------- |
| text   | string | 是   | CDATA属性的内容。 |

**示例：**

```js
let arrayBuffer = new ArrayBuffer(1028);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.setCDATA('root SYSTEM') // => '<![CDATA[root SYSTEM]]>';
```


### setText

setText(text: string): void

设置Text方法。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| text   | string | 是   | text属性的内容。 |

**示例：**

```js
let arrayBuffer = new ArrayBuffer(1024);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.startElement("note");
thatSer.setAttributes("importance", "high");
thatSer.setText("Happy1");
thatSer.endElement(); // => '<note importance="high">Happy1</note>';
```


### setDocType

setDocType(text: string): void

写入DocType属性。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                |
| ------ | ------ | ---- | ------------------- |
| text   | string | 是   | DocType属性的内容。 |

**示例：**

```js
let arrayBuffer = new ArrayBuffer(1024);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.setDocType('root SYSTEM'); // => '<!DOCTYPE root SYSTEM>';
```


## XmlPullParser


### XmlPullParser

constructor(buffer: ArrayBuffer | DataView, encoding?: string)

创建并返回一个XmlPullParser对象，该XmlPullParser对象传参两个, 第一参数是ArrayBuffer或DataView类型的一段内存，第二个参数为文件格式（默认为UTF-8）

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                       |
| -------- | --------------------------------- | ---- | ------------------------------------------ |
| buffer   | ArrayBuffer \| DataView | 是   | 含有xml文本信息的ArrayBuffer或者DataView。 |
| encoding | string                            | 否   | 编码格式（仅支持utf-8）。                  |

**示例：**

```js
let strXml =
            '<?xml version="1.0" encoding="utf-8"?>' +
            '<note importance="high" logged="true">' +
            '    <title>Happy</title>' +
            '    <todo>Work</todo>' +
            '    <todo>Play</todo>' +
            '</note>';
let arrayBuffer = new ArrayBuffer(strXml.length);
let bufView = new Uint8Array(arrayBuffer);
let strLen = strXml.length;
for (var i = 0; i < strLen; ++i) {
    bufView[i] = strXml.charCodeAt(i);//设置arraybuffer方式
}
let that = new xml.XmlPullParser(arrayBuffer);
```


### parse

parse(option: ParseOptions): void

该接口用于解析xml。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型                          | 必填 | 说明                             |
| ------ | ----------------------------- | ---- | -------------------------------- |
| option | [ParseOptions](#parseoptions) | 是   | 用户控制以及获取解析信息的选项。 |

**示例：**

```js
let strXml =
            '<?xml version="1.0" encoding="utf-8"?>' +
            '<note importance="high" logged="true">' +
            '    <title>Happy</title>' +
            '    <todo>Work</todo>' +
            '    <todo>Play</todo>' +
            '</note>';
let arrayBuffer = new ArrayBuffer(strXml.length);
let bufView = new Uint8Array(arrayBuffer);
let strLen = strXml.length;
for (var tmp = 0; tmp < strLen; ++tmp) {
    bufView[tmp] = strXml.charCodeAt(tmp);
}
let that = new xml.XmlPullParser(arrayBuffer);
let arrTag = {};
let str = "";
let i = 0;
function func(key, value){
    arrTag[i] = 'key:'+key+' value:'+ value.getDepth();
    str += arrTag[i];
    i++;
    return true; // Determines whether to continuely parse, which is used to continue or terminate parsing.
}
let options = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// 输出:
// key:0 value:0key:2 value:1key:10 value:1key:2 value:2key:4 value:2key:3 value:2key:10 value:1key:2 value:2key:4 value:2key:3 value:2key:10 value:1key:2 value:2key:4 value:2key:3 value:2key:3 value:1key:1 value:0
// 解析:
// key代表了当前事件类型，value为当前解析的深度。你可以根据EVENTTYPE来知道具体的解析事件。例如本示例结果key: value代表含义为:
// 0(START_DOCUMENT):0(起始深度为0), 2(START_TAG):1(解析到开始标签node, 对应深度为1), 10(WHITESPACE):1(解析到空白标签空格, 对应深度为1), 2(START_TAG):2(解析到开始标签title, 对应深度为2), ...
```


## ParseOptions

xml解析选项。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Utils.Lang


| 名称                           | 类型                                                         | 必填 | 说明                                    |
| ------------------------------ | ------------------------------------------------------------ | ---- | --------------------------------------- |
| supportDoctype                 | boolean                                                      | 否   | 是否忽略Doctype , 默认false。 |
| ignoreNameSpace                | boolean                                                      | 否   | 是否忽略NameSpace，默认false。          |
| tagValueCallbackFunction       | (name: string, value: string) =&gt; boolean | 否   | 获取tagValue回调函数。                  |
| attributeValueCallbackFunction | (name: string, value: string) =&gt; boolean | 否   | 获取attributeValue回调函数。            |
| tokenValueCallbackFunction     | (eventType: [EventType](#eventtype), value: [ParseInfo](#parseinfo)) =&gt; boolean | 否   | 获取tokenValue回调函数。                |

## ParseInfo

当前xml解析信息。


### getColumnNumber

getColumnNumber(): number

获取当前列号，从1开始。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| number | 返回当前列号。 |


### getDepth

getDepth(): number

获取元素的当前深度。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 返回元素的当前深度。 |


### getLineNumber

getLineNumber(): number

获取当前行号，从1开始。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| number | 返回当前行号。 |


### getName

getName(): string

获取当前元素名称。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| string | 返回当前元素名称。 |


### getNamespace

getNamespace(): string

获取当前元素的命名空间。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| string | 返回当前元素的命名空间。 |


### getPrefix

getPrefix(): string

获取当前元素前缀。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| string | 返回当前元素前缀。 |


### getText

getText(): string

获取当前事件的文本内容。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| string | 返回当前事件的文本内容。 |


### isEmptyElementTag

isEmptyElementTag(): boolean

判断当前元素是否为空元素。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型    | 说明                         |
| ------- | ---------------------------- |
| boolean | 返回true，当前元素为空元素。 |


### isWhitespace

isWhitespace(): boolean

判断当前文本事件是否仅包含空格字符。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型    | 说明                                   |
| ------- | -------------------------------------- |
| boolean | 返回true，当前文本事件仅包含空格字符。 |


### getAttributeCount

getAttributeCount(): number

获取当前开始标记的属性数。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**
| 类型   | 说明                   |
| ------ | ---------------------- |
| number | 当前开始标记的属性数。 |


## EventType

事件枚举。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Utils.Lang

| 名称             | 值   | 说明                  |
| ---------------- | ---- | --------------------- |
| START_DOCUMENT   | 0    | 启动文件事件。        |
| END_DOCUMENT     | 1    | 结束文件事件。        |
| START_TAG        | 2    | 启动标签事件。        |
| END_TAG          | 3    | 结束标签事件。        |
| TEXT             | 4    | 文本事件。            |
| CDSECT           | 5    | CDATA事件。           |
| COMMENT          | 6    | XML注释事件。         |
| DOCDECL          | 7    | XML文档类型声明事件。 |
| INSTRUCTION      | 8    | XML处理指令声明事件。 |
| ENTITY_REFERENCE | 9    | 实体引用事件。        |
| WHITESPACE       | 10   | 空白事件。            |