# @ohos.enterprise.accountManager (Account Management)

The **accountManager** module provides APIs for account management of enterprise devices.

> **NOTE**
>
> - The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> - The APIs of this module can be used only in the stage model.
>
> - The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).

## Modules to Import

```ts
import { accountManager } from '@kit.MDMKit';
```

## accountManager.disallowOsAccountAddition

disallowOsAccountAddition(admin: Want, disallow: boolean, accountId?: number): void

Users are not allowed to add accounts.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                      |
| disallow  | boolean                                                 | Yes  | Whether to forbid the creation of local user accounts. The value **true** means the creation of local user accounts is forbidden, and the value **false** means the opposite. |
| accountId | number                                                  | No  | User ID, which specifies a user. If this parameter is not specified, all users are not allowed to add accounts. If this parameter is specified, specified users are not allowed to add accounts. The value must be greater than or equal to 0.<br>You can call the [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9) API to obtain the user ID.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  accountManager.disallowOsAccountAddition(wantTemp, true, 100);
  console.info('Succeeded in disallowing os account addition.');
} catch (err) {
  console.error(`Failed to disallow os account addition. Code: ${err.code}, message: ${err.message}`);
}
```

## accountManager.isOsAccountAdditionDisallowed

isOsAccountAdditionDisallowed(admin: Want, accountId?: number): boolean

Queries whether a user is not allowed to add an account.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility.                                      |
| accountId | number                                                  | No  | User ID, which specifies a user. If this parameter is not specified, the system queries whether all users are not allowed to add accounts. If this parameter is specified, the system queries whether specified users are not allowed to add accounts. The value must be greater than or equal to 0.<br>You can call the [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9) API to obtain the user ID.|

**Return value**

| Type   | Description                                                      |
| ------- | ---------------------------------------------------------- |
| boolean | If **true** is returned, accounts cannot be added.<br>If **false** is returned, the account can be added.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

try {
  let isDisallowed: boolean = accountManager.isOsAccountAdditionDisallowed(wantTemp, 100);
  console.info(`Succeeded in querying the os account addition or not: ${isDisallowed}`);
} catch (err) {
  console.error(`Failed to query the os account addition or not. Code: ${err.code}, message: ${err.message}`);
}
```

## accountManager.addOsAccountAsync

addOsAccountAsync(admin: Want, name: string, type: osAccount.OsAccountType): Promise&lt;osAccount.OsAccountInfo&gt;

Adds an account in the background. This API uses a promise to return the result.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager



**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility.                                      |
| name   | string                                                       | Yes  | Account name, which is the name of the account to be added. An account with the same name or an empty name cannot be created.|
| type   | [osAccount.OsAccountType](../apis-basic-services-kit/js-apis-osAccount.md#osaccounttype) | Yes  | Type of the account to add.<br>The value can be any of the following:<br>· **ADMIN**: administrator account.<br>· **NORMAL**: normal account.<br>· **GUEST**: guest account.|

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| Promise&lt;[osAccount.OsAccountInfo](../apis-basic-services-kit/js-apis-osAccount.md#osaccountinfo)&gt; | Promise used to return the added account information.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9201003  | Failed to add an OS account.                                 |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 401      | Parameter error. Possible causes: 1. Mandatory parameters are left unspecified; 2. Incorrect parameter types; 3. Parameter verification failed. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError, osAccount } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  bundleName: 'com.example.myapplication',
  abilityName: 'EntryAbility',
};

accountManager.addOsAccountAsync(wantTemp, "TestAccountName", osAccount.OsAccountType.NORMAL).then((info) => {
  console.info(`Succeeded in creating os account: ${JSON.stringify(info)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to creating os account. Code: ${err.code}, message: ${err.message}`);
});
```
## accountManager.setDomainAccountPolicy<sup>19+</sup>

setDomainAccountPolicy(admin: Want, domainAccountInfo: osAccount.DomainAccountInfo, policy: DomainAccountPolicy): void

Sets the domain account policy. This API takes effect only on 2-in-1 devices.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name           | Type                                                        | Mandatory| Description                                                        |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin             | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility.                                      |
| domainAccountInfo | [osAccount.DomainAccountInfo](../apis-basic-services-kit/js-apis-osAccount.md#domainaccountinfo8) | Yes  | Domain account information.<br>If the internal attribute of **domainAccountInfo** is empty, a global policy is set for all domain accounts.<br>If the internal attribute of **domainAccountInfo** is not empty, the policy is set for the specified domain account.<br>The priority of the specified domain account policy is higher than that of the global policy. If the specified domain account has a domain account policy, the global policy does not take effect for the domain account.<br>Note: To set a policy for a specified domain account, the **serverConfigId** field in **DomainAccountInfo** is mandatory.|
| policy            | [DomainAccountPolicy](#domainaccountpolicy19)                | Yes  | Domain account policy.<br>Note: After setting the domain account policy, you must change the domain account password on the device. Otherwise, the **passwordValidityPeriod** and **passwordExpirationNotification** configurations in **DomainAccountPolicy** do not take effect.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError, osAccount } from '@kit.BasicServicesKit';

async function setDomainAccountPolicy() {
  let wantTemp: Want = {
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility',
  };
  let policy: accountManager.DomainAccountPolicy = {
    authenticationValidityPeriod: 300,
    passwordValidityPeriod: 420,
    passwordExpirationNotification: 60,
  }
  // Set the global domain account policy.
  let accountInfo: osAccount.DomainAccountInfo = {
    domain: '',
    accountName: '',
    serverConfigId: '',
  }
  try {
    accountManager.setDomainAccountPolicy(wantTemp, accountInfo, policy);
    console.info('Succeeded in setting global domainAccount policy.');
  } catch (err) {
    console.error(`Failed to set domainAccount policy. Code: ${err.code}, message: ${err.message}`);
  }
  // Set the policy for a specified domain account.
  let accountInfo2: osAccount.DomainAccountInfo = {
    domain: '',
    accountName: '',
    serverConfigId: '',
  }
  let userId: number = 100;
  await osAccount.getAccountManager().getOsAccountDomainInfo(userId)
    .then((domainAccountInfo: osAccount.DomainAccountInfo) => {
      accountInfo2 = domainAccountInfo;
    }).catch((err: BusinessError) => {
      console.error(`Failed to get account domain info. Code: ${err.code}, message: ${err.message}`);
    })
  try {
    accountManager.setDomainAccountPolicy(wantTemp, accountInfo2, policy);
    console.info('Succeeded in setting domain account policy.');
  } catch (err) {
    console.error(`Failed to set domain account policy. Code: ${err.code}, message: ${err.message}`);
  }
}
```



## accountManager.getDomainAccountPolicy<sup>19+</sup>

getDomainAccountPolicy(admin: Want, domainAccountInfo: osAccount.DomainAccountInfo): DomainAccountPolicy

Obtains the domain account policy. This API takes effect only on 2-in-1 devices.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Parameters**

| Name           | Type                                                        | Mandatory| Description                                                        |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin             | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility.                                      |
| domainAccountInfo | [osAccount.DomainAccountInfo](../apis-basic-services-kit/js-apis-osAccount.md#domainaccountinfo8) | Yes  | Domain account information.<br>If all the internal attributes of **domainAccountInfo** are empty, the global domain account policy is queried.<br>If the internal attribute of **domainAccountInfo** is not empty, the specified domain account policy is queried.<br>Note: To query a specified domain account policy, the **serverConfigId** field in **DomainAccountInfo** is mandatory.|

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| [DomainAccountPolicy](#domainaccountpolicy19) | Domain account policy.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |

**Example**

```ts
import { Want } from '@kit.AbilityKit';
import { BusinessError, osAccount } from '@kit.BasicServicesKit';

async function getDomainAccountPolicy() {
  let wantTemp: Want = {
    bundleName: 'com.example.myapplication',
    abilityName: 'EntryAbility',
  };
  let domainAccountPolicy: accountManager.DomainAccountPolicy = {}
  // Query the global domain account policy.
  let accountInfo: osAccount.DomainAccountInfo = {
    domain: '',
    accountName: '',
    serverConfigId: '',
  }
  try {
    domainAccountPolicy = accountManager.getDomainAccountPolicy(wantTemp, accountInfo);
    console.info('Succeeded in getting global domain account policy.');
  } catch (err) {
    console.error(`Failed to get domain account policy. Code: ${err.code}, message: ${err.message}`);
  }
  // Query the policy of a specified domain account.
  let accountInfo2: osAccount.DomainAccountInfo = {
    domain: '',
    accountName: '',
    serverConfigId: '',
  }
  let userId: number = 100;
  await osAccount.getAccountManager()
    .getOsAccountDomainInfo(userId)
    .then((domainAccountInfo: osAccount.DomainAccountInfo) => {
      accountInfo2 = domainAccountInfo;
    })
    .catch((err: BusinessError) => {
      console.error(`Failed to get account domain info. Code: ${err.code}, message: ${err.message}`);
    })
  try {
    domainAccountPolicy = accountManager.getDomainAccountPolicy(wantTemp, accountInfo2);
    console.info('Succeeded in getting domain account policy.');
  } catch (err) {
    console.error(`Failed to get domain account policy. Code: ${err.code}, message: ${err.message}`);
  }
}
```

## DomainAccountPolicy<sup>19+</sup>

Domain account policy.

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

| Name                          | Type  | Read-Only| Optional| Description                                                        |
| ------------------------------ | ------ | ---- | ---- |------------------------------------------------------------ |
| authenticationValidityPeriod   | number | No  | Yes  |Validity period of the domain account authentication token, in seconds. The value range is [-1, 2147483647]. The validity period starts from the time when the domain account is authenticated for the last time, for example, login or unlocking after the screen is locked.<br>The default value is **-1**, indicating that the token is permanently valid. The value **0** indicates that the token becomes invalid immediately. After the token expires or becomes invalid, the domain account and password must be authenticated when a user logs in to the system.|
| passwordValidityPeriod         | number | No  | Yes  |Validity period of the domain account password, in seconds. The value range is [-1,2147483647]. The validity period starts from the time when the password is last changed on the device.<br>The default value is **-1**, indicating that the domain account password is permanently valid.|
| passwordExpirationNotification | number | No  | Yes  |Notification period before a domain account password expires, in seconds. The value range is [0, 2147483647].<br>The default value is **0**, indicating that the system does not display a message indicating that the domain account password has expired.<br>Note: **passwordExpirationNotification** must be used together with **passwordValidityPeriod**. When the system time is later than or equal to (the time when the domain account password is last changed on the device + the value of **passwordValidityPeriod** – the value of **passwordExpirationNotification**), a message is displayed, indicating that the password is about to expire.|
