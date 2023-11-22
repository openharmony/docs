# @ohos.util.PlainArray    
PlainArray可用于存储具有关联关系的key-value键值对集合，存储元素中key值唯一，key值类型为number类型，每个key对应一个value。<span style="letter-spacing: 0px;">PlainArray依据泛型定义，采用轻量级结构，集合中key值的查找依赖于二分查找算法，然后映射到其他数组中的value值。</span>  
PlainArray和[LightWeightMap](js-apis-lightweightmap.md)都是用来存储键值对，且均采用轻量级结构，但PlainArray的key值类型只能为number类型。  
> **说明**   
>本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import PlainArray from '@ohos.util.PlainArray'    
```  
    
## PlainArray  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| length | number | false | true | PlainArray的元素个数。 |  
    
### add    
向容器中添加一组数据。  
 **调用形式：**     
- add(key: number, value: T): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | number | true | 添加成员数据的键名。 |  
| value | T | true | 添加成员数据的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The add method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let plainArray: PlainArray<string> = new PlainArray();plainArray.add(1, "squirrel");    
```    
  
    
### clear    
清除容器中的所有元素，并把length置为0。  
 **调用形式：**     
- clear(): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The clear method cannot be bound |  
    
 **示例代码：**   
```ts    
let plainArray: PlainArray<string> = new PlainArray();plainArray.add(1, "squirrel");plainArray.add(2, "sparrow");plainArray.clear();    
```    
  
    
### clone    
克隆一个实例，并返回克隆后的实例。修改克隆后的实例并不会影响原实例。  
 **调用形式：**     
- clone(): PlainArray\<T>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| PlainArray<T> | 返回新的对象实例。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The clone method cannot be bound. |  
    
 **示例代码：**   
```ts    
let plainArray: PlainArray<string> = new PlainArray();plainArray.add(1, "squirrel");plainArray.add(2, "sparrow");let newPlainArray = plainArray.clone();    
```    
  
    
### has    
判断此容器中是否含有该指定key。  
 **调用形式：**     
- has(key: number): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | number | true | 指定key。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 包含指定key返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The has method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let plainArray: PlainArray<string> = new PlainArray();plainArray.add(1, "squirrel");let result = plainArray.has(1);    
```    
  
    
### get    
获取指定key所对应的value。  
 **调用形式：**     
- get(key: number): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | number | true | 查找的指定key。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回key映射的value值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | he get method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let plainArray: PlainArray<string> = new PlainArray();plainArray.add(1, "squirrel");plainArray.add(2, "sparrow");let result = plainArray.get(1);    
```    
  
    
### getIndexOfKey    
查找指定key第一次出现的下标值，如果没有找到该key返回-1。  
 **调用形式：**     
- getIndexOfKey(key: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | number | true | 指定key。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回指定key第一次出现时的下标值，查找失败返回-1。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getIndexOfKey method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let plainArray: PlainArray<string> = new PlainArray();plainArray.add(1, "squirrel");plainArray.add(2, "sparrow");let result = plainArray.getIndexOfKey(2);    
```    
  
    
### getIndexOfValue    
查找指定value元素第一次出现的下标值，如果没有找到该value元素返回-1。  
 **调用形式：**     
- getIndexOfValue(value: T): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| value | T | true | 指定value元素。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回指定value元素第一次出现时的下标值，查找失败返回-1。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getIndexOfValue method cannot be bound. |  
    
 **示例代码：**   
```ts    
let plainArray: PlainArray<string> = new PlainArray();plainArray.add(1, "squirrel");plainArray.add(2, "sparrow");let result = plainArray.getIndexOfValue("squirrel");    
```    
  
    
### isEmpty    
判断该容器是否为空。  
 **调用形式：**     
- isEmpty(): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 为空返回true, 不为空返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The isEmpty method cannot be bound. |  
    
 **示例代码：**   
```ts    
const plainArray: PlainArray<string> = new PlainArray();let result = plainArray.isEmpty();    
```    
  
    
### getKeyAt    
查找指定下标元素键值对中的key值。  
 **调用形式：**     
- getKeyAt(index: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | 指定下标。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 返回该下标元素键值对中的key值，失败返回-1。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getKeyAt method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let plainArray: PlainArray<string> = new PlainArray();plainArray.add(1, "squirrel");plainArray.add(2, "sparrow");let result = plainArray.getKeyAt(1);    
```    
  
    
### remove    
删除指定key对应元素。  
 **调用形式：**     
- remove(key: number): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| key | number | true | 指定key。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回删除元素的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The remove method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let plainArray: PlainArray<string> = new PlainArray();plainArray.add(1, "squirrel");plainArray.add(2, "sparrow");let result = plainArray.remove(2);    
```    
  
    
### removeAt    
删除指定下标对应的元素。  
 **调用形式：**     
- removeAt(index: number): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | 指定元素下标。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回删除的元素。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The removeAt method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let plainArray: PlainArray<string> = new PlainArray();plainArray.add(1, "squirrel");plainArray.add(2, "sparrow");let result = plainArray.removeAt(1);    
```    
  
    
### removeRangeFrom    
删除一定范围内的元素。  
 **调用形式：**     
- removeRangeFrom(index: number, size: number): number  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | 删除元素的起始下标。 |  
| size | number | true | 期望删除元素个数。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| number | 实际删除元素个数。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The removeRangeFrom method cannot be bound |  
| 10200001 | The value of index is out of range. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let plainArray: PlainArray<string> = new PlainArray();plainArray.add(1, "squirrel");plainArray.add(2, "sparrow");let result = plainArray.removeRangeFrom(1, 3);    
```    
  
    
### setValueAt    
替换容器中指定下标对应键值对中的键值。  
 **调用形式：**     
- setValueAt(index: number, value: T): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | 指定替换数据下标。 |  
| value | T | true | 替换键值对中的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The setValueAt method cannot be bound. |  
| 10200001 | The value of index is out of range. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let plainArray: PlainArray<string | number> = new PlainArray();plainArray.add(1, "squirrel");plainArray.add(2, "sparrow");plainArray.setValueAt(1, 3546);    
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
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The toString method cannot be bound. |  
    
 **示例代码：**   
```ts    
let plainArray: PlainArray<string> = new PlainArray();plainArray.add(1, "squirrel");plainArray.add(2, "sparrow");let result = plainArray.toString();    
```    
  
    
### getValueAt    
查找指定下标元素键值对中的Value值，失败返回undefined。  
 **调用形式：**     
- getValueAt(index: number): T  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| index | number | true | 指定下标。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| T | 返回该下标元素键值对中的value值，失败返回undefined。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The getValueAt method cannot be bound. |  
| 10200001 | The value of index is out of range. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let plainArray: PlainArray<string> = new PlainArray();plainArray.add(1, "squirrel");plainArray.add(2, "sparrow");let result = plainArray.getValueAt(1);    
```    
  
    
### forEach    
通过回调函数来遍历实例对象上的元素以及元素对应的下标。  
 **调用形式：**     
- forEach(callbackFn: (value: T, index?: number, PlainArray?: PlainArray\<T>) => void, thisArg?: Object): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callbackFn | (value: T, index?: number, PlainArray?: PlainArray<T>) => void | true | 回调函数。 |  
| thisArg | Object | false | callbackfn被调用时用作this值，默认值为当前实例对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The forEach method cannot be bound. |  
| 401 |  |  
    
 **示例代码：**   
```ts    
let plainArray: PlainArray<string> = new PlainArray();plainArray.add(1, "squirrel");plainArray.add(2, "sparrow");plainArray.forEach((value: string, index?: number) => {    console.log("value:" + value, "index:" + index);});    
```    
  
    
### [Symbol.iterator]    
返回一个包含key-value键值对的迭代器对象，其中key是number类型。  
 **调用形式：**     
- [Symbol.iterator](): IterableIterator\<[number, T]>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<[number, T]> | 返回一个迭代器。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 10200011 | The Symbol.iterator method cannot be bound. |  
    
 **示例代码：**   
```ts    
let plainArray: PlainArray<string> = new PlainArray();plainArray.add(1, "squirrel");plainArray.add(2, "sparrow");  
let iter = plainArray[Symbol.iterator]();let temp: IteratorResult<Object[]> = iter.next();while(!temp.done) {  console.log("key:" + temp.value[0]);  console.log("value:" + temp.value[1]);  temp = iter.next();}    
```    
  
