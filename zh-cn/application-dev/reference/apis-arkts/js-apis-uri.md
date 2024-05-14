# @ohos.uri (URI字符串解析)

本模块提供URI字符串解析的相关功能。

> **说明：**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


## 导入模块

```ts
import { uri } from '@kit.ArkTS';
```

## URI

构造URI对象，提供判断对象相等、规范路径等方法。

### 属性

**系统能力：** SystemCapability.Utils.Lang

**元服务API：** 从API version 11 开始，该接口支持在元服务中使用。

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| scheme | string | 是 | 否 | 获取URI的协议部分。 |
| userInfo | string | 是 | 否 | 获取URI的用户信息部分。 |
| host | string | 是 | 否 | 获取URI的主机名部分（不带端口）。 |
| port | string | 是 | 否 | 获取URI的端口部分。 |
| path | string | 是 | 否 | 获取URI的路径部分。 |
| query | string | 是 | 否 | 获取URI的查询部分。 |
| fragment | string | 是 | 否 | 获取URI的片段部分 |
| authority | string | 是 | 否 | 获取此URI的解码权限组件部分。 |
| ssp | string | 是 | 否 | 获取URI的解码方案特定部分，方案特定部分是URI的一部分，它包含了特定于协议或方案的信息。 |
| encodedUserInfo<sup>12+</sup>  | string | 是   | 否   | 获取URI的编码用户信息部分。   |
| encodedPath<sup>12+</sup>      | string | 是   | 否   | 获取URI的编码路径部分。         |
| encodedQuery<sup>12+</sup>     | string | 是   | 否   | 获取URI的编码查询部分。       |
| encodedFragment<sup>12+</sup>  | string | 是   | 否   | 获取URI的编码片段部分。       |
| encodedAuthority<sup>12+</sup> | string | 是   | 否   | 获取URI的编码权限组件部分。   |
| encodedSSP<sup>12+</sup>       | string | 是   | 否   | 获取URI的编码方案特定部分。   |

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

```ts
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
console.log(result2.path) // /00/Weather/California/Los Angeles
console.log(result2.scheme) // gopher
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

const result6 = new uri.URI("https://username:my+name@host:8080/directory/my+file?foo=1&bar=2#fragment");
console.log(result6.encodedUserInfo) // username:my+name
console.log(result6.encodedPath) // /directory/my+file
console.log(result6.encodedQuery) // foo=1&bar=2
console.log(result6.encodedFragment) // fragment
console.log(result6.encodedAuthority) // username:my+name@host:8080
console.log(result6.encodedSSP) // //username:my+name@host:8080/directory/my+file?foo=1&bar=2
```

### constructor

constructor(uri: string)

constructor是URI的构造函数。

**元服务API：** 从API version 11 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | 入参对象。 |

**错误码：**

以下错误码的详细介绍请参见[语言基础类库错误码](errorcode-utils.md)。

| 错误码ID | 错误信息 |
| -------- | -------- |
| 10200002 | Invalid uri string. |

**示例：**

```ts
let mm = 'https://username:password@host:8080/directory/file?foo=1&bar=2#fragment';
new uri.URI(mm);
```
```ts
new uri.URI('https://username:password@host:8080');
```


### toString

toString(): string

**系统能力：** SystemCapability.Utils.Lang

返回适用于URI中的查询字符串。

**元服务API：** 从API version 11 开始，该接口支持在元服务中使用。

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 返回网址的字符串序列化。 |

**示例：**

```ts
const result = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
let result1 = result.toString();
```

### equalsTo<sup>9+</sup>

equalsTo(other: URI): boolean

判断此URI是否与其他URI对象相等。

**元服务API：** 从API version 11 开始，该接口支持在元服务中使用。

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

```ts
const uriInstance = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
const uriInstance1 = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
let result = uriInstance.equalsTo(uriInstance1);
```

### checkIsAbsolute

checkIsAbsolute(): boolean

判断此URI是否为绝对URI（是否定义了scheme组件）。

**元服务API：** 从API version 11 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 如果是绝对URI返回true，否则返回false。|

**示例：**

```ts
const uriInstance = new uri.URI('https://username:password@www.qwer.com:8080?query=pppppp');
console.log(`${uriInstance.checkIsAbsolute()}`); // true
const uriInstance1 = new uri.URI('xxx.com/suppliers.htm');
console.log(`${uriInstance1.checkIsAbsolute()}`); // false
```


### normalize

normalize(): URI

规范化此URI的路径。

**元服务API：** 从API version 11 开始，该接口支持在元服务中使用。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| [URI](#uri) | 返回一个path被规范化后的URI对象。 |

**示例：**

```ts
const uriInstance = new uri.URI('https://username:password@www.qwer.com:8080/path/path1/../path2/./path3?query=pppppp');
console.log(uriInstance.path); // /path/path1/../path2/./path3
let uriInstance1 = uriInstance.normalize();
console.log(uriInstance1.path); // /path/path2/path3
```

### checkRelative<sup>12+</sup>

checkRelative(): boolean

判断此URI是否为相对URI，相对URI指的是不包括协议部分的URI。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型    | 说明                                       |
| ------- | ------------------------------------------ |
| boolean | 如果是相对URI返回true，否则返回false。 |

**示例：**

```ts
const uriInstance = new uri.URI("https://username:password@www.qwer.com:8080?query=p");
console.log(`${uriInstance.checkRelative()}`); // false
const uriInstance1 = new uri.URI("/images/pic.jpg");
console.log(`${uriInstance1.checkRelative()}`); // true
```

### checkOpaque<sup>12+</sup>

checkOpaque(): boolean

判断此URI的方案特定部分是否以“/”开头，不以“/”开头的URI为不透明的URI。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型    | 说明                                           |
| ------- | ---------------------------------------------- |
| boolean | 如果是不透明的URI返回true，否则返回false。 |

**示例：**

```ts
const uriInstance = new uri.URI("http://www.test.com/images/pic.jpg");
console.log(`${uriInstance.checkOpaque()}`); // false
const uriInstance1 = new uri.URI("mailto:user@example.com");
console.log(`${uriInstance1.checkOpaque()}`); // true
```

### checkHierarchical<sup>12+</sup>

checkHierarchical(): boolean

判断此URI的方案特定部分是否以“/”开头，以“/”开头的URI为分层的URI。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型    | 说明                                         |
| ------- | -------------------------------------------- |
| boolean | 如果是分层的URI返回true，否则返回false。 |

**示例：**

```ts
const uriInstance = new uri.URI("http://www.test.com/images/pic.jpg");
console.log(`${uriInstance.checkHierarchical()}`); // true
const uriInstance1 = new uri.URI("mailto:user@example.com");
console.log(`${uriInstance1.checkHierarchical()}`); // false
```

### getQueryValue<sup>12+</sup>

getQueryValue(key:string): string

根据给定的查询关键词，从URI查询参数部分中提取出该关键词对应的第一个值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| key    | string | 是   | 此URI查询参数的名称。 |

**返回值：**

| 类型   | 说明                          |
| ------ | ----------------------------- |
| string | 返回第一个此URI查询参数的值。 |

**示例：**

```ts
const uriInstance = new uri.URI("https://www.com?param1=value1&param2=value2");
console.log(uriInstance.getQueryValue("param1")); // value1
```

### addQueryValue<sup>12+</sup>

addQueryValue(key:string, value:string): URI

在当前URI的基础上添加查询参数，并创建一个新的URI，同时保持原有URI对象不变。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                     |
| ------ | ------ | ---- | ------------------------ |
| key    | string | 是   | 需要增添查询参数的名称。 |
| value  | string | 是   | 需要增添查询参数的值。   |

**返回值：**

| 类型 | 说明                             |
| ---- | -------------------------------- |
| [URI](#uri)  | 返回添加查询部分后的URI对象。 |

**示例：**

```ts
const uriInstance = new uri.URI("https://www.test.com");
const newRoute = uriInstance.addQueryValue("param1", "hello world");
console.log(newRoute.toString()); // https://www.test.com?param1=hello%20world
```

### addSegment<sup>12+</sup>

addSegment(pathSegment:string): URI

对给定的字段进行编码并将其追加到当前URI，并创建一个新的URI，同时保持原有URI对象不变。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名      | 类型   | 必填 | 说明               |
| ----------- | ------ | ---- | ------------------ |
| pathSegment | string | 是   | 需要追加到路径部分的字段。 |

**返回值：**

| 类型 | 说明                             |
| ---- | -------------------------------- |
| [URI](#uri)  | 返回已追加字段的URI对象。 |

**示例：**

```ts
const uriInstance = new uri.URI("http://www.test.com");
const newRoute = uriInstance.addSegment("my image.jpg");
console.log(newRoute.toString()); // http://www.test.com/my%20image.jpg
```

### addEncodedSegment<sup>12+</sup>

addEncodedSegment(pathSegment:string): URI

通过将已编码的字段追加到当前URI，并创建一个新的URI，同时保持原有URI对象不变。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名      | 类型   | 必填 | 说明               |
| ----------- | ------ | ---- | ------------------ |
| pathSegment | string | 是   | 需要追加到路径部分的编码字段。 |

**返回值：**

| 类型 | 说明                             |
| ---- | -------------------------------- |
| [URI](#uri)  | 返回已追加字段的URI对象。 |

**示例：**

```ts
const uriInstance = new uri.URI("http://www.test.com");
const newRoute = uriInstance.addEncodedSegment("my%20image.jpg");
console.log(newRoute.toString()); // http://www.test.com/my%20image.jpg
```

### getQueryNames<sup>12+</sup>

getQueryNames(): string[]

获取URI查询部分中所有不重复的键。查询参数是出现在问号“?”之后的部分，它们由键值对组成，键和值之间用等号“=”连接，不同的参数之间使用与号“&”分隔。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型        | 说明                                |
| ----------- | ----------------------------------- |
| string[] | 返回此URI查询部分中所有不重复键。 |

**示例：**

```ts
const uriInstance = new uri.URI("https://www.test.com?param1=value1&param2=value2");
const paramNames = uriInstance.getQueryNames();
console.log(Array.from(paramNames).toString()); // param1,param2
```

### getQueryValues<sup>12+</sup>

getQueryValues(key:string): string[]

获取此URI中查询参数的所有值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型   | 必填 | 说明                    |
| ------ | ------ | ---- | ----------------------- |
| key    | string | 是   | 此URI查询参数的名称。 |

**返回值：**

| 类型     | 说明                                |
| -------- | ----------------------------------- |
| string[] | 返回此URI中查询参数的所有值。 |

**示例：**

```ts
const uriInstance = new uri.URI("https://www.test.com/search?query=name&query=my");
console.log(uriInstance.getQueryValues("query").toString()); // name,my
```

### getBooleanQueryValue<sup>12+</sup>

getBooleanQueryValue(key:string,defaultValue:boolean): boolean

从URI查询参数中获取布尔类型的参数值。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名       | 类型    | 必填 | 说明                                  |
| ------------ | ------- | ---- | ------------------------------------- |
| key          | string  | 是   | 要获取的查询参数的名称。               |
| defaultValue | boolean | 是   | 当指定的查询参数不存在或者参数值无法被转换为布尔值时，返回的默认值。 |

**返回值：**

| 类型    | 说明                                                                   |
| ------- | ---------------------------------------------------------------------- |
| boolean | 布尔类型的查询参数值，如果指定的查询参数不存在或者无法被转换为布尔值，则返回defaultValue。 |

**示例：**

```ts
const uriInstance = new uri.URI("https://www.test.com/search?active=true");
console.log(`${uriInstance.getBooleanQueryValue("active", false)}`); // true
const uriInstance1 = new uri.URI("https://www.test.com/search");
console.log(`${uriInstance1.getBooleanQueryValue("active", false)}`); // false
```

### clearQuery<sup>12+</sup>

clearQuery(): URI

清除URI路径查询部分，并创建一个新的URI，同时保持原有URI对象不变。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明                                  |
| ---- | ------------------------------------- |
| [URI](#uri)  | 返回一个已被清除查询部分的URI对象。 |

**示例：**

```ts
const uriInstance = new uri.URI("https://www.test.com?param1=value1");
console.log(uriInstance.clearQuery().toString()); // https://www.test.com
```

### getLastSegment<sup>12+</sup>

getLastSegment(): string

获取此URI路径的最后一个段。每个段代表路径中的一个部分，通常通过“/”来进行分隔。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明                          |
| ---- | ----------------------------- |
| string  | 返回此URI路径中的最后一个段。 |

**示例：**

```ts
const uriInstance = new uri.URI("content://com.test.provider/files/image.jpg");
console.log(uriInstance.getLastSegment()); // image.jpg
```

### getSegment<sup>12+</sup>

getSegment(): string[]

获取此URI路径中的所有段。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型     | 说明                        |
| -------- | --------------------------- |
| string[] | 返回此URI路径中的所有段。 |

**示例：**

```ts
const uriInstance = new uri.URI("http://www.test.com/path/to/image.jpg");
console.log(uriInstance.getSegment().toString()); // path,to,image.jpg
```

### createFromParts<sup>12+</sup>

createFromParts(scheme: string, ssp: string, fragment: string): URI

根据提供的协议、方案特定部分以及片段部分创建一个新的URI。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名   | 类型   | 必填 | 说明                            |
| -------- | ------ | ---- | ------------------------------- |
| scheme   | string | 是   | 此URI协议部分。               |
| ssp      | string | 是   | 此URI的方案特定部分。 |
| fragment | string | 是   | 此URI的片段部分。片段部分是URI中的一个特定部分，即“#”符号后面的部分。             |

**返回值：**

| 类型 | 说明                                              |
| ---- | ------------------------------------------------- |
| [URI](#uri)  | 返回创建的URI对象。 |

**示例：**

```ts
const uriInstance = uri.URI.createFromParts("mailto", "no body", "top");
console.log(uriInstance.toString()); // mailto:no%20body#top
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

```ts
const uriInstance = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
const uriInstance1 = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
uriInstance.equals(uriInstance1);
```