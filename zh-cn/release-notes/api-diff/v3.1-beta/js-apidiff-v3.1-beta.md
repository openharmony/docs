# JS API 差异报告

OpenHarmony 3.1 Beta相较于OpenHarmony 3.0 LTS版本的API变更如下:

## 标准系统接口变更

| 模块名称 | 接口名称  | 变更类型 | 变更说明  |
|  --------  |  --------  |  --------  |  --------  |
| 系统应用-settings | getUri(name: string): string | 新增      | 新增获取设置数据URI |
| 系统应用-settings | getValue(dataAbilityHelper: DataAbilityHelper, name: string, defValue: string): string | 新增 | 新增获取设置数据库值 |
| 系统应用-settings | setValue(dataAbilityHelper: DataAbilityHelper, name: string, value: string): boolean | 新增 | 新增设置设置数据库值 |
| 杂散软件服务-systemTime | getCurrentTime(callback: AsyncCallback\<number>): void    | 新增     | 获取自 Unix 纪元以来经过的毫秒数。                   |
| 杂散软件服务-systemTime | getCurrentTime(): Promise\<number>                        | 新增     | 获取自 Unix 纪元以来经过的毫秒数。                   |
| 杂散软件服务-systemTime | getCurrentTimeNs(callback: AsyncCallback\<number>): void  | 新增     | 获取自 Unix 纪元以来经过的纳秒数。                   |
| 杂散软件服务-systemTime | getCurrentTimeNs(): Promise\<number>                      | 新增     | 获取自 Unix 纪元以来经过的纳秒数。                   |
| 杂散软件服务-systemTime | getRealActiveTime(callback: AsyncCallback\<number>): void | 新增     | 获取自系统启动以来经过的毫秒数，不包括深度睡眠时间。 |
| 杂散软件服务-systemTime | getRealActiveTime(): Promise\<number>                     | 新增     | 获取自系统启动以来经过的毫秒数，不包括深度睡眠时间。 |
| 杂散软件服务-systemTime | getRealActiveTimeNs(callback: AsyncCallback\<number>): void | 新增     | 获取自系统启动以来经过的纳秒数，不包括深度睡眠时间。 |
| 杂散软件服务-systemTime | getRealActiveTimeNs(): Promise\<number>                   | 新增     | 获取自系统启动以来经过的纳秒数，不包括深度睡眠时间。 |
| 杂散软件服务-systemTime | getRealTime(callback: AsyncCallback\<number>): void       | 新增     | 获取自系统启动以来经过的毫秒数，包括深度睡眠时间。   |
| 杂散软件服务-systemTime | getRealTime(): Promise\<number>                           | 新增     | 获取自系统启动以来经过的毫秒数，包括深度睡眠时间。   |
| 杂散软件服务-systemTime | getRealTimeNs(callback: AsyncCallback\<number>): void     | 新增     | 获取自系统启动以来经过的纳秒数，包括深度睡眠时间。   |
| 杂散软件服务-systemTime | getRealTimeNs(): Promise\<number>                         | 新增     | 获取自系统启动以来经过的纳秒数，包括深度睡眠时间。   |
| 杂散软件服务-systemTime | getDate(callback: AsyncCallback\<Date>): void             | 新增     | 获取当前时间。                                       |
| 杂散软件服务-systemTime | getDate(): Promise\<Date>                                 | 新增     | 获取当前时间。                                       |
| 杂散软件服务-systemTime | getTimeZone(callback: AsyncCallback\<string>): void       | 新增     | 获取系统时区。                                       |
| 杂散软件服务-systemTime | getTimeZone(): Promise\<string>                           | 新增     | 获取系统时区。                                       |
| Ark UI框架-通用事件    | 组件区域变化事件 onAreaChange | 新增      | 新增组件区域（包括大小和位置）变化事件。 |
| Ark UI框架-通用属性 | 触摸热区设置 responseRegion | 新增 | 新增组件触摸热区设置。 |
| Ark UI框架-通用属性 | 点击控制 touchable | 新增 | 新增设置组件是否可以被触摸。 |
| Ark UI框架-通用属性 | 多态样式 stateStyle | 新增 | 新增设置组件按压态和禁用态的样式。 |
| Ark UI框架-通用手势 | SwipeGesture | 新增 | 新增滑动手势。 |
| Ark UI框架-基础组件 | Marquee | 新增 | 新增跑马灯组件。 |
| Ark UI框架-基础组件 | PluginComponent | 新增 | 新增插件组件。 |
| Ark UI框架-基础组件 | TextArea | 新增 | 新增输入区域组件。 |
| Ark UI框架-基础组件 | TextInput | 新增 | 新增输入框组件。 |
| Ark UI框架-基础组件 | Toggle | 新增 | 新增状态组件。 |
| Ark UI框架-容器组件 | ScrollBar | 新增 | 新增滚动条组件。 |
| Ark UI框架-容器组件 | Navigation | 新增 | 新增页面导航组件。 |
| Ark UI框架-容器组件 | Stepper | 新增 | 新增步骤导航器组件。 |
| Ark UI框架-容器组件 | StepperItem | 新增 | 新增步骤导航器导航项组件。 |
| Ark UI框架-画布组件 | Canvas | 新增 | 新增画布组件。 |
| Ark UI框架-画布组件 | Lottie | 新增 | 新增Lottie库的支持。 |
| Ark UI框架-全局UI方法 | ActionSheet | 新增 | 新增列表选择弹窗。 |
| USB服务-usb | getDevices(): Array\<Readonly\<USBDevice>> | 新增      | 新增获取USB设备列表的接口 |
| USB服务-usb | connectDevice(device: USBDevice): Readonly\<USBDevicePipe> | 新增 | 新增根据getDevices()返回的设备信息打开USB设备的接口 |
| USB服务-usb | hasRight(deviceName: string): boolean | 新增 | 新增判断是否有权访问设备的接口 |
| USB服务-usb | requestRight(deviceName: string): Promise\<boolean> | 新增 | 新增请求给定软件包的临时权限以访问设备的接口 |
| USB服务-usb | claimInterface(pipe: USBDevicePipe, iface: USBInterface, force?: boolean): number | 新增 | 新增获取接口的接口 |
| USB服务-usb | releaseInterface(pipe: USBDevicePipe, iface: USBInterface): number | 新增 | 新增释放接口的接口 |
| USB服务-usb | setConfiguration(pipe: USBDevicePipe, config: USBConfig): number | 新增 | 新增设置设备配置的接口 |
| USB服务-usb | setInterface(pipe: USBDevicePipe, iface: USBInterface): number | 新增 | 新增设置设备接口的接口 |
| USB服务-usb | getRawDescriptor(pipe: USBDevicePipe): Uint8Array | 新增 | 新增获取原始的USB描述符的接口 |
| USB服务-usb | getFileDescriptor(pipe: USBDevicePipe): number | 新增 | 新增获取文件描述符的接口 |
| USB服务-usb | controlTransfer(pipe: USBDevicePipe, contrlparam: USBControlParams, timeout?: number): Promise\<number> | 新增 | 新增控制传输的接口 |
| USB服务-usb | bulkTransfer(pipe: USBDevicePipe, endpoint: USBEndpoint, buffer: Uint8Array, timeout?: number): Promise\<number> | 新增 | 新增批量传输的接口 |
| USB服务-usb | closePipe(pipe: USBDevicePipe): number | 新增 | 新增关闭USBDevicePipe的接口 |
| 用户程序框架-bundle                  | cleanBundleCacheFiles(bundleName: string, callback: AsyncCallback\<void>): void;<br/>cleanBundleCacheFiles(bundleName: string): Promise\<void>; | 新增     | 新增清理应用缓存接口                              |
| 用户程序框架-bundle                   | setApplicationEnabled(bundleName: string, isEnable: boolean, callback: AsyncCallback\<void>): void;<br/>setApplicationEnabled(bundleName: string, isEnable: boolean): Promise\<void>; | 新增     | 新增设置应用使能接口                              |
| 用户程序框架-bundle                    | setAbilityEnabled(info: AbilityInfo, isEnable: boolean, callback: AsyncCallback\<void>): void;<br/>setAbilityEnabled(info: AbilityInfo, isEnable: boolean): Promise\<void>; | 新增     | 新增设置ability使能接口                           |
| 用户程序框架-bundle.innerBundleManager | getLauncherAbilityInfos(bundleName: string, userId: number, callback: AsyncCallback\<Array\<LauncherAbilityInfo>>) : void;<br/>getLauncherAbilityInfos(bundleName: string, userId: number) : Promise\<Array\<LauncherAbilityInfo>>; | 新增     | 新增通过包名获取应用LauncherAbility接口           |
| 用户程序框架-bundle.innerBundleManager | on(type:"BundleStatusChange", bundleStatusCallback : BundleStatusCallback, callback: AsyncCallback\<string>) : void;<br/>on(type:"BundleStatusChange", bundleStatusCallback : BundleStatusCallback): Proimise\<string>; | 新增     | 新增注册监听包状态变化接口                        |
| 用户程序框架-bundle.innerBundleManager | off(type:"BundleStatusChange", callback: AsyncCallback\<string>) : void;<br/>off(type:"BundleStatusChange"): Proimise\<string>; | 新增     | 新增注销监听包状态变化接口                        |
| 用户程序框架-bundle.innerBundleManager | getAllLauncherAbilityInfos(userId: number, callback: AsyncCallback\<Array\<LauncherAbilityInfo>>) : void;<br/>getAllLauncherAbilityInfos(userId: number) : Promise\<Array\<LauncherAbilityInfo>>; | 新增     | 新增通过userId获取所有launcher上应用的ability接口 |
| 用户程序框架-bundle.innerBundleManager | getShortcutInfos(bundleName :string, callback: AsyncCallback\<Array\<ShortcutInfo>>) : void;<br/>getShortcutInfos(bundleName : string) : Promise\<Array\<ShortcutInfo>>; | 新增     | 新增通过bundleName获取应用的shortcutInfo接口      |
| 分布式软总线-rpc.MessageParcel | writeNoException(): void | 新增 | - |
| 分布式软总线-rpc.MessageParcel | readException(): void | 新增 | - |
| 分布式软总线-rpc.MessageParcel | writeRemoteObjectArray(objectArray: IRemoteObject[]): boolean | 新增 | - |
| 分布式软总线-rpc.MessageParcel | readSequenceableArray(sequenceableArray Sequenceable[]): void | 新增 | - |
| 分布式软总线-rpc.MessageParcel | readRemoteObjectArray(objects: IRemoteObject[]): void | 新增 | - |
| 分布式软总线-rpc.MessageParcel | readRemoteObjectArray(): IRemoteObject[] | 新增 | - |
| 分布式软总线-rpc.MessageParcel | static closeFileDescriptor(fd: number): void | 新增 | - |
| 分布式软总线-rpc.MessageParcel | static dupFileDescriptor(fd: number) :number | 新增 | - |
| 分布式软总线-rpc.MessageParcel | containFileDescriptors(): boolean | 新增 | - |
| 分布式软总线-rpc.MessageParcel | writeFileDescriptor(fd: number): boolean | 新增 | - |
| 分布式软总线-rpc.MessageParcel | readFileDescriptor(): number | 新增 | - |
| 分布式软总线-rpc.MessageParcel | writeAshmem(ashmem: Ashmem): boolean | 新增 | - |
| 分布式软总线-rpc.MessageParcel | readAshmem(): Ashmem | 新增 | - |
| 分布式软总线-rpc.MessageParcel | getRawDataCapacity(): number | 新增 | - |
| 分布式软总线-rpc.MessageParcel | writeRawData(rawData: number[], size: number): boolean | 新增 | - |
| 分布式软总线-rpc.MessageParcel | readRawData(size: number): number[] | 新增 | - |
| 分布式软总线-rpc | interface SendRequestResult {<br/>         errCode: number;<br/>         code: number;<br/>         data: MessageParcel;<br/>         reply: MessageParcel;<br/>    } | 新增 | - |
| 分布式软总线-rpc.Ashmem | PROT_EXEC = 4 | 新增 | - |
| 分布式软总线-rpc.Ashmem | PROT_NONE = 0 | 新增 | - |
| 分布式软总线-rpc.Ashmem | PROT_READ = 1 | 新增 | - |
| 分布式软总线-rpc.Ashmem | PROT_WRITE = 2 | 新增 | - |
| 分布式软总线-rpc.Ashmem | static createAshmem(name: string, size: number): Ashmem | 新增 | - |
| 分布式软总线-rpc.Ashmem | static createAshmemFromExisting(ashmem: Ashmem): Ashmem | 新增 | - |
| 分布式软总线-rpc.Ashmem | closeAshmem(): void | 新增 | - |
| 分布式软总线-rpc.Ashmem | unmapAshmem(): void | 新增 | - |
| 分布式软总线-rpc.Ashmem | getAshmemSize(): number | 新增 | - |
| 分布式软总线-rpc.Ashmem | mapAshmem(mapType: number): boolean | 新增 | - |
| 分布式软总线-rpc.Ashmem | mapReadAndWriteAshmem(): boolean | 新增 | - |
| 分布式软总线-rpc.Ashmem | mapReadOnlyAshmem(): boolean | 新增 | - |
| 分布式软总线-rpc.Ashmem | setProtection(protectionType: number): boolean | 新增 | - |
| 分布式软总线-rpc.Ashmem | writeToAshmem(buf: number[], size: number, offset: number): boolean | 新增 | - |
| 分布式软总线-rpc.Ashmem | readFromAshmem(size: number, offset: number): number[] | 新增 | - |
| 分布式软总线-rpc.IRemoteObject | sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean | 废弃 | 替换为异步接口，使用返回Promise或者回调的接口 |
| 分布式软总线-rpc.IRemoteObject | sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult> | 新增 | - |
| 分布式软总线-rpc.IRemoteObject | sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void | 新增 | - |
| 分布式软总线-rpc.RemoteProxy | sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean | 废弃 | 替换为异步接口，使用返回Promise或者回调的接口 |
| 分布式软总线-rpc.RemoteProxy | sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult> | 新增 | - |
| 分布式软总线-rpc.RemoteProxy | sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void | 新增 | - |
| 分布式软总线-rpc.RemoteObject | sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): boolean | 废弃 | 替换为异步接口，使用返回Promise或者回调的接口 |
| 分布式软总线-rpc.RemoteObject | sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption): Promise\<SendRequestResult> | 新增 | - |
| 分布式软总线-rpc.RemoteObject | sendRequest(code: number, data: MessageParcel, reply: MessageParcel, options: MessageOption, callback: AsyncCallback\<SendRequestResult>): void | 新增 | - |
| 分布式软总线-rpc.IRemoteObject | PING_TRANSACTION | 删除 | API 7没有实现，不影响已有应用 |
| 分布式软总线-rpc.IRemoteObject | DUMP_TRANSACTION | 删除 | API 7没有实现，不影响已有应用 |
| 分布式软总线-rpc.IRemoteObject | INTERFACE_TRANSACTION | 删除 | API 7没有实现，不影响已有应用 |
| 分布式软总线-rpc.IRemoteObject | MIN_TRANSACTION_ID | 删除 | API 7没有实现，不影响已有应用 |
| 分布式软总线-rpc.IRemoteObject | MAX_TRANSACTION_ID | 删除 | API 7没有实现，不影响已有应用 |
| 分布式软总线-rpc.Sequenceable | hasFileDescriptor(): boolean | 删除 | API 7可序列化对象定义的方法，rpc框架不会调用，不影响已有应用 |
| 分布式软总线-rpc.MessageOption | constructor(syncFlags?: number, waitTime = TF_WAIT_TIME) | 新增 | - |
| 分布式软总线-rpc.MessageOption | getFlags(): number | 新增 | - |
| 分布式软总线-rpc.MessageOption | setFlags(flags: number): void | 新增 | - |
| 分布式软总线-rpc.MessageOption | getWaitTime(): number | 新增 | - |
| 分布式软总线-rpc.MessageOption | setWaitTime(waitTime: number): void | 新增 | - |
| 分布式软总线-rpc.MessageOption | MAX_WAIT_TIME  = 3000 | 删除 | API 7没有实现，不影响已有应用 |
| 分布式软总线-rpc.RemoteObject | constructor(descriptor: string) | 新增 | - |
| 分布式软总线-rpc.RemoteObject | queryLocalInterface(descriptor: string): IRemoteBroker | 修改 | API 7有误，返回类型更正为IRemoteBroker，不影响已有应用 |
| 分布式软总线-rpc.Proxy | PING_TRANSACTION | 新增 | - |
| 分布式软总线-rpc.Proxy | DUMP_TRANSACTION | 新增 | - |
| 分布式软总线-rpc.Proxy | INTERFACE_TRANSACTION | 新增 | - |
| 分布式软总线-rpc.Proxy | MIN_TRANSACTION_ID = 0x1 | 新增 | - |
| 分布式软总线-rpc.Proxy | MAX_TRANSACTION_ID = 0x00FFFFFF | 新增 | - |
| 分布式软总线-rpc.Proxy | queryLocalInterface(interface: string): IRemoteBroker | 修改 | API 7有误，返回类型更正为IRemoteBroker，不影响已有应用 |
| 分布式软总线-wifi | getLinkedInfo(): Promise\<WifiLinkedInfo>;<br/>getLinkedInfo(callback: AsyncCallback\<WifiLinkedInfo>): void; | 新增 | - |
| 分布式软总线-wifi | isConnected(): boolean; | 新增 | - |
| 分布式软总线-wifi | getSupportedFeatures(): number; | 新增 | - |
| 分布式软总线-wifi | isFeatureSupported(featureId: number): boolean; | 新增 | - |
| 分布式软总线-wifi | getDeviceMacAddress(): string[]; | 新增 | - |
| 分布式软总线-wifi | getIpInfo(): IpInfo; | 新增 | - |
| 分布式软总线-wifi | getCountryCode(): string; | 新增 | - |
| 分布式软总线-wifi | reassociate(): boolean; | 新增 | - |
| 分布式软总线-wifi | reconnect(): boolean; | 新增 | - |
| 分布式软总线-wifi | getDeviceConfigs(): Array\<WifiDeviceConfig>; | 新增 | - |
| 分布式软总线-wifi | updateNetwork(config: WifiDeviceConfig): number; | 新增 | - |
| 分布式软总线-wifi | disableNetwork(netId: number): boolean; | 新增 | - |
| 分布式软总线-wifi | removeAllNetwork(): boolean; | 新增 | - |
| 分布式软总线-wifi | removeDevice(id: number): boolean; | 新增 | - |
| 分布式软总线-wifi | enableHotspot(): boolean; | 新增 | - |
| 分布式软总线-wifi | disableHotspot(): boolean; | 新增 | - |
| 分布式软总线-wifi | isHotspotActive(): boolean; | 新增 | - |
| 分布式软总线-wifi | setHotspotConfig(config: HotspotConfig): boolean; | 新增 | - |
| 分布式软总线-wifi | getHotspotConfig(): HotspotConfig; | 新增 | - |
| 分布式软总线-wifi | getStations(): Array\<StationInfo>; | 新增 | - |
| 分布式软总线-wifi | on(type: "wifiStateChange", callback: Callback\<number>): void; | 新增 | - |
| 分布式软总线-wifi | off(type: "wifiStateChange", callback?: Callback\<number>): void; | 新增 | - |
| 分布式软总线-wifi | on(type: "wifiConnectionChange", callback: Callback\<number>): void; | 新增 | - |
| 分布式软总线-wifi | off(type: "wifiConnectionChange", callback?: Callback\<number>): void; | 新增 | - |
| 分布式软总线-wifi | on(type: "wifiScanStateChange", callback: Callback\<number>): void; | 新增 | - |
| 分布式软总线-wifi | off(type: "wifiScanStateChange", callback?: Callback\<number>): void; | 新增 | - |
| 分布式软总线-wifi | on(type: "wifiRssiChange", callback: Callback\<number>): void; | 新增 | - |
| 分布式软总线-wifi | off(type: "wifiRssiChange", callback?: Callback\<number>): void; | 新增 | - |
| 分布式软总线-wifi | on(type: "hotspotStateChange", callback: Callback\<number>): void; | 新增 | - |
| 分布式软总线-wifi | off(type: "hotspotStateChange", callback?: Callback\<number>): void; | 新增 | - |
| 分布式软总线-wifi | on(type: "hotspotStaJoin", callback: Callback\<StationInfo>): void; | 新增 | - |
| 分布式软总线-wifi | off(type: "hotspotStaJoin", callback?: Callback\<StationInfo>): void; | 新增 | - |
| 分布式软总线-wifi | on(type: "hotspotStaLeave", callback: Callback\<StationInfo>): void; | 新增 | - |
| 分布式软总线-wifi | off(type: "hotspotStaLeave", callback?: Callback\<StationInfo>): void; | 新增 | - |
| 全球化-resourceManager | getRawFile(path: string, callback: AsyncCallback\<Uint8Array>);<br/>getRawFile(path: string): Promise\<Uint8Array>; | 新增 | - |
| 全球化-Intl | RelativeTimeFormat.constructor(); | 新增 | 构造函数 |
| 全球化-Intl | RelativeTimeFormat.constructor(locale: string \| Array\<string>, options?: RelativeTimeFormatInputOptions); | 新增 | 构造函数 |
| 全球化-Intl | RelativeTimeFormat.format(value: number, unit: string): string; | 新增 | 相对时间格式化 |
| 全球化-Intl | RelativeTimeFormat.formatToParts(value: number, unit: string): Array\<object>; | 新增 | 相对时间格式化，结果分为多部份分别存储 |
| 全球化-Intl | RelativeTimeFormat.formatToParts(value: number, unit: string): Array\<object>; | 新增 | 相对时间格式化，结果分为多部份分别存储 |
| 全球化-Intl | PluralRules.constructor(); | 新增 | 构造函数 |
| 全球化-Intl | PluralRules.constructor(locale: string \| Array\<string>, options?: PluralRulesOptions); | 新增 | 构造函数 |
| 全球化-Intl | PluralRules.select(n: number): string; | 新增 | 计算一个数字的单复数类别 |
| 全球化-Intl | Collator.constructor(); | 新增 | 构造函数 |
| 全球化-Intl | Collator.constructor(locale: string \| Array\<string>, options?: CollatorOptions); | 新增 | 构造函数 |
| 全球化-Intl | Collator.compare(first: string, second: string): number; | 新增 | 比较两个字符串 |
| 全球化-Intl | Collator.resolvedOptions(): CollatorOptions; | 新增 | 获取排序对象相关属性 |
| 全球化-I18N | unitConvert(fromUnit: UnitInfo, toUnit: UnitInfo, value: number, locale: string, style?: string): string; | 新增 | 新增转换单位接口 |
| 全球化-I18N | constructor(country: string, options?: PhoneNumberFormatOptions);<br/>isValidNumber(number: string): boolean;<br/>format(number: string): string; | 新增 | 新增电话号码格式化接口 |
| 全球化-I18N | setTime(date: Date);<br/>setTime(time: number);<br/>set(year: number, month: number, date:number, hour?: number, minute?: number, second?: number);<br/>setTimeZone(timezone: string);<br/>getTimeZone(): string;<br/>getFirstDayOfWeek(): number;<br/>setFirstDayOfWeek(value: number);<br/>getMinimalDaysInFirstWeek(): number;<br/>setMinimalDaysInFirstWeek(value: number);<br/>get(field: string): number;<br/>getDisplayName(locale: string): string;<br/>isWeekend(date?: Date): boolean;<br/>export getCalendar(locale: string, type?: string): Calendar; | 新增 | 新增日历接口 |
| 全球化-I18N | isRTL(locale: string): boolean; | 新增 | 判断区域语言是否是从右到左语言 |
| 全球化-I18N | getLineInstance(locale: string): BreakIterator;<br/>current(): number;<br/>first(): number;<br/>last(): number;<br/>next(index?: number): number;<br/>previous(): number;<br/>setLineBreakText(text: string): void;<br/>following(offset: number): number;<br/>getLineBreakText(): string;<br/>isBoundary(offset: number): boolean; | 新增 | 新增断词换行接口 |
| 全球化-I18N | getInstance(locale?:string): IndexUtil;<br/>getIndexList(): Array\<string>; | 新增 | 新增获取字母表索引接口 |
| 全球化-I18N | addLocale(locale: string);<br/>getIndex(text: string): string;<br/>isDigit(char: string): boolean;<br/>isSpaceChar(char: string): boolean;<br/>isWhitespace(char: string): boolean;<br/>isRTL(char: string): boolean;<br/>isIdeograph(char: string): boolean;<br/>isLetter(char: string): boolean;<br/>isLowerCase(char: string): boolean;<br/>isUpperCase(char: string): boolean;<br/>getType(char: string): string; | 新增 | 新增获取字符属性接口 |
| 事件通知-DoNotDisturbDate | type: notification.DoNotDisturbType | 新增      | 免打扰设置的时间类型 |
| 事件通知-DoNotDisturbDate | begin: Date | 新增 | 免打扰设置的起点时间 |
| 事件通知-DoNotDisturbDate | end: Date | 新增 | 免打扰设置的终点时间 |
| 事件通知-DoNotDisturbDate | export enum DoNotDisturbType {<br/>    TYPE_NONE = 0,         // 非通知勿扰类型<br/>    TYPE_ONCE = 1,         // 以设置时间段一次执行勿扰<br/>    TYPE_DAILY = 2,        // 以设置时间段(只看小时和分钟)每天执行勿扰<br/>    TYPE_CLEARLY = 3,        // 以设置时间段(明确年月日时分)执行勿扰<br/>} | 新增 | 免打扰时间类型 |
| 事件通知-notification | setDoNotDisturbDate(date DoNotDisturbDate, callback: AsyncCallback\<void>): void | 新增 | 设置免打扰时间接口 |
| 事件通知-notification | setDoNotDisturbDate(date DoNotDisturbDate): Promise\<void> | 新增 | 设置免打扰时间接口 |
| 事件通知-notification | getDoNotDisturbDate(callback: AsyncCallback\<DoNotDisturbDate>): void | 新增 | 查询免打扰时间接口 |
| 事件通知-notification | getDoNotDisturbDate(): Promise\<DoNotDisturbDate> | 新增 | 查询免打扰时间接口 |
| 事件通知-notification | supportDoNotDisturbMode(callback: AsyncCallback\<boolean>): void | 新增 | 是否支持勿扰模式功能 |
| 事件通知-notification | supportDoNotDisturbMode(): Promise\<boolean> | 新增 | 是否支持勿扰模式功能 |
| 事件通知-notification | cancelGroup(groupName: string, callback: AsyncCallback\<void>): void | 新增     | 取消本应用指定组通知                                         |
| 事件通知-notification        | cancelGroup(groupName: string): Promise\<void> | 新增 | 取消本应用指定组通知 |
| 事件通知-notification        | removeGroupByBundle(bundle: BundleOption, groupName: string, callback: AsyncCallback\<void>): void | 新增 | 删除指定应用指定组通知 |
| 事件通知-notification        | removeGroupByBundle(bundle: BundleOption, groupName: string): Promise\<void> | 新增 | 删除指定应用指定组通知 |
| 事件通知-NotificationSubscriber | onDoNotDisturbDateChange?:(mode: notification.DoNotDisturbDate) => void | 新增 | 免打扰设置信息变更后的通知给订阅者 |
| 事件通知-NotificationRequest | smallIcon?: image.PixelMap | 新增 | 小图标 |
| 事件通知-NotificationRequest | largeIcon?: image.PixelMap; | 新增 | 大图标 |
| 事件通知-NotificationRequest | groupName?: string; | 新增 | 通知分组名称 |
| 事件通知-NotificationUserInput |                                                              | 新增     | 用户输入对象 |
| 事件通知-NotificationUserInput | inputKey: string | 新增 | 用户输入时用于标识此输入的key |
| 事件通知-NotificationActionButton | userInput?: NotificationUserInput | 新增 | 用户输入对象实例 |
| 事件通知-emitter | on(event: InnerEvent, callback: Callback\<EventData>): void | 新增 | 持续订阅某个事件以及接收事件的回调处理 |
| 事件通知-emitter | once(event: InnerEvent, callback: Callback\<EventData>): void | 新增 | 单次订阅某个事件以及接收事件的回调处理，接收到回调处理后自动取消订阅 |
| 事件通知-emitter | off(eventId: number): void | 新增 | 取消订阅某个事件 |
| 事件通知-emitter | emit(event: InnerEvent, data?: EventData): void | 新增 | 发送一个事件到事件队列 |
| 分布式文件-statfs | getFreeBytes(path: string, callback: AsyncCallback\<number>): void | 新增      | 以callback形式异步获取设备剩余空间，单位为字节 |
| 分布式文件-statfs | getFreeBytes(path: string): Promise\<number> | 新增 | 以promise形式异步获取设备剩余空间，单位为字节 |
| 分布式文件-statfs | getTotalBytes(path: string, callback: AsyncCallback\<number>): void | 新增 | 以callback形式异步获取设备总空间，单位为字节 |
| 分布式文件-statfs | getTotalBytes(path: string): Promise\<number> | 新增 | 以promise形式异步获取设备总空间，单位为字节 |
| 分布式任务调度-featureAbility      | continueAbility(options: ContinueAbilityOptions, callback: AsyncCallback\<void>): void;<br/>continueAbility(options: ContinueAbilityOptions): Promise\<void>; | 新增      | -      |
| 语言编译运行时-URI | constructor(uri: string); | 新增 |  |
| 语言编译运行时-URI | toString(): string | 新增 |  |
| 语言编译运行时-URI            | equals(other: URI): boolean;                                 | 新增     |          |
| 语言编译运行时-URI            | checkIsAbsolute(): boolean;                                  | 新增     |          |
| 语言编译运行时-URI            | normalize(): URI;                                            | 新增     |          |
| 语言编译运行时-URI            | scheme: string;                                              | 新增     |          |
| 语言编译运行时-URI            | userinfo: string;                                            | 新增     |          |
| 语言编译运行时-URI            | host: string;                                                | 新增     |          |
| 语言编译运行时-URI            | port: string;                                                | 新增     |          |
| 语言编译运行时-URI            | path: string;                                                | 新增     |          |
| 语言编译运行时-URI            | query: string;                                               | 新增     |          |
| 语言编译运行时-URI            | query: string;                                               | 新增     |          |
| 语言编译运行时-URI            | authority: string;                                           | 新增     |          |
| 语言编译运行时-URI            | ssp: string;                                                 | 新增     |          |
| 语言编译运行时-RationalNumber | constructor(numerator: number, denominator: number);         | 新增     |          |
| 语言编译运行时-RationalNumber | static createRationalFromString(rationalString: string): RationalNumber; | 新增     |  |
| 语言编译运行时-RationalNumber | compareTo(another :RationalNumber): number; | 新增     |  |
| 语言编译运行时-RationalNumber | equals(obj: Object): boolean; | 新增     |  |
| 语言编译运行时-RationalNumber | valueOf(): number; | 新增     |  |
| 语言编译运行时-RationalNumber | static getCommonDivisor(number1: number, number2: number): number; | 新增     |  |
| 语言编译运行时-RationalNumber | getDenominator(): number; | 新增     |  |
| 语言编译运行时-RationalNumber | getNumerator(): number; | 新增     |  |
| 语言编译运行时-RationalNumber | isFinite() : boolean; | 新增     |  |
| 语言编译运行时-RationalNumber | isNaN(): boolean; | 新增     |  |
| 语言编译运行时-RationalNumber | isZero(): boolean; | 新增     |  |
| 语言编译运行时-RationalNumber | toString(): string; | 新增     |  |
| 语言编译运行时-LruBuffer | constructor(capacity?:number); | 新增     |  |
| 语言编译运行时-LruBuffer | updateCapacity(newCapacity: number):void | 新增     |  |
| 语言编译运行时-LruBuffer | toString():string | 新增     |  |
| 语言编译运行时-LruBuffer | length:number | 新增     |  |
| 语言编译运行时-LruBuffer | getCapacity(): number; | 新增     |  |
| 语言编译运行时-LruBuffer | clear(): void; | 新增     |  |
| 语言编译运行时-LruBuffer | getCreateCount(): number; | 新增     |  |
| 语言编译运行时-LruBuffer | getMissCount(): number; | 新增     |  |
| 语言编译运行时-LruBuffer | getRemovalCount(): number; | 新增     |  |
| 语言编译运行时-LruBuffer | getMatchCount(): number; | 新增     |  |
| 语言编译运行时-LruBuffer | getPutCount(): number; | 新增     |  |
| 语言编译运行时-LruBuffer | isEmpty(): boolean; | 新增     |  |
| 语言编译运行时-LruBuffer | get(key: K): V \| undefined; | 新增     |  |
| 语言编译运行时-LruBuffer | put(key: K, value: V): V; | 新增     |  |
| 语言编译运行时-LruBuffer | values(): V[]; | 新增     |  |
| 语言编译运行时-LruBuffer | keys(): K[]; | 新增     |  |
| 语言编译运行时-LruBuffer | remove(key: K): V \| undefined; | 新增     |  |
| 语言编译运行时-LruBuffer | afterRemoval(isEvict: boolean, key: K, value: V, newValue: V): void; | 新增     |  |
| 语言编译运行时-LruBuffer | contains(key: K): boolean; | 新增     |  |
| 语言编译运行时-LruBuffer | createDefault(key: K): V; | 新增     |  |
| 语言编译运行时-LruBuffer | entries(): IterableIterator\<[K, V]>; | 新增     |  |
| 语言编译运行时-LruBuffer | \[Symbol.iterator]\(): IterableIterator\<[K, V]>; | 新增     |  |
| 语言编译运行时-Scope | constructor(lowerObj: ScopeType, upperObj: ScopeType); | 新增     |  |
| 语言编译运行时-Scope | toString(): string; | 新增     |  |
| 语言编译运行时-Scope | intersect(range: Scope): Scope; | 新增     |  |
| 语言编译运行时-Scope | intersect(lowerObj: ScopeType, upperObj: ScopeType): Scope; | 新增     |  |
| 语言编译运行时-Scope | getUpper(): ScopeType; | 新增     |  |
| 语言编译运行时-Scope | getLower(): ScopeType; | 新增     |  |
| 语言编译运行时-Scope | expand(lowerObj: ScopeType, upperObj: ScopeType): Scope; | 新增     |  |
| 语言编译运行时-Scope | expand(range: Scope): Scope; | 新增     |  |
| 语言编译运行时-Scope | expand(value: ScopeType): Scope; | 新增     |  |
| 语言编译运行时-Scope | contains(value: ScopeType): boolean; | 新增     |  |
| 语言编译运行时-Scope | contains(range: Scope): boolean; | 新增     |  |
| 语言编译运行时-Scope | clamp(value: ScopeType): ScopeType; | 新增     |  |
| 语言编译运行时-Base64 | constructor(); | 新增     |  |
| 语言编译运行时-Base64 | encodeSync(src: Uint8Array): Uint8Array; | 新增     |  |
| 语言编译运行时-Base64 | encodeToStringSync(src: Uint8Array): string; | 新增     |  |
| 语言编译运行时-Base64 | decodeSync(src: Uint8Array \| string): Uint8Array; | 新增     |  |
| 语言编译运行时-Base64 | encode(src: Uint8Array): Promise\<Uint8Array>; | 新增     |  |
| 语言编译运行时-Base64 | encodeToString(src: Uint8Array): Promise\<string>; | 新增     |  |
| 语言编译运行时-Base64 | decode(src: Uint8Array \| string): Promise\<Uint8Array>; | 新增     |  |
| 语言编译运行时-types | constructor(); | 新增     |  |
| 语言编译运行时-types | isAnyArrayBuffer(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isArrayBufferView(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isArgumentsObject(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isArrayBuffer(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isAsyncFunction(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isBigInt64Array(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isBigUint64Array(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isBooleanObject(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isBoxedPrimitive(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isDataView(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isDate(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isExternal(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isFloat32Array(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isFloat64Array(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isGeneratorFunction(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isGeneratorObject(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isInt8Array(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isInt16Array(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isInt32Array(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isMap(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isMapIterator(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isModuleNamespaceObject(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isNativeError(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isNumberObject(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isPromise(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isProxy(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isRegExp(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isSet(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isSetIterator(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isSharedArrayBuffer(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isStringObject(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isSymbolObject(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isTypedArray(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isUint8Array(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isUint8ClampedArray(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isUint16Array(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isUint32Array(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isWeakMap(value: Object): boolean; | 新增     |  |
| 语言编译运行时-types | isWeakSet(value: Object): boolean; | 新增     |  |
| 语言编译运行时-process | const tid: number; | 新增     |  |
| 语言编译运行时-process | isIsolatedProcess(): boolean; | 新增     |  |
| 语言编译运行时-process | isAppUid(v: number): boolean; | 新增     |  |
| 语言编译运行时-process | is64Bit(): boolean; | 新增     |  |
| 语言编译运行时-process | getUidForName(v: string): number; | 新增     |  |
| 语言编译运行时-process | getThreadPriority(v: number): number; | 新增     |  |
| 语言编译运行时-process | getStartRealtime(): number; | 新增     |  |
| 语言编译运行时-process | getAvailableCores(): number[]; | 新增     |  |
| 语言编译运行时-process | getPastCpuTime(): number; | 新增     |  |
| 语言编译运行时-process | getSystemConfig(name: number): number; | 新增     |  |
| 语言编译运行时-process | getEnvironmentVar(name: string): string; | 新增     |  |
| 语言编译运行时-ConvertOptions | trim: boolean; | 新增     |  |
| 语言编译运行时-ConvertOptions | ignoreDeclaration?: boolean; | 新增     |  |
| 语言编译运行时-ConvertOptions | ignoreInstruction?: boolean; | 新增     |  |
| 语言编译运行时-ConvertOptions | ignoreAttributes?: boolean; | 新增     |  |
| 语言编译运行时-ConvertOptions | ignoreComment?: boolean; | 新增     |  |
| 语言编译运行时-ConvertOptions | ignoreCdata?: boolean; | 新增     |  |
| 语言编译运行时-ConvertOptions | ignoreDoctype?: boolean; | 新增     |  |
| 语言编译运行时-ConvertOptions | ignoreText?: boolean; | 新增     |  |
| 语言编译运行时-ConvertOptions | declarationKey: string; | 新增     |  |
| 语言编译运行时-ConvertOptions | instructionKey: string; | 新增     |  |
| 语言编译运行时-ConvertOptions | attributesKey: string; | 新增     |  |
| 语言编译运行时-ConvertOptions | textKey: string; | 新增     |  |
| 语言编译运行时-ConvertOptions | cdataKey: string; | 新增     |  |
| 语言编译运行时-ConvertOptions | doctypeKey: string; | 新增     |  |
| 语言编译运行时-ConvertOptions | commentKey: string; | 新增     |  |
| 语言编译运行时-ConvertOptions | parentKey: string; | 新增     |  |
| 语言编译运行时-ConvertOptions | typeKey: string; | 新增     |  |
| 语言编译运行时-ConvertOptions | nameKey: string; | 新增     |  |
| 语言编译运行时-ConvertOptions | elementsKey: string; | 新增     |  |
| 语言编译运行时-ConvertXML | convert(xml: string, options?: ConvertOptions) : Object; | 新增     |  |
| 语言编译运行时-XmlSerializer | constructor(buffer: ArrayBuffer \| DataView, encoding?: string); | 新增     |  |
| 语言编译运行时-XmlSerializer | setAttributes(name: string, value: string): void; | 新增     |  |
| 语言编译运行时-XmlSerializer | addEmptyElement(name: string): void; | 新增     |  |
| 语言编译运行时-XmlSerializer | setDeclaration(): void; | 新增     |  |
| 语言编译运行时-XmlSerializer | startElement(name: string): void; | 新增     |  |
| 语言编译运行时-XmlSerializer | endElement(): void; | 新增     |  |
| 语言编译运行时-XmlSerializer | setNamespace(prefix: string, namespace: string): void; | 新增     |  |
| 语言编译运行时-XmlSerializer | setCommnet(text: string): void; | 新增     |  |
| 语言编译运行时-XmlSerializer | setCData(text: string): void; | 新增     |  |
| 语言编译运行时-XmlSerializer | setText(text: string): void; | 新增     |  |
| 语言编译运行时-XmlSerializer | setDocType(text: string): void; | 新增     |  |
| 语言编译运行时-ParseOptions | supportDoctype?: boolean; | 新增     |  |
| 语言编译运行时-ParseOptions | ignoreNameSpace?: boolean; | 新增     |  |
| 语言编译运行时-ParseOptions | tagValueCallbackFunction?: (name: string, value: string) => boolean; | 新增     |  |
| 语言编译运行时-ParseOptions | attributeValueCallbackFunction?: (name: string, value: string) => boolean; | 新增     |  |
| 语言编译运行时-ParseOptions | tokenValueCallbackFunction?: (eventType: EventType, value: ParseInfo) => boolean; | 新增     |  |
| 帐号-account.appAccount | createAppAccountManager | 新增 | 获取实例 |
| 帐号-account.appAccount | addAccount(name: string, callback: AsyncCallback\<void>): void;<br/>addAccount(name: string, extraInfo: string, callback: AsyncCallback\<void>): void;<br/>addAccount(name: string, extraInfo?: string): Promise\<void>; | 新增 | 添加应用帐户 |
| 帐号-account.appAccount | deleteAccount(name: string, callback: AsyncCallback\<void>): void;<br/>deleteAccount(name: string): Promise\<void>; | 新增 | 删除应用帐户 |
| 帐号-account.appAccount | disableAppAccess(name: string, bundleName: string, callback: AsyncCallback\<void>): void;<br/>disableAppAccess(name: string, bundleName: string): Promise\<void>; | 新增 | 使指定的package拒绝访问给定的应用帐号 |
| 帐号-account.appAccount | enableAppAccess(name: string, bundleName: string, callback: AsyncCallback\<void>): void;<br/>enableAppAccess(name: string, bundleName: string): Promise\<void>; | 新增 | 使指定的package允许访问给定的应用帐号 |
| 帐号-account.appAccount | checkAppAccountSyncEnable(name: string, callback: AsyncCallback\<boolean>): void;<br/>checkAppAccountSyncEnable(name: string): Promise\<boolean>; | 新增 | 检查指定的应用帐号是否允许应用程序同步数据 |
| 帐号-account.appAccount | setAccountCredential(name: string, credentialType: string, credential: string,<br/>                     callback: AsyncCallback\<void>): void;<br/>setAccountCredential(name: string, credentialType: string, credential: string): Promise\<void>; | 新增 | 设置指定应用程序帐号的认证凭据 |
| 帐号-account.appAccount | setAccountExtraInfo(name: string, extraInfo: string, callback: AsyncCallback\<void>): void;<br/>setAccountExtraInfo(name: string, extraInfo: string): Promise\<void>; | 新增 | 设置指定应用帐号的附加信息 |
| 帐号-account.appAccount | setAppAccountSyncEnable(name: string, isEnable: boolean, callback: AsyncCallback\<void>): void;<br/>setAppAccountSyncEnable(name: string, isEnable: boolean): Promise\<void>; | 新增 | 设置指定的应用程序帐号是否允许应用程序同步数据 |
| 帐号-account.appAccount | setAssociatedData(name: string, key: string, value: string, callback: AsyncCallback\<void>): void;<br/>setAssociatedData(name: string, key: string, value: string): Promise\<void>; | 新增 | 设置应用帐号关联信息 |
| 帐号-account.appAccount | getAllAccessibleAccounts(callback: AsyncCallback\<Array\<AppAccountInfo>>): void;<br/>getAllAccessibleAccounts(): Promise\<Array\<AppAccountInfo>>; | 新增 | 获取本应用帐号信息和已授权给本应用的第三方应用帐号的信息 |
| 帐号-account.appAccount | getAllAccounts(owner: string, callback: AsyncCallback\<Array\<AppAccountInfo>>): void;<br/>getAllAccounts(owner: string): Promise\<Array\<AppAccountInfo>>; | 新增 | 获取执行应用下全部帐号信息 |
| 帐号-account.appAccount | getAccountCredential(name: string, credentialType: string, callback: AsyncCallback\<string>): void;<br/>getAccountCredential(name: string, credentialType: string): Promise\<string>; | 新增 | 获取指定应用程序帐号的认证凭据 |
| 帐号-account.appAccount | getAccountExtraInfo(name: string, callback: AsyncCallback\<string>): void;<br/>getAccountExtraInfo(name: string): Promise\<string>; | 新增 | 获取应用帐号附加信息 |
| 帐号-account.appAccount | getAssociatedData(name: string, key: string, callback: AsyncCallback\<string>): void;<br/>getAssociatedData(name: string, key: string): Promise\<string>; | 新增 | 获取应用帐号关联信息 |
| 帐号-account.appAccount| on(type: 'change', owners: Array\<string>, callback: Callback\<Array\<AppAccountInfo>>): void; | 新增 | 订阅指定应用帐号的更改事件 |
| 帐号-account.appAccount | off(type: 'change', callback?: Callback\<void>): void; | 新增 | 取消订阅应用帐号的更改事件 |
| 帐号-account.appAccount | interface AppAccountInfo | 新增 | 应用帐号信息 |
| 泛Sensor服务-sensor   | on(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: AsyncCallback\<AccelerometerResponse>,options?: Options): void | 新增     | 监听加速度传感器的数据变化             |
| 泛Sensor服务-sensor   | on(type:SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION,callback:AsyncCallback\<LinearAccelerometerResponse>, options?: Options): void | 新增     | 监听线性加速度传感器的数据变化         |
| 泛Sensor服务-sensor   | on(type:SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED,callback:AsyncCallback\<AccelerometerUncalibratedResponse>, options?: Options): void | 新增     | 监听未校准加速度计传感器的数据变化     |
| 泛Sensor服务-sensor   | on(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback: AsyncCallback\<GravityResponse>,options?: Options): void | 新增     | 监听重力传感器的数据变化               |
| 泛Sensor服务-sensor   | on(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: AsyncCallback\<GyroscopeResponse>, options?: Options): void | 新增     | 监听陀螺仪传感器的数据变化             |
| 泛Sensor服务-sensor   | on(type:SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED,callback:AsyncCallback\<GyroscopeUncalibratedResponse>, options?: Options): void | 新增     | 监听未校准陀螺仪传感器的数据变化       |
| 泛Sensor服务-sensor   | on(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback: AsyncCallback\<SignificantMotionResponse>, options?: Options): void | 新增     | 监听大幅动作传感器数据变化             |
| 泛Sensor服务-sensor   | on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback: AsyncCallback\<PedometerDetectResponse>, options?: Options): void | 新增     | 监听计步检测传感器的数据变化           |
| 泛Sensor服务-sensor   | on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: AsyncCallback\<PedometerResponse>, options?: Options): void | 新增     | 监听计步传感器的数据变化               |
| 泛Sensor服务-sensor   | on(type:SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,callback:AsyncCallback\<AmbientTemperatureResponse>,  options?: Options): void | 新增     | 监听环境温度传感器的数据变化           |
| 泛Sensor服务-sensor   | on(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: AsyncCallback\<MagneticFieldResponse>,options?: Options): void | 新增     | 监听磁场传感器的数据变化               |
| 泛Sensor服务-sensor   | on(type:SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED,callback:AsyncCallback\<MagneticFieldUncalibratedResponse>, options: Options): void | 新增     | 监听未校准磁场传感器的数据变化         |
| 泛Sensor服务-sensor   | on(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: AsyncCallback\<ProximityResponse>,options?: Options): void | 新增     | 监听接近光传感器的数据变化             |
| 泛Sensor服务-sensor   | on(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: AsyncCallback\<HumidityResponse>,options?: Options): void | 新增     | 监听湿度传感器的数据变化               |
| 泛Sensor服务-sensor   | on(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: AsyncCallback\<BarometerResponse>,options?: Options): void | 新增     | 监听气压计传感器的数据变化             |
| 泛Sensor服务-sensor   | on(type: SensorType.SENSOR_TYPE_ID_HALL, callback: AsyncCallback\<HallResponse>, options?: Options): void | 新增     | 监听霍尔传感器的数据变化               |
| 泛Sensor服务-sensor   | on(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: AsyncCallback\<LightResponse>, options?: Options): void | 新增     | 监听环境光传感器的数据变化             |
| 泛Sensor服务-sensor   | on(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: AsyncCallback\<OrientationResponse>, options?: Options): void | 新增     | 监听方向传感器的数据变化               |
| 泛Sensor服务-sensor   | on(type:SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR,callback:AsyncCallback\<RotationVectorResponse>,options?: Options): void | 新增     | 监听旋转矢量传感器的数据变化           |
| 泛Sensor服务-sensor   | on(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: AsyncCallback\<WearDetectionResponse>,options?: Options): void | 新增     | 监听佩戴检测传感器的数据变化           |
| 泛Sensor服务-sensor   | once(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: AsyncCallback\<AccelerometerResponse>): void | 新增     | 监听加速度传感器的数据变化一次         |
| 泛Sensor服务-sensor   | once(type:SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION,callback:AsyncCallback\<LinearAccelerometerResponse>): void | 新增     | 监听线性加速度传感器的数据变化一次     |
| 泛Sensor服务-sensor   | once(type:SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED,callback:AsyncCallback\<AccelerometerUncalibratedResponse>): void | 新增     | 监听未校准加速度计传感器的数据变化一次 |
| 泛Sensor服务-sensor   | once(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback: AsyncCallback\<GravityResponse>): void | 新增     | 监听重力传感器的数据变化一次           |
| 泛Sensor服务-sensor   | once(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: AsyncCallback\<GyroscopeResponse>): void | 新增     | 监听陀螺仪传感器的数据变化一次         |
| 泛Sensor服务-sensor   | once(type:SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED,callback:AsyncCallback\<GyroscopeUncalibratedResponse>, options?: Options): void | 新增     | 监听未校准陀螺仪传感器的数据变化一次   |
| 泛Sensor服务-sensor   | once(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback: AsyncCallback\<SignificantMotionResponse>): void | 新增     | 监听大幅动作传感器数据变化一次         |
| 泛Sensor服务-sensor   | once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback: AsyncCallback\<PedometerDetectResponse>): void | 新增     | 监听计步检测传感器的数据变化一次       |
| 泛Sensor服务-sensor   | once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: AsyncCallback\<PedometerResponse>): void | 新增     | 监听计步传感器的数据变化一次           |
| 泛Sensor服务-sensor   | once(type:SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE,callback:AsyncCallback\<AmbientTemperatureResponse>): void | 新增     | 监听环境温度传感器的数据变化一次       |
| 泛Sensor服务-sensor   | once(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: AsyncCallback\<MagneticFieldResponse>): void | 新增     | 监听磁场传感器的数据变化一次           |
| 泛Sensor服务-sensor   | once(type:SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED,callback:AsyncCallback\<MagneticFieldUncalibratedResponse>): void | 新增     | 监听未校准磁场传感器的数据变化一次     |
| 泛Sensor服务-sensor   | once(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: AsyncCallback\<ProximityResponse>): void | 新增     | 监听接近光传感器的数据变化一次         |
| 泛Sensor服务-sensor   | once(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: AsyncCallback\<HumidityResponse>): void | 新增     | 监听湿度传感器的数据变化一次           |
| 泛Sensor服务-sensor   | once(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: AsyncCallback\<BarometerResponse>): void | 新增     | 监听气压计传感器的数据变化一次         |
| 泛Sensor服务-sensor   | once(type: SensorType.SENSOR_TYPE_ID_HALL, callback: AsyncCallback\<HallResponse>): void | 新增     | 监听霍尔传感器的数据变化一次           |
| 泛Sensor服务-sensor   | once(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: AsyncCallback\<LightResponse>): void | 新增     | 监听环境光传感器的数据变化一次         |
| 泛Sensor服务-sensor   | once(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: AsyncCallback\<OrientationResponse>): void | 新增     | 监听方向传感器的数据变化一次           |
| 泛Sensor服务-sensor   | once(type:SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR,callback:AsyncCallback\<RotationVectorResponse>): void | 新增     | 监听旋转矢量传感器的数据变化一次       |
| 泛Sensor服务-sensor   | once(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: AsyncCallback\<WearDetectionResponse>): void | 新增     | 监听佩戴检测传感器的数据变化一次       |
| 泛Sensor服务-sensor   | off(type: SensorType, callback?: AsyncCallback\<void>): void | 新增     | 取消订阅传感器数据                     |
| 泛Sensor服务-sensor   | getGeomagneticField(locationOptions: LocationOptions, timeMillis: number, callback: AsyncCallback\<GeomagneticResponse>): void <br/> getGeomagneticField(locationOptions: LocationOptions, timeMillis: number): Promise\<GeomagneticResponse> | 新增     | 获取地球上特定位置的地磁场             |
| 泛Sensor服务-vibrator | vibrate(duration: number): Promise\<void> <br/> vibrate(duration: number, callback?: AsyncCallback\<void>): void | 新增     | 按照指定持续时间触发马达振动           |
| 泛Sensor服务-vibrator | vibrate(effectId: EffectId): Promise\<void> <br/> vibrate(effectId: EffectId, callback?: AsyncCallback\<void>): void | 新增     | 按照指定振动效果触发马达振动           |
| 泛Sensor服务-vibrator | stop(stopMode: VibratorStopMode): Promise\<void> <br/> stop(stopMode: VibratorStopMode, callback?: AsyncCallback\<void>): void | 新增     | 停止马达振动                           |
