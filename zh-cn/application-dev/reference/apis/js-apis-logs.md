# console (日志打印)

本模块提供基础的日志打印能力，支持按照日志级别打印日志信息。

如果需要使用更高级的日志打印服务，比如按照指定标识筛选日志内容，推荐使用[`@ohos.hilog`](js-apis-hilog.md)。

> **说明：**
>
> 本模块首批接口从API version 3开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## console.debug

debug(message: string): void

打印debug级别的日志信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| message | string | 是    | 表示要打印的文本信息。 |


## console.log

log(message: string): void

打印debug级别的日志信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| message | string | 是    | 表示要打印的文本信息。 |


## console.info

info(message: string): void

打印info级别的日志信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| message | string | 是    | 表示要打印的文本信息。 |


## console.warn

warn(message: string): void

打印warn级别的日志信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| message | string | 是    | 表示要打印的文本信息。 |


## console.error

error(message: string): void

打印error级别的日志信息。

**系统能力：** SystemCapability.ArkUI.ArkUI.Full

**参数：**

| 参数名     | 类型     | 必填   | 说明          |
| ------- | ------ | ---- | ----------- |
| message | string | 是    | 表示要打印的文本信息。 |


## 示例

```
export default {    
  clickConsole(){        
    var versionCode = 1;        
    console.info('Hello World. The current version code is ' + versionCode);        
    console.log(`versionCode: ${versionCode}`);        
    // 以下写法从API Version 6开始支持console.log('versionCode:%d.', versionCode);    
  }
}
```

在DevEco Studio的底部，切换到“HiLog”窗口。选择当前的设备及进程，日志级别选择Info，搜索内容设置为“Hello World”。此时窗口仅显示符合条件的日志，效果如图所示：

![zh-cn_image_0000001200913929](figures/zh-cn_image_0000001200913929.png)
