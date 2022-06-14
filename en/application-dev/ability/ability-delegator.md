# Test Framework Usage

## Overview
The delegator test framework provides a self-test framework (environment) for OpenHarmony applications. Using this framework, you can start an ability, schedule its lifecycle, listen for its state changes, run a shell command, and print the test result.

## Constraints

The APIs provided by the test framework can be used only in the test HAP. They take effect only after the test framework is started by running the **aa test** command or using the Integrated Development Environment (IDE).


## Starting the Test Framework

The test framework can be started using either of the following methods:

- Method 1: Run the **aa test** command.
- Method 2: Use the IDE.

### Running aa test

You can run the **aa test** command to start the test framework. You can specify the **TestRunner** to be used and the package name or module name of the HAP where the **TestRunner** is located.

An example command in the FA model is as follows:

```javascript
aa test -p com.example.myapplicationfaets -s unittest OpenHarmonyTestRunner -s class ActsAbilityTest  -w 20
```

An example command in the stage model is as follows:
```javascript
aa test -m com.example.myapplicationfaets -s unittest OpenHarmonyTestRunner -s class ActsAbilityTest  -w 20
```
| Parameter           | Mandatory| Description                                                    |
| --------------- | -------- | ------------------------------------------------------------ |
| -p              | Yes      | Package name of the HAP where the **TestRunner** is located. This parameter is used by the FA model.             |
| -m              | Yes      | Module name of the HAP where the **TestRunner** is located. This parameter is used by the stage model.           |
| -s unittest     | Yes      | Name of the **TestRunner** to be used. The TestRunner name must be the same as the file name.  |
| -w              | No      | Timeout interval of a test case, in seconds. If this parameter is not specified, the test framework exits only after **finishTest** is invoked.|
| -s \<key>\<value> | No      | It can be any parameter in the key-value format. The entered parameters can be obtained in key-value mode through **AbilityDelegatorArgs.parameters**. For example, in **-s classname myTest**, **classname** is the key and **myTest** is the value.|

### Using the IDE

For details about how to start the IDE, see [IDE Guide](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-openharmony-test-framework-0000001263160453#section1034420367508).

## Introduction to TestRunner

**TestRunner** is the entry class of the test framework test process. When the test process is started, the system calls related APIs in **TestRunner**. You need to inherit this class and override the **onPrepare** and **onRun** APIs. When creating an application template, the IDE initializes the default **TestRunner** and starts the default **TestAbility** in the **onRun** API. You can modify the test code of **TestAbility** or override **onPrepare** and **onRun** in **TestRunner** to implement your own test code. For details, see [TestRunner](../reference/apis/js-apis-testRunner.md).

## Introduction to AbilityMonitor

**AbilityMonitor** is provided by the test framework for binding to and listening for abilities. You can use **AbilityMonitor** to bind to an **Ability** instance and add **AbilityMonitor** to the listening list. After an ability is bound, the creation and lifecycle changes of the ability will trigger the related callback in **AbilityMonitor**. You can test and verify the ability in these callbacks. For details, see [AbilityMonitor](../reference/apis/js-apis-application-abilityMonitor.md).

**Example**

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

## Introduction to AbilityDelegator

**AbilityDelegator** is a main function class of the test framework. It provides the functions of starting an ability, obtaining an **Ability** instance, scheduling the ability lifecycle, listening for the ability state, and printing test results.

**Modules to Import**

```javascript
import AbilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'
```

```javascript
var abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator()
```

### Starting an Ability and Listening for the Ability State

Use **AbilityDelegator** and **AbilityMonitor** to start an ability, obtain an **Ability** instance, and listen for the ability state.

**Example**

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

### Scheduling the Ability Lifecycle

**AbilityDelegator** provides APIs to display and schedule the ability lifecycle and supports the foreground and background. It works with **AbilityMonitor** to listen for the ability lifecycle. For details, see [AbilityDelegator](../reference/apis/js-apis-application-abilityDelegator.md).

### Running a Shell Command

**AbilityDelegator** provides APIs to run shell commands. You can run a shell command in the test code. This feature takes effect only in the test environment.
**Example**

```javascript
  var abilityDelegator;
  var cmd = "cmd";
  abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
  abilityDelegator.executeShellCommand(cmd, (err,data) => {
    console.info("executeShellCommand callback");
  });
```
