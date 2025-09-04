# ApplicationStateObserver
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @SKY2001-->
<!--Designer: @yzkp-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

The module defines an observer to listen for application state changes. It can be used as an input parameter in [on](js-apis-app-ability-appManager.md#appmanageronapplicationstate14) to listen for lifecycle changes of the current application.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 14. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { appManager } from '@kit.AbilityKit';
```

## ApplicationStateObserver.onForegroundApplicationChanged

onForegroundApplicationChanged(appStateData: AppStateData): void

Called when the foreground or background state of an application changes.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| appStateData | [AppStateData](js-apis-inner-application-appStateData.md) | Yes| Application state data.|

## ApplicationStateObserver.onAbilityStateChanged

onAbilityStateChanged(abilityStateData: AbilityStateData): void

Called when the ability state changes.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| abilityStateData | [AbilityStateData](js-apis-inner-application-abilityStateData.md) | Yes| Ability state data.|

## ApplicationStateObserver.onProcessCreated

onProcessCreated(processData: ProcessData): void

Called when a process is created.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| processData | [ProcessData](js-apis-inner-application-processData.md) | Yes| Process data.|

## ApplicationStateObserver.onProcessDied

onProcessDied(processData: ProcessData): void

Called when a process is destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| processData | [ProcessData](js-apis-inner-application-processData.md) | Yes| Process data.|

## ApplicationStateObserver.onProcessStateChanged

onProcessStateChanged(processData: ProcessData): void

Called when the process state is changed.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| processData | [ProcessData](js-apis-inner-application-processData.md) | Yes| Process data.|

## ApplicationStateObserver.onAppStarted

onAppStarted(appStateData: AppStateData): void

Called when the first process of the application is created.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| appStateData | [AppStateData](js-apis-inner-application-appStateData.md) | Yes| Application state data.|

## ApplicationStateObserver.onAppStopped

onAppStopped(appStateData: AppStateData): void

Called when the last process of the application is destroyed.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| appStateData | [AppStateData](js-apis-inner-application-appStateData.md) | Yes| Application state data.|

## ProcessData

type ProcessData = _ProcessData.default

Defines the process data.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

| Type| Description|
| --- | --- |
| [_ProcessData.default](js-apis-inner-application-processData.md) | Process data.|

**Example**
```ts
import { appManager } from '@kit.AbilityKit';

let applicationStateObserver: appManager.ApplicationStateObserver = {
  onForegroundApplicationChanged(appStateData) {
    console.log(`onForegroundApplicationChanged, appStateData: ${JSON.stringify(appStateData)}.`);
  },
  onAbilityStateChanged(abilityStateData) {
    console.log(`onAbilityStateChanged, abilityStateData: ${JSON.stringify(abilityStateData)}.`);
  },
  onProcessCreated(processData) {
    console.log(`onProcessCreated, processData: ${JSON.stringify(processData)}.`);
  },
  onProcessDied(processData) {
    console.log(`onProcessDied, processData: ${JSON.stringify(processData)}.`);
  },
  onProcessStateChanged(processData) {
    console.log(`onProcessStateChanged, processData: ${JSON.stringify(processData)}.`);
  },
  onAppStarted(appStateData) {
    console.log(`onAppStarted, appStateData: ${JSON.stringify(appStateData)}.`);
  },
  onAppStopped(appStateData) {
    console.log(`onAppStopped, appStateData: ${JSON.stringify(appStateData)}.`);
  }
};
let observerCode = appManager.on('applicationState', applicationStateObserver);
```
