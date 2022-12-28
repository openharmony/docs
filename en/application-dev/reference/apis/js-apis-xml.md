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
| encoding | string                            | No  | Encoding format.                                      |

**Example**

```js
let arrayBuffer = new ArrayBuffer(1024);
let bufView = new DataView(arrayBuffer);
let thatSer = new xml.XmlSerializer(bufView);
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
let arrayBuffer = new ArrayBuffer(1024);
let bufView = new DataView(arrayBuffer);
let thatSer = new xml.XmlSerializer(bufView);
thatSer.startElement("note");
thatSer.setAttributes("importance", "high"); 
thatSer.endElement(); 
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
let arrayBuffer = new ArrayBuffer(1024);
let bufView = new DataView(arrayBuffer);
let thatSer = new xml.XmlSerializer(bufView);
thatSer.addEmptyElement("b"); // => <b/>
```


### setDeclaration

setDeclaration(): void

Sets a declaration.

**System capability**: SystemCapability.Utils.Lang

**Example**

```js
let arrayBuffer = new ArrayBuffer(1024);
let bufView = new DataView(arrayBuffer);
let thatSer = new xml.XmlSerializer(bufView);
thatSer.setDeclaration() // => <?xml version="1.0" encoding="utf-8"?>;
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
let arrayBuffer = new ArrayBuffer(1024);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.startElement("notel");
thatSer.endElement();// => '<notel/>';
```


### endElement

endElement(): void

Writes the end tag of the element.

**System capability**: SystemCapability.Utils.Lang

**Example**

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

Sets the namespace for an element tag.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name   | Type  | Mandatory| Description                          |
| --------- | ------ | ---- | ------------------------------ |
| prefix    | string | Yes  | Prefix of the element and its child elements.    |
| namespace | string | Yes  | Namespace to set.|

**Example**

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

Sets the comment.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                |
| ------ | ------ | ---- | -------------------- |
| text   | string | Yes  | Comment to set.|

**Example**

```js
let arrayBuffer = new ArrayBuffer(1024);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.startElement("note");
thatSer.setComment("Hi!");
thatSer.endElement(); // => '<note>\r\n  <!--Hi!-->\r\n</note>';
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
let arrayBuffer = new ArrayBuffer(1028);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.setCDATA('root SYSTEM') // => '<![CDATA[root SYSTEM]]>';
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
let arrayBuffer = new ArrayBuffer(1024);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.startElement("note");
thatSer.setAttributes("importance", "high");
thatSer.setText("Happy1");
thatSer.endElement(); // => '<note importance="high">Happy1</note>';
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
let arrayBuffer = new ArrayBuffer(1024);
let thatSer = new xml.XmlSerializer(arrayBuffer);
thatSer.setDocType('root SYSTEM'); // => '<!DOCTYPE root SYSTEM>';
```


## XmlPullParser


### XmlPullParser

constructor(buffer: ArrayBuffer | DataView, encoding?: string)

Creates and returns an **XmlPullParser** object. The **XmlPullParser** object passes two parameters. The first parameter is the memory of the **ArrayBuffer** or **DataView** type, and the second parameter is the file format (UTF-8 by default).

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type                             | Mandatory| Description                                      |
| -------- | --------------------------------- | ---- | ------------------------------------------ |
| buffer   | ArrayBuffer \| DataView | Yes  | **ArrayBuffer** or **DataView** that contains XML text information.|
| encoding | string                            | No  | Encoding format. Only UTF-8 is supported.                 |

**Example**

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
    bufView[i] = strXml.charCodeAt(i);// Set the ArrayBuffer mode.
}
let that = new xml.XmlPullParser(arrayBuffer);
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
| tagValueCallbackFunction       | (name: string, value: string) =&gt; boolean | No  | Callback used to return **tagValue**.                 |
| attributeValueCallbackFunction | (name: string, value: string) =&gt; boolean | No  | Callback used to return **attributeValue**.           |
| tokenValueCallbackFunction     | (eventType: [EventType](#eventtype), value: [ParseInfo](#parseinfo)) =&gt; boolean | No  | Callback used to return **tokenValue**.               |

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


### getDepth

getDepth(): number

Obtains the depth of this element.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                |
| ------ | -------------------- |
| number | Depth obtained.|


### getLineNumber

getLineNumber(): number

Obtains the current line number, starting from 1.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description          |
| ------ | -------------- |
| number | Line number obtained.|


### getName

getName(): string

Obtains the name of this element.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| string | Element name obtained.|


### getNamespace

getNamespace(): string

Obtains the namespace of this element.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| string | Namespace obtained.|


### getPrefix

getPrefix(): string

Obtains the prefix of this element.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description              |
| ------ | ------------------ |
| string | Element prefix obtained.|


### getText

getText(): string

Obtains the text of the current event.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type  | Description                    |
| ------ | ------------------------ |
| string | Text content obtained.|


### isEmptyElementTag

isEmptyElementTag(): boolean

Checks whether the current element is empty.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                        |
| ------- | ---------------------------- |
| boolean | Returns **true** if the element is empty; returns **false** otherwise.|


### isWhitespace

isWhitespace(): boolean

Checks whether the current text event contains only whitespace characters.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                  |
| ------- | -------------------------------------- |
| boolean | Returns **true** if the text event contains only whitespace characters; returns **false** otherwise.|


### getAttributeCount

getAttributeCount(): number

Obtains the number of attributes for the current start tag.

**System capability**: SystemCapability.Utils.Lang

**Return value**
| Type  | Description                  |
| ------ | ---------------------- |
| number | Number of attributes obtained.|


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
