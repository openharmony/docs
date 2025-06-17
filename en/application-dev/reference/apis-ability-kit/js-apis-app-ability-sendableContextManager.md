# @ohos.app.ability.sendableContextManager (sendableContextManager)

The sendableContextManager module provides APIs for converting between Context and [SendableContext](js-apis-inner-application-sendableContext.md) objects.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> - The APIs of this module can be used only in the stage model.

## When to Use

This module is used to transfer data between concurrent ArkTS instances (including the main thread and the worker thread of TaskPool or Worker).

For example, when transferring sendable data from the main thread to a child thread, the following conversion steps are involved to ensure efficient data transfer:
- Conversion from Context to SendableContext for the main thread to transfer sendable data to the child thread.
- Conversion from SendableContext to Context for the child thread to use the sendable data.

The Context here is different from that created by [createModuleContext](./js-apis-app-ability-application.md#applicationcreatemodulecontext12). The differences are as follows:
- Context involved in the conversion: ArkTS concurrent instances hold different application-side Context instances that correspond to the same underlying Context object. When the Context properties and methods in an instance are modified, the Context properties and methods in the related instances are modified accordingly. The eventHub attribute in the Context instance is special. The eventHub objects in different instances are independent from each other and cannot be used across ArkTS instances. If you want to use [EventHub](./js-apis-inner-application-eventHub.md) to transfer data across instances, call [setEventHubMultithreadingEnabled](#sendablecontextmanagerseteventhubmultithreadingenabled20) to enable the cross-thread data transfer feature.


- Context created using [createModuleContext](./js-apis-app-ability-application.md#applicationcreatemodulecontext12): ArkTS concurrent instances hold different application-side Context objects that correspond to different underlying Context objects.

## Constraints

The Context types used in the conversion must be the same. Currently, the following types of Context support conversion: [Context](js-apis-inner-application-context.md), [ApplicationContext](js-apis-inner-application-applicationContext.md), [AbilityStageContext](js-apis-inner-application-abilityStageContext.md), and [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md).

## Modules to Import

```ts
import { sendableContextManager } from '@kit.AbilityKit';
```

## Properties

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

| Name| Type| Mandatory| Description|
| ------- | ------- | ------- | ------- |
| SendableContext | [SendableContext](js-apis-inner-application-sendableContext.md) | Yes| Level-2 module **SendableContext**.|

**Example**

```ts
import { sendableContextManager } from '@kit.AbilityKit';

let sendableContext: sendableContextManager.SendableContext;
```

## sendableContextManager.convertFromContext

convertFromContext(context: common.Context): SendableContext

Converts a **Context** object to a **SendableContext** object.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------- | ------- | ------- |
| context | [common.Context](js-apis-inner-application-context.md) | Yes| Context object. The Context base class, and its child classes [ApplicationContext](js-apis-inner-application-applicationContext.md), [AbilityStageContext](js-apis-inner-application-abilityStageContext.md), and [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md) are supported.|

**Return value**

| Type| Description|
| -------- | -------- |
| SendableContext | [SendableContext](js-apis-inner-application-sendableContext.md) object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ------- |
| 401     | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed. |

**Example**

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

Converts a **SendableContext** object to a **Context** object.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------- | ------- | ------- |
| sendableContext | [SendableContext](js-apis-inner-application-sendableContext.md) | Yes| **SendableContext** object.|

**Return value**

| Type| Description|
| -------- | -------- |
| common.Context | [Context](js-apis-inner-application-context.md) object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ------- |
| 401     | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed. |

**Example**

Context passed by the main thread:
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

Context received by the Worker thread:
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
      // Obtain the sandbox path after obtaining the Context object.
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

Converts a **SendableContext** object to an **ApplicationContext** object.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------- | ------- | ------- |
| sendableContext | [SendableContext](js-apis-inner-application-sendableContext.md) | Yes| **SendableContext** object.|

**Return value**

| Type| Description|
| -------- | -------- |
| common.ApplicationContext | [ApplicationContext](js-apis-inner-application-applicationContext.md) object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ------- |
| 401     | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed. |

**Example**

Context passed by the main thread:
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

Context received by the Worker thread:
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
      // Obtain the sandbox path after obtaining the Context object.
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

Converts a **SendableContext** object to an **AbilityStageContext** object.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------- | ------- | ------- |
| sendableContext | [SendableContext](js-apis-inner-application-sendableContext.md) | Yes| **SendableContext** object.|

**Return value**

| Type| Description|
| -------- | -------- |
| common.AbilityStageContext | [AbilityStageContext](js-apis-inner-application-abilityStageContext.md) object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ------- |
| 401     | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed. |

**Example**

Context passed by the main thread:
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

Context received by the Worker thread:
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
      // Obtain the sandbox path after obtaining the Context object.
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

Converts a **SendableContext** object to a **UIAbilityContext** object.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------- | ------- | ------- |
| sendableContext | [SendableContext](js-apis-inner-application-sendableContext.md) | Yes| **SendableContext** object.|

**Return value**

| Type| Description|
| -------- | -------- |
| common.UIAbilityContext | [UIAbilityContext](js-apis-inner-application-uiAbilityContext.md) object.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| ------- | ------- |
| 401     | If the input parameter invalid. Possible causes: 1.Incorrect parameter types; 2.Parameter verification failed. |

**Example**

Context passed by the main thread:
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

Context received by the Worker thread:
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
      // Obtain the sandbox path after obtaining the Context object.
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
## sendableContextManager.setEventHubMultithreadingEnabled<sup>20+<sup>

setEventHubMultithreadingEnabled(context: common.Context, enabled: boolean): void

Enables the cross-thread data transfer feature of [EventHub](./js-apis-inner-application-eventHub.md) in a [Context](js-apis-inner-application-context.md) object.

> **NOTE**
> 
> - When multiple Context objects communicate, you need to call this API to set each Context object to support EventHub cross-thread data transfer.
> - Before this API is called, data is passed by reference. After this API is called, data is passed through serialization, which means that the data of the sender thread is independent of that of the receiver thread.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 20.

**Parameters**

| Name | Type          | Mandatory| Description                                                        |
| ------- | -------------- | ---- | ------------------------------------------------------------ |
| context | [common.Context](js-apis-inner-application-context.md) | Yes  | Context object. For details about the serialization data types supported by Eventhub, see [Sequenceable Data Types](../apis-arkts/js-apis-taskpool.md#sequenceable-data-types). The data size cannot exceed 16 MB.|
| enabled  | boolean        | Yes  | Whether to enable the cross-thread data transfer feature. The value **true** means to enable the feature, and **false** means the opposite.                               |

**Example**

Enable the cross-thread data transfer feature of [EventHub](./js-apis-inner-application-eventHub.md) in a [Context](./js-apis-inner-application-context.md) object in the main thread, convert the Context object to a [SenableContext](js-apis-inner-application-sendableContext.md) object, and send the SendableContext object to the [Worker](../apis-arkts/js-apis-worker.md) thread.

```ts
import { common, sendableContextManager } from '@kit.AbilityKit';
import { worker } from '@kit.ArkTS';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

@Sendable
export class SendableObject {
  constructor(sendableContext: sendableContextManager.SendableContext, contextName: string) {
    this.sendableContext = sendableContext;
    this.contextName = contextName;
  }

  sendableContext: sendableContextManager.SendableContext;
  contextName: string;
}

@Entry
@Component
struct Index {
  @State context: common.Context | undefined = this.getUIContext().getHostContext();
  worker1: worker.ThreadWorker = new worker.ThreadWorker('entry/ets/workers/Worker.ets');

  aboutToAppear(): void {
    let context: common.Context = this.context as common.Context;
    context.eventHub.on('event1', this.eventFunc);
    context.eventHub.emit('event1', 'xingming', 22);
  }

  eventFunc(name: string, age: number) {
    hilog.info(DOMAIN, 'testTag', 'name %{public}s age %{public}d', name, age);
  }

  build() {
    Column() {
      Row() {
        Button('thread 1')
          .size({ width: 100, height: 100 })
          .onClick(() => {
            if (this.context == undefined) {
              return;
            }
            sendableContextManager.setEventHubMultithreadingEnabled(this.context, true);
            let sendableContext: sendableContextManager.SendableContext =
              sendableContextManager.convertFromContext(this.context);
            let object: SendableObject = new SendableObject(sendableContext, 'BaseContext');
            this.worker1.postMessageWithSharedSendable(object);
          })
      }
    }
  }
}
```

After receiving the [SendableContext](js-apis-inner-application-sendableContext.md) object in the [Worker](../apis-arkts/js-apis-worker.md) thread, convert it to a [Context](./js-apis-inner-application-context.md) object. Then, enable the cross-thread data transfer feature of [EventHub](./js-apis-inner-application-eventHub.md) in the Context object in the Worker thread, and send a message back to the main thread using this feature.

```ts
import { ErrorEvent, MessageEvents, ThreadWorkerGlobalScope, worker } from '@kit.ArkTS';
import { common, sendableContextManager } from '@kit.AbilityKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

const DOMAIN = 0x0000;

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
    try {
      let context: common.Context = sendableContextManager.convertToContext(sendableContext);
      sendableContextManager.setEventHubMultithreadingEnabled(context, true);
      context.eventHub.emit('event1', 'xingming', 40);
    } catch (error) {
      hilog.error(DOMAIN, 'testTag', 'convertToContext failed %{public}s', JSON.stringify(error));
    }
  }
};

workerPort.onmessageerror = (e: MessageEvents) => {
  hilog.error(DOMAIN, 'testTag', '%{public}s', 'onmessageerror');
};

workerPort.onerror = (e: ErrorEvent) => {
  hilog.error(DOMAIN, 'testTag', '%{public}s', 'onerror');
};
```
