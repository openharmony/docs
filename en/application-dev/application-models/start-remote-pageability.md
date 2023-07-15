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
async function RequestPermission() {
  console.info('RequestPermission begin');
  let array: Array<string> = ["ohos.permission.DISTRIBUTED_DATASYNC"];
  let bundleFlag = 0;
  let tokenID = undefined;
  let userID = 100;
  let appInfo = await bundle.getApplicationInfo('ohos.samples.etsDemo', bundleFlag, userID);
  tokenID = appInfo.accessTokenId;
  let atManager = abilityAccessCtrl.createAtManager();
  let requestPermissions: Array<string> = [];
  for (let i = 0;i < array.length; i++) {
    let result = await atManager.verifyAccessToken(tokenID, array[i]);
    console.info("checkAccessToken result:" + JSON.stringify(result));
    if (result != abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED) {
      requestPermissions.push(array[i]);
    }
  }
  console.info("requestPermissions:" + JSON.stringify(requestPermissions));
  if (requestPermissions.length == 0 || requestPermissions == []) {
    return;
  }
  let context = featureAbility.getContext();
  context.requestPermissionsFromUser(requestPermissions, 1, (error, data)=>{
    console.info("data:" + JSON.stringify(data));
    console.info("data requestCode:" + data.requestCode);
    console.info("data permissions:" + data.permissions);
    console.info("data authResults:" + data.authResults);
  });
  console.info('RequestPermission end');
}
```


After obtaining the data synchronization permission, obtain the trusted device list for device selection.


The following sample code shows how to use **getTrustedDeviceListSync()** to obtain the trusted device list.

```ts
import deviceManager from '@ohos.distributedHardware.deviceManager';

let dmClass;

function getDeviceManager() {
  deviceManager.createDeviceManager('ohos.example.distributedService', (error, dm) => {
    if (error) {
      console.info('create device manager failed with ' + error)
    }
    dmClass = dm;
  })
}

function getRemoteDeviceId() {
  if (typeof dmClass === 'object' && dmClass != null) {
    let list = dmClass.getTrustedDeviceListSync();
    if (typeof (list) == 'undefined' || typeof (list.length) == 'undefined') {
      console.info("EntryAbility onButtonClick getRemoteDeviceId err: list is null");
      return;
    }
    console.info("EntryAbility onButtonClick getRemoteDeviceId success:" + list[0].deviceId);
    return list[0].deviceId;
  } else {
    console.info("EntryAbility onButtonClick getRemoteDeviceId err: dmClass is null");
  }
}
```


After a device is selected, call **startAbility()** to explicitly start the remote PageAbility.


The following sample code shows how to explicitly start a remote PageAbility through **startAbility()**.

```ts
import featureAbility from '@ohos.ability.featureAbility';

function onStartRemoteAbility() {
  console.info('onStartRemoteAbility begin');
  let params;
  let wantValue = {
    bundleName: 'ohos.samples.etsDemo',
    abilityName: 'ohos.samples.etsDemo.RemoteAbility',
    deviceId: getRemoteDeviceId(), // getRemoteDeviceId is defined in the preceding sample code.
    parameters: params
  };
  console.info('onStartRemoteAbility want=' + JSON.stringify(wantValue));
  featureAbility.startAbility({
    want: wantValue
  }).then((data) => {
    console.info('onStartRemoteAbility finished, ' + JSON.stringify(data));
  });
  console.info('onStartRemoteAbility end');
}
```
