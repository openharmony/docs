# System Parameter

> **NOTE**<br>
>
> - The initial APIs of this module are supported since API version 6. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - This is a system API and cannot be called by third-party applications.

## Modules to Import

```ts
import parameter from '@ohos.systemParameter'
```


## parameter.getSync

getSync(key: string, def?: string): string

Obtains the value of the attribute with the specified key.

**System capability**: SystemCapability.Startup.SysInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system attribute.|
| def | string | No| Default value.|

**Return value**

| Type| Description|
| -------- | -------- |
| string | System attribute value. If the specified key does not exist, the default value is returned. If no default value has been set, an empty string will be returned.|

**Example**

```ts
try {
    var info = parameter.getSync("test.parameter.key");
    console.log(JSON.stringify(info));
}catch(e){
    console.log("getSync unexpected error: " + e);
}
```


## parameter.get

get(key: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the value of the attribute with the specified key.

**System capability**: SystemCapability.Startup.SysInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system attribute.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result.|

**Example**

```ts
try {
    parameter.get("test.parameter.key", function (err, data) {
    if (err == undefined) {
        console.log("get test.parameter.key value success:" + data)
    } else {
        console.log(" get test.parameter.key value err:" + err.code)
    }});
}catch(e){
    console.log("get unexpected error: " + e);
}
```


## parameter.get

get(key: string, def: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the value of the attribute with the specified key.

**System capability**: SystemCapability.Startup.SysInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system attribute.|
| def | string | Yes| Default Value|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result.|

**Example**

```ts
try {
    parameter.get("test.parameter.key", "default", function (err, data) {
        if (err == undefined) {
            console.log("get test.parameter.key value success:" + data)
        } else {
            console.log(" get test.parameter.key value err:" + err.code)
        }
    });
}catch(e){
    console.log("get unexpected error:" + e)
}
```


## parameter.get

get(key: string, def?: string): Promise&lt;string&gt;

Obtains the value of the attribute with the specified key.

**System capability**: SystemCapability.Startup.SysInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system attribute.|
| def | string | No| Default Value|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;string&gt; | Promise used to return the execution result.|

**Example**

```ts
try {
    var p = parameter.get("test.parameter.key");
    p.then(function (value) {
        console.log("get test.parameter.key success: " + value);
    }).catch(function (err) {
        console.log("get test.parameter.key error: " + err.code);
    });
}catch(e){
    console.log("get unexpected error: " + e);
}
```


## parameter.setSync

setSync(key: string, value: string): void

Sets a value for the attribute with the specified key.

**System capability**: SystemCapability.Startup.SysInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system attribute.|
| value | string | Yes| System attribute value to set.|

**Example**

```ts
try {
    parameter.setSync("test.parameter.key", "default");
}catch(e){
    console.log("set unexpected error: " + e);
}
```


## parameter.set

set(key: string, value: string, callback: AsyncCallback&lt;void&gt;): void

Sets a value for the attribute with the specified key.

**System capability**: SystemCapability.Startup.SysInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system attribute.|
| value | string | Yes| System attribute value to set.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

```ts
try {
    parameter.set("test.parameter.key", "testValue", function (err, data) {
    if (err == undefined) {
        console.log("set test.parameter.key value success :" + data)
    } else {
        console.log("set test.parameter.key value err:" + err.code)
    }});
}catch(e){
    console.log("set unexpected error: " + e);
}
```


## parameter.set

set(key: string, value: string): Promise&lt;void&gt;

Sets a value for the attribute with the specified key.

**System capability**: SystemCapability.Startup.SysInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system attribute.|
| value| string | Yes| System attribute value to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the execution result.|

**Example**

```ts
try {
    var p = para.set("test.parameter.key", "testValue");
    p.then(function (value) {
        console.log("set test.parameter.key success: " + value);
    }).catch(function (err) {
        console.log(" set test.parameter.key error: " + err.code);
    });
}catch(e){
    console.log("set unexpected error: " + e);
}
```
