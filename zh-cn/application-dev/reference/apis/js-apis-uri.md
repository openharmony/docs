# URI字符串解析

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


### constructor

constructor(uri: string)

constructor是URI的构造函数。

**系统能力：** SystemCapability.Utils.Lang

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| uri | string | 是 | 入参对象。 |

**示例：**

```js
let mm = 'http://username:password@host:8080/directory/file?foo=1&bar=2#fragment';
new uri.URI(mm); // Output 'http://username:password@host:8080/directory/file?foo=1&bar=2#fragment';
```
```js
new uri.URI('http://username:password@host:8080'); // Output 'http://username:password@host:8080';
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
const result = new uri.URI('http://username:password@host:8080/directory/file?query=pppppp#qwer=da');
result.toString()
```


### equals<sup>(deprecated)</sup>

> **说明：**
>
> 从API version 8开始支持，从API version 9开始废弃，建议使用[equalsTo<sup>9+</sup>](#equalsto9)替代。

equals(other: URI): boolean

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
const uriInstance = new uri.URI('http://username:password@host:8080/directory/file?query=pppppp#qwer=da');
const uriInstance1 = new uri.URI('http://username:password@host:8080/directory/file?query=pppppp#qwer=da#fragment');
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
const uriInstance = new uri.URI('http://username:password@host:8080/directory/file?query=pppppp#qwer=da');
const uriInstance1 = new uri.URI('http://username:password@host:8080/directory/file?query=pppppp#qwer=da#fragment');
uriInstance.equalsTo(uriInstance1);
```

### checkIsAbsolute

checkIsAbsolute(): boolean

判断此URI是否为绝对URI（是否定义了scheme组件）。

**系统能力：** SystemCapability.Utils.Lang

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| boolean | 返回true表示该URI是否为绝对URI。 |

**示例：**

```js
const uriInstance = new uri.URI('http://username:password@www.qwer.com:8080?query=pppppp');
uriInstance.checkIsAbsolute();
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
const uriInstance = new uri.URI('http://username:password@www.qwer.com:8080/path/path1/../path2/./path3?query=pppppp');
let uriInstance1 = uriInstance.normalize();
uriInstance1.path;
```
