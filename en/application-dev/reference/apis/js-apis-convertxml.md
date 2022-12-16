# XML-to-JavaScript Conversion

The **convertxml** module provides APIs for converting XML text into JavaScript objects.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import convertxml from '@ohos.convertxml';
```

## ConvertXML

### convertToJSObject<sup>9+</sup>

convertToJSObject(xml: string, options?: ConvertOptions) : Object

Converts an XML text into a JavaScript object.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                             | Mandatory| Description           |
| ------- | --------------------------------- | ---- | --------------- |
| xml     | string                            | Yes  | XML text to convert.|
| options | [ConvertOptions](#convertoptions) | No  | Options for conversion.     |

**Return value**

| Type  | Description                        |
| ------ | ---------------------------- |
| Object | JavaScript object.|

**Example**

```js
let xml =
    '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
let conv = new convertxml.convertToJSObject();
let options = {trim : false, declarationKey:"_declaration",
    instructionKey : "_instruction", attributesKey : "_attributes",
    textKey : "_text", cdataKey:"_cdata", doctypeKey : "_doctype",
    commentKey : "_comment", parentKey : "_parent", typeKey : "_type",
    nameKey : "_name", elementsKey : "_elements"}
let result = JSON.stringify(conv.convert(xml, options));
console.log(result);
// Output (non-compact)
// {"_declaration":{"_attributes":{"version":"1.0","encoding":"utf-8"}},"_elements":[{"_type":"element","_name":"note","_attributes":{"importance":"high","logged":"true"},"_elements":[{"_type":"element","_name":"title","_elements":[{"_type":"text","_text":"Happy"}]},{"_type":"element","_name":"todo","_elements":[{"_type":"text","_text":"Work"}]},{"_type":"element","_name":"todo","_elements":[{"_type":"text","_text":"Play"}]}]}]}
```

### convert<sup>(deprecated)</sup>

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [convertToJSObject9+](#converttojsobject9) instead.

convert(xml: string, options?: ConvertOptions) : Object

Converts an XML text into a JavaScript object.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                             | Mandatory| Description           |
| ------- | --------------------------------- | ---- | --------------- |
| xml     | string                            | Yes  | XML text to convert.|
| options | [ConvertOptions](#convertoptions) | No  | Options for conversion.     |

**Return value**

| Type  | Description                        |
| ------ | ---------------------------- |
| Object | JavaScript object.|

**Example**

```js
let xml =
    '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
let conv = new convertxml.ConvertXML();
let options = {trim : false, declarationKey:"_declaration",
    instructionKey : "_instruction", attributesKey : "_attributes",
    textKey : "_text", cdataKey:"_cdata", doctypeKey : "_doctype",
    commentKey : "_comment", parentKey : "_parent", typeKey : "_type",
    nameKey : "_name", elementsKey : "_elements"}
let result = JSON.stringify(conv.convert(xml, options));
console.log(result);
// Output (non-compact)
// {"_declaration":{"_attributes":{"version":"1.0","encoding":"utf-8"}},"_elements":[{"_type":"element","_name":"note","_attributes":{"importance":"high","logged":"true"},"_elements":[{"_type":"element","_name":"title","_elements":[{"_type":"text","_text":"Happy"}]},{"_type":"element","_name":"todo","_elements":[{"_type":"text","_text":"Work"}]},{"_type":"element","_name":"todo","_elements":[{"_type":"text","_text":"Play"}]}]}]}
```

## ConvertOptions

Options for conversion.

**System capability**: SystemCapability.Utils.Lang

| Name             | Type| Mandatory| Description                                                       |
| ----------------- | -------- | ---- | ----------------------------------------------------------- |
| trim              | boolean  | Yes  | Whether to trim the whitespace characters before and after the text. The default value is **false**.                |
| ignoreDeclaration | boolean  | No  | Whether to ignore the XML declaration. The default value is **false**.                       |
| ignoreInstruction | boolean  | No  | Whether to ignore the XML processing instruction. The default value is **false**.                     |
| ignoreAttributes  | boolean  | No  | Whether to print attributes across multiple lines and indent attributes. The default value is **false**.                  |
| ignoreComment     | boolean  | No  | Whether to ignore element comments. The default value is **false**.                        |
| ignoreCDATA       | boolean  | No  | Whether to ignore the element's CDATA information. The default value is **false**.                       |
| ignoreDoctype     | boolean  | No  | Whether to ignore the element's Doctype information. The default value is **false**.                     |
| ignoreText        | boolean  | No  | Whether to ignore the element's text information. The default value is **false**.                        |
| declarationKey    | string   | Yes  | Name of the attribute key for **declaration** in the output object. The default value is **_declaration**.|
| instructionKey    | string   | Yes  | Name of the attribute key for **instruction** in the output object. The default value is **_instruction**.|
| attributesKey     | string   | Yes  | Name of the attribute key for **attributes** in the output object. The default value is **_attributes**.  |
| textKey           | string   | Yes  | Name of the attribute key for **text** in the output object. The default value is **_text**.              |
| cdataKey          | string   | Yes  | Name of the attribute key for **CDATA** in the output object. The default value is **_cdata**.            |
| doctypeKey        | string   | Yes  | Name of the attribute key for **Doctype** in the output object. The default value is **_doctype**.        |
| commentKey        | string   | Yes  | Name of the attribute key for **comment** in the output object. The default value is **_comment**.        |
| parentKey         | string   | Yes  | Name of the attribute key for **parent** in the output object. The default value is **_parent**.          |
| typeKey           | string   | Yes  | Name of the attribute key for **type** in the output object. The default value is **_type**.              |
| nameKey           | string   | Yes  | Name of the attribute key for **name** in the output object. The default value is **_name**.              |
| elementsKey       | string   | Yes  | Name of the attribute key for **elements** in the output object. The default value is **_elements**.      |
