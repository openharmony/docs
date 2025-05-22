# ArkTS子系统变更说明

## cl.arkts.1 util.TextDecoder模块ignoreBOM功能行为变更

**访问级别**

公开接口

**变更原因**

util.TextDecoder模块ignoreBOM参数未使能，无法对存在BOM标记的数据进行正常解析。

**变更影响**

此版本兼容之前的应用开发，不需要适配，后续可调用新增替代接口支持ignoreBOM的功能。

**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.0.0.35 版本开始。

**变更的接口/组件**

为确保版本之间的兼容性，对util.TextDecoder模块ignoreBOM使能的相关接口进行废弃，并新增对应方法。
|  类名 | 废弃接口  | 新增替代接口  |
| ------------ | ------------  | ------------ |
| util.TextDecoder | decodeWithStream(input: Uint8Array, options?: DecodeWithStreamOptions): string;  | decodeToString(input: Uint8Array, options?: DecodeWithStreamOptions): string;  |

**适配指导**

新增接口与废弃接口功能保持一致，主要是对于接受的数据进行解码，新增了ignoreBOM功能。

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

// 废弃接口decodeWithStream表现:
// let decodeWithStreamOptions: util.DecodeWithStreamOptions = {
//   stream: false
// }
// let retStr = textDecoder.decodeWithStream(result , decodeWithStreamOptions);
// console.info("retStr length: " + retStr.length); // retStr length: 4
// console.info("retStr value: " + retStr); // retStr value: abc

// 新增接口decodeToString表现:
let retStr = textDecoder.decodeToString(result , decodeToStringOptions);
console.info("retStr length: " + retStr.length); // retStr length: 3
console.info("retStr value: " + retStr); // retStr value: abc 
```

## cl.arkts.2 Base64Helper、StringDecoder模块部分接口参数异常错误码由undefined变更为401

**访问级别**

公开接口

**变更原因**

接口参数异常错误码规格为401，但实际为抛出错误码为undefined，开发者无法精确找到问题原因。

**变更影响**

不兼容变更，参数异常的错误码由undefined变更为401。

**起始API Level**

|  类名 | 接口 |  起始API Level  |
| ----- | ---- | -------------- |
| util.Base64Helper | encodeToStringSync(src: Uint8Array, options?: Type): string;  | 9  |
| util.Base64Helper | encode(src: Uint8Array, options?: Type): Promise<Uint8Array>;  | 9  |
| util.Base64Helper | encodeSync(src: Uint8Array, options?: Type): Uint8Array;  | 9  |
| util.Base64Helper | encodeToString(src: Uint8Array, options?: Type): Promise<string>;  | 9  |
| util.Base64Helper | decode(src: Uint8Array \| string, options?: Type): Promise<Uint8Array>;  | 9  |
| util.StringDecoder | constructor(encoding?: string);  | 12  |
| util.StringDecoder | write(chunk: string \| Uint8Array): string;  | 12  |
| util.StringDecoder | end(chunk?: string \| Uint8Array): string;  | 12  |

**变更发生版本**

从OpenHarmony SDK 5.0.0.35 版本开始。

**变更的接口/组件**

|  类名 | 接口  | 变更  |
| ------------ | ------------  | ------------ |
| util.Base64Helper | encodeToStringSync(src: Uint8Array, options?: Type): string;  | 参数异常由undefined变更为401。  |
| util.Base64Helper | encode(src: Uint8Array, options?: Type): Promise<Uint8Array>;  | 参数异常由undefined变更为401。  |
| util.Base64Helper | encodeSync(src: Uint8Array, options?: Type): Uint8Array;  | 参数异常由undefined变更为401。  |
| util.Base64Helper | encodeToString(src: Uint8Array, options?: Type): Promise<string>;  | 参数异常由undefined变更为401。  |
| util.Base64Helper | decode(src: Uint8Array \| string, options?: Type): Promise<Uint8Array>;  | 参数异常由undefined变更为401。  |
| util.StringDecoder | constructor(encoding?: string);  | 参数异常由undefined变更为401。  |
| util.StringDecoder | write(chunk: string \| Uint8Array): string;  | 参数异常由undefined变更为401。  |
| util.StringDecoder | end(chunk?: string \| Uint8Array): string;  | 参数异常由undefined变更为401。  |

**适配指导**

基于以上变更错误码的接口，开发者若存在对相关接口参数异常的错误码判断为undefined的情况，需要整改为判断401。
