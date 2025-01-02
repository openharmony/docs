# ArkTS Subsystem Changelog

## cl.arkts.1 Encoding Behavior of utf-16le and utf-16be of the util.TextEncoder Module Changed

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

The utf-16le encoding format uses little-endian. However, the encoded data is in big-endian format.

The utf-16be encoding format uses big-endian. However, the encoded data is in little-endian format.

After change:

The utf-16le encoding format uses little-endian, and the encoded data is in little-endian format.

The utf-16be encoding format uses big-endian, and the encoded data is in big-endian format.

**Start API Level**

9

**Change Since**

OpenHarmony SDK 5.0.0.42

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
// let u16_le = encoderUtf16Le.encodeInto('abcdefg'); // u16_le: 0,97,0,98,0,99,0,100,0,101,0,102,0,103
// let u16_be = encoderUtf16Be.encodeInto('abcdefg'); // u16_be: 97,0,98,0,99,0,100,0,101,0,102,0,103,0


// After change:
let u16_le = encoderUtf16Le.encodeInto('abcdefg'); // u16_le: 97,0,98,0,99,0,100,0,101,0,102,0,103,0
let u16_be = encoderUtf16Be.encodeInto('abcdefg'); // u16_be: 0,97,0,98,0,99,0,100,0,101,0,102,0,103
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
