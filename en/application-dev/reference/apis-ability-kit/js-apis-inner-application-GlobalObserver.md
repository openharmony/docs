# GlobalObserver

The GlobalObserver module defines an exception observer. It can be used as an input parameter in [ErrorManager.on('globalErrorOccurred')](./js-apis-app-ability-errorManager.md#errormanageronglobalerroroccurred16) and [ErrorManager.on('globalUnhandledRejectionDetected')](./js-apis-app-ability-errorManager.md#errormanageronglobalunhandledrejectiondetected16) to listen for event processing of the current application's main thread.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 16. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { errorManager } from '@kit.AbilityKit';
```

## Properties

**Atomic service API**: This API can be used in atomic services since API version 16.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| reason | GlobalError | Yes| Object related to the exception event name, message, error stack information, exception thread name, and exception thread type.|

**Example**

```ts
import { errorManager } from '@kit.AbilityKit';

function errorFunc(observer: errorManager.GlobalObserver) {
    console.log("result name :" + observer.name);
    console.log("result message :" + observer.message);
    console.log("result stack :" + observer.stack);
    console.log("result instanceName :" + observer.instanceName);
    console.log("result instaceType :" + observer.instanceType);
}

errorManager.off('globalErrorOccurred', errorFunc)
```
