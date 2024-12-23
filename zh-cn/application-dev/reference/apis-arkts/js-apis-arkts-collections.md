# @arkts.collections (ArkTS容器集)

本模块提供的ArkTS容器集，可以用于并发场景下的高性能数据传递。功能与JavaScript内建的对应容器类似，但ArkTS容器实例无法通过\.或者\[\]添加或更新属性。

ArkTS容器在多个并发实例间传递时，其默认行为是引用传递，支持多个并发实例可以同时操作同一个容器实例。另外，也支持拷贝传递，即每个并发实例持有一个ArkTS容器实例。

ArkTS容器并不是线程安全的，内部使用了fail-fast（快速失败）机制：当检测多个并发实例同时对容器进行结构性改变时，会触发异常。因此，在修改场景下，容器使用方需要使用ArkTS提供的异步锁机制保证ArkTS容器的安全访问。

当前ArkTS容器集主要包含以下几种容器：[Array](#collectionsarray)、[Map](#collectionsmap)、[Set](#collectionsset)、[TypedArray](#collectionstypedarray)、[ArrayBuffer](#collectionsarraybuffer)、[BitVector](#collectionsbitvector)、[ConcatArray](#collectionsconcatarray)。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { collections } from '@kit.ArkTS';
```

## ISendable

type ISendable = lang.ISendable

ISendable是所有Sendable类型（除`null`和`undefined`）的父类型。自身没有任何必须的方法和属性。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 类型 | 说明   |
| ------ | ------ |
| [lang.ISendable](js-apis-arkts-lang.md#langisendable)   | 所有Sendable类型的父类型。 |

## collections.ConcatArray
表示可以进行连接的类似数组的对象。该接口扩展了`ISendable`接口。

文档中存在泛型的使用，涉及以下泛型标记符：

- T：Type，支持[Sendable支持的数据类型](../../arkts-utils/arkts-sendable.md#sendable支持的数据类型)。

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称   | 类型   | 只读 | 可选 | 说明              |
| ------ | ------ | ---- | ---- | ----------------- |
| length | number | 是   | 否   | ConcatArray的元素个数。 |

### [index: number]

readonly &#91;index: number&#93;: T

返回ConcatArray指定索引位置的元素。

**系统能力：** SystemCapability.Utils.Lang

| 参数名    | 类型   | 必填 | 说明                                                            |
| ----- | ------ | ---- | ------------------------------------------------------------------ |
| index | number | 是   | 所需代码单元的从零开始的索引。当index<0 或者index>=length，则会抛出错误。 |

**返回值：**

| 类型   | 说明                     |
| ----- | ------------------------ |
| T | ConcatArray给定的元素数据类型。|

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                             |
| ------- | ------------------------------------ |
| 401 |  Parameter error. Illegal index.         |
| 10200001 | The value of index is out of range. |

**示例：**

```ts
let concatArray : collections.ConcatArray<number> = new collections.Array<number>(1, 2, 4);
console.info("Element at index 1: ", concatArray[1]);
```

### join

join(separator?: string): string

将ConcatArray的所有元素连接成一个字符串，元素之间可以用指定的分隔符分隔。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型   | 必填 | 说明                                                 |
| --------- | ------ | ---- | ---------------------------------------------------- |
| separator | string | 否   | 用于分隔ConcatArray元素的字符串。如果省略，则使用逗号分隔。 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| string | 包含所有ConcatArray元素连接成的字符串。如果ConcatArray为空，则返回空字符串。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 |  Parameter error. Invalid separator. |

**示例：**

```ts
let concatArray : collections.ConcatArray<string> = new collections.Array<string>('a', 'b', 'c');
let joinedString = concatArray.join('-'); // 返回 "a-b-c"
```

### slice

slice(start?: number, end?: number): ConcatArray\<T>

返回一个新的ConcatArray，该ConcatArray是原始ConcatArray的切片。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**
| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| start  | number | 否   | 开始索引。如果`start < 0`，则会从`start + array.length`位置开始。默认值为0。   |
| end    | number | 否   | 结束索引（不包括该元素）。如果`end < 0`，则会到`end + array.length`位置结束。默认为ArkTS Array的长度。 |

**返回值：**

| 类型      | 说明                       |
| --------- | -------------------------- |
| ConcatArray\<T> | 包含原始ConcatArray切片的新ConcatArray。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | -------- |
| 401 |  Parameter error. Invalid `start` or `end` parameters. |

**示例：**

```ts
let concatArray : collections.ConcatArray<number> = new collections.Array<number>(1, 2, 3, 4, 5);
let slicedArray = concatArray.slice(1, 3); // 返回[2, 3]，原Array保持不变
```

## ArrayFromMapFn<sup>16+</sup>
type ArrayFromMapFn<FromElementType, ToElementType> = (value: FromElementType, index: number) => ToElementType

ArkTS Array归约函数类型，被Array类的'from' 接口使用。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| value | FromElementType | 是 | 当前正在处理的元素。|
| index | number | 是 | 当前遍历的ArkTS Array元素下标。 |

**返回值：**

| 类型   | 说明                          |
| ------ | --------------------------- |
| ToElementType | 归约函数的结果，该结果会作为数组的新元素。 |

## ArrayPredicateFn</a><sup>16+</sup>
type ArrayPredicateFn<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => boolean

ArkTS Array归约函数类型，被Array类的'some'和'every'接口使用，用来判断数组元素是否满足测试条件。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| value | ElementType | 是 | 当前正在处理的元素。|
| index | number | 是 | 当前遍历的ArkTS Array元素下标。 |
| array | ArrayType | 是 | 当前遍历的ArkTS Array本身。 |

**返回值：**

| 类型   | 说明                          |
| ------ | --------------------------- |
| boolean | 归约函数的结果，该结果作为判断当前元素是否通过测试条件。 |

## ArrayReduceCallback</a><sup>16+</sup>
type ArrayReduceCallback<AccType, ElementType, ArrayType> =
    (previousValue: AccType, currentValue: ElementType, currentIndex: number, array: ArrayType) => AccType

ArkTS Array归约函数类型，被Array类的'reduceRight'接口使用。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| previousValue | AccType | 是 | 当前遍历所累积的值。|
| currentValue | ElementType | 是 | 当前遍历的ArkTS Array元素。 |
| currentIndex | number | 是 | 当前遍历的ArkTS Array元素下标。 |
| array | ArrayType | 是 | 当前遍历的ArkTS Array实例。 |

**返回值：**

| 类型   | 说明                          |
| ------ | --------------------------- |
| AccType | 归约函数的结果，该结果会作为下一次调用ArrayReduceCallback时的previousValue参数。 |

## collections.Array

一种线性数据结构，底层基于数组实现，可以在ArkTS上并发实例间传递。

当需要在ArkTS上并发实例间传递Array时，可以通过传递Array引用提升传递性能。

文档中存在泛型的使用，涉及以下泛型标记符：

- T：Type，支持[Sendable支持的数据类型](../../arkts-utils/arkts-sendable.md#sendable支持的数据类型)。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称   | 类型   | 只读 | 可选 | 说明              |
| ------ | ------ | ---- | ---- | ----------------- |
| length | number | 是   | 否   | Array的元素个数。 |


### constructor

**构造函数**

constructor()

创建一个ArkTS Array的构造函数。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                            |
| -------- | --------------------------------------------------- |
| 10200012 | The Array's constructor cannot be directly invoked. |

**示例：**

```ts
let array = new collections.Array<number>();
```

### constructor

constructor(first: T, ...left: T[])

ArkTS Array的构造函数，通过开发者提供的元素进行初始化。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明                            |
| ------ | ---- | ---- | ------------------------------- |
| first  | T    | 是   | 初始化ArkTS Array的第一个元素。 |
| left   | T[]  | 否   | 初始化ArkTS Array的剩余元素。   |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                            |
| -------- | --------------------------------------------------- |
| 10200012 | The Array's constructor cannot be directly invoked. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4);
```
### constructor

constructor(...items: T[])

ArkTS Array的构造函数，通过开发者提供的元素进行初始化。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明                            |
| ------ | ---- | ---- | ------------------------------- |
| items  | T[]  | 否   | 初始化ArkTS Array的元素。       |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                            |
| -------- | --------------------------------------------------- |
| 401      | Parameter error.                                    |
| 10200012 | The Array's constructor cannot be directly invoked. |

**示例：**

```ts
let arrayPara  = [1,2,3];
let array = new collections.Array<number>(...arrayPara);
```

### create

static create\<T>(arrayLength: number, initialValue: T): Array\<T>

生成一个固定长度的Array，其中，每个元素的初始值为initialValue。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型          | 必填 | 说明                            |
| --------- | ------------- | ---- | ------------------------------- |
| arrayLength | number | 是   | 用于构造ArkTS Array的长度。 |
| initialValue | T | 是   | 用于填充ArkTS Array的值。 |

**返回值：**

| 类型      | 说明                    |
| --------- | ----------------------- |
| Array\<T> | 新创建的ArkTS Array实例。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 10200011 | The create method cannot be bound. |

**示例：**

```ts
let array = collections.Array.create<number>(3, 10); // [10, 10, 10]
```

### from

static from\<T>(arrayLike: ArrayLike\<T>): Array\<T>

从一个实现了ArrayLike接口的对象创建一个新的ArkTS Array。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型          | 必填 | 说明                            |
| --------- | ------------- | ---- | ------------------------------- |
| arrayLike | ArrayLike\<T> | 是   | 用于构造ArkTS Array的对象。 |

**返回值：**

| 类型      | 说明                    |
| --------- | ----------------------- |
| Array\<T> | 新创建的ArkTS Array实例。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 10200011 | The from method cannot be bound. |

**示例：**

```ts
// 正例
let array : Array<string> = ['str1', 'str2', 'str3']; // 原生Array<T>，T是Sendable数据类型。
let sendableArray = collections.Array.from<string>(array); // 返回Sendable Array<T>
```

<!--code_no_check-->
```ts
// 反例
let array : Array<Array<string>> = [['str1', 'str2', 'str3'], ['str4', 'str5', 'str6'], ['str7', 'str8', 'str9']]; // 原生Array<T>，T是非Sendable数据类型。
let sendableArray = collections.Array.from<Array<string>>(array); // 打印异常信息：Parameter error.Only accept sendable value
```

### from<sup>12+</sup>

static from\<T>(iterable: Iterable\<T>): Array\<T>

从一个实现了Iterable接口的对象创建一个新的ArkTS Array。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型          | 必填 | 说明                            |
| --------- | ------------- | ---- | ------------------------------- |
| iterable | Iterable\<T> | 是   | 用于构造ArkTS Array的对象。 |

**返回值：**

| 类型      | 说明                    |
| --------- | ----------------------- |
| Array\<T> | 新创建的ArkTS Array实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The from method cannot be bound. |

**示例：**

```ts
// 正例
const mapper = new Map([
  ['1', 'a'],
  ['2', 'b'],
]);
let newArray: collections.Array<string> = collections.Array.from(mapper.values());
console.info(newArray.toString());
// 预期输出： a,b
```

### from<sup>16+</sup>

static from\<T>(arrayLike: ArrayLike\<T> | Iterable\<T>, mapFn: ArrayFromMapFn\<T, T>): Array\<T>

从一个实现了ArrayLike接口的对象创建一个新的ArkTS Array，并且使用自定义函数处理每个数组元素。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型          | 必填 | 说明                            |
| --------- | ------------- | ---- | ------------------------------- |
| arrayLike | ArrayLike\<T> \| Iterable\<T> | 是   | 用于构造ArkTS Array的对象。 |
| mapFn | ArrayFromMapFn\<T,T> | 是   | 调用数组每个元素的函数。 |

**返回值：**

| 类型      | 说明                    |
| --------- | ----------------------- |
| Array\<T> | 新创建的ArkTS Array实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The from method cannot be bound. |

**示例：**

```ts
let array : Array<number> = [1, 2, 3]; // 原生Array<T>，T是Sendable数据类型。
let newarray = collections.Array.from<number, number>(array, (value, index) => value + index); // 返回新的 Array<T>
console.info(newarray.toString());
// 预期输出： 1, 3, 5
```

### from<sup>16+</sup>

static from\<U, T>(arrayLike: ArrayLike\<U> | Iterable\<U>, mapFn: ArrayFromMapFn\<U, T>): Array\<T>

从一个实现了ArrayLike接口的对象创建一个新的ArkTS Array，并且使用自定义函数处理每个数组元素，ArrayLike接口对象的元素类型可以数组元素的类型不一样。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型          | 必填 | 说明                            |
| --------- | ------------- | ---- | ------------------------------- |
| arrayLike | ArrayLike\<U> \| Iterable\<U> | 是   | 用于构造ArkTS Array的对象。 |
| mapFn | ArrayFromMapFn\<U, T> | 是   | 调用数组每个元素的函数。 |

**返回值：**

| 类型      | 说明                    |
| --------- | ----------------------- |
| Array\<T> | 新创建的ArkTS Array实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The from method cannot be bound. |

**示例：**

```ts
let array : Array<number> = [1, 2, 3]; // 原生Array<T>
let newarray = collections.Array.from<number, string>(array, (value, index) => value + "." + index); // 返回新的 Array<T>
console.info(newarray.toString());
// 预期输出： 1.0, 2.1, 3.2
```

### isArray<sup>16+</sup>

static isArray\<T>(value: Object | undefined | null): boolean

检查传入的参数是否是一个ArkTS Array。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型          | 必填 | 说明                            |
| --------- | ------------- | ---- | ------------------------------- |
| value | Object \| undefined \| null | 是   | 需要被检查的值。 |

**返回值：**

| 类型      | 说明                    |
| --------- | ----------------------- |
| boolean | 假如给定对象是ArkTS Array数组，返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
let arr: collections.Array<string> = new collections.Array('a', 'b', 'c', 'd')
let result: boolean = collections.Array.isArray(arr);
console.info(result + '');
// 预期输出： true
```

### of<sup>16+</sup>

static of\<T>(...items: T\[]): Array\<T>

通过可变数量的参数创建一个新的ArkTS Array。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型          | 必填 | 说明                            |
| --------- | ------------- | ---- | ------------------------------- |
| items | T[] | 否   | 用于创建数组的元素集合，参数个数可以是0个、1个或者多个。 |

**返回值：**

| 类型      | 说明                    |
| --------- | ----------------------- |
| Array\<T> | 新的ArkTS Array实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
let arr: collections.Array<string> = collections.Array.of('a', 'b', 'c', 'd')
console.info(arr.toString());
// 预期输出： a, b, c, d
```

### copyWithin<sup>16+</sup>
copyWithin(target: number, start: number, end?: number): Array\<T>

从ArkTS Array指定范围内的元素依次拷贝到目标位置。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| target | number | 是 | 目标起始位置的下标。 |
| start | number | 是 | 源起始位置下标，如果`start < 0`，则会从`start + array.length`位置开始。 |
| end | number | 否 | 源终止位置下标，如果`end < 0`，则会从`end + array.length`位置终止。默认为ArkTS Array的长度。|

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| Array\<T> | 修改后的Array。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------ |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The copyWithin method cannot be bound.           |
| 10200201 | Concurrent modification exception.               |

**示例：**

```ts
let array: collections.Array<number> = collections.Array.from([1, 2, 3, 4, 5, 6, 7, 8]);
let copied: collections.Array<number> = array.copyWithin(3, 1, 3);
console.info(copied.toString());
// 预期输出： 1, 2, 3, 2, 3, 6, 7, 8
```

### lastIndexOf<sup>16+</sup>

lastIndexOf(searchElement: T, fromIndex?: number): number

返回ArkTS Array实例中最后一次出现searchElement的索引，如果对象不包含，则为-1。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名           | 类型     | 必填  | 说明                                                                                |
| ------------- | ------ | --- | --------------------------------------------------------------------------------- |
| searchElement | T | 是   | 待索引的值。                                                                            |
| fromIndex     | number | 否   | 搜索的起始下标。默认值为0。如果下标大于等于ArkTS Array的长度，则返回-1。如果提供的下标值是负数，则从数组末尾开始倒数计数：使用 fromIndex + array.length 的值。 |

**返回值：**

| 类型     | 说明                      |
| ------ | ----------------------- |
| number | 数组中元素的最后一个索引；没有找到，则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID    | 错误信息                                    |
| -------- | --------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range. |
| 10200011 | The lastIndexOf method cannot be bound. |
| 10200201 | Concurrent modification exception.      |

**示例：**

```ts
let array: collections.Array<number> = collections.Array.from([3, 5, 9]);
console.info(array.lastIndexOf(3) + '');
// 预期输出： 0
console.info(array.lastIndexOf(7) + '');
// 预期输出： -1
console.info(array.lastIndexOf(9, 2) + '');
// 预期输出： 2
console.info(array.lastIndexOf(9, -2) + '');
// 预期输出： -1
```

### some<sup>16+</sup>
some(predicate: ArrayPredicateFn\<T, Array\<T>>): boolean

测试ArkTS Array是否存在满足指定条件的元素。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                  |
| ------- | ------ | ---- | ---------------------------------------------------- |
| predicate | ArrayPredicateFn\<T, Array> | 是 | 用于测试的断言函数。|

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| boolean | 如果存在元素满足指定条件返回true，否则返回false。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                            |
| -------- | ---------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 10200011 | The some method cannot be bound.   |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
let newArray: collections.Array<number> = collections.Array.from([-10, 20, -30, 40, -50]);
console.info(newArray.some((element: number) => element < 0) + '');
// 预期输出： true
```

### reduceRight<sup>16+</sup>

reduceRight(callbackFn: ArrayReduceCallback\<T, T, Array\<T>>): T

对Array中的每个元素按照从右到左顺序执行回调函数，将其结果作为累加值，并返回最终的结果。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名        | 类型                                                                               | 必填  | 说明                                         |
| ---------- | -------------------------------------------------------------------------------- | --- | ------------------------------------------ |
| callbackFn | ArrayReduceCallback\<T, T, Array\<T>> | 是   | 一个接受四个参数的函数，用于对每个元素执行操作，并将结果作为累加值传递给下一个元素。 |

**返回值：**

| 类型  | 说明            |
| --- | ------------- |
| T   | 回调函数执行后的最终结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID    | 错误信息                                    |
| -------- | --------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 10200011 | The reduceRight method cannot be bound. |
| 10200201 | Concurrent modification error.          |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let reducedValue = array.reduceRight((accumulator, value) => accumulator + value); // 累加所有元素
console.info(reducedValue + '');
// 预期输出： 15
```

### reduceRight<sup>16+</sup>

reduceRight\<U = T>(callbackFn: ArrayReduceCallback\<U, T, Array\<T>>, initialValue: U): U

与 reduceRight方法类似，但它接受一个初始值作为第二个参数，用于在Array从右到左顺序遍历开始前初始化累加器。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名          | 类型                                                                                           | 必填  | 说明                                         |
| ------------ | -------------------------------------------------------------------------------------------- | --- | ------------------------------------------ |
| callbackFn   | ArrayReduceCallback\<U, T, Array\<T>> | 是   | 一个接受四个参数的函数，用于对每个元素执行操作，并将结果作为累加值传递给下一个元素。 |
| initialValue | U                                                                                            | 是   | 用于初始化累加器的值。                                |

**返回值：**

| 类型  | 说明            |
| --- | ------------- |
| U   | 回调函数执行后的最终结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID    | 错误信息                                    |
| -------- | --------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 10200011 | The reduceRight method cannot be bound. |
| 10200201 | Concurrent modification error.          |

**示例：**

```ts
// 此处使用一个初始值为0的累加器，并将其与Array中的每个元素相加，最终返回累加后的总和
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let reducedValue = array.reduceRight<number>((accumulator: number, value: number) => accumulator + value, 0); // 累加所有元素，初始值为0
console.info(reducedValue + '');
// 预期输出： 15
```

### pop

pop(): T | undefined

从ArkTS Array中移除并返回最后一个元素。如果Array为空，则返回undefined，且Array不发生变化。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型           | 说明                                                |
| -------------- | --------------------------------------------------- |
| T \| undefined | 从Array中移除的元素；如果Array为空，则返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 10200011 | The pop method cannot be bound. |
| 10200201 | Concurrent modification error.  |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3);
let lastElement = array.pop(); // 返回3，Array变为[1, 2]
```

### push

push(...items: T[]): number

在ArkTS Array的末尾添加一个或多个元素，并返回新的Array长度。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明                               |
| ------ | ---- | ---- | ---------------------------------- |
| items  | T[]  | 是   | 要添加到Array末尾的一个或多个元素。 |

**返回值：**

| 类型   | 说明               |
| ------ | ------------------ |
| number | 返回新Array的长度。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 10200011 | The push method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3);
let length = array.push(4, 5); // 返回5，Array变为[1, 2, 3, 4, 5]
```

### join

join(separator?: string): string

将ArkTS Array的所有元素连接成一个字符串，元素之间可以用指定的分隔符分隔。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型   | 必填 | 说明                                                 |
| --------- | ------ | ---- | ---------------------------------------------------- |
| separator | string | 否   | 用于分隔Array元素的字符串。如果省略，则使用逗号分隔。 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| string | 包含所有Array元素连接成的字符串。如果Array为空，则返回空字符串。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 10200011 | The join method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**示例：**

```ts
let array = new collections.Array<string>('a', 'b', 'c');
let joinedString = array.join('-'); // 返回 "a-b-c"
```

### shift

shift(): T | undefined

从ArkTS Array中移除并返回第一个元素。如果Array为空，则返回undefined，且Array不发生变化。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型           | 说明                                                |
| -------------- | --------------------------------------------------- |
| T \| undefined | 从Array中移除的元素；如果Array为空，则返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 10200011 | The shift method cannot be bound. |
| 10200201 | Concurrent modification error.    |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3);
let firstElement = array.shift(); // 返回1，Array变为[2, 3]
```

### reverse<sup>16+</sup>

reverse(): Array\<T>

反转ArkTS Array数组中的元素，并返回同一数组的引用。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型    | 说明                 |
| ----- | ------------------ |
| Array | 反转后的ArkTS Array对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID    | 错误信息                                |
| -------- | ----------------------------------- |
| 10200011 | The reverse method cannot be bound. |
| 10200201 | Concurrent modification exception.  |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let reversed = array.reverse();
console.info(array.toString());
// 预期输出： 5, 4, 3, 2, 1
```

### unshift

unshift(...items: T[]): number

在ArkTS Array的首端插入一个或多个元素，并返回新的Array长度。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明                     |
| ------ | ---- | ---- | ------------------------ |
| items  | T[]  | 是   | 要插入到Array首端的元素。 |

**返回值：**

| 类型   | 说明           |
| ------ | -------------- |
| number | 新Array的长度。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 10200011 | The unshift method cannot be bound. |
| 10200201 | Concurrent modification error.      |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3);
let newLength = array.unshift(0); // 返回4，Array变为[0, 1, 2, 3]
```

### toString<sup>16+</sup>

toString(): string

ArkTS数组转换为字符串。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型         | 说明            |
| ---------- | ------------- |
| string | 一个包含数组所有元素的字符串。 |

**错误码：**

以下错误码详细介绍请参考[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID    | 错误信息                                 |
| -------- | ------------------------------------ |
| 10200011 | The toString method cannot be bound. |
| 10200201 | Concurrent modification error.       |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let stringArray = array.toString();
console.info(stringArray);
// 预期输出：1,2,3,4,5
```

### slice

slice(start?: number, end?: number): Array\<T>

返回一个新的Array，该Array是原始ArkTS Array的切片。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**
| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| start  | number | 否   | 开始索引。如果`start < 0`，则会从`start + array.length`位置开始。默认值为0。   |
| end    | number | 否   | 结束索引（不包括该元素）。如果`end < 0`，则会到`end + array.length`位置结束。默认为ArkTS Array的长度。 |

**返回值：**

| 类型      | 说明                       |
| --------- | -------------------------- |
| Array\<T> | 包含原始Array切片的新Array。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                          |
| -------- | --------------------------------- |
| 10200011 | The slice method cannot be bound. |
| 10200201 | Concurrent modification error.    |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let slicedArray = array.slice(1, 3); // 返回[2, 3]，Array保持不变
```

### sort

sort(compareFn?: (a: T, b: T) => number): Array\<T>

对ArkTS Array进行排序，并返回排序后的Array。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型                   | 必填 | 说明                                       |
| --------- | ---------------------- | ---- | ------------------------------------------ |
| compareFn | (a: T, b: T) => number | 否   | 用于确定元素顺序的函数。默认使用升序排序。 |

**返回值：**

| 类型      | 说明           |
| --------- | -------------- |
| Array\<T> | 排序后的Array。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 10200011 | The sort method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**示例：**

```ts
let array = new collections.Array<number>(1, 3, 5, 4, 2);
array.sort((a: number, b: number) => a - b); // [1, 2, 3, 4, 5]
array.sort((a: number, b: number) => b - a); // [5, 4, 3, 2, 1]
```

### indexOf

indexOf(searchElement: T, fromIndex?: number): number

返回在ArkTS Array中搜索元素首次出现的索引，如果不存在则返回-1。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名        | 类型   | 必填 | 说明                        |
| ------------- | ------ | ---- | --------------------------- |
| searchElement | T      | 是   | 要搜索的值。                |
| fromIndex     | number | 否   | 开始搜索的索引。默认值为0。 |

**返回值：**

| 类型   | 说明                                           |
| ------ | ---------------------------------------------- |
| number | 搜索元素首次出现的索引；如果不存在，则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 10200011 | The indexOf method cannot be bound. |
| 10200201 | Concurrent modification error.      |

**示例：**

```ts
let array = new collections.Array<string>('a', 'b', 'c');
let index = array.indexOf('b'); // 返回1，因为'b'在索引1的位置
```

### forEach

forEach(callbackFn: (value: T, index: number, array: Array\<T>) => void): void

对Array中的每个元素执行提供的回调函数。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型                                                | 必填 | 说明                           |
| ---------- | --------------------------------------------------- | ---- | ------------------------------ |
| callbackFn | (value: T, index: number, array: Array\<T>) => void | 是   | 用于对每个元素执行的回调函数。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 10200011 | The forEach method cannot be bound. |
| 10200201 | Concurrent modification error.      |

**示例：**

```ts
let array = new collections.Array<string>('a', 'b', 'c');
array.forEach((value, index, array) => {
  console.info(`Element ${value} at index ${index}`);
});
```

### map

map\<U>(callbackFn: (value: T, index: number, array: Array\<T>) => U): Array\<U>

对Array中的每个元素执行提供的回调函数，并返回一个新的Array，该Array包含回调函数的结果。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型                                             | 必填 | 说明                           |
| ---------- | ------------------------------------------------ | ---- | ------------------------------ |
| callbackFn | (value: T, index: number, array: Array\<T>) => U | 是   | 用于对每个元素执行的回调函数。 |

**返回值：**

| 类型      | 说明                       |
| --------- | -------------------------- |
| Array\<U> | 包含回调函数结果的新Array。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 10200011 | The map method cannot be bound. |
| 10200201 | Concurrent modification error.  |

**示例：**

```ts
// 此处将原始Array中的每个字符串元素转换为大写形式，并返回一个新Array，其中包含转换后的字符串
let array = new collections.Array<string>('a', 'b', 'c');
let mappedArray = array.map((value, index, array) => {
  return value.toUpperCase(); // 将每个字符串元素转换为大写
});
console.info("" + mappedArray); // 输出: ['A', 'B', 'C']
```

### filter

filter(predicate: (value: T, index: number, array: Array\<T>) => boolean): Array\<T>

返回一个新Array，其中包含通过指定回调函数测试的所有元素。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型                                                   | 必填 | 说明                                                         |
| --------- | ------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| predicate | (value: T, index: number, array: Array\<T>) => boolean | 是   | 一个接受三个参数的函数，用于测试每个元素是否应该包含在新Array中。 |

**返回值：**

| 类型      | 说明                         |
| --------- | ---------------------------- |
| Array\<T> | 包含通过测试的元素的新Array。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                           |
| -------- | ---------------------------------- |
| 10200011 | The filter method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let filteredArray = array.filter((value : number) => value % 2 === 0); // 返回[2, 4]，只包含偶数
```

### reduce

reduce(callbackFn: (previousValue: T, currentValue: T, currentIndex: number, array: Array\<T>) => T): T

对Array中的每个元素执行回调函数，将其结果作为累加值，并返回最终的结果。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型                                                         | 必填 | 说明                                                         |
| ---------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callbackFn | (previousValue: T, currentValue: T, currentIndex: number, array: Array\<T>) => T | 是   | 一个接受四个参数的函数，用于对每个元素执行操作，并将结果作为累加值传递给下一个元素。 |

**返回值：**

| 类型 | 说明                       |
| ---- | -------------------------- |
| T    | 回调函数执行后的最终结果。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                           |
| -------- | ---------------------------------- |
| 10200011 | The reduce method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let reducedValue = array.reduce((accumulator, value) => accumulator + value); // 返回15，累加所有元素
```

### reduce

reduce\<U>(callbackFn: (previousValue: U, currentValue: T, currentIndex: number, array: Array\<T>) => U, initialValue: U): U

与 reduce方法类似，但它接受一个初始值作为第二个参数，用于在Array遍历开始前初始化累加器。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名       | 类型                                                         | 必填 | 说明                                                         |
| ------------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| callbackFn   | callbackFn: (previousValue: U, currentValue: T, currentIndex: number, array: Array\<T>) => U | 是   | 一个接受四个参数的函数，用于对每个元素执行操作，并将结果作为累加值传递给下一个元素。 |
| initialValue | U                                                            | 是   | 用于初始化累加器的值。                                       |

**返回值：**

| 类型 | 说明                       |
| ---- | -------------------------- |
| U    | 回调函数执行后的最终结果。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                           |
| -------- | ---------------------------------- |
| 10200011 | The reduce method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**示例：**

```ts
// 此处使用一个初始值为0的累加器，并将其与Array中的每个元素相加，最终返回累加后的总和
let array = new collections.Array(1, 2, 3, 4, 5);
let reducedValue = array.reduce<number>((accumulator: number, value: number) => accumulator + value, 0); // 返回15，累加所有元素，初始值为0
```

### at

at(index: number): T | undefined

返回Array中指定索引位置的元素。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| index  | number | 是   | 要返回的Array元素的索引（从零开始），取值为整数。负数索引从Array末尾开始计数，如果`index < 0`，则会访问`index + array.length`位置的元素。 |


**返回值：**

| 类型           | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| T \| undefined | 返回指定索引处的元素；如果索引超出范围或无效，则返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                       |
| -------- | ------------------------------ |
| 10200011 | The at method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let elementAtIndex = array.at(2); // 返回3，因为索引是从0开始的
```

### entries

entries(): IterableIterator<[number, T]>

返回一个新的可迭代对象，该对象包含Array中每个元素的键值对。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                          | 说明                                       |
| ----------------------------- | ------------------------------------------ |
| IterableIterator<[number, T]> | 包含Array中每个元素的键值对的迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                            |
| -------- | ----------------------------------- |
| 10200011 | The entries method cannot be bound. |
| 10200201 | Concurrent modification error.      |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let iterator = array.entries();
console.info(iterator.next().value); // 输出：[0, 1]，第一个元素的键值对
```

### keys

keys(): IterableIterator\<number>

返回一个新的可迭代对象，该对象包含Array中每个元素的键。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                      | 说明                                   |
| ------------------------- | -------------------------------------- |
| IterableIterator\<number> | 包含Array中每个元素的键的可迭代迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 10200011 | The keys method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let iterator = array.keys();
for (const key of iterator) {
  console.info("" + key); // 依次输出 0,1,2,3,4
}
```

### values

values(): IterableIterator\<T>

返回一个新的可迭代对象，该对象包含Array中每个元素的值。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                 | 说明                                   |
| -------------------- | -------------------------------------- |
| IterableIterator\<T> | 包含Array中每个元素的值的可迭代迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                           |
| -------- | ---------------------------------- |
| 10200011 | The values method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let iterator = array.values();
for(const value of iterator) {
  console.info("" + value); // 依次输出 1,2,3,4,5
}
```

### find

find(predicate: (value: T, index: number, obj: Array\<T>) => boolean): T | undefined

返回Array中第一个满足指定测试函数的元素的值，如果所有元素都不满足，则返回undefined。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型                                                 | 必填 | 说明                                                   |
| --------- | ---------------------------------------------------- | ---- | ------------------------------------------------------ |
| predicate | (value: T, index: number, obj: Array\<T>) => boolean | 是   | 一个接受三个参数的函数，用于测试每个元素是否满足条件。 |

**返回值：**

| 类型           | 说明                                                         |
| -------------- | ------------------------------------------------------------ |
| T \| undefined | 第一个满足条件的元素的值；如果所有元素都不满足条件，则返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 10200011 | The find method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let foundValue = array.find((value: number) => value % 2 === 0); // 返回2，第一个偶数元素
```

### includes

includes(searchElement: T, fromIndex?: number): boolean

判断Array是否包含指定的元素，并返回一个布尔值。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名        | 类型   | 必填 | 说明                        |
| ------------- | ------ | ---- | --------------------------- |
| searchElement | T      | 是   | 要搜索的元素。              |
| fromIndex     | number | 否   | 开始搜索的索引。默认值为0。 |

**返回值：**

| 类型    | 说明                                                |
| ------- | --------------------------------------------------- |
| boolean | 如果Array包含指定的元素，则返回true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                             |
| -------- | ------------------------------------ |
| 10200011 | The includes method cannot be bound. |
| 10200201 | Concurrent modification error.       |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let includesResult = array.includes(3); // 返回true，因为Array中包含3
```

### findIndex

findIndex(predicate: (value: T, index: number, obj: Array\<T>) => boolean): number

返回Array中第一个满足指定测试函数的元素的索引，如果所有元素都不满足，则返回-1。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型                                                 | 必填 | 说明                                                   |
| --------- | ---------------------------------------------------- | ---- | ------------------------------------------------------ |
| predicate | (value: T, index: number, obj: Array\<T>) => boolean | 是   | 一个接受三个参数的函数，用于测试每个元素是否满足条件。 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 第一个满足条件的元素的索引；如果所有元素都不满足条件，则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                              |
| -------- | ------------------------------------- |
| 10200011 | The findIndex method cannot be bound. |
| 10200201 | Concurrent modification error.        |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let foundIndex = array.findIndex((value: number) => value % 2 === 0); // 返回1，因为2是第一个偶数元素
```

### fill

fill(value: T, start?: number, end?: number): Array\<T>

使用指定的值填充Array中指定范围的所有元素。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                   |
| ------ | ------ | ---- | ------------------------------------------------------ |
| value  | T      | 是   | 要填充的值。                                           |
| start  | number | 否   | 开始填充的索引。默认值为0。                            |
| end    | number | 否   | 结束填充的索引（不包括该元素）。如果省略，则填充到Array的最后一个元素。 |

**返回值：**

| 类型      | 说明           |
| --------- | -------------- |
| Array\<T> | 填充后的Array。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 10200011 | The fill method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**示例：**

```ts
let array = new collections.Array(1, 2, 3, 4, 5);
array.fill(0, 1, 3); // 返回[1, 0, 0, 4, 5]，因为1到3的索引范围内的元素被替换为0
```

### shrinkTo

shrinkTo(arrayLength: number): void

使Array收缩到指定长度。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                   |
| ------ | ------ | ---- | ------------------------------------------------------ |
| arrayLength  | number  | 是   | Array的新长度。如果arrayLength >= array.length，则Array不变。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 10200011 | The shrinkTo method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**示例：**

```ts
let array1 = new collections.Array(1, 2, 3, 4, 5);
array1.shrinkTo(1); // array内容变为：[1]

let array2 = new collections.Array(1, 2, 3, 4, 5);
array2.shrinkTo(10); // array内容不变
```

### extendTo

extendTo(arrayLength: number, initialValue: T): void

使Array扩展到指定长度，扩展的部分使用给定值填充。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                   |
| ------ | ------ | ---- | ------------------------------------------------------ |
| arrayLength  | number  | 是   | Array的新长度。如果arrayLength <= array.length，则Array不变。 |
| initialValue  | T  | 是   | 扩展的部分的填充值。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 10200011 | The extendTo method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**示例：**

```ts
let array1 = new collections.Array(1, 2, 3);
array1.extendTo(5, 10); // array内容变为：[1, 2, 3, 10, 10]

let array2 = new collections.Array(1, 2, 3);
array2.extendTo(1, 10); // array内容不变
```

### concat

concat(...items: ConcatArray\<T>[]): Array\<T>

拼接两个或多个数组。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明                               |
| ------ | ---- | ---- | ---------------------------------- |
| items  | ConcatArray\<T>[]  | 是   | 拼接两个或多个数组。 |

**返回值：**

| 类型 | 说明                               |
| ---- | ---------------------------------- |
| Array\<T>  | 拼接后的数组。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                         |
| ------- | -------- |
| 401 |  Parameter error. Not a valid array. |
| 10200011 | The concat method cannot be bound. |
| 10200201 | Concurrent modification error.   |

**示例：**

```ts
let array = new collections.Array(1, 2, 3);
let array1 = new collections.Array(4, 5, 6);
let array2 = new collections.Array(7, 8, 9);

let concatArray = array.concat(array1, array2); // concatArray的内容为：[1, 2, 3, 4, 5, 6, 7, 8, 9]
```

### splice

splice(start: number): Array\<T>

删除Array中指定位置的元素。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型  | 必填 | 说明                                                                |
| ----- | ------ | -- | ------------------------------------------------------------------- |
| start | number | 是 | 开始索引。如果`-array.length =< start < 0`，从`start + array.length`开始，如果`start < -array.length`，则从0开始。 |

**返回值：**

| 类型      | 说明                   |
| --------- | --------------------- |
| Array\<T> | 返回一个新的包含被删除元素的Array对象。如果没有元素被删除，返回一个空的Array对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                            |
| -------- | ---------------------------------- |
| 401      | Parameter error. Possible causes:<br/>1.Mandatory parameters are left unspecified；<br/>2.Incorrect parameter types. |
| 10200011 | The splice method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let removeArray = array.splice(2); // array内容变为[1, 2]，返回[3, 4, 5]
```

### every<sup>16+</sup>

every(predicate: ArrayPredicateFn\<T, Array\<T>>): boolean

测试ArkTS Array中的所有元素是否满足指定条件。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**
| 参数名  | 类型   | 必填 | 说明                                                    |
| ------- | ------ | ---- | ----------------------------------------------------- |
| predicate | ArrayPredicateFn\<T, Array\<T>> | 是 | 用于测试的断言函数。|

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| boolean | 如果所有元素都满足指定条件则返回true，否则返回false。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 10200011 | The every method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
let newArray: collections.Array<number> = collections.Array.from([-10, 20, -30, 40, -50]);
console.info(newArray.every((element: number) => element > 0) + '');
// 预期输出：false
```

### toLocaleString<sup>16+</sup>

toLocaleString(): string

根据当前应用的系统地区获取符合当前文化习惯的字符串表示形式，让每个元素调用自己的toLocaleString方法转换为字符串，然后使用逗号将每个元素的结果字符串按照顺序拼接成字符串。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型         | 说明            |
| ---------- | ------------- |
| string | 一个包含数组所有元素的字符串。 |

**错误码：**

以下错误码详细介绍请参考[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID    | 错误信息                                       |
| -------- | ------------------------------------------ |
| 10200011 | The toLocaleString method cannot be bound. |
| 10200201 | Concurrent modification error.             |

**示例：**

```ts
// 当前应用所在系统为法国地区
let array = new collections.Array<number | string>(1000, 'Test', 53621);
let stringArray = array.toLocaleString();
console.info(stringArray);
// 预期输出：1,000,Test,53,621
```

### splice

splice(start: number, deleteCount: number, ...items: T[]): Array\<T>

删除Array中指定位置的元素，需要时在Array的指定位置插入新元素。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名       | 类型   | 必填 | 说明                                                                |
| ----------- | ------ | --  | ------------------------------------------------------------------- |
| start       | number | 是  | 开始索引。如果`-array.length =< start < 0`，从`start + array.length`开始，如果`start < -array.length`，则从0开始。 |
| deleteCount | number | 是  | 删除元素的个数。                                                      |
| items       | T[]    | 否  | 从`start`位置开始插入的新元素。如果省略，仅删除Array内的指定元素。        |

**返回值：**

| 类型      | 说明                                  |
| --------- | ------------------------------------ |
| Array\<T> | 返回一个新的包含被删除元素的Array对象。如果没有元素被删除，返回一个空的Array对象。 |

**错误码：**

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                            |
| -------- | ---------------------------------- |
| 401      | Parameter error. Possible causes:<br/>1.Mandatory parameters are left unspecified；<br/>2.Incorrect parameter types. |
| 10200011 | The splice method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**示例：**

```ts
// 例1：
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let removeArray = array.splice(2, 2); // array内容变为[1, 2, 5]，返回[3, 4]
```

```ts
// 例2：
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let removeArray = array.splice(2, 2, 6, 7, 8); // array内容变为[1, 2, 6, 7, 8, 5]，返回[3, 4]
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象，并返回该对象。

> **说明：**
>
> 本接口不支持在.ets文件中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                      | 说明             |
| ------------------------- | ---------------- |
| IterableIterator&lt;T&gt; | 返回一个迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**示例：**

```ts
let array= new collections.Array<number>(1, 2, 3, 4);

for (let item of array) {
  console.info(`value : ${item}`);
}
```

### [index: number]

&#91;index: number&#93;: T

返回Array指定索引位置的元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 参数名    | 类型   | 必填 | 说明                                                            |
| ----- | ------ | ---- | ------------------------------------------------------------------ |
| index | number | 是   | 所需代码单元的从零开始的索引。当index<0 或者index>=length，则会抛出错误。 |

**返回值：**

| 类型   | 说明                     |
| ----- | ------------------------ |
|   T   | Array给定的元素数据类型。  |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                             |
| ------- | ------------------------------------ |
| 401 |        Parameter error.                  |
| 10200001 | The value of index is out of range. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 4);
console.info("Element at index 1: ", array[1]);
```

## collections.Map

一种非线性数据结构。

文档中存在泛型的使用，涉及以下泛型标记符：

- K：Key，键
- V：Value，值

K和V类型都需为[Sendable支持的数据类型](../../arkts-utils/arkts-sendable.md#sendable支持的数据类型)。

### 属性

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型   | 只读 | 可选 | 说明            |
| ---- | ------ | ---- | ---- | --------------- |
| size | number | 是   | 否   | Map的元素个数。 |


### constructor
constructor(entries?: readonly (readonly [K, V])[] | null)

构造函数，用于创建ArkTS Map对象。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| entries | [K, V][] \| null | 否   | 键值对数组或其它可迭代对象。默认值为null，创建一个空Map对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 10200012 | The ArkTS Map's constructor cannot be directly invoked. |

**示例：**

```ts
// 正例1：
const myMap = new collections.Map<number, number>();
```

```ts
// 正例2：
const myMap = new collections.Map<number, string>([
  [1, "one"],
  [2, "two"],
  [3, "three"],
]);
```

<!--code_no_check-->
```ts
// 反例：
@Sendable
class SharedClass {
  constructor() {
  }
}
let sObj = new SharedClass();
const myMap1: collections.Map<number, SharedClass> = new collections.Map<number, SharedClass>([[1, sObj]]);
// Type arguments of generic "Sendable" type must be a "Sendable" data type (arkts-sendable-generic-types)
let obj = new Object();
const myMap2: collections.Map<number, Object> = new collections.Map<number, Object>([[1, obj]]);
```

### entries
entries(): IterableIterator<[K, V]>

返回一个Map迭代器对象，该对象包含了此Map中的每个元素的[key, value]对。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                           | 说明                    |
| ------------------------------ | ----------------------- |
| IterableIterator&lt;[K, V]&gt; | 返回一个Map迭代器对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                              |
| -------- | ----------------------------------------------------- |
| 10200011 | The entries method cannot be bound with non-sendable. |

**示例：**

```ts
// 例1：
const myMap = new collections.Map<number, string>([
  [0, "foo"],
  [1, "bar"]
]);

const iterator = myMap.entries();
// Expected output: [0, "foo"]
console.info(iterator.next().value);
// Expected output: [1, "bar"]
console.info(iterator.next().value);
```

```ts
// 例2：
const myMap: collections.Map<number, string> = new collections.Map<number, string>([
  [0, "one"],
  [1, "two"],
  [2, "three"],
  [3, "four"]
]);
const entriesIter: IterableIterator<[number, string]> = myMap.entries();
for (const entry of entriesIter) {
  if (entry[1].startsWith('t')) {
    myMap.delete(entry[0]);
  }
}
// Expected output: 2
console.info("size:" + myMap.size);
```

### keys
keys(): IterableIterator\<K>

返回一个Map迭代器对象，该对象包含了此Map中每个元素的键。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                      | 说明                    |
| ------------------------- | ----------------------- |
| IterableIterator&lt;K&gt; | 返回一个Map迭代器对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                           |
| -------- | -------------------------------------------------- |
| 10200011 | The keys method cannot be bound with non-sendable. |

**示例：**

```ts
const myMap = new collections.Map<number, string>([
  [0, "foo"],
  [1, "bar"]
]);

const iterator = myMap.keys();
// Expected output: 0
console.info(iterator.next().value);
// Expected output: 1
console.info(iterator.next().value);
```

### values
values(): IterableIterator\<V>

返回一个Map迭代器对象，该对象包含此Map中每个元素的值。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                      | 说明                    |
| ------------------------- | ----------------------- |
| IterableIterator&lt;V&gt; | 返回一个Map迭代器对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 10200011 | The values method cannot be bound with non-sendable. |

**示例：**

```ts
const myMap = new collections.Map<number, string>([
  [0, "foo"],
  [1, "bar"]
]);

const iterator = myMap.values();
// Expected output: "foo"
console.info(iterator.next().value);
// Expected output: "bar"
console.info(iterator.next().value);
```

### clear
clear(): void

删除该Map中的所有元素。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                            |
| -------- | --------------------------------------------------- |
| 10200011 | The clear method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                  |

**示例：**

```ts
const myMap = new collections.Map<number, string>([
  [0, "foo"],
  [1, "bar"]
]);
// Expected output: 2
console.info("size:" + myMap.size);
myMap.clear();
// Expected output: 0
console.info("size:" + myMap.size);
```

### delete
delete(key: K): boolean

删除该Map中指定元素。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明             |
| ------ | ---- | ---- | ---------------- |
| key    | K    | 是   | 待删除元素的键。 |

**返回值：**

| 类型    | 说明                                                         |
| ------- | ------------------------------------------------------------ |
| boolean | 如果元素存在并已被删除，则为true；否则该元素不存在，返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 10200011 | The delete method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                   |


**示例：**

```ts
const myMap = new collections.Map<string, string>([
  ["hello", "world"],
]);
// Expected result: true
console.info("result:" + myMap.delete("hello"));
// Expected result: false
console.info("result:" + myMap.has("hello"));
// Expected result: false
console.info("result:" + myMap.delete("hello"));
```

### forEach
forEach(callbackFn: (value: V, key: K, map: Map<K, V>) => void): void

按插入顺序对该Map中的每个键/值对执行一次回调函数。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型                                       | 必填 | 说明       |
| ---------- | ------------------------------------------ | ---- | ---------- |
| callbackFn | (value: V, key: K, map: Map<K, V>) => void | 是   | 回调函数。 |

callbackFn的参数说明：
| 参数名 | 类型            | 必填 | 说明                         |
| ------ | --------------- | ---- | ---------------------------- |
| value  | V               | 否   | 当前遍历到的元素键值对的值。 |
| key    | K               | 否   | 当前遍历到的元素键值对的键。 |
| map    | Map&lt;K, V&gt; | 否   | 当前map实例对象。            |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                              |
| -------- | ----------------------------------------------------- |
| 10200011 | The forEach method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                    |

**示例：**

```ts
// 正例：
new collections.Map<string, number>([
  ['foo', 0],
  ['bar', 1],
  ['baz', 2],
]).forEach((value, key, map) => {
  console.info(`m[${key}] = ${value}`);
});
```

<!--code_no_check-->
```ts
// 反例：
new collections.Map<string, number>([
  ['foo', 0],
  ['bar', 1],
  ['baz', 2],
]).forEach((value, key, map) => {
  // Throw exception `Concurrent modification exception.`
  map.delete(key);
});
```

### get
get(key: K): V | undefined

返回该Map中的指定元素。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明      |
| ------ | ---- | ---- | --------- |
| key    | K    | 是   | 指定key。 |

**返回值：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| V    | 与指定键相关联的元素，如果键在Map对象中找不到，则返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The get method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                |

**示例：**

```ts
const myMap = new collections.Map<string, string>([
  ["hello", "world"],
]);
// Expected output: "world"
console.info(myMap.get("hello"));
// Expected output: undefined
console.info(myMap.get("world"));
```

### has
has(key: K): boolean

判断该Map中是否存在指定元素。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果存在指定元素，则返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The has method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                |

**示例：**

```ts
const myMap = new collections.Map<string, string>([
  ["hello", "world"],
]);
// Expected output: true
console.info("result:" + myMap.has("hello"));
// Expected output: false
console.info("result:" + myMap.has("world"));
```

### set
set(key: K, value: V): Map<K, V>

向该Map添加或更新一个指定的键值对。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型            | 说明    |
| --------------- | ------- |
| Map&lt;K, V&gt; | Map对象 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The set method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                |

**示例：**

```ts
// 正例：
const myMap = new collections.Map<string, string>();
myMap.set("foo", "bar")
```

<!--code_no_check-->
```ts
// 反例：
let obj = new Object();
const myMap: collections.Map<string, Object> = new collections.Map<string, Object>();
// Type arguments of generic "Sendable" type must be a "Sendable" data type (arkts-sendable-generic-types)
myMap.set("foo", obj);
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[K, V]&gt;

返回一个迭代器，迭代器的每一项都是一个JavaScript对象，并返回该对象。

> **说明：**
>
> 本接口不支持在.ets文件中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| IterableIterator<[K, V]> | 返回一个迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**示例：**

```ts
let map = new collections.Map<number, string>([
    [0, "one"],
    [1, "two"],
    [2, "three"],
    [3, "four"]
]);

let keys = Array.from(map.keys());
for (let key of keys) {
  console.info("key:" + key);
  console.info("value:" + map.get(key));
}
```

## collections.Set

一种非线性数据结构。

文档中存在泛型的使用，涉及以下泛型标记符：

- T：Type，支持[Sendable支持的数据类型](../../arkts-utils/arkts-sendable.md#sendable支持的数据类型)。

### 属性

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型   | 只读 | 可选 | 说明            |
| ---- | ------ | ---- | ---- | --------------- |
| size | number | 是   | 否   | Set的元素个数。 |

### constructor

constructor(values?: readonly T[] | null)

构造函数，用于创建ArkTS Set对象。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                      |
| ------ | ---- | ---- | --------------------------------------------------------- |
| values | T[] \| null | 否 | 数组或其它可迭代对象。默认值为null，创建一个空Set对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 10200012 | The ArkTS Set's constructor cannot be directly invoked. |

**示例：**

```ts
// 正例1：
const mySet = new collections.Set<number>();
```

```ts
// 正例2：
const mySet = new collections.Set<number>([1, 2, 3, 4, 5]);
```

<!--code_no_check-->
```ts
// 反例：
@Sendable
class SharedClass {
  constructor() {
  }
}

let sObj = new SharedClass();
const mySet1: collections.Set<number|SharedClass> = new collections.Set<number|SharedClass>([1, sObj]);
// Type arguments of generic "Sendable" type must be a "Sendable" data type (arkts-sendable-generic-types)
let obj = new Object();
const mySet2: collections.Set<number|SharedClass> = new collections.Set<number|Object>([1, obj]);
```

### entries
entries(): IterableIterator<[T, T]>

返回一个Set迭代器对象。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                           | 说明                    |
| ------------------------------ | ----------------------- |
| IterableIterator&lt;[T, T]&gt; | 返回一个Set迭代器对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                              |
| -------- | ----------------------------------------------------- |
| 10200011 | The entries method cannot be bound with non-sendable. |

**示例：**

```ts
const mySet = new collections.Set<number>([0, 1, 2, 3]);

const iterator = mySet.entries();
// Expected output: [0, 0]
console.info(iterator.next().value);
// Expected output: [1, 1]
console.info(iterator.next().value);
```

### keys
keys(): IterableIterator\<T>

返回一个Set迭代器对象，该对象包含了此Set中每个元素的值。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                      | 说明                    |
| ------------------------- | ----------------------- |
| IterableIterator&lt;T&gt; | 返回一个Set迭代器对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                           |
| -------- | -------------------------------------------------- |
| 10200011 | The keys method cannot be bound with non-sendable. |

**示例：**

```ts
const mySet = new collections.Set<number>([0, 1, 2, 3]);

const iterator = mySet.keys();
// Expected output: 0
console.info(iterator.next().value);
// Expected output: 1
console.info(iterator.next().value);
```

### values
values(): IterableIterator\<T>

返回一个Set迭代器对象，该对象包含了此Set中每个元素的值。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                      | 说明                    |
| ------------------------- | ----------------------- |
| IterableIterator&lt;T&gt; | 返回一个Set迭代器对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 10200011 | The values method cannot be bound with non-sendable. |

**示例：**

```ts
// 例1：
const mySet = new collections.Set<number>([0, 1, 2, 3]);

const iterator = mySet.values();
// Expected output: 0
console.info(iterator.next().value);
// Expected output: 1
console.info(iterator.next().value);
```

```ts
// 例2：
const mySet = new collections.Set<number>([0, 1, 2, 3]);

const valueIter = mySet.values();
for (let value of valueIter) {
    if (value % 2 == 0) {
        mySet.delete(value);
    }
}

// Expected output: 2
console.info("size:" + mySet.size);
```

### clear
clear(): void

删除该Set中的所有元素。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                            |
| -------- | --------------------------------------------------- |
| 10200011 | The clear method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                  |

**示例：**

```ts
const mySet = new collections.Set<number>([0, 1]);
// Expected output: 2
console.info("size:" + mySet.size);
mySet.clear();
// Expected output: 0
console.info("size:" + mySet.size);
```

### delete
delete(value: T): boolean

删除该Set中指定元素。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明             |
| ------ | ---- | ---- | ---------------- |
| key    | K    | 是   | 待删除元素的键。 |

**返回值：**

| 类型    | 说明                              |
| ------- | --------------------------------- |
| boolean | 成功删除返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 10200011 | The delete method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                   |


**示例：**

```ts
const mySet = new collections.Set<string>(["hello", "world"]);
// Expected result: true
console.info("result:" + mySet.delete("hello"));
// Expected result: false
console.info("result:" + mySet.has("hello"));
// Expected result: false
console.info("result:" + mySet.delete("hello"));
```

### forEach
forEach(callbackFn: (value1: T, value2: T, set: Set\<T>) => void): void

按插入顺序对该Set中的每个键/值对执行一次回调函数。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型                                         | 必填 | 说明       |
| ---------- | -------------------------------------------- | ---- | ---------- |
| callbackFn | (value1: T, value2: T, set: Set\<T>) => void | 是   | 回调函数。 |

callbackFn的参数说明：
| 参数名 | 类型         | 必填 | 说明                         |
| ------ | ------------ | ---- | ---------------------------- |
| value1 | T            | 否   | 当前遍历到的元素键值对的值。 |
| value2 | T            | 否   | 当前遍历到的元素键值对的键。 |
| set    | Set&lt;T&gt; | 否   | 当前set实例对象。            |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                              |
| -------- | ----------------------------------------------------- |
| 10200011 | The forEach method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                    |

**示例：**

```ts
// 正例：
new collections.Set<string>(['foo', 'bar', 'baz']).forEach((value1, value2, set) => {
  console.info(`s[${value1}] = ${value2}`);
});
```

<!--code_no_check-->
```ts
// 反例：
new collections.Set<string>(['foo', 'bar', 'baz']).forEach((value1, value2, set) => {
  // Throw exception `Concurrent modification exception.`
  set.delete(value1);
});
```

### has
has(value: T): boolean

判断该Set中是否存在指定元素。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果存在指定元素，则返回true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The has method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                |

**示例：**

```ts
const mySet = new collections.Set<string>(["hello", "world"]);
// Expected output: true
console.info("result:" + mySet.has("hello"));
// Expected output: true
console.info("result:" + mySet.has("world"));
```

### add
add(value: T): Set\<T>

如果没有相同元素，则在该Set中插入一个新元素。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| Set&lt;T&gt; | Set对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The add method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception.                |

**示例：**

```ts
// 正例：
const mySet: collections.Set<string> = new collections.Set<string>();
mySet.add("foo");
```

<!--code_no_check-->
```ts
// 反例：
let obj = new Object();
const mySet: collections.Set<Object> = new collections.Set<Object>();
// Type arguments of generic "Sendable" type must be a "Sendable" data type (arkts-sendable-generic-types)
mySet.add(obj);
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

返回一个迭代器，迭代器的每一项都是一个JavaScript对象，并返回该对象。

> **说明：**
>
> 本接口不支持在.ets文件中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;T&gt; | 返回一个迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**示例：**

```ts
let set = new collections.Set<number>([1, 2, 3, 4, 5]);

let val: Array<number> = Array.from(set.values())
for (let item of val) {
  console.info("value: " + item);
}
```

## collections.ArrayBuffer
ArkTS TypedArray的底层数据结构。

### 属性

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称   | 类型   | 只读 | 可选 | 说明              |
| ------ | ------ | ---- | ---- | ----------------|
| byteLength | number | 是   | 否   | buffer所占的字节数。|

### constructor
constructor(byteLength: number)

构造函数，用于创建一个指定长度的ArkTS ArrayBuffer对象。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型   | 必填 | 说明                       |
| ------ | ------ | ---- | -------------------------|
| byteLength  | number | 是   | buffer所占的字节数。     |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 10200012 | The ArrayBuffer's constructor cannot be directly invoked. |

**示例：**

```ts
let arrayBuffer: collections.ArrayBuffer = new collections.ArrayBuffer(10);
console.info("byteLength: " + arrayBuffer.byteLength); // byteLength: 10
```

### slice
slice(begin: number, end?: number): ArrayBuffer

返回一个新的ArkTS ArrayBuffer对象，其包含原ArkTS ArrayBuffer指定范围的内容。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型   | 必填 | 说明                                              |
| ------ | ------ | ---- | ------------------------------------------------ |
| begin  | number | 是   | 开始索引，如果`begin < 0`，则会从`begin + arraybuffer.byteLength`位置开始。 |
| end    | number | 否   | 结束索引（不包括该元素），如果`end < 0`，则会到`end + arraybuffer.byteLength`位置结束。默认为ArkTS ArrayBuffer的长度。|

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| ArrayBuffer | 新的ArkTS ArrayBuffer对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID |                    错误信息                   |
| -------- | -------------------------------------------- |
| 10200011 | The slice method cannot be bound.            |
| 10200201 | Concurrent modification error.               |

**示例：**

```ts
let arrayBuffer: collections.ArrayBuffer = new collections.ArrayBuffer(10);
let slicedBuffer: collections.ArrayBuffer = arrayBuffer.slice(0, 4);
console.info("byteLength: " + slicedBuffer.byteLength); // byteLength: 4
```

## TypedArrayFromMapFn
type TypedArrayFromMapFn\<FromElementType, ToElementType> = (value: FromElementType, index: number) => ToElementType

ArkTS TypedArray映射函数类型。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| value | FromElementType | 是 | 当前遍历的用于构造ArkTS TypedArray的元素。 |
| index | number | 是 | 当前遍历的用于构造ArkTS TypedArray的元素下标。 |

**返回值：**

| 类型   | 说明                          |
| ------ | --------------------------- |
| ToElementType | 转换后的元素值。 |

## TypedArrayPredicateFn
type TypedArrayPredicateFn\<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => boolean

ArkTS TypedArray断言测试函数类型。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| value | ElementType | 是 | 当前遍历的ArkTS TypedArray元素。 |
| index | number | 是 | 当前遍历的ArkTS TypedArray元素下标。 |
| array | ArrayType | 是 | 当前遍历的ArkTS TypedArray实例。 |

**返回值：**

| 类型   | 说明                          |
| ------ | --------------------------- |
| boolean | 如果值符合条件，则为true，否则为false。 |

## TypedArrayForEachCallback
type TypedArrayForEachCallback\<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => void

ArkTS TypedArray遍历函数类型。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| value | ElementType | 是 | 当前遍历的ArkTS TypedArray元素。 |
| index | number | 是 | 当前遍历的ArkTS TypedArray元素下标。 |
| array | ArrayType | 是 | 当前遍历的ArkTS TypedArray实例。 |

## TypedArrayMapCallback
type TypedArrayMapCallback\<ElementType, ArrayType> = (value: ElementType, index: number, array: ArrayType) => ElementType

ArkTS TypedArray转换映射函数类型。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| value | ElementType | 是 | 当前映射的ArkTS TypedArray元素。 |
| index | number | 是 | 当前映射的ArkTS TypedArray元素下标。 |
| array | ArrayType | 是 | 当前映射的ArkTS TypedArray实例。 |

**返回值：**

| 类型   | 说明                          |
| ------ | --------------------------- |
| ElementType | 转换后的元素值。 |

## TypedArrayReduceCallback
type TypedArrayReduceCallback\<AccType, ElementType, ArrayType> = (previousValue: AccType, currentValue: ElementType, currentIndex: number, array: ArrayType) => AccType

ArkTS TypedArray归约函数类型。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| previousValue | AccType | 是 | 当前遍历所累积的值。|
| currentValue | ElementType | 是 | 当前遍历的ArkTS TypedArray元素。 |
| currentIndex | number | 是 | 当前遍历的ArkTS TypedArray元素下标。 |
| array | ArrayType | 是 | 当前遍历的ArkTS TypedArray实例。 |

**返回值：**

| 类型   | 说明                          |
| ------ | --------------------------- |
| AccType | 归约函数的结果。该结果会作为下一次调用TypedArrayReduceCallback时的previousValue参数。 |

## TypedArrayCompareFn
type TypedArrayCompareFn\<ElementType> = (first: ElementType, second: ElementType) => number

ArkTS TypedArray排序函数类型。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| first | ElementType | 是 | 当前待比较的第一个元素。 |
| second | ElementType | 是 | 当前待比较的第二个元素。 |

**返回值：**

| 类型   | 说明                          |
| ------ | --------------------------- |
| number | 元素比较的结果。如果`first`小于`second`，返回值为负数；如果`first`大于`second`，返回值为正数；如果两个值相等，返回值为0。 |

## collections.TypedArray

一种线性数据结构，底层基于[ArkTS ArrayBuffer](#collectionsarraybuffer)实现。目前支持包括Int8Array、Uint8Array、Int16Array、Uint16Array、Int32Array、Uint32Array、Uint8ClampedArray以及Float32Array。

文档中存在泛型的使用，涉及以下泛型标记符：
- TypedArray: 指上述8种具体的ArkTS TypedArray。

### 属性

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称   | 类型   | 只读 | 可选 | 说明              |
| ------ | ------ | ---- | ---- | ----------------|
| buffer | ArrayBuffer | 是   | 否  | ArkTS TypedArray底层使用的buffer。|
| byteLength | number | 是   | 否   | ArkTS TypedArray的所占的字节数。|
| byteOffset | number | 是   | 否   | ArkTS TypedArray距离其ArrayBuffer起始位置的偏移。|
| length | number | 是   | 否  | ArkTS TypedArray元素个数。|
| BYTES_PER_ELEMENT | number | 是   | 否   | ArkTS TypedArray中每个元素所占用的字节数。|

### constructor
constructor()

构造函数，用于创建一个空ArkTS TypedArray对象。

**系统能力：** SystemCapability.Utils.Lang

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 10200012 | The TypedArray's constructor cannot be directly invoked. |

**示例：**

```ts
let int8Array: collections.Int8Array = new collections.Int8Array();
let uint8Array: collections.Uint8Array = new collections.Uint8Array();
let int16Array: collections.Int16Array = new collections.Int16Array();
let uint16Array: collections.Uint16Array = new collections.Uint16Array();
let int32Array: collections.Int32Array = new collections.Int32Array();
let uint32Array: collections.Uint32Array = new collections.Uint32Array();
let uint8ClampedArray: collections.Uint8ClampedArray = new collections.Uint8ClampedArray();
let float32Array: collections.Float32Array = new collections.Float32Array();
```

### constructor
constructor(length: number)

构造函数，用于创建一个指定长度的ArkTS TypedArray对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                          |
| ------- | ------ | ---- | --------------------------- |
| length | number | 是 | 用于指定ArkTS TypedArray的长度。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                  |
| -------- | -------------------------------------------------------  |
| 10200012 | The TypedArray's constructor cannot be directly invoked. |


**示例：**

```ts
// 以长度参数构造对象
let int8Array: collections.Int8Array = new collections.Int8Array(12);
let uint8Array: collections.Uint8Array = new collections.Uint8Array(12);
let int16Array: collections.Int16Array = new collections.Int16Array(12);
let uint16Array: collections.Uint16Array = new collections.Uint16Array(12);
let int32Array: collections.Int32Array = new collections.Int32Array(12);
let uint32Array: collections.Uint32Array = new collections.Uint32Array(12);
let uint8ClampedArray: collections.Uint8ClampedArray = new collections.Uint8ClampedArray(12);
let float32Array: collections.Float32Array = new collections.Float32Array(12);
```

### constructor
constructor(array: ArrayLike\<number> | ArrayBuffer)

构造函数，以ArrayLike或ArkTS ArrayBuffer创建一个ArkTS TypedArray对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| array |  ArrayLike\<number> \| ArrayBuffer | 是 | 用于构造ArkTS TypedArray的对象。当参数类型是ArrayBuffer时buffer所占的字节数须是4的整数倍。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 10200012 | The TypedArray's constructor cannot be directly invoked. |

**示例：**

```ts
// 例1 从一个ArrayLike构造对象
let arrayLike = [1, 3, 5];
let array: collections.Uint32Array = new collections.Uint32Array(arrayLike);
```

```ts
// 例2 从一个ArrayBuffer构造对象
let arrayBuffer: collections.ArrayBuffer = new collections.ArrayBuffer(12);
let array: collections.Uint32Array = new collections.Uint32Array(arrayBuffer);
```

```ts
// 例3 从另一ArkTS TypedArray构造对象
let arrayLike = [1, 3, 5];
let uint8Array: collections.Uint8Array = new collections.Uint8Array(arrayLike);
// Uint8Array [1, 3, 5]
let uint32Array: collections.Uint32Array = new collections.Uint32Array(uint8Array);
// Uint32Array [1, 3, 5]
```

### constructor
constructor(buffer: ArrayBuffer, byteOffset?: number, length?: number)

构造函数，以ArrayBuffer创建一个ArkTS TypedArray对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                                         |
| ------- | ------ | ---- | ------------------------------------------ |
| buffer | ArrayBuffer | 是 | 用于构造ArkTS TypedArray的ArrayBuffer对象。buffer所占的字节数须是4的整数倍。|
| byteOffset | number | 否 | 指定buffer的字节偏移，默认为0。 |
| length | number | 否 | 指定ArkTS TypedArray的长度，默认为0。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                   |
| -------- | -------------------------------------------------------   |
| 10200012 | The TypedArray's constructor cannot be directly invoked. |

**示例：**

```ts
let int32Array: collections.Int32Array = collections.Int32Array.from([1, 2, 3, 4, 5, 6]);
console.info("byteLength: " + int32Array.buffer.byteLength) // byteLength: 24
// 从int32Array对应buffer第4个字节开始，长度为5
let uint32Array: collections.Uint32Array = new collections.Uint32Array(int32Array.buffer, 4, 5);
console.info("[" + uint32Array + "]"); // [2, 3, 4, 5, 6]
```

### from
static from(arrayLike: ArrayLike\<number>): TypedArray

从一个ArrayLike或者可迭代对象中创建一个ArkTS TypedArray对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                  |
| ------- | ------ | ---- | --------------------------------------------------- |
| arrayLike | ArrayLike\<number> | 是 | 用于构造ArkTS TypedArray的ArrayLike对象。 |

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| TypedArray | 新创建的ArkTS TypedArray对象。|

**示例：**
```ts
let arrayLike = [1, 3, 5];
let array: collections.Uint32Array = collections.Uint32Array.from(arrayLike);
// Uint32Array [1, 3, 5]
```

### from
static from\<T>(arrayLike: ArrayLike\<T>, mapFn: TypedArrayFromMapFn\<T, number>): TypedArray

从一个ArrayLike中创建一个ArkTS TypedArray对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**
| 参数名  | 类型   | 必填 | 说明                                        |
| ------- | ------ | ---- | ------------------------------------------|
| arrayLike | ArrayLike\<T> | 是 | 用于构造ArrayLike对象。              |
| mapFn | [TypedArrayFromMapFn](#typedarrayfrommapfn)\<T, number> | 是 | 映射函数。|

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| TypedArray | 新创建的ArkTS TypedArray对象。|

**示例：**

```ts
// 例1 从一个对象创建
let array: collections.Uint32Array = collections.Uint32Array.from<number>(
  { length: 5 }, (v: Object, k: number) => k);
// Uint32Array [0, 1, 2, 3, 4]
```

```ts
// 例2 从一个字符数组创建
let array: collections.Uint32Array = collections.Uint32Array.from<string>(
  ["1", "3", "5"], (v: string, k: number) => parseInt(v));
// Uint32Array [1, 3, 5]
```

```ts
// 例3 从一个字符串创建
let array: collections.Uint32Array = collections.Uint32Array.from<string>(
  "12345", (v: string, k: number) => parseInt(v));
// Uint32Array [1, 2, 3, 4, 5]
```

### from
static from(iterable: Iterable\<number>, mapFn?: TypedArrayFromMapFn\<number, number>): TypedArray

从一个可迭代对象中创建一个ArkTS TypedArray对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**
| 参数名  | 类型   | 必填 | 说明                                |
| ------- | ------ | ---- | -----------------------------------|
| iterable | Iterable\<number> | 是 | 用于构造的可迭代对象。   |
| mapFn | [TypedArrayFromMapFn](#typedarrayfrommapfn)\<number, number> | 否 | 映射函数。如果省略，则不对元素进行加工处理。|

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| TypedArray | 新创建的ArkTS TypedArray对象。|

**示例：**

```ts
// 例1 不指定映射函数
let set: Set<number> = new Set<number>([1, 2, 3]);
let array: collections.Uint32Array = collections.Uint32Array.from(set);
// Uint32Array [1, 2, 3]
```

```ts
// 例2 指定映射函数
let set: Set<number> = new Set<number>([1, 2, 3]);
let array: collections.Uint32Array = collections.Uint32Array.from(
  set, (v: number, k: number) => v + k);
// Uint32Array [1, 3, 5]
```

### of<sup>16+</sup>

static of(...items: number[]): TypedArray

通过可变数量的参数创建一个新的ArkTS TypedArray对象，参数个数可以是0个、1个或者多个。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型          | 必填 | 说明                            |
| --------- | ------------- | ---- | ------------------------------- |
| items | number[] | 否   | 用于创建数组的元素，参数个数可以是0个、1个或者多个。 |

**返回值：**

| 类型      | 说明                    |
| --------- | ----------------------- |
| TypedArray | 新的ArkTS TypedArray实例。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息                         |
| -------- | -------------------------------- |
| 401 | Parameter error: Possible causes: 1. Mandatory parameters are left unspecified;2. Incorrect parameter types; 3. Parameter verification failed. |

**示例：**

```ts
let arr: collections.Uint32Array = collections.Uint32Array.of(1, 2, 3, 4)
console.info(arr.toString());
// 预期输出：1,2,3,4
```

### toString<sup>16+</sup>

toString(): string

ArkTS TypedArray转换为字符串。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型         | 说明            |
| ---------- | ------------- |
| string | 一个包含数组所有元素的字符串。 |

**错误码：**

以下错误码详细介绍请参考[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID    | 错误信息                                 |
| -------- | ------------------------------------ |
| 10200011 | The toString method cannot be bound. |
| 10200201 | Concurrent modification error.       |

**示例：**

```ts
let array = new collections.Uint32Array([1, 2, 3, 4, 5]);
let stringArray = array.toString();
console.info(stringArray);
// 预期输出：1,2,3,4,5
```

### toLocaleString<sup>16+</sup>

toLocaleString(): string

根据当前应用的系统地区获取符合当前文化习惯的数字表示形式，让每个元素调用自己的toLocaleString方法把数字转换为字符串，然后使用逗号将每个元素的结果字符串按照顺序拼接成字符串。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型         | 说明            |
| ---------- | ------------- |
| string | 一个包含数组所有元素的字符串。 |

**错误码：**

以下错误码详细介绍请参考[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID    | 错误信息                                       |
| -------- | ------------------------------------------ |
| 10200011 | The toLocaleString method cannot be bound. |
| 10200201 | Concurrent modification error.             |

**示例：**

```ts
// 当前应用所在系统为法国地区
let array = new collections.Uint32Array([1000, 2000, 3000]);
let stringArray = array.toLocaleString();
console.info(stringArray);
// 预期输出：1,000,2,000,3,000
```

### copyWithin
copyWithin(target: number, start: number, end?: number): TypedArray

从ArkTS TypedArray指定范围内的元素依次拷贝到目标位置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| target | number | 是 | 目标起始位置的下标。 |
| start | number | 是 | 源起始位置下标，如果`start < 0`，则会从`start + typedarray.length`位置开始。 |
| end | number | 否 | 源终止位置下标，如果`end < 0`，则会从`end + typedarray.length`位置终止。默认为ArkTS TypedArray的长度。|

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| TypedArray | 修改后的TypedArray。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------ |
| 10200011 | The copyWithin method cannot be bound.           |
| 10200201 | Concurrent modification exception.               |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5, 6, 7, 8]);
let copied: collections.Uint32Array = array.copyWithin(3, 1, 3);
// Uint32Array [1, 2, 3, 2, 3, 6, 7, 8]
```

### some
some(predicate: TypedArrayPredicateFn\<number, TypedArray>): boolean

测试ArkTS TypedArray中的是否存在元素满足指定条件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                  |
| ------- | ------ | ---- | ---------------------------------------------------- |
| predicate | [TypedArrayPredicateFn](#typedarraypredicatefn)\<number, TypedArray> | 是 | 用于测试的断言函数。|

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| boolean | 如果存在元素满足指定条件返回true，否则返回false。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                            |
| -------- | ---------------------------------- |
| 10200011 | The some method cannot be bound.   |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
let arrayLike = [-10, 20, -30, 40, -50];
let uint32Array: collections.Uint32Array = new collections.Uint32Array(arrayLike);
uint32Array.some((element: number) => element < 0); // false

let int32Array: collections.Int32Array = new collections.Int32Array(arrayLike);
int32Array.some((element: number) => element < 0); // true
```

### every
every(predicate: TypedArrayPredicateFn\<number, TypedArray>): boolean

测试ArkTS TypedArray中的所有元素是否满足指定条件。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                    |
| ------- | ------ | ---- | ----------------------------------------------------- |
| predicate | [TypedArrayPredicateFn](#typedarraypredicatefn)\<number, TypedArray> | 是 | 用于测试的断言函数。|

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| boolean | 如果所有元素都满足指定条件则返回true，否则返回false。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The every method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
let arrayLike = [-10, 20, -30, 40, -50];
let uint32Array: collections.Uint32Array = new collections.Uint32Array(arrayLike);
uint32Array.every((element: number) => element > 0); // true

let int32Array: collections.Int32Array = new collections.Int32Array(arrayLike);
int32Array.every((element: number) => element > 0);  // false
```

### fill
fill(value: number, start?: number, end?: number): TypedArray

使用特定值填充ArkTS TypedArray指定范围的全部元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                      |
| ------- | ------ | ---- | --------------------------------------------------------|
| value | number | 是 | 待填充的值。|
| start | number | 否 | 开始填充的索引，如果`start < 0`，则会从`start + typedarray.length`位置开始。默认值为0。|
| end | number | 否 | 结束填充的索引，如果`end < 0`，则会到`end + typedarray.length`位置结束。默认为ArkTS TypedArray的长度。|

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| TypedArray | 填充后的TypedArray。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The fill method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
let arrayLike = [1, 2, 3];
new collections.Uint32Array(arrayLike).fill(4); // Uint32Array [4, 4, 4]
new collections.Uint32Array(arrayLike).fill(4, 1); // Uint32Array [1, 4, 4]
new collections.Uint32Array(arrayLike).fill(4, 1, 2); // Uint32Array [1, 4, 3]
```

### filter
filter(predicate: TypedArrayPredicateFn\<number, TypedArray>): TypedArray

返回一个新ArkTS TypedArray，其包含满足指定条件的所有元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                    |
| ------- | ------ | ---- | ------------------------------------------------------ |
| predicate | [TypedArrayPredicateFn](#typedarraypredicatefn)\<number, TypedArray> | 是 | 用于元素过滤的断言函数。 |

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| TypedArray| 过滤后的ArkTS TypedArray对象。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The filter method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([0, 1, 2, 3, 4]);
let filtered: collections.Uint32Array = array.filter((element: number) => element % 2 == 0);
// Uint32Array [0, 2, 4]
```

### find
find(predicate: TypedArrayPredicateFn\<number, TypedArray>): number | undefined

返回ArkTS TypedArray中第一个满足指定条件的元素的值，如果所有元素都不满足，则返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| predicate | [TypedArrayPredicateFn](#typedarraypredicatefn)\<number, TypedArray> | 是 | 用于元素查找的断言函数。|

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
|  number \| undefined | 第一个满足条件的元素的值；如果所有元素都不满足条件，则返回undefined。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The find method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([0, 1, 2, 3, 4]);
array.find((element: number) => element > 2); // 3
array.find((element: number) => element > 4); // undefined
```

### findIndex
findIndex(predicate: TypedArrayPredicateFn\<number, TypedArray>): number

返回ArkTS TypedArray中第一个满足指定条件的元素索引，如果所有元素都不满足，则返回-1。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| predicate | [TypedArrayPredicateFn](#typedarraypredicatefn)\<number, TypedArray> | 是 | 用于元素查找的断言函数。|

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| number | 第一个满足条件的元素索引；如果所有元素都不满足条件，否返回-1。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The findIndex method cannot be bound. |
| 10200201 | Concurrent modification exception.  |

**示例：**

```ts
const array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let foundIndex: number = array.findIndex((element: number) => element % 2 === 0); // 1
```

### forEach
forEach(callbackFn: TypedArrayForEachCallback\<number, TypedArray>): void

对ArkTS TypedArray中的每个元素执行提供的回调函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| callbackFn | [TypedArrayForEachCallback](#typedarrayforeachcallback)\<number, TypedArray> | 是 | 用于对每个元素执行的回调函数。|


**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The forEach method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
let uint32Array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3]);
uint32Array.forEach((value: number, index: number, array: collections.Uint32Array) => {
  console.info(`Element ${value} at index ${index}`);
});
```

### indexOf
indexOf(searchElement: number, fromIndex?: number): number

返回在ArkTS TypedArray中给定元素的第一个索引，如果不存在，则返回-1。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名        | 类型   | 必填 | 说明                        |
| ------------- | ------ | ---- | ---------------------------|
| searchElement | number | 是   | 待索引的值。                |
| fromIndex     | number | 否   | 搜索的起始下标。默认值为0。如果下标大于等于ArkTS TypedArray的长度，则返回-1。如果提供的下标值是负数，则被当做距离数组尾部的偏移，从前到后搜索。 |

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| number | 数组中元素的第一个索引；没有找到，则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The indexOf method cannot be bound. |
| 10200201 | Concurrent modification exception.                |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([3, 5, 9]);
array.indexOf(3); // 0
array.indexOf(7); // -1
array.indexOf(9, 2); // 2
array.indexOf(9, -2); // 2
```

### lastIndexOf<sup>16+</sup>

lastIndexOf(searchElement: number, fromIndex?: number): number

返回ArkTS TypedArray实例中最后一次出现searchElement的索引，如果对象不包含，则为-1。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名           | 类型     | 必填  | 说明                                                                                |
| ------------- | ------ | --- | --------------------------------------------------------------------------------- |
| searchElement | number | 是   | 待索引的值。                                                                            |
| fromIndex     | number | 否   | 搜索的起始下标。默认值为0。如果下标大于等于ArkTS TypedArray的长度，则返回-1。如果提供的下标值是负数，则被当做距离数组尾部的偏移，从后到前搜索。 |

**返回值：**

| 类型     | 说明                      |
| ------ | ----------------------- |
| number | 数组中给定元素的最后一个索引；没有找到，则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID    | 错误信息                                    |
| -------- | --------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range. |
| 10200011 | The lastIndexOf method cannot be bound. |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([3, 5, 9]);
console.info(array.lastIndexOf(3) + '');
// 预期输出：0
console.info(array.lastIndexOf(7) + '');
// 预期输出：-1
console.info(array.lastIndexOf(9, 2) + '');
// 预期输出：2
console.info(array.lastIndexOf(9, -2) + '');
// 预期输出：-1
```

### join
join(separator?: string): string

将ArkTS TypedArray的所有元素拼接成一个字符串，元素之间使用指定的分隔符分隔。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型   | 必填 | 说明                                                 |
| --------- | ------ | ---- | ---------------------------------------------------- |
| separator | string | 否   | 分隔字符串。如果省略，则使用逗号分隔。 |

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| string | 包含所有元素拼接成的字符串。如果ArkTS TypedArray为空，则返回空字符串。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The join method cannot be bound. |
| 10200201 | Concurrent modification exception.  |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let joined: string = array.join('-'); // "1-2-3-4-5"
```

### map
map(callbackFn: TypedArrayMapCallback\<number, TypedArray>): TypedArray

对ArkTS TypedArray中的每个元素应用指定的回调函数，并使用结果创建一个新的ArkTS TypedArray对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**
| 参数名    | 类型   | 必填 | 说明                                                 |
| --------- | ------ | ---- | ---------------------------------------------------- |
| callbackFn | [TypedArrayMapCallback](#typedarraymapcallback)\<number, TypedArray> | 是  | 回调函数。 |


**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| TypedArray | 新ArkTS TypedArray对象。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The map method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([25, 36, 49]);
const mapped: collections.Uint32Array = array.map(Math.sqrt); // Uint32Array [5, 6 ,7]
```

### reduce
reduce(callbackFn: TypedArrayReduceCallback\<number, number, TypedArray>): number

对ArkTS TypedArray中的每个元素执行归约函数，并返回最终的归约结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**
| 参数名     | 类型   | 必填 |  说明     |
| ---------- | ---------------------- | ---- | ------------------------------------------------------------ |
| callbackFn | [TypedArrayReduceCallback](#typedarrayreducecallback)\<number, number, TypedArray> | 是 | 归约函数。 |

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| number | 由归约函数返回的结果。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID |                      错误信息                     |
| -------- | ------------------------------------------------ |
| 10200011 | The reduce method cannot be bound.               |
| 10200201 | Concurrent modification exception.               |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let reducedValue: number = array.reduce((accumulator: number, value: number) => accumulator + value);
// reducedValue == 15
```

### reduceRight<sup>16+</sup>

reduceRight(callbackFn: TypedArrayReduceCallback\<number, number, TypedArray>): number

反向遍历ArkTS TypedArray，对ArkTS TypedArray中的每个元素执行归约函数，并返回最终的归约结果。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**
| 参数名     | 类型   | 必填 |  说明     |
| ---------- | ---------------------- | ---- | ------------------------------------------------------------ |
| callbackFn | [TypedArrayReduceCallback](#typedarrayreducecallback)\<number, number, TypedArray> | 是 | 归约函数。 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| number | 由归约函数返回的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID    | 错误信息                                    |
| -------- | --------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 10200011 | The reduceRight method cannot be bound. |
| 10200201 | Concurrent modification exception.      |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let reducedValue: number = array.reduceRight((accumulator: number, value: number) => accumulator + value);
console.info(reducedValue + '');
// 预期输出： 15
```

### reduce
reduce(callbackFn: TypedArrayReduceCallback\<number, number, TypedArray>, initialValue: number): number

对ArkTS TypedArray中的每个元素执行归约函数，且接收一个初始值作为归约函数首次调用的参数，并返回最终的归约结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**
| 参数名    | 类型   | 必填 | 说明                                                 |
| --------- | ------ | ---- | --------------------------------------------------- |
| callbackFn | [TypedArrayReduceCallback](#typedarrayreducecallback)\<number, number, TypedArray> | 是  | 归约函数。 |
| initialValue | number | 是  | 初始值。 |


**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| number | 由归约函数返回的结果。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The reduce method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let reducedValue: number = array.reduce((accumulator: number, value: number) => accumulator + value, 1);
// reducedValue == 16
```

### reduceRight<sup>16+</sup>

reduceRight\<U = number>(callbackFn: TypedArrayReduceCallback\<U, number, TypedArray>, initialValue: U): U

反向遍历ArkTS TypedArray，对ArkTS TypedArray中的每个元素执行归约函数，且接收一个初始值作为归约函数首次调用的参数，并返回最终的归约结果。

**原子化服务API：** 从API version 16开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**
| 参数名    | 类型   | 必填 | 说明                                                 |
| --------- | ------ | ---- | --------------------------------------------------- |
| callbackFn | [TypedArrayReduceCallback](#typedarrayreducecallback)\<U, number, TypedArray> | 是  | 归约函数。 |
| initialValue | U | 是  | 初始值。 |

**返回值：**

| 类型     | 说明          |
| ------ | ----------- |
| U | 由归约函数返回的结果。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID    | 错误信息                                    |
| -------- | --------------------------------------- |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified. 2.Incorrect parameter types. |
| 10200011 | The reduceRight method cannot be bound. |
| 10200201 | Concurrent modification exception.      |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let reducedValue: number = array.reduceRight((accumulator: number, value: number) => accumulator + value, 1);
console.info(reducedValue + '');
// 预期输出： 16
```

### reduce
reduce\<U>(callbackFn: TypedArrayReduceCallback\<U, number, TypedArray>, initialValue: U): U

对ArkTS TypedArray中的每个元素执行归约函数，且接收一个初始值作为归约函数首次调用的参数，并返回最终的归约结果。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型   | 必填 | 说明                                                 |
| --------- | ------ | ---- | ---------------------------------------------------- |
| callbackFn | [TypedArrayReduceCallback](#typedarrayreducecallback)\<U, number, TypedArray> | 是  | 归约函数。 |
| initialValue | U | 是  | 初始值。 |

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
|  U | 由归约函数返回的结果。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The reduce method cannot be bound. |
| 10200201 | Concurrent modification exception.  |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let reducedValue: string = array.reduce<string>((accumulator: string, value: number) => accumulator + value, "initialValue");
// reducedValue == initialValue12345
```

### reverse
reverse(): TypedArray

反转ArkTS TypedArray。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| TypedArray   | 反转后的ArkTS TypedArray对象。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The reverse method cannot be bound. |
| 10200201 | Concurrent modification exception.   |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let reversed: collections.Uint32Array = array.reverse(); // Uint32Array [5, 4, 3, 2, 1]
```

### set
set(array: ArrayLike\<number>, offset?: number): void

将传入的ArrayLike元素依次写入到指定的起始位置。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**
| 参数名    | 类型   | 必填 | 说明                                                 |
| --------- | ------ | ---- | ---------------------------------------------------- |
| array | ArrayLike\<number> | 是  | 用于设置的ArrayLike对象。|
| offset | number | 否  | 写入的起始位置。默认为0。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The set method cannot be bound. |
| 10200201 | Concurrent modification exception.  |

**示例：**

```ts
let buffer: collections.ArrayBuffer = new collections.ArrayBuffer(8);
let array: collections.Uint8Array = new collections.Uint8Array(buffer);
array.set([1, 2, 3], 3); // Uint8Array [0, 0, 0, 1, 2, 3, 0, 0]
```

### slice
slice(start?: number, end?: number): TypedArray

返回一个新的ArkTS TypedArray对象，其包含原ArkTS TypedArray指定范围的内容。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                   |
| ------ | ------ | ---- | -----------------------------------------------------|
| start  | number | 否   | 开始索引，如果`start < 0`，则会从`start + typedarray.length`位置开始。默认为0。 |
| end    | number | 否   | 结束索引（不包括该元素），如果`end < 0`，则会到`end + typedarray.length`位置结束。默认为ArkTS TypedArray的长度。|

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| TypedArray | 新的ArkTS TypedArray对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The slice method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
array.slice(); // Uint32Array [1, 2, 3, 4, 5]
array.slice(1, 3); // Uint32Array [2, 3]
array.slice(-2); // Uint32Array [4, 5]
```

### sort
sort(compareFn?: TypedArrayCompareFn\<number>): TypedArray

对ArkTS TypedArray进行排序，并返回排序后的ArkTS TypedArray对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型                   | 必填 | 说明                                       |
| --------- | ---------------------- | ---- | ------------------------------------------ |
| compareFn | [TypedArrayCompareFn](#typedarraycomparefn)\<number> | 否   | 用于确定元素顺序的函数。默认使用升序排序。 |

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| TypedArray | 排序后的ArkTS TypedArray对象。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------ |
| 10200011 | The sort method cannot be bound. |
| 10200201 | Concurrent modification exception.         |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 3, 5, 4, 2]);
array.sort(); // Uint32Array [1, 2, 3, 4, 5]
array.sort((a: number, b: number) => a - b); // Uint32Array [1, 2, 3, 4, 5]
array.sort((a: number, b: number) => b - a); // Uint32Array [5, 4, 3, 2, 1]
```

### subarray
subarray(begin?: number, end?: number): TypedArray

返回一个新的、基于相同ArkTS ArrayBuffer的ArkTS TypedArray对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                |
| ------ | ------ | ---- | ------------------------------------------------- |
| begin  | number | 否   | 开始索引，如果`begin < 0`，则会从`begin + typedarray.length`位置开始。默认值为0。 |
| end    | number | 否   | 结束索引（不包括该元素），如果`end < 0`，则会到`end + typedarray.length`位置结束。默认为ArkTS TypedArray的长度。 |

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| TypedArray | 新的ArkTS TypedArray对象。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID |            错误信息                               |
| -------- | -------------------------------------------------|
| 10200011 | The subarray method cannot be bound.             |
| 10200201 | Concurrent modification exception.               |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let subArray: collections.Uint32Array = array.subarray(); // Uint32Array [1, 2, 3, 4, 5]
subArray.set([10, 20, 30]); // Uint32Array [10, 20, 30, 4, 5]
```

### at
at(index: number): number | undefined

返回指定下标的元素，如果不存在，则返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**
| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| index  | number | 是   | 要返回的Array元素的索引（从零开始），取值为整数。如果`index < 0`，则会访问`index + typedarray.length`位置的元素。|

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| number \| undefined| 指定下标的元素；如果不存在，则返回undefined。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID |                       错误信息                    |
| -------- | ------------------------------------------------ |
| 10200011 | The at method cannot be bound.                   |
| 10200201 | Concurrent modification exception.               |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
console.info("element: " + array.at(2));  // element: 3
console.info("element: " + array.at(-1)); // element: 5
console.info("element: " + array.at(6));  // element: undefined
```

### includes
includes(searchElement: number, fromIndex?: number): boolean

判断ArkTS TypedArray是否包含特定元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**
| 参数名 | 类型   | 必填 | 说明                                      |
| ------ | ------ | ---- | --------------------------------------- |
| searchElement  | number | 是   | 待搜索的元素。 |
| fromIndex  | number | 否  | 开始搜索的索引，如果`fromIndex < 0`，则会从`fromIndex + typedarray.length`位置开始。默认值为0。|

**返回值：**

| 类型    | 说明                                                        |
| ------- | ---------------------------------------------------------- |
| boolean | 如果ArkTS TypedArray包含指定的元素，则返回true；否则返回false。|


**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The includes method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3]);
console.info("includes: " + array.includes(2));    // includes: true
console.info("includes: " + array.includes(4));    // includes: false
console.info("includes: " + array.includes(3, 3)); // includes: false
```

### entries
entries(): IterableIterator\<[number, number]>

返回一个新的迭代器对象，该对象包含ArkTS TypedArray中每个元素的键值对。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| IterableIterator\<[number, number]>| 新的迭代器对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The entries method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([11, 22, 33]);
let iterator: IterableIterator<[number, number]> = array.entries();
console.info("value: " + iterator.next().value); // value: [0, 11]
console.info("value: " + iterator.next().value); // value: [1, 22]
console.info("value: " + iterator.next().value); // value: [2, 33]
```

### keys
keys(): IterableIterator\<number>

返回一个新的迭代器对象，该对象包含ArkTS TypedArray中每个元素的键（下标）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| IterableIterator\<number> | 新的迭代器对象。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The keys method cannot be bound. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let iterator: IterableIterator<number> = array.keys();
for (const key of iterator) {
  console.info("" + key); // 依次输出 0,1,2,3,4
}
```

### values
values(): IterableIterator\<number>

返回一个新的迭代器对象，该对象包含ArkTS TypedArray中每个元素的值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| IterableIterator\<number> | 新的迭代器对象。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The values method cannot be bound. |
| 10200201 | Concurrent modification exception.  |

**示例：**

```ts
let array: collections.Uint32Array = collections.Uint32Array.from([1, 2, 3, 4, 5]);
let iterator: IterableIterator<number> = array.values();
for (const value of iterator) {
  console.info("" + value); // 依次输出 1,2,3,4,5
}
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;number&gt;

返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象，并返回该对象。

> **说明：**
>
> 本接口不支持在.ets文件中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                      | 说明             |
| ------------------------- | ---------------- |
| IterableIterator&lt;T&gt; | 返回一个迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**示例：**

```ts
let int32Array: collections.Int32Array = collections.Int32Array.from([1, 2, 3, 4, 5, 6]);

for (let item of int32Array) {
  console.info(`value : ${item}`);
}
```

### [index: number]

&#91;index: number&#93;: number

返回TypedArray指定索引位置的元素，适用于Int8Array，Int16Array，Int32Array，Uint8Array，Uint16Array，Uint32Array，Float32Array和Float64Array 8种数据类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 参数名    | 类型   | 必填 | 说明                     |
| ----- | ------ | ---- | -------------------------- |
| index | number | 是   | 所需代码单元的从零开始的索引。|

**返回值：**

| 类型   | 说明                 |
| ----- | ---------------------|
| number | 返回number数据类型。 |

**示例：**

```ts
let int8Array = collections.Int8Array.from([1, 2, 4]);
console.info("Element at index 1: ", int8Array[1]);
let int16Array = collections.Int16Array.from([1, 2, 4]);
console.info("Element at index 1: ", int16Array[1]);
let int32Array = collections.Int32Array.from([1, 2, 4]);
console.info("Element at index 1: ", int32Array[1]);
let uint8Array = collections.Uint8Array.from([1, 2, 4]);
console.info("Element at index 1: ", uint8Array[1]);
let uint16Array = collections.Uint16Array.from([1, 2, 4]);
console.info("Element at index 1: ", uint16Array[1]);
let uint32Array = collections.Uint32Array.from([1, 2, 4]);
console.info("Element at index 1: ", uint32Array[1]);
let float32Array = collections.Float32Array.from([1, 2, 4]);
console.info("Element at index 1: ", float32Array[1]);
let uint8Clamped = collections.Uint8ClampedArray.from([1, 2, 4]);
console.info("Element at index 1: ", uint8Clamped[1]);
```

## collections.BitVector

BitVector是一种线性数据结构，底层基于数组实现。BitVector中存储元素为bit值，能存储和处理bit级别的操作。

### 属性

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称   | 类型   | 只读 | 可选 | 说明                  |
| ------ | ------ | ---- | ---- | --------------------- |
| length | number | 是   | 否   | BitVector的元素个数。 |


### constructor

constructor(length: number)

BitVector的构造函数。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| length | number | 是   | 初始化BitVector的长度。 |

**示例：**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
```


### push

push(element:number): boolean

在BitVector尾部插入元素。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                                |
| ------- | ------ | ---- | ----------------------------------- |
| element | number | 是   | 待插入的元素，0表示0，其余值表示1。 |

**返回值：**

| 类型    | 说明                              |
| ------- | --------------------------------- |
| boolean | 插入成功返回true，失败返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br/>1.Mandatory parameters are left unspecified；<br/>2.Incorrect parameter types. |
| 10200011 | The push method cannot be bound.                             |
| 10200201 | Concurrent modification error.                               |

**示例：**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
```

### pop

pop(): number

弹出BitVector尾部的元素。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型   | 说明                                       |
| ------ | ------------------------------------------ |
| number | 弹出BitVector尾部的元素，其值为对应bit值。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                        |
| -------- | ------------------------------- |
| 10200011 | The pop method cannot be bound. |
| 10200201 | Concurrent modification error.  |

**示例：**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let res = bitVector.pop(); // bitVector: [0, 1, 0, 1]
console.info("bitVector pop:", res) // 0
```

### has

has(element: number, fromIndex: number, toIndex: number): boolean

判断范围内是否包含特定bit值。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型   | 必填 | 说明                                 |
| --------- | ------ | ---- | ------------------------------------ |
| element   | number | 是   | 待判断的bit值，0表示0，其余值表示1。 |
| fromIndex | number | 是   | 范围起始索引，包含本索引值。         |
| toIndex   | number | 是   | 范围终止索引，包含本索引值。       |

**返回值：**

| 类型    | 说明                                   |
| ------- | -------------------------------------- |
| boolean | 包含特定bit值返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br/>1.Mandatory parameters are left unspecified；<br/>2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The has method cannot be bound.                              |
| 10200201 | Concurrent modification error.                               |

**示例：**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let res0: boolean = bitVector.has(0, 1, 4);
console.info("bitVector has 0:", res0) // true
```

### setBitsByRange

setBitsByRange(element: number, fromIndex: number, toIndex: number): void

将BitVector中指定范围的元素均设为特定bit值。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型   | 必填 | 说明                               |
| --------- | ------ | ---- | ---------------------------------- |
| element   | number | 是   | 待设置的bit值，0表示0，其余表示1。 |
| fromIndex | number | 是   | 范围起始索引，包含本索引值。       |
| toIndex   | number | 是   | 范围终止索引，不包含本索引值。     |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br/>1.Mandatory parameters are left unspecified；<br/>2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The setBitsByRange method cannot be bound.                   |
| 10200201 | Concurrent modification error.                               |

**示例：**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
bitVector.setBitsByRange(1, 1, 3); // bitVector: [0, 1, 1, 1, 0]
```

### setAllBits

setAllBits(element: number): void

将BitVector中所有元素均设为特定bit值。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                                |
| ------- | ------ | ---- | ----------------------------------- |
| element | number | 是   | 待设置的元素，0表示0，其余值表示1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br/>1.Mandatory parameters are left unspecified；<br/>2.Incorrect parameter types. |
| 10200011 | The setAllBits method cannot be bound.                       |
| 10200201 | Concurrent modification error.                               |

**示例：**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
bitVector.setAllBits(1); // bitVector: [1, 1, 1, 1, 1]
```

### getBitsByRange

getBitsByRange(fromIndex: number, toIndex: number): BitVector

获取指定范围内的bit值。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型   | 必填 | 说明                           |
| --------- | ------ | ---- | ------------------------------ |
| fromIndex | number | 是   | 范围起始索引，包含本索引值。   |
| toIndex   | number | 是   | 范围终止索引，不包含本索引值。 |

**返回值：**

| 类型      | 说明                               |
| --------- | ---------------------------------- |
| BitVector | 指定范围内的bit值组成的BitVector。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br/>1.Mandatory parameters are left unspecified；<br/>2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The getBitsByRange method cannot be bound.                   |
| 10200201 | Concurrent modification error.                               |

**示例：**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let bitVector2 = bitVector.getBitsByRange(1, 3); // bitVector2: [1, 0]
console.info("bitVector2 length:", bitVector2.length) // 2
```

### resize

resize(size: number): void

改变BitVector的长度。

若size大于原BitVector的长度，则扩充原BitVector的长度，多出的部分其元素设置为0；

若size小于等于原BitVector的长度，则将原BitVector按size长度大小裁剪。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明             |
| ------ | ------ | ---- | ---------------- |
| size   | number | 是   | 需要改变的长度。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br/>1.Mandatory parameters are left unspecified；<br/>2.Incorrect parameter types. |
| 10200011 | The resize method cannot be bound.                           |
| 10200201 | Concurrent modification error.                               |

**示例：**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
bitVector.resize(10); // bitVector: [0, 1, 0, 1, 0, 0, 0, 0, 0, 0]
console.info("bitVector get bit vector's length:", bitVector.length) // 10
bitVector.resize(3); // bitVector: [0, 1, 0]
console.info("bitVector get bit vector's length:", bitVector.length) // 3
```

### getBitCountByRange

getBitCountByRange(element: number, fromIndex: number, toIndex: number): number

统计指定范围内获取指定bit值的数量。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型   | 必填 | 说明                                 |
| --------- | ------ | ---- | ------------------------------------ |
| element   | number | 是   | 待统计的bit值，0表示0，其余值表示1。 |
| fromIndex | number | 是   | 范围起始索引，包含本索引值。         |
| toIndex   | number | 是   | 范围终止索引，不包含本索引值。       |

**返回值：**

| 类型   | 说明                                |
| ------ | ----------------------------------- |
| number | 统计指定范围内获取指定bit值的数量。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br/>1.Mandatory parameters are left unspecified；<br/>2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The getBitCountByRange method cannot be bound.               |
| 10200201 | Concurrent modification error.                               |

**示例：**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let res: number = bitVector.getBitCountByRange(1, 1, 4);
console.info("bitVector getBitCountByRange:", res) // 2
```

### getIndexOf

getIndexOf(element: number, fromIndex: number, toIndex: number): number

返回指定bit值首次出现时的索引值，查找失败返回-1。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型   | 必填 | 说明                                 |
| --------- | ------ | ---- | ------------------------------------ |
| element   | number | 是   | 待统计的bit值，0表示0，其余值表示1。 |
| fromIndex | number | 是   | 范围起始索引，包含本索引值。         |
| toIndex   | number | 是   | 范围终止索引，不包含本索引值。       |

**返回值：**

| 类型   | 说明                                              |
| ------ | ------------------------------------------------- |
| number | 返回指定bit值首次出现时的下标值，查找失败返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br/>1.Mandatory parameters are left unspecified；<br/>2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The getIndexOf method cannot be bound.                       |
| 10200201 | Concurrent modification error.                               |

**示例：**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let res: number = bitVector.getIndexOf(0, 1, 4);
console.info("bitVector getIndexOf:", res) // 2
```

### getLastIndexOf

getLastIndexOf(element: number, fromIndex: number, toIndex: number): number

返回指定bit值最后一次出现时的下标值，查找失败返回-1。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型   | 必填 | 说明                                 |
| --------- | ------ | ---- | ------------------------------------ |
| element   | number | 是   | 待统计的bit值，0表示0，其余值表示1。 |
| fromIndex | number | 是   | 范围起始索引，包含本索引值。         |
| toIndex   | number | 是   | 范围终止索引，不包含本索引值。       |

**返回值：**

| 类型   | 说明                                                  |
| ------ | ----------------------------------------------------- |
| number | 返回指定bit值最后一次出现时的下标值，查找失败返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br/>1.Mandatory parameters are left unspecified；<br/>2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The getLastIndexOf method cannot be bound.                   |
| 10200201 | Concurrent modification error.                               |

**示例：**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let res: number = bitVector.getLastIndexOf(0, 1, 4);
console.info("bitVector getLastIndexOf:", res) // 2
```

### flipBitByIndex

flipBitByIndex(index: number): void

翻转BitVector指定索引处的bit值，0翻转为1，1翻转为0。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| index  | number | 是   | 指定索引。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br/>1.Mandatory parameters are left unspecified；<br/>2.Incorrect parameter types. |
| 10200001 | The value of index is out of range.                          |
| 10200011 | The flipBitByIndex method cannot be bound.                   |
| 10200201 | Concurrent modification error.                               |

**示例：**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
bitVector.flipBitByIndex(3); // bitVector: [0, 1, 0, 0, 0]
```

### flipBitsByRange

flipBitsByRange(fromIndex: number, toIndex: number): void

翻转BitVector指定范围内的bit值，0翻转为1，1翻转为0。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名    | 类型   | 必填 | 说明                           |
| --------- | ------ | ---- | ------------------------------ |
| fromIndex | number | 是   | 范围起始索引，包含本索引值。   |
| toIndex   | number | 是   | 范围终止索引，不包含本索引值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401      | Parameter error. Possible causes:<br/>1.Mandatory parameters are left unspecified；<br/>2.Incorrect parameter types. |
| 10200001 | The value of fromIndex or toIndex is out of range.           |
| 10200011 | The flipBitsByRange method cannot be bound.                  |
| 10200201 | Concurrent modification error.                               |

**示例：**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
bitVector.flipBitsByRange(1, 4); // bitVector: [0, 0, 1, 0, 0]
```

### values

values(): IterableIterator\<number>

返回一个新的迭代器对象，该对象包含BitVector中每个元素的值。

**原子化服务API**：从API version 12 开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                           | 说明                          |
| ------------------------------ | ----------------------------- |
| IterableIterator&lt;number&gt; | 返回一个BitVector迭代器对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                           |
| -------- | ---------------------------------- |
| 10200011 | The values method cannot be bound. |
| 10200201 | Concurrent modification error.     |

**示例：**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
let iter: IterableIterator<number> = bitVector.values();
let temp: IteratorResult<number> = iter.next();
while (!temp.done) {
  console.info(JSON.stringify(temp.value));
  temp = iter.next();
} // 依次输出 0,1,0,1,0
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;number&gt;

返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象，并返回该对象。

> **说明：**
>
> 本接口不支持在.ets文件中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                      | 说明             |
| ------------------------- | ---------------- |
| IterableIterator&lt;number&gt; | 返回一个迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                    |
| -------- | ------------------------------------------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**示例：**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);

for (let item of bitVector) {
  console.info("value: " + item);
}
```

### [index: number]

&#91;index: number&#93;: number

返回BitVector指定索引位置的元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 参数名    | 类型   | 必填 | 说明                     |
| ----- | ------ | ---- | -------------------------- |
| index | number | 是   | 所需代码单元的从零开始的索引。|

**返回值：**

| 类型   | 说明                 |
| ----- | ---------------------|
| number | 返回number数据类型。 |

**示例：**

```ts
let bitVector: collections.BitVector = new collections.BitVector(0);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0);
bitVector.push(1);
bitVector.push(0); // bitVector: [0, 1, 0, 1, 0]
console.info("BitVector Element Index at 1: " + bitVector[1]);
```