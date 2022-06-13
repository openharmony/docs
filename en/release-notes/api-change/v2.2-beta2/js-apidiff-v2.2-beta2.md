# JS API Differences
This document describes the changes of APIs in OpenHarmony 2.2 Beta2 over OpenHarmony 2.0 Canary.
## Standard System API Changes

| Module | API | Change Type | Change Description |
|  --------  |  --------  |  --------  |  --------  |
|  Time, date, and digit module - Locale |  constructor(locale: string, options?:options)  |  Added |  -  |
|  Time, date, and digit module - Locale |  toString(): string  |  Added |  -  |
|  Time, date, and digit module - Locale |  maximize(): Locale  |  Added |  -  |
|  Time, date, and digit module - Locale |  minimize(): Locale  |  Added |  -  |
|  Time, date, and digit module - Locale |  calendar  |  Added |  -  |
|  Time, date, and digit module - Locale |  caseFirst  |  Added |  -  |
|  Time, date, and digit module - Locale |  collation  |  Added |  -  |
|  Time, date, and digit module - Locale |  hourCycle  |  Added |  -  |
|  Time, date, and digit module - Locale |  numberingSystem  |  Added |  -  |
|  Time, date, and digit module - Locale |  numeric  |  Added |  -  |
|  Time, date, and digit module - Locale |  language  |  Added |  -  |
|  Time, date, and digit module - Locale |  script  |  Added |  -  |
|  Time, date, and digit module - Locale |  region  |  Added |  -  |
|  Time, date, and digit module - Locale |  baseName  |  Added |  -  |
|  Time, date, and digit module - DateTimeFormat |  constructor(locale: string, options?:options)  |  Added |  -  |
|  Time, date, and digit module - DateTimeFormat |  constructor(locale: string[], options?:options)  |  Added |  -  |
|  Time, date, and digit module - DateTimeFormat |  resolvedOptions(): DateTimeOptions  |  Added |  -  |
|  Time, date, and digit module - DateTimeFormat |  format(date: Date): string;  |  Added |  -  |
|  Time, date, and digit module - DateTimeFormat |  formatRange(fromDate: Date, toDate: Date): string;  |  Added |  -  |
|  Time, date, and digit module - NumberFormat |  constructor(locale: string, options?:options)  |  Added |  -  |
|  Time, date, and digit module - NumberFormat |  constructor(locale: string[], options?:options)  |  Added |  -  |
|  Time, date, and digit module - NumberFormat |  resolvedOptions(): NumberOptions  |  Added |  -  |
|  Time, date, and digit module - NumberFormat |  format(number: number): string;  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  locale  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  dateStyle  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  timeStyle  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  calendar  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  dayPeriod  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  numberingSystem  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  localeMatcher  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  timeZone  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  hour12  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  hourCycle  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  formatMatcher  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  weekday  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  era  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  year  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  month  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  day  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  hour  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  minute  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  second  |  Added |  -  |
|  Time, date, and digit module - DateTimeOptions |  timeZoneName  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  locale  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  compactDisplay  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  currency  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  currencyDisplay  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  currencySign  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  localeMatcher  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  notation  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  numberingSystem  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  signDisplay  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  style  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  unit  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  unitDisplay  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  useGrouping  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  minimumIntegerDigits  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  minimumFractionDigits  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  maximumFractionDigits  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  minimumSignificantDigits  |  Added |  -  |
|  Time, date, and digit module - NumberOptions |  maximumSignificantDigits  |  Added |  -  |
|File storage - system.file|mkdir|Added|-|
|File storage - system.file|rmdir|Added|-|
|File storage - system.file|get|Added|-|
|File storage - system.file|list|Added|-|
|File storage - system.file|copy|Added|-|
|File storage - system.file|move|Added|-|
|File storage - system.file|delete|Added|-|
|File storage - system.file|access|Added|-|
|File storage - system.file|writeText|Added|-|
|File storage - system.file|writeArrayBuffer|Added|-|
|File storage - system.file|readText|Added|-|
|File storage - system.file|readArrayBuffer|Added|-|
|File storage - fileio|Dir.readSync|Added|-|
|File storage - fileio|Dir.closeSync|Added|-|
|File storage - fileio|dirent.name|Added|-|
|File storage - fileio|dirent.isBlockDevice()|Added|-|
|File storage - fileio|dirent.isCharacterDevice()|Added|-|
|File storage - fileio|dirent.isDirectory()|Added|-|
|File storage - fileio|dirent.isFIFO()|Added|-|
|File storage - fileio|dirent.isFile()|Added|-|
|File storage - fileio|dirent.isSocket()|Added|-|
|File storage - fileio|dirent.isSymbolicLink()|Added|-|
|File storage - fileio|stat.dev|Added|-|
|File storage - fileio|stat.ino|Added|-|
|File storage - fileio|stat.mode|Added|-|
|File storage - fileio|stat.nlink|Added|-|
|File storage - fileio|stat.uid|Added|-|
|File storage - fileio|stat.gid|Added|-|
|File storage - fileio|stat.rdev|Added|-|
|File storage - fileio|stat.size|Added|-|
|File storage - fileio|stat.blocks|Added|-|
|File storage - fileio|stat.atime|Added|-|
|File storage - fileio|stat.mtime|Added|-|
|File storage - fileio|stat.ctime|Added|-|
|File storage - fileio|stat.isBlockDevice()|Added|-|
|File storage - fileio|stat.isCharacterDevice()|Added|-|
|File storage - fileio|stat.isDirectory()|Added|-|
|File storage - fileio|stat.isFIFO()|Added|-|
|File storage - fileio|stat.isFile()|Added|-|
|File storage - fileio|stat.isSocket()|Added|-|
|File storage - fileio|stat.isSymbolicLink()|Added|-|
|File storage - fileio|Stream.flushSync()|Added|-|
|File storage - fileio|Stream.writeSync()|Added|-|
|File storage - fileio|Stream.readSync()|Added|-|
|File storage - fileio|Stream.closeSync()|Added|-|
|File storage - fileio|fileio.accessSync()|Added|-|
|File storage - fileio|fileio.chmodSync()|Added|-|
|File storage - fileio|fileio.chownSync()|Added|-|
|File storage - fileio|fileio.closeSync()|Added|-|
|File storage - fileio|fileio.copyFileSync()|Added|-|
|File storage - fileio|fileio.createStreamSync()|Added|-|
|File storage - fileio|fileio.fchmodSync()|Added|-|
|File storage - fileio|fileio.fchownSync()|Added|-|
|File storage - fileio|fileio.fdopenStreamSync()|Added|-|
|File storage - fileio|fileio.fstatSync()|Added|-|
|File storage - fileio|fileio.fsyncSync()|Added|-|
|File storage - fileio|fileio.ftruncateSync()|Added|-|
|File storage - fileio|fileio.mkdirSync()|Added|-|
|File storage - fileio|fileio.openSync()|Added|-|
|File storage - fileio|fileio.opendirSync()|Added|-|
|File storage - fileio|fileio.readSync()|Added|-|
|File storage - fileio|fileio.renameSync()|Added|-|
|File storage - fileio|fileio.rmdirSync()|Added|-|
|File storage - fileio|fileio.statSync()|Added|-|
|File storage - fileio|fileio.truncateSync()|Added|-|
|File storage - fileio|fileio.unlinkSync()|Added|-|
|File storage - fileio|fileio.writeSync()|Added|-|
|Device management - DeviceManager|DeviceInfo|Added|-|
|Device management - DeviceManager|DeviceType|Added|-|
|Device management - DeviceManager|DeviceStateChangeAction|Added|-|
|Device management - DeviceManager|SubscribeInfo|Added|-|
|Device management - DeviceManager|DiscoverMode|Added|-|
|Device management - DeviceManager|ExchangeMedium|Added|-|
|Device management - DeviceManager|ExchangeFreq|Added|-|
|Device management - DeviceManager|SubscribeCap|Added|-|
|Device management - DeviceManager|createDeviceManager(bundleName: string, callback: AsyncCallback\<DeviceManager>): void|Added|-|
|Device management - DeviceManager|release(): void|Added|-|
|Device management - DeviceManager|getTrustedDeviceListSync(): Array\<DeviceInfo>|Added|-|
|Device management - DeviceManager|startDeviceDiscovery(subscribeInfo: SubscribeInfo): void|Added|-|
|Device management - DeviceManager|stopDeviceDiscovery(subscribeId: number): void|Added|-|
|Device management - DeviceManager|authenticateDevice(deviceInfo: DeviceInfo): void|Added|-|
|Device management - DeviceManager|on(type: 'deviceStateChange', callback: Callback\<{ action: DeviceStateChangeAction, device: DeviceInfo }>): void|Added|-|
|Device management - DeviceManager|off(type: 'deviceStateChange', callback?: Callback\<{ action: DeviceStateChangeAction, device: DeviceInfo }>): void|Added|-|
|Device management - DeviceManager|on(type: 'deviceFound', callback: Callback\<{ subscribeId: number, device: DeviceInfo }>): void|Added|-|
|Device management - DeviceManager|off(type: 'deviceFound', callback?: Callback\<{ subscribeId: number, device: DeviceInfo }>): void|Added|-|
|Device management - DeviceManager|on(type: 'discoverFail', callback: Callback\<{ subscribeId: number, reason: number }>): void|Added|-|
|Device management - DeviceManager|off(type: 'discoverFail', callback?: Callback\<{ subscribeId: number, reason: number }>): void|Added|-|
|Device management - DeviceManager|on(type: 'authResult', callback: Callback\<{ deviceId: string, status: number, reason: number }>): void|Added|-|
|Device management - DeviceManager|off(type: 'authResult', callback?: Callback\<{ deviceId: string, status: number, reason: number }>): void|Added|-|
|Device management - DeviceManager|on(type: 'serviceDie', callback: () => void): void|Added|-|
|Device management - DeviceManager|off(type: 'serviceDie', callback?: () => void): void|Added|-|
|Playback and recording|createAudioPlayer(): AudioPlayer|Added|-|
|Playback and recording|AudioState|Added|-|
|Playback and recording|play(): void|Added|-|
|Playback and recording|pause(): void|Added|-|
|Playback and recording|stop(): void|Added|-|
|Playback and recording|seek(timeMs: number): void|Added|-|
|Playback and recording|setVolume(vol: number): void|Added|-|
|Playback and recording|reset(): void|Added|-|
|Playback and recording|release(): void|Added|-|
|Playback and recording|src: string|Added|-|
|Playback and recording|loop: boolean|Added|-|
|Playback and recording|readonly currentTime: number|Added|-|
|Playback and recording|readonly duration: number|Added|-|
|Playback and recording|readonly state: AudioState|Added|-|
|Playback and recording|on(type: 'play' / 'pause' / 'stop' / 'reset' / 'dataLoad' / 'finish' / 'volumeChange', callback: () => void): void|Added|-|
|Playback and recording|on(type: 'timeUpdate', callback: Callback\<number>): void|Added|-|
|Playback and recording|on(type: 'error', callback: ErrorCallback): void|Added|-|
|Audio management|getAudioManager(): AudioManager|Added|-|
|Audio management|AudioVolumeType|Added|-|
|Audio management|MEDIA|Added|-|
|Audio management|RINGTONE|Added|-|
|Audio management|DeviceFlag|Added|-|
|Audio management|OUTPUT_DEVICES_FLAG|Added|-|
|Audio management|INPUT_DEVICES_FLAG |Added|-|
|Audio management|ALL_DEVICES_FLAG |Added|-|
|Audio management|DeviceRole |Added|-|
|Audio management|INPUT_DEVICE |Added|-|
|Audio management|OUTPUT_DEVICE |Added|-|
|Audio management|DeviceType |Added|-|
|Audio management|INVALID |Added|-|
|Audio management|SPEAKER |Added|-|
|Audio management|WIRED_HEADSET |Added|-|
|Audio management|BLUETOOTH_SCO |Added|-|
|Audio management|BLUETOOTH_A2DP |Added|-|
|Audio management|MIC|Added|-|
|Audio management|AudioRingMode |Added|-|
|Audio management|RINGER_MODE_NORMAL |Added|-|
|Audio management|RINGER_MODE_SILENT|Added|-|
|Audio management|RINGER_MODE_VIBRATE |Added|-|
|Audio management|setVolume(audioType: AudioVolumeType, volume: number,callback: AsyncCallback\<void>): void|Added|-|
|Audio management|setVolume(audioType: AudioVolumeType, volume: number): Promise\<void>|Added|-|
|Audio management|getVolume(audioType: AudioVolumeType, callback: AsyncCallback\<number>): void|Added|-|
|Audio management|getVolume(audioType: AudioVolumeType): Promise\<number>|Added|-|
|Audio management|getMinVolume(audioType: AudioVolumeType, callback: AsyncCallback\<number>): void|Added|-|
|Audio management|getMinVolume(audioType: AudioVolumeType): Promise\<number>|Added|-|
|Audio management|getMaxVolume(audioType: AudioVolumeType, callback: AsyncCallback\<number>): void|Added|-|
|Audio management|getMaxVolume(audioType: AudioVolumeType): Promise\<number>|Added|-|
|Audio management|getDevices(deviceFlag: DeviceFlag, callback: AsyncCallback\<AudioDeviceDescriptors>): void|Added|-|
|Audio management|getDevices(deviceFlag: DeviceFlag): Promise\<AudioDeviceDescriptors>|Added|-|
|Audio management|getRingerMode(callback: AsyncCallback\<AudioRingMode>): void|Added|-|
|Audio management|getRingerMode(): Promise\<AudioRingMode>|Added|-|
|Audio management|setRingerMode(mode: AudioRingMode, callback: AsyncCallback\<void>): void|Added|-|
|Audio management|setRingerMode(mode: AudioRingMode): Promise\<void>|Added|-|
|Audio management|isMute(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void|Added|-|
|Audio management|isMute(volumeType: AudioVolumeType): Promise\<boolean>|Added|-|
|Audio management|isActive(volumeType: AudioVolumeType, callback: AsyncCallback\<boolean>): void|Added|-|
|Audio management|isActive(volumeType: AudioVolumeType): Promise\<boolean>|Added|-|
|Audio management|isMicrophoneMute(callback: AsyncCallback\<boolean>): void|Added|-|
|Audio management|isMicrophoneMute(): Promise\<boolean>|Added|-|
|Audio management|mute(volumeType: AudioVolumeType, mute: boolean, callback: AsyncCallback\<void>) : void|Added|-|
|Audio management|mute(volumeType: AudioVolumeType, mute: boolean): Promise\<void>|Added|-|
|Audio management|setMicrophoneMute(mute: boolean, callback: AsyncCallback\<void>): void|Added|-|
|Audio management|setMicrophoneMute(mute: boolean): Promise\<void>|Added|-|
|Audio management|isDeviceActive(deviceType: DeviceType, callback: AsyncCallback\<boolean>): void|Added|-|
|Audio management|isDeviceActive(deviceType: DeviceType): Promise\<boolean>|Added|-|
|Audio management|setDeviceActive(deviceType: DeviceType, active: boolean, callback: AsyncCallback\<boolean>): void|Added|-|
|Audio management|setDeviceActive(deviceType: DeviceType, active: boolean): Promise\<boolean>|Added|-|
|Audio management|getAudioParameter(key: string, callback: AsyncCallback\<string>): void|Added|-|
|Audio management|getAudioParameter(key: string): Promise\<string>|Added|-|
|Audio management|setAudioParameter(key: string, value: string, callback: AsyncCallback\<void>): void|Added|-|
|Audio management|setAudioParameter(key: string, value: string): Promise\<void>|Added|-|
|Audio management|AudioDeviceDescriptor|Added|-|
|Audio management|readonly deviceRole: DeviceRole|Added|-|
|Audio management|readonly deviceType: DeviceType|Added|-|
|Audio management|AudioDeviceDescriptors |Added|-|
