# ArkCompiler子系统变更说明

## cl.arkcompiler.1 Sendable容器TypedArray提供的map方法的回调函数声明变更

**访问级别**

公开接口

**变更原因**

Sendable容器TypedArray提供map方法。该方法对TypedArray中的每个元素进行某种操作或转换（通过callbackFn的返回值），并返回一个新的TypedArray，其中包含经过映射函数处理后的结果。

以Uint8Array为例，变更前，map函数的callbackFn声明无返回值，导致转换后的数据丢失，引起开发者使用上的困惑。
- map方法的回调函数声明为`map(callbackFn: TypedArrayForEachCallback<number, Uint8Array>): Uint8Array;`
- 而TypedArrayForEachCallback 的定义为无返回值的：`type TypedArrayForEachCallback<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => void;`

**变更影响**

该变更为不兼容变更。

**变更前**

- 情况一： map函数中的callbackFn无返回值，能通过编译，但是无法实现map功能
- 情况二： map函数中的callbackFn有返回值，但是返回类型不是number，能通过编译，能实现map功能
- 情况三： map函数中的callbackFn有返回值，且返回类型是number，能通过编译，能实现map功能

```
// 创建一个Uint8Array
let uint8: collections.Uint8Array = new collections.Uint8Array([1, 2, 3, 4, 5]);

// 情况一：不能完成map功能：callbackFn无返回值，map函数返回新的collections.Uint8Array
let zeroMappedArray: collections.Uint8Array = uint8.map((value: number) => {}); // 能通过编译
console.info(zeroMappedArray); // 输出: collections.Uint8Array [0, 0, 0, 0, 0]

// 情况二：能完成map功能：callbackFn返回map后的元素值，但类型为string，map函数返回新的collections.Uint8Array
let wrongTypeMapped: collections.Uint8Array = uint8.map((value: number) => value + "1"); // 能通过编译
console.info(wrongTypeMapped); // 输出: collections.Uint8Array [11, 21, 31, 41, 51]

// 情况三：能完成map功能：callbackFn返回map后的元素值，map函数返回新的collections.Uint8Array
let normalMapped: collections.Uint8Array = uint8.map((value: number) => value * 2); // 能通过编译
console.info(normalMappedArray); // 输出: collections.Uint8Array [2, 4, 6, 8, 10]
```

**变更后**

- 情况一： map函数中的callbackFn无返回值，不能通过编译（不兼容变更）
- 情况二： map函数中的callbackFn有返回值，但是返回类型不是number，不能通过编译（不兼容变更）
- 情况三： map函数中的callbackFn有返回值，且返回类型是number，能通过编译，能实现map功能（兼容）


```
// 创建一个Uint8Array
let uint8: collections.Uint8Array = new collections.Uint8Array([1, 2, 3, 4, 5]);

// 情况一：不能完成map功能：callbackFn无返回值，map函数返回新的collections.Uint8Array
let zeroMappedArray: collections.Uint8Array = uint8.map((value: number) => {}); // 不兼容变更：不能通过编译

// 情况二：能完成map功能：callbackFn返回map后的元素值，但类型为string，map函数返回新的collections.Uint8Array
let wrongTypeMapped: collections.Uint8Array = uint8.map((value: number) => value + "1"); // 不兼容变更：不能通过编译

// 情况三：能完成map功能：callbackFn返回map后的元素值，map函数返回新的collections.Uint8Array
let normalMapped: collections.Uint8Array = uint8.map((value: number) => value * 2); // 能通过编译
console.info(normalMappedArray); // 输出: collections.Uint8Array [2, 4, 6, 8, 10]
```

**起始API Level**

API12

**变更发生版本**

从OpenHarmony SDK 5.0.0.31 版本开始。

**变更的接口/组件**

/interface/sdk-js/arkts/@arkts.collections.d.ets中TypedArray（包括Int8Array/Uint8Array/Int16Array/Uint16Array/Int32Array/Uint32Array）的map接口

**适配指导**

- 举例：上述场景二的例子，可以做如下修改：
```
let wrongTypeMapped: collections.Uint8Array = uint8.map((value: number) => parseInt(value + "1")); // 通过parseInt进行字符串到number的转换
```

- 详细说明参见：接口使用的示例代码:
[ArkTS容器集 - TypedArray](../../../application-dev/reference/apis-arkts/js-apis-arkts-collections.md#collectionstypedarray)