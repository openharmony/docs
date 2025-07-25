# ArkTS Subsystem Changelog

## cl.arkts.1 convertXml Now Supports parentKey

**Access Level**

Public API

**Reason for Change**

The convertXml module does not support the **parentKey** attribute. The generated object does not contain the **parentKey** attribute value.

**Change Impact**

This change is a non-compatible change.

Before change:

When **convertToJSObject** parses the input parameters of an XML string, setting the **parentKey** attribute value is not supported.

After change:

When **convertToJSObject** parses the input parameters of an XML string, setting the **parentKey** attribute value is supported.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.1.1

**Key API/Component Changes**

API in the convertXML module:

convertToJSObject(xml: string, options?: ConvertOptions): Object;

**Adaptation Guide**

No adaptation is required.

```ts
import { convertxml } from '@kit.ArkTS';

let xml =
  '<?xml version="1.0" encoding="utf-8"?>' +
    '<note importance="high" logged="true">' +
    '    <title>Happy</title>' +
    '    <todo>Work</todo>' +
    '    <todo>Play</todo>' +
    '</note>';
let conv = new convertxml.ConvertXML()
let options: convertxml.ConvertOptions = {
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
let result: ESObject = conv.convertToJSObject(xml, options);

// Before the change, the value of result is {"_declaration":{"_attributes":{"version":"1.0","encoding":"utf-8"}},"_elements":[{"_type":"element","_name":"note","_attributes":{"importance":"high","logged":"true"},"_elements":[{"_type":"element","_name":"title","_elements":[{"_type":"text","_text":"Happy"}]},{"_type":"element","_name":"todo","_elements":[{"_type":"text","_text":"Work"}]},{"_type":"element","_name":"todo","_elements":[{"_type":"text","_text":"Play"}]}]}]}.

// After the change, the value of result is {"_declaration":{"_attributes":{"version":"1.0","encoding":"utf-8"}},"_elements":[{"_type":"element","_name":"note","_attributes":{"importance":"high","logged":"true"},"_elements":[{"_type":"element","_name":"title","_parent":"note","_elements":[{"_type":"text","_text":"Happy"}]},{"_type":"element","_name":"todo","_parent":"note","_elements":[{"_type":"text","_text":"Work"}]},{"_type":"element","_name":"todo","_parent":"note","_elements":[{"_type":"text","_text":"Play"}]}]}]}. (The parentKey attribute value is added.)

// This does not affect the API usage.
// To obtain the parentKey attribute of the title tag, call the following API: result1["_elements"][0]["_elements"][0]._parent
// Before change: The parentKey attribute of the title tag is undefined.
// After change: The parentKey attribute of the title tag is the actual value note.
```

## cl.arkts.2 Encoding Behavior of utf-16le and utf-16be of the util.TextEncoder Module Changed

**Access Level**

Public API

**Reason for Change**

When TextEncoder uses the utf-16le or utf-16be encoding format, the encoded data obtained is incorrect.

The utf-16le encoding format uses little-endian. However, the encoded data is in big-endian format.

The utf-16be encoding format uses big-endian. However, the encoded data is in little-endian format.

The data obtained does not comply with the standard definition. This problem needs to be corrected.

**Change Impact**

This change is a non-compatible change.

Before change:

- The utf-16le encoding format uses little-endian. However, the encoded data is in big-endian format.
- The utf-16be encoding format uses big-endian. However, the encoded data is in little-endian format.

After change:

- The utf-16le encoding format uses little-endian, and the encoded data is in little-endian format.
- The utf-16be encoding format uses big-endian, and the encoded data is in big-endian format.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.1.1

**Key API/Component Changes**

APIs of the util.TextEncoder module:

encodeInto(input?: string): Uint8Array;

encodeIntoUint8Array(input: string, dest: Uint8Array): EncodeIntoUint8ArrayInfo;

**Adaptation Guide**

No adaptation is required.

Behavior of **encodeInto**:

```ts
import { util } from '@kit.ArkTS';

let encoderUtf16Le = new util.TextEncoder("utf-16le");
let encoderUtf16Be = new util.TextEncoder("utf-16be");

// Before change:
// let u8_le = encoderUtf16Le.encodeInto('abcdefg'); // u8_le: 0,97,0,98,0,99,0,100,0,101,0,102,0,103
// let u8_be = encoderUtf16Be.encodeInto('abcdefg'); // u8_be: 97,0,98,0,99,0,100,0,101,0,102,0,103,0


// After change:
let u8_le = encoderUtf16Le.encodeInto('abcdefg'); // u8_le: 97,0,98,0,99,0,100,0,101,0,102,0,103,0
let u8_be = encoderUtf16Be.encodeInto('abcdefg'); // u8_be: 0,97,0,98,0,99,0,100,0,101,0,102,0,103
```

Behavior of **encodeIntoUint8Array**:

```ts
import { util } from '@kit.ArkTS';

let encoderUtf16Le = new util.TextEncoder("utf-16le");
let encoderUtf16Be = new util.TextEncoder("utf-16be");

// Before change:
// let dest_le = new Uint8Array(14);
// let dest_be = new Uint8Array(14);
// let res_le = encoderUtf16Le.encodeIntoUint8Array('abcdefg', dest_le); // dest_le: 0,97,0,98,0,99,0,100,0,101,0,102,0,103
// let res_be = encoderUtf16Be.encodeIntoUint8Array('abcdefg', dest_be); // dest_be: 97,0,98,0,99,0,100,0,101,0,102,0,103,0

// After change:
let dest_le = new Uint8Array(14);
let dest_be = new Uint8Array(14);
let res_le = encoderUtf16Le.encodeIntoUint8Array('abcdefg', dest_le); // dest_le: 97,0,98,0,99,0,100,0,101,0,102,0,103,0
let res_be = encoderUtf16Be.encodeIntoUint8Array('abcdefg', dest_be); // dest_be: 0,97,0,98,0,99,0,100,0,101,0,102,0,103
```
