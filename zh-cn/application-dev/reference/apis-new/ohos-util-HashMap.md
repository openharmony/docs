# @ohos.util.HashMap    
HashMap底层使用数组+链表+红黑树的方式实现，查询、插入和删除的效率都很高。HashMap存储内容基于key-value的键值对映射，不能有重复的key，且一个key只能对应一个value。<span style="letter-spacing: 0px;">HashMap和[TreeMap](js-apis-treemap.md)相比，HashMap依据键的hashCode存取数据，访问速度较快。而TreeMap是有序存取，效率较低。</span>  
[HashSet](js-apis-hashset.md)基于HashMap实现。HashMap的输入参数由key、value两个值组成。在HashSet中，只对value对象进行处理。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import HashMap from '@ohos.util.HashMap'    
```  
    
## HashMap  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| length | number | false | true | HashMap的元素个数。 |  
    
### isEmpty    
判断该HashMap是否为空。  
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
const hashMap: HashMap<string, number> = new HashMap();let result = hashMap.isEmpty();    
```    
  
    
### hasKey    
判断此HashMap中是否含有该指定key。  
 **调用形式：**     
- hasKey(key: K): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true | 指定Key。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 包含指定Key返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The hasKey method cannot be bound. |  
    
 **示例代码：**   
```ts    
const hashMap: HashMap<string, number> = new HashMap();hashMap.set("squirrel", 123);let result = hashMap.hasKey("squirrel");    
```    
  
    
### hasValue    
判断此HashMap中是否含有该指定value。  
 **调用形式：**     
- hasValue(value: V): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | V | true | 指定value。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 包含指定value返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The hasValue method cannot be bound. |  
    
 **示例代码：**   
```ts    
const hashMap: HashMap<string, number> = new HashMap();hashMap.set("squirrel", 123);let result = hashMap.hasValue(123);    
```    
  
    
### get    
获取指定key所对应的value。  
 **调用形式：**     
- get(key: K): V  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true | 查找的指定key。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| V | 返回key映射的value值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The get method cannot be bound. |  
    
 **示例代码：**   
```ts    
const hashMap: HashMap<string, number> = new HashMap();hashMap.set("squirrel", 123);hashMap.set("sparrow", 356);let result = hashMap.get("sparrow");    
```    
  
    
### setAll    
将一个HashMap中的所有元素组添加到另一个hashMap中。  
 **调用形式：**     
- setAll(map: HashMap\<K, V>): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| map | HashMap<K, V> | true | 被添加元素的hashMap。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The setAll method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
const hashMap: HashMap<string, number> = new HashMap();hashMap.set("squirrel", 123);hashMap.set("sparrow", 356);let newHashMap: HashMap<string, number> = new HashMap();newHashMap.set("newMap", 99);hashMap.setAll(newHashMap);    
```    
  
    
### set    
向HashMap中添加一组数据。  
 **调用形式：**     
- set(key: K, value: V): Object  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true | 添加成员数据的键名。 |  
| value | V | true | 添加成员数据的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Object | 返回添加后的hashMap。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The set method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let hashMap: HashMap<string, number> = new HashMap();let result = hashMap.set("squirrel", 123);    
```    
  
    
### remove    
删除指定key所对应元素。  
 **调用形式：**     
- remove(key: K): V  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true | 指定key。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| V | 返回删除元素的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The remove method cannot be bound. |  
    
 **示例代码：**   
```ts    
let hashMap: HashMap<string, number> = new HashMap();hashMap.set("squirrel", 123);hashMap.set("sparrow", 356);let result = hashMap.remove("sparrow");    
```    
  
    
### clear    
清除HashMap中的所有元素,并把length置为0。  
 **调用形式：**     
- clear(): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The clear method cannot be bound. |  
    
 **示例代码：**   
```ts    
let hashMap: HashMap<string, number> = new HashMap();hashMap.set("squirrel", 123);hashMap.set("sparrow", 356);hashMap.clear();    
```    
  
    
### keys    
返回包含此映射中包含的键的新迭代器对象。  
 **调用形式：**     
- keys(): IterableIterator\<K>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<K> | 返回一个迭代器。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The keys method cannot be bound. |  
    
 **示例代码：**   
```ts    
let hashMap: HashMap<string, number> = new HashMap();hashMap.set("squirrel", 123);hashMap.set("sparrow", 356);let iter = hashMap.keys();let temp: IteratorResult<string,number> = iter.next();while(!temp.done) {  console.log("value:" + temp.value);  temp = iter.next();}    
```    
  
    
### values    
返回包含此映射中包含的键值的新迭代器对象。  
 **调用形式：**     
- values(): IterableIterator\<V>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<V> | 返回一个迭代器。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The values method cannot be bound. |  
    
 **示例代码：**   
```ts    
let hashMap: HashMap<string, number> = new HashMap();hashMap.set("squirrel", 123);hashMap.set("sparrow", 356);let iter = hashMap.values();let temp: IteratorResult<number> = iter.next();while(!temp.done) {  console.log("value:" + temp.value);  temp = iter.next();}    
```    
  
    
### replace    
对HashMap中一组数据进行更新（替换）。  
 **调用形式：**     
- replace(key: K, newValue: V): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true | 依据key指定替换的元素。 |  
| newValue | V | true | 替换成员数据的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 是否成功对已有数据进行替换 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The replace method cannot be bound. |  
    
 **示例代码：**   
```ts    
let hashMap: HashMap<string, number> = new HashMap();hashMap.set("sparrow", 123);let result = hashMap.replace("sparrow", 357);    
```    
  
    
### forEach    
通过回调函数来遍历HashMap实例对象上的元素以及元素对应的下标。  
 **调用形式：**     
- forEach(callbackFn: (value?: V, key?: K, map?: HashMap\<K, V>) => void, thisArg?: Object): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callbackFn | (value?: V, key?: K, map?: HashMap<K, V>) => void | true | 回调函数。 |  
| thisArg | Object | false | callbackfn被调用时用作this值，默认值为当前实例对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The forEach method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let hashMap: HashMap<string, number> = new HashMap();hashMap.set("sparrow", 123);hashMap.set("gull", 357);hashMap.forEach((value?: number, key?: string) => {  console.log("value:" + value, "key:" + key);});    
```    
  
    
### entries    
返回包含此映射中包含的键值对的新迭代器对象。  
 **调用形式：**     
- entries(): IterableIterator\<[K, V]>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<[K, V]> | 返回一个迭代器。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The entries method cannot be bound. |  
    
 **示例代码：**   
```ts    
let hashMap: HashMap<string, number> = new HashMap();hashMap.set("squirrel", 123);hashMap.set("sparrow", 356);let iter = hashMap.entries();let temp: IteratorResult<Object[]> = iter.next();while(!temp.done) {  console.log("key:" + temp.value[0]);  console.log("value:" + temp.value[1]);  temp = iter.next();}    
```    
  
    
### [Symbol.iterator]    
返回一个迭代器，迭代器的每一项都是一个 JavaScript 对象,并返回该对象。  
 **调用形式：**     
- [Symbol.iterator](): IterableIterator\<[K, V]>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<[K, V]> | 返回一个迭代器。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The Symbol.iterator method cannot be bound. |  
    
 **示例代码：**   
```ts    
let hashMap: HashMap<string, number> = new HashMap();hashMap.set("squirrel", 123);hashMap.set("sparrow", 356);  
// 使用方法一：let keys = Array.from(hashMap.keys());for (let key of keys) {  console.log("key:" + key);  console.log("value:" + hashMap.get(key));}  
// 使用方法二：let iter = hashMap[Symbol.iterator]();let temp: IteratorResult<Object[]> = iter.next().value;while(temp != undefined) {  console.log("key:" + temp[0]);  console.log("value:" + temp[1]);  temp = iter.next().value;}    
```    
  
