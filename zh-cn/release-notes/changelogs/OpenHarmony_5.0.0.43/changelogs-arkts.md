# ArkTS子系统Changelog

## cl.arkts.1 StringDecoder中特定场景下解码错误数据行为变更

**访问级别**

公开接口

**变更原因**

StringDecoder对于入参Uint8Array中存在元素0的情况，无法解码出Uint8Array中元素0后数据，在元素0位置截断，导致获取不到完整的解码数据。

**变更影响**

该变更为兼容性变更，属于问题修复。

变更前：
对于存在元素0的Uint8Array对象进行编码时，数据不完整。对解码出的值进行编码时，无法正常恢复为原始Uint8Array。

变更后：
对存在元素0的Uint8Array对象，正确进行解码，解码数据完整。

**起始API Level**

API 12

**变更发生版本**

从OpenHarmony 5.0.0.43 版本开始。

**变更的接口/组件**

util.StringDecoder模块下的两个接口：

write(chunk: string | Uint8Array): string;

end(chunk?: string | Uint8Array): string;

**适配指导**

变更描述：Uint8Array中存在元素0的情况，无需适配，属于问题修复。

```ts
import { util } from '@kit.ArkTS';

let decoder = new util.StringDecoder('utf-8');
// 0xE4, 0xBD, 0xA0 解码结果：你
// 0                解码结果：\u0000(不可见字符，占一个长度)
// 0xE5, 0xA5, 0xBD 解码结果：好
let input = new Uint8Array([0xE4, 0xBD, 0xA0, 0, 0xE5, 0xA5, 0xBD]);
const decoded = decoder.write(input);
const decodedend = decoder.end(input);

// 变更前:
// console.info("decoded:", decoded);// 你
// console.info("decoded.length:", decoded.length);// 1
// console.info("decodedend:", decodedend);// 你
// console.info("decodedend.length:", decodedend.length);// 1

// 变更后：
console.info("decoded:", decoded);// 你好
console.info("decoded.length:", decoded.length);// 3
console.info("decodedend:", decodedend);// 你好
console.info("decodedend.length:", decodedend.length);// 3
```

