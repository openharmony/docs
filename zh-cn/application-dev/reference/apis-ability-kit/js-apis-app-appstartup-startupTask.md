# @ohos.app.appstartup.StartupTask

本模块提供组件初始化的相关能力。

> **说明：**
>
> 本模块首批接口从API version 12开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
>
> 本模块接口仅可在Stage模型下使用。

## 导入模块

```js
import StartupTask from '@ohos.app.appstartup.StartupTask';
```

## StartupTask.onDependencyCompleted

onDependencyCompleted?(dependency: string, result: any): void

在特定的依赖组件完成初始化时调用。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AppStartup

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| dependency | string | 是 | 依赖的组件名称。 |
| result | any | 是 | 依赖组件初始化的结果。 |

**示例：**：

```ts
import StartupTask from '@ohos.app.appstartup.StartupTask';

@Sendable
export default class Sample_001 extends StartupTask {
  constructor() {
    super();
  }

  onDependencyCompleted(dependence: string, result) {
    console.info("StartupTest Sample_001 onDependencyCompleted dependence=" + dependence);
    // ...
  }
}
```


## StartupTask.init

init(context: AbilityStageContext): Promise\<any\>

初始化组件

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AppStartup

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| context | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md) | 是 | AbilityStage的上下文环境 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise\<any\> | Promise对象，返回组件初始化结果对象。 |

**示例：**：

```ts
import StartupTask from '@ohos.app.appstartup.StartupTask';

@Sendable
export default class Sample_001 extends StartupTask {
  constructor() {
    super();
  }

  async init(context) {
    console.info("StartupTest Sample_001 init");
    // ...
  }
}
```
