# 使用call事件拉起指定UIAbility到后台


许多应用希望借助卡片的能力，实现和应用在前台时相同的功能。例如音乐卡片，卡片上提供播放、暂停等按钮，点击不同按钮将触发音乐应用的不同功能，进而提高用户的体验。在卡片中使用[postCardAction](../reference/apis-arkui/js-apis-postCardAction.md#postcardaction)接口的call能力，能够将卡片提供方应用的指定的UIAbility拉到后台。同时，call能力提供了调用应用指定方法、传递数据的功能，使应用在后台运行时可以通过卡片上的按钮执行不同的功能。

> **说明：**
>
> 本文主要介绍动态卡片的事件开发。对于静态卡片，请参见[FormLink](../reference/apis-arkui/arkui-ts/ts-container-formlink.md)。

## 约束限制

提供方应用需要具备后台运行权限([ohos.permission.KEEP_BACKGROUND_RUNNING](../security/AccessToken/permissions-for-all.md#ohospermissionkeep_background_running))。

## 开发步骤

通常使用按钮控件来触发call事件，示例代码如下：


- 在卡片页面中布局两个按钮，点击其中一个按钮时调用postCardAction向指定UIAbility发送call事件，并在事件内定义需要调用的方法和传递的数据。需要注意的是，method参数为必选参数，且类型需要为string类型，用于触发UIAbility中对应的方法。
  
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
                  abilityName: 'WidgetEventCallEntryAbility', // 只能跳转到当前应用下的UIAbility，与module.json5中定义保持
                  params: {
                    formId: this.formId,
                    method: 'funA' // 在EntryAbility中调用的方法名
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
                  abilityName: 'WidgetEventCallEntryAbility', // 只能跳转到当前应用下的UIAbility，与module.json5中定义保持
                  params: {
                    formId: this.formId,
                    method: 'funB', // 在EntryAbility中调用的方法名
                    num: 1 // 需要传递的其他参数
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
  
- 在UIAbility中接收call事件并获取参数，根据传递的method不同，执行不同的方法。其余数据可以通过[readString](../reference/apis-ipc-kit/js-apis-rpc.md#readstring)方法获取。需要注意的是，UIAbility需要onCreate生命周期中监听所需的方法。
  
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
      // 如果UIAbility第一次启动，在收到call事件后会触发onCreate生命周期回调
      onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        try {
          // 监听call事件所需的方法
          this.callee.on('funA', (data: rpc.MessageSequence) => {
            // 获取call事件中传递的所有参数
            hilog.info(DOMAIN_NUMBER, TAG, `FunACall param:  ${JSON.stringify(data.readString())}`);
            promptAction.showToast({
              message: 'FunACall param:' + JSON.stringify(data.readString())
            });
            return new MyParcelable(CONST_NUMBER_1, 'aaa');
          });
          this.callee.on('funB', (data: rpc.MessageSequence) => {
            // 获取call事件中传递的所有参数
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
      
      // 进程退出时，解除监听
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
