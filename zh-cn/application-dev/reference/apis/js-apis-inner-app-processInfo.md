# ProcessInfo<sup>7+</sup>

定义进程信息。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称 | 参数类型 | 可读 | 可写 | 说明 | 
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
