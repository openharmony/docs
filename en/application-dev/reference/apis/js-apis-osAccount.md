# OS Account Management

The **osAccount** module provides basic capabilities for managing OS accounts, including adding, deleting, querying, setting, subscribing to, and enabling an OS account.

> **NOTE**<br>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.


## Modules to Import

```js
import account_osAccount from '@ohos.account.osAccount';
```

## account_osAccount.getAccountManager

getAccountManager(): AccountManager

Obtains an **AccountManager** instance.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                             | Description             |
| --------------------------------- | ---------------- |
| [AccountManager](#accountmanager) | **AccountManager** instance obtained.|

**Example**
  ```js
  let accountManager = account_osAccount.getAccountManager();
  ```

## OsAccountType

Enumerates the OS account types.

**System capability**: SystemCapability.Account.OsAccount

| Name  | Value| Description        |
| ------ | ------ | ----------- |
| ADMIN  | 0      | Administrator account|
| NORMAL | 1      | Normal account  |
| GUEST  | 2      | Guest account  |

## AccountManager

Provides APIs for managing OS accounts.

### activateOsAccount

activateOsAccount(localId: number, callback: AsyncCallback&lt;void&gt;): void

Activates an OS account. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                      | Mandatory| Description                                               |
| -------- | ------------------------- | ---- | -------------------------------------------------- |
| localId  | number                    | Yes  | ID of the target OS account.                 |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |
| 12300009 | Account has been activated. |

**Example**: Activate OS account 100.
  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.activateOsAccount(localId, (err)=>{
      if (err) {
        console.log("activateOsAccount failed, error:" + JSON.stringify(err));
      } else {
        console.log("activateOsAccount successfully");
      }
    });
  } catch (err) {
    console.log("activateOsAccount exception:" + JSON.stringify(err));
  }
  ```

### activateOsAccount

activateOsAccount(localId: number): Promise&lt;void&gt;

Activates an OS account. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description                |
| ------- | ------ | ---- | -------------------- |
| localId | number | Yes  | ID of the target OS account.|

**Return value**

| Type               | Description                                 |
| ------------------- | ------------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |
| 12300009 | Account has been activated. |

**Example**: Activate OS account 100.
  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.activateOsAccount(localId).then(() => {
      console.log('activateOsAccount successfully');
    }).catch((err) => {
      console.log('activateOsAccount failed, err:' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('activateOsAccount exception:' + JSON.stringify(e));
  }
  ```

### checkMultiOsAccountEnabled<sup>9+</sup>

checkMultiOsAccountEnabled(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether multiple OS accounts are supported. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                    |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the result. The value **true** means multiple OS accounts are supported; the value false means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.checkMultiOsAccountEnabled((err, isEnabled) => {
      if (err) {
        console.log("checkMultiOsAccountEnabled failed, error: " + JSON.stringify(err));
      } else {
      console.log("checkMultiOsAccountEnabled successfully, isEnabled: " + isEnabled);
      }
    });
  } catch (err) {
    console.log("checkMultiOsAccountEnabled exception: " + JSON.stringify(err));
  }
  ```

### checkMultiOsAccountEnabled<sup>9+</sup>

checkMultiOsAccountEnabled(): Promise&lt;boolean&gt;

Checks whether multiple OS accounts are supported. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                  | Description                                                       |
| :--------------------- | :--------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means multiple OS accounts are supported; the value false means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  try {
    let accountManager = account_osAccount.getAccountManager();
    accountManager.checkMultiOsAccountEnabled().then((isEnabled) => {
      console.log('checkMultiOsAccountEnabled successfully, isEnabled: ' + isEnabled);
    }).catch((err) => {
      console.log('checkMultiOsAccountEnabled failed, error: '  + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkMultiOsAccountEnabled exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountActivated<sup>9+</sup>

checkOsAccountActivated(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether an OS account is activated. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                    |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| localId  | number                       | Yes  | ID of the target OS account.                                            |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the result. The value **true** means the account is activated; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Check whether OS account 100 is activated.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.checkOsAccountActivated(localId, (err, isActivated) => {
      if (err) {
        console.log('checkOsAccountActivated failed, error:' + JSON.stringify(err));
      } else {
        console.log('checkOsAccountActivated successfully, isActivated:' + isActivated);
      }
    });
  } catch (err) {
    console.log('checkOsAccountActivated exception:' + JSON.stringify(err));
  }
  ```

### checkOsAccountActivated<sup>9+</sup>

checkOsAccountActivated(localId: number): Promise&lt;boolean&gt;

Checks whether an OS account is activated. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description                              |
| ------- | ------ | ---- | --------------------------------- |
| localId | number | Yes  | ID of the target OS account.|

**Return value**

| Type                  | Description                                                      |
| ---------------------- | ---------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the account is activated; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Check whether OS account 100 is activated.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.checkOsAccountActivated(localId).then((isActivated) => {
      console.log('checkOsAccountActivated successfully, isActivated: ' + isActivated);
    }).catch((err) => {
      console.log('checkOsAccountActivated failed, error: '  + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkOsAccountActivated exception:' + JSON.stringify(err));
  }
  ```

### checkConstraintEnabled<sup>9+</sup>

checkConstraintEnabled(localId: number, constraint: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the specified constraint is enabled for an OS account. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                        | Mandatory| Description                                                              |
| ---------- | ---------------------------- | ---- | ----------------------------------------------------------------- |
| localId    | number                       | Yes  | ID of the target OS account.                                |
| constraint | string                       | Yes  | [Constraint](#constraints) to check.                               |
| callback   | AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the result. The value **true** means the specified constraint is enabled; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Check whether OS account 100 is forbidden to use Wi-Fi.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let constraint = "constraint.wifi";
  try {
    accountManager.checkConstraintEnabled(localId, constraint, (err, isEnabled)=>{
      if (err) {
        console.log("checkConstraintEnabled failed, error: " + JSON.stringify(err));
      } else {
        console.log("checkConstraintEnabled successfully, isEnabled: " + isEnabled);
      }
    });
  } catch (err) {
    console.log("checkConstraintEnabled exception: " + JSON.stringify(err));
  }
  ```

### checkConstraintEnabled<sup>9+</sup>

checkConstraintEnabled(localId: number, constraint: string): Promise&lt;boolean&gt;

Checks whether the specified constraint is enabled for an OS account. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type  | Mandatory| Description                               |
| ---------- | ------ | ---- | ---------------------------------- |
| localId    | number | Yes  | ID of the target OS account. |
| constraint | string | Yes  | [Constraint](#constraints) to check.|

**Return value**

| Type                  | Description                                                                 |
| --------------------- | --------------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the specified constraint is enabled; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Check whether OS account 100 is forbidden to use Wi-Fi.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let constraint = "constraint.wifi";
  try {
    accountManager.checkConstraintEnabled(localId, constraint).then((isEnabled) => {
      console.log("checkConstraintEnabled successfully, isEnabled: " + isEnabled);
    }).catch((err) => {
      console.log("checkConstraintEnabled failed, error: "  + JSON.stringify(err));
    });
  } catch (err) {
    console.log("checkConstraintEnabled exception: " + JSON.stringify(err));
  }
  ```

### checkOsAccountTestable<sup>9+</sup>

checkOsAccountTestable(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this OS account is a test account. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                                  |
| -------- | ---------------------------- | ---- | --------------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the result. The value **true** means the account is a test account; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.checkOsAccountTestable((err, isTestable) => {
      if (err) {
        console.log("checkOsAccountTestable failed, error: " + JSON.stringify(err));
      } else {
        console.log("checkOsAccountTestable successfully, isTestable: " + isTestable);
      }
    });
  } catch (err) {
    console.log("checkOsAccountTestable error: " + JSON.stringify(err));
  }
  ```

### checkOsAccountTestable<sup>9+</sup>

checkOsAccountTestable(): Promise&lt;boolean&gt;

Checks whether this OS account is a test account. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                  | Description                                                                     |
| ---------------------- | ------------------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the account is a test account; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.checkOsAccountTestable().then((isTestable) => {
      console.log("checkOsAccountTestable successfully, isTestable: " + isTestable);
    }).catch((err) => {
      console.log("checkOsAccountTestable failed, error: "  + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkOsAccountTestable exception: ' + JSON.stringify(err));
  }
  ```

### checkOsAccountVerified<sup>9+</sup>

checkOsAccountVerified(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this OS account has been verified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                           |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the result. If true is returned, the current account has been verified. If false is returned, the current account has not been verified.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.checkOsAccountVerified((err, isVerified) => {
      if (err) {
        console.log("checkOsAccountVerified failed, error: " + JSON.stringify(err));
      } else {
        console.log("checkOsAccountVerified successfully, isVerified: " + isVerified);
      }
    });
  } catch (err) {
    console.log("checkOsAccountVerified exception: " + JSON.stringify(err));
  }
  ```

### checkOsAccountVerified<sup>9+</sup>

checkOsAccountVerified(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether an OS account has been verified. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                           |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------- |
| localId  | number                       | Yes  | ID of the target OS account.                             |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the result. The value **true** means the OS account has been verified; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.checkOsAccountVerified(localId, (err, isVerified) => {
      if (err) {
        console.log("checkOsAccountVerified failed, error: " + JSON.stringify(err));
      } else {
        console.log("checkOsAccountVerified successfully, isVerified: " + isVerified);
      }
    });
  } catch (err) {
    console.log("checkOsAccountVerified exception: " + err);
  }
  ```

### checkOsAccountVerified<sup>9+</sup>

checkOsAccountVerified(localId?: number): Promise&lt;boolean&gt;

Checks whether an OS account has been verified. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description                                                             |
| ------- | ------ | ---- | --------------------------------------------------------------- |
| localId | number | No  | ID of the target OS account. If this parameter is not specified, this API checks whether the current OS account has been verified.|

**Return value**

| Type                  | Description                                                              |
| ---------------------- | ----------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the OS account has been verified; the value **false** means the opposite.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.checkOsAccountVerified(localId).then((isVerified) => {
      console.log("checkOsAccountVerified successfully, isVerified: " + isVerified);
    }).catch((err) => {
      console.log("checkOsAccountVerified failed, error: " + JSON.stringify(err));
    });
  } catch (err) {
    console.log('checkOsAccountVerified exception: ' + JSON.stringify(err));
  }
  ```

### removeOsAccount

removeOsAccount(localId: number, callback: AsyncCallback&lt;void&gt;): void

Deletes an OS account. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                     | Mandatory| Description                                                |
| -------- | ------------------------- | ---- | -------------------------------------------------- |
| localId  | number                    | Yes  | ID of the target OS account.                 |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let accountName = "testAccountName";
  try {
    accountManager.createOsAccount(accountName, account_osAccount.OsAccountType.NORMAL, (err, osAccountInfo) => {
      accountManager.removeOsAccount(osAccountInfo.localId, (err)=>{
        if (err) {
          console.log("removeOsAccount failed, error: " + JSON.stringify(err));
        } else {
          console.log("removeOsAccount successfully");
        }
      });
    });
  } catch (err) {
    console.log('removeOsAccount exception:' + JSON.stringify(err));
  }
  ```

### removeOsAccount

removeOsAccount(localId: number): Promise&lt;void&gt;

Deletes an OS account. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description                              |
| ------- | ------ | ---- | --------------------------------- |
| localId | number | Yes  | ID of the target OS account.|

**Return value**

| Type               | Description                                 |
| ------------------- | ------------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let accountName = "testAccountName";
  try {
    accountManager.createOsAccount(accountName, account_osAccount.OsAccountType.NORMAL, (err, osAccountInfo)=>{
      accountManager.removeOsAccount(osAccountInfo.localId).then(() => {
        console.log("removeOsAccount successfully");
      }).catch((err) => {
          console.log("removeOsAccount failed, error: " + JSON.stringify(err));
      });
    });
  } catch (err) {
    console.log("removeOsAccount exception: " + JSON.stringify(err));
  }
  ```

### setOsAccountConstraints

setOsAccountConstraints(localId: number, constraints: Array&lt;string&gt;, enable: boolean,callback: AsyncCallback&lt;void&gt;): void

Sets or removes constraints for an OS account. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name     | Type                     | Mandatory| Description                                            |
| ----------- | ------------------------- | ---- | ----------------------------------------------- |
| localId     | number                    | Yes  | ID of the target OS account.              |
| constraints | Array&lt;string&gt;       | Yes  | List of [constraints](#constraints) to set or remove.       |
| enable      | boolean                   | Yes  | Set or remove constraints. The value **true** means to set constraints, and **false** means to remove constraints.                          |
| callback    | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**Example**: Disable Wi-Fi for OS account 100.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let constraint = "constraint.wifi";
  try {
    accountManager.setOsAccountConstraints(localId, [constraint], true, (err) => {
      if (err) {
        console.log("setOsAccountConstraints failed, error:" + JSON.stringify(err));
      } else {
        console.log("setOsAccountConstraints successfully");
      }
    });
  } catch (err) {
    console.log("setOsAccountConstraints exception: " + JSON.stringify(err));
  }
  ```

### setOsAccountConstraints

setOsAccountConstraints(localId: number, constraints: Array&lt;string&gt;, enable: boolean): Promise&lt;void&gt;

Sets or removes constraints for an OS account. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name     | Type               | Mandatory| Description                                        |
| ----------- | ------------------- | ---- | -------------------------------------------- |
| localId     | number              | Yes  | ID of the target OS account.          |
| constraints | Array&lt;string&gt; | Yes  | List of [constraints](#constraints) to set or remove.   |
| enable      | boolean             | Yes  | Set or remove constraints. The value **true** means to set constraints, and **false** means to remove constraints.                    |

**Return value**

| Type               | Description                                |
| :------------------ | :----------------------------------- |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**Example**: Remove the constraint on the use of Wi-Fi for OS account 100.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.setOsAccountConstraints(localId, ['constraint.location.set'], false).then(() => {
      console.log('setOsAccountConstraints succsuccessfully');
    }).catch((err) => {
      console.log('setOsAccountConstraints failed, error: '  + JSON.stringify(err));
    });
  } catch (err) {
    console.log('setOsAccountConstraints exception:' + JSON.stringify(err));
  }
  ```

### setOsAccountName

setOsAccountName(localId: number, localName: string, callback: AsyncCallback&lt;void&gt;): void

Sets a name for an OS account. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name   | Type                     | Mandatory| Description                                            |
| :-------- | ------------------------- | ---- | ----------------------------------------------- |
| localId   | number                    | Yes  | ID of the target OS account.              |
| localName | string                    | Yes  | Account name. The value cannot exceed 1024 characters.                         |
| callback  | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId or localName. |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**Example**: Set the name of OS account 100 to **demoName**.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let name = "demoName";
  try {
    accountManager.setOsAccountName(localId, name, (err) => {
      if (err) {
        console.log("setOsAccountName failed, error: " + JSON.stringify(err));
      } else {
        console.log("setOsAccountName successfully");
      }
    });
  } catch (err) {
    console.log('setOsAccountName exception:' + JSON.stringify(err));
  }
  ```

### setOsAccountName

setOsAccountName(localId: number, localName: string): Promise&lt;void&gt;

Sets a name for an OS account. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name   | Type  | Mandatory| Description                               |
| --------- | ------ | ---- | --------------------------------- |
| localId   | number | Yes  | ID of the target OS account.|
| localName | string | Yes  | Account name to set. The value cannot exceed 1024 characters.           |

**Return value**

| Type               | Description                                 |
| ------------------- | ------------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId or localName.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**Example**: Set the name of OS account 100 to **demoName**.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let name = 'testName';
  try {
    accountManager.setOsAccountName(localId, name).then(() => {
      console.log('setOsAccountName successfully');
    }).catch((err) => {
      console.log('setOsAccountName failed, error: '  + JSON.stringify(err));
    });
  } catch (err) {
    console.log('setOsAccountName exception:' + JSON.stringify(err));
  }
  ```

### getOsAccountCount<sup>9+</sup>

getOsAccountCount(callback: AsyncCallback&lt;number&gt;): void

Obtains the number of OS accounts created. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                        |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the number of created OS accounts. If the operation fails, **err** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.getOsAccountCount((err, count) => {
      if (err) {
        console.log("getOsAccountCount failed, error: " + JSON.stringify(err));
      } else {
        console.log("getOsAccountCount successfully, count: " + count);
      }
    });
  } catch (err) {
    console.log("getOsAccountCount exception: " + JSON.stringify(err));
  }
  ```

### getOsAccountCount<sup>9+</sup>

getOsAccountCount(): Promise&lt;number&gt;

Obtains the number of OS accounts created. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                                   |
| --------------------- | -------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of created OS accounts.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.getOsAccountCount().then((count) => {
      console.log("getOsAccountCount successfully, count: " + count);
    }).catch((err) => {
      console.log("getOsAccountCount failed, error: " + JSON.stringify(err));
    });
  } catch(err) {
    console.log('getOsAccountCount exception:' + JSON.stringify(err));
  }
  ```

### queryOsAccountLocalIdFromProcess<sup>9+</sup>

queryOsAccountLocalIdFromProcess(callback: AsyncCallback&lt;number&gt;): void

Obtains the ID of the OS account to which the current process belongs. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                          |
| -------- | --------------------------- | ---- | ---------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the OS account ID obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryOsAccountLocalIdFromProcess((err, localId) => {
      if (err) {
        console.log("queryOsAccountLocalIdFromProcess failed, error: " + JSON.stringify(err));
      } else {
        console.log("queryOsAccountLocalIdFromProcess successfully, localId: " + localId);
      }
    });
  } catch (err) {
    console.log("queryOsAccountLocalIdFromProcess exception: " + JSON.stringify(err));
  }
  ```

### queryOsAccountLocalIdFromProcess<sup>9+</sup>

queryOsAccountLocalIdFromProcess(): Promise&lt;number&gt;

Obtains the ID of the OS account to which the current process belongs. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                                     |
| --------------------- | ---------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the OS account ID obtained.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryOsAccountLocalIdFromProcess().then((localId) => {
      console.log("queryOsAccountLocalIdFromProcess successfully, localId: " + localId);
    }).catch((err) => {
      console.log("queryOsAccountLocalIdFromProcess failed, error: "  + JSON.stringify(err));
    });
  } catch (err) {
    console.log('queryOsAccountLocalIdFromProcess exception: ' + JSON.stringify(err));
  }
  ```

### queryOsAccountLocalIdFromUid<sup>9+</sup>

queryOsAccountLocalIdFromUid(uid: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the OS account ID based on the process UID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                   |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------- |
| uid      | number                      | Yes  | Process UID.                                                             |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the OS account ID obtained. Otherwise, **data** is an error object.|

**Error codes**

| ID| Error Message        |
| -------- | --------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid uid.    |

**Example**: Obtain the ID of the OS account whose process UID is **12345678**.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let uid = 12345678;
  try {
    accountManager.queryOsAccountLocalIdFromUid(uid, (err, localId) => {
      if (err) {
        console.log("queryOsAccountLocalIdFromUid failed, error: " + JSON.stringify(err));
      }
      console.log("queryOsAccountLocalIdFromUid successfully, localId: " + localId);
    });
  } catch (err) {
    console.log("queryOsAccountLocalIdFromUid exception: " + JSON.stringify(err));
  }
  ```

### queryOsAccountLocalIdFromUid<sup>9+</sup>

queryOsAccountLocalIdFromUid(uid: number): Promise&lt;number&gt;

Obtains the OS account ID based on the process UID. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name| Type  | Mandatory| Description     |
| ------ | ------ | ---- | --------- |
| uid    | number | Yes  | Process UID.|

**Return value**

| Type                 | Description                                    |
| --------------------- | --------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the OS account ID obtained.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid uid. |

**Example**: Obtain the ID of the OS account whose process UID is **12345678**.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let uid = 12345678;
  try {
    accountManager.queryOsAccountLocalIdFromUid(uid).then((localId) => {
      console.log("queryOsAccountLocalIdFromUid successfully, localId: " + localId);
    }).catch((err) => {
      console.log("queryOsAccountLocalIdFromUid failed, error: " + JSON.stringify(err));
    });
  } catch (err) {
    console.log('queryOsAccountLocalIdFromUid exception: ' + JSON.stringify(err));
  }
  ```

### queryOsAccountLocalIdFromDomain<sup>9+</sup>

queryOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;number&gt;): void

Obtains the OS account ID based on the domain account information. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                   | Mandatory| Description                                                                        |
| ---------- | --------------------------------------- | ---- | -------------------------------------------------------------------------- |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | Yes  | Domain account information.                                                               |
| callback   | AsyncCallback&lt;number&gt;             | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the ID of the OS account associated with the domain account. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid domainInfo. |

**Example**

  ```js
  let domainInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryOsAccountLocalIdFromDomain(domainInfo, (err, localId) => {
      if (err) {
        console.log("queryOsAccountLocalIdFromDomain failed, error: " + JSON.stringify(err));
      } else {
        console.log("queryOsAccountLocalIdFromDomain successfully, localId: " + localId);
      }
    });
  } catch (err) {
    console.log('queryOsAccountLocalIdFromDomain exception: ' + JSON.stringify(err));
  }
  ```

### queryOsAccountLocalIdFromDomain<sup>9+</sup>

queryOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo): Promise&lt;number&gt;

Obtains the OS account ID based on the domain account information. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                   | Mandatory| Description        |
| ---------- | --------------------------------------- | ---- | ------------ |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | Yes  | Domain account information.|

**Return value**

| Type                 | Description                                   |
| :-------------------- | :------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the ID of the OS account associated with the domain account.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid domainInfo. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let domainInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  try {
    accountManager.queryOsAccountLocalIdFromDomain(domainInfo).then((localId) => {
      console.log("queryOsAccountLocalIdFromDomain successfully, localId: " + localId);
    }).catch((err) => {
      console.log("queryOsAccountLocalIdFromDomain failed, error: "  + JSON.stringify(err));
    });
  } catch (err) {
    console.log("queryOsAccountLocalIdFromDomain exception: " + JSON.stringify(err));
  }
  ```

### queryMaxOsAccountNumber

queryMaxOsAccountNumber(callback: AsyncCallback&lt;number&gt;): void

Obtains the maximum number of OS accounts that can be created. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                             |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the maximum number of OS accounts that can be created. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryMaxOsAccountNumber((err, maxCnt) => {
      if (err) {
        console.log('queryMaxOsAccountNumber failed, error:' + JSON.stringify(err));
      } else {
        console.log('queryMaxOsAccountNumber successfully, maxCnt:' + maxCnt);
      }
    });
  } catch (err) {
    console.log('queryMaxOsAccountNumber exception:' + JSON.stringify(err));
  }
  ```

### queryMaxOsAccountNumber

queryMaxOsAccountNumber(): Promise&lt;number&gt;

Obtains the maximum number of OS accounts that can be created. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                                        |
| --------------------- | ------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the maximum number of OS accounts that can be created.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryMaxOsAccountNumber().then((maxCnt) => {
      console.log('queryMaxOsAccountNumber successfully, maxCnt: ' + maxCnt);
    }).catch((err) => {
      console.log('queryMaxOsAccountNumber failed, error: '  + JSON.stringify(err));
    });
  } catch (err) {
    console.log('queryMaxOsAccountNumber exception:' + JSON.stringify(err));
  }
  ```

### getOsAccountConstraints<sup>9+</sup>

getOsAccountConstraints(localId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains all constraints enabled for an OS account. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                    | Mandatory| Description                                                                                          |
| -------- | ---------------------------------------- | ---- | -------------------------------------------------------------------------------------------- |
| localId  | number                                   | Yes  | ID of the target OS account.                                                                                 |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is all [constraints](#constraints) obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Obtain all constraints of OS account 100.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.getOsAccountConstraints(localId, (err, constraints) => {
      if (err) {
        console.log("getOsAccountConstraints failed, err: " + JSON.stringify(err));
      } else {
        console.log("getOsAccountConstraints successfully, constraints: " + JSON.stringify(constraints));
      }
    });
  } catch (err) {
    console.log('getOsAccountConstraints exception:' + JSON.stringify(err));
  }
  ```

### getOsAccountConstraints<sup>9+</sup>

getOsAccountConstraints(localId: number): Promise&lt;Array&lt;string&gt;&gt;

Obtains all constraints enabled for an OS account. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| localId | number | Yes  | ID of the target OS account.|

**Return value**

| Type                              | Description                                                      |
| ---------------------------------- | ---------------------------------------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return all the [constraints](#constraints) enabled for the OS account.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Obtain all constraints of OS account 100.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.getOsAccountConstraints(localId).then((constraints) => {
      console.log('getOsAccountConstraints, constraints: ' + constraints);
    }).catch((err) => {
      console.log('getOsAccountConstraints err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getOsAccountConstraints exception:' + JSON.stringify(e));
  }
  ```

### queryAllCreatedOsAccounts

queryAllCreatedOsAccounts(callback: AsyncCallback&lt;Array&lt;OsAccountInfo&gt;&gt;): void

Obtains information about all the OS accounts created. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**Parameters**

| Name  | Type                                                        | Mandatory| Description                                              |
| -------- | ------------------------------------------------------------ | ---- | -------------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[OsAccountInfo](#osaccountinfo)&gt;&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is a list of all created OS accounts. Otherwise, **data** is an error object.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryAllCreatedOsAccounts((err, accountArr)=>{
      console.log('queryAllCreatedOsAccounts err:' + JSON.stringify(err));
      console.log('queryAllCreatedOsAccounts accountArr:' + JSON.stringify(accountArr));
    });
  } catch (e) {
    console.log('queryAllCreatedOsAccounts exception:' + JSON.stringify(e));
  }
  ```

### queryAllCreatedOsAccounts

queryAllCreatedOsAccounts(): Promise&lt;Array&lt;OsAccountInfo&gt;&gt;

Obtains information about all the OS accounts created. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**Return value**

| Type                                                       | Description                                          |
| ----------------------------------------------------------- | --------------------------------------------- |
| Promise&lt;Array&lt;[OsAccountInfo](#osaccountinfo)&gt;&gt; | Promise used to return the information about all the OS accounts created.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryAllCreatedOsAccounts().then((accountArr) => {
      console.log('queryAllCreatedOsAccounts, accountArr: ' + JSON.stringify(accountArr));
    }).catch((err) => {
      console.log('queryAllCreatedOsAccounts err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('queryAllCreatedOsAccounts exception:' + JSON.stringify(e));
  }
  ```

### getActivatedOsAccountIds<sup>9+</sup>

getActivatedOsAccountIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Obtains information about all activated OS accounts. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                    | Mandatory| Description                                                  |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is a list of activated OS accounts. Otherwise, **data** is an error object.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.getActivatedOsAccountIds((err, idArray)=>{
      console.log('getActivatedOsAccountIds err:' + JSON.stringify(err));
      console.log('getActivatedOsAccountIds idArray length:' + idArray.length);
      for(let i=0;i<idArray.length;i++) {
        console.info('activated os account id: ' + idArray[i]);
      }
    });
  } catch (e) {
    console.log('getActivatedOsAccountIds exception:' + JSON.stringify(e));
  }
  ```

### getActivatedOsAccountIds<sup>9+</sup>

getActivatedOsAccountIds(): Promise&lt;Array&lt;number&gt;&gt;

Obtains information about all activated OS accounts. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                              | Description                                              |
| :--------------------------------- | :------------------------------------------------ |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the information about all activated OS accounts.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.getActivatedOsAccountIds().then((idArray) => {
      console.log('getActivatedOsAccountIds, idArray: ' + idArray);
    }).catch((err) => {
      console.log('getActivatedOsAccountIds err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getActivatedOsAccountIds exception:' + JSON.stringify(e));
  }
  ```

### createOsAccount

createOsAccount(localName: string, type: OsAccountType, callback: AsyncCallback&lt;OsAccountInfo&gt;): void

Creates an OS account. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name   | Type                                                | Mandatory| Description                                                                        |
| :-------- | ---------------------------------------------------- | ---- | --------------------------------------------------------------------------- |
| localName | string                                               | Yes  | Name of the OS account to create.                                                       |
| type      | [OsAccountType](#osaccounttype)                      | Yes  | Type of the OS account to create.                                                       |
| callback  | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the created OS account. Otherwise, **err** is an error object.|

**Error codes**

| ID | Error Message                  |
| -------- | ------------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localName or type. |
| 12300005 | Multi-user not supported. |
| 12300006 | Unsupported account type. |
| 12300007 | The number of account reaches the upper limit. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.createOsAccount('testName', account_osAccount.OsAccountType.NORMAL, (err, osAccountInfo)=>{
      console.log('createOsAccount err:' + JSON.stringify(err));
      console.log('createOsAccount osAccountInfo:' + JSON.stringify(osAccountInfo));
    });
  } catch (e) {
    console.log('createOsAccount exception:' + JSON.stringify(e));
  }
  ```

### createOsAccount

createOsAccount(localName: string, type: OsAccountType): Promise&lt;OsAccountInfo&gt;

Creates an OS account. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name   | Type                           | Mandatory| Description                  |
| --------- | ------------------------------- | ---- | ---------------------- |
| localName | string                          | Yes  | Name of the OS account to create.|
| type      | [OsAccountType](#osaccounttype) | Yes  | Type of the OS account to create.|

**Return value**

| Type                                          | Description                                 |
| ---------------------------------------------- | ------------------------------------- |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise used to return the information about the created OS account.|

**Error codes**

| ID | Error Message                  |
| -------- | ------------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localName or type. |
| 12300005 | Multi-user not supported. |
| 12300006 | Unsupported account type. |
| 12300007 | The number of account reaches the upper limit. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.createOsAccount('testAccountName', account_osAccount.OsAccountType.NORMAL).then((accountInfo) => {
      console.log('createOsAccount, accountInfo: ' + JSON.stringify(accountInfo));
    }).catch((err) => {
      console.log('createOsAccount err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('createOsAccount exception:' + JSON.stringify(e));
  }
  ```

### createOsAccountForDomain<sup>8+</sup>

createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;OsAccountInfo&gt;): void

Creates an OS account and associates it with the specified domain account. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                                | Mandatory| Description                                                                        |
| ---------- | ---------------------------------------------------- | ---- | -------------------------------------------------------------------------- |
| type       | [OsAccountType](#osaccounttype)                      | Yes  | Type of the OS account to create.                                                      |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8)              | Yes  | Domain account information.                                                              |
| callback   | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the created OS account. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                    |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid type or domainInfo. |
| 12300005 | Multi-user not supported. |
| 12300006 | Unsupported account type. |
| 12300007 | The number of account reaches the upper limit. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let domainInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  try {
    accountManager.createOsAccountForDomain(account_osAccount.OsAccountType.NORMAL, domainInfo, (err, osAccountInfo)=>{
      console.log('createOsAccountForDomain err:' + JSON.stringify(err));
      console.log('createOsAccountForDomain osAccountInfo:' + JSON.stringify(osAccountInfo));
    });
  } catch (e) {
    console.log('createOsAccountForDomain exception:' + JSON.stringify(e));
  }
  ```

### createOsAccountForDomain<sup>8+</sup>

createOsAccountForDomain(type: OsAccountType, domainInfo: DomainAccountInfo): Promise&lt;OsAccountInfo&gt;

Creates an OS account and associates it with the specified domain account. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                     | Mandatory| Description                |
| ---------- | ---------------------------------------- | ---- | -------------------- |
| type       | [OsAccountType](#osaccounttype)          | Yes  | Type of the OS account to create.|
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | Yes  | Domain account information.         |

**Return value**

| Type                                          | Description                                   |
| ---------------------------------------------- | -------------------------------------- |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise used to return the OS account created.|

**Error codes**

| ID| Error Message                    |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid type or domainInfo. |
| 12300005 | Multi-user not supported. |
| 12300006 | Unsupported account type. |
| 12300007 | The number of account reaches the upper limit. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let domainInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  try {
    accountManager.createOsAccountForDomain(account_osAccount.OsAccountType.NORMAL, domainInfo).then((accountInfo) => {
      console.log('createOsAccountForDomain, account info: ' + JSON.stringify(accountInfo));
    }).catch((err) => {
      console.log('createOsAccountForDomain err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('createOsAccountForDomain exception:' + JSON.stringify(e));
  }
  ```

### getCurrentOsAccount<sup>9+</sup>

getCurrentOsAccount(callback: AsyncCallback&lt;OsAccountInfo&gt;): void

Obtains information about the OS account to which the current process belongs. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                                | Mandatory| Description                                          |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the OS account information obtained. Otherwise, **data** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.getCurrentOsAccount((err, curAccountInfo)=>{
      console.log('getCurrentOsAccount err:' + JSON.stringify(err));
      console.log('getCurrentOsAccount curAccountInfo:' + JSON.stringify(curAccountInfo));
    });
  } catch (e) {
    console.log('getCurrentOsAccount exception:' + JSON.stringify(e));
  }
  ```

### getCurrentOsAccount<sup>9+</sup>

getCurrentOsAccount(): Promise&lt;OsAccountInfo&gt;

Obtains information about the OS account to which the current process belongs. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                                          | Description                                      |
| ---------------------------------------------- | ----------------------------------------- |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise used to return the OS account information obtained.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.getCurrentOsAccount().then((accountInfo) => {
      console.log('getCurrentOsAccount, accountInfo: ' + JSON.stringify(accountInfo));
    }).catch((err) => {
      console.log('getCurrentOsAccount err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getCurrentOsAccount exception:' + JSON.stringify(e));
  }
  ```

### queryOsAccountById

queryOsAccountById(localId: number, callback: AsyncCallback&lt;OsAccountInfo&gt;): void

Obtains information about the OS account of the given ID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                                      |
| -------- | ---------------------------------------------------- | ---- | ------------------------------------------------------------------------ |
| localId  | number                                               | Yes  | ID of the target OS account.                                                     |
| callback | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the OS account information obtained. Otherwise, **data** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Query information about OS account 100.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.queryOsAccountById(localId, (err, accountInfo)=>{
      console.log('queryOsAccountById err:' + JSON.stringify(err));
      console.log('queryOsAccountById accountInfo:' + JSON.stringify(accountInfo));
    });
  } catch (e) {
    console.log('queryOsAccountById exception:' + JSON.stringify(e));
  }
  ```

### queryOsAccountById

queryOsAccountById(localId: number): Promise&lt;OsAccountInfo&gt;

Obtains information about the OS account of the given ID. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description                |
| ------- | ------ | ---- | -------------------- |
| localId | number | Yes  | ID of the target OS account.|

**Return value**

| Type                                          | Description                                |
| ---------------------------------------------- | ------------------------------------ |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise used to return the OS account information obtained.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Query information about OS account 100.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.queryOsAccountById(localId).then((accountInfo) => {
      console.log('queryOsAccountById, accountInfo: ' + JSON.stringify(accountInfo));
    }).catch((err) => {
      console.log('queryOsAccountById err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('queryOsAccountById exception:' + JSON.stringify(e));
  }
  ```

### getOsAccountType<sup>9+</sup>

getOsAccountType(callback: AsyncCallback&lt;OsAccountType&gt;): void

Obtains the type of the account to which the current process belongs. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountType](#osaccounttype)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the OS account type obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.getOsAccountType((err, accountType) => {
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
| Promise&lt;[OsAccountType](#osaccounttype)&gt; | Promise used to return the OS account type obtained.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.getOsAccountType().then((accountType) => {
      console.log('getOsAccountType, accountType: ' + accountType);
    }).catch((err) => {
      console.log('getOsAccountType err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getOsAccountType exception: ' + JSON.stringify(e));
  }
  ```

### queryDistributedVirtualDeviceId<sup>9+</sup>

queryDistributedVirtualDeviceId(callback: AsyncCallback&lt;string&gt;): void

Obtains the ID of this distributed virtual device. This API uses an asynchronous callback to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC or ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                  |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------- |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the distributed virtual device ID obtained. Otherwise, **data** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryDistributedVirtualDeviceId((err, virtualID) => {
      console.log('queryDistributedVirtualDeviceId err: ' + JSON.stringify(err));
      console.log('queryDistributedVirtualDeviceId virtualID: ' + virtualID);
    });
  } catch (e) {
    console.log('queryDistributedVirtualDeviceId exception: ' + JSON.stringify(e));
  }
  ```

### queryDistributedVirtualDeviceId<sup>9+</sup>

queryDistributedVirtualDeviceId(): Promise&lt;string&gt;

Obtains the ID of this distributed virtual device. This API uses a promise to return the result.

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC or ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                             |
| --------------------- | --------------------------------- |
| Promise&lt;string&gt; | Promise used to return the distributed virtual device ID obtained.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryDistributedVirtualDeviceId().then((virtualID) => {
      console.log('queryDistributedVirtualDeviceId, virtualID: ' + virtualID);
    }).catch((err) => {
      console.log('queryDistributedVirtualDeviceId err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('queryDistributedVirtualDeviceId exception: ' + JSON.stringify(e));
  }
  ```

### getOsAccountProfilePhoto

getOsAccountProfilePhoto(localId: number, callback: AsyncCallback&lt;string&gt;): void

Obtains the profile photo of an OS account. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                        |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------- |
| localId  | number                      | Yes  | ID of the target OS account.                                                               |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the profile photo information obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Obtain the profile photo of OS account 100.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.getOsAccountProfilePhoto(localId, (err, photo)=>{
      console.log('getOsAccountProfilePhoto err:' + JSON.stringify(err));
      console.log('get photo:' + photo + ' by localId: ' + localId);
    });
  } catch (e) {
    console.log('getOsAccountProfilePhoto exception:' + JSON.stringify(e));
  }
  ```

### getOsAccountProfilePhoto

getOsAccountProfilePhoto(localId: number): Promise&lt;string&gt;

Obtains the profile photo of an OS account. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| localId | number | Yes  | ID of the target OS account.|

**Return value**

| Type                 | Description                                   |
| --------------------- | -------------------------------------- |
| Promise&lt;string&gt; | Promise used to return the profile photo information obtained.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Obtain the profile photo of OS account 100.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.getOsAccountProfilePhoto(localId).then((photo) => {
      console.log('getOsAccountProfilePhoto: ' + photo);
    }).catch((err) => {
      console.log('getOsAccountProfilePhoto err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getOsAccountProfilePhoto exception:' + JSON.stringify(e));
  }
  ```

### setOsAccountProfilePhoto

setOsAccountProfilePhoto(localId: number, photo: string, callback: AsyncCallback&lt;void&gt;): void

Sets a profile photo for an OS account. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                     | Mandatory| Description        |
| -------- | ------------------------- | ---- | ------------ |
| localId  | number                    | Yes  | ID of the target OS account.|
| photo    | string                    | Yes  | Profile photo information.  |
| callback | AsyncCallback&lt;void&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object. |

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId or photo.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**Example**: Set a profile photo for OS account 100.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let photo = 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAA0AAAAPCAYAAAA/I0V3AAAAAXNSR0IArs4c6QAAAARnQU1BAA'+
  'Cxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAACwSURBVDhPvZLBDYMwDEV/ugsXRjAT0EHCOuFIBwkbdIRewi6unbiAyoGgSn1SFH85+Y'+
  'q/4ljARW62X+LHS8uIzjm4dXUYF+utzBikB52Jo5e5iEPKqpACk7R9NM2RvWm5tIkD2czLCUFNKLD6IjdMHFHDzws285MgGrT0xCtp3WOKHo'+
  '+7q0mP0DZW9pNmoEFUzrQjp5cCnaen2kSJXLFD8ghbXyZCMQf/8e8Ns1XVAG/XAgqKzVnJFAAAAABJRU5ErkJggg=='
  try {
    accountManager.setOsAccountProfilePhoto(localId, photo, (err)=>{
      console.log('setOsAccountProfilePhoto err:' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('setOsAccountProfilePhoto exception:' + JSON.stringify(e));
  }
  ```

### setOsAccountProfilePhoto

setOsAccountProfilePhoto(localId: number, photo: string): Promise&lt;void&gt;

Sets a profile photo for an OS account. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| localId | number | Yes  | ID of the target OS account.|
| photo   | string | Yes  | Profile photo information.  |

**Return value**

| Type               | Description                                |
| ------------------- | ------------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId or photo.    |
| 12300003 | Account not found. |
| 12300008 | Restricted Account. |

**Example**: Set a profile photo for OS account 100.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let photo = 'data:image/png;base64,iVBORw0KGgoAAAANSUhEUgAAAA0AAAAPCAYAAAA/I0V3AAAAAXNSR0IArs4c6QAAAARnQU1BAA'+
  'Cxjwv8YQUAAAAJcEhZcwAADsMAAA7DAcdvqGQAAACwSURBVDhPvZLBDYMwDEV/ugsXRjAT0EHCOuFIBwkbdIRewi6unbiAyoGgSn1SFH85+Y'+
  'q/4ljARW62X+LHS8uIzjm4dXUYF+utzBikB52Jo5e5iEPKqpACk7R9NM2RvWm5tIkD2czLCUFNKLD6IjdMHFHDzws285MgGrT0xCtp3WOKHo'+
  '+7q0mP0DZW9pNmoEFUzrQjp5cCnaen2kSJXLFD8ghbXyZCMQf/8e8Ns1XVAG/XAgqKzVnJFAAAAABJRU5ErkJggg=='
  try {
    accountManager.setOsAccountProfilePhoto(localId, photo).then(() => {
      console.log('setOsAccountProfilePhoto success');
    }).catch((err) => {
      console.log('setOsAccountProfilePhoto err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('setOsAccountProfilePhoto exception:' + JSON.stringify(e));
  }
  ```

### queryOsAccountLocalIdBySerialNumber<sup>9+</sup>

queryOsAccountLocalIdBySerialNumber(serialNumber: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the OS account ID based on the serial number (SN). This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name      | Type                       | Mandatory| Description                                                                          |
| ------------ | --------------------------- | ---- | ---------------------------------------------------------------------------- |
| serialNumber | number                      | Yes  | Account SN.                                                                   |
| callback     | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the OS account ID obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message              |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid serialNumber. |
| 12300003 | Account not found. |

**Example**: Obtain the ID of the OS account whose SN is 12345.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let serialNumber = 12345;
  try {
    accountManager.queryOsAccountLocalIdBySerialNumber(serialNumber, (err, localId)=>{
      console.log('ger localId err:' + JSON.stringify(err));
      console.log('get localId:' + localId + ' by serialNumber: ' + serialNumber);
    });
  } catch (e) {
    console.log('ger localId exception:' + JSON.stringify(e));
  }
  ```

### queryOsAccountLocalIdBySerialNumber<sup>9+</sup>

queryOsAccountLocalIdBySerialNumber(serialNumber: number): Promise&lt;number&gt;

Obtains the OS account ID based on the SN. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name      | Type  | Mandatory| Description      |
| ------------ | ------ | ---- | ---------- |
| serialNumber | number | Yes  | Account SN.|

**Return value**

| Type                 | Description                                        |
| --------------------- | -------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the OS account ID obtained.|

**Error codes**

| ID| Error Message              |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid serialNumber. |
| 12300003 | Account not found. |

**Example**: Obtain the ID of the OS account whose SN is 12345.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let serialNumber = 12345;
  try {
    accountManager.queryOsAccountLocalIdBySerialNumber(serialNumber).then((localId) => {
      console.log('queryOsAccountLocalIdBySerialNumber localId: ' + localId);
    }).catch((err) => {
      console.log('queryOsAccountLocalIdBySerialNumber err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('queryOsAccountLocalIdBySerialNumber exception: '  + JSON.stringify(e));
  }
  ```

### querySerialNumberByOsAccountLocalId<sup>9+</sup>

querySerialNumberByOsAccountLocalId(localId: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the SN of an OS account based on the account ID. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                        |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------- |
| localId  | number                      | Yes  | ID of the target OS account.                                                                |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the SN obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Obtain the SN of the OS account 100.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.querySerialNumberByOsAccountLocalId(localId, (err, serialNumber)=>{
      console.log('ger serialNumber err:' + JSON.stringify(err));
      console.log('get serialNumber:' + serialNumber + ' by localId: ' + localId);
    });
  } catch (e) {
    console.log('ger serialNumber exception:' + JSON.stringify(e));
  }
  ```

### querySerialNumberByOsAccountLocalId<sup>9+</sup>

querySerialNumberByOsAccountLocalId(localId: number): Promise&lt;number&gt;

Obtains the SN of an OS account based on the account ID. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description         |
| ------- | ------ | ---- | ----------- |
| localId | number | Yes  | ID of the target OS account.|

**Return value**

| Type                 | Description                                   |
| :-------------------- | :------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the SN obtained.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId.    |
| 12300003 | Account not found. |

**Example**: Obtain the SN of the OS account 100.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  try {
    accountManager.querySerialNumberByOsAccountLocalId(localId).then((serialNumber) => {
      console.log('querySerialNumberByOsAccountLocalId serialNumber: ' + serialNumber);
    }).catch((err) => {
      console.log('querySerialNumberByOsAccountLocalId err: '  + JSON.stringify(err));
    });
  } catch (e) {
    console.log('querySerialNumberByOsAccountLocalId exception:' + JSON.stringify(e));
  }
  ```

### on

on(type: 'activate' | 'activating', name: string, callback: Callback&lt;number&gt;): void

Subscribes to the OS account activation states, including the states of the account being activated and the account with activation completed. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                      | Mandatory| Description                                                        |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'activate' \| 'activating' | Yes  | Type of the event to subscribe to. The value **activate** indicates an event reported when the OS account activation is complete, and **activating** indicates an event reported when OS account is being activated.|
| name     | string                     | Yes  | Subscription name, which can be customized. The value cannot be empty or exceed 1024 bytes.          |
| callback | Callback&lt;number&gt;     | Yes  | Callback invoked to return the ID of the OS account being activated or activated.   |

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid type or name. |
| 12300011 | Callback has been registered. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  function onCallback(receiveLocalId){
    console.log('receive localId:' + receiveLocalId);
  }
  try {
    accountManager.on('activating', 'osAccountOnOffNameA', onCallback);
  } catch (e) {
    console.log('receive localId exception:' + JSON.stringify(e));
  }
  ```

### off

off(type: 'activate' | 'activating', name: string, callback?: Callback&lt;number&gt;): void

Unsubscribes from the OS account activation states, including the states of the account being activated and the account with activation completed. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS_EXTENSION

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                      | Mandatory| Description                                                        |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| type     | 'activate' \| 'activating' | Yes  | Type of the event to unsubscribe from. The value **activate** means an event indicating that an OS account is activated, and **activating** means an event indicating that an OS account is being activated.|
| name     | string                     | Yes  | Subscription name, which can be customized. The value cannot be empty or exceed 1024 bytes, and must be the same as the value passed by **on()**.|
| callback | Callback&lt;number&gt;     | No  | Callback to unregister. By default, **0** is returned.                     |

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid type or name. |
| 12300012 | Callback has not been registered. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  function offCallback(){
    console.log('off enter')
  }
  try {
    accountManager.off('activating', 'osAccountOnOffNameA', offCallback);
  } catch (e) {
    console.log('off exception:' + JSON.stringify(e));
  }
  ```

### getBundleIdFromUid<sup>9+</sup>

getBundleIdFromUid(uid: number, callback: AsyncCallback&lt;number&gt;): void;

Obtains the bundle ID based on the UID. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                      | Mandatory| Description                                                                       |
| -------- | --------------------------- | ---- | ------------------------------------------------------------------------ |
| uid      | number                      | Yes  | Process UID.                                                                |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the bundle ID obtained. Otherwise, **data** is an error object.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid uid. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let testUid = 1000000;
  try {
    accountManager.getBundleIdFromUid(testUid, (err, bundleId) => {
      console.info('getBundleIdFromUid errInfo:' + JSON.stringify(err));
      console.info('getBundleIdFromUid bundleId:' + JSON.stringify(bundleId));
    });
  } catch (e) {
    console.info('getBundleIdFromUid exception:' + JSON.stringify(e));
  }
  ```
### getBundleIdFromUid<sup>9+</sup>

getBundleIdFromUid(uid: number): Promise&lt;number&gt;;

Obtains the bundle ID based on the UID. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| uid     | number | Yes  |  Process UID.|

**Return value**

| Type                 | Description                                 |
| --------------------- | ------------------------------------ |
| Promise&lt;number&gt; | Promise used to return the bundle ID obtained.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid uid. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let testUid = 1000000;
  try {
    accountManager.getBundleIdFromUid(testUid).then((result) => {
      console.info('getBundleIdFromUid bundleId:' + JSON.stringify(result));
    }).catch((err)=>{
      console.info('getBundleIdFromUid errInfo:' + JSON.stringify(err));
    });
  } catch (e) {
    console.info('getBundleIdFromUid exception:' + JSON.stringify(e));
  }
  ```

### isMainOsAccount<sup>9+</sup>

isMainOsAccount(callback: AsyncCallback&lt;boolean&gt;): void;

Checks whether the current process belongs to the main OS account. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                         | Mandatory| Description                                                              |
| -------- | ---------------------------- | ---- | ----------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the result. If **true** is returned, the current process belongs to the main OS account. If **false** is returned, the current process does not belong to the main OS account.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.isMainOsAccount((err,result)=>{
      console.info('isMainOsAccount errInfo:' + JSON.stringify(err));
      console.info('isMainOsAccount result:' + JSON.stringify(result));
    });
  } catch (e) {
    console.info('isMainOsAccount exception:' + JSON.stringify(e));
  }
  ```
### isMainOsAccount<sup>9+</sup>

isMainOsAccount(): Promise&lt;boolean&gt;;

Checks whether the current process belongs to the main OS account. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                  | Description                                                                 |
| ---------------------- | --------------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. If **true** is returned, the current process belongs to the main OS account. If **false** is returned, the current process does not belong to the main OS account.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | System service exception. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.isMainOsAccount().then((result) => {
      console.info('isMainOsAccount result:' + JSON.stringify(result));
    }).catch((err)=>{
      console.info('isMainOsAccount errInfo:' + JSON.stringify(err));
    });
  } catch (e) {
    console.info('isMainOsAccount exception:' + JSON.stringify(e));
  }
  ```
### queryOsAccountConstraintSourceTypes<sup>9+</sup>

queryOsAccountConstraintSourceTypes(localId: number, constraint: string, callback: AsyncCallback&lt;Array&lt;ConstraintSourceTypeInfo&gt;&gt;): void;

Obtains the constraint source information of an OS account. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                      | Mandatory| Description                                                        |
| -------- | -------------------------- | ---- | ------------------------------------------------------------ |
| localId     | number | Yes  |  ID of the target OS account.|
| constraint     | string | Yes  |  Name of the [constraint](#constraints) to query.|
| callback | AsyncCallback&lt;Array&lt;[ConstraintSourceTypeInfo](#constraintsourcetypeinfo)&gt;&gt;     | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the [constraint](#constraints) source information obtained. Otherwise, **err** is an error object.                     |

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId or constraint. |
| 12300003 | Account not found. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryOsAccountConstraintSourceTypes(100, 'constraint.wifi',(err,sourceTypeInfos)=>{
      console.info('queryOsAccountConstraintSourceType errInfo:' + JSON.stringify(err));
      console.info('queryOsAccountConstraintSourceType sourceTypeInfos:' + JSON.stringify(sourceTypeInfos));
    });
  } catch (e) {
    console.info('queryOsAccountConstraintSourceType exception:' + JSON.stringify(e));
  }
  ```

### queryOsAccountConstraintSourceTypes<sup>9+</sup>

queryOsAccountConstraintSourceTypes(localId: number, constraint: string): Promise&lt;Array&lt;ConstraintSourceTypeInfo&gt;&gt;;

Obtains the constraint source information of an OS account. This API uses a promise to return the result.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| localId     | number | Yes  |  ID of the target OS account.|
| constraint     | string | Yes  |  Name of the [constraint](#constraints) to query.|

**Return value**

| Type                 | Description                                                        |
| --------------------- | ------------------------------------------------------------ |
| Promise&lt;Array&lt;[ConstraintSourceTypeInfo](#constraintsourcetypeinfo)&gt;&gt; | Promise used to return the [constraint](#constraints) source information obtained.|

**Error codes**

| ID| Error Message      |
| -------- | ------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid localId or constraint. |
| 12300003 | Account not found. |

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  try {
    accountManager.queryOsAccountConstraintSourceTypes(100, 'constraint.wifi').then((result) => {
      console.info('queryOsAccountConstraintSourceType sourceTypeInfos:' + JSON.stringify(result));
    }).catch((err)=>{
      console.info('queryOsAccountConstraintSourceType errInfo:' + JSON.stringify(err));
    });
  } catch (e) {
    console.info('queryOsAccountConstraintSourceType exception:' + JSON.stringify(e));
  }
  ```

### isMultiOsAccountEnable<sup>(deprecated)</sup>

isMultiOsAccountEnable(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether multiple OS accounts are supported. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [checkMultiOsAccountEnabled](#checkmultiosaccountenabled9).

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                    |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the result. The value **true** means multiple OS accounts are supported; the value false means the opposite.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.isMultiOsAccountEnable((err, isEnabled) => {
    if (err) {
      console.log("isMultiOsAccountEnable failed, error: " + JSON.stringify(err));
    } else {
    console.log("isMultiOsAccountEnable successfully, isEnabled: " + isEnabled);
    }
  });
  ```

### isMultiOsAccountEnable<sup>(deprecated)</sup>

isMultiOsAccountEnable(): Promise&lt;boolean&gt;

Checks whether multiple OS accounts are supported. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [checkMultiOsAccountEnabled](#checkmultiosaccountenabled9-1).

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                  | Description                                                      |
| :--------------------- | :--------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means multiple OS accounts are supported; the value false means the opposite.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.isMultiOsAccountEnable().then((isEnabled) => {
    console.log('isMultiOsAccountEnable successfully, isEnabled: ' + isEnabled);
  }).catch((err) => {
    console.log('isMultiOsAccountEnable failed, error: '  + JSON.stringify(err));
  });
  ```


### isOsAccountActived<sup>(deprecated)</sup>

isOsAccountActived(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether an OS account is activated. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [checkOsAccountActivated](#checkosaccountactivated9).

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                    |
| -------- | ---------------------------- | ---- | ------------------------------------------------------ |
| localId  | number                       | Yes  | ID of the target OS account.                                           |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the result. The value **true** means the account is activated; the value **false** means the opposite.|

**Example**: Check whether OS account 100 is activated.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  accountManager.isOsAccountActived(localId, (err, isActived) => {
    if (err) {
      console.log('isOsAccountActived failed, err:' + JSON.stringify(err));
    } else {
      console.log('isOsAccountActived successfully, isActived:' + isActived);
    }
  });
  ```

### isOsAccountActived<sup>(deprecated)</sup>

isOsAccountActived(localId: number): Promise&lt;boolean&gt;

Checks whether an OS account is activated. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [checkOsAccountActivated](#checkosaccountactivated9-1).

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description                              |
| ------- | ------ | ---- | --------------------------------- |
| localId | number | Yes  | ID of the target OS account.|

**Return value**

| Type                  | Description                                                       |
| --------------------- | ----------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the account is activated; the value **false** means the opposite.|

**Example**: Check whether OS account 100 is activated.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  accountManager.isOsAccountActived(localId).then((isActived) => {
    console.log('isOsAccountActived successfully, isActived: ' + isActived);
  }).catch((err) => {
    console.log('isOsAccountActived failed, error: '  + JSON.stringify(err));
  });
  ```

### isOsAccountConstraintEnable<sup>(deprecated)</sup>

isOsAccountConstraintEnable(localId: number, constraint: string, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether the specified constraint is enabled for an OS account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [checkConstraintEnabled](#checkconstraintenabled9).

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                        | Mandatory| Description                                                               |
| ---------- | ---------------------------- | ---- | ----------------------------------------------------------------- |
| localId    | number                       | Yes  | ID of the target OS account.                                |
| constraint | string                       | Yes  | [Constraint](#constraints) to check.                               |
| callback   | AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the result. The value **true** means the specified constraint is enabled; the value **false** means the opposite.|

**Example**: Check whether OS account 100 is forbidden to use Wi-Fi.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let constraint = "constraint.wifi";
  accountManager.isOsAccountConstraintEnable(localId, constraint, (err, isEnabled) => {
    if (err) {
      console.log("isOsAccountConstraintEnable failed, error:" + JSON.stringify(err));
    } else {
      console.log("isOsAccountConstraintEnable successfully, isEnabled:" + isEnabled);
    }
  });
  ```

### isOsAccountConstraintEnable<sup>(deprecated)</sup>

isOsAccountConstraintEnable(localId: number, constraint: string): Promise&lt;boolean&gt;

Checks whether the specified constraint is enabled for an OS account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [checkConstraintEnabled](#checkconstraintenabled9-1).

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type  | Mandatory| Description                                |
| ---------- | ------ | ---- | ---------------------------------- |
| localId    | number | Yes  | ID of the target OS account. |
| constraint | string | Yes  | [Constraint](#constraints) to check.|

**Return value**

| Type                  | Description                                                                  |
| ---------------------- | --------------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the specified constraint is enabled; the value **false** means the opposite.|

**Example**: Check whether OS account 100 is forbidden to use Wi-Fi.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  let constraint = "constraint.wifi";
  accountManager.isOsAccountConstraintEnable(localId, constraint).then((isEnabled) => {
    console.log("isOsAccountConstraintEnable successfully, isEnabled: " + isEnabled);
  }).catch((err) => {
    console.log("isOsAccountConstraintEnable err: "  + JSON.stringify(err));
  });
  ```

### isTestOsAccount<sup>(deprecated)</sup>

isTestOsAccount(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this OS account is a test account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [checkOsAccountTestable](#checkosaccounttestable9).

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                                  |
| -------- | ---------------------------- | ---- | --------------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the result. The value **true** means the account is a test account; the value **false** means the opposite.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.isTestOsAccount((err, isTestable) => {
    if (err) {
      console.log("isTestOsAccount failed, error: " + JSON.stringify(err));
    } else {
      console.log("isTestOsAccount successfully, isTestable: " + isTestable);
    }
  });
  ```

### isTestOsAccount<sup>(deprecated)</sup>

isTestOsAccount(): Promise&lt;boolean&gt;

Checks whether this OS account is a test account. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [checkOsAccountTestable](#checkosaccounttestable9-1).

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                  | Description                                                                     |
| ---------------------- | ------------------------------------------------------------------------ |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the account is a test account; the value **false** means the opposite.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.isTestOsAccount().then((isTestable) => {
      console.log("isTestOsAccount successfully, isTestable: " + isTestable);
  }).catch((err) => {
      console.log("isTestOsAccount failed, error: " + JSON.stringify(err));
  });
  ```

### isOsAccountVerified<sup>(deprecated)</sup>

isOsAccountVerified(callback: AsyncCallback&lt;boolean&gt;): void

Checks whether this OS account has been verified. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [checkOsAccountVerified](#checkosaccountverified9).

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                           |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------- |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the result. The value **true** means the OS account has been verified; the value **false** means the opposite.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.isOsAccountVerified((err, isVerified) => {
    if (err) {
      console.log("isOsAccountVerified failed, error: " + JSON.stringify(err));
    } else {
      console.log("isOsAccountVerified successfully, isVerified: " + isVerified);
    }
  });
  ```

### isOsAccountVerified<sup>(deprecated)</sup>

isOsAccountVerified(localId: number, callback: AsyncCallback&lt;boolean&gt;): void

Checks whether an OS account has been verified. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [checkOsAccountVerified](#checkosaccountverified9-1).

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                        | Mandatory| Description                                                           |
| -------- | ---------------------------- | ---- | ------------------------------------------------------------- |
| localId  | number                       | Yes  | ID of the target OS account.                            |
| callback | AsyncCallback&lt;boolean&gt; | Yes  | Callback invoked to return the result. The value **true** means the OS account has been verified; the value **false** means the opposite.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  accountManager.isOsAccountVerified(localId, (err, isVerified) => {
    if (err) {
      console.log("isOsAccountVerified failed, error: " + JSON.stringify(err));
    } else {
      console.log("isOsAccountVerified successfully, isVerified: " + isVerified);
    }
  });
  ```

### isOsAccountVerified<sup>(deprecated)</sup>

isOsAccountVerified(localId?: number): Promise&lt;boolean&gt;

Checks whether an OS account has been verified. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [checkOsAccountVerified](#checkosaccountverified9-2).

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS or ohos.permission.INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description                                                             |
| ------- | ------ | ---- | ---------------------------------------------------------------- |
| localId | number | No  | ID of the target OS account. If this parameter is not specified, this API checks whether the current OS account has been verified.|

**Return value**

| Type                  | Description                                                              |
| ---------------------- | ----------------------------------------------------------------- |
| Promise&lt;boolean&gt; | Promise used to return the result. The value **true** means the OS account has been verified; the value **false** means the opposite.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.isOsAccountVerified(localId).then((isVerified) => {
    console.log("isOsAccountVerified successfully, isVerified: " + isVerified);
  }).catch((err) => {
    console.log("isOsAccountVerified failed, error: " + JSON.stringify(err));
  });
  ```

### getCreatedOsAccountsCount<sup>(deprecated)</sup>

getCreatedOsAccountsCount(callback: AsyncCallback&lt;number&gt;): void

Obtains the number of OS accounts created. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getOsAccountCount](#getosaccountcount9).

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                        |
| -------- | --------------------------- | ---- | -------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the number of created OS accounts. If the operation fails, **err** is an error object.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getCreatedOsAccountsCount((err, count)=>{
    if (err) {
      console.log("getCreatedOsAccountsCount failed, error: " + JSON.stringify(err));
    } else {
      console.log("getCreatedOsAccountsCount successfully, count: " + count);
    }
  });
  ```

### getCreatedOsAccountsCount<sup>(deprecated)</sup>

getCreatedOsAccountsCount(): Promise&lt;number&gt;

Obtains the number of OS accounts created. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getOsAccountCount](#getosaccountcount9-1).

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                                   |
| --------------------- | -------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the number of created OS accounts.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getCreatedOsAccountsCount().then((count) => {
    console.log("getCreatedOsAccountsCount successfully, count: " + count);
  }).catch((err) => {
    console.log("getCreatedOsAccountsCount failed, error: "  + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromProcess<sup>(deprecated)</sup>

getOsAccountLocalIdFromProcess(callback: AsyncCallback&lt;number&gt;): void

Obtains the ID of the OS account to which the current process belongs. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [queryOsAccountLocalIdFromProcess](#queryosaccountlocalidfromprocess9).

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                          |
| -------- | --------------------------- | ---- | ---------------------------------------------------------------------------- |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the OS account ID obtained. Otherwise, **err** is an error object.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromProcess((err, localId) => {
    if (err) {
      console.log("getOsAccountLocalIdFromProcess failed, error: " + JSON.stringify(err));
    } else {
      console.log("getOsAccountLocalIdFromProcess successfully, localId: " + localId);
    }
  });
  ```

### getOsAccountLocalIdFromProcess<sup>(deprecated)</sup>

getOsAccountLocalIdFromProcess(): Promise&lt;number&gt;

Obtains the ID of the OS account to which the current process belongs. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [queryOsAccountLocalIdFromProcess](#queryosaccountlocalidfromprocess9-1).

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                                     |
| :-------------------- | :--------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the OS account ID obtained.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromProcess().then((localId) => {
    console.log('getOsAccountLocalIdFromProcess successfully, localId: ' + localId);
  }).catch((err) => {
    console.log('getOsAccountLocalIdFromProcess failed, error: '  + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromUid<sup>(deprecated)</sup>

getOsAccountLocalIdFromUid(uid: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the OS account ID based on the process UID. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [queryOsAccountLocalIdFromUid](#queryosaccountlocalidfromuid9).

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                   |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------- |
| uid      | number                      | Yes  | Process UID.                                                             |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the OS account ID obtained. Otherwise, **data** is an error object.|

**Example**: Obtain the ID of the OS account whose process UID is **12345678**.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let uid = 12345678;
  accountManager.getOsAccountLocalIdFromUid(uid, (err, localId) => {
    if (err) {
      console.log("getOsAccountLocalIdFromUid failed, error: " + JSON.stringify(err));
    } else {
      console.log("getOsAccountLocalIdFromUid successfully, localId: " + localId);
    }
  });
  ```

### getOsAccountLocalIdFromUid<sup>(deprecated)</sup>

getOsAccountLocalIdFromUid(uid: number): Promise&lt;number&gt;

Obtains the OS account ID based on the process UID. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [queryOsAccountLocalIdFromUid](#queryosaccountlocalidfromuid9-1).

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name| Type  | Mandatory| Description     |
| ------ | ------ | ---- | --------- |
| uid    | number | Yes  | Process UID.|

**Return value**

| Type                 | Description                                 |
| :-------------------- | :----------------------------------- |
| Promise&lt;number&gt; | Promise used to return the OS account ID obtained.|

**Example**: Obtain the ID of the OS account whose process UID is **12345678**.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let uid = 12345678;
  accountManager.getOsAccountLocalIdFromUid(uid).then((localId) => {
    console.log("getOsAccountLocalIdFromUid successfully, localId: " + localId);
  }).catch((err) => {
    console.log("getOsAccountLocalIdFromUid failed, error: "  + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdFromDomain<sup>(deprecated)</sup>

getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo, callback: AsyncCallback&lt;number&gt;): void

Obtains the OS account ID based on the domain account information. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [queryOsAccountLocalIdFromDomain](#queryosaccountlocalidfromdomain9).

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                   | Mandatory| Description                                                                        |
| ---------- | --------------------------------------- | ---- | --------------------------------------------------------------------------- |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | Yes  | Domain account information.                                                               |
| callback   | AsyncCallback&lt;number&gt;             | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the OS account ID obtained. Otherwise, **err** is an error object.|

**Example**

  ```js
  let domainInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountLocalIdFromDomain(domainInfo, (err, localId) => {
    if (err) {
      console.log("getOsAccountLocalIdFromDomain failed, error: " + JSON.stringify(err));
    } else {
      console.log("getOsAccountLocalIdFromDomain successfully, localId: " + localId);
    }
  });
  ```

### getOsAccountLocalIdFromDomain<sup>(deprecated)</sup>

getOsAccountLocalIdFromDomain(domainInfo: DomainAccountInfo): Promise&lt;number&gt;

Obtains the OS account ID based on the domain account information. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [queryOsAccountLocalIdFromDomain](#queryosaccountlocalidfromdomain9-1).

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                   | Mandatory| Description        |
| ---------- | --------------------------------------- | ---- | ------------ |
| domainInfo | [DomainAccountInfo](#domainaccountinfo8) | Yes  | Domain account information.|

**Return value**

| Type                 | Description                                   |
| :-------------------- | :------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the ID of the OS account associated with the domain account.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let domainInfo = {domain: 'testDomain', accountName: 'testAccountName'};
  accountManager.getOsAccountLocalIdFromDomain(domainInfo).then((localId) => {
    console.log('getOsAccountLocalIdFromDomain successfully, localId: ' + localId);
  }).catch((err) => {
    console.log('getOsAccountLocalIdFromDomain failed, error: '  + JSON.stringify(err));
  });
  ```

### getOsAccountAllConstraints<sup>(deprecated)</sup>

getOsAccountAllConstraints(localId: number, callback: AsyncCallback&lt;Array&lt;string&gt;&gt;): void

Obtains all constraints enabled for an OS account. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getOsAccountConstraints](#getosaccountconstraints9).

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                    | Mandatory| Description                                                                                            |
| -------- | ---------------------------------------- | ---- | ---------------------------------------------------------------------------------------------- |
| localId  | number                                   | Yes  | ID of the target OS account.                                                                                   |
| callback | AsyncCallback&lt;Array&lt;string&gt;&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is a list of all [constraints](#constraints) enabled for the OS account. Otherwise, **err** is an error object.|

**Example**: Obtain all constraints of OS account 100.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  accountManager.getOsAccountAllConstraints(localId, (err, constraints)=>{
    console.log('getOsAccountAllConstraints err:' + JSON.stringify(err));
    console.log('getOsAccountAllConstraints:' + JSON.stringify(constraints));
  });
  ```

### getOsAccountAllConstraints<sup>(deprecated)</sup>

getOsAccountAllConstraints(localId: number): Promise&lt;Array&lt;string&gt;&gt;

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getOsAccountConstraints](#getosaccountconstraints9-1).

Obtains all constraints enabled for an OS account. This API uses a promise to return the result.

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description        |
| ------- | ------ | ---- | ------------ |
| localId | number | Yes  | ID of the target OS account.|

**Return value**

| Type                              | Description                                                        |
| :--------------------------------- | :----------------------------------------------------------- |
| Promise&lt;Array&lt;string&gt;&gt; | Promise used to return all the [constraints](#constraints) enabled for the OS account.|

**Example**: Obtain all constraints of OS account 100.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  accountManager.getOsAccountAllConstraints(localId).then((constraints) => {
    console.log('getOsAccountAllConstraints, constraints: ' + constraints);
  }).catch((err) => {
    console.log('getOsAccountAllConstraints err: '  + JSON.stringify(err));
  });
  ```

### queryActivatedOsAccountIds<sup>(deprecated)</sup>

queryActivatedOsAccountIds(callback: AsyncCallback&lt;Array&lt;number&gt;&gt;): void

Obtains information about all activated OS accounts. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getActivatedOsAccountIds](#getactivatedosaccountids9).

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                    | Mandatory| Description                                                  |
| -------- | ---------------------------------------- | ---- | ------------------------------------------------------ |
| callback | AsyncCallback&lt;Array&lt;number&gt;&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is a list of activated OS accounts. Otherwise, **data** is an error object.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.queryActivatedOsAccountIds((err, idArray)=>{
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
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [getActivatedOsAccountIds](#getactivatedosaccountids9-1).

Obtains information about all activated OS accounts. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                              | Description                                              |
| ---------------------------------- | ------------------------------------------------- |
| Promise&lt;Array&lt;number&gt;&gt; | Promise used to return the information about all activated OS accounts.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.queryActivatedOsAccountIds().then((idArray) => {
    console.log('queryActivatedOsAccountIds, idArray: ' + idArray);
  }).catch((err) => {
    console.log('queryActivatedOsAccountIds err: '  + JSON.stringify(err));
  });
  ```

### queryCurrentOsAccount<sup>(deprecated)</sup>

queryCurrentOsAccount(callback: AsyncCallback&lt;OsAccountInfo&gt;): void

Obtains information about the OS account to which the current process belongs. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getCurrentOsAccount](#getcurrentosaccount9).

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                                | Mandatory| Description                                          |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountInfo](#osaccountinfo)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the OS account information obtained. Otherwise, **data** is an error object.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.queryCurrentOsAccount((err, curAccountInfo)=>{
    console.log('queryCurrentOsAccount err:' + JSON.stringify(err));
    console.log('queryCurrentOsAccount curAccountInfo:' + JSON.stringify(curAccountInfo));
  });
  ```

### queryCurrentOsAccount<sup>(deprecated)</sup>

queryCurrentOsAccount(): Promise&lt;OsAccountInfo&gt;

Obtains information about the OS account to which the current process belongs. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getCurrentOsAccount](#getcurrentosaccount9-1).

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                                          | Description                                      |
| ---------------------------------------------- | ------------------------------------------ |
| Promise&lt;[OsAccountInfo](#osaccountinfo)&gt; | Promise used to return the OS account information obtained.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.queryCurrentOsAccount().then((accountInfo) => {
    console.log('queryCurrentOsAccount, accountInfo: ' + JSON.stringify(accountInfo));
  }).catch((err) => {
    console.log('queryCurrentOsAccount err: '  + JSON.stringify(err));
  });
  ```

### getOsAccountTypeFromProcess<sup>(deprecated)</sup>

getOsAccountTypeFromProcess(callback: AsyncCallback&lt;OsAccountType&gt;): void

Obtains the type of the account to which the current process belongs. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getOsAccountType](#getosaccounttype9).

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                                                | Mandatory| Description                                                |
| -------- | ---------------------------------------------------- | ---- | ---------------------------------------------------- |
| callback | AsyncCallback&lt;[OsAccountType](#osaccounttype)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the OS account type obtained. Otherwise, **err** is an error object.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountTypeFromProcess((err, accountType) => {
    console.log('getOsAccountTypeFromProcess err: ' + JSON.stringify(err));
    console.log('getOsAccountTypeFromProcess accountType: ' + accountType);
  });
  ```

### getOsAccountTypeFromProcess<sup>(deprecated)</sup>

getOsAccountTypeFromProcess(): Promise&lt;OsAccountType&gt;

Obtains the type of the account to which the current process belongs. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getOsAccountType](#getosaccounttype9-1).

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                                          | Description                                           |
| ---------------------------------------------- | ----------------------------------------------- |
| Promise&lt;[OsAccountType](#osaccounttype)&gt; | Promise used to return the OS account type obtained.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getOsAccountTypeFromProcess().then((accountType) => {
    console.log('getOsAccountTypeFromProcess, accountType: ' + accountType);
  }).catch((err) => {
    console.log('getOsAccountTypeFromProcess err: '  + JSON.stringify(err));
  });
  ```

### getDistributedVirtualDeviceId<sup>(deprecated)</sup>

getDistributedVirtualDeviceId(callback: AsyncCallback&lt;string&gt;): void

Obtains the ID of the distributed virtual device. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [queryDistributedVirtualDeviceId](#querydistributedvirtualdeviceid9).

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC or ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                   |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------- |
| callback | AsyncCallback&lt;string&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the distributed virtual device ID obtained. Otherwise, **data** is an error object.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getDistributedVirtualDeviceId((err, virtualID) => {
    console.log('getDistributedVirtualDeviceId err: ' + JSON.stringify(err));
    console.log('getDistributedVirtualDeviceId virtualID: ' + virtualID);
  });
  ```

### getDistributedVirtualDeviceId<sup>(deprecated)</sup>

getDistributedVirtualDeviceId(): Promise&lt;string&gt;

Obtains the ID of the distributed virtual device. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [queryDistributedVirtualDeviceId](#querydistributedvirtualdeviceid9-1).

**Required permissions**: ohos.permission.DISTRIBUTED_DATASYNC or ohos.permission.MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type                 | Description                             |
| --------------------- | --------------------------------- |
| Promise&lt;string&gt; | Promise used to return the distributed virtual device ID obtained.|

**Example**

  ```js
  let accountManager = account_osAccount.getAccountManager();
  accountManager.getDistributedVirtualDeviceId().then((virtualID) => {
    console.log('getDistributedVirtualDeviceId, virtualID: ' + virtualID);
  }).catch((err) => {
    console.log('getDistributedVirtualDeviceId err: '  + JSON.stringify(err));
  });
  ```

### getOsAccountLocalIdBySerialNumber<sup>(deprecated)</sup>

getOsAccountLocalIdBySerialNumber(serialNumber: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the OS account ID based on the SN. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [queryOsAccountLocalIdBySerialNumber](#queryosaccountlocalidbyserialnumber9).

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name      | Type                       | Mandatory| Description                                                                              |
| ------------ | --------------------------- | ---- | -------------------------------------------------------------------------------- |
| serialNumber | number                      | Yes  | Account SN.                                                                       |
| callback     | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the OS account ID obtained. Otherwise, **err** is an error object.|

**Example**: Obtain the ID of the OS account whose SN is 12345.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let serialNumber = 12345;
  accountManager.getOsAccountLocalIdBySerialNumber(serialNumber, (err, localId)=>{
    console.log('ger localId err:' + JSON.stringify(err));
    console.log('get localId:' + localId + ' by serialNumber: ' + serialNumber);
  });
  ```

### getOsAccountLocalIdBySerialNumber<sup>(deprecated)</sup>

getOsAccountLocalIdBySerialNumber(serialNumber: number): Promise&lt;number&gt;

Obtains the OS account ID based on the SN. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [queryOsAccountLocalIdBySerialNumber](#queryosaccountlocalidbyserialnumber9-1).

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name      | Type  | Mandatory| Description      |
| ------------ | ------ | ---- | ---------- |
| serialNumber | number | Yes  | Account SN.|

**Return value**

| Type                 | Description                                                        |
| --------------------- | -------------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the OS account ID obtained.|

**Example**: Obtain the ID of the OS account whose SN is 12345.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let serialNumber = 12345;
  accountManager.getOsAccountLocalIdBySerialNumber(serialNumber).then((localId) => {
    console.log('getOsAccountLocalIdBySerialNumber localId: ' + localId);
  }).catch((err) => {
    console.log('getOsAccountLocalIdBySerialNumber err: '  + JSON.stringify(err));
  });
  ```

### getSerialNumberByOsAccountLocalId<sup>(deprecated)</sup>

getSerialNumberByOsAccountLocalId(localId: number, callback: AsyncCallback&lt;number&gt;): void

Obtains the SN of an OS account based on the account ID. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [querySerialNumberByOsAccountLocalId](#queryserialnumberbyosaccountlocalid9).

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name  | Type                       | Mandatory| Description                                                                        |
| -------- | --------------------------- | ---- | --------------------------------------------------------------------------- |
| localId  | number                      | Yes  | ID of the target OS account.                                                                |
| callback | AsyncCallback&lt;number&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the SN obtained. Otherwise, **err** is an error object.|

**Example**: Obtain the SN of the OS account 100.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  accountManager.getSerialNumberByOsAccountLocalId(localId, (err, serialNumber)=>{
    console.log('ger serialNumber err:' + JSON.stringify(err));
    console.log('get serialNumber:' + serialNumber + ' by localId: ' + localId);
  });
  ```

### getSerialNumberByOsAccountLocalId<sup>(deprecated)</sup>

getSerialNumberByOsAccountLocalId(localId: number): Promise&lt;number&gt;

Obtains the SN of an OS account based on the account ID. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 8 and deprecated since API version 9. You are advised to use [querySerialNumberByOsAccountLocalId](#queryserialnumberbyosaccountlocalid9-1).

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name | Type  | Mandatory| Description         |
| ------- | ------ | ---- | ----------- |
| localId | number | Yes  | ID of the target OS account.|

**Return value**

| Type                 | Description                                   |
| --------------------- | -------------------------------------- |
| Promise&lt;number&gt; | Promise used to return the SN obtained.|

**Example**: Obtain the SN of the OS account 100.

  ```js
  let accountManager = account_osAccount.getAccountManager();
  let localId = 100;
  accountManager.getSerialNumberByOsAccountLocalId(localId).then((serialNumber) => {
    console.log('getSerialNumberByOsAccountLocalId serialNumber: ' + serialNumber);
  }).catch((err) => {
    console.log('getSerialNumberByOsAccountLocalId err: '  + JSON.stringify(err));
  });
  ```

## UserAuth<sup>8+</sup>

Provides APIs for user authentication.

**System API**: This is a system API.

### constructor<sup>8+</sup>

constructor()

A constructor used to create an instance for user authentication.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Example** 
  ```js
  let userAuth = new account_osAccount.UserAuth();
  ```

### getVersion<sup>8+</sup>

getVersion(): number;

Obtains version information.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

| Type  | Description        |
| :----- | :----------- |
| number | Version information obtained.|

**Example** 
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let version = userAuth.getVersion();
  console.log('getVersion version = ' + version);
  ```

### getAvailableStatus<sup>8+</sup>

getAvailableStatus(authType: AuthType, authTrustLevel: AuthTrustLevel): number;

Obtains the available status of the authentication capability corresponding to the specified authentication type and trust level.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_USER_AUTH_INTERNAL

**Parameters**

| Name          | Type                              | Mandatory| Description                      |
| --------------- | -----------------------------------| ---- | ------------------------- |
| authType        | [AuthType](#authtype8)             | Yes  | Authentication credential type.    |
| authTrustLevel  | [AuthTrustLevel](#authtrustlevel8) | Yes  | Trust level of the authentication.|

**Return value**

| Type  | Description                          |
| ------ | ----------------------------- |
| number | Available status of the authentication capability.|

**Error codes**

| ID| Error Message                    |
| -------- | --------------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid authType or authTrustLevel. |

**Example** 
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let authType = account_osAccount.AuthType.PIN;
  let authTrustLevel = account_osAccount.AuthTrustLevel.ATL1;
  try {
    let status = userAuth.getAvailableStatus(authType, authTrustLevel);
    console.log('getAvailableStatus status = ' + status);
  } catch (e) {
    console.log('getAvailableStatus exception = ' + JSON.stringify(e));
  }
  ```

### getProperty<sup>8+</sup>

getProperty(request: GetPropertyRequest, callback: AsyncCallback&lt;ExecutorProperty&gt;): void;

Obtains the executor property based on the request. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_USER_AUTH_INTERNAL

**Parameters**

| Name   | Type                                                                   | Mandatory| Description                               |
| -------- | ----------------------------------------------------------- | ---- | ------------------------------------------------------ |
| request  | [GetPropertyRequest](#getpropertyrequest8)                  | Yes  | Request information, including the authentication credential type and property list.|
| callback | AsyncCallback&lt;[ExecutorProperty](#executorproperty8)&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the executor property information obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                    |
| -------- | --------------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid request. |

**Example**
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let keys = [
    account_osAccount.GetPropertyType.AUTH_SUB_TYPE, 
    account_osAccount.GetPropertyType.REMAIN_TIMES,
    account_osAccount.GetPropertyType.FREEZING_TIME
  ];
  let request = {
    authType: account_osAccount.AuthType.PIN,
    keys: keys
  };
  try {
    userAuth.getProperty(request, (err, result) => {
      console.log('getProperty err = ' + JSON.stringify(err));
      console.log('getProperty result = ' + JSON.stringify(result));
    });
  } catch (e) {
    console.log('getProperty exception = ' + JSON.stringify(e));
  }
  ```

### getProperty<sup>8+</sup>

getProperty(request: GetPropertyRequest): Promise&lt;ExecutorProperty&gt;;

Obtains the executor property based on the request. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_USER_AUTH_INTERNAL

**Parameters**

| Name   | Type                                                  | Mandatory| Description                               |
| -------- | ------------------------------------------------------ | ---- | ---------------------------------- |
| request  | [GetPropertyRequest](#getpropertyrequest8) | Yes  | Request information, including the authentication credential type and property list.|

**Return value**

| Type                                                             | Description                                                |
| :---------------------------------------------------------------- | :-------------------------------------------------- |
| Promise&lt;[ExecutorProperty](#executorproperty8)&gt; | Promise used to return the executor property information obtained.|

**Error codes**

| ID| Error Message                    |
| -------- | --------------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid request. |

**Example**
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let keys = [
    account_osAccount.GetPropertyType.AUTH_SUB_TYPE, 
    account_osAccount.GetPropertyType.REMAIN_TIMES,
    account_osAccount.GetPropertyType.FREEZING_TIME
  ];
  let request = {
    authType: account_osAccount.AuthType.PIN,
    keys: keys
  };
  try {
    userAuth.getProperty(request).then((result) => {
      console.log('getProperty result = ' + JSON.stringify(result));
    }).catch((err) => {
      console.log('getProperty error = ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getProperty exception = ' + JSON.stringify(e));
  }
  ```

### setProperty<sup>8+</sup>

setProperty(request: SetPropertyRequest, callback: AsyncCallback&lt;void&gt;): void;

Sets the property for the initialization algorithm. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_USER_AUTH_INTERNAL

**Parameters**

| Name   | Type                                                 | Mandatory| Description                                                                   |
| -------- | ----------------------------------------------------- | ---- | ---------------------------------------------------------------------- |
| request  | [SetPropertyRequest](#setpropertyrequest8)| Yes  | Request information, including the authentication credential type and the key value to set.                                  |
| callback | AsyncCallback&lt;void&gt;                           | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null**. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                    |
| -------- | --------------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid request. |

**Example**
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let request = {
    authType: account_osAccount.AuthType.PIN,
    key: account_osAccount.SetPropertyType.INIT_ALGORITHM,
    setInfo: new Uint8Array([0])
  };
  try {
    userAuth.setProperty(request, (err) => {
      if (err) {
        console.log('setProperty failed, error = ' + JSON.stringify(err));
      } else {
        console.log('setProperty successfully');
      }
    });
  } catch (e) {
    console.log('setProperty exception = ' + JSON.stringify(e));
  }
  ```

### setProperty<sup>8+</sup>

setProperty(request: SetPropertyRequest): Promise&lt;void&gt;;

Sets the property for the initialization algorithm. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_USER_AUTH_INTERNAL

**Parameters**

| Name   | Type                                      | Mandatory| Description                                     |
| -------- | ------------------------------------------ | ---- | ---------------------------------------- |
| request  | [SetPropertyRequest](#setpropertyrequest8) | Yes  | Request information, including the authentication credential type and the key value to set.|

**Return value**

| Type                 | Description                                                          |
| :-------------------- | :------------------------------------------------------------ |
| Promise&lt;void&gt; | Promise that returns no value.|

**Error codes**

| ID| Error Message                    |
| -------- | --------------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid request. |

**Example**
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let request = {
    authType: account_osAccount.AuthType.PIN,
    key: account_osAccount.SetPropertyType.INIT_ALGORITHM,
    setInfo: new Uint8Array([0])
  };
  try {
    userAuth.setProperty(request).then(() => {
      console.log('setProperty successfully');
    }).catch((err) => {
      console.log('setProperty failed, error = ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('setProperty exception = ' + JSON.stringify(e));
  }
  ```

### auth<sup>8+</sup>

auth(challenge: Uint8Array, authType: AuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array;

Performs authentication of the current user. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_USER_AUTH_INTERNAL

**Parameters**

| Name          | Type                                    | Mandatory| Description                               |
| --------------- | ---------------------------------------- | --- | ------------------------------------ |
| challenge       | Uint8Array                               | Yes | Challenge value, which is a random number used to improve security.|
| authType        | [AuthType](#authtype8)                   | Yes | Authentication credential type.                       |
| authTrustLevel  | [AuthTrustLevel](#authtrustlevel8)       | Yes | Trust level of the authentication result.              |
| callback        | [IUserAuthCallback](#iuserauthcallback8) | Yes | Callback invoked to return the authentication result. |

**Return value**

| Type       | Description              |
| ---------- | ------------------ |
| Uint8Array | ID of the context for canceling the authentication.|

**Error codes**

| ID| Error Message         |
| -------- | --------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid challenge or authType or authTrustLevel. |
| 12300101 | Credential is incorrect. |
| 12300105 | Unsupported authTrustLevel. |
| 12300106 | Unsupported authType. |
| 12300110 | Authentication locked. |
| 12300111 | Authentication timeout. |
| 12300112 | Authentication service busy. |

**Example**
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let challenge = new Uint8Array([0]);
  let authType = account_osAccount.AuthType.PIN;
  let authTrustLevel = account_osAccount.AuthTrustLevel.ATL1;
  try {
    userAuth.auth(challenge, authType, authTrustLevel, {
      onResult: function(result,extraInfo){
          console.log('auth result = ' + result);
          console.log('auth extraInfo = ' + JSON.stringify(extraInfo));
      }
    });
  } catch (e) {
    console.log('auth exception = ' + JSON.stringify(e));
  }
  ```

### authUser<sup>8+</sup>

authUser(userId: number, challenge: Uint8Array, authType: AuthType, authTrustLevel: AuthTrustLevel, callback: IUserAuthCallback): Uint8Array;

Performs authentication of the specified user. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_USER_AUTH_INTERNAL

**Parameters**

| Name          | Type                                                | Mandatory| Description                               |
| --------------- | ---------------------------------------------------- | --- | ------------------------------------ |
| userId          | number                                               | Yes | User ID.                       |
| challenge       | Uint8Array                                           | Yes | Challenge value, which is a random number used to improve security.                         |
| authType        | [AuthType](#authtype8)                   | Yes | Authentication credential type.                       |
| authTrustLevel  | [AuthTrustLevel](#authtrustlevel8)       | Yes | Trust level of the authentication result.              |
| callback        | [IUserAuthCallback](#iuserauthcallback8) | Yes | Callback invoked to return the authentication result. |

**Return value**

| Type       | Description              |
| ---------- | ------------------ |
| Uint8Array | ID of the context for canceling the authentication.|

**Error codes**

| ID| Error Message         |
| -------- | --------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid userId or challenge or authType or authTrustLevel. |
| 12300101 | Credential is incorrect. |
| 12300105 | Unsupported authTrustLevel. |
| 12300106 | Unsupported authType. |
| 12300110 | Authentication locked. |
| 12300111 | Authentication timeout. |
| 12300112 | Authentication service busy. |

**Example**
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let userID = 100;
  let challenge = new Uint8Array([0]);
  let authType = account_osAccount.AuthType.PIN;
  let authTrustLevel = account_osAccount.AuthTrustLevel.ATL1;
  try {
    userAuth.authUser(userID, challenge, authType, authTrustLevel, {
      onResult: function(result,extraInfo){
        console.log('authUser result = ' + result);
        console.log('authUser extraInfo = ' + JSON.stringify(extraInfo));
      }
    });
  } catch (e) {
    console.log('authUser exception = ' + JSON.stringify(e));
  }
  ```

### cancelAuth<sup>8+</sup>

cancelAuth(contextID: Uint8Array): void;

Cancels an authentication.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_USER_AUTH_INTERNAL

**Parameters**

| Name   | Type      | Mandatory | Description                                       |
| ----------| ---------- | ---- | ------------------------------------------ |
| contextId | Uint8Array | Yes  | ID of the authentication context. The context ID is dynamically generated.|

**Error codes**

| ID| Error Message           |
| -------- | ------------------ |
| 12300001 | System service exception. |
| 12300002 | Invalid contextId. |

**Example**
  ```js
  let userAuth = new account_osAccount.UserAuth();
  let pinAuth = new account_osAccount.PINAuth();
  let challenge = new Uint8Array([0]);
  let contextId = userAuth.auth(challenge, account_osAccount.AuthType.PIN, account_osAccount.AuthTrustLevel.ATL1, {
    onResult: (result, extraInfo) => {
      console.log('auth result = ' + result);
      console.log('auth extraInfo = ' + JSON.stringify(extraInfo));
    }
  });
  try {
    userAuth.cancelAuth(contextId);
  } catch (e) {
    console.log('cancelAuth exception = ' + JSON.stringify(e));
  }
  ```

## PINAuth<sup>8+</sup>

Provides APIs for PIN authentication.

**System API**: This is a system API.

### constructor<sup>8+</sup>

constructor()

A constructor used to create an instance for PIN authentication.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Example** 
  ```js
  let pinAuth = new account_osAccount.PINAuth();
  ```

### registerInputer<sup>8+</sup>

registerInputer(inputer: IInputer): void;

Register a PIN inputer.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_PIN_AUTH

**Parameters**

| Name   | Type                    | Mandatory| Description                     |
| ----------| ----------------------- | --- | -------------------------- |
| inputer   | [IInputer](#iinputer8)  | Yes | PIN inputer, which is used to obtain the PIN.|

**Return value**

| Type   | Description                                          |
| :------ | :-------------------------------------------- |
| boolean | Returns **true** if the operation is successful; returns **false** otherwise.|

**Error codes**

| ID| Error Message                    |
| -------- | --------------------------- |
| 12300001 | System service exception. |
| 12300103 | Inputer already registered. |

**Example**
  ```js
  let pinAuth = new account_osAccount.PINAuth();
  let password = new Uint8Array([0, 0, 0, 0, 0]);
  try {
    let result = pinAuth.registerInputer({
        onGetData: (pinSubType, callback) => {
          callback.onSetData(pinSubType, password);
        }
    });
    console.log('registerInputer result = ' + result);
  } catch (e) {
    console.log('registerInputer exception = ' + JSON.stringify(e));
  }
  ```

### unregisterInputer<sup>8+</sup>

unregisterInputer(): void;

Unregisters this PIN inputer.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.ACCESS_PIN_AUTH

**Example**
  ```js
  let pinAuth = new account_osAccount.PINAuth();
  pinAuth.unregisterInputer();
  ```

## UserIdentityManager<sup>8+</sup>

Provides APIs for user identity management (IDM).

**System API**: This is a system API.

### constructor<sup>8+</sup>

constructor()

A constructor used to create an instance for user IDM.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Example** 
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  ```

### openSession<sup>8+</sup>

openSession(callback: AsyncCallback&lt;Uint8Array&gt;): void;

Opens a session to obtain the challenge value. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Parameters**

| Name   | Type                            | Mandatory| Description                                                           |
| -------- | -------------------------------- | ---- | -------------------------------------------------------------- |
| callback | AsyncCallback&lt;Uint8Array&gt;  | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the challenge value obtained. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message                    |
| -------- | --------------------------- |
| 12300001 | System service exception. |

**Example**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  try {
    userIDM.openSession((err, challenge) => {
        console.log('openSession error = ' + JSON.stringify(err));
        console.log('openSession challenge = ' + JSON.stringify(challenge));
    });
  } catch (e) {
    console.log('openSession exception = ' + JSON.stringify(e));
  }
  ```

### openSession<sup>8+</sup>

openSession(): Promise&lt;Uint8Array&gt;;

Opens a session to obtain the challenge value. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Return value**

| Type                     | Description                    |
| :------------------------ | ----------------------- |
| Promise&lt;Uint8Array&gt; | Promise used to return the challenge value obtained.|

**Error codes**

| ID| Error Message                    |
| -------- | --------------------------- |
| 12300001 | System service exception. |

**Example**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  try {
    userIDM.openSession().then((challenge) => {
        console.info('openSession challenge = ' + JSON.stringify(challenge));
    }).catch((err) => {
        console.info('openSession error = ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('openSession exception = ' + JSON.stringify(e));
  }
  ```

### addCredential<sup>8+</sup>

addCredential(credentialInfo: CredentialInfo, callback: IIdmCallback): void;

Adds credential information, including the credential type, subtype, and token (if a non-PIN credential is added).

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Parameters**

| Name          | Type                                | Mandatory| Description                       |
| --------------- | ------------------------------------ | --- | ---------------------------- |
| credentialInfo  | [CredentialInfo](#credentialinfo8)   | Yes | Credential information to add.               |
| callback        | [IIdmCallback](#iidmcallback8)       | Yes | Callback invoked to return the result. |

**Error codes**

| ID| Error Message                    |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid credentialInfo, i.e. authType or authSubType. |
| 12300101 | Token is invalid. |
| 12300106 | Unsupported authType. |

**Example**
  ```js
  let password = new Uint8Array([0, 0, 0, 0, 0, 0]);
  let pinAuth = new account_osAccount.PINAuth();
  pinAuth.registerInputer({
    onGetData: (pinSubType, callback) => {
      callback.onSetData(pinSubType, password);
    }
  });
  let credentialInfo = {
    credType: account_osAccount.AuthType.PIN,
    credSubType: account_osAccount.AuthSubType.PIN_SIX,
    token: null
  };
  let userIDM = new account_osAccount.UserIdentityManager();
  userIDM.openSession((err, challenge) => {
    try {
    userIDM.addCredential(credentialInfo, {
      onResult: (result, extraInfo) => {
        console.log('updateCredential result = ' + result);
        console.log('updateCredential extraInfo = ' + extraInfo);
      }
    });
    } catch (e) {
      console.log('updateCredential exception = ' + JSON.stringify(e));
    }
  });
  ```

### updateCredential<sup>8+</sup>

updateCredential(credentialInfo: CredentialInfo, callback: IIdmCallback): void;

Updates credential information. This API uses a callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Parameters**

| Name          | Type                                 | Mandatory| Description                    |
| --------------- | ------------------------------------- | --- | ------------------------- |
| credentialInfo  | [CredentialInfo](#credentialinfo8)    | Yes | New credential information.            |
| callback        | [IIdmCallback](#iidmcallback8)        | Yes | Callback invoked to return the new credential information.|

**Error codes**

| ID| Error Message                    |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid credentialInfo, i.e. authType or authSubType or token. |
| 12300101 | Token is invalid. |
| 12300106 | Unsupported authType. |

**Example**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  let userAuth = new account_osAccount.UserAuth();
  let pinAuth = new account_osAccount.PINAuth();
  let password = new Uint8Array([0, 0, 0, 0, 0, 0]);
  let credentialInfo = {
    credType: account_osAccount.AuthType.PIN,
    credSubType: account_osAccount.AuthSubType.PIN_SIX,
    token: null
  };
  pinAuth.registerInputer({
    onGetData: (pinSubType, callback) => {
      callback.onSetData(pinSubType, password);
    }
  });
  userIDM.openSession((err, challenge) => {
    userAuth.auth(challenge, credentialInfo.credType, account_osAccount.AuthTrustLevel.ATL1, {
      onResult: (result, extraInfo) => {
        if (result != account_osAccount.ResultCode.SUCCESS) {
          return;
        }
        credentialInfo.token = extraInfo.token;
        try {
          userIDM.updateCredential(credentialInfo, {
            onResult: (result, extraInfo) => {
                console.log('updateCredential result = ' + result);
                console.log('updateCredential extraInfo = ' + extraInfo);
            }
          });
        } catch (e) {
          console.log('updateCredential exception = ' + JSON.stringify(e));
        }
      }
    });
  });
  ```

### closeSession<sup>8+</sup>

closeSession(): void;

Closes this session to terminate IDM.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Example**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  userIDM.closeSession();
  ```

### cancel<sup>8+</sup>

cancel(challenge: Uint8Array): void;

Cancels an entry based on the challenge value.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Parameters**

| Name   | Type       | Mandatory| Description  |
| -------- | ----------- | ---- | ----- |
| challenge | Uint8Array | Yes  | Challenge value.|

**Error codes**

| ID| Error Message           |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid challenge. |

**Example**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  let challenge = new Uint8Array([0]);
  try {
    userIDM.cancel(challenge);
  } catch(err) {
    console.log("cancel err:" + JSON.stringify(err));
  }
  ```

### delUser<sup>8+</sup>

delUser(token: Uint8Array, callback: IIdmCallback): void;

Deletes a user based on the authentication token. This API uses a callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Parameters**

| Name   | Type                          | Mandatory| Description                     |
| -------- | ------------------------------ | --- | ------------------------- |
| token    | Uint8Array                     | Yes | Authentication token.            |
| callback | [IIdmCallback](#iidmcallback8) | Yes | Callback invoked to return the result.|

**Error codes**

| ID| Error Message       |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300101 | Token is invalid. |

**Example**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  let token = new Uint8Array([0]);
  try {
    userIDM.delUser(token, {
      onResult: (result, extraInfo) => {
        console.log('delUser result = ' + result);
        console.log('delUser extraInfo = ' + JSON.stringify(extraInfo));
      }
    });
  } catch (e) {
    console.log('delUser exception = ' + JSON.stringify(e));
  }
  ```

### delCred<sup>8+</sup>

delCred(credentialId: Uint8Array, token: Uint8Array, callback: IIdmCallback): void;

Deletes user credential information.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_USER_IDM

**Parameters**

| Name          | Type                                           | Mandatory| Description                     |
| --------------- | ----------------------------------- | --- | ---------------------------|
| credentialId    | Uint8Array                          | Yes | Credential ID.                 |
| token           | Uint8Array                          | Yes | Authentication token.              |
| callback        | [IIdmCallback](#iidmcallback8)      | Yes | Callback invoked to return the result.|

**Error codes**

| ID| Error Message            |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid credentialId. |
| 12300101 | Token is invalid. |
| 12300102 | Credential not found. |

**Example**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  let credentialId = new Uint8Array([0]);
  let token = new Uint8Array([0]);
  try {
    userIDM.delCred(credentialId, token, {
      onResult: (result, extraInfo) => {
          console.log('delCred result = ' + result);
          console.log('delCred extraInfo = ' + JSON.stringify(extraInfo));
      }
    });
  } catch (e) {
    console.log('delCred exception = ' + JSON.stringify(e));
  }
  ```

### getAuthInfo<sup>8+</sup>

getAuthInfo(callback: AsyncCallback&lt;Array&lt;EnrolledCredInfo&gt;&gt;): void;

Obtains authentication information. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.USE_USER_IDM

**Parameters**

| Name   | Type                                                                    | Mandatory| Description                                                |
| -------- | ------------------------------------------------------------------------ | ---- | --------------------------------------------- |
| callback | AsyncCallback&lt;Array&lt;[EnrolledCredInfo](#enrolledcredinfo8)&gt;&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is information about all registered credentials of the user. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message              |
| -------- | --------------------- |
| 12300001 | System service exception. |
| 12300102 | Credential not found. |

**Example**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  try {
    userIDM.getAuthInfo((err, result) => {
      console.log('getAuthInfo err = ' + JSON.stringify(err));
      console.log('getAuthInfo result = ' + JSON.stringify(result));
    });
  } catch (e) {
    console.log('getAuthInfo exception = ' + JSON.stringify(e));
  }
  ```

### getAuthInfo<sup>8+</sup>

getAuthInfo(authType: AuthType, callback: AsyncCallback&lt;Array&lt;EnrolledCredInfo&gt;&gt;): void;

Obtains authentication information of the specified type. This API uses an asynchronous callback to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.USE_USER_IDM

**Parameters**

| Name   | Type                                              | Mandatory| Description                                               |
| -------- | -------------------------------------------------- | ---- | -------------------------------------------------- |
| authType | [AuthType](#authtype8) | Yes  | Authentication credential type.                                         |
| callback | AsyncCallback&lt;Array&lt;[EnrolledCredInfo](#enrolledcredinfo8)&gt;&gt; | Yes  | Callback invoked to return the result. If the operation is successful, **err** is **null** and **data** is the information about all enrolled credentials of the specified type. Otherwise, **err** is an error object.|

**Error codes**

| ID| Error Message              |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid authType. |
| 12300102 | Credential not found. |

**Example**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  try {
    userIDM.getAuthInfo(account_osAccount.AuthType.PIN, (err, result) => {
      console.log('getAuthInfo err = ' + JSON.stringify(err));
      console.log('getAuthInfo result = ' + JSON.stringify(result));
    });
  } catch (e) {
    console.log('getAuthInfo exception = ' + JSON.stringify(e));
  }
  ```

### getAuthInfo<sup>8+</sup>

getAuthInfo(authType?: AuthType): Promise&lt;Array&lt;EnrolledCredInfo&gt;&gt;;

Obtains authentication information of the specified type. This API uses a promise to return the result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.USE_USER_IDM

**Parameters**

| Name   | Type                               | Mandatory| Description     |
| -------- | ----------------------------------- | ---- | -------- |
| authType | [AuthType](#authtype8)              | No  | Authentication credential type.|

**Return value**

| Type                                        | Description                                                                    |
| :------------------------------------------- | :----------------------------------------------------------------------- |
| Promise&lt;Array&lt;[EnrolledCredInfo](#enrolledcredinfo8)&gt;&gt; | Promise used to return the information about all the enrolled credentials of the specified type.|

**Error codes**

| ID| Error Message              |
| -------- | ------------------- |
| 12300001 | System service exception. |
| 12300002 | Invalid authType. |
| 12300102 | Credential not found. |

**Example**
  ```js
  let userIDM = new account_osAccount.UserIdentityManager();
  try {
    userIDM.getAuthInfo(account_osAccount.AuthType.PIN).then((result) => {
      console.log('getAuthInfo result = ' + JSON.stringify(result))
    }).catch((err) => {
      console.log('getAuthInfo error = ' + JSON.stringify(err));
    });
  } catch (e) {
    console.log('getAuthInfo exception = ' + JSON.stringify(e));
  }
  ```

## IInputData<sup>8+</sup>

Provides callbacks for PIN operations.

**System API**: This is a system API.

### onSetData<sup>8+</sup>

onSetData: (pinSubType: AuthSubType, data: Uint8Array) => void;

**System API**: This is a system API.

Called to set data in a PIN operation.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name     | Type                                    | Mandatory| Description                                           |
| ---------- | ---------------------------------------- | ---- | ----------------------------------------------- |
| pinSubType | [AuthSubType](#authsubtype8)             | Yes  | Credential subtype.                           |
| data       | Uint8Array                               | Yes  | Data (credential) to set. The data is used for authentication and operations for adding and modifying credentials.|

**Example**
  ```js
  let password = new Uint8Array([0, 0, 0, 0, 0, 0]);
  let passwordNumber = new Uint8Array([1, 2, 3, 4]);
  let inputer = {
    onGetData: (pinSubType, callback) => {
        if (pinSubType == account_osAccount.AuthSubType.PIN_NUMBER) {
          callback.onSetData(pinSubType, passwordNumber);
        } else {
          callback.onSetData(pinSubType, password);
        }
    }
  };
  ```

## IInputer<sup>8+</sup>

Provides callbacks for the PIN input box.

**System API**: This is a system API.

### onGetData<sup>8+</sup>

onGetData: (pinSubType: AuthSubType, callback: IInputData) => void;

Called to obtain data.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name     | Type                                   | Mandatory| Description            |
| ---------- | --------------------------------------- | ---- | --------------- |
| callback   | [IInputData](#iinputdata8)  | Yes  | Called to input the PIN.|

**Example**
  ```js
  let password = new Uint8Array([0, 0, 0, 0, 0, 0]);
  let passwordNumber = new Uint8Array([1, 2, 3, 4]);
  let inputer = {
    onGetData: (pinSubType, callback) => {
        if (pinSubType == account_osAccount.AuthSubType.PIN_NUMBER) {
          callback.onSetData(pinSubType, passwordNumber);
        } else {
          callback.onSetData(pinSubType, password);
        }
    }
  };
  let pinAuth = new account_osAccount.PINAuth();
  let result = pinAuth.registerInputer(inputer);
  console.log('registerInputer result: ' + result);
  ```

## IUserAuthCallback<sup>8+</sup>

Provides callbacks for user authentication.

**System API**: This is a system API.

### onResult<sup>8+</sup>

onResult: (result: number, extraInfo: AuthResult) => void;

Called to return the result code and authentication result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                   | Mandatory| Description                |
| --------- | --------------------------------------- | ---- | ------------------- |
| result    | number                                   | Yes  | Authentication result code.|
| extraInfo | [AuthResult](#authresult8)  | Yes  | Specific authentication result information. If the authentication is successful, the authentication token is returned in **extrainfo**. If the authentication fails, the remaining authentication time is returned. If the authentication executor is locked, the freezing time is returned.|

**Example**
  ```js
  let authCallback = {
    onResult: (result, extraInfo) => {
      console.log('auth result = ' + result);
      console.log('auth extraInfo = ' + JSON.stringify(extraInfo));
    }
  };
  ```

### onAcquireInfo?<sup>8+</sup>

onAcquireInfo?: (module: number, acquire: number, extraInfo: any) => void;

Called to acquire identity authentication information.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name   | Type    | Mandatory| Description                          |
| --------- | ------- | ---- | ----------------------------- |
| module    | number  | Yes  | Type of authentication executor.  |
| acquire   | number  | Yes  | Tip code of the authentication executor.|
| extraInfo | any     | Yes  | Reserved.                    |

**Example**
  ```js
  let authCallback = {
    onResult: (result, extraInfo) => {
      console.log('auth result = ' + result)
      console.log('auth extraInfo = ' + JSON.stringify(extraInfo));
    },
    onAcquireInfo: (module, acquire, extraInfo) => {
      console.log('auth module = ' + module);
      console.log('auth acquire = ' + acquire);
      console.info('auth extraInfo = ' + JSON.stringify(extraInfo));
    }
  };
  ```

## IIdmCallback<sup>8+</sup>

Provides callbacks for IDM.

**System API**: This is a system API.

### onResult<sup>8+</sup>

onResult: (result: number, extraInfo: RequestResult) => void;

Called to return the result code and request result information.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name    | Type                                   | Mandatory| Description                    |
| --------- | --------------------------------------- | ---- | ----------------------- |
| result    | number                                  | Yes  | Authentication result code.   |
| extraInfo | [RequestResult](#requestresult8)  | Yes  | Specific information to be transferred.|

**Example**
  ```js
  let idmCallback = {
    onResult: (result, extraInfo) => {
      console.log('callback result = ' + result)
      console.info('callback extraInfo = ' + JSON.stringify(extraInfo));
    }
  };
  ```

### onAcquireInfo?<sup>8+</sup>

onAcquireInfo?: (module: number, acquire: number, extraInfo: any) => void;

Called to acquire IDM information.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

**Parameters**

| Name   | Type    | Mandatory| Description                          |
| --------- | ------- | ---- | ----------------------------- |
| module    | number  | Yes  | Type of authentication executor.  |
| acquire   | number  | Yes  | Tip code of the authentication executor.|
| extraInfo | any     | Yes  | Reserved.                    |

**Example**
  ```js
  let idmCallback = {
    onResult: (result, extraInfo) => {
      console.log('callback result = ' + result)
      console.log('callback onResult = ' + JSON.stringify(extraInfo));
    },
    onAcquireInfo: (module, acquire, extraInfo) => {
      console.log('callback module = ' + module);
      console.log('callback acquire = ' + acquire);
      console.log('callback onacquireinfo = ' + JSON.stringify(extraInfo));
    }
  };
  ```

## GetPropertyRequest<sup>8+</sup>

Defines the request for obtaining property information.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name   | Type                                                         | Mandatory  | Description                  |
| -------- | ------------------------------------------------------------- | ----- | ----------------------- |
| authType | [AuthType](#authtype8)                            | Yes   | Authentication credential type.       |
| keys     | Array&lt;[GetPropertyType](#getpropertytype8)&gt; | Yes   | An array of the types of the properties to obtain.|

## SetPropertyRequest<sup>8+</sup>

Defines the request for setting property information.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name   | Type                                            | Mandatory  | Description                |
| -------- | ------------------------------------------------ | ----- | -------------------- |
| authType | [AuthType](#authtype8)               | Yes   | Authentication credential type.    |
| key     | [SetPropertyType](#setpropertytype8) | Yes   | Type of the property to set.|
| setInfo  | Uint8Array                                       | Yes   | Information to set.    |

## ExecutorProperty<sup>8+</sup>

Defines the executor property.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name       | Type                                    | Mandatory  | Description             |
| ------------ | ---------------------------------------- | ----- | ----------------- |
| result       | number                                   | Yes   | Result.        |
| authSubType  | [AuthSubType](#authsubtype8) | Yes   | Authentication credential subtype.|
| remainTimes  | number                                   | No   | Remaining time.    |
| freezingTime | number                                   | No   | Freezing time.    |

## AuthResult<sup>8+</sup>

Defines the authentication result information.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name       | Type       | Mandatory  | Description             |
| ------------ | ----------- | ----- | ----------------- |
| token        | Uint8Array  | No   | Authentication token.    |
| remainTimes  | number      | No   | Remaining time.    |
| freezingTime | number      | No   | Freezing time.    |

## CredentialInfo<sup>8+</sup>

Defines the credential information.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name       | Type                                    | Mandatory  | Description             |
| ------------ | ---------------------------------------- | ----- | ----------------- |
| credType     | [AuthType](#authtype8)       | Yes   | Authentication credential type.    |
| credSubType  | [AuthSubType](#authsubtype8) | Yes   | Authentication credential subtype.  |
| token        | Uint8Array                           | Yes   | Authentication token.    |

## RequestResult<sup>8+</sup>

Defines the request result information.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name       | Type       | Mandatory  | Description             |
| ------------ | ----------- | ----- | ----------------- |
| credentialId | Uint8Array  | No   | Credential ID.    |

## EnrolledCredInfo<sup>8+</sup>

Defines enrolled credential information.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name       | Type                                    | Mandatory  | Description             |
| ------------ | ---------------------------------------- | ----- | ------------------- |
| credentialId | Uint8Array                               | Yes   | Credential ID.      |
| authType     | [AuthType](#authtype8)       | Yes   | Authentication credential type.  |
| authSubType  | [AuthSubType](#authsubtype8) | Yes   | Credential subtype.|
| templateId   | Uint8Array                               | Yes   | Authentication credential template ID.    |

## GetPropertyType<sup>8+</sup>

Enumerates the types of properties to obtain.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name          | Value| Description     |
| ------------- | ------ | --------- |
| AUTH_SUB_TYPE | 1      | Authentication credential subtype.|
| REMAIN_TIMES  | 2      | Remaining time.  |
| FREEZING_TIME | 3      | Freezing time.  |

## SetPropertyType<sup>8+</sup>

Enumerates the types of properties to set.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name          | Value| Description       |
| -------------- | ----- | ----------- |
| INIT_ALGORITHM | 1     | Initialization algorithm.|

## AuthType<sup>8+</sup>

Enumerates the authentication credential types.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name | Value| Description            |
| ----- | ----- | ---------------- |
| PIN   | 1     | PIN authentication.|
| FACE  | 2     | Facial authentication.|

## AuthSubType<sup>8+</sup>

Enumerates the authentication credential subtypes.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name      | Value| Description              |
| ---------- | ----- | ------------------ |
| PIN_SIX    | 10000 | Six-digit PIN.      |
| PIN_NUMBER | 10001 | Custom PIN.|
| PIN_MIXED  | 10002 | Custom mixed credential.|
| FACE_2D    | 20000 | 2D face credential.  |
| FACE_3D    | 20001 | 3D face credential.  |

## AuthTrustLevel<sup>8+</sup>

Enumerates the trust levels of the authentication result.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name | Value| Description       |
| ---- | ------ | ----------- |
| ATL1 | 10000  | Trust level 1.|
| ATL2 | 20000  | Trust level 2.|
| ATL3 | 30000  | Trust level 3.|
| ATL4 | 40000  | Trust level 4.|

## Module<sup>8+</sup>

Enumerates the modules from which information is obtained.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name      | Value| Description                    |
| --------- | ------ | ------------------------ |
| FACE_AUTH | 1      | Facial authentication module.|

## ResultCode<sup>8+</sup>

Enumerates the authentication result codes.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name                   | Value| Description                                    |
| ----------------------- | ----- | ---------------------------------------- |
| SUCCESS                 | 0     | The authentication is successful or the authentication feature is supported.            |
| FAIL                    | 1     | The authentication executor failed to identify the user.                  |
| GENERAL_ERROR           | 2     | Other errors.                           |
| CANCELED                | 3     | The authentication is canceled.                      |
| TIMEOUT                 | 4     | The authentication timed out.                      |
| TYPE_NOT_SUPPORT        | 5     | The authentication credential type is not supported.                |
| TRUST_LEVEL_NOT_SUPPORT | 6     | The authentication trust level is not supported.              |
| BUSY                    | 7     | The authentication executor is busy. Try again after a few seconds.|
| INVALID_PARAMETERS      | 8     | Incorrect parameters are detected.                         |
| LOCKED                  | 9     | The authentication executor is locked.                    |
| NOT_ENROLLED            | 10    | The authentication executor is not enrolled.                  |

## FaceTipsCode<sup>8+</sup>

Enumerates the tip codes for facial authentication.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name                         | Value| Description                                    |
| ----------------------------- | ----- | ---------------------------------------- |
| FACE_AUTH_TIP_TOO_BRIGHT      | 1     | The obtained face image is too bright.        |
| FACE_AUTH_TIP_TOO_DARK        | 2     | The obtained face image is too dark.      |
| FACE_AUTH_TIP_TOO_CLOSE       | 3     | The face is too close to the device.                      |
| FACE_AUTH_TIP_TOO_FAR         | 4     | The face is too far away from the device.                      |
| FACE_AUTH_TIP_TOO_HIGH        | 5     | Only the upper part of the face is captured because the device is angled too high.             |
| FACE_AUTH_TIP_TOO_LOW         | 6     | Only the lower part of the face is captured because the device is angled too low.             |
| FACE_AUTH_TIP_TOO_RIGHT       | 7     | Only the right part of the face is captured because the device is angled too much to the right.|
| FACE_AUTH_TIP_TOO_LEFT        | 8     | Only the left part of the face is captured because the device is angled too much to the left.|
| FACE_AUTH_TIP_TOO_MUCH_MOTION | 9     | The face moves too fast during facial information collection.        |
| FACE_AUTH_TIP_POOR_GAZE       | 10    | The face is not facing the device.                        |
| FACE_AUTH_TIP_NOT_DETECTED    | 11    | No face is detected.                        |

## FingerprintTips<sup>8+</sup>

Enumerates the tip codes for fingerprint authentication.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name                         | Value| Description                                           |
| ----------------------------- | ----- | ----------------------------------------------- |
| FINGERPRINT_TIP_GOOD          | 0     | The captured image is clear.                             |
| FINGERPRINT_TIP_IMAGER_DIRTY  | 1     | The fingerprint image has big noise due to dirt on the sensor.|
| FINGERPRINT_TIP_INSUFFICIENT  | 2     | Failed to process the fingerprint image due to big noise.  |
| FINGERPRINT_TIP_PARTIAL       | 3     | Only part of the fingerprint image is detected.                        |
| FINGERPRINT_TIP_TOO_FAST      | 4     | The fingerprint image is incomplete due to quick motion.                 |
| FINGERPRINT_TIP_TOO_SLOW      | 5     | Failed to read the fingerprint image due to lack of motion.               |

## OsAccountInfo

Defines the OS account information.

**System capability**: SystemCapability.Account.OsAccount

| Name                        | Type                                                        | Mandatory| Description                             |
| ------------------------------ | ------------------------------------------------------------ | ---- | --------------------------------- |
| localId                        | number                                                       | Yes  | ID of the target OS account.                     |
| localName                      | string                                                       | Yes  | OS account name.                   |
| type                           | [OsAccountType](#osaccounttype)                              | Yes  | OS account type.                     |
| constraints                    | Array&lt;string&gt;                                          | No  | [Constraints](#constraints) on the OS account.|
| isVerified<sup>8+</sup>        | boolean                                                      | Yes  | Whether the OS account is verified.                     |
| photo<sup>8+</sup>             | string                                                       | No  | Profile photo of the OS account.                     |
| createTime<sup>8+</sup>        | number                                                       | Yes  | Time when the OS account was created.                 |
| lastLoginTime<sup>8+</sup>     | number                                                       | No  | Last login time of the OS account.         |
| serialNumber<sup>8+</sup>      | number                                                       | Yes  | SN of the OS account.                     |
| isActived<sup>8+</sup>         | boolean                                                      | Yes  | Whether the OS account is activated.                 |
| isCreateCompleted<sup>8+</sup> | boolean                                                      | Yes  | Whether the OS account information is complete.             |
| distributedInfo                | [distributedAccount.DistributedInfo](js-apis-distributed-account.md) | No  | Distributed account information.                   |
| domainInfo<sup>8+</sup>        | [DomainAccountInfo](#domainaccountinfo8)                      | No  | Domain account information.                       |

## DomainAccountInfo<sup>8+</sup>

Defines the domain account information.

**System capability**: SystemCapability.Account.OsAccount

| Name     | Type  | Mandatory| Description      |
| ----------- | ------ | ---- | ---------- |
| domain      | string | Yes  | Domain name.    |
| accountName | string | Yes  | Domain account name.|

## Constraints

| Constraint                                 | Description                          |
| ------------------------------------- | ------------------------------ |
| constraint.wifi                       | A user is not allowed to use Wi-Fi.                 |
| constraint.wifi.set                   | A user is not allowed to set Wi-Fi.                 |
| constraint.locale.set                 | A user is not allowed to change the device language.              |
| constraint.app.accounts               | A user is not allowed to add or delete app accounts.        |
| constraint.apps.install               | A user is not allowed to install apps.                  |
| constraint.apps.uninstall             | A user is not allowed to uninstall apps.                  |
| constraint.location.shared            | A user is not allowed to enable location sharing.              |
| constraint.unknown.sources.install    | A user is not allowed to install apps from unknown sources.        |
| constraint.global.unknown.app.install | All users are not allowed to install apps from unknown sources.|
| constraint.bluetooth.set              | A user is not allowed to configure Bluetooth.                  |
| constraint.bluetooth | The use of Bluetooth is prohibited on the device.|
| constraint.bluetooth.share | Bluetooth sharing is prohibited.|
| constraint.usb.file.transfer | A user is not allowed to transfer files over USB.|
| constraint.credentials.set | A user is not allowed to configure user credentials.|
| constraint.os.account.remove | An admin user is not allowed to remove users or a non-admin user is not allowed to remove itself.|
| constraint.managed.profile.remove | The managed profiles of this user cannot be removed.|
| constraint.debug.features.use | A user is not allowed to enable or access debugging features.|
| constraint.vpn.set | A user is not allowed to configure a VPN.|
| constraint.date.time.set | A user is not allowed to set date, time, or time zone.|
| constraint.tethering.config | A user is not allowed to configure Tethering.|
| constraint.network.reset | A user is not allowed to reset network settings.|
| constraint.factory.reset | A user is not allowed to reset factory settings.|
| constraint.os.account.create | A user is not allowed to create users.|
| constraint.add.managed.profile | A user is not allowed to add managed profiles.|
| constraint.apps.verify.disable | A user is not allowed to disable app verification.|
| constraint.cell.broadcasts.set | A user is not allowed to configure cell broadcasts.|
| constraint.mobile.networks.set | A user is not allowed to configure radio networks.|
| constraint.control.apps | A user is not allowed to modify apps in **Settings** or the boot module.|
| constraint.physical.media | A user is not allowed to mount external physical media.|
| constraint.microphone | A user is not allowed to use microphones.|
| constraint.microphone.unmute | A user is not allowed to unmute the microphone.|
| constraint.volume.adjust | A user is not allowed to adjust the volume.|
| constraint.calls.outgoing | A user is not allowed to make outgoing calls.|
| constraint.sms.use | A user is not allowed to send or receive SMS messages.|
| constraint.fun | A user is not allowed to have entertainment.|
| constraint.windows.create | Windows other than app windows cannot be created.|
| constraint.system.error.dialogs | Error dialogs for crashed or unresponsive apps are prohibited.|
| constraint.cross.profile.copy.paste | Pasting clipboard content to other users or profiles is prohibited.|
| constraint.beam.outgoing | A user is not allowed to use Near Field Communications (NFC) to transfer data from apps.|
| constraint.wallpaper | A user is not allowed to manage wallpapers.|
| constraint.safe.boot | A user is not allowed to reboot the device in safe boot mode.|
| constraint.parent.profile.app.linking | The apps in the parent profile are allowed to handle web links from the managed profile.|
| constraint.audio.record | Audio recording is prohibited.|
| constraint.camera.use | The use of cameras is prohibited.|
| constraint.os.account.background.run | Running in the background is prohibited.|
| constraint.data.roam | A user is not allowed to use cellular data when roaming.|
| constraint.os.account.set.icon | A user is not allowed to change their icon.|
| constraint.wallpaper.set | A user is not allowed to set a wallpaper.|
| constraint.oem.unlock | A user is not allowed to enable OEM unlock.|
| constraint.device.unmute | A user is not allowed to unmute the device.|
| constraint.password.unified | The managed profile is not allowed to have unified lock screen challenge with the primary user.|
| constraint.autofill | A user is not allowed to use the autofill service.|
| constraint.content.capture | Capturing the content of a user's screen is prohibited.|
| constraint.content.suggestions | A user is not allowed to receive content suggestions.|
| constraint.os.account.start | User switching is blocked.|
| constraint.location.set | A user is not allowed to configure the location service.|
| constraint.airplane.mode.set | The airplane mode is prohibited on the device.|
| constraint.brightness.set | A user is not allowed to configure brightness.|
| constraint.share.into.profile | A user is not allowed to share files, images, or data from the primary user to the managed profile.|
| constraint.ambient.display | Ambient display is prohibited for the user.|
| constraint.screen.timeout.set | A user is not allowed to configure the screen off timeout.|
| constraint.print | A user is not allowed to print.|
| constraint.private.dns.set | A user is not allowed to configure a private domain name server (DNS).|

## ConstraintSourceTypeInfo<sup>9+</sup>

Defines the constraint source type.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name     | Type  | Mandatory| Description      |
| ----------- | ------ | ---- | ---------- |
| localId      | number | Yes  | ID of the OS account.    |
| type | [ConstraintSourceType](#constraintsourcetype) | Yes  | Type of the constrain source.|

## ConstraintSourceType<sup>9+</sup>

Enumerates the constraint sources.

**System API**: This is a system API.

**System capability**: SystemCapability.Account.OsAccount

| Name  | Value| Description        |
| ------ | ------ | ------------ |
| CONSTRAINT_NOT_EXIST  | 0      | The constraint does not exist.|
| CONSTRAINT_TYPE_BASE | 1      | Constraint from system settings.  |
| CONSTRAINT_TYPE_DEVICE_OWNER  | 2   | Constraint from the device owners' settings.  |
| CONSTRAINT_TYPE_PROFILE_OWNER  | 3  | Constraint from the profile owners' settings.  |
