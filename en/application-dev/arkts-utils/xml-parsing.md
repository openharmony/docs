# XML Parsing


When using XML as a data carrier, it is necessary to parse relevant nodes in practice. This typically includes three types of operations: [parsing XML tags and their values](#parsing-xml-tags-and-values), [parsing XML attributes and their values](#parsing-xml-attributes-and-values), and [parsing XML event types and element depths](#parsing-xml-event-types-and-element-depths). For example, in web services, XML is the foundation of the Simple Object Access Protocol (SOAP). SOAP messages, which are usually encapsulated in XML format and contain request and response parameters, are parsed by web services to process client requests and generate corresponding responses.


The XML module provides the **XmlPullParser** class to parse XML documents. The input is an ArrayBuffer or DataView containing XML text, and the output is the parsed information.

**Table 1** XML parsing options (see [ParseOptions](../reference/apis-arkts/js-apis-xml.md#parseoptions) for detailed descriptions)

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| supportDoctype | boolean | No| Whether to ignore the document type. The default value is **false**, indicating that the document type is not parsed.|
| ignoreNameSpace | boolean | No| Whether to ignore the namespace. The default value is **false**, indicating that the namespace is parsed.|
| tagValueCallbackFunction | (name: string, value: string) =&gt; boolean | No| Callback used to return **tagValue**, which consists of a tag and its value. The default value is **null**, indicating that XML tags and values are not parsed.|
| attributeValueCallbackFunction | (name: string, value: string) =&gt; boolean | No| Callback used to return **attributeValue**, which consists of an attribute and its value. The default value is **null**, indicating that XML attributes and values are not parsed.|
| tokenValueCallbackFunction | (eventType: EventType, value: ParseInfo) =&gt; boolean | No| Callback used to return **tokenValue**, which consists of the event type and the attributes of **parseInfo**. The default value is **null**, indicating that the event type and the attributes of **parseInfo** are not parsed.|


## Precautions

- To ensure successful XML parsing and conversion, the input XML data must comply with the standard format.

- Currently, parsing a given node is not supported.


## Parsing XML Tags and Values

1. Import the module.

    ```ts
    import { xml, util } from '@kit.ArkTS'; // Use the API provided by the util module to encode the file.
    ```

2. Create an XmlPullParser object.

   You can construct an XmlPullParser object based on ArrayBuffer or DataView. Both methods yield the same results.

    ```ts
    let strXml: string =
    '<?xml version="1.0" encoding="utf-8"?>' +
      '<note importance="high" logged="true">' +
      '<title>Play</title>' +
      '<lens>Work</lens>' +
      '</note>';
    let textEncoder: util.TextEncoder = new util.TextEncoder();
    let arrBuffer: Uint8Array = textEncoder.encodeInto(strXml); // Encode the data to prevent garbled characters.
    // Method 1: Create an XmlPullParser object based on ArrayBuffer.
    let that: xml.XmlPullParser = new xml.XmlPullParser(arrBuffer.buffer as object as ArrayBuffer, 'UTF-8');
   
    // Method 2: Create an XmlPullParser object based on DataView.
    // let dataView: DataView = new DataView(arrBuffer.buffer as object as ArrayBuffer);
    // let that: xml.XmlPullParser = new xml.XmlPullParser(dataView, 'UTF-8');
    ```

3. Customize a callback function. In this example, the callback function directly prints the tags and their values.

    ```ts
    function func(name: string, value: string): boolean {
      if (name == 'note') {
        console.info(name);
      }
      if (value == 'Play' || value == 'Work') {
        console.info('    ' + value);
      }
      if (name == 'title' || name == 'lens') {
        console.info('  ' + name);
      }
      return true; // The value true means to continue parsing, and false means to stop parsing.
    }
    ```

4. Set parsing options and call the **parse()** function.

    ```ts
    let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tagValueCallbackFunction:func};
    that.parse(options);
    ```

	The output is as follows:

	```
	note
	  title
	    Play
	  title
	  lens
	    Work
	  lens
	note
	```




## Parsing XML Attributes and Values

1. Import the module.

    ```ts
    import { xml, util } from '@kit.ArkTS'; // Use the API provided by the util module to encode the file.
    ```

2. Create an XmlPullParser object.

    ```ts
    let strXml: string =
      '<?xml version="1.0" encoding="utf-8"?>' +
        '<note importance="high" logged="true">' +
        '    <title>Play</title>' +
        '    <title>Happy</title>' +
        '    <lens>Work</lens>' +
        '</note>';
    let textEncoder: util.TextEncoder = new util.TextEncoder();
    let arrBuffer: Uint8Array = textEncoder.encodeInto(strXml); // Encode the data to prevent garbled characters.
    let that: xml.XmlPullParser = new xml.XmlPullParser(arrBuffer.buffer as object as ArrayBuffer, 'UTF-8');
    ```

3. Customize a callback function. In this example, the callback function directly prints the attributes and their values.

    ```ts
    let str: string = '';
    function func(name: string, value: string): boolean {
      str += name + ' ' + value + ' ';
      return true; // The value true means to continue parsing, and false means to stop parsing.
    }
    ```

4. Set parsing options and call the **parse()** function.

    ```ts
    let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, attributeValueCallbackFunction:func};
    that.parse(options);
    console.info(str); // Print all attributes and their values at a time.
    ```

   The output is as follows:
   ```
   importance high logged true // Attributes and values of the note node
   ```


## Parsing XML Event Types and Element Depths

1. Import the module.

    ```ts
    import { xml, util } from '@kit.ArkTS'; // Use the API provided by the util module to encode the file.
    ```

2. Create an XmlPullParser object.

    ```ts
    let strXml: string =
      '<?xml version="1.0" encoding="utf-8"?>' +
      '<note importance="high" logged="true">' +
      '<title>Play</title>' +
      '</note>';
    let textEncoder: util.TextEncoder = new util.TextEncoder();
    let arrBuffer: Uint8Array = textEncoder.encodeInto(strXml); // Encode the data to prevent garbled characters.
    let that: xml.XmlPullParser = new xml.XmlPullParser(arrBuffer.buffer as object as ArrayBuffer, 'UTF-8');
    ```

3. Customize a callback function. In this example, the callback function directly prints the event types and element depths.

    ```ts
    let str: string  = '';
    function func(name: xml.EventType, value: xml.ParseInfo): boolean {
      str = name +' ' + value.getDepth(); // getDepth is called to obtain the element depth.
      console.info(str)
      return true; // The value true means to continue parsing, and false means to stop parsing.
    }
    ```

4. Set parsing options and call the **parse()** function.

     ```ts
     let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func};
     that.parse(options);
     ```

   The output is as follows:

	```
	 0 0 // 0: <?xml version="1.0" encoding="utf-8"?>. The event type value of START_DOCUMENT is 0. 0: The depth is 0.
	 2 1 // 2: <note importance="high" logged="true">. The event type value of START_TAG is 2. 1: The depth is 1.
	 2 2 // 2: <title>. The event type value of START_TAG is 2. 2: The depth is 2.
	 4 2 // 4: Play. The event type value of TEXT is 4. 2: The depth is 2.
	 3 2 // 3: </title>. The event type value of END_TAG is 3. 2: The depth is 2.
	 3 1 // 3: </note>. The event type value of END_TAG is 3. 1: The depth is 1 (corresponding to <note>).
	 1 0 // 1: The event type value of END_DOCUMENT is 1. 0: The depth is 0.
	```




## Example Scenario

This example demonstrates how to use all parsing options to parse XML tags, attributes, and event types.


```ts
import { xml, util } from '@kit.ArkTS';

let strXml: string =
  '<?xml version="1.0" encoding="UTF-8"?>' +
    '<book category="COOKING">' +
    '<title lang="en">Everyday</title>' +
    '<author>Giana</author>' +
    '</book>';
let textEncoder: util.TextEncoder = new util.TextEncoder();
let arrBuffer: Uint8Array = textEncoder.encodeInto(strXml);
let that: xml.XmlPullParser = new xml.XmlPullParser(arrBuffer.buffer as object as ArrayBuffer, 'UTF-8');
let str: string = '';

function tagFunc(name: string, value: string): boolean {
  str = name + value;
  console.info('tag-' + str);
  return true;
}

function attFunc(name: string, value: string): boolean {
  str = name + ' ' + value;
  console.info('attri-' + str);
  return true;
}

function tokenFunc(name: xml.EventType, value: xml.ParseInfo): boolean {
  str = name + ' ' + value.getDepth();
  console.info('token-' + str);
  return true;
}

let options: xml.ParseOptions = {
  supportDoctype: true,
  ignoreNameSpace: true,
  tagValueCallbackFunction: tagFunc,
  attributeValueCallbackFunction: attFunc,
  tokenValueCallbackFunction: tokenFunc
};
that.parse(options);
```

The output is as follows:

   ```
   tag-
   token-0 0
   tag-book
   attri-category COOKING
   token-2 1
   tag-title
   attri-lang en
   token-2 2
   tag-Everyday
   token-4 2
   tag-title
   token-3 2
   tag-author
   token-2 2
   tag-Giana
   token-4 2
   tag-author
   token-3 2
   tag-book
   token-3 1
   tag-
   token-1 0
   ```
