| Change Type | Old Version | New Version | d.ts File |
| ---- | ------ | ------ | -------- |
|SysCap changed|Class name: EffectId;<br>API declaration: EFFECT_CLOCK_TIMER = 'haptic.clock.timer'<br>Differences: NA|Class name: EffectId;<br>API declaration: EFFECT_CLOCK_TIMER = 'haptic.clock.timer'<br>Differences: SystemCapability.Sensors.MiscDevice|api/@ohos.vibrator.d.ts|
|SysCap changed|Class name: VibratorStopMode;<br>API declaration: VIBRATOR_STOP_MODE_TIME = 'time'<br>Differences: NA|Class name: VibratorStopMode;<br>API declaration: VIBRATOR_STOP_MODE_TIME = 'time'<br>Differences: SystemCapability.Sensors.MiscDevice|api/@ohos.vibrator.d.ts|
|SysCap changed|Class name: VibratorStopMode;<br>API declaration: VIBRATOR_STOP_MODE_PRESET = 'preset'<br>Differences: NA|Class name: VibratorStopMode;<br>API declaration: VIBRATOR_STOP_MODE_PRESET = 'preset'<br>Differences: SystemCapability.Sensors.MiscDevice|api/@ohos.vibrator.d.ts|
|SysCap changed|Class name: VibrateAttribute;<br>API declaration: id?: number;<br>Differences: NA|Class name: VibrateAttribute;<br>API declaration: id?: number;<br>Differences: SystemCapability.Sensors.MiscDevice|api/@ohos.vibrator.d.ts|
|SysCap changed|Class name: VibrateAttribute;<br>API declaration: usage: Usage;<br>Differences: NA|Class name: VibrateAttribute;<br>API declaration: usage: Usage;<br>Differences: SystemCapability.Sensors.MiscDevice|api/@ohos.vibrator.d.ts|
|SysCap changed|Class name: VibrateTime;<br>API declaration: type: 'time';<br>Differences: NA|Class name: VibrateTime;<br>API declaration: type: 'time';<br>Differences: SystemCapability.Sensors.MiscDevice|api/@ohos.vibrator.d.ts|
|SysCap changed|Class name: VibrateTime;<br>API declaration: duration: number;<br>Differences: NA|Class name: VibrateTime;<br>API declaration: duration: number;<br>Differences: SystemCapability.Sensors.MiscDevice|api/@ohos.vibrator.d.ts|
|SysCap changed|Class name: VibratePreset;<br>API declaration: type: 'preset';<br>Differences: NA|Class name: VibratePreset;<br>API declaration: type: 'preset';<br>Differences: SystemCapability.Sensors.MiscDevice|api/@ohos.vibrator.d.ts|
|SysCap changed|Class name: VibratePreset;<br>API declaration: effectId: string;<br>Differences: NA|Class name: VibratePreset;<br>API declaration: effectId: string;<br>Differences: SystemCapability.Sensors.MiscDevice|api/@ohos.vibrator.d.ts|
|SysCap changed|Class name: VibratePreset;<br>API declaration: count: number;<br>Differences: NA|Class name: VibratePreset;<br>API declaration: count: number;<br>Differences: SystemCapability.Sensors.MiscDevice|api/@ohos.vibrator.d.ts|
|SysCap changed|Class name: VibrateFromFile;<br>API declaration: type: 'file';<br>Differences: NA|Class name: VibrateFromFile;<br>API declaration: type: 'file';<br>Differences: SystemCapability.Sensors.MiscDevice|api/@ohos.vibrator.d.ts|
|SysCap changed|Class name: VibrateFromFile;<br>API declaration: hapticFd: HapticFileDescriptor;<br>Differences: NA|Class name: VibrateFromFile;<br>API declaration: hapticFd: HapticFileDescriptor;<br>Differences: SystemCapability.Sensors.MiscDevice|api/@ohos.vibrator.d.ts|
|Attribute changed|Class name: Options;<br>API declaration: interval?: number;<br>Differences: number|Class name: Options;<br>API declaration: interval?: number \| SensorFrequency;<br>Differences: number,SensorFrequency|api/@ohos.sensor.d.ts|
|API added|NA|Class name: sensor;<br>API declaration: type SensorFrequency = 'game' \| 'ui' \| 'normal';<br>Differences: type SensorFrequency = 'game' \| 'ui' \| 'normal';|api/@ohos.sensor.d.ts|
|API added|NA|Class name: sensor;<br>API declaration:  enum SensorAccuracy<br>Differences:  enum SensorAccuracy|api/@ohos.sensor.d.ts|
|API added|NA|Class name: SensorAccuracy;<br>API declaration: ACCURACY_UNRELIABLE = 0<br>Differences: ACCURACY_UNRELIABLE = 0|api/@ohos.sensor.d.ts|
|API added|NA|Class name: SensorAccuracy;<br>API declaration: ACCURACY_LOW = 1<br>Differences: ACCURACY_LOW = 1|api/@ohos.sensor.d.ts|
|API added|NA|Class name: SensorAccuracy;<br>API declaration: ACCURACY_MEDIUM = 2<br>Differences: ACCURACY_MEDIUM = 2|api/@ohos.sensor.d.ts|
|API added|NA|Class name: SensorAccuracy;<br>API declaration: ACCURACY_HIGH = 3<br>Differences: ACCURACY_HIGH = 3|api/@ohos.sensor.d.ts|
|API added|NA|Class name: Response;<br>API declaration: accuracy: SensorAccuracy;<br>Differences: accuracy: SensorAccuracy;|api/@ohos.sensor.d.ts|
|Initial version changed|Class name: EffectId;<br>API declaration: EFFECT_CLOCK_TIMER = 'haptic.clock.timer'<br>Differences: NA|Class name: EffectId;<br>API declaration: EFFECT_CLOCK_TIMER = 'haptic.clock.timer'<br>Differences: 8|api/@ohos.vibrator.d.ts|
|Initial version changed|Class name: VibratorStopMode;<br>API declaration: VIBRATOR_STOP_MODE_TIME = 'time'<br>Differences: NA|Class name: VibratorStopMode;<br>API declaration: VIBRATOR_STOP_MODE_TIME = 'time'<br>Differences: 8|api/@ohos.vibrator.d.ts|
|Initial version changed|Class name: VibratorStopMode;<br>API declaration: VIBRATOR_STOP_MODE_PRESET = 'preset'<br>Differences: NA|Class name: VibratorStopMode;<br>API declaration: VIBRATOR_STOP_MODE_PRESET = 'preset'<br>Differences: 8|api/@ohos.vibrator.d.ts|
|Initial version changed|Class name: VibrateAttribute;<br>API declaration: id?: number;<br>Differences: NA|Class name: VibrateAttribute;<br>API declaration: id?: number;<br>Differences: 9|api/@ohos.vibrator.d.ts|
|Initial version changed|Class name: VibrateAttribute;<br>API declaration: usage: Usage;<br>Differences: NA|Class name: VibrateAttribute;<br>API declaration: usage: Usage;<br>Differences: 9|api/@ohos.vibrator.d.ts|
|Initial version changed|Class name: VibrateTime;<br>API declaration: type: 'time';<br>Differences: NA|Class name: VibrateTime;<br>API declaration: type: 'time';<br>Differences: 9|api/@ohos.vibrator.d.ts|
|Initial version changed|Class name: VibrateTime;<br>API declaration: duration: number;<br>Differences: NA|Class name: VibrateTime;<br>API declaration: duration: number;<br>Differences: 9|api/@ohos.vibrator.d.ts|
|Initial version changed|Class name: VibratePreset;<br>API declaration: type: 'preset';<br>Differences: NA|Class name: VibratePreset;<br>API declaration: type: 'preset';<br>Differences: 9|api/@ohos.vibrator.d.ts|
|Initial version changed|Class name: VibratePreset;<br>API declaration: effectId: string;<br>Differences: NA|Class name: VibratePreset;<br>API declaration: effectId: string;<br>Differences: 9|api/@ohos.vibrator.d.ts|
|Initial version changed|Class name: VibratePreset;<br>API declaration: count: number;<br>Differences: NA|Class name: VibratePreset;<br>API declaration: count: number;<br>Differences: 9|api/@ohos.vibrator.d.ts|
|Initial version changed|Class name: VibrateFromFile;<br>API declaration: type: 'file';<br>Differences: NA|Class name: VibrateFromFile;<br>API declaration: type: 'file';<br>Differences: 10|api/@ohos.vibrator.d.ts|
|Initial version changed|Class name: VibrateFromFile;<br>API declaration: hapticFd: HapticFileDescriptor;<br>Differences: NA|Class name: VibrateFromFile;<br>API declaration: hapticFd: HapticFileDescriptor;<br>Differences: 10|api/@ohos.vibrator.d.ts|
|Kit changed|NA|SensorServiceKit|api/@ohos.sensor.d.ts|
|Kit changed|NA|SensorServiceKit|api/@ohos.vibrator.d.ts|
|Kit changed|NA|SensorServiceKit|api/@system.sensor.d.ts|
|Kit changed|NA|SensorServiceKit|api/@system.vibrator.d.ts|
