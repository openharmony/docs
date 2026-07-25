# @ohos.url (URL字符串解析)
<!--Kit: ArkTS-->
<!--Subsystem: CommonLibrary-->
<!--Owner: @wang_zhaoyong; @lijin1039-->
<!--Designer: @Malzahar; @lijin1039-->
<!--Tester: @kirl75; @zsw_zhushiwei-->
<!--Adviser: @k1ngqaquuu-->

URL是统一资源定位符，本模块提供了常用的工具函数，实现了解析URL字符串、构造URL对象以及对URL查询参数的解析和操作等功能。<br>

模块主要包含以下核心类：<br>

- [URL](#url)：用于解析和构造完整URL。 <br>

- [URLParams](#urlparams9)：用于操作URL查询参数。 <br>

- [URLSearchParams](#urlsearchparamsdeprecated)：从API version 9开始废弃，建议使用[URLParams](#urlparams9)替代。 <br>

> **说明：**
>
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```ts
import { url } from '@kit.ArkTS';
```
## URLParams<sup>9+</sup>

URLParams是一个用于解析、构造和操作URL参数的实用类。该类提供了统一的接口来处理URL查询参数。

### constructor<sup>9+</sup>

constructor(init?: string[][] | Record&lt;string, string&gt; | string | URLParams)

URLParams的构造函数，用于创建URL参数对象，适用于需要解析、构造或操作URL查询参数的场景。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
 | init | string[][] \| Record&lt;string, string&gt; \| string \| URLParams | 否 | 入参对象。<br>- string[][]：字符串二维数组。<br>- Record&lt;string, string&gt;：对象列表。<br>- string：URL查询参数字符串。<br>- URLParams：URLParams实例对象。<br>- 默认值：null。 |

**示例：**

```ts
// 通过string[][]方式构造URLParams对象：
let objectParams = new url.URLParams([ ['user1', 'abc1'], ['query2', 'first2'], ['query3', 'second3'] ]);
// 通过Record<string, string>方式构造URLParams对象：
let objectParams1 = new url.URLParams({'fod' : '1' , 'bard' : '2'});
// 通过string方式构造URLParams对象：
let objectParams2 = new url.URLParams('?fod=1&bard=2');
// 通过url对象的search属性构造URLParams对象：
let urlObject = url.URL.parseURL('https://developer.mozilla.org/?fod=1&bard=2');
let objectParams3 = new url.URLParams(urlObject.search);
// 通过url对象的params属性获取URLParams对象：
let secondUrlObj = url.URL.parseURL('https://developer.mozilla.org/?fod=1&bard=2');
let objectParams4 = secondUrlObj.params;
```


### append<sup>9+</sup>

append(name: string, value: string): void

将新的键值对插入到查询字符串。与[set](#set9)方法不同，append不会替换已存在的键名对应的值，而是追加一个新的键值对，允许同一键名存在多个值。如需替换已有键值，请使用set方法。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 需要插入搜索参数的键名。 |
| value | string | 是 | 需要插入搜索参数的值。 |

**示例：**

```ts
// 解析URL字符串
let urlObject = url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
// 构造URLParams对象
let paramsObject = new url.URLParams(urlObject.search.slice(1));
// 追加键值对
paramsObject.append('fod', '3');
```


### delete<sup>9+</sup>

delete(name: string): void

删除指定名称的所有键值对。如果指定名称不存在，则不做任何操作。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 需要删除的键名。 |

**示例：**

```ts
// 解析URL字符串
let urlObject = url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
// 构造URLParams对象
let paramsObject = new url.URLParams(urlObject.search.slice(1));
// 删除指定名称的键值对
paramsObject.delete('fod');
```


### getAll<sup>9+</sup>

getAll(name: string): string[]

获取指定名称的所有键对应值的集合。若查找一个不存在的键值对名称时返回值为空数组。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 指定的键名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string[] | 返回指定名称的所有键对应值的集合。 |

**示例：**

```ts
// 解析URL并构造URLParams对象
let urlObject = url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
let params = new url.URLParams(urlObject.search.slice(1));
params.append('fod', '3'); // 追加第二个fod参数值
// 获取指定名称fod的所有值
console.info(params.getAll('fod').toString()); // Output ["1","3"]
```


### entries<sup>9+</sup>

entries(): IterableIterator<[string, string]>

返回一个迭代器，迭代器的每一项都是一个Array。Array的第一项是name，Array的第二项是value。该方法与[Symbol.iterator]行为一致，均返回键值对的迭代器。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[string, string]&gt; | 返回一个迭代器，迭代器的每一项为包含name和value的[string, string]数组。 |

**示例：**

```ts
// 构造URLParams对象
let paramsObject = new url.URLParams('keyName1=valueName1&keyName2=valueName2');
// 获取entries迭代器
let pair = paramsObject.entries();
// 遍历键值对
for (let item of pair) {
  console.info(item[0] + '=' + item[1]);
}
// keyName1=valueName1
// keyName2=valueName2
```


### forEach<sup>9+</sup>

forEach(callbackFn: (value: string, key: string, searchParams: URLParams) => void, thisArg?: Object): void

通过回调函数按照插入顺序遍历URLParams实例对象上的键值对。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callbackFn | function | 是 | 遍历键值对时执行的回调函数，对每个键值对调用一次。 |
| thisArg | Object | 否 | callbackFn被调用时用作this值，默认值是本对象。 |

**表1** callbackFn的参数说明

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| value | string | 是 | 当前遍历到的值。 |
| key | string | 是 | 当前遍历到的键名。 |
| searchParams | [URLParams](#urlparams9) | 是 | 当前调用forEach方法的实例对象。 |

**示例：**

```ts
// 解析URL
const myURLObject = url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
// 通过回调函数遍历URLParams键值对
myURLObject.params.forEach((value, name, searchParams) => {
    console.info(name, value, myURLObject.params === searchParams);
});
```


### get<sup>9+</sup>

get(name: string): string | null

获取指定名称对应的第一个值。

> **说明：**
>
> 若查找一个不存在的键值对名称时返回值为undefined。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 指定键名。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string \| null | 返回第一个值，如果没找到，返回 null。 |

**示例：**

```ts
let paramsObject = new url.URLParams('name=Jonathan&age=18');
let name = paramsObject.get('name'); // is the string "Jonathan"
let age = paramsObject.get('age'); // is the string "18"
let absentValue = paramsObject.get('abc'); // undefined
```


### has<sup>9+</sup>

has(name: string): boolean

判断一个指定的键名对应的值是否存在。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

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
// 解析URL字符串
let urlObject = url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
// 构造URLParams对象
let paramsObject = new url.URLParams(urlObject.search.slice(1));
// 判断键名bard是否存在
let result = paramsObject.has('bard');
```


### set<sup>9+</sup>

set(name: string, value: string): void

将与name关联的URLParams对象中的值设置为value。

如果存在名称为name的键值对，请将第一个键值对的值设置为value并删除所有其他值。如果不存在该键名，则将键值对附加到查询字符串。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 将要设置的参数的键名。 |
| value | string | 是 | 所要设置的参数值。 |

**示例：**

```ts
let urlObject = url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new url.URLParams(urlObject.search.slice(1));
paramsObject.set('baz', '3'); // Add a third parameter.
```


### sort<sup>9+</sup>

sort(): void

对包含在此对象中的所有键值对进行排序，适用于URL规范化场景（如URL签名、缓存键生成等需要参数顺序一致的场景）。排序顺序是根据键的Unicode代码点。该方法使用稳定的排序算法（保留具有相等键的键值对之间的相对顺序）。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
let paramsObject = new url.URLParams("c=3&a=9&b=4&d=2"); // Create a test URLParams object
paramsObject.sort(); // Sort the key/value pairs
console.info(paramsObject.toString()); // Display the sorted query string // Output a=9&b=4&c=3&d=2
```


### keys<sup>9+</sup>

keys(): IterableIterator&lt;string&gt;

返回一个包含所有键值对的name的迭代器。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;string&gt; | 返回一个包含所有键值对的name的迭代器。 |

**示例：**

```ts
// 构造URLParams对象
let paramsObject = new url.URLParams("key1=value1&key2=value2");
// 获取所有键名的迭代器
let keys = paramsObject.keys();
// 遍历输出键名
for (let key of keys) {
  console.info(key);
}
// key1
// key2
```


### values<sup>9+</sup>

values(): IterableIterator&lt;string&gt;

返回一个包含所有键值对的value的迭代器。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;string&gt; | 返回一个包含所有键值对的value的迭代器。 |

**示例：**

```ts
// 构造URLParams对象
let paramsObject = new url.URLParams("key1=value1&key2=value2");
// 获取所有值的迭代器
let values = paramsObject.values();
// 遍历输出值
for (let value of values) {
  console.info(value);
}
// value1
// value2
```


### [Symbol.iterator]<sup>9+</sup>

[Symbol.iterator]\(): IterableIterator&lt;[string, string]&gt;

返回一个迭代器，迭代器的每一项都是一个Array。Array的第一项是name，Array的第二项是value。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[string, string]&gt; | 返回一个迭代器，迭代器的每一项为包含name和value的[string, string]数组。 |

**示例：**

```ts
// 构造URLParams对象
const paramsObject = new url.URLParams('fod=bay&edg=bap');
// 获取Symbol.iterator迭代器
let iter = paramsObject[Symbol.iterator]();
// 遍历键值对
for (let pair of iter) {
  console.info(pair[0] + ', ' + pair[1]);
}
// fod, bay
// edg, bap
```


### toString<sup>9+</sup>

toString(): string

返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。 |

**示例：**

```ts
// 解析URL字符串
let urlObject = url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
// 构造URLParams对象
let params = new url.URLParams(urlObject.search.slice(1));
// 追加参数
params.append('fod', '3');
// 将参数序列化为字符串
console.info(params.toString()); // Output 'fod=1&bard=2&fod=3'
```

## URL

用于解析、构造、规范化、编码对应的URL字符串。

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| hash | string | 否 | 否 | 获取和设置URL的片段部分。**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| host | string | 否 | 否 | 获取和设置URL的主机部分。**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| hostname | string | 否 | 否 | 获取和设置URL的主机名部分，不带端口。**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| href | string | 否 | 否 | 获取和设置序列化的URL。**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| origin | string | 是 | 否 | 获取URL源的只读序列化。**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| password | string | 否 | 否 | 获取和设置URL的密码部分。**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| pathname | string | 否 | 否 | 获取和设置URL的路径部分。**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| port | string | 否 | 否 | 获取和设置URL的端口部分。当port为当前protocol的默认端口时，port将被解析为空字符串。**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| protocol | string | 否 | 否 | 获取和设置URL的协议部分。**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| search | string | 否 | 否 | 获取和设置URL的序列化查询部分。**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| searchParams<sup>(deprecated)</sup> | [URLSearchParams](#urlsearchparamsdeprecated) | 是 | 否 | 获取URLSearchParams对象，用于访问URL查询参数。<br>- **说明：** 此属性从API version 7开始支持，从API version 9开始废弃。建议使用[URLParams](#urlparams9)替代。 |
| params<sup>9+</sup> | [URLParams](#urlparams9) | 是 | 否 | 获取URLParams对象，用于访问URL查询参数。**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |
| username | string | 否 | 否 | 获取和设置URL的用户名部分。**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。 |

> **说明：**
>
> 在解析URL字符串时，如果入参中的port内容是当前protocol的默认端口，那么port将被解析为空字符串。默认端口为：
>
> | 协议 | 默认端口 |
> | -------- | -------- |
> | http: | 80 |
> | https: | 443 |
> | ftp: | 21 |
> | gopher: | 70 |
> | ws: | 80 |
> | wss: | 443 |

**示例：**

```ts
let parsedUrl = url.URL.parseURL('http://username:password@host:8080/directory/file?foo=1&bar=2#fragment');
console.info("hash " + parsedUrl.hash); // hash #fragment
console.info("host " + parsedUrl.host); // host host:8080
console.info("hostname " + parsedUrl.hostname); // hostname host
console.info("href " + parsedUrl.href); // href http://username:password@host:8080/directory/file?foo=1&bar=2#fragment
console.info("origin " + parsedUrl.origin); // origin http://host:8080
console.info("password " + parsedUrl.password); // password password
console.info("pathname " + parsedUrl.pathname); // pathname /directory/file
console.info("port " + parsedUrl.port); // port 8080
console.info("protocol " + parsedUrl.protocol); // protocol http:
console.info("search " + parsedUrl.search); // search ?foo=1&bar=2
console.info("username " + parsedUrl.username); // username username
// parsedUrl.params 返回值为URLParams对象
console.info("params: foo " + parsedUrl.params.get("foo")); // params: foo 1

let urlObj = url.URL.parseURL('http://testhost:80/directory/file?foo=1');
console.info("port " + urlObj.port); // port 
console.info("toString " + urlObj.toString()); // toString http://testhost/directory/file?foo=1
```

### constructor<sup>(deprecated)</sup>

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[parseURL<sup>9+</sup>](#parseurl9)替代。

constructor(url: string, base?: string | URL)

URL的构造函数。与[parseURL](#parseurl9)方法功能相同，但parseURL为静态工厂方法，推荐使用parseURL来创建URL对象。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| url | string | 是 | 一个表示绝对URL或相对URL的字符串，必须是合法的URL格式。 <br>如果url是相对URL，则需要指定base，用于解析最终的URL。 <br>如果 url是绝对URL，则给定的base将不会生效。 |
| base | string \| URL |  否  | 入参字符串或者对象，默认值是undefined。<br>- string：表示基础URL的字符串，当url为相对URL时需为合法URL格式。<br>- URL：已解析的URL对象，用作相对URL解析的基础地址。|

**示例：**

```ts
let baseUrl = 'https://username:password@host:8080';
let rootPathUrl = new url.URL("/", baseUrl); // Output 'https://username:password@host:8080/';
let absoluteUrl = new url.URL(baseUrl); // Output 'https://username:password@host:8080/';
new url.URL('path/path1', b); // Output 'https://username:password@host:8080/path/path1';
let relativePathUrl = new url.URL('/path/path1', absoluteUrl);  // Output 'https://username:password@host:8080/path/path1'; 
new url.URL('/path/path1', relativePathUrl); // Output 'https://username:password@host:8080/path/path1';
new url.URL('/path/path1', rootPathUrl); // Output 'https://username:password@host:8080/path/path1';
new url.URL('/path/path1', "https://www.exampleUrl/fr-FR/toot"); // Output https://www.exampleUrl/path/path1
new url.URL('/path/path1', ''); // Raises a TypeError exception as '' is not a valid URL
new url.URL('/path/path1'); // Raises a TypeError exception as '/path/path1' is not a valid URL
new url.URL('https://www.example.com', ); // Output https://www.example.com/
new url.URL('https://www.example.com', absoluteUrl); // Output https://www.example.com/
```

### constructor<sup>9+</sup>

constructor()

URL的无参构造函数，不建议直接调用。请使用[parseURL](#parseurl9)方法创建URL对象。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

### parseURL<sup>9+</sup>

static parseURL(url: string, base?: string | URL): URL

解析URL字符串，返回解析后的URL对象。该对象包含协议、主机、端口、路径和查询参数等URL组成部分。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| url | string | 是 | 一个表示绝对URL或相对URL的字符串。 <br>如果 url 是相对URL，则需要指定 base，用于解析最终的URL。 <br>如果 url 是绝对URL，则给定的 base 将不会生效。 |
| base | string \| URL | 否 | 入参字符串或者对象，默认值是undefined。<br>- string：字符串。当第一个参数是相对URL时，该参数需符合URL标准。<br>- URL：URL对象。<br>- 在url是相对URL时使用，url为绝对URL时此参数不会生效。 |

**返回值：**

| 类型 | 说明                                              |
| ---- | ------------------------------------------------- |
| [URL](#url)  | 返回解析后的URL对象，包含URL的各组成部分（如协议、主机和路径等属性）。 |

> **说明：**
>
> 当入参url是相对URL时，调用该接口解析后的URL并不是简单地将入参url和base直接拼接。url内容为相对路径格式时，会相对于base的当前目录进行解析，包括base中path字段最后一个斜杠前的所有路径片段，但不包括其后的部分（参照示例中url1）。url内容为指向根目录的格式时，会相对于 base 的原始地址（origin）进行解析（参照示例中url2）。

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200002 | Invalid url string. |

**示例：**

```ts
let baseUrl = 'https://username:password@host:8080/test/test1/test3';
let urlObject = url.URL.parseURL(baseUrl);
let result = urlObject.toString(); // Output 'https://username:password@host:8080/test/test1/test3'
// url内容为相对路径格式时，此时base参数的path为test/test1,解析后的URL的path为/test/path2/path3
let relativePathUrl = url.URL.parseURL('path2/path3', 'https://www.example.com/test/test1'); // Output 'https://www.example.com/test/path2/path3'
// url内容为指向根目录的格式时，此时base参数的path为/test/test1/test3，解析后的URL的path为/path1/path2
let rootPathUrl = url.URL.parseURL('/path1/path2', urlObject); // Output 'https://username:password@host:8080/path1/path2'
url.URL.parseURL('/path/path1', "https://www.exampleUrl/fr-FR/toot"); // Output 'https://www.exampleUrl/path/path1'
url.URL.parseURL('/path/path1', ''); // Raises a TypeError exception as '' is not a valid URL
url.URL.parseURL('/path/path1'); // Raises a TypeError exception as '/path/path1' is not a valid URL
url.URL.parseURL('https://www.example.com', ); // Output 'https://www.example.com/'
url.URL.parseURL('https://www.example.com', urlObject); // Output 'https://www.example.com/'
```

### toString

toString(): string

将解析过后的URL转化为字符串，返回值与URL的href属性值相同。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 解析后的URL序列化字符串。 |

**示例：**

```ts
const urlObject = url.URL.parseURL('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
let result = urlObject.toString(); // Output 'https://username:password@host:8080/directory/file?query=pppppp#qwer=da'
```

### toJSON

toJSON(): string

将解析过后的URL转化为JSON字符串。

**原子化服务API**：从API version 11开始，该接口支持在原子化服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | URL对象的JSON序列化字符串。 |

**示例：**
```ts
// 解析URL字符串
const urlObject = url.URL.parseURL('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
// 将URL转化为字符串
let result = urlObject.toJSON();
```

## URLSearchParams<sup>(deprecated)</sup>

URLSearchParams接口定义了一些处理URL查询字符串的实用方法。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams](#urlparams9)替代。

### constructor<sup>(deprecated)</sup>

constructor(init?: string[][] | Record&lt;string, string&gt; | string | URLSearchParams)

URLSearchParams的构造函数。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams.constructor<sup>9+</sup>](#constructor9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| init | string[][] \| Record&lt;string, string&gt; \| string \| URLSearchParams | 否 | 入参对象。<br>- string[][]：字符串二维数组，每个内部数组包含两个元素，分别为键名和键值。<br>- Record&lt;string, string&gt;：对象列表。<br>- string：字符串，需遵循URL查询参数格式，如'key=value&key2=value2'。<br>- URLSearchParams：对象。<br>- 默认值：undefined。 |

**示例：**

```ts
let objectParams = new url.URLSearchParams([ ['user1', 'abc1'], ['query2', 'first2'], ['query3', 'second3'] ]);
let objectParams1 = new url.URLSearchParams({"fod" : '1' , "bard" : '2'});
let objectParams2 = new url.URLSearchParams('?fod=1&bard=2');
let urlObject = new url.URL('https://developer.mozilla.org/?fod=1&bard=2');
let params = new url.URLSearchParams(urlObject.search);
```

### append<sup>(deprecated)</sup>

append(name: string, value: string): void

将新的键值对插入到查询字符串。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams.append<sup>9+</sup>](#append9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 需要插入搜索参数的键名。 |
| value | string | 是 | 需要插入搜索参数的值。 |

**示例：**

```ts
let urlObject = new url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new url.URLSearchParams(urlObject.search.slice(1));
paramsObject.append('fod', '3');
```

### delete<sup>(deprecated)</sup>

delete(name: string): void

删除指定名称的键值对。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams.delete<sup>9+</sup>](#delete9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 需要删除的键值名称。 |

**示例：**

```ts
let urlObject = new url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new url.URLSearchParams(urlObject.search.slice(1));
paramsObject.delete('fod');
```

### getAll<sup>(deprecated)</sup>

getAll(name: string): string[]

获取指定名称的所有键对应值的集合。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams.getAll<sup>9+</sup>](#getall9)替代。

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
let urlObject = new url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let params = new url.URLSearchParams(urlObject.search.slice(1));
params.append('fod', '3'); // Add a second value for the fod parameter.
console.info(params.getAll('fod').toString()) // Output ["1","3"].
```

### entries<sup>(deprecated)</sup>

entries(): IterableIterator<[string, string]>

返回一个迭代器，迭代器的每一项都是一个Array。Array的第一项是name，Array的第二项是value。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams.entries<sup>9+</sup>](#entries9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[string, string]&gt; | 返回一个迭代器，迭代器的每一项为包含name和value的[string, string]数组。 |

**示例：**

```ts
let searchParamsObject = new url.URLSearchParams("keyName1=valueName1&keyName2=valueName2");
let iter = searchParamsObject.entries();
for (let pair of iter) {
  console.info(pair[0]+ ', '+ pair[1]);
}
// keyName1, valueName1
// keyName2, valueName2
```


### forEach<sup>(deprecated)</sup>

forEach(callbackFn: (value: string, key: string, searchParams: URLSearchParams) => void, thisArg?: Object): void

通过回调函数来遍历URLSearchParams实例对象上的键值对。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams.forEach<sup>9+</sup>](#foreach9)替代。

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
| searchParams | [URLSearchParams](#urlsearchparamsdeprecated) | 是 | 当前调用forEach方法的实例对象。 |

**示例：**

```ts
const myURLObject = new url.URL('https://developer.exampleUrl/?fod=1&bard=2');
myURLObject.searchParams.forEach((value, name, searchParams) => {
    console.info(name, value, myURLObject.searchParams === searchParams);
});
```


### get<sup>(deprecated)</sup>

get(name: string): string | null

获取指定名称对应的第一个值。

> **说明：**
>
> 若查找一个不存在的键值对名称时返回值为undefined。从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams.get<sup>9+</sup>](#get9)替代。


**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 指定键值对的名称。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string \| null | 返回第一个值，如果没找到，返回 null。 |

**示例：**

```ts
let paramsObject = new url.URLSearchParams('name=Jonathan&age=18');
let name = paramsObject.get("name"); // is the string "Jonathan"
let age = paramsObject.get("age"); // is the string '18'
let getObj = paramsObject.get("abc"); // undefined
```


### has<sup>(deprecated)</sup>

has(name: string): boolean

判断一个指定的键名对应的值是否存在。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams.has<sup>9+</sup>](#has9)替代。

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
let urlObject = new url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new url.URLSearchParams(urlObject.search.slice(1));
paramsObject.has('bard') === true;
```


### set<sup>(deprecated)</sup>

set(name: string, value: string): void

将与name关联的URLSearchParams对象中的值设置为value。如果存在名称为name的键值对，请将第一个键值对的值设置为value并删除所有其他值。如果不是，则将键值对附加到查询字符串。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams.set<sup>9+</sup>](#set9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| name | string | 是 | 将要设置的参数的键值名。 |
| value | string | 是 | 所要设置的参数值。 |

**示例：**

```ts
let urlObject = new url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new url.URLSearchParams(urlObject.search.slice(1));
paramsObject.set('baz', '3'); // Add a third parameter.
```


### sort<sup>(deprecated)</sup>

sort(): void

对包含在此对象中的所有键值对进行排序。排序顺序是根据键的Unicode代码点。该方法使用稳定的排序算法 （即，将保留具有相等键的键值对之间的相对顺序）。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams.sort<sup>9+</sup>](#sort9)替代。

**系统能力：** SystemCapability.Utils.Lang

**示例：**

```ts
let searchParamsObject = new url.URLSearchParams("c=3&a=9&b=4&d=2"); // Create a test URLSearchParams object
searchParamsObject.sort(); // Sort the key/value pairs
console.info(searchParamsObject.toString()); // Display the sorted query string // Output a=9&b=4&c=3&d=2
```


### keys<sup>(deprecated)</sup>

keys(): IterableIterator&lt;string&gt;

返回一个所有键值对的name的迭代器。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams.keys<sup>9+</sup>](#keys9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;string&gt; | 返回一个所有键值对的name的迭代器。 |

**示例：**

```ts
let searchParamsObject = new url.URLSearchParams("key1=value1&key2=value2");
let keys = searchParamsObject.keys();
for (let key of keys) {
  console.info(key);
}
// key1
// key2
```


### values<sup>(deprecated)</sup>

values(): IterableIterator&lt;string&gt;

返回一个所有键值对的value的迭代器。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams.values<sup>9+</sup>](#values9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;string&gt; | 返回一个所有键值对的value的迭代器。 |

**示例：**

```ts
let searchParams = new url.URLSearchParams("key1=value1&key2=value2");
let values = searchParams.values();
for (let value of values) {
  console.info(value);
}
// value1
// value2
```


### [Symbol.iterator]<sup>(deprecated)</sup>

[Symbol.iterator]\(): IterableIterator&lt;[string, string]&gt;

返回一个迭代器，迭代器的每一项都是一个Array。Array的第一项是name，Array的第二项是value。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams.[Symbol.iterator]<sup>9+</sup>](#symboliterator9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| IterableIterator&lt;[string, string]&gt; | 返回一个迭代器，迭代器的每一项为包含name和value的[string, string]数组。 |

**示例：**

```ts
const paramsObject = new url.URLSearchParams('fod=bay&edg=bap');
let pairs = paramsObject[Symbol.iterator]();
for (let pair of pairs) {
  console.info(pair[0] + ', ' + pair[1]);
}
// fod, bay
// edg, bap
```

### toString<sup>(deprecated)</sup>

toString(): string

返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。

> **说明：**
>
> 从API version 7开始支持，从API version 9开始废弃，建议使用[URLParams.toString<sup>9+</sup>](#tostring9)替代。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回序列化为字符串的搜索参数，必要时对字符进行百分比编码。 |

**示例：**

```ts
let urlObject = new url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let params = new url.URLSearchParams(urlObject.search.slice(1));
params.append('fod', '3');
console.info(params.toString()); // Output 'fod=1&bard=2&fod=3'
```
<!--no_check-->