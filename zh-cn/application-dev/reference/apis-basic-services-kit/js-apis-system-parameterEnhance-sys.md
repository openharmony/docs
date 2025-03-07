# @ohos.systemParameterEnhance (系统参数)(系统接口)

系统参数（SystemParameter）是为各系统服务提供的简单易用的键值对访问接口，各个系统服务可以定义系统参数来描述该服务的状态信息，或者通过系统参数来改变系统服务的行为。其基本操作原语为get和set，通过get可以查询系统参数的值，通过set可以修改系统参数的值。
详细的系统参数设计原理及定义可参考[系统参数](../../../device-dev/subsystems/subsys-boot-init-sysparam.md)。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。
> - 由于系统参数都是各个系统服务的内部信息和控制参数，每个系统参数都有各自不同的DAC和MAC访问控制权限，三方应用不能使用此类接口。

## 导入模块

```ts
import { systemParameterEnhance } from '@kit.BasicServicesKit';
```

## systemParameterEnhance.getSync

getSync(key: string, def?: string): string

获取系统参数Key对应的值。

**系统能力：** SystemCapability.Startup.SystemInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待查询的系统参数Key。最大长度128字节，只允许字母数字加"."，"-"，"@"，":"或"_"，不允许".."。 |
| def | string | 否 | def为所要获取的系统参数的默认值； <br> def为可选参数，仅当系统参数不存在时生效； <br> def可以传undefined或自定义的任意值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 系统参数值。 <br> 若key存在,返回设定的值。 <br> 若key不存在且def有效，返回def；若未指定def或def无效(如undefined)，抛异常。 |

**错误码**：

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.incorrect parameter types; 3.parameter verification failed. |
| 14700101 | System parameter not found.                                          |
| 14700103 | The operation on the system permission is denied.                    |
| 14700104 | System internal error such as out memory or deadlock.                |

以上错误码详细介绍请参考[系统参数错误码](errorcode-system-parameterV9.md)。

**示例：**

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

获取系统参数Key对应的值。

**系统能力：** SystemCapability.Startup.SystemInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待查询的系统参数Key。最大长度128字节，只允许字母数字加"."，"-"，"@"，":"或"_"，不允许".."。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。 |

**错误码**：

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.incorrect parameter types; 3.parameter verification failed. |
| 14700101 | System parameter not found.                                          |
| 14700103 | The operation on the system permission is denied.                    |
| 14700104 | System internal error such as out memory or deadlock.                |

以上错误码详细介绍请参考[系统参数错误码](errorcode-system-parameterV9.md)。

**示例：**

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

获取系统参数Key对应的值。

**系统能力：** SystemCapability.Startup.SystemInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待查询的系统参数Key。最大长度128字节，只允许字母数字加"."，"-"，"@"，":"或"_"，不允许".."。 |
| def | string | 是 | 默认值。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。 |

**错误码**：

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.incorrect parameter types; 3.parameter verification failed. |
| 14700101 | System parameter not found.                                          |
| 14700103 | The operation on the system permission is denied.                    |
| 14700104 | System internal error such as out memory or deadlock.                |

以上错误码详细介绍请参考[系统参数错误码](errorcode-system-parameterV9.md)。

**示例：**

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

获取系统参数Key对应的值。

**系统能力：** SystemCapability.Startup.SystemInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待查询的系统参数Key。最大长度128字节，只允许字母数字加"."，"-"，"@"，":"或"_"，不允许".."。 |
| def | string | 否 | def为所要获取的系统参数的默认值； <br> def为可选参数，仅当系统参数不存在时生效； <br> def可以传undefined或自定义的任意值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | Promise示例，用于异步获取结果。 |

**错误码**：

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.incorrect parameter types; 3.parameter verification failed. |
| 14700101 | System parameter not found.                                          |
| 14700103 | The operation on the system permission is denied.                    |
| 14700104 | System internal error such as out memory or deadlock.                |

以上错误码详细介绍请参考[系统参数错误码](errorcode-system-parameterV9.md)。

**示例：**

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

设置系统参数Key对应的值。

**系统能力：** SystemCapability.Startup.SystemInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待设置的系统参数Key。最大长度128字节，只允许字母数字加"."，"-"，"@"，":"或"_"，不允许".."。 |
| value | string | 是 | 待设置的系统参数值。最大长度96字节（包括结束符）。 |

**错误码**：

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.incorrect parameter types; 3.parameter verification failed. |
| 14700102 | Invalid system parameter value.                                          |
| 14700103 | The operation on the system permission is denied.                        |
| 14700104 | System internal error such as out memory or deadlock.                    |

以上错误码详细介绍请参考[系统参数错误码](errorcode-system-parameterV9.md)。

**示例：**

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

设置系统参数Key对应的值。

**系统能力：** SystemCapability.Startup.SystemInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待设置的系统参数Key。最大长度128字节，只允许字母数字加"."，"-"，"@"，":"或"_"，不允许".."。 |
| value | string | 是 | 待设置的系统参数值。最大长度96字节（包括结束符）。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**错误码**：

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.incorrect parameter types; 3.parameter verification failed. |
| 14700102 | Invalid system parameter value.                                          |
| 14700103 | The operation on the system permission is denied.                        |
| 14700104 | System internal error such as out memory or deadlock.                    |

以上错误码详细介绍请参考[系统参数错误码](errorcode-system-parameterV9.md)。

**示例：**

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

设置系统参数Key对应的值。

**系统能力：** SystemCapability.Startup.SystemInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待设置的系统参数Key。最大长度128字节，只允许字母数字加"."，"-"，"@"，":"或"_"，不允许".."。 |
| value| string | 是 | 待设置的系统参数值。最大长度96字节（包括结束符）。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise示例，用于异步获取结果。 |

**错误码**：

| 错误码ID | 错误信息                                                     |
| -------- | ------------------------------------------------------------ |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.incorrect parameter types; 3.parameter verification failed. |
| 14700102 | Invalid system parameter value.                                          |
| 14700103 | The operation on the system permission is denied.                        |
| 14700104 | System internal error such as out memory or deadlock.                    |

以上错误码详细介绍请参考[系统参数错误码](errorcode-system-parameterV9.md)。

**示例：**

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
