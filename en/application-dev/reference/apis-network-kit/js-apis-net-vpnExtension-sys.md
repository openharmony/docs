# @ohos.net.vpnExtension (Enhanced VPN Management) (System API)

This module implements virtual private network (VPN) management, such as starting and stopping a third-party VPN.

> **NOTE**
> The initial APIs of this module are supported since API version 11. Newly added APIs will be marked with a superscript to indicate their earliest API version.
> This topic describes only system APIs provided by the module. For details about its public APIs, see [@ohos.net.vpnExtension (VPN Extension)](js-apis-net-vpnExtension.md).

## Modules to Import

```js
import vpnExt from "@ohos.net.vpnExtension";
```


## vpnExt.setAlwaysOnVpnEnabled

setAlwaysOnVpnEnabled(enable: boolean, bundleName: string): Promise\<void>

Enables or disables the **always on** mode.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_VPN

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name    | Type   | Mandatory| Description                                                   |
| ---------- | ------- | ---- | ------------------------------------------------------- |
| enable     | boolean | Yes  | Whether to enable the **always on** mode.                                  |
| bundleName | string  | Yes  | Bundle name of the application (generally a third-party application).|

**Return value**

| Type          | Description                   |
| -------------- | ----------------------- |
| Promise\<void> | Promise that returns no value.|

**Error codes**

| ID| Error Message                                |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**Example**
Stage model:

```ts
import vpnExt from '@ohos.net.vpnExtension';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: "",
  bundleName: 'com.example.myvpndemo',
  abilityName: 'MyVpnExtAbility',
};

vpnExt.setAlwaysOnVpnEnabled(true, want.bundleName).then(() => {
  console.info('setAlwaysOnVpnEnabled success.');
}).catch((err : BusinessError) => {
  console.error('setAlwaysOnVpnEnabled fail, err-> ${JSON.stringify(err)}');
});
```

## vpnExt.isAlwaysOnVpnEnabled

isAlwaysOnVpnEnabled(bundleName: string): Promise\<boolean>

Obtains the status of the **always on** mode.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_VPN

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name    | Type  | Mandatory| Description                                                   |
| ---------- | ------ | ---- | ------------------------------------------------------- |
| bundleName | string | Yes  | Bundle name of the application (generally a third-party application).|

**Return value**

| Type             | Description                          |
| ----------------- | ------------------------------ |
| Promise\<boolean> | Promise used to return the result.|

**Error codes**

| ID| Error Message                                |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**Example**
Stage model:

```ts
import vpnExt from '@ohos.net.vpnExtension';
import Want from '@ohos.app.ability.Want';
import { BusinessError } from '@ohos.base';

let want: Want = {
  deviceId: "",
  bundleName: 'com.example.myvpndemo',
  abilityName: 'MyVpnExtAbility',
};

vpnExt.isAlwaysOnVpnEnabled(want.bundleName).then((data : boolean) => {
  console.info('isAlwaysOnVpnEnabled success.');
}).catch((err : BusinessError) => {
  console.error('setAlwaysOnVpnEnabled fail, err-> ${JSON.stringify(err)}');
});
```

## vpnExt.updateVpnAuthorizedState

updateVpnAuthorizedState(bundleName: string): boolean

Updates the VPN pop-up authorization status.

**System API**: This is a system API.

**Required permissions**: ohos.permission.MANAGE_VPN

**System capability**: SystemCapability.Communication.NetManager.Vpn

**Model restriction**: This API can be used only in the stage model.

**Parameters**

| Name    | Type  | Mandatory| Description                                            |
| ---------- | ------ | ---- | ------------------------------------------------ |
| bundleName | string | Yes  | Bundle name of the application (generally a third-party application).|

**Return value**

| Type   | Description                                       |
| ------- | ------------------------------------------- |
| boolean | Boolean value indicating whether the VPN pop-up authorization status is successfully updated.|

**Error codes**

| ID| Error Message                                |
| --------- | ---------------------------------------- |
| 201       | Permission denied.                       |
| 202       | Non-system applications use system APIs. |
| 401       | Parameter error.                         |

**Example**
Stage model:

```ts
import vpnExt from '@ohos.net.vpnExtension';
import Want from '@ohos.app.ability.Want';

let want: Want = {
  deviceId: "",
  bundleName: 'com.example.myvpndemo',
  abilityName: 'MyVpnExtAbility',
};

let result: boolean = vpnExt.updateVpnAuthorizedState(want.bundleName);
console.log("Result: "+ result);
```
