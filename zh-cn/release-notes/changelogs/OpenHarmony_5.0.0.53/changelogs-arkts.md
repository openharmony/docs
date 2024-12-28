# ArkTS方舟编程语言Changelog

## cl.arkts.1 执行幂运算（\*\*）当底数是1，指数是NaN或ToNumber之后是NaN的情况的返回值变更

**访问级别**

其他

**变更原因**

 ArkTS执行幂运算时，当底数为1，指数为NaN或ToNumber之后是NaN,返回值为1，与[ECMAScript® 2021 Language Specification](https://262.ecma-international.org/12.0/index.html#sec-numeric-types-number-exponentiate)描述不符。

**变更影响**

该变更为不兼容变更。

变更前： 执行幂运算，当底数为1，指数为NaN或ToNumber之后是NaN，返回值为1

变更后： 执行幂运算，当底数为1，指数为NaN或ToNumber之后是NaN，返回值为NaN

**起始 API Level**

6

**变更发生版本**

从OpenHarmony SDK 5.0.0.53 版本开始。

**变更的接口/组件**

不涉及

**适配指导**

排查是否对 **（幂运算）有如下情况的使用

例如：

```typescript
console.log(1 ** NaN)
console.log(1 ** "Test")
```

未变更前该用例输出为：

```
1
1
```

变更后该用例输出为:

```
NaN
NaN
```

本变更修复该问题，** （幂运算）对于底数是1，指数为NaN或ToNumber之后是NaN的情况会返回NaN
