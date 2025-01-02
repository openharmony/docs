# @ohos.convertxml (XML-to-JavaScript Conversion)

The **convertxml** module provides APIs for converting XML text into JavaScript objects.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { convertxml } from '@kit.ArkTS';
```

## ConvertXML

### convertToJSObject<sup>9+</sup>

convertToJSObject(xml: string, options?: ConvertOptions) : Object

Converts an XML text into a JavaScript object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                             | Mandatory | Description           |
| ------- | --------------------------------- | ---- | --------------- |
| xml     | string                            | Yes  | XML text to convert. |
| options | [ConvertOptions](#convertoptions) | No  | Options for conversion. The default value is a **ConvertOptions** object, which consists of the default values of the attributes in the object. |

**Return value**

| Type  | Description                        |
| ------ | ---------------------------- |
| Object | JavaScript object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID | Error Message |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200002 | Invalid xml string. |

**Example**

```ts
try {
  let xml =
    '<?xml version="1.0" encoding="utf-8"?>' +
      '<note importance="high" logged="true">' +
      '    <title>Happy</title>' +
      '    <todo>Work</todo>' +
      '    <todo>Play</todo>' +
      '</note>';
  let conv = new convertxml.ConvertXML()
  let options: convertxml.ConvertOptions = {
    trim: false, declarationKey: "_declaration",
    instructionKey: "_instruction", attributesKey: "_attributes",
    textKey: "_text", cdataKey: "_cdata", doctypeKey: "_doctype",
    commentKey: "_comment", parentKey: "_parent", typeKey: "_type",
    nameKey: "_name", elementsKey: "_elements"
  }
  let result = JSON.stringify(conv.convertToJSObject(xml, options));
  console.log(result);
} catch (e) {
  console.log((e as Object).toString());
}
// Output (non-compact)
// {"_declaration":{"_attributes":{"version":"1.0","encoding":"utf-8"}},"_elements":[{"_type":"element","_name":"note","_attributes":{"importance":"high","logged":"true"},"_elements":[{"_type":"element","_name":"title","_elements":[{"_type":"text","_text":"Happy"}]},{"_type":"element","_name":"todo","_elements":[{"_type":"text","_text":"Work"}]},{"_type":"element","_name":"todo","_elements":[{"_type":"text","_text":"Play"}]}]}]}
```

### convert<sup>(deprecated)</sup>

convert(xml: string, options?: ConvertOptions) : Object

Converts an XML text into a JavaScript object.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [convertToJSObject<sup>9+</sup>](#converttojsobject9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name | Type                             | Mandatory | Description           |
| ------- | --------------------------------- | ---- | --------------- |
| xml     | string                            | Yes  | XML text to convert. |
| options | [ConvertOptions](#convertoptions) | No  | Options for conversion. The default value is a **ConvertOptions** object, which consists of the default values of the attributes in the object. |

**Return value**

| Type  | Description                        |
| ------ | ---------------------------- |
| Object | JavaScript object. |

**Example**

```ts
let xml =
  '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
let conv = new convertxml.ConvertXML();
let options: convertxml.ConvertOptions = {trim : false, declarationKey:"_declaration",
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

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

| Name             | Type | Mandatory | Description                                                       |
| ----------------- | -------- | ---- | ----------------------------------------------------------- |
| trim              | boolean  | Yes  | Whether to trim the whitespace characters before and after the text.                |
| ignoreDeclaration | boolean  | No  | Whether to ignore the XML declaration. The default value is **false**.                       |
| ignoreInstruction | boolean  | No  | Whether to ignore the XML processing instruction. The default value is **false**.                     |
| ignoreAttributes  | boolean  | No  | Whether to ignore the element's attribute information. The default value is **false**.                  |
| ignoreComment     | boolean  | No  | Whether to ignore element comments. The default value is **false**.                        |
| ignoreCDATA       | boolean  | No  | Whether to ignore the element's CDATA information. The default value is **false**.                       |
| ignoreDoctype     | boolean  | No  | Whether to ignore the element's Doctype information. The default value is **false**.                     |
| ignoreText        | boolean  | No  | Whether to ignore the element's text information. The default value is **false**.                        |
| declarationKey    | string   | Yes  | Name of the attribute key for **declaration** in the output object. |
| instructionKey    | string   | Yes  | Name of the attribute key for **instruction** in the output object. |
| attributesKey     | string   | Yes  | Name of the attribute key for **attributes** in the output object.  |
| textKey           | string   | Yes  | Name of the attribute key for **text** in the output object.              |
| cdataKey          | string   | Yes  | Name of the attribute key for **cdata** in the output object.            |
| doctypeKey        | string   | Yes  | Name of the attribute key for **doctype** in the output object.        |
| commentKey        | string   | Yes  | Name of the attribute key for **comment** in the output object.        |
| parentKey         | string   | Yes  | Name of the attribute key for **parent** in the output object.          |
| typeKey           | string   | Yes  | Name of the attribute key for **type** in the output object.              |
| nameKey           | string   | Yes  | Name of the attribute key for **name** in the output object.              |
| elementsKey       | string   | Yes  | Name of the attribute key for **elements** in the output object.      |
