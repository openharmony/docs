# ProcessRunningInfo

本模块提供对进程运行信息进行设置和查询的能力。

> **说明：**<br/>
> - 本模块接口从API version 9 开始废弃，建议使用[ProcessRunningInformation<sup>9+</sup>](js-apis-inner-application-processRunningInformation.md)替代。
> - 本模块首批接口从API version 8 开始支持。

## 属性

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Mission

| 名称 | 类型 | 可读 | 可写 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| pid | number | 是 | 否 | 进程ID。 |
| uid | number | 是 | 否 | 用户ID。 |
| processName | string | 是 | 否 | 进程名称。 |
| bundleNames | Array&lt;string&gt; | 是 | 否 | 进程中所有运行的包名称。 |

## 使用说明

通过appManager中[getProcessRunningInfos](js-apis-application-appManager.md##appManager.getProcessRunningInfos<sup>(deprecated)</sup>)方法来获取。

**示例：**
```ts
import appManager from '@ohos.application.appManager';

appManager.getProcessRunningInfos().then((data) => {
    console.log('success:' + JSON.stringify(data));
}).catch((error) => {
    console.log('failed:' + JSON.stringify(error));
});
```
