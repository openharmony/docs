# @ohos.app.ability.sendableContextManager (sendableContextManager)

sendableContextManager模块提供Context与[SendableContext](js-apis-inner-application-sendableContext.md)相互转换的能力。

> **说明：**
>
> - 本模块首批接口从API version 12 开始支持。后续版本的新增接口，采用上角标单独标记接口的起始版本。
> - 本模块接口仅可在Stage模型下使用。

## 使用场景

本模块主要用于ArkTS并发实例间（包括主线程、TaskPool&Worker工作线程）的数据传递。

例如，以主线程向子线程传递Sendable数据，转换过程如下：
- 主线程向子线程传递Sendable数据时，需要将Context转换为SendableContext。
- 子线程使用Sendable数据时，需要将SendableContext转换为Context。

这里的Context与[createModuleContext](js-apis-inner-application-context.md#contextcreatemodulecontextdeprecated)方法创建的Context不同，具体差异如下：
- 与SendableContext相互转换的Context：ArkTS并发实例持有的应用侧Context是不同的实例，底层对应同一个Context对象。当一个实例中Context属性和方法被修改时，相关实例中的Context属性和方法将会同步修改。其中，Context实例中的eventHub属性比较特殊，不同实例中的eventHub是独立的对象，不支持跨ArkTS实例使用。
- 通过[createModuleContext](js-apis-inner-application-context.md#contextcreatemodulecontextdeprecated)创建的Context：ArkTS并发实例持有的应用侧Context是不同的实例，底层对应不同的Context对象。

## 约束限制

“Context转换为SendableContext”和“SendableContext转换为Context”两个环节中的Context类型必须保持一致。目前支持转换的Context包括[Context](js-apis-inner-application-context.md)、[ApplicationContext](js-apis-inner-application-applicationContext.md)、[AbilityStageContext](js-apis-inner-application-abilityStageContext.md)、[UIAbilityContext](js-apis-inner-application-uiAbilityContext.md)。

## 导入模块

```ts
import { sendableContextManager } from '@kit.AbilityKit';
```

## 属性

**系统能力**：SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

| 名称 | 类型 | 必填 | 说明 |
| ------- | ------- | ------- | ------- |
| SendableContext | [SendableContext](js-apis-inner-application-sendableContext.md) | 是 | SendableContext二级模块。 |

**示例：**

```ts
import { sendableContextManager } from '@kit.AbilityKit';

let sendableContext: sendableContextManager.SendableContext;
```

## sendableContextManager.convertFromContext

convertFromContext(context: common.Context): SendableContext;

将Context转换为SendableContext对象。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------- | ------- | ------- | ------- |
| context | common.Context | 是 | Context对象，支持Context基类，ApplicationContext、AbilityStageContext和UIAbilityContext子类。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ------- |
| 401     | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed. |

**示例：**

```ts
import { AbilityConstant, UIAbility, Want, sendableContextManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { worker } from '@kit.ArkTS';

@Sendable
export class SendableObject {
  constructor(sendableContext: sendableContextManager.SendableContext) {
    this.sendableContext = sendableContext;
  }

  sendableContext: sendableContextManager.SendableContext;
  // other sendable object
}

export default class EntryAbility extends UIAbility {
  worker: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/Worker.ets');

  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');

    // convert and post
    try {
      let sendableContext: sendableContextManager.SendableContext = sendableContextManager.convertFromContext(this.context);
      let object: SendableObject = new SendableObject(sendableContext);
      hilog.info(0x0000, 'testTag', '%{public}s', 'Ability post message');
      this.worker.postMessageWithSharedSendable(object);
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'convertFromContext failed %{public}s', JSON.stringify(error));
    }
  }
}
```

## sendableContextManager.convertToContext

convertToContext(sendableContext: SendableContext): common.Context

将SendableContext对象转换为Context。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------- | ------- | ------- | ------- |
| sendableContext | [SendableContext](js-apis-inner-application-sendableContext.md) | 是 | SendableContext对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ------- |
| 401     | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed. |

**示例：**

主线程传递Context：
```ts
import { AbilityConstant, UIAbility, Want, common, sendableContextManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { worker } from '@kit.ArkTS';

@Sendable
export class SendableObject {
  constructor(sendableContext: sendableContextManager.SendableContext, contextName: string) {
    this.sendableContext = sendableContext;
    this.contextName = contextName;
  }

  sendableContext: sendableContextManager.SendableContext;
  contextName: string;
}

export default class EntryAbility extends UIAbility {
  worker: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/Worker.ets');

  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');

    // convert and post
    try {
      let context: common.Context = this.context as common.Context;
      let sendableContext: sendableContextManager.SendableContext = sendableContextManager.convertFromContext(context);
      let object: SendableObject = new SendableObject(sendableContext, 'BaseContext');
      hilog.info(0x0000, 'testTag', '%{public}s', 'Ability post message');
      this.worker.postMessageWithSharedSendable(object);
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'convertFromContext failed %{public}s', JSON.stringify(error));
    }
  }
}
```

Worker线程接收Context：
```ts
import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
import { common, sendableContextManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Sendable
export class SendableObject {
  constructor(sendableContext: sendableContextManager.SendableContext, contextName: string) {
    this.sendableContext = sendableContext;
    this.contextName = contextName;
  }

  sendableContext: sendableContextManager.SendableContext;
  contextName: string;
}

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

workerPort.onmessage = (e: MessageEvents) => {
  let object: SendableObject = e.data;
  let sendableContext: sendableContextManager.SendableContext = object.sendableContext;
  if (object.contextName == 'BaseContext') {
    hilog.info(0x0000, 'testTag', '%{public}s', 'convert to context.');
    try {
      let context: common.Context = sendableContextManager.convertToContext(sendableContext);
      // 获取context后获取沙箱路径
      hilog.info(0x0000, 'testTag', 'worker context.databaseDir: %{public}s', context.databaseDir);
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'convertToContext failed %{public}s', JSON.stringify(error));
    }
  }
}

workerPort.onmessageerror = (e: MessageEvents) => {
  hilog.info(0x0000, 'testTag', '%{public}s', 'onmessageerror');
}

workerPort.onerror = (e: ErrorEvent) => {
  hilog.info(0x0000, 'testTag', '%{public}s', 'onerror');
}
```

## sendableContextManager.convertToApplicationContext

convertToApplicationContext(sendableContext: SendableContext): common.ApplicationContext

将SendableContext对象转换为ApplicationContext。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------- | ------- | ------- | ------- |
| sendableContext | [SendableContext](js-apis-inner-application-sendableContext.md) | 是 | SendableContext对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ------- |
| 401     | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed. |

**示例：**

主线程传递Context：
```ts
import { AbilityConstant, UIAbility, Want, common, sendableContextManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { worker } from '@kit.ArkTS';

@Sendable
export class SendableObject {
  constructor(sendableContext: sendableContextManager.SendableContext, contextName: string) {
    this.sendableContext = sendableContext;
    this.contextName = contextName;
  }

  sendableContext: sendableContextManager.SendableContext;
  contextName: string;
}

export default class EntryAbility extends UIAbility {
  worker: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/Worker.ets');

  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');

    // convert and post
    try {
      let context: common.Context = this.context as common.Context;
      let applicationContext = context.getApplicationContext();
      let sendableContext: sendableContextManager.SendableContext = sendableContextManager.convertFromContext(applicationContext);
      let object: SendableObject = new SendableObject(sendableContext, 'ApplicationContext');
      hilog.info(0x0000, 'testTag', '%{public}s', 'Ability post message');
      this.worker.postMessageWithSharedSendable(object);
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'convertFromContext failed %{public}s', JSON.stringify(error));
    }
  }
}
```

Worker线程接收Context：
```ts
import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
import { common, sendableContextManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Sendable
export class SendableObject {
  constructor(sendableContext: sendableContextManager.SendableContext, contextName: string) {
    this.sendableContext = sendableContext;
    this.contextName = contextName;
  }

  sendableContext: sendableContextManager.SendableContext;
  contextName: string;
}

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

workerPort.onmessage = (e: MessageEvents) => {
  let object: SendableObject = e.data;
  let sendableContext: sendableContextManager.SendableContext = object.sendableContext;
  if (object.contextName == 'ApplicationContext') {
    hilog.info(0x0000, 'testTag', '%{public}s', 'convert to application context.');
    try {
      let context: common.ApplicationContext = sendableContextManager.convertToApplicationContext(sendableContext);
      // 获取context后获取沙箱路径
      hilog.info(0x0000, 'testTag', 'worker context.databaseDir: %{public}s', context.databaseDir);
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'convertToApplicationContext failed %{public}s', JSON.stringify(error));
    }
  }
}

workerPort.onmessageerror = (e: MessageEvents) => {
  hilog.info(0x0000, 'testTag', '%{public}s', 'onmessageerror');
}

workerPort.onerror = (e: ErrorEvent) => {
  hilog.info(0x0000, 'testTag', '%{public}s', 'onerror');
}
```

## sendableContextManager.convertToAbilityStageContext

convertToAbilityStageContext(sendableContext: SendableContext): common.AbilityStageContext

将SendableContext对象转换为AbilityStageContext。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------- | ------- | ------- | ------- |
| sendableContext | [SendableContext](js-apis-inner-application-sendableContext.md) | 是 | SendableContext对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ------- |
| 401     | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed. |

**示例：**

主线程传递Context：
```ts
import { UIAbility, sendableContextManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { worker } from '@kit.ArkTS';

@Sendable
export class SendableObject {
  constructor(sendableContext: sendableContextManager.SendableContext, contextName: string) {
    this.sendableContext = sendableContext;
    this.contextName = contextName;
  }

  sendableContext: sendableContextManager.SendableContext;
  contextName: string;
}

export default class EntryAbility extends UIAbility {
  worker: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/Worker.ets');

  onCreate(): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'AbilityStage onCreate');

    // convert and post
    try {
      let sendableContext: sendableContextManager.SendableContext = sendableContextManager.convertFromContext(this.context);
      let object: SendableObject = new SendableObject(sendableContext, 'AbilityStageContext');
      hilog.info(0x0000, 'testTag', '%{public}s', 'AbilityStage post message');
      this.worker.postMessageWithSharedSendable(object);
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'convertFromContext failed %{public}s', JSON.stringify(error));
    }
  }
}
```

Worker线程接收Context：
```ts
import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
import { common, sendableContextManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Sendable
export class SendableObject {
  constructor(sendableContext: sendableContextManager.SendableContext, contextName: string) {
    this.sendableContext = sendableContext;
    this.contextName = contextName;
  }

  sendableContext: sendableContextManager.SendableContext;
  contextName: string;
}

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

workerPort.onmessage = (e: MessageEvents) => {
  let object: SendableObject = e.data;
  let sendableContext: sendableContextManager.SendableContext = object.sendableContext;
  if (object.contextName == 'AbilityStageContext') {
    hilog.info(0x0000, 'testTag', '%{public}s', 'convert to abilitystage context.');
    try {
      let context: common.AbilityStageContext = sendableContextManager.convertToAbilityStageContext(sendableContext);
      // 获取context后获取沙箱路径
      hilog.info(0x0000, 'testTag', 'worker context.databaseDir: %{public}s', context.databaseDir);
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'convertToAbilityStageContext failed %{public}s', JSON.stringify(error));
    }
  }
}

workerPort.onmessageerror = (e: MessageEvents) => {
  hilog.info(0x0000, 'testTag', '%{public}s', 'onmessageerror');
}

workerPort.onerror = (e: ErrorEvent) => {
  hilog.info(0x0000, 'testTag', '%{public}s', 'onerror');
}
```

## sendableContextManager.convertToUIAbilityContext

convertToUIAbilityContext(sendableContext: SendableContext): common.UIAbilityContext

将SendableContext对象转换为UIAbilityContext。

**系统能力**：以下各项对应的系统能力均为SystemCapability.Ability.AbilityRuntime.Core

**原子化服务API：** 从API version 12开始，该接口支持在原子化服务中使用。

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| ------- | ------- | ------- | ------- |
| sendableContext | [SendableContext](js-apis-inner-application-sendableContext.md) | 是 | SendableContext对象。 |

**错误码**：

以下错误码详细介绍请参考[通用错误码](../errorcode-universal.md)。

| 错误码ID | 错误信息 |
| ------- | ------- |
| 401     | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed. |

**示例：**

主线程传递Context：
```ts
import { AbilityConstant, UIAbility, Want, common, sendableContextManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';
import { worker } from '@kit.ArkTS';

@Sendable
export class SendableObject {
  constructor(sendableContext: sendableContextManager.SendableContext, contextName: string) {
    this.sendableContext = sendableContext;
    this.contextName = contextName;
  }

  sendableContext: sendableContextManager.SendableContext;
  contextName: string;
}

export default class EntryAbility extends UIAbility {
  worker: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/Worker.ets');

  onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
    hilog.info(0x0000, 'testTag', '%{public}s', 'Ability onCreate');

    // convert and post
    try {
      let sendableContext: sendableContextManager.SendableContext = sendableContextManager.convertFromContext(this.context);
      let object: SendableObject = new SendableObject(sendableContext, 'EntryAbilityContext');
      hilog.info(0x0000, 'testTag', '%{public}s', 'Ability post message');
      this.worker.postMessageWithSharedSendable(object);
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'convertFromContext failed %{public}s', JSON.stringify(error));
    }
  }
}
```

Worker线程接收Context：
```ts
import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
import { common, sendableContextManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

@Sendable
export class SendableObject {
  constructor(sendableContext: sendableContextManager.SendableContext, contextName: string) {
    this.sendableContext = sendableContext;
    this.contextName = contextName;
  }

  sendableContext: sendableContextManager.SendableContext;
  contextName: string;
}

const workerPort: ThreadWorkerGlobalScope = worker.workerPort;

workerPort.onmessage = (e: MessageEvents) => {
  let object: SendableObject = e.data;
  let sendableContext: sendableContextManager.SendableContext = object.sendableContext;
  if (object.contextName == 'EntryAbilityContext') {
    hilog.info(0x0000, 'testTag', '%{public}s', 'convert to uiability context.');
    try {
      let context: common.UIAbilityContext = sendableContextManager.convertToUIAbilityContext(sendableContext);
      // 获取context后获取沙箱路径
      hilog.info(0x0000, 'testTag', 'worker context.databaseDir: %{public}s', context.databaseDir);
    } catch (error) {
      hilog.error(0x0000, 'testTag', 'convertToUIAbilityContext failed %{public}s', JSON.stringify(error));
    }
  }
}

workerPort.onmessageerror = (e: MessageEvents) => {
  hilog.info(0x0000, 'testTag', '%{public}s', 'onmessageerror');
}

workerPort.onerror = (e: ErrorEvent) => {
  hilog.info(0x0000, 'testTag', '%{public}s', 'onerror');
}
```
