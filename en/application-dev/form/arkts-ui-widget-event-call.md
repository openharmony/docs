# Launching UIAbility to the Background (call Event)

<!--Kit: Form Kit-->
<!--Subsystem: Ability-->
<!--Owner: @Qian-Win-->
<!--Designer: @cx983299475-->
<!--Tester: @mahailong123456-->
<!--Adviser: @HelloShuo-->
<!-- md-trans-meta sourceCommit=f2cd623d606ddf44ee1a12cd7214615ae69df40f translatedAt=2026-08-03T02:24:29.316Z pushedAt=2026-08-03T06:39:46.393Z -->

Many apps want to leverage widget capabilities to achieve the same functionality as when the app is running in the foreground. For example, a music widget provides buttons such as play and pause. Tapping different buttons triggers different functions of the music app, thereby improving the user experience. Using the call capability of the [postCardAction](../reference/apis-arkui/js-apis-postCardAction.md#postcardaction-1) API in a widget, you can pull the UIAbility specified by the widget provider app to the background. In addition, the call capability allows you to invoke a specified method of the app and pass data, so that the app can execute different functions through the buttons on the widget while running in the background.

> **NOTE**
>
> This topic describes development for dynamic widgets. For static widgets, see [FormLink](../reference/apis-arkui/arkui-ts/ts-container-formlink.md).

## How to Develop

1. Create a dynamic widget.

    Create a dynamic widget named WidgetEventCall.

2. Implement page layout.

    **Button A** and **Button B** correspond to calling the `funA` and `funB` methods, respectively. `funA` carries the `formId` parameter, and `funB` carries the `formId` and `num` parameters. Pass parameters based on your actual needs during development. The `method` parameter in `postCardAction` is mandatory and identifies the method name to be called. It must be consistent with the method listened for by the UIAbility in step 3. Other parameters are optional.

    <!-- @[widget_event_call_card](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ApplicationModels/StageServiceWidgetCards/entry/src/main/ets/widgeteventcall/pages/WidgetEventCallCard.ets) -->

    ``` TypeScript
    //src/main/ets/widgeteventcall/pages/WidgetEventCallCard.ets
    let storageEventCall = new LocalStorage();
    
    @Entry(storageEventCall)
    @Component
    struct WidgetEventCallCard {
      @LocalStorageProp('formId') formId: string = '12400633174999288';
      // Replace $r('app.string.ButtonA_label') and $r('app.string.ButtonB_label') with the resource files you use.
      private funA: Resource = $r('app.string.ButtonA_label');
      private funB: Resource = $r('app.string.ButtonB_label');
    
      build() {
        RelativeContainer() {
          Button(this.funA)
            .id('funA__')
            .fontSize(14)
            .fontWeight(FontWeight.Bold)
            .alignRules({
              center: { anchor: '__container__', align: VerticalAlign.Center },
              middle: { anchor: '__container__', align: HorizontalAlign.Center }
            })
            .onClick(() => {
              postCardAction(this, {
                action: 'call',
                // Only the UIAbility of the current application is allowed. The ability name must be the same as that defined in module.json5.
                abilityName: 'WidgetEventCallEntryAbility',
                params: {
                  formId: this.formId,
                  // Name of the method to be called.
                  method: 'funA'
                }
              });
            })
    
          Button(this.funB)
            .id('funB__')
            .fontSize(14)
            .fontWeight(FontWeight.Bold)
            .margin({ top: 10 })
            .alignRules({
              top: { anchor: 'funA__', align: VerticalAlign.Bottom },
              middle: { anchor: '__container__', align: HorizontalAlign.Center }
            })
            .onClick(() => {
              postCardAction(this, {
                action: 'call',
                abilityName: 'WidgetEventCallEntryAbility',
                params: {
                  formId: this.formId,
                  // Name of the method to be called.
                  method: 'funB',
                  num: 1
                }
              });
            })
        }
        .height('100%')
        .width('100%')
      }
    }
    ```

3. Create a UIAbility.

    Listen for the call event in the UIAbility. Based on the method name in the `method` parameter, call the corresponding method and obtain parameters through [rpc.MessageSequence](../reference/apis-ipc-kit/js-apis-rpc.md#messagesequence9). The method listened for in the UIAbility must be consistent with the method called in step 2.

    <!-- @[widget_event_call_card_entry_ability](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ApplicationModels/StageServiceWidgetCards/entry/src/main/ets/widgeteventcallentryability/WidgetEventCallEntryAbility.ets) -->

    ``` TypeScript
    //src/main/ets/WidgetEventCallEntryAbility/WidgetEventCallEntryAbility.ets
    import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    
    const TAG: string = 'WidgetEventCallEntryAbility';
    const DOMAIN_NUMBER: number = 0xFF00;
    const CONST_NUMBER_1: number = 1;
    const CONST_NUMBER_2: number = 2;
    
    // Implementation of the IPC return type, which is used for data serialization and deserialization.
    class MyParcelable implements rpc.Parcelable {
      private num: number;
      private str: string;
    
      constructor(num: number, str: string) {
        this.num = num;
        this.str = str;
      }
    
      marshalling(messageSequence: rpc.MessageSequence): boolean {
        messageSequence.writeInt(this.num);
        messageSequence.writeString(this.str);
        return true;
      }
    
      unmarshalling(messageSequence: rpc.MessageSequence): boolean {
        this.num = messageSequence.readInt();
        this.str = messageSequence.readString();
        return true;
      }
    }
    
    export default class WidgetEventCallEntryAbility extends UIAbility {
      // If the UIAbility is started, the onCreate lifecycle callback is triggered after the call event is received.
      onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        try {
          // Listen for the method required by the call event and call the method.
          this.callee.on('funA', (data: rpc.MessageSequence) => {
            // Obtain all parameters passed in the call event.
            hilog.info(DOMAIN_NUMBER, TAG, `FunACall param:  ${JSON.stringify(data.readString())}`);
            return new MyParcelable(CONST_NUMBER_1, 'aaa');
          });
          this.callee.on('funB', (data: rpc.MessageSequence) => {
            // Obtain all parameters passed in the call event.
            hilog.info(DOMAIN_NUMBER, TAG, `FunBCall param:  ${JSON.stringify(data.readString())}`);
            return new MyParcelable(CONST_NUMBER_2, 'bbb');
          });
        } catch (err) {
          hilog.error(DOMAIN_NUMBER, TAG, `Failed to register callee on. Cause: ${JSON.stringify(err as BusinessError)}`);
        }
      }
    
      // Deregister the listener when the process exits.
      onDestroy(): void | Promise<void> {
        try {
          this.callee.off('funA');
          this.callee.off('funB');
        } catch (err) {
          hilog.error(DOMAIN_NUMBER, TAG, `Failed to register callee off. Cause: ${JSON.stringify(err as BusinessError)}`);
        }
      }
    }
    ```

4. Configure the background running permission.

    To receive the call event, the widget provider must add the background running permission ([ohos.permission.KEEP_BACKGROUND_RUNNING](../security/AccessToken/permissions-for-all.md#ohospermissionkeep_background_running)) to the **module.json5** file.

    <!-- @[module_json5_request_permissions](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ApplicationModels/StageServiceWidgetCards/entry/src/main/module.json5) -->

    ``` JSON5
    //src/main/module.json5
    "requestPermissions": [
      {
        "name": "ohos.permission.KEEP_BACKGROUND_RUNNING",
      },
    // ···
      // [EndExclude jscard_extension_ability]
    ]
    ```

5. Configure the UIAbility.

    Add the WidgetEventCallEntryAbility configuration information to the abilities array in the **module.json5** file.

    <!-- @[module_json5_abilities](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/ApplicationModels/StageServiceWidgetCards/entry/src/main/module.json5) -->

    ``` JSON5
    //src/main/module.json5
    "abilities": [
    // ···
      {
        "name": "WidgetEventCallEntryAbility",
        "srcEntry": "./ets/widgeteventcallentryability/WidgetEventCallEntryAbility.ets",
        "description": "$string:WidgetEventCallEntryAbility_desc",
        "icon": "$media:icon",
        "label": "$string:WidgetEventCallEntryAbility_label",
        "startWindowIcon": "$media:icon",
        "startWindowBackground": "$color:start_window_background"
      }
    ],
    ```