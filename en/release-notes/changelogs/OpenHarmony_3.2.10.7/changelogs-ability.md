# Ability Subsystem Changelog

## cl.ability.1 AreaMode APIs Changed
Duplicate **AreaMode** APIs are deleted.

**Change Impact**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement features in the SDK environment of the new version.

**Key API/Component Changes**

| Module                   | Class               | Method/Attribute/Enum/Constant                                         | Change Type|
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.app.ability.common.d.ts | common.AreaMode |  | Deleted    |
| application/Context.d.ts | AreaMode |  | Deleted    |


**Adaptation Guide**

Use **AreaMode** in **@ohos.app.ability.contextConstant.d.ts**.

```ts
import contextConstant from '@ohos.app.ability.contextConstant';
let area: contextConstant.AreaMode = contextConstant.AreaMode.EL1;
```



## cl.ability.2 killProcessesBySelf Renamed

The **killProcessesBySelf** API is renamed **killAllProcesses**.

**Change Impact**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement features in the SDK environment of the new version.

**Key API/Component Changes**

| Module                        | Class              | Method/Attribute/Enum/Constant                                  | Change Type|
| ------------------------------ | ------------------ | ----------------------------------------------------- | -------- |
| application/ApplicationContext | ApplicationContext | killProcessesBySelf(): Promise\<void\>;               | Deleted    |
| application/ApplicationContext | ApplicationContext | killProcessesBySelf(callback: AsyncCallback\<void\>); | Deleted    |
| application/ApplicationContext | ApplicationContext | killAllProcesses(): Promise\<void\>;                  | Added    |
| application/ApplicationContext | ApplicationContext | killAllProcesses(callback: AsyncCallback\<void\>);    | Added    |


**Adaptation Guide**

The following code snippet shows how to call **killProcessesBySelf** in an application.

Code before the change:

```ts
let context: common.UIAbilityContext = globalThis.abilityContext;
let appContext = context.getApplicationContext();
appContext.killProcessesBySelf()
```

Code after the change:

```ts
let context: common.UIAbilityContext = globalThis.abilityContext;
let appContext = context.getApplicationContext();
appContext.killAllProcesses()
```



## cl.ability.3 getProcessRunningInformation Renamed

The **getProcessRunningInformation** API is renamed **getRunningProcessInformation**.

**Change Impact**

JS APIs in API version 9 are affected. Your application needs to adapt these APIs so that it can properly implement features in the SDK environment of the new version.

**Key API/Component Changes**

| Module                             | Class              | Method/Attribute/Enum/Constant                                         | Change Type|
| ----------------------------------- | ------------------ | ------------------------------------------------------------ | -------- |
| @ohos.app.ability.appManager.d.ts   | appManager         | function getProcessRunningInformation(): Promise\<Array\<ProcessRunningInformation\>\>; | Deleted    |
| @ohos.app.ability.appManager.d.ts   | appManager         | function getProcessRunningInformation(callback: AsyncCallback\<Array\<ProcessRunningInformation\>\>): void; | Deleted    |
| @ohos.app.ability.appManager.d.ts   | appManager         | function getRunningProcessInformation(): Promise\<Array\<ProcessInformation\>\>; | Added    |
| @ohos.app.ability.appManager.d.ts   | appManager         | function getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation\>\>): void; | Added    |
| application/ApplicationContext.d.ts | ApplicationContext | getProcessRunningInformation(): Promise\<Array\<ProcessRunningInformation\>\>; | Deleted    |
| application/ApplicationContext.d.ts | ApplicationContext | getProcessRunningInformation(callback: AsyncCallback\<Array\<ProcessRunningInformation\>\>): void; | Deleted    |
| application/ApplicationContext.d.ts | ApplicationContext | getRunningProcessInformation(): Promise\<Array\<ProcessInformation\>\>; | Added    |
| application/ApplicationContext.d.ts | ApplicationContext | getRunningProcessInformation(callback: AsyncCallback\<Array\<ProcessInformation\>\>): void; | Added    |

**Adaptation Guide**

The following code snippet shows how to call **getProcessRunningInformation** in an application.

Code before the change:

```ts
let context: common.UIAbilityContext = globalThis.abilityContext;
let appContext = context.getApplicationContext();
appContext.getProcessRunningInformation()
```

Code after the change:

```ts
let context: common.UIAbilityContext = globalThis.abilityContext;
let appContext = context.getApplicationContext();
appContext.getRunningProcessInformation()
```
