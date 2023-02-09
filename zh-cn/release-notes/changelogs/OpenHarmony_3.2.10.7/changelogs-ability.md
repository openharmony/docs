# 元能力子系统JS API变更Changelog

## cl.ability.1 AreaMode接口变更
AreaMode接口有多个重复，删除掉重复的AreaMode。

**变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键的接口/组件变更**

| 模块名                    | 类名                | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.app.ability.common.d.ts | common.AreaMode |  | 删除     |
| application/Context.d.ts | AreaMode |  | 删除     |


**适配指导**

使用@ohos.app.ability.contextConstant.d.ts中的AreaMode

```ts
import contextConstant from '@ohos.app.ability.contextConstant';
let area: contextConstant.AreaMode = contextConstant.AreaMode.EL1;
```



## cl.ability.2 killProcessesBySelf接口变更

killProcessesBySelf接口命名不合理，修改为killAllProcesses。

**变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键接口/组件变更**

| 模块名                         | 类名               | 方法/属性/枚举/常量                                   | 变更类型 |
| ------------------------------ | ------------------ | ----------------------------------------------------- | -------- |
| application/ApplicationContext | ApplicationContext | killProcessesBySelf(): Promise\<void\>;               | 删除     |
| application/ApplicationContext | ApplicationContext | killProcessesBySelf(callback: AsyncCallback\<void\>); | 删除     |
| application/ApplicationContext | ApplicationContext | killAllProcesses(): Promise\<void\>;                  | 新增     |
| application/ApplicationContext | ApplicationContext | killAllProcesses(callback: AsyncCallback\<void\>);    | 新增     |


**适配指导**

应用中调用killProcessesBySelf可参考下列代码

变更前代码：

```ts
let context: common.UIAbilityContext = globalThis.abilityContext;
let appContext = context.getApplicationContext();
appContext.killProcessesBySelf()
```

变更后代码：

```ts
let context: common.UIAbilityContext = globalThis.abilityContext;
let appContext = context.getApplicationContext();
appContext.killAllProcesses()
```



## cl.ability.3 getProcessRunningInformation接口变更

getProcessRunningInformation接口命名不合理，修改为getRunningProcessInformation。

**变更影响**

影响API9版本的JS接口，应用需要进行适配才可以在新版本SDK环境正常实现功能。

**关键接口/组件变更**

| 模块名                              | 类名               | 方法/属性/枚举/常量                                          | 变更类型 |
| ----------------------------------- | ------------------ | ------------------------------------------------------------ | -------- |
| @ohos.app.ability.appManager.d.ts   | appManager         | function getProcessRunningInformation(): Promise\<Array\<ProcessRunningInformation\>\>; | 删除     |
| @ohos.app.ability.appManager.d.ts   | appManager         | function getProcessRunningInformation(callback: AsyncCallback\<Array\<ProcessRunningInformation\>\>): void; | 删除     |
| @ohos.app.ability.appManager.d.ts   | appManager         | function getRunningProcessInformation(): Promise\<Array\<ProcessInformation\>\>; | 新增     |
| @ohos.app.ability.appManager.d.ts   | appManager         | function getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation\>\>): void; | 新增     |
| application/ApplicationContext.d.ts | ApplicationContext | getProcessRunningInformation(): Promise\<Array\<ProcessRunningInformation\>\>; | 删除     |
| application/ApplicationContext.d.ts | ApplicationContext | getProcessRunningInformation(callback: AsyncCallback\<Array\<ProcessRunningInformation\>\>): void; | 删除     |
| application/ApplicationContext.d.ts | ApplicationContext | getRunningProcessInformation(): Promise\<Array\<ProcessInformation\>\>; | 新增     |
| application/ApplicationContext.d.ts | ApplicationContext | getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation\>\>): void; | 新增     |

**适配指导**

应用中调用getProcessRunningInformation可参考下列代码

变更前代码：

```ts
let context: common.UIAbilityContext = globalThis.abilityContext;
let appContext = context.getApplicationContext();
appContext.getProcessRunningInformation()
```

变更后代码：

```ts
let context: common.UIAbilityContext = globalThis.abilityContext;
let appContext = context.getApplicationContext();
appContext.getRunningProcessInformation()
```

