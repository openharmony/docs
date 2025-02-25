# Arkts子系统变更说明

## cl.arkts.1 Buffer.from()接口行为变更

**访问级别**

公开接口

**变更原因**

Buffer模块的from接口在使用Array作为入参时，创建的buffer中的数据在遇到负数以及大于255的数时会将该数据错误的置为0，按照标准规则应该是将该数据按照(value & 255)的规则进行取低八位，以适应0-255的范围。

**变更影响**

此变更不涉及应用适配。

影响使用Array数据类型创建的Buffer的数据内容。

**变更前**

```ts
// 使用Array的内容中包含负数以及大于255的数值时，创建的buffer中此种情况对应值都改为0。
let bufObj = buffer.from([1, 2, 3, 4, -1, -2, 5, 265]);
console.info(JSON.stringify(bufObj)) // {"type":"Buffer","data":[1,2,3,4,0,0,5,0]}

```
**变更后**

```ts
// 使用Array的内容中包含负数以及大于255的数值时，创建的buffer中对应数值按照(value & 255)的规则进行取值低八位，以适应0-255的范围。
let bufObj = buffer.from([1, 2, 3, 4, -1, -2, 5, 265]);
console.info(JSON.stringify(bufObj)) // {"type":"Buffer","data":[1,2,3,4,255,254,5,9]}

```
**起始API Level**

9

**变更发生版本**

从OpenHarmony SDK 5.1.0.46版本开始。

**变更的接口/组件**

from(array: number[]): Buffer;

**适配指导**

from(array: number[]): Buffer 方法行为变更之后，用户之前如果入参Array中有负数或者大于255的数值时，buffer对应位置的结果由0变为与 0xFF 操作取低8位（每个字节）的值。