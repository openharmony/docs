# 测试框架使用指导

Delegator测试框架是OpenHarmony提供的一套开发者应用自测试框架，旨在为开发者提供针对应用的自测试环境。开发者可以通过delegator类启动对应Ability，并通过Delegator类提供的能力对Ability进行生命周期切换和监听，同时支持shellCMD输入和测试结果打印显示等功能。	

## 测试框架启动

测试框架启动有两种方式，方式一：通过aa test命令启动，方式二：通过IDE启动。
### aa test启动

开发者可通过 aa test 命令启动启动测试框架，开发者可以自行指定使用的runner以及runner所在hap包的package name/module name，具体命令示例如下:

**FA模型：**

```javascript
aa test -p com.example.myapplicationfaets -s unittest OpenHarmonyTestRunner -s class ActsAbilityTest  -w 20
```

**Stage模型：**
```javascript
aa test -m com.example.myapplicationfaets -s unittest OpenHarmonyTestRunner -s class ActsAbilityTest  -w 20
```
| 参数            | 是否必选 | 参数说明                                                     |
| --------------- | -------- | ------------------------------------------------------------ |
| -p              | 是       | TestRunner所在hap包的package name，FA模型使用。              |
| -m              | 是       | TestRunner所在hap包的module name，stage模型使用。            |
| -s unittest     | 是       | 启用的TestRunner名称，TestRunner名称和文件名需要保持一致。   |
| -w              | 否       | 测试用例超时时间，如果未指定，测试框架会一直等待测试代码调用finishTest才退出。 |
| -s <key><value> | 否       | 支持以key-value的方式输入任何参数，输入的参数可通过AbilityDelegatorArgs.parameters以key-value的方式获取。 |

### IDE启动

IDE文档中介绍，待IDE文档上库补充链接。

## TestRunner介绍

TestRunner是测试框架测试流程入口类，当测试流程启动时，系统会调用TestRunner内相关接口，开发者需要派生该类，并重写onPrepare、onRun方法。IDE在创建应用模板时会初始化一个默认TestRunner，并在onRun方法启动默认的TestAbility。开发者也可以修改TestAbility测试代码内容，也可以修改默认的TestRunner内onPrepare、onRun方法，自行实现测试代码。具体详细内容请参考TestRunnerAPI接口说明[TestRunner](../reference/apis/js-apis-testRunner.md)。

## AbilityMonitor介绍

AbilityMonitor是测试框架提供用来绑定并监听Ability类，开发者可以使用AbilityMonitor绑定Ability，并将AbilityMonitor添加到监听列表。绑定后Ability的创建、生命周期变化等会触发AbilityMonitor内相关回调函数，开发者可以在对应回调函数内进行测试验证。具体详细内容请参考AbilityMonitor API接口说明[AbilityMonitor](../reference/apis/js-apis-application-abilityMonitor.md)。

**示例**

```javascript
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'

function onAbilityCreateCallback() {
    console.info("onAbilityCreateCallback");
}

var monitor = {
    abilityName: "abilityname",
    onAbilityCreate: onAbilityCreateCallback
}

var abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.addAbilityMonitor(monitor).then((void) => {
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

function onAbilityCreateCallback() {
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

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.startAbility(want, (err, data) => {
    console.info("startAbility callback");
});
```

### 调度Ability生命周期

AbilityDelegator提供对Ability生命周期进行显示调度，支持Foreground、Background，配合AbilityMonitor中对Ability生命周期监听方法，可以完整的测试Ability生命周期变化。具体详细内容请参考AbilityDelegator API接口说明[AbilityDelegator](../reference/apis/js-apis-application-abilityDelegator.md)。

### 执行shellCMD命令

AbilityDelegator提供执行shellCMD命令功能，开发者可以在测试代码中执行shell命令，该功能仅在测试环境中生效，非测试环境该接口调用无效果。
**示例：**

```javascript
  var abilityDelegator;
  var cmd = "cmd";
  abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
  abilityDelegator.executeShellCommand(cmd, (err,data) => {
    console.info("executeShellCommand callback");
  });
```