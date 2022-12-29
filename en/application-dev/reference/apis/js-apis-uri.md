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


### constructor

constructor(uri: string)

A constructor used to create a URI instance.

**System capability**: SystemCapability.Utils.Lang

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| uri | string | Yes| Input object.|

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
result.toString()
```


### equals<sup>(deprecated)</sup>

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [equalsTo<sup>9+</sup>](#equalsto9) instead.

equals(other: URI): boolean

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
const uriInstance1 = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da#fragment');
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
const uriInstance1 = new uri.URI('https://username:password@host:8080/directory/file?query=pppppp#qwer=da#fragment');
uriInstance.equalsTo(uriInstance1);
```

### checkIsAbsolute

checkIsAbsolute(): boolean

Checks whether this URI is an absolute URI (whether the scheme component is defined).

**System capability**: SystemCapability.Utils.Lang

**Return value**

| Type| Description|
| -------- | -------- |
| boolean | Returns **true** if the URI is an absolute URI; returns **false** otherwise.|

**Example**

```js
const uriInstance = new uri.URI('https://username:password@www.qwer.com:8080?query=pppppp');
uriInstance.checkIsAbsolute();
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
let uriInstance1 = uriInstance.normalize();
uriInstance1.path;
```
