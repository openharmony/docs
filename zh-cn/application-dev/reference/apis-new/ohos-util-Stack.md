# @ohos.util.Stack    
Stack基于数组的数据结构实现，特点是先进后出，只能在一端进行数据的插入和删除。  
  
Stack和[Queue](js-apis-queue.md)相比，Queue基于循环队列实现，只能在一端删除，另一端插入，而Stack都在一端操作。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import Stack from '@ohos.util.Stack'    
```  
    
## Stack  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| length | number | false | true | Stack的元素个数。 |  
    
### isEmpty    
判断该栈是否为空。  
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
let stack : Stack<number> = new Stack();stack.push(2);stack.push(4);stack.push(5);stack.push(4);let result = stack.isEmpty();    
```    
  
    
### peek    
获取并返回栈顶元素。  
 **调用形式：**     
- peek(): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回栈顶元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The peek method cannot be bound. |  
    
 **示例代码：**   
```ts    
let stack : Stack<number> = new Stack();stack.push(2);stack.push(4);stack.push(5);stack.push(2);let result = stack.peek();    
```    
  
    
### pop    
删除栈顶元素并返回该删除元素。  
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
let stack : Stack<number> = new Stack();stack.push(2);stack.push(4);stack.push(5);stack.push(2);stack.push(4);let result = stack.pop();    
```    
  
    
### push    
在栈顶插入元素，并返回该元素。  
 **调用形式：**     
- push(item: T): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| item | T | true | 添加进去的元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回被添加进去的元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The push method cannot be bound. |  
    
 **示例代码：**   
```ts    
class C1 {  
  name: string = ""  
  age: string = ""  
}  
let stack : Stack<number | string | C1> = new Stack();  
let result = stack.push("a");  
let result1 = stack.push(1);  
let c : C1  = {name : "Dylon", age : "13"};  
let result2 = stack.push(c);  
    
```    
  
    
### locate    
返回指定元素第一次出现时的下标值，查找失败返回-1。  
 **调用形式：**     
- locate(element: T): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| element | T | true |  指定元素。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 找到就返回下标值，查找失败返回-1。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The locate method cannot be bound. |  
    
 **示例代码：**   
```ts    
let stack : Stack<number> = new Stack();stack.push(2);stack.push(4);stack.push(5);stack.push(2);let result = stack.locate(2);    
```    
  
    
### forEach    
通过回调函数来遍历Stack实例对象上的元素以及元素对应的下标。  
 **调用形式：**     
- forEach(callbackFn: (value: T, index?: number, stack?: Stack\<T>) => void, thisArg?: Object): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callbackFn | (value: T, index?: number, stack?: Stack<T>) => void | true | 回调函数。 |  
| thisArg | Object | false | callbackfn被调用时用作this值，默认值为当前实例对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The forEach method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let stack : Stack<number> = new Stack();stack.push(2);stack.push(4);stack.push(5);stack.push(4);stack.forEach((value : number, index ?: number) :void => {  console.log("value:" + value, "index:" + index);});    
```    
  
    
### [Symbol.iterator]    
返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象,并返回该对象。  
 **调用形式：**     
- [Symbol.iterator](): IterableIterator\<T>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<T> | The Symbol.iterator method cannot be bound. |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | 返回一个迭代器。 |  
    
 **示例代码：**   
```ts    
let stack : Stack<number> = new Stack();stack.push(2);stack.push(4);stack.push(5);stack.push(4);  
// 使用方法一：while(!stack.isEmpty()) {  // 业务逻辑  let item = stack.pop()  console.log("value:" + item);}  
// 使用方法二：let iter = stack[Symbol.iterator]();let temp: IteratorResult<number> = iter.next().value;while(temp != undefined) {  console.log("value:" + temp);  temp = iter.next().value;}    
```    
  
