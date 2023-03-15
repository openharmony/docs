| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.commonEventManager<br>类名: Support<br>方法 or 属性: COMMON_EVENT_USER_INFO_UPDATED = "usual.event.USER_INFO_UPDATED"|@ohos.commonEventManager.d.ts|
|删除|模块名: ohos.notification<br>类名: notification<br>方法 or 属性：function publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number, callback: AsyncCallback<void>): void;|NA|@ohos.notification.d.ts|
|删除|模块名: ohos.notification<br>类名: notification<br>方法 or 属性：function publishAsBundle(request: NotificationRequest, representativeBundle: string, userId: number): Promise<void>;|NA|@ohos.notification.d.ts|
|删除|模块名: ohos.notification<br>类名: notification<br>方法 or 属性：function cancelAsBundle(id: number, representativeBundle: string, userId: number, callback: AsyncCallback<void>): void;|NA|@ohos.notification.d.ts|
|删除|模块名: ohos.notification<br>类名: notification<br>方法 or 属性：function cancelAsBundle(id: number, representativeBundle: string, userId: number): Promise<void>;|NA|@ohos.notification.d.ts|
|删除|模块名: ohos.notification<br>类名: notification<br>方法 or 属性：function enableNotificationSlot(bundle: BundleOption, type: SlotType, enable: boolean, callback: AsyncCallback<void>): void;|NA|@ohos.notification.d.ts|
|删除|模块名: ohos.notification<br>类名: notification<br>方法 or 属性：function enableNotificationSlot(bundle: BundleOption, type: SlotType, enable: boolean): Promise<void>;|NA|@ohos.notification.d.ts|
|删除|模块名: ohos.notification<br>类名: notification<br>方法 or 属性：function isNotificationSlotEnabled(bundle: BundleOption, type: SlotType, callback: AsyncCallback<boolean>): void;|NA|@ohos.notification.d.ts|
|删除|模块名: ohos.notification<br>类名: notification<br>方法 or 属性：function isNotificationSlotEnabled(bundle: BundleOption, type: SlotType): Promise<boolean>;|NA|@ohos.notification.d.ts|
|删除|模块名: ohos.notification<br>类名: notification<br>方法 or 属性：function setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean, callback: AsyncCallback<void>): void;|NA|@ohos.notification.d.ts|
|删除|模块名: ohos.notification<br>类名: notification<br>方法 or 属性：function setSyncNotificationEnabledWithoutApp(userId: number, enable: boolean): Promise<void>;|NA|@ohos.notification.d.ts|
|删除|模块名: ohos.notification<br>类名: notification<br>方法 or 属性：function getSyncNotificationEnabledWithoutApp(userId: number, callback: AsyncCallback<boolean>): void;|NA|@ohos.notification.d.ts|
|删除|模块名: ohos.notification<br>类名: notification<br>方法 or 属性：function getSyncNotificationEnabledWithoutApp(userId: number): Promise<boolean>;|NA|@ohos.notification.d.ts|
|起始版本有变化|类名：RemoveReason<br>起始版本：9|类名：RemoveReason<br>起始版本：N/A|@ohos.notification.d.ts|
