# 公共事件与通知开发常见问题

## emitter数据大小限制

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

emitter数据大小限制不超过10240。

## 如何实现点击Notification通知打开对应App 

适用于：OpenHarmony SDK 3.2.5.5版本，API9 Stage模型

通过配置Notification.publish发布通知接口的参数NotificationRequest中wantAgent属性实现

参考文档：[Notification](../reference/apis/js-apis-notification.md#notificationpublish)、[WantAgent](../reference/apis/js-apis-wantAgent.md)

示例：

```
import WantAgent from '@ohos.wantAgent';

async function publishNotification() {
  let wantAgentInfo = {
    wants: [
      {
        bundleName: "com.example.notification",
        abilityName: "MainAbility",
      }
    ],
    operationType: WantAgent.OperationType.START_ABILITIES,
    requestCode: 0,
  }
  const wantAgent = await WantAgent.getWantAgent(wantAgentInfo)
  let contentType = Notification.ContentType.NOTIFICATION_CONTENT_BASIC_TEXT;
  await Notification.publish({
    content: {
      contentType: contentType,
      normal: {
        title: "测试标题",
        text: "测试内容",
      }
    },
    id: 1,
    wantAgent: wantAgent
  })
  prompt.showToast({ message: "发送成功" })
}
```
<!--no_check-->