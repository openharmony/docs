# JS API 差异报告
OpenHarmony 2.2 Beta2相较于OpenHarmony 2.0 Canary版本的API变更如下:
## 标准系统接口变更

| 模块名称  | 接口名称  | 变更类型  | 变更说明  |
|  --------  |  --------  |  --------  |  --------  |
|  时间日期数字模块-Locale  |  constructor(locale: string, options?:options)  |  新增  |  -  |
|  时间日期数字模块-Locale  |  toString(): string  |  新增  |  -  |
|  时间日期数字模块-Locale  |  maximize(): Locale  |  新增  |  -  |
|  时间日期数字模块-Locale  |  minimize(): Locale  |  新增  |  -  |
|  时间日期数字模块-Locale  |  calendar  |  新增  |  -  |
|  时间日期数字模块-Locale  |  caseFirst  |  新增  |  -  |
|  时间日期数字模块-Locale  |  collation  |  新增  |  -  |
|  时间日期数字模块-Locale  |  hourCycle  |  新增  |  -  |
|  时间日期数字模块-Locale  |  numberingSystem  |  新增  |  -  |
|  时间日期数字模块-Locale  |  numeric  |  新增  |  -  |
|  时间日期数字模块-Locale  |  language  |  新增  |  -  |
|  时间日期数字模块-Locale  |  script  |  新增  |  -  |
|  时间日期数字模块-Locale  |  region  |  新增  |  -  |
|  时间日期数字模块-Locale  |  baseName  |  新增  |  -  |
|  时间日期数字模块-DateTimeFormat  |  constructor(locale: string, options?:options)  |  新增  |  -  |
|  时间日期数字模块-DateTimeFormat  |  constructor(locale: string[], options?:options)  |  新增  |  -  |
|  时间日期数字模块-DateTimeFormat  |  resolvedOptions(): DateTimeOptions  |  新增  |  -  |
|  时间日期数字模块-DateTimeFormat  |  format(date: Date): string;  |  新增  |  -  |
|  时间日期数字模块-DateTimeFormat  |  formatRange(fromDate: Date, toDate: Date): string;  |  新增  |  -  |
|  时间日期数字模块-NumberFormat  |  constructor(locale: string, options?:options)  |  新增  |  -  |
|  时间日期数字模块-NumberFormat  |  constructor(locale: string[], options?:options)  |  新增  |  -  |
|  时间日期数字模块-NumberFormat  |  resolvedOptions(): NumberOptions  |  新增  |  -  |
|  时间日期数字模块-NumberFormat  |  format(number: number): string;  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  locale  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  dateStyle  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  timeStyle  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  calendar  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  dayPeriod  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  numberingSystem  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  localeMatcher  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  timeZone  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  hour12  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  hourCycle  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  formatMatcher  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  weekday  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  era  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  year  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  month  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  day  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  hour  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  minute  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  second  |  新增  |  -  |
|  时间日期数字模块-DateTimeOptions  |  timeZoneName  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  locale  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  compactDisplay  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  currency  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  currencyDisplay  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  currencySign  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  localeMatcher  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  notation  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  numberingSystem  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  signDisplay  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  style  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  unit  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  unitDisplay  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  useGrouping  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  minimumIntegerDigits  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  minimumFractionDigits  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  maximumFractionDigits  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  minimumSignificantDigits  |  新增  |  -  |
|  时间日期数字模块-NumberOptions  |  maximumSignificantDigits  |  新增  |  -  |
|文件存储- system.file|mkdir|新增|-|
|文件存储- system.file|rmdir|新增|-|
|文件存储- system.file|get|新增|-|
|文件存储- system.file|list|新增|-|
|文件存储- system.file|copy|新增|-|
|文件存储- system.file|move|新增|-|
|文件存储- system.file|delete|新增|-|
|文件存储- system.file|access|新增|-|
|文件存储- system.file|writeText|新增|-|
|文件存储- system.file|writeArrayBuffer|新增|-|
|文件存储- system.file|readText|新增|-|
|文件存储- system.file|readArrayBuffer|新增|-|
|文件存储- fileio|Dir.readSync|新增|-|
|文件存储- fileio|Dir.closeSync|新增|-|
|文件存储- fileio|dirent.name|新增|-|
|文件存储- fileio|dirent.isBlockDevice()|新增|-|
|文件存储- fileio|dirent.isCharacterDevice()|新增|-|
|文件存储- fileio|dirent.isDirectory()|新增|-|
|文件存储- fileio|dirent.isFIFO()|新增|-|
|文件存储- fileio|dirent.isFile()|新增|-|
|文件存储- fileio|dirent.isSocket()|新增|-|
|文件存储- fileio|dirent.isSymbolicLink()|新增|-|
|文件存储- fileio|stat.dev|新增|-|
|文件存储- fileio|stat.ino|新增|-|
|文件存储- fileio|stat.mode|新增|-|
|文件存储- fileio|stat.nlink|新增|-|
|文件存储- fileio|stat.uid|新增|-|
|文件存储- fileio|stat.gid|新增|-|
|文件存储- fileio|stat.rdev|新增|-|
|文件存储- fileio|stat.size|新增|-|
|文件存储- fileio|stat.blocks|新增|-|
|文件存储- fileio|stat.atime|新增|-|
|文件存储- fileio|stat.mtime|新增|-|
|文件存储- fileio|stat.ctime|新增|-|
|文件存储- fileio|stat.isBlockDevice()|新增|-|
|文件存储- fileio|stat.isCharacterDevice()|新增|-|
|文件存储- fileio|stat.isDirectory()|新增|-|
|文件存储- fileio|stat.isFIFO()|新增|-|
|文件存储- fileio|stat.isFile()|新增|-|
|文件存储- fileio|stat.isSocket()|新增|-|
|文件存储- fileio|stat.isSymbolicLink()|新增|-|
|文件存储- fileio|Stream.flushSync()|新增|-|
|文件存储- fileio|Stream.writeSync()|新增|-|
|文件存储- fileio|Stream.readSync()|新增|-|
|文件存储- fileio|Stream.closeSync()|新增|-|
|文件存储- fileio|fileio.accessSync()|新增|-|
|文件存储- fileio|fileio.chmodSync()|新增|-|
|文件存储- fileio|fileio.chownSync()|新增|-|
|文件存储- fileio|fileio.closeSync()|新增|-|
|文件存储- fileio|fileio.copyFileSync()|新增|-|
|文件存储- fileio|fileio.createStreamSync()|新增|-|
|文件存储- fileio|fileio.fchmodSync()|新增|-|
|文件存储- fileio|fileio.fchownSync()|新增|-|
|文件存储- fileio|fileio.fdopenStreamSync()|新增|-|
|文件存储- fileio|fileio.fstatSync()|新增|-|
|文件存储- fileio|fileio.fsyncSync()|新增|-|
|文件存储- fileio|fileio.ftruncateSync()|新增|-|
|文件存储- fileio|fileio.mkdirSync()|新增|-|
|文件存储- fileio|fileio.openSync()|新增|-|
|文件存储- fileio|fileio.opendirSync()|新增|-|
|文件存储- fileio|fileio.readSync()|新增|-|
|文件存储- fileio|fileio.renameSync()|新增|-|
|文件存储- fileio|fileio.rmdirSync()|新增|-|
|文件存储- fileio|fileio.statSync()|新增|-|
|文件存储- fileio|fileio.truncateSync()|新增|-|
|文件存储- fileio|fileio.unlinkSync()|新增|-|
|文件存储- fileio|fileio.writeSync()|新增|-|
|设备管理-DeviceManager|DeviceInfo|新增|-|
|设备管理-DeviceManager|DeviceType|新增|-|
|设备管理-DeviceManager|DeviceStateChangeAction|新增|-|
|设备管理-DeviceManager|SubscribeInfo|新增|-|
|设备管理-DeviceManager|DiscoverMode|新增|-|
|设备管理-DeviceManager|ExchangeMedium|新增|-|
|设备管理-DeviceManager|ExchangeFreq|新增|-|
|设备管理-DeviceManager|SubscribeCap|新增|-|
|设备管理-DeviceManager|createDeviceManager(bundleName: string, callback: AsyncCallback\<DeviceManager>): void|新增|-|
|设备管理-DeviceManager|release(): void|新增|-|
|设备管理-DeviceManager|getTrustedDeviceListSync(): Array\<DeviceInfo>|新增|-|
|设备管理-DeviceManager|startDeviceDiscovery(subscribeInfo: SubscribeInfo): void|新增|-|
|设备管理-DeviceManager|stopDeviceDiscovery(subscribeId: number): void|新增|-|
|设备管理-DeviceManager|authenticateDevice(deviceInfo: DeviceInfo): void|新增|-|
|设备管理-DeviceManager|on(type: 'deviceStateChange', callback: Callback\<{ action: DeviceStateChangeAction, device: DeviceInfo }>): void|新增|-|
|设备管理-DeviceManager|off(type: 'deviceStateChange', callback?: Callback\<{ action: DeviceStateChangeAction, device: DeviceInfo }>): void|新增|-|
|设备管理-DeviceManager|on(type: 'deviceFound', callback: Callback\<{ subscribeId: number, device: DeviceInfo }>): void|新增|-|
|设备管理-DeviceManager|off(type: 'deviceFound', callback?: Callback\<{ subscribeId: number, device: DeviceInfo }>): void|新增|-|
|设备管理-DeviceManager|on(type: 'discoverFail', callback: Callback\<{ subscribeId: number, reason: number }>): void|新增|-|
|设备管理-DeviceManager|off(type: 'discoverFail', callback?: Callback\<{ subscribeId: number, reason: number }>): void|新增|-|
|设备管理-DeviceManager|on(type: 'authResult', callback: Callback\<{ deviceId: string, status: number, reason: number }>): void|新增|-|
|设备管理-DeviceManager|off(type: 'authResult', callback?: Callback\<{ deviceId: string, status: number, reason: number }>): void|新增|-|
|设备管理-DeviceManager|on(type: 'serviceDie', callback: () => void): void|新增|-|
|设备管理-DeviceManager|off(type: 'serviceDie', callback?: () => void): void|新增|-|
|播放录制|createAudioPlayer(): AudioPlayer|新增|-|
|播放录制|AudioState|新增|-|
|播放录制|play(): void|新增|-|
|播放录制|pause(): void|新增|-|
|播放录制|stop(): void|新增|-|
|播放录制|seek(timeMs: number): void|新增|-|
|播放录制|setVolume(vol: number): void|新增|-|
|播放录制|reset(): void|新增|-|
|播放录制|release(): void|新增|-|
|播放录制|src: string|新增|-|
|播放录制|loop: boolean|新增|-|
|播放录制|readonly currentTime: number|新增|-|
|播放录制|readonly duration: number|新增|-|
|播放录制|readonly state: AudioState|新增|-|
|播放录制|on(type: 'play' / 'pause' / 'stop' / 'reset' / 'dataLoad' / 'finish' / 'volumeChange', callback: () => void): void|新增|-|
|播放录制|on(type: 'timeUpdate', callback: Callback\<number>): void|新增|-|
|播放录制|on(type: 'error', callback: ErrorCallback): void|新增|-|
|音频管理|getAudioManager(): AudioManager|新增|-|
|音频管理|AudioVolumeType|新增|-|
|音频管理|MEDIA|新增|-|
|音频管理|RINGTONE|新增|-|
|音频管理|DeviceFlag|新增|-|
|音频管理|OUTPUT_DEVICES_FLAG|新增|-|
|音频管理|INPUT_DEVICES_FLAG |新增|-|
|音频管理|ALL_DEVICES_FLAG |新增|-|
|音频管理|DeviceRole |新增|-|
|音频管理|INPUT_DEVICE |新增|-|
|音频管理|OUTPUT_DEVICE |新增|-|
|音频管理|DeviceType |新增|-|
|音频管理|INVALID |新增|-|
|音频管理|SPEAKER |新增|-|
|音频管理|WIRED_HEADSET |新增|-|
|音频管理|BLUETOOTH_SCO |新增|-|
|音频管理|BLUETOOTH_A2DP |新增|-|
|音频管理|MIC|新增|-|
|音频管理|AudioRingMode |新增|-|
|音频管理|RINGER_MODE_NORMAL |新增|-|
|音频管理|RINGER_MODE_SILENT|新增|-|
|音频管理|RINGER_MODE_VIBRATE |新增|-|
|音频管理|setVolume(audioType: AudioVolumeType, volume: number,callback: AsyncCallback\<void>): void|新增|-|
|音频管理|setVolume(audioType: AudioVolumeType, volume: number): Promise\<void>|新增|-|
|音频管理|getVolume(audioType: AudioVolumeType, callback: AsyncCallback\<number>): void|新增|-|
|音频管理|getVolume(audioType: AudioVolumeType): Promise\<number>|新增|-|
|音频管理|getMinVolume(audioType: AudioVolumeType, callback: AsyncCallback\<number>): void|新增|-|
|音频管理|getMinVolume(audioType: AudioVolumeType): Promise\<number>|新增|-|
|音频管理|getMaxVolume(audioType: AudioVolumeType, callback: AsyncCallback\<number>): void|新增|-|
|音频管理|getMaxVolume(audioType: AudioVolumeType): Promise\<number>|新增|-|
|音频管理|getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback\<AudioDeviceDescriptors>): void|新增|-|
|音频管理|getDevices(deviceFlag: DeviceFlag): Promise\<AudioDeviceDescriptors>|新增|-|
|音频管理|getRingerMode(callback: AsyncCallback\<AudioRingMode>): void|新增|-|
|音频管理|getRingerMode(): Promise\<AudioRingMode>|新增|-|
|音频管理|setRingerMode(mode: AudioRingMode, callback: AsyncCallback\<void>): void|新增|-|
|音频管理|setRingerMode(mode: AudioRingMode): Promise\<void>|新增|-|
|音频管理|isMute(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void|新增|-|
|音频管理|isMute(volumeType: AudioVolumeType): Promise\<boolean>|新增|-|
|音频管理|isActive(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void|新增|-|
|音频管理|isActive(volumeType: AudioVolumeType): Promise\<boolean>|新增|-|
|音频管理|isMicrophoneMute(callback: AsyncCallback\<boolean>): void|新增|-|
|音频管理|isMicrophoneMute(): Promise\<boolean>|新增|-|
|音频管理|mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback\<void>) : void|新增|-|
|音频管理|mute(volumeType: AudioVolumeType, mute: boolean): Promise\<void>|新增|-|
|音频管理|setMicrophoneMute(mute: boolean, callback: AsyncCallback\<void>): void|新增|-|
|音频管理|setMicrophoneMute(mute: boolean): Promise\<void>|新增|-|
|音频管理|isDeviceActive(deviceType: DeviceType, callback: AsyncCallback\<boolean>): void|新增|-|
|音频管理|isDeviceActive(deviceType: DeviceType): Promise\<boolean>|新增|-|
|音频管理|setDeviceActive(deviceType: DeviceType, active: boolean, callback: AsyncCallback\<boolean>): void|新增|-|
|音频管理|setDeviceActive(deviceType: DeviceType, active: boolean): Promise\<boolean>|新增|-|
|音频管理|getAudioParameter(key: string, callback: AsyncCallback\<string>): void|新增|-|
|音频管理|getAudioParameter(key: string): Promise\<string>|新增|-|
|音频管理|setAudioParameter(key: string, value: string, callback: AsyncCallback\<void>): void|新增|-|
|音频管理|setAudioParameter(key: string, value: string): Promise\<void>|新增|-|
|音频管理|AudioDeviceDescriptor|新增|-|
|音频管理|readonly deviceRole: DeviceRole|新增|-|
|音频管理|readonly deviceType: DeviceType|新增|-|
|音频管理|AudioDeviceDescriptors |新增|-|

