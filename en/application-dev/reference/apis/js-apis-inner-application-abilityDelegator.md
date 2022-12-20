# AbilityDelegator

The **AbilityDelegator** module provides APIs for managing **AbilityMonitor** instances that are used to monitor the lifecycle state changes of a specified ability. You can use the APIs to add and remove **AbilityMonitor** instances, wait for an ability to reach the **OnCreate** lifecycle state, set the waiting time, obtain the lifecycle state of an ability, obtain the top ability of the current application, and start an ability.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Usage

The ability delegator can be obtained by calling **getAbilityDelegator** in **AbilityDelegatorRegistry**.
```ts
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'

var abilityDelegator;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();

```

## AbilityDelegator

### addAbilityMonitor<sup>9+</sup>

addAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void;

Adds an **AbilityMonitor** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| monitor  | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor) | Yes      | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor) instance.|
| callback | AsyncCallback\<void>                                         | Yes      | Callback used to return the result.                                          |

**Example**

```ts
var abilityDelegator;

function onAbilityCreateCallback(data) {
    console.info("onAbilityCreateCallback");
}

var monitor = {
    abilityName: "abilityname",
    onAbilityCreate: onAbilityCreateCallback
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.addAbilityMonitor(monitor, (err : any) => {
    console.info("addAbilityMonitor callback");
});
```

### addAbilityMonitor<sup>9+</sup>

addAbilityMonitor(monitor: AbilityMonitor): Promise\<void>;

Adds an **AbilityMonitor** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor) | Yes  | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor) instance.|

**Return value**

| Type          | Description               |
| -------------- | ------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
var abilityDelegator;

function onAbilityCreateCallback(data) {
    console.info("onAbilityCreateCallback");
}

var monitor = {
    abilityName: "abilityname",
    onAbilityCreate: onAbilityCreateCallback
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.addAbilityMonitor(monitor).then(() => {
    console.info("addAbilityMonitor promise");
});
```



### removeAbilityMonitor<sup>9+</sup>

removeAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void;

Removes an **AbilityMonitor** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor  | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor) | Yes  | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor) instance.|
| callback | AsyncCallback\<void>                                         | Yes  | Callback used to return the result.                                          |

**Example**

```ts
var abilityDelegator;

function onAbilityCreateCallback(data) {
    console.info("onAbilityCreateCallback");
}

var monitor = {
    abilityName: "abilityname",
    onAbilityCreate: onAbilityCreateCallback
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.removeAbilityMonitor(monitor, (err : any) => {
    console.info("removeAbilityMonitor callback");
});
```



### removeAbilityMonitor<sup>9+</sup>

removeAbilityMonitor(monitor: AbilityMonitor): Promise\<void>;

Removes an **AbilityMonitor** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name   | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor) | Yes  | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor) instance.|

**Return value**

| Type          | Description               |
| -------------- | ------------------- |
| Promise\<void> | Promise used to return the result.|

- Example

```ts
var abilityDelegator;

function onAbilityCreateCallback(data) {
    console.info("onAbilityCreateCallback");
}

var monitor = {
    abilityName: "abilityname",
    onAbilityCreate: onAbilityCreateCallback
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.removeAbilityMonitor(monitor).then(() => {
    console.info("removeAbilityMonitor promise");
});
```



### waitAbilityMonitor<sup>9+</sup>

waitAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<UIAbility>): void;

Waits for the **Ability** instance that matches the **AbilityMonitor** instance to reach the **OnCreate** lifecycle state and returns the **Ability** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor  | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor) | Yes  | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor) instance.|
| callback | AsyncCallback\<[UIAbility](js-apis-app-ability-uiAbility.md)> | Yes  | Callback used to return the result.                                          |

**Example**

```ts
var abilityDelegator;

function onAbilityCreateCallback(data) {
    console.info("onAbilityCreateCallback");
}

var monitor = {
    abilityName: "abilityname",
    onAbilityCreate: onAbilityCreateCallback
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityMonitor(monitor, (err : any, data : any) => {
    console.info("waitAbilityMonitor callback");
});
```

### waitAbilityMonitor<sup>9+</sup>

waitAbilityMonitor(monitor: AbilityMonitor, timeout: number, callback: AsyncCallback\<UIAbility>): void;

Waits a period of time for the **Ability** instance that matches the **AbilityMonitor** instance to reach the **OnCreate** lifecycle state and returns the **Ability** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor  | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor) | Yes  | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor) instance.|
| timeout  | number                                                       | No  | Maximum waiting time, in milliseconds.                                |
| callback | AsyncCallback\<[UIAbility](js-apis-app-ability-uiAbility.md)> | Yes  | Callback used to return the result.                                          |

**Example**

```ts
var abilityDelegator;
var timeout = 100;

function onAbilityCreateCallback(data) {
    console.info("onAbilityCreateCallback");
}

var monitor = {
    abilityName: "abilityname",
    onAbilityCreate: onAbilityCreateCallback
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityMonitor(monitor, timeout, (err : any, data : any) => {
    console.info("waitAbilityMonitor callback");
});
```



### waitAbilityMonitor<sup>9+</sup>

waitAbilityMonitor(monitor: AbilityMonitor, timeout?: number): Promise\<UIAbility>;

Waits a period of time for the **Ability** instance that matches the **AbilityMonitor** instance to reach the **OnCreate** lifecycle state and returns the **Ability** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor) | Yes  | [AbilityMonitor](js-apis-inner-application-abilityMonitor.md#AbilityMonitor) instance.|
| timeout | number                                                       | No  | Maximum waiting time, in milliseconds.                                |

**Return value**

| Type                                                       | Description                      |
| ----------------------------------------------------------- | -------------------------- |
| Promise\<[UIAbility](js-apis-app-ability-uiAbility.md)> | Promise used to return the **Ability** instance.|

**Example**

```ts
var abilityDelegator;

function onAbilityCreateCallback(data) {
    console.info("onAbilityCreateCallback");
}

var monitor = {
    abilityName: "abilityname",
    onAbilityCreate: onAbilityCreateCallback
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityMonitor(monitor).then((data : any) => {
    console.info("waitAbilityMonitor promise");
});
```



### getAppContext<sup>9+</sup>

getAppContext(): Context;

Obtains the application context.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                 | Description                                       |
| ------------------------------------- | ------------------------------------------- |
| [Context](js-apis-inner-application-context.md) | Application [context](js-apis-inner-application-context.md).|

**Example**

```ts
var abilityDelegator;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
var context = abilityDelegator.getAppContext();
```



### getAbilityState<sup>9+</sup>

getAbilityState(ability: UIAbility): number;

Obtains the lifecycle state of an ability.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type                                             | Mandatory| Description           |
| ------- | ------------------------------------------------- | ---- | --------------- |
| ability | [UIAbility](js-apis-app-ability-uiAbility.md) | Yes  | Target ability.|

**Return value**

| Type  | Description                                                        |
| ------ | ------------------------------------------------------------ |
| number | Lifecycle state of the ability. For details about the available enumerated values, see [AbilityLifecycleState](js-apis-application-abilityDelegatorRegistry.md#AbilityLifecycleState).|

**Example**

```ts
var abilityDelegator;
var ability;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err : any, data : any) => {
    console.info("getCurrentTopAbility callback");
    ability = data;
    var state = abilityDelegator.getAbilityState(ability);
    console.info("getAbilityState" + state);
});
```



### getCurrentTopAbility<sup>9+</sup>

getCurrentTopAbility(callback: AsyncCallback\<UIAbility>): void;

Obtains the top ability of this application. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description              |
| -------- | ------------------------------------------------------------ | ---- | ------------------ |
| callback | AsyncCallback\<[UIAbility](js-apis-app-ability-uiAbility.md)> | Yes  | Callback used to return the result.|

**Example**

```ts
var abilityDelegator;
var ability;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err : any, data : any) => {
    console.info("getCurrentTopAbility callback");
    ability = data;
});
```



### getCurrentTopAbility<sup>9+</sup>

getCurrentTopAbility(): Promise\<UIAbility>;

Obtains the top ability of this application. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Return value**

| Type                                                       | Description                                  |
| ----------------------------------------------------------- | -------------------------------------- |
| Promise\<[UIAbility](js-apis-app-ability-uiAbility.md)> | Promise used to return the top ability.|

**Example**

```ts
var abilityDelegator;
var ability;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility().then((data : any) => {
    console.info("getCurrentTopAbility promise");
    ability = data;
});
```



### startAbility<sup>9+</sup>

startAbility(want: Want, callback: AsyncCallback\<void>): void;

Starts an ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description              |
| -------- | -------------------------------------- | ---- | ------------------ |
| want     | [Want](js-apis-application-want.md) | Yes  | **Want** parameter for starting the ability.   |
| callback | AsyncCallback\<void>                   | Yes  | Callback used to return the result.|

**Example**

```ts
var abilityDelegator;
var want = {
    bundleName: "bundleName",
    abilityName: "abilityName"
};

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.startAbility(want, (err : any, data : any) => {
    console.info("startAbility callback");
});
```



### startAbility<sup>9+</sup>

startAbility(want: Want): Promise\<void>;

Starts an ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type                                  | Mandatory| Description           |
| ------ | -------------------------------------- | ---- | --------------- |
| want   | [Want](js-apis-application-want.md) | Yes  | **Want** parameter for starting the ability.|

**Return value**

| Type          | Description               |
| -------------- | ------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
var abilityDelegator;
var want = {
    bundleName: "bundleName",
    abilityName: "abilityName"
};

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.startAbility(want).then((data: any) => {
    console.info("startAbility promise");
});
```



### doAbilityForeground<sup>9+</sup>

doAbilityForeground(ability: UIAbility, callback: AsyncCallback\<void>): void;

Schedules the lifecycle state of an ability to **Foreground**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                   |
| -------- | ----------------------- | ---- | ------------------------------------------------------- |
| ability  | UIAbility               | Yes  | Target ability.                                        |
| callback | AsyncCallback\<void>    | Yes  | Callback used to return the result.<br>\- **true**: The operation is successful.<br>\- **false**: The operation failed.|

**Example**

```ts
var abilityDelegator;
var ability;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err : any, data : any) => {
    console.info("getCurrentTopAbility callback");
    ability = data;
    abilityDelegator.doAbilityForeground(ability, (err : any, data : any) => {
        console.info("doAbilityForeground callback");
    });
});
```



### doAbilityForeground<sup>9+</sup>

doAbilityForeground(ability: UIAbility): Promise\<void>;

Schedules the lifecycle state of an ability to **Foreground**. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type   | Mandatory| Description           |
| ------- | ------- | ---- | --------------- |
| ability | UIAbility | Yes  | Target ability.|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result.<br>\- **true**: The operation is successful.<br>\- **false**: The operation failed.|

**Example**

```ts
var abilityDelegator;
var ability;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err : any, data : any) => {
    console.info("getCurrentTopAbility callback");
    ability = data;
    abilityDelegator.doAbilityForeground(ability).then((data : any) => {
        console.info("doAbilityForeground promise");
    });
});
```



### doAbilityBackground<sup>9+</sup>

doAbilityBackground(ability: UIAbility, callback: AsyncCallback\<void>): void;

Schedules the lifecycle state of an ability to **Background**. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                   |
| -------- | ----------------------- | ---- | ------------------------------------------------------- |
| ability  | UIAbility                 | Yes  | Target ability.                                        |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.<br>\- **true**: The operation is successful.<br>\- **false**: The operation failed.|

**Example**

```ts
var abilityDelegator;
var ability;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err : any, data : any) => {
    console.info("getCurrentTopAbility callback");
    ability = data;
    abilityDelegator.doAbilityBackground(ability, (err : any, data : any) => {
        console.info("doAbilityBackground callback");
    });
});
```



### doAbilityBackground<sup>9+</sup>

doAbilityBackground(ability: UIAbility): Promise\<void>;

Schedules the lifecycle state of an ability to **Background**. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type   | Mandatory| Description           |
| ------- | ------- | ---- | --------------- |
| ability | UIAbility | Yes  | Target ability.|

**Return value**

| Type             | Description                                                        |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | Promise used to return the result.<br>\- **true**: The operation is successful.<br>\- **false**: The operation failed.|

**Example**

```ts
var abilityDelegator;
var ability;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err : any, data : any) => {
    console.info("getCurrentTopAbility callback");
    ability = data;
    abilityDelegator.doAbilityBackground(ability).then((data : any) => {
        console.info("doAbilityBackground promise");
    });
});
```



### printSync<sup>9+</sup>

printSync(msg: string): void;

Prints log information to the unit test console.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| msg    | string | Yes  | Log string.|

**Example**

```ts
var abilityDelegator;
var msg = "msg";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.printSync(msg);
```



### print

print(msg: string, callback: AsyncCallback\<void>): void;

Prints log information to the unit test console. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                | Mandatory| Description              |
| -------- | -------------------- | ---- | ------------------ |
| msg      | string               | Yes  | Log string.        |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
var abilityDelegator;
var msg = "msg";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.print(msg, (err : any) => {
    console.info("print callback");
});
```



### print

print(msg: string): Promise\<void>;

Prints log information to the unit test console. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| msg    | string | Yes  | Log string.|

**Return value**

| Type          | Description               |
| -------------- | ------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
var abilityDelegator;
var msg = "msg";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.print(msg).then(() => {
    console.info("print promise");
});
```



### executeShellCommand

executeShellCommand(cmd: string, callback: AsyncCallback\<ShellCmdResult>): void;

Executes a shell command. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description              |
| -------- | ------------------------------------------------------------ | ---- | ------------------ |
| cmd      | string                                                       | Yes  | Shell command string.   |
| callback | AsyncCallback\<[ShellCmdResult](js-apis-inner-application-shellCmdResult.md#ShellCmdResult)> | Yes  | Callback used to return the result.|

**Example**

```ts
var abilityDelegator;
var cmd = "cmd";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, (err : any, data : any) => {
    console.info("executeShellCommand callback");
});
```



### executeShellCommand

executeShellCommand(cmd: string, timeoutSecs: number, callback: AsyncCallback\<ShellCmdResult>): void;

Executes a shell command with the timeout period specified. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name     | Type                                                        | Mandatory| Description                         |
| ----------- | ------------------------------------------------------------ | ---- | ----------------------------- |
| cmd         | string                                                       | Yes  | Shell command string.              |
| timeoutSecs | number                                                       | No  | Command timeout period, in seconds.|
| callback    | AsyncCallback\<[ShellCmdResult](js-apis-inner-application-shellCmdResult.md#ShellCmdResult)> | Yes  | Callback used to return the result.           |

**Example**

```ts
var abilityDelegator;
var cmd = "cmd";
var timeout = 100;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, timeout, (err : any, data : any) => {
    console.info("executeShellCommand callback");
});
```



### executeShellCommand

executeShellCommand(cmd: string, timeoutSecs?: number): Promise\<ShellCmdResult>;

Executes a shell command with the timeout period specified. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name     | Type  | Mandatory| Description                         |
| ----------- | ------ | ---- | ----------------------------- |
| cmd         | string | Yes  | Shell command string.              |
| timeoutSecs | number | No  | Command timeout period, in seconds.|

**Return value**

| Type                                                        | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise\<[ShellCmdResult](js-apis-inner-application-shellCmdResult.md#ShellCmdResult)> | Promise used to return a [ShellCmdResult](js-apis-inner-application-shellCmdResult.md#ShellCmdResult) object.|

**Example**

```ts
var abilityDelegator;
var cmd = "cmd";
var timeout = 100;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, timeout).then((data : any) => {
    console.info("executeShellCommand promise");
});
```



### finishTest<sup>9+</sup>

finishTest(msg: string, code: number, callback: AsyncCallback\<void>): void;

Finishes the test and prints log information to the unit test console. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                | Mandatory| Description              |
| -------- | -------------------- | ---- | ------------------ |
| msg      | string               | Yes  | Log string.        |
| code     | number               | Yes  | Log code.            |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```ts
var abilityDelegator;
var msg = "msg";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.finishTest(msg, 0, (err : any) => {
    console.info("finishTest callback");
});
```



### finishTest<sup>9+</sup>

finishTest(msg: string, code: number): Promise\<void>;

Finishes the test and prints log information to the unit test console. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type  | Mandatory| Description      |
| ------ | ------ | ---- | ---------- |
| msg    | string | Yes  | Log string.|
| code   | number | Yes  | Log code.    |

**Return value**

| Type          | Description               |
| -------------- | ------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
var abilityDelegator;
var msg = "msg";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.finishTest(msg, 0).then(() => {
    console.info("finishTest promise");
});
```

### addAbilityStageMonitor<sup>9+</sup>

addAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<void>): void;

Adds an **AbilityStageMonitor** instance to monitor the lifecycle state changes of an ability stage. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| monitor  | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) | Yes      | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) instance.|
| callback | AsyncCallback\<void>                                         | Yes      | Callback used to return the result.                                          |

**Example**

```ts
var abilityDelegator;

var monitor = {
    moduleName: "moduleName",
    srcEntrance: "srcEntrance",
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.addAbilityStageMonitor(monitor, (err : any) => {
    console.info("addAbilityStageMonitor callback");
});
```



### addAbilityStageMonitor<sup>9+</sup>

addAbilityStageMonitor(monitor: AbilityStageMonitor): Promise\<void>;

Adds an **AbilityStageMonitor** instance to monitor the lifecycle state changes of an ability stage. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) | Yes  | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) instance.|

**Return value**

| Type          | Description               |
| -------------- | ------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
var abilityDelegator;

var monitor = {
    moduleName: "moduleName",
    srcEntrance: "srcEntrance",
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.addAbilityStageMonitor(monitor).then(() => {
    console.info("addAbilityStageMonitor promise");
});
```

### removeAbilityStageMonitor<sup>9+</sup>

removeAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<void>): void;

Removes an **AbilityStageMonitor** instance from the application memory. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| monitor  | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) | Yes      | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) instance.|
| callback | AsyncCallback\<void>                                         | Yes      | Callback used to return the result.                                          |

**Example**

```ts
var abilityDelegator;

var monitor = {
    moduleName: "moduleName",
    srcEntrance: "srcEntrance",
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.removeAbilityStageMonitor(monitor, (err : any) => {
    console.info("removeAbilityStageMonitor callback");
});
```



### removeAbilityStageMonitor<sup>9+</sup>

removeAbilityStageMonitor(monitor: AbilityStageMonitor): Promise\<void>;

Removes an **AbilityStageMonitor** object from the application memory. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) | Yes  | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) instance.|

**Return value**

| Type          | Description               |
| -------------- | ------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```ts
var abilityDelegator;

var monitor = {
    moduleName: "moduleName",
    srcEntrance: "srcEntrance",
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.removeAbilityStageMonitor(monitor).then(() => {
    console.info("removeAbilityStageMonitor promise");
});
```

### waitAbilityStageMonitor<sup>9+</sup>

waitAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<AbilityStage>): void;

Waits for an **AbilityStage** instance that matches the conditions set in an **AbilityStageMonitor** instance and returns the **AbilityStage** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| monitor  | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) | Yes      | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) instance.|
| callback | AsyncCallback\<AbilityStage>                                         | Yes      | Callback used to return the result. If the operation is successful, an **AbilityStage** instance is returned. Otherwise, no value is returned.            |

**Example**

```ts
var abilityDelegator;

function onAbilityCreateCallback(data) {
    console.info("onAbilityCreateCallback");
}

var monitor = {
    moduleName: "moduleName",
    srcEntrance: "srcEntrance",
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityStageMonitor(monitor, (err : any, data : any) => {
    console.info("waitAbilityStageMonitor callback");
});
```
  
### waitAbilityStageMonitor<sup>9+</sup>

waitAbilityStageMonitor(monitor: AbilityStageMonitor, timeout?: number): Promise\<AbilityStage>;

Waits for an **AbilityStage** instance that matches the conditions set in an **AbilityStageMonitor** instance and returns the **AbilityStage** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) | Yes  | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) instance.|
| timeout | number | No  | Maximum waiting time, in milliseconds.|

**Return value**

| Type          | Description               |
| -------------- | ------------------- |
| Promise\<AbilityStage> | Promise used to return the result. If the operation is successful, an **AbilityStage** instance is returned. Otherwise, no value is returned.|

**Example**

```ts
var abilityDelegator;

function onAbilityCreateCallback(data) {
    console.info("onAbilityCreateCallback");
}

var monitor = {
    moduleName: "moduleName",
    srcEntrance: "srcEntrance",
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityStageMonitor(monitor).then((data : any) => {
    console.info("waitAbilityStageMonitor promise");
});
```

### waitAbilityStageMonitor<sup>9+</sup>

waitAbilityStageMonitor(monitor: AbilityStageMonitor, timeout: number, callback: AsyncCallback\<AbilityStage>): void;

Waits a period of time for an **AbilityStage** instance that matches the conditions set in an **AbilityStageMonitor** instance and returns the **AbilityStage** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name | Type                                                        | Mandatory| Description                                                        |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) | Yes  | [AbilityStageMonitor](js-apis-inner-application-abilityStageMonitor.md) instance.|
| timeout | number | No  | Maximum waiting time, in milliseconds.|
| callback | AsyncCallback\<AbilityStage>                                         | Yes      | Callback used to return the result. If the operation is successful, an **AbilityStage** instance is returned. Otherwise, no value is returned.                    |

**Example**

```ts
var abilityDelegator;
var timeout = 100;

function onAbilityCreateCallback(data) {
    console.info("onAbilityCreateCallback");
}

var monitor = {
    moduleName: "moduleName",
    srcEntrance: "srcEntrance",
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityStageMonitor(monitor, timeout, (err : any, data : any) => {
    console.info("waitAbilityStageMonitor callback");
});
```
