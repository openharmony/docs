# Launching a UIAbility in the Background Through the call Event


There may be cases you want to provide in a widget access to features available in your application running in the foreground, for example, the play, pause, and stop buttons in a music application widget. This is where the **call** capability of the [postCardAction](../reference/apis-arkui/js-apis-postCardAction.md#postcardaction) API comes in handy. This capability, when used in a widget, can start the specified UIAbility of the widget provider in the background. It also allows the widget to call the specified method of the application and transfer data so that the application, while in the background, can behave accordingly in response to touching of the buttons on the widget.

> **NOTE**
>
> This topic describes development for dynamic widgets. For static widgets, see [FormLink](../reference/apis-arkui/arkui-ts/ts-container-formlink.md).

## Constraints

This action type requires that the widget provider should have the [ohos.permission.KEEP_BACKGROUND_RUNNING](../security/AccessToken/permissions-for-all.md#ohospermissionkeep_background_running) permission.

## How to Develop

Typically, the call event is triggered for touching of buttons. Below is an example.


- In this example, two buttons are laid out on the widget page. When one button is clicked, the **postCardAction** API is called to send a call event to the target UIAbility. Note that the **method** parameter in the API indicates the method to call in the target UIAbility. It is mandatory and of the string type.
  
    ```ts
    @Entry
    @Component
    struct WidgetEventCallCard {
      @LocalStorageProp('formId') formId: string = '12400633174999288';
    
      build() {
        Column() {
          //...
          Row() {
            Column() {
              Button() {
              //...
              }
              //...
              .onClick(() => {
                postCardAction(this, {
                  action: 'call',
                  abilityName: 'WidgetEventCallEntryAbility', // Only the UIAbility of the current application is allowed. The ability name must be the same as that defined in module.json5.
                  params: {
                    formId: this.formId,
                    method: 'funA' // Set the name of the method to call in the EntryAbility.
                  }
                });
              })
    
              Button() {
              //...
              }
              //...
              .onClick(() => {
                postCardAction(this, {
                  action: 'call',
                  abilityName: 'WidgetEventCallEntryAbility', // Only the UIAbility of the current application is allowed. The ability name must be the same as that defined in module.json5.
                  params: {
                    formId: this.formId,
                    method: 'funB', // Set the name of the method to call in the EntryAbility.
                    num: 1 // Set other parameters to be passed in.
                  }
                });
              })
            }
          }.width('100%').height('80%')
          .justifyContent(FlexAlign.Center)
        }
        .width('100%')
        .height('100%')
        .alignItems(HorizontalAlign.Center)
      }
    }
    ```
  
- The UIAbility receives the call event and obtains the transferred parameters. It then executes the target method specified by the **method** parameter. Other data can be obtained through the [readString](../reference/apis-ipc-kit/js-apis-rpc.md#readstring) method. Listen for the method required by the call event in the **onCreate** callback of the UIAbility.
  
    ```ts
    import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
    import { promptAction } from '@kit.ArkUI';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { rpc } from '@kit.IPCKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
      
    const TAG: string = 'WidgetEventCallEntryAbility';
    const DOMAIN_NUMBER: number = 0xFF00;
    const CONST_NUMBER_1: number = 1;
    const CONST_NUMBER_2: number = 2;
      
    class MyParcelable implements rpc.Parcelable {
      num: number;
      str: string;
      
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
      // If the UIAbility is started for the first time, onCreate is triggered after the call event is received.
      onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        try {
          // Listen for the method required by the call event.
          this.callee.on('funA', (data: rpc.MessageSequence) => {
            // Obtain all parameters passed in the call event.
            hilog.info(DOMAIN_NUMBER, TAG, `FunACall param:  ${JSON.stringify(data.readString())}`);
            promptAction.showToast({
              message: 'FunACall param:' + JSON.stringify(data.readString())
            });
            return new MyParcelable(CONST_NUMBER_1, 'aaa');
          });
          this.callee.on('funB', (data: rpc.MessageSequence) => {
            // Obtain all parameters passed in the call event.
            hilog.info(DOMAIN_NUMBER, TAG, `FunBCall param:  ${JSON.stringify(data.readString())}`);
            promptAction.showToast({
              message: 'FunBCall param:' + JSON.stringify(data.readString())
            });
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
