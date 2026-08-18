# @ohos.account.distributedAccount (Distributed Account Management)

<!--Kit: Basic Services Kit-->
<!--Subsystem: Account-->
<!--Owner: @steven-q-->
<!--Designer: @JiDong-CS1-->
<!--Tester: @pan9f-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=3de182f5b788a3afd1b8fcd773572aaabf69c317 translatedAt=2026-08-17T09:28:42.375Z pushedAt=2026-08-18T03:02:26.973Z -->

This module provides APIs for managing distributed accounts, including querying and updating account login states. This module is applicable to multi-device collaboration, improving the consistency and user experience of cross-device account management. Typical application scenarios include multi-device collaboration, distributed data synchronization, and cross-device capability calling.

> **NOTE**
>
> The initial APIs of this module are supported since API version 7. Newly added APIs will be marked with a superscript to indicate their earliest API version.

## Modules to Import

```ts
import { distributedAccount } from '@kit.BasicServicesKit';
```

## distributedAccount.getDistributedAccountAbility

getDistributedAccountAbility(): DistributedAccountAbility

Obtains a **DistributedAccountAbility** instance.

**System capability**: SystemCapability.Account.OsAccount

**Return value**

  | Type| Description|
  | -------- | -------- |
  | [DistributedAccountAbility](#distributedaccountability) | **DistributedAccountAbility** instance obtained. This instance provides APIs for querying and updating the login state of a distributed account.|

**Example**

  ```ts
  // Obtain a DistributedAccountAbility instance.
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  ```

## DistributedAccountAbility

Provides APIs for querying and updating the login state of a distributed account. You must obtain a **DistributedAccountAbility** instance first.

### getOsAccountDistributedInfo<sup>9+</sup>

getOsAccountDistributedInfo(callback: AsyncCallback&lt;DistributedInfo&gt;): void

Obtains the distributed account information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS (for system applications only), ohos.permission.GET_DISTRIBUTED_ACCOUNTS (for system applications only), or ohos.permission.DISTRIBUTED_DATASYNC

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[DistributedInfo](#distributedinfo)&gt; | Yes | Callback used to return the result. If the distributed account information is obtained successfully, **err** is **undefined** and **data** is the distributed account information obtained. Otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Account Management Error Codes](errorcode-account.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | System service exception. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Obtain a DistributedAccountAbility instance.
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  try {
    accountAbility.getOsAccountDistributedInfo(
      (err: BusinessError, data: distributedAccount.DistributedInfo) => {
        if (err) {
          console.error(`getOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
        } else {
          console.info('distributed information: ' + JSON.stringify(data));
        }
      });
  } catch (e) {
    const err = e as BusinessError;
    console.error(`getOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
  }
  ```

### getOsAccountDistributedInfo<sup>9+</sup>

getOsAccountDistributedInfo(): Promise&lt;DistributedInfo&gt;

Obtains the distributed account information. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS (for system applications only), ohos.permission.GET_DISTRIBUTED_ACCOUNTS (for system applications only), or ohos.permission.DISTRIBUTED_DATASYNC

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[DistributedInfo](#distributedinfo)&gt; | Promise used to return the distributed account information obtained.|

**Error codes**

For details about the error codes, see [Account Management Error Codes](errorcode-account.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ------------------- |
| 201 | Permission denied.|
| 12300001 | System service exception. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Obtain a DistributedAccountAbility instance.
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  try {
    accountAbility.getOsAccountDistributedInfo().then((data: distributedAccount.DistributedInfo) => {
      console.info('distributed information: ' + JSON.stringify(data));
    }).catch((err: BusinessError) => {
      console.error(`getOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
    });
  } catch (e) {
    const err = e as BusinessError;
    console.error(`getOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
  }
  ```

### queryOsAccountDistributedInfo<sup>(deprecated)</sup>

queryOsAccountDistributedInfo(callback: AsyncCallback&lt;DistributedInfo&gt;): void

Queries the distributed account information. This API uses an asynchronous callback to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getOsAccountDistributedInfo](#getosaccountdistributedinfo9) instead.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (for system applications only) or ohos.permission.DISTRIBUTED_DATASYNC

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | callback | AsyncCallback&lt;[DistributedInfo](#distributedinfo)&gt; | Yes | Callback used to return the result. If the distributed account information is obtained successfully, **err** is **undefined** and **data** is the distributed account information obtained. Otherwise, **err** is an error object. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Obtain a DistributedAccountAbility instance.
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  accountAbility.queryOsAccountDistributedInfo(
    (err: BusinessError, data: distributedAccount.DistributedInfo) => {
      if (err) {
        console.error(`queryOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('distributed information: ' + JSON.stringify(data));
      }
    });
  ```

### queryOsAccountDistributedInfo<sup>(deprecated)</sup>

queryOsAccountDistributedInfo(): Promise&lt;DistributedInfo&gt;

Queries the distributed account information. This API uses a promise to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [getOsAccountDistributedInfo](#getosaccountdistributedinfo9-1) instead.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (for system applications only) or ohos.permission.DISTRIBUTED_DATASYNC

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;[DistributedInfo](#distributedinfo)&gt; | Promise used to return the distributed account information obtained.|

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Obtain a DistributedAccountAbility instance.
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  accountAbility.queryOsAccountDistributedInfo().then((data: distributedAccount.DistributedInfo) => {
    console.info('distributed information: ' + JSON.stringify(data));
  }).catch((err: BusinessError) => {
    console.error(`queryOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
  });
  ```

### setOsAccountDistributedInfo<sup>9+</sup>

setOsAccountDistributedInfo(accountInfo: DistributedInfo, callback: AsyncCallback&lt;void&gt;): void

Sets the distributed account information. This API uses an asynchronous callback to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS (available only for system applications)

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | accountInfo | [DistributedInfo](#distributedinfo) | Yes| Distributed account information to set.|
  | callback | AsyncCallback&lt;void&gt; | Yes | Callback used to return the result. If the distributed account information is updated successfully, **err** is **undefined**. Otherwise, **err** is an error object. |

**Error codes**

For details about the error codes, see [Account Management Error Codes](errorcode-account.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | System service exception. |
| 12300002 | Invalid accountInfo. |
| 12300003 | Account not found. |
| 12300406 | The distributed account information has already been bound to a sub-profile of the same OS account.<br>Applicable versions: 26.0.0+ |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Obtain a DistributedAccountAbility instance.
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  // This is an example. Replace it with the actual distributed account information obtained using getOsAccountDistributedInfo.
  let accountInfo: distributedAccount.DistributedInfo =
    { id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN' };
  try {
    accountAbility.setOsAccountDistributedInfo(accountInfo, (err: BusinessError) => {
      if (err) {
        console.error(`setOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
      } else {
        console.info('setOsAccountDistributedInfo successfully');
      }
    });
  } catch (e) {
    const err = e as BusinessError;
    console.error(`setOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
  }
  ```

### setOsAccountDistributedInfo<sup>9+</sup>

setOsAccountDistributedInfo(accountInfo: DistributedInfo): Promise&lt;void&gt;

Sets the distributed account information. This API uses a promise to return the result.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_DISTRIBUTED_ACCOUNTS (available only for system applications)

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | accountInfo | [DistributedInfo](#distributedinfo) | Yes| Distributed account information to set.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value. |

**Error codes**

For details about the error codes, see [Account Management Error Codes](errorcode-account.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message|
| -------- | ------------------- |
| 201 | Permission denied.|
| 401 | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified. 2. Incorrect parameter types. |
| 12300001 | System service exception. |
| 12300002 | Invalid accountInfo. |
| 12300003 | Account not found. |
| 12300406 | The distributed account information has already been bound to a sub-profile of the same OS account.<br>Applicable versions: 26.0.0+ |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Obtain a DistributedAccountAbility instance.
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  // This is an example. Replace it with the actual distributed account information obtained using getOsAccountDistributedInfo.
  let accountInfo: distributedAccount.DistributedInfo =
    { id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN' };
  try {
    accountAbility.setOsAccountDistributedInfo(accountInfo).then(() => {
      console.info('setOsAccountDistributedInfo successfully');
    }).catch((err: BusinessError) => {
      console.error(`setOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
    });
  } catch (e) {
    const err = e as BusinessError;
    console.error(`setOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
  }
  ```

### updateOsAccountDistributedInfo<sup>(deprecated)</sup>

updateOsAccountDistributedInfo(accountInfo: DistributedInfo, callback: AsyncCallback&lt;void&gt;): void

Updates the distributed account information. This API uses an asynchronous callback to return the result.

> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setOsAccountDistributedInfo](#setosaccountdistributedinfo9) instead.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | accountInfo | [DistributedInfo](#distributedinfo) | Yes| Distributed account information to update.|
  | callback | AsyncCallback&lt;void&gt; | Yes | Callback used to return the result. If the distributed account information is updated successfully, **err** is **undefined**. Otherwise, **err** is an error object. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Obtain a DistributedAccountAbility instance.
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  // This is an example. Replace it with the actual distributed account information obtained using getOsAccountDistributedInfo.
  let accountInfo: distributedAccount.DistributedInfo =
    { id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN' };
  accountAbility.updateOsAccountDistributedInfo(accountInfo, (err: BusinessError) => {
    if (err) {
      console.error(`updateOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
    } else {
      console.info('updateOsAccountDistributedInfo successfully');
    }
  });
  ```

### updateOsAccountDistributedInfo<sup>(deprecated)</sup>

updateOsAccountDistributedInfo(accountInfo: DistributedInfo): Promise&lt;void&gt;

Updates distributed account information. This API uses a promise to return the result.
> **NOTE**
>
> This API is supported since API version 7 and deprecated since API version 9. You are advised to use [setOsAccountDistributedInfo](#setosaccountdistributedinfo9-1) instead.

**System capability**: SystemCapability.Account.OsAccount

**Required permissions**: ohos.permission.MANAGE_LOCAL_ACCOUNTS (available only for system applications)

**Parameters**

  | Name| Type| Mandatory| Description|
  | -------- | -------- | -------- | -------- |
  | accountInfo | [DistributedInfo](#distributedinfo) | Yes| Distributed account information to update.|

**Return value**

  | Type| Description|
  | -------- | -------- |
  | Promise&lt;void&gt; | Promise that returns no value. |

**Example**

  ```ts
  import { BusinessError } from '@kit.BasicServicesKit';

  // Obtain a DistributedAccountAbility instance.
  const accountAbility: distributedAccount.DistributedAccountAbility = distributedAccount.getDistributedAccountAbility();
  // This is an example. Replace it with the actual distributed account information obtained using getOsAccountDistributedInfo.
  let accountInfo: distributedAccount.DistributedInfo =
    { id: '12345', name: 'ZhangSan', event: 'Ohos.account.event.LOGIN' };
  accountAbility.updateOsAccountDistributedInfo(accountInfo).then(() => {
    console.info('updateOsAccountDistributedInfo successfully');
  }).catch((err: BusinessError) => {
    console.error(`updateOsAccountDistributedInfo exception: code is ${err.code}, message is ${err.message}`);
  });
  ```

## DistributedInfo

Represents the distributed account information about an OS account.

**System capability**: SystemCapability.Account.OsAccount

| Name| Type| Read-Only | Optional| Description|
| -------- | -------- | -------- | -------- | -------- |
| name | string | No| No | Name of the distributed account. It must be a non-null string.|
| id | string | No| No | UID of the distributed account. It must be a non-null string.|
| event | string | No| No | Login state of the distributed account. The state can be login, logout, token invalid, or logoff, which correspond to the following strings respectively:<br>-&nbsp;Ohos.account.event.LOGIN<br>-&nbsp;Ohos.account.event.LOGOUT<br>-&nbsp;Ohos.account.event.TOKEN_INVALID<br>-&nbsp;Ohos.account.event.LOGOFF |
| nickname<sup>9+</sup> | string | No | Yes | Nickname of the distributed account. Set this parameter when the user nickname needs to be displayed. If this parameter is not set, it is left empty by default, which does not affect the account function. |
| avatar<sup>9+</sup> | string | No | Yes | Avatar of the distributed account. Set this parameter when the user avatar needs to be displayed. If this parameter is not set, it is left empty by default, which does not affect the account function. |
| status<sup>10+</sup> | [DistributedAccountStatus](#distributedaccountstatus10) | Yes | Yes | Status of the distributed account. The value is of the enumerated type. This parameter is used when the account login status needs to be queried or set. If this parameter is not set, the default value is **NOT_LOGGED_IN** (not logged in). |
| scalableData<sup>8+</sup> | object | No | Yes | Scalable data about the distributed account. Set this parameter when customized service information needs to be passed in key-value (KV) pairs. If this parameter is not set, it is left empty by default, which does not affect the basic account function. |

## DistributedAccountStatus<sup>10+</sup>

Enumerates the statuses of a distributed account.

**System capability**: SystemCapability.Account.OsAccount

| Name | Value| Description       |
| ---- | ------ | ----------- |
| NOT_LOGGED_IN   | 0  | The account has not logged in.|
| LOGGED_IN  | 1  | The account has logged in.|