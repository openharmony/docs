# XML-to-JavaScript Conversion

> **NOTE**
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```
import convertxml from '@ohos.convertxml';
```

## System Capabilities

SystemCapability.Utils.Lang

## ConvertXML


### convert

convert(xml: string, options?: ConvertOptions) : Object

Converts an XML text into a JavaScript object.


- Parameters

  | Name| Type| Mandatory| Description|
  | ------- | --------------------------------- | ---- | ------------------ |
  | xml     | string                            | Yes| XML text to convert.|
  | options | [ConvertOptions](#convertoptions) | No| Settings of the convert operation.|

- Return value

  | Type| Description|
  | ------ | ---------------------------- |
  | string | JavaScript object.|

- Example

  ```
  var xml =
      '<?xml version="1.0" encoding="utf-8"?>' +
      '<note importance="high" logged="true">' +
      '    <title>Happy</title>' +
      '    <todo>Work</todo>' +
      '    <todo>Play</todo>' +
      '</note>';
  var conv = new convertxml.ConvertXML();
  var result1 = conv.convert(xml, {trim: false, ignoreDeclaration: false});
  console.log(result1)
  ```


## ConvertOptions

| Name| Type| Mandatory| Description|
| ----------------- | -------- | ---- | ----------------------------------------------------------- |
| trim              | boolean  | No| Whether to trim the whitespace characters before and after the text. The default value is **false**.|
| ignoreDeclaration | boolean  | No| Whether to ignore the XML declaration. The default value is **false**.|
| ignoreInstruction | boolean  | No| Whether to ignore the XML processing instruction. The default value is **false**.|
| ignoreAttributes  | boolean  | No| Whether to print attributes across multiple lines and indent attributes. The default value is **false**.|
| ignoreComment     | boolean  | No| Whether to ignore element comments. The default value is **false**.|
| ignoreCDATA       | boolean  | No| Whether to ignore the element's CDATA information. The default value is **false**.|
| ignoreDoctype     | boolean  | No| Whether to ignore the element's Doctype information. The default value is **false**.|
| ignoreText        | boolean  | No| Whether to ignore the element's text information. The default value is **false**.|
| declarationKey    | string   | No| Name of the attribute key for **declaration** in the output object. The default value is **_declaration**.|
| instructionKey    | string   | No| Name of the attribute key for **instruction** in the output object. The default value is **_instruction**.|
| attributesKey     | string   | No| Name of the attribute key for **attributes** in the output object. The default value is **_attributes**.|
| textKey           | string   | No| Name of the attribute key for **text** in the output object. The default value is **_text**.|
| cdataKey          | string   | No| Name of the attribute key for **CDATA** in the output object. The default value is **_cdata**.|
| doctypeKey        | string   | No| Name of the attribute key for **Doctype** in the output object. The default value is **_doctype**.|
| commentKey        | string   | No| Name of the attribute key for **comment** in the output object. The default value is **_comment**.|
| parentKey         | string   | No| Name of the attribute key for **parent** in the output object. The default value is **_parent**.|
| typeKey           | string   | No| Name of the attribute key for **type** in the output object. The default value is **_type**.|
| nameKey           | string   | No| Name of the attribute key for **name** in the output object. The default value is **_name**.|
| elementsKey       | string   | No| Name of the attribute key for **elements** in the output object. The default value is **_elements**.|
