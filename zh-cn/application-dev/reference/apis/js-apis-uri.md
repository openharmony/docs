# @ohos.uri (URI字符串解析)

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```js
import uri from '@ohos.uri'  
```

## URI

### 属性

**系统能力：** SystemCapability.Utils.Lang

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| scheme | string | 是 | 否 | 获取URI&nbsp;的协议部分。 |
| userInfo | string | 是 | 否 | 获取&nbsp;URI&nbsp;的用户信息部分。 |
| host | string | 是 | 否 | 获取&nbsp;URI&nbsp;的主机名部分（不带端口）。 |
| port | string | 是 | 否 | 获取&nbsp;URI&nbsp;的端口部分。 |
| path | string | 是 | 否 | 获取&nbsp;URI&nbsp;的路径部分。 |
| query | string | 是 | 否 | 获取&nbsp;URI&nbsp;的查询部分。 |
| fragment | string | 是 | 否 | 获取&nbsp;URI&nbsp;的片段部分 |
| authority | string | 是 | 否 | 获取此URI的解码权限组件部分。 |
| ssp | string | 是 | 否 | 获取URI的解码方案特定部分。 |

### 命名规则

**命名形式：**

标准uri定义由以下三个部分组成
[scheme:]scheme-specific-part[#fragment]
- scheme: 协议名，根据需要填写。例如http、https、ftp、datashare、dataability等。
- scheme-specific-part: URI的特定解码方案特定部分，由[//][authority][path][?query]组成，根据需要填写。
    - authority: URI的解码权限组件部分。由[userinfo@]host[:port]组成，根据需要填写。
        - userinfo: 用户信息，根据需要填写。
        - host: 服务器的主机名部分，当authority存在时，此项必填。
        - port: 服务器端口，根据需要填写。
    - path: 路径信息，根据需要填写。
    - query: 查询部分，根据需要填写。
- fragment: 片段部分，根据需要填写。

**URI示例：**

```js
const result1 = new uri.URI("ftp://ftp.aaa.bbb.ccc/dddd/eee.txt");
console.log(result1.host) // ftp.aaa.bbb.ccc
console.log(result1.fragment) // null
console.log(result1.path) // /dddd/eee.txt
console.log(result1.scheme) // ftp
console.log(result1.userInfo) // null
console.log(result1.port) // -1
console.log(result1.query) // null

const result2 = new uri.URI("gopher://spinaltap.micro.umn.edu/00/Weather/California/Los%20Angeles#fragment");
console.log(result2.host) // spinaltap.micro.umn.edu
console.log(result2.fragment) // fragment
console.log(result2.path) // /dddd/eee.txt
console.log(result2.scheme) // ftp
console.log(result2.userInfo) // null
console.log(result2.port) //-1
console.log(result2.query) // null

const result3 = new uri.URI("datashare:///com.samples.datasharetest.DataShare/DB00/TBL00");
console.log(result3.host) // null
console.log(result3.fragment) // null
console.log(result3.path) // /com.samples.datasharetest.DataShare/DB00/TBL00
console.log(result3.scheme) // datashare
console.log(result3.userInfo) // null
console.log(result3.port) // -1
console.log(result3.query) // null

const result4 = new uri.URI("https://username:password@host:8080/directory/file?foo=1&bar=2#fragment");
console.log(result4.host) // host
console.log(result4.fragment) // fragment
console.log(result4.path) // /directory/file
console.log(result4.scheme) // https
console.log(result4.userInfo) // username:password
console.log(result4.port) // 8080
console.log(result4.query) // foo=1&bar=2

const result5 = new uri.URI("dataability:///com.example.DataAbility");
console.log(result5.host) // null
console.log(result5.fragment) // null
console.log(result5.path) // /com.example.DataAbility:
console.log(result5.scheme) // dataability
console.log(result5.userInfo) // null
console.log(result5.port) // -1
console.log(result5.query) // null
```

### constructor

constructor(uri: string)

constructor是URI的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | 入参对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](../errorcodes/errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200002 | Invalid uri string. |

**示例：**

```js
let mm = 'https://username:password@host:8080/directory/file?foo=1&bar=2#fragment';
new uri.URI(mm); // Output 'https://username:password@host:8080/directory/file?foo=1&bar=2#fragment';
```
```js
new uri.URI('https://username:password@host:8080'); // Output 'https://username:password@host:8080';
```


### toString

toString(): string

**系统能力：** SystemCapability.Utils.Lang

返回适用于URI中的查询字符串。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回网址的字符串序列化。 |

**示例：**

```js
const result = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
let result1 = result.toString();
```


### equals<sup>(deprecated)</sup>

equals(other: URI): boolean

判断此URI是否与其他URI对象相等。

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[equalsTo<sup>9+</sup>](#equalsto9)替代。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| other | [URI](#uri) | 是 | 需要比较的URI对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回true表示相等，否则返回false。 |

**示例：**

```js
const uriInstance = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
const uriInstance1 = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
uriInstance.equals(uriInstance1);
```
### equalsTo<sup>9+</sup>

equalsTo(other: URI): boolean

判断此URI是否与其他URI对象相等。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| other | [URI](#uri) | 是 | 需要比较的URI对象。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回true表示相等，否则返回false。 |

**示例：**

```js
const uriInstance = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
const uriInstance1 = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
let result = uriInstance.equalsTo(uriInstance1);
```

### checkIsAbsolute

checkIsAbsolute(): boolean

判断此URI是否为绝对URI（是否定义了scheme组件）。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是绝对URI返回true，否则返回false。|

**示例：**

```js
const uriInstance = new uri.URI('https://username:password@www.qwer.com:8080?query=pppppp');
console.log(`${uriInstance.checkIsAbsolute()}`); // true
const uriInstance1 = new uri.URI('xxx.com/suppliers.htm');
console.log(`${uriInstance1.checkIsAbsolute()}`); // false
```


### normalize

normalize(): URI

规范化此URI的路径。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| URI | 返回一个path被规范化后的URI对象。 |

**示例：**

```js
const uriInstance = new uri.URI('https://username:password@www.qwer.com:8080/path/path1/../path2/./path3?query=pppppp');
console.log(uriInstance.path); // /path/path1/../path2/./path3
let uriInstance1 = uriInstance.normalize();
console.log(uriInstance1.path); // /path/path2/path3
```
