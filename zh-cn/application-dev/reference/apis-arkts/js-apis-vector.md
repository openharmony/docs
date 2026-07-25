# @ohos.util.Vector (线性容器Vector)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong-->
<!--Designer: @Malzahar-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

Vector是一种线性数据结构，底层基于数组实现，解决了需要动态扩容、高效随机访问的数据存储问题。当Vector的内存用尽时，会自动分配更大的连续内存区，将原先的元素复制到新的内存区，并释放旧的内存区。使用Vector能够高效快速地访问元素，其2倍扩容策略减少了频繁的内存重分配，同时丰富的操作接口提供了更灵活的数据管理能力。

Vector和[ArrayList](js-apis-arraylist.md)相似，都是基于数组实现，但Vector提供了更多操作数组的接口。它们都可以动态调整容量，但Vector每次扩容增加1倍，ArrayList只扩容0.5倍。

**推荐使用场景：** 当需要频繁按索引随机访问元素且数据量较大时，推荐使用Vector来存取数据。

文档中存在泛型的使用，涉及以下泛型类型参数：<br>
- T：Type，类型

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> API version 9开始，该接口不再维护，推荐使用接口[ArrayList](js-apis-arraylist.md)。

## 导入模块

```ts
import { Vector } from '@kit.ArkTS';
```


## Vector

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| length | number | 是 | 否 | Vector的元素个数。 |


### constructor

constructor()

Vector的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
let vector : Vector<string | number | Array<number>> = new Vector();
```


### add

add(element: T): boolean

在Vector中尾部插入元素，插入成功后Vector的长度增加1。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 添加的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 插入成功返回true，失败返回false。 |

**示例：**

```ts
// 定义自定义类PersonInfo
class PersonInfo {
  name: string = ""
  age: string = ""
}
// 创建Vector实例
let vector : Vector<string | number | PersonInfo | Array<number>> = new Vector();
// 添加字符串元素
let result = vector.add("a");
// 添加数字元素
let result1 = vector.add(1);
let numArray = [1, 2, 3];
// 添加数组元素
let result2 = vector.add(numArray);
let personInfo: PersonInfo = {name : "Jack", age : "13"};
// 添加自定义类实例
let result3 = vector.add(personInfo);
```

### insert

insert(element: T, index: number): void

在长度范围内的指定位置插入元素，并将该位置后续元素向右移动。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 被插入的元素。 |
| index | number | 是 | 被插入的位置索引，取值范围为[0, length]。 |

**示例：**

```ts
// 创建Vector实例
let vector : Vector<string | number | Object | Array<number>> = new Vector();
// 在索引0处插入字符串"A"
vector.insert("A", 0);
// 在索引1处插入数字0
vector.insert(0, 1);
// 在索引2处插入布尔值true
vector.insert(true, 2);
```

### has

has(element: T): boolean

判断此Vector中是否含有该指定元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 指定的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 是否包含指定元素，true表示包含该元素，false表示不包含。 |

**示例：**

```ts
// 创建Vector实例
let vector : Vector<string> = new Vector();
// 在添加元素前判断是否包含"squirrel"，预期返回false
let result = vector.has("squirrel");
// 添加元素"squirrel"
vector.add("squirrel");
// 在添加元素后判断是否包含"squirrel"，预期返回true
let result1 = vector.has("squirrel");
```

### getIndexOf

getIndexOf(element: T): number

返回指定元素第一次出现时的下标值，查找失败返回-1。与[getLastIndexOf](#getlastindexof)的区别：getIndexOf返回元素首次出现的位置，getLastIndexOf返回元素末次出现的位置。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 指定的元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回指定元素第一次出现时的下标值，查找失败返回-1。 |

**示例：**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(2);
vector.add(1);
vector.add(2);
vector.add(4);
let result = vector.getIndexOf(2);
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

**示例：**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(2);
vector.add(1);
vector.add(2);
vector.add(4);
let result = vector.getLastIndexOf(2);
```

### removeByIndex

removeByIndex(index: number): T

根据下标值找到对应元素并删除，同时将该位置后续元素向左移动，返回被删除的元素。index取值范围为[0, length-1]。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 要删除元素的位置下标值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回被删除的元素。Vector为空时返回undefined，下标越界时抛出异常。 |

**示例：**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(2);
vector.add(4);
let result = vector.removeByIndex(2);
```

### remove

remove(element: T): boolean

删除查找到的第一个指定的元素，并将其后续元素向左移动。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 指定元素。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 删除成功返回true，删除失败返回false。 |

**示例：**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.remove(2);
```

### removeByRange

removeByRange(fromIndex: number, toIndex: number): void

从一段范围内删除元素，包括起始值但不包括终止值，删除后后续元素向左移动，Vector的长度相应减少。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| fromIndex | number | 是 | 起始下标，包含该下标对应的元素。 |
| toIndex | number | 是 | 终止下标，不包含该下标对应的元素。 |

**示例：**

```ts
// 创建Vector实例并添加元素
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
// 删除索引2到4之间的元素（包含起始索引2，不包含终止索引4）
vector.removeByRange(2,4);
```

### replaceAllElements

replaceAllElements(callbackFn: (value: T, index?: number, vector?: Vector&lt;T&gt;) => T, thisArg?: Object): void

通过回调函数操作Vector中的元素，用回调函数返回的元素替换原元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 回调函数，用于操作Vector中的元素，并用操作后的结果替换原元素。 |
| thisArg | Object | 否 | callbackFn被调用时用作this值，默认值为当前实例对象。 |

callbackFn的参数说明：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 当前遍历到的元素。 |
| index | number | 否 | 当前遍历到的下标值。 |
| vector | [Vector&lt;T&gt;](#vector) | 否 | 当前调用replaceAllElements方法的实例对象，默认值为当前实例对象。 |

**示例：**

```ts
// 创建Vector实例并添加元素
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
// 对Vector中的每个元素执行替换操作，回调函数返回替换后的元素
vector.replaceAllElements((value : number) : number => {
  // 用户操作逻辑根据实际场景进行添加。
  return value;
});
```

### forEach

forEach(callbackFn: (value: T, index?: number, vector?: Vector&lt;T&gt;) => void, thisArg?: Object): void

通过回调函数来遍历Vector实例对象上的元素以及元素对应的下标。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 回调函数，用于遍历Vector中的每个元素。 |
| thisArg | Object | 否 | callbackFn被调用时用作this值，默认值为当前实例对象。 |

callbackFn的参数说明：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | T | 是 | 当前遍历到的元素。 |
| index | number | 否 | 当前遍历到的下标值。 |
| vector | [Vector&lt;T&gt;](#vector) | 否 | 当前调用forEach方法的实例对象，默认值为当前实例对象。 |

**示例：**

```ts
// 创建Vector实例并添加元素
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
// 遍历Vector中的每个元素，打印元素值和下标
vector.forEach((value : number, index?: number) : void => {
  console.info("value:" + value, "index:" + index);
});
```

### sort

sort(comparator?: (firstValue: T, secondValue: T) => number): void

对Vector中的元素进行一个排序操作。排序后元素的索引位置会发生改变，排序前通过getIndexOf、getLastIndexOf等方法获取的索引值将不再有效，需重新查询索引。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| comparator | function | 否 | 回调函数，若不传入此参数，则按照默认排序规则对元素进行排序。 |

comparator的参数说明：

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| firstValue | T | 是 | 前一项元素。 |
| secondValue | T | 是 | 后一项元素。 |

**示例：**

```ts
// 创建Vector实例并添加元素
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
// 按升序排序
vector.sort((a: number, b: number) => a - b);
// 按降序排序
vector.sort((a: number, b: number) => b - a);
// 使用默认排序规则
vector.sort();
```

### subVector

subVector(fromIndex: number, toIndex: number): Vector&lt;T&gt;

根据下标截取Vector中的一段元素，并返回这一段Vector实例，包括起始值但不包括终止值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| fromIndex | number | 是 | 起始下标，取值范围：0 ≤ fromIndex < length。 |
| toIndex | number | 是 | 终止下标，取值范围：0 ≤ toIndex ≤ length，且toIndex应大于fromIndex。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Vector&lt;T&gt; | 返回包含从起始下标到终止下标（不包括终止下标）元素的Vector对象实例。 |

**示例：**

```ts
// 创建Vector实例并添加元素
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.add(6);
vector.add(8);
// 截取索引0到4之间的元素（包含起始索引0，不包含终止索引4，且toIndex大于fromIndex）
let result = vector.subVector(0,4);
// 截取索引2到4之间的元素（包含起始索引2，不包含终止索引4）
let result1 = vector.subVector(2,4);

```

### clear

clear(): void

清除Vector中的所有元素，并把length置为0。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.clear();
```

### clone

clone(): Vector&lt;T&gt;

克隆一个与Vector相同的实例，并返回克隆后的实例。修改克隆后的实例并不会影响原实例。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Vector&lt;T&gt; | 返回与原实例内容相同的克隆Vector对象实例，修改克隆实例不影响原实例。 |

**示例：**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.clone();
```

### getCapacity

getCapacity(): number

获取当前实例的容量大小。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回Vector的容量大小。 |

**示例：**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.getCapacity();
```

### convertToArray

convertToArray(): Array&lt;T&gt;

把当前Vector实例转换成数组，并返回转换后的数组。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Array&lt;T&gt; | 返回包含Vector中所有元素的数组。 |

**示例：**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.convertToArray();
```

### isEmpty

isEmpty(): boolean

判断该Vector是否为空。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 为空返回true，不为空返回false。 |

**示例：**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.isEmpty();
```

### increaseCapacityTo

increaseCapacityTo(newCapacity: number): void

如果传入的新容量大于或等于当前Vector实例的元素个数，将容量变更为新容量；如果传入的新容量小于当前Vector实例的元素个数，不做变更。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| newCapacity | number | 是 | 新容量，需大于或等于当前Vector中的元素个数。传入值小于元素个数时不生效。 |

**示例：**

```ts
// 创建Vector实例并添加元素
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
// 传入容量2小于元素个数4，不会变更容量
vector.increaseCapacityTo(2);
// 传入容量12大于元素个数4，容量变更为12
vector.increaseCapacityTo(12);
```

### trimToCurrentLength

trimToCurrentLength(): void

把容量限制为当前的length大小。适用于在完成元素添加后释放多余的内存空间，优化内存使用。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.trimToCurrentLength();
```

### toString

toString(): string

用","将Vector实例中的元素按顺序拼接成字符串。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回用","将Vector中的元素按顺序拼接成的字符串。 |

**示例：**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.toString();
```

### copyToArray

copyToArray(array: Array&lt;T&gt;): void

将Vector实例中的元素按索引对应关系复制到指定数组中对应位置。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| array | Array&lt;T&gt; | 是 | 接收复制元素的目标数组。 |

### getFirstElement

getFirstElement(): T

获取实例中的第一个元素。Vector为空时返回undefined。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回Vector实例中的第一个元素；若Vector为空，返回undefined。 |

**示例：**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.getFirstElement();
```

### getLastElement

getLastElement(): T

获取Vector实例中的最后一个元素。Vector为空时返回undefined。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| T | 返回Vector实例中的最后一个元素；若Vector为空，返回undefined。 |

**示例：**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.getLastElement();
```

### getLastIndexFrom

getLastIndexFrom(element: T, index: number): number

从指定索引向低索引方向搜索，返回该元素的下标索引。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 要查找的元素。 |
| index | number | 是 | 从指定索引开始搜索，取值范围[0, length-1]。超出范围时返回-1。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回该元素的下标，如果查找失败，则返回-1。 |

**示例：**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.getLastIndexFrom(4,3);
```

### getIndexFrom

getIndexFrom(element: T, index: number): number

从指定索引向高索引方向搜索，返回该元素的下标索引。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| element | T | 是 | 要查找的元素。 |
| index | number | 是 | 从指定索引向前搜索的起始位置，取值范围为[0, length-1]。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| number | 返回该元素的下标，如果查找失败，则返回 -1。 |

**示例：**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.getIndexFrom(4, 3);
```

### setLength

setLength(newSize: number): void

设置Vector实例的元素个数。若newSize大于当前元素个数则进行扩容，若newSize小于当前元素个数则截断删除超出部分的元素。newSize=0时清空所有元素，length置为0。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| newSize | number | 是 | 设置的新长度，取值原则：newSize ≥ 0。 |

**示例：**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
vector.setLength(8);
vector.setLength(2);
```

### get

get(index: number): T 

根据下标值获取Vector实例中的元素，index取值范围为[0, length-1]。Vector为空或下标越界时返回undefined。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

  | 参数名 | 类型 | 必填 | 说明 |
  | -------- | -------- | -------- | -------- |
  | index | number | 是 | 查找的下标值，取值范围：0 ≤ index < length。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | T | 返回获取到的元素。 |

**示例：**

```ts
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
let result = vector.get(2);
```

### set

set(index: number, element: T): T

将此Vector中指定位置的元素替换为指定元素。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| index | number | 是 | 查找的下标值，取值范围为[0, length-1]。 |
| element | T | 是 | 用来替换的元素。 |

**返回值：**

  | 类型 | 说明 |
  | -------- | -------- |
  | T | 返回被替换位置上的原元素。 |

### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;T&gt;

返回一个迭代器，用于遍历Vector中的元素。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**
| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;T&gt; | 返回一个迭代器，用于遍历Vector实例中的元素。 |

**示例：**

```ts
// 创建Vector实例并添加元素
let vector : Vector<number> = new Vector();
vector.add(2);
vector.add(4);
vector.add(5);
vector.add(4);
// 使用方法一：通过convertToArray将Vector转为数组后使用for-of遍历
let nums: Array<number> =  vector.convertToArray()
for (let item of nums) {
  console.info("value:" + item);
}

// 使用方法二：通过Symbol.iterator获取迭代器，使用next()逐个访问元素
let iter = vector[Symbol.iterator]();
let temp: IteratorResult<number> = iter.next().value;
while(temp != undefined) {
  console.info("value:" + temp);
  temp = iter.next().value;
}
```