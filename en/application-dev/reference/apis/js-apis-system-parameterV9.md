# SystemParameter

The **SystemParameter** module provides system services with easy access to key-value pairs. You can use the APIs provided by this module to describe the service status and change the service behavior. The basic operation primitives are get and set. You can obtain the values of system parameters through getters and modify the values through setters.
For details about the system parameter design principles and definitions, see
[Service Management](../../../device-dev/subsystems/subsys-boot-init-sysparam.md).

> **NOTE**
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.
> - Third-party applications cannot use the APIs provided by this module, because system parameters each require specific discretionary access control (DAC) and MAC permissions.

## Modules to Import

```ts
import systemparameter from '@ohos.systemParameterV9'
```

## systemparameter.getSync

getSync(key: string, def?: string): string

Obtains the value of the system parameter with the specified key.

**System capability**: SystemCapability.Startup.SystemInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system parameter.|
| def | string | No| Default value.|

**Return value**

| Type| Description|
| -------- | -------- |
| string | Value of the system parameter. If the specified key does not exist, the default value is returned. If no default value has been set, an empty string will be returned.|

**Example**

```ts
try {
    var info = systemparameter.getSync("const.ohos.apiversion");
    console.log(JSON.stringify(info));
}catch(e){
    console.log("getSync unexpected error: " + e);
}
```

## systemparameter.get

get(key: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the value of the system parameter with the specified key.

**System capability**: SystemCapability.Startup.SystemInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system parameter.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result.|

**Example**

```ts
try {
    systemparameter.get("const.ohos.apiversion", function (err, data) {
    if (err == undefined) {
        console.log("get test.parameter.key value success:" + data)
    } else {
        console.log(" get test.parameter.key value err:" + err.code)
    }});
}catch(e){
    console.log("get unexpected error: " + e);
}
```

## systemparameter.get

get(key: string, def: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the value of the system parameter with the specified key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Startup.SystemInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system parameter.|
| def | string | Yes| Default value.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result.|

**Example**

```ts
try {
    systemparameter.get("const.ohos.apiversion", "default", function (err, data) {
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

## systemparameter.get

get(key: string, def?: string): Promise&lt;string&gt;

Obtains the value of the system parameter with the specified key. This API uses a promise to return the result.

**System capability**: SystemCapability.Startup.SystemInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system parameter.|
| def | string | No| Default value.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;string&gt; | Promise used to return the execution result.|

**Example**

```ts
try {
    var p = systemparameter.get("const.ohos.apiversion");
    p.then(function (value) {
        console.log("get test.parameter.key success: " + value);
    }).catch(function (err) {
        console.log("get test.parameter.key error: " + err.code);
    });
}catch(e){
    console.log("get unexpected error: " + e);
}
```

## systemparameter.setSync

setSync(key: string, value: string): void

Sets a value for the system parameter with the specified key.

**System capability**: SystemCapability.Startup.SystemInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system parameter.|
| value | string | Yes| Value of the system parameter to set.|

**Example**

```ts
try {
    systemparameter.setSync("test.parameter.key", "default");
}catch(e){
    console.log("set unexpected error: " + e);
}
```

## systemparameter.set

set(key: string, value: string, callback: AsyncCallback&lt;void&gt;): void

Sets a value for the system parameter with the specified key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Startup.SystemInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system parameter.|
| value | string | Yes| Value of the system parameter to set.|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Example**

```ts
try {
    systemparameter.set("test.parameter.key", "testValue", function (err, data) {
    if (err == undefined) {
        console.log("set test.parameter.key value success :" + data)
    } else {
        console.log("set test.parameter.key value err:" + err.code)
    }});
}catch(e){
    console.log("set unexpected error: " + e);
}
```

## systemparameter.set

set(key: string, value: string): Promise&lt;void&gt;

Sets a value for the system parameter with the specified key. This API uses a promise to return the result.

**System capability**: SystemCapability.Startup.SystemInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system parameter.|
| value| string | Yes| Value of the system parameter to set.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the execution result.|

**Example**

```ts
try {
    var p = systemparameter.set("test.parameter.key", "testValue");
    p.then(function (value) {
        console.log("set test.parameter.key success: " + value);
    }).catch(function (err) {
        console.log(" set test.parameter.key error: " + err.code);
    });
}catch(e){
    console.log("set unexpected error: " + e);
}
```
