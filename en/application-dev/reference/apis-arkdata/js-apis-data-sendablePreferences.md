# @ohos.data.sendablePreferences (Shared User Preferences)


The **sendablePreferences** module provides APIs for processing data in the form of key-value (KV) pairs, including querying, modifying, and persisting KV pairs.

In the KV pairs, the key must be a string, and the value can be a number, a string, a Boolean value, a bigint, or a serializable object.

The default encryption level of the shared user preferences is EL2, and the persistent files are stored in the corresponding **el2/** directory. Generally, the data in the **el2/** directory can be accessed only after at least one successful unlock operation (by PIN, fingerprint, or facial authentication) upon the start of the device. Avoid direct access to preferences data without the screen unlock operation. For details about how to modify the encryption level, see [Obtaining and Modifying Encryption Levels](../../../application-dev/application-models/application-context-stage.md#obtaining-and-modifying-encryption-levels).

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The shared user preferences are not thread-safe and may cause file damage and data loss when used in multi-process scenarios. Do not use it in multi-process scenarios.

## Modules to Import

```ts
import { sendablePreferences } from '@kit.ArkData';
```

## Constant

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

| Name            | Type| Readable| Writable| Description                                   |
| ---------------- | -------- | ---- | ---- | --------------------------------------- |
| MAX_KEY_LENGTH   | number   | Yes  | No  | Maximum length of a key, which is 1024 bytes.    |
| MAX_VALUE_LENGTH | number   | Yes  | No  | Maximum value length, which is 16 x 1024 x 1024 bytes.|

## sendablePreferences.getPreferences

getPreferences(context: Context, options: Options): Promise&lt;Preferences&gt;

Obtains a **Preferences** instance. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type            | Mandatory| Description                                                                                                                                                                          |
| ------- | ---------------- | ---- | ------------------------------------------------------------------------------------------------------------------------------------------------------------------------------ |
| context | [Context](../apis-ability-kit/js-apis-inner-application-baseContext.md)          | Yes  | Application context.|
| options | [Options](#options) | Yes  | Configuration options of the **Preferences** instance.       |

**Return value**

| Type                                   | Description                              |
| --------------------------------------- | ---------------------------------- |
| Promise&lt;[Preferences](#preferences)&gt; | Promise used to return the **Preferences** instance obtained.<br>This instance inherits [ISendable](../../arkts-utils/arkts-sendable.md#isendable) and can be passed between concurrent ArkTS instances (including the main thread and the TaskPool or Worker threads) via pass-by-reference. For details, see [When to Use](../../arkts-utils/arkts-sendable.md#when-to-use).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 801      | Capability not supported.     |
| 15500000 | Inner error.                   |
| 15501001 | Only supported in stage mode. |
| 15501002 | The data group id is not valid.     |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

let preferences: sendablePreferences.Preferences;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let options: sendablePreferences.Options = { name: 'myStore' };
    let promise = sendablePreferences.getPreferences(this.context, options);
    promise.then((object: sendablePreferences.Preferences) => {
      preferences = object;
      console.info("Succeeded in getting preferences.");
    }).catch((err: BusinessError) => {
      console.error(`Failed to get preferences. code: ${err.code}, message: ${err.message}`);
    })
  }
}
```

## sendablePreferences.getPreferencesSync

getPreferencesSync(context: Context, options: Options): Preferences

Obtains a **Preferences** instance. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type                 | Mandatory| Description                                                        |
| ------- | --------------------- | ---- | ------------------------------------------------------------ |
| context | [Context](../apis-ability-kit/js-apis-inner-application-baseContext.md)               | Yes  | Application context.|
| options | [Options](#options) | Yes  | Configuration options of the **Preferences** instance.                           |

**Return value**

| Type                       | Description                 |
| --------------------------- | --------------------- |
| [Preferences](#preferences) | **Preferences** instance obtained.<br>This instance inherits [ISendable](../../arkts-utils/arkts-sendable.md#isendable) and can be passed between concurrent ArkTS instances (including the main thread and the TaskPool or Worker threads) via pass-by-reference. For details, see [When to Use](../../arkts-utils/arkts-sendable.md#when-to-use).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 801      | Capability not supported.     |
| 15500000 | Inner error.                   |
| 15501001 | Only supported in stage mode.   |
| 15501002 | The data group id is not valid. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

let preferences: sendablePreferences.Preferences;

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let options: sendablePreferences.Options = { name: 'myStore' };
    preferences = sendablePreferences.getPreferencesSync(this.context, options);
  }
}
```

## sendablePreferences.deletePreferences

deletePreferences(context: Context, options: Options): Promise&lt;void&gt;

Deletes a **Preferences** instance from the cache. If the **Preferences** instance has a persistent file, the persistent file will also be deleted. This API uses a promise to return the result.

Avoid using a deleted **Preferences** instance to perform data operations, which may cause data inconsistency.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type            | Mandatory| Description                                                                        |
| ------- | ---------------- | ---- | ----------------------------------------------------------------------------|
| context | [Context](../apis-ability-kit/js-apis-inner-application-baseContext.md)          | Yes  | Application context.|
| options | [Options](#options) | Yes  | Configuration options of the **Preferences** instance.                                                                           |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 801      | Capability not supported.     |
| 15500000 | Inner error.                   |
| 15500010 | Failed to delete preferences file. |
| 15501001 | Only supported in stage mode. |
| 15501002 | The data group id is not valid. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let options: sendablePreferences.Options = { name: 'myStore' };
    let promise = sendablePreferences.deletePreferences(this.context, options);
    promise.then(() => {
      console.info("Succeeded in deleting preferences.");
    }).catch((err: BusinessError) => {
      console.error(`Failed to delete preferences. code: ${err.code}, message: ${err.message}`);
    })
  }
}
```

## sendablePreferences.removePreferencesFromCache

removePreferencesFromCache(context: Context, options: Options): Promise&lt;void&gt;

Removes a **Preferences** instance from the cache. This API uses a promise to return the result.

After an application calls [getPreferences](#sendablepreferencesgetpreferences) for the first time to obtain a **Preferences** instance, the obtained **Preferences** instance is cached. When the application calls [getPreferences](#sendablepreferencesgetpreferences) again, the **Preferences** instance will be read from the cache instead of from the persistent file. After this API is called to remove the instance from the cache, calling **getPreferences** again will read data from the persistent file and create a new **Preferences** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type            | Mandatory| Description                                                                                                                     |
| ------- | ---------------- | ---- | ----------------------------------------------------------------------------------------------------------------------- |
| context | [Context](../apis-ability-kit/js-apis-inner-application-baseContext.md)          | Yes  | Application context.|
| options | [Options](#options) | Yes  | Configuration options of the **Preferences** instance.                                                                                   |

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 801      | Capability not supported.     |
| 15500000 | Inner error.                   |
| 15501001 | Only supported in stage mode. |
| 15501002 | The data group id is not valid.     |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { window } from '@kit.ArkUI';

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let options: sendablePreferences.Options = { name: 'myStore' };
    let promise = sendablePreferences.removePreferencesFromCache(this.context, options);
    promise.then(() => {
      console.info("Succeeded in removing preferences.");
    }).catch((err: BusinessError) => {
      console.error(`Failed to remove preferences. code: ${err.code}, message: ${err.message}`);
    })
  }
}
```

## sendablePreferences.removePreferencesFromCacheSync

removePreferencesFromCacheSync(context: Context, options: Options):void

Removes a **Preferences** instance from the cache. This API returns the result synchronously.

After an application calls [getPreferences](#sendablepreferencesgetpreferences) for the first time to obtain a **Preferences** instance, the obtained **Preferences** instance is cached. When the application calls [getPreferences](#sendablepreferencesgetpreferences) again, the **Preferences** instance will be read from the cache instead of from the persistent file. After this API is called to remove the instance from the cache, calling **getPreferences** again will read data from the persistent file and create a new **Preferences** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name | Type                 | Mandatory| Description                                                        |
| ------- | --------------------- | ---- | ------------------------------------------------------------ |
| context | [Context](../apis-ability-kit/js-apis-inner-application-baseContext.md)               | Yes  | Application context.|
| options | [Options](#options) | Yes  | Configuration options of the **Preferences** instance.                           |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 801      | Capability not supported.     |
| 15500000 | Inner error.                   |
| 15501001 | Only supported in stage mode.   |
| 15501002 | The data group id is not valid. |

**Example**

```ts
import { UIAbility } from '@kit.AbilityKit';
import { window } from '@kit.ArkUI';

class EntryAbility extends UIAbility {
  onWindowStageCreate(windowStage: window.WindowStage) {
    let options: sendablePreferences.Options = { name: 'myStore' };
    sendablePreferences.removePreferencesFromCacheSync(this.context, options);
  }
}
```

## Options

Represents the configuration options of a **Preferences** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

| Name       | Type  | Mandatory| Description                                                        |
| ----------- | ------ | ---- | ------------------------------------------------------------ |
| name        | string | Yes  | Name of the **Preferences** instance.                                     |
| dataGroupId | string\|null | No  | Application group ID, which needs to be obtained from AppGallery. This parameter is not supported currently.<br>This parameter is optional. A **Preferences** instance will be created in the sandbox path corresponding to the specified **dataGroupId**. If this parameter is not specified, the **Preferences** instance is created in the sandbox directory of the application.<br> **Model restriction**: This attribute can be used only in the stage model.|


## Preferences

Provides APIs for obtaining and modifying **Preferences** instances. **Preferences** inherits from [ISendable](../../arkts-utils/arkts-sendable.md#isendable) and can be passed between concurrent ArkTS instances (including the main thread and the TaskPool or Worker threads) via pass-by-reference.

Before calling any API of **Preferences**, obtain a **Preferences** instance by using [sendablePreferences.getPreferences](#sendablepreferencesgetpreferences).

### get

get(key: string, defValue: lang.ISendable): Promise&lt;lang.ISendable&gt;

Obtains the value of a key from this **Preferences** instance. This API uses a promise to return the result. If the value is null or is not of the default value type, **defValue** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

 **Parameters**

| Name  | Type                   | Mandatory| Description |
| -------- | ----------------------- | ---- |--------|
| key      | string                  | Yes  | Key of the data to obtain. It cannot be empty. |
| defValue | [lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable) | Yes  | Default value to be returned.|

**Return value**

| Type                               | Description                         |
| ----------------------------------- | ----------------------------- |
| Promise&lt;[lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable)&gt; | Promise used to return the value obtained.<br>This instance inherits [ISendable](../../arkts-utils/arkts-sendable.md#isendable) and can be passed between concurrent ArkTS instances (including the main thread and the TaskPool or Worker threads) via pass-by-reference. For details, see [When to Use](../../arkts-utils/arkts-sendable.md#when-to-use).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { lang } from '@kit.ArkTS';

let promise = preferences.get('startup', 'default');
promise.then((data: lang.ISendable) => {
  let dataStr = data as string;
  console.info(`Succeeded in getting value of 'startup'. Data: ${dataStr}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to get value of 'startup'. code: ${err.code}, message: ${err.message}`);
})
```

### getSync

getSync(key: string, defValue: lang.ISendable): lang.ISendable

Obtains the value of a key from this **Preferences** instance. This API returns the result synchronously. If the value is null or is not of the default value type, **defValue** is returned.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                   | Mandatory| Description           |
| -------- | ----------------------- | ---- |---------------------|
| key      | string                  | Yes  | Key of the data to obtain. It cannot be empty. |
| defValue | [lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable) | Yes  | Default value to be returned.|

**Return value**

| Type                               | Description                         |
| ----------------------------------- | ----------------------------- |
| [lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable) | Value obtained.<br>This instance inherits [ISendable](../../arkts-utils/arkts-sendable.md#isendable) and can be passed between concurrent ArkTS instances (including the main thread and the TaskPool or Worker threads) via pass-by-reference. For details, see [When to Use](../../arkts-utils/arkts-sendable.md#when-to-use).|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**Example**

```ts
import { lang } from '@kit.ArkTS';
let value: lang.ISendable = preferences.getSync('startup', 'default');
```

### getAll

getAll(): Promise&lt;lang.ISendable&gt;

Obtains all KV pairs from this **Preferences** instance. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Return value**

| Type                 | Description                                       |
| --------------------- | ------------------------------------------- |
| Promise&lt;[lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable)&gt; | Promise used to return the KV pairs obtained.<br>This object inherits [ISendable](../../arkts-utils/arkts-sendable.md#isendable) and can be passed between concurrent ArkTS instances (including the main thread and the TaskPool or Worker threads) via pass-by-reference. For details, see [When to Use](../../arkts-utils/arkts-sendable.md#when-to-use). |

**Error codes**

For details about the error codes, see [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 15500000 | Inner error.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { lang } from '@kit.ArkTS';

let promise = preferences.getAll();
promise.then((keyValues: lang.ISendable) => {
  for (let value of Object.keys(keyValues)) {
    console.info("getAll " + JSON.stringify(value));
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to get all key-values. code: ${err.code}, message: ${err.message}`);
})
```

### getAllSync

getAllSync(): lang.ISendable

Obtains all KV pairs from this **Preferences** instance. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Return value**

| Type                 | Description                                       |
| --------------------- | ------------------------------------------- |
| [lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable) | All KV pairs obtained.<br>This object inherits [ISendable](../../arkts-utils/arkts-sendable.md#isendable) and can be passed between concurrent ArkTS instances (including the main thread and the TaskPool or Worker threads) via pass-by-reference. For details, see [When to Use](../../arkts-utils/arkts-sendable.md#when-to-use).|

**Error codes**

For details about the error codes, see [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 15500000 | Inner error.                   |

**Example**

```ts
import { lang } from '@kit.ArkTS';

let keyValues: lang.ISendable = preferences.getAllSync();
for (let value of Object.keys(keyValues)) {
  console.info("getAll " + JSON.stringify(value));
}
```

### put

put(key: string, value: lang.ISendable): Promise&lt;void&gt;

Writes data to this **Preferences** instance. This API uses a promise to return the result. You can use [flush](#flush) to persist the **Preferences** instance.

  > **NOTE**
  >
  > If the key already exists, **put()** overwrites the value. You can use **hasSync()** to check whether the KV pair exists.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type                   | Mandatory| Description                        |
| ------ | ----------------------- | ---- |--------------------------|
| key    | string                  | Yes  | Key of the data. It cannot be empty. |
| value  | [lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable) | Yes  | Value to write.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = preferences.put('startup', 'auto');
promise.then(() => {
  console.info("Succeeded in putting value of 'startup'.");
}).catch((err: BusinessError) => {
  console.error(`Failed to put value of 'startup'. code: ${err.code}, message: ${err.message}`);
})
```

### putSync

putSync(key: string, value: lang.ISendable): void

Writes data to this **Preferences** instance. This API returns the result synchronously. You can use [flush](#flush) to persist the **Preferences** instance.

  > **NOTE**
  >
  > If the key already exists, **putSync()** overwrites the value. You can use **hasSync()** to check whether the KV pair exists.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type                   | Mandatory| Description                                                        |
| ------ | ----------------------- | ---- | ------------------------ |
| key    | string                  | Yes  | Key of the data. It cannot be empty.|
| value  | [lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable) | Yes  | Value to write.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**Example**

```ts
preferences.putSync('startup', 'auto');
```

### has

has(key: string): Promise&lt;boolean&gt;

Checks whether this **Preferences** instance contains the KV pair of the given key. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| key    | string | Yes  | Key of the data to check. It cannot be empty.|

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the **Preferences** instance contains the KV pair; the value **false** means the opposite.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = preferences.has('startup');
promise.then((val: boolean) => {
  if (val) {
    console.info("The key 'startup' is contained.");
  } else {
    console.error("The key 'startup' dose not contain.");
  }
}).catch((err: BusinessError) => {
  console.error(`Failed to check the key 'startup'. code: ${err.code}, message: ${err.message}`);
})
```

### hasSync

hasSync(key: string): boolean

Checks whether this **Preferences** instance contains the KV pair of the given key. This API returns the result synchronously.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| key    | string | Yes  | Key of the data to check. It cannot be empty.|

**Return value**

| Type                  | Description                                                        |
| ---------------------- | ------------------------------------------------------------ |
| boolean | Returns **true** if the **Preferences** instance contains the KV pair; returns **false** otherwise.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**Example**

```ts
let isExist: boolean = preferences.hasSync('startup');
if (isExist) {
  console.info("The key 'startup' is contained.");
} else {
  console.error("The key 'startup' dose not contain.");
}
```

### delete

delete(key: string): Promise&lt;void&gt;

Deletes a KV pair from this **Preferences** instance. This API uses a promise to return the result. You can use [flush](#flush) to persist the **Preferences** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| key    | string | Yes  | Key of the KV pair to delete. It cannot be empty.|

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = preferences.delete('startup');
promise.then(() => {
  console.info("Succeeded in deleting the key 'startup'.");
}).catch((err: BusinessError) => {
  console.error(`Failed to delete the key 'startup'. code: ${err.code}, message: ${err.message}`);
})
```

### deleteSync

deleteSync(key: string): void

Deletes a KV pair from this **Preferences** instance. This API returns the result synchronously. You can use [flush](#flush) to persist the **Preferences** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name| Type  | Mandatory| Description                           |
| ------ | ------ | ---- | ------------------------------- |
| key    | string | Yes  | Key of the KV pair to delete. It cannot be empty.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**Example**

```ts
preferences.deleteSync('startup');
```

### flush

flush(): Promise&lt;void&gt;

Flushes the data in this **Preferences** instance to the persistent file. This API uses a promise to return the result.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 15500000 | Inner error.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = preferences.flush();
promise.then(() => {
  console.info("Succeeded in flushing.");
}).catch((err: BusinessError) => {
  console.error(`Failed to flush. code: ${err.code}, message: ${err.message}`);
})
```

### clear

clear(): Promise&lt;void&gt;

Clears this **Preferences** instance. This API uses a promise to return the result. You can use [flush](#flush) to persist the **Preferences** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Return value**

| Type               | Description                     |
| ------------------- | ------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

For details about the error codes, see [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 15500000 | Inner error.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let promise = preferences.clear();
promise.then(() => {
  console.info("Succeeded in clearing.");
}).catch((err: BusinessError) => {
  console.error(`Failed to clear. code: ${err.code}, message: ${err.message}`);
})
```

### clearSync

clearSync(): void

Clears this **Preferences** instance. This API returns the result synchronously. You can use [flush](#flush) to persist the **Preferences** instance.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Error codes**

For details about the error codes, see [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 15500000 | Inner error.                   |

**Example**

```ts
preferences.clearSync();
```

### on('change')

on(type: 'change', callback: Callback&lt;string&gt;): void

Subscribes to data changes. The registered callback will be invoked to return the new value if the data change is [flushed](#flush).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type    | Mandatory| Description                                    |
| -------- | -------- | ---- | ---------------------------------------- |
| type     | string   | Yes  | Event type. The value is **'change'**, which indicates data changes.|
| callback | Callback&lt;string&gt; | Yes  | Callback used to return the key whose value is changed.    |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let observer = (key: string) => {
  console.info("The key " + key + " changed.");
}
preferences.on('change', observer);
preferences.putSync('startup', 'manual');
preferences.flush().then(() => {
  console.info("Succeeded in flushing.");
}).catch((err: BusinessError) => {
  console.error(`Failed to flush. code: ${err.code}, message: ${err.message}`);
})
```

### on('multiProcessChange')

on(type: 'multiProcessChange', callback: Callback&lt;string&gt;): void

Subscribes to inter-process data changes. For the multiple processes holding the same preference file, if the value of the subscribed key changes in any process, the callback in this API will be invoked after [flush()](#flush) is executed.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type. The value is **'multiProcessChange'**, which indicates inter-process data changes.|
| callback | Callback&lt;string&gt; | Yes  | Callback used to return the key whose value is changed.                  |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                               |
| -------- | -------------------------------------- |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                           |
| 15500019 | Failed to obtain subscription service. |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let observer = (key: string) => {
  console.info("The key " + key + " changed.");
}
preferences.on('multiProcessChange', observer);
preferences.putSync('startup', 'manual');
preferences.flush().then(() => {
  console.info("Succeeded in flushing.");
}).catch((err: BusinessError) => {
  console.error(`Failed to flush. code: ${err.code}, message: ${err.message}`);
})
```

### on('dataChange')

on(type: 'dataChange', keys: Array&lt;string&gt;, callback: Callback&lt;lang.ISendable&gt;): void

Subscribes to changes of specific data. The registered callback will be invoked only after the values of the specified keys are changed and [flushed](#flush).

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is **'dataChange'**, which indicates data changes.          |
| keys     | Array&lt;string&gt;                                          | Yes  | Keys to be observed.                                         |
| callback | callback: Callback&lt;[lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable)&gt; | Yes  | Callback used to return the KV pairs changed. The keys are the keys observed, and the values are the new values. The values support the following types: number, string, boolean, bigint, and serializable object. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { lang } from '@kit.ArkTS';

let observer = (data: lang.ISendable) => {
  console.info(`observer : ${data}`)
}
let keys = ['name', 'age'];
preferences.on('dataChange', keys, observer);
preferences.putSync('name', 'xiaohong');
preferences.putSync('weight', 125);
preferences.flush().then(() => {
  console.info("Succeeded in flushing.");
}).catch((err: BusinessError) => {
  console.error(`Failed to flush. code: ${err.code}, message: ${err.message}`);
});
```

### off('change')

off(type: 'change', callback?: Callback&lt;string&gt;): void

Unsubscribes from data changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type. The value is **'change'**, which indicates data changes.                    |
| callback | Callback&lt;string&gt; | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for data changes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let observer = (key: string) => {
  console.info("The key " + key + " changed.");
}
preferences.on('change', observer);
preferences.putSync('startup', 'auto');
preferences.flush().then(() => {
  console.info("Succeeded in flushing.");
  preferences.off('change', observer);
}).catch((err: BusinessError) => {
  console.error(`Failed to flush. code: ${err.code}, message: ${err.message}`);
});
```

### off('multiProcessChange')

off(type: 'multiProcessChange', callback?: Callback&lt;string&gt;): void

Unsubscribes from inter-process data changes.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type    | Mandatory| Description                                                        |
| -------- | -------- | ---- | ------------------------------------------------------------ |
| type     | string   | Yes  | Event type. The value is **'multiProcessChange'**, which indicates inter-process data changes.|
| callback | Callback&lt;string&gt; | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for inter-process data changes.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';

let observer = (key: string) => {
  console.info("The key " + key + " changed.");
}
preferences.on('multiProcessChange', observer);
preferences.putSync('startup', 'auto');
preferences.flush().then(() => {
  console.info("Succeeded in flushing.");
  preferences.off('multiProcessChange', observer);
}).catch((err: BusinessError) => {
  console.error(`Failed to flush. code: ${err.code}, message: ${err.message}`);
});
```
### off('dataChange')

off(type: 'dataChange', keys: Array&lt;string&gt;, callback?: Callback&lt;lang.ISendable&gt;): void

Unsubscribes from changes of specific data.

**Atomic service API**: This API can be used in atomic services since API version 12.

**System capability**: SystemCapability.DistributedDataManager.Preferences.Core

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                                        |
| -------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| type     | string                                                       | Yes  | Event type. The value is **'dataChange'**, which indicates data changes.          |
| keys     | Array&lt;string&gt;                                          | Yes  | Keys to be unsubscribed from. If this parameter is not specified, this API unsubscribes from the changes of all keys.|
| callback | Callback&lt;[lang.ISendable](../../arkts-utils/arkts-sendable.md#isendable)&gt; | No  | Callback to unregister. If this parameter is not specified, this API unregisters all callbacks for the changes of the specified data.|

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [User Preference Error Codes](errorcode-preferences.md).

| ID| Error Message                       |
| -------- | ------------------------------ |
| 401      | Parameter error. Possible causes:<br>1. Mandatory parameters are left unspecified;<br>2. Incorrect parameter types;<br>3. Parameter verification failed.                       |
| 15500000 | Inner error.                   |

**Example**

```ts
import { BusinessError } from '@kit.BasicServicesKit';
import { lang } from '@kit.ArkTS';

let observer = (data: lang.ISendable) => {
  console.info(`observer : ${data}`)
}
let keys = ['name', 'age'];
preferences.on('dataChange', keys, observer);
preferences.putSync('name', 'xiaohong');
preferences.putSync('weight', 125);
preferences.flush().then(() => {
  console.info("Succeeded in flushing.");
  preferences.off('dataChange', keys, observer);
}).catch((err: BusinessError) => {
  console.error(`Failed to flush. code: ${err.code}, message: ${err.message}`);
});
```
