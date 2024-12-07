# XML Generation


XML can be used as a data exchange format, which is supported by a wealth of systems and applications. For example, web services can transfer structured data in XML format.


XML can also be used as a message passing format for communication between nodes in a distributed system.


## Precautions

- XML tags must appear in pairs: one start tag and one end tag.

- XML tags are case sensitive. The start tag and end tag must use the same case.


## How to Develop

The **xml** module provides the **XmlSerializer** class to generate XML files. The input is an object of the ArrayBuffer or DataView type with a fixed length, which is used to store the output XML data.

You can call different methods to write different types of content. For example, call **startElement(name: string)** to write a start tag and **setText(text: string)** to write a tag value. 

For details about the APIs of the **XML** module, see [@ohos.xml (XML Parsing and Generation)](../reference/apis-arkts/js-apis-xml.md).<br>To generate an XML file, proceed as follows:

1. Import the modules.

   ```ts
   import { xml, util } from '@kit.ArkTS';
   ```

2. Create a buffer and construct an **XmlSerializer** object, either based on an object of the ArrayBuffer or DataView type.

   ```ts
   // Method 1: Create an XmlSerializer object based on an object of the ArrayBuffer type.
   let arrayBuffer: ArrayBuffer = new ArrayBuffer(2048); // Create a 2048-byte object of the ArrayBuffer type.
   let thatSer: xml.XmlSerializer = new xml.XmlSerializer(arrayBuffer); // Create an XmlSerializer object based on the object of the ArrayBuffer type.

   // Method 2: Create an XmlSerializer object based on an object of the DataView type.
   // let arrayBuffer: ArrayBuffer = new ArrayBuffer(2048); 
   // let dataView: DataView = new DataView(arrayBuffer); 
   // let thatSer: xml.XmlSerializer = new xml.XmlSerializer(dataView); 
   ```

3. Call the functions to generate an XML file.

   ```ts
   thatSer.setDeclaration(); // Write the XML file declaration.
   thatSer.startElement('bookstore'); // Write the start tag of an element.
   thatSer.startElement('book'); // Write the start tag of a nested element.
   thatSer.setAttributes('category', 'COOKING'); // Write the attributes and attribute values.
   thatSer.startElement('title');
   thatSer.setAttributes('lang', 'en');
   thatSer.setText('Everyday'); // Write the tag value.
   thatSer.endElement(); // Write the end flag.
   thatSer.startElement('author');
   thatSer.setText('Giana');
   thatSer.endElement();
   thatSer.startElement('year');
   thatSer.setText('2005');
   thatSer.endElement();
   thatSer.endElement();
   thatSer.endElement();
   ```

4. Use **Uint8Array** to operate the object of the ArrayBuffer type, and use **TextDecoder** to decode the Uint8Array.

   ```ts
   let view: Uint8Array = new Uint8Array(arrayBuffer); // Use Uint8Array to read data from the object of the ArrayBuffer type.
   let textDecoder: util.TextDecoder = util.TextDecoder.create(); // Call the TextDecoder class of the util module.
   let res: string = textDecoder.decodeToString(view); // Decode the view.
   console.info(res);
   ```

   The output is as follows:

   ```
   <?xml version=\"1.0\" encoding=\"utf-8\"?><bookstore>\r\n  <book category=\"COOKING\">\r\n    <title lang=\"en\">Everyday</title>\r\n    <author>Giana</author>\r\n    <year>2005</year>\r\n  </book>\r\n</bookstore>
   ```
