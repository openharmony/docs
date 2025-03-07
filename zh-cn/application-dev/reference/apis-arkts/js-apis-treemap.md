# @ohos.util.TreeMap (非线性容器TreeMap)

TreeMap可用于存储具有关联关系的key-value键值对集合，存储元素中key值唯一，每个key对应一个value。

TreeMap底层使用红黑树实现，可以利用二叉树特性快速查找键值对。key值有序存储，可以实现快速的插入和删除。

TreeMap和[HashMap](js-apis-hashmap.md)相比，HashMap依据键的hashCode存取数据，访问速度较快。而TreeMap是有序存取，效率较低。

**推荐使用场景：** 一般需要存储有序键值对的场景，可以使用TreeMap。

文档中存在泛型的使用，涉及以下泛型标记符：

- K：Key，键

- V：Value，值

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { TreeMap } from '@kit.ArkTS';
```

## TreeMap

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | TreeMap的元素个数。 |


### constructor

constructor(comparator?:(firstValue: K, secondValue: K) => boolean)

TreeMap的构造函数，支持通过比较函数对元素进行升序或降序排序。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| comparator | function | 否 | 用户自定义的比较函数，可通过比较关系对元素进行排序。默认值为hole（一个空白占位符），表示不提供比较函数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed. |
| 10200012 | The TreeMap's constructor cannot be directly invoked. |

**示例：**

```ts
//默认构造
let treeMap : TreeMap<number, number> = new TreeMap();
```

```ts
//使用comparator firstValue < secondValue，表示期望结果为升序排序。反之firstValue > secondValue，表示为降序排序。
let treeMap : TreeMap<string,string> = new TreeMap<string,string>((firstValue: string, secondValue: string) : boolean => {return firstValue > secondValue});
treeMap.set("aa","3");
treeMap.set("dd","1");
treeMap.set("cc","2");
treeMap.set("bb","4");
let numbers = Array.from(treeMap.keys())
for (let item of numbers) {
  console.log("treeMap:" + item);
}
```

```ts
//当插入自定义类型时，则必须要提供比较函数。
 class TestEntry{
   public id: number = 0;
 }
 let ts1: TreeMap<TestEntry, string> = new TreeMap<TestEntry, string>((t1: TestEntry, t2: TestEntry): boolean => {return t1.id < t2.id;});
 let entry1: TestEntry = {
   id: 0
 };
 let entry2: TestEntry = {
   id: 1
 }
 ts1.set(entry1, "0");
 ts1.set(entry2, "1");
 console.log("treeMap: ", ts1.length);

```


### isEmpty

isEmpty(): boolean

判断该容器是否为空。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 为空返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The isEmpty method cannot be bound. |

**示例：**

```ts
let treeMap : TreeMap<number, number> = new TreeMap();
let result = treeMap.isEmpty();
```


### hasKey

hasKey(key: K): boolean

判断此容器中是否含有该指定key。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 指定key。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 包含指定key返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The hasKey method cannot be bound. |

**示例：**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
let result = treeMap.hasKey("squirrel");
```


### hasValue

hasValue(value: V): boolean

判断此容器中是否含有该指定value。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | V | 是 | 指定value。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 包含指定元素返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The hasValue method cannot be bound. |

**示例：**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
let result = treeMap.hasValue(123);
```


### get

get(key: K): V

获取指定key所对应的value，为空时返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 指定key。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| V | 返回key映射的value值，为空时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The get method cannot be bound. |

**示例：**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let result = treeMap.get("sparrow");
```


### getFirstKey

getFirstKey(): K

获取容器中排序第一的key，为空时返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| K | 返回排序第一的key，为空时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getFirstKey method cannot be bound. |

**示例：**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let result = treeMap.getFirstKey();
```


### getLastKey

getLastKey(): K

获取容器中排序最后的key，为空时返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| K | 返回排序最后的key，为空时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getLastKey method cannot be bound. |

**示例：**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let result = treeMap.getLastKey();
```


### setAll

setAll(map: TreeMap<K, V>): void

将一个TreeMap中的所有元素组添加到另一个TreeMap中。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| map | TreeMap<K, V> | 是 | 该map会添加到其调用setAll接口的map对象中。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The setAll method cannot be bound. |

**示例：**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let map : TreeMap<string, number> = new TreeMap();
map.set("demo", 12);
map.setAll(treeMap); // 将treeMap中的所有元素添加到map中
map.forEach((value ?: number, key ?: string) : void => {
  console.log("value" + value, "key" + key); // 打印结果 12 demo、356 sparrow、123 squirrel
})
```


### set

set(key: K, value: V): Object

向容器中添加或更新一组数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 添加成员数据的键名。 |
| value | V | 是 | 添加成员数据的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Object | 返回添加后的treeMap。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The set method cannot be bound. |

**示例：**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
```


### remove

remove(key: K): V

删除指定key对应的元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 指定key。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| V | 返回删除元素的值。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The remove method cannot be bound. |

**示例：**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let result = treeMap.remove("sparrow");
```


### getLowerKey

getLowerKey(key: K): K

获取容器中等于key或者比传入key排序靠前一位的key，为空时返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 对比的key值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| K | 返回排序中key前一位的数据，为空时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getLowerKey method cannot be bound. |

**示例：**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
treeMap.set("gander", 356);
let result = treeMap.getLowerKey("sparrow");
```


### getHigherKey

getHigherKey(key: K): K

获取容器中等于key或者比传入key排序靠后一位的key，为空时返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 对比的key值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| K | 返回排序中key后一位的数据，为空时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getHigherKey method cannot be bound. |

**示例：**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
treeMap.set("gander", 356);
let result = treeMap.getHigherKey("sparrow");
```

### replace

replace(key: K, newValue: V): boolean

对容器中一组数据进行更新（替换）。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 指定key。 |
| newValue | V | 是 | 替换的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 对指定key对应的元素替换成功返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The replace method cannot be bound. |

**示例：**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("sparrow", 123);
let result = treeMap.replace("sparrow", 357);
```


### clear

clear(): void

清除容器中的所有元素，并把length置为0。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The clear method cannot be bound. |

**示例：**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
treeMap.clear();
```


### keys

keys(): IterableIterator&lt;K&gt;

返回包含此映射中包含的键的新迭代器对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;K&gt; | 返回一个迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The keys method cannot be bound. |

**示例：**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let it = treeMap.keys();
let t: IteratorResult<string> = it.next();
while(!t.done) {
  console.log("TreeMap " + t.value);
  t = it.next()
}
```


### values

values(): IterableIterator&lt;V&gt;

返回包含此映射中键值的新迭代器对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;V&gt; | 返回一个迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The values method cannot be bound. |

**示例：**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let it = treeMap.values();
let t: IteratorResult<number> = it.next();
while(!t.done) {
  console.log("TreeMap" + t.value);
  t = it.next()
}
```


### forEach

forEach(callbackFn: (value?: V, key?: K, map?: TreeMap<K, V>) => void, thisArg?: Object): void

通过回调函数来遍历实例对象上的元素以及元素对应的下标。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 回调函数。 |
| thisArg | Object | 否 | callbackFn被调用时用作this值，默认值为当前实例对象。 |

callbackFn的参数说明：
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | V | 否 | 当前遍历到的元素键值对的值，默认值为首个键值对的值。 |
| key | K | 否 | 当前遍历到的元素键值对的键，默认值为首个键值对的键。 |
| map | TreeMap<K, V> | 否 | 当前调用forEach方法的实例对象，默认值为当前实例对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The forEach method cannot be bound. |

**示例：**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("sparrow", 123);
treeMap.set("gull", 357);
treeMap.forEach((value ?: number, key ?: string) : void => {
  console.log("value:" + value, "key:" + key);
});
```
```ts
 // 不建议在forEach中使用set、remove方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
 let treeMap : TreeMap<string, number> = new TreeMap();
 for(let i = 0; i < 10; i++) {
   treeMap.set("sparrow" + i, 123);
 }
 for(let i = 0;i < 10; i++) {
   treeMap.remove("sparrow" + i);
 }
```

### entries

entries(): IterableIterator<[K, V]>

返回包含此映射中键值对的新迭代器对象。

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
| 10200011 | The entries method cannot be bound. |

**示例：**

```ts
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);
let it = treeMap.entries();
let t: IteratorResult<Object[]> = it.next();
while(!t.done) {
  console.log("TreeMap" + t.value);
  t = it.next()
}
```
```ts
 // 不建议在entries中使用set、remove方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
 let treeMap : TreeMap<string, number> = new TreeMap();
 for(let i = 0; i < 10; i++) {
   treeMap.set("sparrow" + i, 123);
 }
 for(let i = 0;i < 10; i++) {
   treeMap.remove("sparrow" + i);
 }
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[K, V]&gt;

返回一个迭代器，迭代器的每一项都是一个JavaScript对象，并返回该对象。

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
let treeMap : TreeMap<string, number> = new TreeMap();
treeMap.set("squirrel", 123);
treeMap.set("sparrow", 356);

// 使用方法一：
let it = treeMap.entries();
let t: IteratorResult<Object[]> = it.next();
while(!t.done) {
  console.log("TreeMap" + t.value);
  t = it.next()
}

// 使用方法二：
 let iter = treeMap[Symbol.iterator]();
 let temp: IteratorResult<Object[]> = iter.next();
 while(!temp.done) {
   console.log("key:" + temp.value[0]);
   console.log("value:" + temp.value[1]);
   temp = iter.next();
 }
```
```ts
 // 不建议在Symbol.iterator中使用set、remove方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
 let treeMap : TreeMap<string, number> = new TreeMap();
 for(let i = 0; i < 10; i++) {
   treeMap.set("sparrow" + i, 123);
 }
 for(let i = 0;i < 10; i++) {
   treeMap.remove("sparrow" + i);
 }
```