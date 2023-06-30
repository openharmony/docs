# arkXtest User Guide


## Overview

To accelerate test automation of OpenHarmony, arkXtest — an automated unit and UI test framework that supports both the JavaScript (JS) and TypeScript (TS) programming languages — is provided.

In this document you will learn about the key functions of arkXtest and how to use it to perform unit testing on application or system APIs and to write UI automated test scripts.


### Introduction

arkXtest is part of the OpenHarmony toolkit and provides basic capabilities of writing and running OpenHarmony automated test scripts. In terms of test script writing, arkXtest offers a wide range of APIs, including basic process APIs, assertion APIs, and APIs related to UI operations. In terms of test script running, arkXtest offers such features as identifying, scheduling, and executing test scripts, as well as summarizing test script execution results.


### Implementation

arkXtest is divided into two parts: unit test framework and UI test framework.

- Unit Test Framework

  As the backbone of arkXtest, the unit test framework offers such features as identifying, scheduling, and executing test scripts, as well as summarizing test script execution results. The figure below shows the main functions of the unit test framework.

  ![](figures/UnitTest.PNG)

  The following figure shows the basic unit test process. To start the unit test framework, run the **aa test** command.
  
  ![](figures/TestFlow.PNG)

- UI Test Framework

  The UI test framework provides [UiTest APIs](../reference/apis/js-apis-uitest.md) for you to call in different test scenarios. The UI test scripts are executed on top of the aformentioned unit test framework.

  The figure below shows the main functions of the UI test framework.

  ![](figures/Uitest.PNG)


### Constraints

- The features of the UI test framework are available only in OpenHarmony 3.1 and later versions.
- The feature availability of the unit test framework varies by version. For details about the mappings between the features and versions, see [arkXtest](https://gitee.com/openharmony/testfwk_arkxtest/blob/master/README_en.md).


## Preparing the Environment

### Environment Requirements

Software: DevEco Studio 3.0 or later

Hardware: PC connected to an OpenHarmony device, such as the RK3568 development board

### Setting Up the Environment

[Download DevEco Studio](https://developer.harmonyos.com/cn/develop/deveco-studio#download) and set it up as instructed on the official website.


## Creating a Test Script

1. Open DevEco Studio and create a project, in which the **ohos** directory is where the test script is located.
2. Open the .ets file of the module to be tested in the project directory. Move the cursor to any position in the code, and then right-click and choose **Show Context Actions** > **Create Ohos Test** or press **Alt+Enter** and choose **Create Ohos Test** to create a test class.

## Writing a Unit Test Script

```TS
import { describe, beforeAll, beforeEach, afterEach, afterAll, it, expect } from '@ohos/hypium';
import abilityDelegatorRegistry from '@ohos.app.ability.abilityDelegatorRegistry';

const delegator = abilityDelegatorRegistry.getAbilityDelegator()
export default function abilityTest() {
  describe('ActsAbilityTest', function () {
    it('testUiExample',0, async function (done) {
      console.info("uitest: TestUiExample begin");
      //start tested ability
      await delegator.executeShellCommand('aa start -b com.ohos.uitest -a EntryAbility').then(result =>{
        console.info('Uitest, start ability finished:' + result)
      }).catch(err => {
        console.info('Uitest, start ability failed: ' + err)
      })
      await sleep(1000);
      //check top display ability
      await delegator.getCurrentTopAbility().then((Ability)=>{
        console.info("get top ability");
        expect(Ability.context.abilityInfo.name).assertEqual('EntryAbility');
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

1. Import of the dependencies so that the dependent test APIs can be used.

2. Test code, mainly about the related logic, such as API invoking.

3. Invoking of the assertion APIs and setting of checkpoints. If there is no checkpoint, the test script is considered as incomplete.

## Writing a UI Test Script

You write a UI test script based on the unit test framework, adding the invoking of APIs provided by the UI test framework to implement the corresponding test logic.

In this example, the UI test script is written based on the preceding unit test script. First, import the dependency, as shown below:

```js
import {Driver,ON,Component,MatchPattern} from '@ohos.uitest'
```

Then, write specific test code. Specifically, implement the click action on the started application page and add checkpoint check cases.

```js
export default function abilityTest() {
  describe('ActsAbilityTest', function () {
    it('testUiExample',0, async function (done) {
      console.info("uitest: TestUiExample begin");
      //start tested ability
      await delegator.executeShellCommand('aa start -b com.ohos.uitest -a EntryAbility').then(result =>{
        console.info('Uitest, start ability finished:' + result)
      }).catch(err => {
        console.info('Uitest, start ability failed: ' + err)
      })
      await sleep(1000);
      //check top display ability
      await delegator.getCurrentTopAbility().then((Ability)=>{
        console.info("get top ability");
        expect(Ability.context.abilityInfo.name).assertEqual('EntryAbility');
      })
      //ui test code
      //init driver
      var driver = await Driver.create();
      await driver.delayMs(1000);
      //find button on text 'Next'
      var button = await driver.findComponent(ON.text('Next'));
      //click button
      await button.click();
      await driver.delayMs(1000);
      //check text
      await driver.assertComponentExist(ON.text('after click'));
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

### In DevEco Studio

You can run a test script in DevEco Studio in any of the following modes:

- Test package level: All test cases in the test package are executed.
- Test suite level: All test cases defined in the **describe** method are executed.
- Test method level: The specified **it** method, that is, a single test case, is executed.

![](figures/Execute.PNG)

**Viewing the Test Result**

After the test is complete, you can view the test result in DevEco Studio, as shown in the following figure.

![](figures/TestResult.PNG)

### In the CLI

To run a test script in the CLI, execute **aa** commands with different execution control keywords.

The table below lists the keywords in **aa** test commands.

| Keyword | Abbreviation| Description                          | Example                      |
| ------------- | ------------ | -------------------------------------- | ---------------------------------- |
| --bundleName  | -b           | Application bundle name.                        | - b com.test.example               |
| --packageName | -p           | Application module name, which is applicable to applications developed in the FA model.          | - p com.test.example.entry         |
| --moduleName  | -m           | Application module name, which is applicable to applications developed in the stage model.       | -m entry                           |
| NA            | -s           | \<key, value> pair.| - s unittest OpenHarmonyTestRunner |

The framework supports multiple test case execution modes, which are triggered by the key-value pair following the **-s** keyword. The table below lists the available keys and values.

| Key    | Description                                                | Value                                                | Example                             |
| ------------ | -----------------------------------------------------------------------------    | ------------------------------------------------------------ | ----------------------------------------- |
| unittest     | **OpenHarmonyTestRunner** object used for test case execution. | **OpenHarmonyTestRunner** or custom runner name.                 | - s unittest OpenHarmonyTestRunner        |
| class        | Test suite or test case to be executed.                                  | {describeName}#{itName}, {describeName}                     | -s class attributeTest#testAttributeIt    |
| notClass     | Test suite or test case that does not need to be executed.                              | {describeName}#{itName}, {describeName}                     | -s notClass attributeTest#testAttributeIt |
| itName       | Test case to be executed.                                        | {itName}                                                     | -s itName testAttributeIt                 |
| timeout      | Timeout interval for executing a test case.                                       | Positive integer (unit: ms). If no value is set, the default value 5000 is used.                       | -s timeout 15000                          |
| breakOnError | Whether to enable break-on-error mode. When this mode is enabled, the test execution process exits if a test assertion failure or error occurs.| **true**/**false** (default value)                                          | -s breakOnError true                      |
| random | Whether to execute test cases in random sequence.| **true**/**false** (default value)                                          | -s random true                      |
| testType     | Type of the test case to be executed.                                     | function, performance, power, reliability, security, global, compatibility, user, standard, safety, resilience| -s testType function                      |
| level        | Level of the test case to be executed.                                     | 0, 1, 2, 3, 4                                                   | -s level 0                                |
| size         | Size of the test case to be executed.                                   | small, medium, large                                        | -s size small        
| stress       | Number of times that the test case is executed.                                   |  Positive integer                                        | -s stress 1000                            |

**Running Commands**

> Before running commands in the CLI, make sure hdc-related environment variables have been configured.

- Open the CLI.
- Run the **aa test** commands.

Example 1: Execute all test cases.

```shell  
 hdc shell aa test -b xxx -p xxx -s unittest OpenHarmonyTestRunner
```

Example 2: Execute cases in the specified test suites, separated by commas (,).

```shell  
  hdc shell aa test -b xxx -p xxx -s unittest OpenHarmonyTestRunner -s class s1,s2
```

Example 3: Execute specified cases in the specified test suites, separated by commas (,).

```shell  
  hdc shell aa test -b xxx -p xxx -s unittest OpenHarmonyTestRunner -s class testStop#stop_1,testStop1#stop_0
```

Example 4: Execute all test cases except the specified ones, separated by commas (,).

```shell  
  hdc shell aa test -b xxx -p xxx -s unittest OpenHarmonyTestRunner -s notClass testStop
```

Example 5: Execute specified test cases, separated by commas (,).

```shell  
  hdc shell aa test -b xxx -p xxx -s unittest OpenHarmonyTestRunner -s itName stop_0
```

Example 6: Set the timeout interval for executing a test case.

```shell  
  hdc shell aa test -b xxx -p xxx -s unittest OpenHarmonyTestRunner  -s timeout 15000
```

Example 7: Enable break-on-error mode.

```shell  
  hdc shell aa test -b xxx -p xxx -s unittest OpenHarmonyTestRunner   -s breakOnError true
```

Example 8: Execute test cases of the specified type.

```shell  
  hdc shell aa test -b xxx -p xxx -s unittest OpenHarmonyTestRunner   -s testType function
```

Example 9: Execute test cases at the specified level.

```shell  
  hdc shell aa test -b xxx -p xxx -s unittest OpenHarmonyTestRunner   -s level 0
```

Example 10: Execute test cases with the specified size.

```shell  
  hdc shell aa test -b xxx -p xxx -s unittest OpenHarmonyTestRunner   -s size small
```

Example 11: Execute test cases for a specified number of times.

```shell  
  hdc shell aa test -b xxx -p xxx -s unittest OpenHarmonyTestRunner   -s stress 1000
```

**Viewing the Test Result**

- During test execution in the CLI, the log information similar to the following is displayed:

```
OHOS_REPORT_STATUS: class=testStop
OHOS_REPORT_STATUS: current=1
OHOS_REPORT_STATUS: id=JS
OHOS_REPORT_STATUS: numtests=447
OHOS_REPORT_STATUS: stream=
OHOS_REPORT_STATUS: test=stop_0
OHOS_REPORT_STATUS_CODE: 1

OHOS_REPORT_STATUS: class=testStop
OHOS_REPORT_STATUS: current=1
OHOS_REPORT_STATUS: id=JS
OHOS_REPORT_STATUS: numtests=447
OHOS_REPORT_STATUS: stream=
OHOS_REPORT_STATUS: test=stop_0
OHOS_REPORT_STATUS_CODE: 0
OHOS_REPORT_STATUS: consuming=4
```

| Log Field              | Description      |
| -------           | -------------------------|
| OHOS_REPORT_SUM    | Total number of test cases in the current test suite.|
| OHOS_REPORT_STATUS: class | Name of the test suite that is being executed.|
| OHOS_REPORT_STATUS: id | Case execution language. The default value is JS. |
| OHOS_REPORT_STATUS: numtests | Total number of test cases in the test package.|
| OHOS_REPORT_STATUS: stream | Error information of the current test case.|
| OHOS_REPORT_STATUS: test| Name of the current test case.|
| OHOS_REPORT_STATUS_CODE | Execution result of the current test case. The options are as follows:<br>**0**: pass<br>**1**: error<br>**2**: fail|
| OHOS_REPORT_STATUS: consuming | Time spent in executing the current test case.|

- After the commands are executed, the log information similar to the following is displayed:

```
OHOS_REPORT_RESULT: stream=Tests run: 447, Failure: 0, Error: 1, Pass: 201, Ignore: 245
OHOS_REPORT_CODE: 0

OHOS_REPORT_RESULT: breakOnError model, Stopping whole test suite if one specific test case failed or error
OHOS_REPORT_STATUS: taskconsuming=16029

```
| Log Field              | Description          |
| ------------------| -------------------------|
| run    | Total number of test cases in the current test package.|
| Failure | Number of failed test cases.|
| Error | Number of test cases whose execution encounters errors. |
| Pass | Number of passed test cases.|
| Ignore | Number of test cases not yet executed.|
| taskconsuming| Total time spent in executing the current test case.|

> When an error occurs in break-on-error mode, check the **Ignore** and interrupt information.

## FAQs

### FAQs About Unit Test Cases

#### The logs in the test case are printed after the test case result

**Problem**

The logs added to the test case are displayed after the test case execution, rather than during the test case execution.

**Possible Causes**

More than one asynchronous API is called in the test case.<br>In principle, logs in the test case are printed before the test case execution is complete.

**Solution**

If more than one asynchronous API is called, you are advised to encapsulate the API invoking into the promise mode.

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

3. Test assertion fails, and a failure exception is thrown. As a result, the test case execution does not end until it times out.

**Solution**

1. Check the code logic of the test case to ensure that the **done** function is executed even if the assertion fails.

2. Modify the case execution timeout settings under **Run/Debug Configurations** in DevEco Studio.

3. Check the code logic and assertion result of the test case and make sure that the assertion is passed.
### FAQs About UI Test Cases

#### The failure log contains "Get windows failed/GetRootByWindow failed"

**Problem**

The UI test case fails to be executed. The HiLog file contains the error message "Get windows failed/GetRootByWindow failed."

**Possible Causes**

The ArkUI feature is disabled. As a result, the component tree information is not generated on the test page.

**Solution**

Run the following command, restart the device, and execute the test case again:

```shell
hdc shell param set persist.ace.testmode.enabled 1
```

#### The failure log contains "uitest-api does not allow calling concurrently"

**Problem**

The UI test case fails to be executed. The HiLog file contains the error message "uitest-api does not allow calling concurrently".

**Possible Causes**

1. In the test case, the **await** operator is not added to the asynchronous API provided by the UI test framework.

2. The UI test case is executed in multiple processes. As a result, multiple UI test processes are started. The framework does not support multi-process invoking.

**Solution**

1. Check the case implementation and add the **await** operator to the asynchronous API.

2. Do not execute UI test cases in multiple processes.

#### The failure log contains "does not exist on current UI! Check if the UI has changed after you got the widget object"

**Problem**

The UI test case fails to be executed. The HiLog file contains the error message "does not exist on current UI! Check if the UI has changed after you got the widget object."

**Possible Causes**

After the target component is found in the code of the test case, the device UI changes, resulting in loss of the found component and inability to perform emulation.

**Solution**

Run the UI test case again.
