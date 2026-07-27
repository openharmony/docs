# Class (Set)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
一种存储唯一值的非线性数据结构，能够高效地进行元素存在性检测和去重操作。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 此模块仅支持在ArkTS文件（文件后缀为.ets）中导入使用。

文档中存在泛型的使用，涉及以下泛型类型参数：

- T：Type，支持[Sendable支持的数据类型](../../arkts-utils/arkts-sendable.md#sendable支持的数据类型)。

**装饰器类型：**\@Sendable

## 导入模块

```ts
import { collections } from '@kit.ArkTS';
```

## 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型   | 只读 | 可选 | 说明            |
| ---- | ------ | ---- | ---- | --------------- |
| size | number | 是   | 否   | Set的元素个数。 |

## constructor

constructor(values?: readonly T[] | null)

构造函数，用于创建ArkTS Set对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明                                                      |
| ------ | ---- | ---- | --------------------------------------------------------- |
| values | readonly T[] \| null | 否 | 数组或null。默认值为null，创建一个空Set对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 10200012 | The ArkTS Set's constructor cannot be directly invoked. |

**示例：**

```ts
// 正例1：
// 创建空的Set对象
const mySet = new collections.Set<number>();
```

```ts
// 正例2：
// 使用数组初始值创建Set
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
## constructor

constructor(iterable: Iterable\<T>)

构造函数，用于通过可迭代对象创建ArkTS Set对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明                              |
| ------ | ---- | ---- | ------------------------------- |
| iterable | Iterable\<T> | 是 | 用于构造ArkTS Set的可迭代对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 10200012 | The ArkTS Set's constructor cannot be directly invoked. |

**示例：**

```ts
// 创建标准Map对象
const mapper = new Map([
  ["1", "a"],
  ["2", "b"]
]);
// 通过标准Map的values()方法获取迭代器，构造ArkTS Set对象
let newSet = new collections.Set<string>(mapper.values());
console.info(newSet.has("a").toString()); // Expected output: true
console.info(newSet.has("b").toString()); // Expected output: true
```

## entries
entries(): IterableIterator<[T, T]>

返回一个Set迭代器对象，该对象包含了此Set中每个元素的键值对。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                           | 说明                    |
| ------------------------------ | ----------------------- |
| IterableIterator&lt;[T, T]&gt; | 返回一个Set迭代器对象，该对象包含了此Set中每个元素的键值对。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                              |
| -------- | ----------------------------------------------------- |
| 10200011 | The entries method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
// 创建Set对象
const mySet = new collections.Set<number>([0, 1, 2, 3]);
// 获取Set的entries迭代器
const iterator = mySet.entries();
// Expected output: [0, 0]
console.info(iterator.next().value);
// Expected output: [1, 1]
console.info(iterator.next().value);
```

## keys
keys(): IterableIterator\<T>

返回一个Set迭代器对象，该对象包含了此Set中每个元素的键。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                      | 说明                    |
| ------------------------- | ----------------------- |
| IterableIterator&lt;T&gt; | 返回一个Set迭代器对象，该对象包含了此Set中每个元素的键。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                           |
| -------- | -------------------------------------------------- |
| 10200011 | The keys method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
// 创建Set对象
const mySet = new collections.Set<number>([0, 1, 2, 3]);
// 获取Set的keys迭代器
const iterator = mySet.keys();
// Expected output: 0
console.info(iterator.next().value);
// Expected output: 1
console.info(iterator.next().value);
```

## values
values(): IterableIterator\<T>

返回一个Set迭代器对象，该对象包含了此Set中每个元素的值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型                      | 说明                    |
| ------------------------- | ----------------------- |
| IterableIterator&lt;T&gt; | 返回一个Set迭代器对象，该对象包含了此Set中每个元素的值。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 10200011 | The values method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error. |

**示例：**

```ts
// 例1：
// 创建Set对象
const mySet = new collections.Set<number>([0, 1, 2, 3]);
// 获取values迭代器
const iterator = mySet.values();
// Expected output: 0
console.info(iterator.next().value);
// Expected output: 1
console.info(iterator.next().value);
```

```ts
// 例2：
// 创建Set对象
const mySet = new collections.Set<number>([0, 1, 2, 3]);
// 获取values迭代器
const valueIter = mySet.values();
// 遍历Set并删除偶数元素
for (let value of valueIter) {
  if (value % 2 == 0) {
    mySet.delete(value);
  }
}

// Expected output: 2
console.info("size:" + mySet.size);
```

## clear
clear(): void

删除该Set中的所有元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                            |
| -------- | --------------------------------------------------- |
| 10200011 | The clear method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                  |

**示例：**

```ts
// 创建Set对象
const mySet = new collections.Set<number>([0, 1]);
// Expected output: 2
console.info("size:" + mySet.size);
// 清除Set中的所有元素
mySet.clear();
// Expected output: 0
console.info("size:" + mySet.size);
```

## delete
delete(value: T): boolean

删除该Set中指定元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明             |
| ------ | ---- | ---- | ---------------- |
| value    | T    | 是   | 待删除元素的值。 |

**返回值：**

| 类型    | 说明                              |
| ------- | --------------------------------- |
| boolean | 成功删除返回true，指定元素不存在时返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                             |
| -------- | ---------------------------------------------------- |
| 10200011 | The delete method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                   |


**示例：**

```ts
// 创建Set对象
const mySet = new collections.Set<string>(["hello", "world"]);
// 删除Set中的指定元素
// Expected result: true
console.info("result:" + mySet.delete("hello"));
// 判断元素是否仍存在
// Expected result: false
console.info("result:" + mySet.has("hello"));
// 再次删除已删除的元素
// Expected result: false
console.info("result:" + mySet.delete("hello"));
```

## forEach
forEach(callbackFn: (value: T, value2: T, set: Set\<T>) => void): void

按插入顺序对该Set中的每个键值对执行一次回调函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型                                         | 必填 | 说明       |
| ---------- | -------------------------------------------- | ---- | ---------- |
| callbackFn | (value: T, value2: T, set: Set\<T>) => void  | 是   | 回调函数。回调执行期间不应修改当前Set对象，否则会触发并发修改错误。  |

callbackFn的参数说明：
| 参数名 | 类型         | 必填 | 说明                         |
| ------ | ------------ | ---- | ---------------------------- |
| value  | T            | 否   | 当前遍历到的元素键值对的值。 |
| value2 | T            | 否   | 当前遍历到的元素键值对的键。 |
| set    | Set&lt;T&gt; | 否   | 当前Set实例对象。            |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                              |
| -------- | ----------------------------------------------------- |
| 10200011 | The forEach method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                    |

**示例：**

```ts
// 正例：
// 遍历Set中每个元素
new collections.Set<string>(["foo", "bar", "baz"]).forEach((value1, value2, set) => {
  console.info(`s[${value1}] = ${value2}`);
});
```

<!--code_no_check-->
```ts
// 反例：
new collections.Set<string>(["foo", "bar", "baz"]).forEach((value1, value2, set) => {
  // Throw exception `Concurrent modification error.`
  set.delete(value1);
});
```

## has
has(value: T): boolean

判断该Set中是否存在指定元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型 | 必填 | 说明             |
| ------ | ---- | ---- | ---------------- |
| value  | T    | 是   | 待查找元素的值。 |

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果存在指定元素，则返回true；否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The has method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                |

**示例：**

```ts
// 创建Set对象
const mySet = new collections.Set<string>(["hello", "world"]);
// 判断Set中是否存在指定元素
// Expected output: true
console.info("result:" + mySet.has("hello"));
// Expected output: true
console.info("result:" + mySet.has("world"));
```

## add
add(value: T): Set\<T>

如果Set中不存在该元素，则将其插入Set中。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型 | 必填 | 说明             |
| ------ | ---- | ---- | ---------------- |
| value  | T    | 是   | 待插入元素的值。  |

**返回值：**

| 类型         | 说明      |
| ------------ | --------- |
| Set&lt;T&gt; | 插入元素后的Set对象本身。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The add method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                |

**示例：**

```ts
// 正例：
// 创建空的Set对象
const mySet: collections.Set<string> = new collections.Set<string>();
// 向Set中添加新元素
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

## [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

返回一个迭代器，迭代器包含Set中的所有元素。

> **说明：**
>
> 本接口不支持在.ets文件中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;T&gt; | 包含Set中所有元素的迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**示例：**

```ts
// 创建Set对象
let mySet = new collections.Set<number>([1, 2, 3, 4, 5]);
// 将Set的values转换为数组
let values: Array<number> = Array.from(mySet.values());
// 遍历并输出每个元素
for (let item of values) {
  console.info("value: " + item);
}
```
