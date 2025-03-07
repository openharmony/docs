# ArkCompiler子系统Changelog

## cl.arkcompiler.1 JSON.parse解析非法字符串行为变更

**访问级别**

公开接口

**变更原因**

JSON.parse解析非法字符串未抛JS异常，表现与预期及ECMA规范不一致

**变更影响**

该变更为不兼容性变更。

```
const strData = `{"k1": "hello", "k2": 3}`;
const strErr = strData.substring(0, strData.length - 2); // `{"k1": "hello", "k2": `
JSON.parse(strErr);
```

变更前：JSON.parse解析非法字符串`strErr`能够正常解析，未抛出JS异常。

变更后：JSON.parse解析非法字符串`strErr`抛出JS异常。

**起始API Level**

12

**变更发生版本**

5.0 Beta3

**变更的接口/组件**

JSON.parse/ASON.parse/util.json.parse

**适配指导**

针对JSON.parse解析非法字符串的异常场景，开发者需要保证传入的字符串为合法字符串，或者使用try-catch捕获异常。

## cl.arkcompiler.2 JSON.parse解析浮点数下溢或-0行为变更

**访问级别**

公开接口

**变更原因**

JSON.parse相关接口解析字符串含有浮点数下溢或-0的情况，表现与规范不一致。

**变更影响**

该变更为不兼容性变更。

变更前：
`JSON.parse('123.456e-789');` 返回 `-Infinity`，是错误结果。
`1/JSON.parse('-0');` 返回 `Infinity`，是错误结果。

变更后：
`JSON.parse('123.456e-789');` 返回 `0`，是正确结果。
`1/JSON.parse('-0');` 返回 `-Infinity`，是正确结果。

**起始API Level**

12

**变更发生版本**

5.0 Beta3

**变更的接口/组件**

JSON.parse/ASON.parse/util.json.parse

**适配指导**

对于开发者，排查代码中是否存在对JSON.parse相关接口传入下溢的浮点数字符串与-0的情况，如果存在该现象，则排查代码逻辑是否能适配正确的值。

## cl.arkcompiler.3 TextEncoder.encodeInto()接口变更

**访问级别**

公开接口

**变更原因**

TextEncoder.encodeInto编码字符串，当字符串中每多一个'\0'字符，返回的数组长度会增加2，长度异常。

**变更影响**

该变更为不兼容性变更。

```
const arr = encoder.encodeInto('\0ab');
arr.length;
```

变更前：arr = [0x00, 0x61, 0x62, 0x00], arr.length 为4

变更后：arr = [0x00, 0x61, 0x62], arr.length 为3

**起始API Level**

9

**变更发生版本**

5.0 Beta3

**变更的接口/组件**

TextEncoder.encodeInto

**适配指导**

针对TextEncoder.encodeInto编码字符串时，注意返回的数组长度。