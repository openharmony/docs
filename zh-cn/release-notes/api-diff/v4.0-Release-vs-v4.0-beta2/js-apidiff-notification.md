| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：commonEventManager;<br>方法or属性：function createSubscriberSync(subscribeInfo: CommonEventSubscribeInfo): CommonEventSubscriber;|@ohos.commonEventManager.d.ts|
|新增|NA|类名：commonEventManager;<br>方法or属性：export type CommonEventData = _CommonEventData;|@ohos.commonEventManager.d.ts|
|新增|NA|类名：commonEventManager;<br>方法or属性：export type CommonEventSubscriber = _CommonEventSubscriber;|@ohos.commonEventManager.d.ts|
|新增|NA|类名：commonEventManager;<br>方法or属性：export type CommonEventSubscribeInfo = _CommonEventSubscribeInfo;|@ohos.commonEventManager.d.ts|
|新增|NA|类名：commonEventManager;<br>方法or属性：export type CommonEventPublishData = _CommonEventPublishData;|@ohos.commonEventManager.d.ts|
|新增|NA|类名：Support;<br>方法or属性：COMMON_EVENT_CONNECTIVITY_CHANGE = 'usual.event.CONNECTIVITY_CHANGE'|@ohos.commonEventManager.d.ts|
|新增|NA|类名：Support;<br>方法or属性：COMMON_EVENT_SPECIAL_CODE = 'common.event.SPECIAL_CODE'|@ohos.commonEventManager.d.ts|
|新增|NA|类名：Support;<br>方法or属性：COMMON_EVENT_AUDIO_QUALITY_CHANGE = 'usual.event.AUDIO_QUALITY_CHANGE'|@ohos.commonEventManager.d.ts|
|新增|NA|类名：notificationManager;<br>方法or属性：function requestEnableNotification(context: UIAbilityContext, callback: AsyncCallback\<void>): void;|@ohos.notificationManager.d.ts|
|新增|NA|类名：notificationManager;<br>方法or属性：function requestEnableNotification(context: UIAbilityContext): Promise\<void>;|@ohos.notificationManager.d.ts|
|新增|NA|类名：CommonEventSubscriber;<br>方法or属性：getCodeSync(): number;|commonEventSubscriber.d.ts|
|新增|NA|类名：CommonEventSubscriber;<br>方法or属性：setCodeSync(code: number): void;|commonEventSubscriber.d.ts|
|新增|NA|类名：CommonEventSubscriber;<br>方法or属性：getDataSync(): string;|commonEventSubscriber.d.ts|
|新增|NA|类名：CommonEventSubscriber;<br>方法or属性：setDataSync(data: string): void;|commonEventSubscriber.d.ts|
|新增|NA|类名：CommonEventSubscriber;<br>方法or属性：setCodeAndDataSync(code: number, data: string): void;|commonEventSubscriber.d.ts|
|新增|NA|类名：CommonEventSubscriber;<br>方法or属性：isOrderedCommonEventSync(): boolean;|commonEventSubscriber.d.ts|
|新增|NA|类名：CommonEventSubscriber;<br>方法or属性：isStickyCommonEventSync(): boolean;|commonEventSubscriber.d.ts|
|新增|NA|类名：CommonEventSubscriber;<br>方法or属性：abortCommonEventSync(): void;|commonEventSubscriber.d.ts|
|新增|NA|类名：CommonEventSubscriber;<br>方法or属性：clearAbortCommonEventSync(): void;|commonEventSubscriber.d.ts|
|新增|NA|类名：CommonEventSubscriber;<br>方法or属性：getAbortCommonEventSync(): boolean;|commonEventSubscriber.d.ts|
|新增|NA|类名：CommonEventSubscriber;<br>方法or属性：getSubscribeInfoSync(): CommonEventSubscribeInfo;|commonEventSubscriber.d.ts|
|新增|NA|类名：NotificationFlagStatus;<br>方法or属性：TYPE_NONE = 0|notificationFlags.d.ts|
|新增|NA|类名：NotificationFlagStatus;<br>方法or属性：TYPE_OPEN = 1|notificationFlags.d.ts|
|新增|NA|类名：NotificationFlagStatus;<br>方法or属性：TYPE_CLOSE = 2|notificationFlags.d.ts|
|新增|NA|类名：NotificationFlags;<br>方法or属性：readonly soundEnabled?: NotificationFlagStatus;|notificationFlags.d.ts|
|新增|NA|类名：NotificationFlags;<br>方法or属性：readonly vibrationEnabled?: NotificationFlagStatus;|notificationFlags.d.ts|
