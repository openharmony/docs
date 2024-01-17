# Starting a Remote PageAbility (for System Applications Only)


The **startAbility()** method in the **featureAbility** class is used to start a remote PageAbility.


In addition to **'\@ohos.ability.featureAbility'**, you must import **'\@ohos.distributedHardware.deviceManager'**, which provides account-independent distributed device networking capabilities. Then you can use **getTrustedDeviceListSync** of the **DeviceManager** module to obtain the remote device ID and pass the remote device ID in the **want** parameter for starting the remote PageAbility.


The **getTrustedDeviceListSync** method is available only for system applications. Therefore, non-system applications cannot obtain remote device information or start a remote ability.


**Table 1** featureAbility APIs

| API| Description|
| -------- | -------- |
| startAbility(parameter: StartAbilityParameter)| Starts an ability.|
| startAbilityForResult(parameter: StartAbilityParameter)| Starts an ability and returns the execution result when the ability is terminated.|


**Table 2** deviceManager APIs

| API| Description|
| -------- | -------- |
| getTrustedDeviceListSync(): Array&lt;DeviceInfo&gt; | Obtains all trusted devices synchronously.|


In the cross-device scenario, before starting a remote PageAbility, you must request the data synchronization permission. The related APIs are described in the table below.


**Table 3** AtManager APIs

| API| Description|
| -------- | -------- |
| checkAccessToken(tokenID: number, permissionName: string): Promise&lt;GrantStatus&gt; | Verifies whether a permission is granted to an application. This API uses a promise to return the result **GrantStatus**. You are advised to use **checkAccessToken** instead of **verifyAccessToken**, which is deprecated since API version 9.|


**Table 4** context APIs

| API| Description|
| -------- | -------- |
| requestPermissionsFromUser(permissions: Array&lt;string&gt;, requestCode: number, resultCallback: AsyncCallback&lt; PermissionRequestResult&gt;): void | Requests permissions from the system. This API uses an asynchronous callback to return the result. For details, see [API Reference](../reference/apis/js-apis-inner-app-context.md#contextrequestpermissionsfromuser7-1).|


The following sample code shows how to request the data synchronization permission from users:

```ts
import abilityAccessCtrl from "@ohos.abilityAccessCtrl";
import featureAbility from '@ohos.ability.featureAbility';
import bundle from '@ohos.bundle.bundleManager';
import Logger from '../../utils/Logger';

const TAG: string = 'PagePageAbilitySecond';

async requestPermission(): Promise<void> {
  Logger.info(TAG, 'RequestPermission begin');
  let array: Array<string> = ['ohos.permission.DISTRIBUTED_DATASYNC'];
  let bundleFlag = 0;
  let tokenID: number | undefined = undefined;
  let userID = 100;
  let appInfo = await bundle.getApplicationInfo('com.samples.famodelabilitydevelop', bundleFlag, userID);
  tokenID = appInfo.accessTokenId;
  let atManager = abilityAccessCtrl.createAtManager();
  let requestPermissions: Array<string> = [];
  for (let i = 0;i < array.length; i++) {
    let result = await atManager.verifyAccessToken(tokenID, array[i]);
    Logger.info(TAG, 'checkAccessToken result:' + JSON.stringify(result));
    if (result != abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED) {
      requestPermissions.push(array[i]);
    }
  }
  Logger.info(TAG, 'requestPermissions:' + JSON.stringify(requestPermissions));
  if (requestPermissions.length == 0) {
    return;
  }
  let context = featureAbility.getContext();
  context.requestPermissionsFromUser(requestPermissions, 1, (error, data) => {
    Logger.info(TAG, 'error:' + error.message + ',data:' + JSON.stringify(data));
    Logger.info(TAG, 'data requestCode:' + data.requestCode);
    Logger.info(TAG, 'data permissions:' + data.permissions);
    Logger.info(TAG, 'data authResults:' + data.authResults);
  });
  Logger.info(TAG, 'RequestPermission end');
}
```


After obtaining the data synchronization permission, obtain the trusted device list for device selection.


The following sample code shows how to use **getAvailableDeviceListSync()** to obtain the trusted device list.

```ts
import deviceManager from '@ohos.distributedDeviceManager';
import promptAction from '@ohos.promptAction';
import Logger from '../../utils/Logger';

const TAG: string = 'PagePageAbilitySecond';

getRemoteDeviceId(): void {
  let dmClass: deviceManager.DeviceManager;
  dmClass = deviceManager.createDeviceManager('com.samples.famodelabilitydevelop');
  try {
    if (typeof dmClass === 'object' && dmClass !== null) {
      let list = dmClass.getAvailableDeviceListSync();
      if (typeof (list) == undefined || list.length == 0) {
        Logger.info(TAG, 'EntryAbility onButtonClick getRemoteDeviceId err: list is null');
        return;
      }
      Logger.info(TAG, `EntryAbility onButtonClick getRemoteDeviceId success[${list.length}]:` + JSON.stringify(list[0]));
      if (list[0].networkId != undefined) {
        this.deviceID = list[0].networkId;
      }
      promptAction.showToast({
        message: this.deviceID
      });
    } else {
      Logger.info(TAG, 'EntryAbility onButtonClick getRemoteDeviceId err: dmClass is null');
    }
  } catch (error) {
    Logger.info(TAG, `getRemoteDeviceId error, error=${error}, message=${error.message}`);
  }
}
```


After a device is selected, call **startAbility()** to explicitly start the remote PageAbility.


The following sample code shows how to explicitly start a remote PageAbility through **startAbility()**.

```ts
import featureAbility from '@ohos.ability.featureAbility';
import Want from '@ohos.app.ability.Want';
import promptAction from '@ohos.promptAction';
import { BusinessError } from '@ohos.base';
import Logger from '../../utils/Logger';

const TAG: string = 'PagePageAbilitySecond';;

onStartRemoteAbility(): void {
  Logger.info(TAG, 'onStartRemoteAbility begin');
  let wantValue: Want = {
    bundleName: 'ohos.samples.distributedmusicplayer',
    abilityName: 'ohos.samples.distributedmusicplayer.MainAbility',
    deviceId: this.deviceID, // The method of obtaining this.deviceID is described in the preceding sample code.
  };
  Logger.info(TAG, 'onStartRemoteAbility want=' + JSON.stringify(wantValue));
  featureAbility.startAbility({
    want: wantValue
  }).then((data) => {
    promptAction.showToast({
      message: $r('app.string.start_remote_success_toast')
    });
    Logger.info(TAG, 'onStartRemoteAbility finished, ' + JSON.stringify(data));
  }).catch((error: BusinessError) => {
    promptAction.showToast({
      message: JSON.stringify(error)
    });
    Logger.error(TAG, 'onStartRemoteAbility failed: ' + JSON.stringify(error));
  });
  Logger.info(TAG, 'onStartRemoteAbility end');
}
```
