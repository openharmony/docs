# URL字符串解析

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```
import Url from '@ohos.url' 
```

## URLSearchParams


### constructor

constructor(init?: string[][] | Record&lt;string, string&gt; | string | URLSearchParams)

URLSearchParams的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| init | string[][]&nbsp;\|&nbsp;Record&lt;string,&nbsp;string&gt;&nbsp;\|&nbsp;string&nbsp;\|&nbsp;URLSearchParams | 否 | 入参对象。<br/>-&nbsp;string[][]：字符串二维数组<br/>-&nbsp;Record&lt;string,&nbsp;string&gt;：对象列表<br/>-&nbsp;string：字符串<br/>-&nbsp;URLSearchParams：对象 |

**示例：**

```js
var objectParams = new Url.URLSearchParams([ ['user1', 'abc1'], ['query2', 'first2'], ['query3', 'second3'] ]);
var objectParams1 = new Url.URLSearchParams({"fod" : 1 , "bard" : 2});
var objectParams2 = new Url.URLSearchParams('?fod=1&bard=2');
var urlObject = new Url.URL('https://developer.mozilla.org/?fod=1&bard=2');
var params = new Url.URLSearchParams(urlObject.search);
```


### append

append(name: string, value: string): void

将新的键值对插入到查询字符串。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 需要插入搜索参数的键名。 |
| value | string | 是 | 需要插入搜索参数的值。 |

**示例：**

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new Url.URLSearchParams(urlObject.search.slice(1));
paramsObject.append('fod', 3);
```


### delete

delete(name: string): void

删除指定名称的键值对。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 需要删除的键值名称。 |

**示例：**

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsobject = new Url.URLSearchParams(urlObject.search.slice(1));
paramsobject.delete('fod');
```


### getAll

getAll(name: string): string[]

获取指定名称的所有键值对。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 指定的键值名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string[] | 返回指定名称的所有键值对。 |

**示例：**

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2'); 
let paramsObject = new Url.URLSearchParams(urlObject.search.slice(1)); 
paramsObject.append('fod', 3); // Add a second value for the fod parameter.
console.log(params.getAll('fod')) // Output ["1","3"].
```


### entries

entries(): IterableIterator<[string, string]>

返回一个ES6的迭代器，迭代器的每一项都是一个 JavaScript Array。Array的第一项是name，Array的第二项是value。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[string,&nbsp;string]&gt; | 返回一个ES6的迭代器。 |

**示例：**

```js
var searchParamsObject = new Url.URLSearchParams("keyName1=valueName1&keyName2=valueName2"); 
for (var pair of searchParamsObject .entries()) { // Show keyName/valueName pairs
    console.log(pair[0]+ ', '+ pair[1]);
}
```


### forEach

forEach(callbackfn: (value: string, key: string, searchParams: this) => void, thisArg?: Object): void

通过回调函数来遍历URLSearchParams实例对象上的键值对。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackfn | function | 是 | 回调函数。 |
| thisArg | Object | 否 | callbackfn被调用时用作this值 |

**表1** callbackfn的参数说明

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string | 是 | 当前遍历到的键值。 |
| key | string | 是 | 当前遍历到的键名。 |
| searchParams | Object | 是 | 当前调用forEach方法的实例对象。 |

**示例：**

```js
const myURLObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2'); 
myURLObject.searchParams.forEach((value, name, searchParams) => {  
    console.log(name, value, myURLObject.searchParams === searchParams);
});
```


### get

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
| null | 如果没找到，返回&nbsp;null。 |

**示例：**

```js
var paramsOject = new Url.URLSearchParams(document.location.search.substring(1)); 
var name = paramsOject.get("name"); // is the string "Jonathan" 
var age = parseInt(paramsOject.get("age"), 10); // is the number 18
var address = paramsOject.get("address"); // null
```


### has

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

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new Url.URLSearchParams(urlObject.search.slice(1)); 
paramsObject.has('bard') === true;
```


### set

set(name: string, value: string): void

将与name关联的URLSearchParams对象中的值设置为value。如果存在名称为name的键值对，请将第一个键值对的值设置为value并删除所有其他值。如果不是，则将键值对附加到查询字符串。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 将要设置的参数的键值名。 |
| value | string | 是 | 所要设置的参数值。 |

**示例：**

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new Url.URLSearchParams(urlObject.search.slice(1));
paramsObject.set('baz', 3); // Add a third parameter.
```


### sort

sort(): void

对包含在此对象中的所有键值对进行排序，并返回undefined。排序顺序是根据键的Unicode代码点。该方法使用稳定的排序算法 （即，将保留具有相等键的键值对之间的相对顺序）。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```js
var searchParamsObject = new Url.URLSearchParams("c=3&a=9&b=4&d=2"); // Create a test URLSearchParams object
searchParamsObject.sort(); // Sort the key/value pairs
console.log(searchParamsObject.toString()); // Display the sorted query string // Output a=9&b=2&c=3&d=4
```


### keys

keys(): IterableIterator&lt;string&gt;

返回一个所有键值对的name的ES6迭代器。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;string&gt; | 返回一个所有键值对的name的ES6迭代器。 |

**示例：**

```js
var searchParamsObject = new Url.URLSearchParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
for (var key of searchParamsObject .keys()) { // Output key-value pairs
    console.log(key);
}
```


### values

values(): IterableIterator&lt;string&gt;

返回一个所有键值对的value的ES6迭代器。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;string&gt; | 返回一个所有键值对的value的ES6迭代器。 |

**示例：**

```js
var searchParams = new Url.URLSearchParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
for (var value of searchParams.values()) { 
    console.log(value);
}
```


### [Symbol.iterator]

[Symbol.iterator]\(): IterableIterator&lt;[string, string]&gt;

返回一个ES6的迭代器，迭代器的每一项都是一个 JavaScript Array。Array的第一项是name，Array的第二项是value。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[string,&nbsp;string]&gt; | 返回一个ES6的迭代器。 |

**示例：**

```js
const paramsObject = new Url.URLSearchParams('fod=bay&edg=bap');
for (const [name, value] of paramsObject) { 
    console.log(name, value); 
} 
```


### tostring

toString(): string

返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。 |

**示例：**

```js
let url = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let params = new Url.URLSearchParams(url.search.slice(1)); 
params.append('fod', 3);
console.log(params.toString());
```


## URL

### 属性

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Utils.Lang

| 名称 | 参数类型 | 可读 | 可写 | 说明 |
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
| searchParams | URLsearchParams | 是 | 否 | 获取URLSearchParams表示URL查询参数的对象。 |
| username | string | 是 | 是 | 获取和设置URL的用户名部分。 |


### constructor

constructor(url: string, base?: string | URL)

URL的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| url | string | 是 | 入参对象。 |
| base | string&nbsp;\|&nbsp;URL | 否 | 入参字符串或者对象。<br/>-&nbsp;string：字符串<br/>-&nbsp;URL：字符串或对象 |

**示例：**

```js
var mm = 'http://username:password@host:8080';
var a = new Url.URL("/", mm); // Output 'http://username:password@host:8080/';
var b = new Url.URL(mm); // Output 'http://username:password@host:8080/';
new Url.URL('path/path1', b); // Output 'http://username:password@host:8080/path/path1';
var c = new Url.URL('/path/path1', b);  // Output 'http://username:password@host:8080/path/path1'; 
new Url.URL('/path/path1', c); // Output 'http://username:password@host:8080/path/path1';
new Url.URL('/path/path1', a); // Output 'http://username:password@host:8080/path/path1';
new Url.URL('/path/path1', "https://www.exampleUrl/fr-FR/toto"); // Output https://www.exampleUrl/path/path1
new Url.URL('/path/path1', ''); // Raises a TypeError exception as '' is not a valid URL
new Url.URL('/path/path1'); // Raises a TypeError exception as '/path/path1' is not a valid URL
new Url.URL('http://www.shanxi.com', ); // Output http://www.shanxi.com/
new Url.URL('http://www.shanxi.com', b); // Output http://www.shanxi.com/
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

```js
const url = new Url.URL('http://username:password@host:8080/directory/file?query=pppppp#qwer=da');
url.toString()
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
```js
const url = new Url.URL('http://username:password@host:8080/directory/file?query=pppppp#qwer=da');
url.toJSON()
```
