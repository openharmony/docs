# @ohos.util.TreeSet    
TreeSet基于[TreeMap](js-apis-treemap.md)实现，在TreeSet中，只对value对象进行处理。TreeSet可用于存储一系列值的集合，元素中value唯一且有序。  
  
TreeSet和[HashSet](js-apis-hashset.md)相比，HashSet中的数据无序存放，而TreeSet是有序存放。它们集合中的元素都不允许重复，但HashSet允许放入null值，TreeSet不允许。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import TreeSet from '@ohos.util.TreeSet'    
```  
    
## TreeSet  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| length | number | false | true | TreeSet的元素个数。 |  
    
### isEmpty    
判断该容器是否为空。  
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
const treeSet : TreeSet<string | number | boolean | Object>  = new TreeSet();let result = treeSet.isEmpty();    
```    
  
    
### has    
判断此容器中是否含有该指定元素。  
 **调用形式：**     
- has(value: T): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | T | true | 指定元素。 |  
    
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
let treeSet : TreeSet<number> = new TreeSet();treeSet.add(123);let result = treeSet.has(123);    
```    
  
    
### add    
向容器中添加一组数据。  
 **调用形式：**     
- add(value: T): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | T | true | 添加的成员数据 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 成功添加新数据至容器返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200011 | The add method cannot be bound. |  
    
 **示例代码：**   
```ts    
let treeSet : TreeSet<string> = new TreeSet();let result = treeSet.add("squirrel");    
```    
  
    
### remove    
删除指定的元素。  
 **调用形式：**     
- remove(value: T): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | T | true | 指定的元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 成功删除元素返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The remove method cannot be bound. |  
    
 **示例代码：**   
```ts    
let treeSet : TreeSet<string> = new TreeSet();treeSet.add("squirrel");treeSet.add("sparrow");let result = treeSet.remove("sparrow");    
```    
  
    
### clear    
清除容器中的所有元素，并把length置为0。  
 **调用形式：**     
- clear(): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The clear method cannot be bound. |  
    
 **示例代码：**   
```ts    
let treeSet : TreeSet<string> = new TreeSet();treeSet.add("squirrel");treeSet.add("sparrow");treeSet.clear();    
```    
  
    
### getFirstValue    
获取容器中排序第一的数据。  
 **调用形式：**     
- getFirstValue(): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回排序第一的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getFirstValue method cannot be bound. |  
    
 **示例代码：**   
```ts    
let treeSet : TreeSet<string> = new TreeSet();treeSet.add("squirrel");treeSet.add("sparrow");let result = treeSet.getFirstValue();    
```    
  
    
### getLastValue    
获取容器中排序最后的数据。  
 **调用形式：**     
- getLastValue(): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回排序最后的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getLastValue method cannot be bound. |  
    
 **示例代码：**   
```ts    
let treeSet : TreeSet<string> = new TreeSet();treeSet.add("squirrel");treeSet.add("sparrow");let result = treeSet.getLastValue();    
```    
  
    
### getLowerValue    
获取容器中比传入元素排序靠前一位的元素。  
 **调用形式：**     
- getLowerValue(key: T): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | T | true | 对比的元素值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回排序中对比元素前一位的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getLowerValue method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let treeSet : TreeSet<string> = new TreeSet();treeSet.add("squirrel");treeSet.add("sparrow");treeSet.add("gander");let result = treeSet.getLowerValue("sparrow");    
```    
  
    
### getHigherValue    
获取容器中比传入元素排序靠后一位的元素。  
 **调用形式：**     
- getHigherValue(key: T): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | T | true | 对比的元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回排序中传入元素后一位的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getHigherValue method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let treeSet : TreeSet<string> = new TreeSet();treeSet.add("squirrel");treeSet.add("sparrow");treeSet.add("gander");let result = treeSet.getHigherValue("sparrow");    
```    
  
    
### popFirst    
删除容器中排序最前的数据。  
 **调用形式：**     
- popFirst(): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回删除的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The popFirst method cannot be bound. |  
    
 **示例代码：**   
```ts    
let treeSet : TreeSet<string> = new TreeSet();treeSet.add("squirrel");treeSet.add("sparrow");let result = treeSet.popFirst();    
```    
  
    
### popLast    
删除容器中排序最后的数据。  
 **调用形式：**     
- popLast(): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回删除的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The popLast method cannot be bound. |  
    
 **示例代码：**   
```ts    
let treeSet : TreeSet<string> = new TreeSet();treeSet.add("squirrel");treeSet.add("sparrow");let result = treeSet.popLast();    
```    
  
    
### forEach    
通过回调函数来遍历实例对象上的元素以及元素对应的下标。  
 **调用形式：**     
- forEach(callbackFn: (value?: T, key?: T, set?: TreeSet\<T>) => void, thisArg?: Object): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callbackFn | (value?: T, key?: T, set?: TreeSet<T>) => void | true | 回调函数。 |  
| thisArg | Object | false |  callbackFn被调用时用作this值，默认值为当前实例对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The forEach method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let treeSet : TreeSet<string> = new TreeSet();treeSet.add("sparrow");treeSet.add("gull");treeSet.forEach((value ?: string, key ?: string) :void => {  console.log("value:" + value, "key:" + key);});    
```    
  
    
### values    
返回包含此映射中键值的新迭代器对象。  
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
let treeSet : TreeSet<string> = new TreeSet();treeSet.add("squirrel");treeSet.add("sparrow");let it = treeSet.values();let t: IteratorResult<string> = it.next();while(!t.done) {  console.log("TreeSet: " + t.value);  t = it.next()}    
```    
  
    
### entries    
返回包含此映射中键值对的新迭代器对象。  
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
let treeSet : TreeSet<string> = new TreeSet();treeSet.add("squirrel");treeSet.add("sparrow");let it = treeSet.entries();let t: IteratorResult<Object[]> = it.next();while(!t.done) {  console.log("TreeSet: " + t.value);  t = it.next()}    
```    
  
    
### [Symbol.iterator]    
返回一个迭代器，迭代器的每一项都是一个JavaScript对象，并返回该对象。  
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
let treeSet : TreeSet<string> = new TreeSet();treeSet.add("squirrel");treeSet.add("sparrow");let numbers = Array.from(treeSet.values())// 使用方法一：for (let item of numbers) {  console.log("value:" + item);}// 使用方法二：let iter = treeSet[Symbol.iterator]();let temp: IteratorResult<string> = iter.next().value;while(temp != undefined) {  console.log("value:" + temp);  temp = iter.next().value;}    
```    
  
