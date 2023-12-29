# API切换概述


FA模型和Stage模型由于线程模型和进程模型的差异，部分接口仅在FA模型下才能使用，针对这部分接口在SDK的接口中有FAModelOnly的标记，用于提醒开发者这部分接口仅能在FA模型下使用。因此在切换到Stage模型时，需要将应用中用到的FAModelOnly接口替换成Stage模型下对应的接口。下面是startAbility的接口切换示例，全量接口列表请查看后续章节：

![api-switch-overview](figures/api-switch-overview.png)

startAbility接口由FA模型切换到Stage模型的示例：

- FA模型示例

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

- Stage示例示例

  ```ts
  import Want from '@ohos.app.ability.Want';

  // context为Ability对象的成员，在非Ability对象内部调用需要
  // 将Context对象传递过去
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
