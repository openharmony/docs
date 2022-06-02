# 线性容器List 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

List底层通过单向链表实现，每个节点有一个指向后一个元素的引用。当需要查询元素时，必须从头遍历，插入、删除效率高，查询效率低。List允许元素为null。

List和[LinkedList](js-apis-linkedlist.md)相比，LinkedList是双向链表，可以快速地在头尾进行增删，而List是单向链表，无法双向操作。

**推荐使用场景：** 当需要频繁的插入删除时，推荐使用List高效操作。

## 导入模块

```ts
import List from '@ohos.util.List';  
```

## 系统能力

SystemCapability.Utils.Lang


## List


### 属性

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | List的元素个数。 |


### constructor

constructor()

List的构造函数。


**示例：**

```ts
let list = new List();
```


### add

add(element: T): boolean

在List尾部插入元素。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 添加进去的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 插入成功返回true，否则返回false。 |

**示例：**

```ts
let list = new List();
let result = list.add("a");
let result1 = list.add(1);
let b = [1, 2, 3];
list.add(b);
let c = {name : "lala", age : "13"};
let result3 = list.add(false);
```

### insert

insert(element: T, index: number): void

在长度范围内任意位置插入指定元素。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 插入元素。 |
| index | number | 是 | 插入的位置索引。 |

**示例：**

```ts
let list = new List();
list.insert("A", 0);
list.insert(0, 1);
list.insert(true, 2);
```

### has

has(element: T): boolean

判断此List中是否含有该指定元素。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 指定元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 包含指定元素返回true，否则返回false。 |

**示例：**

```ts
let list = new List();
let result = list.has("Ahfbrgrbgnutfodgorrogorg");
list.add("Ahfbrgrbgnutfodgorrogorg");
let result1 = list.has("Ahfbrgrbgnutfodgorrogorg");
```

### get

get(index: number): T

根据下标获取List中的元素。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 要查找的下标。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 根据下标查找到的元素。 |

**示例：**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(2);
list.add(1);
list.add(2);
list.add(4);
let result = list.get(2);
```

### getLastIndexOf

getLastIndexOf(element: T): number

查找指定元素最后一次出现的下标值，查找失败返回-1。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 指定元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 查找指定元素最后一次出现的下标值，查找失败返回-1。 |

**示例：**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(2);
list.add(1);
list.add(2);
list.add(4);
let result = list.getLastIndexOf(2);
```

### getIndexOf

getIndexOf(element: T): number

查找指定元素第一次出现的下标值，查找失败返回-1。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 指定元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回第一次找到指定元素的下标，没有找到返回-1。 |

**示例：**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(2);
list.add(1);
list.add(2);
list.add(4);
list.getIndexOf(2);
let result = list.getIndexOf(2);
```

### equal

equal(obj: Object): boolean

比较指定对象与此List是否相等。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| obj | Object | 是 | 用来比较的对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果对象与此列表相同回true，否则返回false。 |

**示例：**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(2);
let obj1 = new List();
obj1.add(2);
obj1.add(4);
obj1.add(5);
list.equal(obj1);
let obj2 = {name : "lala", age : "13"};
let result = list.equal(obj2);
```

### removeByIndex

removeByIndex(index: number): T

根据元素的下标值查找元素，返回元素后将其删除。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 指定元素的下标值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回删除的元素。 |

**示例：**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(2);
list.add(4);
let result = list.removeByIndex(2);
```

### remove

remove(element: T): boolean

删除查找到的第一个指定的元素。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 指定元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 删除成功返回true，否则返回false。 |

**示例：**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.remove(2);
```

### replaceAllElements

replaceAllElements(callbackfn: (value: T, index?: number, list?: List&lt;T&gt;) => T,
thisArg?: Object): void

用户操作List中的元素,用操作后的元素替换原元素并返回操作后的元素。

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
| list | List&lt;T&gt; | 否 | 当前调用replaceAllElements方法的实例对象。 |

**示例：**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
list.replaceAllElements((value, index) => {
  return value = 2 * value;
});
list.replaceAllElements((value, index) => {
  return value = value - 2;
});
```

### forEach

forEach(callbackfn: (value: T, index?: number, List?: List&lt;T&gt;) => void,
thisArg?: Object): void

通过回调函数来遍历List实例对象上的元素以及元素对应的下标。

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
| List | List&lt;T&gt; | 否 | 当前调用forEach方法的实例对象。 |

**示例：**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
list.forEach((value, index) => {
  console.log("value: " + value, index);
});

```

### sort

sort(comparator: (firstValue: T, secondValue: T) => number): void

对List中的元素进行一个排序操作。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| comparator | function | 是 | 回调函数。 |

comparator的参数说明：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| firstValue | T | 是 | 前一项元素。 |
| secondValue | T | 是 | 后一项元素。 |

**示例：**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
list.sort((a, b) => a - b);
list.sort((a, b) => b - a);
```

### getSubList

getSubList(fromIndex: number, toIndex: number): List&lt;T&gt;

根据下标截取List中的一段元素，并返回这一段List实例，包括起始值但不包括终止值。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| fromIndex | number | 是 | 起始下标。 |
| toIndex | number | 是 | 终止下标。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| List&lt;T&gt; | 返回List对象实例。 |

**示例：**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.subList(2, 4);
let result1 = list.subList(4, 3);
let result2 = list.subList(2, 6);
```

### clear

clear(): void

清除List中的所有元素，并把length置为0。

**示例：**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
list.clear();
```

### set

set(index: number, element: T): T

将此 List 中指定位置的元素替换为指定元素。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 查找的下标值。 |
| element | T | 是 | 用来替换的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回替换后的元素 |

**示例：**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
list.set(2, "b");

```

### convertToArray

convertToArray(): Array&lt;T&gt;

把当前List实例转换成数组，并返回转换后的数组。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array&lt;T&gt; | 返回转换后的数组。 |

**示例：**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.convertToArray();
```

### isEmpty

isEmpty(): boolean

判断该List是否为空。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 为空返回true，不为空返回false。 |

**示例：**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.isEmpty();
```

### getFirst

getFirst(): T

获取List实例中的第一个元素。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回实例的第一个元素。 |

**示例：**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.getFirst();
```

### getLast

getLast(): T

获取List实例中的最后一个元素。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回实例的最后一个元素。 |

**示例：**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);
let result = list.getLast();
```

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;


返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象，并返回该对象。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;T&gt; | 返回一个迭代器。 |

**示例：**

```ts
let list = new List();
list.add(2);
list.add(4);
list.add(5);
list.add(4);

// 使用方法一：
for (let item of list) { 
  console.log("value: " + item); 
}

// 使用方法二：
let iter = list[Symbol.iterator]();
let temp = iter.next().value;
while(temp != undefined) {
  console.log("value: " + temp);
  temp = iter.next().value;
}
```