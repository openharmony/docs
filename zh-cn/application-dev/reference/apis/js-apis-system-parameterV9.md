# @ohos.systemParameterV9 (系统属性)

系统参数（SystemParameter）是为各系统服务提供的简单易用的键值对访问接口，各个系统服务可以定义系统参数来描述该服务的状态信息，或者通过系统参数来改变系统服务的行为。其基本操作原语为get和set，通过get可以查询系统参数的值，通过set可以修改系统参数的值。
详细的系统参数设计原理及定义可参考
[系统参数](../../../device-dev/subsystems/subsys-boot-init-sysparam.md)。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。
> - 由于系统参数都是各个系统服务的内部信息和控制参数，每个系统参数都有各自不同的DAC和MAC访问控制权限，三方应用不能使用此类接口。

## 导入模块

```ts
import systemparameter from '@ohos.systemParameterV9'
```

## systemparameter.getSync

getSync(key: string, def?: string): string

获取系统参数Key对应的值。

**系统能力：** SystemCapability.Startup.SystemInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待查询的系统参数Key。 |
| def | string | 否 | 默认值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 系统参数值，若key不存在，返回默认值。若未指定默认值，返回空字符串。 |

**示例：**

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

获取系统参数Key对应的值。

**系统能力：** SystemCapability.Startup.SystemInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待查询的系统参数Key。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。 |

**示例：**

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

获取系统参数Key对应的值。

**系统能力：** SystemCapability.Startup.SystemInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待查询的系统参数Key。 |
| def | string | 是 | 默认值。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。 |

**示例：**

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

获取系统参数Key对应的值。

**系统能力：** SystemCapability.Startup.SystemInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待查询的系统参数Key。 |
| def | string | 否 | 默认值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | Promise示例，用于异步获取结果。 |

**示例：**

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

设置系统参数Key对应的值。

**系统能力：** SystemCapability.Startup.SystemInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待设置的系统参数Key。 |
| value | string | 是 | 待设置的系统参数值。 |

**示例：**

```ts
try {
    systemparameter.setSync("test.parameter.key", "default");
}catch(e){
    console.log("set unexpected error: " + e);
}
```

## systemparameter.set

set(key: string, value: string, callback: AsyncCallback&lt;void&gt;): void

设置系统参数Key对应的值。

**系统能力：** SystemCapability.Startup.SystemInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待设置的系统参数Key。 |
| value | string | 是 | 待设置的系统参数值。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**示例：**

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

设置系统参数Key对应的值。

**系统能力：** SystemCapability.Startup.SystemInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待设置的系统参数Key。 |
| value| string | 是 | 待设置的系统参数值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;void&gt; | Promise示例，用于异步获取结果。 |

**示例：**

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
