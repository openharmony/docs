# Setting Atomic Services to Support Sharing
By means of sharing, users can quickly access atomic services and use their features.

## How to Develop
In the sharing scenario, there are two parties involved: a target application that shares data and an application that obtains the shared data. The two can be physically the same. The target application uses the **onShare()** lifecycle callback to set the data to share. After the target application is started, you can run the **hdc shell aa dump -a** command to check the started services and processes and find its mission ID. After the current application is started, call the **abilityManager.acquireShareData()** API with the mission ID passed in to obtain the shared data.
> **NOTE**
>
> The mission ID of the target application can also be obtained by calling [missionManager.getMissionInfos()](../reference/apis/js-apis-app-ability-missionManager.md#getmissioninfos).

1. The target application calls **UIAbility.onShare()** provided by the UIAbility component to set the data to share. **ohos.extra.param.key.contentTitle** indicates the title of the content to share in the sharing box, **ohos.extra.param.key.shareAbstract** provides an abstract description of the content, and **ohos.extra.param.key.shareUrl** indicates the online address of the service. You need to set these three items as objects, with the key set to **title**, **abstract**, and **url**, respectively.

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

2. The current application calls **abilityManager.acquireShareData()** to obtain the data shared by the target application. **missionId** indicates the target application's mission ID, which can be obtained by running the **hdc shell aa dump -a** command or calling the **missionManager.getMissionInfos()** API after the target application is started. **wantParam** indicates the data shared by the target application through the **UIAbility.onShare()** lifecycle callback.

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
