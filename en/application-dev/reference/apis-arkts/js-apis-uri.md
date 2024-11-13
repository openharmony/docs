# @ohos.uri (URI String Parsing)

The uri module provides APIs for parsing URI strings that comply with the RFC3986 standard. This standard defines how to encode and parse the identifiers used to locate network resources. The module does not support parsing of URIs in non-standard scenarios.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import { uri } from '@kit.ArkTS';
```

## URI

Implements a URI, which provides APIs for determining whether objects are equal as well as standard paths.

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| scheme | string | Yes| No| Scheme in the URI. If this part does not exist, a null object is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| userInfo | string | Yes| No| User information in the URI. If this part does not exist, a null object is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| host | string | Yes| No| Host name (without the port number) in the URI. If this part does not exist, a null object is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| port | string | Yes| No| Port number in the URI.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| path | string | Yes| No| Path in the URI. If this part does not exist, a null object is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| query | string | Yes| No| Query parameters in the URI. If this part does not exist, a null object is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| fragment | string | Yes| No| Fragments in the URI. If this part does not exist, a null object is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| authority | string | Yes| No| Authority in the URI. If this part does not exist, a null object is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| ssp | string | Yes| No| Scheme-specific part in the URI. It contains protocol-or scheme-specific information.<br>**Atomic service API**: This API can be used in atomic services since API version 11.|
| encodedUserInfo<sup>12+</sup>  | string | Yes  | No  | Encoded user information in the URI. If this part does not exist, a null object is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 12.  |
| encodedPath<sup>12+</sup>      | string | Yes  | No  | Encoded path in the URI. If this part does not exist, a null object is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 12.      |
| encodedQuery<sup>12+</sup>     | string | Yes  | No  | Encoded query parameters in the URI. If this part does not exist, a null object is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 12.     |
| encodedFragment<sup>12+</sup>  | string | Yes  | No  | Encoded fragments in the URI. If this part does not exist, a null object is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 12.     |
| encodedAuthority<sup>12+</sup> | string | Yes  | No  | Encoded authority in the URI. If this part does not exist, a null object is returned.<br>**Atomic service API**: This API can be used in atomic services since API version 12.  |
| encodedSSP<sup>12+</sup>       | string | Yes  | No  | Encoded scheme-specific part in the URI.<br>**Atomic service API**: This API can be used in atomic services since API version 12.  |

### Naming Rules

Naming format:

A standard URI mainly consists of three parts, as follows:

[scheme:]scheme-specific-part[#fragment]

The generic URI syntax consists of a hierarchical sequence of components, as follows:

[scheme:][//authority][path][?query][#fragment]

It can be further divided into the following parts:

[scheme:][//[user-info@]host[:port]][path][?query][#fragment]

- scheme: scheme name, which is separated from scheme-specific-part by a colon (:). The URI that contains the scheme component is an absolute URI, and the URI that does not contain the scheme component is a relative URI. Set this part as required. Example values: **http**, **https**, **ftp**, and **datashare**.
- scheme-specific-part: specific part of the URI decoding scheme. It is located between [scheme:] and [#fragment] and consists of [//][authority][path][?query]. The URI that starts with a slash (/) is a hierarchical URI, and the URI that does not start with a slash (/) is an opaque URI. Set this part as required.
    - authority: decoding authority component of the URI. The value consists of [userinfo@]host[:port]. Set this part as required.
        - userinfo: user information, which is separated from host by an at sign (@). Set this part as required.
        - host: host name of the server. This parameter is mandatory when authority exists.
        - port: port number of the server. The default value is **-1**. Set this part as required.
    - path: path information, which is located between host and query and separated by a slash (/). Set this part as required.
    - query: query component, which is located between path and fragment, indicated by the first question mark (?) character, and is in the format of key-value pairs. Multiple key-value pairs are separated by the at sign (&), and the key and value in a pair is separated by the equal sign (=). Set this part as required.
- fragment: fragment component, which is separated from scheme-specific-part by the pound key (#). Set this part as required.

**Example URIs**

```ts
const result1 = new uri.URI("ftp://ftp.aaa.bbb.ccc/dddd/eee.txt");
console.info(result1.host) // ftp.aaa.bbb.ccc
console.info(result1.fragment) // null
console.info(result1.path) // /dddd/eee.txt
console.info(result1.scheme) // ftp
console.info(result1.userInfo) // null
console.info(result1.port) // -1
console.info(result1.query) // null

const result2 = new uri.URI("gopher://spinaltap.micro.umn.edu/00/Weather/California/Los%20Angeles#fragment");
console.info(result2.host) // spinaltap.micro.umn.edu
console.info(result2.fragment) // fragment
console.info(result2.path) // /00/Weather/California/Los Angeles
console.info(result2.scheme) // gopher
console.info(result2.userInfo) // null
console.info(result2.port) //-1
console.info(result2.query) // null

const result3 = new uri.URI("datashare:///com.samples.datasharetest.DataShare/DB00/TBL00");
console.info(result3.host) // null
console.info(result3.fragment) // null
console.info(result3.path) // /com.samples.datasharetest.DataShare/DB00/TBL00
console.info(result3.scheme) // datashare
console.info(result3.userInfo) // null
console.info(result3.port) // -1
console.info(result3.query) // null

const result4 = new uri.URI("https://username:password@host:8080/directory/file?foo=1&bar=2#fragment");
console.info(result4.host) // host
console.info(result4.fragment) // fragment
console.info(result4.path) // /directory/file
console.info(result4.scheme) // https
console.info(result4.userInfo) // username:password
console.info(result4.port) // 8080
console.info(result4.query) // foo=1&bar=2

const result5 = new uri.URI("dataability:///com.example.DataAbility");
console.info(result5.host) // null
console.info(result5.fragment) // null
console.info(result5.path) // /com.example.DataAbility:
console.info(result5.scheme) // dataability
console.info(result5.userInfo) // null
console.info(result5.port) // -1
console.info(result5.query) // null

const result6 = new uri.URI("https://username:my+name@host:8080/directory/my+file?foo=1&bar=2#fragment");
console.info(result6.encodedUserInfo) // username:my+name
console.info(result6.encodedPath) // /directory/my+file
console.info(result6.encodedQuery) // foo=1&bar=2
console.info(result6.encodedFragment) // fragment
console.info(result6.encodedAuthority) // username:my+name@host:8080
console.info(result6.encodedSSP) // //username:my+name@host:8080/directory/my+file?foo=1&bar=2

let result7 = new uri.URI("www.abc.com:8080/directory/file?ab=pppppp#qwer=da");
console.log(result7.scheme) // www.abc.com
console.log(result7.host) // null
console.log(result7.port) // -1
console.log(result7.path) // null
console.log(result7.query) // null
console.log(result7.authority) // null
console.log(result7.fragment) // qwer=da
console.log(result7.ssp) // 8080/directory/file?ab=pppppp
console.log(result7.checkIsAbsolute()) // true
```

### constructor

constructor(uri: string)

A constructor used to create a URI instance.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| Input object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200002 | Invalid uri string. |

**Example**

```ts
let mm = 'https://username:password@host:8080/directory/file?foo=1&bar=2#fragment';
new uri.URI(mm);
```
```ts
new uri.URI('https://username:password@host:8080');
```


### toString

toString(): string

Converts this URI into an encoded string.

**System capability**: SystemCapability.Utils.Lang

**Atomic service API**: This API can be used in atomic services since API version 11.

**Return value**

| Type| Description|
| -------- | -------- |
| string | URI in a serialized string.|

**Example**

```ts
const result = new uri.URI('https://username:password@host:8080/directory/file?ab=pppppp#qwer da');
let result1 = result.toString(); // https://username:password@host:8080/directory/file?ab=pppppp#qwer%20da
```

### equalsTo<sup>9+</sup>

equalsTo(other: URI): boolean

Checks whether this URI is the same as another URI object.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| other | [URI](#uri) | Yes| URI object to compare.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the two URIs are the same; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
const uriInstance = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
const uriInstance1 = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
let result = uriInstance.equalsTo(uriInstance1); // true
```

### checkIsAbsolute

checkIsAbsolute(): boolean

Checks whether this URI is an absolute URI (whether the scheme component is defined).

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | **true**: The URI is an absolute URI.<br>**false**: The URI is not an absolute URI.|

**Example**

```ts
const uriInstance = new uri.URI('https://username:password@www.qwer.com:8080?query=pppppp');
console.info(`${uriInstance.checkIsAbsolute()}`); // true
const uriInstance1 = new uri.URI('xxx.com/suppliers.htm');
console.info(`${uriInstance1.checkIsAbsolute()}`); // false
```


### normalize

normalize(): URI

Normalizes the path of this URI.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| [URI](#uri) | URI with the normalized path.|

**Example**

```ts
const uriInstance = new uri.URI('https://username:password@www.qwer.com:8080/path/path1/../path2/./path3?query=pppppp');
console.info(uriInstance.path); // /path/path1/../path2/./path3
let uriInstance1 = uriInstance.normalize();
console.info(uriInstance1.path); // /path/path2/path3
```

### checkRelative<sup>12+</sup>

checkRelative(): boolean

Checks whether this URI is a relative URI. A relative URI does not contain the scheme component.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                      |
| ------- | ------------------------------------------ |
| boolean | **true**: The URI is a relative URI.<br>**false**: The URI is not a relative URI.|

**Example**

```ts
const uriInstance = new uri.URI("https://username:password@www.qwer.com:8080?query=p");
console.info(`${uriInstance.checkRelative()}`); // false
const uriInstance1 = new uri.URI("/images/pic.jpg");
console.info(`${uriInstance1.checkRelative()}`); // true
```

### checkOpaque<sup>12+</sup>

checkOpaque(): boolean

Checks whether this URI is an opaque URI. The URI that does not start with a slash (/) is an opaque URI.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                          |
| ------- | ---------------------------------------------- |
| boolean | **true**: The URI is an opaque URI.<br>**false**: The URI is not an opaque URI.|

**Example**

```ts
const uriInstance = new uri.URI("http://www.test.com/images/pic.jpg");
console.info(`${uriInstance.checkOpaque()}`); // false
const uriInstance1 = new uri.URI("mailto:user@example.com");
console.info(`${uriInstance1.checkOpaque()}`); // true
```

### checkHierarchical<sup>12+</sup>

checkHierarchical(): boolean

Checks whether this URI is a hierarchical URI. The URI that starts with a slash (/) in scheme-specific-part is a hierarchical URI. Relative URIs are also hierarchical.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type   | Description                                        |
| ------- | -------------------------------------------- |
| boolean | **true**: The URI is a hierarchical URI.<br>**false**: The URI is not a hierarchical URI.|

**Example**

```ts
const uriInstance = new uri.URI("http://www.test.com/images/pic.jpg");
console.info(`${uriInstance.checkHierarchical()}`); // true
const uriInstance1 = new uri.URI("mailto:user@example.com");
console.info(`${uriInstance1.checkHierarchical()}`); // false
```

### getQueryValue<sup>12+</sup>

getQueryValue(key:string): string

Obtains the first value of a given key from the query component of this URI. If the query component contains encoded content, this API decodes the key before obtaining the value.

The query component follows the question mark (?) and consists of key-value pairs, separated by the at sign (&). In each key-value pair, the equal sign (=) is used to connect the key and value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                   |
| ------ | ------ | ---- | ----------------------- |
| key    | string | Yes  | Key of the URI query parameter.|

**Return value**

| Type  | Description                         |
| ------ | ----------------------------- |
| string | First value obtained. If no value is found, a null object is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
const uriInstance = new uri.URI("https://www.com?param1=value1&param2=value2");
console.info(uriInstance.getQueryValue("param1")); // value1
let uriInstance1 = new uri.URI('https://www.zyy.ss?sa%3D=po%7E');
console.info(uriInstance1.getQueryValue('sa=')) // po~
console.info(uriInstance1.getQueryValue('abc')) // null
```

### addQueryValue<sup>12+</sup>

addQueryValue(key:string, value:string): URI

Adds a query parameter to this URI to create a new URI, while keeping the existing URI unchanged.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                    |
| ------ | ------ | ---- | ------------------------ |
| key    | string | Yes  | Key of the query parameter.|
| value  | string | Yes  | Value of the query parameter.  |

**Return value**

| Type| Description                            |
| ---- | -------------------------------- |
| [URI](#uri)  | URI object with the query parameter.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
const uriInstance = new uri.URI("https://www.test.com");
const newRoute = uriInstance.addQueryValue("param1", "hello world");
console.info(newRoute.toString()); // https://www.test.com?param1=hello%20world
```

### addSegment<sup>12+</sup>

addSegment(pathSegment:string): URI

Encodes a given field, appends it to the path component of this URI to create a new URI, and returns the new URI, while keeping the existing URI unchanged.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name     | Type  | Mandatory| Description              |
| ----------- | ------ | ---- | ------------------ |
| pathSegment | string | Yes  | Field to be appended to the path component.|

**Return value**

| Type| Description                            |
| ---- | -------------------------------- |
| [URI](#uri)  | URI object with the appended field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
const uriInstance = new uri.URI("http://www.test.com");
const newRoute = uriInstance.addSegment("my image.jpg");
console.info(newRoute.toString()); // http://www.test.com/my%20image.jpg
```

### addEncodedSegment<sup>12+</sup>

addEncodedSegment(pathSegment:string): URI

Appends an encoded field to the path component of this URI to create a new URI and returns the new URI, while keeping the existing URI unchanged.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name     | Type  | Mandatory| Description              |
| ----------- | ------ | ---- | ------------------ |
| pathSegment | string | Yes  | Encoded field to be appended to the path component.|

**Return value**

| Type| Description                            |
| ---- | -------------------------------- |
| [URI](#uri)  | URI object with the appended field.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
const uriInstance = new uri.URI("http://www.test.com");
const newRoute = uriInstance.addEncodedSegment("my%20image.jpg");
console.info(newRoute.toString()); // http://www.test.com/my%20image.jpg
```

### getQueryNames<sup>12+</sup>

getQueryNames(): string[]

Obtains all non-repeated keys in the query component of this URI. The query component follows the question mark (?) and consists of key-value pairs, separated by the at sign (&). In each key-value pair, the equal sign (=) is used to connect the key and value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type       | Description                               |
| ----------- | ----------------------------------- |
| string[] | Non-repeated keys in the query component.|

**Example**

```ts
const uriInstance = new uri.URI("https://www.test.com?param1=value1&param2=value2");
const paramNames = uriInstance.getQueryNames();
console.info(Array.from(paramNames).toString()); // param1,param2
```

### getQueryValues<sup>12+</sup>

getQueryValues(key:string): string[]

Obtains the values of a given key from the query component of this URI. If the query component contains encoded content, this API decodes the keys before obtaining the values.

The query component follows the question mark (?) and consists of key-value pairs, separated by the at sign (&). In each key-value pair, the equal sign (=) is used to connect the key and value.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type  | Mandatory| Description                   |
| ------ | ------ | ---- | ----------------------- |
| key    | string | Yes  | Key of the URI query parameter.|

**Return value**

| Type    | Description                               |
| -------- | ----------------------------------- |
| string[] | Array of values obtained. If no value is found, an empty string array [] is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
const uriInstance = new uri.URI("https://www.test.com/search?query=name&query=my");
console.info(uriInstance.getQueryValues("query").toString()); // name,my
console.info(JSON.stringify(uriInstance.getQueryValues("abc"))); // []
```

### getBooleanQueryValue<sup>12+</sup>

getBooleanQueryValue(key:string,defaultValue:boolean): boolean

Obtains the value of the Boolean type of a query parameter in this URI.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name      | Type   | Mandatory| Description                                 |
| ------------ | ------- | ---- | ------------------------------------- |
| key          | string  | Yes  | Name of the query parameter.              |
| defaultValue | boolean | Yes  | Default value.|

**Return value**

| Type   | Description                                                                  |
| ------- | ---------------------------------------------------------------------- |
| boolean | If the specified query parameter does not exist, the default value is returned. If the first value of the query parameter is **false** or **0**, **false** is returned. Otherwise, **true** is returned.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
const uriInstance = new uri.URI("https://www.test.com/search?active=true");
console.info(`${uriInstance.getBooleanQueryValue("active", false)}`); // true
const uriInstance1 = new uri.URI("https://www.test.com/search");
console.info(`${uriInstance1.getBooleanQueryValue("active", false)}`); // false
const uriInstance2 = new uri.URI("https://www.test.com/search?active=aa&active=false");
console.info(`${uriInstance2.getBooleanQueryValue("active", false)}`); // true
const uriInstance3 = new uri.URI("https://www.test.com/search?active=0");
console.info(`${uriInstance3.getBooleanQueryValue("active", true)}`); // false
```

### clearQuery<sup>12+</sup>

clearQuery(): URI

Clears the query component of this URI to create a new URI, while keeping the existing URI object unchanged.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description                                 |
| ---- | ------------------------------------- |
| [URI](#uri)  | URI object whose query component has been cleared.|

**Example**

```ts
const uriInstance = new uri.URI("https://www.test.com?param1=value1");
console.info(uriInstance.clearQuery().toString()); // https://www.test.com
```

### getLastSegment<sup>12+</sup>

getLastSegment(): string

Obtains the last segment of this URI. A path includes multiple segments, separated by slashes (/). The part that ends with a slash is not a segment.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description                         |
| ---- | ----------------------------- |
| string  | Last segment of the URI.|

**Example**

```ts
const uriInstance = new uri.URI("content://com.test.provider/files/image.jpg");
console.info(uriInstance.getLastSegment()); // image.jpg
```

### getSegment<sup>12+</sup>

getSegment(): string[]

Obtains all segments of this URI.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type    | Description                       |
| -------- | --------------------------- |
| string[] | All segments of this URI.|

**Example**

```ts
const uriInstance = new uri.URI("http://www.test.com/path/to/image.jpg");
console.info(uriInstance.getSegment().toString()); // path,to,image.jpg
```

### createFromParts<sup>12+</sup>

createFromParts(scheme: string, ssp: string, fragment: string): URI

Creates a URI based on the provided scheme, scheme-specific-part, and fragment components.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name  | Type  | Mandatory| Description                           |
| -------- | ------ | ---- | ------------------------------- |
| scheme   | string | Yes  | Scheme of the URI.              |
| ssp      | string | Yes  | Scheme-specific-part of the URI.|
| fragment | string | Yes  | Fragment of this URI. The fragment component is the part following the number sign (#).            |

**Return value**

| Type| Description                                             |
| ---- | ------------------------------------------------- |
| [URI](#uri)  | URI object obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
const uriInstance = uri.URI.createFromParts("mailto", "no body", "top");
console.info(uriInstance.toString()); // mailto:no%20body#top
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

```ts
const uriInstance = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
const uriInstance1 = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
uriInstance.equals(uriInstance1); // true
```
