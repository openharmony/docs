# @ohos.abilityToolAccessCtrl (工具访问控制)(系统接口)

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @gcw_3MIoLA9y-->
<!--Designer: @wkr321_ent-->
<!--Tester: @nacyli-->
<!--Adviser: @zengyawen-->

工具访问控制模块提供工具（CLI命令和API接口）的权限管理能力，包括权限查询、用户授权、远程授权等功能。权限查询用于检查工具的权限状态，用户授权用于根据用户决定授予工具权限，远程授权通过ticket机制实现跨设备权限管理。模块支持ticket验证机制和跨设备协同授权，能够提升权限管理安全性并简化授权流程。

当需要查询CLI命令或API接口的权限状态、进行工具权限授权、或管理远程设备的授权时，使用本模块接口。

**起始版本：** 26.0.0

> **说明：**
>
> 本模块接口为系统接口。

## 导入模块

```ts
import { abilityToolAccessCtrl } from '@kit.AbilityKit';
```

## abilityToolAccessCtrl.requestToolPermissions

requestToolPermissions(permissionQuery: PermissionQuery): Promise&lt;PermissionQueryResult&gt;

根据指定操作查询工具权限。检查入参[permissionQuery](#permissionquery)的[operationInfo](#operationinfo)属性中指定的CLI命令或API接口的权限状态，返回每个操作的权限状态、授权状态以及是否需要用户弹窗。当[permissionQuery.needTicket](#permissionquery)设置为true时，将生成用于远程授权的ticket。使用Promise异步回调。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.QUERY_TOOL_PERMISSIONS

**系统能力：** SystemCapability.Security.Asset

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| permissionQuery | [PermissionQuery](#permissionquery) | 是 | 权限查询信息，包含操作信息列表、是否需要生成ticket、远程设备信息等。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;[PermissionQueryResult](#permissionqueryresult)&gt; | Promise对象。返回权限查询结果，包含是否需要弹窗、权限状态信息和ticket信息。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[工具访问控制错误码](errorcode-abilityToolAccessCtrl-sys.md)。


| 错误码ID | 错误信息 |
| -------- | -------- |
| 201 | Permission denial. The interface caller does not have permission "ohos.permission.QUERY_TOOL_PERMISSIONS". |
| 202 | The caller is not a system application. |
| 401 | Parameter error. Possible causes: 1.Mandatory parameters are left unspecified; 2.Incorrect parameter types. |
| 24010000 | Invalid parameter. OperationType and operationInfo do not match, specified callerTokenId does not exist, ticketExpireTime exceeds 24h, etc. |
| 24010001 | Service is abnormal. Possible cause: IPC failed. |
| 24010002 | Common internal error. Possible cause: dependent service unavailable, resource access failed, etc. |
| 24010003 | The account is not logged in, network is unavailable, timeout, etc. |
| 24010006 | The requested operation is not allowed to be executed while the device is locked. |

**示例：**

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

根据用户授权结果授予工具权限。根据用户的授权决定，为工具（CLI命令或API接口）授予权限。授权成功后，生成可用于权限验证的ticket。使用Promise异步回调。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**需要权限：** ohos.permission.MANAGE_TOOL_RUNTIME_PERMISSIONS

**系统能力：** SystemCapability.Security.Asset

**参数：**

| 参数名 | 类型 | 必填 | 说明 |
| -------- | -------- | -------- | -------- |
| userAuthResult | Array&lt;[UserAuthResult](#userauthresult)&gt; | 是 | 用户授权结果列表，包含权限信息和权限查询信息。 |

**返回值：**

| 类型 | 说明 |
| -------- | -------- |
| Promise&lt;Array&lt;[TicketInfo](#ticketinfo)&gt;&gt; | Promise对象。返回授权成功后生成的ticket信息列表。 |

**错误码：**

以下错误码的详细介绍请参见[通用错误码](../errorcode-universal.md)和[工具访问控制错误码](errorcode-abilityToolAccessCtrl-sys.md)。

| 错误码ID | 错误信息 |
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


**示例：**

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

表示CLI（Command Line Interface，命令行界面）命令信息。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.Asset

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| cliCmdName | string | 否 | 否 | CLI命令名称，用于指定待查询或授权的CLI命令。需传入系统支持的CLI命令名称，如'ohos-displayManager'。 |
| subCliCmdName | string | 否 | 否 | CLI子命令名称，用于指定待查询或授权的CLI子命令。需传入指定CLI命令支持的子命令名称，如'set-brightness'。 |

## PermissionQuery

表示权限查询信息。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.Asset

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| operationInfo | Array&lt;[OperationInfo](#operationinfo)&gt; | 否 | 否 | 操作信息列表，指定待查询的CLI命令或API接口。 |
| needTicket | boolean | 否 | 是 | 是否需要生成ticket用于本地或远程授权。true表示需要生成ticket，false表示不需要。当设置为true时，仅在本次查询结果通过的情况下才会返回ticket信息。<br>默认值：false |
| ticketExpireTimeMs | number | 否 | 是 | ticket过期时间，单位为毫秒。取值范围：1~86400000（24小时），超过最大值将返回错误码24010000。需配合needTicket参数使用，仅当needTicket为true时本参数生效。默认值10000适用于常规授权场景，长时间远程授权场景可适当延长。<br>默认值：10000 |
| callerTokenId | number | 否 | 是 | 调用方进程的tokenId。当需要为其他进程查询或授权时，可指定目标进程的tokenId。<br>如果未传入该参数，默认获取调用方进程的tokenId。|
| domainId | string | 否 | 是 | 域标识。<br>如果未传入该参数，则默认获取调用方当前的域标识。|

## OperationInfo

表示操作信息。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.Asset

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| operationType | [OperationType](#operationtype) | 否 | 否 | 操作类型，表示操作是CLI命令还是API接口。 |
| info | [CliCmdInfo](#clicmdinfo) \| [Permissions](../../security/AccessToken/app-permissions.md) | 否 | 否 | 操作具体信息。当operationType为CLI时，info为CliCmdInfo；当operationType为API时，info为权限名称。如果operationType和info的类型不匹配，会导致参数错误。 |

## PermissionInfo

表示权限信息。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.Asset

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| permission | string | 否 | 否 | 权限名称，合法的权限名取值可在[应用权限列表](../../security/AccessToken/app-permissions.md)中查询。 |
| permissionStatus | [PermissionStatus](js-apis-abilityAccessCtrl.md#permissionstatus20) | 否 | 否 | 权限状态。 |
| authStatusInfo | [AuthStatusInfo](#authstatusinfo) | 否 | 是 | 授权状态信息。<br>该项作为出参；当PermissionInfo作为入参时，该项无需传入，如果传入会被忽略。默认值为undefined。|

## AuthStatusInfo

表示授权状态信息。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.Asset

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| authStatus | [AuthStatus](#authstatus) | 否 | 是 | 授权状态。作为入参时，该项无需传入，如果传入会被忽略；作为出参时，该项返回实际的授权状态，表示权限的授权结果。 |
| flag | number | 否 | 是 | 授权标志，用于标识权限授权的相关属性（如授权类型、授权持久性等）。<br>作为入参时，该项无需传入，如果传入会被忽略，默认值为0；作为出参时，该项返回实际的授权标志。|

## PermissionQueryResult

表示权限查询结果。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.Asset

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| needDialog | boolean | 否 | 否 | 是否需要弹窗。true表示需要弹窗请求用户授权，false表示不需要弹窗。 |
| permissionResults | Array&lt;[PermissionInfo](#permissioninfo)&gt; | 否 | 否 | 权限状态结果列表。 |
| ticket | [TicketInfo](#ticketinfo) | 否 | 是 | ticket信息。<br>当入参传入的[permissionQuery.needTicket](#permissionquery)为true，且本次查询结果通过时，返回ticket信息。 |

## TicketInfo

表示ticket信息。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.Asset

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| message | string | 否 | 否 | ticket消息，用于传递授权相关的授权信息、提示信息和状态描述。 |
| challenge | string | 否 | 否 | 挑战值，用于验证ticket的合法性。 |
| ticket | string | 否 | 否 | ticket字符串，用于权限验证。 |

## UserAuthResult

表示用户授权结果。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.Asset

| 名称 | 类型 | 只读 | 可选 | 说明 |
| -------- | -------- | -------- | -------- | -------- |
| permissionInfo | Array&lt;[PermissionInfo](#permissioninfo)&gt; | 否 | 否 | 权限信息列表，包含权限名称和授权状态。 |
| permissionQuery | [PermissionQuery](#permissionquery) | 否 | 否 | 对应的权限查询信息。 |

## AuthStatus

表示授权状态枚举。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.Asset

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| REQUIRE_AUTH | 0 | 需要授权。 |
| FORBIDDEN | 1 | 禁止授权。 |
| AUTHORIZED | 2 | 已授权。 |
| RESTRICTED | 3 | 受限制，权限受系统或策略限制。 |
| REMOTE_RESTRICTED | 4 | 远程受限制，远程设备的权限受限制。 |


## OperationType

表示操作类型枚举。

**起始版本：** 26.0.0

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Security.Asset

| 名称 | 值 | 说明 |
| -------- | -------- | -------- |
| CLI | 0x01 | CLI命令操作。 |
| API | 0x02 | API接口操作。 |
