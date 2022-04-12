# AbilityDelegator

> **说明**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'
```



## AbilityDelegator
### startAbility

startAbility(want: Want, callback: AsyncCallback\<void>): void

启动指定ability（callback形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明               |
| -------- | -------------------------------------- | ---- | ------------------ |
| want     | [Want](js-apis-featureAbility.md#Want) | 是   | 启动Ability参数    |
| callback | AsyncCallback\<void>                   | 是   | 表示指定的回调方法 |

**示例：**

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

启动指定ability（promise形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型                                   | 必填 | 说明            |
| ------ | -------------------------------------- | ---- | --------------- |
| want   | [Want](js-apis-featureAbility.md#Want) | 是   | 启动Ability参数 |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<void> | 以Promise形式返回。 |

**示例：**

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

打印日志信息到单元测试终端控制台（callback形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明               |
| -------- | -------------------- | ---- | ------------------ |
| msg      | string               | 是   | 日志字符串         |
| callback | AsyncCallback\<void> | 是   | 表示指定的回调方法 |

**示例：**

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

打印日志信息到单元测试终端控制台（promise形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| msg    | string | 是   | 日志字符串 |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<void> | 以Promise形式返回。 |

**示例：**

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

执行指定的shell命令（callback形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明               |
| -------- | ------------------------------------------------------------ | ---- | ------------------ |
| cmd      | string                                                       | 是   | shell命令字符串    |
| callback | AsyncCallback\<[ShellCmdResult](js-apis-application-shellCmdResult.md#ShellCmdResult)> | 是   | 表示指定的回调方法 |

**示例：**

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

指定超时时间，并执行指定的shell命令（callback形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名      | 类型                                                         | 必填 | 说明                          |
| ----------- | ------------------------------------------------------------ | ---- | ----------------------------- |
| cmd         | string                                                       | 是   | shell命令字符串               |
| timeoutSecs | number                                                       | 是   | 设定命令超时时间，单位秒（s） |
| callback    | AsyncCallback\<[ShellCmdResult](js-apis-application-shellCmdResult.md#ShellCmdResult)> | 是   | 表示指定的回调方法            |

**示例：**

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

指定超时时间，并执行指定的shell命令（promise形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明                          |
| ----------- | ------ | ---- | ----------------------------- |
| cmd         | string | 是   | shell命令字符串               |
| timeoutSecs | number | 否   | 设定命令超时时间，单位秒（s） |

**返回值：**

| 类型                                                         | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| Promise\<[ShellCmdResult](js-apis-application-shellCmdResult.md#ShellCmdResult)> | 以Promise形式返回Shell命令执行结果[ShellCmdResult](js-apis-application-shellCmdResult.md#ShellCmdResult)对象。 |

**示例：**

```js
var abilityDelegator;
var cmd = "cmd";
var timeout = 100;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, timeout).then((data : any) => {
    console.info("executeShellCommand promise");
});
```
