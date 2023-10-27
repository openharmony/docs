# @ohos.data.preferences (User Preferences)

The **Preferences** module provides APIs for processing data in the form of key-value (KV) pairs, and supports persistence of the KV pairs when required, as well as modification and query of the data.

The key is of the string type, and the value can be a number, a string, a Boolean value, or an array of numbers, strings, or Boolean values.


> **NOTE**
>
> The initial APIs of this module are supported since API version 9. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```ts
import data_preferences from '@ohos.data.preferences';
```

## Constants

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

| Name            | Type| Readable| Writable| Description                                   |
| ---------------- | -------- | ---- | ---- | --------------------------------------- |
| MAX_KEY_LENGTH   | number   | Yes  | No  | Maximum length of a key, which is 80 bytes.    |
| MAX_VALUE_LENGTH | number   | Yes  | No  | Maximum length of a value, which is 8192 bytes.|


## data_preferences.getPreferences

getPreferences(context: Context, name: string, callback: AsyncCallback&lt;Preferences&gt;): void

Obtains a **Preferences** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                                            | Mandatory| Description                                                        |
| -------- | ------------------------------------------------ | ---- | ------------------------------------------------------------ |
| context  | Context            | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).                                                |
| name     | string                                           | Yes  | Name of the **Preferences** instance.                                     |
| callback | AsyncCallback&lt;[Preferences](#preferences)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and the **Preferences** instance obtained is returned. Otherwise, **err** is an error object.|

**Example**

FA model:

```ts
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base';

let context = featureAbility.getContext();
let preferences: data_preferences.Preferences | null = null;

try {
    data_preferences.getPreferences(context, 'myStore', (err: BusinessError, val: data_preferences.Preferences) => {
        if (err) {
            console.error("Failed to get preferences. code =" + err.code + ", message =" + err.message);
            return;
        }
        preferences = val;
        console.info("Succeeded in getting preferences.");
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to get preferences. code =" + code + ", message =" + message);
}
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base';
import window from '@ohos.window';

let preferences: data_preferences.Preferences | null = null;

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        try {
            data_preferences.getPreferences(this.context, 'myStore', (err: BusinessError, val: data_preferences.Preferences) => {
                if (err) {
                console.error("Failed to get preferences. code =" + err.code + ", message =" + err.message);
                return;
                }
                preferences = val;
                console.info("Succeeded in getting preferences.");
            })
        } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.error("Failed to get preferences. code =" + code + ", message =" + message);
        }
    }
}
```

## data_preferences.getPreferences

getPreferences(context: Context, name: string): Promise&lt;Preferences&gt;

Obtains a **Preferences** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type                                 | Mandatory| Description                   |
| ------- | ------------------------------------- | ---- | ----------------------- |
| context | Context | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).           |
| name    | string                                | Yes  | Name of the **Preferences** instance.|

**Return value**

| Type                                      | Description                              |
| ------------------------------------------ | ---------------------------------- |
| Promise&lt;[Preferences](#preferences)&gt; | Promise used to return the **Preferences** instance obtained.|

**Example**

FA model:

```ts
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base'

let context = featureAbility.getContext();

let preferences: data_preferences.Preferences | null = null;
try {
    let promise = data_preferences.getPreferences(context, 'myStore');
    promise.then((object: data_preferences.Preferences) => {
        preferences = object;
        console.info("Succeeded in getting preferences.");
    }).catch((err: BusinessError) => {
        console.error("Failed to get preferences. code =" + err.code + ", message =" + err.message);
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to get preferences. code =" + code + ", message =" + message);
}
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base'
import window from '@ohos.window';

let preferences: data_preferences.Preferences | null = null;

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        try {
            let promise = data_preferences.getPreferences(this.context, 'myStore');
            promise.then((object: data_preferences.Preferences) => {
                preferences = object;
                console.info("Succeeded in getting preferences.");
            }).catch((err: BusinessError) => {
                console.error("Failed to get preferences. code =" + err.code + ", message =" + err.message);
            })
        } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.error("Failed to get preferences. code =" + code + ", message =" + message);
        }
    }
}
```

## data_preferences.getPreferences<sup>10+</sup>

getPreferences(context: Context, options: Options, callback: AsyncCallback&lt;Preferences&gt;): void

Obtains a **Preferences** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                                         | Mandatory| Description                                                                                                                                                                          |
| -------- | --------------------------------------------- | ---- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| context  | Context                                       | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| options  | [Options](#options10)                              | Yes  | Configuration options of the **Preferences** instance.                                                                                                                                             |
| callback | AsyncCallback&lt;[Preferences](#preferences)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and the **Preferences** instance obtained is returned. Otherwise, **err** is an error object.                                                                                   |

**Error codes**

For details about the error codes, see [User Preference Error Codes](../errorcodes/errorcode-preferences.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 15501001 | Only supported in stage mode. |
| 15501002 | The data group id is not valid.     |

**Example**

FA model:

```ts
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base'

let context = featureAbility.getContext();
let preferences: data_preferences.Preferences | null = null;

try {
    let options: data_preferences.Options = { name: 'myStore', dataGroupId:'myId' };
    data_preferences.getPreferences(context, options, (err: BusinessError, val: data_preferences.Preferences) => {
        if (err) {
            console.error("Failed to get preferences. code =" + err.code + ", message =" + err.message);
            return;
        }
        preferences = val;
        console.info("Succeeded in getting preferences.");
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to get preferences. code =" + code + ", message =" + message);
}
```


Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base'
import window from '@ohos.window';

let preferences: data_preferences.Preferences | null = null;

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        try {
            let options: data_preferences.Options = { name: 'myStore', dataGroupId:'myId' };
            data_preferences.getPreferences(this.context, options, (err: BusinessError, val: data_preferences.Preferences) => {
                if (err) {
                    console.error("Failed to get preferences. code =" + err.code + ", message =" + err.message);
                    return;
                }
                preferences = val;
                console.info("Succeeded in getting preferences.");
            })
        } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.error("Failed to get preferences. code =" + code + ", message =" + message);
        }
    }
}
```

## data_preferences.getPreferences<sup>10+</sup>

getPreferences(context: Context, options: Options): Promise&lt;Preferences&gt;

Obtains a **Preferences** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type            | Mandatory| Description                                                                                                                                                                          |
| ------- | ---------------- | ---- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| context | Context          | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| options | [Options](#options10) | Yes  | Configuration options of the **Preferences** instance.                                                                                                                                             |

**Return value**

| Type                                   | Description                              |
| --------------------------------------- | ---------------------------------- |
| Promise&lt;[Preferences](#preferences)&gt; | Promise used to return the **Preferences** instance obtained.|

**Error codes**

For details about the error codes, see [User Preference Error Codes](../errorcodes/errorcode-preferences.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 15501001 | Only supported in stage mode. |
| 15501002 | The data group id is not valid.     |

**Example**

FA model:

```ts
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base'
let context = featureAbility.getContext();

let preferences: data_preferences.Preferences | null = null;
try {
    let options: data_preferences.Options =  { name: 'myStore' };
    let promise = data_preferences.getPreferences(context, options);
    promise.then((object: data_preferences.Preferences) => {
        preferences = object;
        console.info("Succeeded in getting preferences.");
    }).catch((err: BusinessError) => {
        console.error("Failed to get preferences. code =" + err.code + ", message =" + err.message);
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to get preferences. code =" + code + ", message =" + message);
}
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base'
import window from '@ohos.window';

let preferences: data_preferences.Preferences | null = null;

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        try {
            let options: data_preferences.Options =  { name: 'myStore', dataGroupId:'myId' };
            let promise = data_preferences.getPreferences(this.context, options);
            promise.then((object: data_preferences.Preferences) => {
                preferences = object;
                console.info("Succeeded in getting preferences.");
            }).catch((err: BusinessError) => {
                console.error("Failed to get preferences. code =" + err.code + ", message =" + err.message);
            })
        } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.error("Failed to get preferences. code =" + code + ", message =" + message);
        }
    }
}
```

## data_preferences.getPreferencesSync<sup>10+</sup>

getPreferencesSync(context: Context, options: Options): Preferences

Obtains the **Preferences** instance. This API is a synchronous interface.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type                 | Mandatory| Description                                                        |
| ------- | --------------------- | ---- | ------------------------------------------------------------ |
| context | Context               | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| options | [Options](#options10) | Yes  | Configuration options of the **Preferences** instance.                           |

**Return value**

| Type                       | Description                 |
| --------------------------- | --------------------- |
| [Preferences](#preferences) | **Preferences** instance obtained.|

**Error codes**

For details about the error codes, see [User Preference Error Codes](../errorcodes/errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------- |
| 15501001 | Only supported in stage mode.   |
| 15501002 | The data group id is not valid. |

**Example**

FA model:

```ts
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base'

let context = featureAbility.getContext();
let preferences: data_preferences.Preferences | null = null;

try {
    let options: data_preferences.Options =  { name: 'myStore' };
    preferences = data_preferences.getPreferencesSync(context, options);
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to get preferences. code =" + code + ", message =" + message);
}
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base'
import window from '@ohos.window';

let preferences: data_preferences.Preferences | null = null;

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        try {
            let options: data_preferences.Options = { name: 'myStore', dataGroupId:'myId' };
            preferences = data_preferences.getPreferencesSync(this.context, options);
        } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.error("Failed to get preferences. code =" + code + ", message =" + message);
        }
    }
}
```

## data_preferences.deletePreferences

deletePreferences(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

Deletes a **Preferences** instance from the cache. If the **Preferences** instance has a persistent file, the persistent file will also be deleted. This API uses an asynchronous callback to return the result.

After the **Preferences** instance is deleted, do not use it to perform data operations. Otherwise, data inconsistency may be caused. For this purpose, set the deleted **Preferences** instance to null. The system will reclaim the deleted **Preferences** instances in a unified manner.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                |
| -------- | ------------------------------------- | ---- | ---------------------------------------------------- |
| context  | Context | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).                                        |
| name     | string                                | Yes  | Name of the **Preferences** instance.                             |
| callback | AsyncCallback&lt;void&gt;             | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Error codes**

For details about the error codes, see [User Preference Error Codes](../errorcodes/errorcode-preferences.md).

| ID| Error Message                      |
| -------- | ------------------------------|
| 15500010 | Failed to delete preferences file. |

**Example**

FA model:

```ts
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base'

let context = featureAbility.getContext();

try {
    data_preferences.deletePreferences(context, 'myStore', (err: BusinessError) => {
        if (err) {
            console.error("Failed to delete preferences. code =" + err.code + ", message =" + err.message);
            return;
        }
        console.info("Succeeded in deleting preferences." );
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to delete preferences. code =" + code + ", message =" + message);
}
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base'
import window from '@ohos.window';

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        try {
            data_preferences.deletePreferences(this.context, 'myStore', (err: BusinessError) => {
                if (err) {
                    console.error("Failed to delete preferences. code =" + err.code + ", message =" + err.message);
                    return;
                }
                console.info("Succeeded in deleting preferences." );
            })
        } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.error("Failed to delete preferences. code =" + code + ", message =" + message);
        }
    }
}
```

## data_preferences.deletePreferences

deletePreferences(context: Context, name: string): Promise&lt;void&gt;

Deletes a **Preferences** instance from the cache. If the **Preferences** instance has a persistent file, the persistent file will also be deleted. This API uses a promise to return the result.

After the **Preferences** instance is deleted, do not use it to perform data operations. Otherwise, data inconsistency may be caused. For this purpose, set the deleted **Preferences** instance to null. The system will reclaim the deleted **Preferences** instances in a unified manner.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type                                 | Mandatory| Description                   |
| ------- | ------------------------------------- | ---- | ----------------------- |
| context | Context | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).           |
| name    | string                                | Yes  | Name of the **Preferences** instance.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [User Preference Error Codes](../errorcodes/errorcode-preferences.md).

| ID| Error Message                      |
| -------- | ------------------------------|
| 15500010 | Failed to delete preferences file. |

**Example**

FA model:

```ts
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base'

let context = featureAbility.getContext();

try {
    let promise = data_preferences.deletePreferences(context, 'myStore');
    promise.then(() => {
        console.info("Succeeded in deleting preferences.");
    }).catch((err: BusinessError) => {
        console.error("Failed to delete preferences. code =" + err.code + ", message =" + err.message);
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to delete preferences. code =" + code + ", message =" + message);
}
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base'
import window from '@ohos.window';

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        try{
            let promise = data_preferences.deletePreferences(this.context, 'myStore');
            promise.then(() => {
                console.info("Succeeded in deleting preferences.");
            }).catch((err: BusinessError) => {
                console.error("Failed to delete preferences. code =" + err.code + ", message =" + err.message);
            })
        } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.error("Failed to delete preferences. code =" + code + ", message =" + message);
        }
    }
}
```

## data_preferences.deletePreferences<sup>10+</sup>

deletePreferences(context: Context, options: Options, callback: AsyncCallback&lt;void&gt;): void

Deletes a **Preferences** instance from the cache. If the **Preferences** instance has a persistent file, the persistent file will also be deleted. This API uses an asynchronous callback to return the result.

After the **Preferences** instance is deleted, do not use it to perform data operations. Otherwise, data inconsistency may be caused. For this purpose, set the deleted **Preferences** instance to null. The system will reclaim the deleted **Preferences** instances in a unified manner.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                                                                                                                                          |
| -------- | ------------------------- | ---- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| context  | Context                   | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| options  | [Options](#options10)          | Yes  | Configuration options of the **Preferences** instance.                                                                                                                                             |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.                                                                                                                          |

**Error codes**

For details about the error codes, see [User Preference Error Codes](../errorcodes/errorcode-preferences.md).

| ID| Error Message                          |
| -------- | ---------------------------------- |
| 15500010 | Failed to delete preferences file. |
| 15501001 | Only supported in stage mode. |
| 15501002 | The data group id is not valid. |

**Example**

FA model:

```ts
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base'

let context = featureAbility.getContext();

try {
    let options: data_preferences.Options = { name: 'myStore' };
    data_preferences.deletePreferences(context, options, (err: BusinessError) => {
        if (err) {
            console.error("Failed to delete preferences. code =" + err.code + ", message =" + err.message);
            return;
        }
        console.info("Succeeded in deleting preferences." );
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to delete preferences. code =" + code + ", message =" + message);
}
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base'
import window from '@ohos.window';

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        try {
            let options: data_preferences.Options = { name: 'myStore', dataGroupId:'myId' };
            data_preferences.deletePreferences(this.context, options, (err: BusinessError) => {
                if (err) {
                    console.error("Failed to delete preferences. code =" + err.code + ", message =" + err.message);
                    return;
                }
                console.info("Succeeded in deleting preferences." );
            })
        } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.error("Failed to delete preferences. code =" + code + ", message =" + message);
        }
    }
}
```


## data_preferences.deletePreferences<sup>10+</sup>

deletePreferences(context: Context, options: Options): Promise&lt;void&gt;

Deletes a **Preferences** instance from the cache. If the **Preferences** instance has a persistent file, the persistent file will also be deleted. This API uses a promise to return the result.

After the **Preferences** instance is deleted, do not use it to perform data operations. Otherwise, data inconsistency may be caused. For this purpose, set the deleted **Preferences** instance to null. The system will reclaim the deleted **Preferences** instances in a unified manner.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type            | Mandatory| Description                                                                                                                                                                          |
| ------- | ---------------- | ---- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| context | Context          | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| options | [Options](#options10) | Yes  | Configuration options of the **Preferences** instance.                                                                                                                                             |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [User Preference Error Codes](../errorcodes/errorcode-preferences.md).

| ID| Error Message                          |
| -------- | ---------------------------------- |
| 15500010 | Failed to delete preferences file. |
| 15501001 | Only supported in stage mode. |
| 15501002 | The data group id is not valid. |

**Example**

FA model:

```ts
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base'

let context = featureAbility.getContext();

try {
    let options: data_preferences.Options = { name: 'myStore' };
    let promise = data_preferences.deletePreferences(context, options);
    promise.then(() => {
        console.info("Succeeded in deleting preferences.");
    }).catch((err: BusinessError) => {
        console.error("Failed to delete preferences. code =" + err.code + ", message =" + err.message);
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to delete preferences. code =" + code + ", message =" + message);
}
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base'
import window from '@ohos.window';

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        try{
            let options: data_preferences.Options = { name: 'myStore', dataGroupId:'myId' };
            let promise = data_preferences.deletePreferences(this.context, options);
            promise.then(() => {
                console.info("Succeeded in deleting preferences.");
            }).catch((err: BusinessError) => {
                console.error("Failed to delete preferences. code =" + err.code + ", message =" + err.message);
            })
        } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.error("Failed to delete preferences. code =" + code + ", message =" + message);
        }
    }
}
```


## data_preferences.removePreferencesFromCache

removePreferencesFromCache(context: Context, name: string, callback: AsyncCallback&lt;void&gt;): void

Removes a **Preferences** instance from the cache. This API uses an asynchronous callback to return the result.

After an application calls [getPreferences](#data_preferencesgetpreferences) for the first time to obtain a **Preferences** instance, the obtained **Preferences** instance is cached. When the application calls [getPreferences](#data_preferencesgetpreferences) again, the **Preferences** instance will be read from the cache instead of from the persistent file. After this API is called to remove the instance from the cache, calling **getPreferences** again will read data from the persistent file and create a new **Preferences** instance.

After the **Preferences** instance is removed, do not use it to perform data operations. Otherwise, data inconsistency may be caused. For this purpose, set the removed **Preferences** instance to null. The system will reclaim the removed **Preferences** instances in a unified manner.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                                 | Mandatory| Description                                                |
| -------- | ------------------------------------- | ---- | ---------------------------------------------------- |
| context  | Context | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).                                        |
| name     | string                                | Yes  | Name of the **Preferences** instance.                             |
| callback | AsyncCallback&lt;void&gt;             | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

FA model:

```ts
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base'

let context = featureAbility.getContext();
try {
    data_preferences.removePreferencesFromCache(context, 'myStore', (err: BusinessError) => {
        if (err) {
            console.error("Failed to remove preferences. code =" + err.code + ", message =" + err.message);
            return;
        }
        console.info("Succeeded in removing preferences.");
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to remove preferences. code =" + code + ", message =" + message);
}
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base'
import window from '@ohos.window';

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        try {
            data_preferences.removePreferencesFromCache(this.context, 'myStore', (err: BusinessError) => {
                if (err) {
                    console.error("Failed to remove preferences. code =" + err.code + ", message =" + err.message);
                    return;
                }
                console.info("Succeeded in removing preferences.");
            })
        } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.error("Failed to remove preferences. code =" + code + ", message =" + message);
        }
    }
}
```

## data_preferences.removePreferencesFromCache

removePreferencesFromCache(context: Context, name: string): Promise&lt;void&gt;

Removes a **Preferences** instance from the cache. This API uses a promise to return the result.

After an application calls [getPreferences](#data_preferencesgetpreferences) for the first time to obtain a **Preferences** instance, the obtained **Preferences** instance is cached. When the application calls [getPreferences](#data_preferencesgetpreferences) again, the **Preferences** instance will be read from the cache instead of from the persistent file. After this API is called to remove the instance from the cache, calling **getPreferences** again will read data from the persistent file and create a new **Preferences** instance.

After the **Preferences** instance is removed, do not use it to perform data operations. Otherwise, data inconsistency may be caused. For this purpose, set the removed **Preferences** instance to null. The system will reclaim the removed **Preferences** instances in a unified manner.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type                                 | Mandatory| Description                   |
| ------- | ------------------------------------- | ---- | ----------------------- |
| context | Context | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).           |
| name    | string                                | Yes  | Name of the **Preferences** instance.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

FA model:

```ts
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base'

let context = featureAbility.getContext();
try {
    let promise = data_preferences.removePreferencesFromCache(context, 'myStore');
    promise.then(() => {
        console.info("Succeeded in removing preferences.");
    }).catch((err: BusinessError) => {
        console.error("Failed to remove preferences. code =" + err.code + ", message =" + err.message);
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to remove preferences. code =" + code + ", message =" + message);
}
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base'
import window from '@ohos.window';

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        try {
            let promise = data_preferences.removePreferencesFromCache(this.context, 'myStore');
            promise.then(() => {
                console.info("Succeeded in removing preferences.");
            }).catch((err: BusinessError) => {
                console.error("Failed to remove preferences. code =" + err.code + ", message =" + err.message);
            })
        } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.error("Failed to remove preferences. code =" + code + ", message =" + message);
        }
    }
}
```

## data_preferences.removePreferencesFromCacheSync<sup>10+</sup>

removePreferencesFromCacheSync(context: Context, name: string): void

Removes a **Preferences** instance from the cache. This API returns the result synchronously.

After an application calls [getPreferences](#data_preferencesgetpreferences) for the first time to obtain a **Preferences** instance, the obtained **Preferences** instance is cached. When the application calls [getPreferences](#data_preferencesgetpreferences) again, the **Preferences** instance will be read from the cache instead of from the persistent file. After this API is called to remove the instance from the cache, calling **getPreferences** again will read data from the persistent file and create a new **Preferences** instance.

After the **Preferences** instance is removed, do not use it to perform data operations. Otherwise, data inconsistency may be caused. For this purpose, set the removed **Preferences** instance to null. The system will reclaim the removed **Preferences** instances in a unified manner.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type                                 | Mandatory| Description                   |
| ------- | ------------------------------------- | ---- | ----------------------- |
| context | Context | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).           |
| name    | string                                | Yes  | Name of the **Preferences** instance.|

**Example**

FA model:

```ts
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base'
let context = featureAbility.getContext();
try {
    data_preferences.removePreferencesFromCacheSync(context, 'myStore');
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to remove preferences. code =" + code + ", message =" + message);
}
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base'
import window from '@ohos.window';

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        try {
            data_preferences.removePreferencesFromCacheSync(this.context, 'myStore');
        } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.error("Failed to remove preferences. code =" + code + ", message =" + message);
        }
    }
}
```

## data_preferences.removePreferencesFromCache<sup>10+</sup>

removePreferencesFromCache(context: Context, options: Options, callback: AsyncCallback&lt;void&gt;): void

Removes a **Preferences** instance from the cache. This API uses an asynchronous callback to return the result.

After an application calls [getPreferences](#data_preferencesgetpreferences) for the first time to obtain a **Preferences** instance, the obtained **Preferences** instance is cached. When the application calls [getPreferences](#data_preferencesgetpreferences) again, the **Preferences** instance will be read from the cache instead of from the persistent file. After this API is called to remove the instance from the cache, calling **getPreferences** again will read data from the persistent file and create a new **Preferences** instance.

After the **Preferences** instance is removed, do not use it to perform data operations. Otherwise, data inconsistency may be caused. For this purpose, set the removed **Preferences** instance to null. The system will reclaim the removed **Preferences** instances in a unified manner.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                                                                                                                                          |
| -------- | ------------------------- | ---- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| context  | Context                   | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| options  | [Options](#options10)          | Yes  | Configuration options of the **Preferences** instance.                                                                                                                                             |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.                                                                                                                          |

**Error codes**

For details about the error codes, see [User Preference Error Codes](../errorcodes/errorcode-preferences.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 15501001 | Only supported in stage mode. |
| 15501002 | The data group id is not valid.     |

**Example**

FA model:

```ts
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base'
let context = featureAbility.getContext();
try {
    let options: data_preferences.Options = { name: 'myStore' };
    data_preferences.removePreferencesFromCache(context, options, (err: BusinessError) => {
        if (err) {
            console.error("Failed to remove preferences. code =" + err.code + ", message =" + err.message);
            return;
        }
        console.info("Succeeded in removing preferences.");
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to remove preferences. code =" + code + ", message =" + message);
}
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base'
import window from '@ohos.window';

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        try {
            let options: data_preferences.Options = { name: 'myStore', dataGroupId:'myId' };
            data_preferences.removePreferencesFromCache(this.context, options, (err: BusinessError) => {
                if (err) {
                    console.error("Failed to remove preferences. code =" + err.code + ", message =" + err.message);
                    return;
                }
                console.info("Succeeded in removing preferences.");
            })
        } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.error("Failed to remove preferences. code =" + code + ", message =" + message);
        }
    }
}
```

## data_preferences.removePreferencesFromCache<sup>10+</sup>

removePreferencesFromCache(context: Context, options: Options): Promise&lt;void&gt;

Removes a **Preferences** instance from the cache. This API uses a promise to return the result.

After an application calls [getPreferences](#data_preferencesgetpreferences) for the first time to obtain a **Preferences** instance, the obtained **Preferences** instance is cached. When the application calls [getPreferences](#data_preferencesgetpreferences) again, the **Preferences** instance will be read from the cache instead of from the persistent file. After this API is called to remove the instance from the cache, calling **getPreferences** again will read data from the persistent file and create a new **Preferences** instance.

After the **Preferences** instance is removed, do not use it to perform data operations. Otherwise, data inconsistency may be caused. For this purpose, set the removed **Preferences** instance to null. The system will reclaim the removed **Preferences** instances in a unified manner.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type            | Mandatory| Description                                                                                                                                                                          |
| ------- | ---------------- | ---- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| context | Context          | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| options | [Options](#options10) | Yes  | Configuration options of the **Preferences** instance.                                                                                                                                             |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [User Preference Error Codes](../errorcodes/errorcode-preferences.md).

| ID| Error Message                      |
| -------- | ------------------------------ |
| 15501001 | Only supported in stage mode. |
| 15501002 | The data group id is not valid.     |

**Example**

FA model:

```ts
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
import { BusinessError } from '@ohos.base'
let context = featureAbility.getContext();
try {
    let options: data_preferences.Options = { name: 'myStore' };
    let promise = data_preferences.removePreferencesFromCache(context, options);
    promise.then(() => {
        console.info("Succeeded in removing preferences.");
    }).catch((err: BusinessError) => {
        console.error("Failed to remove preferences. code =" + err.code + ", message =" + err.message);
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to remove preferences. code =" + code + ", message =" + message);
}
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import { BusinessError } from '@ohos.base'
import window from '@ohos.window';

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        try {
            let options: data_preferences.Options = { name: 'myStore', dataGroupId:'myId' };
            let promise = data_preferences.removePreferencesFromCache(this.context, options);
            promise.then(() => {
                console.info("Succeeded in removing preferences.");
            }).catch((err: BusinessError) => {
                console.error("Failed to remove preferences. code =" + err.code + ", message =" + err.message);
            })
        } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.error("Failed to remove preferences. code =" + code + ", message =" + message);
        }
    }
}
```

## data_preferences.removePreferencesFromCacheSync<sup>10+</sup>

removePreferencesFromCacheSync(context: Context, options: Options):void

Removes a **Preferences** instance from the cache. This API returns the result synchronously.

After an application calls [getPreferences](#data_preferencesgetpreferences) for the first time to obtain a **Preferences** instance, the obtained **Preferences** instance is cached. When the application calls [getPreferences](#data_preferencesgetpreferences) again, the **Preferences** instance will be read from the cache instead of from the persistent file. After this API is called to remove the instance from the cache, calling **getPreferences** again will read data from the persistent file and create a new **Preferences** instance.

After the **Preferences** instance is removed, do not use it to perform data operations. Otherwise, data inconsistency may be caused. For this purpose, set the removed **Preferences** instance to null. The system will reclaim the removed **Preferences** instances in a unified manner.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type                 | Mandatory| Description                                                        |
| ------- | --------------------- | ---- | ------------------------------------------------------------ |
| context | Context               | Yes  | Application context.<br>For details about the application context of the FA model, see [Context](js-apis-inner-app-context.md).<br>For details about the application context of the stage model, see [Context](js-apis-inner-application-uiAbilityContext.md).|
| options | [Options](#options10) | Yes  | Configuration options of the **Preferences** instance.                           |

**Error codes**

For details about the error codes, see [User Preference Error Codes](../errorcodes/errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------- |
| 15501001 | Only supported in stage mode.   |
| 15501002 | The data group id is not valid. |

**Example**

FA model:

```ts
// Obtain the context.
import featureAbility from '@ohos.ability.featureAbility';
let context = featureAbility.getContext();
try {
    let options: data_preferences.Options = { name: 'myStore' };
    data_preferences.removePreferencesFromCacheSync(context, options);
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to remove preferences. code =" + code + ", message =" + message);
}
```

Stage model:

```ts
import UIAbility from '@ohos.app.ability.UIAbility';
import window from '@ohos.window';

class EntryAbility extends UIAbility {
    onWindowStageCreate(windowStage: window.WindowStage) {
        try {
            let options: data_preferences.Options = { name: 'myStore', dataGroupId:'myId' };
            data_preferences.removePreferencesFromCacheSync(this.context, options);
        } catch (err) {
            let code = (err as BusinessError).code;
            let message = (err as BusinessError).message;
            console.error("Failed to remove preferences. code =" + code + ", message =" + message);
        }
    }
}
```

## Options<sup>10+</sup>

Represents the configuration options of a **Preferences** instance.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

| Name       | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| name        | string | Yes  | Name of the **Preferences** instance.                                     |
| dataGroupId | string | No  | Application group ID, which needs to be obtained from the AppGallery.<br>**Model restriction**: This attribute can be used only in the stage model.<br>This parameter is supported since API version 10. It specifies the **Preferences** instance created in the sandbox directory corresponding to the **dataGroupId**. If this parameter is not specified, the **Preferences** instance is created in the sandbox directory of the application.|

## Preferences

Provides APIs for obtaining and modifying the stored data.

Before calling any method of **Preferences**, you must obtain a **Preferences** instance by using [data_preferences.getPreferences](#data_preferencesgetpreferences).


### get

get(key: string, defValue: ValueType, callback: AsyncCallback&lt;ValueType&gt;): void

Obtains the value corresponding to the specified key from the cached **Preferences** instance. This API uses an asynchronous callback to return the result. If the value is null or is not of the default value type, **defValue** is returned.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                                        | Mandatory| Description                                                        |
| -------- | -------------------------------------------- | ---- | ------------------------------------------------------------ |
| key      | string                                       | Yes  | Key of the data to obtain. It cannot be empty.                             |
| defValue | [ValueType](#valuetype)                      | Yes  | Default value to be returned. The value can be a number, a string, a Boolean value, or an array of numbers, strings, or Boolean values.|
| callback | AsyncCallback&lt;[ValueType](#valuetype)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **data** is the value obtained. Otherwise, **err** is an error object.|

**Example**

```ts
try {
    preferences.get('startup', 'default', (err: BusinessError, val: data_preferences.ValueType) => {
        if (err) {
            console.error("Failed to get value of 'startup'. code =" + err.code + ", message =" + err.message);
            return;
        }
        console.info("Obtained the value of 'startup' successfully. val: " + val);
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to get value of 'startup'. code =" + code + ", message =" + message);
}
```


### get

get(key: string, defValue: ValueType): Promise&lt;ValueType&gt;

Obtains the value corresponding to the specified key from the cached **Preferences** instance. This API uses a promise to return the result. If the value is null or is not of the default value type, **defValue** is returned.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

 **Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| key      | string                  | Yes  | Key of the data to obtain. It cannot be empty.                             |
| defValue | [ValueType](#valuetype) | Yes  | Default value to be returned. The value can be a number, a string, a Boolean value, or an array of numbers, strings, or Boolean values.|

**Return value**

| Type                               | Description                         |
| ----------------------------------- | ----------------------------- |
| Promise<[ValueType](#valuetype)&gt; | Promise used to return the value obtained.|

**Example**

```ts
try {
    let promise = preferences.get('startup', 'default');
    promise.then((data: data_preferences.ValueType) => {
        console.info("Got the value of 'startup'. Data: " + data);
    }).catch((err: BusinessError) => {
        console.error("Failed to get value of 'startup'. code =" + err.code + ", message =" + err.message);
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to get value of 'startup'. code =" + code + ", message =" + message);
}
```

### getSync<sup>10+</sup>

getSync(key: string, defValue: ValueType): ValueType

Obtains the value corresponding to the specified key from the cached **Preferences** instance. This API returns the result synchronously. If the value is null or is not of the default value type, **defValue** is returned.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                   | Mandatory| Description                                                        |
| -------- | ----------------------- | ---- | ------------------------------------------------------------ |
| key      | string                  | Yes  | Key of the data to obtain. It cannot be empty.                             |
| defValue | [ValueType](#valuetype) | Yes  | Default value to be returned. The value can be a number, a string, a Boolean value, or an array of numbers, strings, or Boolean values.|

**Return value**

| Type                               | Description                         |
| ----------------------------------- | ----------------------------- |
| [ValueType](#valuetype) | Returns the value obtained.|

**Example**

```ts
try {
    let value: data_preferences.ValueType = preferences.getSync('startup', 'default');
    console.info("Succeeded in getting value of 'startup'. Data: " + value);
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to get value of 'startup'. code =" + code + ", message =" + message);
}
```

### getAll

getAll(callback: AsyncCallback&lt;Object&gt;): void;

Obtains all KV pairs from the cached **Preferences** instance. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                       | Mandatory| Description                                                        |
| -------- | --------------------------- | ---- | ------------------------------------------------------------ |
| callback | AsyncCallback&lt;Object&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined** and **value** provides all KV pairs obtained. Otherwise, **err** is an error object.|

**Example**

```ts
// There is no Object.keys in ArkTS, and the for..in... syntax cannot be used.
// If an error is reported, extract this API to a .ts file and expose it. Then import the API to the .ets file when required.
function getObjKeys(obj: Object): string[] {
  let keys = Object.keys(obj);
  return keys;
}

try {
    preferences.getAll((err: BusinessError, value: Object) => {
        if (err) {
            console.error("Failed to get all key-values. code =" + err.code + ", message =" + err.message);
            return;
        }
        let allKeys = getObjKeys(value);
        console.info("getAll keys = " + allKeys);
        console.info("getAll object = " + JSON.stringify(value));
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to get all key-values. code =" + code + ", message =" + message);
}
```


### getAll

getAll(): Promise&lt;Object&gt;

Obtains all KV pairs from the cached **Preferences** instance. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Return value**

| Type                 | Description                                       |
| --------------------- | ------------------------------------------- |
| Promise&lt;Object&gt; | Promise used to return the KV pairs obtained.|

**Example**

```ts
// There is no Object.keys in ArkTS, and the for..in... syntax cannot be used.
// If an error is reported, extract this API to a .ts file and expose it. Then import the API to the .ets file when required.
function getObjKeys(obj: Object): string[] {
  let keys = Object.keys(obj);
  return keys;
}

try {
    let promise = preferences.getAll();
    promise.then((value: Object) => {
        let allKeys = getObjKeys(value);
        console.info('getAll keys = ' + allKeys);
        console.info("getAll object = " + JSON.stringify(value));
    }).catch((err: BusinessError) => {
        console.error("Failed to get all key-values. code =" + err.code + ", message =" + err.message);
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to get all key-values. code =" + code + ", message =" + message);
}
```

### getAllSync<sup>10+</sup>

getAllSync(): Object

Obtains all KV pairs from the cached **Preferences** instance. This API returns the result synchronously.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Return value**

| Type                 | Description                                       |
| --------------------- | ------------------------------------------- |
| Object | Returns all KV pairs obtained.|

**Example**

```ts
// There is no Object.keys in ArkTS, and the for..in... syntax cannot be used.
// If an error is reported, extract this API to a .ts file and expose it. Then import the API to the .ets file when required.
function getObjKeys(obj: Object): string[] {
  let keys = Object.keys(obj);
  return keys;
}

try {
    let value = preferences.getAllSync();
    let allKeys = getObjKeys(value);
    console.info('getAll keys = ' + allKeys);
    console.info("getAll object = " + JSON.stringify(value));
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to get all key-values. code =" + code + ", message =" + message);
}
```

### put

put(key: string, value: ValueType, callback: AsyncCallback&lt;void&gt;): void

Writes data to the cached **Preferences** instance. This API uses an asynchronous callback to return the result. You can use [flush](#flush) to persist the **Preferences** instance.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                        |
| -------- | ------------------------- | ---- | ------------------------------------------------------------ |
| key      | string                    | Yes  | Key of the data. It cannot be empty.                               |
| value    | [ValueType](#valuetype)   | Yes  | Value to write. The value can be a number, a string, a Boolean value, or an array of numbers, strings, or Boolean values.|
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If data is written successfully, **err** is **undefined**. Otherwise, **err** is an error object.    |

**Example**

```ts
try {
    preferences.put('startup', 'auto', (err: BusinessError) => {
        if (err) {
            console.error("Failed to put value of 'startup'. code =" + err.code + ", message =" + err.message);
            return;
        }
        console.info("Successfully put the value of 'startup'.");
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to put value of 'startup'. code =" + code + ", message =" + message);
}
```


### put

put(key: string, value: ValueType): Promise&lt;void&gt;

Writes data to the cached **Preferences** instance. This API uses a promise to return the result. You can use [flush](#flush) to persist the **Preferences** instance.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type                   | Mandatory| Description                                                        |
| ------ | ----------------------- | ---- | ------------------------------------------------------------ |
| key    | string                  | Yes  | Key of the data. It cannot be empty.                               |
| value  | [ValueType](#valuetype) | Yes  | Value to write. The value can be a number, a string, a Boolean value, or an array of numbers, strings, or Boolean values.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
try {
    let promise = preferences.put('startup', 'auto');
    promise.then(() => {
        console.info("Successfully put the value of 'startup'.");
    }).catch((err: BusinessError) => {
        console.error("Failed to put value of 'startup'. code =" + err.code +", message =" + err.message);
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to put value of 'startup'. code =" + code +", message =" + message);
}
```


### putSync<sup>10+</sup>

putSync(key: string, value: ValueType): void

Writes data to the cached **Preferences** instance. This API returns the result synchronously. You can use [flush](#flush) to persist the **Preferences** instance.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type                   | Mandatory| Description                                                        |
| ------ | ----------------------- | ---- | ------------------------------------------------------------ |
| key    | string                  | Yes  | Key of the data. It cannot be empty.                               |
| value  | [ValueType](#valuetype) | Yes  | Value to write. The value can be a number, a string, a Boolean value, or an array of numbers, strings, or Boolean values.|

**Example**

```ts
try {
    preferences.putSync('startup', 'auto');
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to put value of 'startup'. code =" + code +", message =" + message);
}
```


### has

has(key: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the cached **Preferences** instance contains the KV pair of the given key. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                        | Mandatory| Description                                                        |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------ |
| key      | string                       | Yes  | Key of the data to check. It cannot be empty.                             |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the result. If the **Preferences** instance contains the KV pair, **true** will be returned. Otherwise, **false** will be returned.|

**Example**

```ts
try {
    preferences.has('startup', (err: BusinessError, val: boolean) => {
        if (err) {
            console.error("Failed to check the key 'startup'. code =" + err.code + ", message =" + err.message);
            return;
        }
        if (val) {
            console.info("The key 'startup' is contained.");
        } else {
            console.info("The key 'startup' is not contained.");
        }
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to check the key 'startup'. code =" + code + ", message =" + message);
}
```


### has

has(key: string): Promise&lt;boolean&gt;

Checks whether the cached **Preferences** instance contains the KV pair of the given key. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| key    | string | Yes  | Key of the data to check. It cannot be empty.|

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. If the **Preferences** instance contains the KV pair, **true** will be returned. Otherwise, **false** will be returned.|

**Example**

```ts
try {
    let promise = preferences.has('startup');
    promise.then((val: boolean) => {
        if (val) {
            console.info("The key 'startup' is contained.");
        } else {
            console.info("The key 'startup' is not contained.");
        }
    }).catch((err: BusinessError) => {
        console.error("Failed to check the key 'startup'. code =" + err.code + ", message =" + err.message);
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to check the key 'startup'. code =" + code + ", message =" + message);
}
```


### hasSync<sup>10+</sup>

hasSync(key: string): boolean

Checks whether the cached **Preferences** instance contains the KV pair of the given key. This API returns the result synchronously.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| key    | string | Yes  | Key of the data to check. It cannot be empty.|

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| boolean | If the **Preferences** instance contains the KV pair, **true** will be returned. Otherwise, **false** will be returned.|

**Example**

```ts
try {
    let isExist: boolean = preferences.hasSync('startup');
    if (isExist) {
        console.info("The key 'startup' is contained.");
    } else {
        console.info("The key 'startup' is not contained.");
    }
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to check the key 'startup'. code =" + code + ", message =" + message);
}
```


### delete

delete(key: string, callback: AsyncCallback&lt;void&gt;): void

Deletes the KV pair from the cached **Preferences** instance based on the specified key. This API uses an asynchronous callback to return the result. You can use [flush](#flush) to persist the **Preferences** instance.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                |
| -------- | ------------------------- | ---- | ---------------------------------------------------- |
| key      | string                    | Yes  | Key of the KV pair to delete. It cannot be empty.                     |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```ts
try {
    preferences.delete('startup', (err: BusinessError) => {
        if (err) {
            console.error("Failed to delete the key 'startup'. code =" + err.code + ", message =" + err.message);
            return;
        }
        console.info("Deleted the key 'startup'.");
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to delete the key 'startup'. code =" + code + ", message =" + message);
}
```


### delete

delete(key: string): Promise&lt;void&gt;

Deletes a KV pair from the cached **Preferences** instance based on the specified key. This API uses a promise to return the result. You can use [flush](#flush) to persist the **Preferences** instance.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| key    | string | Yes  | Key of the KV pair to delete. It cannot be empty.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
try {
    let promise = preferences.delete('startup');
    promise.then(() => {
        console.info("Deleted the key 'startup'.");
    }).catch((err: BusinessError) => {
        console.error("Failed to delete the key 'startup'. code =" + err.code +", message =" + err.message);
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to delete the key 'startup'. code =" + code +", message =" + message);
}
```


### deleteSync<sup>10+</sup>

deleteSync(key: string): void

Deletes a KV pair from the cached **Preferences** instance based on the specified key. This API returns the result synchronously. You can use [flush](#flush) to persist the **Preferences** instance.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| key    | string | Yes  | Key of the KV pair to delete. It cannot be empty.|

**Example**

```ts
try {
    preferences.deleteSync('startup');
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to delete the key 'startup'. code =" + code +", message =" + message);
}
```


### flush

flush(callback: AsyncCallback&lt;void&gt;): void

Flushes the data in the cached **Preferences** instance to the persistent file. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                |
| -------- | ------------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```ts
try {
    preferences.flush((err: BusinessError) => {
        if (err) {
            console.error("Failed to flush. code =" + err.code + ", message =" + err.message);
            return;
        }
        console.info("Successfully flushed data.");
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to flush. code =" + code + ", message =" + message);
}
```


### flush

flush(): Promise&lt;void&gt;

Flushes the data in the cached **Preferences** instance to the persistent file. This API uses a promise to return the result.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
try {
    let promise = preferences.flush();
    promise.then(() => {
        console.info("Successfully flushed data.");
    }).catch((err: BusinessError) => {
        console.error("Failed to flush. code =" + err.code + ", message =" + err.message);
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to flush. code =" + code + ", message =" + message);
}
```


### clear

clear(callback: AsyncCallback&lt;void&gt;): void

Clears all data in the cached **Preferences** instance. This API uses an asynchronous callback to return the result. You can use [flush](#flush) to persist the **Preferences** instance.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                     | Mandatory| Description                                                |
| -------- | ------------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **undefined**. Otherwise, **err** is an error object.|

**Example**

```ts
try {
    preferences.clear((err: BusinessError) =>{
        if (err) {
            console.error("Failed to clear. code =" + err.code + ", message =" + err.message);
            return;
        }
        console.info("Successfully cleared data.");
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to clear. code =" + code + ", message =" + message);
}
```


### clear

clear(): Promise&lt;void&gt;

Clears all data in the cached **Preferences** instance. This API uses a promise to return the result. You can use [flush](#flush) to persist the **Preferences** instance.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Example**

```ts
try {
    let promise = preferences.clear();
    promise.then(() => {
        console.info("Successfully cleared data.");
    }).catch((err: BusinessError) => {
        console.error("Failed to clear. code =" + err.code + ", message =" + err.message);
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to clear. code =" + code + ", message =" + message);
}
```


### clearSync<sup>10+</sup>

clearSync(): void

Clears all data in the cached **Preferences** instance. This API returns the result synchronously. You can use [flush](#flush) to persist the **Preferences** instance.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Example**

```ts
try {
    preferences.clearSync();
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to clear. code =" + code + ", message =" + message);
}
```


### on('change')

on(type: 'change', callback: ( key : string ) => void): void

Subscribes to data changes. A callback will be triggered to return the new value if the value of the subscribed key is changed and [flushed](#flush).

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type    | Mandatory| Description                                    |
| -------- | -------- | ---- | ---------------------------------------- |
| type     | string                           | Yes  | Event type. The value is **change**, which indicates data changes. |
| callback | Function | Yes  | Callback invoked to return the result.<br>**key** indicates the key whose value is changed.    |

**Example**

```ts
try {
    data_preferences.getPreferences(this.context, 'myStore', (err: BusinessError, preferences: data_preferences.Preferences) => {
        if (err) {
            console.error("Failed to get preferences.");
            return;
        }
        preferences.on('change', (key: string) => {
            console.info("The key " + key + " changed.");
        });
        preferences.put('startup', 'manual', (err: BusinessError) => {
            if (err) {
            console.error("Failed to put the value of 'startup'. Cause: " + err);
            return;
            }
            console.info("Successfully put the value of 'startup'.");

            preferences.flush((err: BusinessError) => {
            if (err) {
                console.error("Failed to flush. Cause: " + err);
                return;
            }
            console.info("Successfully flushed data.");
            })
        })
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to flush. code =" + code + ", message =" + message);
}
```

### on('multiProcessChange')<sup>10+</sup>

on(type: 'multiProcessChange', callback: ( key : string ) => void): void

Subscribes to inter-process data changes. For the multiple processes holding the same preference file, if the value of the subscribed key changes in any process, the callback in this API will be invoked after [flush()](#flush) is executed.

This API can be used with [removePreferencesFromCache](#data_preferencesremovepreferencesfromcache) to update the **Preferences** instance in the callback when detecting that a process updates a file. For details, see example 2.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type. The value is **multiProcessChange**, which indicates data changes between multiple processes.|
| callback | Function | Yes  | Callback invoked to return the result.<br>**key** indicates the key whose value is changed.                        |

**Error codes**

For details about the error codes, see [User Preference Error Codes](../errorcodes/errorcode-preferences.md).

| ID| Error Message                              |
| -------- | -------------------------------------- |
| 15500019 | Failed to obtain subscription service. |

**Example 1**

```ts
try {
    let options: data_preferences.Options = { name: 'myStore', dataGroupId:'myId' };
    data_preferences.getPreferences(this.context, options, (err: BusinessError, preferences: data_preferences.Preferences) => {
        if (err) {
            console.error("Failed to get preferences.");
            return;
        }
        preferences.on('multiProcessChange', (key: string) => {
            console.info("The key " + key + " changed.");
        });
        preferences.put('startup', 'manual', (err: BusinessError) => {
            if (err) {
                console.error("Failed to put the value of 'startup'. Cause: " + err);
                return;
            }
            console.info("Successfully put the value of 'startup'.");
            preferences.flush((err: BusinessError) => {
                if (err) {
                    console.error("Failed to flush. Cause: " + err);
                    return;
                }
                console.info("Successfully flushed data.");
            })
        })
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to flush. code =" + code + ", message =" + message);
}
```

**Example 2**

```ts
try {
    let options: data_preferences.Options = { name: 'myStore' };
    data_preferences.getPreferences(this.context, options, (err: BusinessError, val: data_preferences.Preferences) => {
        if (err) {
            console.error("Failed to get preferences.");
            return;
        }
        preferences = val;
        preferences.on('multiProcessChange', (key: string) => {
            console.info("The key " + key + " changed.");
            try {
                data_preferences.removePreferencesFromCache(this.context, options, (err: BusinessError) => {
                    if (err) {
                        console.error("Failed to remove preferences. code =" + err.code + ", message =" + err.message);
                        return;
                    }
                    preferences = null;
                    console.info("Succeeded in removing preferences.");
                })
            } catch (err) {
                let code = (err as BusinessError).code;
                let message = (err as BusinessError).message;
                console.error("Failed to remove preferences. code =" + code + ", message =" + message);
            }

            try {
                data_preferences.getPreferences(this.context, options, (err: BusinessError, val: data_preferences.Preferences) => {
                    if (err) {
                        console.error("Failed to get preferences. code =" + err.code + ", message =" + err.message);
                        return;
                    }
                    preferences = val;
                    console.info("Succeeded in getting preferences.");
                })
            } catch (err) {
                let code = (err as BusinessError).code;
                let message = (err as BusinessError).message;
                console.error("Failed to get preferences. code =" + code + ", message =" + message);
            }
        });
        preferences.put('startup', 'manual', (err: BusinessError) => {
            if (err) {
                console.error("Failed to put the value of 'startup'. Cause: " + err);
                return;
            }
            console.info("Successfully put the value of 'startup'.");

            if (preferences != null) {
                preferences.flush((err: BusinessError) => {
                    if (err) {
                        console.error("Failed to flush. Cause: " + err);
                        return;
                    }
                    console.info("Successfully flushed data.");
                })
            }
        })
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to flush. code =" + code + ", message =" + message);
}
```

### off('change')

off(type: 'change', callback?: ( key : string ) => void): void

Unsubscribes from data changes.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string                           | Yes  | Event type. The value is **change**, which indicates data changes. |
| callback | Function | No  | Callback to unregister. If this parameter is left blank, all callbacks for data changes will be unregistered.<br>**key** indicates the key whose value is changed.|

**Example**

```ts

try {
    data_preferences.getPreferences(this.context, 'myStore', (err: BusinessError, preferences: data_preferences.Preferences) => {
        if (err) {
            console.error("Failed to get preferences.");
            return;
        }
        preferences.on('change', (key: string) => {
            console.info("The key " + key + " changed.");
        });
        preferences.put('startup', 'auto', (err: BusinessError) => {
            if (err) {
                console.error("Failed to put the value of 'startup'. Cause: " + err);
                return;
            }
            console.info("Successfully put the value of 'startup'.");

            preferences.flush((err: BusinessError) =>{
                if (err) {
                    console.error("Failed to flush. Cause: " + err);
                    return;
                }
                console.info("Successfully flushed data.");
            })
            preferences.off('change', (key: string) => {
                console.info("The key " + key + " changed.");
            });
        })
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to flush. code =" + code + ", message =" + message);
}
```

### off('multiProcessChange')<sup>10+</sup>

off(type: 'multiProcessChange', callback?: ( key : string ) => void): void

Unsubscribes from inter-process data changes.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type. The value is **multiProcessChange**, which indicates data changes between multiple processes.|
| callback | Function | No  | Callback to unregister. If this parameter is left blank, all callbacks for **multiProcessChange** will be unregistered.<br>**key** indicates the key whose value is changed.|

**Example**

```ts
try {
    let options: data_preferences.Options = { name: 'myStore', dataGroupId:'myId' };
    data_preferences.getPreferences(this.context, options, (err: BusinessError, preferences: data_preferences.Preferences) => {
        if (err) {
            console.error("Failed to get preferences.");
            return;
        }
        preferences.on('multiProcessChange', (key: string) => {
            console.info("The key " + key + " changed.");
        });
        preferences.put('startup', 'auto', (err: BusinessError) => {
            if (err) {
                console.error("Failed to put the value of 'startup'. Cause: " + err);
                return;
            }
            console.info("Successfully put the value of 'startup'.");

            preferences.flush((err: BusinessError) => {
                if (err) {
                    console.error("Failed to flush. Cause: " + err);
                    return;
                }
                console.info("Successfully flushed data.");
            })
            preferences.off('multiProcessChange', (key: string) => {
                console.info("The key " + key + " changed.");
            });
        })
    })
} catch (err) {
    let code = (err as BusinessError).code;
    let message = (err as BusinessError).message;
    console.error("Failed to flush. code =" + code + ", message =" + message);
}
```
## ValueType

Enumerates the value types.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

| Type           | Description                          |
| --------------- | ------------------------------ |
| number          | The value is a number.            |
| string          | The value is a string.          |
| boolean         | The value is of Boolean type.          |
| Array\<number>  | The value is an array of numbers.  |
| Array\<boolean> | The value is a Boolean array.  |
| Array\<string>  | The value is an array of strings.|
