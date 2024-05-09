| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|syscap变更|NA|文件名：api\@ohos.vibrator.d.ts；<br>类名：EffectId；<br>API声明：EFFECT_CLOCK_TIMER = 'haptic.clock.timer'<br>差异内容：SystemCapability.Sensors.MiscDevice|api\@ohos.vibrator.d.ts|
|syscap变更|NA|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibratorStopMode；<br>API声明：VIBRATOR_STOP_MODE_TIME = 'time'<br>差异内容：SystemCapability.Sensors.MiscDevice|api\@ohos.vibrator.d.ts|
|syscap变更|NA|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibratorStopMode；<br>API声明：VIBRATOR_STOP_MODE_PRESET = 'preset'<br>差异内容：SystemCapability.Sensors.MiscDevice|api\@ohos.vibrator.d.ts|
|syscap变更|NA|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateAttribute；<br>API声明：id?: number;<br>差异内容：SystemCapability.Sensors.MiscDevice|api\@ohos.vibrator.d.ts|
|syscap变更|NA|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateAttribute；<br>API声明：usage: Usage;<br>差异内容：SystemCapability.Sensors.MiscDevice|api\@ohos.vibrator.d.ts|
|syscap变更|NA|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateTime；<br>API声明：type: 'time';<br>差异内容：SystemCapability.Sensors.MiscDevice|api\@ohos.vibrator.d.ts|
|syscap变更|NA|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateTime；<br>API声明：duration: number;<br>差异内容：SystemCapability.Sensors.MiscDevice|api\@ohos.vibrator.d.ts|
|syscap变更|NA|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibratePreset；<br>API声明：type: 'preset';<br>差异内容：SystemCapability.Sensors.MiscDevice|api\@ohos.vibrator.d.ts|
|syscap变更|NA|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibratePreset；<br>API声明：effectId: string;<br>差异内容：SystemCapability.Sensors.MiscDevice|api\@ohos.vibrator.d.ts|
|syscap变更|NA|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibratePreset；<br>API声明：count: number;<br>差异内容：SystemCapability.Sensors.MiscDevice|api\@ohos.vibrator.d.ts|
|syscap变更|NA|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateFromFile；<br>API声明：type: 'file';<br>差异内容：SystemCapability.Sensors.MiscDevice|api\@ohos.vibrator.d.ts|
|syscap变更|NA|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateFromFile；<br>API声明：hapticFd: HapticFileDescriptor;<br>差异内容：SystemCapability.Sensors.MiscDevice|api\@ohos.vibrator.d.ts|
|属性变更|文件名：api\@ohos.sensor.d.ts；<br>类名：Options；<br>API声明：interval?: number;<br>差异内容：number|文件名：api\@ohos.sensor.d.ts；<br>类名：Options；<br>API声明：interval?: number \| SensorFrequency;<br>差异内容：number,SensorFrequency|api\@ohos.sensor.d.ts|
|新增API|NA|文件名：api\@ohos.sensor.d.ts；<br>类名：sensor；<br>API声明：type SensorFrequency = 'game' \| 'ui' \| 'normal';<br>差异内容：type SensorFrequency = 'game' \| 'ui' \| 'normal';|api\@ohos.sensor.d.ts|
|新增API|NA|文件名：api\@ohos.sensor.d.ts；<br>类名：sensor；<br>API声明： enum SensorAccuracy<br>差异内容： enum SensorAccuracy|api\@ohos.sensor.d.ts|
|新增API|NA|文件名：api\@ohos.sensor.d.ts；<br>类名：SensorAccuracy；<br>API声明：ACCURACY_UNRELIABLE = 0<br>差异内容：ACCURACY_UNRELIABLE = 0|api\@ohos.sensor.d.ts|
|新增API|NA|文件名：api\@ohos.sensor.d.ts；<br>类名：SensorAccuracy；<br>API声明：ACCURACY_LOW = 1<br>差异内容：ACCURACY_LOW = 1|api\@ohos.sensor.d.ts|
|新增API|NA|文件名：api\@ohos.sensor.d.ts；<br>类名：SensorAccuracy；<br>API声明：ACCURACY_MEDIUM = 2<br>差异内容：ACCURACY_MEDIUM = 2|api\@ohos.sensor.d.ts|
|新增API|NA|文件名：api\@ohos.sensor.d.ts；<br>类名：SensorAccuracy；<br>API声明：ACCURACY_HIGH = 3<br>差异内容：ACCURACY_HIGH = 3|api\@ohos.sensor.d.ts|
|新增API|NA|文件名：api\@ohos.sensor.d.ts；<br>类名：Response；<br>API声明：accuracy: SensorAccuracy;<br>差异内容：accuracy: SensorAccuracy;|api\@ohos.sensor.d.ts|
|起始版本有变化|文件名：api\@system.sensor.d.ts；<br>类名：global；<br>API声明： export interface AccelerometerResponse<br>差异内容：3|文件名：api\@system.sensor.d.ts；<br>类名：global；<br>API声明： export interface AccelerometerResponse<br>差异内容：-1|api\@system.sensor.d.ts|
|起始版本有变化|文件名：api\@system.vibrator.d.ts；<br>类名：global；<br>API声明： export interface VibrateOptions<br>差异内容：3|文件名：api\@system.vibrator.d.ts；<br>类名：global；<br>API声明： export interface VibrateOptions<br>差异内容：-1|api\@system.vibrator.d.ts|
|起始版本有变化|文件名：api\@ohos.vibrator.d.ts；<br>类名：EffectId；<br>API声明：EFFECT_CLOCK_TIMER = 'haptic.clock.timer'<br>差异内容：-1|文件名：api\@ohos.vibrator.d.ts；<br>类名：EffectId；<br>API声明：EFFECT_CLOCK_TIMER = 'haptic.clock.timer'<br>差异内容：8|api\@ohos.vibrator.d.ts|
|起始版本有变化|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibratorStopMode；<br>API声明：VIBRATOR_STOP_MODE_TIME = 'time'<br>差异内容：-1|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibratorStopMode；<br>API声明：VIBRATOR_STOP_MODE_TIME = 'time'<br>差异内容：8|api\@ohos.vibrator.d.ts|
|起始版本有变化|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibratorStopMode；<br>API声明：VIBRATOR_STOP_MODE_PRESET = 'preset'<br>差异内容：-1|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibratorStopMode；<br>API声明：VIBRATOR_STOP_MODE_PRESET = 'preset'<br>差异内容：8|api\@ohos.vibrator.d.ts|
|起始版本有变化|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateAttribute；<br>API声明：id?: number;<br>差异内容：-1|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateAttribute；<br>API声明：id?: number;<br>差异内容：9|api\@ohos.vibrator.d.ts|
|起始版本有变化|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateAttribute；<br>API声明：usage: Usage;<br>差异内容：-1|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateAttribute；<br>API声明：usage: Usage;<br>差异内容：9|api\@ohos.vibrator.d.ts|
|起始版本有变化|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateTime；<br>API声明：type: 'time';<br>差异内容：-1|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateTime；<br>API声明：type: 'time';<br>差异内容：9|api\@ohos.vibrator.d.ts|
|起始版本有变化|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateTime；<br>API声明：duration: number;<br>差异内容：-1|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateTime；<br>API声明：duration: number;<br>差异内容：9|api\@ohos.vibrator.d.ts|
|起始版本有变化|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibratePreset；<br>API声明：type: 'preset';<br>差异内容：-1|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibratePreset；<br>API声明：type: 'preset';<br>差异内容：9|api\@ohos.vibrator.d.ts|
|起始版本有变化|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibratePreset；<br>API声明：effectId: string;<br>差异内容：-1|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibratePreset；<br>API声明：effectId: string;<br>差异内容：9|api\@ohos.vibrator.d.ts|
|起始版本有变化|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibratePreset；<br>API声明：count: number;<br>差异内容：-1|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibratePreset；<br>API声明：count: number;<br>差异内容：9|api\@ohos.vibrator.d.ts|
|起始版本有变化|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateFromFile；<br>API声明：type: 'file';<br>差异内容：-1|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateFromFile；<br>API声明：type: 'file';<br>差异内容：10|api\@ohos.vibrator.d.ts|
|起始版本有变化|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateFromFile；<br>API声明：hapticFd: HapticFileDescriptor;<br>差异内容：-1|文件名：api\@ohos.vibrator.d.ts；<br>类名：VibrateFromFile；<br>API声明：hapticFd: HapticFileDescriptor;<br>差异内容：10|api\@ohos.vibrator.d.ts|
