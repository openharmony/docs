# 启动远程PageAbility（仅对系统应用开放）

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @lidongrui-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

<!--deprecated_code_no_check-->

启动远程PageAbility同样通过featureAbility中的startAbility接口实现。


除引入'\@ohos.ability.featureAbility'外，还需引入'\@ohos.distributedHardware.deviceManager'，通过DeviceManager（该组件提供帐号无关的分布式设备的认证组网能力）的[getTrustedDeviceListSync](../reference/apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync)接口（获取信任设备列表）获取远端的deviceId，写入want中，用于启动远程PageAbility。


由于当前DeviceManager的[getTrustedDeviceListSync](../reference/apis-distributedservice-kit/js-apis-device-manager-sys.md#gettrusteddevicelistsync)接口仅对系统应用开放，故现阶段非系统应用无法获取其他设备信息，无远程启动设备选择入口，远程启动Ability开发。


  **表1** featureAbility接口说明

| 接口名 | 接口描述 |
| -------- | -------- |
| startAbility(parameter:&nbsp;StartAbilityParameter) | 启动Ability。 |
| startAbilityForResult(parameter:&nbsp;StartAbilityParameter) | 启动Ability，并在该Ability被销毁时返回执行结果。 |


  **表2** deviceManager接口说明

| 接口名 | 接口描述 |
| -------- | -------- |
| getTrustedDeviceListSync():&nbsp;Array&lt;DeviceInfo&gt; | 同步获取所有可信设备列表。 |


在跨设备场景下，启动远程PageAbility首先需要向用户申请数据同步的权限，相关接口说明如下：


  **表3** AtManager接口说明

| 接口名 | 接口描述 |
| -------- | -------- |
| checkAccessToken(tokenID:&nbsp;number,&nbsp;permissionName:&nbsp;string)<br>:&nbsp;Promise&lt;GrantStatus&gt; | 校验应用是否授予权限。使用Promise异步回调。返回值GrantStatus。建议使用checkAccessToken代替verifyAccessToken（已废弃），verifyAccessToken从API&nbsp;version&nbsp;9开始不再维护。 |


  **表4** context接口说明

| 接口名 | 接口描述 |
| -------- | -------- |
| requestPermissionsFromUser(permissions:&nbsp;Array&lt;string&gt;,&nbsp;<br>requestCode:&nbsp;number,&nbsp;resultCallback:&nbsp;AsyncCallback&lt;<br>PermissionRequestResult&gt;):&nbsp;void | 以callback形式从系统请求某些权限，详见对应[接口文档](../reference/apis-ability-kit/js-apis-inner-app-context.md#contextrequestpermissionsfromuser7-1)。 |


如下示例代码展示了向用户申请数据同步权限的方法：

```ts
import abilityAccessCtrl from "@ohos.abilityAccessCtrl";
import featureAbility from '@ohos.ability.featureAbility';
import bundle from '@ohos.bundle.bundleManager';
import hilog from '@ohos.hilog';

const TAG: string = 'PagePageAbilitySecond'
const domain: number = 0xFF00;

@Entry
@Component
struct PagePageAbilitySecond {
  async requestPermission(): Promise<void> {
    hilog.info(domain, TAG, 'RequestPermission begin');
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
      hilog.info(domain, TAG, 'checkAccessToken result:' + JSON.stringify(result));
      if (result != abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED) {
        requestPermissions.push(array[i]);
      }
    }
    hilog.info(domain, TAG, 'requestPermissions:' + JSON.stringify(requestPermissions));
    if (requestPermissions.length == 0) {
      return;
    }
    let context = featureAbility.getContext();
    context.requestPermissionsFromUser(requestPermissions, 1, (error, data) => {
      hilog.info(domain, TAG, 'error:' + error.message + ',data:' + JSON.stringify(data));
      hilog.info(domain, TAG, 'data requestCode:' + data.requestCode);
      hilog.info(domain, TAG, 'data permissions:' + data.permissions);
      hilog.info(domain, TAG, 'data authResults:' + data.authResults);
    });
    hilog.info(domain, TAG, 'RequestPermission end');
  }

  build() {
    //...
  }
}

```


在获取数据同步权限后，需要获取可信设备列表，进行设备选择。


  如下示例展示了通过getAvailableDeviceListSync获取可信设备列表，选择设备的方法。

```ts
import deviceManager from '@ohos.distributedDeviceManager';
import promptAction from '@ohos.promptAction';
import hilog from '@ohos.hilog';

const TAG: string = 'PagePageAbilitySecond'
const domain: number = 0xFF00;

@Entry
@Component
struct PagePageAbilitySecond {
  @State deviceID: string = '';
  
  getRemoteDeviceId(): void {
    let dmClass: deviceManager.DeviceManager;
    dmClass = deviceManager.createDeviceManager('com.samples.famodelabilitydevelop');
    try {
      if (typeof dmClass === 'object' && dmClass !== null) {
        let list = dmClass.getAvailableDeviceListSync();
        if (typeof (list) == undefined || list.length == 0) {
          hilog.info(domain, TAG, 'EntryAbility onButtonClick getRemoteDeviceId err: list is null');
          return;
        }
        hilog.info(domain, TAG, `EntryAbility onButtonClick getRemoteDeviceId success[${list.length}]:` + JSON.stringify(list[0]));
        if (list[0].networkId != undefined) {
          this.deviceID = list[0].networkId;
        }
        promptAction.showToast({
          message: this.deviceID
        });
      } else {
        hilog.info(domain, TAG, 'EntryAbility onButtonClick getRemoteDeviceId err: dmClass is null');
      }
    } catch (error) {
      hilog.info(domain, TAG, `getRemoteDeviceId error, error=${error}, message=${error.message}`);
    }
  }

  build() {
    //...
  }
}
```


设备选择完成后，通过调用startAbility接口，显式启动远程PageAbility。


如下示例展示了通过startAbility显式启动远程PageAbility的方法。

```ts
import featureAbility from '@ohos.ability.featureAbility';
import Want from '@ohos.app.ability.Want';
import promptAction from '@ohos.promptAction';
import { BusinessError } from '@ohos.base';
import hilog from '@ohos.hilog';

const TAG: string = 'PagePageAbilitySecond'
const domain: number = 0xFF00;

@Entry
@Component
struct PagePageAbilitySecond {
  @State deviceID: string = '';
  
  onStartRemoteAbility(): void {
    hilog.info(domain, TAG, 'onStartRemoteAbility begin');
    let wantValue: Want = {
      bundleName: 'ohos.samples.distributedmusicplayer',
      abilityName: 'ohos.samples.distributedmusicplayer.MainAbility',
      deviceId: this.deviceID, // this.deviceID的获取方式在前面的示例代码中
    };
    hilog.info(domain, TAG, 'onStartRemoteAbility want=' + JSON.stringify(wantValue));
    featureAbility.startAbility({
      want: wantValue
    }).then((data) => {
      promptAction.showToast({
        message: 'start_remote_success_toast'
      });
      hilog.info(domain, TAG, 'onStartRemoteAbility finished, ' + JSON.stringify(data));
    }).catch((error: BusinessError) => {
      promptAction.showToast({
        message: JSON.stringify(error)
      });
      hilog.error(domain, TAG, 'onStartRemoteAbility failed: ' + JSON.stringify(error));
    });
    hilog.info(domain, TAG, 'onStartRemoteAbility end');
  }
  build() {
    //...
  }
}

```
