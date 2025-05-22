# @ohos.faultLogger (FaultLogger)

The **faultLogger** APIs can be used to query fault logs of an application cached on the system. The APIs use the application bundle name and the UID allocated by the system as the unique key value.
The number of application fault logs stored in the system is limited by the system log pressure. You are advised to use [@ohos.hiviewdfx.hiAppEvent](js-apis-hiviewdfx-hiappevent.md) to subscribe to fault events such as **APP_CRASH** and **APP_FREEZE**.

> **NOTE**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version. 
> The APIs of this module are no longer maintained since API version 18. You are advised to use [@ohos.hiviewdfx.hiAppEvent](js-apis-hiviewdfx-hiappevent.md) to subscribe to the **APP_CRASH** and **APP_FREEZE** events in later versions.

## Modules to Import

```ts
import { FaultLogger } from '@kit.PerformanceAnalysisKit';
```

## FaultType

Enumerates the fault types.

**System capability**: SystemCapability.HiviewDFX.Hiview.FaultLogger

| Name| Value| Description|
| -------- | -------- | -------- |
| NO_SPECIFIC | 0 | No specific fault type.|
| CPP_CRASH | 2 | C++ program crash.|
| JS_CRASH | 3 | JS program crash.|
| APP_FREEZE | 4 | Application freezing.|

## FaultLogInfo

Defines the data structure of the fault log information.

**System capability**: SystemCapability.HiviewDFX.Hiview.FaultLogger

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| pid | number | Yes| Process ID of the faulty process.|
| uid | number | Yes| User ID of the faulty process.|
| type | [FaultType](#faulttype) | Yes| Fault type.|
| timestamp | number | Yes| Millisecond-level timestamp when the log was generated.|
| reason | string | Yes| Reason for the fault.|
| module | string | Yes| Module on which the fault occurred.|
| summary | string | Yes| Summary of the fault.|
| fullLog | string | Yes| Full log text.|

## FaultLogger.query<sup>9+</sup>

query(faultType: FaultType, callback: AsyncCallback&lt;Array&lt;FaultLogInfo&gt;&gt;) : void

Obtains the fault information about the current application. This API uses an asynchronous callback to return the fault information array obtained, which contains a maximum of 10 pieces of fault information.

**System capability**: SystemCapability.HiviewDFX.Hiview.FaultLogger

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| faultType | [FaultType](#faulttype) | Yes| Fault type.|
| callback | AsyncCallback&lt;Array&lt;[FaultLogInfo](#faultloginfo)&gt;&gt; | Yes| Callback used to return the fault information array.<br>**value** is the fault information array obtained. If **value** is **undefined**, an exception occurs during the information retrieval. In this case, an error string will be returned.|

**Error codes**

For details about the error codes, see [FaultLogger Error Codes](errorcode-faultlogger.md).

| ID| Error Message|
| --- | --- |
| 401 | The parameter check failed, Parameter type error. |
| 801 | The specified SystemCapability name was not found. |
| 10600001 | The service is not started or is faulty. |

**Example**

```ts
import { FaultLogger } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

function queryFaultLogCallback(error: BusinessError, value: Array<FaultLogger.FaultLogInfo>) {
    if (error) {
        console.info('error is ' + error);
    } else {
        console.info("value length is " + value.length);
        let len: number = value.length;
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
    FaultLogger.query(FaultLogger.FaultType.JS_CRASH, queryFaultLogCallback);
} catch (err) {
    console.error(`code: ${(err as BusinessError).code}, message: ${(err as BusinessError).message}`);
}
```

## FaultLogger.query<sup>9+</sup>

query(faultType: FaultType) : Promise&lt;Array&lt;FaultLogInfo&gt;&gt;

Obtains the fault information about the current application. This API uses a promise to return the fault information array obtained, which contains a maximum of 10 pieces of fault information.

**System capability**: SystemCapability.HiviewDFX.Hiview.FaultLogger

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| faultType | [FaultType](#faulttype) | Yes| Fault type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;[FaultLogInfo](#faultloginfo)&gt;&gt; | Promise used to return the fault information array. You can obtain the fault information instance in its **then()** method or use **await**.<br>**value** is the fault information array obtained. If **value** is **undefined**, an exception occurs during the information retrieval.|

**Error codes**

For details about the error codes, see [FaultLogger Error Codes](errorcode-faultlogger.md).

| ID| Error Message|
| --- | --- |
| 401 | The parameter check failed, Parameter type error. |
| 801 | The specified SystemCapability name was not found. |
| 10600001 | The service is not started or is faulty. |

**Example**

```ts
import { FaultLogger } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

async function getLog() {
  try {
    let value: Array<FaultLogger.FaultLogInfo> = await FaultLogger.query(FaultLogger.FaultType.JS_CRASH);
    if (value) {
      console.info("value length is " + value.length);
      let len: number = value.length;
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
    console.error(`code: ${(err as BusinessError).code}, message: ${(err as BusinessError).message}`);
  }
}
```

## FaultLogger.querySelfFaultLog<sup>(deprecated)</sup>

querySelfFaultLog(faultType: FaultType, callback: AsyncCallback&lt;Array&lt;FaultLogInfo&gt;&gt;) : void

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [FaultLogger.query](#faultloggerquery9).

Obtains the fault information about the current application. This API uses an asynchronous callback to return the fault information array obtained, which contains a maximum of 10 pieces of fault information.

**System capability**: SystemCapability.HiviewDFX.Hiview.FaultLogger

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| faultType | [FaultType](#faulttype) | Yes| Fault type.|
| callback | AsyncCallback&lt;Array&lt;[FaultLogInfo](#faultloginfo)&gt;&gt; | Yes| Callback used to return the fault information array.<br>**value** is the fault information array obtained. If **value** is **undefined**, an exception occurs during the information retrieval. In this case, an error string will be returned.|

**Example**

```ts
import { FaultLogger } from '@kit.PerformanceAnalysisKit';
import { BusinessError } from '@kit.BasicServicesKit';

function queryFaultLogCallback(error: BusinessError, value: Array<FaultLogger.FaultLogInfo>) {
  if (error) {
    console.info('error is ' + error);
  } else {
    console.info("value length is " + value.length);
    let len: number = value.length;
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
FaultLogger.querySelfFaultLog(FaultLogger.FaultType.JS_CRASH, queryFaultLogCallback);
```

## FaultLogger.querySelfFaultLog<sup>(deprecated)</sup>

querySelfFaultLog(faultType: FaultType) : Promise&lt;Array&lt;FaultLogInfo&gt;&gt;

> **NOTE**
>
> This API is deprecated since API version 9. You are advised to use [FaultLogger.query](#faultloggerquery9-1).

Obtains the fault information about the current application. This API uses a promise to return the fault information array obtained, which contains a maximum of 10 pieces of fault information.

**System capability**: SystemCapability.HiviewDFX.Hiview.FaultLogger

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| faultType | [FaultType](#faulttype) | Yes| Fault type.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;Array&lt;[FaultLogInfo](#faultloginfo)&gt;&gt; | Promise used to return the fault information array. You can obtain the fault information instance in its **then()** method or use **await**.<br>**value** is the fault information array obtained. If **value** is **undefined**, an exception occurs during the information retrieval.|

**Example**

```ts
import { FaultLogger } from '@kit.PerformanceAnalysisKit';

async function getLog() {
  let value: Array<FaultLogger.FaultLogInfo> = await FaultLogger.querySelfFaultLog(FaultLogger.FaultType.JS_CRASH);
  if (value) {
    console.info("value length is " + value.length);
    let len: number = value.length;
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
