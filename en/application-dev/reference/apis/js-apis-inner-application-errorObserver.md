# ErrorObserver

The **ErrorObserver** module defines an observer to listen for application errors. It can be used as an input parameter in [errorManager.on](js-apis-app-ability-errorManager.md#errormanageron) to listen for errors that occur in the current application.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import errorManager from '@ohos.app.ability.errorManager';
```

## ErrorObserver.onUnhandledException

onUnhandledException(errMsg: string): void;

Called when an unhandled exception occurs in the JS runtime.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| errMsg | string | No| Message and error stack trace about the exception.|

**Example**

```ts
import errorManager from '@ohos.app.ability.errorManager';

let observer = {
  onUnhandledException(errorMsg) {
    console.error('onUnhandledException, errorMsg: ', errorMsg);
  }
};

try {
    errorManager.on('error', observer);
} catch (error) {
    console.error('registerErrorObserver failed, error.code: ${error.code}, error.message: ${error.message}');
}
```
```
