# @ohos.account.osAccount (System Account Management)

The **osAccount** module provides basic capabilities for managing system (OS) accounts, including adding, deleting, querying, setting, subscribing to, and enabling a system account.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { osAccount } from '@kit.BasicServicesKit';
```

## osAccount.getAccountManager

getAccountManager(): AccountManager

Obtains an **AccountManager** instance.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                             | Description             |
| --------------------------------- | ---------------- |
| [AccountManager](#accountmanager) | **AccountManager** instance obtained.|

**Example**

  ```ts
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  ```

## OsAccountType

Enumerates the system account types.

**System capability**: SystemCapability.Account.OsAccount

| Name  | Value| Description        |
| ------ | ------ | ----------- |
| ADMIN  | 0      | Administrator account.|
| NORMAL | 1      | Normal account.  |
| GUEST  | 2      | Guest account.  |

## AccountManager

Provides APIs for managing system accounts.

### checkMultiOsAccountEnabled<sup>9+</sup>

checkMultiOsAccountEnabled(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether multiple system accounts are supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                    |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means multiple system accounts are supported; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.checkMultiOsAccountEnabled((err: BusinessError, isEnabled: boolean) => {
      if (err) {
        console.error(`checkMultiOsAccountEnabled failed, code is ${err.code}, message is ${err.message}`);
      } else {
      console.log('checkMultiOsAccountEnabled successfully, isEnabled: ' + isEnabled);
      }
    });
  } catch (err) {
    console.log('checkMultiOsAccountEnabled failed, error:' + JSON.stringify(err));
  }
  ```

### checkMultiOsAccountEnabled<sup>9+</sup>

checkMultiOsAccountEnabled(): Promise&lt;boolean&gt;

Checks whether multiple system accounts are supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                  | Description                                                       |
| :--------------------- | :--------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means multiple system accounts are supported; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  try {
    let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
    accountManager.checkMultiOsAccountEnabled().then((isEnabled: boolean) => {
      console.log('checkMultiOsAccountEnabled successfully, isEnabled: ' + isEnabled);
    }).catch((err: BusinessError) => {
      console.error(`checkMultiOsAccountEnabled failed, code is ${err.code}, message is ${err.message}`);
    });
  } catch (err) {
    console.log('checkMultiOsAccountEnabled failed, error:' + JSON.stringify(err));
  }
  ```

### checkOsAccountActivated<sup>(deprecated)</sup>

checkOsAccountActivated(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a system account is activated. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                    |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| localId  | number                       | Yes  | ID of the target system account.                                            |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means the account is activated; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Check whether system account 100 is activated.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.checkOsAccountActivated(localId, (err: BusinessError, isActivated: boolean) => {
      if (err) {
        console.log('checkOsAccountActivated failed, error:' + JSON.stringify(err));
      } else {
        console.log('checkOsAccountActivated successfully, isActivated:' + isActivated);
      }
    });
  } catch (err) {
    console.log('checkOsAccountActivated exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountActivated<sup>(deprecated)</sup>

checkOsAccountActivated(localId: number): Promise&lt;boolean&gt;

Checks whether a system account is activated. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description                              |
| ------- | ------ | ---- | --------------------------------- |
| localId | number | Yes  | ID of the target system account.|

**Return value**

| Type                  | Description                                                      |
| ---------------------- | ---------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the account is activated; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Check whether system account 100 is activated.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.checkOsAccountActivated(localId).then((isActivated: boolean) => {
      console.log('checkOsAccountActivated successfully, isActivated: ' + isActivated);
    }).catch((err: BusinessError) => {
      console.log('checkOsAccountActivated failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkOsAccountActivated exception: ' + JSON.stringify(err));
  }
  ```

### isOsAccountConstraintEnabled<sup>11+</sup>

isOsAccountConstraintEnabled(constraint: string): Promise&lt;boolean&gt;

Checks whether a constraint is enabled for this system account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type  | Mandatory| Description                               |
| ---------- | ------ | ---- | ---------------------------------- |
| constraint | string | Yes  | [Constraint](#constraints) to check.|

**Return value**

| Type                  | Description                                                                 |
| --------------------- | --------------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the specified constraint is enabled; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |

**Example**: Check whether system account 100 is forbidden to use Wi-Fi.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let constraint: string = 'constraint.wifi';
  try {
    accountManager.isOsAccountConstraintEnabled(constraint).then((isEnabled: boolean) => {
      console.log('isOsAccountConstraintEnabled successfully, isEnabled: ' + isEnabled);
    }).catch((err: BusinessError) => {
      console.log('isOsAccountConstraintEnabled failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('isOsAccountConstraintEnabled exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountConstraintEnabled<sup>(deprecated)</sup>

checkOsAccountConstraintEnabled(localId: number, constraint: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the specified constraint is enabled for a system account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                        | Mandatory| Description                                                              |
| ---------- | ---------------------------- | ---- | ----------------------------------------------------------------- |
| localId    | number                       | Yes  | ID of the target system account.                                |
| constraint | string                       | Yes  | [Constraint](#constraints) to check.                               |
| callback   | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means the specified constraint is enabled; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId or constraint.    |
| 12300003 | Account not found. |

**Example**: Check whether system account 100 is forbidden to use Wi-Fi.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  let constraint: string = 'constraint.wifi';
  try {
    accountManager.checkOsAccountConstraintEnabled(localId, constraint, (err: BusinessError, isEnabled: boolean)=>{
      if (err) {
        console.log('checkOsAccountConstraintEnabled failed, error: ' + JSON.stringify(err));
      } else {
        console.log('checkOsAccountConstraintEnabled successfully, isEnabled: ' + isEnabled);
      }
    });
  } catch (err) {
    console.log('checkOsAccountConstraintEnabled exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountConstraintEnabled<sup>(deprecated)</sup>

checkOsAccountConstraintEnabled(localId: number, constraint: string): Promise&lt;boolean&gt;

Checks whether the specified constraint is enabled for a system account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type  | Mandatory| Description                               |
| ---------- | ------ | ---- | ---------------------------------- |
| localId    | number | Yes  | ID of the target system account. |
| constraint | string | Yes  | [Constraint](#constraints) to check.|

**Return value**

| Type                  | Description                                                                 |
| --------------------- | --------------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the specified constraint is enabled; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId or constraint.    |
| 12300003 | Account not found. |

**Example**: Check whether system account 100 is forbidden to use Wi-Fi.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  let constraint: string = 'constraint.wifi';
  try {
    accountManager.checkOsAccountConstraintEnabled(localId, constraint).then((isEnabled: boolean) => {
      console.log('checkOsAccountConstraintEnabled successfully, isEnabled: ' + isEnabled);
    }).catch((err: BusinessError) => {
      console.log('checkOsAccountConstraintEnabled failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkOsAccountConstraintEnabled exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountTestable<sup>9+</sup>

checkOsAccountTestable(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this system account is a test account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                                  |
| -------- | ---------------------------- | ---- | --------------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means the account is a test account; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.checkOsAccountTestable((err: BusinessError, isTestable: boolean) => {
      if (err) {
        console.log('checkOsAccountTestable failed, error: ' + JSON.stringify(err));
      } else {
        console.log('checkOsAccountTestable successfully, isTestable: ' + isTestable);
      }
    });
  } catch (err) {
    console.log('checkOsAccountTestable error: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountTestable<sup>9+</sup>

checkOsAccountTestable(): Promise&lt;boolean&gt;

Checks whether this system account is a test account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                  | Description                                                                     |
| ---------------------- | ------------------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the account is a test account; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.checkOsAccountTestable().then((isTestable: boolean) => {
      console.log('checkOsAccountTestable successfully, isTestable: ' + isTestable);
    }).catch((err: BusinessError) => {
      console.log('checkOsAccountTestable failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkOsAccountTestable exception: ' + JSON.stringify(err));
  }
  ```

### isOsAccountUnlocked<sup>11+</sup>

isOsAccountUnlocked(): Promise&lt;boolean&gt;

Checks whether this system account is unlocked. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                  | Description                                                                     |
| ---------------------- | ------------------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the system account is unlocked; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.isOsAccountUnlocked().then((isVerified: boolean) => {
      console.log('isOsAccountUnlocked successfully, isVerified: ' + isVerified);
    }).catch((err: BusinessError) => {
      console.log('isOsAccountUnlocked failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('isOsAccountUnlocked exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountVerified<sup>(deprecated)</sup>

checkOsAccountVerified(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this system account has been verified. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. Use [isOsAccountUnlocked](#isosaccountunlocked11) instead.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                           |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means the system account has been verified; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.checkOsAccountVerified((err: BusinessError, isVerified: boolean) => {
      if (err) {
        console.log('checkOsAccountVerified failed, error: ' + JSON.stringify(err));
      } else {
        console.log('checkOsAccountVerified successfully, isVerified: ' + isVerified);
      }
    });
  } catch (err) {
    console.log('checkOsAccountVerified exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountVerified<sup>(deprecated)</sup>

checkOsAccountVerified(): Promise&lt;boolean&gt;

Checks whether this system account has been verified. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. Use [isOsAccountUnlocked](#isosaccountunlocked11) instead.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                  | Description                                                                     |
| ---------------------- | ------------------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the system account has been verified; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.checkOsAccountVerified().then((isVerified: boolean) => {
      console.log('checkOsAccountVerified successfully, isVerified: ' + isVerified);
    }).catch((err: BusinessError) => {
      console.log('checkOsAccountVerified failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkOsAccountVerified exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountVerified<sup>(deprecated)</sup>

checkOsAccountVerified(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a system account has been verified. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                           |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------- |
| localId  | number                       | Yes  | ID of the target system account.                             |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means the system account has been verified; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.checkOsAccountVerified(localId, (err: BusinessError, isVerified: boolean) => {
      if (err) {
        console.log('checkOsAccountVerified failed, error: ' + JSON.stringify(err));
      } else {
        console.log('checkOsAccountVerified successfully, isVerified: ' + isVerified);
      }
    });
  } catch (err) {
    console.log('checkOsAccountVerified exception: ' + err);
  }
  ```

### checkOsAccountVerified<sup>(deprecated)</sup>

checkOsAccountVerified(localId: number): Promise&lt;boolean&gt;

Checks whether a system account has been verified. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description                                                             |
| ------- | ------ | ---- | --------------------------------------------------------------- |
| localId | number | Yes  | ID of the target system account. If this parameter is not specified, this API checks whether the current system account has been verified.|

**Return value**

| Type                  | Description                                                              |
| ---------------------- | ----------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the system account has been verified; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.checkOsAccountVerified(localId).then((isVerified: boolean) => {
      console.log('checkOsAccountVerified successfully, isVerified: ' + isVerified);
    }).catch((err: BusinessError) => {
      console.log('checkOsAccountVerified failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkOsAccountVerified exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountCount<sup>9+</sup>

getOsAccountCount(callback: AsyncCallback&lt;number&gt;): void

Obtains the number of system accounts created. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                        |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the number of created system accounts. If the operation fails, **err** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountCount((err: BusinessError, count: number) => {
      if (err) {
        console.log('getOsAccountCount failed, error: ' + JSON.stringify(err));
      } else {
        console.log('getOsAccountCount successfully, count: ' + count);
      }
    });
  } catch (err) {
    console.log('getOsAccountCount exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountCount<sup>9+</sup>

getOsAccountCount(): Promise&lt;number&gt;

Obtains the number of system accounts created. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                                   |
| --------------------- | -------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of created system accounts.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 201 | Permission denied.|
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountCount().then((count: number) => {
      console.log('getOsAccountCount successfully, count: ' + count);
    }).catch((err: BusinessError) => {
      console.log('getOsAccountCount failed, error: ' + JSON.stringify(err));
    });
  } catch(err) {
    console.log('getOsAccountCount exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountLocalId<sup>9+</sup>

getOsAccountLocalId(callback: AsyncCallback&lt;number&gt;): void

Obtains the ID of the system account to which the current process belongs. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                          |
| -------- | --------------------------- | ---- | ---------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the system account ID obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountLocalId((err: BusinessError, localId: number) => {
      if (err) {
        console.log('getOsAccountLocalId failed, error: ' + JSON.stringify(err));
      } else {
        console.log('getOsAccountLocalId successfully, localId: ' + localId);
      }
    });
  } catch (err) {
    console.log('getOsAccountLocalId exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountLocalId<sup>9+</sup>

getOsAccountLocalId(): Promise&lt;number&gt;

Obtains the ID of the system account to which the current process belongs. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                                     |
| --------------------- | ---------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the system account ID obtained.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountLocalId().then((localId: number) => {
      console.log('getOsAccountLocalId successfully, localId: ' + localId);
    }).catch((err: BusinessError) => {
      console.log('getOsAccountLocalId failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('getOsAccountLocalId exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountLocalIdForUid<sup>9+</sup>

getOsAccountLocalIdForUid(uid: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the system account ID based on the process UID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                   |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------- |
| uid      | number                      | Yes  | Process UID.                                                             |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the system account ID obtained. Otherwise, **data** is an error object.|

**Error codes**

| ID| Error Message        |
| -------- | --------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid uid.    |

**Example**: Obtain the ID of the system account whose process UID is **12345678**.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let uid: number = 12345678;
  try {
    accountManager.getOsAccountLocalIdForUid(uid, (err: BusinessError, localId: number) => {
      if (err) {
        console.log('getOsAccountLocalIdForUid failed, error: ' + JSON.stringify(err));
      }
      console.log('getOsAccountLocalIdForUid successfully, localId: ' + localId);
    });
  } catch (err) {
    console.log('getOsAccountLocalIdForUid exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountLocalIdForUid<sup>9+</sup>

getOsAccountLocalIdForUid(uid: number): Promise&lt;number&gt;

Obtains the system account ID based on the process UID. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name| Type  | Mandatory| Description     |
| ------ | ------ | ---- | --------- |
| uid    | number | Yes  | Process UID.|

**Return value**

| Type                 | Description                                    |
| --------------------- | --------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the system account ID obtained.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid uid. |

**Example**: Obtain the ID of the system account whose process UID is **12345678**.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let uid: number = 12345678;
  try {
    accountManager.getOsAccountLocalIdForUid(uid).then((localId: number) => {
      console.log('getOsAccountLocalIdForUid successfully, localId: ' + localId);
    }).catch((err: BusinessError) => {
      console.log('getOsAccountLocalIdForUid failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('getOsAccountLocalIdForUid exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountLocalIdForUidSync<sup>10+</sup>

getOsAccountLocalIdForUidSync(uid: number): number

Obtains the system account ID based on the process UID. The API returns the result synchronously.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name| Type  | Mandatory| Description     |
| ------ | ------ | ---- | --------- |
| uid    | number | Yes  | Process UID.|

**Return value**

| Type                 | Description                                    |
| --------------------- | --------------------------------------- |
| number | System account ID obtained.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300002 | Invalid uid. |

**Example**: Obtain the ID of the system account whose process UID is **12345678**.

  ```ts
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let uid: number = 12345678;
  try {
    let localId : number = accountManager.getOsAccountLocalIdForUidSync(uid);
    console.log('getOsAccountLocalIdForUidSync successfully, localId: ' + localId);
  } catch (err) {
    console.log('getOsAccountLocalIdForUidSync exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountLocalIdForDomain<sup>9+</sup>

getOsAccountLocalIdForDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;number&gt;): void

Obtains the system account ID based on the domain account information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                   | Mandatory| Description                                                                        |
| ---------- | --------------------------------------- | ---- | -------------------------------------------------------------------------- |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | Yes  | Domain account information.                                                               |
| callback   | AsyncCallback&lt;number&gt;             | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the ID of the system account associated with the domain account. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid domainInfo. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let domainInfo: osAccount.DomainAccountInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountLocalIdForDomain(domainInfo, (err: BusinessError, localId: number) => {
      if (err) {
        console.log('getOsAccountLocalIdForDomain failed, error: ' + JSON.stringify(err));
      } else {
        console.log('getOsAccountLocalIdForDomain successfully, localId: ' + localId);
      }
    });
  } catch (err) {
    console.log('getOsAccountLocalIdForDomain exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountLocalIdForDomain<sup>9+</sup>

getOsAccountLocalIdForDomain(domainInfo: DomainAccountInfo): Promise&lt;number&gt;

Obtains the system account ID based on the domain account information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                   | Mandatory| Description        |
| ---------- | --------------------------------------- | ---- | ------------ |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | Yes  | Domain account information.|

**Return value**

| Type                 | Description                                   |
| :-------------------- | :------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the ID of the system account associated with the domain account.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid domainInfo. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let domainInfo: osAccount.DomainAccountInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  try {
    accountManager.getOsAccountLocalIdForDomain(domainInfo).then((localId: number) => {
      console.log('getOsAccountLocalIdForDomain successfully, localId: ' + localId);
    }).catch((err: BusinessError) => {
      console.log('getOsAccountLocalIdForDomain failed, error: ' + JSON.stringify(err));
    });
  } catch (err) {
    console.log('getOsAccountLocalIdForDomain exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountConstraints<sup>(deprecated)</sup>

getOsAccountConstraints(localId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains all constraints enabled for a system account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                    | Mandatory| Description                                                                                          |
| -------- | ---------------------------------------- | ---- | -------------------------------------------------------------------------------------------- |
| localId  | number                                   | Yes  | ID of the target system account.                                                                                 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is all [constraints](#constraints) obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Obtain all constraints of system account 100.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.getOsAccountConstraints(localId, (err: BusinessError, constraints: string[]) => {
      if (err) {
        console.log('getOsAccountConstraints failed, err: ' + JSON.stringify(err));
      } else {
        console.log('getOsAccountConstraints successfully, constraints: ' + JSON.stringify(constraints));
      }
    });
  } catch (err) {
    console.log('getOsAccountConstraints exception: ' + JSON.stringify(err));
  }
  ```

### getOsAccountConstraints<sup>(deprecated)</sup>

getOsAccountConstraints(localId: number): Promise&lt;Array&lt;string&gt;&gt;

Obtains all constraints enabled for a system account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| localId | number | Yes  | ID of the target system account.|

**Return value**

| Type                              | Description                                                      |
| ---------------------------------- | ---------------------------------------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return all the [constraints](#constraints) enabled for the system account.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Obtain all constraints of system account 100.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.getOsAccountConstraints(localId).then((constraints: string[]) => {
      console.log('getOsAccountConstraints, constraints: ' + constraints);
    }).catch((err: BusinessError) => {
      console.log('getOsAccountConstraints err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getOsAccountConstraints exception: ' + JSON.stringify(e));
  }
  ```

### getActivatedOsAccountLocalIds<sup>9+</sup>

getActivatedOsAccountLocalIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Obtains information about all activated system accounts. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                    | Mandatory| Description                                                  |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is a list of activated system accounts. Otherwise, **data** is an error object.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types.|
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getActivatedOsAccountLocalIds((err: BusinessError, idArray: number[])=>{
      console.log('getActivatedOsAccountLocalIds err:' + JSON.stringify(err));
      console.log('getActivatedOsAccountLocalIds idArray length:' + idArray.length);
      for(let i=0;i<idArray.length;i++) {
        console.info('activated os account id: ' + idArray[i]);
      }
    });
  } catch (e) {
    console.log('getActivatedOsAccountLocalIds exception: ' + JSON.stringify(e));
  }
  ```

### getActivatedOsAccountLocalIds<sup>9+</sup>

getActivatedOsAccountLocalIds(): Promise&lt;Array&lt;number&gt;&gt;

Obtains information about all activated system accounts. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                              | Description                                              |
| :--------------------------------- | :------------------------------------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the information about all activated system accounts.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getActivatedOsAccountLocalIds().then((idArray: number[]) => {
      console.log('getActivatedOsAccountLocalIds, idArray: ' + idArray);
    }).catch((err: BusinessError) => {
      console.log('getActivatedOsAccountLocalIds err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getActivatedOsAccountLocalIds exception: ' + JSON.stringify(e));
  }
  ```

### getCurrentOsAccount<sup>(deprecated)</sup>

getCurrentOsAccount(callback: AsyncCallback&lt;OsAccountInfo&gt;): void

Obtains information about the system account to which the current process belongs. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.GET_LOCAL_ACCOUNTS<sup>10+</sup> (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                                | Mandatory| Description                                          |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the system account information obtained. Otherwise, **data** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getCurrentOsAccount((err: BusinessError, curAccountInfo: osAccount.OsAccountInfo)=>{
      console.log('getCurrentOsAccount err:' + JSON.stringify(err));
      console.log('getCurrentOsAccount curAccountInfo:' + JSON.stringify(curAccountInfo));
    });
  } catch (e) {
    console.log('getCurrentOsAccount exception: ' + JSON.stringify(e));
  }
  ```

### getCurrentOsAccount<sup>(deprecated)</sup>

getCurrentOsAccount(): Promise&lt;OsAccountInfo&gt;

Obtains information about the system account to which the current process belongs. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 9 and deprecated since API version 11. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.GET_LOCAL_ACCOUNTS<sup>10+</sup> (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                                          | Description                                      |
| ---------------------------------------------- | ----------------------------------------- |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise used to return the system account information obtained.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 201 | Permission denied.|
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getCurrentOsAccount().then((accountInfo: osAccount.OsAccountInfo) => {
      console.log('getCurrentOsAccount, accountInfo: ' + JSON.stringify(accountInfo));
    }).catch((err: BusinessError) => {
      console.log('getCurrentOsAccount err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getCurrentOsAccount exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountType<sup>9+</sup>

getOsAccountType(callback: AsyncCallback&lt;OsAccountType&gt;): void

Obtains the type of the account to which the current process belongs. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountType](#osaccounttype)&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the system account type obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountType((err: BusinessError, accountType: osAccount.OsAccountType) => {
      console.log('getOsAccountType err: ' + JSON.stringify(err));
      console.log('getOsAccountType accountType: ' + accountType);
    });
  } catch (e) {
    console.log('getOsAccountType exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountType<sup>9+</sup>

getOsAccountType(): Promise&lt;OsAccountType&gt;

Obtains the type of the account to which the current process belongs. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                                          | Description                                            |
| ---------------------------------------------- | ----------------------------------------------- |
| Promise&lt;[OsAccountType](#osaccounttype)&gt; | Promise used to return the system account type obtained.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountType().then((accountType: osAccount.OsAccountType) => {
      console.log('getOsAccountType, accountType: ' + accountType);
    }).catch((err: BusinessError) => {
      console.log('getOsAccountType err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getOsAccountType exception: ' + JSON.stringify(e));
  }
  ```

### queryDistributedVirtualDeviceId<sup>9+</sup>

queryDistributedVirtualDeviceId(callback: AsyncCallback&lt;string&gt;): void

Queries the ID of the distributed virtual device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications) or ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                  |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------- |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the distributed virtual device ID obtained. Otherwise, **data** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.queryDistributedVirtualDeviceId((err: BusinessError, virtualID: string) => {
      console.log('queryDistributedVirtualDeviceId err: ' + JSON.stringify(err));
      console.log('queryDistributedVirtualDeviceId virtualID: ' + virtualID);
    });
  } catch (e) {
    console.log('queryDistributedVirtualDeviceId exception: ' + JSON.stringify(e));
  }
  ```

### queryDistributedVirtualDeviceId<sup>9+</sup>

queryDistributedVirtualDeviceId(): Promise&lt;string&gt;

Queries the ID of the distributed virtual device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications) or ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                             |
| --------------------- | --------------------------------- |
| Promise&lt;string&gt; | Promise used to return the distributed virtual device ID obtained.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 201 | Permission denied.|
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.queryDistributedVirtualDeviceId().then((virtualID: string) => {
      console.log('queryDistributedVirtualDeviceId, virtualID: ' + virtualID);
    }).catch((err: BusinessError) => {
      console.log('queryDistributedVirtualDeviceId err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('queryDistributedVirtualDeviceId exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountLocalIdForSerialNumber<sup>9+</sup>

getOsAccountLocalIdForSerialNumber(serialNumber: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the system account ID based on the SN. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name      | Type                       | Mandatory| Description                                                                          |
| ------------ | --------------------------- | ---- | ---------------------------------------------------------------------------- |
| serialNumber | number                      | Yes  | Account SN.                                                                   |
| callback     | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the system account ID obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message              |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid serialNumber. |
| 12300003 | The account indicated by serialNumber dose not exist. |

**Example**: Obtain the ID of the system account whose SN is 12345.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let serialNumber: number = 12345;
  try {
    accountManager.getOsAccountLocalIdForSerialNumber(serialNumber, (err: BusinessError, localId: number)=>{
      console.log('ger localId err:' + JSON.stringify(err));
      console.log('get localId:' + localId + ' by serialNumber: ' + serialNumber);
    });
  } catch (e) {
    console.log('ger localId exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountLocalIdForSerialNumber<sup>9+</sup>

getOsAccountLocalIdForSerialNumber(serialNumber: number): Promise&lt;number&gt;

Obtains the system account ID based on the SN. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name      | Type  | Mandatory| Description      |
| ------------ | ------ | ---- | ---------- |
| serialNumber | number | Yes  | Account SN.|

**Return value**

| Type                 | Description                                        |
| --------------------- | -------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the system account ID obtained.|

**Error codes**

| ID| Error Message              |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid serialNumber. |
| 12300003 | The account indicated by serialNumber dose not exist. |

**Example**: Obtain the ID of the system account whose SN is 12345.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let serialNumber: number = 12345;
  try {
    accountManager.getOsAccountLocalIdForSerialNumber(serialNumber).then((localId: number) => {
      console.log('getOsAccountLocalIdForSerialNumber localId: ' + localId);
    }).catch((err: BusinessError) => {
      console.log('getOsAccountLocalIdForSerialNumber err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getOsAccountLocalIdForSerialNumber exception: ' + JSON.stringify(e));
  }
  ```

### getSerialNumberForOsAccountLocalId<sup>9+</sup>

getSerialNumberForOsAccountLocalId(localId: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the SN of a system account based on the account ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                        |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------- |
| localId  | number                      | Yes  | ID of the target system account.                                                                |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the SN obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Obtain the SN of the system account 100.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.getSerialNumberForOsAccountLocalId(localId, (err: BusinessError, serialNumber: number)=>{
      console.log('ger serialNumber err:' + JSON.stringify(err));
      console.log('get serialNumber:' + serialNumber + ' by localId: ' + localId);
    });
  } catch (e) {
    console.log('ger serialNumber exception: ' + JSON.stringify(e));
  }
  ```

### getSerialNumberForOsAccountLocalId<sup>9+</sup>

getSerialNumberForOsAccountLocalId(localId: number): Promise&lt;number&gt;

Obtains the SN of a system account based on the account ID. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description         |
| ------- | ------ | ---- | ----------- |
| localId | number | Yes  | ID of the target system account.|

**Return value**

| Type                 | Description                                   |
| :-------------------- | :------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the SN obtained.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Obtain the SN of the system account 100.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  try {
    accountManager.getSerialNumberForOsAccountLocalId(localId).then((serialNumber: number) => {
      console.log('getSerialNumberForOsAccountLocalId serialNumber: ' + serialNumber);
    }).catch((err: BusinessError) => {
      console.log('getSerialNumberForOsAccountLocalId err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getSerialNumberForOsAccountLocalId exception: ' + JSON.stringify(e));
  }
  ```

### isMultiOsAccountEnable<sup>(deprecated)</sup>

isMultiOsAccountEnable(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether multiple system accounts are supported. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [checkMultiOsAccountEnabled](#checkmultiosaccountenabled9) instead.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                    |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means multiple system accounts are supported; the value **false** means the opposite.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.isMultiOsAccountEnable((err: BusinessError, isEnabled: boolean) => {
    if (err) {
      console.log('isMultiOsAccountEnable failed, error: ' + JSON.stringify(err));
    } else {
    console.log('isMultiOsAccountEnable successfully, isEnabled: ' + isEnabled);
    }
  });
  ```

### isMultiOsAccountEnable<sup>(deprecated)</sup>

isMultiOsAccountEnable(): Promise&lt;boolean&gt;

Checks whether multiple system accounts are supported. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [checkMultiOsAccountEnabled](#checkmultiosaccountenabled9-1) instead.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                  | Description                                                      |
| :--------------------- | :--------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means multiple system accounts are supported; the value **false** means the opposite.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.isMultiOsAccountEnable().then((isEnabled: boolean) => {
    console.log('isMultiOsAccountEnable successfully, isEnabled: ' + isEnabled);
  }).catch((err: BusinessError) => {
    console.log('isMultiOsAccountEnable failed, error: ' + JSON.stringify(err));
  });
  ```

### isOsAccountActived<sup>(deprecated)</sup>

isOsAccountActived(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a system account is activated. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                    |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| localId  | number                       | Yes  | ID of the target system account.                                           |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means the account is activated; the value **false** means the opposite.|

**Example**: Check whether system account 100 is activated.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  accountManager.isOsAccountActived(localId, (err: BusinessError, isActived: boolean) => {
    if (err) {
      console.log('isOsAccountActived failed, err:' + JSON.stringify(err));
    } else {
      console.log('isOsAccountActived successfully, isActived:' + isActived);
    }
  });
  ```

### isOsAccountActived<sup>(deprecated)</sup>

isOsAccountActived(localId: number): Promise&lt;boolean&gt;

Checks whether a system account is activated. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description                              |
| ------- | ------ | ---- | --------------------------------- |
| localId | number | Yes  | ID of the target system account.|

**Return value**

| Type                  | Description                                                       |
| --------------------- | ----------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the account is activated; the value **false** means the opposite.|

**Example**: Check whether system account 100 is activated.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  accountManager.isOsAccountActived(localId).then((isActived: boolean) => {
    console.log('isOsAccountActived successfully, isActived: ' + isActived);
  }).catch((err: BusinessError) => {
    console.log('isOsAccountActived failed, error: ' + JSON.stringify(err));
  });
  ```

### isOsAccountConstraintEnable<sup>(deprecated)</sup>

isOsAccountConstraintEnable(localId: number, constraint: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the specified constraint is enabled for a system account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                        | Mandatory| Description                                                               |
| ---------- | ---------------------------- | ---- | ----------------------------------------------------------------- |
| localId    | number                       | Yes  | ID of the target system account.                                |
| constraint | string                       | Yes  | [Constraint](#constraints) to check.                               |
| callback   | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means the specified constraint is enabled; the value **false** means the opposite.|

**Example**: Check whether system account 100 is forbidden to use Wi-Fi.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  let constraint: string = 'constraint.wifi';
  accountManager.isOsAccountConstraintEnable(localId, constraint, (err: BusinessError, isEnabled: boolean) => {
    if (err) {
      console.log('isOsAccountConstraintEnable failed, error: ' + JSON.stringify(err));
    } else {
      console.log('isOsAccountConstraintEnable successfully, isEnabled: ' + isEnabled);
    }
  });
  ```

### isOsAccountConstraintEnable<sup>(deprecated)</sup>

isOsAccountConstraintEnable(localId: number, constraint: string): Promise&lt;boolean&gt;

Checks whether the specified constraint is enabled for a system account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type  | Mandatory| Description                                |
| ---------- | ------ | ---- | ---------------------------------- |
| localId    | number | Yes  | ID of the target system account. |
| constraint | string | Yes  | [Constraint](#constraints) to check.|

**Return value**

| Type                  | Description                                                                  |
| ---------------------- | --------------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the specified constraint is enabled; the value **false** means the opposite.|

**Example**: Check whether system account 100 is forbidden to use Wi-Fi.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  let constraint: string = 'constraint.wifi';
  accountManager.isOsAccountConstraintEnable(localId, constraint).then((isEnabled: boolean) => {
    console.log('isOsAccountConstraintEnable successfully, isEnabled: ' + isEnabled);
  }).catch((err: BusinessError) => {
    console.log('isOsAccountConstraintEnable err: ' + JSON.stringify(err));
  });
  ```

### isTestOsAccount<sup>(deprecated)</sup>

isTestOsAccount(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this system account is a test account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [checkOsAccountTestable](#checkosaccounttestable9) instead.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                                  |
| -------- | ---------------------------- | ---- | --------------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means the account is a test account; the value **false** means the opposite.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.isTestOsAccount((err: BusinessError, isTestable: boolean) => {
    if (err) {
      console.log('isTestOsAccount failed, error: ' + JSON.stringify(err));
    } else {
      console.log('isTestOsAccount successfully, isTestable: ' + isTestable);
    }
  });
  ```

### isTestOsAccount<sup>(deprecated)</sup>

isTestOsAccount(): Promise&lt;boolean&gt;

Checks whether this system account is a test account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [checkOsAccountTestable](#checkosaccounttestable9-1) instead.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                  | Description                                                                     |
| ---------------------- | ------------------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the account is a test account; the value **false** means the opposite.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
    accountManager.isTestOsAccount().then((isTestable: boolean) => {
      console.log('isTestOsAccount successfully, isTestable: ' + isTestable);
    }).catch((err: BusinessError) => {
      console.log('isTestOsAccount failed, error: ' + JSON.stringify(err));
  });
  ```

### isOsAccountVerified<sup>(deprecated)</sup>

isOsAccountVerified(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this system account has been verified. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [checkOsAccountVerified](#checkosaccountverifieddeprecated).

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                           |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means the system account has been verified; the value **false** means the opposite.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.isOsAccountVerified((err: BusinessError, isVerified: boolean) => {
    if (err) {
      console.log('isOsAccountVerified failed, error: ' + JSON.stringify(err));
    } else {
      console.log('isOsAccountVerified successfully, isVerified: ' + isVerified);
    }
  });
  ```

### isOsAccountVerified<sup>(deprecated)</sup>

isOsAccountVerified(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether a system account has been verified. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                           |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------- |
| localId  | number                       | Yes  | ID of the target system account.                            |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback used to return the result. The value **true** means the system account has been verified; the value **false** means the opposite.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  accountManager.isOsAccountVerified(localId, (err: BusinessError, isVerified: boolean) => {
    if (err) {
      console.log('isOsAccountVerified failed, error: ' + JSON.stringify(err));
    } else {
      console.log('isOsAccountVerified successfully, isVerified: ' + isVerified);
    }
  });
  ```

### isOsAccountVerified<sup>(deprecated)</sup>

isOsAccountVerified(localId?: number): Promise&lt;boolean&gt;

Checks whether a system account has been verified. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description                                                             |
| ------- | ------ | ---- | ---------------------------------------------------------------- |
| localId | number | No  | ID of the target system account. If this parameter is not specified, this API checks whether the current system account has been verified.|

**Return value**

| Type                  | Description                                                              |
| ---------------------- | ----------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the system account has been verified; the value **false** means the opposite.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.isOsAccountVerified().then((isVerified: boolean) => {
    console.log('isOsAccountVerified successfully, isVerified: ' + isVerified);
  }).catch((err: BusinessError) => {
    console.log('isOsAccountVerified failed, error: ' + JSON.stringify(err));
  });
  ```

### getCreatedOsAccountsCount<sup>(deprecated)</sup>

getCreatedOsAccountsCount(callback: AsyncCallback&lt;number&gt;): void

Obtains the number of system accounts created. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [getOsAccountCount](#getosaccountcount9) instead.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                        |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the number of created system accounts. If the operation fails, **err** is an error object.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getCreatedOsAccountsCount((err: BusinessError, count: number)=>{
    if (err) {
      console.log('getCreatedOsAccountsCount failed, error: ' + JSON.stringify(err));
    } else {
      console.log('getCreatedOsAccountsCount successfully, count: ' + count);
    }
  });
  ```

### getCreatedOsAccountsCount<sup>(deprecated)</sup>

getCreatedOsAccountsCount(): Promise&lt;number&gt;

Obtains the number of system accounts created. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [getOsAccountCount](#getosaccountcount9-1) instead.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                                   |
| --------------------- | -------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of created system accounts.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getCreatedOsAccountsCount().then((count: number) => {
    console.log('getCreatedOsAccountsCount successfully, count: ' + count);
  }).catch((err: BusinessError) => {
    console.log('getCreatedOsAccountsCount failed, error: ' + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromProcess<sup>(deprecated)</sup>

getOsAccountLocalIdFromProcess(callback: AsyncCallback&lt;number&gt;): void

Obtains the ID of the system account to which the current process belongs. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [getOsAccountLocalId](#getosaccountlocalid9) instead.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                          |
| -------- | --------------------------- | ---- | ---------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the system account ID obtained. Otherwise, **err** is an error object.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromProcess((err: BusinessError, localId: number) => {
    if (err) {
      console.log('getOsAccountLocalIdFromProcess failed, error: ' + JSON.stringify(err));
    } else {
      console.log('getOsAccountLocalIdFromProcess failed, error: ' + localId);
    }
  });
  ```

### getOsAccountLocalIdFromProcess<sup>(deprecated)</sup>

getOsAccountLocalIdFromProcess(): Promise&lt;number&gt;

Obtains the ID of the system account to which the current process belongs. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [getOsAccountLocalId](#getosaccountlocalid9-1) instead.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                                     |
| :-------------------- | :--------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the system account ID obtained.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromProcess().then((localId: number) => {
    console.log('getOsAccountLocalIdFromProcess successfully, localId: ' + localId);
  }).catch((err: BusinessError) => {
    console.log('getOsAccountLocalIdFromProcess failed, error: ' + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromUid<sup>(deprecated)</sup>

getOsAccountLocalIdFromUid(uid: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the system account ID based on the process UID. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [getOsAccountLocalIdForUid](#getosaccountlocalidforuid9) instead.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                   |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------- |
| uid      | number                      | Yes  | Process UID.                                                             |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the system account ID obtained. Otherwise, **data** is an error object.|

**Example**: Obtain the ID of the system account whose process UID is **12345678**.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let uid: number = 12345678;
  accountManager.getOsAccountLocalIdFromUid(uid, (err: BusinessError, localId: number) => {
    if (err) {
      console.log('getOsAccountLocalIdFromUid failed, error: ' + JSON.stringify(err));
    } else {
      console.log('getOsAccountLocalIdFromUid successfully, localId: ' + localId);
    }
  });
  ```

### getOsAccountLocalIdFromUid<sup>(deprecated)</sup>

getOsAccountLocalIdFromUid(uid: number): Promise&lt;number&gt;

Obtains the system account ID based on the process UID. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [getOsAccountLocalIdForUid](#getosaccountlocalidforuid9-1) instead.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name| Type  | Mandatory| Description     |
| ------ | ------ | ---- | --------- |
| uid    | number | Yes  | Process UID.|

**Return value**

| Type                 | Description                                 |
| :-------------------- | :----------------------------------- |
| Promise&lt;number&gt; | Promise used to return the system account ID obtained.|

**Example**: Obtain the ID of the system account whose process UID is **12345678**.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let uid: number = 12345678;
  accountManager.getOsAccountLocalIdFromUid(uid).then((localId: number) => {
    console.log('getOsAccountLocalIdFromUid successfully, localId: ' + localId);
  }).catch((err: BusinessError) => {
    console.log('getOsAccountLocalIdFromUid failed, error: ' + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromDomain<sup>(deprecated)</sup>

getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;number&gt;): void

Obtains the system account ID based on the domain account information. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. Use [getOsAccountLocalIdForDomain](#getosaccountlocalidfordomain9) instead.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                   | Mandatory| Description                                                                        |
| ---------- | --------------------------------------- | ---- | --------------------------------------------------------------------------- |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | Yes  | Domain account information.                                                               |
| callback   | AsyncCallback&lt;number&gt;             | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the system account ID obtained. Otherwise, **err** is an error object.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let domainInfo: osAccount.DomainAccountInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromDomain(domainInfo, (err: BusinessError, localId: number) => {
    if (err) {
      console.log('getOsAccountLocalIdFromDomain failed, error: ' + JSON.stringify(err));
    } else {
      console.log('getOsAccountLocalIdFromDomain successfully, localId: ' + localId);
    }
  });
  ```

### getOsAccountLocalIdFromDomain<sup>(deprecated)</sup>

getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo): Promise&lt;number&gt;

Obtains the system account ID based on the domain account information. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. Use [getOsAccountLocalIdForDomain](#getosaccountlocalidfordomain9-1) instead.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                   | Mandatory| Description        |
| ---------- | --------------------------------------- | ---- | ------------ |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | Yes  | Domain account information.|

**Return value**

| Type                 | Description                                   |
| :-------------------- | :------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the ID of the system account associated with the domain account.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let domainInfo: osAccount.DomainAccountInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  accountManager.getOsAccountLocalIdFromDomain(domainInfo).then((localId: number) => {
    console.log('getOsAccountLocalIdFromDomain successfully, localId: ' + localId);
  }).catch((err: BusinessError) => {
    console.log('getOsAccountLocalIdFromDomain failed, error: ' + JSON.stringify(err));
  });
  ```

### getOsAccountAllConstraints<sup>(deprecated)</sup>

getOsAccountAllConstraints(localId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains all constraints enabled for a system account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                    | Mandatory| Description                                                                                            |
| -------- | ---------------------------------------- | ---- | ---------------------------------------------------------------------------------------------- |
| localId  | number                                   | Yes  | ID of the target system account.                                                                                   |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is a list of all [constraints](#constraints) enabled for the system account. Otherwise, **err** is an error object.|

**Example**: Obtain all constraints of system account 100.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  accountManager.getOsAccountAllConstraints(localId, (err: BusinessError, constraints: string[])=>{
    console.log('getOsAccountAllConstraints err:' + JSON.stringify(err));
    console.log('getOsAccountAllConstraints:' + JSON.stringify(constraints));
  });
  ```

### getOsAccountAllConstraints<sup>(deprecated)</sup>

getOsAccountAllConstraints(localId: number): Promise&lt;Array&lt;string&gt;&gt;

Obtains all constraints enabled for a system account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| localId | number | Yes  | ID of the target system account.|

**Return value**

| Type                              | Description                                                        |
| :--------------------------------- | :----------------------------------------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return all the [constraints](#constraints) enabled for the system account.|

**Example**: Obtain all constraints of system account 100.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  accountManager.getOsAccountAllConstraints(localId).then((constraints: string[]) => {
    console.log('getOsAccountAllConstraints, constraints: ' + constraints);
  }).catch((err: BusinessError) => {
    console.log('getOsAccountAllConstraints err: ' + JSON.stringify(err));
  });
  ```

### queryActivatedOsAccountIds<sup>(deprecated)</sup>

queryActivatedOsAccountIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Obtains information about all activated system accounts. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. Use [getActivatedOsAccountLocalIds](#getactivatedosaccountlocalids9) instead.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                    | Mandatory| Description                                                  |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is a list of activated system accounts. Otherwise, **data** is an error object.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.queryActivatedOsAccountIds((err: BusinessError, idArray: number[])=>{
    console.log('queryActivatedOsAccountIds err:' + JSON.stringify(err));
    console.log('queryActivatedOsAccountIds idArray length:' + idArray.length);
    for(let i=0;i<idArray.length;i++) {
      console.info('activated os account id: ' + idArray[i]);
    }
  });
  ```

### queryActivatedOsAccountIds<sup>(deprecated)</sup>

queryActivatedOsAccountIds(): Promise&lt;Array&lt;number&gt;&gt;

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. Use [getActivatedOsAccountLocalIds](#getactivatedosaccountlocalids9-1) instead.

Obtains information about all activated system accounts. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                              | Description                                              |
| ---------------------------------- | ------------------------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the information about all activated system accounts.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.queryActivatedOsAccountIds().then((idArray: number[]) => {
    console.log('queryActivatedOsAccountIds, idArray: ' + idArray);
  }).catch((err: BusinessError) => {
    console.log('queryActivatedOsAccountIds err: ' + JSON.stringify(err));
  });
  ```

### queryCurrentOsAccount<sup>(deprecated)</sup>

queryCurrentOsAccount(callback: AsyncCallback&lt;OsAccountInfo&gt;): void

Obtains information about the system account to which the current process belongs. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                                | Mandatory| Description                                          |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the system account information obtained. Otherwise, **data** is an error object.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.queryCurrentOsAccount((err: BusinessError, curAccountInfo: osAccount.OsAccountInfo)=>{
    console.log('queryCurrentOsAccount err:' + JSON.stringify(err));
    console.log('queryCurrentOsAccount curAccountInfo:' + JSON.stringify(curAccountInfo));
  });
  ```

### queryCurrentOsAccount<sup>(deprecated)</sup>

queryCurrentOsAccount(): Promise&lt;OsAccountInfo&gt;

Obtains information about the system account to which the current process belongs. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. The substitute API is available only to system applications.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                                          | Description                                      |
| ---------------------------------------------- | ------------------------------------------ |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise used to return the system account information obtained.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.queryCurrentOsAccount().then((accountInfo: osAccount.OsAccountInfo) => {
    console.log('queryCurrentOsAccount, accountInfo: ' + JSON.stringify(accountInfo));
  }).catch((err: BusinessError) => {
    console.log('queryCurrentOsAccount err: ' + JSON.stringify(err));
  });
  ```

### getOsAccountTypeFromProcess<sup>(deprecated)</sup>

getOsAccountTypeFromProcess(callback: AsyncCallback&lt;OsAccountType&gt;): void

Obtains the type of the account to which the current process belongs. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [getOsAccountType](#getosaccounttype9) instead.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountType](#osaccounttype)&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the system account type obtained. Otherwise, **err** is an error object.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getOsAccountTypeFromProcess((err: BusinessError, accountType: osAccount.OsAccountType) => {
    console.log('getOsAccountTypeFromProcess err: ' + JSON.stringify(err));
    console.log('getOsAccountTypeFromProcess accountType: ' + accountType);
  });
  ```

### getOsAccountTypeFromProcess<sup>(deprecated)</sup>

getOsAccountTypeFromProcess(): Promise&lt;OsAccountType&gt;

Obtains the type of the account to which the current process belongs. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [getOsAccountType](#getosaccounttype9-1) instead.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                                          | Description                                           |
| ---------------------------------------------- | ----------------------------------------------- |
| Promise&lt;[OsAccountType](#osaccounttype)&gt; | Promise used to return the system account type obtained.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getOsAccountTypeFromProcess().then((accountType: osAccount.OsAccountType) => {
    console.log('getOsAccountTypeFromProcess, accountType: ' + accountType);
  }).catch((err: BusinessError) => {
    console.log('getOsAccountTypeFromProcess err: ' + JSON.stringify(err));
  });
  ```

### getDistributedVirtualDeviceId<sup>(deprecated)</sup>

getDistributedVirtualDeviceId(callback: AsyncCallback&lt;string&gt;): void

Obtains the ID of this distributed virtual device. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [queryDistributedVirtualDeviceId](#querydistributedvirtualdeviceid9) instead.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications) or ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                   |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------- |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the distributed virtual device ID obtained. Otherwise, **data** is an error object.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getDistributedVirtualDeviceId((err: BusinessError, virtualID: string) => {
    console.log('getDistributedVirtualDeviceId err: ' + JSON.stringify(err));
    console.log('getDistributedVirtualDeviceId virtualID: ' + virtualID);
  });
  ```

### getDistributedVirtualDeviceId<sup>(deprecated)</sup>

getDistributedVirtualDeviceId(): Promise&lt;string&gt;

Obtains the ID of this distributed virtual device. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. Use [queryDistributedVirtualDeviceId](#querydistributedvirtualdeviceid9-1) instead.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications) or ohos.permission.DISTRIBUTED_DATASYNC

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                             |
| --------------------- | --------------------------------- |
| Promise&lt;string&gt; | Promise used to return the distributed virtual device ID obtained.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  accountManager.getDistributedVirtualDeviceId().then((virtualID: string) => {
    console.log('getDistributedVirtualDeviceId, virtualID: ' + virtualID);
  }).catch((err: BusinessError) => {
    console.log('getDistributedVirtualDeviceId err: ' + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdBySerialNumber<sup>(deprecated)</sup>

getOsAccountLocalIdBySerialNumber(serialNumber: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the system account ID based on the SN. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. Use [getOsAccountLocalIdForSerialNumber](#getosaccountlocalidforserialnumber9) instead.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name      | Type                       | Mandatory| Description                                                                              |
| ------------ | --------------------------- | ---- | -------------------------------------------------------------------------------- |
| serialNumber | number                      | Yes  | Account SN.                                                                       |
| callback     | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the system account ID obtained. Otherwise, **err** is an error object.|

**Example**: Obtain the ID of the system account whose SN is 12345.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let serialNumber: number = 12345;
  accountManager.getOsAccountLocalIdBySerialNumber(serialNumber, (err: BusinessError, localId: number)=>{
    console.log('ger localId err:' + JSON.stringify(err));
    console.log('get localId:' + localId + ' by serialNumber: ' + serialNumber);
  });
  ```

### getOsAccountLocalIdBySerialNumber<sup>(deprecated)</sup>

getOsAccountLocalIdBySerialNumber(serialNumber: number): Promise&lt;number&gt;

Obtains the system account ID based on the SN. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. Use [getOsAccountLocalIdForSerialNumber](#getosaccountlocalidforserialnumber9-1) instead.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name      | Type  | Mandatory| Description      |
| ------------ | ------ | ---- | ---------- |
| serialNumber | number | Yes  | Account SN.|

**Return value**

| Type                 | Description                                                        |
| --------------------- | -------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the system account ID obtained.|

**Example**: Obtain the ID of the system account whose SN is 12345.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let serialNumber: number = 12345;
  accountManager.getOsAccountLocalIdBySerialNumber(serialNumber).then((localId: number) => {
    console.log('getOsAccountLocalIdBySerialNumber localId: ' + localId);
  }).catch((err: BusinessError) => {
    console.log('getOsAccountLocalIdBySerialNumber err: ' + JSON.stringify(err));
  });
  ```

### getSerialNumberByOsAccountLocalId<sup>(deprecated)</sup>

getSerialNumberByOsAccountLocalId(localId: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the SN of a system account based on the account ID. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. Use [getSerialNumberForOsAccountLocalId](#getserialnumberforosaccountlocalid9) instead.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                        |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------------- |
| localId  | number                      | Yes  | ID of the target system account.                                                                |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback used to return the result. If the operation is successful, **err** is **null** and **data** is the SN obtained. Otherwise, **err** is an error object.|

**Example**: Obtain the SN of the system account 100.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  accountManager.getSerialNumberByOsAccountLocalId(localId, (err: BusinessError, serialNumber: number)=>{
    console.log('ger serialNumber err:' + JSON.stringify(err));
    console.log('get serialNumber:' + serialNumber + ' by localId: ' + localId);
  });
  ```

### getSerialNumberByOsAccountLocalId<sup>(deprecated)</sup>

getSerialNumberByOsAccountLocalId(localId: number): Promise&lt;number&gt;

Obtains the SN of a system account based on the account ID. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. Use [getSerialNumberForOsAccountLocalId](#getserialnumberforosaccountlocalid9-1) instead.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description         |
| ------- | ------ | ---- | ----------- |
| localId | number | Yes  | ID of the target system account.|

**Return value**

| Type                 | Description                                   |
| --------------------- | -------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the SN obtained.|

**Example**: Obtain the SN of the system account 100.

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  accountManager.getSerialNumberByOsAccountLocalId(localId).then((serialNumber: number) => {
    console.log('getSerialNumberByOsAccountLocalId serialNumber: ' + serialNumber);
  }).catch((err: BusinessError) => {
    console.log('getSerialNumberByOsAccountLocalId err: ' + JSON.stringify(err));
  });
  ```

### getOsAccountName<sup>12+</sup>

getOsAccountName(): Promise&lt;string&gt;

Obtains the name of the system account of the caller. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                     | Description                    |
| :------------------------ | ----------------------- |
| Promise&lt;string&gt; | Promise used to return the system account name obtained.|

**Error codes**

| ID| Error Message                    |
| -------- | --------------------------- |
| 12300001 | The system service works abnormally. |

**Example**
  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getOsAccountName().then((name: string) => {
      console.log('getOsAccountName, name: ' + name);
    }).catch((err: BusinessError) => {
      console.log('getOsAccountName err: ' + err);
    });
  } catch (e) {
    console.log('getOsAccountName exception: ' + e);
  }
  ```

### getForegroundOsAccountLocalId<sup>15+</sup>

getForegroundOsAccountLocalId(): Promise&lt;number&gt;;

Obtains the ID of the foreground system account.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                  | Description                                                              |
| ---------------------- | ----------------------------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | The system service works abnormally. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  try {
    accountManager.getForegroundOsAccountLocalId().then((localId: number) => {
      console.log('getForegroundOsAccountLocalId, localId: ' + localId);
    }).catch((err: BusinessError) => {
      console.log('getForegroundOsAccountLocalId err: ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getForegroundOsAccountLocalId exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountDomainInfo<sup>15+</sup>

getOsAccountDomainInfo(localId: number): Promise&lt;DomainAccountInfo&gt;;

Obtains the domain account information associated with a specified system account.

**Required permissions**: ohos.permission.GET_DOMAIN_ACCOUNTS and ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS (available to system applications and enterprise applications)

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                  | Description                                                              |
| ---------------------- | ----------------------------------------------------------------- |
| Promise&lt;DomainAccountInfo&gt; | Promise used to return the result.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 201 | Permission denied. |
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | The system service works abnormally. |
| 12300003 | OS account not found. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';
  let accountManager: osAccount.AccountManager = osAccount.getAccountManager();
  let localId: number = 100;
  accountManager.getOsAccountDomainInfo(localId).then((domainAccountInfo: osAccount.DomainAccountInfo) => {
    if (domainAccountInfo === null) {
      console.log('The target OS account is not a domain account.')
    } else {
      console.log('getOsAccountDomainInfo domain: ' + domainAccountInfo.domain);
      console.log('getOsAccountDomainInfo accountName: ' + domainAccountInfo.accountName);
    }
  }).catch((err: BusinessError) => {
    console.log('getOsAccountDomainInfo err: ' + JSON.stringify(err));
  })
  ```

## OsAccountInfo

Represents information about a system account.

**System capability**: SystemCapability.Account.OsAccount

| Name                        | Type                                                        | Mandatory| Description                             |
| ------------------------------ | ------------------------------------------------------------ | ---- | --------------------------------- |
| localId                        | number                                                       | Yes  | ID of the system account.                     |
| localName                      | string                                                       | Yes  | Name of the system account.                   |
| type                           | [OsAccountType](#osaccounttype)                              | Yes  | Type of the system account.                     |
| constraints                    | Array&lt;string&gt;                                          | Yes  | [Constraints](#constraints) of the system account. By default, no value is passed in.|
| isVerified<sup>(deprecated)</sup> | boolean                                                   | Yes  | Whether the account has been verified.<br>**NOTE**<br/>This parameter is supported since API version 7 and deprecated since API version 11.                    |
| isUnlocked<sup>11+</sup>      | boolean                                                       | Yes  | Whether the account is unlocked (whether the **el2/** directory is decrypted).                     |
| photo<sup>8+</sup>             | string                                                       | Yes  | Avatar of the system account. By default, no value is passed in.                     |
| createTime<sup>8+</sup>        | number                                                       | Yes  | Time when the system account was created.                 |
| lastLoginTime<sup>8+</sup>     | number                                                       | Yes  | Last login time of the system account. By default, no value is passed in.         |
| serialNumber<sup>8+</sup>      | number                                                       | Yes  | SN of the system account.                     |
| isActived<sup>(deprecated)</sup>         | boolean                                            | Yes  | Whether the system account is activated.<br>**NOTE**<br/>This parameter is supported since API version 7 and deprecated since API version 11.                 |
| isActivated<sup>11+</sup>         | boolean                                                   | Yes  | Whether the system account is activated.                 |
| isCreateCompleted<sup>8+</sup> | boolean                                                      | Yes  | Whether the system account information is complete.             |
| distributedInfo                | [distributedAccount.DistributedInfo](js-apis-distributed-account.md#distributedinfo) | Yes  | Distributed account information. By default, no value is passed in.                   |
| domainInfo<sup>8+</sup>        | [DomainAccountInfo](#domainaccountinfo8)                      | Yes  | Domain account information. By default, no value is passed in.                       |

## DomainAccountInfo<sup>8+</sup>

Represents the domain account information.

**System capability**: SystemCapability.Account.OsAccount

| Name     | Type  | Mandatory| Description      |
| ----------- | ------ | ---- | ---------- |
| domain      | string | Yes  | Domain name.    |
| accountName | string | Yes  | Domain account name.|

## Constraints

| Constraint                                 | Description                          |
| ------------------------------------- | ------------------------------ |
| constraint.wifi                       | Disallow the use of Wi-Fi.                 |
| constraint.wifi.set                   | Disallow setting of Wi-Fi.                 |
| constraint.locale.set                 | Disallow setting of the language to use.              |
| constraint.app.accounts               | Disallow adding or deletion of app accounts.        |
| constraint.apps.install               | Disallow app installation.                  |
| constraint.apps.uninstall             | Disallow app uninstallation.                  |
| constraint.location.shared            | Disallow location sharing.              |
| constraint.unknown.sources.install    | Disallow installation of apps from unknown sources.        |
| constraint.global.unknown.app.install | Disallow installation of apps from unknown sources for all users.|
| constraint.bluetooth.set              | Disallow setting of Bluetooth.                  |
| constraint.bluetooth | Disallow the use of Bluetooth.|
| constraint.bluetooth.share | Disallow Bluetooth sharing.|
| constraint.usb.file.transfer | Disallow file transfer over USB.|
| constraint.credentials.set | Disallow setting of user credentials.|
| constraint.os.account.remove | Disallow removal of users.|
| constraint.managed.profile.remove | Disallow removal of the managed profiles of this user.|
| constraint.debug.features.use | Disallow the use of debugging features.|
| constraint.vpn.set | Disallow setting of VPN.|
| constraint.date.time.set | Disallow setting of date, time, or time zone.|
| constraint.tethering.config | Disallow setting of Tethering.|
| constraint.network.reset | Disallow reset of network settings.|
| constraint.factory.reset | Disallow reset to factory settings.|
| constraint.os.account.create | Disallow creation of new users.|
| constraint.add.managed.profile | Disallow addition of managed profiles.|
| constraint.apps.verify.disable | Disallow app verification from being disabled.|
| constraint.cell.broadcasts.set | Disallow setting of cell broadcasts.|
| constraint.mobile.networks.set | Disallow setting of mobile networks.|
| constraint.control.apps | Disallow modification of apps in **Settings** or the boot module.|
| constraint.physical.media | Disallow mounting of external physical media.|
| constraint.microphone | Disallow the use of microphones.|
| constraint.microphone.unmute | Disallow unmuting of the microphone.|
| constraint.volume.adjust | Disallow adjustment of the volume.|
| constraint.calls.outgoing | Disallow outgoing calls.|
| constraint.sms.use | Disallow the use of the short message service (SMS).|
| constraint.fun | Disallow the use of entertainment features.|
| constraint.windows.create | Disallow creation of the windows other than app windows.|
| constraint.system.error.dialogs | Disallow display of error dialogs for crashed or unresponsive apps.|
| constraint.cross.profile.copy.paste | Disallow pasting of clipboard content to other users or profiles.|
| constraint.beam.outgoing | Disallow the use of Near Field Communications (NFC) to transfer data from apps.|
| constraint.wallpaper | Disallow wallpaper management.|
| constraint.safe.boot | Disallow reboot of the device in safe boot mode.|
| constraint.parent.profile.app.linking | Disallow the app in the parent profile from handling web links from the managed profiles.|
| constraint.audio.record | Disallow audio recording.|
| constraint.camera.use | Disallow the use of cameras.|
| constraint.os.account.background.run | Disallow background system accounts.|
| constraint.data.roam | Disallow the use of cellular data when roaming.|
| constraint.os.account.set.icon | Disallow setting of user icons.|
| constraint.wallpaper.set | Disallow setting of wallpapers.|
| constraint.oem.unlock | Disallow the use of OEM unlock.|
| constraint.device.unmute | Disallow unmuting of the device.|
| constraint.password.unified | Disallow the use of the unified lock screen challenge for the managed profile with the primary user.|
| constraint.autofill | Disallow the use of the autofill service.|
| constraint.content.capture | Disallow capturing of the screen content.|
| constraint.content.suggestions | Disallow receiving of content suggestions.|
| constraint.os.account.activate | Disallow activating of system accounts in the foreground.|
| constraint.location.set | Disallow setting of the location service.|
| constraint.airplane.mode.set | Disallow setting of the airplane mode.|
| constraint.brightness.set | Disallow setting of the brightness.|
| constraint.share.into.profile | Disallow sharing of files, images, and data of the primary user to the managed profiles.|
| constraint.ambient.display | Disallow display of the ambient environment.|
| constraint.screen.timeout.set | Disallow setting of the screen-off timeout.|
| constraint.print | Disallow printing.|
| constraint.private.dns.set | Disallow setting of the private domain name server (DNS).|
