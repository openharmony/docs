# @ohos.util.LinkedList    
LinkedList底层通过双向链表实现，双向链表的每个节点都包含对前一个元素和后一个元素的引用。当需要查询元素时，可以从头遍历，也可以从尾部遍历，插入、删除效率高，查询效率低。LinkedList允许元素为null。  
  
LinkedList和[List](js-apis-list.md)相比，LinkedList是双向链表，可以快速地在头尾进行增删，而List是单向链表，无法双向操作。  
  
LinkedList和[ArrayList](js-apis-arraylist.md)相比，插入数据效率LinkedList优于ArrayList，而查询效率ArrayList优于LinkedList。  
  
**推荐使用场景：** 当需要频繁的插入删除时，推荐使用LinkedList高效操作。  
  
文档中存在泛型的使用，涉及以下泛型标记符：  
  
- T： Type，类。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import LinkedList from '@ohos.util.LinkedList'    
```  
    
## LinkedList  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| length | number | false | true | LinkedList的元素个数。 |  
    
### add    
在LinkedList尾部插入元素。  
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
| boolean | 插入成功返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The add method cannot be bound. |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<string | number | boolean | object> = new LinkedList();  
let result = linkedList.add("a");  
let result1 = linkedList.add(1);  
let b = [1, 2, 3];  
let result2 = linkedList.add(b);  
class C {  
  name: string = ''  
  age: string = ''  
}  
let c: C = {name : "Dylon", age : "13"};  
let result3 = linkedList.add(c);  
let result4 = linkedList.add(false);  
    
```    
  
    
### insert    
在长度范围内任意插入指定元素。  
 **调用形式：**     
- insert(index: number, element: T): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | 插入位置索引。 |  
| element | T | true | 插入元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The insert method cannot be bound. |  
| 401 |  |  
| 10200001 | The value of index is out of range. |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<string | number | boolean | object> = new LinkedList();  
linkedList.insert(0, "A");  
linkedList.insert(1, 0);  
linkedList.insert(2, true);    
```    
  
    
### get    
根据下标获取LinkedList中的元素。  
 **调用形式：**     
- get(index: number): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | 指定的下标值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 根据下标查找到的元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The get method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<number> = new LinkedList();  
linkedList.add(2);  
linkedList.add(4);  
linkedList.add(5);  
linkedList.add(2);  
linkedList.add(1);  
linkedList.add(2);  
linkedList.add(4);  
let result = linkedList.get(2);    
```    
  
    
### addFirst    
在LinkedList头部插入元素。  
 **调用形式：**     
- addFirst(element: T): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element | T | true | 待插入的元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The addFirst method cannot be bound. |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<string | number | boolean | object> = new LinkedList();  
linkedList.addFirst("a");  
linkedList.addFirst(1);  
let b = [1, 2, 3];  
linkedList.addFirst(b);  
class C {  
  name: string = ''  
  age: string = ''  
}  
let c: C = {name : "Dylon", age : "13"};  
linkedList.addFirst(c);  
linkedList.addFirst(false);  
    
```    
  
    
### removeFirst    
删除并返回LinkedList的第一个元素。  
 **调用形式：**     
- removeFirst(): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回删除的元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The removeFirst method cannot be bound. |  
| 10200010 | Container is empty. |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<number> = new LinkedList();  
linkedList.add(2);  
linkedList.add(4);  
linkedList.add(5);  
linkedList.add(2);  
linkedList.add(4);  
let result = linkedList.removeFirst();    
```    
  
    
### removeLast    
删除并返回LinkedList的最后一个元素。  
 **调用形式：**     
- removeLast(): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回删除的元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The removeLast method cannot be bound. |  
| 10200010 | Container is empty. |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<number> = new LinkedList();  
linkedList.add(2);  
linkedList.add(4);  
linkedList.add(5);  
linkedList.add(2);  
linkedList.add(4);  
let result = linkedList.removeLast();    
```    
  
    
### has    
判断此LinkedList中是否含有该指定元素。  
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
| boolean | 包含指定元素返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The has method cannot be bound. |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<string> = new LinkedList();  
linkedList.add("squirrel");  
let result = linkedList.has("squirrel");    
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
let linkedList: LinkedList<number> = new LinkedList();  
linkedList.add(2);  
linkedList.add(4);  
linkedList.add(5);  
linkedList.add(2);  
linkedList.add(1);  
linkedList.add(2);  
linkedList.add(4);  
let result = linkedList.getIndexOf(2);    
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
| 10200011 | The removeByIndex method cannot be bound. |  
| 401 |  |  
| 10200001 | The value of index is out of range. |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<number> = new LinkedList();  
linkedList.add(2);  
linkedList.add(4);  
linkedList.add(5);  
linkedList.add(2);  
linkedList.add(4);  
let result = linkedList.removeByIndex(2);    
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
| boolean | 删除成功返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The remove method cannot be bound. |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<number> = new LinkedList();  
linkedList.add(2);  
linkedList.add(4);  
linkedList.add(5);  
linkedList.add(4);  
let result = linkedList.remove(2);    
```    
  
    
### removeFirstFound    
删除第一次出现的指定元素。  
 **调用形式：**     
- removeFirstFound(element: T): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element | T | true | 指定元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 删除成功返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The removeFirstFound method cannot be bound. |  
| 10200010 | Container is empty. |  
| 10200017 | The element does not exist in this container. |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<number> = new LinkedList();  
linkedList.add(2);  
linkedList.add(4);  
linkedList.add(5);  
linkedList.add(4);  
let result = linkedList.removeFirstFound(4);    
```    
  
    
### removeLastFound    
删除最后一次出现的指定元素。  
 **调用形式：**     
- removeLastFound(element: T): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element | T | true | 指定元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 删除成功返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The removeLastFound method cannot be bound. |  
| 10200010 | Container is empty. |  
| 10200017 | The element does not exist in this container. |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<number> = new LinkedList();  
linkedList.add(2);  
linkedList.add(4);  
linkedList.add(5);  
linkedList.add(4);  
let result = linkedList.removeLastFound(4);    
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
let linkedList: LinkedList<number> = new LinkedList();  
linkedList.add(2);  
linkedList.add(4);  
linkedList.add(5);  
linkedList.add(2);  
linkedList.add(1);  
linkedList.add(2);  
linkedList.add(4);  
let result = linkedList.getLastIndexOf(2);    
```    
  
    
### getFirst    
获取LinkedList实例中的第一个元素。  
 **调用形式：**     
- getFirst(): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回对应元素，如果为空返回undefined。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getFirst method cannot be bound. |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<number> = new LinkedList();  
linkedList.add(2);  
linkedList.add(4);  
linkedList.add(5);  
linkedList.add(4);  
let result = linkedList.getFirst();    
```    
  
    
### getLast    
获取LinkedList实例中的最后一个元素。  
 **调用形式：**     
- getLast(): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回对应元素，如果为空返回undefined。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getLast method cannot be bound. |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<number> = new LinkedList();  
linkedList.add(2);  
linkedList.add(4);  
linkedList.add(5);  
linkedList.add(4);  
let result = linkedList.getLast();    
```    
  
    
### set    
将此LinkedList中指定位置的元素替换为指定元素。  
 **调用形式：**     
- set(index: number, element: T): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | 查找的下标值。 |  
| element | T | true | 用来替换的元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回替换后的元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The set method cannot be bound. |  
| 10200001 | The value of index is out of range. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<number | string> = new LinkedList();  
linkedList.add(2);  
linkedList.add(4);  
linkedList.add(5);  
linkedList.add(4);  
let result = linkedList.set(2, "b");    
```    
  
    
### forEach    
通过回调函数来遍历LinkedList实例对象上的元素以及元素对应的下标。  
 **调用形式：**     
- forEach(callbackFn: (value: T, index?: number, LinkedList?: LinkedList\<T>) => void, thisArg?: Object): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callbackFn | (value: T, index?: number, LinkedList?: LinkedList<T>) => void | true | 回调函数。 |  
| thisArg | Object | false | callbackfn被调用时用作this值，默认值为当前实例对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The forEach method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<number> = new LinkedList();  
linkedList.add(2);  
linkedList.add(4);  
linkedList.add(5);  
linkedList.add(4);  
linkedList.forEach((value: number, index?: number) => {  
  console.log("value:" + value, "index:" + index);  
});    
```    
  
    
### clear    
清除LinkedList中的所有元素，并把length置为0。  
 **调用形式：**     
- clear(): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The clear method cannot be bound. |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<number> = new LinkedList();  
linkedList.add(2);  
linkedList.add(4);  
linkedList.add(5);  
linkedList.add(4);  
linkedList.clear();    
```    
  
    
### clone    
克隆一个与LinkedList相同的实例，并返回克隆后的实例。修改克隆后的实例并不会影响原实例。  
 **调用形式：**     
- clone(): LinkedList\<T>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| LinkedList<T> | 返回LinkedList对象实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The clone method cannot be bound. |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<number> = new LinkedList();  
linkedList.add(2);  
linkedList.add(4);  
linkedList.add(5);  
linkedList.add(4);  
let result = linkedList.clone();    
```    
  
    
### convertToArray    
把当前LinkedList实例转换成数组，并返回转换后的数组。  
 **调用形式：**     
- convertToArray(): Array\<T>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<T> | 返回转换后的数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The convertToArray method cannot be bound. |  
    
 **示例代码：**   
```ts    
let linkedList: LinkedList<number> = new LinkedList();  
linkedList.add(2);  
linkedList.add(4);  
linkedList.add(5);  
linkedList.add(4);  
let result = linkedList.convertToArray();    
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
let linkedList: LinkedList<number> = new LinkedList();  
linkedList.add(2);  
linkedList.add(4);  
linkedList.add(5);  
linkedList.add(4);  
  
// 使用方法一：  
let items = Array.from(linkedList)  
for (let item of items) {   
  console.log("value:" + item);   
}   
  
// 使用方法二：  
let iter = linkedList[Symbol.iterator]();  
let temp: IteratorResult<number> = iter.next();  
while(!temp.done) {  
  console.log("value:" + temp.value);  
  temp = iter.next();  
}    
```    
  
