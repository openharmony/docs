# JS API Differences

This document describes the changes of APIs in OpenHarmony 3.1 Beta when compared with OpenHarmony 3.0 LTS.

## Standard System API Changes

| Module| API | Change Type| Change Description |
|  --------  |  --------  |  --------  |  --------  |
| System Application - settings| getUri(name: string): string | Added     | Added the API for obtaining the URI of a string.|
| System Application - settings| getValue(dataAbilityHelper: DataAbilityHelper, name: string, defValue: string): string | Added| Added the API for obtaining the value of a string in the database.|
| System Application - settings| setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean | Added| Added the API for saving a string name and its value in the database.|
| Misc Services - systemTime| getCurrentTime(callback: AsyncCallback\<number>): void    | Added    | Added the API for obtaining the number of milliseconds elapsed since the Unix epoch.                  |
| Misc Services - systemTime| getCurrentTime(): Promise\<number>                        | Added    | Added the API for obtaining the number of milliseconds elapsed since the Unix epoch.                  |
| Misc Services - systemTime| getCurrentTimeNs(callback: AsyncCallback\<number>): void  | Added    | Added the API for obtaining the number of nanoseconds elapsed since the Unix epoch.                  |
| Misc Services - systemTime| getCurrentTimeNs(): Promise\<number>                      | Added    | Added the API for obtaining the number of nanoseconds elapsed since the Unix epoch.                  |
| Misc Services - systemTime| getRealActiveTime(callback: AsyncCallback\<number>): void | Added    | Added the API for obtaining the number of milliseconds elapsed since the system boot, excluding the deep sleep time.|
| Misc Services - systemTime| getRealActiveTime(): Promise\<number>                     | Added    | Added the API for obtaining the number of milliseconds elapsed since the system boot, excluding the deep sleep time.|
| Misc Services - systemTime| getRealActiveTimeNs(callback: AsyncCallback\<number>): void | Added    | Added the API for obtaining the number of nanoseconds elapsed since the system boot, excluding the deep sleep time.|
| Misc Services - systemTime| getRealActiveTimeNs(): Promise\<number>                   | Added    | Added the API for obtaining the number of nanoseconds elapsed since the system boot, excluding the deep sleep time.|
| Misc Services - systemTime| getRealTime(callback: AsyncCallback\<number>): void       | Added    | Added the API for obtaining the number of milliseconds elapsed since the system boot, including the deep sleep time.  |
| Misc Services - systemTime| getRealTime(): Promise\<number>                           | Added    | Added the API for obtaining the number of milliseconds elapsed since the system boot, including the deep sleep time.  |
| Misc Services - systemTime| getRealTimeNs(callback: AsyncCallback\<number>): void     | Added    | Added the API for obtaining the number of nanoseconds elapsed since the system boot, including the deep sleep time.  |
| Misc Services - systemTime| getRealTimeNs(): Promise\<number>                         | Added    | Added the API for obtaining the number of nanoseconds elapsed since the system boot, including the deep sleep time.  |
| Misc Services - systemTime| getDate(callback: AsyncCallback\<Date>): void             | Added    | Added the API for obtaining the current time.                                      |
| Misc Services - systemTime| getDate(): Promise\<Date>                                 | Added    | Added the API for obtaining the current time.                                      |
| Misc Services - systemTime| getTimeZone(callback: AsyncCallback\<string>): void       | Added    | Added the API for obtaining the system time zone.                                      |
| Misc Services - systemTime| getTimeZone(): Promise\<string>                           | Added    | Added the API for obtaining the system time zone.                                      |
| ArkUI Framework - Universal Events   | onAreaChange| Added     | Added the event indicating component area (including the size and position) changes.|
| ArkUI Framework - Universal Attributes| responseRegion| Added| Added the attribute for touch hotspot settings.|
| ArkUI Framework - Universal Attributes| touchable| Added| Added the attribute that specifies whether a component is touchable.|
| ArkUI Framework - Universal Attributes| stateStyle| Added| Added the attribute that specifies the styles of the pressed and disabled states of a component.|
| ArkUI Framework - Basic Gestures| SwipeGesture | Added| Added the SwipeGesture module.|
| ArkUI Framework - Basic Components| Marquee | Added| Added the **\<Marquee>** component.|
| ArkUI Framework - Basic Components| PluginComponent | Added| Added the **\<PluginComponent>** component.|
| ArkUI Framework - Basic Components| TextArea | Added| Added the **\<TextArea>** component.|
| ArkUI Framework - Basic Components| TextInput | Added| Added the **\<TextInput>** component.|
| ArkUI Framework - Basic Components| Toggle | Added| Added the **\<Toggle>** component.|
| ArkUI Framework - Container Components| ScrollBar | Added| Added the **\<ScrollBar>** component.|
| ArkUI Framework - Container Components| Navigation | Added| Added the **\<Navigation>** component.|
| ArkUI Framework - Container Components| Stepper | Added| Added the **\<Stepper>** component.|
| ArkUI Framework - Container Components| StepperItem | Added| Added the **\<StepperItem>** component.|
| ArkUI Framework - Canvas Components| Canvas | Added| Added the **\<Canvas>** component.|
| ArkUI Framework - Canvas Components| Lottie | Added| Added the support for the Lottie library.|
| ArkUI Framework - Global UI Methods| ActionSheet | Added| Added the support for the list selection dialog box.|
| USB Service - USB| getDevices(): Array\<Readonly\<USBDevice>> | Added     | Added the API for obtaining USB devices.|
| USB Service - USB| connectDevice(device: USBDevice): Readonly\<USBDevicePipe> | Added| Added the API for opening a USB device based on the device information returned by **getDevices()**.|
| USB Service - USB| hasRight(deviceName: string): boolean | Added| Added the API for checking whether the caller has the permission to access the USB device.|
| USB Service - USB| requestRight(deviceName: string): Promise\<boolean> | Added| Added the API for requesting the temporary permission for the caller to access the USB device.|
| USB Service - USB| claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number | Added| Added the API for claiming a USB interface.|
| USB Service - USB| releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number | Added| Added the API for releasing a USB interface.|
| USB Service - USB| setConfiguration(pipe: USBDevicePipe, config: USBConfig): number | Added| Added the API for setting USB device configurations.|
| USB Service - USB| setInterface(pipe: USBDevicePipe, iface: USBInterface): number | Added| Added the API for setting USB device interfaces.|
| USB Service - USB| getRawDescriptor(pipe: USBDevicePipe): Uint8Array | Added| Added the API for obtaining the raw USB descriptor.|
| USB Service - USB| getFileDescriptor(pipe: USBDevicePipe): number | Added| Added the API for obtaining the file descriptor.|
| USB Service - USB| controlTransfer(pipe: USBDevicePipe, contrlparam: USBControlParams, timeout?: number): Promise\<number> | Added| Added the API for control transfer.|
| USB Service - USB| bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array, timeout?: number): Promise\<number> | Added| Added the API for bulk transfer.|
| USB Service - USB| closePipe(pipe: USBDevicePipe): number | Added| Added the API for closing the USB device pipe.|
| Application Framework - bundle                 | cleanBundleCacheFiles(bundleName: string, callback: AsyncCallback\<void>): void;<br>cleanBundleCacheFiles(bundleName: string): Promise\<void>; | Added    | Added the APIs for clearing the cache of an application.                             |
| Application Framework - bundle                  | setApplicationEnabled(bundleName: string, isEnable: boolean, callback: AsyncCallback\<void>): void;<br>setApplicationEnabled(bundleName: string, isEnable: boolean): Promise\<void>; | Added    | Added the API for setting whether to enable an application.                             |
| Application Framework - bundle                   | setAbilityEnabled(info: AbilityInfo, isEnable: boolean, callback: AsyncCallback\<void>): void;<br>setAbilityEnabled(info: AbilityInfo, isEnable: boolean): Promise\<void>; | Added    | Added the API for setting whether to enable an ability.                          |
| Application Framework - bundle.innerBundleManager| getLauncherAbilityInfos(bundleName: string, userId: number, callback: AsyncCallback\<Array\<LauncherAbilityInfo>>) : void;<br>getLauncherAbilityInfos(bundleName: string, userId: number) : Promise\<Array\<LauncherAbilityInfo>>; | Added    | Added the API for obtaining the launcher ability information by **bundleName**.          |
| Application Framework - bundle.innerBundleManager| on(type:"BundleStatusChange", bundleStatusCallback : BundleStatusCallback, callback: AsyncCallback\<string>) : void;<br>on(type:"BundleStatusChange", bundleStatusCallback : BundleStatusCallback): Proimise\<string>; | Added    | Added the API for subscribing to bundle status changes.                       |
| Application Framework - bundle.innerBundleManager| off(type:"BundleStatusChange", callback: AsyncCallback\<string>) : void;<br>off(type:"BundleStatusChange"): Proimise\<string>; | Added    | Added the APIs for unsubscribing from bundle status changes.                       |
| Application Framework - bundle.innerBundleManager| getAllLauncherAbilityInfos(userId: number, callback: AsyncCallback\<Array\<LauncherAbilityInfo>>) : void;<br>getAllLauncherAbilityInfos(userId: number) : Promise\<Array\<LauncherAbilityInfo>>; | Added    | Added the APIs for obtaining the application abilities on all launchers by **userId**.|
| Application Framework - bundle.innerBundleManager| getShortcutInfos(bundleName :string, callback: AsyncCallback\<Array\<ShortcutInfo>>) : void;<br>getShortcutInfos(bundleName : string) : Promise\<Array\<ShortcutInfo>>; | Added    | Added the API for obtaining the application shortcut information by **bundleName**.     |
| DSoftBus - rpc.MessageParcel| writeNoException(): void | Added| - |
| DSoftBus - rpc.MessageParcel| readException(): void | Added| - |
| DSoftBus - rpc.MessageParcel| writeRemoteObjectArray(objectArray: IRemoteObject[]): boolean | Added| - |
| DSoftBus - rpc.MessageParcel| readSequenceableArray(sequenceableArray Sequenceable[]): void | Added| - |
| DSoftBus - rpc.MessageParcel| readRemoteObjectArray(objects: IRemoteObject[]): void | Added| - |
| DSoftBus - rpc.MessageParcel| readRemoteObjectArray(): IRemoteObject[] | Added| - |
| DSoftBus - rpc.MessageParcel| static closeFileDescriptor(fd: number): void | Added| - |
| DSoftBus - rpc.MessageParcel| static dupFileDescriptor(fd: number) :number | Added| - |
| DSoftBus - rpc.MessageParcel| containFileDescriptors(): boolean | Added| - |
| DSoftBus - rpc.MessageParcel| writeFileDescriptor(fd: number): boolean | Added| - |
| DSoftBus - rpc.MessageParcel| readFileDescriptor(): number | Added| - |
| DSoftBus - rpc.MessageParcel| writeAshmem(ashmem: Ashmem): boolean | Added| - |
| DSoftBus - rpc.MessageParcel| readAshmem(): Ashmem | Added| - |
| DSoftBus - rpc.MessageParcel| getRawDataCapacity(): number | Added| - |
| DSoftBus - rpc.MessageParcel| writeRawData(rawData: number[], size: number): boolean | Added| - |
| DSoftBus - rpc.MessageParcel| readRawData(size: number): number[] | Added| - |
| DSoftBus - rpc| interface SendRequestResult {<br>         errCode: number;<br>         code: number;<br>         data: MessageParcel;<br>         reply: MessageParcel;<br>    } | Added| - |
| DSoftBus - rpc.Ashmem| PROT_EXEC = 4 | Added| - |
| DSoftBus - rpc.Ashmem| PROT_NONE = 0 | Added| - |
| DSoftBus - rpc.Ashmem| PROT_READ = 1 | Added| - |
| DSoftBus - rpc.Ashmem| PROT_WRITE = 2 | Added| - |
| DSoftBus - rpc.Ashmem| static createAshmem(name: string, size: number): Ashmem | Added| - |
| DSoftBus - rpc.Ashmem| static createAshmemFromExisting(ashmem: Ashmem): Ashmem | Added| - |
| DSoftBus - rpc.Ashmem| closeAshmem(): void | Added| - |
| DSoftBus - rpc.Ashmem| unmapAshmem(): void | Added| - |
| DSoftBus - rpc.Ashmem| getAshmemSize(): number | Added| - |
| DSoftBus - rpc.Ashmem| mapAshmem(mapType: number): boolean | Added| - |
| DSoftBus - rpc.Ashmem| mapReadAndWriteAshmem(): boolean | Added| - |
| DSoftBus - rpc.Ashmem| mapReadOnlyAshmem(): boolean | Added| - |
| DSoftBus - rpc.Ashmem| setProtection(protectionType: number): boolean | Added| - |
| DSoftBus - rpc.Ashmem| writeToAshmem(buf: number[], size: number, offset: number): boolean | Added| - |
| DSoftBus - rpc.Ashmem| readFromAshmem(size: number, offset: number): number[] | Added| - |
| DSoftBus - rpc.IRemoteObject| sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean | Deprecated| Replaced by an asynchronous interface, which uses a promise or callback.|
| DSoftBus - rpc.IRemoteObject| sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult> | Added| - |
| DSoftBus - rpc.IRemoteObject| sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void | Added| - |
| DSoftBus - rpc.RemoteProxy| sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean | Deprecated| Replaced by an asynchronous interface, which uses a promise or callback.|
| DSoftBus - rpc.RemoteProxy| sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult> | Added| - |
| DSoftBus - rpc.RemoteProxy| sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void | Added| - |
| DSoftBus - rpc.RemoteObject| sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean | Deprecated| Replaced by an asynchronous interface, which uses a promise or callback.|
| DSoftBus - rpc.RemoteObject| sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult> | Added| - |
| DSoftBus - rpc.RemoteObject| sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void | Added| - |
| DSoftBus - rpc.IRemoteObject| PING_TRANSACTION | Deleted| Deleted since it is not implemented in API Version 7. The deletion has no impact on existing applications.|
| DSoftBus - rpc.IRemoteObject| DUMP_TRANSACTION | Deleted| Deleted since it is not implemented in API Version 7. The deletion has no impact on existing applications.|
| DSoftBus - rpc.IRemoteObject| INTERFACE_TRANSACTION | Deleted| Deleted since it is not implemented in API Version 7. The deletion has no impact on existing applications.|
| DSoftBus - rpc.IRemoteObject| MIN_TRANSACTION_ID | Deleted| Deleted since it is not implemented in API Version 7. The deletion has no impact on existing applications.|
| DSoftBus - rpc.IRemoteObject| MAX_TRANSACTION_ID | Deleted| Deleted since it is not implemented in API Version 7. The deletion has no impact on existing applications.|
| DSoftBus - rpc.Sequenceable| hasFileDescriptor(): boolean | Deleted| Deleted since this API will not be invoked by the RPC framework. The deletion has no impact on existing applications.|
| DSoftBus - rpc.MessageOption| constructor(syncFlags?: number, waitTime = TF_WAIT_TIME) | Added| - |
| DSoftBus - rpc.MessageOption| getFlags(): number | Added| - |
| DSoftBus - rpc.MessageOption| setFlags(flags: number): void | Added| - |
| DSoftBus - rpc.MessageOption| getWaitTime(): number | Added| - |
| DSoftBus - rpc.MessageOption| setWaitTime(waitTime: number): void | Added| - |
| DSoftBus - rpc.MessageOption| MAX_WAIT_TIME  = 3000 | Deleted| Deleted since it is not implemented in API Version 7. The deletion has no impact on existing applications.|
| DSoftBus - rpc.RemoteObject| constructor(descriptor: string) | Added| - |
| DSoftBus - rpc.RemoteObject| queryLocalInterface(descriptor: string): IRemoteBroker | Modified| Corrected the return type to **IRemoteBroker**. This change does not affect existing applications.|
| DSoftBus - rpc.Proxy| PING_TRANSACTION | Added| - |
| DSoftBus - rpc.Proxy| DUMP_TRANSACTION | Added| - |
| DSoftBus - rpc.Proxy| INTERFACE_TRANSACTION | Added| - |
| DSoftBus - rpc.Proxy| MIN_TRANSACTION_ID = 0x1 | Added| - |
| DSoftBus - rpc.Proxy| MAX_TRANSACTION_ID = 0x00FFFFFF | Added| - |
| DSoftBus - rpc.Proxy| queryLocalInterface(interface: string): IRemoteBroker | Modified| Corrected the return type to **IRemoteBroker**. This change does not affect existing applications.|
| DSoftBus - Wi-Fi| getLinkedInfo(): Promise\<WifiLinkedInfo>;<br>getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void; | Added| - |
| DSoftBus - Wi-Fi| isConnected(): boolean; | Added| - |
| DSoftBus - Wi-Fi| getSupportedFeatures(): number; | Added| - |
| DSoftBus - Wi-Fi| isFeatureSupported(featureId: number): boolean; | Added| - |
| DSoftBus - Wi-Fi| getDeviceMacAddress(): string[]; | Added| - |
| DSoftBus - Wi-Fi| getIpInfo(): IpInfo; | Added| - |
| DSoftBus - Wi-Fi| getCountryCode(): string; | Added| - |
| DSoftBus - Wi-Fi| reassociate(): boolean; | Added| - |
| DSoftBus - Wi-Fi| reconnect(): boolean; | Added| - |
| DSoftBus - Wi-Fi| getDeviceConfigs(): Array\<WifiDeviceConfig>; | Added| - |
| DSoftBus - Wi-Fi| updateNetwork(config: WifiDeviceConfig): number; | Added| - |
| DSoftBus - Wi-Fi| disableNetwork(netId: number): boolean; | Added| - |
| DSoftBus - Wi-Fi| removeAllNetwork(): boolean; | Added| - |
| DSoftBus - Wi-Fi| removeDevice(id: number): boolean; | Added| - |
| DSoftBus - Wi-Fi| enableHotspot(): boolean; | Added| - |
| DSoftBus - Wi-Fi| disableHotspot(): boolean; | Added| - |
| DSoftBus - Wi-Fi| isHotspotActive(): boolean; | Added| - |
| DSoftBus - Wi-Fi| setHotspotConfig(config: HotspotConfig): boolean; | Added| - |
| DSoftBus - Wi-Fi| getHotspotConfig(): HotspotConfig; | Added| - |
| DSoftBus - Wi-Fi| getStations(): Array\<StationInfo>; | Added| - |
| DSoftBus - Wi-Fi| on(type: "wifiStateChange", callback: Callback\<number>): void; | Added| - |
| DSoftBus - Wi-Fi| off(type: "wifiStateChange", callback?: Callback\<number>): void; | Added| - |
| DSoftBus - Wi-Fi| on(type: "wifiConnectionChange", callback: Callback\<number>): void; | Added| - |
| DSoftBus - Wi-Fi| off(type: "wifiConnectionChange", callback?: Callback\<number>): void; | Added| - |
| DSoftBus - Wi-Fi| on(type: "wifiScanStateChange", callback: Callback\<number>): void; | Added| - |
| DSoftBus - Wi-Fi| off(type: "wifiScanStateChange", callback?: Callback\<number>): void; | Added| - |
| DSoftBus - Wi-Fi| on(type: "wifiRssiChange", callback: Callback\<number>): void; | Added| - |
| DSoftBus - Wi-Fi| off(type: "wifiRssiChange", callback?: Callback\<number>): void; | Added| - |
| DSoftBus - Wi-Fi| on(type: "hotspotStateChange", callback: Callback\<number>): void; | Added| - |
| DSoftBus - Wi-Fi| off(type: "hotspotStateChange", callback?: Callback\<number>): void; | Added| - |
| DSoftBus - Wi-Fi| on(type: "hotspotStaJoin", callback: Callback\<StationInfo>): void; | Added| - |
| DSoftBus - Wi-Fi| off(type: "hotspotStaJoin", callback?: Callback\<StationInfo>): void; | Added| - |
| DSoftBus - Wi-Fi| on(type: "hotspotStaLeave", callback: Callback\<StationInfo>): void; | Added| - |
| DSoftBus - Wi-Fi| off(type: "hotspotStaLeave", callback?: Callback\<StationInfo>): void; | Added| - |
| Globalization - resourceManager| getRawFile(path: string, callback: AsyncCallback\<Uint8Array>);<br>getRawFile(path: string): Promise\<Uint8Array>; | Added| - |
| Globalization - Intl| RelativeTimeFormat.constructor(); | Added| Added this constructor.|
| Globalization - Intl| RelativeTimeFormat.constructor(locale: string \| Array\<string>, options?: RelativeTimeFormatInputOptions); | Added| Added this constructor.|
| Globalization - Intl| RelativeTimeFormat.format(value: number, unit: string): string; | Added| Added the API for formatting the relative time.|
| Globalization - Intl| RelativeTimeFormat.formatToParts(value: number, unit: string): Array\<object>; | Added| Added the API for formatting the relative time. The result is divided into multiple parts and stored separately.|
| Globalization - Intl| RelativeTimeFormat.formatToParts(value: number, unit: string): Array\<object>; | Added| Added the API for formatting the relative time. The result is divided into multiple parts and stored separately.|
| Globalization - Intl| PluralRules.constructor(); | Added| Added this constructor.|
| Globalization - Intl| PluralRules.constructor(locale: string \| Array\<string>, options?: PluralRulesOptions); | Added| Added this constructor.|
| Globalization - Intl| PluralRules.select(n: number): string; | Added| Added the API for checking the singular-plural type of a number.|
| Globalization - Intl| Collator.constructor(); | Added| Added this constructor.|
| Globalization - Intl| Collator.constructor(locale: string \| Array\<string>, options?: CollatorOptions); | Added| Added this constructor.|
| Globalization - Intl| Collator.compare(first: string, second: string): number; | Added| Added the API for comparing two strings.|
| Globalization - Intl| Collator.resolvedOptions(): CollatorOptions; | Added| Added the API for obtaining the attributes of a sorting object.|
| Globalization - I18N| unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string; | Added| Added the API for unit conversion.|
| Globalization - I18N| constructor(country: string, options?: PhoneNumberFormatOptions);<br>isValidNumber(number: string): boolean;<br>format(number: string): string; | Added| Added the APIs for formatting phone numbers.|
| Globalization - I18N| setTime(date: Date);<br>setTime(time: number);<br>set(year: number, month: number, date:number, hour?: number, minute?: number, second?: number);<br>setTimeZone(timezone: string);<br>getTimeZone(): string;<br>getFirstDayOfWeek(): number;<br>setFirstDayOfWeek(value: number);<br>getMinimalDaysInFirstWeek(): number;<br>setMinimalDaysInFirstWeek(value: number);<br>get(field: string): number;<br>getDisplayName(locale: string): string;<br>isWeekend(date?: Date): boolean;<br>export getCalendar(locale: string, type?: string): Calendar; | Added| Added the APIs for the calendar.|
| Globalization - I18N| isRTL(locale: string): boolean; | Added| Added the API for checking whether the localized script for the specified language is displayed from right to left.|
| Globalization - I18N| getLineInstance(locale: string): BreakIterator;<br>current(): number;<br>first(): number;<br>last(): number;<br>next(index?: number): number;<br>previous(): number;<br>setLineBreakText(text: string): void;<br>following(offset: number): number;<br>getLineBreakText(): string;<br>isBoundary(offset: number): boolean; | Added| Added the APIs for line feed.|
| Globalization - I18N| getInstance(locale?:string): IndexUtil;<br>getIndexList(): Array\<string>; | Added| Added the APIs for obtaining the alphabet index.|
| Globalization - I18N| addLocale(locale: string);<br>getIndex(text: string): string;<br>isDigit(char: string): boolean;<br>isSpaceChar(char: string): boolean;<br>isWhitespace(char: string): boolean;<br>isRTL(char: string): boolean;<br>isIdeograph(char: string): boolean;<br>isLetter(char: string): boolean;<br>isLowerCase(char: string): boolean;<br>isUpperCase(char: string): boolean;<br>getType(char: string): string; | Added| Added the APIs for obtaining character attributes.|
| Event Notification - DoNotDisturbDate| type: notification.DoNotDisturbType | Added     | Added the do-not-disturb (DND) time type.|
| Event Notification - DoNotDisturbDate| begin: Date | Added| Added the DND start time setting.|
| Event Notification - DoNotDisturbDate| end: Date | Added| Added the DND end time setting.|
| Event Notification - DoNotDisturbDate| export enum DoNotDisturbType {<br>    TYPE_NONE = 0,         // Non-notification DND type<br>    TYPE_ONCE = 1,         // One-shot DND at the specified time segment<br>    TYPE_DAILY = 2,        // Daily DND at the specified time segment (only the hour and minute specified)<br>    TYPE_CLEARLY = 3,        // DND at the specified time segment (the year, month, day, hour, and minute specified)<br>} | Added| Added the DND time type.|
| Event Notification - notification| setDoNotDisturbDate(date DoNotDisturbDate, callback: AsyncCallback\<void>): void | Added| Added the API for setting the DND time segment.|
| Event Notification - notification| setDoNotDisturbDate(date DoNotDisturbDate): Promise\<void> | Added| Added the API for setting the DND time segment.|
| Event Notification - notification| getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate>): void | Added| Added the API for obtaining the DND time segment.|
| Event Notification - notification| getDoNotDisturbDate(): Promise\<DoNotDisturbDate> | Added| Added the API for obtaining the DND time segment.|
| Event Notification - notification| supportDoNotDisturbMode(callback: AsyncCallback\<boolean>): void | Added| Added the API for checking whether DND is supported.|
| Event Notification - notification| supportDoNotDisturbMode(): Promise\<boolean> | Added| Added the API for checking whether DND is supported.|
| Event Notification - notification| cancelGroup(groupName: string, callback: AsyncCallback\<void>): void | Added    | Added the API for canceling a notification group of the current application.                                        |
| Event Notification - notification       | cancelGroup(groupName: string): Promise\<void> | Added| Added the API for canceling a notification group of the current application.|
| Event Notification - notification       | removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void>): void | Added| Added the API for removing a notification group of a specified application.|
| Event Notification - notification       | removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void> | Added| Added the API for removing a notification group of a specified application.|
| Event Notification - NotificationSubscriber| onDoNotDisturbDateChange?:(mode: notification.DoNotDisturbDate) => void | Added| Added the API for subscribing to DND setting changes.|
| Event Notification - NotificationRequest| smallIcon?: image.PixelMap | Added| Added the small notification icon.|
| Event Notification - NotificationRequest| largeIcon?: image.PixelMap; | Added| Added the large notification icon.|
| Event Notification - NotificationRequest| groupName?: string; | Added| Added the notification group name.|
| Event Notification - NotificationUserInput|                                                              | Added    | Added the user input object.|
| Event Notification - NotificationUserInput| inputKey: string | Added| Added a key to identify the user input.|
| Event Notification - NotificationActionButton| userInput?: NotificationUserInput | Added| Added the user input object.|
| Event notification - emitter| on(event: InnerEvent, callback: Callback\<EventData>): void | Added| Added the API for subscribing to an event in persistent manner and receiving the event callback.|
| Event notification - emitter| once(event: InnerEvent, callback: Callback\<EventData>): void | Added| Added the API for subscribing to an event in one-shot manner and unsubscribing from it after the event is received via a callback.|
| Event notification - emitter| off(eventId: number): void | Added| Added the API for unsubscribing from an event.|
| Event notification - emitter| emit(event: InnerEvent, data?: EventData): void | Added| Added the API for emitting an event to the event queue.|
| Distributed File - statfs| getFreeBytes(path: string, callback: AsyncCallback\<number>): void | Added     | Added the API for obtaining the free space (in bytes) of a device using an asynchronous callback.|
| Distributed File - statfs| getFreeBytes(path: string): Promise\<number> | Added| Added the API for obtaining the free space (in bytes) of a device using a promise.|
| Distributed File - statfs| getTotalBytes(path: string, callback: AsyncCallback\<number>): void | Added| Added the API for obtaining the total space (in bytes) of a device using an asynchronous callback.|
| Distributed File - statfs| getTotalBytes(path: string): Promise\<number> | Added| Added the API for obtaining the total space (in bytes) of a device using a promise.|
| Distributed Scheduler - featureAbility     | continueAbility(options: ContinueAbilityOptions, callback: AsyncCallback\<void>): void;<br>continueAbility(options: ContinueAbilityOptions): Promise\<void>; | Added     | -      |
| Multi-language Runtime - URI| constructor(uri: string); | Added|  |
| Multi-language Runtime - URI| toString(): string | Added|  |
| Multi-language Runtime - URI           | equals(other: URI): boolean;                                 | Added    |          |
| Multi-language Runtime - URI           | checkIsAbsolute(): boolean;                                  | Added    |          |
| Multi-language Runtime - URI           | normalize(): URI;                                            | Added    |          |
| Multi-language Runtime - URI           | scheme: string;                                              | Added    |          |
| Multi-language Runtime - URI           | userinfo: string;                                            | Added    |          |
| Multi-language Runtime - URI           | host: string;                                                | Added    |          |
| Multi-language Runtime - URI           | port: string;                                                | Added    |          |
| Multi-language Runtime - URI           | path: string;                                                | Added    |          |
| Multi-language Runtime - URI           | query: string;                                               | Added    |          |
| Multi-language Runtime - URI           | query: string;                                               | Added    |          |
| Multi-language Runtime - URI           | authority: string;                                           | Added    |          |
| Multi-language Runtime - URI           | ssp: string;                                                 | Added    |          |
| Multi-language Runtime - RationalNumber| constructor(numerator: number, denominator: number);         | Added    |          |
| Multi-language Runtime - RationalNumber| static createRationalFromString(rationalString: string): RationalNumber; | Added    |  |
| Multi-language Runtime - RationalNumber| compareTo(another :RationalNumber): number; | Added    |  |
| Multi-language Runtime - RationalNumber| equals(obj: Object): boolean; | Added    |  |
| Multi-language Runtime - RationalNumber| valueOf(): number; | Added    |  |
| Multi-language Runtime - RationalNumber| static getCommonDivisor(number1: number, number2: number): number; | Added    |  |
| Multi-language Runtime - RationalNumber| getDenominator(): number; | Added    |  |
| Multi-language Runtime - RationalNumber| getNumerator(): number; | Added    |  |
| Multi-language Runtime - RationalNumber| isFinite() : boolean; | Added    |  |
| Multi-language Runtime - RationalNumber| isNaN(): boolean; | Added    |  |
| Multi-language Runtime - RationalNumber| isZero(): boolean; | Added    |  |
| Multi-language Runtime - RationalNumber| toString(): string; | Added    |  |
| Multi-language Runtime - LruBuffer| constructor(capacity?:number); | Added    |  |
| Multi-language Runtime - LruBuffer| updateCapacity(newCapacity: number):void | Added    |  |
| Multi-language Runtime - LruBuffer| toString():string | Added    |  |
| Multi-language Runtime - LruBuffer| length:number | Added    |  |
| Multi-language Runtime - LruBuffer| getCapacity(): number; | Added    |  |
| Multi-language Runtime - LruBuffer| clear(): void; | Added    |  |
| Multi-language Runtime - LruBuffer| getCreateCount(): number; | Added    |  |
| Multi-language Runtime - LruBuffer| getMissCount(): number; | Added    |  |
| Multi-language Runtime - LruBuffer| getRemovalCount(): number; | Added    |  |
| Multi-language Runtime - LruBuffer| getMatchCount(): number; | Added    |  |
| Multi-language Runtime - LruBuffer| getPutCount(): number; | Added    |  |
| Multi-language Runtime - LruBuffer| isEmpty(): boolean; | Added    |  |
| Multi-language Runtime - LruBuffer| get(key: K): V \| undefined; | Added    |  |
| Multi-language Runtime - LruBuffer| put(key: K, value: V): V; | Added    |  |
| Multi-language Runtime - LruBuffer| values(): V[]; | Added    |  |
| Multi-language Runtime - LruBuffer| keys(): K[]; | Added    |  |
| Multi-language Runtime - LruBuffer| remove(key: K): V \| undefined; | Added    |  |
| Multi-language Runtime - LruBuffer| afterRemoval(isEvict: boolean, key: K, value: V, newValue: V): void; | Added    |  |
| Multi-language Runtime - LruBuffer| contains(key: K): boolean; | Added    |  |
| Multi-language Runtime - LruBuffer| createDefault(key: K): V; | Added    |  |
| Multi-language Runtime - LruBuffer| entries(): IterableIterator\<[K, V]>; | Added    |  |
| Multi-language Runtime - LruBuffer| \[Symbol.iterator]\(): IterableIterator\<[K, V]>; | Added    |  |
| Multi-language Runtime - Scope| constructor(lowerObj: ScopeType, upperObj: ScopeType); | Added    |  |
| Multi-language Runtime - Scope| toString(): string; | Added    |  |
| Multi-language Runtime - Scope| intersect(range: Scope): Scope; | Added    |  |
| Multi-language Runtime - Scope| intersect(lowerObj: ScopeType, upperObj: ScopeType): Scope; | Added    |  |
| Multi-language Runtime - Scope| getUpper(): ScopeType; | Added    |  |
| Multi-language Runtime - Scope| getLower(): ScopeType; | Added    |  |
| Multi-language Runtime - Scope| expand(lowerObj: ScopeType, upperObj: ScopeType): Scope; | Added    |  |
| Multi-language Runtime - Scope| expand(range: Scope): Scope; | Added    |  |
| Multi-language Runtime - Scope| expand(value: ScopeType): Scope; | Added    |  |
| Multi-language Runtime - Scope| contains(value: ScopeType): boolean; | Added    |  |
| Multi-language Runtime - Scope| contains(range: Scope): boolean; | Added    |  |
| Multi-language Runtime - Scope| clamp(value: ScopeType): ScopeType; | Added    |  |
| Multi-language Runtime - Base64| constructor(); | Added    |  |
| Multi-language Runtime - Base64| encodeSync(src: Uint8Array): Uint8Array; | Added    |  |
| Multi-language Runtime - Base64| encodeToStringSync(src: Uint8Array): string; | Added    |  |
| Multi-language Runtime - Base64| decodeSync(src: Uint8Array \| string): Uint8Array; | Added    |  |
| Multi-language Runtime - Base64| encode(src: Uint8Array): Promise\<Uint8Array>; | Added    |  |
| Multi-language Runtime - Base64| encodeToString(src: Uint8Array): Promise\<string>; | Added    |  |
| Multi-language Runtime - Base64| decode(src: Uint8Array \| string): Promise\<Uint8Array>; | Added    |  |
| Multi-language Runtime - types| constructor(); | Added    |  |
| Multi-language Runtime - types| isAnyArrayBuffer(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isArrayBufferView(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isArgumentsObject(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isArrayBuffer(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isAsyncFunction(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isBigInt64Array(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isBigUint64Array(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isBooleanObject(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isBoxedPrimitive(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isDataView(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isDate(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isExternal(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isFloat32Array(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isFloat64Array(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isGeneratorFunction(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isGeneratorObject(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isInt8Array(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isInt16Array(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isInt32Array(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isMap(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isMapIterator(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isModuleNamespaceObject(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isNativeError(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isNumberObject(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isPromise(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isProxy(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isRegExp(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isSet(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isSetIterator(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isSharedArrayBuffer(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isStringObject(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isSymbolObject(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isTypedArray(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isUint8Array(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isUint8ClampedArray(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isUint16Array(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isUint32Array(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isWeakMap(value: Object): boolean; | Added    |  |
| Multi-language Runtime - types| isWeakSet(value: Object): boolean; | Added    |  |
| Multi-language Runtime - process| const tid: number; | Added    |  |
| Multi-language Runtime - process| isIsolatedProcess(): boolean; | Added    |  |
| Multi-language Runtime - process| isAppUid(v: number): boolean; | Added    |  |
| Multi-language Runtime - process| is64Bit(): boolean; | Added    |  |
| Multi-language Runtime - process| getUidForName(v: string): number; | Added    |  |
| Multi-language Runtime - process| getThreadPriority(v: number): number; | Added    |  |
| Multi-language Runtime - process| getStartRealtime(): number; | Added    |  |
| Multi-language Runtime - process| getAvailableCores(): number[]; | Added    |  |
| Multi-language Runtime - process| getPastCpuTime(): number; | Added    |  |
| Multi-language Runtime - process| getSystemConfig(name: number): number; | Added    |  |
| Multi-language Runtime - process| getEnvironmentVar(name: string): string; | Added    |  |
| Multi-language Runtime - ConvertOptions| trim: boolean; | Added    |  |
| Multi-language Runtime - ConvertOptions| ignoreDeclaration?: boolean; | Added    |  |
| Multi-language Runtime - ConvertOptions| ignoreInstruction?: boolean; | Added    |  |
| Multi-language Runtime - ConvertOptions| ignoreAttributes?: boolean; | Added    |  |
| Multi-language Runtime - ConvertOptions| ignoreComment?: boolean; | Added    |  |
| Multi-language Runtime - ConvertOptions| ignoreCdata?: boolean; | Added    |  |
| Multi-language Runtime - ConvertOptions| ignoreDoctype?: boolean; | Added    |  |
| Multi-language Runtime - ConvertOptions| ignoreText?: boolean; | Added    |  |
| Multi-language Runtime - ConvertOptions| declarationKey: string; | Added    |  |
| Multi-language Runtime - ConvertOptions| instructionKey: string; | Added    |  |
| Multi-language Runtime - ConvertOptions| attributesKey: string; | Added    |  |
| Multi-language Runtime - ConvertOptions| textKey: string; | Added    |  |
| Multi-language Runtime - ConvertOptions| cdataKey: string; | Added    |  |
| Multi-language Runtime - ConvertOptions| doctypeKey: string; | Added    |  |
| Multi-language Runtime - ConvertOptions| commentKey: string; | Added    |  |
| Multi-language Runtime - ConvertOptions| parentKey: string; | Added    |  |
| Multi-language Runtime - ConvertOptions| typeKey: string; | Added    |  |
| Multi-language Runtime - ConvertOptions| nameKey: string; | Added    |  |
| Multi-language Runtime - ConvertOptions| elementsKey: string; | Added    |  |
| Multi-language Runtime - ConvertXML| convert(xml: string, options?: ConvertOptions) : Object; | Added    |  |
| Multi-language Runtime - XmlSerializer| constructor(buffer: ArrayBuffer \| DataView, encoding?: string); | Added    |  |
| Multi-language Runtime - XmlSerializer| setAttributes(name: string, value: string): void; | Added    |  |
| Multi-language Runtime - XmlSerializer| addEmptyElement(name: string): void; | Added    |  |
| Multi-language Runtime - XmlSerializer| setDeclaration(): void; | Added    |  |
| Multi-language Runtime - XmlSerializer| startElement(name: string): void; | Added    |  |
| Multi-language Runtime - XmlSerializer| endElement(): void; | Added    |  |
| Multi-language Runtime - XmlSerializer| setNamespace(prefix: string, namespace: string): void; | Added    |  |
| Multi-language Runtime - XmlSerializer| setCommnet(text: string): void; | Added    |  |
| Multi-language Runtime - XmlSerializer| setCData(text: string): void; | Added    |  |
| Multi-language Runtime - XmlSerializer| setText(text: string): void; | Added    |  |
| Multi-language Runtime - XmlSerializer| setDocType(text: string): void; | Added    |  |
| Multi-language Runtime -ParseOptions| supportDoctype?: boolean; | Added    |  |
| Multi-language Runtime -ParseOptions| ignoreNameSpace?: boolean; | Added    |  |
| Multi-language Runtime -ParseOptions| tagValueCallbackFunction?: (name: string, value: string) => boolean; | Added    |  |
| Multi-language Runtime -ParseOptions| attributeValueCallbackFunction?: (name: string, value: string) => boolean; | Added    |  |
| Multi-language Runtime -ParseOptions| tokenValueCallbackFunction?: (eventType: EventType, value: ParseInfo) => boolean; | Added    |  |
| Account - account.appAccount| createAppAccountManager | Added| Added the API for obtaining an **AppAccountManager** instance.|
| Account - account.appAccount| addAccount(name: string, callback: AsyncCallback\<void>): void;<br>addAccount(name: string, extraInfo: string, callback: AsyncCallback\<void>): void;<br>addAccount(name: string, extraInfo?: string): Promise\<void>; | Added| Added the APIs for adding an application account.|
| Account - account.appAccount| deleteAccount(name: string, callback: AsyncCallback\<void>): void;<br>deleteAccount(name: string): Promise\<void>; | Added| Added the APIs for deleting an application account.|
| Account - account.appAccount| disableAppAccess(name: string, bundleName: string, callback: AsyncCallback\<void>): void;<br>disableAppAccess(name: string, bundleName: string): Promise\<void>; | Added| Added the APIs for disabling an application account from accessing a third-party application with the given bundle name.|
| Account - account.appAccount| enableAppAccess(name: string, bundleName: string, callback: AsyncCallback\<void>): void;<br>enableAppAccess(name: string, bundleName: string): Promise\<void>; | Added| Added the APIs for enabling an application account to access a third-party application with the given bundle name.|
| Account - account.appAccount| checkAppAccountSyncEnable(name: string, callback: AsyncCallback\<boolean>): void;<br>checkAppAccountSyncEnable(name: string): Promise\<boolean>; | Added| Added the APIs for checking whether an application account allows application data synchronization.|
| Account - account.appAccount| setAccountCredential(name: string, credentialType: string, credential: string,<br>                     callback: AsyncCallback\<void>): void;<br>setAccountCredential(name: string, credentialType: string, credential: string): Promise\<void>; | Added| Added the APIs for setting a credential for an application account.|
| Account - account.appAccount| setAccountExtraInfo(name: string, extraInfo: string, callback: AsyncCallback\<void>): void;<br>setAccountExtraInfo(name: string, extraInfo: string): Promise\<void>; | Added| Added the APIs for setting additional information for an application account.|
| Account - account.appAccount| setAppAccountSyncEnable(name: string, isEnable: boolean, callback: AsyncCallback\<void>): void;<br>setAppAccountSyncEnable(name: string, isEnable: boolean): Promise\<void>; | Added| Added the APIs for setting whether to enable application data synchronization for an application account.|
| Account - account.appAccount| setAssociatedData(name: string, key: string, value: string, callback: AsyncCallback\<void>): void;<br>setAssociatedData(name: string, key: string, value: string): Promise\<void>; | Added| Added the APIs for setting data to be associated with an application account.|
| Account - account.appAccount| getAllAccessibleAccounts(callback: AsyncCallback\<Array\<AppAccountInfo>>): void;<br>getAllAccessibleAccounts(): Promise\<Array\<AppAccountInfo>>; | Added| Added the APIs for obtaining the account information of this application and the information about the third-party application account that has been authorized to the current application.|
| Account - account.appAccount| getAllAccounts(owner: string, callback: AsyncCallback\<Array\<AppAccountInfo>>): void;<br>getAllAccounts(owner: string): Promise\<Array\<AppAccountInfo>>; | Added| Added the APIs for obtaining all account information of this application.|
| Account - account.appAccount| getAccountCredential(name: string, credentialType: string, callback: AsyncCallback\<string>): void;<br>getAccountCredential(name: string, credentialType: string): Promise\<string>; | Added| Added the APIs for obtaining the credential of an application account.|
| Account - account.appAccount| getAccountExtraInfo(name: string, callback: AsyncCallback\<string>): void;<br>getAccountExtraInfo(name: string): Promise\<string>; | Added| Added the APIs for obtaining additional information of an application account.|
| Account - account.appAccount| getAssociatedData(name: string, key: string, callback: AsyncCallback\<string>): void;<br>getAssociatedData(name: string, key: string): Promise\<string>; | Added| Added the APIs for obtaining data associated with an application account.|
| Account - account.appAccount| on(type: 'change', owners: Array\<string>, callback: Callback\<Array\<AppAccountInfo>>): void; | Added| Added the API for subscribing to application account changes.|
| Account - account.appAccount| off(type: 'change', callback?: Callback\<void>): void; | Added| Added the API for unsubscribing from application account changes.|
| Account - account.appAccount| interface AppAccountInfo | Added| Added the **AppAccountInfo** interface.|
| Pan-sensor - sensor  | on(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: AsyncCallback\<AccelerometerResponse>,options?: Options): void | Added    | Added the API for subscribing to acceleration sensor data changes.            |
| Pan-sensor - sensor  | on(type:SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION,callback:AsyncCallback\<LinearAccelerometerResponse>, options?: Options): void | Added    | Added the API for subscribing to data changes of the linear acceleration sensor.        |
| Pan-sensor - sensor  | on(type:SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED,callback:AsyncCallback\<AccelerometerUncalibratedResponse>, options?: Options): void | Added    | Added the API for subscribing to data changes of the uncalibrated acceleration sensor.    |
| Pan-sensor - sensor  | on(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback: AsyncCallback\<GravityResponse>,options?: Options): void | Added    | Added the API for subscribing to data changes of the gravity sensor.              |
| Pan-sensor - sensor  | on(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: AsyncCallback\<GyroscopeResponse>, options?: Options): void | Added    | Added the API for subscribing to data changes of the gyroscope sensor.            |
| Pan-sensor - sensor  | on(type:SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED,callback:AsyncCallback\<GyroscopeUncalibratedResponse>, options?: Options): void | Added    | Added the API for subscribing to data changes of the uncalibrated gyroscope sensor.      |
| Pan-sensor - sensor  | on(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback: AsyncCallback\<SignificantMotionResponse>, options?: Options): void | Added    | Added the API for subscribing to data changes of the significant motion sensor.            |
| Pan-sensor - sensor  | on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback: AsyncCallback\<PedometerDetectResponse>, options?: Options): void | Added    | Added the API for subscribing to data changes of the pedometer detection sensor.          |
| Pan-sensor - sensor  | on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: AsyncCallback\<PedometerResponse>, options?: Options): void | Added    | Added the API for subscribing to data changes of the pedometer sensor.              |
| Pan-sensor - sensor  | on(type:SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,callback:AsyncCallback\<AmbientTemperatureResponse>,  options?: Options): void | Added    | Added the API for subscribing to data changes of the ambient temperature sensor.          |
| Pan-sensor - sensor  | on(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: AsyncCallback\<MagneticFieldResponse>,options?: Options): void | Added    | Added the API for subscribing to data changes of the magnetic field sensor.              |
| Pan-sensor - sensor  | on(type:SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED,callback:AsyncCallback\<MagneticFieldUncalibratedResponse>, options: Options): void | Added    | Added the API for subscribing to data changes of the uncalibrated magnetic field sensor.        |
| Pan-sensor - sensor  | on(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: AsyncCallback\<ProximityResponse>,options?: Options): void | Added    | Added the API for subscribing to proximity sensor data changes.            |
| Pan-sensor - sensor  | on(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: AsyncCallback\<HumidityResponse>,options?: Options): void | Added    | Added the API for subscribing to humidity sensor data changes.              |
| Pan-sensor - sensor  | on(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: AsyncCallback\<BarometerResponse>,options?: Options): void | Added    | Added the API for subscribing to barometer sensor data changes.            |
| Pan-sensor - sensor  | on(type: SensorType.SENSOR_TYPE_ID_HALL, callback: AsyncCallback\<HallResponse>, options?: Options): void | Added    | Added the API for subscribing to data changes of the Hall effect sensor.              |
| Pan-sensor - sensor  | on(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: AsyncCallback\<LightResponse>, options?: Options): void | Added    | Added the API for subscribing to data changes of the ambient light sensor.            |
| Pan-sensor - sensor  | on(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: AsyncCallback\<OrientationResponse>, options?: Options): void | Added    | Added the API for subscribing to orientation sensor data changes.              |
| Pan-sensor - sensor  | on(type:SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR,callback:AsyncCallback\<RotationVectorResponse>,options?: Options): void | Added    | Added the API for subscribing to data changes of the rotation vector sensor.          |
| Pan-sensor - sensor  | on(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: AsyncCallback\<WearDetectionResponse>,options?: Options): void | Added    | Added the API for subscribing to wear detection data changes.          |
| Pan-sensor - sensor  | once(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: AsyncCallback\<AccelerometerResponse>): void | Added    | Added the API for subscribing to only one data change of the acceleration sensor.        |
| Pan-sensor - sensor  | once(type:SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION,callback:AsyncCallback\<LinearAccelerometerResponse>): void | Added    | Added the API for subscribing to only one data change of the linear acceleration sensor.    |
| Pan-sensor - sensor  | once(type:SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED,callback:AsyncCallback\<AccelerometerUncalibratedResponse>): void | Added    | Added the API for subscribing to only one data change of the uncalibrated acceleration sensor.|
| Pan-sensor - sensor  | once(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback: AsyncCallback\<GravityResponse>): void | Added    | Added the API for subscribing to only one data change of the gravity sensor.          |
| Pan-sensor - sensor  | once(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: AsyncCallback\<GyroscopeResponse>): void | Added    | Added the API for subscribing to only one data change of the gyroscope sensor.        |
| Pan-sensor - sensor  | once(type:SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED,callback:AsyncCallback\<GyroscopeUncalibratedResponse>, options?: Options): void | Added    | Added the API for subscribing to only one data change of the uncalibrated gyroscope sensor.  |
| Pan-sensor - sensor  | once(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback: AsyncCallback\<SignificantMotionResponse>): void | Added    | Added the API for subscribing to only one data change of the significant motion sensor.        |
| Pan-sensor - sensor  | once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback: AsyncCallback\<PedometerDetectResponse>): void | Added    | Added the API for subscribing to only one data change of the pedometer detection sensor.      |
| Pan-sensor - sensor  | once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: AsyncCallback\<PedometerResponse>): void | Added    | Added the API for subscribing to only one data change of the pedometer sensor.          |
| Pan-sensor - sensor  | once(type:SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,callback:AsyncCallback\<AmbientTemperatureResponse>): void | Added    | Added the API for subscribing to only one data change of the ambient temperature sensor.      |
| Pan-sensor - sensor  | once(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: AsyncCallback\<MagneticFieldResponse>): void | Added    | Added the API for subscribing to only one data change of the magnetic field sensor.          |
| Pan-sensor - sensor  | once(type:SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED,callback:AsyncCallback\<MagneticFieldUncalibratedResponse>): void | Added    | Added the API for subscribing to only one data change of the uncalibrated magnetic field sensor.    |
| Pan-sensor - sensor  | once(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: AsyncCallback\<ProximityResponse>): void | Added    | Added the API for subscribing to only one data change of the proximity sensor.        |
| Pan-sensor - sensor  | once(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: AsyncCallback\<HumidityResponse>): void | Added    | Added the API for subscribing to only one data change of the humidity sensor.          |
| Pan-sensor - sensor  | once(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: AsyncCallback\<BarometerResponse>): void | Added    | Added the API for subscribing to only one data change of the barometer sensor.        |
| Pan-sensor - sensor  | once(type: SensorType.SENSOR_TYPE_ID_HALL, callback: AsyncCallback\<HallResponse>): void | Added    | Added the API for subscribing to only one data change of the Hall effect sensor.          |
| Pan-sensor - sensor  | once(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: AsyncCallback\<LightResponse>): void | Added    | Added the API for subscribing to only one data change of the ambient light sensor.        |
| Pan-sensor - sensor  | once(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: AsyncCallback\<OrientationResponse>): void | Added    | Added the API for subscribing to only one data change of the orientation sensor.          |
| Pan-sensor - sensor  | once(type:SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR,callback:AsyncCallback\<RotationVectorResponse>): void | Added    | Added the API for subscribing to only one data change of the rotation vector sensor.      |
| Pan-sensor - sensor  | once(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: AsyncCallback\<WearDetectionResponse>): void | Added    | Added the API for subscribing to only one data change of the wear detection sensor.      |
| Pan-sensor - sensor  | off(type: SensorType, callback?: AsyncCallback\<void>): void | Added    | Added the API for unsubscribing from sensor data changes.                    |
| Pan-sensor - sensor  | getGeomagneticField(locationOptions: LocationOptions, timeMillis: number, callback: AsyncCallback\<GeomagneticResponse>): void <br> getGeomagneticField(locationOptions: LocationOptions, timeMillis: number): Promise\<GeomagneticResponse> | Added    | Added the APIs for obtaining the geomagnetic field of a geographic location.            |
| Pan-sensor - vibrator| vibrate(duration: number): Promise\<void> <br> vibrate(duration: number, callback?: AsyncCallback\<void>): void | Added    | Added the APIs for triggering vibration with a specific duration.          |
| Pan-sensor - vibrator| vibrate(effectId: EffectId): Promise\<void> <br> vibrate(effectId: EffectId, callback?: AsyncCallback\<void>): void | Added    | Added the APIs for triggering vibration with a specific effect.          |
| Pan-sensor - vibrator| stop(stopMode: VibratorStopMode): Promise\<void> <br> stop(stopMode: VibratorStopMode, callback?: AsyncCallback\<void>): void | Added    | Added the APIs for stopping vibration.                          |
