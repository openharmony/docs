# ErrorObserver

The **ErrorObserver** module defines an observer to listen for application errors. It can be used as an input parameter in [ErrorManager.on](js-apis-app-ability-errorManager.md#errormanageron) to listen for errors that occur in the current application.

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
    console.log('onUnhandledException, errorMsg: ', errorMsg);
  }
};

try {
    errorManager.on('error', observer);
} catch (error) {
    console.log('registerErrorObserver failed, error.code: ${JSON.stringify(error.code)}, error.message: ${JSON.stringify(error.message)}');
}
```
