# Setting Atomic Services to Support Sharing
## How to Develop

1. An application calls [UIAbility.onShare()](../reference/apis/js-apis-app-ability-uiAbility.md#onshare), a lifecycle callback provided by the UIAbility component, to set the data to share. In this lifecycle callback, **ohos.extra.param.key.contentTitle** indicates the title of the content to share in the sharing box, **ohos.extra.param.key.shareAbstract** provides an abstract description of the content, and **ohos.extra.param.key.shareUrl** indicates the online address of the service. You need to set these three items as objects, with the key set to **title**, **abstract**, and **url**, respectively.

   ```ts
   import AbilityConstant from '@ohos.app.ability.AbilityConstant';
   class MyUIAbility extends UIAbility {
       onShare(wantParams) {
           console.log('onShare');
           wantParams['ohos.extra.param.key.contentTitle'] = 'shareFeatureAbility';
           wantParams['ohos.extra.param.key.shareAbstract'] = 'huawei employee';
           wantParams['ohos.extra.param.key.shareUrl'] = 'w3.huawei.com';
       }
   }
   ```

2. A system dialog box calls [abilityManager.acquireShareData()](../reference/apis/js-apis-app-ability-abilityManager.md#acquiresharedata) to obtain data shared through atomic service sharing. Specifically, the system finds the UIAbility based on the mission ID and calls the **OnShare()** lifecycle of the UIAbility to obtain the shared data.

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
