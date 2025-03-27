# @ohos.util.HashSet (非线性容器HashSet)

HashSet基于[HashMap](js-apis-hashmap.md)实现。在HashSet中，只对value对象进行处理。

HashSet和[TreeSet](js-apis-treeset.md)相比，HashSet中的数据无序存放，即存放元素的顺序和取出的顺序不一致，而TreeSet是有序存放。它们集合中的元素都不允许重复，但HashSet允许放入null值，TreeSet不建议存放null值，可能会对排序结果产生影响。

**推荐使用场景：** 可以利用HashSet不重复的特性，当需要不重复的集合或需要去重某个集合的时候使用。

文档中存在泛型的使用，涉及以下泛型标记符：<br>
- T：Type，类

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { HashSet } from '@kit.ArkTS';
```

## HashSet

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | HashSet的元素个数。 |

**示例：**

```ts
let hashSet: HashSet<number> = new HashSet();
hashSet.add(1);
hashSet.add(2);
hashSet.add(3);
hashSet.add(4);
hashSet.add(5);
let res = hashSet.length;
```

### constructor

constructor()

HashSet的构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200012 | The HashSet's constructor cannot be directly invoked. |

**示例：**

```ts
let hashSet: HashSet<number> = new HashSet();
```


### isEmpty

isEmpty(): boolean

判断该HashSet是否为空。

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
const hashSet: HashSet<number> = new HashSet();
let result = hashSet.isEmpty();
```


### has

has(value: T): boolean

判断此HashSet中是否含有该指定元素。

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

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The has method cannot be bound. |

**示例：**

```ts
let hashSet: HashSet<string> = new HashSet();
hashSet.add("squirrel");
let result = hashSet.has("squirrel");
```


### add

add(value: T): boolean

向HashSet中添加数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 添加成员数据。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 成功增加元素返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The add method cannot be bound. |

**示例：**

```ts
let hashSet: HashSet<string> = new HashSet();
let result = hashSet.add("squirrel");
```


### remove

remove(value: T): boolean

删除指定的元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 指定删除的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 成功删除指定元素返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200011 | The remove method cannot be bound. |

**示例：**

```ts
let hashSet: HashSet<string> = new HashSet();
hashSet.add("squirrel");
hashSet.add("sparrow");
let result = hashSet.remove("sparrow");
```


### clear

clear(): void

清除HashSet中的所有元素，并把length置为0。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The clear method cannot be bound. |

**示例：**

```ts
let hashSet: HashSet<string> = new HashSet();
hashSet.add("squirrel");
hashSet.add("sparrow");
hashSet.clear();
```


### values

values(): IterableIterator&lt;T&gt;

返回包含此映射中包含的键值的新迭代器对象。

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
let hashSet: HashSet<string> = new HashSet();
hashSet.add("squirrel");
hashSet.add("sparrow");
let iter = hashSet.values();
let temp = iter.next();
while(!temp.done) {
  console.log("value:" + temp.value);
  temp = iter.next();
}
```


### forEach

forEach(callbackFn: (value?: T, key?: T, set?: HashSet&lt;T&gt;) => void, thisArg?: Object): void

通过回调函数来遍历实例对象上的元素以及元素对应的下标。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

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
| set | HashSet&lt;T&gt; | 否 | 当前调用forEach方法的实例对象，默认值为当前实例对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The forEach method cannot be bound. |

**示例：**

```ts
let hashSet: HashSet<string> = new HashSet();
hashSet.add("sparrow");
hashSet.add("squirrel");
hashSet.forEach((value?: string, key?: string): void => {
  console.log("value:" + value, "key:" + key);
});
```
```ts
// 不建议在forEach中使用set、remove方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
let hashSet : HashSet<string> = new HashSet();
for(let i = 0;i < 10; i++) {
  hashSet.add("sparrow" + i);
}
for(let i = 0;i < 10; i++) {
  hashSet.remove("sparrow" + i);
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
let hashSet: HashSet<string> = new HashSet();
hashSet.add("squirrel");
hashSet.add("sparrow");
let iter = hashSet.entries();
let temp: IteratorResult<[string, string]> = iter.next();
while(!temp.done) {
  console.log("key:" + temp.value[0]);
  console.log("value:" + temp.value[1]);
  temp = iter.next();
}
```
```ts
// 不建议在entries中使用set、remove方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
let hashSet : HashSet<string> = new HashSet();
for(let i = 0;i < 10; i++) {
  hashSet.add("sparrow" + i);
}
for(let i = 0;i < 10; i++) {
  hashSet.remove("sparrow" + i);
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
let hashSet: HashSet<string> = new HashSet();
hashSet.add("squirrel");
hashSet.add("sparrow");

// 使用方法一：
let val: Array<string> = Array.from(hashSet.values())
for (let item of val) {
  console.log("value: " + item);
}

// 使用方法二：
let iter = hashSet[Symbol.iterator]();
let temp: IteratorResult<string> = iter.next();
while(!temp.done) {
  console.log("value: " + temp.value);
  temp = iter.next();
}
```
```ts
// 不建议在Symbol.iterator中使用set、remove方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
let hashSet : HashSet<string> = new HashSet();
for(let i = 0;i < 10;i++) {
  hashSet.add("sparrow" + i);
}
for(let i = 0;i < 10;i++) {
  hashSet.remove("sparrow" + i);
}
```