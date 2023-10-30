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
| buffer   | ArrayBuffer \| DataView | Yes  | **ArrayBuffer** or **DataView** for storing the XML information to set.|
| encoding | string                            | No  | Encoding format. The default value is **'utf-8'** (the only format currently supported).              |

**Example**

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

Sets an attribute.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description           |
| ------ | ------ | ---- | --------------- |
| name   | string | Yes  | Key of the attribute.  |
| value  | string | Yes  | Value of the attribute.|

**Example**

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

Adds an empty element.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| name   | string | Yes  | Name of the empty element to add.|

**Example**

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

Sets a declaration.

**System capability**: SystemCapability.Utils.Lang

**Example**

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

Writes the start tag based on the given element name.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description              |
| ------ | ------ | ---- | ------------------ |
| name   | string | Yes  | Name of the element.|

**Example**

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

Writes the end tag of the element.

**System capability**: SystemCapability.Utils.Lang

**Example**

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

Sets the namespace for an element tag.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                          |
| --------- | ------ | ---- | ------------------------------ |
| prefix    | string | Yes  | Prefix of the element and its child elements.    |
| namespace | string | Yes  | Namespace to set.|

**Example**

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

Sets a comment.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| text   | string | Yes  | Comment to set.|

**Example**

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

Sets CDATA data.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description             |
| ------ | ------ | ---- | ----------------- |
| text   | string | Yes  | CDATA data to set.|

**Example**

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

Sets a tag value.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description            |
| ------ | ------ | ---- | ---------------- |
| text   | string | Yes  | Tag value to set, which is the content of the **text** attribute.|

**Example**

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

Sets a document type.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description               |
| ------ | ------ | ---- | ------------------- |
| text   | string | Yes  | Content of **DocType** to set.|

**Example**

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
let that = new xml.XmlPullParser(arrbuffer.buffer, 'UTF-8');
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

Parses XML information.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type                         | Mandatory| Description                            |
| ------ | ----------------------------- | ---- | -------------------------------- |
| option | [ParseOptions](#parseoptions) | Yes  | Options for controlling and obtaining the parsed information.|

**Example**

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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getDepth() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:0 key:2 value:1 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:3 value:1 key:1 value:0
// Note:
// key indicates the event type, and value indicates the parsing depth. You can learn the specific parsed event based on EVENTTYPE. In this example, key: value means:
// 0(START_DOCUMENT):0 (START_DOCUMENT is being parsed, and the depth is 0), 2(START_TAG):1 (START_TAG is being parsed, and the depth is 1), 10(WHITESPACE):1 (WHITESPACE is being parsed, and the depth is 1), 2(START_TAG):2 (START_TAG is being parsed, and the depth is 2), ...
```


## ParseOptions

Defines the XML parsing options.

**System capability**: SystemCapability.Utils.Lang


| Name                          | Type                                                        | Mandatory| Description                                   |
| ------------------------------ | ------------------------------------------------------------ | ---- | --------------------------------------- |
| supportDoctype                 | boolean                                                      | No  | Whether to ignore the document type. The default value is **false**, indicating that the document type is parsed.|
| ignoreNameSpace                | boolean                                                      | No  | Whether to ignore the namespace. The default value is **false**, indicating that the namespace is parsed.|
| tagValueCallbackFunction       | (name: string, value: string) =&gt; boolean | No  | Callback used to return **tagValue** for parsing the tag and tag value. The default value is **null**, indicating that the tag and tag value are not parsed. |
| attributeValueCallbackFunction | (name: string, value: string) =&gt; boolean | No  | Callback used to return **attributeValue** for parsing the attribute and attribute value. The default value is **null**, indicating that the attribute and attribute value are not parsed.|
| tokenValueCallbackFunction     | (eventType: [EventType](#eventtype), value: [ParseInfo](#parseinfo)) =&gt; boolean | No  | Callback used to return **tokenValue** for parsing the [EventType](#eventtype) and [ParseInfo](#parseinfo) attributes. The default value is **null**, indicating that the **EventType** and **ParseInfo** attribute are not parsed.|

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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getColumnNumber() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:1 key:2 value:77 key:10 value:81 key:2 value:88 key:4 value:93 key:3 value:101 key:10 value:105 key:2 value:111 key:4 value:115 key:3 value:122 key:10 value:126 key:2 value:132 key:4 value:136 key:3 value:143 key:3 value:150 key:1 value:299
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getDepth() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:0 key:2 value:1 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:10 value:1 key:2 value:2 key:4 value:2 key:3 value:2 key:3 value:1 key:1 value:0
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getLineNumber() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:1 key:2 value:1 key:10 value:1 key:2 value:1 key:4 value:1 key:3 value:1 key:10 value:1 key:2 value:1 key:4 value:1 key:3 value:1 key:10 value:1 key:2 value:1 key:4 value:1 key:3 value:1 key:3 value:1 key:1 value:1
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getName() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value: key:2 value:note key:10 value: key:2 value:title key:4 value: key:3 value:title key:10 value: key:2 value:todo key:4 value: key:3 value:todo key:10 value: key:2 value:todo key:4 value: key:3 value:todo key:3 value:note key:1 value:
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getNamespace() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value: key:2 value: key:10 value: key:2 value: key:4 value: key:3 value: key:10 value: key:2 value: key:4 value: key:3 value: key:10 value: key:2 value: key:4 value: key:3 value: key:3 value: key:1 value:
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getPrefix() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value: key:2 value: key:10 value: key:2 value: key:4 value: key:3 value: key:10 value: key:2 value: key:4 value: key:3 value: key:10 value: key:2 value: key:4 value: key:3 value: key:3 value: key:1 value:
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += ' key:' + key + ' value:' + value.getText() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:  key:2 value:  key:10 value:      key:2 value:  key:4 value:Happy  key:3 value:  key:10 value:      key:2 value:  key:4 value:Work  key:3 value:  key:10 value:      key:2 value:  key:4 value:Play  key:3 value:  key:3 value:  key:1 value:
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.isEmptyElementTag() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:false key:2 value:false key:10 value:false key:2 value:false key:4 value:false key:3 value:false key:10 value:false key:2 value:false key:4 value:false key:3 value:false key:10 value:false key:2 value:false key:4 value:false key:3 value:false key:3 value:false key:1 value:false
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.isWhitespace() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:true key:2 value:false key:10 value:true key:2 value:true key:4 value:false key:3 value:true key:10 value:true key:2 value:true key:4 value:false key:3 value:true key:10 value:true key:2 value:true key:4 value:false key:3 value:true key:3 value:true key:1 value:true
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
let that = new xml.XmlPullParser(arrbuffer.buffer);
let str = "";
function func(key: xml.EventType, value: xml.ParseInfo) {
  str += 'key:' + key + ' value:' + value.getAttributeCount() + ' ';
  return true; // Determines whether to continually parse, which is used to continue or terminate parsing.
}
let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func}
that.parse(options);
console.log(str);
// Output:
// key:0 value:0 key:2 value:2 key:10 value:0 key:2 value:0 key:4 value:0 key:3 value:0 key:10 value:0 key:2 value:0 key:4 value:0 key:3 value:0 key:10 value:0 key:2 value:0 key:4 value:0 key:3 value:0 key:3 value:0 key:1 value:0
```

## EventType

Enumerates the event types.

**System capability**: SystemCapability.Utils.Lang

| Name            | Value  | Description                 |
| ---------------- | ---- | --------------------- |
| START_DOCUMENT   | 0    | Start document event.       |
| END_DOCUMENT     | 1    | End document event.       |
| START_TAG        | 2    | Start tag event.       |
| END_TAG          | 3    | End tag event.       |
| TEXT             | 4    | Text event.           |
| CDSECT           | 5    | CDATA section event.          |
| COMMENT          | 6    | XML comment event.        |
| DOCDECL          | 7    | XML document type declaration event.|
| INSTRUCTION      | 8    | XML processing instruction event.|
| ENTITY_REFERENCE | 9    | Entity reference event.       |
| WHITESPACE       | 10   | Whitespace character event.           |
