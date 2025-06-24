# XML Parsing


When using XML as a data carrier, it is necessary to parse relevant elements in practice. This typically includes three types of operations: [parsing XML tags and their values](#parsing-xml-tags-and-values), [parsing XML attributes and their values](#parsing-xml-attributes-and-values), and [parsing XML event types and element information](#parsing-xml-event-types-and-element-information). For example, in web services, XML is the foundation of the Simple Object Access Protocol (SOAP). SOAP messages, which are usually encapsulated in XML format and contain request and response parameters, are parsed by web services to process client requests and generate corresponding responses.


The XML module provides the **XmlPullParser** class to parse XML text. The input is an ArrayBuffer or a DataView containing XML text, and the output is the parsed information.

**Table 1** XML parsing options (see [ParseOptions](../reference/apis-arkts/js-apis-xml.md#parseoptions) for detailed descriptions)

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| supportDoctype | boolean | No| Whether to parse the document type. The value **true** means to parse the document type, and **false** means the opposite. The default value is **false**.|
| ignoreNameSpace | boolean | No| Whether to ignore the namespace. If the namespace is ignored, it will not be parsed. The value **true** means to ignore the namespace, and **false** means the opposite. The default value is **false**.|
| tagValueCallbackFunction | (name: string, value: string) =&gt; boolean | No| Callback used to return **tagValue**, which consists of a tag and its value. The default value is undefined, indicating that XML tags and their values are not parsed.|
| attributeValueCallbackFunction | (name: string, value: string) =&gt; boolean | No| Callback used to return **attributeValue**, which consists of an attribute and its value. The default value is undefined, indicating that XML attributes and their values are not parsed.|
| tokenValueCallbackFunction | (eventType: EventType, value: ParseInfo) =&gt; boolean | No| Callback used to return **tokenValue**, which consists of the event type and the attributes of **parseInfo**. The default value is undefined, indicating that the XML event type is not parsed.|


## Precautions

- The input XML data must be in the standard format.

- Parsing a given node is not supported yet.


## Parsing XML Tags and Values

1. Import the module.

    ```ts
    import { xml, util } from '@kit.ArkTS'; // Use the API provided by the util module to encode text.
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
    that.parseXml(options);
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
    import { xml, util } from '@kit.ArkTS'; // Use the API provided by the util module to encode text.
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
    that.parseXml(options);
    console.info(str); // Print all attributes and their values at a time.
    ```

   The output is as follows:
   ```
   importance high logged true // Attributes and values of the note node
   ```


## Parsing XML Event Types and Element Information

1. Import the module.

    ```ts
    import { xml, util } from '@kit.ArkTS'; // Use the API provided by the util module to encode text.
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
    let str: string = '';
    function func(name: xml.EventType, value: xml.ParseInfo): boolean {
      str = name +' ' + value.getDepth(); // getDepth is called to obtain the element depth.
      console.info(str);
      return true; // The value true means to continue parsing, and false means to stop parsing.
    }
    ```

4. Set parsing options and call the **parse()** function.

     ```ts
     let options: xml.ParseOptions = {supportDoctype:true, ignoreNameSpace:true, tokenValueCallbackFunction:func};
     that.parseXml(options);
     ```

   The output is as follows:

	```
	 0 0 // First digit 0: <?xml version="1.0" encoding="utf-8"?> corresponds to event type START_DOCUMENT, which value is 0; second digit 0: The depth is 0.
	 2 1 // First digit 2: <note importance="high" logged="true"> corresponds to event type START_TAG, which value is 2; second digit 1: The depth is 1.
	 2 2 // First digit 2: <title> corresponds to event type START_TAG, which value is 2; second digit 2: The depth is 2.
	 4 2 // First digit 4: "Play" corresponds to event type TEXT, which value is 4; second digit 2: The depth is 2.
	 3 2 // First digit 3: </title> corresponds to event type END_TAG, which value is 3; second digit 2: The depth is 2.
	 3 1 // First digit 3: </note> corresponds to event type END_TAG, which value is 3; second digit 1: The depth is 1.
	 1 0 // First digit 1: corresponds to event type END_DOCUMENT, which value is 1; second digit 0: The depth is 0.
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
that.parseXml(options);
```

The output is as follows:

```
tag-
token-0 0
tag-book
token-2 1
attri-category COOKING
tag-title
token-2 2
attri-lang en
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
