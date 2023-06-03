# 事件通知子系统ChangeLog

## cl.notification.1 API异常处理方式变更

事件通知部分接口使用业务逻辑返回值表示错误信息，不符合OpenHarmony接口错误码规范。

**变更影响**

基于此前版本开发的应用，需适配变更接口的错误信息返回方式，否则会影响原有业务逻辑。

**关键接口/组件变更**

为适配统一的API异常处理方式，对事件通知相关接口进行废弃（下表中 原接口 列内容），并新增对应接口（下表中 新接口 列内容）。新增接口支持统一的错误码异常处理规范，功能上与原接口保持一致。

| 原接口                  | 新接口                           |
| ----------------------- | -------------------------------- |
| @ohos.commonEvent.d.ts  | @ohos.commonEventManager.d.ts    |
| @ohos.notification.d.ts | @ohos.notificationManager.d.ts   |
| @ohos.notification.d.ts | @ohos.notificationSubscribe.d.ts |

**适配指导**

如上所述，仅将老接口平移到了新的namespace中，所以可以通过修改import来解决适配问题：

如原先接口使用了@ohos.commonEvent

```js
import commonEvent from '@ohos.commonEvent';
```

可以通过直接修改import，来切换到新的namespace上：

```js
import commonEvent from '@ohos.commonEventManager';
```

@ohos.notification拆分成了两个namespace，需要根据接口情况选择需要的新namespace进行适配。

此外还需要适配异常处理，具体参考新接口的接口文档。

## cl.notification.2 接口变更

对事件通知部分接口名进行了变更。

**关键的接口/组件变更**

| 模块名                    | 类名                | 方法/属性/枚举/常量                                          | 变更类型 |
| ------------------------- | ------------------- | ------------------------------------------------------------ | -------- |
| @ohos.notification        | notification        | **function** enableNotification(bundle: BundleOption, enable: boolean, callback: AsyncCallback<**void**>): **void**; | 废弃     |
| @ohos.notification        | notification        | **function** enableNotification(bundle: BundleOption, enable: boolean): Promise<**void**>; | 废弃     |
| @ohos.notificationManager | notificationManager | **function** setNotificationEnable(bundle: BundleOption, enable: boolean, callback: AsyncCallback<**void**>): **void**; | 新增     |
| @ohos.notificationManager | notificationManager | **function** setNotificationEnable(bundle: BundleOption, enable: boolean): Promise<**void**>; | 新增     |
| @ohos.notification        | notification        | **function** enableNotificationSlot(bundle: BundleOption, **type**: SlotType, enable: boolean, callback: AsyncCallback<**void**>): **void**; | 废弃     |
| @ohos.notification        | notification        | **function** enableNotificationSlot(bundle: BundleOption, **type**: SlotType, enable: boolean): Promise<**void**>; | 废弃     |
| @ohos.notificationManager | notificationManager | **function** setNotificationEnableSlot(bundle: BundleOption, **type**: SlotType, enable: boolean, callback: AsyncCallback<**void**>): **void**; | 新增     |
| @ohos.notificationManager | notificationManager | **function** setNotificationEnableSlot(bundle: BundleOption, **type**: SlotType, enable: boolean): Promise<**void**>; | 新增     |
| @ohos.notification        | notification        | **function** enableDistributed(enable: boolean, callback: AsyncCallback<**void**>): **void**; | 废弃     |
| @ohos.notification        | notification        | **function** enableDistributed(enable: boolean, callback: AsyncCallback<**void**>): **void**; | 废弃     |
| @ohos.notificationManager | notificationManager | **function** setDistributedEnable(enable: boolean, callback: AsyncCallback<**void**>): **void**; | 新增     |
| @ohos.notificationManager | notificationManager | **function** setDistributedEnable(enable: boolean): Promise<**void**>; | 新增     |
| @ohos.notification        | notification        | **function** enableDistributedByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback<**void**>): **void**; | 废弃     |
| @ohos.notification        | notification        | **function** enableDistributedByBundle(bundle: BundleOption, enable: boolean): Promise<**void**>; | 废弃     |
| @ohos.notificationManager | notificationManager | **function** setDistributedEnableByBundle(bundle: BundleOption, enable: boolean, callback: AsyncCallback<**void**>): **void**; | 新增     |
| @ohos.notificationManager | notificationManager | **function** setDistributedEnableByBundle(bundle: BundleOption, enable: boolean): Promise<**void**>; | 新增     |