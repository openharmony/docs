# XML Conversion
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @xliu-huanwei; @shilei123; @huanghello-->
<!--Designer: @yuanyao14-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @ge-yafang-->


Converting XML text into JavaScript objects can simplify data handling and manipulation, making it more suitable for use in JavaScript applications.


The ArkTS common library provides the **ConvertXML** class to convert XML text into JavaScript objects. The input is the XML string to be converted and conversion options, and the output is the resulting JavaScript object. For details about the conversion options, see [@ohos.convertxml (XML-to-JavaScript Conversion)](../reference/apis-arkts/js-apis-convertxml.md).


## Precautions

To ensure successful XML parsing and conversion, the input XML data must comply with the standard format.


## How to Develop

To convert an XML document into a JavaScript object and obtain the tag values, proceed as follows:

1. Import the required module.

   ```ts
   import { convertxml } from '@kit.ArkTS';
   ```

2. Pass in the XML file to be converted and set conversion options. For details about the supported conversion options and their meanings, see [ConvertOptions](../reference/apis-arkts/js-apis-convertxml.md#convertoptions).

   > **NOTE**
   >
   > Ensure that the input XML text complies with the standard format. If the XML text to convert contains the ampersand (&), replace it with the entity reference **\&amp;**.

   ```ts
   let xml: string =
    '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
   let options: convertxml.ConvertOptions = {
     // trim: false, indicating that spaces before and after the text are not deleted after conversion.
     // declarationKey: "_declaration", indicating that _declaration is used to identify the file declaration after conversion.
     // instructionKey: "_instruction", indicating that _instruction is used to identify instructions after conversion.
     // attributesKey: "_attributes", indicating that _attributes is used to identify attributes after conversion.
     // textKey: "_text", indicating that _text is used to identify tag values after conversion.
     // cdataKey: "_cdata", indicating that _cdata is used to identify unparsed data after conversion.
     // docTypeKey: "_doctype", indicating that _doctype is used to identify documents after conversion.
     // commentKey: "_comment", indicating that _comment is used to identify comments after conversion.
     // parentKey: "_parent", indicating that _parent is used to identify parent classes after conversion.
     // typeKey: "_type", indicating that _type is used to identify types after conversion.
     // nameKey: "_name", indicating that _name is used to identify tag names after conversion.
     // elementsKey: "_elements", indicating that _elements is used to identify elements after conversion.
     trim: false,
     declarationKey: "_declaration",
     instructionKey: "_instruction",
     attributesKey: "_attributes",
     textKey: "_text",
     cdataKey: "_cdata",
     doctypeKey: "_doctype",
     commentKey: "_comment",
     parentKey: "_parent",
     typeKey: "_type",
     nameKey: "_name",
     elementsKey: "_elements"
   }
   ```

3. Call the **fastConvertToJSObject** function and print the result.

   ```ts
   let conv: convertxml.ConvertXML = new convertxml.ConvertXML();
   let result: object = conv.fastConvertToJSObject(xml, options);
   let strRes: string = JSON.stringify(result); // Convert the JavaScript object into a JSON string for explicit output.
   console.info(strRes);
   ```

   The output is as follows:

   ```json
   strRes:
   {"_declaration":{"_attributes":{"version":"1.0","encoding":"utf-8"}},"_elements":[{"_type":"element","_name":"note",
    "_attributes":{"importance":"high","logged":"true"},"_elements":[{"_type":"element","_name":"title","_parent":"note",
    "_elements":[{"_type":"text","_text":"Happy"}]},{"_type":"element","_name":"todo","_parent":"note","_elements":
    [{"_type":"text","_text":"Work"}]},{"_type":"element","_name":"todo","_parent":"note","_elements":[{"_type":"text",
    "_text":"Play"}]}]}]}
   ```
