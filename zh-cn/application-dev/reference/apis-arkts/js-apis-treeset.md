# @ohos.util.TreeSet (非线性容器TreeSet)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong; @lijin1039-->
<!--Designer: @Malzahar; @lijin1039-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

TreeSet基于[TreeMap](js-apis-treemap.md)实现，在TreeSet中，仅处理元素的值（value），不单独处理键（key）。TreeSet的每个元素在底层TreeMap中同时作为key和value存储，因此元素中value唯一且有序。关于TreeMap的详细实现机制，请参见[TreeMap](js-apis-treemap.md)。

TreeSet和[HashSet](js-apis-hashset.md)中的元素都不允许重复。HashSet中的数据无序存放，而TreeSet是有序存放。HashSet允许插入null值，但TreeSet不建议插入null值，可能会影响排序结果。

**推荐使用场景：** TreeSet适用于需要有序存储和遍历集合的场景，如：有序数据展示、排名与排序系统、需要获取排序相邻元素的场景或自动排序插入等。

文档中使用了泛型，涉及以下泛型标记符：

- T：Type，表示TreeSet中元素的类型。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 容器类使用静态语言实现，限制了存储位置和属性，不支持自定义属性和方法。


## 导入模块

```ts
import { TreeSet } from '@kit.ArkTS';
```

## TreeSet

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | TreeSet的元素个数。 |


### constructor

constructor(comparator?: (firstValue: T, secondValue: T) => boolean)

TreeSet的构造函数，支持通过比较函数对元素进行升序或降序排序。当插入自定义类型时，必须提供比较函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| comparator | function | 否 | 用户自定义的比较函数，可通过比较关系对元素排序。默认值为null，表示不提供比较函数。取值原则：比较函数返回值决定排序方向，返回firstValue < secondValue为升序排序，返回firstValue > secondValue为降序排序。|

comparator的参数说明：

| 参数名 | 类型 | 必填 | 说明 |
| ------| ---- | ----- | -- |
| firstValue | T | 是 | 比较函数中的第一个比较元素，与secondValue比较后决定排序方向。 |
| secondValue | T | 是 | 比较函数中的第二个比较元素，与firstValue比较后决定排序方向。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200012 | The TreeSet's constructor cannot be directly invoked. |

**示例：**

```ts
// 默认构造
let treeSet = new TreeSet<string | number | boolean | Object>();
```

```ts
// 使用comparator firstValue < secondValue，表示期望结果为升序排序。反之firstValue > secondValue，表示为降序排序。
let treeSet: TreeSet<string> = new TreeSet<string>((firstValue: string, secondValue: string): boolean => {
  return firstValue < secondValue;
});
treeSet.add('a');
treeSet.add('c');
treeSet.add('d');
treeSet.add('b');
for (let value of treeSet) {
  console.info('value:', value);
};
// value: a
// value: b
// value: c
// value: d
```

```ts
// 插入自定义类型时，必须提供比较函数。
class TestEntry {
  public id: number = 0;
}
let testEntrySet: TreeSet<TestEntry> = new TreeSet<TestEntry>((t1: TestEntry, t2: TestEntry): boolean => { return t1.id > t2.id; });
let firstEntry: TestEntry = {
  id: 0
};
let secondEntry: TestEntry = {
  id: 1
}
testEntrySet.add(firstEntry);
testEntrySet.add(secondEntry);
console.info('treeSet: ', testEntrySet.length);
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
let treeSet = new TreeSet<string>();
// 判断容器是否为空
let result = treeSet.isEmpty();
console.info('result:', result);  // result: true
```


### has

has(value: T): boolean

判断容器中是否包含指定元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 要判断是否存在于容器中的目标元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 包含指定元素返回true，不包含指定元素返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The has method cannot be bound. |

**示例：**

```ts
let treeSet = new TreeSet<number>();
treeSet.add(123);
// 判断容器中是否包含指定元素
let result = treeSet.has(123);
console.info('result:', result); // result: true
```

### getFirstValue

getFirstValue(): T

获取容器中排序第一的元素，为空时返回undefined。

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
let treeSet = new TreeSet<string>();
treeSet.add('squirrel');
treeSet.add('sparrow');
let result = treeSet.getFirstValue();
console.info('result:', result); // result: sparrow
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
let treeSet = new TreeSet<string>();
treeSet.add('squirrel');
treeSet.add('sparrow');
let result = treeSet.getLastValue();
console.info('result:', result); // result: squirrel
```


### add

add(value: T): boolean

向容器中添加指定元素。不建议插入null值，可能会影响排序结果；添加自定义类型元素时，需确保TreeSet在构造时已提供比较函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 向TreeSet中添加的值元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 成功添加新元素至容器返回true，当元素已存在时返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The add method cannot be bound. |

**示例：**

```ts
let treeSet = new TreeSet<string>();
let result = treeSet.add('squirrel');
console.info('result:', result); // result: true
```


### remove

remove(value: T): boolean

删除指定的元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 要从容器中删除的目标元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 成功删除元素返回true，指定元素不存在返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The remove method cannot be bound. |

**示例：**

```ts
let treeSet = new TreeSet<string>();
treeSet.add('squirrel');
treeSet.add('sparrow');
let result = treeSet.remove('sparrow');
console.info('result:', result); // result: true
```


### getLowerValue

getLowerValue(key: T): T

获取容器中比传入元素排序靠前一位的元素，为空时返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | T | 是 | 作为查找基准的元素值，用于定位排序中比该元素靠前一位的数据。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回排序中传入元素前一位的数据，为空时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getLowerValue method cannot be bound. |

**示例：**

```ts
let treeSet = new TreeSet<string>();
treeSet.add('squirrel');
treeSet.add('sparrow');
treeSet.add('gander');
let result = treeSet.getLowerValue('sparrow');
console.info('result:', result); // result: gander
```


### getHigherValue

getHigherValue(key: T): T

获取容器中比传入元素排序靠后一位的元素，为空时返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | T | 是 | 作为查找基准的元素，用于定位排序中比该元素靠后一位的数据。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回排序中传入元素后一位的数据。为空时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getHigherValue method cannot be bound. |

**示例：**

```ts
let treeSet = new TreeSet<string>();
treeSet.add('squirrel');
treeSet.add('sparrow');
treeSet.add('gander');
let result = treeSet.getHigherValue('sparrow');
console.info('result:', result); // result: squirrel
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
let treeSet = new TreeSet<string>();
treeSet.add('squirrel');
treeSet.add('sparrow');
let result = treeSet.popFirst();
console.info('result:', result); // result: sparrow
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
let treeSet = new TreeSet<string>();
treeSet.add('squirrel');
treeSet.add('sparrow');
let result = treeSet.popLast();
console.info('result:', result); // result: squirrel
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
let treeSet = new TreeSet<string>();
treeSet.add('squirrel');
treeSet.add('sparrow');
treeSet.clear();
let result = treeSet.isEmpty();
console.info('result:', result); // result: true
```


### values

values(): IterableIterator&lt;T&gt;

返回包含此容器中元素值的新迭代器对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;T&gt; | 返回包含TreeSet中所有元素的迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The values method cannot be bound. |

**示例：**

```ts
// 不建议在values中使用add、remove方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
let treeSet = new TreeSet<string>();
treeSet.add('squirrel');
treeSet.add('sparrow');
let values = treeSet.values();
for (let value of values) {
  console.info('value:', value);
}
// value: sparrow
// value: squirrel
```


### forEach

forEach(callbackFn: (value?: T, key?: T, set?: TreeSet&lt;T&gt;) => void, thisArg?: Object): void

通过回调函数来遍历实例对象上的元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 遍历实例对象中每个元素时调用的回调函数，开发者可在回调中对元素及其下标进行自定义处理。 |
| thisArg | Object | 否 | callbackFn被调用时用作this值。当需要在回调函数中使用特定的this上下文（如访问外部对象属性）时传入此参数。不传入时默认值为当前实例对象，回调函数中的this指向TreeSet实例本身。 |

callbackFn的参数说明：
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 否 | 当前遍历到的value元素，forEach调用回调时始终传入此参数。 |
| key | T | 否 | 当前遍历到的元素（在TreeSet中key与value相同，均为元素本身）。 |
| set | TreeSet&lt;T&gt; | 否 | 当前调用forEach方法的实例对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The forEach method cannot be bound. |

**示例：**

```ts
let treeSet = new TreeSet<string>();
treeSet.add('sparrow');
treeSet.add('gull');
// 通过forEach遍历TreeSet中的元素
treeSet.forEach((value: string, key: string): void => {
  console.info('value:' + value);
});
// value:gull
// value:sparrow
```
```ts
// 不建议在forEach中使用add、remove方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
let treeSet = new TreeSet<string>();
for (let i = 0; i < 10; i++) {
  treeSet.add('sparrow' + i);
}
for (let i = 0; i < 10; i++) {
  treeSet.remove('sparrow' + i);
}
```

### entries

entries(): IterableIterator<[T, T]>

返回包含此容器中元素的新迭代器对象，每个元素以[value, value]的形式返回。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator<[T, T]> | 返回包含TreeSet中所有元素键值对的迭代器对象，每个键值对中键与值相同，均为元素本身。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The entries method cannot be bound. |

**示例：**

```ts
let treeSet = new TreeSet<string>();
treeSet.add('squirrel');
treeSet.add('sparrow');
// 获取entries迭代器
let iterator = treeSet.entries();
// 遍历迭代器获取键值对
let iterResult: IteratorResult<Object[]> = iterator.next();
while (!iterResult.done) {
  console.info('TreeSet: ' + iterResult.value[1]);
  iterResult = iterator.next();
}
// TreeSet: sparrow
// TreeSet: squirrel
```

```ts
// 不建议在entries中使用add、remove方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
let treeSet = new TreeSet<string>();
for(let i = 0; i < 10; i++) {
  treeSet.add('sparrow' + i);
}
for(let i = 0; i < 10; i++) {
  treeSet.remove('sparrow' + i);
}
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

返回一个迭代器，迭代器的每一项为容器中的元素值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;T&gt; | 返回包含TreeSet中所有元素的迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**示例：**

```ts
let treeSet = new TreeSet<string>();
treeSet.add('squirrel');
treeSet.add('sparrow');
// 使用方法一：使用for...of语法遍历TreeSet
for (let item of treeSet) {
  console.info('value:' + item);
}
// value:sparrow
// value:squirrel

// 使用方法二：通过Symbol.iterator获取迭代器手动遍历
let iterator = treeSet[Symbol.iterator]();
let currentValue: IteratorResult<string> = iterator.next().value;
while (currentValue != undefined) {
  console.info('value:' + currentValue);
  currentValue = iterator.next().value;
}
// value:sparrow
// value:squirrel
```

```ts
// 不建议在Symbol.iterator中使用add、remove方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
let treeSet = new TreeSet<string>();
for (let i = 0; i < 10; i++) {
  treeSet.add('sparrow' + i);
}
for (let i = 0; i < 10; i++) {
  treeSet.remove('sparrow' + i);
}
```