# 为协同通知添加快捷回复

当用户通过`运动健康`连接至手机后，用户无需解锁手机，就可以在`wearable`上阅读通知并快捷回复。
  
## 接口说明

接口详情参见[API参考](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerpublish-1)。

**表1** 通知发布接口功能介绍

| **接口名**  | **描述** |
| -------- | -------- |
| publish(request: NotificationRequest): Promise\<void\>       | 发布通知。  |

## 开发步骤
 
1. 手机通过`运动健康`连接`wearable`。

2. 导入模块。

    ```typescript
    import { notificationManager, notificationSubscribe } from '@kit.NotificationKit';
    import { AbilityConstant, UIAbility, Want } from '@kit.AbilityKit';
    import { window } from '@kit.ArkUI';
    import { rpc } from '@kit.IPCKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { common } from '@kit.AbilityKit';

    const TAG: string = '[PublishOperation]';
    const DOMAIN_NUMBER: number = 0xFF00;
    ```

3. 应用与`wearable`建立连接。

    ```typescript
    function sendMsgCallback(data: rpc.MessageSequence) {
      // 获取wearable发送的序列化数据
      let inputKey: string = data.readString();
      let userInput: string = data.readString();
      // ...
    }

    export default class EntryAbility extends UIAbility {
      onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        hilog.info(0x0000, '01203', '%{public}s', 'Ability onCreate');
        hilog.info(0x0000, '01203', 'onCreate %{public}s', JSON.stringify(want));
        try {
          this.callee.on('com.ohos.notification_service.sendReply', sendMsgCallback)
        } catch (error) {
          hilog.error(DOMAIN_NUMBER, TAG, `Failed to register. Code is ${error.code}, message is ${error.message}`);
        }
        hilog.info(0x0000, '01203', 'register successfully');
      }
    }
    ```

4. 发布通知。该通知必须携带有`userInput`的`actionButtons`，且`notificationSlotType`必须为`SOCIAL_COMMUNICATION`。

    ```typescript
    let wantAgentObj:WantAgent; // 用于保存创建成功的wantAgent对象，后续使用其完成触发的动作。
    let wantAgentInfo:wantAgent.WantAgentInfo = {
      wants: [
        {
          deviceId: '',
          bundleName: 'com.samples.notification',
          abilityName: 'EntryAbility',
          action: '',
          entities: [],
          uri: '',
          parameters: {}
        }
      ],
      actionType: wantAgent.OperationType.START_ABILITY,
      requestCode: 0,
      wantAgentFlags:[wantAgent.WantAgentFlags.CONSTANT_FLAG]
    };
    // 创建WantAgent
    wantAgent.getWantAgent(wantAgentInfo, (err: BusinessError, data:WantAgent) => {
      if (err) {
         hilog.error(DOMAIN_NUMBER, TAG, `Failed to get want agent. Code is ${err.code}, message is ${err.message}`);
         return;
      }
      hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in getting want agent.');
      wantAgentObj = data;
      let notificationRequest: notificationManager.NotificationRequest = {
        id: 1,
        // notificationSlotType必须为SOCIAL_COMMUNICATION
        notificationSlotType: notificationManager.SlotType.SOCIAL_COMMUNICATION,
        content: {
          notificationContentType: notificationManager.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT,
          normal: {
            title: 'Test_Title',
            text: 'Test_Text',
            additionalText: 'Test_AdditionalText',
          },
          actionButtons: [
            {
              title: "button",
              // 该wantAgent的abilityName必须为步骤三的EntryAbility
              wantAgent: wantAgentObj,
              // 必须携带userInput
              userInput: {"inputKey": "value"},
            }],
        },
      }
      // 发布通知
      notificationManager.publish(notificationRequest, (err: BusinessError) => {
        if (err) {
          hilog.error(DOMAIN_NUMBER, TAG, `Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
          return;
        }
        hilog.info(DOMAIN_NUMBER, TAG, 'Succeeded in publishing notification.');
      });
    });
   ```

5. `wearable`上点击快捷回复，应用即可通过步骤3的`sendMsgCallback`收到快捷消息。

