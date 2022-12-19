# ProcessInfo

定义进程信息，可以通过[getProcessInfo](js-apis-inner-app-context.md#contextgetprocessinfo7)获取当前Ability运行的进程信息。

> **说明：**
> 
> 本模块首批接口从API version 7开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 类型 | 可读 | 可写 | 说明 | 
| -------- | -------- | -------- | -------- | -------- |
| pid | number | 是 | 否 | 进程ID。 | 
| processName | string | 是 | 否 | 进程名称。 | 

**示例：**
```ts
import featureAbility from '@ohos.ability.featureAbility';

var context = featureAbility.getContext();
context.getProcessInfo((err, data) => {
    console.info("getProcessInfo err: " + JSON.stringify(err) + "data: " + JSON.stringify(data));
    let pid = data.pid;
    let processName = data.processName;
});
```

