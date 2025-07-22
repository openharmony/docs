# @ohos.util.LightWeightSet (非线性容器LightWeightSet)

LightWeightSet可用于存储一系列值的集合，存储元素中value值唯一。

LightWeightSet依据泛型定义，采用轻量级结构，初始默认容量大小为8，每次扩容大小为原始容量的两倍。

集合中value值的查找依赖于hash算法，通过一个数组存储hash值，然后映射到其他数组中的value值。

LightWeightSet和[HashSet](js-apis-hashset.md)都是用来存储键值的集合，但LightWeightSet的占用内存更小。

**推荐使用场景：** 当需要存取某个集合或是对某个集合去重时，推荐使用占用内存更小的LightWeightSet。

文档中使用了泛型，涉及以下泛型标记符：
- T：Type，类

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { LightWeightSet } from '@kit.ArkTS';
```

## LightWeightSet

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | LightWeightSet的元素个数。 |


### constructor

constructor()

LightWeightSet的构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200012 | The LightWeightSet's constructor cannot be directly invoked. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<number | string>();
```

### isEmpty

isEmpty(): boolean

判断容器是否为空。

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
const lightWeightSet = new LightWeightSet<number>();
let result = lightWeightSet.isEmpty();
console.info("result:", result);  // result: true
```

### add

add(obj: T): boolean

向容器中添加数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The add method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
let result = lightWeightSet.add("squirrel");
console.info("result:", result);  // result: true
```


### addAll

addAll(set: LightWeightSet&lt;T&gt;): boolean

将另一个容器的所有元素组添加到当前容器。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| set | LightWeightSet&lt;T&gt; | 是 | 提供添加元素的LightWeightSet。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 成功添加元素返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The addAll method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let set = new LightWeightSet<string>();
set.add("gull");
lightWeightSet.addAll(set);
let result = lightWeightSet.has("gull");
console.info("result:", result);  // result: true
```


### hasAll

hasAll(set: LightWeightSet&lt;T&gt;): boolean

判断容器中是否包含指定set中的所有元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| set | LightWeightSet&lt;T&gt; | 是 | 比较对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 包含所有元素时返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The hasAll method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let set = new LightWeightSet<string>();
set.add("sparrow");
let result = lightWeightSet.hasAll(set);
console.info("result:", result);  // result: true
```


### has

has(key: T): boolean

判断容器中是否包含指定的key。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | T | 是 | 指定key |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 包含指定key时返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The has method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<number>();
lightWeightSet.add(123);
let result = lightWeightSet.has(123);
console.info("result:", result);  // result: true
```


### increaseCapacityTo

increaseCapacityTo(minimumCapacity: number): void

将当前LightWeightSet扩容至指定容量。如果传入的容量值大于或等于当前LightWeightSet中的元素个数，将容量变更为新容量，小于则不会变更。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| minimumCapacity | number | 是 | 需要容纳的元素数量。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200001 | The value of minimumCapacity is out of range. |
| 10200011 | The increaseCapacityTo method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.increaseCapacityTo(10);
```


### getIndexOf

getIndexOf(key: T): number

获取指定key所对应的下标。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | T | 是 | 查找的指定key。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 在lightWeightSet中指定数据的下标。若lightWeightSet中没有要查找的元素，则返回一个负值。表示目标哈希值应该插入的位置，插入位置是从1开始计数的，负号表示这是一个插入位置而不是索引。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getIndexOf method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.getIndexOf("sparrow");
console.info("result:", result);  // result: 0
```


### remove

remove(key: T): T

删除并返回指定key对应的元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The remove method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.remove("sparrow");
console.info("result:", result);  // result: sparrow
```


### removeAt

removeAt(index: number): boolean

删除指定下标所对应的元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定下标。需要小于等于int32_max即2147483647。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 确认是否成功删除元素，成功删除元素返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The removeAt method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.removeAt(1);
console.info("result:", result);  // result: true
```


### getValueAt

getValueAt(index: number): T

获取容器中指定下标对应的元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定下标。需要小于等于int32_max即2147483647。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回指定下标对应的元素。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The getValueAt method cannot be bound. |

**参数：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.getValueAt(1);
console.info("result:", result);  // result: squirrel
```


### clear

clear(): void

清除容器中的所有元素，并将length置为0。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The clear method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
lightWeightSet.clear();
let result = lightWeightSet.isEmpty();
console.info("result:", result);  // result: true
```


### toString

toString(): String

获取包含容器中所有键和值的字符串。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| String | 返回对应字符串。 |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.toString();
console.info("result:", result);  // result: sparrow,squirrel
```


### toArray

toArray(): Array&lt;T&gt;

获取包含此容器中所有对象的数组。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array&lt;T&gt; | 返回对应数组。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The toArray method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let result = lightWeightSet.toArray();
```


### values

values(): IterableIterator&lt;T&gt;

返回包含此映射中所有键值的新迭代器对象。

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
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let values = lightWeightSet.values();
for (let value of values) {
  console.info("value:", value);
}
// value: sparrow
// value: squirrel
```


### forEach

forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet&lt;T&gt;) => void, thisArg?: Object): void

通过回调函数来遍历LightWeightSet实例对象上的元素以及元素对应的下标。

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
| value | T | 否 | 当前遍历到的元素键值对的值，默认值为首个键值对的值。 |
| key | T | 否 | 当前遍历到的元素键值对的键（和value相同），默认值为首个键值对的键。 |
| set | LightWeightSet&lt;T&gt; | 否 | 当前调用forEach方法的实例对象，默认值为当前实例对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The forEach method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("sparrow");
lightWeightSet.add("gull");
lightWeightSet.forEach((value: string, key: string) => {
  console.info("value:" + value, "key:" + key);
});
// value:gull key:gull
// value:sparrow key:sparrow
```

```ts
// 不建议在forEach函数中使用add、remove、removeAt方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
let lightWeightSet = new LightWeightSet<string>();
for(let i = 0; i < 10; i++) {
  lightWeightSet.add(i + "123");
}
for(let i = 0; i < 10; i++) {
  lightWeightSet.remove(i + "123");
}
```

### entries

entries(): IterableIterator<[T, T]>

返回包含此映射中包含的键值对的新迭代器对象。

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
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let iter = lightWeightSet.entries();
for (let item of iter) {
  console.info("value:", item[1])
}
// value: sparrow
// value: squirrel
```

```ts
// 不建议在entries中使用add、remove、removeAt方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
let lightWeightSet = new LightWeightSet<string>();
for(let i = 0; i < 10; i++) {
  lightWeightSet.add(i + "123");
}
for(let i = 0; i < 10; i++) {
  lightWeightSet.remove(i + "123");
}
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

返回一个迭代器，迭代器的每一项都是一个JavaScript对象。

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
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");

// 使用方法一：
for (let value of lightWeightSet) {
  console.info("value:", value);
}
// value: sparrow
// value: squirrel

// 使用方法二：
let iter = lightWeightSet[Symbol.iterator]();
let temp: IteratorResult<string> = iter.next();
while(!temp.done) {
  console.info("value:", temp.value);
  temp = iter.next();
}
// value: sparrow
// value: squirrel
```

```ts
// 不建议在Symbol.iterator中使用add、remove、removeAt方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
let lightWeightSet = new LightWeightSet<string>();
for(let i = 0; i < 10; i++) {
  lightWeightSet.add(i + "123");
}
for(let i = 0; i < 10; i++) {
  lightWeightSet.remove(i + "123");
}
```


### equal<sup>(deprecated)</sup>

equal(obj: Object): boolean

判断此容器与obj的构成元素是否相同。

> **说明：**
>
> 此接口从API version 10开始支持，从API version 12开始废弃。无替代接口。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| obj | Object | 是 | 比较对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 当obj为仅含string或number的LightWeightSet或数组，且对象内部元素构成相同时，返回true；其它情况返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The equal method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let obj = ["sparrow", "squirrel"];
let result = lightWeightSet.equal(obj);
console.info("result:", result);  // result: true
```