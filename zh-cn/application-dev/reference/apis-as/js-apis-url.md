# @ohos.url (URL字符串解析)

URL代表着是统一资源定位符，本模块提供了常用的工具函数，实现了处理URL字符串[URLParams](#urlparams9)和构造[URL](#url)对象等功能。

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import Url from '@ohos.url'
```
## URLParams<sup>9+</sup>

URLParams接口定义了一些处理URL查询字符串的实用方法。

### constructor<sup>9+</sup>

constructor(init?: string[][] | Record&lt;string, string&gt; | string | URLParams)

URLParams的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| init | string[][] \| Record&lt;string, string&gt; \| string \| URLParams | 否 | 入参对象。<br/>- string[][]：字符串二维数组<br/>- Record&lt;string, string&gt;：对象列表<br/>- string：字符串<br/>- URLParams：对象<br/>- 默认值：null。 |

**示例：**

```ts
let objectParams = new Url.URLParams([ ['user1', 'abc1'], ['query2', 'first2'], ['query3', 'second3'] ]);
let objectParams1 = new Url.URLParams({"fod" : '1' , "bard" : '2'});
let objectParams2 = new Url.URLParams('?fod=1&bard=2');
let urlObject = Url.URL.parseURL('https://developer.mozilla.org/?fod=1&bard=2');
let params = new Url.URLParams(urlObject.search);
```


### append<sup>9+</sup>

append(name: string, value: string): void

将新的键值对插入到查询字符串。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 需要插入搜索参数的键名。 |
| value | string | 是 | 需要插入搜索参数的值。 |

**示例：**

```ts
let urlObject = Url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new Url.URLParams(urlObject.search.slice(1));
paramsObject.append('fod', '3');
```


### delete<sup>9+</sup>

delete(name: string): void

删除指定名称的键值对。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 需要删除的键值名称。 |

**示例：**

```ts
let urlObject = Url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new Url.URLParams(urlObject.search.slice(1));
paramsObject.delete('fod');
```


### getAll<sup>9+</sup>

getAll(name: string): string[]

获取指定名称的所有键对应值的集合。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 指定的键值名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string[] | 返回指定名称的所有键对应值的集合。 |

**示例：**

```ts
let urlObject = Url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
let params = new Url.URLParams(urlObject.search.slice(1));
params.append('fod', '3'); // Add a second value for the fod parameter.
console.log(params.getAll('fod').toString()) // Output ["1","3"].
```


### entries<sup>9+</sup>

entries(): IterableIterator<[string, string]>

返回一个ES6的迭代器，迭代器的每一项都是一个 JavaScript Array。Array的第一项是name，Array的第二项是value。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[string, string]&gt; | 返回一个ES6的迭代器。 |

**示例：**

```ts
let searchParamsObject = new Url.URLParams("keyName1=valueName1&keyName2=valueName2");
let pair:Iterable<Object[]> = searchParamsObject.entries();
let arrayValue = Array.from(pair);
for (let pair of arrayValue) { // Show keyName/valueName pairs
  console.log(pair[0]+ ', '+ pair[1]);
}
```


### forEach<sup>9+</sup>

forEach(callbackFn: (value: string, key: string, searchParams: URLParams) => void, thisArg?: Object): void

通过回调函数来遍历URLSearchParams实例对象上的键值对。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 回调函数。 |
| thisArg | Object | 否 | callbackFn被调用时用作this值，默认值是本对象。 |

**表1** callbackFn的参数说明

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string | 是 | 当前遍历到的键值。 |
| key | string | 是 | 当前遍历到的键名。 |
| searchParams | [URLParams](#urlparams9) | 是 | 当前调用forEach方法的实例对象。 |

**示例：**

```ts
const myURLObject = Url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2'); 
myURLObject.params.forEach((value, name, searchParams) => {  
    console.log(name, value, myURLObject.params === searchParams);
});
```


### get<sup>9+</sup>

get(name: string): string | null

获取指定名称对应的第一个值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 指定键值对的名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回第一个值。 |
| null | 如果没找到，返回 null。 |

**示例：**

```ts
let paramsObject = new Url.URLParams('name=Jonathan&age=18'); 
let name = paramsObject.get("name"); // is the string "Jonathan" 
let age = paramsObject.get("age"); // is the string "18"
```


### has<sup>9+</sup>

has(name: string): boolean

判断一个指定的键名对应的值是否存在。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 要查找的参数的键名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 是否存在相对应的key值，存在返回true，否则返回false。 |

**示例：**

```ts
let urlObject = Url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new Url.URLParams(urlObject.search.slice(1)); 
let result = paramsObject.has('bard');
```


### set<sup>9+</sup>

set(name: string, value: string): void

将与name关联的URLSearchParams对象中的值设置为value。如果存在名称为name的键值对，请将第一个键值对的值设置为value并删除所有其他值。如果不是，则将键值对附加到查询字符串。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 将要设置的参数的键值名。 |
| value | string | 是 | 所要设置的参数值。 |

**示例：**

```ts
let urlObject = Url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new Url.URLParams(urlObject.search.slice(1));
paramsObject.set('baz', '3'); // Add a third parameter.
```


### sort<sup>9+</sup>

sort(): void

对包含在此对象中的所有键值对进行排序，并返回undefined。排序顺序是根据键的Unicode代码点。该方法使用稳定的排序算法 （即，将保留具有相等键的键值对之间的相对顺序）。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
let searchParamsObject = new Url.URLParams("c=3&a=9&b=4&d=2"); // Create a test URLSearchParams object
searchParamsObject.sort(); // Sort the key/value pairs
console.log(searchParamsObject.toString()); // Display the sorted query string // Output a=9&b=4&c=3&d=2
```


### keys<sup>9+</sup>

keys(): IterableIterator&lt;string&gt;

返回一个所有键值对的name的ES6迭代器。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;string&gt; | 返回一个所有键值对的name的ES6迭代器。 |

**示例：**

```ts
let searchParamsObject = new Url.URLParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
let keys = Array.from(searchParamsObject.keys());
for (let key of keys) { // Output key-value pairs
  console.log(key);
}
```


### values<sup>9+</sup>

values(): IterableIterator&lt;string&gt;

返回一个所有键值对的value的ES6迭代器。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;string&gt; | 返回一个所有键值对的value的ES6迭代器。 |

**示例：**

```ts
let searchParams = new Url.URLParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
let values = Array.from(searchParams.values());
for (let value of values) {
  console.log(value);
}
```


### [Symbol.iterator]<sup>9+</sup>

[Symbol.iterator]\(): IterableIterator&lt;[string, string]&gt;

返回一个ES6的迭代器，迭代器的每一项都是一个 JavaScript Array。Array的第一项是name，Array的第二项是value。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[string, string]&gt; | 返回一个ES6的迭代器。 |

**示例：**

```ts
const paramsObject = new Url.URLParams('fod=bay&edg=bap');
let iter: Iterable<Object[]> = paramsObject[Symbol.iterator]();
let pairs = Array.from(iter);
for (let pair of pairs) {
  console.log(pair[0] + ', ' + pair[1]);
}
```


### tostring<sup>9+</sup>

toString(): string

返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。 |

**示例：**

```ts
let url = Url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
let params = new Url.URLParams(url.search.slice(1)); 
params.append('fod', '3');
console.log(params.toString());
```

## URL

用于解析、构造、编码对应的URL字符串。

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| hash | string | 是 | 是 | 获取和设置URL的片段部分。 |
| host | string | 是 | 是 | 获取和设置URL的主机部分。 |
| hostname | string | 是 | 是 | 获取和设置URL的主机名部分，不带端口。 |
| href | string | 是 | 是 | 获取和设置序列化的URL。 |
| origin | string | 是 | 否 | 获取URL源的只读序列化。 |
| password | string | 是 | 是 | 获取和设置URL的密码部分。 |
| pathname | string | 是 | 是 | 获取和设置URL的路径部分。 |
| port | string | 是 | 是 | 获取和设置URL的端口部分。 |
| protocol | string | 是 | 是 | 获取和设置URL的协议部分。 |
| search | string | 是 | 是 | 获取和设置URL的序列化查询部分。 |
| params<sup>9+</sup> | [URLParams](#urlparams9) | 是 | 否 | 获取URLParams表示URL查询参数的对象。 |
| username | string | 是 | 是 | 获取和设置URL的用户名部分。 |


### constructor<sup>9+</sup>

constructor()

URL的无参构造函数。parseURL调用后返回一个URL对象，不单独使用。

**系统能力：** SystemCapability.Utils.Lang

### parseURL<sup>9+</sup>

static parseURL(url : string, base?: string | URL): URL

URL静态成员函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| url | string | 是 | 入参对象。 |
| base | string \| URL | 否 | 入参字符串或者对象。<br/>- string：字符串<br/>- URL：字符串或对象<br/>- 默认值是空字符串或空对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200002 | Invalid url string. |


**示例：**

```ts
let mm = 'https://username:password@host:8080';
let url = Url.URL.parseURL(mm); 
let result = url.toString(); // Output 'https://username:password@host:8080/'
```

### tostring

toString(): string

将解析过后的URL转化为字符串。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 用于返回网址的字符串序列化。 |

**示例：**

```ts
const url = Url.URL.parseURL('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
let result = url.toString();
```

### toJSON

toJSON(): string

将解析过后的URL转化为JSON字符串。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 用于返回网址的字符串序列化。 |

**示例：**
```ts
const url = Url.URL.parseURL('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
let result = url.toJSON();
```