# @ohos.url (URL String Parsing)

The **url** module provides APIs for constructing [URLParams](#urlparams9) and [URL](#url) instances to process URL strings.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { url } from '@kit.ArkTS';
```
## URLParams<sup>9+</sup>

Defines APIs for handling URL query strings.

### constructor<sup>9+</sup>

constructor(init?: string[][] | Record&lt;string, string&gt; | string | URLParams)

A constructor used to create a **URLParams** instance.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| init | string[][] \| Record&lt;string, string&gt; \| string \| URLParams | No| Input parameter objects, which include the following:<br>- **string[][]**: two-dimensional string array<br>- **Record&lt;string, string&gt;**: list of objects<br>- **string**: string<br>- **URLParams**: object<br>The default value is **null**.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed. |

**Example**

```ts
// Construct a URLParams object in string[][] mode.
let objectParams = new url.URLParams([ ['user1', 'abc1'], ['query2', 'first2'], ['query3', 'second3'] ]);
// Construct a URLParams object in Record<string, string> mode.
let objectParams1 = new url.URLParams({"fod" : '1' , "bard" : '2'});
// Construct a URLParams object in string mode.
let objectParams2 = new url.URLParams('?fod=1&bard=2');
// Construct a URLParams object using the search attribute of the url object.
let urlObject = url.URL.parseURL('https://developer.mozilla.org/?fod=1&bard=2');
let objectParams3 = new url.URLParams(urlObject.search);
// Construct a URLParams object using the params attribute of the url object.
let urlObject1 = url.URL.parseURL('https://developer.mozilla.org/?fod=1&bard=2');
let objectParams4 = urlObject1.params;
```


### append<sup>9+</sup>

append(name: string, value: string): void

Appends a key-value pair into the query string.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key of the key-value pair to append.|
| value | string | Yes| Value of the key-value pair to append.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
let urlObject = url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new url.URLParams(urlObject.search.slice(1));
paramsObject.append('fod', '3');
```


### delete<sup>9+</sup>

delete(name: string): void

Deletes key-value pairs of the specified key.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key of the key-value pairs to delete.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
let urlObject = url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new url.URLParams(urlObject.search.slice(1));
paramsObject.delete('fod');
```


### getAll<sup>9+</sup>

getAll(name: string): string[]

Obtains all the values based on the specified key.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Target key.|

**Return value**

| Type| Description|
| -------- | -------- |
| string[] | All the values obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
let urlObject = url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
let params = new url.URLParams(urlObject.search.slice(1));
params.append('fod', '3'); // Add a second value for the fod parameter.
console.log(params.getAll('fod').toString()) // Output ["1","3"].
```


### entries<sup>9+</sup>

entries(): IterableIterator<[string, string]>

Obtains an ES6 iterator. Each item of the iterator is a JavaScript array, and the first and second fields of each array are the key and value respectively.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;[string, string]&gt; | ES6 iterator.|

**Example**

```ts
let searchParamsObject = new url.URLParams("keyName1=valueName1&keyName2=valueName2");
let pair:Iterable<Object[]> = searchParamsObject.entries();
let arrayValue = Array.from(pair);
for (let pair of arrayValue) { // Show keyName/valueName pairs
  console.log(pair[0]+ ', '+ pair[1]);
}
```


### forEach<sup>9+</sup>

forEach(callbackFn: (value: string, key: string, searchParams: URLParams) => void, thisArg?: Object): void

Traverses the key-value pairs in the **URLSearchParams** instance by using a callback.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackFn | function | Yes| Callback invoked to traverse the key-value pairs in the **URLSearchParams** instance.|
| thisArg | Object | No| Value of **this** to use when **callbackFn** is invoked. The default value is this object.|

**Table 1** callbackFn parameter description

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | string | Yes| Value that is currently traversed.|
| key | string | Yes| Key that is currently traversed.|
| searchParams | [URLParams](#urlparams9) | Yes| Instance that invokes the **forEach** method.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
const myURLObject = url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
myURLObject.params.forEach((value, name, searchParams) => {
    console.log(name, value, myURLObject.params === searchParams);
});
```


### get<sup>9+</sup>

get(name: string): string | null

Obtains the value of the first key-value pair based on the specified key.

> **NOTE**
>
> If the key-value pair does not exist, **undefined** is returned.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key specified to obtain the value.|

**Return value**

| Type| Description|
| -------- | -------- |
| string | Returns the value of the first key-value pair if obtained.|
| null | Returns **null** if no value is obtained.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
let paramsObject = new url.URLParams('name=Jonathan&age=18');
let name = paramsObject.get("name"); // is the string "Jonathan"
let age = paramsObject.get("age"); // is the string "18"
let getObj = paramsObject.get("abc"); // undefined
```


### has<sup>9+</sup>

has(name: string): boolean

Checks whether a key has a value.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key specified to search for its value.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the value exists; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types. |

**Example**

```ts
let urlObject = url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new url.URLParams(urlObject.search.slice(1));
let result = paramsObject.has('bard');
```


### set<sup>9+</sup>

set(name: string, value: string): void

Sets the value for a key. If key-value pairs matching the specified key exist, the value of the first key-value pair will be set to the specified value and other key-value pairs will be deleted. Otherwise, the key-value pair will be appended to the query string.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key of the value to set.|
| value | string | Yes| Value to set.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | -------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
let urlObject = url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new url.URLParams(urlObject.search.slice(1));
paramsObject.set('baz', '3'); // Add a third parameter.
```


### sort<sup>9+</sup>

sort(): void

Sorts all key-value pairs contained in this object based on the Unicode code points of the keys and returns undefined.  This method uses a stable sorting algorithm, that is, the relative order between key-value pairs with equal keys is retained.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let searchParamsObject = new url.URLParams("c=3&a=9&b=4&d=2"); // Create a test URLSearchParams object
searchParamsObject.sort(); // Sort the key/value pairs
console.log(searchParamsObject.toString()); // Display the sorted query string // Output a=9&b=4&c=3&d=2
```


### keys<sup>9+</sup>

keys(): IterableIterator&lt;string&gt;

Obtains an ES6 iterator that contains the keys of all the key-value pairs.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;string&gt; | ES6 iterator that contains the keys of all the key-value pairs.|

**Example**

```ts
let searchParamsObject = new url.URLParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
let keys = Array.from(searchParamsObject.keys());
for (let key of keys) { // Output key-value pairs
  console.log(key);
}
```


### values<sup>9+</sup>

values(): IterableIterator&lt;string&gt;

Obtains an ES6 iterator that contains the values of all the key-value pairs.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;string&gt; | ES6 iterator that contains the values of all the key-value pairs.|

**Example**

```ts
let searchParams = new url.URLParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
let values = Array.from(searchParams.values());
for (let value of values) {
  console.log(value);
}
```


### [Symbol.iterator]<sup>9+</sup>

[Symbol.iterator]\(): IterableIterator&lt;[string, string]&gt;

Obtains an ES6 iterator. Each item of the iterator is a JavaScript array, and the first and second fields of each array are the key and value respectively.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;[string, string]&gt; | ES6 iterator.|

**Example**

```ts
const paramsObject = new url.URLParams('fod=bay&edg=bap');
let iter: Iterable<Object[]> = paramsObject[Symbol.iterator]();
let pairs = Array.from(iter);
for (let pair of pairs) {
  console.log(pair[0] + ', ' + pair[1]);
}
```


### toString<sup>9+</sup>

toString(): string

Obtains search parameters that are serialized as a string and, if necessary, percent-encodes the characters in the string.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| string | String of serialized search parameters, which is percent-encoded if necessary.|

**Example**

```ts
let urlObject = url.URL.parseURL('https://developer.exampleUrl/?fod=1&bard=2');
let params = new url.URLParams(urlObject.search.slice(1));
params.append('fod', '3');
console.log(params.toString());
```

## URL

Provides APIs for parsing, constructing, standardizing, and encoding URL strings.

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| hash | string | Yes| Yes| String that contains a harsh mark (#) followed by the fragment identifier of a URL. **Atomic service API**: This API can be used in atomic services since API version 11.|
| host | string | Yes| Yes| Host information in a URL. **Atomic service API**: This API can be used in atomic services since API version 11.|
| hostname | string | Yes| Yes| Hostname (without the port) in a URL. **Atomic service API**: This API can be used in atomic services since API version 11.|
| href | string | Yes| Yes| String that contains the whole URL. **Atomic service API**: This API can be used in atomic services since API version 11.|
| origin | string | Yes| No| Read-only string that contains the Unicode serialization of the origin of the represented URL. **Atomic service API**: This API can be used in atomic services since API version 11.|
| password | string | Yes| Yes| Password in a URL. **Atomic service API**: This API can be used in atomic services since API version 11.|
| pathname | string | Yes| Yes| Path in a URL. **Atomic service API**: This API can be used in atomic services since API version 11.|
| port | string | Yes| Yes| Port in a URL. **Atomic service API**: This API can be used in atomic services since API version 11.|
| protocol | string | Yes| Yes| Protocol in a URL. **Atomic service API**: This API can be used in atomic services since API version 11.|
| search | string | Yes| Yes| Serialized query string in a URL. **Atomic service API**: This API can be used in atomic services since API version 11.|
| searchParams<sup>(deprecated)</sup> | [URLSearchParams](#urlsearchparamsdeprecated) | Yes| No| **URLSearchParams** object allowing access to the query parameters in a URL.<br>- **NOTE**: This attribute is supported since API version 7 and is deprecated since API version 9. You are advised to use params<sup>9+</sup> instead.|
| params<sup>9+</sup> | [URLParams](#urlparams9) | Yes| No| **URLParams** object allowing access to the query parameters in a URL. **Atomic service API**: This API can be used in atomic services since API version 11.|
| username | string | Yes| Yes| Username in a URL. **Atomic service API**: This API can be used in atomic services since API version 11.|

**Example**

```ts
let that = url.URL.parseURL('http://username:password@host:8080/directory/file?foo=1&bar=2#fragment');
console.log("hash " + that.hash) // hash #fragment
console.log("host " + that.host) // host host:8080
console.log("hostname " + that.hostname) // hostname host
console.log("href " + that.href) // href http://username:password@host:8080/directory/file?foo=1&bar=2#fragment
console.log("origin " + that.origin) // origin http://host:8080
console.log("password " + that.password) // password password
console.log("pathname " + that.pathname) // pathname /directory/file
console.log("port " + that.port) // port 8080
console.log("protocol " + that.protocol) // protocol http:
console.log("search " + that.search) // search ?foo=1&bar=2
console.log("username " + that.username) // username username
// The return value of that.params is a URLParams object.
console.log("params: foo " + that.params.get("foo")) // params: foo 1
```

### constructor<sup>(deprecated)</sup>

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [parseURL<sup>9+</sup>](#parseurl9) instead.

constructor(url: string, base?: string | URL)

Creates a URL.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| url | string | Yes| Input object.|
| base | string \| URL | No| Input parameter, which can be any of the following:<br>- **string**: string<br>- **URL**: string or object<br>The default value is an empty string or an empty object.|

**Example**

```ts
let mm = 'https://username:password@host:8080';
let a = new url.URL("/", mm); // Output 'https://username:password@host:8080/';
let b = new url.URL(mm); // Output 'https://username:password@host:8080/';
new url.URL('path/path1', b); // Output 'https://username:password@host:8080/path/path1';
let c = new url.URL('/path/path1', b);  // Output 'https://username:password@host:8080/path/path1'; 
new url.URL('/path/path1', c); // Output 'https://username:password@host:8080/path/path1';
new url.URL('/path/path1', a); // Output 'https://username:password@host:8080/path/path1';
new url.URL('/path/path1', "https://www.exampleUrl/fr-FR/toot"); // Output https://www.exampleUrl/path/path1
new url.URL('/path/path1', ''); // Raises a TypeError exception as '' is not a valid URL
new url.URL('/path/path1'); // Raises a TypeError exception as '/path/path1' is not a valid URL
new url.URL('https://www.example.com', ); // Output https://www.example.com/
new url.URL('https://www.example.com', b); // Output https://www.example.com/
```

### constructor<sup>9+</sup>

constructor()

A no-argument constructor used to create a URL. It returns a **URL** object after **parseURL** is called. It is not used independently.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

### parseURL<sup>9+</sup>

static parseURL(url: string, base?: string | URL): URL

Parses a URL.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| url | string | Yes| Input object.|
| base | string \| URL | No| Input parameter, which can be any of the following:<br>- **string**: string<br>- **URL**: string or object<br>The default value is an empty string or an empty object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Utils Error Codes](errorcode-utils.md).

| ID| Error Message|
| -------- | -------- |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |
| 10200002 | Invalid url string. |

**Example**

```ts
let mm = 'https://username:password@host:8080';
let urlObject = url.URL.parseURL(mm);
let result = urlObject.toString(); // Output 'https://username:password@host:8080/'
```

### toString

toString(): string

Converts the parsed URL into a string.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| string | Website address in a serialized string.|

**Example**

```ts
const urlObject = url.URL.parseURL('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
let result = urlObject.toString();
```

### toJSON

toJSON(): string

Converts the parsed URL into a JSON string.

**Atomic service API**: This API can be used in atomic services since API version 11.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| string | Website address in a serialized string.|

**Example**
```ts
const urlObject = url.URL.parseURL('https://username:password@host:8080/directory/file?query=pppppp#qwer=da');
let result = urlObject.toJSON();
```

## URLSearchParams<sup>(deprecated)</sup>

Defines APIs for handling URL query strings.

This class is deprecated since API version 9. You are advised to use [URLParams](#urlparams9) instead.

### constructor<sup>(deprecated)</sup>

constructor(init?: string[][] | Record&lt;string, string&gt; | string | URLSearchParams)

A constructor used to create a **URLSearchParams** instance.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [URLParams.constructor<sup>9+</sup>](#constructor9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| init | string[][] \| Record&lt;string, string&gt; \| string \| URLSearchParams | No| Input parameter objects, which include the following:<br>- **string[][]**: two-dimensional string array<br>- **Record&lt;string, string&gt;**: list of objects<br>- **string**: string<br>- **URLSearchParams**: object<br>The default value is **null**.|

**Example**

```ts
let objectParams = new url.URLSearchParams([ ['user1', 'abc1'], ['query2', 'first2'], ['query3', 'second3'] ]);
let objectParams1 = new url.URLSearchParams({"fod" : '1' , "bard" : '2'});
let objectParams2 = new url.URLSearchParams('?fod=1&bard=2');
let urlObject = new url.URL('https://developer.mozilla.org/?fod=1&bard=2');
let params = new url.URLSearchParams(urlObject.search);
```

### append<sup>(deprecated)</sup>

append(name: string, value: string): void

Appends a key-value pair into the query string.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [URLParams.append<sup>9+</sup>](#append9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key of the key-value pair to append.|
| value | string | Yes| Value of the key-value pair to append.|

**Example**

```ts
let urlObject = new url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new url.URLSearchParams(urlObject.search.slice(1));
paramsObject.append('fod', '3');
```

### delete<sup>(deprecated)</sup>

delete(name: string): void

Deletes key-value pairs of the specified key.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [URLParams.delete<sup>9+</sup>](#delete9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key of the key-value pairs to delete.|

**Example**

```ts
let urlObject = new url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsobject = new url.URLSearchParams(urlObject.search.slice(1));
paramsobject.delete('fod');
```

### getAll<sup>(deprecated)</sup>

getAll(name: string): string[]

Obtains all the key-value pairs based on the specified key.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [URLParams.getAll<sup>9+</sup>](#getall9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Target key.|

**Return value**

| Type| Description|
| -------- | -------- |
| string[] | All key-value pairs matching the specified key.|

**Example**

```ts
let urlObject = new url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let params = new url.URLSearchParams(urlObject.search.slice(1));
params.append('fod', '3'); // Add a second value for the fod parameter.
console.log(params.getAll('fod').toString()) // Output ["1","3"].
```

### entries<sup>(deprecated)</sup>

entries(): IterableIterator<[string, string]>

Obtains an ES6 iterator. Each item of the iterator is a JavaScript array, and the first and second fields of each array are the key and value respectively.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [URLParams.entries<sup>9+</sup>](#entries9) instead.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;[string, string]&gt; | ES6 iterator.|

**Example**

```ts
let searchParamsObject = new url.URLSearchParams("keyName1=valueName1&keyName2=valueName2");
let iter: Iterable<Object[]> = searchParamsObject.entries();
let pairs = Array.from(iter);
for (let pair of pairs) { // Show keyName/valueName pairs
  console.log(pair[0]+ ', '+ pair[1]);
}
```


### forEach<sup>(deprecated)</sup>

forEach(callbackFn: (value: string, key: string, searchParams: URLSearchParams) => void, thisArg?: Object): void

Traverses the key-value pairs in the **URLSearchParams** instance by using a callback.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [URLParams.forEach<sup>9+</sup>](#foreach9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackFn | function | Yes| Callback invoked to traverse the key-value pairs in the **URLSearchParams** instance.|
| thisArg | Object | No| Value of **this** to use when **callbackFn** is invoked. The default value is this object.|

**Table 1** callbackFn parameter description

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | string | Yes| Value that is currently traversed.|
| key | string | Yes| Key that is currently traversed.|
| searchParams | [URLSearchParams](#urlsearchparamsdeprecated) | Yes| Instance that invokes the **forEach** method.|

**Example**

```ts
const myURLObject = new url.URL('https://developer.exampleUrl/?fod=1&bard=2');
myURLObject.searchParams.forEach((value, name, searchParams) => {
    console.log(name, value, myURLObject.searchParams === searchParams);
});
```


### get<sup>(deprecated)</sup>

get(name: string): string | null

Obtains the value of the first key-value pair based on the specified key.

> **NOTE**
>
> If the key-value pair does not exist, **undefined** is returned.
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [URLParams.get<sup>9+</sup>](#get9) instead.


**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key specified to obtain the value.|

**Return value**

| Type| Description|
| -------- | -------- |
| string | Returns the value of the first key-value pair if obtained.|
| null | Returns **null** if no value is obtained.|

**Example**

```ts
let paramsObject = new url.URLSearchParams('name=Jonathan&age=18');
let name = paramsObject.get("name"); // is the string "Jonathan"
let age = paramsObject.get("age"); // is the string '18'
let getObj = paramsObject.get("abc"); // undefined
```


### has<sup>(deprecated)</sup>

has(name: string): boolean

Checks whether a key has a value.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [URLParams.has<sup>9+</sup>](#has9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key specified to search for its value.|

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the value exists; returns **false** otherwise.|

**Example**

```ts
let urlObject = new url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new url.URLSearchParams(urlObject.search.slice(1));
paramsObject.has('bard') === true;
```


### set<sup>(deprecated)</sup>

set(name: string, value: string): void

Sets the value for a key. If key-value pairs matching the specified key exist, the value of the first key-value pair will be set to the specified value and other key-value pairs will be deleted. Otherwise, the key-value pair will be appended to the query string.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [URLParams.set<sup>9+</sup>](#set9) instead.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key of the value to set.|
| value | string | Yes| Value to set.|

**Example**

```ts
let urlObject = new url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new url.URLSearchParams(urlObject.search.slice(1));
paramsObject.set('baz', '3'); // Add a third parameter.
```


### sort<sup>(deprecated)</sup>

sort(): void

Sorts all key-value pairs contained in this object based on the Unicode code points of the keys and returns undefined.  This method uses a stable sorting algorithm, that is, the relative order between key-value pairs with equal keys is retained.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [URLParams.sort<sup>9+</sup>](#sort9) instead.

**System capability**: SystemCapability.Utils.Lang

**Example**

```ts
let searchParamsObject = new url.URLSearchParams("c=3&a=9&b=4&d=2"); // Create a test URLSearchParams object
searchParamsObject.sort(); // Sort the key/value pairs
console.log(searchParamsObject.toString()); // Display the sorted query string // Output a=9&b=4&c=3&d=2
```


### keys<sup>(deprecated)</sup>

keys(): IterableIterator&lt;string&gt;

Obtains an ES6 iterator that contains the keys of all the key-value pairs.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [URLParams.keys<sup>9+</sup>](#keys9) instead.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;string&gt; | ES6 iterator that contains the keys of all the key-value pairs.|

**Example**

```ts
let searchParamsObject = new url.URLSearchParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
let keys = Array.from(searchParamsObject.keys());
for (let key of keys) { // Output key-value pairs
  console.log(key);
}
```


### values<sup>(deprecated)</sup>

values(): IterableIterator&lt;string&gt;

Obtains an ES6 iterator that contains the values of all the key-value pairs.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [URLParams.values<sup>9+</sup>](#values9) instead.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;string&gt; | ES6 iterator that contains the values of all the key-value pairs.|

**Example**

```ts
let searchParams = new url.URLSearchParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
let values = Array.from(searchParams.values());
for (let value of values) {
  console.log(value);
}
```


### [Symbol.iterator]<sup>(deprecated)</sup>

[Symbol.iterator]\(): IterableIterator&lt;[string, string]&gt;

Obtains an ES6 iterator. Each item of the iterator is a JavaScript array, and the first and second fields of each array are the key and value respectively.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [URLParams.[Symbol.iterator]<sup>9+</sup>](#symboliterator9) instead.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;[string, string]&gt; | ES6 iterator.|

**Example**

```ts
const paramsObject = new url.URLSearchParams('fod=bay&edg=bap');
let iter: Iterable<Object[]> = paramsObject[Symbol.iterator]();
let pairs = Array.from(iter);
for (let pair of pairs) {
  console.log(pair[0] + ', ' + pair[1]);
}
```

### toString<sup>(deprecated)</sup>

toString(): string

Obtains search parameters that are serialized as a string and, if necessary, percent-encodes the characters in the string.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [URLParams.toString<sup>9+</sup>](#tostring9) instead.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| string | String of serialized search parameters, which is percent-encoded if necessary.|

**Example**

```ts
let urlObject = new url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let params = new url.URLSearchParams(urlObject.search.slice(1));
params.append('fod', '3');
console.log(params.toString());
```
<!--no_check-->
