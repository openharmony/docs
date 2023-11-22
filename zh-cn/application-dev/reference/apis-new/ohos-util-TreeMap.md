# @ohos.util.TreeMap    
TreeMap可用于存储具有关联关系的key-value键值对集合，存储元素中key值唯一，每个key对应一个value。<span style="letter-spacing: 0px;">TreeMap底层使用红黑树实现，可以利用二叉树特性快速查找键值对。key值有序存储，可以实现快速的插入和删除。</span>  
TreeMap和[HashMap](js-apis-hashmap.md)相比，HashMap依据键的hashCode存取数据，访问速度较快。而TreeMap是有序存取，效率较低。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import TreeMap from '@ohos.util.TreeMap'    
```  
    
## TreeMap  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| length | number | false | true | TreeMap的元素个数。 |  
    
### isEmpty    
判断该容器是否为空。  
 **调用形式：**     
- isEmpty(): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 为空返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The isEmpty method cannot be bound. |  
    
 **示例代码：**   
```ts    
let treeMap : TreeMap<number, number> = new TreeMap();let result = treeMap.isEmpty();    
```    
  
    
### hasKey    
判断此容器中是否含有该指定key。  
 **调用形式：**     
- hasKey(key: K): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true | 指定key |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 包含指定key返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The hasKey method cannot be bound. |  
    
 **示例代码：**   
```ts    
let treeMap : TreeMap<string, number> = new TreeMap();treeMap.set("squirrel", 123);let result = treeMap.hasKey("squirrel");    
```    
  
    
### hasValue    
判断此容器中是否含有该指定value。  
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
| boolean | 包含指定元素返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The hasValue method cannot be bound. |  
    
 **示例代码：**   
```ts    
let treeMap : TreeMap<string, number> = new TreeMap();treeMap.set("squirrel", 123);let result = treeMap.hasValue(123);    
```    
  
    
### get    
获取指定key所对应的value。  
 **调用形式：**     
- get(key: K): V  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true | 指定key。 |  
    
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
let treeMap : TreeMap<string, number> = new TreeMap();treeMap.set("squirrel", 123);treeMap.set("sparrow", 356);let result = treeMap.get("sparrow");    
```    
  
    
### getFirstKey    
获取容器中排序第一的key。  
 **调用形式：**     
- getFirstKey(): K  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| K | 返回排序第一的key。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getFirstKey method cannot be bound. |  
    
 **示例代码：**   
```ts    
let treeMap : TreeMap<string, number> = new TreeMap();treeMap.set("squirrel", 123);treeMap.set("sparrow", 356);let result = treeMap.getFirstKey();    
```    
  
    
### getLastKey    
获取容器中排序最后的key。  
 **调用形式：**     
- getLastKey(): K  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| K | 获取容器中排序最后的key。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getLastKey method cannot be bound. |  
    
 **示例代码：**   
```ts    
let treeMap : TreeMap<string, number> = new TreeMap();treeMap.set("squirrel", 123);treeMap.set("sparrow", 356);let result = treeMap.getLastKey();    
```    
  
    
### setAll    
将一个TreeMap中的所有元素组添加到另一个TreeMap中。  
 **调用形式：**     
- setAll(map: TreeMap\<K, V>): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| map | TreeMap<K, V> | true | 该map会添加到其调用setAll接口的map对象中。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The setAll method cannot be bound. |  
| 401 | 该map会添加到其调用setAll接口的map对象中。 |  
    
 **示例代码：**   
```ts    
let treeMap : TreeMap<string, number> = new TreeMap();treeMap.set("squirrel", 123);treeMap.set("sparrow", 356);let map : TreeMap<string, number> = new TreeMap();map.set("demo", 12);map.setAll(treeMap); // 将treeMap中的所有元素添加到map中map.forEach((value ?: number, key ?: string) : void => {  console.log("value" + value, "key" + key); // 打印结果 12 demo、356 sparrow、123 squirrel})    
```    
  
    
### set    
向容器中添加一组数据。  
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
| Object |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The set method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let treeMap : TreeMap<string, number> = new TreeMap();treeMap.set("squirrel", 123);    
```    
  
    
### remove    
删除指定key对应的元素。  
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
let treeMap : TreeMap<string, number> = new TreeMap();treeMap.set("squirrel", 123);treeMap.set("sparrow", 356);let result = treeMap.remove("sparrow");    
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
let treeMap : TreeMap<string, number> = new TreeMap();treeMap.set("squirrel", 123);treeMap.set("sparrow", 356);treeMap.clear();    
```    
  
    
### getLowerKey    
获取容器中比传入key排序靠前一位的key。  
 **调用形式：**     
- getLowerKey(key: K): K  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true | 对比的key值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| K | 返回排序中key前一位的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getLowerKey method cannot be bound. |  
    
 **示例代码：**   
```ts    
let treeMap : TreeMap<string, number> = new TreeMap();treeMap.set("squirrel", 123);treeMap.set("sparrow", 356);treeMap.set("gander", 356);let result = treeMap.getLowerKey("sparrow");    
```    
  
    
### getHigherKey    
获取容器中比传入key排序靠后一位的key。  
 **调用形式：**     
- getHigherKey(key: K): K  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true | 对比的key值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| K | 返回排序中key后一位的数据。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getHigherKey method cannot be bound. |  
    
 **示例代码：**   
```ts    
let treeMap : TreeMap<string, number> = new TreeMap();treeMap.set("squirrel", 123);treeMap.set("sparrow", 356);treeMap.set("gander", 356);let result = treeMap.getHigherKey("sparrow");    
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
let treeMap : TreeMap<string, number> = new TreeMap();treeMap.set("squirrel", 123);treeMap.set("sparrow", 356);let it = treeMap.values();let t: IteratorResult<number> = it.next();while(!t.done) {  console.log("TreeMap" + t.value);  t = it.next()}    
```    
  
    
### values    
返回包含此映射中键值的新迭代器对象。  
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
let treeMap : TreeMap<string, number> = new TreeMap();treeMap.set("squirrel", 123);treeMap.set("sparrow", 356);let it = treeMap.values();let t: IteratorResult<number> = it.next();while(!t.done) {  console.log("TreeMap" + t.value);  t = it.next()}    
```    
  
    
### replace    
对容器中一组数据进行更新（替换）。  
 **调用形式：**     
- replace(key: K, newValue: V): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true | 指定key。 |  
| newValue | V | true | 替换的元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 对指定key对应的元素替换成功返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The replace method cannot be bound. |  
    
 **示例代码：**   
```ts    
let treeMap : TreeMap<string, number> = new TreeMap();treeMap.set("sparrow", 123);let result = treeMap.replace("sparrow", 357);    
```    
  
    
### forEach    
通过回调函数来遍历实例对象上的元素以及元素对应的下标。  
 **调用形式：**     
- forEach(callbackFn: (value?: V, key?: K, map?: TreeMap\<K, V>) => void, thisArg?: Object): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callbackFn | (value?: V, key?: K, map?: TreeMap<K, V>) => void | true | 回调函数。 |  
| thisArg | Object | false | callbackFn被调用时用作this值，默认值为当前实例对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The forEach method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let treeMap : TreeMap<string, number> = new TreeMap();treeMap.set("sparrow", 123);treeMap.set("gull", 357);treeMap.forEach((value ?: number, key ?: string) : void => {  console.log("value:" + value, "key:" + key);});    
```    
  
    
### entries    
返回包含此映射中键值对的新迭代器对象。  
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
let treeMap : TreeMap<string, number> = new TreeMap();treeMap.set("squirrel", 123);treeMap.set("sparrow", 356);let it = treeMap.entries();let t: IteratorResult<Object[]> = it.next();while(!t.done) {  console.log("TreeMap" + t.value);  t = it.next()}    
```    
  
    
### [Symbol.iterator]    
返回一个迭代器，迭代器的每一项都是一个JavaScript对象，并返回该对象。  
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
let treeMap : TreeMap<string, number> = new TreeMap();treeMap.set("squirrel", 123);treeMap.set("sparrow", 356);  
// 使用方法一：let it = treeMap.entries();let t: IteratorResult<Object[]> = it.next();while(!t.done) {  console.log("TreeMap" + t.value);  t = it.next()}  
// 使用方法二：let iter = treeMap[Symbol.iterator]();let temp: IteratorResult<Object[]> = iter.next().value;while(temp != undefined) {  console.log("key:" + temp[0]);  console.log("value:" + temp[1]);  temp = iter.next().value;}    
```    
  
