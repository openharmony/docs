# @ohos.util.ArrayList    
ArrayList是一种线性数据结构，底层基于数组实现。ArrayList会根据实际需要动态调整容量，每次扩容增加50%。  
  
ArrayList和[Vector](js-apis-vector.md)相似，都是基于数组实现。它们都可以动态调整容量，但Vector每次扩容增加1倍。  
  
ArrayList和[LinkedList](js-apis-linkedlist.md)相比，ArrayList的随机访问效率更高。但由于ArrayList的增删操作会影响数组内其他元素的移动，LinkedList的增加和删除操作效率更高。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import ArrayList from '@ohos.util.ArrayList'    
```  
    
## ArrayList  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| length | number | false | true | ArrayList的元素个数。 |  
    
### add    
在ArrayList尾部插入元素。  
 **调用形式：**     
- add(element: T): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element | T | true | 待插入的元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 插入成功返回true，失败返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The add method cannot be bound. |  
    
 **示例代码：**   
```ts    
class C1 {  
  name: string = ""  
  age: string = ""  
}  
let arrayList: ArrayList<string | number | boolean | Array<number> | C1> = new ArrayList();  
let result1 = arrayList.add("a");  
let arrayList1: ArrayList<number> = new ArrayList();  
let result2 = arrayList.add(1);  
let b = [1, 2, 3];  
let result3 = arrayList.add(b);  
let c : C1 = {name: "Dylon", age: "13"}  
let result4 = arrayList.add(c);  
let result5 = arrayList.add(false);  
    
```    
  
    
### insert    
在长度范围内任意位置插入指定元素。  
 **调用形式：**     
- insert(element: T, index: number): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element | T | true | 被插入的元素。 |  
| index | number | true | 被插入的位置索引。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200001 | The insert method cannot be bound. |  
| 10200011 | The value of index is out of range. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number | string | boolean> = new ArrayList();arrayList.insert("A", 0);arrayList.insert(0, 1);arrayList.insert(true, 2);    
```    
  
    
### has    
判断此ArrayList中是否含有该指定元素。  
 **调用形式：**     
- has(element: T): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element | T | true | 指定元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 返回true表示包含指定元素，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The has method cannot be bound. |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<string> = new ArrayList();arrayList.add("squirrel");let result: boolean = arrayList.has("squirrel");    
```    
  
    
### getIndexOf    
返回指定元素第一次出现时的下标值，查找失败返回-1。  
 **调用形式：**     
- getIndexOf(element: T): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element | T | true | 指定元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回指定元素第一次出现时的下标值，查找失败返回-1。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getIndexOf method cannot be bound. |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number> = new ArrayList();arrayList.add(2);arrayList.add(4);arrayList.add(5);arrayList.add(2);arrayList.add(1);arrayList.add(2);arrayList.add(4);let result: number = arrayList.getIndexOf(2);    
```    
  
    
### removeByIndex    
根据元素的下标值查找元素，返回元素后将其删除。  
 **调用形式：**     
- removeByIndex(index: number): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | 指定元素的下标值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回删除的元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200001 | The removeByIndex method cannot be bound. |  
| 10200011 | The value of index is out of range. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number> = new ArrayList();arrayList.add(2);arrayList.add(4);arrayList.add(5);arrayList.add(2);arrayList.add(4);let result: number = arrayList.removeByIndex(2);    
```    
  
    
### remove    
删除查找到的第一个指定的元素。  
 **调用形式：**     
- remove(element: T): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element | T | true | 指定元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 删除成功返回true，失败返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The remove method cannot be bound. |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number> = new ArrayList();arrayList.add(2);arrayList.add(4);arrayList.add(5);arrayList.add(4);let result: boolean = arrayList.remove(2);    
```    
  
    
### getLastIndexOf    
返回指定元素最后一次出现时的下标值，查找失败返回-1。  
 **调用形式：**     
- getLastIndexOf(element: T): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element | T | true | 指定元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回指定元素最后一次出现时的下标值，查找失败返回-1。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getLastIndexOf method cannot be bound. |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number> = new ArrayList();arrayList.add(2);arrayList.add(4);arrayList.add(5);arrayList.add(2);arrayList.add(1);arrayList.add(2);arrayList.add(4);let result: number = arrayList.getLastIndexOf(2);    
```    
  
    
### removeByRange    
从一段范围内删除元素，包括起始值但不包括终止值。  
 **调用形式：**     
- removeByRange(fromIndex: number, toIndex: number): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fromIndex | number | true |  |  
| toIndex | number | true |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200001 |  |  
| 10200011 |  |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number> = new ArrayList();arrayList.add(2);arrayList.add(4);arrayList.add(5);arrayList.add(4);arrayList.removeByRange(2, 4);    
```    
  
    
### replaceAllElements    
用户操作ArrayList中的元素，用操作后的元素替换原元素并返回操作后的元素。  
 **调用形式：**     
- replaceAllElements(callbackFn: (value: T, index?: number, arrlist?: ArrayList\<T>) => T, thisArg?: Object): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callbackFn | (value: T, index?: number, arrlist?: ArrayList<T>) => T | true | 回调函数。 |  
| thisArg | Object | false | callbackfn被调用时用作this值，默认值为当前实例对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The replaceAllElements method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number> = new ArrayList();arrayList.add(2);arrayList.add(4);arrayList.add(5);arrayList.add(4);arrayList.replaceAllElements((value: number): number => {  // 用户操作逻辑根据实际场景进行添加。  return value;});    
```    
  
    
### forEach    
通过回调函数来遍历ArrayList实例对象上的元素以及元素对应的下标。  
 **调用形式：**     
- forEach(callbackFn: (value: T, index?: number, arrlist?: ArrayList\<T>) => void, thisArg?: Object): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callbackFn | (value: T, index?: number, arrlist?: ArrayList<T>) => void | true | 回调函数。 |  
| thisArg | Object | false | callbackfn被调用时用作this值，默认值为当前实例对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The forEach method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number> = new ArrayList();arrayList.add(2);arrayList.add(4);arrayList.add(5);arrayList.add(4);arrayList.forEach((value: number, index?: number) => {  console.log("value:" + value, "index:" + index);});    
```    
  
    
### sort    
对ArrayList中的元素排序。  
 **调用形式：**     
- sort(comparator?: (firstValue: T, secondValue: T) => number): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| comparator | (firstValue: T, secondValue: T) => number | false | 回调函数，默认为升序排序的回调函数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The sort method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number> = new ArrayList();arrayList.add(2);arrayList.add(4);arrayList.add(5);arrayList.add(4);arrayList.sort((a: number, b: number) => a - b);arrayList.sort((a: number, b: number) => b - a);arrayList.sort();    
```    
  
    
### subArrayList    
根据下标截取ArrayList中的一段元素，并返回这一段ArrayList实例，包括起始值但不包括终止值。  
 **调用形式：**     
- subArrayList(fromIndex: number, toIndex: number): ArrayList\<T>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| fromIndex | number | true | 起始下标。 |  
| toIndex | number | true | 终止下标。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ArrayList<T> | 返回ArrayList对象实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200001 | The subArrayList method cannot be bound. |  
| 10200011 | The value of fromIndex or toIndex is out of range. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number> = new ArrayList();arrayList.add(2);arrayList.add(4);arrayList.add(5);arrayList.add(4);let result: ArrayList<number> = arrayList.subArrayList(2, 4);    
```    
  
    
### clear    
清除ArrayList中的所有元素，并把length置为0。  
 **调用形式：**     
- clear(): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The clear method cannot be bound. |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number> = new ArrayList();arrayList.add(2);arrayList.add(4);arrayList.add(5);arrayList.add(4);arrayList.clear();    
```    
  
    
### clone    
克隆一个与ArrayList相同的实例，并返回克隆后的实例。修改克隆后的实例并不会影响原实例。  
 **调用形式：**     
- clone(): ArrayList\<T>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| ArrayList<T> | 返回ArrayList对象实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The clone method cannot be bound. |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number> = new ArrayList();arrayList.add(2);arrayList.add(4);arrayList.add(5);arrayList.add(4);let result:  ArrayList<number> = arrayList.clone();    
```    
  
    
### getCapacity    
获取当前实例的容量大小。  
 **调用形式：**     
- getCapacity(): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回arraylist的容量大小。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getCapacity method cannot be bound. |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number> = new ArrayList();arrayList.add(2);arrayList.add(4);arrayList.add(5);arrayList.add(4);let result: number = arrayList.getCapacity();    
```    
  
    
### convertToArray    
把当前ArrayList实例转换成数组，并返回转换后的数组。  
 **调用形式：**     
- convertToArray(): Array\<T>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<T> | 返回数组类型。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The convertToArray method cannot be bound. |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number> = new ArrayList();arrayList.add(2);arrayList.add(4);arrayList.add(5);arrayList.add(4);let result: Array<number> = arrayList.convertToArray();    
```    
  
    
### isEmpty    
判断该ArrayList是否为空。  
 **调用形式：**     
- isEmpty(): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 为空返回true，不为空返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The isEmpty method cannot be bound. |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number> = new ArrayList();arrayList.add(2);arrayList.add(4);arrayList.add(5);arrayList.add(4);let result: boolean = arrayList.isEmpty();    
```    
  
    
### increaseCapacityTo    
如果传入的新容量大于或等于ArrayList中的元素个数，将容量变更为新容量。  
 **调用形式：**     
- increaseCapacityTo(newCapacity: number): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| newCapacity | number | true | 新容量。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The increaseCapacityTo method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number> = new ArrayList();arrayList.add(2);arrayList.add(4);arrayList.add(5);arrayList.add(4);arrayList.increaseCapacityTo(2);arrayList.increaseCapacityTo(8);    
```    
  
    
### trimToCurrentLength    
把容量限制为当前的length大小。  
 **调用形式：**     
- trimToCurrentLength(): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The trimToCurrentLength method cannot be bound. |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number> = new ArrayList();arrayList.add(2);arrayList.add(4);arrayList.add(5);arrayList.add(4);arrayList.trimToCurrentLength();    
```    
  
    
### [Symbol.iterator]    
返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象，并返回该对象。  
 **调用形式：**     
- [Symbol.iterator](): IterableIterator\<T>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<T> | 返回一个迭代器。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The Symbol.iterator method cannot be bound. |  
    
 **示例代码：**   
```ts    
let arrayList: ArrayList<number> = new ArrayList();arrayList.add(2);arrayList.add(4);arrayList.add(5);arrayList.add(4);  
// 使用方法一：let numbers: Array<number> = arrayList.convertToArray()for (let item of numbers) {  console.log(`value : ${item}`);}  
// 使用方法二：let iter = arrayList[Symbol.iterator]();let temp: IteratorResult<number> = iter.next().value;while(!temp.done) {    console.log(`value:${temp.value}`);    temp = iter.next();}    
```    
  
