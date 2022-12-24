# 测试框架使用指导

## 概述
Delegator测试框架是OpenHarmony提供的一套开发者应用自测试框架，旨在为开发者提供针对应用的自测试环境。开发者可以通过Delegator类启动对应Ability，并通过Delegator类提供的能力对Ability进行生命周期切换和监听，同时支持shellCMD输入和测试结果打印显示等功能。

## 约束与限制

测试框架相关接口只能在测试HAP中使用，只有通过`aa test`命令或者DevEco Studio启动测试环境后相关接口才能生效。


## 测试框架启动

测试框架启动有两种方式：

- 方式一：通过`aa test`命令启动。
- 方式二：通过DevEco Studio启动。

### aa test启动

开发者可通过 `aa test` 命令启动测试框架，开发者可以自行指定使用的TestRunner以及TestRunner所在HAP的package name或module name，具体命令示例如下:

**FA模型：**

```javascript
aa test -b BundleName -p com.example.myapplicationfaets -s unittest OpenHarmonyTestRunner -s class ActsAbilityTest -w 20
```

**Stage模型：**
```javascript
aa test -b BundleName -m com.example.myapplicationfaets -s unittest OpenHarmonyTestRunner -s class ActsAbilityTest -w 20
```
| 参数            | 是否必选 | 参数说明                                                     |
| --------------- | -------- | ------------------------------------------------------------ |
| -b              | 是       | TestRunner所在HAP的bundle name。              |
| -p              | 是       | TestRunner所在HAP的package name，FA模型使用。              |
| -m              | 是       | TestRunner所在HAP的module name，Stage模型使用。            |
| -s unittest     | 是       | 启用的TestRunner名称，TestRunner名称和文件名需要保持一致。   |
| -w              | 否       | 测试用例超时时间，单位为秒，如果未指定或指定小于等于0的整数，测试框架会一直等待测试代码调用finishTest才退出。 |
| -s \<key>\<value> | 否       | 支持以key-value的方式输入任何参数，输入的参数可通过AbilityDelegatorArgs.parameters以key-value的方式获取。示例：-s classname myTest，key为"-s classname"，value为"myTest"。 |
| -D              | 否       | 以Debug模式启动被测试应用。 |
| -h              | 否       | 输出帮助信息。 |

### DevEco Studio启动

DevEco Studio启动相关介绍见 [OpenHarmony测试框架](https://developer.harmonyos.com/cn/docs/documentation/doc-guides/ohos-openharmony-test-framework-0000001263160453#section1034420367508)。

## TestRunner介绍

TestRunner是测试框架测试流程入口类。当测试流程启动时，系统会调用TestRunner内相关接口，开发者需要派生该类，并重写onPrepare、onRun方法。DevEco Studio在创建应用模板时会初始化一个默认TestRunner，并在onRun方法启动默认的TestAbility。开发者也可以修改TestAbility测试代码内容，也可以修改默认的TestRunner内onPrepare、onRun方法，自行实现测试代码。具体详细内容请参考TestRunnerAPI接口说明[TestRunner](../reference/apis/js-apis-application-testRunner.md)。

## AbilityDelegatorRegistry介绍

AbilityDelegatorRegistry是测试框架提供的AbilityDelegator仓库类。开发者可以使用AbilityDelegatorRegistry获取AbilityDelegator实例以及执行此次测试时传入和生成的相关参数AbilityDelegatorArgs。开发者可以使用AbilityDelegator调用测试框架提供的函数集进行测试验证。具体详细内容请参考AbilityDelegatorRegistry API接口说明[AbilityDelegatorRegistry](../reference/apis/js-apis-application-abilityDelegatorRegistry.md)。

## AbilityDelegatorArgs介绍

AbilityDelegatorArgs是测试框架提供的测试参数类。开发者可以使用AbilityDelegatorArgs获取执行此次测试时传入和生成的相关参数。具体详细内容请参考AbilityDelegatorArgs API接口说明[AbilityDelegatorArgs](../reference/apis/js-apis-inner-application-abilityDelegatorArgs.md)。

## AbilityMonitor介绍

AbilityMonitor是测试框架提供用来绑定并监听Ability类。开发者可以使用AbilityMonitor绑定Ability，并将AbilityMonitor添加到监听列表。绑定后Ability的创建、生命周期变化等会触发AbilityMonitor内相关回调函数，开发者可以在对应回调函数内进行测试验证。具体详细内容请参考AbilityMonitor API接口说明[AbilityMonitor](../reference/apis/js-apis-application-abilityMonitor.md)。

**示例**

```javascript
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'

function onAbilityCreateCallback(data) {
    console.info("onAbilityCreateCallback");
}

var monitor = {
    abilityName: "abilityname",
    onAbilityCreate: onAbilityCreateCallback
}

var abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.addAbilityMonitor(monitor).then(() => {
    console.info("addAbilityMonitor promise");
});
```

## AbilityDelegator介绍

AbilityDelegator是测试框架主要功能类，提供了启动Ability、获取Ability示例、调度Ability生命周期、对Ability生命周期进行监听、打印测试结果等功能。

**导入模块**

```javascript
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'
```

```javascript
var abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator()
```

### 启动Ability并监听Ability状态变化

配合AbilityMonitor使用，可以实现对Ability启动、Ability实例获取、监听状态变化功能。

**示例：**

```javascript
var abilityDelegator;
var ability;
var timeout = 100;

function onAbilityCreateCallback(data) {
    console.info("onAbilityCreateCallback");
}

var monitor = {
    abilityName: "abilityname",
    onAbilityCreate: onAbilityCreateCallback
}

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.waitAbilityMonitor(monitor, timeout, (err, data) => {
    ability = data;
    console.info("waitAbilityMonitor callback");
});

var want = {
    bundleName: "bundleName",
    abilityName: "abilityName"
};
abilityDelegator.startAbility(want, (err, data) => {
    console.info("startAbility callback");
});
```

### 调度Ability生命周期

AbilityDelegator提供对Ability生命周期进行显示调度的能力，支持Foreground、Background，配合AbilityMonitor中对Ability生命周期监听方法，可以完整的测试Ability生命周期变化。具体详细内容请参考AbilityDelegator API接口说明[AbilityDelegator](../reference/apis/js-apis-inner-application-abilityDelegator.md)。

### 执行shellCMD命令

AbilityDelegator提供执行shellCMD命令功能，开发者可以在测试代码中执行shell命令，该功能仅在测试环境中生效，非测试环境该接口调用无效果。

**示例：**

```javascript
var abilityDelegator;
var cmd = "cmd";
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, (err, data) => {
    console.info("executeShellCommand callback");
});
```

### 打印日志信息

AbilityDelegator提供打印日志信息功能，开发者可以在测试代码中输出过程日志信息到终端控制台。

**示例：**

```javascript
var abilityDelegator;
var msg = "msg";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.print(msg, (err) => {
    console.info("print callback");
});
```

### 结束测试并打印日志信息

AbilityDelegator提供主动结束测试的功能，开发者可以在测试代码中主动结束测试过程并输出日志码及信息到终端控制台。

**示例：**

```javascript
var abilityDelegator;
var msg = "msg";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.finishTest(msg, 0, (err) => {
    console.info("finishTest callback");
});
```