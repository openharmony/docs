# API Switching Overview


Due to the differences in the thread model and process model, certain APIs can be used only in the FA model. They are marked with **FAModelOnly** in the SDK. When switching an application from the FA model to the stage model, replace the APIs marked with **FAModelOnly** in the application with the APIs supported in the stage model. This topic uses the switching of **startAbility()** as an example.

![api-switch-overview](figures/api-switch-overview.png)

 

- Sample code of **startAbility()** in the FA model:

  ```ts
  import featureAbility from '@ohos.ability.featureAbility';
  import { BusinessError } from '@ohos.base';
  
  try {
    Logger.info(TAG, 'Begin to start ability');
    let want: Want = {
      bundleName: 'com.samples.famodelabilitydevelop',
      moduleName: 'entry',
      abilityName: 'com.samples.famodelabilitydevelop.PageAbilitySingleton'
    };
    await featureAbility.startAbility({ want: want });
    Logger.info(TAG, `Start ability succeed`);
  }
  catch (error) {
    Logger.error(TAG, 'Start ability failed with ' + error);
  }
  ```

- Sample code of **startAbility()** in the stage model:

  ```ts
  import Want from '@ohos.app.ability.Want';

  // Context is a member of the ability object and is required for invoking inside a non-ability object.
  // Pass in the Context object.
  let wantInfo: Want = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility"
  };
  this.context.startAbility(wantInfo).then(() => {
    console.info('startAbility success.');
  }).catch((error: BusinessError) => {
    console.error('startAbility failed.');
  })
  ```
