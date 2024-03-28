# @arkts.collections.Array (ArkTS Array)

Array是一种线性数据结构，底层基于数组实现，可以在ArkTS上并发实例间传递

默认情况下，Array数据在ArkTS并发实例间传递的行为是引用传递。同时，ArkTS支持Array数据在ArkTS并发实例间的拷贝传递。

当多个并发实例尝试同时更新可变Array数据时，会发生数据竞争。ArkTS提供了一部所的机制来避免不同并发实例间的数据竞争。(TODO: link to async lock's doc)

**推荐使用场景：** 当需要在ArkTS上并发实例间传递Array时，可以通过传递Array引用提升传递性能。

文档中存在泛型的使用，涉及以下泛型标记符：<br>
- T：Type，支持Sendable的数据类型。(TODO: link to sendable spec.)

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { collections } from '@kit.ArkTS';
```

## Array

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 是 | Array的元素个数。 |


### constructor

**构造函数**

```typescript
constructor();
```

创建一个ArkTS Array的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200012 | The Array's constructor cannot be directly invoked. |

**示例：**

```ts
let array = new collections.Array<number>();
```

### constructor

**构造函数**

```typescript
constructor(first: T, ...left: T[]);
```

创建一个ArkTS Array的构造函数，并初始化数组的元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| first | T | 是 | 初始化ArkTS Array的第一个元素。 |
| left | T[] | 否 | 初始化ArkTS Array的剩余元素。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200012 | The Array's constructor cannot be directly invoked. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4);
```

### from

**静态方法**

```typescript
static from<T>(arrayLike: ArrayLike<T>): Array<T>;
```

从一个类数组对象创建一个新的ArkTS数组。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| arrayLike | ArrayLike<T> | 是 | 要转换为ArkTS数组的类数组对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array<T> | 新创建的ArkTS数组实例。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The from method cannot be bound. |

**示例：**

```ts
let arrayLike = [1, 3, 5];
let array = collections.Array.from<number>(arrayLike);
```

### length

**属性**

```typescript
length: number;
```

获取或设置ArkTS数组的长度。这个数值是ArkTS数组中最高索引值加一。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3);
console.log(array.length); // 输出：3
array.length = 5;
console.log(array.length); // 输出：5
```

### pop

**方法**

```typescript
pop(): T | undefined;
```

从ArkTS数组中移除最后一个元素并返回它。如果数组为空，则返回undefined，并且数组不发生变化。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T \| undefined | 从数组中移除的元素；如果数组为空，则返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The pop method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3);
let lastElement = array.pop(); // 返回3，数组变为[1, 2]
```

### push

**方法**

```typescript
push(...items: T[]): number;
```

在ArkTS数组的末尾添加一个或多个元素，并返回新的数组长度。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| items | T[] | 是 | 要添加到数组末尾的一个或多个元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 数组的新长度。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The push method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3);
let length = array.push(4, 5); // 返回5，数组变为[1, 2, 3, 4, 5]
```

### join

**方法**

```typescript
join(separator?: string): string;
```

将ArkTS数组的所有元素连接成一个字符串，元素之间可以用指定的分隔符分隔。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| separator | string | 否 | 用于分隔数组元素的字符串。如果省略，则使用逗号分隔。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 包含所有数组元素连接成的字符串。如果数组为空，则返回空字符串。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The join method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<string>('a', 'b', 'c');
let joinedString = array.join('-'); // 返回 "a-b-c"
```

### shift

**方法**

```typescript
shift(): T | undefined;
```

从ArkTS数组中移除第一个元素并返回它。如果数组为空，则返回undefined，并且数组不发生变化。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T \| undefined | 从数组中移除的元素；如果数组为空，则返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The shift method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3);
let firstElement = array.shift(); // 返回1，数组变为[2, 3]
```

### unshift

**方法**

```typescript
unshift(...items: T[]): number;
```

在ArkTS数组的开头插入一个或多个元素，并返回新的数组长度。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| items | T[] | 是 | 要插入到数组开头的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 数组的新长度。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The unshift method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3);
let newLength = array.unshift(0); // 返回4，数组变为[0, 1, 2, 3]
```

### slice

**方法**

```typescript
slice(start?: number, end?: number): Array<T>;
```

返回一个新的数组，该数组是原始ArkTS数组的切片。

**系统能力：** SystemCapability.Utils.Lang

**参数：**
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| start | number | 否 | 开始索引。如果省略，则从数组的第一个元素开始。 |
| end | number | 否 | 结束索引（不包括该元素）。如果省略，则切片到数组的最后一个元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array<T> | 包含原始数组切片的新数组。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The slice method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let slicedArray = array.slice(1, 3); // 返回[2, 3]，数组保持不变
```

### sort

**方法**

```typescript
sort(compareFn?: (a: T, b: T) => number): Array<T>;
```

原地对ArkTS数组进行排序，并返回排序后的数组。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| compareFn | function | 否 | 用于确定元素顺序的函数。如果省略，则使用升序排序。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array<T> | 排序后的数组。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The sort method cannot be bound. |
| 10200201 | Concurrent modification error

**示例：**

```ts
let array = new collections.Array<number>(1, 3, 5, 4, 1);
array.sort((a: number, b: number) => a - b); // [1, 2, 3, 4, 5]
array.sort((a: number, b: number) => b - a); // [5, 4, 3, 2, 1]
```

### indexOf

**方法**

```typescript
indexOf(searchElement: T, fromIndex?: number): number;
```

返回在ArkTS数组中搜索元素首次出现的索引，如果不存在则返回-1。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| searchElement | T | 是 | 要搜索的值。 |
| fromIndex | number | 否 | 开始搜索的索引。如果省略，则从数组的第一个元素开始。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 搜索元素首次出现的索引；如果不存在，则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The indexOf method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<string>('a', 'b', 'c');
let index = array.indexOf('b'); // 返回1，因为'b'在索引1的位置
```

### forEach

**方法**

```typescript
forEach(callbackFn: (value: T, index: number, array: Array<T>) => void): void;
```

对数组中的每个元素执行提供的回调函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 用于对每个元素执行的回调函数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| void | 没有返回值。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The forEach method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<string>('a', 'b', 'c');
array.forEach((value, index, array) => {
  console.log(`Element ${value} at index ${index}`);
});
```

### map

**方法**

```typescript
map<U>(callbackFn: (value: T, index: number, array: Array<T>) => U): Array<U>;
```

对数组中的每个元素执行提供的回调函数，并返回一个新的数组，该数组包含回调函数的结果。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 用于对每个元素执行的回调函数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array<U> | 包含回调函数结果的新数组。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The map method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<string>('a', 'b', 'c');
let mappedArray = array.map((value, index, array) => {
  return value.toUpperCase(); // 将每个字符串元素转换为大写
});
console.log("" + mappedArray); // 输出: ['A', 'B', 'C']
```

在这个示例中，`map` 方法将原始数组中的每个字符串元素转换为大写形式，并返回一个新数组，其中包含转换后的字符串。

### filter

**方法**

```typescript
filter(predicate: (value: T, index: number, array: Array<T>) => boolean): Array<T>;
```

返回一个新数组，其中包含通过指定回调函数测试的所有元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| predicate | function | 是 | 一个接受三个参数的函数，用于测试每个元素是否应该包含在新数组中。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array<T> | 包含通过测试的元素的新数组。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The filter method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let filteredArray = array.filter((value : number) => value % 2 === 0); // 返回[2, 4]，只包含偶数
```

### reduce

**方法**

```typescript
reduce(callbackFn: (previousValue: T, currentValue: T, currentIndex: number, array: Array<T>) => T): T;
```

对数组中的每个元素执行回调函数，将其结果作为累加值（accumulator），并返回最终的结果。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 一个接受四个参数的函数，用于对每个元素执行操作，并将结果作为累加值传递给下一个元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 回调函数执行后的最终结果。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The reduce method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let reducedValue = array.reduce((accumulator, value) => accumulator + value); // 返回15，累加所有元素
```
### reduce<U>

**方法**

```typescript
reduce<U>(callbackFn: (previousValue: U, currentValue: T, currentIndex: number, array: Array<T>) => U, initialValue: U): U;
```

与 `reduce` 方法类似，但它接受一个初始值作为第三个参数，用于在数组遍历开始前初始化累加器。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 一个接受四个参数的函数，用于对每个元素执行操作，并将结果作为累加值传递给下一个元素。 |
| initialValue | U | 是 | 用于初始化累加器的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| U | 回调函数执行后的最终结果。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The reduce method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array(1, 2, 3, 4, 5);
let reducedValue = array.reduce<number>((accumulator: number, value: number) => accumulator + value, 0); // 返回15，累加所有元素，初始值为0
```

在这个示例中，`reduce` 方法使用一个初始值为0的累加器，并将其与数组中的每个元素相加，最终返回累加后的总和。

### at

**方法**

```typescript
at(index: number): T | undefined;
```

返回数组中指定索引位置的元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 零基索引，表示要检索的元素位置。负索引从数组末尾开始计数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T \| undefined | 返回指定索引处的元素；如果索引超出范围或无效，则返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The at method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let elementAtIndex = array.at(2); // 返回3，因为索引是从0开始的
```

### entries

**方法**

```typescript
entries(): IterableIterator<[number, T]>;
```

返回一个新的可迭代对象，该对象包含数组中每个元素的键值对。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator<[number, T]> | 包含数组中每个元素的键值对的可迭代迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The entries method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let iterator = array.entries();
console.log(iterator.next().value); // 输出：[0, 1]，第一个元素的键值对
```

### keys

**方法**

```typescript
keys(): IterableIterator<number>;
```

返回一个新的可迭代对象，该对象包含数组中每个元素的键。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator<number> | 包含数组中每个元素的键的可迭代迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The keys method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let iterator = array.keys();
for (const key of iterator) {
  console.log("" + key); // 依次输出 0,1,2,3,4
}
```

### values

**方法**

```typescript
values(): IterableIterator<T>;
```

返回一个新的可迭代对象，该对象包含数组中每个元素的值。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator<T> | 包含数组中每个元素的值的可迭代迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The values method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let iterator = array.values();
for(const value of iterator) {
  console.log("" + value); // 依次输出 1,2,3,4,5
}
```

### find

**方法**

```typescript
find(predicate: (value: T, index: number, obj: Array<T>) => boolean): T | undefined;
```

返回数组中第一个满足指定测试函数的元素的值，如果所有元素都不满足，则返回undefined。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| predicate | function | 是 | 一个接受三个参数的函数，用于测试每个元素是否满足条件。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T \| undefined | 第一个满足条件的元素的值；如果所有元素都不满足条件，则返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The find method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let foundValue = array.find((value: number) => value % 2 === 0); // 返回4，第一个偶数元素
```

### includes

**方法**

```typescript
includes(searchElement: T, fromIndex?: number): boolean;
```

判断数组是否包含指定的元素，并返回一个布尔值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| searchElement | T | 是 | 要搜索的元素。 |
| fromIndex | number | 否 | 开始搜索的索引。如果省略，则从数组的第一个元素开始。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果数组包含指定的元素，则返回true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The includes method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let includesResult = array.includes(3); // 返回true，因为数组中包含3
```

### findIndex

**方法**

```typescript
findIndex(predicate: (value: T, index: number, obj: Array<T>) => boolean): number;
```

返回数组中第一个满足指定测试函数的元素的索引，如果所有元素都不满足，则返回-1。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| predicate | function | 是 | 一个接受三个参数的函数，用于测试每个元素是否满足条件。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 第一个满足条件的元素的索引；如果所有元素都不满足条件，则返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The findIndex method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array<number>(1, 2, 3, 4, 5);
let foundIndex = array.findIndex((value: number) => value % 2 === 0); // 返回1，因为2是第一个偶数元素
```

### fill

**方法**

```typescript
fill(value: T, start?: number, end?: number): Array<T>;
```

使用指定的值填充数组中指定范围的所有元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 要填充的值。 |
| start | number | 否 | 开始填充的索引。如果省略，则从数组的第一个元素开始。 |
| end | number | 否 | 结束填充的索引。如果省略，则填充到数组的最后一个元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array<T> | 填充后的数组。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The fill method cannot be bound. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
let array = new collections.Array(1, 2, 3, 4, 5);
array.fill(0, 1, 3); // 返回[1, 0, 0, 4, 5]，因为1到3的索引范围内的元素被替换为0
```
