# @ohos.abilityToolAccessCtrl (Tool Access Control) (System API)

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @gcw_3MIoLA9y-->
<!--Designer: @wkr321_ent-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=9eedeabb897b5c930f430ede938f82d7fa7d96d8 translatedAt=2026-08-13T13:16:52.686Z pushedAt=2026-08-14T08:10:37.962Z -->

The Tool Access Control module provides permission management capabilities for tools (CLI commands and API interfaces), including permission query, user authorization, and remote authorization. Permission query is used to check the permission status of tools, user authorization is used to grant tool permissions based on user decisions, and remote authorization implements cross-device permission management through the ticket mechanism. The module supports the ticket verification mechanism and cross-device collaborative authorization, which can improve permission management security and simplify the authorization process.

Use the APIs of this module when you need to query the permission status of CLI commands or API interfaces, authorize tool permissions, or manage authorization of remote devices.

**Since**: 26.0.0

> **NOTE**
>
> The APIs of this module are system APIs.

## Modules to Import

```ts
import { abilityToolAccessCtrl } from '@kit.AbilityKit';
```

## abilityToolAccessCtrl.requestToolPermissions

requestToolPermissions(permissionQuery: PermissionQuery): Promise&lt;PermissionQueryResult&gt;

Queries tool permissions based on the specified operation. Checks the permission status of the CLI command or API specified in the [operationInfo](#operationinfo) property of the input parameter [permissionQuery](#permissionquery), and returns the permission status, authorization status, and whether a user dialog box is required for each operation. When [permissionQuery.needTicket](#permissionquery) is set to true, a ticket for remote authorization is generated. This API uses a promise to return the result.

**Since**: 26.0.0

**System API**: This is a system API.

**Required permissions:** ohos.permission.QUERY_TOOL_PERMISSIONS

**System capability:** SystemCapability.Security.Asset

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| permissionQuery | [PermissionQuery](#permissionquery) | Yes | Permission query information, including the operation information list, whether to generate a ticket, remote device information, and so on. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;[PermissionQueryResult](#permissionqueryresult)&gt; | Promise used to return the permission query result, including whether a dialog box is required, permission status information, and ticket information. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Tool Access Control Error Codes](errorcode-abilityToolAccessCtrl-sys.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denial. The interface caller does not have permission "ohos.permission.QUERY_TOOL_PERMISSIONS". |
| 202 | The caller is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 24010000 | Invalid parameter. OperationType and operationInfo do not match, specified callerTokenId does not exist, ticketExpireTime exceeds 24h, etc. |
| 24010001 | Service is abnormal. Possible cause: IPC failed. |
| 24010002 | Common internal error. Possible cause: dependent service unavailable, resource access failed, etc. |
| 24010003 | The account is not logged in, network is unavailable, timeout, etc. |
| 24010006 | The requested operation is not allowed to be executed while the device is locked. |

**Example**

```ts
import { abilityToolAccessCtrl } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let permissionQuery: abilityToolAccessCtrl.PermissionQuery = {
  operationInfo: [{
    operationType: abilityToolAccessCtrl.OperationType.CLI,
    info: {
      cliCmdName: 'ohos-displayManager',
      subCliCmdName: 'set-brightness'
    }
  }],
  needTicket: true,
  ticketExpireTimeMs: 10000,
};
abilityToolAccessCtrl.requestToolPermissions(permissionQuery).then((data: abilityToolAccessCtrl.PermissionQueryResult) => {
  console.info('requestToolPermissions success, data: ' + JSON.stringify(data));
}).catch((err: BusinessError): void => {
  console.error(`requestToolPermissions fail, code: ${err.code}, message: ${err.message}`);
});
```

## abilityToolAccessCtrl.grantToolPermissionsByUser

grantToolPermissionsByUser(userAuthResult: UserAuthResult[]): Promise&lt;TicketInfo[]&gt;

Grants tool permissions based on the user authorization result. Grants permissions to a tool (CLI command or API) based on the user's authorization decision. After the authorization succeeds, generates a ticket that can be used for permission verification. This API uses a promise to return the result.

**Since**: 26.0.0

**System API**: This is a system API.

**Required permissions:** ohos.permission.MANAGE_TOOL_RUNTIME_PERMISSIONS

**System capability:** SystemCapability.Security.Asset

**Parameters**

| Name | Type | Mandatory | Description |
| -------- | -------- | -------- | -------- |
| userAuthResult | Array&lt;[UserAuthResult](#userauthresult)&gt; | Yes | List of user authorization results, including permission information and permission query information. |

**Return value**

| Type | Description |
| -------- | -------- |
| Promise&lt;Array&lt;[TicketInfo](#ticketinfo)&gt;&gt; | Promise used to return the list of ticket information generated after successful authorization. |

**Error codes**

For details about the error codes, see [Universal Error Codes](../errorcode-universal.md) and [Tool Access Control Error Codes](errorcode-abilityToolAccessCtrl-sys.md).

| ID | Error Message |
| -------- | -------- |
| 201 | Permission denial. The interface caller does not have permission "ohos.permission.MANAGE_TOOL_RUNTIME_PERMISSIONS". |
| 202 | The caller is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 24010000 | Invalid parameter. OperationType and operationInfo do not match, specified callerTokenId does not exist, ticketExpireTime exceeds 24h, etc. |
| 24010001 | Service is abnormal. Possible cause: IPC failed. |
| 24010002 | Common internal error. Possible cause: dependent service unavailable, resource access failed, etc. |
| 24010003 | The account is not logged in, network is unavailable, timeout, etc. |
| 24010004 | Invalid permission. A permission in permissionInfo does not exist. |
| 24010005 | Grant permission failed. The application specified by the tokenID is not allowed to be granted with the specified permission, the specified permission cannot be granted by user, etc. |

**Example**

```ts
import { abilityToolAccessCtrl, abilityAccessCtrl, Permissions } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';

let userAuthResult: Array<abilityToolAccessCtrl.UserAuthResult> = [{
  permissionInfo: [{
    permission: 'ohos.permission.cli.BUNDLE_ACTIVE_INFO' as Permissions,
    permissionStatus: abilityAccessCtrl.PermissionStatus.GRANTED
  }],
  permissionQuery: {
    operationInfo: [{
      operationType: abilityToolAccessCtrl.OperationType.CLI,
      info: 'ohos.permission.cli.BUNDLE_ACTIVE_INFO'
    }],
    needTicket: true
  }
}];
abilityToolAccessCtrl.grantToolPermissionsByUser(userAuthResult).then((data: Array<abilityToolAccessCtrl.TicketInfo>) => {
  console.info('grantToolPermissionsByUser success, data: ' + JSON.stringify(data));
}).catch((err: BusinessError): void => {
  console.error(`grantToolPermissionsByUser fail, code: ${err.code}, message: ${err.message}`);
});
```

## CliCmdInfo

Represents the CLI (Command Line Interface) command information.

**Since**: 26.0.0

**System API**: This is a system API.

**System capability:** SystemCapability.Security.Asset

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| cliCmdName | string | No | No | Name of the CLI command, used to specify the CLI command to query or authorize. A CLI command name supported by the system must be passed in, for example, 'ohos-displayManager'. |
| subCliCmdName | string | No | No | Name of the CLI subcommand, used to specify the CLI subcommand to query or authorize. A subcommand name supported by the specified CLI command must be passed in, for example, 'set-brightness'. |

## PermissionQuery

Represents the permission query information.

**Since**: 26.0.0

**System API**: This is a system API.

**System capability:** SystemCapability.Security.Asset

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| operationInfo | Array&lt;[OperationInfo](#operationinfo)&gt; | No | No | List of operation information, which specifies the CLI commands or APIs to be queried. |
| needTicket | boolean | No | Yes | Whether to generate a ticket for local or remote authorization. The value **true** means to generate a ticket, and **false** means the opposite. When this parameter is set to **true**, the ticket information is returned only when the current query result passes.<br>Default value: **false** |
| ticketExpireTimeMs | number | No | Yes | Expiration time of the ticket, in milliseconds. The value ranges from 1 to 86400000 (24 hours). If the value exceeds the maximum, error code 24010000 is returned. This parameter must be used together with **needTicket**, and it takes effect only when **needTicket** is **true**. The default value **10000** applies to common authorization scenarios, and can be extended as appropriate for long-duration remote authorization scenarios.<br>Default value: **10000** |
| callerTokenId | number | No | Yes | Token ID of the caller process. When you need to query or authorize for another process, you can specify the token ID of the target process.<br>If this parameter is not passed, the token ID of the caller process is obtained by default. |
| domainId | string | No | Yes | Domain identifier.<br>If this parameter is not passed, the current domain identifier of the caller is obtained by default. |

## OperationInfo

Describes the operation information.

**Since**: 26.0.0

**System API**: This is a system API.

**System capability:** SystemCapability.Security.Asset

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| operationType | [OperationType](#operationtype) | No | No | Operation type, indicating whether the operation is a CLI command or an API. |
| info | [CliCmdInfo](#clicmdinfo) \| [Permissions](../../security/AccessToken/app-permissions.md) | No | No | Specific information about the operation. When **operationType** is **CLI**, **info** is **CliCmdInfo**; when **operationType** is **API**, **info** is the permission name. If the types of **operationType** and **info** do not match, a parameter error occurs. |

## PermissionInfo

Represents permission information.

**Since**: 26.0.0

**System API**: This is a system API.

**System capability:** SystemCapability.Security.Asset

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| permission | string | No | No | Permission name. For valid permission names, see [App Permission List](../../security/AccessToken/app-permissions.md). |
| permissionStatus | [PermissionStatus](js-apis-abilityAccessCtrl.md#permissionstatus20) | No | No | Permission status. |
| authStatusInfo | [AuthStatusInfo](#authstatusinfo) | No | Yes | Authorization status information.<br>This item is used as an output parameter. When PermissionInfo is used as an input parameter, this item does not need to be passed in, and it is ignored if passed in. The default value is undefined.|

## AuthStatusInfo

Represents the authorization status information.

**Since**: 26.0.0

**System API**: This is a system API.

**System capability:** SystemCapability.Security.Asset

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| authStatus | [AuthStatus](#authstatus) | No | Yes | Authorization status. When used as an input parameter, this field does not need to be passed in and will be ignored if passed in. When used as an output parameter, this field returns the actual authorization status, indicating the authorization result of the permission. |
| flag | number | No | Yes | Authorization flag, which identifies the attributes related to permission authorization (such as authorization type and authorization persistence).<br>When used as an input parameter, this field does not need to be passed in and will be ignored if passed in. The default value is 0. When used as an output parameter, this field returns the actual authorization flag.|

## PermissionQueryResult

Represents the permission query result.

**Since**: 26.0.0

**System API**: This is a system API.

**System capability:** SystemCapability.Security.Asset

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| needDialog | boolean | No | No | Whether a dialog box is required. The value **true** means that a dialog box is required to request user authorization, and **false** means the opposite. |
| permissionResults | Array&lt;[PermissionInfo](#permissioninfo)&gt; | No | No | List of permission status results. |
| ticket | [TicketInfo](#ticketinfo) | No | Yes | Ticket information.<br>When [permissionQuery.needTicket](#permissionquery) passed in is **true** and the query result is passed, the ticket information is returned. |

## TicketInfo

Represents ticket information.

**Since**: 26.0.0

**System API**: This is a system API.

**System capability:** SystemCapability.Security.Asset

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| message | string | No | No | Ticket message, used to convey authorization information, prompt information, and status description related to authorization. |
| challenge | string | No | No | Challenge value, used to verify the validity of the ticket. |
| ticket | string | No | No | Ticket string, used for permission verification. |

## UserAuthResult

Represents the user authorization result.

**Since**: 26.0.0

**System API**: This is a system API.

**System capability:** SystemCapability.Security.Asset

| Name | Type | Read-Only | Optional | Description |
| -------- | -------- | -------- | -------- | -------- |
| permissionInfo | Array&lt;[PermissionInfo](#permissioninfo)&gt; | No | No | List of permission information, including permission names and authorization statuses. |
| permissionQuery | [PermissionQuery](#permissionquery) | No | No | Corresponding permission query information. |

## AuthStatus

Enumerates the authorization statuses.

**Since**: 26.0.0

**System API**: This is a system API.

**System capability:** SystemCapability.Security.Asset

| Name | Value | Description |
| -------- | -------- | -------- |
| REQUIRE_AUTH | 0 | Authorization required. |
| FORBIDDEN | 1 | Authorization forbidden. |
| AUTHORIZED | 2 | Authorized. |
| RESTRICTED | 3 | Restricted. The permission is restricted by the system or policy. |
| REMOTE_RESTRICTED | 4 | Remotely restricted. The permission of the remote device is restricted. |

## OperationType

Enumerates the operation types.

**Since**: 26.0.0

**System API**: This is a system API.

**System capability:** SystemCapability.Security.Asset

| Name | Value | Description |
| -------- | -------- | -------- |
| CLI | 0x01 | CLI command operation. |
| API | 0x02 | API interface operation. |