# ANS通知子系统ChangeLog

## cl.notificationManager.1  接口名变更

基于此前接口名定义不够规范，与其他功能类型的接口命名不一致，对此接口名进行变更。

**变更影响**

底层仍支持原接口功能，不影响4.0.2.3版本调用该接口的应用。

**关键接口/组件变更**

| 包名            | 旧接口                                                       | 新接口                                                       |
| --------------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| ohos.notificationManager.d.ts | **function** supportDoNotDisturbMode(callback: AsyncCallback<boolean>): **void**; | **function** isSupportDoNotDisturbMode(callback: AsyncCallback<boolean>): **void**; |
| ohos.notificationManager.d.ts | **function** supportDoNotDisturbMode(): Promise<boolean>; | **function** isSupportDoNotDisturbMode(): Promise<boolean>; |

**适配指导**

按新的接口isSupportDoNotDisturbMode调用。

