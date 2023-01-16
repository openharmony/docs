# API Switching Overview


Due to the differences in the thread model and process model, certain APIs (marked with **FAModelOnly** in the SDK) can be used only in the FA model. When switching an application from the FA model to the stage model, replace the APIs marked with **FAModelOnly** in the application with the APIs supported in the stage model. This topic uses the switching of **startAbility()** as an example.

![api-switch-overview](figures/api-switch-overview.png)

 

- Sample code of **startAbility()** in the FA model:

  ```ts
  import fa from '@ohos.ability.featureAbility';
  let parameter = {
    "want": {
      bundleName: "com.example.myapplication",
      abilityName: "com.example.myapplication.EntryAbility"
    }
  }
  fa.startAbility(parameter).then((data) => {
    console.info('startAbility success');
  }).catch((error) => {
    console.error('startAbility failed.');
  })
  ```

- Sample code of **startAbility()** in the stage model:

  ```ts
  // context is a member of the ability object and is required for invoking inside a non-ability object.
  // Pass in the Context object.
  let wantInfo = {
    bundleName: "com.example.myapplication",
    abilityName: "EntryAbility"
  };
  this.context.startAbility(wantInfo).then((data) => {
    console.info('startAbility success.');
  }).catch((error) => {
    console.error('startAbility failed.');
  })
  ```
