# 使用call事件拉起指定UIAbility到后台


许多应用希望借助卡片的能力，实现和应用在前台时相同的功能。例如音乐卡片，卡片上提供播放、暂停等按钮，点击不同按钮将触发音乐应用的不同功能，进而提高用户的体验。在卡片中使用[postCardAction](../reference/apis-arkui/js-apis-postCardAction.md#postcardaction)接口的call能力，能够将卡片提供方应用的指定的UIAbility拉到后台。同时，call能力提供了调用应用指定方法、传递数据的功能，使应用在后台运行时可以通过卡片上的按钮执行不同的功能。

> **说明：**
>
> 本文主要介绍动态卡片的事件开发。对于静态卡片，请参见[FormLink](../reference/apis-arkui/arkui-ts/ts-container-formlink.md)。

## 示例代码开发步骤
- 1：创建动态卡片
  - 在工程的 entry 模块中，通过右键操作添加一个名为WidgetEventCallCard的ArkTs动态卡片，用于后续相关功能的承载与展示。
- 2：页面布局代码实现
  - 找到WidgetEventCallCard卡片页面对应代码文件(通常在src/main/ets相关目录下)，构建页面布局，确保页面呈现符合预期功能需求。
  - 示例代码在卡片页面中布局两个按钮，点击其中一个按钮时调用postCardAction向指定UIAbility发送call事件，并在事件内定义需要调用的方法和传递的数据。需要注意的是，method参数为必选参数，且类型需要为string类型，用于触发UIAbility中对应的方法。
    ```ts
    //src/main/ets/widgeteventcallcard/pages/WidgetEventCallCardCard.ets
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
- 3：创建指定的UIAbility。
  - 在UIAbility中接收call事件并获取参数，根据传递的method不同，执行不同的方法。其余数据可以通过[readString](../reference/apis-ipc-kit/js-apis-rpc.md#readstring)方法获取。需要注意的是，UIAbility需要onCreate生命周期中监听所需的方法。
  - 创建时可参照如下示例代码，确保其含有关键运行逻辑。
    ```ts
    //src/main/ets/widgeteventcallcard/WidgetEventCallEntryAbility/WidgetEventCallEntryAbility.ets
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
- 4：添加后台运行权限
  - call事件含有约束限制：提供方应用需要具备后台运行权限([ohos.permission.KEEP_BACKGROUND_RUNNING](../security/AccessToken/permissions-for-all.md#ohospermissionkeep_background_running))。
  - 在module.json5顶层对象module下添加如下配置
    ```ts
    //src/main/module.json5
    "requestPermissions"：[
       {
         "name": "ohos.permission.KEEP_BACKGROUND_RUNNING"
       }
     ]
    ```
- 5：配置指定的UIAbility
  - 在module.json5顶层对象module的abilities数组内添加WidgetEventCallEntryAbility对应的配置信息，示例代码如下：
    ```ts
    //src/main/module.json5
    {
      "name": 'WidgetEventCallEntryAbility',
      "srcEntry": './ets/widgeteventcallcard/WidgetEventCallEntryAbility/WidgetEventCallEntryAbility.ets',
      "description": '$string:WidgetEventCallCard_desc',
      "icon": "$media:app_icon",
      "label": "$string:WidgetEventCallCard_label",
      "startWindowIcon": "$media:app_icon",
      "startWindowBackground": "$color:start_window_background"
    }
    ```
- 6：资源配置调整
  - 根据实际业务需求，在资源配置中进行相应字段的添加、修改操作，同时按需处理图片相关配置，以保障整个功能在实际使用场景中的完整性与准确性。