# 单元测试框架使用指导 

<!--Kit: Test Kit-->
<!--Subsystem: Test-->
<!--Owner: @inter515-->
<!--Designer: @inter515-->
<!--Tester: @laonie666-->
<!--Adviser: @Brilliantry_Rui-->

## 概述

单元测试框架（JsUnit），是自动化测试框架基础底座，提供测试脚本识别、调度、执行和结果汇总的能力。开发者可在测试脚本中调用UI测试框架和白盒性能测试框架接口编写测试用例。<br>
本指南介绍单元测试框架的主要功能、实现原理和开发步骤。


## 框架能力全景

单元测试框架是测试框架基础底座，提供测试脚本识别、调度、执行及结果汇总的能力。其具体功能特性如下表所示：
|   特性     | 功能说明                                                     |
|  -------- | ------------------------------------------------------------ |
|  [基础流程](#基础流程能力) | 支持编写及异步执行测试用例。                                 |
|  [断言库](#断言能力)   | 判断用例实际结果值与预期值是否相符。                         |
|  [Mock能力](#mock能力) | 支持函数级Mock能力，对定义的函数进行Mock并修改函数的行为，使其返回指定的值或者执行指定操作。 |
|  [数据驱动](#数据驱动) | 提供数据驱动能力，支持复用同一个测试脚本，使用不同输入数据驱动测试脚本执行。 |
| [专项能力](#命令行执行测试脚本) | 支持测试套与用例筛选、随机执行、压力测试、超时设置、遇错即停模式和跳过执行模式。 |

  **图1.单元测试框架主要功能**

  ![](figures/UnitTest.PNG)


## 发布方式
单元测试框架以ohpm包独立发布，版本信息详见[服务组件官网](https://ohpm.openharmony.cn/#/cn/detail/@ohos%2Fhypium)。开发者下载DevEco Studio后，在应用工程中的[oh-package.json5](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-oh-package-json5)文件中devDependencies节点中配置版本号即可使用对应版本框架功能。

**配置示例**
```json
"devDependencies": {
    "@ohos/hypium": "1.0.24"
  }
```

## 基于ArkTS编写和执行测试脚本

### 搭建环境

测试脚本基于DevEco Studio编写，请下载[DevEco Studio](https://developer.huawei.com/consumer/cn/download/)并完成<!--RP1-->[hdc配置](../dfx/hdc.md)<!--RP1End-->。

### 新建测试脚本

参考[DevEco Studio指导](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-instrument-test#section36049271219)创建ArkTS测试用例。

### 编写单元测试脚本

一个完整的测试脚本需要包含以下基本元素：

1. 依赖导包，以便使用单元测试框架提供的接口，以及其他测试脚本中需要依赖使用的接口，导入模块详见下文示例。
2. 测试代码编写，编写测试用例的相关测试逻辑。
3. 断言接口调用，设置测试代码中的检查点，用于检查用例是否符合预期。

下面提供一个简单示例，测试场景：启动被测试页面，检查设备当前显示的页面是否为预期启动的页面。

```ts
import { describe, it, expect, Level } from '@ohos/hypium';
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { UIAbility, Want } from '@kit.AbilityKit';

const delegator = abilityDelegatorRegistry.getAbilityDelegator();
function sleep(time: number) {
  return new Promise<void>((resolve: Function) => setTimeout(resolve, time));
}
export default function abilityTest() {
  describe('ActsAbilityTest', () =>{
    it('testExample',Level.LEVEL1, async (done: Function) => {
      console.info("unitTest: TestExample begin");
      await sleep(500);
      const bundleName = abilityDelegatorRegistry.getArguments().bundleName;
      //启动被测试Ability
      const want: Want = {
        bundleName: bundleName,
        abilityName: 'EntryAbility'
      }
      await delegator.startAbility(want);
      await sleep(500);
      //获取设备上前台显示的Ability并断言检查
      const ability: UIAbility = await delegator.getCurrentTopAbility();
      console.info("get top ability");
      expect(ability.context.abilityInfo.name).assertEqual('EntryAbility');
      done();
    })
  })
}
```
### DevEco Stuido执行测试脚本

连接目标测试设备（如手机），在DevEco Studio页面点击对应按钮执行测试脚本，当前支持以下四种方式：

1. 测试包级别执行，即执行测试包内的全部用例。
2. 测试类级别执行，即执行*.ets文件里的所有测试用例。
3. 测试套级别执行，即执行describe接口中定义的全部测试用例。
4. 测试用例级别执行，即执行指定it接口也就是单条测试用例。

下面给出测试类级别即测试文件执行示例，其他请查考[运行模式](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-instrument-test#section1574003717165)。

![](figures/Execute.PNG)

* 查看测试结果

测试执行后可直接在DevEco Studio中查看测试结果。

![](figures/TestResult.PNG)

* 查看测试用例覆盖率

执行测试用例后可以查看测试用例覆盖率，具体操作请参考[覆盖率统计模式](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-instrument-test#section1989615417457)章节内的内容。

### 命令行执行测试脚本

脚本执行需连接硬件设备，开发者安装测试包到连接设备上，在命令行窗口中通过执行aa test命令并设置执行参数，触发执行测试用例。

* aa test工具命令列表

以下是单元测试过程中的常用命令，其他aa test命令及含义说明参考<!--RP2-->[命令指南说明](../tools/aa-tool.md)<!--RP2End-->。

| 参数  | 参数说明                          | 示例                       |
| ------------- |  -------------------------------------- | ---------------------------------- |
| --bundleName/-b  |  应用Bundle名称。                       | - b com.test.example               |
| --packageName/-p | 应用模块名，适用于FA模型应用。           | - p com.test.example.entry         |
| --moduleName/-m  |  应用模块名，适用于STAGE模型应用。        | -m entry                           |
| -s            |  特定参数，以<key, value>键值对方式传入。框架支持通过-s参数键值配置多种用例执行方式，-s的参数及对应含义参见下表。 | - s unittest /ets/testrunner/OpenHarmonyTestRunner |


| 参数     | 参数含义及取值                                             | 示例                              |
| ------------ | -----------------------------------------------------------------------------     | ----------------------------------------- |
| unittest     | 用例执行所使用OpenHarmonyTestRunner对象，取值可为OpenHarmonyTestRunner或用户自定义runner名称。                  | -s unittest OpenHarmonyTestRunner        |
| class        | 筛选执行方式，即指定要执行的测试套或测试用例。取值为describeName，describeName#itName。                   | -s class attributeTest#testAttributeIt    |
| notClass     | 排除执行方式，即指定不需要执行的测试套或测试用例。取值为describeName，describeName#itName。                     | -s notClass attributeTest#testAttributeIt |
| itName       |筛选执行方式， 指定要执行的测试用例。取值为itName。                              | -s itName testAttributeIt                 |
| timeout      | 设置测试用例执行的超时时间。取值为正整数（单位ms），默认值：5000。                      | -s timeout 15000                          |
| breakOnError | 遇错即停方式，设置是否在用例失败时立即停止测试。取值为true（停止）/false（继续），默认为false。<br> **说明**：从@ohos/hypium 1.0.6版本开始支持。 | -s breakOnError true                      |
| random | 随机执行方式，设置为true时随机顺序执行测试用例。取值为true（设置）/false（不设置），默认为false。<br> **说明**：从@ohos/hypium 1.0.3版本开始支持。  | -s random true                      |
| testType     | 筛选执行方式，指定筛选执行的用例类型。取值为function，performance，power，reliability，security，global，compatibility，user，standard，safety，resilience。 | -s testType function                      |
| level        | 筛选执行方式，指定筛选执行的用例级别。取值为0，1，2，3，4。                                              | -s level 0                                |
| size         | 筛选执行方式，指定筛选执行的用例规模。取值为small，medium，large。                                        | -s size small        |
| stress       | 压力执行方式，指定执行用例的执行次数，设置后框架按照设置次数重复执行。取值为正整数。<br> **说明**：从@ohos/hypium 1.0.5版本开始支持。                  | -s stress 1000                            |
| skipMessage       | 控制是否显示跳过测试套和跳过用例的信息。取值为true（跳过）/false（不跳过），默认为false。<br>**说明**：从@ohos/hypium 1.0.17版本开始支持。 | -s skipMessage true                            |
| runSkipped       | 跳过执行方式，指定要执行的跳过测试套&跳过用例。取值为all，skipped，describeName#itName。<br>**说明**：从@ohos/hypium 1.0.17版本开始支持。 | -s runSkipped all                            |

* 执行测试脚本

> **说明：**<br>
>
> 下文参数配置和命令示例均基于Stage模型。
>
> 执行命令参数需基于@ohos/hypium框架发布版本，且测试应用包需集成该版本，否则命令参数无法响应，具体配置方式参考[发布方式](#发布方式)。  


**示例代码1**：执行所有测试用例

```shell  
 hdc shell aa test -b xxx -m xxx -s unittest OpenHarmonyTestRunner
```

**示例代码2**：执行指定的describe测试套用例，指定多个需用逗号隔开

```shell  
  hdc shell aa test -b xxx -m xxx -s unittest OpenHarmonyTestRunner -s class s1,s2
```

**示例代码3**：执行指定测试套中指定的用例，指定多个需用逗号隔开

```shell  
  hdc shell aa test -b xxx -m xxx -s unittest OpenHarmonyTestRunner -s class testStop#stop_1,testStop1#stop_0
```

**示例代码4**：执行除指定配置外的所有用例，设置不执行多个测试套需用逗号隔开

```shell  
  hdc shell aa test -b xxx -m xxx -s unittest OpenHarmonyTestRunner -s notClass testStop
```

**示例代码5**：执行指定it名称的所有用例，指定多个需用逗号隔开

```shell  
  hdc shell aa test -b xxx -m xxx -s unittest OpenHarmonyTestRunner -s itName stop_0
```

**示例代码6**：用例执行超时时长配置

```shell  
  hdc shell aa test -b xxx -m xxx -s unittest OpenHarmonyTestRunner -s timeout 15000
```

**示例代码7**：用例以遇错即停模式执行用例

```shell  
  hdc shell aa test -b xxx -m xxx -s unittest OpenHarmonyTestRunner -s breakOnError true
```

**示例代码8**：执行测试类型匹配的测试用例

```shell  
  hdc shell aa test -b xxx -m xxx -s unittest OpenHarmonyTestRunner -s testType function
```

**示例代码9**：执行测试级别匹配的测试用例

```shell  
  hdc shell aa test -b xxx -m xxx -s unittest OpenHarmonyTestRunner -s level 0
```

**示例代码10**：执行测试规模匹配的测试用例

```shell  
  hdc shell aa test -b xxx -m xxx -s unittest OpenHarmonyTestRunner -s size small
```

**示例代码11**：执行测试用例指定次数

```shell  
  hdc shell aa test -b xxx -m xxx -s unittest OpenHarmonyTestRunner -s stress 1000
```

* 查看测试结果

1. 在命令行模式执行过程中，框架会打印如下日志信息。

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

| 日志输出字段               | 日志输出字段含义       |
| -------           | -------------------------|
| OHOS_REPORT_SUM    | 当前执行的测试套中用例总数。 |
| OHOS_REPORT_STATUS: class | 当前执行用例所属测试套名称。|
| OHOS_REPORT_STATUS: id | 当前用例执行语言，默认JS。  |
| OHOS_REPORT_STATUS: numtests | 当前测试包中测试用例总数。|
| OHOS_REPORT_STATUS: stream | 当前用例发生错误时，记录错误信息。 |
| OHOS_REPORT_STATUS: test| 当前用例执行的it name。 |
| OHOS_REPORT_STATUS_CODE | 当前用例执行结果状态。0表示通过，1表示错误，2表示失败。|
| OHOS_REPORT_STATUS: consuming | 当前用例执行消耗的时长（ms）。 |

2. 命令行执行完成后，框架会打印如下相关日志信息。

 ```
  OHOS_REPORT_RESULT: stream=Tests run: 447, Failure: 0, Error: 1, Pass: 201, Ignore: 245
  OHOS_REPORT_CODE: 0

  OHOS_REPORT_RESULT: breakOnError model, Stopping whole test suite if one specific test case failed or error
  OHOS_REPORT_STATUS: taskconsuming=16029

 ```

| 日志输出字段               | 日志输出字段含义           |
| ------------------| -------------------------|
| run    | 当前测试包用例总数。 |
| Failure | 当前测试失败用例数量。 |
| Error | 当前执行用例发生错误用例数量。  |
| Pass | 当前执行用例通过用例数量。|
| Ignore | 当前未执行用例数量。 |
| taskconsuming| 执行当前测试用例总耗时（ms）。 |

> **说明：**
>
> 当按照遇错即停方式执行时，用例发生错误时，注意查看Ignore字段以及错误中断时的提示信息。

## 单元测试框架能力使用说明
### 基础流程能力
单元测试框架提供执行测试脚本所需的基础流程接口，开发者需要实现相关接口，框架侧在运行时通过基础流程接口识别测试用例，调度执行并汇总测试结果。当前支持的基础流程接口如下表所示：
| 接口名               | 功能说明                                                                   |
| ----------------- |------------------------------------------------------------------------|
|  describe          | 定义一个测试套，测试套中可以定义多个测试用例函数，但不支持异步函数。                      |
|  it          | 定义一条测试用例。          |
|  beforeAll         | 在测试套内定义一个预置条件，在所有测试用例开始前执行且仅执行一次。                        |
|  beforeEach        | 在测试套内定义一个预置条件，在每条测试用例开始前执行，执行次数与it定义的测试用例数一致。          |
|  afterEach         | 在测试套内定义一个单元清理条件，在每条测试用例结束后执行，执行次数与it定义的测试用例数一致。          |
|  afterAll          | 在测试套内定义一个清理条件，在所有测试用例结束后执行且仅执行一次。                        |
|  beforeItSpecified | 在测试套内定义一个单元预置条件，仅在指定测试用例开始前执行。<br>**说明**：从@ohos/hypium 1.0.15版本开始支持。 |
|  afterItSpecified  | 在测试套内定义一个单元清理条件，仅在指定测试用例结束后执行。<br>**说明**：从@ohos/hypium 1.0.15版本开始支持。 |
|  expect            | 支持bool类型判断等多种断言能力。                        |
|  xdescribe    | 定义一个跳过的测试套，测试套中可以定义多个测试用例函数，但不支持异步函数。<br>**说明**：从@ohos/hypium 1.0.17版本开始支持。                             |
|  xit                | 定义一条跳过的测试用例。    <br>**说明**：从@ohos/hypium 1.0.17版本开始支持。                     |


**示例代码1**：beforeAll/beforeEach/afterEach/afterAll使用示例

```ts
import { describe, beforeAll, beforeEach, afterEach, afterAll, it, expect, Level } from '@ohos/hypium';

export default function exampleTest() {
  
  describe('ExampleTest', () =>{
    let testNumA : number = 1;
    let testNumB : number = 1;
    
    beforeAll(() => {
      testNumA++;
    })
  
    beforeEach(() => {
      testNumA++;
      testNumB++;
    })
 
    afterEach(() => {
      testNumA++;
    })
  
    afterAll(() => {
      expect(testNumA).assertEqual(5);
    })
     
    it('testExampleA',Level.LEVEL1, async (done: Function) => {
      console.info("unitTest: testExampleA begin");
      expect(testNumA).assertEqual(3);
      expect(testNumB).assertEqual(2);
      done();
    })

    it('testExampleB',Level.LEVEL1, async (done: Function) => {
      console.info("unitTest: testExampleB begin");
      expect(testNumA).assertEqual(5);
      expect(testNumB).assertEqual(3);
      done();
    })
  })
}
```
**示例代码2**：beforeItSpecified/afterItSpecified使用示例，从1.0.15版本开始支持
```ts
import { describe, beforeItSpecified, afterItSpecified, it, expect, Level } from '@ohos/hypium';

export default function exampleTest() {
    
  describe('ExampleTest', () =>{
   let testNumA : number = 1;
   let testNumB : number = 1;

   beforeItSpecified(['testExampleB'], () => {
      testNumB++;
    })
   afterItSpecified(['testExampleA'], () => {
      testNumA++;
    })
      
    it('testExampleA',Level.LEVEL1, async (done: Function) => {
      console.info("unitTest: testExampleA begin");
      expect(testNumA).assertEqual(1);
      expect(testNumB).assertEqual(1);
      done();
    })

    it('testExampleB',Level.LEVEL1, async (done: Function) => {
      console.info("unitTest: testExampleB begin");
      expect(testNumA).assertEqual(2);
      expect(testNumB).assertEqual(2);
      done();
    })
  })
}
```
**示例代码3**：xit使用示例，从1.0.17版本开始支持

```ts
import { describe, xit, it, Level } from '@ohos/hypium';

export default function describeExampleTest() {
  
  describe('ExampleTest', () =>{
    xit('testExampleA',Level.LEVEL1, async (done: Function) => {
      console.info("unitTest: testExampleA begin");
      done();
    })

    it('testExampleB',Level.LEVEL1, async (done: Function) => {
      console.info("unitTest: testExampleB begin");
      done();
    })
  })
}
```

### 断言能力
单元测试框架提供了丰富的断言接口，供开发者在不同测试场景下使用，详细接口可查看下表。
| 接口名                | 功能说明                                                        |
| :------------------|-------------------------------------------------------------|
|  assertClose        | 检验实际值和预期值之间的数值差异是否在指定的允许误差范围内。         |
|  assertContain      | 检验实际值中是否包含预期值。                              |
|  assertEqual        | 检验实际值是否等于预期值。                            |
|  assertFail         | 抛出一个错误。                                                     |
|  assertFalse        | 检验实际值是否是false。                                      |
|  assertTrue         | 检验实际值是否是true。                                       |
|  assertInstanceOf   | 检验实际值是否是预期类型，支持基础类型。                       |
|  assertLarger       | 检验实际值是否大于预期值。                               |
|  assertLargerOrEqual       | 检验实际值是否大于或等于预期值。                             |
|  assertLess         | 检验实际值是否小于预期值。                               |
|  assertLessOrEqual         | 检验实际值是否小于或等于预期值。                             |
|  assertNull         | 检验实际值是否是null。                                       |
|  assertThrowError   | 检验实际值抛出Error内容是否为预期的异常类型。                      |
|  assertUndefined    | 检验实际值是否是undefined。                                  |
|  assertNaN          |  检验实际值是否是NaN。   <br> **说明**：从@ohos/hypium 1.0.4版本开始支持。                      |
|  assertNegUnlimited | 检验实际值是否等于Number.NEGATIVE_INFINITY。<br> **说明**：从@ohos/hypium 1.0.4版本开始支持。    |
|  assertPosUnlimited | 检验实际值是否等于Number.POSITIVE_INFINITY。<br> **说明**：从@ohos/hypium 1.0.4版本开始支持。     |
|  assertDeepEquals   | 检验实际值和预期值是否完全相等。<br> **说明**：从@ohos/hypium 1.0.4版本开始支持。               |
|  assertPromiseIsPending | 检验Promise是否处于Pending状态。<br>**说明**：从@ohos/hypium 1.0.4版本开始支持。                         |
|  assertPromiseIsRejected | 检验Promise是否处于Rejected状态。<br>**说明**：从@ohos/hypium 1.0.4版本开始支持。                        |
|  assertPromiseIsRejectedWith | 检验Promise是否处于Rejected状态，并且比较执行的结果值。<br>**说明**：从@ohos/hypium 1.0.4版本开始支持。             |
|  assertPromiseIsRejectedWithError |  检验Promise是否处于Rejected状态并包含异常，比较异常类型和异常信息。<br>**说明**：从@ohos/hypium 1.0.4版本开始支持。 |
|  assertPromiseIsResolved | 检验Promise是否处于Resolved状态。<br>**说明**：从@ohos/hypium 1.0.4版本开始支持。                        |
|  assertPromiseIsResolvedWith |检验Promise是否处于Resolved状态并比较结果值。<br> **说明**：从@ohos/hypium 1.0.4版本开始支持。            |
|  not                | 断言取反，支持上述所有断言功能。<br>**说明**：从@ohos/hypium 1.0.4版本开始支持。           |

**示例代码**：
```ts
import { describe, it, expect, Level } from '@ohos/hypium';

export default function exampleTest() {
  describe('ExampleTest', () =>{
    it('assertCloseTest', Level.LEVEL1, () => {
      let a: number = 100;
      let b: number = 0.1;
      expect(a).assertClose(99, b);
    })

    it('assertContain_1', Level.LEVEL1, () => {
      let a = "abc";
      expect(a).assertContain('b');
    })

    it('assertContain_2', Level.LEVEL1, () => {
      let a = [1, 2, 3];
      expect(a).assertContain(1);
    })

    it('assertEqualTest', Level.LEVEL1, () => {
      expect(3).assertEqual(3);
    })

    it('assertFailTest', Level.LEVEL1, () => {
      expect().assertFail(); // 用例失败
    })

    it('assertFalseTest', Level.LEVEL1, () => {
      expect(false).assertFalse();
    })

    it('assertTrueTest', Level.LEVEL1, () => {
      expect(true).assertTrue();
    })

    it('assertInstanceOfTest', Level.LEVEL1, () => {
      let a: string = 'strTest';
      expect(a).assertInstanceOf('String');
    })

    it('assertLargerTest', Level.LEVEL1, () => {
      expect(3).assertLarger(2);
    })

    it('assertLessTest', Level.LEVEL1, () => {
      expect(2).assertLess(3);
    })

    it('assertNullTest', Level.LEVEL1, () => {
      expect(null).assertNull();
    })

    it('assertThrowErrorTest', Level.LEVEL1, () => {
      expect(() => {
        throw new Error('test');
      }).assertThrowError('test');
    })

    it('assertUndefinedTest', Level.LEVEL1, () => {
      expect(undefined).assertUndefined();
    })

    it('assertLargerOrEqualTest', Level.LEVEL1, () => {
      expect(3).assertLargerOrEqual(3);
    })

    it('assertLessOrEqualTest', Level.LEVEL1, () => {
      expect(3).assertLessOrEqual(3);
    })

    it('assertNaNTest', Level.LEVEL1, () => {
      expect(Number.NaN).assertNaN(); // true
    })

    it('assertNegUnlimitedTest', Level.LEVEL1, () => {
      expect(Number.NEGATIVE_INFINITY).assertNegUnlimited(); // true
    })

    it('assertPosUnlimitedTest', Level.LEVEL1, () => {
      expect(Number.POSITIVE_INFINITY).assertPosUnlimited(); // true
    })

    it('deepEquals_null_true', Level.LEVEL1, () => {
      expect(null).assertDeepEquals(null);
    })

    it('deepEquals_array_not_have_true', Level.LEVEL1, () => {
      const a: Array<number> = [];
      const b: Array<number> = [];
      expect(a).assertDeepEquals(b);
    })

    it('deepEquals_map_equal_length_success', Level.LEVEL1, () => {
      const a: Map<number, number> = new Map();
      const b: Map<number, number> = new Map();
      a.set(1, 100);
      a.set(2, 200);
      b.set(1, 100);
      b.set(2, 200);
      expect(a).assertDeepEquals(b);
    })

    it("deepEquals_obj_success_1", Level.LEVEL1, () => {
      const a: SampleTest = {x: 1};
      const b: SampleTest = {x: 1};
      expect(a).assertDeepEquals(b);
    })

    it("deepEquals_regExp_success_0", Level.LEVEL1, () => {
      const a: RegExp = new RegExp("/test/");
      const b: RegExp = new RegExp("/test/");
      expect(a).assertDeepEquals(b);
    })

    it('assertPromiseIsPendingTest', Level.LEVEL1, async () => {
      let p: Promise<void> = new Promise<void>(() => {});
      await expect(p).assertPromiseIsPending();
    })

    it('assertPromiseIsRejectedTest', Level.LEVEL1, async () => {
      let info: PromiseInfo = {res: "no"};
      let p: Promise<PromiseInfo> = Promise.reject(info);
      await expect(p).assertPromiseIsRejected();
    })

    it('assertPromiseIsRejectedWithTest', Level.LEVEL1, async () => {
      let info: PromiseInfo = {res: "reject value"};
      let p: Promise<PromiseInfo> = Promise.reject(info);
      await expect(p).assertPromiseIsRejectedWith(info);
    })

    it('assertPromiseIsRejectedWithErrorTest', Level.LEVEL1, async () => {
      let p1: Promise<TypeError> = Promise.reject(new TypeError('number'));
      await expect(p1).assertPromiseIsRejectedWithError(TypeError);
    })
    
    it('assertPromiseIsResolvedTest', Level.LEVEL1, async () => {
      let info: PromiseInfo = {res: "result value"};
      let p: Promise<PromiseInfo> = Promise.resolve(info);
      await expect(p).assertPromiseIsResolved();
    })

    it('assertPromiseIsResolvedWithTest', Level.LEVEL1, async () => {
      let info: PromiseInfo = {res: "result value"};
      let p: Promise<PromiseInfo> = Promise.resolve(info);
      await expect(p).assertPromiseIsResolvedWith(info);
    })

    it("test_message", Level.LEVEL1, () => {
      expect(1).message('1 is not equal 2!').assertEqual(2); // fail
    })
  })
}

interface SampleTest {
  x: number;
}

interface PromiseInfo {
  res: string;
}
```
### Mock能力
从@ohos/hypium 1.0.1版本开始，单元测试框架支持Mock能力。配置方式参考上文[发布方式](#发布方式)。

> **说明：**
>
>仅支持Mock应用工程中自定义对象，不支持Mock系统API对象。如需Mock系统API，请参考[系统模块Mock指南](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-test-mock#section8353132513310)。
>
>不支持Mock对象的私有函数。 

**基础类**

Mockit是Mock的基础类，用于指定需要Mock的实例和函数。
| 接口名 | 功能说明                 |
| --- |-------------------------------------------------------------------------------------------------------------------------------------------------|
| mockFunc| Mock某个类实例中的函数，支持使用异步函数。                                                 |
| verify | 验证函数在对应参数下的执行行为是否符合预期，返回一个VerificationMode类。 |
| ignoreMock | 使用ignoreMock可以还原实例中被Mock后的函数，对被Mock后的函数有效。                                                                                                   |
| clear | 用例执行完毕后，对数据mocker实例进行还原处理（还原之后对象恢复被Mock之前的功能）。                                                                       |
| clearAll | 用例执行完毕后，进行数据和内存清理，不会还原实例中被Mock后的函数。                                  |  

**VerificationMode**

VerificationMode用于验证被Mock函数的被调用次数，需同verify函数结合使用。
| 接口名 | 功能说明                                                                                                                                         |
| --- |-------------------------------------------------------------------------------------------------------------------------------------------------|
| times | 验证函数被调用过的次数符合预期。                                                                                                                                  |
| once | 验证函数被调用过一次。                                                                                                                                      |
| atLeast | 验证函数最少被调用的次数符合预期。                                                                                                                                |
| atMost | 验证函数最多被调用的次数符合预期。                                                                                                                               |
| never | 验证函数从未被调用过。                                                                                                                                |

**when**

when是一个函数，用于设置函数期望被Mock的值。
| 接口名 | 功能说明                                                                                                                                            |
| --- |-------------------------------------------------------------------------------------------------------------------------------------------------|
| when | 对传入后函数做检查，检查是否被Mock并标记过，返回一个内置函数，函数执行后返回一个类用于设置Mock值。                                                                                                           |

使用when函数之后，需使用如下函数设置函数被Mock后的返回值。
| 接口名 | 功能说明                                                                                                                                            |
| --- |-------------------------------------------------------------------------------------------------------------------------------------------------|
| afterReturn | 设定一个自定义的期望返回值，比如某个字符串或者一个Promise。                                                                                                          |
| afterReturnNothing| 设定预期没有返回值，即undefined。                                                                                                                          |
| afterAction | 设定预期返回一个函数执行的操作。                                                                                                                                |
| afterThrow | 设定预期抛出异常，并指定异常描述信息。                                                                                                                              |

**ArgumentMatchers相关接口**

ArgumentMatchers用于用户自定义函数参数，当开发者想基于某类规则设定预期返回值时，可以使用。它以枚举值或函数的形式提供给开发者使用。
| 枚举名 | 功能说明                           |
| --- |-------------------------------------------------------------------------------------------------------------------------------------------------|
| any | 设定用户传任何类型参数（undefined和null除外），执行的结果返回所设置的预期值，使用ArgumentMatchers.any方式调用。                                                                           |
| anyString | 设定用户传任何字符串参数，执行的结果都是预期的值，使用ArgumentMatchers.anyString方式调用。                                                                                      |
| anyBoolean | 设定用户传任何boolean类型参数，执行的结果都是预期的值，使用ArgumentMatchers.anyBoolean方式调用。                                                                               |
| anyFunction | 设定用户传任何function类型参数，执行的结果都是预期的值，使用ArgumentMatchers.anyFunction方式调用。                                                                             |
| anyNumber | 设定用户传任何数字类型参数，执行的结果都是预期的值，使用ArgumentMatchers.anyNumber方式调用。                                                                                     |
| anyObj | 设定用户传任何对象类型参数，执行的结果都是预期的值，使用ArgumentMatchers.anyObj方式调用。 

| 接口名 | 功能说明    |
| --- |--------------|                                           
| matchRegexs | 设定用户传任何符合正则表达式验证的参数，执行的结果都是预期的值，使用ArgumentMatchers.matchRegexs(Regex)方式调用。 


> **说明：**
>使用Mock能力时必须导入Mock能力模块： MockKit，when，开发者可根据实际需求导入对应模块。
>
>例如：`import { describe, expect, it, MockKit, when} from '@ohos/hypium'`

**示例代码1**：使用afterReturn/afterReturnNothing设置预期返回值

```ts
import { describe, expect, it, MockKit, when } from '@ohos/hypium';

class ClassName {
  constructor() {
  }

  method_1(arg: string) {
    return '888888';
  }

  method_2(arg: string) {
    return '999999';
  }
}
export default function afterReturnTest() {
  describe('afterReturnTest', () => {
    it('afterReturnTest', 0, () => {
      console.info("it1 begin");
      // 创建一个Mock能力的对象MockKit
      let mocker: MockKit = new MockKit();
      // 初始化ClassName的对象claser
      let claser: ClassName = new ClassName();
      // 进行Mock操作，对ClassName类的method_1函数进行Mock
      let mockfunc: Function = mocker.mockFunc(claser, claser.method_1);
      // 期望claser.method_1函数被Mock后, 以'testA'为入参时调用函数返回结果'1',以'testB''为入参时调用函数返回结果undefined
      when(mockfunc)('testA').afterReturn('1');
      when(mockfunc)('testB').afterReturnNothing();
      // 对Mock后的函数进行断言，看是否符合预期。分别传入参数'testA'和'testB'时，应该返回自定义的预期结果1和undefined
      expect(claser.method_1('testA')).assertEqual('1'); // 断言执行通过
      expect(claser.method_1('testB')).assertUndefined(); // 断言执行通过
    })
  })
}
```

**示例代码2**：使用ArgumentMatchers设定参数类型为any即接受任何参数（undefined和null除外）

```ts
import { describe, expect, it, MockKit, when, ArgumentMatchers } from '@ohos/hypium';

class ClassName {
  constructor() {
  }

  method_1(arg: string) {
    return '888888';
  }

  method_2(arg: string) {
    return '999999';
  }
}
export default function argumentMatchersAnyTest() {
  describe('argumentMatchersAnyTest', () => {
    it('testMockfunc', 0, () => {
      console.info("it1 begin");
      // 创建一个Mock能力的对象MockKit
      let mocker: MockKit = new MockKit();
      // 初始化ClassName的对象claser
      let claser: ClassName = new ClassName();
      // 进行Mock操作，对ClassName类的method_1函数进行Mock
      let mockfunc: Function = mocker.mockFunc(claser, claser.method_1);
      // 期望claser.method_1函数被Mock后, 参数为任一类型在被调用时均返回结果'1'
      when(mockfunc)(ArgumentMatchers.any).afterReturn('1');
      // 传入不同参数验证是否符合预期
      expect(claser.method_1('test')).assertEqual('1'); // 断言执行通过
      expect(claser.method_1("123")).assertEqual('1');// 断言执行通过
      expect(claser.method_1("true")).assertEqual('1');// 断言执行通过
    })
  })
}
```

**示例代码3**：使用ArgumentMatchers设定参数类型为String

```ts
import { describe, expect, it, MockKit, when, ArgumentMatchers } from '@ohos/hypium';

class ClassName {
  constructor() {
  }

  method_1(arg: string) {
    return '888888';
  }

  method_2(arg: string) {
    return '999999';
  }
}
export default function argumentMatchersTest() {
  describe('argumentMatchersTest', () => {
    it('testMockfunc', 0, () => {
      console.info("it1 begin");
      // 创建一个Mock能力的对象MockKit
      let mocker: MockKit = new MockKit();
      // 初始化ClassName的对象claser
      let claser: ClassName = new ClassName();
      // 进行Mock操作,对ClassName类的method_1函数进行Mock
      let mockfunc: Function = mocker.mockFunc(claser, claser.method_1);
      // 期望claser.method_1函数被Mock后, 以任何string类型为参数调用函数时返回结果'1'
      when(mockfunc)(ArgumentMatchers.anyString).afterReturn('1');
      // 传入不同string类型参数，验证是否符合预期
      expect(claser.method_1('test')).assertEqual('1'); // 断言执行通过
      expect(claser.method_1('abc')).assertEqual('1'); // 断言执行通过
    })
  })
}
```

**示例代码4**：使用ArgumentMatchers设定参数类型为matchRegexs（Regex）即正则表达式

```ts
import { describe, expect, it, MockKit, when, ArgumentMatchers } from '@ohos/hypium';

class ClassName {
  constructor() {
  }

  method_1(arg: string) {
    return '888888';
  }

  method_2(arg: string) {
    return '999999';
  }
}
export default function matchRegexsTest() {
  describe('matchRegexsTest', () => {
    it('testMockfunc', 0, () => {
      console.info("it1 begin");
      // 创建一个Mock能力的对象MockKit
      let mocker: MockKit = new MockKit();
      // 初始化ClassName的对象claser
      let claser: ClassName = new ClassName();
      // 进行Mock操作，对ClassName类的method_1函数进行Mock
      let mockfunc: Function = mocker.mockFunc(claser, claser.method_1);
      // 期望claser.method_1函数被Mock后, 以"test"为入参调用函数时返回结果'1'
      when(mockfunc)(ArgumentMatchers.matchRegexs(new RegExp("test"))).afterReturn('1');
      // 传入test参数后验证是否符合预期
      expect(claser.method_1('test')).assertEqual('1'); // 断言执行通过
    })
  })
}
```

**示例代码5**：使用verify函数验证被Mock函数在对应参数下的执行行为是否符合预期

```ts
import { describe, it, MockKit } from '@ohos/hypium';

class ClassName {
  constructor() {
  }

  method_1(...arg: string[]) {
    return '888888';
  }

  method_2(...arg: string[]) {
    return '999999';
  }
}
export default function verifyTest() {
  describe('verifyTest', () => {
    it('testMockfunc', 0, () => {
      console.info("it1 begin");
      // 创建一个Mock能力的对象MockKit
      let mocker: MockKit = new MockKit();
      // 初始化ClassName的对象claser
      let claser: ClassName = new ClassName();
      // 进行Mock操作，对ClassName类的method_1和method_2两个函数进行Mock
      mocker.mockFunc(claser, claser.method_1);
      mocker.mockFunc(claser, claser.method_2);
      // 函数调用
      claser.method_1('abc', 'ppp');
      claser.method_1('abc');
      claser.method_1('xyz');
      claser.method_1();
      claser.method_1('abc', 'xxx', 'yyy');
      claser.method_1();
      claser.method_2('111');
      claser.method_2('111', '222');
      // 对Mock后的两个函数进行验证，验证method_2,参数仅为'111'时执行过一次
      mocker.verify('method_2',['111']).once(); // 断言执行通过
    })
  })
}
```

**示例代码6**：使用ignoreMock函数还原指定被Mock函数实现

```ts
import { describe, expect, it, MockKit, when, ArgumentMatchers } from '@ohos/hypium';

class ClassName {
  constructor() {
  }

  method_1(...arg: number[]) {
    return '888888';
  }

  method_2(...arg: number[]) {
    return '999999';
  }
}
export default function ignoreMockTest() {
  describe('ignoreMockTest', () => {
    it('testMockfunc', 0, () => {
      console.info("it1 begin");
      // 创建一个Mock能力的对象MockKit
      let mocker: MockKit = new MockKit();
      // 初始化ClassName的对象claser
      let claser: ClassName = new ClassName();
      // 进行Mock操作，对ClassName类的method_1和method_2两个函数进行Mock
      let func_1: Function = mocker.mockFunc(claser, claser.method_1);
      let func_2: Function = mocker.mockFunc(claser, claser.method_2);
      // 期望claser.method_1函数被Mock后, 以number类型为入参时调用函数返回结果'4'
      when(func_1)(ArgumentMatchers.anyNumber).afterReturn('4');
      // 期望claser.method_2函数被Mock后, 以number类型为入参时调用函数返回结果'5'
      when(func_2)(ArgumentMatchers.anyNumber).afterReturn('5');
      // 函数调用
      expect(claser.method_1(123)).assertEqual("4");
      expect(claser.method_2(456)).assertEqual("5");
      // 现在对Mock后的两个函数的其中一个函数method_1进行还原处理
      mocker.ignoreMock(claser, claser.method_1);
      // 调用claser.method_1函数
      expect(claser.method_1(123)).assertEqual('888888');// 断言执行通过
    })
  })
}
```

**示例代码7**：使用clear函数还原类中所有被Mock函数原有实现

```ts
import { describe, expect, it, MockKit, when, ArgumentMatchers } from '@ohos/hypium';

class ClassName {
  constructor() {
  }

  method_1(...arg: number[]) {
    return '888888';
  }

  method_2(...arg: number[]) {
    return '999999';
  }
}
export default function clearTest() {
  describe('clearTest', () => {
    it('testMockfunc', 0, () => {
      console.info("it1 begin");
      // 创建一个Mock能力的对象MockKit
      let mocker: MockKit = new MockKit();
      // 初始化ClassName的对象claser
      let claser: ClassName = new ClassName();
      // 进行Mock操作，对ClassName类的method_1和method_2两个函数进行Mock
      let func_1: Function = mocker.mockFunc(claser, claser.method_1);
      let func_2: Function = mocker.mockFunc(claser, claser.method_2);
      // 期望claser.method_1函数被Mock后, 以任何number类型为参数调用函数时返回结果'4'
      when(func_1)(ArgumentMatchers.anyNumber).afterReturn('4');
      // 期望claser.method_2函数被Mock后, 以任何number类型为参数调用函数时返回结果'5'
      when(func_2)(ArgumentMatchers.anyNumber).afterReturn('5');
      // 函数调用
      expect(claser.method_1(123)).assertEqual('4');
      expect(claser.method_2(123)).assertEqual('5');
      // 还原obj上所有的Mock能力
      mocker.clear(claser);
      // 调用claser.method_1,claser.method_2函数，测试结果
      expect(claser.method_1(123)).assertEqual('888888');// 断言执行通过
      expect(claser.method_2(123)).assertEqual('999999');// 断言执行通过
    })
  })
}
```

**示例代码8**：使用afterThrow函数抛出指定异常信息

```ts
import { describe, expect, it, MockKit, when } from '@ohos/hypium';

class ClassName {
  constructor() {
  }

  method_1(arg: string) {
    return '888888';
  }
}
export default function afterThrowTest() {
  describe('afterThrowTest', () => {
    it('testMockfunc', 0, () => {
      console.info("it1 begin");
      // 创建一个Mock能力的对象MockKit
      let mocker: MockKit = new MockKit();
      // 初始化ClassName的对象claser
      let claser: ClassName = new ClassName();
      // 进行Mock操作,对ClassName类的method_1函数进行Mock
      let mockfunc: Function = mocker.mockFunc(claser, claser.method_1);
      // 期望claser.method_1函数被Mock后, 以'test'为参数调用函数时抛出error xxx异常
      when(mockfunc)('test').afterThrow('error xxx');
      // 执行Mock后的函数，捕捉异常并使用assertEqual对比msg否符合预期
      try {
        claser.method_1('test');
      } catch (e) {
        expect(e).assertEqual('error xxx'); // 断言执行通过
      }
    })
  })
}
```

**示例代码9**：Mock异步返回Promise对象

```ts
import { describe, expect, it, MockKit, when } from '@ohos/hypium';

class ClassName {
  constructor() {
  }

  async method_1(arg: string) {
    return new Promise<string>((resolve: Function, reject: Function) => {
      setTimeout(() => {
        console.log('执行');
        resolve('数据传递');
      }, 2000);
    });
  }
}
export default function mockPromiseTest() {
  describe('mockPromiseTest', () => {
    it('testMockfunc', 0, async (done: Function) => {
      console.info("it1 begin");
      // 创建一个Mock能力的对象MockKit
      let mocker: MockKit = new MockKit();
      // 初始化ClassName的对象claser
      let claser: ClassName = new ClassName();
      // 进行Mock操作对ClassName类的method_1函数进行Mock
      let mockfunc: Function = mocker.mockFunc(claser, claser.method_1);
      // 期望claser.method_1函数被Mock后, 以'test'为参数调用函数时返回一个Promise对象
      when(mockfunc)('test').afterReturn(new Promise<string>((resolve: Function, reject: Function) => {
        console.log("do something");
        resolve('success something');
      }));
      // 执行Mock后的函数，即对定义的Promise进行后续执行
      let result = await claser.method_1('test');
      expect(result).assertEqual("success something");// 断言执行通过
      done();
    })
  })
}
```

**示例代码10**：使用times/atLeast函数验证被Mock函数调用次数

```ts
import { describe, it, MockKit, when } from '@ohos/hypium'

class ClassName {
  constructor() {
  }

  method_1(...arg: string[]) {
    return '888888';
  }
}
export default function verifyTimesTest() {
  describe('verifyTimesTest', () => {
    it('test_verify_times', 0, () => {
      // 创建一个Mock能力的对象MockKit
      let mocker: MockKit = new MockKit();
      // 初始化ClassName的对象claser
      let claser: ClassName = new ClassName();
      // 进行Mock操作对ClassName类的method_1函数进行Mock
      let func_1: Function = mocker.mockFunc(claser, claser.method_1);
      // 期望被Mock后的函数返回结果'4'
      when(func_1)('123').afterReturn('4');
      // 5.函数调用
      claser.method_1('123', 'ppp');
      claser.method_1('abc');
      claser.method_1('xyz');
      claser.method_1();
      claser.method_1('abc', 'xxx', 'yyy');
      claser.method_1('abc');
      claser.method_1();
      // 验证函数method_1且参数为'abc'时，执行过的次数是否为2
      mocker.verify('method_1', ['abc']).times(2);// 断言执行通过
       // 验证函数method_1且参数为空时，是否至少执行过2次
      mocker.verify('method_1', []).atLeast(2);// 断言执行通过
    })
  })
}
```

**示例代码11**：Mock静态函数（从1.0.16版本开始支持）

```ts
import { describe, it, expect, MockKit, when, ArgumentMatchers } from '@ohos/hypium';

class ClassName {
  constructor() {
  }

  static method_1() {
    return 'ClassName_method_1_call';
  }
}

export default function staticTest() {
  describe('staticTest', () => {
    it('staticTest_001', 0, () => {
      let really_result = ClassName.method_1();
      expect(really_result).assertEqual('ClassName_method_1_call');
      // 创建MockKit对象
      let mocker: MockKit = new MockKit();
      // Mock类ClassName对象的某个函数method_1
      let func_1: Function = mocker.mockFunc(ClassName, ClassName.method_1);
      // 期望被mock后的函数返回结果'mock_data'
      when(func_1)(ArgumentMatchers.any).afterReturn('mock_data');
      let mock_result = ClassName.method_1();
      expect(mock_result).assertEqual('mock_data');// 断言执行通过
      // 清除Mock能力
      mocker.clear(ClassName);
      let really_result1 = ClassName.method_1();
      expect(really_result1).assertEqual('ClassName_method_1_call');// 断言执行通过
    })
  })
}
```

### 数据驱动

单元测试框架的数据驱动能力从[1.0.2版本](https://ohpm.openharmony.cn/#/cn/detail/@ohos%2Fhypium)开始支持。开发者可以复用测试用例代码，通过数据配置文件配置输入数据和预期结果数据，在用例实现中获取数据进行相应实现和断言处理，减少冗余测试代码。

数据驱动能力可以根据测试数据配置来驱动测试用例的执行次数和每次执行时传入的参数，使用时依赖data.json配置文件，文件内容如下：

>**说明：**
>
> data.json与测试用例*.test.js或*.test.ets文件同目录。
>
> data.json文件中的参数配置名称需同测试用例中定义参数名称保持一致。

```json
{
	"suites": [{
		"describe": ["AbilityTest"],
		"stress": 2,
		"params": {
			"suiteParams1": "suiteParams001",
			"suiteParams2": "suiteParams002"
		},
		"items": [{
			"it": "testDataDriverAsync",
			"stress": 2,
			"params": [{
				"name": "tom",
				"value": 5
			}, {
				"name": "jerry",
				"value": 4
			}]
		}, {
			"it": "testDataDriver",
			"stress": 3
		}]
	}]
}
```

配置参数说明：

| 配置项名称 | 功能                                  | 必填 |
| :--------- | :------------------------------------ | ---- |
|  "suite"    | 测试套配置。                         | 是   |
|  "describe"    | 测试套名称。                       | 是   |
|  "items" | 测试用例。                         | 是   |
|  "it"       | 测试用例名称。                       | 是   |
|  "params"   | 测试套/测试用例可传入使用的参数。 | 否   |
|  "stress"   | 测试套/测试用例指定执行次数。     | 否   |

**示例代码**

- Stage模型

在测试工程中的TestAbility目录下TestAbility.ets文件中导入data.json，并在文件中的Hypium.hypiumTest()函数执行前设置参数数据，参考下面示例代码。

- FA模型

在测试工程中的TestAbility目录下的app.js或app.ets文件中导入data.json，并在文件中Hypium.hypiumTest()函数执行前设置参数数据，参考下面示例代码。

```ts
import { abilityDelegatorRegistry } from '@kit.TestKit';
import { Hypium } from '@ohos/hypium';
import testsuite from '../test/List.test';//导入测试用例集合文件
import data from '../test/data.json';//导入参数数据文件

...
let abilityDelegator = abilityDelegatorRegistry.getAbilityDelegator();
let abilityDelegatorArguments = abilityDelegatorRegistry.getArguments();
Hypium.setData(data);//设置参数数据
Hypium.hypiumTest(abilityDelegator, abilityDelegatorArguments, testsuite);
...
```

```ts
 import { describe, it } from '@ohos/hypium';

 export default function abilityTest() {
  describe('AbilityTest', () => {
    it('testDataDriverAsync', 0, async (done: Function, data: ParmObj) => {
      console.info('name: ' + data.name);
      console.info('value: ' + data.value);
      done();
    });

    it('testDataDriver', 0, () => {
      console.info('stress test');
    })
  })
}
 interface ParmObj {
   name: string,
   value: string
 }
```
>**说明:** 
>
>若要使用数据驱动传入参数功能，测试用例 `it` 的 `func` 必须传入两个参数：`done` 定义在前面，`data` 定义在后面。若不使用数据驱动传入参数功能，`func` 可以不传参或仅传入 `done`。

### 专项能力
专项能力提供脚本执行配置能力，包括筛选执行、压力执行、随机执行等，通过命令行方式执行，具体用法请参考[命令行执行测试脚本](#命令行执行测试脚本)章节介绍。

## 单元测试框架常见问题

**用例中增加的打印日志在用例结果之后才打印**

**问题描述**

用例中新增的日志打印信息未在执行过程中出现，而是在执行结束之后才显示。

**可能原因**

此类情况仅在用例调用异步接口时出现。为确保日志正确捕获执行过程，用例中所有日志信息必须在用例执行结束前打印。

**解决方法**

当被调用的异步接口数量超过两个时，建议将接口调用封装成Promise方式调用。

**执行用例时报用例超时错误**

**问题描述**

用例执行结束，控制台提示execute time XXms错误，即用例执行超时。

**可能原因**

1. 用例执行异步接口时，如果未调用done函数，会导致用例无法正常结束，最终超时。
2. 用例调用函数耗时过长，超过用例执行设置的超时时间（默认5000ms）。
3. 用例调用函数时断言失败抛出异常，导致用例执行超时终止。  

**解决方法**

1. 检查用例代码逻辑，确保断言失败时能走到done函数，完成用例执行。
2. 可在DevEco Studio的Run/Debug Configurations中修改用例执行超时参数，避免执行超时。
3. 检查用例代码逻辑，确保断言通过。
