# ErrorObserver

The **ErrorObserver** module defines an observer to listen for application errors. It can be used as an input parameter in [registerErrorObserver](js-apis-application-errorManager.md#errormanagerregistererrorobserver) to listen for errors that occur in the current application.

## onUnhandledException

onUnhandledException(errMsg: string): void;

Called when an unhandled exception occurs in the JS runtime.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**

| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| errMsg | string | No| Message and error stack trace about the exception.|

**Example**

```ts
import errorManager from '@ohos.application.errorManager';

let observer = {
    onUnhandledException(errorMsg) {
        console.log('onUnhandledException, errorMsg: ' + JSON.stringify(errorMsg));
    }
};
errorManager.registerErrorObserver(observer);
```
