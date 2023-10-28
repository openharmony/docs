| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|Added|NA|Class name: commonEventManager;<br>Method or attribute name: function createSubscriberSync(subscribeInfo: CommonEventSubscribeInfo): CommonEventSubscriber;|@ohos.commonEventManager.d.ts|
|Added|NA|Class name: commonEventManager;<br>Method or attribute name: export type CommonEventData = _CommonEventData;|@ohos.commonEventManager.d.ts|
|Added|NA|Class name: commonEventManager;<br>Method or attribute name: export type CommonEventSubscriber = _CommonEventSubscriber;|@ohos.commonEventManager.d.ts|
|Added|NA|Class name: commonEventManager;<br>Method or attribute name: export type CommonEventSubscribeInfo = _CommonEventSubscribeInfo;|@ohos.commonEventManager.d.ts|
|Added|NA|Class name: commonEventManager;<br>Method or attribute name: export type CommonEventPublishData = _CommonEventPublishData;|@ohos.commonEventManager.d.ts|
|Added|NA|Class name: Support;<br>Method or attribute name: COMMON_EVENT_CONNECTIVITY_CHANGE = 'usual.event.CONNECTIVITY_CHANGE'|@ohos.commonEventManager.d.ts|
|Added|NA|Class name: Support;<br>Method or attribute name: COMMON_EVENT_SPECIAL_CODE = 'common.event.SPECIAL_CODE'|@ohos.commonEventManager.d.ts|
|Added|NA|Class name: Support;<br>Method or attribute name: COMMON_EVENT_AUDIO_QUALITY_CHANGE = 'usual.event.AUDIO_QUALITY_CHANGE'|@ohos.commonEventManager.d.ts|
|Added|NA|Class name: notificationManager;<br>Method or attribute name: function requestEnableNotification(context: UIAbilityContext, callback: AsyncCallback\<void>): void;|@ohos.notificationManager.d.ts|
|Added|NA|Class name: notificationManager;<br>Method or attribute name: function requestEnableNotification(context: UIAbilityContext): Promise\<void>;|@ohos.notificationManager.d.ts|
|Added|NA|Class name: CommonEventSubscriber;<br>Method or attribute name: getCodeSync(): number;|commonEventSubscriber.d.ts|
|Added|NA|Class name: CommonEventSubscriber;<br>Method or attribute name: setCodeSync(code: number): void;|commonEventSubscriber.d.ts|
|Added|NA|Class name: CommonEventSubscriber;<br>Method or attribute name: getDataSync(): string;|commonEventSubscriber.d.ts|
|Added|NA|Class name: CommonEventSubscriber;<br>Method or attribute name: setDataSync(data: string): void;|commonEventSubscriber.d.ts|
|Added|NA|Class name: CommonEventSubscriber;<br>Method or attribute name: setCodeAndDataSync(code: number, data: string): void;|commonEventSubscriber.d.ts|
|Added|NA|Class name: CommonEventSubscriber;<br>Method or attribute name: isOrderedCommonEventSync(): boolean;|commonEventSubscriber.d.ts|
|Added|NA|Class name: CommonEventSubscriber;<br>Method or attribute name: isStickyCommonEventSync(): boolean;|commonEventSubscriber.d.ts|
|Added|NA|Class name: CommonEventSubscriber;<br>Method or attribute name: abortCommonEventSync(): void;|commonEventSubscriber.d.ts|
|Added|NA|Class name: CommonEventSubscriber;<br>Method or attribute name: clearAbortCommonEventSync(): void;|commonEventSubscriber.d.ts|
|Added|NA|Class name: CommonEventSubscriber;<br>Method or attribute name: getAbortCommonEventSync(): boolean;|commonEventSubscriber.d.ts|
|Added|NA|Class name: CommonEventSubscriber;<br>Method or attribute name: getSubscribeInfoSync(): CommonEventSubscribeInfo;|commonEventSubscriber.d.ts|
|Added|NA|Class name: NotificationFlagStatus;<br>Method or attribute name: TYPE_NONE = 0|notificationFlags.d.ts|
|Added|NA|Class name: NotificationFlagStatus;<br>Method or attribute name: TYPE_OPEN = 1|notificationFlags.d.ts|
|Added|NA|Class name: NotificationFlagStatus;<br>Method or attribute name: TYPE_CLOSE = 2|notificationFlags.d.ts|
|Added|NA|Class name: NotificationFlags;<br>Method or attribute name: readonly soundEnabled?: NotificationFlagStatus;|notificationFlags.d.ts|
|Added|NA|Class name: NotificationFlags;<br>Method or attribute name: readonly vibrationEnabled?: NotificationFlagStatus;|notificationFlags.d.ts|
