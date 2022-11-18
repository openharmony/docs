# 线性容器ArrayList

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

ArrayList是一种线性数据结构，底层基于数组实现。ArrayList会根据实际需要动态调整容量，每次扩容增加50%。

ArrayList和[Vector](js-apis-vector.md)相似，都是基于数组实现。它们都可以动态调整容量，但Vector每次扩容增加1倍。

ArrayList和[LinkedList](js-apis-linkedlist.md)相比，ArrayList的随机访问效率更高。但由于ArrayList的增删操作会影响数组内其他元素的移动，LinkedList的增加和删除操作效率更高。

**推荐使用场景：** 当需要频繁读取集合中的元素时，推荐使用ArrayList。

文档中存在泛型的使用,涉及以下泛型标记符:<br>
- T: Type, 类

## 导入模块

```ts
import ArrayList from '@ohos.util.ArrayList';
```

## ArrayList

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | ArrayList的元素个数。 |


### constructor

constructor()

ArrayList的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200012 | The ArrayList's constructor cannot be directly invoked. |

**示例：**

```ts
let arrayList = new ArrayList();
try {
  let arrayList2 = ArrayList();
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```


### add

add(element: T): boolean

在ArrayList尾部插入元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 待插入的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 插入成功返回true，失败返回false。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The add method cannot be bound. |

**示例：**

  ```ts
  let arrayList = new ArrayList();
  let result = arrayList.add("a");
  let result1 = arrayList.add(1);
  let b = [1, 2, 3];
  let result2 = arrayList.add(b);
  let c = {name: "Dylon", age: "13"};
  let result3 = arrayList.add(c);
  let result4 = arrayList.add(false);
  try {
    arrayList.add.bind({}, "b")(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
  } catch(err) {
    console.log(`${err.code} - ${err.name} - ${err.message}`);
  }
  ```

### insert

insert(element: T, index: number): void

在长度范围内任意位置插入指定元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 被插入的元素。 |
| index | number | 是 | 被插入的位置索引。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The insert method cannot be bound. |
| 10200001 | The value of parameters are out of range. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.insert("A", 0);
arrayList.insert(0, 1);
arrayList.insert(true, 2);
try {
  arrayList.insert.bind({}, 1, 2)(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
try {
  let res = arrayList.insert(8, 11); // 测试越界异常
} catch (err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
try {
  let res = arrayList.insert("a", "b"); // 测试类型异常
} catch (err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### has

has(element: T): boolean

判断此ArrayList中是否含有该指定元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 指定元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回true表示包含指定元素，否则返回false。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The has method cannot be bound. |

**示例：**

```ts
let arrayList = new ArrayList();
let result = arrayList.has("squirrel");
arrayList.add("squirrel");
let result1 = arrayList.has("squirrel");
try {
  arrayList.has.bind({}, "squirrel")(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### getIndexOf

getIndexOf(element: T): number

返回指定元素第一次出现时的下标值，查找失败返回-1。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 指定元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回指定元素第一次出现时的下标值，查找失败返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The getIndexOf method cannot be bound. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(2);
arrayList.add(1);
arrayList.add(2);
arrayList.add(4);
let result = arrayList.getIndexOf(2);
try {
  arrayList.getIndexOf.bind({}, 2)(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### getLastIndexOf

getLastIndexOf(element: T): number

返回指定元素最后一次出现时的下标值，查找失败返回-1。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 指定元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回指定元素最后一次出现时的下标值，查找失败返回-1。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The getLastIndexOf method cannot be bound. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(2);
arrayList.add(1);
arrayList.add(2);
arrayList.add(4);
let result = arrayList.getLastIndexOf(2);
try {
  arrayList.getLastIndexOf.bind({}, 2)(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### removeByIndex

removeByIndex(index: number): T

根据元素的下标值查找元素，返回元素后将其删除。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定元素的下标值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回删除的元素。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The removeByIndex method cannot be bound. |
| 10200001 | The value of parameters are out of range. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(2);
arrayList.add(4);
let result = arrayList.removeByIndex(2);
try {
  arrayList.removeByIndex.bind({}, 2)(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
try {
  arrayList.removeByIndex("a"); // 测试类型异常
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
try {
  arrayList.removeByIndex(8); // 测试越界异常
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### remove

remove(element: T): boolean

删除查找到的第一个指定的元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 指定元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 删除成功返回true，失败返回false。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The remove method cannot be bound. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
let result = arrayList.remove(2);
try {
  arrayList.remove.bind({}, 2)(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### removeByRange

removeByRange(fromIndex: number, toIndex: number): void

从一段范围内删除元素，包括起始值但不包括终止值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| fromIndex | number | 是 | 起始下标。 |
| toIndex | number | 是 | 终止下标。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The removeByRange method cannot be bound. |
| 10200001 | The value of parameters are out of range. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
arrayList.removeByRange(2, 4);
try {
  arrayList.removeByRange.bind({}, 2, 4)(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
try {
  arrayList.removeByRange(8, 4); // 测试越界异常
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### replaceAllElements

replaceAllElements(callbackfn: (value: T, index?: number, arrlist?: ArrayList&lt;T&gt;) => T,
thisArg?: Object): void

用户操作ArrayList中的元素，用操作后的元素替换原元素并返回操作后的元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackfn | function | 是 | 回调函数。 |
| thisArg | Object | 否 | callbackfn被调用时用作this值。 |

callbackfn的参数说明：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 当前遍历到的元素。 |
| index | number | 否 | 当前遍历到的下标值。 |
| arrlist | ArrayList&lt;T&gt; | 否 | 当前调用replaceAllElements方法的实例对象。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The replaceAllElements method cannot be bound. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
arrayList.replaceAllElements((value: number, index: number)=> {
  return value = 2 * value;
});
arrayList.replaceAllElements((value: number, index: number) => {
  return value = value - 2;
});
try {
  arrayList.replaceAllElements.bind({}, (value: number, index: number)=> {
    return value = 2 * value;
  })(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### forEach

forEach(callbackfn: (value: T, index?: number, arrlist?: ArrayList&lt;T&gt;) => void,
thisArg?: Object): void

通过回调函数来遍历ArrayList实例对象上的元素以及元素对应的下标。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackfn | function | 是 | 回调函数。 |
| thisArg | Object | 否 | callbackfn被调用时用作this值。 |

callbackfn的参数说明：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 当前遍历到的元素。 |
| index | number | 否 | 当前遍历到的下标值。 |
| arrlist | ArrayList&lt;T&gt; | 否 | 当前调用forEach方法的实例对象。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The forEach method cannot be bound. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
arrayList.forEach((value, index) => {
  console.log(`value:${value}`, index);
});
try {
  arrayList.forEach.bind({}, (value, index) => {
    console.log(`value:${value}`, index);
  })(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### sort

sort(comparator?: (firstValue: T, secondValue: T) => number): void

对ArrayList中的元素排序。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| comparator | function | 否 | 回调函数。 |

comparator的参数说明：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| firstValue | T | 是 | 前一项元素。 |
| secondValue | T | 是 | 后一项元素。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The sort method cannot be bound. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
arrayList.sort((a: number, b: number) => a - b);
arrayList.sort((a: number, b: number) => b - a);
arrayList.sort();
try {
  arrayList.sort.bind({})(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### subArrayList

subArrayList(fromIndex: number, toIndex: number): ArrayList&lt;T&gt;

根据下标截取ArrayList中的一段元素，并返回这一段ArrayList实例，包括起始值但不包括终止值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| fromIndex | number | 是 | 起始下标。 |
| toIndex | number | 是 | 终止下标。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| ArrayList&lt;T&gt; | 返回ArrayList对象实例。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The subArrayList method cannot be bound. |
| 10200001 | The value of parameters are out of range. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
let result1 = arrayList.subArrayList(2, 4);
let result2 = arrayList.subArrayList(4, 3);
let result3 = arrayList.subArrayList(2, 6);
try {
  arrayList.subArrayList.bind({}, 2, 4)(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
try {
  arrayList.subArrayList(6, 4);
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### clear

clear(): void

清除ArrayList中的所有元素，并把length置为0。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The clear method cannot be bound. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
arrayList.clear();
try {
  arrayList.clear.bind({})(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### clone

clone(): ArrayList&lt;T&gt; 

克隆一个与ArrayList相同的实例，并返回克隆后的实例。修改克隆后的实例并不会影响原实例。

**系统能力：** SystemCapability.Utils.Lang


**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| ArrayList&lt;T&gt; | 返回ArrayList对象实例。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The clone method cannot be bound. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
let result = arrayList.clone();
try {
  arrayList.clone.bind({})(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### getCapacity

getCapacity(): number

获取当前实例的容量大小。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回arraylist的容量大小。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The getCapacity method cannot be bound. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
let result = arrayList.getCapacity();
try {
  arrayList.getCapacity.bind({})(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### convertToArray

convertToArray(): Array&lt;T&gt;

把当前ArrayList实例转换成数组，并返回转换后的数组。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array&lt;T&gt; | 返回数组类型。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The convertToArray method cannot be bound. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
let result = arrayList.convertToArray();
try {
  arrayList.convertToArray.bind({})(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### isEmpty

isEmpty(): boolean

判断该ArrayList是否为空。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 为空返回true，不为空返回false。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The isEmpty method cannot be bound. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
let result = arrayList.isEmpty();
try {
  arrayList.isEmpty.bind({})(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### increaseCapacityTo

increaseCapacityTo(newCapacity: number): void

如果传入的新容量大于或等于ArrayList中的元素个数，将容量变更为新容量。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| newCapacity | number | 是 | 新容量。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The increaseCapacityTo method cannot be bound. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
arrayList.increaseCapacityTo(2);
arrayList.increaseCapacityTo(8);
try {
  arrayList.increaseCapacityTo.bind({}, 5)(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### trimToCurrentLength

trimToCurrentLength(): void

把容量限制为当前的length大小。

**系统能力：** SystemCapability.Utils.Lang

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The trimToCurrentLength method cannot be bound. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);
arrayList.trimToCurrentLength();
try {
  arrayList.trimToCurrentLength.bind({})(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象，并返回该对象。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;T&gt; | 返回一个迭代器。 |

**错误码：**

以下错误码的详细介绍请参见[containers错误码](../errorcodes/errorcode-containers.md)。

| 错误码ID | 错误码信息 |
| -------- | -------- |
| 10200011 | The Symbol.iterator method cannot be bound. |

**示例：**

```ts
let arrayList = new ArrayList();
arrayList.add(2);
arrayList.add(4);
arrayList.add(5);
arrayList.add(4);

// 使用方法一：
for (let item of arrayList) { 
  console.log(`value:${item}`); 
} 

// 使用方法二：
let iter = arrayList[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log(`value:${temp}`);
  temp = iter.next().value;
}
try {
  arrayList[Symbol.iterator].bind({})(); // bind为JS标准内置对象Function的方法，用于改变this的指向，测试异常捕获
} catch(err) {
  console.log(`${err.code} - ${err.name} - ${err.message}`);
}
```