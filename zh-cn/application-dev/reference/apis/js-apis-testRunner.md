# TestRunner

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 本模块首批接口从API version 8开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。  

## 导入模块

```js
import TestRunner from '@ohos.application.testRunner'
```



## TestRunner.onPrepare

onPrepare(): void

为运行测试用例准备单元测试环境

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**示例：**

```js
export default class UserTestRunner extends TestRunner {
    onPrepare() {
        console.log("Trigger onPrepare")
    }
};
```



## TestRunner.onRun

onRun(): void

运行测试用例

**系统能力：** SystemCapability.Ability.AbilityRuntime.Core

**示例：**

```js
export default class UserTestRunner extends TestRunner {
    onRun() {
        console.log("Trigger onRun")
    }
};
```
