# arkXtest User Guide


## Overview

To accelerate test automation of OpenHarmony, arkXtest — an automated test framework that supports both the JavaScript (JS) and TypeScript (TS) programming languages — is provided.

In this document you will learn about the key functions of arkXtest and how to use it to perform unit testing on application or system APIs and to write UI automated test scripts.


### Introduction

arkXtest is part of the OpenHarmony toolkit and provides basic capabilities of writing and running OpenHarmony automated test scripts. In terms of test script writing, arkXtest offers a wide range of APIs, including basic process APIs, assertion APIs, and APIs related to UI operations. In terms of test script running, arkXtest offers such features as identifying, scheduling, and executing test scripts, as well as summarizing test script execution results.


### Principles

arkXtest is divided into two parts: unit test framework and UI test framework.

- Unit Test Framework

  As the backbone of arkXtest, the unit test framework offers such features as identifying, scheduling, and executing test scripts, as well as summarizing test script execution results. The figure below shows the main functions of the unit test framework.

  ![](figures/UnitTest.PNG)

  The following figure shows the basic unit test process. To start the unit test framework, run the **aa test** command.
  
  ![](figures/TestFlow.PNG)

- UI Testing Framework

  The UI test framework provides [UiTest APIs](../reference/apis/js-apis-uitest.md) for you to call in different test scenarios. The test scripts are executed on top of the unit test framework mentioned above.

  The figure below shows the main functions of the UI test framework.

  ![](figures/Uitest.PNG)


### Limitations and Constraints

- The features of the UI test framework are available only in OpenHarmony 3.1 and later versions.
- The feature availability of the unit test framework varies by version. For details about the mappings between the features and versions, see [arkXtest](https://gitee.com/openharmony/testfwk_arkxtest/blob/master/README_en.md).


## Environment preparations

### Environment Requirements

Software for writing test scripts: DevEco Studio 3.0 or later

Hardware for running test scripts: PC connected to a OpenHarmony device, such as the RK3568 development board

### Setting Up the Environment

[Download DevEco Studio](https://developer.harmonyos.com/cn/develop/deveco-studio#download) and set it up as instructed on the official website.


## Creating a Test Script

1. Open DevEco Studio and create a project, where the **ohos** directory is where the test script is located.
2. Open the .ets file of the module to be tested in the project directory. Move the cursor to any position in the code, and then right-click and choose **Show Context Actions** > **Create Ohos Test** or press **Alt+Enter** and choose **Create Ohos Test** to create a test class.

## Writing a Unit Test Script

```TS
import { describe, beforeAll, beforeEach, afterEach, afterAll, it, expect } from '@ohos/hypium'
import abilityDelegatorRegistry from '@ohos.application.abilityDelegatorRegistry'

const delegator = abilityDelegatorRegistry.getAbilityDelegator()
export default function abilityTest() {
  describe('ActsAbilityTest', function () {
    it('testUiExample',0, async function (done) {
      console.info("uitest: TestUiExample begin");
      //start tested ability
      await delegator.executeShellCommand('aa start -b com.ohos.uitest -a MainAbility').then(result =>{
        console.info('Uitest, start ability finished:' + result)
      }).catch(err => {
        console.info('Uitest, start ability failed: ' + err)
      })
      await sleep(1000);
      //check top display ability
      await delegator.getCurrentTopAbility().then((Ability)=>{
        console.info("get top ability");
        expect(Ability.context.abilityInfo.name).assertEqual('MainAbility');
      })
      done();
    })

    function sleep(time) {
      return new Promise((resolve) => setTimeout(resolve, time));
    }
  })
}
```

The unit test script must contain the following basic elements:

1. Import of the dependency package so that the dependent test APIs can be used.

2. Test code, mainly about the related logic, such as API invoking.

3. Invoking of the assertion APIs and setting of checkpoints. If there is no checkpoint, the test script is considered as incomplete.

## Writing a UI Test Script

You write a UI test script based on the unit test framework, adding the invoking of APIs provided by the UI test framework to implement the corresponding test logic.

In this example, the UI test script is written based on the preceding unit test script. First, add the dependency package, as shown below:

```js
import {UiDriver,BY,UiComponent,MatchPattern} from '@ohos.uitest'
```

Then, write specific test code. Specifically, implement the click action on the started application page and add checkpoint check cases.

```js
export default function abilityTest() {
  describe('ActsAbilityTest', function () {
    it('testUiExample',0, async function (done) {
      console.info("uitest: TestUiExample begin");
      //start tested ability
      await delegator.executeShellCommand('aa start -b com.ohos.uitest -a MainAbility').then(result =>{
        console.info('Uitest, start ability finished:' + result)
      }).catch(err => {
        console.info('Uitest, start ability failed: ' + err)
      })
      await sleep(1000);
      //check top display ability
      await delegator.getCurrentTopAbility().then((Ability)=>{
        console.info("get top ability");
        expect(Ability.context.abilityInfo.name).assertEqual('MainAbility');
      })
      //ui test code
      //init uidriver
      var driver = await UiDriver.create();
      await driver.delayMs(1000);
      //find button by text 'Next'
      var button = await driver.findComponent(BY.text('Next'));
      //click button
      await button.click();
      await driver.delayMs(1000);
      //check text
      await driver.assertComponentExist(BY.text('after click'));
      await driver.pressBack();
      done();
    })

    function sleep(time) {
      return new Promise((resolve) => setTimeout(resolve, time));
    }
  })
}
```

## Running the Test Script

You can run a test script in DevEco Studio in any of the following modes:

- Test package level: All test cases in the test package are executed.
- Test suite level: All test cases defined in the **describe** method are executed.
- Test method level: The specified **it** method, that is, a single test case, is executed.

![](figures/Execute.PNG)

## Viewing the Test Result

After the test is complete, you can view the test result in DevEco Studio, as shown in the following figure.

![](figures/TestResult.PNG)

## FAQs

### FAQs About Unit Test Cases

#### The logs in the test case are printed after the test case result

**Problem**

The logs added to the test case are displayed after the test case execution, rather than during the test case execution.

**Possible Causes**

More than one asynchronous interface is called in the test case.<br>In principle, logs in the test case are printed before the test case execution is complete.

 **Solution**

If more than one asynchronous interface is called, you are advised to encapsulate the interface invoking into the promise mode

#### Error "fail to start ability" is reported during test case execution

**Problem**

When a test case is executed, the console returns the error message "fail to start ability".

**Possible Causes**

An error occurs during the packaging of the test package, and the test framework dependency file is not included in the test package.

**Solution**

Check whether the test package contains the **OpenHarmonyTestRunner.abc** file. If the file does not exist, rebuild and pack the file and perform the test again.

#### Test case execution timeout

**Problem**

After the test case execution is complete, the console displays the error message "execute time XXms", indicating that the case execution times out.

**Possible Causes**

1. The test case is executed through an asynchronous interface, but the **done** function is not executed during the execution. As a result, the test case execution does not end until it times out.
2. The time taken for API invocation is longer than the timeout interval set for test case execution. 

**Solution**

1. Check the code logic of the test case to ensure that the **done** function is executed even if the assertion fails.

2. Modify the case execution timeout settings under **Run/Debug Configurations** in DevEco Studio. 

### FAQs About UI Test Cases

#### The failure log contains "Get windows failed/GetRootByWindow failed"

**Problem**

The UI test case fails to be executed. The HiLog file contains the error message "Get windows failed/GetRootByWindow failed".

**Possible Causes**

The ArkUI feature is disabled. As a result, the control tree information on the test page is not generated.

**Solution**

Run the following command, restart the device, and execute the test case again:

```shell
hdc shell param set persist.ace.testmode.enabled 1
```

#### The failure log contains "uitest-api dose not allow calling concurrently"

**Problem**

The UI test case fails to be executed. The HiLog file contains the error message "uitest-api dose not allow calling concurrently".

**Possible Causes**

1. In the test case, the **await** operator is not added to the asynchronous interface provided by the UI test framework.

2. The UI test case is executed in multiple processes. As a result, multiple UI test processes are started. The framework does not support multi-process invoking.

**Solution**

1. Check the case implementation and add the **await** operator to the asynchronous interface invoking.

2. Do not execute UI test cases in multiple processes.

#### The failure log contains "dose not exist on current UI! Check if the UI has changed after you got the widget object"

**Problem**

The UI test case fails to be executed. The HiLog file contains the error message "dose not exist on current UI! Check if the UI has changed after you got the widget object".

**Possible Causes**

After the target component is found in the code of the test case, the device UI changes. As a result, the found component is lost and the emulation operation cannot be performed.

**Solution**

Run the UI test case again.
