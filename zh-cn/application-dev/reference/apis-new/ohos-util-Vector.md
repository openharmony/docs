# @ohos.util.Vector    
Vector是一种线性数据结构，底层基于数组实现。当Vector的内存用尽时，会自动分配更大的连续内存区，将原先的元素复制到新的内存区，并释放旧的内存区。使用Vector能够高效快速地访问元素。  
  
Vector和[ArrayList](js-apis-arraylist.md)相似，都是基于数组实现，但Vector提供了更多操作数组的接口。它们都可以动态调整容量，但Vector每次扩容增加1倍，ArrayList只扩容0.5倍。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import Vector from '@ohos.util.Vector'    
```  
    
## Vector<sup>(deprecated)</sup>    
从API version 8 开始支持，从API version 9 开始废弃。建议使用ohos.util.ArrayList替代。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| length<sup>(deprecated)</sup> | number | false | true | 从API version 8 开始支持，从API version 9 开始废弃。<br> Vector的元素个数。 |  
    
### add<sup>(deprecated)</sup>    
在Vector中尾部插入元素。  
 **调用形式：**     
- add(element: T): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element<sup>(deprecated)</sup> | T | true | 添加进去的元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 插入成功返回true,失败返回false。 |  
    
 **示例代码：**   
```ts    
class C1 {  
  name: string = ""  
  age: string = ""  
}  
let vector : Vector<string | number | C1 | Array<number>> = new Vector();  
let result = vector.add("a");  
let result1 = vector.add(1);  
let b = [1, 2, 3];  
let result2 = vector.add(b);  
let c: C1 = {name : "Dylon", age : "13"};  
let result3 = vector.add(c);  
    
```    
  
    
### insert<sup>(deprecated)</sup>    
在长度范围内任意插入指定元素。  
 **调用形式：**     
- insert(element: T, index: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element<sup>(deprecated)</sup> | T | true |  被插入的元素。 |  
| index<sup>(deprecated)</sup> | number | true | 被插入的位置索引。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<string | number | Object | Array<number>> = new Vector();vector.insert("A", 0);vector.insert(0, 1);vector.insert(true, 2);    
```    
  
    
### has<sup>(deprecated)</sup>    
判断此Vector中是否含有该指定元素。  
 **调用形式：**     
- has(element: T): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element<sup>(deprecated)</sup> | T | true | 指定的元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 是否包含指定元素。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<string> = new Vector();let result = vector.has("squirrel");vector.add("squirrel");let result1 = vector.has("squirrel");    
```    
  
    
### get<sup>(deprecated)</sup>    
根据下标值获取Vector实例中的元素。  
 **调用形式：**     
- get(index: number): T  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index<sup>(deprecated)</sup> | number | true | 查找的下标值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回获取到的元素。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);let result = vector.get(2);    
```    
  
    
### getIndexOf<sup>(deprecated)</sup>    
返回指定元素第一次出现时的下标值，查找失败返回-1。  
 **调用形式：**     
- getIndexOf(element: T): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element<sup>(deprecated)</sup> | T | true | 指定的元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回指定元素第一次出现时的下标值，查找失败返回-1。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(2);vector.add(1);vector.add(2);vector.add(4);let result = vector.getIndexOf(2)    
```    
  
    
### getFirstElement<sup>(deprecated)</sup>    
获取实例中的第一个元素。  
 **调用形式：**     
- getFirstElement(): T  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回第一个元素。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);let result = vector.getFirstElement();    
```    
  
    
### getLastElement<sup>(deprecated)</sup>    
获取Vector实例中的最后一个元素。  
 **调用形式：**     
- getLastElement(): T  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回最后一个元素。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);let result = vector.getLastElement();    
```    
  
    
### removeByIndex<sup>(deprecated)</sup>    
根据元素的下标值查找元素，返回元素后将其删除。  
 **调用形式：**     
- removeByIndex(index: number): T  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index<sup>(deprecated)</sup> | number | true | 指定元素的下标值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回删除的元素。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(2);vector.add(4);let result = vector.removeByIndex(2);    
```    
  
    
### remove<sup>(deprecated)</sup>    
删除查找到的第一个指定的元素。  
 **调用形式：**     
- remove(element: T): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element<sup>(deprecated)</sup> | T | true | 指定元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 删除成功返回true，否则返回false。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);let result = vector.remove(2);    
```    
  
    
### set<sup>(deprecated)</sup>    
将此Vector中指定位置的元素替换为指定元素。  
 **调用形式：**     
- set(index: number, element: T): T  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index<sup>(deprecated)</sup> | number | true | 查找的下标值。 |  
| element<sup>(deprecated)</sup> | T | true | 用来替换的元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回替换后的元素。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);// 使用方法一：let nums: Array<number> =  vector.convertToArray()for (let item of nums) {  console.log("value:" + item);}  
// 使用方法二：let iter = vector[Symbol.iterator]();let temp: IteratorResult<number> = iter.next().value;while(temp != undefined) {  console.log("value:" + temp);  temp = iter.next().value;}    
```    
  
    
### getLastIndexOf<sup>(deprecated)</sup>    
返回指定元素最后一次出现时的下标值，查找失败返回-1。  
 **调用形式：**     
- getLastIndexOf(element: T): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element<sup>(deprecated)</sup> | T | true | 指定元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回指定元素最后一次出现时的下标值，查找失败返回-1。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(2);vector.add(1);vector.add(2);vector.add(4);let result = vector.getLastIndexOf(2);    
```    
  
    
### getLastIndexFrom<sup>(deprecated)</sup>    
从指定索引向后搜索，返回该元素的下标索引。  
 **调用形式：**     
- getLastIndexFrom(element: T, index: number): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element<sup>(deprecated)</sup> | T | true | 要查找的元素。 |  
| index<sup>(deprecated)</sup> | number | true |  从指定索引开始搜索。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回该元素的下标，如果查找失败，则返回-1。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);let result = vector.getLastIndexFrom(4,3);    
```    
  
    
### getIndexFrom<sup>(deprecated)</sup>    
从指定索引向前搜索，返回该元素的下标索引。  
 **调用形式：**     
- getIndexFrom(element: T, index: number): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element<sup>(deprecated)</sup> | T | true | 要查找的元素。 |  
| index<sup>(deprecated)</sup> | number | true | 从指定索引开始搜索。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回该元素的下标，如果查找失败，则返回 -1。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);let result = vector.getIndexFrom(4, 3);    
```    
  
    
### removeByRange<sup>(deprecated)</sup>    
从一段范围内删除元素，包括起始值但不包括终止值。  
 **调用形式：**     
- removeByRange(fromIndex: number, toIndex: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fromIndex<sup>(deprecated)</sup> | number | true | 起始下标。 |  
| toIndex<sup>(deprecated)</sup> | number | true |  终止下标。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);vector.removeByRange(2,4);    
```    
  
    
### replaceAllElements<sup>(deprecated)</sup>    
用户操作Vector中的元素，用操作后的元素替换原元素并返回操作后的元素。  
 **调用形式：**     
- replaceAllElements(callbackFn: (value: T, index?: number, vector?: Vector\<T>) => T, thisArg?: Object): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callbackFn<sup>(deprecated)</sup> | (value: T, index?: number, vector?: Vector<T>) => T | true | 回调函数。  |  
| thisArg<sup>(deprecated)</sup> | Object | false |  callbackfn被调用时用作this值，默认值为当前实例对象。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);vector.replaceAllElements((value : number) : number => {  // 用户操作逻辑根据实际场景进行添加。  return value;});    
```    
  
    
### forEach<sup>(deprecated)</sup>    
通过回调函数来遍历Vector实例对象上的元素以及元素对应的下标。  
 **调用形式：**     
- forEach(callbackFn: (value: T, index?: number, vector?: Vector\<T>) => void, thisArg?: Object): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callbackFn<sup>(deprecated)</sup> | (value: T, index?: number, vector?: Vector<T>) => void | true | 回调函数。 |  
| thisArg<sup>(deprecated)</sup> | Object | false | callbackfn被调用时用作this值，默认值为当前实例对象。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);vector.forEach((value : number, index ?: number) : void => {  console.log("value:" + value, "index:" + index);});    
```    
  
    
### sort<sup>(deprecated)</sup>    
对Vector中的元素进行一个排序操作。  
 **调用形式：**     
- sort(comparator?: (firstValue: T, secondValue: T) => number): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| comparator<sup>(deprecated)</sup> | (firstValue: T, secondValue: T) => number | false | 回调函数，默认值为当前实例对象。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);vector.sort((a: number, b: number) => a - b);vector.sort((a: number, b: number) => b - a);vector.sort();    
```    
  
    
### subVector<sup>(deprecated)</sup>    
根据下标截取Vector中的一段元素，并返回这一段vector实例，包括起始值但不包括终止值。  
 **调用形式：**     
- subVector(fromIndex: number, toIndex: number): Vector\<T>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fromIndex<sup>(deprecated)</sup> | number | true | 起始下标。 |  
| toIndex<sup>(deprecated)</sup> | number | true | 终止下标。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Vector<T> | 返回Vector对象实例。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);vector.add(6);vector.add(8);let result = vector.subVector(0,4);let result1 = vector.subVector(2,4);    
```    
  
    
### clear<sup>(deprecated)</sup>    
清除Vector中的所有元素，并把length置为0。  
 **调用形式：**     
- clear(): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);vector.clear();    
```    
  
    
### clone<sup>(deprecated)</sup>    
克隆一个与Vector相同的实例，并返回克隆后的实例。修改克隆后的实例并不会影响原实例。  
 **调用形式：**     
- clone(): Vector\<T>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Vector<T> | 返回Vector对象实例。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);let result = vector.clone();    
```    
  
    
### setLength<sup>(deprecated)</sup>    
设置Vector实例的元素个数。  
 **调用形式：**     
- setLength(newSize: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| newSize<sup>(deprecated)</sup> | number | true | 设置的新长度。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);vector.setLength(8);vector.setLength(2);    
```    
  
    
### getCapacity<sup>(deprecated)</sup>    
获取当前实例的容量大小。  
 **调用形式：**     
- getCapacity(): number  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回Vector的容量大小。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);let result = vector.getCapacity();    
```    
  
    
### convertToArray<sup>(deprecated)</sup>    
把当前Vector实例转换成数组，并返回转换后的数组。  
 **调用形式：**     
- convertToArray(): Array\<T>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<T> | 返回数组类型。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);let result = vector.convertToArray();    
```    
  
    
### isEmpty<sup>(deprecated)</sup>    
判断该Vector是否为空。  
 **调用形式：**     
- isEmpty(): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 为空返回true，否则返回false。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);let result = vector.isEmpty();    
```    
  
    
### increaseCapacityTo<sup>(deprecated)</sup>    
如果传入的新容量大于或等于Vector中的元素个数，将容量变更为新容量。  
 **调用形式：**     
- increaseCapacityTo(newCapacity: number): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| newCapacity<sup>(deprecated)</sup> | number | true | 新容量。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);vector.increaseCapacityTo(2);vector.increaseCapacityTo(12);    
```    
  
    
### toString<sup>(deprecated)</sup>    
用","将Vector实例中的元素按顺序拼接成字符串。  
 **调用形式：**     
- toString(): string  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回对应的字符串。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);let result = vector.toString();    
```    
  
    
### trimToCurrentLength<sup>(deprecated)</sup>    
把容量限制为当前的length大小。  
 **调用形式：**     
- trimToCurrentLength(): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);vector.trimToCurrentLength();    
```    
  
    
### copyToArray<sup>(deprecated)</sup>    
将Vector实例中的元素按照下标复制到指定数组。  
 **调用形式：**     
- copyToArray(array: Array\<T>): void  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| array<sup>(deprecated)</sup> | Array<T> | true | 指定数组。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);let result = vector.getFirstElement();    
```    
  
    
### [Symbol.iterator]<sup>(deprecated)</sup>    
返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象,并返回该对象。  
 **调用形式：**     
- [Symbol.iterator](): IterableIterator\<T>  
  
 **废弃说明：** 从API version 9 开始废弃。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<T> | 返回一个迭代器。 |  
    
 **示例代码：**   
```ts    
let vector : Vector<number> = new Vector();vector.add(2);vector.add(4);vector.add(5);vector.add(4);// 使用方法一：let nums: Array<number> =  vector.convertToArray()for (let item of nums) {  console.log("value:" + item);}  
// 使用方法二：let iter = vector[Symbol.iterator]();let temp: IteratorResult<number> = iter.next().value;while(temp != undefined) {  console.log("value:" + temp);  temp = iter.next().value;}    
```    
  
