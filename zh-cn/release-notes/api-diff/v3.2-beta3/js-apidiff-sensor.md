# 泛Sensor子系统JS API变更

OpenHarmony 3.2 Beta3版本相较于OpenHarmony 3.2 Beta2版本，泛Sensor子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.vibrator | VibratePreset    | count: number;    | 新增 |
| ohos.vibrator | VibratePreset    | effectId: string; | 新增 |
| ohos.vibrator | VibratePreset    | type: "preset";   | 新增 |
| ohos.vibrator | VibrateTime      | duration: number; | 新增 |
| ohos.vibrator | VibrateTime      | type: "time";     | 新增 |
| ohos.vibrator | VibrateAttribute | usage: Usage,     | 新增 |
| ohos.vibrator | VibrateAttribute | id?: number,      | 新增 |
