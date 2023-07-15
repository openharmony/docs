# 设置原子化服务支持分享
## 原子化服务分享

1. UIAbility组件提供了[UIAbility.onShare()](../reference/apis/js-apis-app-ability-uiAbility.md#onshare)生命周期方法，应用可通过此方法设置要分享的数据。其中，ohos.extra.param.key.contentTitle表示分享框中对分享内容title的描述，ohos.extra.param.key.shareAbstract表示分享框中对携带内容的摘要描述，ohos.extra.param.key.shareUrl表示服务的在线地址。以上三项分享数据均是开发者填充，且为Object对象，对象的key分别为title，abstract，url。

   ```ts
   import AbilityConstant from '@ohos.app.ability.AbilityConstant';
   class MyUIAbility extends UIAbility {
       onShare(wantParams) {
           console.log('onShare');
           wantParams['ohos.extra.param.key.contentTitle'] = {title: "OA"};
           wantParams['ohos.extra.param.key.shareAbstract'] = {abstract: "communication for company employee"};
           wantParams['ohos.extra.param.key.shareUrl'] = {url: "oa.example.com"};
       }
   }
   ```

2. 系统弹框调用[abilityManager.acquireShareData()](../reference/apis/js-apis-app-ability-abilityManager.md#acquiresharedata)接口发起原子化服务共享，根据missionId找到对应的UIAbility，调用其OnShare生命周期，收到共享数据。

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
