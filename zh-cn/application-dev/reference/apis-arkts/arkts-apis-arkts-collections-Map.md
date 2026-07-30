# Class (Map)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @weng-changcheng-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->
一种基于键值对存储的非线性数据结构，能够高效地通过唯一键来存取对应的值。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 此模块仅支持在ArkTS文件（文件后缀为.ets）中导入使用。

文档中存在泛型的使用，涉及以下泛型类型参数：

- K：Key，键
- V：Value，值

K和V类型都需为[Sendable支持的数据类型](../../arkts-utils/arkts-sendable.md#sendable支持的数据类型)。

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
| size | number | 是   | 否   | Map的元素个数。 |


## constructor
constructor(entries?: readonly (readonly [K, V])[] | null)

构造函数，用于创建ArkTS Map对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名  | 类型   | 必填 | 说明                                                         |
| ------- | ------ | ---- | ------------------------------------------------------------ |
| entries | readonly (readonly [K, V])[] \| null | 否   | 键值对数组或null。默认值为null，创建一个空Map对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 10200012 | The ArkTS Map's constructor cannot be directly invoked. |

**示例：**

```ts
// 正例1：
// 创建空的ArkTS Map对象
const myMap = new collections.Map<number, number>();
```

```ts
// 正例2：
// 通过键值对数组创建含初始元素的ArkTS Map对象
const myMap = new collections.Map<number, string>([
  [1, "one"],
  [2, "two"],
  [3, "three"]
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

## constructor

constructor(iterable: Iterable\<readonly \[K, V]>)

构造函数，用于通过可迭代对象创建ArkTS Map对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明                              |
| ------ | ---- | ---- | ------------------------------- |
| iterable | Iterable\<readonly \[K, V]> | 是 | 用于构造ArkTS Map的可迭代对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                                |
| -------- | ------------------------------------------------------- |
| 10200012 | The ArkTS Map's constructor cannot be directly invoked. |

**示例：**

```ts
// 创建标准Map对象
const mapper = new Map([
  ["1", "a"],
  ["2", "b"]
]);
// 通过标准Map的entries()方法获取迭代器，构造ArkTS Map对象
let newMap = new collections.Map<string, string>(mapper.entries());
console.info(newMap.get("1")); // Expected output: a
console.info(newMap.get("2")); // Expected output: b
```


## entries
entries(): IterableIterator<[K, V]>

返回一个Map迭代器对象，该对象包含了此Map中的每个元素的[key, value]对。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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
| 10200201 | Concurrent modification error. |

**示例：**

```ts
// 例1：
// 创建Map对象
const myMap = new collections.Map<number, string>([
  [0, "foo"],
  [1, "bar"]
]);
// 调用entries()方法，返回包含Map中每个元素[key, value]对的迭代器
const iterator = myMap.entries();
// Expected output: 0, foo
console.info(iterator.next().value);
// Expected output: 1, bar
console.info(iterator.next().value);
```

```ts
// 例2：
// 创建Map对象
const myMap: collections.Map<number, string> = new collections.Map<number, string>([
  [0, "one"],
  [1, "two"],
  [2, "three"],
  [3, "four"]
]);
// 返回一个myMap迭代器对象，该对象包含了此myMap中的每个元素的[number, string]键值对。
const entriesIter: IterableIterator<[number, string]> = myMap.entries();
// 遍历entriesIter迭代器对象。
for (const entry of entriesIter) {
  if (entry[1].startsWith("t")) {
    myMap.delete(entry[0]);
  }
}
// Expected output: 2
console.info("size:" + myMap.size);
```

## keys
keys(): IterableIterator\<K>

返回一个Map迭代器对象，该对象包含了此Map中每个元素的键。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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
| 10200201 | Concurrent modification error. |

**示例：**

```ts
// 创建Map对象
const myMap = new collections.Map<number, string>([
  [0, "foo"],
  [1, "bar"]
]);
// 调用keys()方法，返回包含Map中所有键的迭代器
const iterator = myMap.keys();
// Expected output: 0
console.info(iterator.next().value);
// Expected output: 1
console.info(iterator.next().value);
```

## values
values(): IterableIterator\<V>

返回一个Map迭代器对象，该对象包含了此Map中每个元素的值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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
| 10200201 | Concurrent modification error. |

**示例：**

```ts
// 创建Map对象
const myMap = new collections.Map<number, string>([
  [0, "foo"],
  [1, "bar"]
]);
// 调用values()方法，返回包含Map中所有值的迭代器
const iterator = myMap.values();
// Expected output: "foo"
console.info(iterator.next().value);
// Expected output: "bar"
console.info(iterator.next().value);
```

## clear
clear(): void

删除该Map中的所有元素。

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
// 创建Map对象
const myMap = new collections.Map<number, string>([
  [0, "foo"],
  [1, "bar"]
]);
// Expected output: 2
console.info("size:" + myMap.size);
// 调用clear()方法，删除Map中的所有元素
myMap.clear();
// Expected output: 0
console.info("size:" + myMap.size);
```

## delete
delete(key: K): boolean

删除该Map中指定键对应的元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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
| 10200201 | Concurrent modification error.                   |


**示例：**

```ts
// 创建Map对象
const myMap = new collections.Map<string, string>([
  ["hello", "world"],
]);
// 删除Map中的指定键
// Expected result: true
console.info("result:" + myMap.delete("hello"));
// 判断键是否仍存在
// Expected result: false
console.info("result:" + myMap.has("hello"));
// 再次删除已删除的键
// Expected result: false
console.info("result:" + myMap.delete("hello"));
```

## forEach
forEach(callbackFn: (value: V, key: K, map: Map<K, V>) => void): void

按插入顺序对该Map中的每个键值对执行一次回调函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名     | 类型                                       | 必填 | 说明       |
| ---------- | ------------------------------------------ | ---- | ---------- |
| callbackFn | (value: V, key: K, map: Map<K, V>) => void | 是   | 回调函数。回调执行期间不能修改当前Map对象，否则会触发并发修改错误。 |

callbackFn的参数说明：
| 参数名 | 类型            | 必填 | 说明                         |
| ------ | --------------- | ---- | ---------------------------- |
| value  | V               | 否   | 当前遍历到的元素键值对的值。 |
| key    | K               | 否   | 当前遍历到的元素键值对的键。 |
| map    | Map&lt;K, V&gt; | 否   | 当前Map实例对象。            |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                              |
| -------- | ----------------------------------------------------- |
| 10200011 | The forEach method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                    |

**示例：**

```ts
// 正例：
// 遍历Map中每个元素
new collections.Map<string, number>([
  ["foo", 0],
  ["bar", 1],
  ["baz", 2],
]).forEach((value, key, map) => {
  console.info(`m[${key}] = ${value}`);
});
```

<!--code_no_check-->
```ts
// 反例：
new collections.Map<string, number>([
  ["foo", 0],
  ["bar", 1],
  ["baz", 2],
]).forEach((value, key, map) => {
  // Throw exception `Concurrent modification error.`
  map.delete(key);
});
```

## get
get(key: K): V | undefined

返回该Map中指定键对应的元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明      |
| ------ | ---- | ---- | --------- |
| key    | K    | 是   | 要获取值的键。 |

**返回值：**

| 类型 | 说明                                                         |
| ---- | ------------------------------------------------------------ |
| V \| undefined    | 与指定键相关联的元素，如果键在Map对象中找不到，则返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The get method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                |

**示例：**

```ts
const myMap = new collections.Map<string, string>([
  ["hello", "world"],
]);
// Expected output: "world"
console.info(myMap.get("hello"));
// Expected output: undefined
console.info(myMap.get("hel"));
```

## has
has(key: K): boolean

判断该Map中是否存在指定键。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明      |
| ------ | ---- | ---- | --------- |
| key    | K    | 是   | 待查找元素的键。 |

**返回值：**

| 类型    | 说明                                          |
| ------- | --------------------------------------------- |
| boolean | 如果Map中存在指定键，则返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The has method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                |

**示例：**

```ts
// 创建Map对象
const myMap = new collections.Map<string, string>([
  ["hello", "world"],
]);
// 判断Map中是否存在指定键
// Expected output: true
console.info("result:" + myMap.has("hello"));
// Expected output: false
console.info("result:" + myMap.has("world"));
```

## set
set(key: K, value: V): Map<K, V>

向该Map添加或更新一个指定的键值对。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明      |
| ------ | ---- | ---- | --------- |
| key    | K    | 是   | 要添加或更新的键。 |
| value    | V    | 是   | 要添加或更新的值。 |

**返回值：**

| 类型            | 说明    |
| --------------- | ------- |
| Map&lt;K, V&gt; | 添加或更新键值对操作后的Map对象本身。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息                                          |
| -------- | ------------------------------------------------- |
| 10200011 | The set method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification error.                |

**示例：**

```ts
// 正例：
const myMap = new collections.Map<string, string>();
// 调用set()方法，向Map中添加键"foo"对应值"bar"
myMap.set("foo", "bar");
```

<!--code_no_check-->
```ts
// 反例：
let obj = new Object();
const myMap: collections.Map<string, Object> = new collections.Map<string, Object>();
// Type arguments of generic "Sendable" type must be a "Sendable" data type (arkts-sendable-generic-types)
myMap.set("foo", obj);
```

## [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[K, V]&gt;

返回一个迭代器，迭代器包含Map中每个元素的键值对。

> **说明：**
>
> 本接口不支持在.ets文件中使用。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| IterableIterator<[K, V]> | 包含Map中每个元素键值对的迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**示例：**

```ts
let myMap = new collections.Map<number, string>([
    [0, "one"],
    [1, "two"],
    [2, "three"],
    [3, "four"]
]);
// 通过Array.from和keys()获取所有键的数组
let keys = Array.from(myMap.keys());
// 遍历每个键，通过get()方法获取对应的值
for (let key of keys) {
  console.info("key:" + key);
  console.info("value:" + myMap.get(key));
}
```
