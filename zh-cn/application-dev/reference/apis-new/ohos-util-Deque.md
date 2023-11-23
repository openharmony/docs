# @ohos.util.Deque    
Deque（double ended queue）根据循环队列的数据结构实现，符合先进先出以及先进后出的特点，支持两端的元素插入和移除。Deque会根据实际需要动态调整容量，每次进行两倍扩容。  
  
Deque和[Queue](js-apis-queue.md)相比，Queue的特点是先进先出，只能在头部删除元素，尾部增加元素。  
  
与[Vector](js-apis-vector.md)相比，它们都支持在两端增删元素，但Deque不能进行中间插入的操作。对头部元素的插入删除效率高于Vector，而Vector访问元素的效率高于Deque。<span style="font-family: monospace, monospace; font-size: 1em; letter-spacing: 0px;">  
</span><span style="font-family: monospace, monospace; font-size: 1em; letter-spacing: 0px;">文档中存在泛型的使用，涉及以下泛型标记符：  
</span>。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import Deque from '@ohos.util.Deque'    
```  
    
## Deque  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| length | number | false | true | Deque的元素个数。 |  
    
### insertFront    
在deque头部插入元素。  
 **调用形式：**     
- insertFront(element: T): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element | T | true | 插入的元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The insertFront method cannot be bound. |  
    
 **示例代码：**   
```ts    
class C1 {  
  name: string = ""  
  age: string = ""  
}  
let deque: Deque<string | number | boolean | Array<number> | C1> = new Deque();  
deque.insertFront("a");  
deque.insertFront(1);  
let b = [1, 2, 3];  
deque.insertFront(b);  
let c: C1 = {name : "Dylon", age : "13"};  
deque.insertFront(c);  
deque.insertFront(false);  
    
```    
  
    
### insertEnd    
在deque尾部插入元素。  
 **调用形式：**     
- insertEnd(element: T): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element | T | true | 插入的元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The insertEnd method cannot be bound. |  
    
 **示例代码：**   
```ts    
class C1 {  
  name: string = ""  
  age: string = ""  
}  
  
let deque: Deque<string | number | boolean | Array<number> | C1> = new Deque();  
deque.insertEnd("a");  
deque.insertEnd(1);  
let b = [1, 2, 3];  
deque.insertEnd(b);  
let c: C1 = {name : "Dylon", age : "13"};  
deque.insertEnd(c);  
deque.insertEnd(false);<i></i><span style="font-size: 14px; letter-spacing: 0px;"></span>  
    
```    
  
    
### has    
判断此Deque中是否含有该指定元素。  
 **调用形式：**     
- has(element: T): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element | T | true | 指定的元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 如果包含指定元素返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The has method cannot be bound. |  
    
 **示例代码：**   
```ts    
let deque: Deque<string> = new Deque();deque.insertFront("squirrel");let result = deque.has("squirrel");    
```    
  
    
### getFirst    
获取Deque实例中的头元素。  
 **调用形式：**     
- getFirst(): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回T类型的头元素 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getFirst method cannot be bound. |  
    
 **示例代码：**   
```ts    
let deque: Deque<number> = new Deque();deque.insertEnd(2);deque.insertEnd(4);deque.insertFront(5);deque.insertFront(4);let result = deque.getFirst();    
```    
  
    
### getLast    
获取Deque实例中的尾元素。  
 **调用形式：**     
- getLast(): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回T类型的尾元素 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getLast method cannot be bound. |  
    
 **示例代码：**   
```ts    
let deque: Deque<number> = new Deque();deque.insertFront(2);deque.insertFront(4);deque.insertFront(5);deque.insertFront(4);let result = deque.getLast(    
```    
  
    
### popFirst    
删除并返回双端队列的首元素。  
 **调用形式：**     
- popFirst(): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回被删除的首元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The popFirst method cannot be bound. |  
    
 **示例代码：**   
```ts    
let deque: Deque<number> = new Deque();deque.insertFront(2);deque.insertFront(4);deque.insertEnd(5);deque.insertFront(2);deque.insertFront(4);let result = deque.popFirst();    
```    
  
    
### popLast    
删除并返回双端队列的尾元素。  
 **调用形式：**     
- popLast(): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回被删除的尾元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The popLast method cannot be bound. |  
    
 **示例代码：**   
```ts    
let deque: Deque<number> = new Deque();deque.insertFront(2);deque.insertEnd(4);deque.insertFront(5);deque.insertFront(2);deque.insertFront(4);let result = deque.popLast();    
```    
  
    
### forEach    
通过回调函数来遍历Deque实例对象上的元素以及元素对应的下标。  
 **调用形式：**     
- forEach(callbackFn: (value: T, index?: number, deque?: Deque\<T>) => void, thisArg?: Object): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callbackFn | (value: T, index?: number, deque?: Deque<T>) => void | true | 回调函数。 |  
| thisArg | Object | false | callbackfn被调用时用作this值，默认值为当前实例对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200011 | The forEach method cannot be bound. |  
    
 **示例代码：**   
```ts    
let deque: Deque<number> = new Deque();deque.insertFront(2);deque.insertEnd(4);deque.insertFront(5);deque.insertEnd(4);deque.forEach((value: number, index?: number | undefined, deque?: Deque<number> | undefined):void => {  console.log("value:" + value, "index:" + index);});    
```    
  
    
### [Symbol.iterator]    
返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象,并返回该对象。  
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
let deque: Deque<number> = new Deque();deque.insertFront(2);deque.insertFront(4);deque.insertFront(5);deque.insertFront(4);  
// 使用方法一：let nums: Array<number> = Array.from(deque)for (let item of nums) {  console.log("value:" + item);}  
// 使用方法二：let iter = deque[Symbol.iterator]();let temp:IteratorResult<number> = iter.next();while(!temp.done) {  console.log("value:" + temp.value);  temp = iter.next();}    
```    
  
