# @ohos.systemCapability (System Capability) (System API)

System capability (SysCap) refers to a relatively independent feature in the operating system. Different devices provide different system capabilities, and multiple APIs implement a system capability. You can determine whether an API can be used based on system capabilities. This module provides APIs for querying the set of system capabilities.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.


## Modules to Import

```ts
import systemcapability from '@ohos.systemCapability';
```

## systemcapability.querySystemCapabilities

querySystemCapabilities(callback: AsyncCallback&lt;string&gt;): void;

Queries system capabilities. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Developtools.Syscap

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result.|


**Example**

```ts
try {
    systemcapability.querySystemCapabilities((err:Error, data:string) => {
    if (err == undefined) {
        console.log("get system capabilities:" + data)
    } else {
        console.log(" get system capabilities err:" + err)
    }});
}catch(e){
    console.log("get unexpected error: " + e);
}
```


## systemcapability.querySystemCapabilities

querySystemCapabilities(): Promise&lt;string&gt;

Queries system capabilities. This API uses a promise to return the result.

**System capability**: SystemCapability.Developtools.Syscap

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;string&gt; | Promise used to return the result.|

**Example**

```ts
try {
    systemcapability.querySystemCapabilities().then((value:string) => {
        console.log("get system capabilities: " + value);
    }).catch((err:Error) => {
        console.log("get system capabilities error: " + err);
    });
}catch(e){
    console.log("get unexpected error: " + e);
}
```


> **NOTE**
>
> The system capabilities returned by the preceding APIs are in the form of an encoded numeric string.
