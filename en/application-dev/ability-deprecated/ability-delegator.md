# Test Framework Usage

## Overview
The delegator test framework provides a self-test environment for OpenHarmony applications. Using this framework, you can start an ability, schedule its lifecycle, listen for its state changes, run a shell command, and print the test result.

## Constraints

The APIs provided by the test framework can be used only in the test HAP. They take effect only after the test framework is started.


## Starting the Test Framework

The test framework can be started in either of the following ways:

- Method 1: Run the `aa test` command.
- Method 2: Use DevEco Studio.

### Running aa test

To start the test framework, specify the **TestRunner** and the package name or module name of the HAP where the **TestRunner** is located.

An example command in the FA model is as follows:

```javascript
aa test -b BundleName -p com.example.myapplicationfaets -s unittest OpenHarmonyTestRunner -s class ActsAbilityTest -w 20
```

An example command in the stage model is as follows:
```javascript
aa test -b BundleName -m com.example.myapplicationfaets -s unittest OpenHarmonyTestRunner -s class ActsAbilityTest -w 20
```
| Parameter           | Mandatory| Description                                                    |
| --------------- | -------- | ------------------------------------------------------------ |
| -b              | Yes      | Bundle name of the HAP where the **TestRunner** is located.             |
| -p              | Yes      | Package name of the HAP where the **TestRunner** is located. This parameter is used by the FA model.             |
| -m              | Yes      | Module name of the HAP where the **TestRunner** is located. This parameter is used by the stage model.           |
| -s unittest     | Yes      | Name of the **TestRunner** to be used. The TestRunner name must be the same as the file name.  |
| -w              | No      | Timeout interval of a test case, in seconds. If this parameter is not specified or is set to a value less than or equal to **0**, the test framework exits only after **finishTest** is invoked.|
| -s \<key>\<value> | No      | **-s** can be followed by any key-value pair obtained through **AbilityDelegatorArgs.parameters**. For example, in **-s classname myTest**, **-s classname** is the key and **myTest** is the value.|
| -D              | No      | Debug mode for starting the tested application.|
| -h              | No      | Help information.|

### Using DevEco Studio

For details about how to use DevEco Studio to start the test framework, see [OpenHarmony Test Framework](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-openharmony-test-framework-0000001263160453#section1034420367508).

## Introduction to TestRunner

**TestRunner** is the entry class of the test framework test process. When the test process is started, the system calls related APIs in **TestRunner**. You need to inherit this class and override the **onPrepare** and **onRun** APIs. When creating an application template, DevEco Studio initializes the default **TestRunner** and starts the default **TestAbility** in the **onRun** API. You can modify the test code of **TestAbility** or override **onPrepare** and **onRun** in **TestRunner** to implement your own test code. For details, see [TestRunner](../reference/apis/js-apis-application-testRunner.md).

## Introduction to AbilityDelegatorRegistry

**AbilityDelegatorRegistry** is the **AbilityDelegator** repository class provided by the test framework. You can use **AbilityDelegatorRegistry** to obtain an **AbilityDelegator** instance and the input and generated parameters **AbilityDelegatorArgs** during the test. You can use **AbilityDelegator** to invoke the function set provided by the test framework for testing and verification. For details, see [AbilityDelegatorRegistry](../reference/apis/js-apis-application-abilityDelegatorRegistry.md).

## Introduction to AbilityDelegatorArgs

**AbilityDelegatorArgs** is a test parameter class provided by the test framework. You can use **AbilityDelegatorArgs** to obtain the parameters passed and generated during the test. For details, see [AbilityDelegatorArgs](../reference/apis/js-apis-inner-application-abilityDelegatorArgs.md).

## Introduction to AbilityMonitor

**AbilityMonitor** is provided by the test framework for binding to and listening for abilities. You can use **AbilityMonitor** to bind to an **Ability** instance and add **AbilityMonitor** to the listening list. When **AbilityMonitor** is bound to an ability, the creation and lifecycle changes of the ability will trigger the related callback in **AbilityMonitor**. You can test and verify the ability in these callbacks. For details, see [AbilityMonitor](../reference/apis/js-apis-inner-application-abilityMonitor.md).

**Example**

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

### Scheduling the Ability Lifecycle

**AbilityDelegator** provides APIs to display and schedule the ability lifecycle and supports the foreground and background. It works with **AbilityMonitor** to listen for the ability lifecycle. For details, see [AbilityDelegator](../reference/apis/js-apis-inner-application-abilityDelegator.md).

### Running a Shell Command

**AbilityDelegator** provides APIs to run shell commands in the test environment.

**Example**

```javascript
var abilityDelegator;
var cmd = "cmd";
abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.executeShellCommand(cmd, (err, data) => {
    console.info("executeShellCommand callback");
});
```

### Printing Log Information

**AbilityDelegator** provides APIs for printing log information. You can call any API in the test code to print process logs to the unit test console.

**Example**

```javascript
var abilityDelegator;
var msg = "msg";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.print(msg, (err) => {
    console.info("print callback");
});
```

### Finishing the Test and Printing Log Information

**AbilityDelegator** provides the APIs for actively finishing the test. You can call any API in test code to finish the test and print logs to the unit test console.

**Example**

```javascript
var abilityDelegator;
var msg = "msg";

abilityDelegator = AbilityDelegatorRegistry.getAbilityDelegator();
abilityDelegator.finishTest(msg, 0, (err) => {
    console.info("finishTest callback");
});
```
