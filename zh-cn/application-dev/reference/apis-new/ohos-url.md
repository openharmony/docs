# @ohos.url    
URL代表着是统一资源定位符，本模块提供了常用的工具函数，实现了处理URL字符串[URLParams](#urlparams9)和构造[URL](#url)对象等功能。  
> **说明**   
>本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本  
  
## 导入模块  
  
```js    
import url from '@ohos.url'    
```  
    
## URLSearchParams<sup>(deprecated)</sup>    
URLSearchParams接口定义了一些处理URL查询字符串的实用方法，从API version 9开始废弃，建议使用[URLParams](#urlparams9)。    
从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.url.URLParams替代。  
 **系统能力:**  SystemCapability.Utils.Lang    
### append<sup>(deprecated)</sup>    
将新的键值对插入到查询字符串。  
 **调用形式：**     
- append(name: string, value: string): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.url.URLParams.append。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 需要插入搜索参数的键名。 |  
| value<sup>(deprecated)</sup> | string | true | 需要插入搜索参数的值。 |  
    
 **示例代码：**   
```ts    
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1bard=2');let paramsObject = new Url.URLSearchParams(urlObject.search.slice(1));paramsObject.append('fod', '3');    
```    
  
    
### delete<sup>(deprecated)</sup>    
删除指定名称的键值对。  
 **调用形式：**     
- delete(name: string): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.url.URLParams.delete。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 需要删除的键值名称。 |  
    
 **示例代码：**   
```ts    
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1bard=2');let paramsobject = new Url.URLSearchParams(urlObject.search.slice(1));paramsobject.delete('fod');    
```    
  
    
### getAll<sup>(deprecated)</sup>    
获取指定名称的所有键值对。  
 **调用形式：**     
- getAll(name: string): string[]  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.url.URLParams.getAll。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 指定的键值名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string[] | 返回指定名称的所有键值对。 |  
    
 **示例代码：**   
```ts    
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1bard=2');let params = new Url.URLSearchParams(urlObject.search.slice(1));params.append('fod', '3'); // Add a second value for the fod parameter.console.log(params.getAll('fod').toString()) // Output ["1","3"].    
```    
  
    
### entries<sup>(deprecated)</sup>    
返回一个ES6的迭代器，迭代器的每一项都是一个 JavaScript Array。Array的第一项是name，Array的第二项是value。  
 **调用形式：**     
- entries(): IterableIterator\<[string, string]>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.url.URLParams.entries。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<[string, string]> | 返回一个ES6的迭代器。 |  
    
 **示例代码：**   
```ts    
let searchParamsObject = new Url.URLSearchParams("keyName1=valueName1keyName2=valueName2");let iter: Iterable<Object[]> = searchParamsObject.entries();let pairs = Array.from(iter);for (let pair of pairs) { // Show keyName/valueName pairs  console.log(pair[0]+ ', '+ pair[1]);}    
```    
  
    
### forEach<sup>(deprecated)</sup>    
通过回调函数来遍历URLSearchParams实例对象上的键值对。  
 **调用形式：**     
- forEach(callbackFn: (value: string, key: string, searchParams: URLSearchParams) => void, thisArg?: Object): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.url.URLParams.forEach。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callbackFn<sup>(deprecated)</sup> | (value: string, key: string, searchParams: URLSearchParams) => void | true | 回调函数。 |  
| thisArg<sup>(deprecated)</sup> | Object | false | callbackFn被调用时用作this值，默认值是本对象。 |  
    
 **示例代码：**   
```ts    
const myURLObject = Url.URL.parseURL('https://developer.exampleUrl/?fod=1bard=2'); myURLObject.params.forEach((value, name, searchParams) => {      console.log(name, value, myURLObject.params === searchParams);});    
```    
  
    
### get<sup>(deprecated)</sup>    
获取指定名称对应的第一个值。  
 **调用形式：**     
- get(name: string): string | null  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.url.URLParams.get。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 指定键值对的名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | null | 返回第一个值。 |  
    
 **示例代码：**   
```ts    
let paramsObject = new Url.URLSearchParams('name=Jonathanage=18');let name = paramsObject.get("name"); // is the string "Jonathan"let age = paramsObject.get("age"); // is the string '18'    
```    
  
    
### has<sup>(deprecated)</sup>    
判断一个指定的键名对应的值是否存在。  
 **调用形式：**     
- has(name: string): boolean  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.url.URLParams.has。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 要查找的参数的键名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 是否存在相对应的key值，存在返回true，否则返回false。 |  
    
 **示例代码：**   
```ts    
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1bard=2');let paramsObject = new Url.URLSearchParams(urlObject.search.slice(1)); paramsObject.has('bard') === true;    
```    
  
    
### set<sup>(deprecated)</sup>    
将与name关联的URLSearchParams对象中的值设置为value。如果存在名称为name的键值对，请将第一个键值对的值设置为value并删除所有其他值。如果不是，则将键值对附加到查询字符串。  
 **调用形式：**     
- set(name: string, value: string): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.url.URLParams.set。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name<sup>(deprecated)</sup> | string | true | 将要设置的参数的键值名。 |  
| value<sup>(deprecated)</sup> | string | true | 所要设置的参数值。 |  
    
 **示例代码：**   
```ts    
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1bard=2');let paramsObject = new Url.URLSearchParams(urlObject.search.slice(1));paramsObject.set('baz', '3'); // Add a third parameter.    
```    
  
    
### sort<sup>(deprecated)</sup>    
对包含在此对象中的所有键值对进行排序，并返回undefined。排序顺序是根据键的Unicode代码点。该方法使用稳定的排序算法  
 **调用形式：**     
- sort(): void  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.url.URLParams.sort。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **示例代码：**   
```ts    
let searchParamsObject = new Url.URLSearchParams("c=3a=9b=4d=2"); // Create a test URLSearchParams objectsearchParamsObject.sort(); // Sort the key/value pairsconsole.log(searchParamsObject.toString()); // Display the sorted query string // Output a=9b=4c=3d=2    
```    
  
    
### keys<sup>(deprecated)</sup>    
返回一个所有键值对的name的ES6迭代器。  
 **调用形式：**     
- keys(): IterableIterator\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.url.URLParams.keys。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<string> | 返回一个所有键值对的name的ES6迭代器。 |  
    
 **示例代码：**   
```ts    
let searchParamsObject = new Url.URLSearchParams("key1=value1key2=value2"); // Create a URLSearchParamsObject object for testinglet keys = Array.from(searchParamsObject.keys());for (let key of keys) { // Output key-value pairs  console.log(key);}    
```    
  
    
### values<sup>(deprecated)</sup>    
返回一个所有键值对的value的ES6迭代器。  
 **调用形式：**     
- values(): IterableIterator\<string>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.url.URLParams.values。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<string> | 返回一个所有键值对的value的ES6迭代器。 |  
    
 **示例代码：**   
```ts    
let searchParams = new Url.URLSearchParams("key1=value1key2=value2"); // Create a URLSearchParamsObject object for testinglet values = Array.from(searchParams.values());for (let value of values) {  console.log(value);}    
```    
  
    
### [Symbol.iterator]<sup>(deprecated)</sup>    
返回一个ES6的迭代器，迭代器的每一项都是一个 JavaScript Array。Array的第一项是name，Array的第二项是value。  
 **调用形式：**     
- [Symbol.iterator](): IterableIterator\<[string, string]>  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.url.URLParams.Symbol.iterator。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<[string, string]> | 返回一个ES6的迭代器。 |  
    
 **示例代码：**   
```ts    
const paramsObject = new Url.URLSearchParams('fod=bayedg=bap');let iter: Iterable<Object[]> = paramsObject[Symbol.iterator]();let pairs = Array.from(iter);for (let pair of pairs) {  console.log(pair[0] + ', ' + pair[1]);}    
```    
  
    
### toString<sup>(deprecated)</sup>    
返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。  
 **调用形式：**     
- toString(): string  
  
 **废弃说明：** 从API version 9 开始废弃。替代接口: ohos.url.URLParams.toString。  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。 |  
    
 **示例代码：**   
```ts    
let url = new Url.URL('https://developer.exampleUrl/?fod=1bard=2');let params = new Url.URLSearchParams(url.search.slice(1)); params.append('fod', '3');console.log(params.toString());    
```    
  
    
## URLParams<sup>(9+)</sup>    
URLParams接口定义了一些处理URL查询字符串的实用方法。  
 **系统能力:**  SystemCapability.Utils.Lang    
### append<sup>(9+)</sup>    
将新的键值对插入到查询字符串。  
 **调用形式：**     
- append(name: string, value: string): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 需要插入搜索参数的键名。 |  
| value | string | true | 需要插入搜索参数的值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let urlObject = Url.URL.parseURL('https://developer.exampleUrl/?fod=1bard=2');let paramsObject = new Url.URLParams(urlObject.search.slice(1));paramsObject.append('fod', '3');    
```    
  
    
### delete<sup>(9+)</sup>    
删除指定名称的键值对。  
 **调用形式：**     
- delete(name: string): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 需要删除的键值名称。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let urlObject = Url.URL.parseURL('https://developer.exampleUrl/?fod=1bard=2');let paramsObject = new Url.URLParams(urlObject.search.slice(1));paramsObject.delete('fod');    
```    
  
    
### getAll<sup>(9+)</sup>    
获取指定名称的所有键对应值的集合。  
 **调用形式：**     
- getAll(name: string): string[]  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 指定的键值名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string[] | 返回指定名称的所有键对应值的集合。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let urlObject = Url.URL.parseURL('https://developer.exampleUrl/?fod=1bard=2');let params = new Url.URLParams(urlObject.search.slice(1));params.append('fod', '3'); // Add a second value for the fod parameter.console.log(params.getAll('fod').toString()) // Output ["1","3"].    
```    
  
    
### entries<sup>(9+)</sup>    
返回一个ES6的迭代器，迭代器的每一项都是一个 JavaScript Array。Array的第一项是name，Array的第二项是value。  
 **调用形式：**     
- entries(): IterableIterator\<[string, string]>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<[string, string]> | 返回一个ES6的迭代器。 |  
    
 **示例代码：**   
```ts    
let searchParamsObject = new Url.URLParams("keyName1=valueName1keyName2=valueName2");let pair:Iterable<Object[]> = searchParamsObject.entries();let arrayValue = Array.from(pair);for (let pair of arrayValue) { // Show keyName/valueName pairs  console.log(pair[0]+ ', '+ pair[1]);}    
```    
  
    
### forEach<sup>(9+)</sup>    
通过回调函数来遍历URLSearchParams实例对象上的键值对。  
 **调用形式：**     
- forEach(callbackFn: (value: string, key: string, searchParams: URLParams) => void, thisArg?: Object): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| callbackFn | (value: string, key: string, searchParams: URLParams) => void | true | 回调函数。 |  
| thisArg | Object | false | callbackFn被调用时用作this值，默认值是本对象。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
const myURLObject = new Url.URL('https://developer.exampleUrl/?fod=1bard=2'); myURLObject.searchParams.forEach((value, name, searchParams) => {      console.log(name, value, myURLObject.searchParams === searchParams);});    
```    
  
    
### get<sup>(9+)</sup>    
获取指定名称对应的第一个值。  
 **调用形式：**     
- get(name: string): string | null  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 指定键值对的名称。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | null | 返回第一个值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let paramsObject = new Url.URLParams('name=Jonathanage=18'); let name = paramsObject.get("name"); // is the string "Jonathan" let age = paramsObject.get("age"); // is the string "18"    
```    
  
    
### has<sup>(9+)</sup>    
判断一个指定的键名对应的值是否存在。  
 **调用形式：**     
- has(name: string): boolean  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 要查找的参数的键名。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| boolean | 是否存在相对应的key值，存在返回true，否则返回false。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let urlObject = Url.URL.parseURL('https://developer.exampleUrl/?fod=1bard=2');let paramsObject = new Url.URLParams(urlObject.search.slice(1)); let result = paramsObject.has('bard');    
```    
  
    
### set<sup>(9+)</sup>    
将与name关联的URLSearchParams对象中的值设置为value。如果存在名称为name的键值对，请将第一个键值对的值设置为value并删除所有其他值。如果不是，则将键值对附加到查询字符串。  
 **调用形式：**     
- set(name: string, value: string): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| name | string | true | 将要设置的参数的键值名。 |  
| value | string | true | 所要设置的参数值。 |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
    
 **示例代码：**   
```ts    
let urlObject = Url.URL.parseURL('https://developer.exampleUrl/?fod=1bard=2');let paramsObject = new Url.URLParams(urlObject.search.slice(1));paramsObject.set('baz', '3'); // Add a third parameter.    
```    
  
    
### sort<sup>(9+)</sup>    
对包含在此对象中的所有键值对进行排序，并返回undefined。排序顺序是根据键的Unicode代码点。该方法使用稳定的排序算法 （即，将保留具有相等键的键值对之间的相对顺序）。  
 **调用形式：**     
- sort(): void  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **示例代码：**   
```ts    
let searchParamsObject = new Url.URLParams("c=3a=9b=4d=2"); // Create a test URLSearchParams objectsearchParamsObject.sort(); // Sort the key/value pairsconsole.log(searchParamsObject.toString()); // Display the sorted query string // Output a=9b=4c=3    
```    
  
    
### keys<sup>(9+)</sup>    
返回一个所有键值对的name的ES6迭代器。  
 **调用形式：**     
- keys(): IterableIterator\<string>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<string> | 返回一个所有键值对的name的ES6迭代器。 |  
    
 **示例代码：**   
```ts    
let searchParamsObject = new Url.URLParams("key1=value1key2=value2"); // Create a URLSearchParamsObject object for testinglet keys = Array.from(searchParamsObject.keys());for (let key of keys) { // Output key-value pairs  console.log(key);}    
```    
  
    
### values<sup>(9+)</sup>    
返回一个所有键值对的value的ES6迭代器。  
 **调用形式：**     
- values(): IterableIterator\<string>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<string> | 返回一个所有键值对的value的ES6迭代器。 |  
    
 **示例代码：**   
```ts    
let searchParams = new Url.URLParams("key1=value1key2=value2"); // Create a URLSearchParamsObject object for testinglet values = Array.from(searchParams.values());for (let value of values) {  console.log(value);}    
```    
  
    
### [Symbol.iterator]<sup>(9+)</sup>    
返回一个ES6的迭代器，迭代器的每一项都是一个 JavaScript Array。Array的第一项是name，Array的第二项是value。  
 **调用形式：**     
- [Symbol.iterator](): IterableIterator\<[string, string]>  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| IterableIterator<[string, string]> | 返回一个ES6的迭代器。 |  
    
 **示例代码：**   
```ts    
const paramsObject = new Url.URLParams('fod=bayedg=bap');let iter: Iterable<Object[]> = paramsObject[Symbol.iterator]();let pairs = Array.from(iter);for (let pair of pairs) {  console.log(pair[0] + ', ' + pair[1]);}    
```    
  
    
### toString<sup>(9+)</sup>    
返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。  
 **调用形式：**     
- toString(): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。 |  
    
 **示例代码：**   
```ts    
let url = Url.URL.parseURL('https://developer.exampleUrl/?fod=1bard=2');let params = new Url.URLParams(url.search.slice(1)); params.append('fod', '3');console.log(params.toString());    
```    
  
    
## URL    
用于解析、构造、编码对应的URL字符串。  
 **系统能力:**  SystemCapability.Utils.Lang    
### 属性    
 **系统能力:**  SystemCapability.Utils.Lang    
| 名称 | 类型 | 只读 | 必填 | 说明 |  
| --------| --------| --------| --------| --------|  
| hash | string | false | true | 获取和设置URL的片段部分。 |  
| host | string | false | true | 获取和设置URL的主机部分。 |  
| hostname | string | false | true | 获取和设置URL的主机名部分，不带端口。 |  
| href | string | false | true | 获取和设置序列化的URL。 |  
| origin | string | true | true | 获取URL源的只读序列化。 |  
| password | string | false | true | 获取和设置URL的密码部分。 |  
| pathname | string | false | true | 获取和设置URL的路径部分。 |  
| port | string | false | true | 获取和设置URL的端口部分。 |  
| protocol | string | false | true | 获取和设置URL的协议部分。 |  
| search | string | false | true | 获取和设置URL的序列化查询部分。 |  
| searchParams<sup>(deprecated)</sup> | URLSearchParams | true | true | 从API version 7 开始支持，从API version 9 开始废弃。建议使用ohos.url.URL.params替代。<br>获取URLSearchParams表示URL查询参数的对象。<br/>- **说明：** 此属性从API version 7开始支持，从API version 9开始被废弃。建议使用params<sup>9+</sup>替代。 |  
| params<sup>(9+)</sup> | URLParams | true | true | 获取URLParams表示URL查询参数的对象。 |  
| username | string | false | true | 获取和设置URL的用户名部分。 |  
    
### parseURL<sup>(9+)</sup>    
URL静态成员函数。  
 **调用形式：**     
- static parseURL(url: string, base?: string | URL): URL  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **参数：**     
| 参数名 | 类型 | 必填 | 说明 |  
| --------| --------| --------| --------|  
| url | string | true | 入参对象。 |  
| base | string | false | 入参字符串或者对象。<br/>- string：字符串<br/>- URL：字符串或对象<br/>- 默认值是空字符串或空对象。 |  
    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| URL |  |  
    
    
 **错误码：**     
| 错误码ID | 错误信息 |  
| --------| --------|  
| 401 |  |  
| 10200002 | Invalid url string. |  
    
 **示例代码：**   
```ts    
let mm = 'https://username:password@host:8080';let url = Url.URL.parseURL(mm); let result = url.toString(); // Output 'https://username:password@host:8080/'    
```    
  
    
### toString    
将解析过后的URL转化为字符串。  
 **调用形式：**     
- toString(): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 用于返回网址的字符串序列化。 |  
    
 **示例代码：**   
```ts    
const url = Url.URL.parseURL('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');let result = url.toString();    
```    
  
    
### toJSON    
将解析过后的URL转化为JSON字符串。  
 **调用形式：**     
- toJSON(): string  
  
 **系统能力:**  SystemCapability.Utils.Lang    
 **回调或返回值：**     
| 类型 | 说明 |  
| --------| --------|  
| string | 用于返回网址的字符串序列化。 |  
    
 **示例代码：**   
```ts    
const url = Url.URL.parseURL('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');let result = url.toJSON();    
```    
  
