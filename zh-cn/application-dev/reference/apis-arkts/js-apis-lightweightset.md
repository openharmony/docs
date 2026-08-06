# @ohos.util.LightWeightSet (非线性容器LightWeightSet)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong; @lijin1039-->
<!--Designer: @Malzahar; @lijin1039-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

LightWeightSet可用于存储一系列值，存储元素中value唯一。

LightWeightSet依据泛型定义，采用轻量级结构，初始默认容量大小为8，每次扩容为原始容量的两倍。

集合中value值的查找依赖于hash算法，通过一个数组存储hash值，然后根据hash值映射到对应的存储位置获取value。

LightWeightSet和[HashSet](js-apis-hashset.md)都是用于存储元素的集合类型，但LightWeightSet的占用内存更小。

**推荐使用场景：** 当需要存储一组唯一元素、对数据进行去重、或需要基于hash快速查找元素时，推荐使用LightWeightSet。相比HashSet，LightWeightSet占用内存更小，适合内存敏感场景下的小规模数据存储与查找。

文档中使用了泛型，涉及以下泛型标记符：

T：Type，表示LightWeightSet中存储元素的类型。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 容器类使用静态语言实现，限制了存储位置和属性，不支持自定义属性和方法。

## 规格限制

当LightWeightSet存入的value为number类型且值大于INT32_MAX（2147483647）或小于INT32_MIN（-2147483648）时，针对LightWeightSet的操作，其结果可能与预期不一致。

这是因为，当value为number类型且值大于INT32_MAX或小于INT32_MIN时，存储结构会发生改变。

例如在以下示例中，针对value的计算，1758783600000大于INT32_MAX，此时会通过TaggedDouble存储；1758783600在INT32范围内，此时会通过TaggedInt存储。由于以上存储方式的差异，当对其进行hash算法即会计算出不同的hash值，从而导致映射结果不同，产生与预期不一致的现象。

```ts
let lightWeightSet = new LightWeightSet<number>();
let value = 1758783600000 / 1000;  // 1758783600000 > INT32_MAX
lightWeightSet.add(value);
console.info("result:", lightWeightSet.has(1758783600));  // result: false 
console.info("result:", lightWeightSet.has(value));  // result: true
```

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
// 创建LightWeightSet实例
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
// 判断容器是否为空
const lightWeightSet = new LightWeightSet<number>();
let result = lightWeightSet.isEmpty();
console.info("result:", result);  // result: true
```

### add

add(obj: T): boolean

向容器中添加数据。若添加的元素已存在于容器中，则不会重复添加，返回false。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| obj | T | 是 | 添加的成员数据。若添加的值已存在于容器中，则不会重复添加。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 成功添加元素返回true，要添加的元素已存在时返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The add method cannot be bound. |

**示例：**

```ts
// 向容器中添加元素
let lightWeightSet = new LightWeightSet<string>();
let result = lightWeightSet.add("squirrel");
console.info("result:", result);  // result: true
```


### addAll

addAll(set: LightWeightSet&lt;T&gt;): boolean

将另一个容器的所有元素添加到当前容器。若源容器中的元素已存在于当前容器中，则跳过该元素不重复添加。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| set | [LightWeightSet&lt;T&gt;](#lightweightset) | 是 | 提供添加元素的LightWeightSet。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 成功添加元素返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The addAll method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let set = new LightWeightSet<string>();
set.add("gull");
// 将另一个容器的所有元素添加到当前容器
lightWeightSet.addAll(set);
let result = lightWeightSet.has("gull");
console.info("result:", result);  // result: true
```


### hasAll

hasAll(set: LightWeightSet&lt;T&gt;): boolean

判断容器中是否包含指定set中的所有元素。当容器中存储的value为number类型且值大于INT32_MAX(2147483647)或小于INT32_MIN(-2147483648)时，判断结果可能与预期不一致，详见[规格限制](#规格限制)。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| set | LightWeightSet&lt;T&gt; | 是 | 用于判断当前容器是否包含其所有元素的目标集合。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | true表示容器中包含目标集合中的所有元素，false表示容器中不包含目标集合中的全部元素。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The hasAll method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
let set = new LightWeightSet<string>();
set.add("sparrow");
// 判断容器中是否包含指定set中的所有元素
let result = lightWeightSet.hasAll(set);
console.info("result:", result);  // result: true
```


### has

has(key: T): boolean

判断容器中是否包含指定元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | T | 是 | 指定查找的元素，用于判断容器中是否包含该元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | true表示容器中包含指定元素，false表示容器中不包含指定元素。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The has method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<number>();
lightWeightSet.add(123);
// 判断容器中是否包含指定元素
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
| minimumCapacity | number | 是 | 需要容纳的元素数量。若传入值小于当前元素个数，则不会变更容量。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200001 | The value of minimumCapacity is out of range. |
| 10200011 | The increaseCapacityTo method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
// 将容器扩容至指定容量
lightWeightSet.increaseCapacityTo(10);
```


### getIndexOf

getIndexOf(key: T): number

获取指定元素所对应的下标。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | T | 是 | 查找的指定key。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 在LightWeightSet中指定数据的下标。若LightWeightSet中没有要查找的元素，则返回一个负值。表示目标哈希值应该插入的位置，插入位置是从1开始计数的，负号表示这是一个插入位置而不是索引。 |

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
// 获取指定元素的下标
let result = lightWeightSet.getIndexOf("sparrow");
console.info("result:", result);  // result: 0
```


### remove

remove(key: T): T

删除并返回指定元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | T | 是 | 指定要删除的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回删除的元素。 |

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
// 删除并返回指定元素
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
| index | number | 是 | 指定下标，取值范围[0, length-1]，且需要小于等于INT32_MAX即2147483647。超出有效下标范围时返回false。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 成功删除元素返回true，指定下标不存在或超出范围时返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The removeAt method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
// 删除指定下标的元素
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
| index | number | 是 | 指定下标。需要小于等于INT32_MAX即2147483647。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回指定下标位置的元素值。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getValueAt method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
// 获取指定下标对应的元素
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
// 清除容器中的所有元素
lightWeightSet.clear();
let result = lightWeightSet.isEmpty();
console.info("result:", result);  // result: true
```


### toString

toString(): String

获取包含容器中所有元素的字符串。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| String | 返回包含容器中所有元素的字符串。 |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("squirrel");
lightWeightSet.add("sparrow");
// 获取包含容器中所有元素的字符串
let result = lightWeightSet.toString();
console.info("result:", result);  // result: sparrow,squirrel
```


### toArray

toArray(): Array&lt;T&gt;

获取包含此容器中所有元素的数组。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array&lt;T&gt; | 返回包含此容器中所有元素的数组。 |

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
// 获取包含此容器中所有对象的数组
let result = lightWeightSet.toArray();
console.info(result.toString());
// sparrow,squirrel
```


### values

values(): IterableIterator&lt;T&gt;

返回包含此集合中所有值的新迭代器对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;T&gt; | 返回包含LightWeightSet中所有value的迭代器对象。 |

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
// 获取包含所有元素的迭代器
let values = lightWeightSet.values();
for (let value of values) {
  console.info("value:", value);
}
// value: sparrow
// value: squirrel
```


### forEach

forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet&lt;T&gt;) => void, thisArg?: Object): void

通过回调函数来遍历LightWeightSet实例对象上的元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 回调函数，用于遍历LightWeightSet实例对象上的元素及其下标。 |
| thisArg | Object | 否 | callbackFn被调用时用作this值。当需要改变回调函数中的this指向时传入此参数，不需要改变this指向时可省略。不传入时默认值为当前实例对象。 |

callbackFn的参数说明：
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 否 | 当前遍历到的元素的值，默认值为首个元素的值。 |
| key | T | 否 | 当前遍历到的元素（与value相同），默认值为首个元素。 |
| set | [LightWeightSet&lt;T&gt;](#lightweightset) | 否 | 当前调用forEach方法的实例对象，默认值为当前实例对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The forEach method cannot be bound. |

**示例：**

```ts
let lightWeightSet = new LightWeightSet<string>();
lightWeightSet.add("sparrow");
lightWeightSet.add("gull");
// 通过回调函数遍历LightWeightSet中的元素
lightWeightSet.forEach((value: string, key: string) => {
  console.info("value:" + value, "key:" + key);
});
// value:gull key:gull
// value:sparrow key:sparrow
```

```ts
// 不建议在forEach函数中使用add、remove、removeAt方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
let lightWeightSet = new LightWeightSet<string>();
for (let i = 0; i < 10; i++) {
  lightWeightSet.add(i + "123");
}
for (let i = 0; i < 10; i++) {
  lightWeightSet.remove(i + "123");
}
```

### entries

entries(): IterableIterator<[T, T]>

返回包含此容器中所有元素对的新迭代器对象，每个元素对由相同值组成[value, value]。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator<[T, T]> | 返回包含LightWeightSet中所有键值对的迭代器对象，每一项为[key, value]结构的数组。 |

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
let entryIterator = lightWeightSet.entries();
for (let item of entryIterator) {
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
| IterableIterator&lt;T&gt; | 返回遍历LightWeightSet中所有元素的迭代器对象，每一项为容器中的元素值。 |

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
let symbolIterator = lightWeightSet[Symbol.iterator]();
let iteratorResult: IteratorResult<string> = symbolIterator.next();
while (!iteratorResult.done) {
  console.info("value:", iteratorResult.value);
  iteratorResult = symbolIterator.next();
}
// value: sparrow
// value: squirrel
```

```ts
// 不建议在Symbol.iterator中使用add、remove、removeAt方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
let lightWeightSet = new LightWeightSet<string>();
for (let i = 0; i < 10; i++) {
  lightWeightSet.add(i + "123");
}
for (let i = 0; i < 10; i++) {
  lightWeightSet.remove(i + "123");
}
```


### equal<sup>(deprecated)</sup>

equal(obj: Object): boolean

判断此容器与obj的构成元素是否相同。

> **说明：**
>
> 从API version 8开始支持，从API version 12开始废弃。无替代接口。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| obj | Object | 是 | 与当前容器比较元素构成是否相同的对象，可为仅含string或number的LightWeightSet或数组。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 当obj为仅含string或number的LightWeightSet或数组，且对象内部元素构成相同时，返回true；其他情况返回false。 |

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
let comparisonArray = ["sparrow", "squirrel"];
// 判断此容器与obj的构成元素是否相同
let result = lightWeightSet.equal(comparisonArray);
console.info("result:", result);  // result: true
```