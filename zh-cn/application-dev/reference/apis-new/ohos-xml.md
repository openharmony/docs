# @ohos.xml    
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import xml from '@ohos.xml'    
```  
    
## XmlSerializer    
XmlSerializer接口用于生成XML文件。  
 **系统能力:**  SystemCapability.Utils.Lang    
### setAttributes    
写入元素的属性和属性值。  
 **调用形式：**     
- setAttributes(name: string, value: string): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 属性。 |  
| value | string | true | 属性值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
const myMAX = 2048;let arrayBuffer = new ArrayBuffer(myMAX);let thatSer = new xml.XmlSerializer(arrayBuffer);thatSer.startElement("note");thatSer.setAttributes("importance1", "high1");thatSer.endElement();let result = '<note importance1="high1"/>';let view = new Uint8Array(arrayBuffer);let view1 = "";for (let i = 0; i < result.length; ++i) {    view1 = view1 + String.fromCodePoint(view[i]);}console.log(view1) // <note importance1="high1"/>    
```    
  
    
### addEmptyElement    
写入一个空元素。  
 **调用形式：**     
- addEmptyElement(name: string): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 该空元素的元素名。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
const myMAX = 2048;let arrayBuffer = new ArrayBuffer(myMAX);let thatSer = new xml.XmlSerializer(arrayBuffer);thatSer.addEmptyElement("d");let result = '<d/>';let view = new Uint8Array(arrayBuffer);let view1 = "";for (let i = 0; i < result.length; ++i) {    view1 = view1 + String.fromCodePoint(view[i]);}console.log(view1) // <d/>    
```    
  
    
### setDeclaration    
写入XML文件声明。  
 **调用形式：**     
- setDeclaration(): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **示例代码：**   
```ts    
const myMAX = 2048;let arrayBuffer = new ArrayBuffer(myMAX);let thatSer = new xml.XmlSerializer(arrayBuffer);thatSer.setDeclaration();thatSer.setNamespace("h", "http://www.w3.org/TR/html4/");thatSer.startElement("note");thatSer.endElement();let result = '<?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>';let view = new Uint8Array(arrayBuffer);let view1 = "";for (let i = 0; i < result.length; ++i) {    view1 = view1 + String.fromCodePoint(view[i]);}console.log(view1)// <?xml version="1.0" encoding="utf-8"?>// <h:note xmlns:h="http://www.w3.org/TR/html4/"/>    
```    
  
    
### startElement    
根据给定名称写入元素开始标记。  
 **调用形式：**     
- startElement(name: string): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 当前元素的元素名。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
const myMAX = 2048;let arrayBuffer = new ArrayBuffer(myMAX);let thatSer = new xml.XmlSerializer(arrayBuffer);thatSer.setDeclaration();thatSer.setNamespace("h", "http://www.w3.org/TR/html4/");thatSer.startElement("note");thatSer.endElement();let result = '<?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>';let view = new Uint8Array(arrayBuffer);let view1 = "";for (let i = 0; i < result.length; ++i) {    view1 = view1 + String.fromCodePoint(view[i]);}console.log(JSON.stringify(view1)) // <?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>    
```    
  
    
### endElement    
写入元素结束标记。  
 **调用形式：**     
- endElement(): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **示例代码：**   
```ts    
const myMAX = 2048;let arrayBuffer = new ArrayBuffer(myMAX);let thatSer = new xml.XmlSerializer(arrayBuffer);thatSer.setDeclaration();thatSer.setNamespace("h", "http://www.w3.org/TR/html4/");thatSer.startElement("note");thatSer.endElement();let result = '<?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>';let view = new Uint8Array(arrayBuffer);let view1 = "";for (let i = 0; i < result.length; ++i) {    view1 = view1 + String.fromCodePoint(view[i]);}console.log(JSON.stringify(view1)) // <?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>    
```    
  
    
### setNamespace    
写入当前元素标记的命名空间。  
 **调用形式：**     
- setNamespace(prefix: string, namespace: string): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| prefix | string | true | 当前元素及其子元素的前缀。 |  
| namespace | string | true | 当前元素及其子元素的命名空间。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
const myMAX = 2048;let arrayBuffer = new ArrayBuffer(myMAX);let thatSer = new xml.XmlSerializer(arrayBuffer);thatSer.setDeclaration();thatSer.setNamespace("h", "http://www.w3.org/TR/html4/");thatSer.startElement("note");thatSer.endElement();let result = '<?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>';let view = new Uint8Array(arrayBuffer);let view1 = "";for (let i = 0; i < result.length; ++i) {    view1 = view1 + String.fromCodePoint(view[i]);}console.log(JSON.stringify(view1)) // <?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>    
```    
  
    
### setComment    
写入注释内容。  
 **调用形式：**     
- setComment(text: string): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text | string | true | 当前元素的注释内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
const myMAX = 2048;let arrayBuffer = new ArrayBuffer(myMAX);let thatSer = new xml.XmlSerializer(arrayBuffer);thatSer.setComment("Hello, World!");let result = '<!--Hello, World!-->';let view = new Uint8Array(arrayBuffer);let view1 = "";for (let i = 0; i < result.length; ++i) {    view1 = view1 + String.fromCodePoint(view[i]);}console.log(view1) // <!--Hello, World!-->    
```    
  
    
### setCDATA    
写入CDATA数据。  
 **调用形式：**     
- setCDATA(text: string): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text | string | true | CDATA属性的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
const myMAX = 2048;let arrayBuffer = new ArrayBuffer(myMAX);let thatSer = new xml.XmlSerializer(arrayBuffer);thatSer.setCDATA('root SYSTEM')let result = '<![CDATA[root SYSTEM]]>';let view = new Uint8Array(arrayBuffer);let view1 = "";for (let i = 0; i < result.length; ++i) {    view1 = view1 + String.fromCodePoint(view[i]);}console.log(view1) // <![CDATA[root SYSTEM]]>    
```    
  
    
### setText    
写入标签值。  
 **调用形式：**     
- setText(text: string): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text | string | true | text属性的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
const myMAX = 2048;let arrayBuffer = new ArrayBuffer(myMAX);let thatSer = new xml.XmlSerializer(arrayBuffer);thatSer.startElement("note");thatSer.setAttributes("importance", "high");thatSer.setText("Happy1");thatSer.endElement();let result = '<note importance="high">Happy1</note>';let view = new Uint8Array(arrayBuffer);let view1 = "";for (let i = 0; i < result.length; ++i) {    view1 = view1 + String.fromCodePoint(view[i]);}console.log(view1) // <note importance="high">Happy1</note>    
```    
  
    
### setDocType    
写入文档类型。  
 **调用形式：**     
- setDocType(text: string): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| text | string | true | DocType属性的内容。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
const myMAX = 2048;let arrayBuffer = new ArrayBuffer(myMAX);let thatSer = new xml.XmlSerializer(arrayBuffer);thatSer.setDocType('root SYSTEM "http://www.test.org/test.dtd"');let result = '<!DOCTYPE root SYSTEM "http://www.test.org/test.dtd">';let view = new Uint8Array(arrayBuffer);let view1 = "";for (let i = 0; i < result.length; ++i) {    view1 = view1 + String.fromCodePoint(view[i]);}console.log(view1) // <!DOCTYPE root SYSTEM "http://www.test.org/test.dtd">    
```    
  
    
## EventType    
事件类型枚举。    
    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 值 | 说明 |  
| --------| --------| --------|  
| START_DOCUMENT | 0 | 启动文件事件。 |  
| END_DOCUMENT | 1 | 结束文件事件。 |  
| START_TAG | 2 | 启动标签事件。 |  
| END_TAG | 3 | 结束标签事件。 |  
| TEXT | 4 | 文本事件。 |  
| CDSECT | 5 | CDATA事件。 |  
| COMMENT | 6 | XML注释事件。 |  
| DOCDECL | 7 | XML文档类型声明事件。 |  
| INSTRUCTION | 8 | XML处理指令声明事件。 |  
| ENTITY_REFERENCE | 9 | 实体引用事件。 |  
| WHITESPACE | 10 | 空白事件。 |  
    
## ParseInfo    
当前xml解析信息。  
 **系统能力:**  SystemCapability.Utils.Lang    
### getColumnNumber    
获取当前列号，从1开始。  
 **调用形式：**     
- getColumnNumber(): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回当前列号。 |  
    
 **示例代码：**   
```ts    
import util from '@ohos.util';  
let strXml =  '<?xml version="1.0" encoding="utf-8"?>' +    '<note importance="high" logged="true">' +    '    <title>Happy</title>' +    '    <todo>Work</todo>' +    '    <todo>Play</todo>' +    '</note>';let textEncoder = new util.TextEncoder();let arrbuffer = textEncoder.encodeInto(strXml);let that = new xml.XmlPullParser(arrbuffer.buffer);let str = "";function func(key: xml.EventType, value: xml.ParseInfo) {  str += 'key:' + key + ' value:' + value.getColumnNumber() + ' ';  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.}let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}that.parse(options);console.log(str);// 输出:// key:0 value:1 key:2 value:77 key:10 value:81 key:2 value:88 key:4 value:93 key:3 value:101 key:10 value:105 key:2 value:111 key:4 value:115 key:3 value:122 key:10 value:126 key:2 value:132 key:4 value:136 key:3 value:143 key:3 value:150 key:1 value:299    
```    
  
    
### getDepth    
获取元素的当前深度。  
 **调用形式：**     
- getDepth(): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回元素的当前深度。 |  
    
 **示例代码：**   
```ts    
import util from '@ohos.util';  
let strXml =  '<?xml version="1.0" encoding="utf-8"?>' +    '<note importance="high" logged="true">' +    '    <title>Happy</title>' +    '    <todo>Work</todo>' +    '    <todo>Play</todo>' +    '</note>';let textEncoder = new util.TextEncoder();let arrbuffer = textEncoder.encodeInto(strXml);let that = new xml.XmlPullParser(arrbuffer.buffer);let str = "";function func(key: xml.EventType, value: xml.ParseInfo) {  str += 'key:' + key + ' value:' + value.getDepth() + ' ';  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.}let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}that.parse(options);console.log(str);// 输出:// key:0 value:0 key:2 value:1 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:3 value:1 key:1 value:0// 解析:// key代表了当前事件类型，value为当前解析的深度。你可以根据EVENTTYPE来知道具体的解析事件。例如本示例结果key: value代表含义为:// 0(START_DOCUMENT):0(起始深度为0), 2(START_TAG):1(解析到开始标签node, 对应深度为1), 10(WHITESPACE):1(解析到空白标签空格, 对应深度为1), 2(START_TAG):2(解析到开始标签title, 对应深度为2), ...    
```    
  
    
### getLineNumber    
获取当前行号，从1开始。  
 **调用形式：**     
- getLineNumber(): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回当前行号。 |  
    
 **示例代码：**   
```ts    
import util from '@ohos.util';  
let strXml =  '<?xml version="1.0" encoding="utf-8"?>' +    '<note importance="high" logged="true">' +    '    <title>Happy</title>' +    '    <todo>Work</todo>' +    '    <todo>Play</todo>' +    '</note>';let textEncoder = new util.TextEncoder();let arrbuffer = textEncoder.encodeInto(strXml);let that = new xml.XmlPullParser(arrbuffer.buffer);let str = "";function func(key: xml.EventType, value: xml.ParseInfo) {  str += 'key:' + key + ' value:' + value.getLineNumber() + ' ';  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.}let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}that.parse(options);console.log(str);// 输出:// key:0 value:1 key:2 value:1 key:10 value:1 key:2 value:1 key:4 value:1 key:3 value:1 key:10 value:1 key:2 value:1 key:4 value:1 key:3 value:1 key:10 value:1 key:2 value:1 key:4 value:1 key:3 value:1 key:3 value:1 key:1 value:1    
```    
  
    
### getName    
获取当前元素名称。  
 **调用形式：**     
- getName(): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回当前元素名称。 |  
    
 **示例代码：**   
```ts    
import util from '@ohos.util';  
let strXml =  '<?xml version="1.0" encoding="utf-8"?>' +    '<note importance="high" logged="true">' +    '    <title>Happy</title>' +    '    <todo>Work</todo>' +    '    <todo>Play</todo>' +    '</note>';let textEncoder = new util.TextEncoder();let arrbuffer = textEncoder.encodeInto(strXml);let that = new xml.XmlPullParser(arrbuffer.buffer);let str = "";function func(key: xml.EventType, value: xml.ParseInfo) {  str += 'key:' + key + ' value:' + value.getName() + ' ';  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.}let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}that.parse(options);console.log(str);// 输出:// key:0 value: key:2 value:note key:10 value: key:2 value:title key:4 value: key:3 value:title key:10 value: key:2 value:todo key:4 value: key:3 value:todo key:10 value: key:2 value:todo key:4 value: key:3 value:todo key:3 value:note key:1 value:    
```    
  
    
### getNamespace    
获取当前元素的命名空间。  
 **调用形式：**     
- getNamespace(): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回当前元素的命名空间。 |  
    
 **示例代码：**   
```ts    
import util from '@ohos.util';  
let strXml =  '<?xml version="1.0" encoding="utf-8"?>' +    '<note importance="high" logged="true">' +    '    <title>Happy</title>' +    '    <todo>Work</todo>' +    '    <todo>Play</todo>' +    '</note>';let textEncoder = new util.TextEncoder();let arrbuffer = textEncoder.encodeInto(strXml);let that = new xml.XmlPullParser(arrbuffer.buffer);let str = "";function func(key: xml.EventType, value: xml.ParseInfo) {  str += 'key:' + key + ' value:' + value.getNamespace() + ' ';  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.}let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}that.parse(options);console.log(str);// 输出:// key:0 value: key:2 value: key:10 value: key:2 value: key:4 value: key:3 value: key:10 value: key:2 value: key:4 value: key:3 value: key:10 value: key:2 value: key:4 value: key:3 value: key:3 value: key:1 value:    
```    
  
    
### getPrefix    
获取当前元素前缀。  
 **调用形式：**     
- getPrefix(): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回当前元素前缀。 |  
    
 **示例代码：**   
```ts    
import util from '@ohos.util';  
let strXml =  '<?xml version="1.0" encoding="utf-8"?>' +    '<note importance="high" logged="true">' +    '    <title>Happy</title>' +    '    <todo>Work</todo>' +    '    <todo>Play</todo>' +    '</note>';let textEncoder = new util.TextEncoder();let arrbuffer = textEncoder.encodeInto(strXml);let that = new xml.XmlPullParser(arrbuffer.buffer);let str = "";function func(key: xml.EventType, value: xml.ParseInfo) {  str += 'key:' + key + ' value:' + value.getPrefix() + ' ';  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.}let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}that.parse(options);console.log(str);// 输出:// key:0 value: key:2 value: key:10 value: key:2 value: key:4 value: key:3 value: key:10 value: key:2 value: key:4 value: key:3 value: key:10 value: key:2 value: key:4 value: key:3 value: key:3 value: key:1 value:    
```    
  
    
### getText    
获取当前事件的文本内容。  
 **调用形式：**     
- getText(): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回当前事件的文本内容。 |  
    
 **示例代码：**   
```ts    
import util from '@ohos.util';  
let strXml =  '<?xml version="1.0" encoding="utf-8"?>' +    '<note importance="high" logged="true">' +    '    <title>Happy</title>' +    '    <todo>Work</todo>' +    '    <todo>Play</todo>' +    '</note>';let textEncoder = new util.TextEncoder();let arrbuffer = textEncoder.encodeInto(strXml);let that = new xml.XmlPullParser(arrbuffer.buffer);let str = "";function func(key: xml.EventType, value: xml.ParseInfo) {  str += ' key:' + key + ' value:' + value.getText() + ' ';  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.}let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}that.parse(options);console.log(str);// 输出:// key:0 value:  key:2 value:  key:10 value:      key:2 value:  key:4 value:Happy  key:3 value:  key:10 value:      key:2 value:  key:4 value:Work  key:3 value:  key:10 value:      key:2 value:  key:4 value:Play  key:3 value:  key:3 value:  key:1 value:    
```    
  
    
### isEmptyElementTag    
判断当前元素是否为空元素。  
 **调用形式：**     
- isEmptyElementTag(): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true，当前元素为空元素。 |  
    
 **示例代码：**   
```ts    
import util from '@ohos.util';  
let strXml =  '<?xml version="1.0" encoding="utf-8"?>' +    '<note importance="high" logged="true">' +    '    <title>Happy</title>' +    '    <todo>Work</todo>' +    '    <todo>Play</todo>' +    '</note>';let textEncoder = new util.TextEncoder();let arrbuffer = textEncoder.encodeInto(strXml);let that = new xml.XmlPullParser(arrbuffer.buffer);let str = "";function func(key: xml.EventType, value: xml.ParseInfo) {  str += 'key:' + key + ' value:' + value.isEmptyElementTag() + ' ';  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.}let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}that.parse(options);console.log(str);// 输出:// key:0 value:false key:2 value:false key:10 value:false key:2 value:false key:4 value:false key:3 value:false key:10 value:false key:2 value:false key:4 value:false key:3 value:false key:10 value:false key:2 value:false key:4 value:false key:3 value:false key:3 value:false key:1 value:false    
```    
  
    
### isWhitespace    
判断当前文本事件是否仅包含空格字符。  
 **调用形式：**     
- isWhitespace(): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true，当前文本事件仅包含空格字符。 |  
    
 **示例代码：**   
```ts    
import util from '@ohos.util';  
let strXml =  '<?xml version="1.0" encoding="utf-8"?>' +    '<note importance="high" logged="true">' +    '    <title>Happy</title>' +    '    <todo>Work</todo>' +    '    <todo>Play</todo>' +    '</note>';let textEncoder = new util.TextEncoder();let arrbuffer = textEncoder.encodeInto(strXml);let that = new xml.XmlPullParser(arrbuffer.buffer);let str = "";function func(key: xml.EventType, value: xml.ParseInfo) {  str += 'key:' + key + ' value:' + value.isWhitespace() + ' ';  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.}let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}that.parse(options);console.log(str);// 输出:// key:0 value:true key:2 value:false key:10 value:true key:2 value:true key:4 value:false key:3 value:true key:10 value:true key:2 value:true key:4 value:false key:3 value:true key:10 value:true key:2 value:true key:4 value:false key:3 value:true key:3 value:true key:1 value:true    
```    
  
    
### getAttributeCount    
获取当前开始标记的属性数。  
 **调用形式：**     
- getAttributeCount(): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 当前开始标记的属性数。 |  
    
 **示例代码：**   
```ts    
import util from '@ohos.util';  
let strXml =  '<?xml version="1.0" encoding="utf-8"?>' +    '<note importance="high" logged="true">' +    '    <title>Happy</title>' +    '    <todo>Work</todo>' +    '    <todo>Play</todo>' +    '</note>';let textEncoder = new util.TextEncoder();let arrbuffer = textEncoder.encodeInto(strXml);let that = new xml.XmlPullParser(arrbuffer.buffer);let str = "";function func(key: xml.EventType, value: xml.ParseInfo) {  str += 'key:' + key + ' value:' + value.getAttributeCount() + ' ';  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.}let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}that.parse(options);console.log(str);// 输出:// key:0 value:0 key:2 value:2 key:10 value:0 key:2 value:0 key:4 value:0 key:3 value:0 key:10 value:0 key:2 value:0 key:4 value:0 key:3 value:0 key:10 value:0 key:2 value:0 key:4 value:0 key:3 value:0 key:3 value:0 key:1 value:0    
```    
  
    
## ParseOptions    
xml解析选项。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| supportDoctype | boolean | false | false | 是否忽略文档类型，默认false，表示解析文档类型。 |  
| ignoreNameSpace | boolean | false | false | 是否忽略命名空间，默认false，表示解析命名空间。 |  
| tagValueCallbackFunction | (name: string, value: string) => boolean | false | false | 获取tagValue回调函数，解析标签和标签值，默认null，表示不解析标签和标签值。 |  
| attributeValueCallbackFunction | (name: string, value: string) => boolean | false | false | 获取attributeValue回调函数，解析属性和属性值，默认null，表示不解析属性和属性值。 |  
| tokenValueCallbackFunction | (eventType: EventType, value: ParseInfo) => boolean | false | false | 获取tokenValue回调函数,，解析元素事件类型([EventType](#eventtype))和[ParseInfo](#parseinfo)属性，默认null，表示不解析元素事件类型和ParseInfo属性。 |  
    
## XmlPullParser    
XmlPullParser接口用于解析现有的XML文件。  
 **系统能力:**  SystemCapability.Utils.Lang    
### parse    
该接口用于解析xml。  
 **调用形式：**     
- parse(option: ParseOptions): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| option | ParseOptions | true | 用户控制以及获取解析信息的选项。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
import util from '@ohos.util';  
let strXml =  '<?xml version="1.0" encoding="utf-8"?>' +    '<note importance="high" logged="true">' +    '    <title>Happy</title>' +    '    <todo>Work</todo>' +    '    <todo>Play</todo>' +    '</note>';let textEncoder = new util.TextEncoder();let arrbuffer = textEncoder.encodeInto(strXml);let that = new xml.XmlPullParser(arrbuffer.buffer);let str = "";function func(key: xml.EventType, value: xml.ParseInfo) {  str += 'key:' + key + ' value:' + value.getDepth() + ' ';  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.}let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}that.parse(options);console.log(str);// 输出:// key:0 value:0 key:2 value:1 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:3 value:1 key:1 value:0// 解析:// key代表了当前事件类型，value为当前解析的深度。你可以根据EVENTTYPE来知道具体的解析事件。例如本示例结果key: value代表含义为:// 0(START_DOCUMENT):0(起始深度为0), 2(START_TAG):1(解析到开始标签node, 对应深度为1), 10(WHITESPACE):1(解析到空白标签空格, 对应深度为1), 2(START_TAG):2(解析到开始标签title, 对应深度为2), ...    
```    
  
    
 **示例代码：**   
```null    
let arrayBuffer = new ArrayBuffer(2048);let thatSer = new xml.XmlSerializer(arrayBuffer, "utf-8");thatSer.setDeclaration();let result = '<?xml version="1.0" encoding="utf-8"?>';let view = new Uint8Array(arrayBuffer);let view1 = "";for (let i = 0; i < result.length; ++i) {    view1 = view1 + String.fromCodePoint(view[i]);}console.log(view1) // <?xml version="1.0" encoding="utf-8"?>    
```    
  
