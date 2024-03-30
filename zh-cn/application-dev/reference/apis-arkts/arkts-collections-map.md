# @arkts.collections.Map (ArkTS Map)

ArkTS Map与JavaScript内建的Map类似，是一种非线性数据结构。两者最大的区别在于:
- ArkTS Map支持在多个线程间共享访问；
- ArkTS Map实例无法通过`.`或`[]`添加或更新属性。

默认情况下，ArkTS Map对象在线程间传输的行为是引用传递，同时也支持拷贝传递。如果通过引用传递，当多个线程同时访问时，可能会发生数据竞争。
为此，ArkTS提供了[异步锁]()机制来保护多线程安全访问。

**推荐使用场景：** 多线程共享。

文档中存在泛型的使用，涉及以下泛型标记符：

- K：Key，键
- V：Value，值

类型K和V都需为[Sendable类型](../../arkts-utils/arkts-sendable.md)。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { collections } from '@Kit.ArkTS';
```

## Map

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| size | number | 是 | 否 | Map的元素个数。|


### constructor
```ts
constructor(entries?: readonly (readonly [K, V])[] | null);
```

Map的构造函数，创建Map对象。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| entries | [K, V] \| null | 否 | 键值对数组或其它可迭代对象，默认为null，创建一个空的Map |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200012 | The ArkTS Map's constructor cannot be directly invoked. |

**示例：**

```ts
const myMap = new collections.Map<number, number>();
```

```ts
const myMap = new collections.Map<number, string>([
  [1, "one"],
  [2, "two"],
  [3, "three"],
]);
```

```ts
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
```ts
entries(): IterableIterator<[K, V]>;
```

返回一个map迭代器对象，该对象包含了此map中的每个元素的[key, value]对。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[K, V]&gt; | 返回一个map迭代器对象。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The entries method cannot be bound with non-sendable. |

**示例：**

```ts
const myMap = new collections.Map<number, string>([
  [0, "foo"],
  [1, "bar"]
]);

const iterator = myMap.entries();
// Expected output: [0, "foo"]
console.log(iterator.next().value);
// Expected output: [1, "bar"]
console.log(iterator.next().value);
```

```ts
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
console.log("size:" + myMap.size);
```

### keys
```ts
keys(): IterableIterator<K>;
```

返回一个map迭代器对象，该对象包含了此map中每个元素的键。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;K&gt; | 返回一个map迭代器对象。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The keys method cannot be bound with non-sendable. |

**示例：**

```ts
const myMap = new collections.Map<number, string>([
  [0, "foo"],
  [1, "bar"]
]);

const iterator = myMap.keys();
// Expected output: 0
console.log(iterator.next().value);
// Expected output: 1
console.log(iterator.next().value);
```

### values
```ts
values(): IterableIterator<V>;
```

返回一个map迭代器对象，该对象包含此map中每个元素的值。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;V&gt; | 返回一个map迭代器对象。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The values method cannot be bound with non-sendable. |

**示例：**

```ts
const myMap = new collections.Map<number, string>([
  [0, "foo"],
  [1, "bar"]
]);

const iterator = myMap.values();
// Expected output: "foo"
console.log(iterator.next().value);
// Expected output: "bar"
console.log(iterator.next().value);
```

### clear
```ts
clear(): void;
```

删除该map中的所有元素。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The clear method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
const myMap = new collections.Map<number, string>([
  [0, "foo"],
  [1, "bar"]
]);
// Expected output: 2
console.log("size:" + myMap.size);
myMap.clear();
// Expected output: 0
console.log("size:" + myMap.size);
```

### delete
```ts
delete(key: K): boolean;
```

删除该map中指定元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 待删除元素的键。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果元素存在并已被删除，则为true；否则该元素不存在，返回false。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The delete method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception. |


**示例：**

```ts
const myMap = new collections.Map<string, string>([
  ["hello", "world"],
]);
// Expected result: true
console.log("result:" + myMap.delete("hello"));
// Expected result: false
console.log("result:" + myMap.has("hello"));
// Expected result: false
console.log("result:" + myMap.delete("hello"));
```

### forEach
```ts
forEach(callbackFn: (value: V, key: K, map: Map<K, V>) => void): void;
```

按插入顺序对该map中的每个键/值对执行一次回调函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 回调函数。|

callbackFn的参数说明：
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | V | 否 | 当前遍历到的元素键值对的值。|
| key | K | 否 | 当前遍历到的元素键值对的键。|
| map | Map&lt;K, V&gt; | 否 | 当前map实例对象。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The forEach method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
new collections.Map<string, number>([
  ['foo', 0],
  ['bar', 1],
  ['baz', 2],
]).forEach((value, key, map) => {
  console.log(`m[${key}] = ${value}`);
});
```

```ts
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
```ts
get(key: K): V | undefined;
```

返回该map中的指定元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 指定key。|

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| V | 与指定键相关联的元素，如果键在Map对象中找不到，则返回undefined。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The get method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
const myMap = new collections.Map<string, string>([
  ["hello", "world"],
]);
// Expected output: "foo"
console.log(myMap.get("hello"));
// Expected output: undefined
console.log(myMap.get("world"));
```

### has
```ts
has(key: K): boolean;
```

判断该Map中是否存在指定元素。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果存在指定元素，则返回true，否则返回false。|

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The has method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
const myMap = new collections.Map<string, string>([
  ["hello", "world"],
]);
// Expected output: true
console.log("result:" + myMap.has("hello"));
// Expected output: false
console.log("result:" + myMap.has("world"));
```

### set
```ts
set(key: K, value: V): Map<K, V>;
```

向该Map添加或更新一个指定的键值对。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Map&lt;K, V&gt; | Map对象 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401 | Parameter error. |
| 10200011 | The set method cannot be bound with non-sendable. |
| 10200201 | Concurrent modification exception. |

**示例：**

```ts
const myMap = new collections.Map<string, string>();
myMap.set("foo", "bar")
```

```ts
let obj = new Object();
const myMap = new collections.Map<string, Object>();
// Throw exception `Parameter error. Only accept sendable value`
myMap.set("foo", obj)
```