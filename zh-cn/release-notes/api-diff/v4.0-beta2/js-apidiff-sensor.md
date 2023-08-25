| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：sensor;<br>方法or属性：function on(type: SensorId.COLOR, callback: Callback\<ColorResponse>, options?: Options): void;|@ohos.sensor.d.ts|
|新增|NA|类名：sensor;<br>方法or属性：function on(type: SensorId.SAR, callback: Callback\<SarResponse>, options?: Options): void;|@ohos.sensor.d.ts|
|新增|NA|类名：sensor;<br>方法or属性：function off(type: SensorId.COLOR, callback?: Callback\<ColorResponse>): void;|@ohos.sensor.d.ts|
|新增|NA|类名：sensor;<br>方法or属性：function off(type: SensorId.SAR, callback?: Callback\<SarResponse>): void;|@ohos.sensor.d.ts|
|新增|NA|类名：SensorId;<br>方法or属性：COLOR = 14|@ohos.sensor.d.ts|
|新增|NA|类名：SensorId;<br>方法or属性：SAR = 15|@ohos.sensor.d.ts|
|新增|NA|类名：ColorResponse;<br>方法or属性：lightIntensity: number;|@ohos.sensor.d.ts|
|新增|NA|类名：ColorResponse;<br>方法or属性：colorTemperature: number;|@ohos.sensor.d.ts|
|新增|NA|类名：SarResponse;<br>方法or属性：absorptionRatio: number;|@ohos.sensor.d.ts|
|新增|NA|类名：VibrateFromFile;<br>方法or属性：type: 'file';|@ohos.vibrator.d.ts|
|新增|NA|类名：VibrateFromFile;<br>方法or属性：hapticFd: HapticFileDescriptor;|@ohos.vibrator.d.ts|
|新增|NA|类名：HapticFileDescriptor;<br>方法or属性：fd: number;|@ohos.vibrator.d.ts|
|新增|NA|类名：HapticFileDescriptor;<br>方法or属性：offset?: number;|@ohos.vibrator.d.ts|
|新增|NA|类名：HapticFileDescriptor;<br>方法or属性：length?: number;|@ohos.vibrator.d.ts|
|废弃版本有变化|类名：vibrator;<br>方法or属性：function vibrate(duration: number): Promise\<void>;<br>旧版本信息：|类名：vibrator;<br>方法or属性：function vibrate(duration: number): Promise\<void>;<br>新版本信息：9<br>代替接口： vibrator#startVibration|@ohos.vibrator.d.ts|
|废弃版本有变化|类名：vibrator;<br>方法or属性：function vibrate(effectId: EffectId, callback?: AsyncCallback\<void>): void;<br>旧版本信息：|类名：vibrator;<br>方法or属性：function vibrate(effectId: EffectId, callback?: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： vibrator#startVibration|@ohos.vibrator.d.ts|
|废弃版本有变化|类名：vibrator;<br>方法or属性：function stop(stopMode: VibratorStopMode, callback?: AsyncCallback\<void>): void;<br>旧版本信息：|类名：vibrator;<br>方法or属性：function stop(stopMode: VibratorStopMode, callback?: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： vibrator#stopVibration|@ohos.vibrator.d.ts|
|错误码有变化|类名：vibrator;<br>方法or属性：function startVibration(effect: VibrateEffect, attribute: VibrateAttribute, callback: AsyncCallback\<void>): void;<br>旧版本信息：201,401,14600101|类名：vibrator;<br>方法or属性：function startVibration(effect: VibrateEffect, attribute: VibrateAttribute, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,801,14600101|@ohos.vibrator.d.ts|
|错误码有变化|类名：vibrator;<br>方法or属性：function startVibration(effect: VibrateEffect, attribute: VibrateAttribute): Promise\<void>;<br>旧版本信息：201,401,14600101|类名：vibrator;<br>方法or属性：function startVibration(effect: VibrateEffect, attribute: VibrateAttribute): Promise\<void>;<br>新版本信息：201,401,801,14600101|@ohos.vibrator.d.ts|
|权限有变化|类名：vibrator;<br>方法or属性：function vibrate(duration: number): Promise\<void>;<br>旧版本信息：|类名：vibrator;<br>方法or属性：function vibrate(duration: number): Promise\<void>;<br>新版本信息：ohos.permission.VIBRATE|@ohos.vibrator.d.ts|
|权限有变化|类名：vibrator;<br>方法or属性：function vibrate(effectId: EffectId, callback?: AsyncCallback\<void>): void;<br>旧版本信息：|类名：vibrator;<br>方法or属性：function vibrate(effectId: EffectId, callback?: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.VIBRATE|@ohos.vibrator.d.ts|
|权限有变化|类名：vibrator;<br>方法or属性：function stop(stopMode: VibratorStopMode, callback?: AsyncCallback\<void>): void;<br>旧版本信息：|类名：vibrator;<br>方法or属性：function stop(stopMode: VibratorStopMode, callback?: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.VIBRATE|@ohos.vibrator.d.ts|
|权限有变化|类名：VibrateOptions;<br>方法or属性：mode?: 'long' \| 'short';<br>旧版本信息：|类名：VibrateOptions;<br>方法or属性：mode?: 'long' \| 'short';<br>新版本信息：ohos.permission.VIBRATE|@system.vibrator.d.ts|
|权限有变化|类名：VibrateOptions;<br>方法or属性：success: () => void;<br>旧版本信息：|类名：VibrateOptions;<br>方法or属性：success: () => void;<br>新版本信息：ohos.permission.VIBRATE|@system.vibrator.d.ts|
|权限有变化|类名：VibrateOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：VibrateOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：ohos.permission.VIBRATE|@system.vibrator.d.ts|
|权限有变化|类名：VibrateOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：VibrateOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：ohos.permission.VIBRATE|@system.vibrator.d.ts|
|type有变化|类名：vibrator;<br>方法or属性：type VibrateEffect = VibrateTime \| VibratePreset \| VibrateFromFile;<br>旧版本信息：|类名：vibrator;<br>方法or属性：type VibrateEffect = VibrateTime \| VibratePreset \| VibrateFromFile;<br>新版本信息：VibrateTime \| VibratePreset \| VibrateFromFile|@ohos.vibrator.d.ts|
|函数有变化|类名：vibrator;<br>方法or属性：type VibrateEffect = VibrateTime \| VibratePreset;|类名：vibrator;<br>方法or属性：type VibrateEffect = VibrateTime \| VibratePreset \| VibrateFromFile;|@ohos.vibrator.d.ts|
