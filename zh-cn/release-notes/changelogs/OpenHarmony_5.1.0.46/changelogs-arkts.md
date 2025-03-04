# ArkTS子系统变更说明

## cl.arkts.1 Buffer.from()接口行为变更

**访问级别**

公开接口

**变更原因**

为了更好对二进制数据进行底层操作，Buffer模块底层的每一个元素都是按照 UInt8（无符号8位整数）进行存储的。当使用Array作为入参调用Buffer.from()接口创建Buffer对象时，当前实现存在以下不规范行为：Array中的数据存在负数或超过255的数值时，返回的Buffer对象中对应的数值会错误地置为0。正确的技术规范应为：对越界值执行二进制补码转换（负数）或取模运算（超上限整数值），使其严格适配0-255的数值区间。


**变更影响**

此变更不涉及应用适配。

变更前:

```ts
// 使用Array创建Buffer对象时，Array数据中包含负数以及大于255的数值时，返回的Buffer对象中对应位置的数值会错误地置为0。
let bufObj = buffer.from([1, 2, 3, 4, -1, -2, 5, 265]);
console.info(JSON.stringify(bufObj)); // {"type":"Buffer","data":[1,2,3,4,0,0,5,0]}

```
变更后:

```ts
// 使用Array创建Buffer对象时，Array数据中包含负数以及大于255的数值时，返回的Buffer对象中对应位置的数值按照(value & 255)的规则进行取值低八位，使其严格适配0-255的数值区间。
let bufObj = buffer.from([1, 2, 3, 4, -1, -2, 5, 265]);
console.info(JSON.stringify(bufObj)); // {"type":"Buffer","data":[1,2,3,4,255,254,5,9]}

```
**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.1.0.46版本开始。

**变更的接口/组件**

from(array: number[]): Buffer

**适配指导**

默认行为变更，无需适配。
在使用Array作为入参调用Buffer.from()接口创建Buffer对象时，注意返回的Buffer对象中对应位置的数值内容的变更。