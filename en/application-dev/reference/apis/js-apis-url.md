# URL String Parsing

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```
import Url from '@ohos.url' 
```
## URLParams<sup>9+</sup>


### constructor<sup>9+</sup>

constructor(init?: string[][] | Record&lt;string, string&gt; | string | URLParams)

A constructor used to create a **URLParams** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| init | string[][] \| Record&lt;string, string&gt; \| string \| URLParams | No| Input parameter objects, which include the following:<br>- **string[][]**: two-dimensional string array<br>- **Record&lt;string, string&gt;**: list of objects<br>- **string**: string<br>- **URLParams**: object|

**Example**

```js
let objectParams = new Url.URLParams([ ['user1', 'abc1'], ['query2', 'first2'], ['query3', 'second3'] ]);
let objectParams1 = new Url.URLParams({"fod" : '1' , "bard" : '2'});
let objectParams2 = new Url.URLParams('?fod=1&bard=2');
let urlObject = new Url.URL('https://developer.mozilla.org/?fod=1&bard=2');
let params = new Url.URLParams(urlObject.search);
```


### append<sup>9+</sup>

append(name: string, value: string): void

Appends a key-value pair into the query string.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key of the key-value pair to append.|
| value | string | Yes| Value of the key-value pair to append.|

**Example**

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new Url.URLParams(urlObject.search.slice(1));
paramsObject.append('fod', '3');
```


### delete<sup>9+</sup>

delete(name: string): void

Deletes key-value pairs of the specified key.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key of the key-value pairs to delete.|

**Example**

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsobject = new Url.URLParams(urlObject.search.slice(1));
paramsobject.delete('fod');
```


### getAll<sup>9+</sup>

getAll(name: string): string[]

Obtains all the key-value pairs based on the specified key.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key specified to obtain all key-value pairs.|

**Return value**

| Type| Description|
| -------- | -------- |
| string[] | All key-value pairs matching the specified key.|

**Example**

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let params = new Url.URLParams(urlObject.search.slice(1));
params.append('fod', '3'); // Add a second value for the fod parameter.
console.log(params.getAll('fod').toString()) // Output ["1","3"].
```


### entries<sup>9+</sup>

entries(): IterableIterator<[string, string]>

Obtains an ES6 iterator. Each item of the iterator is a JavaScript array, and the first and second fields of each array are the key and value respectively.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;[string, string]&gt; | ES6 iterator.|

**Example**

```js
let searchParamsObject = new Url.URLParams("keyName1=valueName1&keyName2=valueName2"); 
for (var pair of searchParamsObject .entries()) { // Show keyName/valueName pairs
    console.log(pair[0]+ ', '+ pair[1]);
}
```


### forEach<sup>9+</sup>

forEach(callbackfn: (value: string, key: string, searchParams: this) => void, thisArg?: Object): void

Traverses the key-value pairs in the **URLSearchParams** instance by using a callback.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackfn | function | Yes| Callback invoked to traverse the key-value pairs in the **URLSearchParams** instance.|
| thisArg | Object | No| Value to use when the callback is invoked.|

**Table 1** callbackfn parameter description

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | string | Yes| Value that is currently traversed.|
| key | string | Yes| Key that is currently traversed.|
| searchParams | Object | Yes| Instance that invokes the **forEach** method.|

**Example**

```js
const myURLObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2'); 
myURLObject.URLParams.forEach((value, name, searchParams) => {  
    console.log(name, value, myURLObject.searchParams === searchParams);
});
```


### get<sup>9+</sup>

get(name: string): string | null

Obtains the value of the first key-value pair based on the specified key.

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

```js
let paramsObject = new Url.URLParams('name=Jonathan&age=18'); 
let name = paramsObject.get("name"); // is the string "Jonathan" 
let age = parseInt(paramsObject.get("age"), 10); // is the number 18
```


### has<sup>9+</sup>

has(name: string): boolean

Checks whether a key has a value.

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

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new Url.URLParams(urlObject.search.slice(1)); 
paramsObject.has('bard') === true;
```


### set<sup>9+</sup>

set(name: string, value: string): void

Sets the value for a key. If key-value pairs matching the specified key exist, the value of the first key-value pair will be set to the specified value and other key-value pairs will be deleted. Otherwise, the key-value pair will be appended to the query string.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key of the value to set.|
| value | string | Yes| Value to set.|

**Example**

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new Url.URLParams(urlObject.search.slice(1));
paramsObject.set('baz', '3'); // Add a third parameter.
```


### sort<sup>9+</sup>

sort(): void

Sorts all key-value pairs contained in this object based on the Unicode code points of the keys and returns undefined.  This method uses a stable sorting algorithm, that is, the relative order between key-value pairs with equal keys is retained.

**System capability**: SystemCapability.Utils.Lang

**Example**

```js
let searchParamsObject = new Url.URLParams("c=3&a=9&b=4&d=2"); // Create a test URLSearchParams object
searchParamsObject.sort(); // Sort the key/value pairs
console.log(searchParamsObject.toString()); // Display the sorted query string // Output a=9&b=2&c=3&d=4
```


### keys<sup>9+</sup>

keys(): IterableIterator&lt;string&gt;

Obtains an ES6 iterator that contains the keys of all the key-value pairs.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;string&gt; | ES6 iterator that contains the keys of all the key-value pairs.|

**Example**

```js
let searchParamsObject = new Url.URLParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
for (var key of searchParamsObject .keys()) { // Output key-value pairs
    console.log(key);
}
```


### values<sup>9+</sup>

values(): IterableIterator&lt;string&gt;

Obtains an ES6 iterator that contains the values of all the key-value pairs.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;string&gt; | ES6 iterator that contains the values of all the key-value pairs.|

**Example**

```js
let searchParams = new Url.URLParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
for (var value of searchParams.values()) {
    console.log(value);
}
```


### [Symbol.iterator]<sup>9+</sup>

[Symbol.iterator]\(): IterableIterator&lt;[string, string]&gt;

Obtains an ES6 iterator. Each item of the iterator is a JavaScript array, and the first and second fields of each array are the key and value respectively.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;[string, string]&gt; | ES6 iterator.|

**Example**

```js
const paramsObject = new Url.URLParams('fod=bay&edg=bap');
for (const [name, value] of paramsObject) {
    console.log(name, value); 
} 
```


### tostring<sup>9+</sup>

toString(): string

Obtains search parameters that are serialized as a string and, if necessary, percent-encodes the characters in the string.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| string | String of serialized search parameters, which is percent-encoded if necessary.|

**Example**

```js
let url = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let params = new Url.URLParams(url.search.slice(1)); 
params.append('fod', '3');
console.log(params.toString());
```

## URLSearchParams<sup>(deprecated)</sup>

### constructor<sup>(deprecated)</sup>

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [URLParams<sup>9+</sup>](#constructor9+) instead.

constructor(init?: string[][] | Record&lt;string, string&gt; | string | URLSearchParams)

A constructor used to create a **URLSearchParams** instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| init | string[][] \| Record&lt;string, string&gt; \| string \| URLSearchParams | No| Input parameter objects, which include the following:<br>- **string[][]**: two-dimensional string array<br>- **Record&lt;string, string&gt;**: list of objects<br>- **string**: string<br>- **URLSearchParams**: object|

**Example**

```js
let objectParams = new Url.URLSearchParams([ ['user1', 'abc1'], ['query2', 'first2'], ['query3', 'second3'] ]);
let objectParams1 = new Url.URLSearchParams({"fod" : '1' , "bard" : '2'});
let objectParams2 = new Url.URLSearchParams('?fod=1&bard=2');
let urlObject = new Url.URL('https://developer.mozilla.org/?fod=1&bard=2');
let params = new Url.URLSearchParams(urlObject.search);
```

### append<sup>(deprecated)</sup>

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [URLParams<sup>9+</sup>.append<sup>9+</sup>](#append9) instead.

append(name: string, value: string): void

Appends a key-value pair into the query string.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key of the key-value pair to append.|
| value | string | Yes| Value of the key-value pair to append.|

**Example**

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new Url.URLSearchParams(urlObject.search.slice(1));
paramsObject.append('fod', '3');
```

### delete<sup>(deprecated)</sup>

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [URLParams<sup>9+</sup>.delete<sup>9+</sup>](#delete9) instead.

delete(name: string): void

Deletes key-value pairs of the specified key.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key of the key-value pairs to delete.|

**Example**

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsobject = new Url.URLSearchParams(urlObject.search.slice(1));
paramsobject.delete('fod');
```

### getAll<sup>(deprecated)</sup>

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [URLParams<sup>9+</sup>.getAll<sup>9+</sup>](#getall9) instead.

getAll(name: string): string[]

Obtains all the key-value pairs based on the specified key.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key specified to obtain all key-value pairs.|

**Return value**

| Type| Description|
| -------- | -------- |
| string[] | All key-value pairs matching the specified key.|

**Example**

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let params = new Url.URLSearchParams(urlObject.search.slice(1));
params.append('fod', '3'); // Add a second value for the fod parameter.
console.log(params.getAll('fod').toString()) // Output ["1","3"].
```

### entries<sup>(deprecated)</sup>

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [URLParams<sup>9+</sup>.entries<sup>9+</sup>](#entries9) instead.

entries(): IterableIterator<[string, string]>

Obtains an ES6 iterator. Each item of the iterator is a JavaScript array, and the first and second fields of each array are the key and value respectively.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;[string, string]&gt; | ES6 iterator.|

**Example**

```js
let searchParamsObject = new Url.URLSearchParams("keyName1=valueName1&keyName2=valueName2"); 
for (var pair of searchParamsObject .entries()) { // Show keyName/valueName pairs
    console.log(pair[0]+ ', '+ pair[1]);
}
```


### forEach<sup>(deprecated)</sup>
> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [URLParams<sup>9+</sup>.forEach<sup>9+</sup>](#foreach9) instead.

forEach(callbackfn: (value: string, key: string, searchParams: this) => void, thisArg?: Object): void

Traverses the key-value pairs in the **URLSearchParams** instance by using a callback.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callbackfn | function | Yes| Callback invoked to traverse the key-value pairs in the **URLSearchParams** instance.|
| thisArg | Object | No| Value to use when the callback is invoked.|

**Table 1** callbackfn parameter description

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| value | string | Yes| Value that is currently traversed.|
| key | string | Yes| Key that is currently traversed.|
| searchParams | Object | Yes| Instance that invokes the **forEach** method.|

**Example**

```js
const myURLObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2'); 
myURLObject.searchParams.forEach((value, name, searchParams) => {  
    console.log(name, value, myURLObject.searchParams === searchParams);
});
```


### get<sup>(deprecated)</sup>
> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [URLParams<sup>9+</sup>.get<sup>9+</sup>](#get9) instead.

get(name: string): string | null

Obtains the value of the first key-value pair based on the specified key.

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

```js
let paramsObject = new Url.URLSearchParams('name=Jonathan&age=18'); 
let name = paramsObject.get("name"); // is the string "Jonathan" 
let age = parseInt(paramsObject.get("age"), 10); // is the number 18
```


### has<sup>(deprecated)</sup>
> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [URLParams<sup>9+</sup>.has<sup>9+</sup>](#has9) instead.

has(name: string): boolean

Checks whether a key has a value.

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

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new Url.URLSearchParams(urlObject.search.slice(1)); 
paramsObject.has('bard') === true;
```


### set<sup>(deprecated)</sup>
> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [URLParams<sup>9+</sup>.set<sup>9+</sup>](#set9) instead.

set(name: string, value: string): void

Sets the value for a key. If key-value pairs matching the specified key exist, the value of the first key-value pair will be set to the specified value and other key-value pairs will be deleted. Otherwise, the key-value pair will be appended to the query string.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| name | string | Yes| Key of the value to set.|
| value | string | Yes| Value to set.|

**Example**

```js
let urlObject = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let paramsObject = new Url.URLSearchParams(urlObject.search.slice(1));
paramsObject.set('baz', '3'); // Add a third parameter.
```


### sort<sup>(deprecated)</sup>
> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [URLParams<sup>9+</sup>.sort<sup>9+</sup>](#sort9) instead.

sort(): void

Sorts all key-value pairs contained in this object based on the Unicode code points of the keys and returns undefined.  This method uses a stable sorting algorithm, that is, the relative order between key-value pairs with equal keys is retained.

**System capability**: SystemCapability.Utils.Lang

**Example**

```js
let searchParamsObject = new Url.URLSearchParams("c=3&a=9&b=4&d=2"); // Create a test URLSearchParams object
searchParamsObject.sort(); // Sort the key/value pairs
console.log(searchParamsObject.toString()); // Display the sorted query string // Output a=9&b=2&c=3&d=4
```


### keys<sup>(deprecated)</sup>
> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [URLParams<sup>9+</sup>.keys<sup>9+</sup>](#keys9) instead.

keys(): IterableIterator&lt;string&gt;

Obtains an ES6 iterator that contains the keys of all the key-value pairs.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;string&gt; | ES6 iterator that contains the keys of all the key-value pairs.|

**Example**

```js
let searchParamsObject = new Url.URLSearchParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
for (var key of searchParamsObject .keys()) { // Output key-value pairs
    console.log(key);
}
```


### values<sup>(deprecated)</sup>
> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [URLParams<sup>9+</sup>.values<sup>9+</sup>](#values9) instead.

values(): IterableIterator&lt;string&gt;

Obtains an ES6 iterator that contains the values of all the key-value pairs.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;string&gt; | ES6 iterator that contains the values of all the key-value pairs.|

**Example**

```js
let searchParams = new Url.URLSearchParams("key1=value1&key2=value2"); // Create a URLSearchParamsObject object for testing
for (var value of searchParams.values()) {
    console.log(value);
}
```


### [Symbol.iterator]<sup>(deprecated)</sup>

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [[Symbol.iterator]<sup>9+</sup>](#symboliterator9) instead.


[Symbol.iterator]\(): IterableIterator&lt;[string, string]&gt;

Obtains an ES6 iterator. Each item of the iterator is a JavaScript array, and the first and second fields of each array are the key and value respectively.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| IterableIterator&lt;[string, string]&gt; | ES6 iterator.|

**Example**

```js
const paramsObject = new Url.URLSearchParams('fod=bay&edg=bap');
for (const [name, value] of paramsObject) {
    console.log(name, value); 
} 
```

### tostring<sup>(deprecated)</sup>
> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [URLParams<sup>9+</sup>.tostring<sup>9+</sup>](#tostring9) instead.

toString(): string

Obtains search parameters that are serialized as a string and, if necessary, percent-encodes the characters in the string.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| string | String of serialized search parameters, which is percent-encoded if necessary.|

**Example**

```js
let url = new Url.URL('https://developer.exampleUrl/?fod=1&bard=2');
let params = new Url.URLSearchParams(url.search.slice(1)); 
params.append('fod', '3');
console.log(params.toString());
```

## URL

### Attributes

**System capability**: SystemCapability.Utils.Lang

| Name| Type| Readable| Writable| Description|
| -------- | -------- | -------- | -------- | -------- |
| hash | string | Yes| Yes| String that contains a harsh mark (#) followed by the fragment identifier of a URL.|
| host | string | Yes| Yes| Host information in a URL.|
| hostname | string | Yes| Yes| Hostname (without the port) in a URL.|
| href | string | Yes| Yes| String that contains the whole URL.|
| origin | string | Yes| No| Read-only string that contains the Unicode serialization of the origin of the represented URL.|
| password | string | Yes| Yes| Password in a URL.|
| pathname | string | Yes| Yes| Path in a URL.|
| port | string | Yes| Yes| Port in a URL.|
| protocol | string | Yes| Yes| Protocol in a URL.|
| search | string | Yes| Yes| Serialized query string in a URL.|
| searchParams | URLsearchParams | Yes| No| **URLSearchParams** object allowing access to the query parameters in a URL.|
| URLParams | URLParams | Yes| No| **URLParams** object allowing access to the query parameters in a URL.|
| username | string | Yes| Yes| Username in a URL.|


### constructor

constructor(url?: string, base?: string | URL)

Creates a URL.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| url | string | Yes| Input object.|
| base | string \| URL | No| Input parameter, which can be any of the following:<br>- **string**: string<br>- **URL**: string or object|

**Example**

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
new Url.URL('http://www.shanxi.com', ); // Output http://www.shanxi.com/
new Url.URL('http://www.shanxi.com', b); // Output http://www.shanxi.com/
```

### parseURL<sup>9+</sup>

static parseURL(inputUrl : string, inputBase ?: string | URL)

Parses a URL.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| inputUrl | string | Yes| Input object.|
| inputBase | string \| URL | No| Input parameter, which can be any of the following:<br>- **string**: string<br>- **URL**: string or object|

**Example**

```js
let mm = 'http://username:password@host:8080';
Url.URL.parseURL(mm); // Output 'http://username:password@host:8080/';
```

### tostring

toString(): string

Converts the parsed URL into a string.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| string | Website address in a serialized string.|

**Example**

```js
const url = new Url.URL('http://username:password@host:8080/directory/file?query=pppppp#qwer=da');
url.toString();
```


### toJSON

toJSON(): string

Converts the parsed URL into a JSON string.

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| string | Website address in a serialized string.|

**Example**
```js
const url = new Url.URL('http://username:password@host:8080/directory/file?query=pppppp#qwer=da');
url.toJSON();
```
<!--no_check-->
