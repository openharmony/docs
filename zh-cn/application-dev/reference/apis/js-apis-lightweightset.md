# @ohos.util.LightWeightSet (非线性容器LightWeightSet)

LightWeightSet可用于存储一系列值的集合，存储元素中value值唯一。

LightWeightSet依据泛型定义，采用轻量级结构，初始默认容量大小为8，每次扩容大小为原始容量的两倍。

集合中value值的查找依赖于hash算法，通过一个数组存储hash值，然后映射到其他数组中的value值。

LightWeightSet和[HashSet](js-apis-hashset.md)都是用来存储键值的集合，LightWeightSet的占用内存更小。

**推荐使用场景：** 当需要存取某个集合或是对某个集合去重时，推荐使用占用内存更小的LightWeightSet。

文档中存在泛型的使用，涉及以下泛型标记符：<br>
- T：Type，类

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import LightWeightSet from '@ohos.util.LightWeightSet';  
```

## LightWeightSet

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | LightWeightSet的元素个数。 |


### constructor

constructor()

LightWeightSet的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200012 | The LightWeightSet's constructor cannot be directly invoked. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet();
```


### isEmpty

isEmpty(): boolean

判断该容器是否为空。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 为空返回true，不为空返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The isEmpty method cannot be bound. |

**示例：**

```ts
const lightWeightSet = new LightWeightSet();
let result = lightWeightSet.isEmpty();
```

### add

add(obj: T): boolean

向此容器中添加数据。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| obj | T | 是 | 添加的成员数据。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 成功添加元素返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The add method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet();
let result = lightWeightSet.add("squirrel");
```


### addAll

addAll(set: LightWeightSet&lt;T&gt;): boolean

将另一个容器中的所有元素组添加到当前容器中。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| set | LightWeightSet&lt;T&gt; | 是 | 提供添加元素的lightWeightSet。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The addAll method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let set = new LightWeightSet();
set.add("gull");
let result = lightWeightSet.addAll(set);
```


### hasAll

hasAll(set: LightWeightSet&lt;T&gt;): boolean

判断此容器中是否含有该指定set中的所有元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| set | LightWeightSet&lt;T&gt; | 是 | 比较对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 包含所有元素返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The hasAll method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let set = new LightWeightSet();
set.add("sparrow");
let result = lightWeightSet.hasAll(set);
```


### has

has(key: T): boolean

判断此容器中是否含有该指定key。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | T | 是 | 指定key |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 包含指定key返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The has method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add(123);
let result = lightWeightSet.has(123);
```


### equal

equal(obj: Object): boolean

判断此容器中是否含有该指定obj同类型的对象。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| obj | Object | 是 | 比较对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 构成类型相同返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The equal method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let obj = ["sparrow", "squirrel"];
let result = lightWeightSet.equal(obj);
```


### increaseCapacityTo

increaseCapacityTo(minimumCapacity: number): void

将当前容器扩容至可以容纳指定数量元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| minimumCapacity | number | 是 | 需要容纳数量。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The increaseCapacityTo method cannot be bound. |
| 10200001 | The value of minimumCapacity is out of range. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.increaseCapacityTo(10);
```


### getIndexOf

getIndexOf(key: T): number

获取指定key所对应的下标。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | T | 是 | 查找的指定key。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 在lightWeightSet中指定数据的下标。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getIndexOf method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.getIndexOf("sparrow");
```


### remove

remove(key: T): T

删除并返回指定key对应的元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | T | 是 | 指定key。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回删除元素的值。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The remove method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.remove("sparrow");
```


### removeAt

removeAt(index: number): boolean

删除指定下标所对应的元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定下标。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 确认是否成功删除元素 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The removeAt method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.removeAt(1);
```


### getValueAt

getValueAt(index: number): T

获取此容器中指定下标对应的元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定下标。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回指定下标对应的元素。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getValueAt method cannot be bound. |

**参数：**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.getValueAt(1);
```


### clear

clear(): void

清除容器中的所有元素，并把length置为0。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The clear method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
lightWeightSet.clear();
```


### toString

toString(): String

获取包含容器中所有键和值的字符串。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| String | 返回对应字符串。 |

**示例：**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.toString();
```


### toArray

toArray(): Array&lt;T&gt;

获取包含此容器中所有对象的数组。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array&lt;T&gt; | 返回对应数组。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The toArray method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.toArray();
```


### values

values(): IterableIterator&lt;T&gt;

返回包含此映射中包含的键值的新迭代器对象。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;T&gt; | 返回一个迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The values method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let iter = lightWeightSet.values();
let index = 0;
while(index < lightWeightSet.length) {
  console.log(JSON.stringify(iter.next().value));
  index++;
}
```


### forEach

forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet&lt;T&gt;) => void, thisArg?: Object): void

通过回调函数来遍历LightWeightSet实例对象上的元素以及元素对应的下标。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 回调函数。 |
| thisArg | Object | 否 | callbackfn被调用时用作this值，默认值为当前实例对象。 |

callbackfn的参数说明：
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 否 | 当前遍历到的元素键值对的值，默认值为首个键值对的值。 |
| key | T | 否 | 当前遍历到的元素键值对的键（和value相同），默认值为首个键值对的键。 |
| set | LightWeightSet&lt;T&gt; | 否 | 当前调用forEach方法的实例对象，默认值为当前实例对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The forEach method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("sparrow");
lightWeightSet.add("gull");
lightWeightSet.forEach((value, key) => {
    console.log("value:" + value, "key:" + key);
});
```


### entries

entries(): IterableIterator<[T, T]>

返回包含此映射中包含的键值对的新迭代器对象。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator<[T, T]> | 返回一个迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The entries method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let iter = lightWeightSet.entries();
let index = 0;
while(index < lightWeightSet.length) {
  console.log(JSON.stringify(iter.next().value));
  index++;
}
```


### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象,并返回该对象。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;T&gt; | 返回一个迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");

// 使用方法一：
for (let item of lightWeightSet) { 
  console.log("value:" + item);
}

// 使用方法二：
let iter = lightWeightSet[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value:" + temp);
  temp = iter.next().value;
}
```