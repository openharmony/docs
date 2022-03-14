# ProcessRunningInfo

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。


进程运行信息。


## 使用说明


通过appManager来获取。


  
```js
import appManager from '@ohos.application.appManager';
appManager.getProcessRunningInfos((error,data) => { 
    console.log("getProcessRunningInfos error: "  + error.code + " data: " + JSON.stringify(data));
});
```


## 属性

  | 名称 | 参数类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| pid | number | 是 | 否 | 进程ID。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core | 
| uid | number | 是 | 否 | 用户ID。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core | 
| processName | string | 是 | 否 | 进程名称。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core | 
| bundleNames | Array&lt;string&gt; | 是 | 否 | 进程中所有运行的包名称。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core | 
