# AbilityDelegatorRegistry

> **说明**
>
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。

## 导入模块

```js
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'
```



## AbilityLifecycleState

Ability生命周期状态

| 名称          | 值   | 说明                                                         |
| ------------- | ---- | ------------------------------------------------------------ |
| UNINITIALIZED | 0    | 表示无效状态。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| CREATE        | 1    | 表示Ability处于已创建状态。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| FOREGROUND    | 2    | 表示Ability处于前台状态。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| BACKGROUND    | 3    | 表示Ability处于后台状态。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| DESTROY       | 4    | 表示Ability处于已销毁状态。<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |



## AbilityDelegatorRegistry.getAbilityDelegator

getAbilityDelegator(): AbilityDelegator

获取应用程序的AbilityDelegator对象

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**-

**返回值：**

| 类型                                  | 说明                                                         |
| ------------------------------------- | ------------------------------------------------------------ |
| [AbilityDelegator](#AbilityDelegator) | [AbilityDelegator](#AbilityDelegator)对象。可有用来调度测试框架相关功能。 |

**示例：**

```js
var abilityDelegator;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
```



## AbilityDelegatorRegistry.getArguments

getArguments(): AbilityDelegatorArgs

获取单元测试参数AbilityDelegatorArgs对象

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**-

**返回值：**

| 类型                                          | 说明                                                         |
| --------------------------------------------- | ------------------------------------------------------------ |
| [AbilityDelegatorArgs](#AbilityDelegatorArgs) | [AbilityDelegatorArgs](#AbilityDelegatorArgs)对象。可以用来获取测试参数。 |

**示例：**

```js
var args = AbilityDelegatorRegistry.getArguments();
console.info("=========>getArguments==========>bundleName:" + args.bundleName);
console.info("=========>getArguments==========>testCaseNames:" + args.testCaseNames);
console.info("=========>getArguments==========>testRunnerClassName:" + args.testRunnerClassName);
```



## AbilityDelegator

### addAbilityMonitor

addAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void

添加AbilityMonitor实例（callback形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                              | 必填说明 | 说明                                  |
| -------- | --------------------------------- | -------- | ------------------------------------- |
| monitor  | [AbilityMonitor](#AbilityMonitor) | 是       | [AbilityMonitor](#AbilityMonitor)实例 |
| callback | AsyncCallback\<void>              | 是       | 表示指定的回调方法                    |

**示例：**

```js
var abilityDelegator;

function onAbilityCreateCallback(err) {
    console.info("==========================>onAbilityCreateCallback=======================>");
}

var monitor = {
	abilityName: "abilityname",
	onAbilityCreate: onAbilityCreateCallback
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.addAbilityMonitor(monitor, (err) => {
    console.info("==========================>AddAbilityMonitorCallback=======================>");
});
```



### addAbilityMonitor

addAbilityMonitor(monitor: AbilityMonitor): Promise\<void>

添加AbilityMonitor实例（promise形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                  |
| ------- | --------------------------------- | ---- | ------------------------------------- |
| monitor | [AbilityMonitor](#AbilityMonitor) | 是   | [AbilityMonitor](#AbilityMonitor)实例 |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<void> | 以Promise形式返回。 |

**示例：**

```js
var abilityDelegator;

function onAbilityCreateCallback(err) {
    console.info("==========================>onAbilityCreateCallback=======================>");
}

var monitor = {
	abilityName : "abilityname",
	onAbilityCreate: onAbilityCreateCallback
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.addAbilityMonitor(monitor).then((void) => {
	console.info("==========================>AddAbilityMonitor Promise=======================>");
});
```



### removeAbilityMonitor

removeAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void

删除已经添加的AbilityMonitor实例（callback形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                  |
| -------- | --------------------------------- | ---- | ------------------------------------- |
| monitor  | [AbilityMonitor](#AbilityMonitor) | 是   | [AbilityMonitor](#AbilityMonitor)实例 |
| callback | AsyncCallback\<void>              | 是   | 表示指定的回调方法                    |

**示例：**

```js
var abilityDelegator;

function onAbilityCreateCallback(err) {
    console.info("==========================>onAbilityCreateCallback=======================>");
}

var monitor = {
	abilityName : "abilityname",
	onAbilityCreate: onAbilityCreateCallback
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.removeAbilityMonitor(monitor, (err) => {
    console.info("==========================>removeAbilityMonitorCallback=======================>");
});
```



### removeAbilityMonitor

removeAbilityMonitor(monitor: AbilityMonitor): Promise\<void>

删除已经添加的AbilityMonitor实例（promise形式）

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 名称    | 类型                              | 必填 | 说明                                  |
| ------- | --------------------------------- | ---- | ------------------------------------- |
| monitor | [AbilityMonitor](#AbilityMonitor) | 是   | [AbilityMonitor](#AbilityMonitor)实例 |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<void> | 以Promise形式返回。 |

- 示例

```js
var abilityDelegator;

function onAbilityCreateCallback(err) {
    console.info("==========================>onAbilityCreateCallback=======================>");
}

var monitor = {
	abilityName : "abilityname",
	onAbilityCreate: onAbilityCreateCallback
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.removeAbilityMonitor(monitor).then((void) => {
	console.info("==========================>removeAbilityMonitor Promise=======================>");
});
```



### waitAbilityMonitor

waitAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<Ability>): void

等待与AbilityMonitor实例匹配的ability到达OnCreate生命周期，并返回ability实例（callback形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                  |
| -------- | --------------------------------- | ---- | ------------------------------------- |
| monitor  | [AbilityMonitor](#AbilityMonitor) | 是   | [AbilityMonitor](#AbilityMonitor)实例 |
| callback | AsyncCallback\<Ability>           | 是   | 表示指定的回调方法                    |

**示例：**

```js
var abilityDelegator;

function onAbilityCreateCallback(err) {
    console.info("==========================>onAbilityCreateCallback=======================>");
}

var monitor = {
	abilityName: "abilityname",
	onAbilityCreate: onAbilityCreateCallback
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityMonitor(monitor, (err, data) => {
    console.info("==========================>waitAbilityMonitorCallback=======================>");
});
```



### waitAbilityMonitor

waitAbilityMonitor(monitor: AbilityMonitor, timeout: number, callback: AsyncCallback\<Ability>): void

设置等待时间，等待与AbilityMonitor实例匹配的ability到达OnCreate生命周期，并返回ability实例（callback形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                              | 必填 | 说明                                  |
| -------- | --------------------------------- | ---- | ------------------------------------- |
| monitor  | [AbilityMonitor](#AbilityMonitor) | 是   | [AbilityMonitor](#AbilityMonitor)实例 |
| timeout  | number                            | 是   | 最大等待时间，单位毫秒                |
| callback | AsyncCallback\<Ability>           | 是   | 表示指定的回调方法                    |

**示例：**

```js
var abilityDelegator;
var timeout = 100;

function onAbilityCreateCallback(err) {
    console.info("==========================>onAbilityCreateCallback=======================>");
}

var monitor = {
	abilityName : "abilityname",
	onAbilityCreate: onAbilityCreateCallback
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityMonitor(monitor, timeout, (err, data) => {
    console.info("==========================>waitAbilityMonitorCallback=======================>");
});
```



### waitAbilityMonitor

waitAbilityMonitor(monitor: AbilityMonitor, timeout?: number): Promise\<Ability>

等待与AbilityMonitor实例匹配的ability到达OnCreate生命周期，并返回ability实例（promise形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                              | 必填 | 说明                                  |
| ------- | --------------------------------- | ---- | ------------------------------------- |
| monitor | [AbilityMonitor](#AbilityMonitor) | 是   | [AbilityMonitor](#AbilityMonitor)实例 |
| timeout | number                            | 否   | 最大等待时间，单位毫秒                |

**返回值：**

| 类型           | 说明                       |
| -------------- | -------------------------- |
| Promise\<void> | 以Promise形式返回Ability。 |

**示例：**

```js
var abilityDelegator;

function onAbilityCreateCallback(err) {
    console.info("==========================>onAbilityCreateCallback=======================>");
}

var monitor = {
	abilityName : "abilityname",
	onAbilityCreate: onAbilityCreateCallback
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityMonitor(monitor).then((data) => {
	console.info("==========================>waitAbilityMonitor Promise=======================>");
});
```



### getAppContext

getAppContext(): Context

获取应用Context

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                  | 说明                                        |
| ------------------------------------- | ------------------------------------------- |
| [Context](js-apis-Context.md#Context) | 应用[Context](js-apis-Context.md#Context)。 |

**示例：**

```js
var abilityDelegator;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
var context = abilityDelegator.getAppContext();
```



### getAbilityState

getAbilityState(ability: Ability): number

获取指定ability的生命周期状态

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明            |
| ------- | ------- | ---- | --------------- |
| ability | Ability | 是   | 指定Ability对象 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 指定ability的生命周期状态。状态枚举值使用[AbilityLifecycleState](#AbilityLifecycleState)。 |

**示例：**

```js
var abilityDelegator;
var ability;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err, data) => {
    console.info("==========================>GetCurrentTopCallBack=======================>");
    ability = data;
    var state = abilityDelegator.getAbilityState(ability);
    console.info("==========================>getAbilityState=======================>" + state);
});
```



### getCurrentTopAbility

getCurrentTopAbility(callback: AsyncCallback\<Ability>): void

获取当前应用顶部ability（callback形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明               |
| -------- | ----------------------- | ---- | ------------------ |
| callback | AsyncCallback\<Ability> | 是   | 表示指定的回调方法 |

**示例：**

```js
var abilityDelegator;
var ability;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err, data) => {
    console.info("==========================>GetCurrentTopCallBack=======================>");
    ability = data;
});
```



### getCurrentTopAbility

getCurrentTopAbility(): Promise\<Ability>

获取当前应用顶部ability（promise形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型              | 说明                                   |
| ----------------- | -------------------------------------- |
| Promise\<Ability> | 以Promise形式返回当前应用顶部ability。 |

**示例：**

```js
var abilityDelegator;
var ability;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility().then((data) => {
	console.info("==========================>getCurrentTopAbility Promise=======================>");
	ability = data;
});
```



### startAbility

startAbility(want: Want, callback: AsyncCallback\<void>): void

启动指定ability（callback形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

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
    console.info("==========================>StartAbilityCallBack=======================>");
});
```



### startAbility

startAbility(want: Want): Promise\<void>

启动指定ability（promise形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

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
abilityDelegator.startAbility(want).then((data) => {
	console.info("==========================>startAbility Promise=======================>");
});
```



### doAbilityForeground

doAbilityForeground(ability: Ability, callback: AsyncCallback\<boolean>): void

调度指定ability生命周期状态到Foreground状态（callback形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                    |
| -------- | ----------------------- | ---- | ------------------------------------------------------- |
| ability  | Ability                 | 是   | 指定Ability对象                                         |
| callback | AsyncCallback\<boolean> | 是   | 表示指定的回调方法<br/>\- true：成功<br/>\- false：失败 |

**示例：**

```js
var abilityDelegator;
var ability;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err, data) => {
    console.info("==========================>GetCurrentTopCallBack=======================>");
    ability = data;
    abilityDelegator.doAbilityForeground(ability, (err, data) => {
    	console.info("==========================>DoAbilityForegroundCallBack=======================>");
	});
});
```



### doAbilityForeground

doAbilityForeground(ability: Ability): Promise\<boolean>

调度指定ability生命周期状态到Foreground状态（promise形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明            |
| ------- | ------- | ---- | --------------- |
| ability | Ability | 是   | 指定Ability对象 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | 以Promise形式返回执行结果。<br/>\- true：成功<br/>\- false：失败 |

**示例：**

```js
var abilityDelegator;
var ability;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err, data) => {
    console.info("==========================>GetCurrentTopCallBack=======================>");
    ability = data;
    abilityDelegator.doAbilityForeground(ability).then((data) => {
        console.info("==========================>doAbilityForeground Promise=======================>");
    });
});
```



### doAbilityBackground

doAbilityBackground(ability: Ability, callback: AsyncCallback\<boolean>): void

调度指定ability生命周期状态到Background状态（callback形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                    |
| -------- | ----------------------- | ---- | ------------------------------------------------------- |
| ability  | Ability                 | 是   | 指定Ability对象                                         |
| callback | AsyncCallback\<boolean> | 是   | 表示指定的回调方法<br/>\- true：成功<br/>\- false：失败 |

**示例：**

```js
var abilityDelegator;
var ability;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err, data) => {
    console.info("==========================>GetCurrentTopCallBack=======================>");
    ability = data;
    abilityDelegator.doAbilityBackground(ability, (err, data) => {
        console.info("==========================>DoAbilityBackgroundCallBack=======================>");
    });
});
```



### doAbilityBackground

doAbilityBackground(ability: Ability): Promise\<boolean>

调度指定ability生命周期状态到Background状态（promise形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明            |
| ------- | ------- | ---- | --------------- |
| ability | Ability | 是   | 指定Ability对象 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | 以Promise形式返回执行结果。<br/>\- true：成功<br/>\- false：失败 |

**示例：**

```js
var abilityDelegator;
var ability;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.getCurrentTopAbility((err, data) => {
    console.info("==========================>GetCurrentTopCallBack=======================>");
    ability = data;
    abilityDelegator.doAbilityBackground(ability).then((data) => {
        console.info("==========================>doAbilityBackground Promise=======================>");
    });
});
```



### print

print(msg: string, callback: AsyncCallback\<void>): void

打印日志信息到单元测试终端控制台（callback形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

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
    console.info("==========================>printCallBack=======================>");
});
```



### print

print(msg: string): Promise\<void>

打印日志信息到单元测试终端控制台（promise形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

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
	console.info("==========================>print Promise=======================>");
});
```



### executeShellCommand

executeShellCommand(cmd: string, callback: AsyncCallback\<ShellCmdResult>): void

执行指定的shell命令（callback形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                              | 必填 | 说明               |
| -------- | ------------------------------------------------- | ---- | ------------------ |
| cmd      | string                                            | 是   | shell命令字符串    |
| callback | AsyncCallback\<[ShellCmdResult](#ShellCmdResult)> | 是   | 表示指定的回调方法 |

**示例：**

```js
var abilityDelegator;
var cmd = "cmd";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, (err,data) => {
    console.info("==========================>executeShellCommandCallBack=======================>");
});
```



### executeShellCommand

executeShellCommand(cmd: string, timeoutSecs: number, callback: AsyncCallback\<ShellCmdResult>): void

执行指定的shell命令（callback形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名      | 类型                                              | 必填 | 说明               |
| ----------- | ------------------------------------------------- | ---- | ------------------ |
| cmd         | string                                            | 是   | shell命令字符串    |
| timeoutSecs | number                                            | 是   | 设定时间，单位秒   |
| callback    | AsyncCallback\<[ShellCmdResult](#ShellCmdResult)> | 是   | 表示指定的回调方法 |

**示例：**

```js
var abilityDelegator;
var cmd = "cmd";
var timeout = 100;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, timeout, (err,data) => {
    console.info("==========================>executeShellCommandCallBack=======================>");
});
```



### executeShellCommand

executeShellCommand(cmd: string, timeoutSecs: number): Promise\<ShellCmdResult>

执行指定的shell命令（promise形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名      | 类型   | 必填 | 说明             |
| ----------- | ------ | ---- | ---------------- |
| cmd         | string | 是   | shell命令字符串  |
| timeoutSecs | number | 否   | 设定时间，单位秒 |

**返回值：**

| 类型                                        | 说明                                                         |
| ------------------------------------------- | ------------------------------------------------------------ |
| Promise\<[ShellCmdResult](#ShellCmdResult)> | 以Promise形式返回Shell命令执行结果[ShellCmdResult](#ShellCmdResult)对象。 |

**示例：**

```js
var abilityDelegator;
var cmd = "cmd";
var timeout = 100;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, timeout).then((data) => {
	console.info("==========================>executeShellCommand Promise=======================>");
});
```



## AbilityDelegatorArgs

测试参数信息

| 名称                | 类型                   | 可读 | 可写 | 说明                                                         |
| ------------------- | ---------------------- | ---- | ---- | ------------------------------------------------------------ |
| bundleName          | string                 | 是   | 是   | 当前被测试应用的包名<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| parameters          | {[key:string]: string} | 是   | 是   | 当前启动单元测试的参数<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| testCaseNames       | string                 | 是   | 是   | 测试用例名称<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| testRunnerClassName | string                 | 是   | 是   | 执行测试用例的测试执行器的名称<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |



## AbilityMonitor

Ability监听器

| 名称                 | 类型     | 可读 | 可写 | 说明                                                         |
| -------------------- | -------- | ---- | ---- | ------------------------------------------------------------ |
| abilityName          | string   | 是   | 是   | 当前AbilityMonitor绑定的ability名称<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| onAbilityCreate      | function | 是   | 是   | ability被启动初始化时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| onAbilityForeground  | function | 是   | 是   | ability状态变成前台时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| onAbilityBackground  | function | 是   | 是   | ability状态变成后台时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| onAbilityDestroy     | function | 是   | 是   | ability被销毁前的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| onWindowStageCreate  | function | 是   | 是   | window stage被创建时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| onWindowStageRestore | function | 是   | 是   | window stage被重载时的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| onWindowStageDestroy | function | 是   | 是   | window stage被销毁前的回调函数<br/>不设置该属性则不能收到该生命周期回调<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |



## ShellCmdResult

Shell命令执行结果

| 名称      | 类型   | 可读 | 可写 | 说明                                                         |
| --------- | ------ | ---- | ---- | ------------------------------------------------------------ |
| stdResult | string | 是   | 是   | 标准输出内容<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
| exitCode  | number | 是   | 是   | 结果码<br/>**系统能力**：SystemCapability.Ability.AbilityRuntime.Core |
