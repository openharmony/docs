# 启动远程PageAbility（仅对系统应用开放）


启动远程PageAbility同样通过featureAbility中的startAbility接口实现。


除引入'\@ohos.ability.featureAbility'外，还需引入'\@ohos.distributedHardware.deviceManager'，通过DeviceManager（该组件在OpenHarmony上提供账号无关的分布式设备的认证组网能力）的getTrustedDeviceListSync接口（获取信任设备列表）获取远端的deviceId，写入want中，用于启动远程PageAbility。


由于当前DeviceManager的getTrustedDeviceListSync接口仅对系统应用开放，故现阶段非系统应用无法获取其他设备信息，无远程启动设备选择入口，远程启动Ability开发。


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
| requestPermissionsFromUser(permissions:&nbsp;Array&lt;string&gt;,&nbsp;<br>requestCode:&nbsp;number,&nbsp;resultCallback:&nbsp;AsyncCallback&lt;<br>PermissionRequestResult&gt;):&nbsp;void | 以callback形式从系统请求某些权限，详见对应[接口文档](../reference/apis/js-apis-Context.md#contextrequestpermissionsfromuser7-1)。 |


如下示例代码展示了向用户申请数据同步权限的方法：

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


在获取数据同步权限后，需要获取可信设备列表，进行设备选择。


  如下示例展示了通过getTrustedDeviceListSync获取可信设备列表，选择设备的方法。

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
            console.info("MainAbility onButtonClick getRemoteDeviceId err: list is null");            
            return;          
        }          
        console.info("MainAbility onButtonClick getRemoteDeviceId success:" + list[0].deviceId);          
        return list[0].deviceId;      
    } else {          
        console.info("MainAbility onButtonClick getRemoteDeviceId err: dmClass is null");      
    }  
}
```


设备选择完成后，通过调用startAbility接口，显式启动远程PageAbility。


如下示例展示了通过startAbility显式启动远程PageAbility的方法。

```ts
import featureAbility from '@ohos.ability.featureAbility';
function onStartRemoteAbility() {  
    console.info('onStartRemoteAbility begin');  
    let params;  
    let wantValue = {      
        bundleName: 'ohos.samples.etsDemo',      
        abilityName: 'ohos.samples.etsDemo.RemoteAbility',      
        deviceId: getRemoteDeviceId(), // getRemoteDeviceId的定义在前面的示例代码中
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
