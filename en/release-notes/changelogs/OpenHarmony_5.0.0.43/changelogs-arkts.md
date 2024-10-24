# ArkTS Subsystem Changelog

## cl.arkts.1 StringDecoder's Incorrect Decoding Behavior in Specific Scenarios Is Changed

**Access Level**

Public API

**Reason for Change**

If the input parameter Uint8Array contains element 0, StringDecoder cannot decode the data following element 0. Instead, it truncates the data at the position of element 0. As such, the decoded data is incomplete.

**Change Impact**

This change is a compatible change.

Before change:
When the Uint8Array that contains element 0 is encoded, the data is incomplete. Encoding the decoded data fails to restore the original Uint8Array.

After change:
The Uint8Array that contains element 0 is correctly decoded, and the decoded data is complete.

**Start API Level**

12

**Change Since**

OpenHarmony SDK 5.0.0.43

**Key API/Component Changes**

Two APIs in the util.StringDecoder module:

write(chunk: string | Uint8Array): string;

end(chunk?: string | Uint8Array): string;

**Adaptation Guide**

No adaptation is required.

```ts
import { util } from '@kit.ArkTS';

let decoder = new util.StringDecoder('utf-8');
// 0xE4, 0xBD, 0xA0 Decoding result: Hello
// 0                Decoding result: \u0000 (invisible character, occupying one byte)
// 0xE5, 0xA5, 0xBD decoding result: World
let input = new Uint8Array([0xE4, 0xBD, 0xA0, 0, 0xE5, 0xA5, 0xBD]);
const decoded = decoder.write(input);
const decodedend = decoder.end(input);

// Before change:
console.info("decoded:", decoded)); // Hello
// console.info("decoded.length:", decoded.length); // 1
// console.info ("decodedend:," decodedend); // Hello
// console.info("decodedend.length:", decodedend.length); // 1

// Now:
console.info("decoded:", decoded)); // Hello World
console.info("decoded.length:", decoded.length); // 3
console.info("decodedend:", decodedend);// Hello World
console.info("decodedend.length:", decodedend.length); // 3
```
