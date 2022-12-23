# @ohos.application.errorManager

The **ErrorManager** module provides APIs for registering and deregistering error observers.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import
```ts
import errorManager from '@ohos.application.errorManager'
```

## ErrorManager.registerErrorObserver

registerErrorObserver(observer: ErrorObserver): number;

Registers an error observer.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**
 
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| observer | [ErrorObserver](js-apis-inner-application-errorObserver.md) | Yes| Numeric code of the observer.|

**Example**
    
```ts
var observer = {
    onUnhandledException(errorMsg) {
        console.log('onUnhandledException, errorMsg: ', errorMsg)
    }
}
errorManager.registerErrorObserver(observer)
```

## ErrorManager.unregisterErrorObserver

unregisterErrorObserver(observerId: number,  callback: AsyncCallback\<void>): void;

Deregisters an error observer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**
 
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| observerId | number | Yes| Numeric code of the observer.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**
    
```ts
var observerId = 100;

function unregisterErrorObserverCallback(err) {
    if (err) {
        console.log('------------ unregisterErrorObserverCallback ------------', err);
    }
}
errorManager.unregisterErrorObserver(observerId, unregisterErrorObserverCallback);

```

## ErrorManager.unregisterErrorObserver

unregisterErrorObserver(observerId: number): Promise\<void>;

Deregisters an error observer. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**
 
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| observerId | number | Yes| Numeric code of the observer.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise used to return the result.|

**Example**
    
```ts
var observerId = 100;
errorManager.unregisterErrorObserver(observerId)
.then((data) => {
    console.log('----------- unregisterErrorObserver success ----------', data);
})
.catch((err) => {
    console.log('----------- unregisterErrorObserver fail ----------', err);
})

```
