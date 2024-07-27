# ArkCompiler子系统Changelog

## cl.arkcompiler.1 ArkTS Sendable&共享模块语法规则编译检查完善

**访问级别**

其他

**变更原因**

Sendable对象需要遵循[使用规则](../../..//application-dev/arkts-utils/arkts-sendable.md#sendable使用规则)，共享模块需要遵循[使用规则](../../..//application-dev/arkts-utils/arkts-sendable-module.md#使用规格)，在Sendable&共享模块的部分需要约束的export场景中，编译器缺少检查，导致这些场景会发生运行时异常但是没有编译时错误。在本次版本更新中，修复了这些约束的编译时检查，将运行时异常提前到编译时。旨在通过编译时错误或警告，帮助开发者更早发现Sendable&共享模块使用约束，减少运行时定位成本。

**变更影响**

此变更为兼容性变更。


变更前：
1. 当在共享模块中使用`export default someVariable`方式导出，并且`someVariable`是Non-sendable类型时，DevEco编辑界面有错误提示，编译没有错误，程序运行时会崩溃。
2. 当在共享模块中使用`export type someType = someNonSendableType`方式导出Non-sendable类型的别名时，DevEco编辑界面没有提示，编译没有异常。
3. 当sendable class内部使用当前模块top level中`export`的sendable class对象时，DevEco编辑界面没有提示，编译没有异常，运行时会触发异常。

变更后：
1. 当在共享模块中使用`export default someVariable`方式导出，并且`someVariable`是Non-sendable类型时，DevEco编辑界面有错误提示，编译有错误。
2. 当在共享模块中使用`export type someType = someNonSendableType`方式导出Non-sendable类型的别名时，DevEco编辑界面有警告提示，编译有警告。
3. 当sendable class内部使用当前模块top level中`export`的sendable class对象时，DevEco编辑界面有警告提示，编译有警告。


具体场景示例：

共享模块export约束

场景一：在共享模块中使用`export default someVariable`方式导出，并且`someVariable`是Non-sendable类型时。影响：兼容变更，运行时崩溃变更为编译报错

变更前

```ts
'use shared';
class NonSendableClass {};
export default NonSendableClass; // 引发 GC 时崩溃
```

变更后

```ts
'use shared';
class NonSendableClass {};
export default NonSendableClass; // 编译错误
```

场景二：在共享模块中使用`export type someType = someNonSendableType`方式导出Non-sendable的别名时。影响：兼容变更，无提示变更为编辑警告、编译警告

变更前

```ts
'use shared';
class NonSendableClass {};
export type NonSendableAlias = NonSendableClass;
```

变更后

```ts
'use shared';
class NonSendableClass {};
export type NonSendableAlias = NonSendableClass; // DevEco编辑界面警告提示 & 编译警告
```

sendable class内部的变量使用约束

场景一：当sendable class内部使用当前模块top level中`export`的sendable class对象时。影响：兼容变更，运行时异常变更为编辑、编译警告

变更前

```ts
import { taskpool } from '@kit.ArkTS';

@Sendable
export class SendableData {};

@Sendable
class SendableClass {
    handle():void {
      new SendableData(); // 运行时异常
    }
}

@Concurrent
async function taskHandle(sendable: SendableClass) {
  sendable.handle();
}

taskpool.execute(new taskpool.Task(taskHandle, new SendableClass()));
```

变更后

```ts
import { taskpool } from '@kit.ArkTS';

@Sendable
export class SendableData {};

@Sendable
class SendableClass {
    handle():void {
      new SendableData(); // DevEco编辑界面警告提示 & 编译警告
    }
}

@Concurrent
async function taskHandle(sendable: SendableClass) {
  sendable.handle();
}

taskpool.execute(new taskpool.Task(taskHandle, new SendableClass()));
```

**起始 API Level**

ArkTS Sendable语法检查从API 12起启用。

**变更发生版本**

从OpenHarmony SDK 5.0.0.36 开始。

**变更的接口/组件**

不涉及。

**适配指导**

对于开发者，建议按照Sendable&共享模块规格修复新增警告，防止出现运行时异常。
