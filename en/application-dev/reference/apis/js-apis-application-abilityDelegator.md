# AbilityDelegator

> **Note**
>
> The initial APIs of this module are supported since API version 8. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```js
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'
```



## AbilityDelegator

### startAbility

startAbility(want: Want, callback: AsyncCallback\<void>): void

Starts an ability. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                                  | Mandatory| Description              |
| -------- | -------------------------------------- | ---- | ------------------ |
| want     | [Want](js-apis-featureAbility.md#Want) | Yes  | **Want** parameter for starting the ability.   |
| callback | AsyncCallback\<void>                   | Yes  | Callback used to return the result.|

**Example**

```js
var abilityDelegator;
var want = {
    bundleName: "bundleName",
    abilityName: "abilityName"
};

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.startAbility(want, (err, data) => {
    console.info("startAbility callback");
});
```



### startAbility

startAbility(want: Want): Promise\<void>

Starts an ability. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type                                  | Mandatory| Description           |
| ------ | -------------------------------------- | ---- | --------------- |
| want   | [Want](js-apis-featureAbility.md#Want) | Yes  | **Want** parameter for starting the ability.|

**Return value**

| Type          | Description               |
| -------------- | ------------------- |
| Promise\<void> | Promise used to return the result.|

**Example**

```js
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

### print

print(msg: string, callback: AsyncCallback\<void>): void

Prints log information to the unit test console. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                | Mandatory| Description              |
| -------- | -------------------- | ---- | ------------------ |
| msg      | string               | Yes  | Log string.        |
| callback | AsyncCallback\<void> | Yes  | Callback used to return the result.|

**Example**

```js
var abilityDelegator;
var msg = "msg";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.print(msg, (err) => {
    console.info("print callback");
});
```



### print

print(msg: string): Promise\<void>

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

```js
var abilityDelegator;
var msg = "msg";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.print(msg).then(() => {
    console.info("print promise");
});
```



### executeShellCommand

executeShellCommand(cmd: string, callback: AsyncCallback\<ShellCmdResult>): void

Executes a shell command. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description              |
| -------- | ------------------------------------------------------------ | ---- | ------------------ |
| cmd      | string                                                       | Yes  | Shell command string.   |
| callback | AsyncCallback\<[ShellCmdResult](js-apis-application-shellCmdResult.md#ShellCmdResult)> | Yes  | Callback used to return a [ShellCmdResult](js-apis-application-shellCmdResult.md#ShellCmdResult) object.|

**Example**

```js
var abilityDelegator;
var cmd = "cmd";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, (err, data) => {
    console.info("executeShellCommand callback");
});
```



### executeShellCommand

executeShellCommand(cmd: string, timeoutSecs: number, callback: AsyncCallback\<ShellCmdResult>): void

Executes a shell command with the timeout period specified. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name     | Type                                                        | Mandatory| Description                         |
| ----------- | ------------------------------------------------------------ | ---- | ----------------------------- |
| cmd         | string                                                       | Yes  | Shell command string.              |
| timeoutSecs | number                                                       | Yes  | Command timeout period, in seconds.|
| callback    | AsyncCallback\<[ShellCmdResult](js-apis-application-shellCmdResult.md#ShellCmdResult)> | Yes  | Callback used to return a [ShellCmdResult](js-apis-application-shellCmdResult.md#ShellCmdResult) object.           |

**Example**

```js
var abilityDelegator;
var cmd = "cmd";
var timeout = 100;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, timeout, (err, data) => {
    console.info("executeShellCommand callback");
});
```



### executeShellCommand

executeShellCommand(cmd: string, timeoutSecs: number): Promise\<ShellCmdResult>

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
| Promise\<[ShellCmdResult](js-apis-application-shellCmdResult.md#ShellCmdResult)> | Promise used to return a [ShellCmdResult](js-apis-application-shellCmdResult.md#ShellCmdResult) object.|

**Example**

```js
var abilityDelegator;
var cmd = "cmd";
var timeout = 100;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, timeout).then((data : any) => {
    console.info("executeShellCommand promise");
});
```
