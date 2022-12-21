# ProcessRunningInformation

ProcessRunningInformation模块提供对进程运行信息进行设置和查询的能力。

> **说明：**
> 
> 本模块首批接口从API version 9开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 使用说明

通过appManager的[getProcessRunningInformation](js-apis-application-appManager.md#appmanagergetprocessrunninginformation9)来获取。

```ts
import appManager from '@ohos.application.appManager';

appManager.getProcessRunningInformation((error, data) => { 
    console.log("error: "  + error.code + " data: " + JSON.stringify(data));
});
```

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| pid | number | 是 | 否 | 进程ID。 |
| uid | number | 是 | 否 | 用户ID。 |
| processName | string | 是 | 否 | 进程名称。 |
| bundleNames | Array&lt;string&gt; | 是 | 否 | 进程中所有运行的包名称。 |
