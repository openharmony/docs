# ArkTS方舟编程语言Changelog

## cl.arkts.1 JSON.parse() 解析数值 Number.MIN_VALUE 返回值变更

**访问级别**

公开接口

**变更原因**

 Number.MIN_VALUE静态数据属性表示在JavaScript中可表示的最小正数值，大小约为 5e-324，JSON.parse()新增支持对该数值的解析，引入此变更。

**变更影响**

此变更涉及应用适配。

变更前： JSON.parse() 解析数值 Number.MIN_VALUE 返回值为Infinity.

变更后： JSON.parse() 解析数值 Number.MIN_VALUE 返回值为5e-324.

**起始 API Level**

6

**变更发生版本**

从OpenHarmony SDK 5.1.0.47 版本开始。

**变更的接口/组件**

不涉及

**适配指导**

目前JSON.parse() 支持解析的最小数值为 Number.MIN_VALUE，约为 5e-324。变更之前支持解析的最小数值约为 2.22e-308。

例如：

```typescript
let res = JSON.parse('{"num":5e-324}')
console.info(res.num)
```

未变更前该用例输出为：

```
Infinity
```

变更后该用例输出为:

```
5e-324
```
