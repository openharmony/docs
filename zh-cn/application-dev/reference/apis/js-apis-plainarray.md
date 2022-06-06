# 非线性容器PlainArray  

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

PlainArray可用于存储具有关联关系的key-value键值对集合，存储元素中key值唯一，key值类型为number类型，每个key对应一个value。

PlainArray依据泛型定义，采用轻量级结构，集合中key值的查找依赖于二分查找算法，然后映射到其他数组中的value值。

PlainArray和[LightWeightMap](js-apis-lightweightmap.md)都是用来存储键值对，且均采用轻量级结构，但PlainArray的key值类型只能为number类型。

**推荐使用场景：** 当需要存储key值为number类型的键值对时，可以使用PlainArray。

## 导入模块

```ts
import PlainArray from '@ohos.util.PlainArray';  
```



## PlainArray

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | PlainArray的元素个数。 |


### constructor

constructor()

PlainArray的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
let plainArray = new PlainArray();
```


### isEmpty

isEmpty(): boolean

判断该容器是否为空。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 为空返回true, 不为空返回false。 |

**示例：**

```ts
const plainArray = new PlainArray();
let result = plainArray.isEmpty();
```


### has

has(key: number): boolean

判断此容器中是否含有该指定key。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | number | 是 | 指定key。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 包含指定key返回true，否则返回false。 |

**示例：**

```ts
let plainArray = new PlainArray();
plainArray.has(1);
plainArray.add(1, "sddfhf");
let result1 = plainArray.has(1);
```


### get

get(key: number): T

获取指定key所对应的value。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | number | 是 | 查找的指定key。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回key映射的value值。 |

**示例：**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
let result = plainArray.get(1);
```


### getIndexOfKey

getIndexOfKey(key: number): number

查找指定key第一次出现的下标值，如果没有找到该key返回-1。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | number | 是 | 指定key。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回指定key第一次出现时的下标值，查找失败返回-1。 |

**示例：**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
let result = plainArray.getIndexOfKey("sdfs");
```


### getIndexOfValue

getIndexOfValue(value: T): number

查找指定value元素第一次出现的下标值，如果没有找到该value元素返回-1。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 指定value元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回指定value元素第一次出现时的下标值，查找失败返回-1。 |

**示例：**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
let result = plainArray.getIndexOfValue("sddfhf");
```


### getKeyAt

getKeyAt(index: number): number

查找指定下标的元素键值对中key值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定下标。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回该下标对应的元素键值对中key值，失败返回-1。 |

**示例：**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
let result = plainArray.getKeyAt(1);
```

### getValueAt

getValueAt(index: number): T

查找指定下标元素键值对中Value值，否则返回undefined。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | index | number | 是 | 指定下标。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | T | 返回该下标对应的元素键值对中key值，失败返回undefined。 |

**示例：**

  ```ts
  let plainArray = new PlainArray();
  plainArray.add(1, "sddfhf");
  plainArray.add(2, "sffdfhf");
  let result = plainArray.getKeyAt(1);
  ```

### clone

clone(): PlainArray&lt;T&gt;

克隆一个实例，并返回克隆后的实例。修改克隆后的实例并不会影响原实例。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| PlainArray&lt;T&gt; | 返回新的对象实例。 |

**示例：**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
let newPlainArray = plainArray.clone();
```


### add

add(key: number, value: T): void

向容器中添加一组数据。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | number | 是 | 添加成员数据的键名。 |
| value | T | 是 | 添加成员数据的值。 |

**示例：**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
```


### remove

remove(key: number): T

删除指定key对应元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | number | 是 | 指定key。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回删除元素的值。 |

**示例：**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
plainArray.remove(2);
let result = plainArray.remove(2);
```


### removeAt

removeAt(index: number): T

删除指定下标对应的元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定元素下标。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回删除的元素。 |

**示例：**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
plainArray.removeAt(1);
let result = plainArray.removeAt(1);
```


### removeRangeFrom

removeRangeFrom(index: number, size: number): number

删除一定范围内的元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 删除元素的起始下标。 |
| size | number | 是 | 期望删除元素个数。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 实际删除元素个数。 |

**示例：**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
let result = plainArray.removeRangeFrom(1, 3);
```


### setValueAt

setValueAt(index: number, value: T): void

替换容器中指定下标对应键值对中的键值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定替换数据下标。 |
| value | T | 是 | 替换键值对中的值。 |

**示例：**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
plainArray.setValueAt(1, 3546);
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
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
let result = plainArray.toString();
```


### clear

clear(): void

清除容器中的所有元素，并把length置为0。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
plainArray.clear();
```


### forEach

forEach(callbackfn: (value: T, index?: number, PlainArray?: PlainArray&lt;T&gt;) => void, thisArg?: Object): void

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
| value | T | 是 | 当前遍历到的元素键值对的值。 |
| index | number | 否 | 当前遍历到的元素键值对的键。 |
| PlainArray | PlainArray&lt;T&gt;| 否 | 当前调用forEach方法的实例对象。 |

**示例：**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");
plainArray.forEach((value, index) => {
  console.log("value:" + value, index);
});
```


### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[number, T]&gt;

返回一个迭代器，迭代器的每一项都是一个 JavaScript对象，并返回该对象。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[number, T]&gt; | 返回一个迭代器。 |

**示例：**

```ts
let plainArray = new PlainArray();
plainArray.add(1, "sddfhf");
plainArray.add(2, "sffdfhf");

// 使用方法一：
for (let item of plainArray) { 
  console.log("index:" + item[0]);
  console.log("value:" + item[1]);
}

// 使用方法二：
let iter = plainArray[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("index:" + temp[0]);
  console.log("value:" + temp[1]);
  temp = iter.next().value;
}
```