| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|API跨平台权限变更|类名：commonEventManager；<br>API声明：function createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback\<CommonEventSubscriber>): void;<br>差异内容：NA|类名：commonEventManager；<br>API声明：function createSubscriber(subscribeInfo: CommonEventSubscribeInfo, callback: AsyncCallback\<CommonEventSubscriber>): void;<br>差异内容：crossplatform|api/@ohos.commonEventManager.d.ts|
|API跨平台权限变更|类名：commonEventManager；<br>API声明：function createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise\<CommonEventSubscriber>;<br>差异内容：NA|类名：commonEventManager；<br>API声明：function createSubscriber(subscribeInfo: CommonEventSubscribeInfo): Promise\<CommonEventSubscriber>;<br>差异内容：crossplatform|api/@ohos.commonEventManager.d.ts|
|API跨平台权限变更|类名：commonEventManager；<br>API声明：function subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback\<CommonEventData>): void;<br>差异内容：NA|类名：commonEventManager；<br>API声明：function subscribe(subscriber: CommonEventSubscriber, callback: AsyncCallback\<CommonEventData>): void;<br>差异内容：crossplatform|api/@ohos.commonEventManager.d.ts|
|API跨平台权限变更|类名：commonEventManager；<br>API声明：function unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback\<void>): void;<br>差异内容：NA|类名：commonEventManager；<br>API声明：function unsubscribe(subscriber: CommonEventSubscriber, callback?: AsyncCallback\<void>): void;<br>差异内容：crossplatform|api/@ohos.commonEventManager.d.ts|
|API跨平台权限变更|类名：global；<br>API声明： export interface CommonEventData<br>差异内容：NA|类名：global；<br>API声明： export interface CommonEventData<br>差异内容：crossplatform|api/commonEvent/commonEventData.d.ts|
|API跨平台权限变更|类名：CommonEventData；<br>API声明：event: string;<br>差异内容：NA|类名：CommonEventData；<br>API声明：event: string;<br>差异内容：crossplatform|api/commonEvent/commonEventData.d.ts|
|API跨平台权限变更|类名：global；<br>API声明： export interface CommonEventSubscribeInfo<br>差异内容：NA|类名：global；<br>API声明： export interface CommonEventSubscribeInfo<br>差异内容：crossplatform|api/commonEvent/commonEventSubscribeInfo.d.ts|
|API跨平台权限变更|类名：CommonEventSubscribeInfo；<br>API声明：events: Array\<string>;<br>差异内容：NA|类名：CommonEventSubscribeInfo；<br>API声明：events: Array\<string>;<br>差异内容：crossplatform|api/commonEvent/commonEventSubscribeInfo.d.ts|
|API跨平台权限变更|类名：CommonEventSubscriber；<br>API声明：getSubscribeInfo(callback: AsyncCallback\<CommonEventSubscribeInfo>): void;<br>差异内容：NA|类名：CommonEventSubscriber；<br>API声明：getSubscribeInfo(callback: AsyncCallback\<CommonEventSubscribeInfo>): void;<br>差异内容：crossplatform|api/commonEvent/commonEventSubscriber.d.ts|
|API跨平台权限变更|类名：CommonEventSubscriber；<br>API声明：getSubscribeInfo(): Promise\<CommonEventSubscribeInfo>;<br>差异内容：NA|类名：CommonEventSubscriber；<br>API声明：getSubscribeInfo(): Promise\<CommonEventSubscribeInfo>;<br>差异内容：crossplatform|api/commonEvent/commonEventSubscriber.d.ts|
|syscap变更|类名：ReminderRequestTimer；<br>API声明：triggerTimeInSeconds: number;<br>差异内容：NA|类名：ReminderRequestTimer；<br>API声明：triggerTimeInSeconds: number;<br>差异内容：SystemCapability.Notification.ReminderAgent|api/@ohos.reminderAgent.d.ts|
|syscap变更|类名：reminderAgent；<br>API声明： interface LocalDateTime<br>差异内容：NA|类名：reminderAgent；<br>API声明： interface LocalDateTime<br>差异内容：SystemCapability.Notification.ReminderAgent|api/@ohos.reminderAgent.d.ts|
|syscap变更|类名：reminderAgentManager；<br>API声明： interface ReminderRequestCalendar<br>差异内容：NA|类名：reminderAgentManager；<br>API声明： interface ReminderRequestCalendar<br>差异内容：SystemCapability.Notification.ReminderAgent|api/@ohos.reminderAgentManager.d.ts|
|syscap变更|类名：ReminderRequestTimer；<br>API声明：triggerTimeInSeconds: number;<br>差异内容：NA|类名：ReminderRequestTimer；<br>API声明：triggerTimeInSeconds: number;<br>差异内容：SystemCapability.Notification.ReminderAgent|api/@ohos.reminderAgentManager.d.ts|
|syscap变更|类名：reminderAgentManager；<br>API声明： interface LocalDateTime<br>差异内容：NA|类名：reminderAgentManager；<br>API声明： interface LocalDateTime<br>差异内容：SystemCapability.Notification.ReminderAgent|api/@ohos.reminderAgentManager.d.ts|
|API废弃版本变更|类名：ReminderRequestTimer；<br>API声明：triggerTimeInSeconds: number;<br>差异内容：NA|类名：ReminderRequestTimer；<br>API声明：triggerTimeInSeconds: number;<br>差异内容：9|api/@ohos.reminderAgent.d.ts|
|API废弃版本变更|类名：reminderAgent；<br>API声明： interface LocalDateTime<br>差异内容：NA|类名：reminderAgent；<br>API声明： interface LocalDateTime<br>差异内容：9|api/@ohos.reminderAgent.d.ts|
|API废弃版本变更|类名：NotificationContent；<br>API声明：contentType: notification.ContentType;<br>差异内容：NA|类名：NotificationContent；<br>API声明：contentType?: notification.ContentType;<br>差异内容：11|api/notification/notificationContent.d.ts|
|API废弃版本变更|类名：NotificationRequest；<br>API声明：slotType?: notification.SlotType;<br>差异内容：NA|类名：NotificationRequest；<br>API声明：slotType?: notification.SlotType;<br>差异内容：11|api/notification/notificationRequest.d.ts|
|API废弃版本变更|类名：NotificationSlot；<br>API声明：type: notification.SlotType;<br>差异内容：NA|类名：NotificationSlot；<br>API声明：type?: notification.SlotType;<br>差异内容：11|api/notification/notificationSlot.d.ts|
|错误码变更|类名：notificationManager；<br>API声明：function publish(request: NotificationRequest, callback: AsyncCallback\<void>): void;<br>差异内容：1600001,1600002,1600003,1600004,1600005,1600009,1600012,401|类名：notificationManager；<br>API声明：function publish(request: NotificationRequest, callback: AsyncCallback\<void>): void;<br>差异内容：1600001,1600002,1600003,1600004,1600005,1600007,1600009,1600012,1600014,1600015,1600016,2300007,401|api/@ohos.notificationManager.d.ts|
|错误码变更|类名：notificationManager；<br>API声明：function publish(request: NotificationRequest): Promise\<void>;<br>差异内容：1600001,1600002,1600003,1600004,1600005,1600009,1600012,401|类名：notificationManager；<br>API声明：function publish(request: NotificationRequest): Promise\<void>;<br>差异内容：1600001,1600002,1600003,1600004,1600005,1600007,1600009,1600012,1600014,1600015,1600016,2300007,401|api/@ohos.notificationManager.d.ts|
|错误码变更|类名：notificationManager；<br>API声明：function requestEnableNotification(callback: AsyncCallback\<void>): void;<br>差异内容：1600001,1600002,1600003,401|类名：notificationManager；<br>API声明：function requestEnableNotification(callback: AsyncCallback\<void>): void;<br>差异内容：1600001,1600002,1600003,1600004,1600013,401|api/@ohos.notificationManager.d.ts|
|错误码变更|类名：notificationManager；<br>API声明：function requestEnableNotification(context: UIAbilityContext, callback: AsyncCallback\<void>): void;<br>差异内容：1600001,1600002,1600003,401|类名：notificationManager；<br>API声明：function requestEnableNotification(context: UIAbilityContext, callback: AsyncCallback\<void>): void;<br>差异内容：1600001,1600002,1600003,1600004,1600013,401|api/@ohos.notificationManager.d.ts|
|错误码变更|类名：notificationManager；<br>API声明：function requestEnableNotification(): Promise\<void>;<br>差异内容：1600001,1600002,1600003,401|类名：notificationManager；<br>API声明：function requestEnableNotification(): Promise\<void>;<br>差异内容：1600001,1600002,1600003,1600004,1600013,401|api/@ohos.notificationManager.d.ts|
|错误码变更|类名：notificationManager；<br>API声明：function requestEnableNotification(context: UIAbilityContext): Promise\<void>;<br>差异内容：1600001,1600002,1600003,401|类名：notificationManager；<br>API声明：function requestEnableNotification(context: UIAbilityContext): Promise\<void>;<br>差异内容：1600001,1600002,1600003,1600004,1600013,401|api/@ohos.notificationManager.d.ts|
|属性变更|类名：NotificationContent；<br>API声明：contentType: notification.ContentType;<br>差异内容：contentType: notification.ContentType;|类名：NotificationContent；<br>API声明：contentType?: notification.ContentType;<br>差异内容：contentType?: notification.ContentType;|api/notification/notificationContent.d.ts|
|属性变更|类名：NotificationSlot；<br>API声明：type: notification.SlotType;<br>差异内容：type: notification.SlotType;|类名：NotificationSlot；<br>API声明：type?: notification.SlotType;<br>差异内容：type?: notification.SlotType;|api/notification/notificationSlot.d.ts|
|属性变更|类名：NotificationTemplate；<br>API声明：data: {<br>        [key: string]: Object;<br>    };<br>差异内容：{<br>        [key: string]: Object;<br>    }|类名：NotificationTemplate；<br>API声明：data: Record\<string, Object>;<br>差异内容：Record\<string, Object>|api/notification/notificationTemplate.d.ts|
|新增API|NA|类名：emitter；<br>API声明：function on(eventId: string, callback: Callback\<EventData>): void;<br>差异内容：function on(eventId: string, callback: Callback\<EventData>): void;|api/@ohos.events.emitter.d.ts|
|新增API|NA|类名：emitter；<br>API声明：function once(eventId: string, callback: Callback\<EventData>): void;<br>差异内容：function once(eventId: string, callback: Callback\<EventData>): void;|api/@ohos.events.emitter.d.ts|
|新增API|NA|类名：emitter；<br>API声明：function off(eventId: string): void;<br>差异内容：function off(eventId: string): void;|api/@ohos.events.emitter.d.ts|
|新增API|NA|类名：emitter；<br>API声明：function off(eventId: string, callback: Callback\<EventData>): void;<br>差异内容：function off(eventId: string, callback: Callback\<EventData>): void;|api/@ohos.events.emitter.d.ts|
|新增API|NA|类名：emitter；<br>API声明：function emit(eventId: string, data?: EventData): void;<br>差异内容：function emit(eventId: string, data?: EventData): void;|api/@ohos.events.emitter.d.ts|
|新增API|NA|类名：emitter；<br>API声明：function emit(eventId: string, options: Options, data?: EventData): void;<br>差异内容：function emit(eventId: string, options: Options, data?: EventData): void;|api/@ohos.events.emitter.d.ts|
|新增API|NA|类名：emitter；<br>API声明：function getListenerCount(eventId: number \| string): number;<br>差异内容：function getListenerCount(eventId: number \| string): number;|api/@ohos.events.emitter.d.ts|
|新增API|NA|类名：emitter；<br>API声明： export interface Options<br>差异内容： export interface Options|api/@ohos.events.emitter.d.ts|
|新增API|NA|类名：Options；<br>API声明：priority?: EventPriority;<br>差异内容：priority?: EventPriority;|api/@ohos.events.emitter.d.ts|
|新增API|NA|类名：notificationManager；<br>API声明：function isNotificationEnabled(callback: AsyncCallback\<boolean>): void;<br>差异内容：function isNotificationEnabled(callback: AsyncCallback\<boolean>): void;|api/@ohos.notificationManager.d.ts|
|新增API|NA|类名：notificationManager；<br>API声明：function isNotificationEnabled(): Promise\<boolean>;<br>差异内容：function isNotificationEnabled(): Promise\<boolean>;|api/@ohos.notificationManager.d.ts|
|新增API|NA|类名：SlotType；<br>API声明：LIVE_VIEW = 4<br>差异内容：LIVE_VIEW = 4|api/@ohos.notificationManager.d.ts|
|新增API|NA|类名：SlotType；<br>API声明：CUSTOMER_SERVICE = 5<br>差异内容：CUSTOMER_SERVICE = 5|api/@ohos.notificationManager.d.ts|
|新增API|NA|类名：ContentType；<br>API声明：NOTIFICATION_CONTENT_SYSTEM_LIVE_VIEW<br>差异内容：NOTIFICATION_CONTENT_SYSTEM_LIVE_VIEW|api/@ohos.notificationManager.d.ts|
|新增API|NA|类名：ContentType；<br>API声明：NOTIFICATION_CONTENT_LIVE_VIEW<br>差异内容：NOTIFICATION_CONTENT_LIVE_VIEW|api/@ohos.notificationManager.d.ts|
|新增API|NA|类名：notificationManager；<br>API声明：export type NotificationSystemLiveViewContent = _NotificationSystemLiveViewContent;<br>差异内容：export type NotificationSystemLiveViewContent = _NotificationSystemLiveViewContent;|api/@ohos.notificationManager.d.ts|
|新增API|NA|类名：notificationManager；<br>API声明：export type NotificationCapsule = _NotificationCapsule;<br>差异内容：export type NotificationCapsule = _NotificationCapsule;|api/@ohos.notificationManager.d.ts|
|新增API|NA|类名：notificationManager；<br>API声明：export type NotificationButton = _NotificationButton;<br>差异内容：export type NotificationButton = _NotificationButton;|api/@ohos.notificationManager.d.ts|
|新增API|NA|类名：notificationManager；<br>API声明：export type NotificationTime = _NotificationTime;<br>差异内容：export type NotificationTime = _NotificationTime;|api/@ohos.notificationManager.d.ts|
|新增API|NA|类名：notificationManager；<br>API声明：export type NotificationProgress = _NotificationProgress;<br>差异内容：export type NotificationProgress = _NotificationProgress;|api/@ohos.notificationManager.d.ts|
|新增API|NA|类名：ActionButton；<br>API声明：titleResource?: string;<br>差异内容：titleResource?: string;|api/@ohos.reminderAgentManager.d.ts|
|新增API|NA|类名：ReminderRequest；<br>API声明：groupId?: string;<br>差异内容：groupId?: string;|api/@ohos.reminderAgentManager.d.ts|
|新增API|NA|类名：ReminderRequest；<br>API声明：snoozeSlotType?: notification.SlotType;<br>差异内容：snoozeSlotType?: notification.SlotType;|api/@ohos.reminderAgentManager.d.ts|
|新增API|NA|类名：ReminderRequest；<br>API声明：customRingUri?: string;<br>差异内容：customRingUri?: string;|api/@ohos.reminderAgentManager.d.ts|
|新增API|NA|类名：ReminderRequestCalendar；<br>API声明：daysOfWeek?: Array\<number>;<br>差异内容：daysOfWeek?: Array\<number>;|api/@ohos.reminderAgentManager.d.ts|
|新增API|NA|类名：CommonEventSubscribeInfo；<br>API声明：publisherBundleName?: string;<br>差异内容：publisherBundleName?: string;|api/commonEvent/commonEventSubscribeInfo.d.ts|
|新增API|NA|类名：global；<br>API声明： export interface NotificationSystemLiveViewContent<br>差异内容： export interface NotificationSystemLiveViewContent|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationSystemLiveViewContent；<br>API声明：typeCode: number;<br>差异内容：typeCode: number;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationSystemLiveViewContent；<br>API声明：capsule?: NotificationCapsule;<br>差异内容：capsule?: NotificationCapsule;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationSystemLiveViewContent；<br>API声明：button?: NotificationButton;<br>差异内容：button?: NotificationButton;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationSystemLiveViewContent；<br>API声明：time?: NotificationTime;<br>差异内容：time?: NotificationTime;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationSystemLiveViewContent；<br>API声明：progress?: NotificationProgress;<br>差异内容：progress?: NotificationProgress;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：global；<br>API声明： export interface NotificationCapsule<br>差异内容： export interface NotificationCapsule|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationCapsule；<br>API声明：title?: string;<br>差异内容：title?: string;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationCapsule；<br>API声明：icon?: image.PixelMap;<br>差异内容：icon?: image.PixelMap;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationCapsule；<br>API声明：backgroundColor?: string;<br>差异内容：backgroundColor?: string;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：global；<br>API声明： export interface NotificationButton<br>差异内容： export interface NotificationButton|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationButton；<br>API声明：names?: Array\<string>;<br>差异内容：names?: Array\<string>;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationButton；<br>API声明：icons?: Array\<image.PixelMap>;<br>差异内容：icons?: Array\<image.PixelMap>;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：global；<br>API声明： export interface NotificationTime<br>差异内容： export interface NotificationTime|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationTime；<br>API声明：initialTime?: number;<br>差异内容：initialTime?: number;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationTime；<br>API声明：isCountDown?: boolean;<br>差异内容：isCountDown?: boolean;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationTime；<br>API声明：isPaused?: boolean;<br>差异内容：isPaused?: boolean;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationTime；<br>API声明：isInTitle?: boolean;<br>差异内容：isInTitle?: boolean;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：global；<br>API声明： export interface NotificationProgress<br>差异内容： export interface NotificationProgress|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationProgress；<br>API声明：maxValue?: number;<br>差异内容：maxValue?: number;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationProgress；<br>API声明：currentValue?: number;<br>差异内容：currentValue?: number;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationProgress；<br>API声明：isPercentage?: boolean;<br>差异内容：isPercentage?: boolean;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationContent；<br>API声明：notificationContentType?: notificationManager.ContentType;<br>差异内容：notificationContentType?: notificationManager.ContentType;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：NotificationContent；<br>API声明：systemLiveView?: NotificationSystemLiveViewContent;<br>差异内容：systemLiveView?: NotificationSystemLiveViewContent;|api/notification/notificationContent.d.ts|
|新增API|NA|类名：global；<br>API声明： export enum NotificationFlagStatus<br>差异内容： export enum NotificationFlagStatus|api/notification/notificationFlags.d.ts|
|新增API|NA|类名：NotificationFlagStatus；<br>API声明：TYPE_NONE = 0<br>差异内容：TYPE_NONE = 0|api/notification/notificationFlags.d.ts|
|新增API|NA|类名：NotificationFlagStatus；<br>API声明：TYPE_OPEN = 1<br>差异内容：TYPE_OPEN = 1|api/notification/notificationFlags.d.ts|
|新增API|NA|类名：NotificationFlagStatus；<br>API声明：TYPE_CLOSE = 2<br>差异内容：TYPE_CLOSE = 2|api/notification/notificationFlags.d.ts|
|新增API|NA|类名：NotificationRequest；<br>API声明：notificationSlotType?: notificationManager.SlotType;<br>差异内容：notificationSlotType?: notificationManager.SlotType;|api/notification/notificationRequest.d.ts|
|新增API|NA|类名：NotificationSlot；<br>API声明：notificationType?: notificationManager.SlotType;<br>差异内容：notificationType?: notificationManager.SlotType;|api/notification/notificationSlot.d.ts|
|起始版本有变化|类名：ReminderRequestTimer；<br>API声明：triggerTimeInSeconds: number;<br>差异内容：NA|类名：ReminderRequestTimer；<br>API声明：triggerTimeInSeconds: number;<br>差异内容：7|api/@ohos.reminderAgent.d.ts|
|起始版本有变化|类名：reminderAgent；<br>API声明： interface LocalDateTime<br>差异内容：NA|类名：reminderAgent；<br>API声明： interface LocalDateTime<br>差异内容：7|api/@ohos.reminderAgent.d.ts|
|起始版本有变化|类名：reminderAgentManager；<br>API声明： interface ReminderRequestCalendar<br>差异内容：NA|类名：reminderAgentManager；<br>API声明： interface ReminderRequestCalendar<br>差异内容：9|api/@ohos.reminderAgentManager.d.ts|
|起始版本有变化|类名：ReminderRequestTimer；<br>API声明：triggerTimeInSeconds: number;<br>差异内容：NA|类名：ReminderRequestTimer；<br>API声明：triggerTimeInSeconds: number;<br>差异内容：9|api/@ohos.reminderAgentManager.d.ts|
|起始版本有变化|类名：reminderAgentManager；<br>API声明： interface LocalDateTime<br>差异内容：NA|类名：reminderAgentManager；<br>API声明： interface LocalDateTime<br>差异内容：9|api/@ohos.reminderAgentManager.d.ts|
|kit变更|NA|BasicServicesKit|api/@ohos.commonEventManager.d.ts|
|kit变更|NA|BasicServicesKit|api/@ohos.events.emitter.d.ts|
|kit变更|NA|NotificationKit|api/@ohos.notificationManager.d.ts|
|kit变更|NA|BackgroundTasksKit|api/@ohos.reminderAgent.d.ts|
|kit变更|NA|BackgroundTasksKit|api/@ohos.reminderAgentManager.d.ts|
|kit变更|NA|NotificationKit|api/@system.notification.d.ts|
