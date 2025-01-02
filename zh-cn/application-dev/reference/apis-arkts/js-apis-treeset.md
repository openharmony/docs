# @ohos.util.TreeSet (非线性容器TreeSet)

TreeSet基于[TreeMap](js-apis-treemap.md)实现，在TreeSet中，只对value对象进行处理。TreeSet可用于存储一系列值的集合，元素中value唯一且有序。

TreeSet和[HashSet](js-apis-hashset.md)相比，HashSet中的数据无序存放，而TreeSet是有序存放。它们集合中的元素都不允许重复，但HashSet允许放入null值，TreeSet不建议插入空值，可能会影响排序结果。

**推荐使用场景：** 一般需要存储有序集合的场景，可以使用TreeSet。

文档中存在泛型的使用，涉及以下泛型标记符：

- T：Type，类

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { TreeSet } from '@kit.ArkTS';
```

## TreeSet

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | TreeSet的元素个数。 |


### constructor

constructor(comparator?: (firstValue: T, secondValue: T) => boolean)

TreeSet的构造函数，支持通过比较函数对元素进行升序或降序排序。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| comparator | function | 否 | 用户自定义的比较函数，可通过比较关系对元素进行排序。默认值为hole（一个空白占位符），表示不提供比较函数。|

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed. |
| 10200012 | The TreeSet's constructor cannot be directly invoked. |

**示例：**

```ts
//默认构造
let treeSet : TreeSet<string | number | boolean | Object> = new TreeSet();
```

```ts
//使用comparator firstValue < secondValue，表示期望结果为升序排序。反之firstValue > secondValue，表示为降序排序。
let treeSet : TreeSet<string> = new TreeSet<string>((firstValue: string, secondValue: string) : boolean => {return firstValue < secondValue});
treeSet.add("a");
treeSet.add("c");
treeSet.add("d");
treeSet.add("b");
let numbers = Array.from(treeSet.values())
for (let item of numbers) {
  console.log("TreeSet:" + item);
}
```

```ts
//当插入自定义类型时，则必须要提供比较函数。
class TestEntry{
  public id: number = 0;
}
let ts1: TreeSet<TestEntry> = new TreeSet<TestEntry>((t1: TestEntry, t2: TestEntry): boolean => {return t1.id > t2.id;});
let entry1: TestEntry = {
  id: 0
};
let entry2: TestEntry = {
  id: 1
}
ts1.add(entry1);
ts1.add(entry2);
console.log("treeSet: ", ts1.length);
```


### isEmpty

isEmpty(): boolean

判断该容器是否为空。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 为空返回true，不为空返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The isEmpty method cannot be bound. |

**示例：**

```ts
const treeSet : TreeSet<string | number | boolean | Object>  = new TreeSet();
let result = treeSet.isEmpty();
```


### has

has(value: T): boolean

判断此容器中是否含有该指定元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 指定元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 包含指定元素返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The has method cannot be bound. |

**示例：**

```ts
let treeSet : TreeSet<number> = new TreeSet();
treeSet.add(123);
let result = treeSet.has(123);
```

### getFirstValue

getFirstValue(): T

获取容器中排序第一的数据，为空时返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回排序第一的数据，为空时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getFirstValue method cannot be bound. |

**示例：**

```ts
let treeSet : TreeSet<string> = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let result = treeSet.getFirstValue();
```


### getLastValue

getLastValue(): T

获取容器中排序最后的数据，为空时返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回排序最后的数据，为空时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getLastValue method cannot be bound. |

**示例：**

```ts
let treeSet : TreeSet<string> = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let result = treeSet.getLastValue();
```


### add

add(value: T): boolean

向容器中添加一组数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 添加的成员数据。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 成功添加新数据至容器返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The add method cannot be bound. |

**示例：**

```ts
let treeSet : TreeSet<string> = new TreeSet();
let result = treeSet.add("squirrel");
```


### remove

remove(value: T): boolean

删除指定的元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 指定的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 成功删除元素返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The remove method cannot be bound. |

**示例：**

```ts
let treeSet : TreeSet<string> = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let result = treeSet.remove("sparrow");
```


### getLowerValue

getLowerValue(key: T): T

获取容器中比传入元素排序靠前一位的元素，为空时返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | T | 是 | 对比的元素值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回排序中对比元素前一位的数据，为空时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The getLowerValue method cannot be bound. |

**示例：**

```ts
let treeSet : TreeSet<string> = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
treeSet.add("gander");
let result = treeSet.getLowerValue("sparrow");
```


### getHigherValue

getHigherValue(key: T): T

获取容器中比传入元素排序靠后一位的元素，为空时返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | T | 是 | 对比的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回排序中传入元素后一位的数据。为空时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The getHigherValue method cannot be bound. |

**示例：**

```ts
let treeSet : TreeSet<string> = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
treeSet.add("gander");
let result = treeSet.getHigherValue("sparrow");
```


### popFirst

popFirst(): T

删除容器中排序最前的数据，为空时返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回删除的数据，为空时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The popFirst method cannot be bound. |

**示例：**

```ts
let treeSet : TreeSet<string> = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let result = treeSet.popFirst();
```


### popLast

popLast(): T

删除容器中排序最后的数据，为空时返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回删除的数据，为空时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The popLast method cannot be bound. |

**示例：**

```ts
let treeSet : TreeSet<string> = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let result = treeSet.popLast();
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
let treeSet : TreeSet<string> = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
treeSet.clear();
```


### values

values(): IterableIterator&lt;T&gt;

返回包含此映射中键值的新迭代器对象。

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
| 10200011 | The values method cannot be bound. |

**示例：**

```ts
let treeSet : TreeSet<string> = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let it = treeSet.values();
let t: IteratorResult<string> = it.next();
while(!t.done) {
  console.log("TreeSet: " + t.value);
  t = it.next()
}
```


### forEach

forEach(callbackFn: (value?: T, key?: T, set?: TreeSet&lt;T&gt;) => void, thisArg?: Object): void

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
| value | T | 否 | 当前遍历到的value元素，默认值为首个键值对的值。 |
| key | T | 否 | 当前遍历到的key元素，默认值为首个键值对的键。 |
| set | TreeSet&lt;T&gt; | 否 | 当前调用forEach方法的实例对象，默认值为当前实例对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The forEach method cannot be bound. |

**示例：**

```ts
let treeSet : TreeSet<string> = new TreeSet();
treeSet.add("sparrow");
treeSet.add("gull");
treeSet.forEach((value ?: string, key ?: string) :void => {
  console.log("value:" + value, "key:" + key);
});
```
```ts
// 不建议在forEach中使用set、remove方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
let treeSet : TreeSet<string> = new TreeSet();
for(let i = 0; i < 10; i++) {
  treeSet.add("sparrow" + i);
}
for(let i = 0; i < 10; i++) {
  treeSet.remove("sparrow" + i);
}
```

### entries

entries(): IterableIterator<[T, T]>

返回包含此映射中键值对的新迭代器对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator<[T, T]> | 返回一个迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The entries method cannot be bound. |

**示例：**

```ts
let treeSet : TreeSet<string> = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let it = treeSet.entries();
let t: IteratorResult<Object[]> = it.next();
while(!t.done) {
  console.log("TreeSet: " + t.value);
  t = it.next()
}
```
```ts
// 不建议在entries中使用set、remove方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
let treeSet : TreeSet<string> = new TreeSet();
for(let i = 0; i < 10; i++) {
  treeSet.add("sparrow" + i);
}
for(let i = 0; i < 10; i++) {
  treeSet.remove("sparrow" + i);
}
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

返回一个迭代器，迭代器的每一项都是一个JavaScript对象，并返回该对象。

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
let treeSet : TreeSet<string> = new TreeSet();
treeSet.add("squirrel");
treeSet.add("sparrow");
let numbers = Array.from(treeSet.values())
// 使用方法一：
for (let item of numbers) {
  console.log("value:" + item);
}
// 使用方法二：
let iter = treeSet[Symbol.iterator]();
let temp: IteratorResult<string> = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
```
```ts
// 不建议在Symbol.iterator中使用set、remove方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
let treeSet : TreeSet<string> = new TreeSet();
for(let i = 0; i < 10; i++) {
  treeSet.add("sparrow" + i);
}
for(let i = 0; i < 10; i++) {
  treeSet.remove("sparrow" + i);
}
```