# ArkCompiler Subsystem Changelog

## cl.arkcompiler.1 Compilation Check Enhanced for ArkTS Sendable and Shared Syntax Rules

**Access Level**

Other

**Reason for Change**

A sendable object must comply with the [usage rules](../../..//application-dev/arkts-utils/arkts-sendable.md#sendable-usage-rules), and a shared module must comply with the [specifications](../../..//application-dev/arkts-utils/arkts-sendable-module.md#specifications). In export scenarios where some constraints should be made, the compiler does not check for the restrictions. As a result, a runtime exception occurs, but no compilation error is reported. In this version update, a compile-time check is added for these constraints. You can find the code that fails to meet the sendable and shared module usage constraints earlier through compile-time errors or warnings, reducing fault locating costs at the runtime.

**Change Impact**

This change is a compatible change.


Before change:
1. When the export default someVariable mode is used in the shared module to export a variable of the non-sendable type, an error message is displayed on the DevEco Studio editing page, but no compilation error is reported, and the program breaks down at the runtime.
2. When the export type someType = someNonSendableType mode is used in the shared module to export an alias of the non-sendable type, no error message is displayed on the DevEco Studio editing page, and no compilation exception is reported.
3. When the sendable class internally uses the sendable class object exported from the top level of the current module, no error message is displayed on the DevEco Studio editing page, no compilation exception is reported, but an exception occurs at the runtime.

After change:
1. When the export default someVariable mode is used in the shared module to export a variable of the non-sendable type, an error message is displayed on the DevEco Studio editing page, and a compilation error is reported.
2. When the export type someType = someNonSendableType mode is used in the shared module to export an alias of the non-sendable type, a warning message is displayed on the DevEco Studio editing page, and a compilation warning is reported.
3. When the sendable class uses the sendable class object exported from the top level of the current module, a warning message is displayed on the DevEco Studio editing page, and a compilation warning is reported.


Example scenarios:

Constraints on export of the Shared Module

Scenario 1: The export default someVariable mode is used in the shared module to export a variable of the non-sendable type. Impact: The change is a compatibility change. Before the change, the program crashes. After the change, a compilation error is reported.

Before change:

```ts
'use shared';
class NonSendableClass {};
export default NonSendableClass; // The program crashes during GC.
```

After change:

```ts
'use shared';
class NonSendableClass {};
export default NonSendableClass; // Compilation error.
```

Scenario 2: The export type someType = someNonSendableType mode is used in the shared module to export an alias of the non-sendable type. Impact: The change is a compatibility change. Before the change, no message is displayed. After the change, a warning is displayed on the editing page, and a compilation warning is displayed.

Before change:

```ts
'use shared';
class NonSendableClass {};
export type NonSendableAlias = NonSendableClass;
```

After change:

```ts
'use shared';
class NonSendableClass {};
export type NonSendableAlias = NonSendableClass; // Warning on the DevEco Studio editing page and compilation warning
```

Constraints on Variables in the sendable Class

Scenario 1: The sendable class uses the sendable class object exported from the top level of the current module. Impact: The change is a compatibility change. Before the change, a runtime error is reported. After the change, a warning is displayed on the editing page, and a compilation warning is displayed.

Before change:

```ts
import { taskpool } from '@kit.ArkTS';

@Sendable
export class SendableData {};

@Sendable
class SendableClass {
    handle():void {
      new SendableData(); // Runtime exception.
    }
}

@Concurrent
async function taskHandle(sendable: SendableClass) {
  sendable.handle();
}

taskpool.execute(new taskpool.Task(taskHandle, new SendableClass()));
```

After change:

```ts
import { taskpool } from '@kit.ArkTS';

@Sendable
export class SendableData {};

@Sendable
class SendableClass {
    handle():void {
      new SendableData(); // Warning on the DevEco Studio editing page and compilation warning
    }
}

@Concurrent
async function taskHandle(sendable: SendableClass) {
  sendable.handle();
}

taskpool.execute(new taskpool.Task(taskHandle, new SendableClass()));
```

**Start API Level**

API version 12

**Change Since**

OpenHarmony SDK 5.0.0.36

**Key API/Component Changes**

N/A

**Adaptation Guide**

You are advised to fix new warnings based on the sendable and shared module specifications to prevent runtime exceptions.
