# @ohos.util.LightWeightMap    
LightWeightMap可用于存储具有关联关系的key-value键值对集合，存储元素中key值唯一，每个key对应一个value。  
  
LightWeightMap依据泛型定义，采用轻量级结构，初始默认容量大小为8，每次扩容大小为原始容量的两倍。  
  
集合中key值的查找依赖于hash算法，通过一个数组存储hash值，然后映射到其他数组中的key值及value值。  
  
LightWeightMap和[HashMap](js-apis-hashmap.md)都是用来存储键值对的集合，LightWeightMap占用内存更小。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import LightWeightMap from '@ohos.util.LightWeightMap'    
```  
    
## LightWeightMap  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| length | number | false | true | LightWeightMap的元素个数。<br/> |  
    
### hasAll    
判断此LightWeightMap中是否含有该指定map中的所有元素。  
 **调用形式：**     
- hasAll(map: LightWeightMap\<K, V>): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| map | LightWeightMap<K, V> | true | 比较对象。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 包含所有元素返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200011 | The hasAll method cannot be bound. |  
    
 **示例代码：**   
```ts    
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);lightWeightMap.set("sparrow", 356);let map: LightWeightMap<string, number> = new LightWeightMap();map.set("sparrow", 356);let result = lightWeightMap.hasAll(map);    
```    
  
    
### hasKey    
判断此LightWeightMap中是否含有该指定key。  
 **调用形式：**     
- hasKey(key: K): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true |  指定key。 |  
    
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
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);let result = lightWeightMap.hasKey("squirrel");    
```    
  
    
### hasValue    
判断此LightWeightMap中是否含有该指定value。  
 **调用形式：**     
- hasValue(value: V): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | V | true | 指定元素。 |  
    
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
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);let result = lightWeightMap.hasValue(123);    
```    
  
    
### increaseCapacityTo    
将当前LightWeightMap扩容至可以容纳指定数量元素。  
 **调用形式：**     
- increaseCapacityTo(minimumCapacity: number): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| minimumCapacity | number | true | 需要容纳的数量。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The increaseCapacityTo method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.increaseCapacityTo(10);    
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
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);lightWeightMap.set("sparrow", 356);let iter = lightWeightMap.entries();let temp: IteratorResult<Object[]> = iter.next();while(!temp.done) {  console.log("key:" + temp.value[0]);  console.log("value:" + temp.value[1]);  temp = iter.next();}    
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
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);lightWeightMap.set("sparrow", 356);let result = lightWeightMap.get("sparrow");    
```    
  
    
### getIndexOfKey    
查找key元素第一次出现的下标值，如果没有找到该元素返回-1。  
 **调用形式：**     
- getIndexOfKey(key: K): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true | 被查找的元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回key元素第一次出现时的下标值，查找失败返回-1。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getIndexOfKey method cannot be bound. |  
    
 **示例代码：**   
```ts    
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);lightWeightMap.set("sparrow", 356);let result = lightWeightMap.getIndexOfKey("sparrow");    
```    
  
    
### getIndexOfValue    
查找value元素第一次出现的下标值，如果没有找到该元素返回-1。  
 **调用形式：**     
- getIndexOfValue(value: V): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | V | true | 被查找的元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回value元素第一次出现时的下标值，查找失败返回-1。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getIndexOfValue method cannot be bound. |  
    
 **示例代码：**   
```ts    
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);lightWeightMap.set("sparrow", 356);let result = lightWeightMap.getIndexOfValue(123);    
```    
  
    
### isEmpty    
判断该LightWeightMap是否为空。  
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
const lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();let result = lightWeightMap.isEmpty();    
```    
  
    
### getKeyAt    
查找指定下标的元素键值对中key值，否则返回undefined。  
 **调用形式：**     
- getKeyAt(index: number): K  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | 所查找的下标。  |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| K | 返回该下标对应的元素键值对中key值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getKeyAt method cannot be bound. |  
| 10200001 | The value of index is out of range. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);lightWeightMap.set("sparrow", 356);let result = lightWeightMap.getKeyAt(1);    
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
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);lightWeightMap.set("sparrow", 356);let iter = lightWeightMap.keys();let temp: IteratorResult<string, number> = iter.next();while(!temp.done) {  console.log("value:" + temp.value);  temp = iter.next();}    
```    
  
    
### setAll    
将一个LightWeightMap中的所有元素组添加到另一个lightWeightMap中。  
 **调用形式：**     
- setAll(map: LightWeightMap\<K, V>): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| map | LightWeightMap<K, V> | true | 被添加元素的lightWeightMap。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The setAll method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);lightWeightMap.set("sparrow", 356);let map: LightWeightMap<string, number> = new LightWeightMap();map.setAll(lightWeightMap); // 将lightWeightMap中所有的元素添加到map中    
```    
  
    
### set    
向LightWeightMap中添加一组数据。  
 **调用形式：**     
- set(key: K, value: V): Object  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | K | true |  添加成员数据的键名。 |  
| value | V | true |  添加成员数据的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Object | 返回添加数据后的lightWeightMap。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The set method cannot be bound. |  
    
 **示例代码：**   
```ts    
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();let result = lightWeightMap.set("squirrel", 123);    
```    
  
    
### remove    
删除并返回指定key映射的元素。  
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
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);lightWeightMap.set("sparrow", 356);lightWeightMap.remove("sparrow");    
```    
  
    
### removeAt    
删除指定下标对应的元素。  
 **调用形式：**     
- removeAt(index: number): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | 指定下标。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 成功删除元素返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The removeAt method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);lightWeightMap.set("sparrow", 356);let result = lightWeightMap.removeAt(1);    
```    
  
    
### clear    
清除LightWeightMap中的所有元素,并把length置为0。  
 **调用形式：**     
- clear(): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The clear method cannot be bound. |  
    
 **示例代码：**   
```ts    
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);lightWeightMap.set("sparrow", 356);lightWeightMap.clear();    
```    
  
    
### setValueAt    
替换指定下标对应键值对中的元素。  
 **调用形式：**     
- setValueAt(index: number, newValue: V): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true |  <span style="font-family: monospace, monospace; font-size: 1em; letter-spacing: 0px;">指定下标。</span><br/> |  
| newValue | V | true | 替换键值对中的值。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 成功替换指定位置数据返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The setValueAt method cannot be bound. |  
| 10200001 | The value of index is out of range. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);lightWeightMap.set("sparrow", 356);lightWeightMap.setValueAt(1, 3546);    
```    
  
    
### forEach    
通过回调函数来遍历实例对象上的元素以及元素对应的下标。  
 **调用形式：**     
- forEach(callbackFn: (value?: V, key?: K, map?: LightWeightMap\<K, V>) => void, thisArg?: Object): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callbackFn | (value?: V, key?: K, map?: LightWeightMap<K, V>) => void | true | 回调函数。 |  
| thisArg | Object | false | callbackfn被调用时用作this值，默认值为当前实例对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The forEach method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("sparrow", 123);lightWeightMap.set("gull", 357);lightWeightMap.forEach((value?: number, key?: string) => {  console.log("value:" + value, "key:" + key);});    
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
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);lightWeightMap.set("sparrow", 356);  
// 使用方法一：let nums = Array.from(lightWeightMap.values());for (let item1 of nums) {  console.log("value:" + item1);}  
let key = Array.from(lightWeightMap.keys());for (let item2 of key) {  console.log("key:" + item2);}  
// 使用方法二：let iter = lightWeightMap[Symbol.iterator]();let temp: IteratorResult<Object[]> = iter.next();while(!temp.done) {  console.log("key:" + temp.value[0]);  console.log("value:" + temp.value[1]);  temp = iter.next();}    
```    
  
    
### toString    
将此映射中包含的键值对拼接成字符串，并返回字符串类型。  
 **调用形式：**     
- toString(): String  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| String | 返回一个字符串。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The toString method cannot be bound. |  
    
 **示例代码：**   
```ts    
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);lightWeightMap.set("sparrow", 356);let result = lightWeightMap.toString();    
```    
  
    
### getValueAt    
获取指定下标对应键值对中的元素。  
 **调用形式：**     
- getValueAt(index: number): V  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true |  指定下标。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| V | 返回指定下标对应键值对中的元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getValueAt method cannot be bound. |  
| 10200001 | The value of index is out of range. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);lightWeightMap.set("sparrow", 356);let result = lightWeightMap.getValueAt(1);    
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
let lightWeightMap: LightWeightMap<string, number> = new LightWeightMap();lightWeightMap.set("squirrel", 123);lightWeightMap.set("sparrow", 356);let iter = lightWeightMap.values();let temp: IteratorResult<number> = iter.next();while(!temp.done) {  console.log("value:" + temp.value);  temp = iter.next();}    
```    
  
