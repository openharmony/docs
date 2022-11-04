# 电源服务子系统JS API变更

OpenHarmony 3.2 Beta3版本相较于OpenHarmony 3.2 Beta2版本，电源服务子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| system.battery    | Battery                  | static getStatus(options?: GetStatusOptions): void;             | 废弃 |
| system.battery    | GetStatusOptions         | complete?: () => void;                                          | 废弃 |
| system.battery    | GetStatusOptions         | fail?: (data: string, code: number) => void;                    | 废弃 |
| system.battery    | GetStatusOptions         | success?: (data: BatteryResponse) => void;                      | 废弃 |
| system.battery    | BatteryResponse          | level: number;                                                  | 废弃 |
| system.battery    | BatteryResponse          | charging: boolean;                                              | 废弃 |
| system.brightness | Brightness               | static setKeepScreenOn(options?: SetKeepScreenOnOptions): void; | 废弃 |
| system.brightness | Brightness               | static setMode(options?: SetBrightnessModeOptions): void;       | 废弃 |
| system.brightness | Brightness               | static getMode(options?: GetBrightnessModeOptions): void;       | 废弃 |
| system.brightness | Brightness               | static setValue(options?: SetBrightnessOptions): void;          | 废弃 |
| system.brightness | Brightness               | static getValue(options?: GetBrightnessOptions): void;          | 废弃 |
| system.brightness | SetKeepScreenOnOptions   | complete?: () => void                                           | 废弃 |
| system.brightness | SetKeepScreenOnOptions   | fail?: (data: string, code: number) => void;                    | 废弃 |
| system.brightness | SetKeepScreenOnOptions   | success?: () => void;                                           | 废弃 |
| system.brightness | SetKeepScreenOnOptions   | keepScreenOn: boolean;                                          | 废弃 |
| system.brightness | SetBrightnessModeOptions | complete?: () => void                                           | 废弃 |
| system.brightness | SetBrightnessModeOptions | fail?: (data: string, code: number) => void;                    | 废弃 |
| system.brightness | SetBrightnessModeOptions | success?: () => void;                                           | 废弃 |
| system.brightness | SetBrightnessModeOptions | mode: number;                                                   | 废弃 |
| system.brightness | GetBrightnessModeOptions | complete?: () => void;                                          | 废弃 |
| system.brightness | GetBrightnessModeOptions | fail?: (data: string, code: number) => void;                    | 废弃 |
| system.brightness | GetBrightnessModeOptions | success?: (data: BrightnessModeResponse) => void;               | 废弃 |
| system.brightness | BrightnessModeResponse   | mode: number;                                                   | 废弃 |
| system.brightness | SetBrightnessOptions     | complete?: () => void                                           | 废弃 |
| system.brightness | SetBrightnessOptions     | fail?: (data: string, code: number) => void;                    | 废弃 |
| system.brightness | SetBrightnessOptions     | success?: () => void;                                           | 废弃 |
| system.brightness | SetBrightnessOptions     | value: number;                                                  | 废弃 |
| system.brightness | GetBrightnessOptions     | complete?: () => void;                                          | 废弃 |
| system.brightness | GetBrightnessOptions     | fail?: (data: string, code: number) => void;                    | 废弃 |
| system.brightness | GetBrightnessOptions     | success?: (data: BrightnessResponse) => void;                   | 废弃 |
| system.brightness | BrightnessResponse       | value: number;                                                  | 废弃 |
| ohos.batteryInfo | batteryInfo | ohos.batteryinfo -> ohos.batteryInfo | 模块名修改 |

