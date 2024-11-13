# LoopObserver

The LoopObserver module defines an observer to listen for event processing timeout. It can be used as an input parameter in [ErrorManager.on](./js-apis-app-ability-errorManager.md#errormanageronerror) to listen for the event processing time of the current application's main thread.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { errorManager } from '@kit.AbilityKit';
```

## LoopObserver.onLoopTimeOut

onLoopTimeOut?(timeout: number): void

Called when a timeout occurs for the main thread to process an event in the JS runtime.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| timeout | number | Yes| Actual execution time of the main thread.|

**Example**

```ts
import { errorManager } from '@kit.AbilityKit';

let observer: errorManager.LoopObserver = {
  onLoopTimeOut(timeout: number) {
    console.log('Duration timeout: ' + timeout);
  }
};

errorManager.on("loopObserver", 1, observer);
```
