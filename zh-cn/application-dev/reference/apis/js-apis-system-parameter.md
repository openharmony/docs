# 系统属性

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 本模块首批接口从API version 6开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 此接口为系统接口，三方应用不支持调用。

## 导入模块

```ts
import parameter from '@ohos.systemParameter'
```


## parameter.getSync

getSync(key: string, def?: string): string

获取系统属性Key对应的值。

**系统能力：** SystemCapability.Startup.SysInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待查询的系统属性Key。 |
| def | string | 否 | 默认值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| string | 系统属性值，若key不存在，返回默认值。若未指定默认值，返回空字符串。 |

**示例：**

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

获取系统属性Key对应的值。

**系统能力：** SystemCapability.Startup.SysInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待查询的系统属性Key。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。 |

**示例：**

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

获取系统属性Key对应的值。

**系统能力：** SystemCapability.Startup.SysInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待查询的系统属性Key。 |
| def | string | 是 | 默认值。 |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。 |

**示例：**

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

获取系统属性Key对应的值。

**系统能力：** SystemCapability.Startup.SysInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待查询的系统属性Key。 |
| def | string | 否 | 默认值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | Promise示例，用于异步获取结果。 |

**示例：**

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

设置系统属性Key对应的值。

**系统能力：** SystemCapability.Startup.SysInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待设置的系统属性Key。 |
| value | string | 是 | 待设置的系统属性值。 |

**示例：**

```ts
try {
    parameter.setSync("test.parameter.key", "default");
}catch(e){
    console.log("set unexpected error: " + e);
}
```


## parameter.set

set(key: string, value: string, callback: AsyncCallback&lt;void&gt;): void

设置系统属性Key对应的值。

**系统能力：** SystemCapability.Startup.SysInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待设置的系统属性Key。 |
| value | string | 是 | 待设置的系统属性值。 |
| callback | AsyncCallback&lt;void&gt; | 是 | 回调函数。 |

**示例：**

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

set(key: string, value: string): Promise&lt;string&gt;

设置系统属性Key对应的值。

**系统能力：** SystemCapability.Startup.SysInfo

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| key | string | 是 | 待待设置的系统属性Key。 |
| value| string | 否 | 待设置的系统属性值。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | Promise示例，用于异步获取结果。 |

**示例：**

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
