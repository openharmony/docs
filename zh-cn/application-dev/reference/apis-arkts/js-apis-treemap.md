# @ohos.util.TreeMap (非线性容器TreeMap)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong; @lijin1039-->
<!--Designer: @Malzahar; @lijin1039-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

TreeMap可用于存储具有关联关系的key-value键值对集合，存储元素中key值唯一，每个key对应一个value。

TreeMap底层使用红黑树实现，可以利用二叉树特性查找键值对，查找、插入和删除操作的时间复杂度为O(log n)。key值有序存储，可以实现高效的有序遍历。

TreeMap和[HashMap](js-apis-hashmap.md)相比，HashMap依据键的hashCode存取数据，访问速度较快但不保证键的顺序；而TreeMap基于红黑树有序存取，访问效率较低，但支持有序遍历、范围查询和首末键及相邻键查找等有序操作。

**推荐使用场景：** 需要对键值对进行有序存储和访问的场景，例如范围查询、有序遍历和键邻近查找等。

文档使用了泛型，涉及以下泛型标记符：

- K：Key，键

- V：Value，值

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 容器类使用静态语言实现，限制了存储位置和属性，不支持自定义属性和方法。


## 导入模块

```ts
import { TreeMap } from '@kit.ArkTS';
```

## TreeMap

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | TreeMap的元素个数。 |


### constructor

constructor(comparator?:(firstValue: K, secondValue: K) => boolean)

TreeMap的构造函数，支持通过比较函数使元素按照自定义规则排序。当key为自定义类型时，必须提供比较函数，否则自定义类型的key无法正常排序和比较。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| comparator | function | 否 | 用户自定义的比较函数，可通过比较关系对元素进行排序。默认值为null，表示不提供比较函数。当key为自定义类型时，必须提供比较函数，否则可能导致插入或查找异常。 |

comparator的参数说明：

| 参数名 | 类型 | 必填 | 说明 |
| ------| ---- | ----- | -- |
| firstValue | K | 是 | 参与比较的前一项元素，作为排序判断的第一个比较对象。 |
| secondValue | K | 是 | 参与比较的后一项元素，作为排序判断的第二个比较对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200012 | The TreeMap's constructor cannot be directly invoked. |

**示例：**

```ts
// 默认构造
let treeMap = new TreeMap<number, number>();
```

```ts
//使用comparator firstValue < secondValue，表示期望结果为升序排序。反之firstValue > secondValue，表示为降序排序。
let treeMap: TreeMap<string, string> = new TreeMap<string, string>((firstValue: string, secondValue: string): boolean => {
  return firstValue > secondValue;
});
treeMap.set('aa', '3');
treeMap.set('dd', '1');
treeMap.set('cc', '2');
treeMap.set('bb', '4');
for (let item of treeMap) {
  console.info('key: ' + item[0], 'value: ' + item[1]);
};
// 输出结果：
// key: dd value: 1
// key: cc value: 2
// key: bb value: 4
// key: aa value: 3
```

```ts
// 当插入自定义类型时，则必须要提供比较函数。
class TestEntry {
  public id: number = 0;
}

let testEntryMap: TreeMap<TestEntry, string> = new TreeMap<TestEntry, string>((t1: TestEntry, t2: TestEntry): boolean => {
  return t1.id < t2.id;
});
let entry1: TestEntry = {
  id: 0
};
let entry2: TestEntry = {
  id: 1
}
testEntryMap.set(entry1, '0');
testEntryMap.set(entry2, '1');
console.info('length:', testEntryMap.length); // length: 2
```


### isEmpty

isEmpty(): boolean

判断容器是否为空。

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
let treeMap = new TreeMap<number, number>();
// 判断容器是否为空
let result = treeMap.isEmpty();
console.info('result:', result);  // result: true
```


### hasKey

hasKey(key: K): boolean

判断容器中是否包含指定key。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 需要判断是否存在于容器中的键。 |

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
let treeMap = new TreeMap<string, number>();
// 向容器中添加数据
treeMap.set('squirrel', 123);
// 判断容器中是否包含指定key
let result = treeMap.hasKey('squirrel');
console.info('result:', result);  // result: true
```


### hasValue

hasValue(value: V): boolean

判断容器中是否包含指定value。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | V | 是 | 需要判断是否存在于容器中的值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 包含指定value返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The hasValue method cannot be bound. |

**示例：**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set('squirrel', 123);
// 判断容器中是否包含指定value
let result = treeMap.hasValue(123);
console.info('result:', result);  // result: true
```


### get

get(key: K): V

获取指定key所对应的value，若指定key不存在则返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 指定需要获取对应value的key。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| V | 返回key映射的value值，指定key不存在时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The get method cannot be bound. |

**示例：**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set('squirrel', 123);
treeMap.set('sparrow', 356);
// 获取指定key对应的value
let result = treeMap.get('sparrow');
console.info('result:', result); // result: 356
```


### getFirstKey

getFirstKey(): K

获取容器中排序第一的key，若容器为空则返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| K | 返回排序第一的key，容器为空时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getFirstKey method cannot be bound. |

**示例：**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set('squirrel', 123);
treeMap.set('sparrow', 356);
// 获取容器中排序第一的key
let result = treeMap.getFirstKey();
console.info('result:', result); // result: sparrow
```


### getLastKey

getLastKey(): K

获取容器中排序最后的key，若容器为空则返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| K | 返回排序最后的key，容器为空时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getLastKey method cannot be bound. |

**示例：**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set('squirrel', 123);
treeMap.set('sparrow', 356);
// 获取容器中排序最后的key
let result = treeMap.getLastKey();
console.info('result:', result); // result: squirrel
```


### setAll

setAll(map: TreeMap<K, V>): void

将一个TreeMap中的所有元素添加到另一个TreeMap中。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| map | TreeMap<K, V> | 是 | 将参数map中的所有元素添加到调用setAll方法的TreeMap对象中。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The setAll method cannot be bound. |

**示例：**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set('squirrel', 123);
treeMap.set('sparrow', 356);
let map: TreeMap<string, number> = new TreeMap();
map.set('demo', 12);
map.setAll(treeMap); // 将treeMap中的所有元素添加到map中
map.forEach((value?: number, key?: string) : void => {
  console.info('value: ' + value, 'key: ' + key); 
});
// 输出结果:
// value: 12 key: demo
// value: 356 key: sparrow
// value: 123 key: squirrel
```


### set

set(key: K, value: V): Object

向容器中添加一组键值对数据，若key已存在则更新对应value值，若key不存在则新增键值对。

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
| Object | 返回添加后的TreeMap。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The set method cannot be bound. |

**示例：**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set('squirrel', 123);
console.info('squirrel:', treeMap.get('squirrel')); // squirrel: 123
```


### remove

remove(key: K): V

删除指定key对应的元素并返回其value值，若指定key不存在则返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 指定需要删除元素对应的key。 |

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
let treeMap = new TreeMap<string, number>();
treeMap.set('squirrel', 123);
treeMap.set('sparrow', 356);
let result = treeMap.remove('sparrow'); // 删除数据
console.info('result = ' + result); // result = 356
```


### getLowerKey

getLowerKey(key: K): K

获取容器中小于对比key值的最大键，如果不存在小于对比key值的键，则返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 对比的key值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| K | 返回小于指定key的最大键，不存在时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getLowerKey method cannot be bound. |

**示例：**

```ts
let treeMap = new TreeMap<number, string>();
treeMap.set(1, 'one');
treeMap.set(2, 'two');
treeMap.set(3, 'three');
treeMap.set(4, 'four');
// 获取小于对比key值3的最大键
let result = treeMap.getLowerKey(3);
console.info('result:', result); // result: 2
```


### getHigherKey

getHigherKey(key: K): K

获取容器中大于指定key的最小key，如果不存在大于指定key的key，则返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 对比的key值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| K | 返回排序中位于指定key后一位的键，不存在时返回undefined。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getHigherKey method cannot be bound. |

**示例：**

```ts
let treeMap = new TreeMap<number, string>();
treeMap.set(1, 'one');
treeMap.set(2, 'two');
treeMap.set(3, 'three');
treeMap.set(4, 'four');
// 获取大于对比key值3的最小键
let result = treeMap.getHigherKey(3);
console.info('result:', result); // result: 4
```

### replace

replace(key: K, newValue: V): boolean

对容器中指定key对应的value进行替换，若key存在则替换成功并返回true，若key不存在则不做修改并返回false。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | K | 是 | 指定需要替换value对应的key。 |
| newValue | V | 是 | 替换的新值，将覆盖指定key对应的原有value。 |

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
let treeMap = new TreeMap<string, number>();
treeMap.set('sparrow', 123);
// 替换指定key对应的value
treeMap.replace('sparrow', 357);
console.info('sparrow:', treeMap.get('sparrow')); // sparrow: 357
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
let treeMap = new TreeMap<string, number>();
treeMap.set('squirrel', 123);
treeMap.set('sparrow', 356);
// 清除容器中的所有元素
treeMap.clear();
let result = treeMap.isEmpty();
console.info('result:', result); // result: true
```


### keys

keys(): IterableIterator&lt;K&gt;

返回包含此映射中所有键的新迭代器对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;K&gt; | 返回包含此映射中所有键的迭代器对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The keys method cannot be bound. |

**示例：**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set('squirrel', 123);
treeMap.set('sparrow', 356);
// 获取包含所有键的迭代器
let keys = treeMap.keys();
for (let key of keys) {
  console.info('key:', key);
}
// 输出结果：
// key: sparrow
// key: squirrel
```


### values

values(): IterableIterator&lt;V&gt;

返回包含此映射中所有值的新迭代器对象。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;V&gt; | 返回包含此映射中所有值的迭代器对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The values method cannot be bound. |

**示例：**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set('squirrel', 123);
treeMap.set('sparrow', 356);
// 获取包含所有值的迭代器
let values = treeMap.values();
for (let value of values) {
  console.info('value:', value);
}
// value: 356
// value: 123
```


### forEach

forEach(callbackFn: (value?: V, key?: K, map?: TreeMap<K, V>) => void, thisArg?: Object): void

通过回调函数来遍历实例对象上的元素及其键。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 回调函数，用于遍历实例对象中的每个键值对并在回调中执行自定义操作。 |
| thisArg | Object | 否 | callbackFn被调用时用作this值，默认值为undefined。 |

callbackFn的参数说明：
| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | V | 否 | 当前遍历到的元素键值对的值。 |
| key | K | 否 | 当前遍历到的元素键值对的键。 |
| map | TreeMap<K, V> | 否 | 当前调用forEach方法的实例对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The forEach method cannot be bound. |

**示例：**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set('sparrow', 123);
treeMap.set('gull', 357);
// 通过回调函数遍历TreeMap中的所有元素
treeMap.forEach((value: number, key: string): void => {
  console.info('value: ' + value, 'key: ' + key);
});
// 输出结果：
// value: 357 key: gull
// value: 123 key: sparrow
```

```ts
 // 不建议在forEach中使用set、remove方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
 let treeMap = new TreeMap<string, number>();
 for (let i = 0; i < 10; i++) {
   treeMap.set('sparrow' + i, 123);
 }
 for (let i = 0; i < 10; i++) {
   treeMap.remove('sparrow' + i);
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
| IterableIterator<[K, V]> | 返回包含此映射中所有键值对的迭代器对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The entries method cannot be bound. |

**示例：**

```ts
let treeMap = new TreeMap<string, number>();
treeMap.set('squirrel', 123);
treeMap.set('sparrow', 356);
// 获取键值对迭代器
let entriesIterator = treeMap.entries();
// 通过迭代器遍历所有键值对
let nextResult: IteratorResult<Object[]> = entriesIterator.next();
while (!nextResult.done) {
  console.info('TreeMap:', nextResult.value);
  nextResult = entriesIterator.next();
}
// 输出结果：
// TreeMap: sparrow,356
// TreeMap: squirrel,123
```

```ts
 // 不建议在entries中使用set、remove方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
 let treeMap = new TreeMap<string, number>();
 for (let i = 0; i < 10; i++) {
   treeMap.set('sparrow' + i, 123);
 }
 for (let i = 0;i < 10; i++) {
   treeMap.remove('sparrow' + i);
 }
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[K, V]&gt;

返回一个迭代器，迭代器的每一项是一个包含键和值的[K, V]数组。

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
let treeMap = new TreeMap<string, number>();
treeMap.set('squirrel', 123);
treeMap.set('sparrow', 356);

// 使用方法一：
for (let item of treeMap) {
  console.info('TreeMap:', item[0], item[1]);
}
// 输出结果：
// TreeMap: sparrow,356
// TreeMap: squirrel,123

// 使用方法二：
let iter = treeMap[Symbol.iterator]();
let nextResult: IteratorResult<Object[]> = iter.next();
while (!nextResult.done) {
  console.info('key:', nextResult.value[0]);
  console.info('value:', nextResult.value[1]);
  nextResult = iter.next();
}
// 输出结果：
// key: sparrow
// value: 356
// key: squirrel
// value: 123
```

```ts
 // 不建议在Symbol.iterator中使用set、remove方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
 let treeMap = new TreeMap<string, number>();
 for (let i = 0; i < 10; i++) {
   treeMap.set('sparrow' + i, 123);
 }
 for (let i = 0;i < 10; i++) {
   treeMap.remove('sparrow' + i);
 }
```