# JS API Changes of the Common Event and Notification Subsystem

The table below lists the APIs changes of the common event and notification subsystem in OpenHarmony 3.2 Beta1 over OpenHarmony 3.1 Release.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| commonEventSubscriber | CommonEventSubscriber | finishCommonEvent(callback: AsyncCallback\<void>): void;<br>finishCommonEvent(): Promise\<void>; | Added|
| notificationSlot | NotificationSlot | readonly enabled?: boolean; | Added|
| ohos.commonEvent | Support | COMMON_EVENT_VOLUME_EJECT = "usual.event.data.VOLUME_EJECT" | Added|
| ohos.commonEvent | Support | COMMON_EVENT_VOLUME_BAD_REMOVAL = "usual.event.data.VOLUME_BAD_REMOVAL" | Added|
| ohos.commonEvent | Support | COMMON_EVENT_VOLUME_MOUNTED = "usual.event.data.VOLUME_MOUNTED" | Added|
| ohos.commonEvent | Support | COMMON_EVENT_VOLUME_UNMOUNTED = "usual.event.data.VOLUME_UNMOUNTED" | Added|
| ohos.commonEvent | Support | COMMON_EVENT_VOLUME_REMOVED = "usual.event.data.VOLUME_REMOVED" | Added|
| ohos.notification | notification | isNotificationSlotEnabled(bundle: BundleOption, type: SlotType, callback: AsyncCallback\<boolean>): void;<br>isNotificationSlotEnabled(bundle: BundleOption, type: SlotType): Promise\<boolean>; | Added|
| ohos.notification | notification | enableNotificationSlot(bundle: BundleOption, type: SlotType, enable: boolean, callback: AsyncCallback\<void>): void;<br>enableNotificationSlot(bundle: BundleOption, type: SlotType, enable: boolean): Promise\<void>; | Added|
| ohos.notification | notification | cancelAsBundle(id: number, representativeBundle: string, userId: number, callback: AsyncCallback\<void>): void;<br>cancelAsBundle(id: number, representativeBundle: string, userId: number): Promise\<void>; | Added|
| ohos.notification | notification | publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number, callback: AsyncCallback\<void>): void;<br>publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number): Promise\<void>; | Added|
