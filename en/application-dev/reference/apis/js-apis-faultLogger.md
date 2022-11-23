# Fault Logger
> **NOTE**<br/>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import faultLogger from '@ohos.faultLogger'
```


## FaultType

Enumerates the fault types.

**System capability**: SystemCapability.HiviewDFX.Hiview.FaultLogger

| Name| Default Value| Description|
| -------- | -------- | -------- |
| NO_SPECIFIC | 0 | No specific fault type.|
| CPP_CRASH | 2 | C++ program crash.|
| JS_CRASH | 3 | JS program crash.|
| APP_FREEZE | 4 | Application freezing.|

## FaultLogInfo

Defines the data structure of the fault log information.

**System capability**: SystemCapability.HiviewDFX.Hiview.FaultLogger

| Name| Type| Description|
| -------- | -------- | -------- |
| pid | number | Process ID of the faulty process.|
| uid | number | User ID of the faulty process.|
| type | [FaultType](#faulttype) | Fault type.|
| timestamp | number | Second-level timestamp when the log was generated.|
| reason | string | Reason for the fault.|
| module | string | Module on which the fault occurred.|
| summary | string | Summary of the fault.|
| fullLog | string | Full log text.|

## faultLogger.querySelfFaultLog<sup>(deprecated)</sup>

querySelfFaultLog(faultType: FaultType, callback: AsyncCallback&lt;Array&lt;FaultLogInfo&gt;&gt;) : void

> **NOTE**<br>This API is deprecated since API version 9. You are advised to use [faultLogger.query](#faultloggerquery9) instead.

Obtains the fault information about the current process. This API uses an asynchronous callback to return the fault information array obtained, which contains a maximum of 10 pieces of fault information.

**System capability**: SystemCapability.HiviewDFX.Hiview.FaultLogger

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| faultType | [FaultType](#faulttype) | Yes| Fault type.|
| callback | AsyncCallbackArray&lt;Array&lt;[FaultLogInfo](#faultloginfo)&gt;&gt; | Yes| Callback used to return the fault information array.<br>The value is the fault information array obtained. If the value is **undefined**, an exception occurs during the information retrieval. In this case, an error string will be returned.

**Example**

```js
function queryFaultLogCallback(error, value) {
    if (error) {
        console.info('error is ' + error);
    } else {
        console.info("value length is " + value.length);
        let len = value.length;
        for (let i = 0; i < len; i++) {
            console.info("log: " + i);
            console.info("Log pid: " + value[i].pid);
            console.info("Log uid: " + value[i].uid);
            console.info("Log type: " + value[i].type);
            console.info("Log timestamp: " + value[i].timestamp);
            console.info("Log reason: " + value[i].reason);
            console.info("Log module: " + value[i].module);
            console.info("Log summary: " + value[i].summary);
            console.info("Log text: " + value[i].fullLog);
        }
    }
}
faultLogger.querySelfFaultLog(faultLogger.FaultType.JS_CRASH, queryFaultLogCallback);
```

## faultLogger.querySelfFaultLog<sup>(deprecated)</sup>

querySelfFaultLog(faultType: FaultType) : Promise&lt;Array&lt;FaultLogInfo&gt;&gt;

> **NOTE**<br>This API is deprecated since API version 9. You are advised to use [faultLogger.query](#faultloggerquery9-1) instead.

Obtains the fault information about the current process. This API uses a promise to return the fault information array obtained, which contains a maximum of 10 pieces of fault information.

**System capability**: SystemCapability.HiviewDFX.Hiview.FaultLogger

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| faultType | [FaultType](#faulttype) | Yes| Fault type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;[FaultLogInfo](#faultloginfo)&gt;&gt; | Promise used to return the fault information array. You can obtain the fault information instance in its **then()** method or use **await**.<br>The value is the fault information array obtained. If the value is **undefined**, an exception occurs during the information retrieval.|

**Example**

```js
async function getLog() {
    let value = await faultLogger.querySelfFaultLog(faultLogger.FaultType.JS_CRASH);
    if (value) {
        console.info("value length is " + value.length);
        let len = value.length;
        for (let i = 0; i < len; i++) {
            console.info("log: " + i);
            console.info("Log pid: " + value[i].pid);
            console.info("Log uid: " + value[i].uid);
            console.info("Log type: " + value[i].type);
            console.info("Log timestamp: " + value[i].timestamp);
            console.info("Log reason: " + value[i].reason);
            console.info("Log module: " + value[i].module);
            console.info("Log summary: " + value[i].summary);
            console.info("Log text: " + value[i].fullLog);
        }
    }
}
```

## faultLogger.query<sup>9+</sup>

query(faultType: FaultType, callback: AsyncCallback&lt;Array&lt;FaultLogInfo&gt;&gt;) : void

Obtains the fault information about the current process. This API uses an asynchronous callback to return the fault information array obtained, which contains a maximum of 10 pieces of fault information.

**System capability**: SystemCapability.HiviewDFX.Hiview.FaultLogger

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| faultType | [FaultType](#faulttype) | Yes| Fault type.|
| callback | AsyncCallbackArray&lt;Array&lt;[FaultLogInfo](#faultloginfo)&gt;&gt; | Yes| Callback used to return the fault information array.<br>The value is the fault information array obtained. If the value is **undefined**, an exception occurs during the information retrieval. In this case, an error string will be returned.

**Error codes**

For details about the error codes, see [faultLogger Error Codes](../errorcodes/errorcode-faultlogger.md).

| ID| Error Message|
| --- | --- |
| 10600001 | The service is not running or broken |

**Example**

```js
function queryFaultLogCallback(error, value) {
    if (error) {
        console.info('error is ' + error);
    } else {
        console.info("value length is " + value.length);
        let len = value.length;
        for (let i = 0; i < len; i++) {
            console.info("log: " + i);
            console.info("Log pid: " + value[i].pid);
            console.info("Log uid: " + value[i].uid);
            console.info("Log type: " + value[i].type);
            console.info("Log timestamp: " + value[i].timestamp);
            console.info("Log reason: " + value[i].reason);
            console.info("Log module: " + value[i].module);
            console.info("Log summary: " + value[i].summary);
            console.info("Log text: " + value[i].fullLog);
        }
    }
}
try {
    faultLogger.query(faultLogger.FaultType.JS_CRASH, queryFaultLogCallback);
} catch (err) {
    console.error(`code: ${err.code}, message: ${err.message}`);
}
```

## faultLogger.query<sup>9+</sup>

query(faultType: FaultType) : Promise&lt;Array&lt;FaultLogInfo&gt;&gt;

Obtains the fault information about the current process. This API uses a promise to return the fault information array obtained, which contains a maximum of 10 pieces of fault information.

**System capability**: SystemCapability.HiviewDFX.Hiview.FaultLogger

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| faultType | [FaultType](#faulttype) | Yes| Fault type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;[FaultLogInfo](#faultloginfo)&gt;&gt; | Promise used to return the fault information array. You can obtain the fault information instance in its **then()** method or use **await**.<br>The value is the fault information array obtained. If the value is **undefined**, an exception occurs during the information retrieval.|

**Error codes**

For details about the error codes, see [faultLogger Error Codes](../errorcodes/errorcode-faultlogger.md).

| ID| Error Message|
| --- | --- |
| 10600001 | The service is not running or broken |

**Example**

```js
async function getLog() {
    try {
        let value = await faultLogger.query(faultLogger.FaultType.JS_CRASH);
        if (value) {
            console.info("value length is " + value.length);
            let len = value.length;
            for (let i = 0; i < len; i++) {
                console.info("log: " + i);
                console.info("Log pid: " + value[i].pid);
                console.info("Log uid: " + value[i].uid);
                console.info("Log type: " + value[i].type);
                console.info("Log timestamp: " + value[i].timestamp);
                console.info("Log reason: " + value[i].reason);
                console.info("Log module: " + value[i].module);
                console.info("Log summary: " + value[i].summary);
                console.info("Log text: " + value[i].fullLog);
            }
        }
    } catch (err) {
        console.error(`code: ${err.code}, message: ${err.message}`);
    }
}
```
