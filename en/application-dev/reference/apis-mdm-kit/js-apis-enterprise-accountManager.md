# @ohos.enterprise.accountManager (Account Management)
<!--Kit: MDM Kit-->
<!--Subsystem: Customization-->
<!--Owner: @huanleima; @weizai16-->
<!--Designer: @hp_guo-->
<!--Tester: @lpw_work-->
<!--Adviser: @zhang_yixin13-->

This module provides device account management capabilities, including forbidding the creation of local accounts.

> **NOTE**
>
> The initial APIs of this module are supported since API version 12. Newly added APIs will be marked with a superscript to indicate their earliest API version.
>
> The APIs of this module can be used only in the stage model.
>
> The APIs of this module can be called only by a device administrator application that is enabled. For details, see [MDM Kit Development](../../mdm/mdm-kit-guide.md).

## Modules to Import

```ts
import { accountManager } from '@kit.MDMKit';
```

## accountManager.disallowOsAccountAddition

disallowOsAccountAddition(admin: Want, disallow: boolean, accountId?: number): void

Users are not allowed to add accounts. After the API is successfully called, the system forbids the specified user or all users from adding new accounts. This API is applicable to enterprise device management scenarios, such as preventing employees from creating local accounts and enhancing device security management.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Security-first](../../mdm/mdm-kit-multi-mdm.md#rule-1-security-first)

**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| disallow  | boolean                                                 | Yes  | Whether to forbid the creation of local accounts. The value **true** indicates yes, and the value **false** indicates no. |
| accountId | number                                                  | No  | User ID, which specifies a user. If this parameter is not specified, all users are not allowed to add accounts. If this parameter is specified, specified users are not allowed to add accounts. The value must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).|

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
import { accountManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace parameters with actual values.
  accountManager.disallowOsAccountAddition(wantTemp, true, 100);
  console.info('Succeeded in disallowing os account addition.');
} catch (err) {
  console.error(`Failed to disallow os account addition. Code: ${err.code}, message: ${err.message}`);
}
```

## accountManager.isOsAccountAdditionDisallowed

isOsAccountAdditionDisallowed(admin: Want | null, accountId?: number): boolean

Queries whether a user is not allowed to add an account. This API is applicable to enterprise audit and compliance check scenarios, helping administrators confirm the execution of account policies.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.


**Parameters**

| Name   | Type                                                   | Mandatory| Description                                                        |
| --------- | ------------------------------------------------------- | ---- | ------------------------------------------------------------ |
| admin     | [Want](../apis-ability-kit/js-apis-app-ability-want.md) \| null | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.<br>When multiple MDM applications exist on the device, passing a **Want** parameter queries the policies set by the corresponding enterprise device administrator application for versions earlier than API version 26.0.0. Since API version 26.0.0, passing null is additionally supported to query the policies that actually take effect.                         |
| accountId | number                                                  | No  | User ID, which specifies a user. If this parameter is not specified, the system queries whether all users are not allowed to add accounts. If this parameter is specified, the system queries whether specified users are not allowed to add accounts. The value must be greater than or equal to 0.<br>**accountId** can be obtained via APIs such as [getOsAccountLocalId](../apis-basic-services-kit/js-apis-osAccount.md#getosaccountlocalid9-1).|

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
import { accountManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

try {
  // Replace parameters with actual values.
  let isDisallowed: boolean = accountManager.isOsAccountAdditionDisallowed(wantTemp, 100);
  console.info(`Succeeded in querying the os account addition or not: ${isDisallowed}`);
} catch (err) {
  console.error(`Failed to query the os account addition or not. Code: ${err.code}, message: ${err.message}`);
}
```

## accountManager.addOsAccountAsync

addOsAccountAsync(admin: Want, name: string, type: osAccount.OsAccountType): Promise&lt;osAccount.OsAccountInfo&gt;

Adds an account in the background. This API uses a promise to return the result. This API is applicable to scenarios where enterprises need to create accounts in batches or remotely manage accounts. Accounts can be created without user interaction, improving management efficiency.

> **NOTE**
> 
> This API is time-consuming. Subsequent calls to other synchronous APIs in the application main thread must wait for the asynchronous return of this API.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Latest configuration precedence](../../mdm/mdm-kit-multi-mdm.md#rule-3-latest-configuration-precedence).

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| name   | string                                                       | Yes  | Account name, which is the name of the account to be added. An account with a duplicate name or an empty name cannot be created. An attempt to create a duplicate-name account will result in error code 9201003, and an attempt to create an account with an empty name will result in error code 401.|
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
import { accountManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError, osAccount } from '@kit.BasicServicesKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// Replace parameters with actual values.
accountManager.addOsAccountAsync(wantTemp, "TestAccountName", osAccount.OsAccountType.NORMAL).then((info) => {
  console.info(`Succeeded in creating os account: ${JSON.stringify(info)}`);
}).catch((err: BusinessError) => {
  console.error(`Failed to create os account. Code: ${err.code}, message: ${err.message}`);
});
```
## accountManager.setDomainAccountPolicy<sup>19+</sup>

setDomainAccountPolicy(admin: Want, domainAccountInfo: osAccount.DomainAccountInfo, policy: DomainAccountPolicy): void

Sets the domain account policy.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Conflict rule**: [Latest configuration precedence](../../mdm/mdm-kit-multi-mdm.md#rule-3-latest-configuration-precedence).

**Parameters**

<!--Table: 19%; 21%; 8%; 52%-->
| Name           | Type                                                        | Mandatory| Description                                                        |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin             | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| domainAccountInfo | [osAccount.DomainAccountInfo](../apis-basic-services-kit/js-apis-osAccount.md#domainaccountinfo8) | Yes  | Domain account information.<br>If the internal attribute of **domainAccountInfo** is empty, a global policy is set for all domain accounts.<br>If the internal attribute of **domainAccountInfo** is not empty, the policy is set for the specified domain account.<br>The priority of the specified domain account policy is higher than that of the global policy. If the specified domain account has a domain account policy, the global policy does not take effect for the domain account.<br>**Note:** To set a policy for a specified domain account, the **serverConfigId** parameter in **DomainAccountInfo** is mandatory.|
| policy            | [DomainAccountPolicy](#domainaccountpolicy19)                | Yes  | Domain account policy.<br>**Note:** After setting the domain account policy, you must change the domain account password on the device. Otherwise, the **passwordValidityPeriod** and **passwordExpirationNotification** configurations in **DomainAccountPolicy** do not take effect.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { accountManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError, osAccount } from '@kit.BasicServicesKit';

async function setDomainAccountPolicy() {
  let wantTemp: Want = {
    // Replace with actual values.
    bundleName: 'com.example.myapplication',
    abilityName: 'EnterpriseAdminAbility'
  };
  let policy: accountManager.DomainAccountPolicy = {
    // Replace with actual values.
    authenticationValidityPeriod: 300,
    passwordValidityPeriod: 420,
    passwordExpirationNotification: 60
  };
  // Set the global domain account policy.
  let accountInfo: osAccount.DomainAccountInfo = {
    domain: '',
    accountName: '',
    serverConfigId: ''
  };
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
    serverConfigId: ''
  };
  // Replace with actual values.
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

Obtains the domain account policy. This API is applicable to enterprise management scenarios, such as querying the current domain account policy configuration and auditing policy compliance.

**Required permissions**: ohos.permission.ENTERPRISE_SET_ACCOUNT_POLICY

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Device behavior differences**: This API can be properly called on PCs/2-in-1 devices. If it is called on other device types, error code 801 is returned.

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name           | Type                                                        | Mandatory| Description                                                        |
| ----------------- | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin             | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| domainAccountInfo | [osAccount.DomainAccountInfo](../apis-basic-services-kit/js-apis-osAccount.md#domainaccountinfo8) | Yes  | Domain account information.<br>If all the internal attributes of **domainAccountInfo** are empty, the global domain account policy is queried.<br>If the internal attribute of **domainAccountInfo** is not empty, the specified domain account policy is queried.<br>**Note:** To query a specified domain account policy, the **serverConfigId** parameter in **DomainAccountInfo** is mandatory.|

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
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { accountManager } from '@kit.MDMKit';
import { Want } from '@kit.AbilityKit';
import { BusinessError, osAccount } from '@kit.BasicServicesKit';

async function getDomainAccountPolicy() {
  let wantTemp: Want = {
    // Replace with actual values.
    bundleName: 'com.example.myapplication',
    abilityName: 'EnterpriseAdminAbility'
  };
  let domainAccountPolicy: accountManager.DomainAccountPolicy = {};
  // Query the global domain account policy.
  let accountInfo: osAccount.DomainAccountInfo = {
    domain: '',
    accountName: '',
    serverConfigId: ''
  };
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
    serverConfigId: ''
  };
  // Replace with actual values.
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

<!--Table: 28%; 10%; 8%; 8%; 46%-->
| Name                          | Type  | Read-Only| Optional| Description                                                        |
| ------------------------------ | ------ | ---- | ---- |------------------------------------------------------------ |
| authenticationValidityPeriod   | number | No  | Yes  |Validity period (in seconds) of the token for domain account authentication. This parameter is used to control that a user can access system resources without repeated authentication within the validity period of the token. The value range is [-1,2147483647]. The validity period starts from the time when the domain account is authenticated for the last time, for example, login or unlocking after the screen is locked.<br>The default value is **-1**, indicating that the token is permanently valid. The value **0** indicates that the token becomes invalid immediately. After the token expires or becomes invalid, the domain account and password must be authenticated when a user logs in to the system.|
| passwordValidityPeriod         | number | No  | Yes  |Validity period (in seconds) of the domain account password. It is used to require users to change their passwords periodically to enhance account security. The value range is [-1, 2147483647]. The validity period starts from the time of the last password change on the device side.<br>The default value is **-1**, indicating that the domain account password is permanently valid.|
| passwordExpirationNotification | number | No  | Yes  |Notification period before a domain account password expires, in seconds. The value range is [0, 2147483647].<br>The default value is **0**, indicating that the system does not display a message indicating that the domain account password has expired.<br>**Note:** **passwordExpirationNotification** must be used together with **passwordValidityPeriod**. When the system time is later than or equal to (the time when the domain account password is last changed on the device + the value of **passwordValidityPeriod** – the value of **passwordExpirationNotification**), a message is displayed, indicating that the password is about to expire.|

## accountManager.createNormalOsAccount

createNormalOsAccount(admin: Want, name: string): Promise&lt;osAccount.OsAccountInfo&gt;

Creates a normal system account. A maximum of two normal system accounts ([osAccount.OsAccountType](../apis-basic-services-kit/js-apis-osAccount.md#osaccounttype)) can be created.
> **NOTE**
> 
> The account creation process is time-consuming. Subsequent calls to other synchronous APIs in the application main thread must wait for the asynchronous return of this API.
> 
> Creating a system account has a significant impact on device performance. This API is supported only on phones and tablets with 12 GB or more of RAM.

**Since:** 26.0.0

**Required permissions:** ohos.permission.ENTERPRISE_MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| name   | string                                                       | Yes  | System account name. The system account name must be unique and cannot be empty. Otherwise, error code 9200012 is reported.|

**Return value**

| Type                                                        | Description                |
| ------------------------------------------------------------ | -------------------- |
| Promise&lt;[osAccount.OsAccountInfo](../apis-basic-services-kit/js-apis-osAccount.md#osaccountinfo)&gt; | Promise used to return the information about the created system account.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                                 |
| 9201003  | Failed to add an OS account.                                 |
| 9201040  | The number of accounts reaches the upper limit.                           |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 204      | Access denied due to user access control policy. Possible causes: 1. The operation is restricted by the OS-account constraint; 2. The required privilege for the operation has not been granted. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { accountManager } from '@kit.MDMKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { osAccount } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// Create a normal system account. The account name needs to be passed.
accountManager.createNormalOsAccount(wantTemp, "TestAccountName").then((accountInfo: osAccount.OsAccountInfo) => {
  console.info('Succeeded in creating normal os account, accountInfo: ' + JSON.stringify(accountInfo));
}).catch((err: BusinessError) => {
  console.error(`Failed to create normal os account: code is ${err.code}, message is ${err.message}`);
});
```

## accountManager.removeOsAccount

removeOsAccount(admin: Want, accountId: number): Promise&lt;void&gt;

Removes a system account. Currently, this API is supported only on phones and tablets. It can remove normal system accounts (of the normal type) created via [createNormalOsAccount](#accountmanagercreatenormalosaccount) and system accounts (of the admin, normal, and guest types) created via [addOsAccountAsync](#accountmanageraddosaccountasync). The default system account (ID: 100) cannot be removed.

**Since:** 26.0.0

**Required permissions:** ohos.permission.ENTERPRISE_MANAGE_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                      |
| accountId   | number                                                  | Yes  | ID of the system account to be removed. The default system account (ID: 100) cannot be removed. Otherwise, error code 9201041 is reported.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails., an error object is thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                                 |
| 9200016  | Service timeout.                                 |
| 9201041  | Restricted account.                           |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 204      | Access denied due to user access control policy. Possible causes: 1. The operation is restricted by the OS-account constraint; 2. The required privilege for the operation has not been granted. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { accountManager } from '@kit.MDMKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { osAccount } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// Create a normal system account.
accountManager.createNormalOsAccount(wantTemp, "TestAccountName").then((accountInfo: osAccount.OsAccountInfo) => {
  console.info('Succeeded in creating normal os account, accountInfo: ' + JSON.stringify(accountInfo));
  // Remove the created account based on the system account ID.
  let accountId: number = accountInfo.localId;
  return accountManager.removeOsAccount(wantTemp, accountId);
}).then(() => {
  console.info('Succeeded in removing os account');
}).catch((err: BusinessError) => {
  console.error(`Failed to create and remove normal os account: code is ${err.code}, message is ${err.message}`);
});
```

## accountManager.activateOsAccount

activateOsAccount(admin: Want, accountId: number): Promise&lt;void&gt;

Switches the system account. Currently, this API is supported only on phones and tablets, and can only switch between normal system accounts created via [createNormalOsAccount](#accountmanagercreatenormalosaccount) and the default system account (ID: 100).

**Since:** 26.0.0

**Required permissions:** ohos.permission.ENTERPRISE_INTERACT_ACROSS_LOCAL_ACCOUNTS

**System capability**: SystemCapability.Customization.EnterpriseDeviceManager

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name| Type                                                        | Mandatory| Description                                                        |
| ------ | ------------------------------------------------------------ | ---- | ------------------------------------------------------------ |
| admin  | [Want](../apis-ability-kit/js-apis-app-ability-want.md)      | Yes  | EnterpriseAdminExtensionAbility. **Want** must contain the ability name of the EnterpriseAdminExtensionAbility and the bundle name of the application.                                     |
| accountId   | number                                                  | Yes  | System account ID. If you switch to a system account that does not exist, error code 9200012 is reported. If you switch to a restricted system account, for example, a system account created via [addOsAccountAsync](#accountmanageraddosaccountasync), error code 9201041 is reported.|

**Return value**

| Type| Description|
| -------- | -------- |
| Promise&lt;void&gt; | Promise that returns no value. If the operation fails., an error object is thrown.|

**Error codes**

For details about the error codes, see [Enterprise Device Management Error Codes](errorcode-enterpriseDeviceManager.md) and [Universal Error Codes](../errorcode-universal.md).

| ID| Error Message                                                    |
| -------- | ------------------------------------------------------------ |
| 9200001  | The application is not an administrator application of the device. |
| 9200002  | The administrator application does not have permission to manage the device. |
| 9200012  | Parameter verification failed.                                 |
| 9200016  | Service timeout.                                 |
| 9201041  | Restricted account.                            |
| 9201046  | The number of signed-in accounts reaches the upper limit.                            |
| 201      | Permission verification failed. The application does not have the permission required to call the API. |
| 801      | Capability not supported. Failed to call the API due to limited device capabilities. |

**Example**

```ts
import { accountManager } from '@kit.MDMKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { osAccount } from '@kit.BasicServicesKit';
import { Want } from '@kit.AbilityKit';

let wantTemp: Want = {
  // Replace with actual values.
  bundleName: 'com.example.myapplication',
  abilityName: 'EnterpriseAdminAbility'
};

// Create a normal system account.
accountManager.createNormalOsAccount(wantTemp, "TestAccountName").then((accountInfo: osAccount.OsAccountInfo) => {
  console.info('Succeeded in creating normal os account, accountInfo: ' + JSON.stringify(accountInfo));
  // Switch the account based on the system account ID.
  let accountId: number = accountInfo.localId;
  return accountManager.activateOsAccount(wantTemp, accountId);
}).then(() => {
  console.info('Succeeded in activating os account');
}).catch((err: BusinessError) => {
  console.error(`Failed to create and activate normal os account: code is ${err.code}, message is ${err.message}`);
});
```
