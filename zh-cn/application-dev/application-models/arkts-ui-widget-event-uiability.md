# 通过router或call事件刷新卡片内容


在卡片页面中可以通过**postCardAction**接口触发router事件或者call事件拉起UIAbility，然后由UIAbility刷新卡片内容，下面是这种刷新方式的简单示例。

> **说明：**
>
> 本文主要介绍动态卡片的事件开发。对于静态卡片，请参见[FormLink](../reference/arkui-ts/ts-container-formlink.md)。

## 通过router事件刷新卡片内容

- 在卡片页面通过注册Button的onClick点击事件回调，并在回调中调用**postCardAction**接口触发router事件拉起UIAbility。
  
  ```ts
  let storageUpdtRouter = new LocalStorage();
  
  @Entry(storageUpdtRouter)
  @Component
  struct WidgetUpdtRouterCard {
    @LocalStorageProp('routerDetail') routerDetail: ResourceStr = $r('app.string.init');
  
    build() {
      Column() {
        Column() {
          Text(this.routerDetail)
            .fontColor('#FFFFFF')
            .opacity(0.9)
            .fontSize(14)
            .margin({ top: '8%', left: '10%', right: '10%' })
            .textOverflow({ overflow: TextOverflow.Ellipsis })
            .maxLines(2)
        }.width('100%').height('50%')
        .alignItems(HorizontalAlign.Start)
  
        Row() {
          Button() {
            Text($r('app.string.JumpLabel'))
              .fontColor('#45A6F4')
              .fontSize(12)
          }
          .width(120)
          .height(32)
          .margin({ top: '30%', bottom: '10%' })
          .backgroundColor('#FFFFFF')
          .borderRadius(16)
          .onClick(() => {
            postCardAction(this, {
              action: 'router',
              abilityName: 'WidgetEventRouterEntryAbility', // 只能跳转到当前应用下的UIAbility
              params: {
                routerDetail: 'RouterFromCard',
              }
            });
          })
        }.width('100%').height('40%')
        .justifyContent(FlexAlign.Center)
      }
      .width('100%')
      .height('100%')
      .alignItems(HorizontalAlign.Start)
      .backgroundImage($r('app.media.CardEvent'))
      .backgroundImageSize(ImageSize.Cover)
    }
  }
  ```
  
- 在UIAbility的onCreate()或者onNewWant()生命周期中可以通过入参want获取卡片的formID和传递过来的参数信息，然后调用[updateForm](../reference/apis/js-apis-app-form-formProvider.md#updateform)接口刷新卡片。
  
  ```ts
  import type AbilityConstant from '@ohos.app.ability.AbilityConstant';
  import type Base from '@ohos.base';
  import formBindingData from '@ohos.app.form.formBindingData';
  import formInfo from '@ohos.app.form.formInfo';
  import formProvider from '@ohos.app.form.formProvider';
  import hilog from '@ohos.hilog';
  import UIAbility from '@ohos.app.ability.UIAbility';
  import type Want from '@ohos.app.ability.Want';
  import type window from '@ohos.window';
  
  const TAG: string = 'WidgetEventRouterEntryAbility';
  const DOMAIN_NUMBER: number = 0xFF00;
  
  export default class WidgetEventRouterEntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      this.handleFormRouterEvent(want);
    }
  
    handleFormRouterEvent(want: Want): void {
      hilog.info(DOMAIN_NUMBER, TAG, 'handleFormRouterEvent, Want:', JSON.stringify(want));
      if (want.parameters && want.parameters[formInfo.FormParam.IDENTITY_KEY] !== undefined) {
        let curFormId = JSON.stringify(want.parameters[formInfo.FormParam.IDENTITY_KEY]);
        let message: string = JSON.stringify(want.parameters.routerDetail);
        hilog.info(DOMAIN_NUMBER, TAG, `UpdateForm formId: ${curFormId}, message: ${message}`);
        let formData: Record<string, string> = {
          routerDetail: message + 'UIAbility.', // 和卡片布局中对应
        };
        let formMsg = formBindingData.createFormBindingData(formData);
        formProvider.updateForm(want.parameters[formInfo.FormParam.IDENTITY_KEY] + '', formMsg).then((data) => {
          hilog.info(DOMAIN_NUMBER, TAG, 'updateForm success.', JSON.stringify(data));
        }).catch((error: Base.BusinessError) => {
          hilog.info(DOMAIN_NUMBER, TAG, 'updateForm failed.', JSON.stringify(error));
        });
      }
    }
  
    // 如果UIAbility已在后台运行，在收到Router事件后会触发onNewWant生命周期回调
    onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      hilog.info(DOMAIN_NUMBER, TAG, 'onNewWant Want:', JSON.stringify(want));
      if (want.parameters && want.parameters[formInfo.FormParam.IDENTITY_KEY] !== undefined) {
        let curFormId = JSON.stringify(want.parameters[formInfo.FormParam.IDENTITY_KEY]);
        let message: string = JSON.stringify(want.parameters.routerDetail);
        hilog.info(DOMAIN_NUMBER, TAG, `UpdateForm formId: ${curFormId}, message: ${message}`);
        let formData: Record<string, string> = {
          routerDetail: message + 'onNewWant UIAbility.', // 和卡片布局中对应
        };
        let formMsg = formBindingData.createFormBindingData(formData);
        formProvider.updateForm(want.parameters[formInfo.FormParam.IDENTITY_KEY] + '', formMsg).then((data) => {
          hilog.info(DOMAIN_NUMBER, TAG, 'updateForm success.', JSON.stringify(data));
        }).catch((error: Base.BusinessError) => {
          hilog.info(DOMAIN_NUMBER, TAG, 'updateForm failed.', JSON.stringify(error));
        });
      }
    }
  
    onWindowStageCreate(windowStage: window.WindowStage): void {
      // Main window is created, set main page for this ability
      hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'Ability onWindowStageCreate');
  
      windowStage.loadContent('pages/Index', (err, data) => {
        if (err.code) {
          hilog.error(DOMAIN_NUMBER, TAG, 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
          return;
        }
        hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
      });
    }
    ...
  }
  ```



## 通过call事件刷新卡片内容

- 在使用**postCardAction**接口的call事件时，需要在FormExtensionAbility中的onAddForm生命周期回调中更新formId。

  ```ts
  import formBindingData from '@ohos.app.form.formBindingData';
  import FormExtensionAbility from '@ohos.app.form.FormExtensionAbility';
  import formInfo from '@ohos.app.form.formInfo';
  import type Want from '@ohos.app.ability.Want';
  
  export default class WidgetCalleeFormAbility extends FormExtensionAbility {
    onAddForm(want: Want): formBindingData.FormBindingData {
      class DataObj1 {
        formId: string = '';
      }
  
      let dataObj1 = new DataObj1();
      if (want.parameters && want.parameters['ohos.extra.param.key.form_identity'] !== undefined) {
        let formId: string = want.parameters['ohos.extra.param.key.form_identity'].toString();
        dataObj1.formId = formId;
      }
      let obj1 = formBindingData.createFormBindingData(dataObj1);
      return obj1;
    }
    ...
  }
  ```

- 在卡片页面通过注册Button的onClick点击事件回调，并在回调中调用**postCardAction**接口触发call事件拉起UIAbility。
  
  ```ts
  let storageUpdtCall = new LocalStorage();
  
  @Entry(storageUpdtCall)
  @Component
  struct WidgetUpdateCallCard {
    @LocalStorageProp('formId') formId: string = '12400633174999288';
    @LocalStorageProp('calleeDetail') calleeDetail: ResourceStr = $r('app.string.init');
  
    build() {
      Column() {
        Column() {
            Text(this.calleeDetail)
            .fontColor('#FFFFFF')
            .opacity(0.9)
            .fontSize(14)
            .margin({ top: '8%', left: '10%' })
        }.width('100%').height('50%')
        .alignItems(HorizontalAlign.Start)
  
        Row() {
          Button() {
            Text($r('app.string.CalleeJumpLabel'))
              .fontColor('#45A6F4')
              .fontSize(12)
          }
          .width(120)
          .height(32)
          .margin({ top: '30%', bottom: '10%' })
          .backgroundColor('#FFFFFF')
          .borderRadius(16)
          .onClick(() => {
            postCardAction(this, {
              action: 'call',
              abilityName: 'WidgetCalleeEntryAbility', // 只能拉起当前应用下的UIAbility
              params: {
                method: 'funA',
                formId: this.formId,
                calleeDetail: 'CallFrom'
              }
            });
          })
        }.width('100%').height('40%')
        .justifyContent(FlexAlign.Center)
      }
      .width('100%')
      .height('100%')
      .alignItems(HorizontalAlign.Start)
      .backgroundImage($r('app.media.CardEvent'))
      .backgroundImageSize(ImageSize.Cover)
    }
  }
  ```
  
- 在UIAbility的onCreate生命周期中监听call事件所需的方法，然后在对应方法中调用[updateForm](../reference/apis/js-apis-app-form-formProvider.md#updateform)接口刷新卡片。
  
  ```ts
  import type AbilityConstant from '@ohos.app.ability.AbilityConstant';
  import formBindingData from '@ohos.app.form.formBindingData';
  import formProvider from '@ohos.app.form.formProvider';
  import hilog from '@ohos.hilog';
  import type rpc from '@ohos.rpc';
  import UIAbility from '@ohos.app.ability.UIAbility';
  import type Want from '@ohos.app.ability.Want';
  import type window from '@ohos.window';
  
  const TAG: string = 'WidgetCalleeEntryAbility';
  const DOMAIN_NUMBER: number = 0xFF00;
  const MSG_SEND_METHOD: string = 'funA';
  const CONST_NUMBER_1: number = 1;
  
  class MyParcelable implements rpc.Parcelable {
    num: number;
    str: string;
  
    constructor(num: number, str: string) {
      this.num = num;
      this.str = str;
    };
  
    marshalling(messageSequence: rpc.MessageSequence): boolean {
      messageSequence.writeInt(this.num);
      messageSequence.writeString(this.str);
      return true;
    };
  
    unmarshalling(messageSequence: rpc.MessageSequence): boolean {
      this.num = messageSequence.readInt();
      this.str = messageSequence.readString();
      return true;
    };
  }
  
  // 在收到call事件后会触发callee监听的方法
  let funACall = (data: rpc.MessageSequence): MyParcelable => {
    // 获取call事件中传递的所有参数
    let params: Record<string, string> = JSON.parse(data.readString());
    if (params.formId !== undefined) {
      let curFormId: string = params.formId;
      let message: string = params.calleeDetail;
      hilog.info(DOMAIN_NUMBER, TAG, `UpdateForm formId: ${curFormId}, message: ${message}`);
      let formData: Record<string, string> = {
        calleeDetail: message
      };
      let formMsg: formBindingData.FormBindingData = formBindingData.createFormBindingData(formData);
      formProvider.updateForm(curFormId, formMsg).then((data) => {
        hilog.info(DOMAIN_NUMBER, TAG, `updateForm success. ${JSON.stringify(data)}`);
      }).catch((error) => {
        hilog.error(DOMAIN_NUMBER, TAG, `updateForm failed: ${JSON.stringify(error)}`);
      });
    }
    return new MyParcelable(CONST_NUMBER_1, 'aaa');
  };
  
  export default class WidgetCalleeEntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      try {
        // 监听call事件所需的方法
        this.callee.on(MSG_SEND_METHOD, funACall);
      } catch (error) {
        hilog.error(DOMAIN_NUMBER, TAG, `${MSG_SEND_METHOD} register failed with error ${JSON.stringify(error)}`);
      };
    }
  
    onWindowStageCreate(windowStage: window.WindowStage): void {
      // Main window is created, set main page for this ability
      hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'Ability onWindowStageCreate');
  
      windowStage.loadContent('pages/Index', (err, data) => {
        if (err.code) {
          hilog.error(DOMAIN_NUMBER, TAG, 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
          return;
        }
        hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
      });
    }
  }
  ```