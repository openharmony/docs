# commonlibrary子系统变更说明

## cl.commonlibrary.1 ArkTs util模块decodeWithStream接口在入参为空时返回值变更

**引入版本**

OpenHarmony_5.0.0.19

**变更原因**

原返回值与接口声明不一致

**变更影响**

该变更为非兼容性变更。

**适配指导**

变更后，入参为空时，接口返回值由undefined变为空字符串

```
let decoder = util.TextDecoder.create();
let uint8 = new Uint8Array(0);
let res = decoder.decodeWithStream(uint8);
console.info(res);
```
