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
console.log((1 ** NaN).toString())
```

未变更前该用例输出为：

```
1
```

变更后该用例输出为:

```
NaN
```

> **说明：**

> 对于类似  `1 ** "test"` 的用法，在ets文件中不能使用，但是可能在三方库中有使用，该行为同样会变化。

本变更修复该问题，** （幂运算）对于底数是1，指数为NaN或ToNumber之后是NaN的情况会返回NaN。



## cl.arkts.2 String.prototype.lastIndexOf 接口查找空字符串行为变更

**访问级别**

其他

**变更原因**

String.prototype.lastIndexOf 接口查找空字符串时返回值为-1，与[ECMAScript® 2021 Language Specification](https://262.ecma-international.org/12.0/index.html#sec-string.prototype.lastindexof)描述不符。

**变更影响**

该变更为不兼容变更。

变更前：String.prototype.lastIndexOf接口查找字符串为空时返回值为-1

变更后：String.prototype.lastIndexOf接口查找字符串为空时返回值为最后一个字符的位置加1

**起始 API Level**

6

**变更发生版本**

从OpenHarmony SDK 5.0.0.53 版本开始。

**变更的接口/组件**

String.prototype.lastIndexOf

**适配指导**

排查是否有使用 String.prototype.lastIndexOf 接口查找空字符串的场景

例如：

```typescript
console.log("abcde".lastIndexOf("").toString())
```

未变更前该用例输出为：

```
-1
```

变更后该用例输出为:

```
5
```

本变更修复该问题，String.prototype.lastIndexOf 查找空串的结果是最后一个字符的位置加1。

