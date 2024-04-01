# @arkts.collections (ArkTS容器集)

本模块提供的ArkTS容器集，可以用于并发场景下的高性能数据传递。功能与JavaScript内建的对应容器类似，但ArkTS容器实例无法通过\.或者\[\]添加或更新属性。

ArkTS容器在多个并发实例间传递时，其默认行为是引用传递，支持多个并发实例可以同时操作同一个容器实例。另外，也支持拷贝传递，即每个并发实例持有一个ArkTS容器实例。

ArkTS容器并不是线程安全的，内部使用了fail-fast（快速失败）机制：当检测多个并发实例同时对容器进行结构性改变时，会触发异常。因此，在修改场景下，容器使用方需要使用ArkTS提供的异步锁机制保证ArkTS容器的安全访问。

当前ArkTS容器集主要包含以下几种容器：[Array](#collectionsarray)、[Map](#collectionsmap)、[Set](#collectionsset)。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { collections } from '@kit.ArkTS';
```

## collections.Array

一种线性数据结构，底层基于数组实现，可以在ArkTS上并发实例间传递。

当需要在ArkTS上并发实例间传递Array时，可以通过传递Array引用提升传递性能。

文档中存在泛型的使用，涉及以下泛型标记符：

- T：Type，支持[Sendable的数据类型](../../arkts-utils/arkts-sendable.md)。

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称   | 类型   | 可读 | 可写 | 说明              |
| ------ | ------ | ---- | ---- | ----------------- |
| length | number | 是   | 否   | Array的元素个数。 |


### constructor

**构造函数**

constructor()

创建一个ArkTS Array的构造函数。

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

### create

static create\<T>(arrayLength: number, initialValue: T): Array\<T>

生成一个固定长度的Array，其中，每个元素的初始值为initialValue。

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
let arrayLike = [1, 3, 5];
let array = collections.Array.from<number>(arrayLike);
```

### pop

pop(): T | undefined

从ArkTS Array中移除并返回最后一个元素。如果Array为空，则返回undefined，且Array不发生变化。

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

### unshift

unshift(...items: T[]): number

在ArkTS Array的首端插入一个或多个元素，并返回新的Array长度。

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

### slice

slice(start?: number, end?: number): Array\<T>

返回一个新的Array，该Array是原始ArkTS Array的切片。

**系统能力：** SystemCapability.Utils.Lang

**参数：**
| 参数名 | 类型   | 必填 | 说明                                                         |
| ------ | ------ | ---- | ------------------------------------------------------------ |
| start  | number | 否   | 开始索引。默认值为0。                                        |
| end    | number | 否   | 结束索引（不包括该元素）。如果省略，则切片到Array的最后一个元素。 |

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
let array = new collections.Array<number>(1, 3, 5, 4, 1);
array.sort((a: number, b: number) => a - b); // [1, 2, 3, 4, 5]
array.sort((a: number, b: number) => b - a); // [5, 4, 3, 2, 1]
```

### indexOf

indexOf(searchElement: T, fromIndex?: number): number

返回在ArkTS Array中搜索元素首次出现的索引，如果不存在则返回-1。

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

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                                                   |
| ------ | ------ | ---- | ------------------------------------------------------ |
| value  | T      | 是   | 要填充的值。                                           |
| start  | number | 否   | 开始填充的索引。默认值为0。                            |
| end    | number | 否   | 结束填充的索引。如果省略，则填充到Array的最后一个元素。 |

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

## collections.Map

一种非线性数据结构。

文档中存在泛型的使用，涉及以下泛型标记符：

- K：Key，键
- V：Value，值

K和V类型都需为[Sendable类型](../../arkts-utils/arkts-sendable.md)。

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型   | 可读 | 可写 | 说明            |
| ---- | ------ | ---- | ---- | --------------- |
| size | number | 是   | 否   | Map的元素个数。 |


### constructor
constructor(entries?: readonly (readonly [K, V])[] | null)

构造函数，用于创建ArkTS Map对象。

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

```ts
// 反例：
@Sendable
class SharedClass {
  constructor() {
  }
}
let sObj = new SharedClass();
const myMap1 = new collections.Map<number, SharedClass>([[1, sObj]]);

// Throw exception `Parameter error. Only accept sendable value`
let obj = new Object();
const myMap2 = new collections.Map<number, Object>([[1, obj]]);
```

### entries
entries(): IterableIterator<[K, V]>

返回一个Map迭代器对象，该对象包含了此Map中的每个元素的[key, value]对。

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
const myMap = new collections.Map<number, string>([
  [0, "one"],
  [1, "two"],
  [2, "three"],
  [3, "four"]
]);

const entriesIter = myMap.entries();
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

```ts
// 反例：
let obj = new Object();
const myMap = new collections.Map<string, Object>();
// Throw exception `Parameter error. Only accept sendable value`
myMap.set("foo", obj)
```


## collections.Set

一种非线性数据结构。

文档中存在泛型的使用，涉及以下泛型标记符：

- T：Type，支持[Sendable的数据类型](../../arkts-utils/arkts-sendable.md)。

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型   | 可读 | 可写 | 说明            |
| ---- | ------ | ---- | ---- | --------------- |
| size | number | 是   | 否   | Set的元素个数。 |

### constructor

constructor(values?: readonly T[] | null)

构造函数，用于创建ArkTS Set对象。

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

```ts
// 反例：
@Sendable
class SharedClass {
  constructor() {
  }
}

let sObj = new SharedClass();
const mySet1 = new collections.Set<number|SharedClass>([1, sObj]);

// Throw exception `Parameter error. Only accept sendable value`
let obj = new Object();
const mySet2 = new collections.Set<number|Object>([1, obj]);
```

### entries
entries(): IterableIterator<[T, T]>

返回一个Set迭代器对象。

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
const mySet = new collections.Set<string>();
mySet.add("foo", "bar")
```

```ts
// 反例：
let obj = new Object();
const mySet = new collections.Set<Object>();
// Throw exception `Parameter error. Only accept sendable value`
mySet.add(obj)
```