# @ohos.util.HashSet    
HashSet基于[HashMap](js-apis-hashmap.md)实现。在HashSet中，只对value对象进行处理。  
  
HashSet和[TreeSet](js-apis-treeset.md)相比，HashSet中的数据无序存放，即存放元素的顺序和取出的顺序不一致，而TreeSet是有序存放。它们集合中的元素都不允许重复，但HashSet允许放入null值，TreeSet不允许。。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import HashSet from '@ohos.util.HashSet'    
```  
    
## HashSet  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| length | number | false | true | HashSet的元素个数。 |  
    
### isEmpty    
判断该HashSet是否为空。  
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
const hashSet: HashSet<number> = new HashSet();let result = hashSet.isEmpty();    
```    
  
    
### has    
判断此HashSet中是否含有该指定元素。  
 **调用形式：**     
- has(value: T): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | T | true |  指定元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 包含指定元素返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The has method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let hashSet: HashSet<string> = new HashSet();hashSet.add("squirrel");let result = hashSet.has("squirrel");    
```    
  
    
### add    
向HashSet中添加数据。  
 **调用形式：**     
- add(value: T): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | T | true | 添加成员数据。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 成功增加元素返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The add method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let hashSet: HashSet<string> = new HashSet();let result = hashSet.add("squirrel");    
```    
  
    
### remove    
删除指定的元素。  
 **调用形式：**     
- remove(value: T): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | T | true | 指定删除的元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 成功删除指定元素返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The remove method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let hashSet: HashSet<string> = new HashSet();hashSet.add("squirrel");hashSet.add("sparrow");let result = hashSet.remove("sparrow");    
```    
  
    
### clear    
清除HashSet中的所有元素,并把length置为0。  
 **调用形式：**     
- clear(): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The clear method cannot be bound. |  
    
 **示例代码：**   
```ts    
let hashSet: HashSet<string> = new HashSet();hashSet.add("squirrel");hashSet.add("sparrow");hashSet.clear();    
```    
  
    
### forEach    
通过回调函数来遍历实例对象上的元素以及元素对应的下标。  
 **调用形式：**     
- forEach(callbackFn: (value?: T, key?: T, set?: HashSet\<T>) => void, thisArg?: Object): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callbackFn | (value?: T, key?: T, set?: HashSet<T>) => void | true | 回调函数。 |  
| thisArg | Object | false | callbackfn被调用时用作this值，默认值为当前实例对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The forEach method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let hashSet: HashSet<string> = new HashSet();hashSet.add("sparrow");hashSet.add("squirrel");hashSet.forEach((value?: string, key?: string): void => {  console.log("value:" + value, "key:" + key);});    
```    
  
    
### values    
返回包含此映射中包含的键值的新迭代器对象。  
 **调用形式：**     
- values(): IterableIterator\<T>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<T> | 返回一个迭代器。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The values method cannot be bound. |  
    
 **示例代码：**   
```ts    
let hashSet: HashSet<string> = new HashSet();hashSet.add("squirrel");hashSet.add("sparrow");let iter = hashSet.values();let temp = iter.next();while(!temp.done) {  console.log("value:" + temp.value);  temp = iter.next();}    
```    
  
    
### entries    
返回包含此映射中包含的键值对的新迭代器对象。  
 **调用形式：**     
- entries(): IterableIterator\<[T, T]>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<[T, T]> | 返回一个迭代器。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The entries method cannot be bound. |  
    
 **示例代码：**   
```ts    
let hashSet: HashSet<string> = new HashSet();hashSet.add("squirrel");hashSet.add("sparrow");let iter = hashSet.entries();let temp: IteratorResult<[string, string]> = iter.next();while(!temp.done) {  console.log("key:" + temp.value[0]);  console.log("value:" + temp.value[1]);  temp = iter.next();}    
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
let hashSet: HashSet<string> = new HashSet();hashSet.add("squirrel");hashSet.add("sparrow");  
// 使用方法一：let val: Array<string> = Array.from(hashSet.values())for (let item of val) {  console.log("value: " + item);}  
// 使用方法二：let iter = hashSet[Symbol.iterator]();let temp: IteratorResult<string> = iter.next();while(!temp.done) {  console.log("value: " + temp.value);  temp = iter.next();}    
```    
  
