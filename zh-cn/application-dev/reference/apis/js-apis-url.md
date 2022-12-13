# URL字符串解析

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```
import Url from '@ohos.url' 
```
## URLParams<sup>9+</sup>


### constructor<sup>9+</sup>

constructor(init?: string[][] | Record&lt;string, string&gt; | string | URLSearchParams)

URLParams的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| init | string[][] \| Record&lt;string, string&gt; \| string \| URLSearchParams | 否 | 入参对象。<br/>- string[][]：字符串二维数组<br/>- Record&lt;string, string&gt;：对象列表<br/>- string：字符串<br/>- URLSearchParams：对象 |

**示例：**

```js
let objectParams = new Url.URLParams([ ['user1', 'abc1'], ['query2', 'first2'], ['query3', 'second3'] ]);
let objectParams1 = new Url.URLParams({"fod" : '1' , "bard" : '2'});
let objectParams2 = new Url.URLParams('?fod=1&bard=2');
let urlObject = new Url.URL('https://developer.mozilla.org/?fod=1&bard=2');
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

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
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

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsobject = new Url.URLParams(urlObject.search.slice(1));
paramsobject.delete('fod');
```


### getAll<sup>9+</sup>

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

```js
let searchParamsObject = new Url.URLParams("keyName1=valueName1&keyName2=valueName2"); 
for (var pair of searchParamsObject .entries()) { // Show keyName/valueName pairs
    console.log(pair[0]+ ', '+ pair[1]);
}
```


### forEach<sup>9+</sup>

forEach(callbackFn: (value: string, key: string, searchParams: this) => void, thisArg?: Object): void

通过回调函数来遍历URLSearchParams实例对象上的键值对。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 回调函数。 |
| thisArg | Object | 否 | callbackFn被调用时用作this值 |

**表1** callbackFn的参数说明

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

```js
let paramsObject = new Url.URLParams('name=Jonathan&age=18'); 
let name = paramsObject.get("name"); // is the string "Jonathan" 
let age = parseInt(paramsObject.get("age"), 10); // is the number 18
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

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new Url.URLParams(urlObject.search.slice(1)); 
paramsObject.has('bard') === true;
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

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new Url.URLParams(urlObject.search.slice(1));
paramsObject.set('baz', '3'); // Add a third parameter.
```


### sort<sup>9+</sup>

sort(): void

对包含在此对象中的所有键值对进行排序，并返回undefined。排序顺序是根据键的Unicode代码点。该方法使用稳定的排序算法 （即，将保留具有相等键的键值对之间的相对顺序）。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```js
let searchParamsObject = new Url.URLParams("c=3&a=9&b=4&d=2"); // Create a test URLSearchParams object
searchParamsObject.sort(); // Sort the key/value pairs
console.log(searchParamsObject.toString()); // Display the sorted query string // Output a=9&b=2&c=3&d=4
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

```js
let searchParamsObject = new Url.URLParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
for (var key of searchParamsObject .keys()) { // Output key-value pairs
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

```js
let searchParams = new Url.URLParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
for (var value of searchParams.values()) {
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

```js
const paramsObject = new Url.URLParams('fod=bay&edg=bap');
for (const [name, value] of paramsObject) {
    console.log(name, value); 
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

```js
let url = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let params = new Url.URLParams(url.search.slice(1)); 
params.append('fod', '3');
console.log(params.toString());
```

## URL

### 属性

**系统能力：** 以下各项对应的系统能力均为SystemCapability.Utils.Lang

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
| searchParams | URLSearchParams | 是 | 否 | 获取URLSearchParams表示URL查询参数的对象。 |
| URLParams | URLParams | 是 | 否 | 获取URLParams表示URL查询参数的对象。 |
| username | string | 是 | 是 | 获取和设置URL的用户名部分。 |

### constructor<sup>(deprecated)</sup>

constructor(url: string, base?: string | URL)

URL的构造函数。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[parseURL<sup>9+</sup>](#parseurl9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| url | string | 是 | 入参对象。 |
| base | string \| URL | 否 | 入参字符串或者对象。<br/>- string：字符串<br/>- URL：字符串或对象 |

**示例：**

```js
let mm = 'http://username:password@host:8080';
let a = new Url.URL("/", mm); // Output 'http://username:password@host:8080/';
let b = new Url.URL(mm); // Output 'http://username:password@host:8080/';
new Url.URL('path/path1', b); // Output 'http://username:password@host:8080/path/path1';
let c = new Url.URL('/path/path1', b);  // Output 'http://username:password@host:8080/path/path1';
new Url.URL('/path/path1', c); // Output 'http://username:password@host:8080/path/path1';
new Url.URL('/path/path1', a); // Output 'http://username:password@host:8080/path/path1';
new Url.URL('/path/path1', "https://www.exampleUrl/fr-FR/toto"); // Output https://www.exampleUrl/path/path1
new Url.URL('/path/path1', ''); // Raises a TypeError exception as '' is not a valid URL
new Url.URL('/path/path1'); // Raises a TypeError exception as '/path/path1' is not a valid URL
new Url.URL('https://www.example.com', ); // Output https://www.example.com/
new Url.URL('https://www.example.com', b); // Output https://www.example.com/
```

### parseURL<sup>9+</sup>

static parseURL(url : string, base?: string | URL): URL

URL静态成员函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| url | string | 是 | 入参对象。 |
| base | string \| URL | 否 | 入参字符串或者对象。<br/>- string：字符串<br/>- URL：字符串或对象 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200002 | Invalid url string. |

**示例：**

```js
let mm = 'http://username:password@host:8080';
Url.URL.parseURL(mm); // Output 'http://username:password@host:8080/';
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
url.toString();
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
url.toJSON();
```

## URLSearchParams<sup>(deprecated)</sup>

### constructor<sup>(deprecated)</sup>

constructor(init?: string[][] | Record&lt;string, string&gt; | string | URLSearchParams)

URLSearchParams的构造函数。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams<sup>9+</sup>](#constructor9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| init | string[][] \| Record&lt;string, string&gt; \| string \| URLSearchParams | 否 | 入参对象。<br/>- string[][]：字符串二维数组<br/>- Record&lt;string, string&gt;：对象列表<br/>- string：字符串<br/>- URLSearchParams：对象 |

**示例：**

```js
let objectParams = new Url.URLSearchParams([ ['user1', 'abc1'], ['query2', 'first2'], ['query3', 'second3'] ]);
let objectParams1 = new Url.URLSearchParams({"fod" : '1' , "bard" : '2'});
let objectParams2 = new Url.URLSearchParams('?fod=1&bard=2');
let urlObject = new Url.URL('https://developer.mozilla.org/?fod=1&bard=2');
let params = new Url.URLSearchParams(urlObject.search);
```

### append<sup>(deprecated)</sup>

append(name: string, value: string): void

将新的键值对插入到查询字符串。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams<sup>9+</sup>.append<sup>9+</sup>](#append9)替代。

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
paramsObject.append('fod', '3');
```

### delete<sup>(deprecated)</sup>

delete(name: string): void

删除指定名称的键值对。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams<sup>9+</sup>.delete<sup>9+</sup>](#delete9)替代。

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

### getAll<sup>(deprecated)</sup>

getAll(name: string): string[]

获取指定名称的所有键值对。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams<sup>9+</sup>.getAll<sup>9+</sup>](#getall9)替代。

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
let params = new Url.URLSearchParams(urlObject.search.slice(1));
params.append('fod', '3'); // Add a second value for the fod parameter.
console.log(params.getAll('fod').toString()) // Output ["1","3"].
```

### entries<sup>(deprecated)</sup>

entries(): IterableIterator<[string, string]>

返回一个ES6的迭代器，迭代器的每一项都是一个 JavaScript Array。Array的第一项是name，Array的第二项是value。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams<sup>9+</sup>.entries<sup>9+</sup>](#entries9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[string, string]&gt; | 返回一个ES6的迭代器。 |

**示例：**

```js
let searchParamsObject = new Url.URLSearchParams("keyName1=valueName1&keyName2=valueName2"); 
for (var pair of searchParamsObject .entries()) { // Show keyName/valueName pairs
    console.log(pair[0]+ ', '+ pair[1]);
}
```


### forEach<sup>(deprecated)</sup>

forEach(callbackFn: (value: string, key: string, searchParams: this) => void, thisArg?: Object): void

通过回调函数来遍历URLSearchParams实例对象上的键值对。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams<sup>9+</sup>.forEach<sup>9+</sup>](#foreach9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 回调函数。 |
| thisArg | Object | 否 | callbackFn被调用时用作this值 |

**表1** callbackFn的参数说明

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


### get<sup>(deprecated)</sup>

get(name: string): string | null

获取指定名称对应的第一个值。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams<sup>9+</sup>.get<sup>9+</sup>](#get9)替代。

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

```js
let paramsObject = new Url.URLSearchParams('name=Jonathan&age=18'); 
let name = paramsObject.get("name"); // is the string "Jonathan" 
let age = parseInt(paramsObject.get("age"), 10); // is the number 18
```


### has<sup>(deprecated)</sup>

has(name: string): boolean

判断一个指定的键名对应的值是否存在。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams<sup>9+</sup>.has<sup>9+</sup>](#has9)替代。

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


### set<sup>(deprecated)</sup>

set(name: string, value: string): void

将与name关联的URLSearchParams对象中的值设置为value。如果存在名称为name的键值对，请将第一个键值对的值设置为value并删除所有其他值。如果不是，则将键值对附加到查询字符串。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams<sup>9+</sup>.set<sup>9+</sup>](#set9)替代。

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
paramsObject.set('baz', '3'); // Add a third parameter.
```


### sort<sup>(deprecated)</sup>

sort(): void

对包含在此对象中的所有键值对进行排序，并返回undefined。排序顺序是根据键的Unicode代码点。该方法使用稳定的排序算法 （即，将保留具有相等键的键值对之间的相对顺序）。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams<sup>9+</sup>.sort<sup>9+</sup>](#sort9)替代。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```js
let searchParamsObject = new Url.URLSearchParams("c=3&a=9&b=4&d=2"); // Create a test URLSearchParams object
searchParamsObject.sort(); // Sort the key/value pairs
console.log(searchParamsObject.toString()); // Display the sorted query string // Output a=9&b=2&c=3&d=4
```


### keys<sup>(deprecated)</sup>

keys(): IterableIterator&lt;string&gt;

返回一个所有键值对的name的ES6迭代器。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams<sup>9+</sup>.keys<sup>9+</sup>](#keys9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;string&gt; | 返回一个所有键值对的name的ES6迭代器。 |

**示例：**

```js
let searchParamsObject = new Url.URLSearchParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
for (var key of searchParamsObject .keys()) { // Output key-value pairs
    console.log(key);
}
```


### values<sup>(deprecated)</sup>

values(): IterableIterator&lt;string&gt;

返回一个所有键值对的value的ES6迭代器。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams<sup>9+</sup>.values<sup>9+</sup>](#values9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;string&gt; | 返回一个所有键值对的value的ES6迭代器。 |

**示例：**

```js
let searchParams = new Url.URLSearchParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
for (var value of searchParams.values()) {
    console.log(value);
}
```


### [Symbol.iterator]<sup>(deprecated)</sup>

[Symbol.iterator]\(): IterableIterator&lt;[string, string]&gt;

返回一个ES6的迭代器，迭代器的每一项都是一个 JavaScript Array。Array的第一项是name，Array的第二项是value。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[[Symbol.iterator]<sup>9+</sup>](#symboliterator9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[string, string]&gt; | 返回一个ES6的迭代器。 |

**示例：**

```js
const paramsObject = new Url.URLSearchParams('fod=bay&edg=bap');
for (const [name, value] of paramsObject) {
    console.log(name, value); 
} 
```

### tostring<sup>(deprecated)</sup>

toString(): string

返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[tostring<sup>9+</sup>](#tostring9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。 |

**示例：**

```js
let url = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let params = new Url.URLSearchParams(url.search.slice(1)); 
params.append('fod', '3');
console.log(params.toString());
```
<!--no_check-->