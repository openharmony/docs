# XML Generation
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @yuanyao14-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->


XML is a widely supported data exchange format used by various systems and applications. For example, web services often transmit structured data in XML format.


XML can also serve as a messaging format for communication between nodes in distributed systems.


## Precautions

- XML tags must always appear in pairs: one start tag and one end tag.

- XML tags are case sensitive, meaning that the case of the start and end tags must match.


## How to Develop

The XML module provides the `XmlSerializer` and `XmlDynamicSerializer` classes to generate XML data. When using `XmlSerializer`, you need to pass an `ArrayBuffer` or `DataView` object of a fixed length as the output buffer to store the serialized XML data.
The `XmlDynamicSerializer` class dynamically expands the capacity. The program automatically creates an `ArrayBuffer` based on the size of the generated data.

You can call various methods to write different content. For example, call **startElement(name: string)** to write the start tag of an element and **setText(text: string)** to write the tag value.

For details about the APIs of the XML module, see [@ohos.xml (XML Parsing and Generation)](../reference/apis-arkts/js-apis-xml.md). By calling the appropriate functions as needed, you can generate a complete XML document.

The following is an example of generating an XML document using **XmlSerializer**:

1. Import the module.

   ```ts
   import { xml, util } from '@kit.ArkTS';
   ```

2. Create a buffer and construct an XmlSerializer object, either based on an ArrayBuffer or a DataView object.

   Method 1: Create an XmlSerializer object based on ArrayBuffer.

   ```ts
   let arrayBuffer: ArrayBuffer = new ArrayBuffer(2048); // Create a 2048-byte ArrayBuffer.
   let serializer: xml.XmlSerializer = new xml.XmlSerializer(arrayBuffer); // Create an XmlSerializer object based on the ArrayBuffer.
   ```

   Method 2: Create an XmlSerializer object based on DataView.

   ```ts
   let arrayBuffer: ArrayBuffer = new ArrayBuffer(2048); // Create a 2048-byte ArrayBuffer.
   let dataView: DataView = new DataView(arrayBuffer); // Create a DataView.
   let serializer: xml.XmlSerializer = new xml.XmlSerializer(dataView); // Create an XmlSerializer object based on the object of the DataView type.
   ```

3. Call the functions to generate XML data.

   ```ts
   serializer.setDeclaration(); // Write the XML declaration.
   serializer.startElement('bookstore'); // Write the start tag of an element.
   serializer.startElement('book'); // Write the start tag of a nested element.
   serializer.setAttributes('category', 'COOKING'); // Write attributes and attribute values.
   serializer.startElement('title');
   serializer.setAttributes('lang', 'en');
   serializer.setText('Everyday'); // Write the tag value.
   serializer.endElement(); // Write the end flag.
   serializer.startElement('author');
   serializer.setText('Giana');
   serializer.endElement();
   serializer.startElement('year');
   serializer.setText('2005');
   serializer.endElement();
   serializer.endElement();
   serializer.endElement();
   ```

4. Use **Uint8Array** to manipulate the ArrayBuffer, use **TextDecoder** to decode the Uint8Array, and output it.

   ```ts
   let uint8Array: Uint8Array = new Uint8Array(arrayBuffer); // Use Uint8Array to read data from the ArrayBuffer.
   let textDecoder: util.TextDecoder = util.TextDecoder.create(); // Call the TextDecoder class of the util module.
   let result: string = textDecoder.decodeToString(uint8Array); // Decode the Uint8Array.
   console.info(result);
   ```

   The output is as follows:

   ```
   <?xml version="1.0" encoding="utf-8"?><bookstore>
     <book category="COOKING">
       <title lang="en">Everyday</title>
       <author>Giana</author>
       <year>2005</year>
     </book>
   </bookstore>
   ```

The following is an example of generating an XML document using `XmlDynamicSerializer`:

1. Import the module.

   ```ts
   import { xml, util } from '@kit.ArkTS';
   ```

2. Call the functions to generate XML data.

   ```ts
   let DySerializer = new xml.XmlDynamicSerializer('utf-8');
   DySerializer.setDeclaration(); // Write the XML declaration.
   DySerializer.startElement('bookstore'); // Write the start tag of an element.
   DySerializer.startElement('book'); // Write the start tag of a nested element.
   DySerializer.setAttributes('category', 'COOKING'); // Write attributes and attribute values.
   DySerializer.startElement('title');
   DySerializer.setAttributes('lang', 'en');
   DySerializer.setText('Everyday'); // Write the tag value.
   DySerializer.endElement(); // Write the end flag.
   DySerializer.startElement('author');
   DySerializer.setText('Giana');
   DySerializer.endElement();
   DySerializer.startElement('year');
   DySerializer.setText('2005');
   DySerializer.endElement();
   DySerializer.endElement();
   DySerializer.endElement();
   let arrayBuffer = DySerializer.getOutput();
   ```

4. Use **Uint8Array** to manipulate the ArrayBuffer, use **TextDecoder** to decode the Uint8Array, and output it.

   ```ts
   let uint8Array: Uint8Array = new Uint8Array(arrayBuffer);
   let result: string = util.TextDecoder.create().decodeToString(uint8Array);
   console.info(result);
   ```

   The output is as follows:

   ```
   <?xml version="1.0" encoding="utf-8"?>
   <bookstore>
     <book category="COOKING">
       <title lang="en">Everyday</title>
       <author>Giana</author>
       <year>2005</year>
     </book>
   </bookstore>
   ```
