# AbilityDelegator

AbilityDelegator提供添加用于监视指定ability的生命周期状态更改的AbilityMonitor对象的能力，包括对AbilityMonitor实例的添加、删除、等待ability到达OnCreate生命周期、设置等待时间等、获取指定ability的生命周期状态、获取当前应用顶部ability、启动指定ability等。

> **说明：**
> 
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。 

## 使用说明

通过AbilityDelegatorRegistry中getAbilityDelegator方法获取。
```js
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'

var abilityDelegator;

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();

```

## AbilityDelegator

### addAbilityMonitor<sup>9+</sup>

addAbilityMonitor(monitor: AbilityMonitor, callback: AsyncCallback\<void>): void;

添加AbilityMonitor实例（callback形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| monitor  | [AbilityMonitor](js-apis-application-abilityMonitor.md#AbilityMonitor) | 是       | [AbilityMonitor](js-apis-application-abilityMonitor.md#AbilityMonitor)实例 |
| callback | AsyncCallback\<void>                                         | 是       | 表示指定的回调方法                                           |

**示例：**

```js
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

添加AbilityMonitor实例（promise形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityMonitor](js-apis-application-abilityMonitor.md#AbilityMonitor) | 是   | [AbilityMonitor](js-apis-application-abilityMonitor.md#AbilityMonitor)实例 |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<void> | 以Promise形式返回。 |

**示例：**

```js
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

删除已经添加的AbilityMonitor实例（callback形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor  | [AbilityMonitor](js-apis-application-abilityMonitor.md#AbilityMonitor) | 是   | [AbilityMonitor](js-apis-application-abilityMonitor.md#AbilityMonitor)实例 |
| callback | AsyncCallback\<void>                                         | 是   | 表示指定的回调方法                                           |

**示例：**

```js
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

删除已经添加的AbilityMonitor实例（promise形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名    | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityMonitor](js-apis-application-abilityMonitor.md#AbilityMonitor) | 是   | [AbilityMonitor](js-apis-application-abilityMonitor.md#AbilityMonitor)实例 |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<void> | 以Promise形式返回。 |

- 示例

```js
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

等待与AbilityMonitor实例匹配的ability到达OnCreate生命周期，并返回ability实例（callback形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor  | [AbilityMonitor](js-apis-application-abilityMonitor.md#AbilityMonitor) | 是   | [AbilityMonitor](js-apis-application-abilityMonitor.md#AbilityMonitor)实例 |
| callback | AsyncCallback\<[UIAbility](js-apis-application-ability.md#Ability)> | 是   | 表示指定的回调方法                                           |

**示例：**

```js
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

设置等待时间，等待与AbilityMonitor实例匹配的ability到达OnCreate生命周期，并返回ability实例（callback形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor  | [AbilityMonitor](js-apis-application-abilityMonitor.md#AbilityMonitor) | 是   | [AbilityMonitor](js-apis-application-abilityMonitor.md#AbilityMonitor)实例 |
| timeout  | number                                                       | 是   | 最大等待时间，单位毫秒（ms）                                 |
| callback | AsyncCallback\<[UIAbility](js-apis-application-ability.md#Ability)> | 是   | 表示指定的回调方法                                           |

**示例：**

```js
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

设置等待时间，等待与AbilityMonitor实例匹配的ability到达OnCreate生命周期，并返回ability实例（promise形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityMonitor](js-apis-application-abilityMonitor.md#AbilityMonitor) | 是   | [AbilityMonitor](js-apis-application-abilityMonitor.md#AbilityMonitor)实例 |
| timeout | number                                                       | 否   | 最大等待时间，单位毫秒（ms）                                 |

**返回值：**

| 类型                                                        | 说明                       |
| ----------------------------------------------------------- | -------------------------- |
| Promise\<[UIAbility](js-apis-application-ability.md#Ability)> | 以Promise形式返回Ability。 |

**示例：**

```js
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

获取应用Context

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

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



### getAbilityState<sup>9+</sup>

getAbilityState(ability: UIAbility): number;

获取指定ability的生命周期状态

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                              | 必填 | 说明            |
| ------- | ------------------------------------------------- | ---- | --------------- |
| ability | [UIAbility](js-apis-application-ability.md#Ability) | 是   | 指定Ability对象 |

**返回值：**

| 类型   | 说明                                                         |
| ------ | ------------------------------------------------------------ |
| number | 指定ability的生命周期状态。状态枚举值使用[AbilityLifecycleState](js-apis-abilityDelegatorRegistry.md#AbilityLifecycleState)。 |

**示例：**

```js
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

获取当前应用顶部ability（callback形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明               |
| -------- | ------------------------------------------------------------ | ---- | ------------------ |
| callback | AsyncCallback\<[UIAbility](js-apis-application-ability.md#Ability)> | 是   | 表示指定的回调方法 |

**示例：**

```js
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

获取当前应用顶部ability（promise形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**返回值：**

| 类型                                                        | 说明                                   |
| ----------------------------------------------------------- | -------------------------------------- |
| Promise\<[UIAbility](js-apis-application-ability.md#Ability)> | 以Promise形式返回当前应用顶部ability。 |

**示例：**

```js
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

启动指定ability（callback形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                   | 必填 | 说明               |
| -------- | -------------------------------------- | ---- | ------------------ |
| want     | [Want](js-apis-application-Want.md) | 是   | 启动Ability参数    |
| callback | AsyncCallback\<void>                   | 是   | 表示指定的回调方法 |

**示例：**

```js
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

启动指定ability（promise形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型                                   | 必填 | 说明            |
| ------ | -------------------------------------- | ---- | --------------- |
| want   | [Want](js-apis-application-Want.md) | 是   | 启动Ability参数 |

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



### doAbilityForeground<sup>9+</sup>

doAbilityForeground(ability: UIAbility, callback: AsyncCallback\<void>): void;

调度指定ability生命周期状态到Foreground状态（callback形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                    |
| -------- | ----------------------- | ---- | ------------------------------------------------------- |
| ability  | UIAbility               | 是   | 指定Ability对象                                         |
| callback | AsyncCallback\<void>    | 是   | 表示指定的回调方法<br/>\- true：成功<br/>\- false：失败 |

**示例：**

```js
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

调度指定ability生命周期状态到Foreground状态（promise形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明            |
| ------- | ------- | ---- | --------------- |
| ability | UIAbility | 是   | 指定Ability对象 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | 以Promise形式返回执行结果。<br/>\- true：成功<br/>\- false：失败 |

**示例：**

```js
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

调度指定ability生命周期状态到Background状态（callback形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                    | 必填 | 说明                                                    |
| -------- | ----------------------- | ---- | ------------------------------------------------------- |
| ability  | UIAbility                 | 是   | 指定Ability对象                                         |
| callback | AsyncCallback\<void> | 是   | 表示指定的回调方法<br/>\- true：成功<br/>\- false：失败 |

**示例：**

```js
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

调度指定ability生命周期状态到Background状态（promise形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型    | 必填 | 说明            |
| ------- | ------- | ---- | --------------- |
| ability | UIAbility | 是   | 指定Ability对象 |

**返回值：**

| 类型              | 说明                                                         |
| ----------------- | ------------------------------------------------------------ |
| Promise\<boolean> | 以Promise形式返回执行结果。<br/>\- true：成功<br/>\- false：失败 |

**示例：**

```js
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

打印日志信息到单元测试终端控制台

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| msg    | string | 是   | 日志字符串 |

**示例：**

```js
var abilityDelegator;
var msg = "msg";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.printSync(msg);
```



### print

print(msg: string, callback: AsyncCallback\<void>): void;

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
abilityDelegator.print(msg, (err : any) => {
    console.info("print callback");
});
```



### print

print(msg: string): Promise\<void>;

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

executeShellCommand(cmd: string, callback: AsyncCallback\<ShellCmdResult>): void;

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
abilityDelegator.executeShellCommand(cmd, (err : any, data : any) => {
    console.info("executeShellCommand callback");
});
```



### executeShellCommand

executeShellCommand(cmd: string, timeoutSecs: number, callback: AsyncCallback\<ShellCmdResult>): void;

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
abilityDelegator.executeShellCommand(cmd, timeout, (err : any, data : any) => {
    console.info("executeShellCommand callback");
});
```



### executeShellCommand

executeShellCommand(cmd: string, timeoutSecs?: number): Promise\<ShellCmdResult>;

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



### finishTest<sup>9+</sup>

finishTest(msg: string, code: number, callback: AsyncCallback\<void>): void;

结束测试并打印日志信息到单元测试终端控制台（callback形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                 | 必填 | 说明               |
| -------- | -------------------- | ---- | ------------------ |
| msg      | string               | 是   | 日志字符串         |
| code     | number               | 是   | 日志码             |
| callback | AsyncCallback\<void> | 是   | 表示指定的回调方法 |

**示例：**

```js
var abilityDelegator;
var msg = "msg";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.finishTest(msg, 0, (err : any) => {
    console.info("finishTest callback");
});
```



### finishTest<sup>9+</sup>

finishTest(msg: string, code: number): Promise\<void>;

结束测试并打印日志信息到单元测试终端控制台（promise形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名 | 类型   | 必填 | 说明       |
| ------ | ------ | ---- | ---------- |
| msg    | string | 是   | 日志字符串 |
| code   | number | 是   | 日志码     |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<void> | 以Promise形式返回。 |

**示例：**

```js
var abilityDelegator;
var msg = "msg";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.finishTest(msg, 0).then(() => {
    console.info("finishTest promise");
});
```

### addAbilityStageMonitor<sup>9+</sup>

addAbilityStageMonitor(monitor: AbilityStageMonitor, callback: AsyncCallback\<void>): void;

添加一个AbilityStageMonitor对象，用于监视指定abilityStage的生命周期状态更改。（callback形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| monitor  | [AbilityStageMonitor](#abilitystagemonitor) | 是       | [AbilityStageMonitor](#abilitystagemonitor) 实例 |
| callback | AsyncCallback\<void>                                         | 是       | 表示指定的回调方法                                           |

**示例：**

```js
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

添加一个AbilityStageMonitor对象，用于监视指定abilityStage的生命周期状态更改。（promise形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityStageMonitor](#abilitystagemonitor) | 是   | [AbilityStageMonitor](#abilitystagemonitor) 实例 |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<void> | 以Promise形式返回。 |

**示例：**

```js
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

从应用程序内存中删除指定的AbilityStageMonitor对象。（callback形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| monitor  | [AbilityStageMonitor](#abilitystagemonitor) | 是       | [AbilityStageMonitor](#abilitystagemonitor) 实例 |
| callback | AsyncCallback\<void>                                         | 是       | 表示指定的回调方法                                           |

**示例：**

```js
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

从应用程序内存中删除指定的AbilityStageMonitor对象。（promise形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityStageMonitor](#abilitystagemonitor) | 是   | [AbilityStageMonitor](#abilitystagemonitor) 实例 |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<void> | 以Promise形式返回。 |

**示例：**

```js
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

等待并返回与给定AbilityStageMonitor中设置的条件匹配的AbilityStage对象。（callback形式）

**系统能力：**SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名   | 类型                                                         | 必填 | 说明                                                         |
| -------- | ------------------------------------------------------------ | -------- | ------------------------------------------------------------ |
| monitor  | [AbilityStageMonitor](#abilitystagemonitor) | 是       | [AbilityStageMonitor](#abilitystagemonitor) 实例 |
| callback | AsyncCallback\<AbilityStage>                                         | 是       | 成功返回AbilityStage对象，失败返回空。             |

**示例：**

```js
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

等待并返回与给定AbilityStageMonitor中设置的条件匹配的AbilityStage对象。（promise形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityStageMonitor](#abilitystagemonitor) | 是   | [AbilityStageMonitor](#abilitystagemonitor) 实例 |
| timeout | number | 是   | 超时最大等待时间，以毫秒为单位。 |

**返回值：**

| 类型           | 说明                |
| -------------- | ------------------- |
| Promise\<AbilityStage> | 成功返回AbilityStage对象，失败返回空。 |

**示例：**

```js
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

等待并返回与给定AbilityStageMonitor中设置的条件匹配的AbilityStage对象。（callback形式）

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**参数：**

| 参数名  | 类型                                                         | 必填 | 说明                                                         |
| ------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| monitor | [AbilityStageMonitor](#abilitystagemonitor) | 是   | [AbilityStageMonitor](#abilitystagemonitor) 实例 |
| timeout | number | 否   | 超时最大等待时间，以毫秒为单位。 |
| callback | AsyncCallback\<AbilityStage>                                         | 是       | 成功返回AbilityStage对象，失败返回空。                     |

**示例：**

```js
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

## AbilityStageMonitor

提供用于匹配满足指定条件的受监视的AbilityStage对象的方法。最近匹配的AbilityStage对象将保存在AbilityStageMonitor对象中。  

系统能力：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

| 名称                                                         | 类型     | 可读 | 可写 | 说明                                                         |
| ------------------------------------------------------------ | -------- | ---- | ---- | ------------------------------------------------------------ |
| moduleName<sup>9+</sup>                                                 | string   | 是   | 是   | 要监视的abilityStage的模块名。 |
| srcEntrance<sup>9+</sup> | string | 是   | 是   | 要监视的abilityStage的源路径。 |

