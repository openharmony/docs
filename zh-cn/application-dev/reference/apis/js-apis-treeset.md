# 非线性容器TreeSet  

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

TreeSet基于[TreeMap](js-apis-treemap.md)实现，在TreeSet中，只对value对象进行处理。TreeSet可用于存储一系列值的集合，元素中value唯一且有序。

TreeSet和[HashSet](js-apis-hashset.md)相比，HashSet中的数据无序存放，而TreeSet是有序存放。它们集合中的元素都不允许重复，但HashSet允许放入null值，TreeSet不允许。

**推荐使用场景：** 一般需要存储有序集合的场景，可以使用TreeSet。

文档中存在泛型的使用,涉及以下泛型标记符:<br>
- T: Type, 类

## 导入模块

```ts
import TreeSet from '@ohos.util.TreeSet';  
```

## TreeSet

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | TreeSet的元素个数。 |


### constructor

constructor(comparator?: (firstValue: T, secondValue: T) => boolean)

TreeSet的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| comparator | function | 否 | 用户自定义的比较函数。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200012 | The TreeSet's constructor cannot be directly invoked. |

**示例：**

```ts
let treeSet = new TreeSet();
try {
  let treeSet2 = TreeSet();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### isEmpty

isEmpty(): boolean

判断该容器是否为空。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 为空返回true，不为空返回false。 |

**示例：**

```ts
const treeSet = new TreeSet();
let result = treeSet.isEmpty();
try {
  treeSet.isEmpty.bind({})();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### has

has(value: T): boolean

判断此容器中是否含有该指定元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 指定元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 包含指定元素返回true，否则返回false。 |

**示例：**

```ts
let treeSet = new TreeSet();
treeSet.has(123);
treeSet.add(123);
let result1 = treeSet.has(123);
try {
  treeSet.has.bind({}, 123)();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### getFirstValue

getFirstValue(): T

获取容器中排序第一的数据。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回排序第一的数据。 |

**示例：**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let result = treeSet.getFirstValue();
try {
  treeSet.getFirstValue.bind({})();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### getLastValue

getLastValue(): T

获取容器中排序最后的数据。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回排序最后的数据。 |

**示例：**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let result = treeSet.getLastValue();
try {
  treeSet.getLastValue.bind({})();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### add

add(value: T): boolean

向容器中添加一组数据。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 添加的成员数据。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 成功添加新数据至容器返回true，否则返回false。 |

**示例：**

```ts
let treeSet = new TreeSet();
let result = treeSet.add("squirrel");
try {
  treeSet.add.bind({}, "squirrel")();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### remove

remove(value: T): boolean

删除指定的元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 指定的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 成功删除元素返回true，否则返回false。 |

**示例：**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let result = treeSet.remove("sparrow");
try {
  treeSet.remove.bind({}, "sparrow")();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### getLowerValue

getLowerValue(key: T): T

获取容器中比传入元素排序靠前一位的元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | T | 是 | 对比的元素值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回排序中对比元素前一位的数据。 |

**示例：**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
treeSet.add("gander");
let result = treeSet.getLowerValue("sparrow");
try {
  treeSet.getLowerValue.bind({}, "sparrow")();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### getHigherValue

getHigherValue(key: T): T

获取容器中比传入元素排序靠后一位的元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | T | 是 | 对比的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回排序中传入元素后一位的数据。 |

**示例：**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
treeSet.add("gander");
let result = treeSet.getHigherValue("sparrow");
try {
  treeSet.getHigherValue.bind({}, "sparrow")();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### popFirst

popFirst(): T

删除容器中排序最前的数据。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回删除的数据。 |

**示例：**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let result = treeSet.popFirst();
try {
  treeSet.popFirst.bind({})();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### popLast

popLast(): T

删除容器中排序最后的数据。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回删除的数据。 |

**示例：**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let result = treeSet.popLast();
try {
  treeSet.popLast.bind({})();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### clear

clear(): void

清除容器中的所有元素，并把length置为0。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
treeSet.clear();
try {
  treeSet.clear.bind({})();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### values

values(): IterableIterator&lt;T&gt;

返回包含此映射中包含的键值的新迭代器对象。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;T&gt; | 返回一个迭代器。 |

**示例：**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let iter = treeSet.values();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
try {
  treeSet.values.bind({})();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### forEach

forEach(callbackfn: (value?: T, key?: T, set?: TreeSet&lt;T&gt;) => void, thisArg?: Object): void

通过回调函数来遍历实例对象上的元素以及元素对应的下标。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackfn | function | 是 | 回调函数。 |
| thisArg | Object | 否 | callbackfn被调用时用作this值。 |

callbackfn的参数说明：
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 否 | 当前遍历到的元素。 |
| key | T | 否 | 当前遍历到的元素（和value相同）。 |
| set | TreeSet&lt;T&gt; | 否 | 当前调用forEach方法的实例对象。 |

**示例：**

```ts
let treeSet = new TreeSet();
treeSet.add("sparrow");
treeSet.add("gull");
treeSet.forEach((value, key) => {
  console.log("value:" + value, key)
});
try {
  treeSet.forEach.bind({}, (value, key) => {
    console.log("value:" + value, key)
  })();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### entries

entries(): IterableIterator<[T, T]>

返回包含此映射中包含的键值对的新迭代器对象。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator<[T, T]> | 返回一个迭代器。 |

**示例：**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let iter = treeSet.entries();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("key:" + temp[0]);
  console.log("value:" + temp[1]);
  temp = iter.next().value;
}
try {
  treeSet.entries.bind({})();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象,并返回该对象。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;T&gt; | 返回一个迭代器 |

**示例：**

```ts
let treeSet = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
  
// 使用方法一：
for (let item of treeSet) { 
  console.log("value:" + item);
}

// 使用方法二：
let iter = treeSet[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
try {
  treeSet[Symbol.iterator].bind({})();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```