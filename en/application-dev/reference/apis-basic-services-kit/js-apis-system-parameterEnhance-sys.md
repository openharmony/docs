# @ohos.systemParameterEnhance (System Parameter) (System API)

The **SystemParameter** module provides system services with easy access to key-value pairs. You can use the APIs provided by this module to describe the service status and change the service behavior. The basic operation primitives are get and set. You can obtain the values of system parameters through getter APIs and modify the values through setter APIs.
For details about the system parameter design principles and definitions, see [Parameter Management](../../../device-dev/subsystems/subsys-boot-init-sysparam.md).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs provided by this module are system APIs.
> - Third-party applications cannot use the APIs provided by this module, because system parameters each require specific discretionary access control (DAC) and mandatory access control (MAC) permissions.

## Modules to Import

```ts
import { systemParameterEnhance } from '@kit.BasicServicesKit';
```

## systemParameterEnhance.getSync

getSync(key: string, def?: string): string

Obtains the value of the system parameter with the specified key.

**System capability**: SystemCapability.Startup.SystemInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system parameter. The value can contain a maximum of 128 bytes. Only letters, digits, periods (.), hyphens (-), at signs (@), colons (:), and underscores (_) are allowed.|
| def | string | No| Default value of the system parameter.<br> It works only when the system parameter does not exist.<br> The value can be **undefined** or any custom value.|

**Return value**

| Type| Description|
| -------- | -------- |
| string | Value of the system parameter.<br> If the specified key exists, the set value is returned.<br> If the specified key does not exist and **def** is set to a valid value, the set value is returned. If the specified key does not exist and **def** is set to an invalid value (such as **undefined**) or is not set, an exception is thrown.|

**Error codes**

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.incorrect parameter types; 3.parameter verification failed. |
| 14700101 | System parameter not found.                                          |
| 14700103 | The operation on the system permission is denied.                    |
| 14700104 | System internal error such as out memory or deadlock.                |

For details about the error codes, see [System Parameter Error Codes](errorcode-system-parameterV9.md).

**Example**

```ts
try {
    let info: string = systemParameterEnhance.getSync("const.ohos.apiversion");
    console.log(JSON.stringify(info));
} catch(e) {
    console.log("getSync unexpected error: " + e);
}
```

## systemParameterEnhance.get

get(key: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the value of the system parameter with the specified key.

**System capability**: SystemCapability.Startup.SystemInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system parameter. The value can contain a maximum of 128 bytes. Only letters, digits, periods (.), hyphens (-), at signs (@), colons (:), and underscores (_) are allowed.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.incorrect parameter types; 3.parameter verification failed. |
| 14700101 | System parameter not found.                                          |
| 14700103 | The operation on the system permission is denied.                    |
| 14700104 | System internal error such as out memory or deadlock.                |

For details about the error codes, see [System Parameter Error Codes](errorcode-system-parameterV9.md).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    systemParameterEnhance.get("const.ohos.apiversion", (err: BusinessError, data: string) => {
    if (err == undefined) {
        console.log("get test.parameter.key value success:" + data)
    } else {
        console.log(" get test.parameter.key value err:" + err.code)
    }});
} catch(e) {
    console.log("get unexpected error: " + e);
}
```

## systemParameterEnhance.get

get(key: string, def: string, callback: AsyncCallback&lt;string&gt;): void

Obtains the value of the system parameter with the specified key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Startup.SystemInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system parameter. The value can contain a maximum of 128 bytes. Only letters, digits, periods (.), hyphens (-), at signs (@), colons (:), and underscores (_) are allowed.|
| def | string | Yes| Default value.|
| callback | AsyncCallback&lt;string&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.incorrect parameter types; 3.parameter verification failed. |
| 14700101 | System parameter not found.                                          |
| 14700103 | The operation on the system permission is denied.                    |
| 14700104 | System internal error such as out memory or deadlock.                |

For details about the error codes, see [System Parameter Error Codes](errorcode-system-parameterV9.md).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    systemParameterEnhance.get("const.ohos.apiversion", "default", (err: BusinessError, data: string) => {
        if (err == undefined) {
            console.log("get test.parameter.key value success:" + data)
        } else {
            console.log(" get test.parameter.key value err:" + err.code)
        }
    });
} catch(e) {
    console.log("get unexpected error:" + e)
}
```

## systemParameterEnhance.get

get(key: string, def?: string): Promise&lt;string&gt;

Obtains the value of the system parameter with the specified key. This API uses a promise to return the result.

**System capability**: SystemCapability.Startup.SystemInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system parameter. The value can contain a maximum of 128 bytes. Only letters, digits, periods (.), hyphens (-), at signs (@), colons (:), and underscores (_) are allowed.|
| def | string | No| Default value of the system parameter.<br> It works only when the system parameter does not exist.<br> The value can be **undefined** or any custom value.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;string&gt; | Promise used to return the execution result.|

**Error codes**

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.incorrect parameter types; 3.parameter verification failed. |
| 14700101 | System parameter not found.                                          |
| 14700103 | The operation on the system permission is denied.                    |
| 14700104 | System internal error such as out memory or deadlock.                |

For details about the error codes, see [System Parameter Error Codes](errorcode-system-parameterV9.md).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let p: Promise<string> = systemParameterEnhance.get("const.ohos.apiversion");
    p.then((value: string) => {
        console.log("get test.parameter.key success: " + value);
    }).catch((err: BusinessError) => {
        console.log("get test.parameter.key error: " + err.code);
    });
} catch(e) {
    console.log("get unexpected error: " + e);
}
```

## systemParameterEnhance.setSync

setSync(key: string, value: string): void

Sets a value for the system parameter with the specified key.

**System capability**: SystemCapability.Startup.SystemInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system parameter. The value can contain a maximum of 128 bytes. Only letters, digits, periods (.), hyphens (-), at signs (@), colons (:), and underscores (_) are allowed.|
| value | string | Yes| Value of the system parameter to set. The value can contain a maximum of 96 bytes (including the end character).|

**Error codes**

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.incorrect parameter types; 3.parameter verification failed. |
| 14700102 | Invalid system parameter value.                                          |
| 14700103 | The operation on the system permission is denied.                        |
| 14700104 | System internal error such as out memory or deadlock.                    |

For details about the error codes, see [System Parameter Error Codes](errorcode-system-parameterV9.md).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    systemParameterEnhance.setSync("test.parameter.key", "default");
} catch(e) {
    console.log("set unexpected error: " + e);
}
```

## systemParameterEnhance.set

set(key: string, value: string, callback: AsyncCallback&lt;void&gt;): void

Sets a value for the system parameter with the specified key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Startup.SystemInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system parameter. The value can contain a maximum of 128 bytes. Only letters, digits, periods (.), hyphens (-), at signs (@), colons (:), and underscores (_) are allowed.|
| value | string | Yes| Value of the system parameter to set. The value can contain a maximum of 96 bytes (including the end character).|
| callback | AsyncCallback&lt;void&gt; | Yes| Callback used to return the result.|

**Error codes**

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.incorrect parameter types; 3.parameter verification failed. |
| 14700102 | Invalid system parameter value.                                          |
| 14700103 | The operation on the system permission is denied.                        |
| 14700104 | System internal error such as out memory or deadlock.                    |

For details about the error codes, see [System Parameter Error Codes](errorcode-system-parameterV9.md).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    systemParameterEnhance.set("test.parameter.key", "testValue", (err: BusinessError, data: void) => {
    if (err == undefined) {
        console.log("set test.parameter.key value success :" + data)
    } else {
        console.log("set test.parameter.key value err:" + err.code)
    }});
} catch(e) {
    console.log("set unexpected error: " + e);
}
```

## systemParameterEnhance.set

set(key: string, value: string): Promise&lt;void&gt;

Sets a value for the system parameter with the specified key. This API uses a promise to return the result.

**System capability**: SystemCapability.Startup.SystemInfo

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| key | string | Yes| Key of the system parameter. The value can contain a maximum of 128 bytes. Only letters, digits, periods (.), hyphens (-), at signs (@), colons (:), and underscores (_) are allowed.|
| value| string | Yes| Value of the system parameter to set. The value can contain a maximum of 96 bytes (including the end character).|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise used to return the execution result.|

**Error codes**

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.incorrect parameter types; 3.parameter verification failed. |
| 14700102 | Invalid system parameter value.                                          |
| 14700103 | The operation on the system permission is denied.                        |
| 14700104 | System internal error such as out memory or deadlock.                    |

For details about the error codes, see [System Parameter Error Codes](errorcode-system-parameterV9.md).

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

try {
    let p: Promise<void>  = systemParameterEnhance.set("test.parameter.key", "testValue");
    p.then((value: void) => {
        console.log("set test.parameter.key success: " + value);
    }).catch((err: BusinessError) => {
        console.log(" set test.parameter.key error: " + err.code);
    });
} catch(e) {
    console.log("set unexpected error: " + e);
}
```
