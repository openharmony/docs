# 系统能力

系统能力（SystemCapability）是部件向开发者提供的接口的集合，各个部件通过定义系统能力来描述该部件所能提供的能力。其基本操作原语为querySystemCapabilities，可以查询系统能力的集合。
详细的系统能力原理及配置可参考
[系统能力](../../../device-dev/subsystems/subsys-build-syscap.md)。

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。


## 导入模块

```ts
import systemcapability from '@ohos.systemCapability'
```

## systemcapability.querySystemCapabilities

querySystemCapabilities(callback: AsyncCallback<string>): void;

获取系统能力集合的字符串，并调用回调函数。

**系统能力：** SystemCapability.Developtools.Syscap

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback<string> | 是 | 回调函数 |


**示例：**

```ts
try {
    systemcapability.querySystemCapabilities(function (err, data) {
    if (err == undefined) {
        console.log("get system capabilities:" + data)
    } else {
        console.log(" get system capabilities err:" + err.code)
    }});
}catch(e){
    console.log("get unexpected error: " + e);
}
```


## systemcapability.querySystemCapabilities

querySystemCapabilities(): Promise&lt;string&gt;

获取系统能力的集合。

**系统能力：** SystemCapability.Startup.SystemInfo

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | Promise示例，用于异步获取结果。 |

**示例：**

```ts
try {
    var p = systemcapability.querySystemCapabilities();
    p.then(function (value) {
        console.log("get system capabilities: " + value);
    }).catch(function (err) {
        console.log("get system capabilities error: " + err.code);
    });
}catch(e){
    console.log("get unexpected error: " + e);
}
```


> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 以上接口所返回的system capability集合形式均为编码后的数字字符串形式。


