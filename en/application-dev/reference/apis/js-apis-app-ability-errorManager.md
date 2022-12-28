# @ohos.app.ability.errorManager

The **ErrorManager** module provides APIs for registering and deregistering error observers.

> **NOTE**
> 
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import
```
import errorManager from '@ohos.app.ability.errorManager'
```

## ErrorManager.on

on(type: "error", observer: ErrorObserver): number;

Registers an error observer.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**
 
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Type of the API to call.|
| observer | [ErrorObserver](./js-apis-inner-application-errorObserver.md) | Yes| Numeric code of the observer.|

**Example**
    
```js
var observer = {
    onUnhandledException(errorMsg) {
        console.log('onUnhandledException, errorMsg: ', errorMsg)
    }
}
try {
    errorManager.on("error", observer);
} catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
}
```

## ErrorManager.off

off(type: "error", observerId: number,  callback: AsyncCallback\<void>): void;

Deregisters an error observer. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**
 
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Type of the API to call.|
| observerId | number | Yes| Numeric code of the observer.|
| callback | AsyncCallback\<void> | Yes| Callback used to return the result.|

**Example**
    
```js
var observerId = 100;

function unregisterErrorObserverCallback(err) {
    if (err) {
        console.log('------------ unregisterErrorObserverCallback ------------', err);
    }
}
try {
    errorManager.off("error", observerId, unregisterErrorObserverCallback);
} catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
}
```

## ErrorManager.off

off(type: "error", observerId: number): Promise\<void>;

Deregisters an error observer. This API uses a promise to return the result.

**System capability**: SystemCapability.Ability.AbilityRuntime.Core

**Parameters**
 
| Name| Type| Mandatory| Description|
| -------- | -------- | -------- | -------- |
| type | string | Yes| Type of the API to call.|
| observerId | number | Yes| Numeric code of the observer.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise\<void> | Promise used to return the result.|

**Example**
    
```js
var observerId = 100;
try {
    errorManager.off("error", observerId)
        .then((data) => {
            console.log('----------- unregisterErrorObserver success ----------', data);
        })
        .catch((err) => {
            console.log('----------- unregisterErrorObserver fail ----------', err);
    })
} catch (paramError) {
    console.log("error: " + paramError.code + ", " + paramError.message);
}

```
