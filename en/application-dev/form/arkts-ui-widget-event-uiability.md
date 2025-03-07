# Updating Widget Content Through the router or call Event

With the router event, a touch on the widget can start the associated application's UIAbility in the foreground and trigger a widget update. With the call event, a touch on the widget can start the associated application's UIAbility in the background and trigger a widget update. On the widget page, the [postCardAction](../reference/apis-arkui/js-apis-postCardAction.md#postcardaction) API can be used to trigger a router or call event to start a UIAbility, which then updates the widget content. The following is an example of this widget update mode.

> **NOTE**
>
> This topic describes development for dynamic widgets. For static widgets, see [FormLink](../reference/apis-arkui/arkui-ts/ts-container-formlink.md).

## Updating Widget Content Through the router Event

- In the widget page code, register the **onClick** event callback of the button and call the **postCardAction** API in the callback to trigger the router event to start the UIAbility in the foreground.
  
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
              abilityName: 'WidgetEventRouterEntryAbility', // Only the UIAbility of the current application is allowed.
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
  
- In the **onCreate** or **onNewWant** lifecycle callback of the UIAbility, use the input parameter **want** to obtain the ID (**formID**) and other information of the widget, and then call the [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#updateform) API to update the widget.
  
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
        // want.parameters.params corresponds to params in postCardAction().
        let message: string = (JSON.parse(want.parameters?.params as string))?.routerDetail;
        hilog.info(DOMAIN_NUMBER, TAG, `UpdateForm formId: ${curFormId}, message: ${message}`);
        let formData: Record<string, string> = {
          'routerDetail': message + ' ' + source + ' UIAbility', // It matches the widget layout.
        };
        let formMsg = formBindingData.createFormBindingData(formData);
        formProvider.updateForm(curFormId, formMsg).then((data) => {
          hilog.info(DOMAIN_NUMBER, TAG, 'updateForm success.', JSON.stringify(data));
        }).catch((error: BusinessError) => {
          hilog.info(DOMAIN_NUMBER, TAG, 'updateForm failed.', JSON.stringify(error));
        });
      }
    }

    // If the UIAbility is running in the background, onNewWant is triggered after the router event is received.
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
## Updating Widget Content Through the call Event

- In the widget page code, register the **onClick** event callback of the button and call the **postCardAction** API in the callback to trigger the call event to start the UIAbility in the background.
  
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
              abilityName: 'WidgetCalleeEntryAbility', // Only the UIAbility of the current application is allowed.
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
  
- Listen for the method required by the call event in the **onCreate** callback of the UIAbility, and then call the [updateForm](../reference/apis-form-kit/js-apis-app-form-formProvider.md#updateform) API in the corresponding method to update the widget.
  
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
  
  // After the call event is received, the method listened for by the callee is triggered.
  let funACall = (data: rpc.MessageSequence): MyParcelable => {
    // Obtain all parameters transferred in the call event.
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
        // Listen for the method required by the call event.
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
  To start the UIAbility in the background, you must configure the ohos.permission.KEEP_BACKGROUND_RUNNING permission in the **module.json5** file.
  ```json
    "requestPermissions":[
        {
        "name": "ohos.permission.KEEP_BACKGROUND_RUNNING"
        }
      ]
  ```
