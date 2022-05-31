# 事件通知子系统JS API变更

OpenHarmony 3.2 Beta1版本相较于OpenHarmony 3.1 Release版本，事件通知子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| commonEventSubscriber | CommonEventSubscriber | finishCommonEvent(callback: AsyncCallback<void>): void;<br>finishCommonEvent(): Promise<void>; | 新增 |
| notificationSlot | NotificationSlot | readonly enabled?: boolean; | 新增 |
| ohos.commonEvent | Support | COMMON_EVENT_VOLUME_EJECT = "usual.event.data.VOLUME_EJECT" | 新增 |
| ohos.commonEvent | Support | COMMON_EVENT_VOLUME_BAD_REMOVAL = "usual.event.data.VOLUME_BAD_REMOVAL" | 新增 |
| ohos.commonEvent | Support | COMMON_EVENT_VOLUME_MOUNTED = "usual.event.data.VOLUME_MOUNTED" | 新增 |
| ohos.commonEvent | Support | COMMON_EVENT_VOLUME_UNMOUNTED = "usual.event.data.VOLUME_UNMOUNTED" | 新增 |
| ohos.commonEvent | Support | COMMON_EVENT_VOLUME_REMOVED = "usual.event.data.VOLUME_REMOVED" | 新增 |
| ohos.notification | notification | function isNotificationSlotEnabled(bundle: BundleOption, type: SlotType, callback: AsyncCallback<boolean>): void;<br>function isNotificationSlotEnabled(bundle: BundleOption, type: SlotType): Promise<boolean>; | 新增 |
| ohos.notification | notification | function enableNotificationSlot(bundle: BundleOption, type: SlotType, enable: boolean, callback: AsyncCallback<void>): void;<br>function enableNotificationSlot(bundle: BundleOption, type: SlotType, enable: boolean): Promise<void>; | 新增 |
| ohos.notification | notification | function cancelAsBundle(id: number, representativeBundle: string, userId: number, callback: AsyncCallback<void>): void;<br>function cancelAsBundle(id: number, representativeBundle: string, userId: number): Promise<void>; | 新增 |
| ohos.notification | notification | function publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number, callback: AsyncCallback<void>): void;<br>function publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number): Promise<void>; | 新增 |
