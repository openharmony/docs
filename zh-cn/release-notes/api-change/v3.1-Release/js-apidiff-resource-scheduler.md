# 资源调度子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，资源调度子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.reminderAgent | LocalDateTime | second?: number; | 新增 |
| ohos.reminderAgent | LocalDateTime | minute: number; | 新增 |
| ohos.reminderAgent | LocalDateTime | hour: number; | 新增 |
| ohos.reminderAgent | LocalDateTime | day: number; | 新增 |
| ohos.reminderAgent | LocalDateTime | month: number; | 新增 |
| ohos.reminderAgent | LocalDateTime | year: number; | 新增 |
| ohos.reminderAgent | ReminderRequestTimer | triggerTimeInSeconds: number; | 新增 |
| ohos.reminderAgent | ReminderRequestAlarm | daysOfWeek?: Array\<number>; | 新增 |
| ohos.reminderAgent | ReminderRequestAlarm | minute: number; | 新增 |
| ohos.reminderAgent | ReminderRequestAlarm | hour: number; | 新增 |
| ohos.reminderAgent | ReminderRequestCalendar | repeatDays?: Array\<number>; | 新增 |
| ohos.reminderAgent | ReminderRequestCalendar | repeatMonths?: Array\<number>; | 新增 |
| ohos.reminderAgent | ReminderRequestCalendar | dateTime: LocalDateTime; | 新增 |
| ohos.reminderAgent | ReminderRequest | slotType?: notification.SlotType; | 新增 |
| ohos.reminderAgent | ReminderRequest | notificationId?: number; | 新增 |
| ohos.reminderAgent | ReminderRequest | snoozeContent?: string; | 新增 |
| ohos.reminderAgent | ReminderRequest | expiredContent?: string; | 新增 |
| ohos.reminderAgent | ReminderRequest | content?: string; | 新增 |
| ohos.reminderAgent | ReminderRequest | title?: string; | 新增 |
| ohos.reminderAgent | ReminderRequest | timeInterval?: number; | 新增 |
| ohos.reminderAgent | ReminderRequest | snoozeTimes?: number; | 新增 |
| ohos.reminderAgent | ReminderRequest | ringDuration?: number; | 新增 |
| ohos.reminderAgent | ReminderRequest | maxScreenWantAgent?: MaxScreenWantAgent; | 新增 |
| ohos.reminderAgent | ReminderRequest | wantAgent?: WantAgent; | 新增 |
| ohos.reminderAgent | ReminderRequest | actionButton?: [ActionButton?, ActionButton?]; | 新增 |
| ohos.reminderAgent | ReminderRequest | reminderType: ReminderType; | 新增 |
| ohos.reminderAgent | MaxScreenWantAgent | abilityName: string; | 新增 |
| ohos.reminderAgent | MaxScreenWantAgent | pkgName: string; | 新增 |
| ohos.reminderAgent | WantAgent | abilityName: string; | 新增 |
| ohos.reminderAgent | WantAgent | pkgName: string; | 新增 |
| ohos.reminderAgent | ActionButton | type: ActionButtonType; | 新增 |
| ohos.reminderAgent | ActionButton | title: string; | 新增 |
| ohos.reminderAgent | ReminderType | REMINDER_TYPE_ALARM = 2 | 新增 |
| ohos.reminderAgent | ReminderType | REMINDER_TYPE_CALENDAR = 1 | 新增 |
| ohos.reminderAgent | ReminderType | REMINDER_TYPE_TIMER = 0 | 新增 |
| ohos.reminderAgent | ActionButtonType | ACTION_BUTTON_TYPE_SNOOZE = 1 | 新增 |
| ohos.reminderAgent | ActionButtonType | ACTION_BUTTON_TYPE_CLOSE = 0 | 新增 |
| ohos.reminderAgent | reminderAgent | removeNotificationSlot(slotType: notification.SlotType, callback: AsyncCallback\<void>): void;<br>removeNotificationSlot(slotType: notification.SlotType): Promise\<void>; | 新增 |
| ohos.reminderAgent | reminderAgent | addNotificationSlot(slot: NotificationSlot, callback: AsyncCallback\<void>): void;<br>addNotificationSlot(slot: NotificationSlot): Promise\<void>; | 新增 |
| ohos.reminderAgent | reminderAgent | cancelAllReminders(callback: AsyncCallback\<void>): void;<br>cancelAllReminders(): Promise\<void>; | 新增 |
| ohos.reminderAgent | reminderAgent | getValidReminders(callback: AsyncCallback\<Array\<ReminderRequest>>): void;<br>getValidReminders(): Promise\<Array\<ReminderRequest>>; | 新增 |
| ohos.reminderAgent | reminderAgent | cancelReminder(reminderId: number, callback: AsyncCallback\<void>): void;<br>cancelReminder(reminderId: number): Promise\<void>; | 新增 |
| ohos.reminderAgent | reminderAgent | publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback\<number>): void;<br>publishReminder(reminderReq: ReminderRequest): Promise\<number>; | 新增 |
| ohos.bundleState | bundleState | queryCurrentBundleActiveStates(begin: number, end: number, callback: AsyncCallback\<Array\<BundleActiveState>>): void;<br>queryCurrentBundleActiveStates(begin: number, end: number): Promise\<Array\<BundleActiveState>>; | 新增 |
| ohos.bundleState | IntervalType | BY_ANNUALLY = 4 | 新增 |
| ohos.bundleState | IntervalType | BY_MONTHLY = 3 | 新增 |
| ohos.bundleState | IntervalType | BY_WEEKLY = 2 | 新增 |
| ohos.bundleState | IntervalType | BY_DAILY = 1 | 新增 |
| ohos.bundleState | IntervalType | BY_OPTIMIZED = 0 | 新增 |
| ohos.bundleState | BundleActiveInfoResponse | [key: string]: BundleStateInfo; | 新增 |
| ohos.bundleState | bundleState | queryAppUsagePriorityGroup(callback: AsyncCallback\<number>): void;<br>queryAppUsagePriorityGroup(): Promise\<number>; | 新增 |
| ohos.bundleState | bundleState | isIdleState(bundleName: string, callback: AsyncCallback\<boolean>): void;<br>isIdleState(bundleName: string): Promise\<boolean>; | 新增 |
| ohos.bundleState | BundleActiveState | stateType?: number; | 新增 |
| ohos.bundleState | BundleActiveState | stateOccurredTime?: number; | 新增 |
| ohos.bundleState | BundleActiveState | nameOfClass?: string; | 新增 |
| ohos.bundleState | BundleActiveState | indexOfLink?: string; | 新增 |
| ohos.bundleState | BundleActiveState | bundleName?: string; | 新增 |
| ohos.bundleState | BundleActiveState | appUsagePriorityGroup?: number; | 新增 |
| ohos.bundleState | BundleStateInfo | merge(toMerge: BundleStateInfo): void; | 新增 |
| ohos.bundleState | BundleStateInfo | infosEndTime?: number; | 新增 |
| ohos.bundleState | BundleStateInfo | infosBeginTime?: number; | 新增 |
| ohos.bundleState | BundleStateInfo | fgAbilityPrevAccessTime?: number; | 新增 |
| ohos.bundleState | BundleStateInfo | fgAbilityAccessTotalTime?: number; | 新增 |
| ohos.bundleState | BundleStateInfo | bundleName?: string; | 新增 |
| ohos.bundleState | BundleStateInfo | abilitySeenTotalTime?: number; | 新增 |
| ohos.bundleState | BundleStateInfo | abilityPrevSeenTime?: number; | 新增 |
| ohos.bundleState | BundleStateInfo | abilityPrevAccessTime?: number; | 新增 |
| ohos.bundleState | BundleStateInfo | abilityInFgTotalTime?: number; | 新增 |
| ohos.bundleState | BundleStateInfo | id: number; | 新增 |
| ohos.backgroundTaskManager | BackgroundMode | TASK_KEEPING = 9 | 新增 |
| ohos.backgroundTaskManager | BackgroundMode | MULTI_DEVICE_CONNECTION = 6 | 新增 |
| ohos.backgroundTaskManager | BackgroundMode | BLUETOOTH_INTERACTION = 5 | 新增 |
| ohos.backgroundTaskManager | BackgroundMode | LOCATION = 4 | 新增 |
| ohos.backgroundTaskManager | BackgroundMode | AUDIO_RECORDING = 3 | 新增 |
| ohos.backgroundTaskManager | BackgroundMode | AUDIO_PLAYBACK = 2 | 新增 |
| ohos.backgroundTaskManager | BackgroundMode | DATA_TRANSFER = 1 | 新增 |
| ohos.backgroundTaskManager | backgroundTaskManager | stopBackgroundRunning(context: Context, callback: AsyncCallback\<void>): void;<br>stopBackgroundRunning(context: Context): Promise\<void>; | 新增 |
| ohos.backgroundTaskManager | backgroundTaskManager | startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback\<void>): void;<br>startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise\<void>; | 新增 |
| ohos.backgroundTaskManager | backgroundTaskManager | requestSuspendDelay(reason: string, callback: Callback\<void>): DelaySuspendInfo; | 新增 |
| ohos.backgroundTaskManager | backgroundTaskManager | getRemainingDelayTime(requestId: number, callback: AsyncCallback\<number>): void;<br>getRemainingDelayTime(requestId: number): Promise\<number>; | 新增 |
| ohos.backgroundTaskManager | backgroundTaskManager | cancelSuspendDelay(requestId: number): void; | 新增 |
| ohos.backgroundTaskManager | DelaySuspendInfo | actualDelayTime: number; | 新增 |
| ohos.backgroundTaskManager | DelaySuspendInfo | requestId: number; | 新增 |
