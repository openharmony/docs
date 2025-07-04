# 为跨设备协同通知添加快捷回复

从API version 18开始，支持为跨设备协同通知添加快捷回复。

当手机应用通过指定事件ID订阅通知回复事件、并发布支持快捷回复的通知到手表时，用户无需解锁手机，即可在手表上查看通知消息并快捷回复。

## 前提条件

 - 用户已通过手机中运动健康App连接手表。
 - 用户已在手机的“运动健康App > 设备 > 消息通知”中，开启通知总开关与当前应用的通知开关。

## 实现原理

快捷回复的实现原理如下。其中，开发者仅需要实现步骤1和步骤2，步骤6为用户操作，其他均由系统实现。

![notification_introduction](figures/notification_quickreply.png)

## 接口说明

| **接口名**  | **描述** |
| -------- | -------- |
| [publish](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerpublish-1)(request: NotificationRequest): Promise\<void\>       | 发布通知。  |
| [on](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md#on)(method: string, callback: CalleeCallback): void       | 通用组件服务端注册消息通知callback。  |

## 开发步骤

1. 导入模块。

    ```typescript
    import { notificationManager } from '@kit.NotificationKit';
    import { AbilityConstant, UIAbility, Want, wantAgent, WantAgent } from '@kit.AbilityKit';
    import { window } from '@kit.ArkUI';
    import { rpc } from '@kit.IPCKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    ```

2. 手机中应用订阅通知回复事件。

    ```typescript
    class MySequenceable implements rpc.Parcelable {
      inputKey: string = ''
      userInput: string = ''

      constructor(inputKey: string, userInput: string) {
        this.inputKey = inputKey
        this.userInput = userInput
      }

      marshalling(messageParcel: rpc.MessageSequence) {
        messageParcel.writeString(this.inputKey)
        messageParcel.writeString(this.userInput)
        return true
      }

      unmarshalling(messageParcel: rpc.MessageSequence) {
        this.inputKey = messageParcel.readString()
        this.userInput = messageParcel.readString()
        return true
      }
    }

    function sendMsgCallback(data: rpc.MessageSequence) {
      // 获取客户端发送的序列化数据
      let receivedData = new MySequenceable('', '')
      // receivedData.inputKey为value1.
      receivedData.inputKey = data.readString();
      // receivedData.userInput为用户指定的快捷回复内容。
      receivedData.userInput = data.readString();
      console.info(`inputKey : ${JSON.stringify(receivedData.inputKey)}`);
      console.info(`userInput : ${JSON.stringify(receivedData.userInput)}`);

      return new MySequenceable('', '')
    }

    export default class EntryAbility extends UIAbility {
      onCreate(want: Want, launchParam: AbilityConstant.LaunchParam): void {
        console.info('Ability onCreate');
        console.info(`onCreate ${JSON.stringify(want)}`);
        try {
          // 服务端注册消息通知回调sendMsgCallback，且必须订阅com.ohos.notification_service.sendReply
          this.callee.on('com.ohos.notification_service.sendReply', sendMsgCallback)
        } catch (error) {
          console.error(`Failed to register. Code is ${error.code}, message is ${error.message}`);
        }
        console.info('register successfully');
      }
    }
    ```

3. 发布可快捷回复的通知消息。该通知必须携带有`userInput`的`actionButtons`，且`notificationSlotType`必须为`SOCIAL_COMMUNICATION`。

    ```typescript
    // 用于保存创建成功的wantAgent对象，后续使用其完成触发的动作。
    let wantAgentObj:WantAgent;
    // 该wantAgentInfo的abilityName必须为步骤二的EntryAbility。
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
         console.error(`Failed to get want agent. Code is ${err.code}, message is ${err.message}`);
         return;
      }
      console.info('Succeeded in getting want agent.');
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
        },
        actionButtons: [{
          title: 'button1',
          wantAgent: wantAgentObj,
          // 必须携带userInput
          userInput: {'inputKey': 'value1'},
        }],
      }
      // 发布通知
      notificationManager.publish(notificationRequest, (err: BusinessError) => {
        if (err) {
          console.error(`Failed to publish notification. Code is ${err.code}, message is ${err.message}`);
          return;
        }
        console.info('Succeeded in publishing notification.');
      });
    });
   ```

## 调试验证

1. 手表上进行快捷回复。

2. 在手机应用中查看是否可以收到快捷消息。如果可以，表明功能实现正常。
