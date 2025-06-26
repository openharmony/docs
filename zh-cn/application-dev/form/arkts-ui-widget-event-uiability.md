# 通过router或call事件刷新卡片内容

使用router事件，点击卡片可拉起对应应用的UIAbility至前台，并刷新卡片。使用call事件，点击卡片可拉起对应应用的UIAbility至后台，并刷新卡片。在卡片页面中可以通过[postCardAction](../reference/apis-arkui/js-apis-postCardAction.md#postcardaction)接口触发router事件或者call事件拉起UIAbility，然后由UIAbility刷新卡片内容，下面是这种刷新方式的简单示例。

> **说明：**
>
> 本文主要介绍动态卡片的事件开发。对于静态卡片，请参见[FormLink](../reference/apis-arkui/arkui-ts/ts-container-formlink.md)。

## 通过router事件刷新卡片内容

- 在卡片页面代码文件中，通过注册Button的onClick点击事件回调并在回调中调用postCardAction接口，触发router事件拉起UIAbility至前台。
  
  ```ts
  let storageUpdateRouter = new LocalStorage();
  
  @Entry(storageUpdateRouter)
  @Component
  struct WidgetUpdateRouterCard {
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
  
- 在UIAbility的onCreate或者onNewWant生命周期中可以通过入参want获取卡片的formID和传递过来的参数信息，然后调用[updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform)接口刷新卡片。
  
  ```ts
  import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { formBindingData, formInfo, formProvider } from '@kit.FormKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';

  const TAG: string = 'WidgetEventRouterEntryAbility';
  const DOMAIN_NUMBER: number = 0xFF00;

  export default class WidgetEventRouterEntryAbility extends UIAbility {
    onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      this.handleFormRouterEvent(want, 'onCreate');
    }

    handleFormRouterEvent(want: Want, source: string): void {
      hilog.info(DOMAIN_NUMBER, TAG, `handleFormRouterEvent ${source}, Want: ${JSON.stringify(want)}`);
      if (want.parameters && want.parameters[formInfo.FormParam.IDENTITY_KEY] !== undefined) {
        let curFormId = want.parameters[formInfo.FormParam.IDENTITY_KEY].toString();
        // want.parameters.params 对应 postCardAction() 中 params 内容
        let message: string = (JSON.parse(want.parameters?.params as string))?.routerDetail;
        hilog.info(DOMAIN_NUMBER, TAG, `UpdateForm formId: ${curFormId}, message: ${message}`);
        let formData: Record<string, string> = {
          'routerDetail': message + ' ' + source + ' UIAbility', // 和卡片布局中对应
        };
        let formMsg = formBindingData.createFormBindingData(formData);
        formProvider.updateForm(curFormId, formMsg).then((data) => {
          hilog.info(DOMAIN_NUMBER, TAG, 'updateForm success.', JSON.stringify(data));
        }).catch((error: BusinessError) => {
          hilog.info(DOMAIN_NUMBER, TAG, 'updateForm failed.', JSON.stringify(error));
        });
      }
    }

    // 如果UIAbility已在后台运行，在收到Router事件后会触发onNewWant生命周期回调
    onNewWant(want: Want, launchParam: AbilityConstant.LaunchParam): void {
      hilog.info(DOMAIN_NUMBER, TAG, 'onNewWant Want:', JSON.stringify(want));
      this.handleFormRouterEvent(want, 'onNewWant');
    }

    onWindowStageCreate(windowStage: window.WindowStage): void {
      
      hilog.info(DOMAIN_NUMBER, TAG, '%{public}s', 'Ability onWindowStageCreate');

      windowStage.loadContent('pages/Index', (err, data) => {
        if (err.code) {
          hilog.error(DOMAIN_NUMBER, TAG, 'Failed to load the content. Cause: %{public}s', JSON.stringify(err) ?? '');
          return;
        }
        hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in loading the content. Data: %{public}s', JSON.stringify(data) ?? '');
      });
    }
    // ...
  }
  ```
## 通过call事件刷新卡片内容

- 在卡片页面代码文件中，通过注册Button的onClick点击事件回调并在回调中调用postCardAction接口，触发call事件拉起UIAbility至后台。
  
  ```ts
  let storageUpdateCall = new LocalStorage();
  
  @Entry(storageUpdateCall)
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
  
- 在UIAbility的onCreate生命周期中监听call事件所需的方法，然后在对应方法中调用[updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#formproviderupdateform)接口刷新卡片。
  
  ```ts
  import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
  import { window } from '@kit.ArkUI';
  import { BusinessError } from '@kit.BasicServicesKit';
  import { formBindingData, formProvider } from '@kit.FormKit';
  import { rpc } from '@kit.IPCKit';
  import { hilog } from '@kit.PerformanceAnalysisKit';
  
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
        'calleeDetail': message
      };
      let formMsg: formBindingData.FormBindingData = formBindingData.createFormBindingData(formData);
      formProvider.updateForm(curFormId, formMsg).then((data) => {
        hilog.info(DOMAIN_NUMBER, TAG, `updateForm success. ${JSON.stringify(data)}`);
      }).catch((error: BusinessError) => {
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
  }
  ```
  要拉起UIAbility至后台，需要在`module.json5`配置文件中，配置`ohos.permission.KEEP_BACKGROUND_RUNNING`权限。
  ```json
    "requestPermissions":[
        {
        "name": "ohos.permission.KEEP_BACKGROUND_RUNNING"
        }
      ]
  ```