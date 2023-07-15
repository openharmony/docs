# @ohos.uri (URI String Parsing)

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import uri from '@ohos.uri'  
```

## URI

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| scheme | string | Yes| No| Scheme in the URI.|
| userInfo | string | Yes| No| User information in the URI.|
| host | string | Yes| No| Host name (without the port number) in the URI.|
| port | string | Yes| No| Port number in the URI.|
| path | string | Yes| No| Path in the URI.|
| query | string | Yes| No| Query part in the URI.|
| fragment | string | Yes| No| Fragment part in the URI.|
| authority | string | Yes| No| Authority part in the URI.|
| ssp | string | Yes| No| Scheme-specific part in the URI.|

### Naming Rules

Naming format:

A standard URI consists of the following parts:
[scheme:]scheme-specific-part[#fragment]
- scheme: scheme component. Set this parameter as required. Example values: **http**, **https**, **ftp**, **datashare**, and **dataability**.
- scheme-specific-part: specific part of the URI decoding scheme. The value consists of [//][authority][path][?query]. Set this parameter as required.
    - authority: decoding authority component of the URI. The value consists of [userinfo@]host[:port]. Set this parameter as required.
        - userinfo: user information. Set this parameter as required.
        - host: host name of the server. This parameter is mandatory when authority exists.
        - port: port number of the server. Set this parameter as required.
    - path: path information. Set this parameter as required.
    - query: query component. Set this parameter as required.
- fragment: fragment component. Set this parameter as required.

**Example URIs**

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

A constructor used to create a URI instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| Input object.|

**Error codes**

For details about the error codes, see [Utils Error Codes](../errorcodes/errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 10200002 | Invalid uri string. |

**Example**

```js
let mm = 'https://username:password@host:8080/directory/file?foo=1&bar=2#fragment';
new uri.URI(mm); // Output 'https://username:password@host:8080/directory/file?foo=1&bar=2#fragment';
```
```js
new uri.URI('https://username:password@host:8080'); // Output 'https://username:password@host:8080';
```


### toString

toString(): string

**System capability**: SystemCapability.Utils.Lang

Obtains the query string applicable to this URI.

**Return value**

| Type| Description|
| -------- | -------- |
| string | Website address in a serialized string.|

**Example**

```js
const result = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
let result1 = result.toString();
```


### equals<sup>(deprecated)</sup>

equals(other: URI): boolean

Checks whether this URI is the same as another URI object.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [equalsTo<sup>9+</sup>](#equalsto9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| other | [URI](#uri) | Yes| URI object to compare.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the two URIs are the same; returns **false** otherwise.|

**Example**

```js
const uriInstance = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
const uriInstance1 = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
uriInstance.equals(uriInstance1);
```
### equalsTo<sup>9+</sup>

equalsTo(other: URI): boolean

Checks whether this URI is the same as another URI object.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| other | [URI](#uri) | Yes| URI object to compare.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the two URIs are the same; returns **false** otherwise.|

**Example**

```js
const uriInstance = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
const uriInstance1 = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
let result = uriInstance.equalsTo(uriInstance1);
```

### checkIsAbsolute

checkIsAbsolute(): boolean

Checks whether this URI is an absolute URI (whether the scheme component is defined).

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | If the URI is an absolute URI, **true** is returned. Otherwise, **false** is returned.|

**Example**

```js
const uriInstance = new uri.URI('https://username:password@www.qwer.com:8080?query=pppppp');
console.log(`${uriInstance.checkIsAbsolute()}`); // true
const uriInstance1 = new uri.URI('xxx.com/suppliers.htm');
console.log(`${uriInstance1.checkIsAbsolute()}`); // false
```


### normalize

normalize(): URI

Normalizes the path of this URI.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| URI | URI with the normalized path.|

**Example**

```js
const uriInstance = new uri.URI('https://username:password@www.qwer.com:8080/path/path1/../path2/./path3?query=pppppp');
console.log(uriInstance.path); // /path/path1/../path2/./path3
let uriInstance1 = uriInstance.normalize();
console.log(uriInstance1.path); // /path/path2/path3
```
