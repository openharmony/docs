# @ohos.xml (XML Parsing and Generation)

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import xml from '@ohos.xml';
```

## XmlSerializer


### constructor

constructor(buffer: ArrayBuffer | DataView, encoding?: string)

A constructor used to create an **XmlSerializer** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                             | Mandatory| Description                                            |
| -------- | --------------------------------- | ---- | ------------------------------------------------ |
| buffer   | ArrayBuffer \| DataView | Yes  | **ArrayBuffer** or **DataView** for storing the XML information to write.|
| encoding | string                            | No  | Encoding format. The default value is **'utf-8'** (the only format currently supported).              |

**Example**

```js
let arrayBuffer = new ArrayBuffer(2048);
let thatSer = new xml.XmlSerializer(arrayBuffer, "utf-8");
thatSer.setDeclaration();
let result = '<?xml version="1.0" encoding="utf-8"?>';
let view = new Uint8Array(arrayBuffer);
let view1 = "";
for (let i = 0; i < result.length; ++i) {
    view1 = view1 + String.fromCodePoint(view[i]);
}
console.log(view1) //<?xml version="1.0" encoding="utf-8"?>
```


### setAttributes

setAttributes(name: string, value: string): void

Sets an attribute.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| name   | string | Yes  | Key of the attribute.  |
| value  | string | Yes  | Value of the attribute.|

**Example**

```js
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
console.log(view1) //<note importance1="high1"/>
```


### addEmptyElement

addEmptyElement(name: string): void

Adds an empty element.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| name   | string | Yes  | Name of the empty element to add.|

**Example**

```js
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
console.log(view1) //<d/>
```


### setDeclaration

setDeclaration(): void

Sets a declaration.

**System capability**: SystemCapability.Utils.Lang

**Example**

```js
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
console.log(view1) //<?xml version="1.0" encoding="utf-8"?>
```


### startElement

startElement(name: string): void

Writes the start tag based on the given element name.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| name   | string | Yes  | Name of the element.|

**Example**

```js
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
console.log(JSON.stringify(view1)) //<?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>
```

### endElement

endElement(): void

Writes the end tag of the element.

**System capability**: SystemCapability.Utils.Lang

**Example**

```js
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
console.log(JSON.stringify(view1)) //<?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>
```


### setNamespace

setNamespace(prefix: string, namespace: string): void

Sets the namespace for an element tag.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                          |
| --------- | ------ | ---- | ------------------------------ |
| prefix    | string | Yes  | Prefix of the element and its child elements.    |
| namespace | string | Yes  | Namespace to set.|

**Example**

```js
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
console.log(JSON.stringify(view1)) //<?xml version="1.0" encoding="utf-8"?>\r\n<h:note xmlns:h="http://www.w3.org/TR/html4/"/>
```

### setComment

setComment(text: string): void

Sets the comment.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| text   | string | Yes  | Comment to set.|

**Example**

```js
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
console.log(view1) //<!--Hello, World!-->'
```


### setCDATA

setCDATA(text: string): void

Sets CDATA attributes.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description             |
| ------ | ------ | ---- | ----------------- |
| text   | string | Yes  | CDATA attribute to set.|

**Example**

```js
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
console.log(view1) //'<![CDATA[root SYSTEM]]>''
```


### setText

setText(text: string): void

Sets **Text**.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| text   | string | Yes  | Content of the **Text** to set.|

**Example**

```js
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
console.log(view1) // '<note importance="high">Happy1</note>'
```


### setDocType

setDocType(text: string): void

Sets **DocType**.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description               |
| ------ | ------ | ---- | ------------------- |
| text   | string | Yes  | Content of **DocType** to set.|

**Example**

```js
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
console.log(view1) //'<!DOCTYPE root SYSTEM "http://www.test.org/test.dtd">'
```


## XmlPullParser


### constructor

constructor(buffer: ArrayBuffer | DataView, encoding?: string)

Creates and returns an **XmlPullParser** object.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                             | Mandatory| Description                                      |
| -------- | --------------------------------- | ---- | ------------------------------------------ |
| buffer   | ArrayBuffer \| DataView | Yes  | XML text information to be parsed.|
| encoding | string                            | No  | Encoding format. The default value is **'utf-8'** (the only format currently supported).        |

**Example**

```js
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
let that = new xml.XmlPullParser(arrbuffer.buffer, 'UTF-8');
let str1 = '';
function func1(name, value){
    str1 += name+':'+value;
    return true;
}
let options = {supportDoctype:true, ignoreNameSpace:true, tagValueCallbackFunction:func1}
that.parse(options);
console.log(str1) //'note:company:title:title:lens:lens:a:b:h:table:h:tr:h:td:h:td:'
```


### parse

parse(option: ParseOptions): void

Parses XML information.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                         | Mandatory| Description                            |
| ------ | ----------------------------- | ---- | -------------------------------- |
| option | [ParseOptions](#parseoptions) | Yes  | Options for controlling and obtaining the parsed information.|

**Example**

```js
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let arrTag = {};
let str = "";
let i = 0;
function func(key, value){
    arrTag[i] = 'key:'+key+' value:'+ value.getDepth();
    str += arrTag[i];
    i++;
    return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:0key:2 value:1key:10 value:1key:2 value:2key:4 value:2key:3 value:2key:10 value:1key:2 value:2key:4 value:2key:3 value:2key:10 value:1key:2 value:2key:4 value:2key:3 value:2key:3 value:1key:1 value:0
// Note:
// key indicates the event type, and value indicates the parsing depth. You can learn the specific parsed event based on EVENTTYPE. In this example, key: value means:
// 0(START_DOCUMENT):0 (START_DOCUMENT is being parsed, and the depth is 0), 2(START_TAG):1 (START_TAG is being parsed, and the depth is 1), 10(WHITESPACE):1 (WHITESPACE is being parsed, and the depth is 1), 2(START_TAG):2 (START_TAG is being parsed, and the depth is 2), ...
```


## ParseOptions

Defines the XML parsing options.

**System capability**: SystemCapability.Utils.Lang


| Name                          | Type                                                        | Mandatory| Description                                   |
| ------------------------------ | ------------------------------------------------------------ | ---- | --------------------------------------- |
| supportDoctype                 | boolean                                                      | No  | Whether to ignore **Doctype**. The default value is **false**.|
| ignoreNameSpace                | boolean                                                      | No  | Whether to ignore **Namespace**. The default value is **false**.         |
| tagValueCallbackFunction       | (name: string, value: string) =&gt; boolean | No  | Callback used to return **tagValue**. The default value is **null**.                 |
| attributeValueCallbackFunction | (name: string, value: string) =&gt; boolean | No  | Callback used to return **attributeValue**. The default value is **null**.           |
| tokenValueCallbackFunction     | (eventType: [EventType](#eventtype), value: [ParseInfo](#parseinfo)) =&gt; boolean | No  | Callback used to return **tokenValue**. The default value is **null**.    |

## ParseInfo

Provides APIs to manage the parsed XML information.


### getColumnNumber

getColumnNumber(): number

Obtains the column line number, starting from 1.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description          |
| ------ | -------------- |
| number | Column number obtained.|

**Example**

```js
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let arrTag = {};
let str = "";
let i = 0;
function func(key, value){
    arrTag[i] = 'key:'+key+' value:'+ value.getColumnNumber();
    str += arrTag[i];
    i++;
    return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:1key:2 value:77key:10 value:81key:2 value:88key:4 value:93key:3 value:101key:10 value:105key:2 value:111key:4 value:115key:3 value:122key:10 value:126key:2 value:132key:4 value:136key:3 value:143key:3 value:150key:1 value:299
```

### getDepth

getDepth(): number

Obtains the depth of this element.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| number | Depth obtained.|

**Example**

```js
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let arrTag = {};
let str = "";
let i = 0;
function func(key, value){
    arrTag[i] = 'key:'+key+' value:'+ value.getDepth();
    str += arrTag[i];
    i++;
    return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:0key:2 value:1key:10 value:1key:2 value:2key:4 value:2key:3 value:2key:10 value:1key:2 value:2key:4 value:2key:3 value:2key:10 value:1key:2 value:2key:4 value:2key:3 value:2key:3 value:1key:1 value:0
// Note:
// key indicates the event type, and value indicates the parsing depth. You can learn the specific parsed event based on EVENTTYPE. In this example, key: value means:
// 0(START_DOCUMENT):0 (START_DOCUMENT is being parsed, and the depth is 0), 2(START_TAG):1 (START_TAG is being parsed, and the depth is 1), 10(WHITESPACE):1 (WHITESPACE is being parsed, and the depth is 1), 2(START_TAG):2 (START_TAG is being parsed, and the depth is 2), ...
```

### getLineNumber

getLineNumber(): number

Obtains the current line number, starting from 1.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description          |
| ------ | -------------- |
| number | Line number obtained.|

**Example**

```js
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let arrTag = {};
let str = "";
let i = 0;
function func(key, value){
    arrTag[i] = 'key:'+key+' value:'+ value.getLineNumber();
    str += arrTag[i];
    i++;
    return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:1key:2 value:1key:10 value:1key:2 value:1key:4 value:1key:3 value:1key:10 value:1key:2 value:1key:4 value:1key:3 value:1key:10 value:1key:2 value:1key:4 value:1key:3 value:1key:3 value:1key:1 value:1
```

### getName

getName(): string

Obtains the name of this element.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| string | Element name obtained.|

**Example**

```js
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let arrTag = {};
let str = "";
let i = 0;
function func(key, value){
    arrTag[i] = 'key:'+key+' value:'+ value.getName();
    str += arrTag[i];
    i++;
    return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:key:2 value:notekey:10 value:key:2 value:titlekey:4 value:key:3 value:titlekey:10 value:key:2 value:todokey:4 value:key:3 value:todokey:10 value:key:2 value:todokey:4 value:key:3 value:todokey:3 value:notekey:1 value:
```
### getNamespace

getNamespace(): string

Obtains the namespace of this element.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| string | Namespace obtained.|

**Example**

```js
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let arrTag = {};
let str = "";
let i = 0;
function func(key, value){
    arrTag[i] = 'key:'+key+' value:'+ value.getNamespace();
    str += arrTag[i];
    i++;
    return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:key:2 value:key:10 value:key:2 value:key:4 value:key:3 value:key:10 value:key:2 value:key:4 value:key:3 value:key:10 value:key:2 value:key:4 value:key:3 value:key:3 value:key:1 value:
```
### getPrefix

getPrefix(): string

Obtains the prefix of this element.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| string | Element prefix obtained.|

**Example**

```js
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let arrTag = {};
let str = "";
let i = 0;
function func(key, value){
    arrTag[i] = 'key:'+key+' value:'+ value.getPrefix();
    str += arrTag[i];
    i++;
    return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:key:2 value:key:10 value:key:2 value:key:4 value:key:3 value:key:10 value:key:2 value:key:4 value:key:3 value:key:10 value:key:2 value:key:4 value:key:3 value:key:3 value:key:1 value:
```

### getText

getText(): string

Obtains the text of the current event.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| string | Text content obtained.|

**Example**

```js
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let arrTag = {};
let str = "";
let i = 0;
function func(key, value){
    arrTag[i] = 'key:'+key+' value:'+ value.getText();
    str += arrTag[i];
    i++;
    return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:key:2 value:key:10 value:    key:2 value:key:4 value:Happykey:3 value:key:10 value:    key:2 value:key:4 value:Workkey:3 value:key:10 value:    key:2 value:key:4 value:Playkey:3 value:key:3 value:key:1 value:
```
### isEmptyElementTag

isEmptyElementTag(): boolean

Checks whether the current element is empty.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                        |
| ------- | ---------------------------- |
| boolean | Returns **true** if the element is empty; returns **false** otherwise.|

**Example**

```js
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let arrTag = {};
let str = "";
let i = 0;
function func(key, value){
    arrTag[i] = 'key:'+key+' value:'+ value.isEmptyElementTag();
    str += arrTag[i];
    i++;
    return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:falsekey:2 value:falsekey:10 value:falsekey:2 value:falsekey:4 value:falsekey:3 value:falsekey:10 value:falsekey:2 value:falsekey:4 value:falsekey:3 value:falsekey:10 value:falsekey:2 value:falsekey:4 value:falsekey:3 value:falsekey:3 value:falsekey:1 value:false
```
### isWhitespace

isWhitespace(): boolean

Checks whether the current text event contains only whitespace characters.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                  |
| ------- | -------------------------------------- |
| boolean | Returns **true** if the text event contains only whitespace characters; returns **false** otherwise.|

**Example**

```js
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let arrTag = {};
let str = "";
let i = 0;
function func(key, value){
    arrTag[i] = 'key:'+key+' value:'+ value.isWhitespace();
    str += arrTag[i];
    i++;
    return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:truekey:2 value:falsekey:10 value:truekey:2 value:truekey:4 value:falsekey:3 value:truekey:10 value:truekey:2 value:truekey:4 value:falsekey:3 value:truekey:10 value:truekey:2 value:truekey:4 value:falsekey:3 value:truekey:3 value:truekey:1 value:true
```
### getAttributeCount

getAttributeCount(): number

Obtains the number of attributes for the current start tag.

**System capability**: SystemCapability.Utils.Lang

**Return value**
| Type  | Description                  |
| ------ | ---------------------- |
| number | Number of attributes obtained.|

**Example**

```js
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let arrTag = {};
let str = "";
let i = 0;
function func(key, value){
    arrTag[i] = 'key:'+key+' value:'+ value.getAttributeCount();
    str += arrTag[i];
    i++;
    return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:0key:2 value:2key:10 value:0key:2 value:0key:4 value:0key:3 value:0key:10 value:0key:2 value:0key:4 value:0key:3 value:0key:10 value:0key:2 value:0key:4 value:0key:3 value:0key:3 value:0key:1 value:0
```

## EventType

Enumerates the events.

**System capability**: SystemCapability.Utils.Lang

| Name            | Value  | Description                 |
| ---------------- | ---- | --------------------- |
| START_DOCUMENT   | 0    | Indicates a start document event.       |
| END_DOCUMENT     | 1    | Indicates an end document event.       |
| START_TAG        | 2    | Indicates a start tag event.       |
| END_TAG          | 3    | Indicates an end tag event.       |
| TEXT             | 4    | Indicates a text event.           |
| CDSECT           | 5    | Indicates a CDATA section event.          |
| COMMENT          | 6    | Indicates an XML comment event.        |
| DOCDECL          | 7    | Indicates an XML document type declaration event.|
| INSTRUCTION      | 8    | Indicates an XML processing instruction event.|
| ENTITY_REFERENCE | 9    | Indicates an entity reference event.       |
| WHITESPACE       | 10   | Indicates a whitespace character event.           |
