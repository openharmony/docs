# 请求通知授权

应用需要获取用户授权才能发送通知。在通知发布前调用[requestEnableNotification()](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanagerrequestenablenotification10-1)接口，弹窗让用户选择是否允许发送通知。当用户拒绝授权后，将无法通过该接口再次拉起弹窗。如果应用需要向用户再次申请通知授权，则可以使用[openNotificationSettings](../reference/apis-notification-kit/js-apis-notificationManager.md#notificationmanageropennotificationsettings13)接口拉起通知管理半模态弹窗。

## 接口说明

接口详情参见[API参考](../reference/apis-notification-kit/js-apis-notificationManager.md)。

**表1** 通知授权接口功能介绍

| **接口名**  | **描述** |
| -------- | -------- |
| isNotificationEnabled():Promise\<boolean\>       | 查询通知是否授权。  |
| requestEnableNotification(context: UIAbilityContext): Promise\<void\> | 请求发送通知的许可，第一次调用会弹窗让用户选择。     |
| openNotificationSettings(context: UIAbilityContext): Promise\<void\>  | 拉起通知管理弹窗。|


## 开发步骤

1. 导入NotificationManager模块。

    ```ts
    import { notificationManager } from '@kit.NotificationKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    import { hilog } from '@kit.PerformanceAnalysisKit';
    import { common } from '@kit.AbilityKit';

    const TAG: string = '[PublishOperation]';
    const DOMAIN_NUMBER: number = 0xFF00;
    ```

2. 拉起通知弹窗，向用户请求通知授权。

    可通过requestEnableNotification的错误码判断用户是否授权。若返回的错误码为1600004，即为拒绝授权。

    ```ts
    let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
    notificationManager.isNotificationEnabled().then((data: boolean) => {
      hilog.info(DOMAIN_NUMBER, TAG, "isNotificationEnabled success, data: " + JSON.stringify(data));
      if(!data){
        notificationManager.requestEnableNotification(context).then(() => {
          hilog.info(DOMAIN_NUMBER, TAG, `[ANS] requestEnableNotification success`);
        }).catch((err : BusinessError) => {
          if(1600004 == err.code){
            hilog.error(DOMAIN_NUMBER, TAG, `[ANS] requestEnableNotification refused, code is ${err.code}, message is ${err.message}`);
          } else {
            hilog.error(DOMAIN_NUMBER, TAG, `[ANS] requestEnableNotification failed, code is ${err.code}, message is ${err.message}`);
          }
        });
      }
    }).catch((err : BusinessError) => {
        hilog.error(DOMAIN_NUMBER, TAG, `isNotificationEnabled fail, code is ${err.code}, message is ${err.message}`);
    });
    ```

3. （可选）拉起通知管理半模态弹窗，向用户再次申请通知授权。

    ```ts
    let context = this.getUIContext().getHostContext() as common.UIAbilityContext;
    notificationManager.isNotificationEnabled().then((data: boolean) => {
      hilog.info(DOMAIN_NUMBER, TAG, "isNotificationEnabled success, data: " + JSON.stringify(data));
      if(!data){
          notificationManager.openNotificationSettings(context).then(() => {
            hilog.info(0x0000, 'testTag', `[ANS] openNotificationSettings success`);
          }).catch((err: BusinessError) => {
            hilog.error(0x0000, 'testTag', `[ANS] openNotificationSettings failed, code is ${err.code}, message is ${err.message}`);
          });
      }
    })
    ```


