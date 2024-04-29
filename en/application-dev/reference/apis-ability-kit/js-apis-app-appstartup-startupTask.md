# @ohos.app.appstartup.StartupTask

The @ohos.app.appstartup.StartupTask module provides the APIs related to startup task initialization.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.

## Modules to Import

```js
import StartupTask from '@ohos.app.appstartup.StartupTask';
```

## StartupTask.onDependencyCompleted

onDependencyCompleted(dependency: string, result: ESObject): void

Called when a startup task completes initialization.

**System capability**: SystemCapability.Ability.AppStartup

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| dependency | string | Yes| Name of the startup task.|
| result | ESObject | Yes| Initialization result of the startup task.|

**Example**

```ts
import StartupTask from '@ohos.app.appstartup.StartupTask';

export default class Sample_001 extends StartupTask {
  onDependencyCompleted(dependence: string, result) {
    console.info("StartupTest Sample_001 onDependencyCompleted dependence=" + dependence);
    ...
  }
}
```


## StartupTask.init

init(context: AbilityStageContext): Promise\<ESObject\>

Initializes a startup task.

**System capability**: SystemCapability.Ability.AppStartup

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| context | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md) | Yes| Context of the ability stage.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<ESObject\> | Promise used to return the initialization result.|

**Example**

```ts
import StartupTask from '@ohos.app.appstartup.StartupTask';

export default class Sample_001 extends StartupTask {
  async init(context) {
    console.info("StartupTest Sample_001 init");
    ...
  }
}
```
