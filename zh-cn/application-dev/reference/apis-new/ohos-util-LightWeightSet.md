# @ohos.util.LightWeightSet    
LightWeightSet可用于存储一系列值的集合，存储元素中value值唯一。  
  
LightWeightSet依据泛型定义，采用轻量级结构，初始默认容量大小为8，每次扩容大小为原始容量的两倍。  
  
集合中value值的查找依赖于hash算法，通过一个数组存储hash值，然后映射到其他数组中的value值。  
  
LightWeightSet和[HashSet](js-apis-hashset.md)都是用来存储键值的集合，LightWeightSet的占用内存更小。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import LightWeightSet from '@ohos.util.LightWeightSet'    
```  
    
## LightWeightSet  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| length | number | false | true | LightWeightSet的元素个数。 |  
    
### add    
向此容器中添加数据。  
 **调用形式：**     
- add(obj: T): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| obj | T | true | 添加的成员数据。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 成功添加元素返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The add method cannot be bound. |  
    
 **示例代码：**   
```ts    
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();let result = lightWeightSet.add("squirrel");    
```    
  
    
### addAll    
将另一个容器中的所有元素组添加到当前容器中。  
 **调用形式：**     
- addAll(set: LightWeightSet\<T>): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| set | LightWeightSet<T> | true | 提供添加元素的lightWeightSet。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The addAll method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();lightWeightSet.add("squirrel");lightWeightSet.add("sparrow");let set: LightWeightSet<string> = new LightWeightSet();set.add("gull");let result = lightWeightSet.addAll(set);    
```    
  
    
### hasAll    
判断此容器中是否含有该指定set中的所有元素。  
 **调用形式：**     
- hasAll(set: LightWeightSet\<T>): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| set | LightWeightSet<T> | true | 比较对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 包含所有元素返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The hasAll method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();lightWeightSet.add("squirrel");lightWeightSet.add("sparrow");let set: LightWeightSet<string> = new LightWeightSet();set.add("sparrow");let result = lightWeightSet.hasAll(set);    
```    
  
    
### has    
判断此容器中是否含有该指定key。  
 **调用形式：**     
- has(key: T): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | T | true |  指定key |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 包含指定key返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The has method cannot be bound. |  
    
 **示例代码：**   
```ts    
let lightWeightSet: LightWeightSet<number> = new LightWeightSet();lightWeightSet.add(123);let result = lightWeightSet.has(123);    
```    
  
    
### equal    
判断此容器中是否含有该指定obj同类型的对象。  
 **调用形式：**     
- equal(obj: Object): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| obj | Object | true | 比较对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 构成类型相同返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The equal method cannot be bound. |  
    
 **示例代码：**   
```ts    
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();lightWeightSet.add("squirrel");lightWeightSet.add("sparrow");let obj = ["sparrow", "squirrel"];let result = lightWeightSet.equal(obj)    
```    
  
    
### increaseCapacityTo    
将当前容器扩容至可以容纳指定数量元素。  
 **调用形式：**     
- increaseCapacityTo(minimumCapacity: number): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| minimumCapacity | number | true | 需要容纳数量。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The increaseCapacityTo method cannot be bound. |  
| 401 |  |  
| 10200001 | The value of minimumCapacity is out of range. |  
    
 **示例代码：**   
```ts    
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();lightWeightSet.increaseCapacityTo(10);    
```    
  
    
### getIndexOf    
获取指定key所对应的下标。  
 **调用形式：**     
- getIndexOf(key: T): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | T | true | 查找的指定key。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 在lightWeightSet中指定数据的下标。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getIndexOf method cannot be bound. |  
    
 **示例代码：**   
```ts    
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();lightWeightSet.add("squirrel");lightWeightSet.add("sparrow");let result = lightWeightSet.getIndexOf("sparrow");    
```    
  
    
### remove    
删除并返回指定key对应的元素。  
 **调用形式：**     
- remove(key: T): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | T | true | 指定key。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回删除元素的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The remove method cannot be bound. |  
    
 **示例代码：**   
```ts    
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();lightWeightSet.add("squirrel");lightWeightSet.add("sparrow");let result = lightWeightSet.remove("sparrow");    
```    
  
    
### removeAt    
删除指定下标所对应的元素。  
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
| boolean | 确认是否成功删除元素 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The removeAt method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();lightWeightSet.add("squirrel");lightWeightSet.add("sparrow");let result = lightWeightSet.removeAt(1);    
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
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();lightWeightSet.add("squirrel");lightWeightSet.add("sparrow");lightWeightSet.clear();    
```    
  
    
### forEach    
通过回调函数来遍历LightWeightSet实例对象上的元素以及元素对应的下标。  
 **调用形式：**     
- forEach(callbackFn: (value?: T, key?: T, set?: LightWeightSet\<T>) => void, thisArg?: Object): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callbackFn | (value?: T, key?: T, set?: LightWeightSet<T>) => void | true | 回调函数。 |  
| thisArg | Object | false | callbackfn被调用时用作this值，默认值为当前实例对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The forEach method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();lightWeightSet.add("sparrow");lightWeightSet.add("gull");lightWeightSet.forEach((value ?: string, key ?: string) => {  console.log("value:" + value, "key:" + key);});    
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
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();lightWeightSet.add("squirrel");lightWeightSet.add("sparrow");  
// 使用方法一：let nums: Array<string> = lightWeightSet.toArray()for (let item of nums) {  console.log("value:" + item);}  
// 使用方法二：let iter = lightWeightSet[Symbol.iterator]();let temp: IteratorResult<string> = iter.next();while(!temp.done) {  console.log("value:" + temp.value);  temp = iter.next();}    
```    
  
    
### toString    
获取包含容器中所有键和值的字符串。  
 **调用形式：**     
- toString(): String  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| String | 返回对应字符串。 |  
    
 **示例代码：**   
```ts    
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();lightWeightSet.add("squirrel");lightWeightSet.add("sparrow");let result = lightWeightSet.toString();    
```    
  
    
### toArray    
获取包含此容器中所有对象的数组。  
 **调用形式：**     
- toArray(): Array\<T>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| Array<T> | 返回对应数组。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The toArray method cannot be bound. |  
    
 **示例代码：**   
```ts    
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();lightWeightSet.add("squirrel");lightWeightSet.add("sparrow");let result = lightWeightSet.toArray();    
```    
  
    
### getValueAt    
获取此容器中指定下标对应的元素。  
 **调用形式：**     
- getValueAt(index: number): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true |  指定下标。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回指定下标对应的元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getValueAt method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();lightWeightSet.add("squirrel");lightWeightSet.add("sparrow");let result = lightWeightSet.getValueAt(1);    
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
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();lightWeightSet.add("squirrel");lightWeightSet.add("sparrow");let iter = lightWeightSet.values();let index = 0;while(index < lightWeightSet.length) {  console.log(JSON.stringify(iter.next().value));  index++;}    
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
let lightWeightSet: LightWeightSet<string> = new LightWeightSet();lightWeightSet.add("squirrel");lightWeightSet.add("sparrow");let iter = lightWeightSet.entries();let index = 0;while(index < lightWeightSet.length) {  console.log(JSON.stringify(iter.next().value));  index++;}    
```    
  
    
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
const lightWeightSet: LightWeightSet<number> = new LightWeightSet();let result = lightWeightSet.isEmpty();    
```    
  
