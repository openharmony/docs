# 非线性容器TreeMap  

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

TreeMap可用于存储具有关联关系的key-value键值对集合，存储元素中key值唯一，每个key对应一个value。

TreeMap底层使用红黑树实现，可以利用二叉树特性快速查找键值对。key值有序存储，可以实现快速的插入和删除。

TreeMap和[HashMap](js-apis-treemap.md)相比，HashMap依据键的hashCode存取数据，访问速度较快。而TreeMap是有序存取，效率较低。

**推荐使用场景：** 一般需要存储有序键值对的场景，可以使用TreeMap。

## 导入模块

```ts
import TreeMap from '@ohos.util.TreeMap';  
```

## 系统能力

SystemCapability.Utils.Lang

## TreeMap


### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | TreeMap的元素个数。 |


### constructor

constructor(comparator?:(firstValue: K, secondValue: K) => boolean)

TreeMap的构造函数。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| comparator | function | 否 | 用户自定义的比较函数。 |

**示例：**

```ts
let treeMap = new TreeMap();
```


### isEmpty

isEmpty(): boolean

判断该容器是否为空。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 为空返回true，否则返回false。 |

**示例：**

```ts
const treeMap = new TreeMap();
let result = treeMap.isEmpty();
```


### hasKey

hasKey(key: K): boolean

判断此容器中是否含有该指定key。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 指定key |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 包含指定key返回true，否则返回false。 |

**示例：**

```ts
let treeMap = new TreeMap();
let result = treeMap.hasKey("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
let result1 = treeMap.hasKey("Ahfbrgrbgnutfodgorrogorgrogofdfdf");
```


### hasValue

hasValue(value: V): boolean

判断此容器中是否含有该指定value。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | V | 是 | 指定value。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 包含指定元素返回true，否则返回false。 |

**示例：**

```ts
let treeMap = new TreeMap();
let result = treeMap.hasValue(123);
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
let result1 = treeMap.hasValue(123);
```


### get

get(key: K): V

获取指定key所对应的value。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 指定key。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| V | 返回key映射的value值。 |

**示例：**

```ts
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
let result = treeMap.get("sdfs");
```


### getFirstKey

getFirstKey(): K

获取容器中排序第一的key。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| K | 返回排序第一的key。 |

**示例：**

```ts
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
let result = treeMap.getFirstKey();
```


### getLastKey

getLastKey(): K

获取容器中排序最后的key。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| K | 返回排序最后的key |

**示例：**

```ts
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
let result = treeMap.getLastKey();
```


### setAll

setAll(map: TreeMap<K, V>): void

将一个TreeMap中的所有元素组添加到另一个TreeMap中。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| map | TreeMap<K, V> | 是 | 被添加元素的treeMap。 |

**示例：**

```ts
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
let map = new TreeMap();
treeMap.setAll(map);
```


### set

set(key: K, value: V): Object

向容器中添加一组数据。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 添加成员数据的键名。 |
| value | V | 是 | 添加成员数据的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Object | 返回添加后的treeMap |

**示例：**

```ts
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
```


### remove

remove(key: K): V

删除指定key对应的元素。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 指定key。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| V | 返回删除元素的值。 |

**示例：**

```ts
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
treeMap.remove("sdfs");
```


### getLowerKey

getLowerKey(key: K): K

获取容器中比传入key排序靠前一位的key。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 对比的key值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| K | 返回排序中key前一位的数据。 |

**示例：**

```ts
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
treeMap.set("zdfgsd", 356);
let result = treeMap.getLowerKey("sdfs");
```


### getHigherKey

getHigherKey(key: K): K

获取容器中比传入key排序靠后一位的key。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 对比的key值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| K | 返回排序中key后一位的数据。 |

**示例：**

```ts
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
treeMap.set("zdfgsd", 356);
let result = treeMap.getHigherKey("sdfs");
```

### replace

replace(key: K, newValue: V): boolean

对容器中一组数据进行更新（替换）。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 指定key。 |
| newValue | V | 是 | 替换的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 对指定key对应的元素替换成功返回true，否则返回false。 |

**示例：**

```ts
let treeMap = new TreeMap();
treeMap.set("sdfs", 123);
let result = treeMap.replace("sdfs", 357);
```


### clear

clear(): void

清除容器中的所有元素，并把length置为0。

**示例：**

```ts
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
treeMap.clear();
```


### keys

keys(): IterableIterator&lt;K&gt;

返回包含此映射中包含的键的新迭代器对象。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;K&gt; | 返回一个迭代器。 |

**示例：**

```ts
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
let iter = treeMap.keys();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
} 
```


### values

values(): IterableIterator&lt;V&gt;

返回包含此映射中包含的键值的新迭代器对象。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;V&gt; | 返回一个迭代器。 |

**示例：**

```ts
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
let iter = treeMap.values();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
```


### forEach

forEach(callbackfn: (value?: V, key?: K, map?: TreeMap<K, V>) => void, thisArg?: Object): void

通过回调函数来遍历实例对象上的元素以及元素对应的下标。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackfn | function | 是 | 回调函数。 |
| thisArg | Object | 否 | callbackfn被调用时用作this值。 |

callbackfn的参数说明：
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | V | 否 | 当前遍历到的元素键值对的值。 |
| key | K | 否 | 当前遍历到的元素键值对的键。 |
| map | TreeMap<K, V> | 否 | 当前调用forEach方法的实例对象。 |

**示例：**

```ts
let treeMap = new TreeMap();
treeMap.set("sdfs", 123);
treeMap.set("dfsghsf", 357);
treeMap.forEach((value, key) => {
  console.log("value:" + value, key);
});
```


### entries

entries(): IterableIterator<[K, V]>

返回包含此映射中包含的键值对的新迭代器对象。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator<[K, V]> | 返回一个迭代器。 |

**示例：**

```ts
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);
let iter = treeMap.entries();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("key:" + temp[0]);
  console.log("value:" + temp[1]);
  temp = iter.next().value;
}
```


### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[K, V]&gt;


返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象，并返回该对象。

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| IterableIterator<[K, V]> | 返回一个迭代器。 |

**示例：**

```ts
let treeMap = new TreeMap();
treeMap.set("Ahfbrgrbgnutfodgorrogorgrogofdfdf", 123);
treeMap.set("sdfs", 356);

// 使用方法一：
for (let item of treeMap) { 
  console.log("key:" + item[0]);
  console.log("value:" + item[1]);
}

// 使用方法二：
let iter = treeMap[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("key:" + temp[0]);
  console.log("value:" + temp[1]);
  temp = iter.next().value;
}
```