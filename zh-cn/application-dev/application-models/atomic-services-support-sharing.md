# 设置原子化服务支持分享
原子化服务所提供的便捷服务，可以通过接入华为分享实现近距离快速分享，使便捷服务可以精准快速的推送至接收方，降低用户触达服务的成本，提升用户体检。

## 原子化服务分享
假设当前服务分享场景存在分享数据的目标应用和获取分享数据的应用。目标应用生命周期中增加`onShare()`方法，设置要分享的数据。启动目标应用，执行hdc shell aa dump -a 命令，查看设备中拉起的服务与进程，找到目标应用的missionId。启动当前应用，调用`abilityManager.acquireShareData()`方法，传入目标应用的missionId，得到目标应用的分享数据。
> **说明：**
当前获取数据的应用与分享数据的目标应用可以是同一个，missionId通过[missionManager.getMissionInfos()](../reference/apis/js-apis-app-ability-missionManager.md#getmissioninfos)方法来获取。

1. UIAbility组件提供了`UIAbility.onShare()`生命周期方法，应用可通过此方法设置要分享的数据。其中，ohos.extra.param.key.contentTitle表示分享框中对分享内容title的描述，ohos.extra.param.key.shareAbstract表示分享框中对携带内容的摘要描述，ohos.extra.param.key.shareUrl表示服务的在线地址。以上三项分享数据均是开发者填充，且为Object对象，对象的key分别为title，abstract，url。

   ```ts
   import AbilityConstant from '@ohos.app.ability.AbilityConstant';
   class MyUIAbility extends UIAbility {
       onShare(wantParams) {
           console.log('onShare');
           wantParams['ohos.extra.param.key.contentTitle'] = {title: "W3"};
           wantParams['ohos.extra.param.key.shareAbstract'] = {abstract: "communication for huawei employee"};
           wantParams['ohos.extra.param.key.shareUrl'] = {url: "w3.huawei.com"};
       }
   }
   ```

2. 使用`abilityManager.acquireShareData()`方法获取目标应用要分享的数据。其中，missionId是分享数据目标应用的missionId，启动应用后通过hdc shell aa dump -a 命令查看或者`missionManager.getMissionInfos()`方法获取，wantParam是目标应用`UIAbility.onShare()`生命周期方法回调的分享数据。

   ```ts
   import abilityManager from '@ohos.app.ability.abilityManager';
   try {
       abilityManager.acquireShareData(1, (err, wantParam) => {
           if (err) {
               console.error(`acquireShareData fail, err: ${JSON.stringify(err)}`);
           } else {
               console.log(`acquireShareData success, data: ${JSON.stringify(wantParam)}`);
           }
       });
   } catch (paramError) {
       console.error(`error.code: ${JSON.stringify(paramError.code)}, error.message: ${JSON.stringify(paramError.message)}`);
   }
   ```
