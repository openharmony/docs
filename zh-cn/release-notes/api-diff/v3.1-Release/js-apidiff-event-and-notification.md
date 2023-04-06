# 事件通知子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，事件通知子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| notificationUserInput | NotificationUserInput | inputKey: string; | 新增 |
| notificationTemplate | NotificationTemplate | data: {[key: string]: Object}; | 新增 |
| notificationTemplate | NotificationTemplate | name: string; | 新增 |
| notificationRequest | DistributedOptions | supportOperateDevices?: Array\<string>; | 新增 |
| notificationRequest | DistributedOptions | supportDisplayDevices?: Array\<string>; | 新增 |
| notificationRequest | DistributedOptions | isDistributed?: boolean; | 新增 |
| notificationRequest | NotificationRequest | readonly notificationFlags?: NotificationFlags; | 新增 |
| notificationRequest | NotificationRequest | distributedOption?: DistributedOptions; | 新增 |
| notificationRequest | NotificationRequest | template?: NotificationTemplate; | 新增 |
| notificationRequest | NotificationRequest | readonly creatorUserId?: number; | 新增 |
| notificationRequest | NotificationRequest | groupName?: string; | 新增 |
| notificationActionButton | NotificationActionButton | userInput?: NotificationUserInput; | 新增 |
| ohos.notification | notification | isDistributedEnabled(callback: AsyncCallback\<boolean>): void;<br>isDistributedEnabled(): Promise\<boolean>; | 新增 |
| ohos.notification | notification | requestEnableNotification(callback: AsyncCallback\<void>): void;<br>requestEnableNotification(): Promise\<void>; | 新增 |
| ohos.notification | notification | isSupportTemplate(templateName: string, callback: AsyncCallback\<boolean>): void;<br>isSupportTemplate(templateName: string): Promise\<boolean>; | 新增 |
| ohos.notification | notification | cancelGroup(groupName: string, callback: AsyncCallback\<void>): void;<br>cancelGroup(groupName: string): Promise\<void>; | 新增 |
| ohos.events.emitter | EventPriority | IDLE | 新增 |
| ohos.events.emitter | EventPriority | LOW | 新增 |
| ohos.events.emitter | EventPriority | HIGH | 新增 |
| ohos.events.emitter | EventPriority | IMMEDIATE = 0 | 新增 |
| ohos.events.emitter | InnerEvent | priority?: EventPriority; | 新增 |
| ohos.events.emitter | InnerEvent | eventId: number; | 新增 |
| ohos.events.emitter | EventData | data?: {[key: string]: any}; | 新增 |
| ohos.events.emitter | emitter | emit(event: InnerEvent, data?: EventData): void; | 新增 |
| ohos.events.emitter | emitter | off(eventId: number): void; | 新增 |
| ohos.events.emitter | emitter | once(event: InnerEvent, callback: Callback\<EventData>): void; | 新增 |
| ohos.events.emitter | emitter | on(event: InnerEvent, callback: Callback\<EventData>): void; | 新增 |
| ohos.commonEvent | Support | COMMON_EVENT_SPLIT_SCREEN = "common.event.SPLIT_SCREEN" | 新增 |
| ohos.commonEvent | Support | COMMON_EVENT_THERMAL_LEVEL_CHANGED = "usual.event.THERMAL_LEVEL_CHANGED" | 新增 |
