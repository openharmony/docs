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

The Context here is different from that created by [createModuleContext](js-apis-inner-application-context.md#contextcreatemodulecontext). The differences are as follows:
- Context involved in the conversion: ArkTS concurrent instances hold different application-side Context instances that correspond to the same underlying Context object. When the Context properties and methods in an instance are modified, the Context properties and methods in the related instances are modified accordingly. The eventHub attribute in the Context instance is special. The eventHub objects in different instances are independent from each other and cannot be used across ArkTS instances.
- Context created using [createModuleContext](js-apis-inner-application-context.md#contextcreatemodulecontext): ArkTS concurrent instances hold different application-side Context objects that correspond to different underlying Context objects.

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

convertFromContext(context: common.Context): SendableContext;

Converts a **Context** object to a **SendableContext** object.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Atomic service API**: This API can be used in atomic services since API version 12.

**Parameters**

| Name| Type| Mandatory| Description|
| ------- | ------- | ------- | ------- |
| context | common.Context | Yes| **Context** object, which supports the base class **Context** and the child classes **ApplicationContext**, **AbilityStageContext**, and **UIAbilityContext**.|

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
