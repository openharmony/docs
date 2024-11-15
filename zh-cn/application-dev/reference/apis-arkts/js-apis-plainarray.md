# @ohos.util.PlainArray (非线性容器PlainArray)  

PlainArray可用于存储具有关联关系的key-value键值对集合，存储元素中key值唯一，key值类型为number类型，每个key对应一个value。

PlainArray依据泛型定义，采用轻量级结构，集合中key值的查找依赖于二分查找算法，然后映射到其他数组中的value值。

PlainArray和[LightWeightMap](js-apis-lightweightmap.md)都是用来存储键值对，且均采用轻量级结构，但PlainArray的key值类型只能为number类型。

**推荐使用场景：** 当需要存储key值为number类型的键值对时，可以使用PlainArray。

文档中存在泛型的使用，涉及以下泛型标记符：<br>
- T：Type，类

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { PlainArray } from '@kit.ArkTS';  
```


## PlainArray

### 属性

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | PlainArray的元素个数。 |


### constructor

constructor()

PlainArray的构造函数。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200012 | The PlainArray's constructor cannot be directly invoked. |

**示例：**

```ts
let plainArray: PlainArray<string> = new PlainArray();
```


### isEmpty

isEmpty(): boolean

判断该容器是否为空。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 为空返回true, 不为空返回false。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The isEmpty method cannot be bound. |

**示例：**

```ts
const plainArray: PlainArray<string> = new PlainArray();
let result = plainArray.isEmpty();
```


### has

has(key: number): boolean

判断此容器中是否含有该指定key。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | number | 是 | 指定key。需要小于等于int32_max即2147483647。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 包含指定key返回true，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The has method cannot be bound. |

**示例：**

```ts
let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, "squirrel");
let result = plainArray.has(1);
```


### get

get(key: number): T

获取指定key所对应的value。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | number | 是 | 查找的指定key。需要小于等于int32_max即2147483647。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回key映射的value值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The get method cannot be bound. |

**示例：**

```ts
let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.get(1);
```


### getIndexOfKey

getIndexOfKey(key: number): number

查找指定key对应的下标值，如果没有找到该key返回-1。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | number | 是 | 指定key。需要小于等于int32_max即2147483647。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回指定key对应的下标值，查找失败返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The getIndexOfKey method cannot be bound. |

**示例：**

```ts
let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.getIndexOfKey(2);
```


### getIndexOfValue

getIndexOfValue(value: T): number

查找指定value元素第一次出现的下标值，如果没有找到该value元素返回-1。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 指定value元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回指定value元素第一次出现时的下标值，查找失败返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The getIndexOfValue method cannot be bound. |

**示例：**

```ts
let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.getIndexOfValue("squirrel");
```


### getKeyAt

getKeyAt(index: number): number

查找指定下标元素键值对中的key值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定下标。需要小于等于int32_max即2147483647。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回该下标元素键值对中的key值，失败返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The getKeyAt method cannot be bound. |

**示例：**

```ts
let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.getKeyAt(1);
```

### getValueAt

getValueAt(index: number): T

查找指定下标元素键值对中的Value值，失败返回undefined。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | index | number | 是 | 指定下标。需要小于等于int32_max即2147483647。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | T | 返回该下标元素键值对中的value值，失败返回undefined。 |

  **错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of index is out of range. |
| 10200011 | The getValueAt method cannot be bound. |

**示例：**

```ts
let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.getValueAt(1);
```

### clone

clone(): PlainArray&lt;T&gt;

克隆一个实例，并返回克隆后的实例。修改克隆后的实例并不会影响原实例。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| PlainArray&lt;T&gt; | 返回新的对象实例。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The clone method cannot be bound. |

**示例：**

```ts
let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let newPlainArray = plainArray.clone();
```


### add

add(key: number, value: T): void

向容器中添加一组数据。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | number | 是 | 添加成员数据的键名。需要小于等于int32_max即2147483647。 |
| value | T | 是 | 添加成员数据的值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The add method cannot be bound. |

**示例：**

```ts
let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, "squirrel");
```


### remove

remove(key: number): T

删除指定key对应的键值对。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | number | 是 | 指定key。需要小于等于int32_max即2147483647。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回所删除的键值对中的Value值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The remove method cannot be bound. |

**示例：**

```ts
let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.remove(2);
```


### removeAt

removeAt(index: number): T

删除指定下标对应的元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定元素下标。需要小于等于int32_max即2147483647。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回删除的元素。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The removeAt method cannot be bound. |

**示例：**

```ts
let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.removeAt(1);
```


### removeRangeFrom

removeRangeFrom(index: number, size: number): number

删除一定范围内的元素。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 删除元素的起始下标。需要小于等于int32_max即2147483647。 |
| size | number | 是 | 期望删除元素个数。需要小于等于int32_max即2147483647。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 实际删除元素个数。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of index is out of range. |
| 10200011 | The removeRangeFrom method cannot be bound. |

**示例：**

```ts
let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.removeRangeFrom(1, 3);
```


### setValueAt

setValueAt(index: number, value: T): void

替换容器中指定下标对应键值对中的键值。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定替换数据下标。需要小于等于int32_max即2147483647。 |
| value | T | 是 | 替换键值对中的值。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200001 | The value of index is out of range. |
| 10200011 | The setValueAt method cannot be bound. |

**示例：**

```ts
let plainArray: PlainArray<string | number> = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
plainArray.setValueAt(1, 3546);
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

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The toString method cannot be bound. |

**示例：**

```ts
let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
let result = plainArray.toString();
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
let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
plainArray.clear();
```


### forEach

forEach(callbackFn: (value: T, index?: number, PlainArray?: PlainArray&lt;T&gt;) => void, thisArg?: Object): void

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
| value | T | 是 | 当前遍历到的元素。 |
| index | number | 否 | 当前遍历到的下标值，默认值为0。 |
| PlainArray | PlainArray&lt;T&gt;| 否 | 当前调用forEach方法的实例对象，默认值为当前实例对象。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |
| 10200011 | The forEach method cannot be bound. |

**示例：**

```ts
let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");
plainArray.forEach((value: string, index?: number) => {
  console.log("value:" + value, "index:" + index);
});
```
```ts
// 不建议在forEach中使用add、remove、removeAt方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
let plainArray: PlainArray<string> = new PlainArray();
for(let i = 0;i < 10;i++) {
  plainArray.add(i,"123");
}

for(let i = 0;i < 10;i++) {
  plainArray.remove(i);
}
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[number, T]&gt;

返回一个包含key-value键值对的迭代器对象，其中key是number类型。

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[number, T]&gt; | 返回一个迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**示例：**

```ts
let plainArray: PlainArray<string> = new PlainArray();
plainArray.add(1, "squirrel");
plainArray.add(2, "sparrow");

let iter = plainArray[Symbol.iterator]();
let temp: IteratorResult<Object[]> = iter.next();
while(!temp.done) {
  console.log("key:" + temp.value[0]);
  console.log("value:" + temp.value[1]);
  temp = iter.next();
}
```
```ts
// 不建议在Symbol.iterator中使用add、remove、removeAt方法，会导致死循环等不可预知的风险，可使用for循环来进行插入和删除。
let plainArray: PlainArray<string> = new PlainArray();
for(let i = 0;i < 10;i++) {
  plainArray.add(i,"123");
}

for(let i = 0;i < 10;i++) {
  plainArray.remove(i);
}
```