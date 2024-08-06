# ArkTS Subsystem Changelog

## cl.arkts.1 Behavior of the ignoreBOM Feature of the util.TextDecoder Module Changed

**Access Level**

Public API

**Reason for Change**

The ignoreBOM feature of the **util.TextDecoder** module is not enabled. As a result, data with BOM flags cannot be parsed.

**Change Impact**

This version is compatible with earlier versions and no adaptation is required. The new API can be called to support the ignoreBOM feature.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.35

**Key API/Component Changes**

To ensure version compatibility, the API related to the ignoreBOM feature of the **util.TextDecoder** module is deprecated, and a substitute API is provided.
|  Class | Deprecated API | Substitute API |
| ------------ | ------------  | ------------ |
| util.TextDecoder | decodeWithStream(input: Uint8Array, options?: DecodeWithStreamOptions): string;  | decodeToString(input: Uint8Array, options?: DecodeWithStreamOptions): string;  |

**Adaptation Guide**

The new API provides the same capability as the deprecated one. It is used to decode received data and supports the ignoreBOM feature.

```
import { util } from '@kit.ArkTS';

let textDecoderOptions: util.TextDecoderOptions = {
  fatal: false,
  ignoreBOM : true
}
let decodeToStringOptions: util.DecodeToStringOptions = {
  stream: false
}
let textDecoder = util.TextDecoder.create('utf-8', textDecoderOptions);
let result = new Uint8Array(6);
result[0] = 0xEF;
result[1] = 0xBB;
result[2] = 0xBF;
result[3] = 0x61;
result[4] = 0x62;
result[5] = 0x63;

// Behavior of decodeWithStream:
// let decodeWithStreamOptions: util.DecodeWithStreamOptions = {
//   stream: false
// }
// let retStr = textDecoder.decodeWithStream(result , decodeWithStreamOptions);
// console.info("retStr length: " + retStr.length); // retStr length: 4
// console.info("retStr value: " + retStr); // retStr value: abc

// Behavior of decodeToString:
let retStr = textDecoder.decodeToString(result , decodeToStringOptions);
console.info("retStr length: " + retStr.length); // retStr length: 3
console.info("retStr value: " + retStr); // retStr value: abc 
```

## cl.arkts.2 Error Code Indicating Parameter Exceptions for Some APIs of the Base64Helper and StringDecoder Modules Are Changed from undefined to 401

**Access Level**

Public API

**Reason for Change**

The error code indicating parameter exceptions is 401. In practice, undefined is thrown.

**Change Impact**

The error code indicating parameter exceptions is changed from undefined to 401.

**Start API Level**

|  Class | API |  Start API Level |
| ----- | ---- | -------------- |
| util.Base64Helper | encodeToStringSync(src: Uint8Array, options?: Type): string;  | 9  |
| util.Base64Helper | encode(src: Uint8Array, options?: Type): Promise\<Uint8Array>; | 9  |
| util.Base64Helper | encodeSync(src: Uint8Array, options?: Type): Uint8Array;  | 9  |
| util.Base64Helper | encodeToString(src: Uint8Array, options?: Type): Promise\<string>; | 9  |
| util.Base64Helper | decode(src: Uint8Array \| string, options?: Type): Promise\<Uint8Array>; | 9  |
| util.StringDecoder | constructor(encoding?: string);  | 12  |
| util.StringDecoder | write(chunk: string \| Uint8Array): string;  | 12  |
| util.StringDecoder | end(chunk?: string \| Uint8Array): string;  | 12  |

**Change Since**

OpenHarmony SDK 5.0.0.35

**Key API/Component Changes**

|  Class | API | Change Description |
| ------------ | ------------  | ------------ |
| util.Base64Helper | encodeToStringSync(src: Uint8Array, options?: Type): string;  | The error code indicating parameter exceptions is changed from undefined to 401. |
| util.Base64Helper | encode(src: Uint8Array, options?: Type): Promise\<Uint8Array>; | The error code indicating parameter exceptions is changed from undefined to 401. |
| util.Base64Helper | encodeSync(src: Uint8Array, options?: Type): Uint8Array;  | The error code indicating parameter exceptions is changed from undefined to 401. |
| util.Base64Helper | encodeToString(src: Uint8Array, options?: Type): Promise\<string>; | The error code indicating parameter exceptions is changed from undefined to 401. |
| util.Base64Helper | decode(src: Uint8Array \| string, options?: Type): Promise\<Uint8Array>; | The error code indicating parameter exceptions is changed from undefined to 401. |
| util.StringDecoder | constructor(encoding?: string);  | The error code indicating parameter exceptions is changed from undefined to 401. |
| util.StringDecoder | write(chunk: string \| Uint8Array): string;  | The error code indicating parameter exceptions is changed from undefined to 401. |
| util.StringDecoder | end(chunk?: string \| Uint8Array): string;  | The error code indicating parameter exceptions is changed from undefined to 401. |

**Adaptation Guide**

Change the error code indicating parameter exceptions from undefined to 401 in your code.
