# ArkTS子系统Changelog

## cl.arkts.1 util.TextEncoder模块utf-16le和utf-16be编码数据行为变更

**访问级别**

公开接口

**变更原因**

TextEncoder编码器在编码格式设置为utf-16le和utf-16be时，获得的编码数据相反。

utf-16le为小端编码格式，编码出数据应该符合小端编码数据，但是实际表现为大端编码数据。

utf-16be为大端编码格式，编码出数据应该符合大端编码数据，但是实际表现为小端编码数据。

这两种编码格式所编码出的数据行为与标准定义不符合，需要修复此问题。

**变更影响**

该变更为不兼容性变更。

变更前：

utf-16le为小端编码格式，编码出数据应该符合小端编码数据，但是实际表现为大端编码数据。

utf-16be为大端编码格式，编码出数据应该符合大端编码数据，但是实际表现为小端编码数据。

变更后：

utf-16le为小端编码格式，实际表现为小端编码数据。

utf-16be为大端编码格式，实际表现为大端编码数据。

**起始API Level**

API 9

**变更发生版本**

从OpenHarmony 5.0.0.42 版本开始。

**变更的接口/组件**

util.TextEncoder模块的接口：

encodeInto(input?: string): Uint8Array;

encodeIntoUint8Array(input: string, dest: Uint8Array): EncodeIntoUint8ArrayInfo;

**适配指导**

变更描述： 修复TextEncoder编码器在编码格式设置为utf-16le和utf-16be时获取编码数据与定义不相符的BUG。

encodeInto接口的表现：

```ts
import { util } from '@kit.ArkTS';

let encoderUtf16Le = new util.TextEncoder("utf-16le");
let encoderUtf16Be = new util.TextEncoder("utf-16be");

// 变更前：
// let u16_le = encoderUtf16Le.encodeInto('abcdefg'); // u16_le: 0,97,0,98,0,99,0,100,0,101,0,102,0,103
// let u16_be = encoderUtf16Be.encodeInto('abcdefg'); // u16_be: 97,0,98,0,99,0,100,0,101,0,102,0,103,0


// 变更后：
let u16_le = encoderUtf16Le.encodeInto('abcdefg'); // u16_le: 97,0,98,0,99,0,100,0,101,0,102,0,103,0
let u16_be = encoderUtf16Be.encodeInto('abcdefg'); // u16_be: 0,97,0,98,0,99,0,100,0,101,0,102,0,103
```

encodeIntoUint8Array接口的表现：

```ts
import { util } from '@kit.ArkTS';

let encoderUtf16Le = new util.TextEncoder("utf-16le");
let encoderUtf16Be = new util.TextEncoder("utf-16be");

// 变更前：
// let dest_le = new Uint8Array(14);
// let dest_be = new Uint8Array(14);
// let res_le = encoderUtf16Le.encodeIntoUint8Array('abcdefg', dest_le); // dest_le: 0,97,0,98,0,99,0,100,0,101,0,102,0,103
// let res_be = encoderUtf16Be.encodeIntoUint8Array('abcdefg', dest_be); // dest_be: 97,0,98,0,99,0,100,0,101,0,102,0,103,0

// 变更后：
let dest_le = new Uint8Array(14);
let dest_be = new Uint8Array(14);
let res_le = encoderUtf16Le.encodeIntoUint8Array('abcdefg', dest_le); // dest_le: 97,0,98,0,99,0,100,0,101,0,102,0,103,0
let res_be = encoderUtf16Be.encodeIntoUint8Array('abcdefg', dest_be); // dest_be: 0,97,0,98,0,99,0,100,0,101,0,102,0,103
```
