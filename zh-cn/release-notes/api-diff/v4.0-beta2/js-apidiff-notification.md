| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：Support;<br>方法or属性：COMMON_EVENT_CHARGE_IDLE_MODE_CHANGED = 'usual.event.CHARGE_IDLE_MODE_CHANGED'|@ohos.commonEventManager.d.ts|
|新增|NA|类名：emitter;<br>方法or属性：function off(eventId: number, callback: Callback\<EventData>): void;|@ohos.events.emitter.d.ts|
|新增|NA|类名：notificationSubscribe;<br>方法or属性：function remove(hashCodes: Array\<String>, reason: RemoveReason, callback: AsyncCallback\<void>): void;|@ohos.notificationSubscribe.d.ts|
|新增|NA|类名：notificationSubscribe;<br>方法or属性：function remove(hashCodes: Array\<String>, reason: RemoveReason): Promise\<void>;|@ohos.notificationSubscribe.d.ts|
|错误码有变化|类名：reminderAgentManager;<br>方法or属性：function publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback\<number>): void;<br>旧版本信息：401|类名：reminderAgentManager;<br>方法or属性：function publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback\<number>): void;<br>新版本信息：401,1700001,1700002|@ohos.reminderAgentManager.d.ts|
|错误码有变化|类名：reminderAgentManager;<br>方法or属性：function publishReminder(reminderReq: ReminderRequest): Promise\<number>;<br>旧版本信息：401|类名：reminderAgentManager;<br>方法or属性：function publishReminder(reminderReq: ReminderRequest): Promise\<number>;<br>新版本信息：401,1700001,1700002|@ohos.reminderAgentManager.d.ts|
|错误码有变化|类名：reminderAgentManager;<br>方法or属性：function cancelReminder(reminderId: number, callback: AsyncCallback\<void>): void;<br>旧版本信息：401|类名：reminderAgentManager;<br>方法or属性：function cancelReminder(reminderId: number, callback: AsyncCallback\<void>): void;<br>新版本信息：401,1700003,1700004|@ohos.reminderAgentManager.d.ts|
|错误码有变化|类名：reminderAgentManager;<br>方法or属性：function cancelReminder(reminderId: number): Promise\<void>;<br>旧版本信息：401|类名：reminderAgentManager;<br>方法or属性：function cancelReminder(reminderId: number): Promise\<void>;<br>新版本信息：401,1700003,1700004|@ohos.reminderAgentManager.d.ts|
|错误码有变化|类名：reminderAgentManager;<br>方法or属性：function getValidReminders(callback: AsyncCallback\<Array\<ReminderRequest>>): void;<br>旧版本信息：401|类名：reminderAgentManager;<br>方法or属性：function getValidReminders(callback: AsyncCallback\<Array\<ReminderRequest>>): void;<br>新版本信息：401,1700004|@ohos.reminderAgentManager.d.ts|
|错误码有变化|类名：reminderAgentManager;<br>方法or属性：function getValidReminders(): Promise\<Array\<ReminderRequest>>;<br>旧版本信息：401|类名：reminderAgentManager;<br>方法or属性：function getValidReminders(): Promise\<Array\<ReminderRequest>>;<br>新版本信息：401,1700004|@ohos.reminderAgentManager.d.ts|
|错误码有变化|类名：reminderAgentManager;<br>方法or属性：function cancelAllReminders(callback: AsyncCallback\<void>): void;<br>旧版本信息：401|类名：reminderAgentManager;<br>方法or属性：function cancelAllReminders(callback: AsyncCallback\<void>): void;<br>新版本信息：401,1700004|@ohos.reminderAgentManager.d.ts|
|错误码有变化|类名：reminderAgentManager;<br>方法or属性：function cancelAllReminders(): Promise\<void>;<br>旧版本信息：401|类名：reminderAgentManager;<br>方法or属性：function cancelAllReminders(): Promise\<void>;<br>新版本信息：401,1700004|@ohos.reminderAgentManager.d.ts|
|访问级别有变化|类名：notification;<br>方法or属性：function publish(request: NotificationRequest, userId: number): Promise\<void>;<br>旧版本信息：|类名：notification;<br>方法or属性：function publish(request: NotificationRequest, userId: number): Promise\<void>;<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：notification;<br>方法or属性：function isNotificationEnabled(userId: number): Promise\<boolean>;<br>旧版本信息：|类名：notification;<br>方法or属性：function isNotificationEnabled(userId: number): Promise\<boolean>;<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：notification;<br>方法or属性：function removeAll(userId: number): Promise\<void>;<br>旧版本信息：|类名：notification;<br>方法or属性：function removeAll(userId: number): Promise\<void>;<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：notification;<br>方法or属性：function removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void>;<br>旧版本信息：|类名：notification;<br>方法or属性：function removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void>;<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：notification;<br>方法or属性：function setDoNotDisturbDate(date: DoNotDisturbDate): Promise\<void>;<br>旧版本信息：|类名：notification;<br>方法or属性：function setDoNotDisturbDate(date: DoNotDisturbDate): Promise\<void>;<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：notification;<br>方法or属性：function setDoNotDisturbDate(date: DoNotDisturbDate, userId: number): Promise\<void>;<br>旧版本信息：|类名：notification;<br>方法or属性：function setDoNotDisturbDate(date: DoNotDisturbDate, userId: number): Promise\<void>;<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：notification;<br>方法or属性：function getDoNotDisturbDate(): Promise\<DoNotDisturbDate>;<br>旧版本信息：|类名：notification;<br>方法or属性：function getDoNotDisturbDate(): Promise\<DoNotDisturbDate>;<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：notification;<br>方法or属性：function getDoNotDisturbDate(userId: number): Promise\<DoNotDisturbDate>;<br>旧版本信息：|类名：notification;<br>方法or属性：function getDoNotDisturbDate(userId: number): Promise\<DoNotDisturbDate>;<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：notification;<br>方法or属性：function supportDoNotDisturbMode(): Promise\<boolean>;<br>旧版本信息：|类名：notification;<br>方法or属性：function supportDoNotDisturbMode(): Promise\<boolean>;<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：notification;<br>方法or属性：function enableDistributed(enable: boolean): Promise\<void>;<br>旧版本信息：|类名：notification;<br>方法or属性：function enableDistributed(enable: boolean): Promise\<void>;<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：notification;<br>方法or属性：function enableDistributedByBundle(bundle: BundleOption, enable: boolean): Promise\<void>;<br>旧版本信息：|类名：notification;<br>方法or属性：function enableDistributedByBundle(bundle: BundleOption, enable: boolean): Promise\<void>;<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：notification;<br>方法or属性：function isDistributedEnabledByBundle(bundle: BundleOption): Promise\<boolean>;<br>旧版本信息：|类名：notification;<br>方法or属性：function isDistributedEnabledByBundle(bundle: BundleOption): Promise\<boolean>;<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：notification;<br>方法or属性：function getDeviceRemindType(): Promise\<DeviceRemindType>;<br>旧版本信息：|类名：notification;<br>方法or属性：function getDeviceRemindType(): Promise\<DeviceRemindType>;<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：DoNotDisturbType;<br>方法or属性：TYPE_NONE = 0<br>旧版本信息：|类名：DoNotDisturbType;<br>方法or属性：TYPE_NONE = 0<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：DoNotDisturbType;<br>方法or属性：TYPE_ONCE = 1<br>旧版本信息：|类名：DoNotDisturbType;<br>方法or属性：TYPE_ONCE = 1<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：DoNotDisturbType;<br>方法or属性：TYPE_DAILY = 2<br>旧版本信息：|类名：DoNotDisturbType;<br>方法or属性：TYPE_DAILY = 2<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：DoNotDisturbType;<br>方法or属性：TYPE_CLEARLY = 3<br>旧版本信息：|类名：DoNotDisturbType;<br>方法or属性：TYPE_CLEARLY = 3<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：DoNotDisturbDate;<br>方法or属性：type: DoNotDisturbType;<br>旧版本信息：|类名：DoNotDisturbDate;<br>方法or属性：type: DoNotDisturbType;<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：DoNotDisturbDate;<br>方法or属性：begin: Date;<br>旧版本信息：|类名：DoNotDisturbDate;<br>方法or属性：begin: Date;<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：DoNotDisturbDate;<br>方法or属性：end: Date;<br>旧版本信息：|类名：DoNotDisturbDate;<br>方法or属性：end: Date;<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：DeviceRemindType;<br>方法or属性：IDLE_DONOT_REMIND = 0<br>旧版本信息：|类名：DeviceRemindType;<br>方法or属性：IDLE_DONOT_REMIND = 0<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：DeviceRemindType;<br>方法or属性：IDLE_REMIND = 1<br>旧版本信息：|类名：DeviceRemindType;<br>方法or属性：IDLE_REMIND = 1<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：DeviceRemindType;<br>方法or属性：ACTIVE_DONOT_REMIND = 2<br>旧版本信息：|类名：DeviceRemindType;<br>方法or属性：ACTIVE_DONOT_REMIND = 2<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：DeviceRemindType;<br>方法or属性：ACTIVE_REMIND = 3<br>旧版本信息：|类名：DeviceRemindType;<br>方法or属性：ACTIVE_REMIND = 3<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：SourceType;<br>方法or属性：TYPE_NORMAL = 0<br>旧版本信息：|类名：SourceType;<br>方法or属性：TYPE_NORMAL = 0<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：SourceType;<br>方法or属性：TYPE_CONTINUOUS = 1<br>旧版本信息：|类名：SourceType;<br>方法or属性：TYPE_CONTINUOUS = 1<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：SourceType;<br>方法or属性：TYPE_TIMER = 2<br>旧版本信息：|类名：SourceType;<br>方法or属性：TYPE_TIMER = 2<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：RemoveReason;<br>方法or属性：CLICK_REASON_REMOVE = 1<br>旧版本信息：|类名：RemoveReason;<br>方法or属性：CLICK_REASON_REMOVE = 1<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：RemoveReason;<br>方法or属性：CANCEL_REASON_REMOVE = 2<br>旧版本信息：|类名：RemoveReason;<br>方法or属性：CANCEL_REASON_REMOVE = 2<br>新版本信息：systemapi|@ohos.notification.d.ts|
|访问级别有变化|类名：NotificationCheckInfo;<br>方法or属性：bundleName: string;<br>旧版本信息：|类名：NotificationCheckInfo;<br>方法or属性：bundleName: string;<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：NotificationCheckInfo;<br>方法or属性：notificationId: number;<br>旧版本信息：|类名：NotificationCheckInfo;<br>方法or属性：notificationId: number;<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：NotificationCheckInfo;<br>方法or属性：contentType: ContentType;<br>旧版本信息：|类名：NotificationCheckInfo;<br>方法or属性：contentType: ContentType;<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：NotificationCheckResult;<br>方法or属性：code: number;<br>旧版本信息：|类名：NotificationCheckResult;<br>方法or属性：code: number;<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：NotificationCheckResult;<br>方法or属性：message: string;<br>旧版本信息：|类名：NotificationCheckResult;<br>方法or属性：message: string;<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：DoNotDisturbType;<br>方法or属性：TYPE_NONE = 0<br>旧版本信息：|类名：DoNotDisturbType;<br>方法or属性：TYPE_NONE = 0<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：DoNotDisturbType;<br>方法or属性：TYPE_ONCE = 1<br>旧版本信息：|类名：DoNotDisturbType;<br>方法or属性：TYPE_ONCE = 1<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：DoNotDisturbType;<br>方法or属性：TYPE_DAILY = 2<br>旧版本信息：|类名：DoNotDisturbType;<br>方法or属性：TYPE_DAILY = 2<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：DoNotDisturbType;<br>方法or属性：TYPE_CLEARLY = 3<br>旧版本信息：|类名：DoNotDisturbType;<br>方法or属性：TYPE_CLEARLY = 3<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：DoNotDisturbDate;<br>方法or属性：type: DoNotDisturbType;<br>旧版本信息：|类名：DoNotDisturbDate;<br>方法or属性：type: DoNotDisturbType;<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：DoNotDisturbDate;<br>方法or属性：begin: Date;<br>旧版本信息：|类名：DoNotDisturbDate;<br>方法or属性：begin: Date;<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：DoNotDisturbDate;<br>方法or属性：end: Date;<br>旧版本信息：|类名：DoNotDisturbDate;<br>方法or属性：end: Date;<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：DeviceRemindType;<br>方法or属性：IDLE_DONOT_REMIND = 0<br>旧版本信息：|类名：DeviceRemindType;<br>方法or属性：IDLE_DONOT_REMIND = 0<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：DeviceRemindType;<br>方法or属性：IDLE_REMIND = 1<br>旧版本信息：|类名：DeviceRemindType;<br>方法or属性：IDLE_REMIND = 1<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：DeviceRemindType;<br>方法or属性：ACTIVE_DONOT_REMIND = 2<br>旧版本信息：|类名：DeviceRemindType;<br>方法or属性：ACTIVE_DONOT_REMIND = 2<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：DeviceRemindType;<br>方法or属性：ACTIVE_REMIND = 3<br>旧版本信息：|类名：DeviceRemindType;<br>方法or属性：ACTIVE_REMIND = 3<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：SourceType;<br>方法or属性：TYPE_NORMAL = 0<br>旧版本信息：|类名：SourceType;<br>方法or属性：TYPE_NORMAL = 0<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：SourceType;<br>方法or属性：TYPE_CONTINUOUS = 1<br>旧版本信息：|类名：SourceType;<br>方法or属性：TYPE_CONTINUOUS = 1<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：SourceType;<br>方法or属性：TYPE_TIMER = 2<br>旧版本信息：|类名：SourceType;<br>方法or属性：TYPE_TIMER = 2<br>新版本信息：systemapi|@ohos.notificationManager.d.ts|
|访问级别有变化|类名：notificationSubscribe;<br>方法or属性：export type BundleOption = _BundleOption;<br>旧版本信息：|类名：notificationSubscribe;<br>方法or属性：export type BundleOption = _BundleOption;<br>新版本信息：systemapi|@ohos.notificationSubscribe.d.ts|
|访问级别有变化|类名：NotificationKey;<br>方法or属性：id: number;<br>旧版本信息：|类名：NotificationKey;<br>方法or属性：id: number;<br>新版本信息：systemapi|@ohos.notificationSubscribe.d.ts|
|访问级别有变化|类名：NotificationKey;<br>方法or属性：label?: string;<br>旧版本信息：|类名：NotificationKey;<br>方法or属性：label?: string;<br>新版本信息：systemapi|@ohos.notificationSubscribe.d.ts|
|访问级别有变化|类名：RemoveReason;<br>方法or属性：CLICK_REASON_REMOVE = 1<br>旧版本信息：|类名：RemoveReason;<br>方法or属性：CLICK_REASON_REMOVE = 1<br>新版本信息：systemapi|@ohos.notificationSubscribe.d.ts|
|访问级别有变化|类名：RemoveReason;<br>方法or属性：CANCEL_REASON_REMOVE = 2<br>旧版本信息：|类名：RemoveReason;<br>方法or属性：CANCEL_REASON_REMOVE = 2<br>新版本信息：systemapi|@ohos.notificationSubscribe.d.ts|
|访问级别有变化|类名：NotificationSorting;<br>方法or属性：readonly slot: NotificationSlot;<br>旧版本信息：|类名：NotificationSorting;<br>方法or属性：readonly slot: NotificationSlot;<br>新版本信息：systemapi|notificationSorting.d.ts|
|访问级别有变化|类名：NotificationSorting;<br>方法or属性：readonly hashCode: string;<br>旧版本信息：|类名：NotificationSorting;<br>方法or属性：readonly hashCode: string;<br>新版本信息：systemapi|notificationSorting.d.ts|
|访问级别有变化|类名：NotificationSorting;<br>方法or属性：readonly ranking: number;<br>旧版本信息：|类名：NotificationSorting;<br>方法or属性：readonly ranking: number;<br>新版本信息：systemapi|notificationSorting.d.ts|
|访问级别有变化|类名：NotificationSortingMap;<br>方法or属性：readonly sortings: { [key: string]: NotificationSorting };<br>旧版本信息：|类名：NotificationSortingMap;<br>方法or属性：readonly sortings: { [key: string]: NotificationSorting };<br>新版本信息：systemapi|notificationSortingMap.d.ts|
|访问级别有变化|类名：NotificationSortingMap;<br>方法or属性：readonly sortedHashCode: Array\<string>;<br>旧版本信息：|类名：NotificationSortingMap;<br>方法or属性：readonly sortedHashCode: Array\<string>;<br>新版本信息：systemapi|notificationSortingMap.d.ts|
|访问级别有变化|类名：NotificationSubscribeInfo;<br>方法or属性：bundleNames?: Array\<string>;<br>旧版本信息：|类名：NotificationSubscribeInfo;<br>方法or属性：bundleNames?: Array\<string>;<br>新版本信息：systemapi|notificationSubscribeInfo.d.ts|
|访问级别有变化|类名：NotificationSubscribeInfo;<br>方法or属性：userId?: number;<br>旧版本信息：|类名：NotificationSubscribeInfo;<br>方法or属性：userId?: number;<br>新版本信息：systemapi|notificationSubscribeInfo.d.ts|
|访问级别有变化|类名：NotificationSubscriber;<br>方法or属性：onConsume?: (data: SubscribeCallbackData) => void;<br>旧版本信息：|类名：NotificationSubscriber;<br>方法or属性：onConsume?: (data: SubscribeCallbackData) => void;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：NotificationSubscriber;<br>方法or属性：onCancel?: (data: SubscribeCallbackData) => void;<br>旧版本信息：|类名：NotificationSubscriber;<br>方法or属性：onCancel?: (data: SubscribeCallbackData) => void;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：NotificationSubscriber;<br>方法or属性：onUpdate?: (data: NotificationSortingMap) => void;<br>旧版本信息：|类名：NotificationSubscriber;<br>方法or属性：onUpdate?: (data: NotificationSortingMap) => void;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：NotificationSubscriber;<br>方法or属性：onConnect?: () => void;<br>旧版本信息：|类名：NotificationSubscriber;<br>方法or属性：onConnect?: () => void;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：NotificationSubscriber;<br>方法or属性：onDisconnect?: () => void;<br>旧版本信息：|类名：NotificationSubscriber;<br>方法or属性：onDisconnect?: () => void;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：NotificationSubscriber;<br>方法or属性：onDestroy?: () => void;<br>旧版本信息：|类名：NotificationSubscriber;<br>方法or属性：onDestroy?: () => void;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：NotificationSubscriber;<br>方法or属性：onDoNotDisturbDateChange?: (mode: notification.DoNotDisturbDate) => void;<br>旧版本信息：|类名：NotificationSubscriber;<br>方法or属性：onDoNotDisturbDateChange?: (mode: notification.DoNotDisturbDate) => void;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：NotificationSubscriber;<br>方法or属性：onEnabledNotificationChanged?: (callbackData: EnabledNotificationCallbackData) => void;<br>旧版本信息：|类名：NotificationSubscriber;<br>方法or属性：onEnabledNotificationChanged?: (callbackData: EnabledNotificationCallbackData) => void;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：NotificationSubscriber;<br>方法or属性：onBadgeChanged?: (data: BadgeNumberCallbackData) => void;<br>旧版本信息：|类名：NotificationSubscriber;<br>方法or属性：onBadgeChanged?: (data: BadgeNumberCallbackData) => void;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：SubscribeCallbackData;<br>方法or属性：readonly request: NotificationRequest;<br>旧版本信息：|类名：SubscribeCallbackData;<br>方法or属性：readonly request: NotificationRequest;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：SubscribeCallbackData;<br>方法or属性：readonly sortingMap?: NotificationSortingMap;<br>旧版本信息：|类名：SubscribeCallbackData;<br>方法or属性：readonly sortingMap?: NotificationSortingMap;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：SubscribeCallbackData;<br>方法or属性：readonly reason?: number;<br>旧版本信息：|类名：SubscribeCallbackData;<br>方法or属性：readonly reason?: number;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：SubscribeCallbackData;<br>方法or属性：readonly sound?: string;<br>旧版本信息：|类名：SubscribeCallbackData;<br>方法or属性：readonly sound?: string;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：SubscribeCallbackData;<br>方法or属性：readonly vibrationValues?: Array\<number>;<br>旧版本信息：|类名：SubscribeCallbackData;<br>方法or属性：readonly vibrationValues?: Array\<number>;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：EnabledNotificationCallbackData;<br>方法or属性：readonly bundle: string;<br>旧版本信息：|类名：EnabledNotificationCallbackData;<br>方法or属性：readonly bundle: string;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：BadgeNumberCallbackData;<br>方法or属性：readonly bundle: string;<br>旧版本信息：|类名：BadgeNumberCallbackData;<br>方法or属性：readonly bundle: string;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：EnabledNotificationCallbackData;<br>方法or属性：readonly uid: number;<br>旧版本信息：|类名：EnabledNotificationCallbackData;<br>方法or属性：readonly uid: number;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：BadgeNumberCallbackData;<br>方法or属性：readonly uid: number;<br>旧版本信息：|类名：BadgeNumberCallbackData;<br>方法or属性：readonly uid: number;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：EnabledNotificationCallbackData;<br>方法or属性：readonly enable: boolean;<br>旧版本信息：|类名：EnabledNotificationCallbackData;<br>方法or属性：readonly enable: boolean;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|访问级别有变化|类名：BadgeNumberCallbackData;<br>方法or属性：readonly badgeNumber: number;<br>旧版本信息：|类名：BadgeNumberCallbackData;<br>方法or属性：readonly badgeNumber: number;<br>新版本信息：systemapi|notificationSubscriber.d.ts|
|权限有变化|类名：notification;<br>方法or属性：function publish(request: NotificationRequest, userId: number): Promise\<void>;<br>旧版本信息：|类名：notification;<br>方法or属性：function publish(request: NotificationRequest, userId: number): Promise\<void>;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER|@ohos.notification.d.ts|
|权限有变化|类名：notification;<br>方法or属性：function isNotificationEnabled(userId: number): Promise\<boolean>;<br>旧版本信息：|类名：notification;<br>方法or属性：function isNotificationEnabled(userId: number): Promise\<boolean>;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER|@ohos.notification.d.ts|
|权限有变化|类名：notification;<br>方法or属性：function removeAll(userId: number): Promise\<void>;<br>旧版本信息：|类名：notification;<br>方法or属性：function removeAll(userId: number): Promise\<void>;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER|@ohos.notification.d.ts|
|权限有变化|类名：notification;<br>方法or属性：function removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void>;<br>旧版本信息：|类名：notification;<br>方法or属性：function removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void>;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER|@ohos.notification.d.ts|
|权限有变化|类名：notification;<br>方法or属性：function setDoNotDisturbDate(date: DoNotDisturbDate): Promise\<void>;<br>旧版本信息：|类名：notification;<br>方法or属性：function setDoNotDisturbDate(date: DoNotDisturbDate): Promise\<void>;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER|@ohos.notification.d.ts|
|权限有变化|类名：notification;<br>方法or属性：function setDoNotDisturbDate(date: DoNotDisturbDate, userId: number): Promise\<void>;<br>旧版本信息：|类名：notification;<br>方法or属性：function setDoNotDisturbDate(date: DoNotDisturbDate, userId: number): Promise\<void>;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER|@ohos.notification.d.ts|
|权限有变化|类名：notification;<br>方法or属性：function getDoNotDisturbDate(): Promise\<DoNotDisturbDate>;<br>旧版本信息：|类名：notification;<br>方法or属性：function getDoNotDisturbDate(): Promise\<DoNotDisturbDate>;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER|@ohos.notification.d.ts|
|权限有变化|类名：notification;<br>方法or属性：function getDoNotDisturbDate(userId: number): Promise\<DoNotDisturbDate>;<br>旧版本信息：|类名：notification;<br>方法or属性：function getDoNotDisturbDate(userId: number): Promise\<DoNotDisturbDate>;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER|@ohos.notification.d.ts|
|权限有变化|类名：notification;<br>方法or属性：function supportDoNotDisturbMode(): Promise\<boolean>;<br>旧版本信息：|类名：notification;<br>方法or属性：function supportDoNotDisturbMode(): Promise\<boolean>;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER|@ohos.notification.d.ts|
|权限有变化|类名：notification;<br>方法or属性：function enableDistributed(enable: boolean): Promise\<void>;<br>旧版本信息：|类名：notification;<br>方法or属性：function enableDistributed(enable: boolean): Promise\<void>;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER|@ohos.notification.d.ts|
|权限有变化|类名：notification;<br>方法or属性：function enableDistributedByBundle(bundle: BundleOption, enable: boolean): Promise\<void>;<br>旧版本信息：|类名：notification;<br>方法or属性：function enableDistributedByBundle(bundle: BundleOption, enable: boolean): Promise\<void>;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER|@ohos.notification.d.ts|
|权限有变化|类名：notification;<br>方法or属性：function isDistributedEnabledByBundle(bundle: BundleOption): Promise\<boolean>;<br>旧版本信息：|类名：notification;<br>方法or属性：function isDistributedEnabledByBundle(bundle: BundleOption): Promise\<boolean>;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER|@ohos.notification.d.ts|
|权限有变化|类名：notification;<br>方法or属性：function getDeviceRemindType(): Promise\<DeviceRemindType>;<br>旧版本信息：|类名：notification;<br>方法or属性：function getDeviceRemindType(): Promise\<DeviceRemindType>;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER|@ohos.notification.d.ts|
|权限有变化|类名：NotificationCheckInfo;<br>方法or属性：bundleName: string;<br>旧版本信息：|类名：NotificationCheckInfo;<br>方法or属性：bundleName: string;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER,ohos.permission.NOTIFICATION_AGENT_CONTROLLER|@ohos.notificationManager.d.ts|
|权限有变化|类名：NotificationCheckInfo;<br>方法or属性：notificationId: number;<br>旧版本信息：|类名：NotificationCheckInfo;<br>方法or属性：notificationId: number;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER,ohos.permission.NOTIFICATION_AGENT_CONTROLLER|@ohos.notificationManager.d.ts|
|权限有变化|类名：NotificationCheckInfo;<br>方法or属性：contentType: ContentType;<br>旧版本信息：|类名：NotificationCheckInfo;<br>方法or属性：contentType: ContentType;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER,ohos.permission.NOTIFICATION_AGENT_CONTROLLER|@ohos.notificationManager.d.ts|
|权限有变化|类名：NotificationCheckResult;<br>方法or属性：code: number;<br>旧版本信息：|类名：NotificationCheckResult;<br>方法or属性：code: number;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER,ohos.permission.NOTIFICATION_AGENT_CONTROLLER|@ohos.notificationManager.d.ts|
|权限有变化|类名：NotificationCheckResult;<br>方法or属性：message: string;<br>旧版本信息：|类名：NotificationCheckResult;<br>方法or属性：message: string;<br>新版本信息：ohos.permission.NOTIFICATION_CONTROLLER,ohos.permission.NOTIFICATION_AGENT_CONTROLLER|@ohos.notificationManager.d.ts|
|type有变化|类名：EventData;<br>方法or属性：data?: { [key: string]: any };<br>旧版本信息：|类名：EventData;<br>方法or属性：data?: { [key: string]: any };<br>新版本信息：?object|@ohos.events.emitter.d.ts|
|type有变化|类名：InnerEvent;<br>方法or属性：eventId: number;<br>旧版本信息：|类名：InnerEvent;<br>方法or属性：eventId: number;<br>新版本信息：number|@ohos.events.emitter.d.ts|
|type有变化|类名：InnerEvent;<br>方法or属性：priority?: EventPriority;<br>旧版本信息：|类名：InnerEvent;<br>方法or属性：priority?: EventPriority;<br>新版本信息：?EventPriority|@ohos.events.emitter.d.ts|
|type有变化|类名：BundleOption;<br>方法or属性：bundle: string;<br>旧版本信息：|类名：BundleOption;<br>方法or属性：bundle: string;<br>新版本信息：string|@ohos.notification.d.ts|
|type有变化|类名：BundleOption;<br>方法or属性：uid?: number;<br>旧版本信息：|类名：BundleOption;<br>方法or属性：uid?: number;<br>新版本信息：?number|@ohos.notification.d.ts|
|type有变化|类名：NotificationKey;<br>方法or属性：id: number;<br>旧版本信息：|类名：NotificationKey;<br>方法or属性：id: number;<br>新版本信息：number|@ohos.notification.d.ts|
|type有变化|类名：NotificationKey;<br>方法or属性：label?: string;<br>旧版本信息：|类名：NotificationKey;<br>方法or属性：label?: string;<br>新版本信息：?string|@ohos.notification.d.ts|
|type有变化|类名：NotificationCheckInfo;<br>方法or属性：bundleName: string;<br>旧版本信息：|类名：NotificationCheckInfo;<br>方法or属性：bundleName: string;<br>新版本信息：string|@ohos.notificationManager.d.ts|
|type有变化|类名：NotificationCheckInfo;<br>方法or属性：notificationId: number;<br>旧版本信息：|类名：NotificationCheckInfo;<br>方法or属性：notificationId: number;<br>新版本信息：number|@ohos.notificationManager.d.ts|
|type有变化|类名：NotificationCheckInfo;<br>方法or属性：contentType: ContentType;<br>旧版本信息：|类名：NotificationCheckInfo;<br>方法or属性：contentType: ContentType;<br>新版本信息：ContentType|@ohos.notificationManager.d.ts|
|type有变化|类名：NotificationCheckResult;<br>方法or属性：code: number;<br>旧版本信息：|类名：NotificationCheckResult;<br>方法or属性：code: number;<br>新版本信息：number|@ohos.notificationManager.d.ts|
|type有变化|类名：NotificationCheckResult;<br>方法or属性：message: string;<br>旧版本信息：|类名：NotificationCheckResult;<br>方法or属性：message: string;<br>新版本信息：string|@ohos.notificationManager.d.ts|
|type有变化|类名：DoNotDisturbDate;<br>方法or属性：type: DoNotDisturbType;<br>旧版本信息：|类名：DoNotDisturbDate;<br>方法or属性：type: DoNotDisturbType;<br>新版本信息：DoNotDisturbType|@ohos.notificationManager.d.ts|
|type有变化|类名：DoNotDisturbDate;<br>方法or属性：begin: Date;<br>旧版本信息：|类名：DoNotDisturbDate;<br>方法or属性：begin: Date;<br>新版本信息：Date|@ohos.notificationManager.d.ts|
|type有变化|类名：DoNotDisturbDate;<br>方法or属性：end: Date;<br>旧版本信息：|类名：DoNotDisturbDate;<br>方法or属性：end: Date;<br>新版本信息：Date|@ohos.notificationManager.d.ts|
|type有变化|类名：NotificationKey;<br>方法or属性：id: number;<br>旧版本信息：|类名：NotificationKey;<br>方法or属性：id: number;<br>新版本信息：number|@ohos.notificationSubscribe.d.ts|
|type有变化|类名：NotificationKey;<br>方法or属性：label?: string;<br>旧版本信息：|类名：NotificationKey;<br>方法or属性：label?: string;<br>新版本信息：?string|@ohos.notificationSubscribe.d.ts|
|type有变化|类名：ActionResult;<br>方法or属性：bundleName: string;<br>旧版本信息：|类名：ActionResult;<br>方法or属性：bundleName: string;<br>新版本信息：string|@system.notification.d.ts|
|type有变化|类名：ActionResult;<br>方法or属性：abilityName: string;<br>旧版本信息：|类名：ActionResult;<br>方法or属性：abilityName: string;<br>新版本信息：string|@system.notification.d.ts|
|type有变化|类名：ActionResult;<br>方法or属性：uri: string;<br>旧版本信息：|类名：ActionResult;<br>方法or属性：uri: string;<br>新版本信息：string|@system.notification.d.ts|
|type有变化|类名：ShowNotificationOptions;<br>方法or属性：contentTitle?: string;<br>旧版本信息：|类名：ShowNotificationOptions;<br>方法or属性：contentTitle?: string;<br>新版本信息：?string|@system.notification.d.ts|
|type有变化|类名：ShowNotificationOptions;<br>方法or属性：contentText?: string;<br>旧版本信息：|类名：ShowNotificationOptions;<br>方法or属性：contentText?: string;<br>新版本信息：?string|@system.notification.d.ts|
|type有变化|类名：ShowNotificationOptions;<br>方法or属性：clickAction?: ActionResult;<br>旧版本信息：|类名：ShowNotificationOptions;<br>方法or属性：clickAction?: ActionResult;<br>新版本信息：?ActionResult|@system.notification.d.ts|
|type有变化|类名：CommonEventData;<br>方法or属性：event: string;<br>旧版本信息：|类名：CommonEventData;<br>方法or属性：event: string;<br>新版本信息：string|commonEventData.d.ts|
|type有变化|类名：CommonEventData;<br>方法or属性：bundleName?: string;<br>旧版本信息：|类名：CommonEventData;<br>方法or属性：bundleName?: string;<br>新版本信息：?string|commonEventData.d.ts|
|type有变化|类名：CommonEventData;<br>方法or属性：code?: number;<br>旧版本信息：|类名：CommonEventData;<br>方法or属性：code?: number;<br>新版本信息：?number|commonEventData.d.ts|
|type有变化|类名：CommonEventData;<br>方法or属性：data?: string;<br>旧版本信息：|类名：CommonEventData;<br>方法or属性：data?: string;<br>新版本信息：?string|commonEventData.d.ts|
|type有变化|类名：CommonEventData;<br>方法or属性：parameters?: { [key: string]: any };<br>旧版本信息：|类名：CommonEventData;<br>方法or属性：parameters?: { [key: string]: any };<br>新版本信息：?object|commonEventData.d.ts|
|type有变化|类名：CommonEventPublishData;<br>方法or属性：bundleName?: string;<br>旧版本信息：|类名：CommonEventPublishData;<br>方法or属性：bundleName?: string;<br>新版本信息：?string|commonEventPublishData.d.ts|
|type有变化|类名：CommonEventPublishData;<br>方法or属性：code?: number;<br>旧版本信息：|类名：CommonEventPublishData;<br>方法or属性：code?: number;<br>新版本信息：?number|commonEventPublishData.d.ts|
|type有变化|类名：CommonEventPublishData;<br>方法or属性：data?: string;<br>旧版本信息：|类名：CommonEventPublishData;<br>方法or属性：data?: string;<br>新版本信息：?string|commonEventPublishData.d.ts|
|type有变化|类名：CommonEventPublishData;<br>方法or属性：subscriberPermissions?: Array\<string>;<br>旧版本信息：|类名：CommonEventPublishData;<br>方法or属性：subscriberPermissions?: Array\<string>;<br>新版本信息：?Array\<string>|commonEventPublishData.d.ts|
|type有变化|类名：CommonEventPublishData;<br>方法or属性：isOrdered?: boolean;<br>旧版本信息：|类名：CommonEventPublishData;<br>方法or属性：isOrdered?: boolean;<br>新版本信息：?boolean|commonEventPublishData.d.ts|
|type有变化|类名：CommonEventPublishData;<br>方法or属性：isSticky?: boolean;<br>旧版本信息：|类名：CommonEventPublishData;<br>方法or属性：isSticky?: boolean;<br>新版本信息：?boolean|commonEventPublishData.d.ts|
|type有变化|类名：CommonEventPublishData;<br>方法or属性：parameters?: { [key: string]: any };<br>旧版本信息：|类名：CommonEventPublishData;<br>方法or属性：parameters?: { [key: string]: any };<br>新版本信息：?object|commonEventPublishData.d.ts|
|type有变化|类名：CommonEventSubscribeInfo;<br>方法or属性：events: Array\<string>;<br>旧版本信息：|类名：CommonEventSubscribeInfo;<br>方法or属性：events: Array\<string>;<br>新版本信息：Array\<string>|commonEventSubscribeInfo.d.ts|
|type有变化|类名：CommonEventSubscribeInfo;<br>方法or属性：publisherPermission?: string;<br>旧版本信息：|类名：CommonEventSubscribeInfo;<br>方法or属性：publisherPermission?: string;<br>新版本信息：?string|commonEventSubscribeInfo.d.ts|
|type有变化|类名：CommonEventSubscribeInfo;<br>方法or属性：publisherDeviceId?: string;<br>旧版本信息：|类名：CommonEventSubscribeInfo;<br>方法or属性：publisherDeviceId?: string;<br>新版本信息：?string|commonEventSubscribeInfo.d.ts|
|type有变化|类名：CommonEventSubscribeInfo;<br>方法or属性：userId?: number;<br>旧版本信息：|类名：CommonEventSubscribeInfo;<br>方法or属性：userId?: number;<br>新版本信息：?number|commonEventSubscribeInfo.d.ts|
|type有变化|类名：CommonEventSubscribeInfo;<br>方法or属性：priority?: number;<br>旧版本信息：|类名：CommonEventSubscribeInfo;<br>方法or属性：priority?: number;<br>新版本信息：?number|commonEventSubscribeInfo.d.ts|
|type有变化|类名：NotificationActionButton;<br>方法or属性：title: string;<br>旧版本信息：|类名：NotificationActionButton;<br>方法or属性：title: string;<br>新版本信息：string|notificationActionButton.d.ts|
|type有变化|类名：NotificationActionButton;<br>方法or属性：wantAgent: WantAgent;<br>旧版本信息：|类名：NotificationActionButton;<br>方法or属性：wantAgent: WantAgent;<br>新版本信息：WantAgent|notificationActionButton.d.ts|
|type有变化|类名：NotificationActionButton;<br>方法or属性：extras?: { [key: string]: any };<br>旧版本信息：|类名：NotificationActionButton;<br>方法or属性：extras?: { [key: string]: any };<br>新版本信息：?object|notificationActionButton.d.ts|
|type有变化|类名：NotificationActionButton;<br>方法or属性：userInput?: NotificationUserInput;<br>旧版本信息：|类名：NotificationActionButton;<br>方法or属性：userInput?: NotificationUserInput;<br>新版本信息：?NotificationUserInput|notificationActionButton.d.ts|
|type有变化|类名：BundleOption;<br>方法or属性：bundle: string;<br>旧版本信息：|类名：BundleOption;<br>方法or属性：bundle: string;<br>新版本信息：string|NotificationCommonDef.d.ts|
|type有变化|类名：BundleOption;<br>方法or属性：uid?: number;<br>旧版本信息：|类名：BundleOption;<br>方法or属性：uid?: number;<br>新版本信息：?number|NotificationCommonDef.d.ts|
|type有变化|类名：NotificationBasicContent;<br>方法or属性：title: string;<br>旧版本信息：|类名：NotificationBasicContent;<br>方法or属性：title: string;<br>新版本信息：string|notificationContent.d.ts|
|type有变化|类名：NotificationBasicContent;<br>方法or属性：text: string;<br>旧版本信息：|类名：NotificationBasicContent;<br>方法or属性：text: string;<br>新版本信息：string|notificationContent.d.ts|
|type有变化|类名：NotificationBasicContent;<br>方法or属性：additionalText?: string;<br>旧版本信息：|类名：NotificationBasicContent;<br>方法or属性：additionalText?: string;<br>新版本信息：?string|notificationContent.d.ts|
|type有变化|类名：NotificationLongTextContent;<br>方法or属性：longText: string;<br>旧版本信息：|类名：NotificationLongTextContent;<br>方法or属性：longText: string;<br>新版本信息：string|notificationContent.d.ts|
|type有变化|类名：NotificationLongTextContent;<br>方法or属性：briefText: string;<br>旧版本信息：|类名：NotificationLongTextContent;<br>方法or属性：briefText: string;<br>新版本信息：string|notificationContent.d.ts|
|type有变化|类名：NotificationMultiLineContent;<br>方法or属性：briefText: string;<br>旧版本信息：|类名：NotificationMultiLineContent;<br>方法or属性：briefText: string;<br>新版本信息：string|notificationContent.d.ts|
|type有变化|类名：NotificationPictureContent;<br>方法or属性：briefText: string;<br>旧版本信息：|类名：NotificationPictureContent;<br>方法or属性：briefText: string;<br>新版本信息：string|notificationContent.d.ts|
|type有变化|类名：NotificationLongTextContent;<br>方法or属性：expandedTitle: string;<br>旧版本信息：|类名：NotificationLongTextContent;<br>方法or属性：expandedTitle: string;<br>新版本信息：string|notificationContent.d.ts|
|type有变化|类名：NotificationPictureContent;<br>方法or属性：expandedTitle: string;<br>旧版本信息：|类名：NotificationPictureContent;<br>方法or属性：expandedTitle: string;<br>新版本信息：string|notificationContent.d.ts|
|type有变化|类名：NotificationMultiLineContent;<br>方法or属性：longTitle: string;<br>旧版本信息：|类名：NotificationMultiLineContent;<br>方法or属性：longTitle: string;<br>新版本信息：string|notificationContent.d.ts|
|type有变化|类名：NotificationMultiLineContent;<br>方法or属性：lines: Array\<string>;<br>旧版本信息：|类名：NotificationMultiLineContent;<br>方法or属性：lines: Array\<string>;<br>新版本信息：Array\<string>|notificationContent.d.ts|
|type有变化|类名：NotificationPictureContent;<br>方法or属性：picture: image.PixelMap;<br>旧版本信息：|类名：NotificationPictureContent;<br>方法or属性：picture: image.PixelMap;<br>新版本信息：image.PixelMap|notificationContent.d.ts|
|type有变化|类名：NotificationContent;<br>方法or属性：contentType: notification.ContentType;<br>旧版本信息：|类名：NotificationContent;<br>方法or属性：contentType: notification.ContentType;<br>新版本信息：notification.ContentType|notificationContent.d.ts|
|type有变化|类名：NotificationContent;<br>方法or属性：normal?: NotificationBasicContent;<br>旧版本信息：|类名：NotificationContent;<br>方法or属性：normal?: NotificationBasicContent;<br>新版本信息：?NotificationBasicContent|notificationContent.d.ts|
|type有变化|类名：NotificationContent;<br>方法or属性：longText?: NotificationLongTextContent;<br>旧版本信息：|类名：NotificationContent;<br>方法or属性：longText?: NotificationLongTextContent;<br>新版本信息：?NotificationLongTextContent|notificationContent.d.ts|
|type有变化|类名：NotificationContent;<br>方法or属性：multiLine?: NotificationMultiLineContent;<br>旧版本信息：|类名：NotificationContent;<br>方法or属性：multiLine?: NotificationMultiLineContent;<br>新版本信息：?NotificationMultiLineContent|notificationContent.d.ts|
|type有变化|类名：NotificationContent;<br>方法or属性：picture?: NotificationPictureContent;<br>旧版本信息：|类名：NotificationContent;<br>方法or属性：picture?: NotificationPictureContent;<br>新版本信息：?NotificationPictureContent|notificationContent.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：content: NotificationContent;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：content: NotificationContent;<br>新版本信息：NotificationContent|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：id?: number;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：id?: number;<br>新版本信息：?number|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：slotType?: notification.SlotType;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：slotType?: notification.SlotType;<br>新版本信息：?notification.SlotType|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：isOngoing?: boolean;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：isOngoing?: boolean;<br>新版本信息：?boolean|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：isUnremovable?: boolean;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：isUnremovable?: boolean;<br>新版本信息：?boolean|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：deliveryTime?: number;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：deliveryTime?: number;<br>新版本信息：?number|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：tapDismissed?: boolean;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：tapDismissed?: boolean;<br>新版本信息：?boolean|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：autoDeletedTime?: number;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：autoDeletedTime?: number;<br>新版本信息：?number|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：wantAgent?: WantAgent;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：wantAgent?: WantAgent;<br>新版本信息：?WantAgent|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：extraInfo?: { [key: string]: any };<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：extraInfo?: { [key: string]: any };<br>新版本信息：?object|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：color?: number;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：color?: number;<br>新版本信息：?number|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：colorEnabled?: boolean;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：colorEnabled?: boolean;<br>新版本信息：?boolean|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：isAlertOnce?: boolean;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：isAlertOnce?: boolean;<br>新版本信息：?boolean|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：isStopwatch?: boolean;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：isStopwatch?: boolean;<br>新版本信息：?boolean|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：isCountDown?: boolean;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：isCountDown?: boolean;<br>新版本信息：?boolean|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：isFloatingIcon?: boolean;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：isFloatingIcon?: boolean;<br>新版本信息：?boolean|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：label?: string;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：label?: string;<br>新版本信息：?string|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：badgeIconStyle?: number;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：badgeIconStyle?: number;<br>新版本信息：?number|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：showDeliveryTime?: boolean;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：showDeliveryTime?: boolean;<br>新版本信息：?boolean|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：actionButtons?: Array\<NotificationActionButton>;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：actionButtons?: Array\<NotificationActionButton>;<br>新版本信息：?Array\<NotificationActionButton>|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：smallIcon?: image.PixelMap;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：smallIcon?: image.PixelMap;<br>新版本信息：?image.PixelMap|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：largeIcon?: image.PixelMap;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：largeIcon?: image.PixelMap;<br>新版本信息：?image.PixelMap|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：groupName?: string;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：groupName?: string;<br>新版本信息：?string|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：readonly creatorBundleName?: string;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：readonly creatorBundleName?: string;<br>新版本信息：?string|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：readonly creatorUid?: number;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：readonly creatorUid?: number;<br>新版本信息：?number|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：readonly creatorPid?: number;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：readonly creatorPid?: number;<br>新版本信息：?number|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：readonly creatorUserId?: number;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：readonly creatorUserId?: number;<br>新版本信息：?number|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：classification?: string;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：classification?: string;<br>新版本信息：?string|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：readonly hashCode?: string;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：readonly hashCode?: string;<br>新版本信息：?string|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：isRemoveAllowed?: boolean;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：isRemoveAllowed?: boolean;<br>新版本信息：?boolean|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：readonly source?: number;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：readonly source?: number;<br>新版本信息：?number|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：template?: NotificationTemplate;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：template?: NotificationTemplate;<br>新版本信息：?NotificationTemplate|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：distributedOption?: DistributedOptions;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：distributedOption?: DistributedOptions;<br>新版本信息：?DistributedOptions|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：readonly deviceId?: string;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：readonly deviceId?: string;<br>新版本信息：?string|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：readonly notificationFlags?: NotificationFlags;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：readonly notificationFlags?: NotificationFlags;<br>新版本信息：?NotificationFlags|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：removalWantAgent?: WantAgent;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：removalWantAgent?: WantAgent;<br>新版本信息：?WantAgent|notificationRequest.d.ts|
|type有变化|类名：NotificationRequest;<br>方法or属性：badgeNumber?: number;<br>旧版本信息：|类名：NotificationRequest;<br>方法or属性：badgeNumber?: number;<br>新版本信息：?number|notificationRequest.d.ts|
|type有变化|类名：DistributedOptions;<br>方法or属性：isDistributed?: boolean;<br>旧版本信息：|类名：DistributedOptions;<br>方法or属性：isDistributed?: boolean;<br>新版本信息：?boolean|notificationRequest.d.ts|
|type有变化|类名：DistributedOptions;<br>方法or属性：supportDisplayDevices?: Array\<string>;<br>旧版本信息：|类名：DistributedOptions;<br>方法or属性：supportDisplayDevices?: Array\<string>;<br>新版本信息：?Array\<string>|notificationRequest.d.ts|
|type有变化|类名：DistributedOptions;<br>方法or属性：supportOperateDevices?: Array\<string>;<br>旧版本信息：|类名：DistributedOptions;<br>方法or属性：supportOperateDevices?: Array\<string>;<br>新版本信息：?Array\<string>|notificationRequest.d.ts|
|type有变化|类名：DistributedOptions;<br>方法or属性：readonly remindType?: number;<br>旧版本信息：|类名：DistributedOptions;<br>方法or属性：readonly remindType?: number;<br>新版本信息：?number|notificationRequest.d.ts|
|type有变化|类名：NotificationSlot;<br>方法or属性：type: notification.SlotType;<br>旧版本信息：|类名：NotificationSlot;<br>方法or属性：type: notification.SlotType;<br>新版本信息：notification.SlotType|notificationSlot.d.ts|
|type有变化|类名：NotificationSlot;<br>方法or属性：level?: notification.SlotLevel;<br>旧版本信息：|类名：NotificationSlot;<br>方法or属性：level?: notification.SlotLevel;<br>新版本信息：?notification.SlotLevel|notificationSlot.d.ts|
|type有变化|类名：NotificationSlot;<br>方法or属性：desc?: string;<br>旧版本信息：|类名：NotificationSlot;<br>方法or属性：desc?: string;<br>新版本信息：?string|notificationSlot.d.ts|
|type有变化|类名：NotificationSlot;<br>方法or属性：badgeFlag?: boolean;<br>旧版本信息：|类名：NotificationSlot;<br>方法or属性：badgeFlag?: boolean;<br>新版本信息：?boolean|notificationSlot.d.ts|
|type有变化|类名：NotificationSlot;<br>方法or属性：bypassDnd?: boolean;<br>旧版本信息：|类名：NotificationSlot;<br>方法or属性：bypassDnd?: boolean;<br>新版本信息：?boolean|notificationSlot.d.ts|
|type有变化|类名：NotificationSlot;<br>方法or属性：lockscreenVisibility?: number;<br>旧版本信息：|类名：NotificationSlot;<br>方法or属性：lockscreenVisibility?: number;<br>新版本信息：?number|notificationSlot.d.ts|
|type有变化|类名：NotificationSlot;<br>方法or属性：vibrationEnabled?: boolean;<br>旧版本信息：|类名：NotificationSlot;<br>方法or属性：vibrationEnabled?: boolean;<br>新版本信息：?boolean|notificationSlot.d.ts|
|type有变化|类名：NotificationSlot;<br>方法or属性：sound?: string;<br>旧版本信息：|类名：NotificationSlot;<br>方法or属性：sound?: string;<br>新版本信息：?string|notificationSlot.d.ts|
|type有变化|类名：NotificationSlot;<br>方法or属性：lightEnabled?: boolean;<br>旧版本信息：|类名：NotificationSlot;<br>方法or属性：lightEnabled?: boolean;<br>新版本信息：?boolean|notificationSlot.d.ts|
|type有变化|类名：NotificationSlot;<br>方法or属性：lightColor?: number;<br>旧版本信息：|类名：NotificationSlot;<br>方法or属性：lightColor?: number;<br>新版本信息：?number|notificationSlot.d.ts|
|type有变化|类名：NotificationSlot;<br>方法or属性：vibrationValues?: Array\<number>;<br>旧版本信息：|类名：NotificationSlot;<br>方法or属性：vibrationValues?: Array\<number>;<br>新版本信息：?Array\<number>|notificationSlot.d.ts|
|type有变化|类名：NotificationSlot;<br>方法or属性：readonly enabled?: boolean;<br>旧版本信息：|类名：NotificationSlot;<br>方法or属性：readonly enabled?: boolean;<br>新版本信息：?boolean|notificationSlot.d.ts|
|type有变化|类名：NotificationSorting;<br>方法or属性：readonly slot: NotificationSlot;<br>旧版本信息：|类名：NotificationSorting;<br>方法or属性：readonly slot: NotificationSlot;<br>新版本信息：NotificationSlot|notificationSorting.d.ts|
|type有变化|类名：NotificationSorting;<br>方法or属性：readonly hashCode: string;<br>旧版本信息：|类名：NotificationSorting;<br>方法or属性：readonly hashCode: string;<br>新版本信息：string|notificationSorting.d.ts|
|type有变化|类名：NotificationSorting;<br>方法or属性：readonly ranking: number;<br>旧版本信息：|类名：NotificationSorting;<br>方法or属性：readonly ranking: number;<br>新版本信息：number|notificationSorting.d.ts|
|type有变化|类名：NotificationSortingMap;<br>方法or属性：readonly sortings: { [key: string]: NotificationSorting };<br>旧版本信息：|类名：NotificationSortingMap;<br>方法or属性：readonly sortings: { [key: string]: NotificationSorting };<br>新版本信息：object|notificationSortingMap.d.ts|
|type有变化|类名：NotificationSortingMap;<br>方法or属性：readonly sortedHashCode: Array\<string>;<br>旧版本信息：|类名：NotificationSortingMap;<br>方法or属性：readonly sortedHashCode: Array\<string>;<br>新版本信息：Array\<string>|notificationSortingMap.d.ts|
|type有变化|类名：NotificationSubscribeInfo;<br>方法or属性：bundleNames?: Array\<string>;<br>旧版本信息：|类名：NotificationSubscribeInfo;<br>方法or属性：bundleNames?: Array\<string>;<br>新版本信息：?Array\<string>|notificationSubscribeInfo.d.ts|
|type有变化|类名：NotificationSubscribeInfo;<br>方法or属性：userId?: number;<br>旧版本信息：|类名：NotificationSubscribeInfo;<br>方法or属性：userId?: number;<br>新版本信息：?number|notificationSubscribeInfo.d.ts|
|type有变化|类名：SubscribeCallbackData;<br>方法or属性：readonly request: NotificationRequest;<br>旧版本信息：|类名：SubscribeCallbackData;<br>方法or属性：readonly request: NotificationRequest;<br>新版本信息：NotificationRequest|notificationSubscriber.d.ts|
|type有变化|类名：SubscribeCallbackData;<br>方法or属性：readonly sortingMap?: NotificationSortingMap;<br>旧版本信息：|类名：SubscribeCallbackData;<br>方法or属性：readonly sortingMap?: NotificationSortingMap;<br>新版本信息：?NotificationSortingMap|notificationSubscriber.d.ts|
|type有变化|类名：SubscribeCallbackData;<br>方法or属性：readonly reason?: number;<br>旧版本信息：|类名：SubscribeCallbackData;<br>方法or属性：readonly reason?: number;<br>新版本信息：?number|notificationSubscriber.d.ts|
|type有变化|类名：SubscribeCallbackData;<br>方法or属性：readonly sound?: string;<br>旧版本信息：|类名：SubscribeCallbackData;<br>方法or属性：readonly sound?: string;<br>新版本信息：?string|notificationSubscriber.d.ts|
|type有变化|类名：SubscribeCallbackData;<br>方法or属性：readonly vibrationValues?: Array\<number>;<br>旧版本信息：|类名：SubscribeCallbackData;<br>方法or属性：readonly vibrationValues?: Array\<number>;<br>新版本信息：?Array\<number>|notificationSubscriber.d.ts|
|type有变化|类名：EnabledNotificationCallbackData;<br>方法or属性：readonly bundle: string;<br>旧版本信息：|类名：EnabledNotificationCallbackData;<br>方法or属性：readonly bundle: string;<br>新版本信息：string|notificationSubscriber.d.ts|
|type有变化|类名：BadgeNumberCallbackData;<br>方法or属性：readonly bundle: string;<br>旧版本信息：|类名：BadgeNumberCallbackData;<br>方法or属性：readonly bundle: string;<br>新版本信息：string|notificationSubscriber.d.ts|
|type有变化|类名：EnabledNotificationCallbackData;<br>方法or属性：readonly uid: number;<br>旧版本信息：|类名：EnabledNotificationCallbackData;<br>方法or属性：readonly uid: number;<br>新版本信息：number|notificationSubscriber.d.ts|
|type有变化|类名：BadgeNumberCallbackData;<br>方法or属性：readonly uid: number;<br>旧版本信息：|类名：BadgeNumberCallbackData;<br>方法or属性：readonly uid: number;<br>新版本信息：number|notificationSubscriber.d.ts|
|type有变化|类名：EnabledNotificationCallbackData;<br>方法or属性：readonly enable: boolean;<br>旧版本信息：|类名：EnabledNotificationCallbackData;<br>方法or属性：readonly enable: boolean;<br>新版本信息：boolean|notificationSubscriber.d.ts|
|type有变化|类名：BadgeNumberCallbackData;<br>方法or属性：readonly badgeNumber: number;<br>旧版本信息：|类名：BadgeNumberCallbackData;<br>方法or属性：readonly badgeNumber: number;<br>新版本信息：number|notificationSubscriber.d.ts|
|type有变化|类名：NotificationTemplate;<br>方法or属性：name: string;<br>旧版本信息：|类名：NotificationTemplate;<br>方法or属性：name: string;<br>新版本信息：string|notificationTemplate.d.ts|
|type有变化|类名：NotificationTemplate;<br>方法or属性：data: { [key: string]: Object };<br>旧版本信息：|类名：NotificationTemplate;<br>方法or属性：data: { [key: string]: Object };<br>新版本信息：object|notificationTemplate.d.ts|
|type有变化|类名：NotificationUserInput;<br>方法or属性：inputKey: string;<br>旧版本信息：|类名：NotificationUserInput;<br>方法or属性：inputKey: string;<br>新版本信息：string|notificationUserInput.d.ts|
|函数有变化|类名：NotificationRequest;<br>方法or属性：readonly isRemoveAllowed?: boolean;|类名：NotificationRequest;<br>方法or属性：isRemoveAllowed?: boolean;|notificationRequest.d.ts|
