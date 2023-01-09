# ChangeLog of JS API Changes in the URL Subsystem

Compared with OpenHarmony 3.2 Beta4, OpenHarmony 3.2.10.1(Mr) has the following API changes in the URL subsystem:

## cl.url.1 URLParams Class API Changes
APIs in the **URLParams** class in the URL subsystem are changed:

**constructor(init?: string[][] | Record<string, string> | string | URLSearchParams)** is changed to **constructor(init?: string[][] | Record<string, string> | string | URLParams)**, and the parameter type is changed from URLSearchParams to URLParams.

You need to adapt your application based on the following information.

**Change Impacts**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement functions in the SDK environment of the new version.

**Key API/Component Changes**

| Module   | Class     | Method/Attribute/Enumeration/Constant                                         | Change Type|
| :-------- | --------- | ------------------------------------------------------------ | -------- |
| @ohos.url | URLParams | constructor(string[][] \| Record&lt;string, string&gt; \| string \| URLSearchParams) | Deleted    |
| @ohos.url         | URLParams       | constructor(string[][] \| Record&lt;string, string&gt; \| string \| URLParams)| Changed|

**Adaptation Guide**

The following illustrates how to create a **URLParams** object in your application:

Example:

```ts
import url from '@ohos.url'
try {
    let params1 = new Url.URLParams('?user=abc&query=xyz')
    let params2 = new Url.URLParams(params1)
    var result= params2.toString()
    console.log(result) //"user=abc&query=xyz"
} catch (err) {
    console.error(`Fail to ceate URLParams.codeis${err.code},message is ${err.message}`);
}
```
## cl.url.2 URL Attribute Changes of URLParams Class APIs
URL attributes in the URL subsystem are changed:

The **searchParams: URLSearchParams** attribute is deprecated, and the **params: URLParams** attribute is added.

You need to adapt your application based on the following information.

**Change Impacts**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement functions in the SDK environment of the new version.

**Key API/Component Changes**

| Module   | Class| Method/Attribute/Enumeration/Constant           | Change Type       |
| :-------- | ---- | ------------------------------ | --------------- |
| @ohos.url | URL  | searchParams: URLSearchParams; | Deprecated (in API version 9)<br>|
| @ohos.url | URL  | params: URLParams;             | Added           |

**Adaptation Guide**

The following illustrates how to create a **URLParams** object in your application:

Example:

```ts
import url from '@ohos.url'
let that = new Url.URL('http://username:password@host:8080/directory/file?Hello=china#qwer=da')
let params = that.URLParams
var result = params.toString()
console.log(result) //%E4%BD%A0%E5%A5%BD=china
```
