# @ohos.xml (xml解析与生成)

> **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import xml from '@ohos.xml';
```

## XmlSerializer

XmlSerializer接口用于生成XML文件。

### constructor

constructor(buffer: ArrayBuffer | DataView, encoding?: string)

XmlSerializer的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                             |
| -------- | --------------------------------- | ---- | ------------------------------------------------ |
| buffer   | ArrayBuffer \| DataView | 是   | 用于接收写入xml信息的ArrayBuffer或DataView内存。 |
| encoding | string                            | 否   | 编码格式 , 默认'utf-8'(目前仅支持'utf-8')。               |

**示例：**

```ts
let arrayBuffer = new ArrayBuffer(2048);
let thatSer = new xml.XmlSerializer(arrayBuffer, "utf-8");
thatSer.setDeclaration();
let result = '<?xml version="1.0" encoding="utf-8"?>';
let view = new Uint8Array(arrayBuffer);
let view1 = "";
for (let i = 0; i < result.length; ++i) {
    view1 = view1 + String.fromCodePoint(view[i]);
}
console.log(view1) // <?xml version="1.0" encoding="utf-8"?>
```


### setAttributes

setAttributes(name: string, value: string): void

写入元素的属性和属性值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明            |
| ------ | ------ | ---- | --------------- |
| name   | string | 是   | 属性。   |
| value  | string | 是   | 属性值。 |

**示例：**

```ts
const myMAX = 2048;
let arrayBuffer = new ArrayBuffer(myMAX);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.startElement("note");
thatSer.setAttributes("importance1", "high1");
thatSer.endElement();
let result = '<note importance1="high1"/>';
let view = new Uint8Array(arrayBuffer);
let view1 = "";
for (let i = 0; i < result.length; ++i) {
    view1 = view1 + String.fromCodePoint(view[i]);
}
console.log(view1) // <note importance1="high1"/>
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

```ts
const myMAX = 2048;
let arrayBuffer = new ArrayBuffer(myMAX);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.addEmptyElement("d");
let result = '<d/>';
let view = new Uint8Array(arrayBuffer);
let view1 = "";
for (let i = 0; i < result.length; ++i) {
    view1 = view1 + String.fromCodePoint(view[i]);
}
console.log(view1) // <d/>
```


### setDeclaration

setDeclaration(): void

写入XML文件声明。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
const myMAX = 2048;
let arrayBuffer = new ArrayBuffer(myMAX);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.setDeclaration();
thatSer.setNamespace("h", "http://www.w3.org/TR/html4/");
thatSer.startElement("note");
thatSer.endElement();
let result = '<?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>';
let view = new Uint8Array(arrayBuffer);
let view1 = "";
for (let i = 0; i < result.length; ++i) {
    view1 = view1 + String.fromCodePoint(view[i]);
}
console.log(view1)
// <?xml version="1.0" encoding="utf-8"?>
// <h:note xmlns:h="http://www.w3.org/TR/html4/"/>
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

```ts
const myMAX = 2048;
let arrayBuffer = new ArrayBuffer(myMAX);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.setDeclaration();
thatSer.setNamespace("h", "http://www.w3.org/TR/html4/");
thatSer.startElement("note");
thatSer.endElement();
let result = '<?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>';
let view = new Uint8Array(arrayBuffer);
let view1 = "";
for (let i = 0; i < result.length; ++i) {
    view1 = view1 + String.fromCodePoint(view[i]);
}
console.log(JSON.stringify(view1)) // <?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>
```

### endElement

endElement(): void

写入元素结束标记。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
const myMAX = 2048;
let arrayBuffer = new ArrayBuffer(myMAX);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.setDeclaration();
thatSer.setNamespace("h", "http://www.w3.org/TR/html4/");
thatSer.startElement("note");
thatSer.endElement();
let result = '<?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>';
let view = new Uint8Array(arrayBuffer);
let view1 = "";
for (let i = 0; i < result.length; ++i) {
    view1 = view1 + String.fromCodePoint(view[i]);
}
console.log(JSON.stringify(view1)) // <?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>
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

```ts
const myMAX = 2048;
let arrayBuffer = new ArrayBuffer(myMAX);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.setDeclaration();
thatSer.setNamespace("h", "http://www.w3.org/TR/html4/");
thatSer.startElement("note");
thatSer.endElement();
let result = '<?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>';
let view = new Uint8Array(arrayBuffer);
let view1 = "";
for (let i = 0; i < result.length; ++i) {
    view1 = view1 + String.fromCodePoint(view[i]);
}
console.log(JSON.stringify(view1)) // <?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>
```

### setComment

setComment(text: string): void

写入注释内容。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                 |
| ------ | ------ | ---- | -------------------- |
| text   | string | 是   | 当前元素的注释内容。 |

**示例：**

```ts
const myMAX = 2048;
let arrayBuffer = new ArrayBuffer(myMAX);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.setComment("Hello, World!");
let result = '<!--Hello, World!-->';
let view = new Uint8Array(arrayBuffer);
let view1 = "";
for (let i = 0; i < result.length; ++i) {
    view1 = view1 + String.fromCodePoint(view[i]);
}
console.log(view1) // <!--Hello, World!-->
```


### setCDATA

setCDATA(text: string): void

写入CDATA数据。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明              |
| ------ | ------ | ---- | ----------------- |
| text   | string | 是   | CDATA属性的内容。 |

**示例：**

```ts
const myMAX = 2048;
let arrayBuffer = new ArrayBuffer(myMAX);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.setCDATA('root SYSTEM')
let result = '<![CDATA[root SYSTEM]]>';
let view = new Uint8Array(arrayBuffer);
let view1 = "";
for (let i = 0; i < result.length; ++i) {
    view1 = view1 + String.fromCodePoint(view[i]);
}
console.log(view1) // <![CDATA[root SYSTEM]]>
```


### setText

setText(text: string): void

写入标签值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| text   | string | 是   | text属性的内容。 |

**示例：**

```ts
const myMAX = 2048;
let arrayBuffer = new ArrayBuffer(myMAX);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.startElement("note");
thatSer.setAttributes("importance", "high");
thatSer.setText("Happy1");
thatSer.endElement();
let result = '<note importance="high">Happy1</note>';
let view = new Uint8Array(arrayBuffer);
let view1 = "";
for (let i = 0; i < result.length; ++i) {
    view1 = view1 + String.fromCodePoint(view[i]);
}
console.log(view1) // <note importance="high">Happy1</note>
```


### setDocType

setDocType(text: string): void

写入文档类型。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                |
| ------ | ------ | ---- | ------------------- |
| text   | string | 是   | DocType属性的内容。 |

**示例：**

```ts
const myMAX = 2048;
let arrayBuffer = new ArrayBuffer(myMAX);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.setDocType('root SYSTEM "http://www.test.org/test.dtd"');
let result = '<!DOCTYPE root SYSTEM "http://www.test.org/test.dtd">';
let view = new Uint8Array(arrayBuffer);
let view1 = "";
for (let i = 0; i < result.length; ++i) {
    view1 = view1 + String.fromCodePoint(view[i]);
}
console.log(view1) // <!DOCTYPE root SYSTEM "http://www.test.org/test.dtd">
```


## XmlPullParser

XmlPullParser接口用于解析现有的XML文件。

### constructor

constructor(buffer: ArrayBuffer | DataView, encoding?: string)

构造并返回一个XmlPullParser对象。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                       |
| -------- | --------------------------------- | ---- | ------------------------------------------ |
| buffer   | ArrayBuffer \| DataView | 是   | 需要解析的xml文本信息。 |
| encoding | string                            | 否   | 编码格式 , 默认'utf-8'(目前仅支持'utf-8')。         |

**示例：**

```ts
import util from '@ohos.util';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
    '<!DOCTYPE note [\n<!ENTITY foo "baa">]>' +
    '<note importance="high" logged="true">' +
    '    <![CDATA[\r\nfuncrion matchwo(a,6)\r\n{\r\nreturn 1;\r\n}\r\n]]>' +
    '    <!--Hello, World!-->' +
    '    <company>John &amp; Hans</company>' +
    '    <title>Happy</title>' +
    '    <title>Happy</title>' +
    '    <lens>Work</lens>' +
    '    <lens>Play</lens>' +
    '    <?go there?>' +
    '    <a><b/></a>' +
    '    <h:table xmlns:h="http://www.w3.org/TR/html4/">' +
    '        <h:tr>' +
    '            <h:td>Apples</h:td>' +
    '            <h:td>Bananas</h:td>' +
    '        </h:tr>' +
    '    </h:table>' +
    '</note>';
let textEncoder = new util.TextEncoder();
let arrbuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrbuffer.buffer as object as ArrayBuffer, 'UTF-8');
let str1 = '';
function func1(name: string, value: string) {
  str1 += name + value;
  return true;
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tagValueCallbackFunction:func1}
that.parse(options);
console.log(str1)
//   note [<!ENTITY foo "baa">]note    funcrion matchwo(a,6){return 1;}    Hello, World!    companyJohn amp;amp; Hanscompany    titleHappytitle    titleHappytitle    lensWorklens    lensPlaylens    go there    abba    h:table        h:tr            h:tdApplesh:td            h:tdBananash:td        h:tr    h:tablenote
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

```ts
import util from '@ohos.util';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
let textEncoder = new util.TextEncoder();
let arrbuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrbuffer.buffer as object as ArrayBuffer );
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getDepth() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// 输出:
// key:0 value:0 key:2 value:1 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:3 value:1 key:1 value:0
// 解析:
// key代表了当前事件类型，value为当前解析的深度。你可以根据EVENTTYPE来知道具体的解析事件。例如本示例结果key: value代表含义为:
// 0(START_DOCUMENT):0(起始深度为0), 2(START_TAG):1(解析到开始标签node, 对应深度为1), 10(WHITESPACE):1(解析到空白标签空格, 对应深度为1), 2(START_TAG):2(解析到开始标签title, 对应深度为2), ...
```


## ParseOptions

xml解析选项。

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Utils.Lang


| 名称                           | 类型                                                         | 必填 | 说明                                    |
| ------------------------------ | ------------------------------------------------------------ | ---- | --------------------------------------- |
| supportDoctype                 | boolean                                                      | 否   | 是否忽略文档类型，默认false，表示解析文档类型。 |
| ignoreNameSpace                | boolean                                                      | 否   | 是否忽略命名空间，默认false，表示解析命名空间。 |
| tagValueCallbackFunction       | (name: string, value: string) =&gt; boolean | 否   | 获取tagValue回调函数，解析标签和标签值，默认null，表示不解析标签和标签值。  |
| attributeValueCallbackFunction | (name: string, value: string) =&gt; boolean | 否   | 获取attributeValue回调函数，解析属性和属性值，默认null，表示不解析属性和属性值。|
| tokenValueCallbackFunction     | (eventType: [EventType](#eventtype), value: [ParseInfo](#parseinfo)) =&gt; boolean | 否   | 获取tokenValue回调函数,，解析元素事件类型([EventType](#eventtype))和[ParseInfo](#parseinfo)属性，默认null，表示不解析元素事件类型和ParseInfo属性。|

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

**示例：**

```ts
import util from '@ohos.util';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
let textEncoder = new util.TextEncoder();
let arrbuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrbuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getColumnNumber() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// 输出:
// key:0 value:1 key:2 value:77 key:10 value:81 key:2 value:88 key:4 value:93 key:3 value:101 key:10 value:105 key:2 value:111 key:4 value:115 key:3 value:122 key:10 value:126 key:2 value:132 key:4 value:136 key:3 value:143 key:3 value:150 key:1 value:299
```

### getDepth

getDepth(): number

获取元素的当前深度。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                 |
| ------ | -------------------- |
| number | 返回元素的当前深度。 |

**示例：**

```ts
import util from '@ohos.util';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
let textEncoder = new util.TextEncoder();
let arrbuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrbuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getDepth() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// 输出:
// key:0 value:0 key:2 value:1 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:3 value:1 key:1 value:0
// 解析:
// key代表了当前事件类型，value为当前解析的深度。你可以根据EVENTTYPE来知道具体的解析事件。例如本示例结果key: value代表含义为:
// 0(START_DOCUMENT):0(起始深度为0), 2(START_TAG):1(解析到开始标签node, 对应深度为1), 10(WHITESPACE):1(解析到空白标签空格, 对应深度为1), 2(START_TAG):2(解析到开始标签title, 对应深度为2), ...
```

### getLineNumber

getLineNumber(): number

获取当前行号，从1开始。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| number | 返回当前行号。 |

**示例：**

```ts
import util from '@ohos.util';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
let textEncoder = new util.TextEncoder();
let arrbuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrbuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getLineNumber() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// 输出:
// key:0 value:1 key:2 value:1 key:10 value:1 key:2 value:1 key:4 value:1 key:3 value:1 key:10 value:1 key:2 value:1 key:4 value:1 key:3 value:1 key:10 value:1 key:2 value:1 key:4 value:1 key:3 value:1 key:3 value:1 key:1 value:1
```

### getName

getName(): string

获取当前元素名称。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| string | 返回当前元素名称。 |

**示例：**

```ts
import util from '@ohos.util';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
let textEncoder = new util.TextEncoder();
let arrbuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrbuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getName() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// 输出:
// key:0 value: key:2 value:note key:10 value: key:2 value:title key:4 value: key:3 value:title key:10 value: key:2 value:todo key:4 value: key:3 value:todo key:10 value: key:2 value:todo key:4 value: key:3 value:todo key:3 value:note key:1 value:
```
### getNamespace

getNamespace(): string

获取当前元素的命名空间。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| string | 返回当前元素的命名空间。 |

**示例：**

```ts
import util from '@ohos.util';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
let textEncoder = new util.TextEncoder();
let arrbuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrbuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getNamespace() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// 输出:
// key:0 value: key:2 value: key:10 value: key:2 value: key:4 value: key:3 value: key:10 value: key:2 value: key:4 value: key:3 value: key:10 value: key:2 value: key:4 value: key:3 value: key:3 value: key:1 value:
```
### getPrefix

getPrefix(): string

获取当前元素前缀。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| string | 返回当前元素前缀。 |

**示例：**

```ts
import util from '@ohos.util';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
let textEncoder = new util.TextEncoder();
let arrbuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrbuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getPrefix() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// 输出:
// key:0 value: key:2 value: key:10 value: key:2 value: key:4 value: key:3 value: key:10 value: key:2 value: key:4 value: key:3 value: key:10 value: key:2 value: key:4 value: key:3 value: key:3 value: key:1 value:
```

### getText

getText(): string

获取当前事件的文本内容。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                     |
| ------ | ------------------------ |
| string | 返回当前事件的文本内容。 |

**示例：**

```ts
import util from '@ohos.util';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
let textEncoder = new util.TextEncoder();
let arrbuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrbuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += ' key:' + key + ' value:' + value.getText() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// 输出:
// key:0 value:  key:2 value:  key:10 value:      key:2 value:  key:4 value:Happy  key:3 value:  key:10 value:      key:2 value:  key:4 value:Work  key:3 value:  key:10 value:      key:2 value:  key:4 value:Play  key:3 value:  key:3 value:  key:1 value:
```
### isEmptyElementTag

isEmptyElementTag(): boolean

判断当前元素是否为空元素。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型    | 说明                         |
| ------- | ---------------------------- |
| boolean | 返回true，当前元素为空元素。 |

**示例：**

```ts
import util from '@ohos.util';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
let textEncoder = new util.TextEncoder();
let arrbuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrbuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.isEmptyElementTag() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// 输出:
// key:0 value:false key:2 value:false key:10 value:false key:2 value:false key:4 value:false key:3 value:false key:10 value:false key:2 value:false key:4 value:false key:3 value:false key:10 value:false key:2 value:false key:4 value:false key:3 value:false key:3 value:false key:1 value:false
```
### isWhitespace

isWhitespace(): boolean

判断当前文本事件是否仅包含空格字符。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型    | 说明                                   |
| ------- | -------------------------------------- |
| boolean | 返回true，当前文本事件仅包含空格字符。 |

**示例：**

```ts
import util from '@ohos.util';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
let textEncoder = new util.TextEncoder();
let arrbuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrbuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.isWhitespace() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// 输出:
// key:0 value:true key:2 value:false key:10 value:true key:2 value:true key:4 value:false key:3 value:true key:10 value:true key:2 value:true key:4 value:false key:3 value:true key:10 value:true key:2 value:true key:4 value:false key:3 value:true key:3 value:true key:1 value:true
```
### getAttributeCount

getAttributeCount(): number

获取当前开始标记的属性数。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**
| 类型   | 说明                   |
| ------ | ---------------------- |
| number | 当前开始标记的属性数。 |

**示例：**

```ts
import util from '@ohos.util';

let strXml =
  '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
let textEncoder = new util.TextEncoder();
let arrbuffer = textEncoder.encodeInto(strXml);
let that = new xml.XmlPullParser(arrbuffer.buffer as object as ArrayBuffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getAttributeCount() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// 输出:
// key:0 value:0 key:2 value:2 key:10 value:0 key:2 value:0 key:4 value:0 key:3 value:0 key:10 value:0 key:2 value:0 key:4 value:0 key:3 value:0 key:10 value:0 key:2 value:0 key:4 value:0 key:3 value:0 key:3 value:0 key:1 value:0
```

## EventType

事件类型枚举。

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