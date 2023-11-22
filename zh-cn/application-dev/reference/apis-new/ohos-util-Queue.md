# @ohos.util.Queue    
Queue的特点是先进先出，在尾部增加元素，在头部删除元素。根据循环队列的数据结构实现。  
  
Queue和[Deque](js-apis-deque.md)相比，Queue只能在一端删除一端增加，Deque可以两端增删。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import Queue from '@ohos.util.Queue'    
```  
    
## Queue  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| length | number | false | true |  Queue的元素个数。 |  
    
### add    
在队列尾部插入元素。  
 **调用形式：**     
- add(element: T): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element | T | true | 添加进去的元素。 |  
    
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
class C1 {  
  name: string = ""  
  age: string = ""  
}  
let queue : Queue<number | string | C1 | number[]> = new Queue();  
let result = queue.add("a");  
let result1 = queue.add(1);  
let b = [1, 2, 3];  
let result2 = queue.add(b);  
let c : C1 = {name : "Dylon", age : "13"};  
let result3 = queue.add(c);  
    
```    
  
    
### getFirst    
获取队列的头元素。  
 **调用形式：**     
- getFirst(): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回获取的元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getFirst method cannot be bound. |  
    
 **示例代码：**   
```ts    
let queue : Queue<number> = new Queue();queue.add(2);queue.add(4);queue.add(5);queue.add(2);let result = queue.getFirst();    
```    
  
    
### pop    
删除头元素并返回该删除元素。  
 **调用形式：**     
- pop(): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回删除的元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The pop method cannot be bound. |  
    
 **示例代码：**   
```ts    
let queue : Queue<number> = new Queue();queue.add(2);queue.add(4);queue.add(5);queue.add(2);queue.add(4);let result = queue.pop();    
```    
  
    
### forEach    
通过回调函数来遍历Queue实例对象上的元素以及元素对应的下标。  
 **调用形式：**     
- forEach(callbackFn: (value: T, index?: number, Queue?: Queue\<T>) => void, thisArg?: Object): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callbackFn | (value: T, index?: number, Queue?: Queue<T>) => void | true | 回调函数。 |  
| thisArg | Object | false | callbackfn被调用时用作this值，默认值为当前实例对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The forEach method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let queue : Queue<number> = new Queue();queue.add(2);queue.add(4);queue.add(5);queue.add(4);queue.forEach((value : number, index ?: number) : void => {  console.log("value:" + value, "index:" + index);});    
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
let queue : Queue<number> = new Queue();queue.add(2);queue.add(4);queue.add(5);queue.add(4);  
// 使用方法一：while(queue.length) {  let item = queue.pop()  console.log("value:" + item);}  
// 使用方法二：let iter = queue[Symbol.iterator]();let temp: IteratorResult<number> = iter.next().value;while(temp != undefined) {  console.log("value:" + temp);  temp = iter.next().value;}    
```    
  
