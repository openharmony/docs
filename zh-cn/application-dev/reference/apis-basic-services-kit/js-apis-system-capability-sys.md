# @ohos.systemCapability (系统能力)(系统接口)

系统能力（SystemCapability，简称SysCap），指操作系统中每一个相对独立的特性。不同的设备对应不同的系统能力集，每个系统能力对应多个接口。开发者可根据系统能力来判断是否可以使用某接口。本模块提供接口可查询系统能力的集合。

> **说明：**
>
> - 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口为系统接口。


## 导入模块

```ts
import systemcapability from '@ohos.systemCapability';
```

## systemcapability.querySystemCapabilities

querySystemCapabilities(callback: AsyncCallback&lt;string&gt;): void

获取系统能力集合的字符串，并调用回调函数。

**系统能力：** SystemCapability.Developtools.Syscap

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| callback | AsyncCallback&lt;string&gt; | 是 | 回调函数。 |


**示例：**

```ts
try {
    systemcapability.querySystemCapabilities((err:Error, data:string) => {
    if (err == undefined) {
        console.log("get system capabilities:" + data)
    } else {
        console.error(" get system capabilities err:" + err)
    }});
}catch(e){
    console.error("get unexpected error: " + e);
}
```


## systemcapability.querySystemCapabilities

querySystemCapabilities(): Promise&lt;string&gt;

获取系统能力的集合。

**系统能力：** SystemCapability.Developtools.Syscap

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;string&gt; | Promise示例，用于异步获取结果。 |

**示例：**

```ts
try {
    systemcapability.querySystemCapabilities().then((value:string) => {
        console.log("get system capabilities: " + value);
    }).catch((err:Error) => {
        console.error("get system capabilities error: " + err);
    });
}catch(e){
    console.error("get unexpected error: " + e);
}
```


> **说明：**
>
> 以上接口所返回的system capability集合形式均为编码后的数字字符串形式。


