# JS API Changes of the Distributed Scheduler Subsystem

The table below lists the APIs changes of the distributed scheduler subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.reminderAgent | LocalDateTime | second?: number; | Added|
| ohos.reminderAgent | LocalDateTime | minute: number; | Added|
| ohos.reminderAgent | LocalDateTime | hour: number; | Added|
| ohos.reminderAgent | LocalDateTime | day: number; | Added|
| ohos.reminderAgent | LocalDateTime | month: number; | Added|
| ohos.reminderAgent | LocalDateTime | year: number; | Added|
| ohos.reminderAgent | ReminderRequestTimer | triggerTimeInSeconds: number; | Added|
| ohos.reminderAgent | ReminderRequestAlarm | daysOfWeek?: Array\<number>; | Added|
| ohos.reminderAgent | ReminderRequestAlarm | minute: number; | Added|
| ohos.reminderAgent | ReminderRequestAlarm | hour: number; | Added|
| ohos.reminderAgent | ReminderRequestCalendar | repeatDays?: Array\<number>; | Added|
| ohos.reminderAgent | ReminderRequestCalendar | repeatMonths?: Array\<number>; | Added|
| ohos.reminderAgent | ReminderRequestCalendar | dateTime: LocalDateTime; | Added|
| ohos.reminderAgent | ReminderRequest | slotType?: notification.SlotType; | Added|
| ohos.reminderAgent | ReminderRequest | notificationId?: number; | Added|
| ohos.reminderAgent | ReminderRequest | snoozeContent?: string; | Added|
| ohos.reminderAgent | ReminderRequest | expiredContent?: string; | Added|
| ohos.reminderAgent | ReminderRequest | content?: string; | Added|
| ohos.reminderAgent | ReminderRequest | title?: string; | Added|
| ohos.reminderAgent | ReminderRequest | timeInterval?: number; | Added|
| ohos.reminderAgent | ReminderRequest | snoozeTimes?: number; | Added|
| ohos.reminderAgent | ReminderRequest | ringDuration?: number; | Added|
| ohos.reminderAgent | ReminderRequest | maxScreenWantAgent?: MaxScreenWantAgent; | Added|
| ohos.reminderAgent | ReminderRequest | wantAgent?: WantAgent; | Added|
| ohos.reminderAgent | ReminderRequest | actionButton?: [ActionButton?, ActionButton?]; | Added|
| ohos.reminderAgent | ReminderRequest | reminderType: ReminderType; | Added|
| ohos.reminderAgent | MaxScreenWantAgent | abilityName: string; | Added|
| ohos.reminderAgent | MaxScreenWantAgent | pkgName: string; | Added|
| ohos.reminderAgent | WantAgent | abilityName: string; | Added|
| ohos.reminderAgent | WantAgent | pkgName: string; | Added|
| ohos.reminderAgent | ActionButton | type: ActionButtonType; | Added|
| ohos.reminderAgent | ActionButton | title: string; | Added|
| ohos.reminderAgent | ReminderType | REMINDER_TYPE_ALARM = 2 | Added|
| ohos.reminderAgent | ReminderType | REMINDER_TYPE_CALENDAR = 1 | Added|
| ohos.reminderAgent | ReminderType | REMINDER_TYPE_TIMER = 0 | Added|
| ohos.reminderAgent | ActionButtonType | ACTION_BUTTON_TYPE_SNOOZE = 1 | Added|
| ohos.reminderAgent | ActionButtonType | ACTION_BUTTON_TYPE_CLOSE = 0 | Added|
| ohos.reminderAgent | reminderAgent | removeNotificationSlot(slotType: notification.SlotType, callback: AsyncCallback\<void>): void;<br>removeNotificationSlot(slotType: notification.SlotType): Promise\<void>; | Added|
| ohos.reminderAgent | reminderAgent | addNotificationSlot(slot: NotificationSlot, callback: AsyncCallback\<void>): void;<br>addNotificationSlot(slot: NotificationSlot): Promise\<void>; | Added|
| ohos.reminderAgent | reminderAgent | cancelAllReminders(callback: AsyncCallback\<void>): void;<br>cancelAllReminders(): Promise\<void>; | Added|
| ohos.reminderAgent | reminderAgent | getValidReminders(callback: AsyncCallback\<Array\<ReminderRequest>>): void;<br>getValidReminders(): Promise\<Array\<ReminderRequest>>; | Added|
| ohos.reminderAgent | reminderAgent | cancelReminder(reminderId: number, callback: AsyncCallback\<void>): void;<br>cancelReminder(reminderId: number): Promise\<void>; | Added|
| ohos.reminderAgent | reminderAgent | publishReminder(reminderReq: ReminderRequest, callback: AsyncCallback\<number>): void;<br>publishReminder(reminderReq: ReminderRequest): Promise\<number>; | Added|
| ohos.bundleState | bundleState | queryCurrentBundleActiveStates(begin: number, end: number, callback: AsyncCallback\<Array\<BundleActiveState>>): void;<br>queryCurrentBundleActiveStates(begin: number, end: number): Promise\<Array\<BundleActiveState>>; | Added|
| ohos.bundleState | IntervalType | BY_ANNUALLY = 4 | Added|
| ohos.bundleState | IntervalType | BY_MONTHLY = 3 | Added|
| ohos.bundleState | IntervalType | BY_WEEKLY = 2 | Added|
| ohos.bundleState | IntervalType | BY_DAILY = 1 | Added|
| ohos.bundleState | IntervalType | BY_OPTIMIZED = 0 | Added|
| ohos.bundleState | BundleActiveInfoResponse | [key: string]: BundleStateInfo; | Added|
| ohos.bundleState | bundleState | queryAppUsagePriorityGroup(callback: AsyncCallback\<number>): void;<br>queryAppUsagePriorityGroup(): Promise\<number>; | Added|
| ohos.bundleState | bundleState | isIdleState(bundleName: string, callback: AsyncCallback\<boolean>): void;<br>isIdleState(bundleName: string): Promise\<boolean>; | Added|
| ohos.bundleState | BundleActiveState | stateType?: number; | Added|
| ohos.bundleState | BundleActiveState | stateOccurredTime?: number; | Added|
| ohos.bundleState | BundleActiveState | nameOfClass?: string; | Added|
| ohos.bundleState | BundleActiveState | indexOfLink?: string; | Added|
| ohos.bundleState | BundleActiveState | bundleName?: string; | Added|
| ohos.bundleState | BundleActiveState | appUsagePriorityGroup?: number; | Added|
| ohos.bundleState | BundleStateInfo | merge(toMerge: BundleStateInfo): void; | Added|
| ohos.bundleState | BundleStateInfo | infosEndTime?: number; | Added|
| ohos.bundleState | BundleStateInfo | infosBeginTime?: number; | Added|
| ohos.bundleState | BundleStateInfo | fgAbilityPrevAccessTime?: number; | Added|
| ohos.bundleState | BundleStateInfo | fgAbilityAccessTotalTime?: number; | Added|
| ohos.bundleState | BundleStateInfo | bundleName?: string; | Added|
| ohos.bundleState | BundleStateInfo | abilitySeenTotalTime?: number; | Added|
| ohos.bundleState | BundleStateInfo | abilityPrevSeenTime?: number; | Added|
| ohos.bundleState | BundleStateInfo | abilityPrevAccessTime?: number; | Added|
| ohos.bundleState | BundleStateInfo | abilityInFgTotalTime?: number; | Added|
| ohos.bundleState | BundleStateInfo | id: number; | Added|
| ohos.backgroundTaskManager | BackgroundMode | TASK_KEEPING = 9 | Added|
| ohos.backgroundTaskManager | BackgroundMode | MULTI_DEVICE_CONNECTION = 6 | Added|
| ohos.backgroundTaskManager | BackgroundMode | BLUETOOTH_INTERACTION = 5 | Added|
| ohos.backgroundTaskManager | BackgroundMode | LOCATION = 4 | Added|
| ohos.backgroundTaskManager | BackgroundMode | AUDIO_RECORDING = 3 | Added|
| ohos.backgroundTaskManager | BackgroundMode | AUDIO_PLAYBACK = 2 | Added|
| ohos.backgroundTaskManager | BackgroundMode | DATA_TRANSFER = 1 | Added|
| ohos.backgroundTaskManager | backgroundTaskManager | stopBackgroundRunning(context: Context, callback: AsyncCallback\<void>): void;<br>stopBackgroundRunning(context: Context): Promise\<void>; | Added|
| ohos.backgroundTaskManager | backgroundTaskManager | startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent, callback: AsyncCallback\<void>): void;<br>startBackgroundRunning(context: Context, bgMode: BackgroundMode, wantAgent: WantAgent): Promise\<void>; | Added|
| ohos.backgroundTaskManager | backgroundTaskManager | requestSuspendDelay(reason: string, callback: Callback\<void>): DelaySuspendInfo; | Added|
| ohos.backgroundTaskManager | backgroundTaskManager | getRemainingDelayTime(requestId: number, callback: AsyncCallback\<number>): void;<br>getRemainingDelayTime(requestId: number): Promise\<number>; | Added|
| ohos.backgroundTaskManager | backgroundTaskManager | cancelSuspendDelay(requestId: number): void; | Added|
| ohos.backgroundTaskManager | DelaySuspendInfo | actualDelayTime: number; | Added|
| ohos.backgroundTaskManager | DelaySuspendInfo | requestId: number; | Added|
