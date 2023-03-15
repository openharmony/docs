# JS API Changes of the Power Management Subsystem

The table below lists the APIs changes of the power management subsystem in OpenHarmony 3.2 Beta3 over OpenHarmony 3.2 Beta2.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| system.battery    | Battery                  | static getStatus(options?: GetStatusOptions): void;             | Deprecated|
| system.battery    | GetStatusOptions         | complete?: () => void;                                          | Deprecated|
| system.battery    | GetStatusOptions         | fail?: (data: string, code: number) => void;                    | Deprecated|
| system.battery    | GetStatusOptions         | success?: (data: BatteryResponse) => void;                      | Deprecated|
| system.battery    | BatteryResponse          | level: number;                                                  | Deprecated|
| system.battery    | BatteryResponse          | charging: boolean;                                              | Deprecated|
| system.brightness | Brightness               | static setKeepScreenOn(options?: SetKeepScreenOnOptions): void; | Deprecated|
| system.brightness | Brightness               | static setMode(options?: SetBrightnessModeOptions): void;       | Deprecated|
| system.brightness | Brightness               | static getMode(options?: GetBrightnessModeOptions): void;       | Deprecated|
| system.brightness | Brightness               | static setValue(options?: SetBrightnessOptions): void;          | Deprecated|
| system.brightness | Brightness               | static getValue(options?: GetBrightnessOptions): void;          | Deprecated|
| system.brightness | SetKeepScreenOnOptions   | complete?: () => void                                           | Deprecated|
| system.brightness | SetKeepScreenOnOptions   | fail?: (data: string, code: number) => void;                    | Deprecated|
| system.brightness | SetKeepScreenOnOptions   | success?: () => void;                                           | Deprecated|
| system.brightness | SetKeepScreenOnOptions   | keepScreenOn: boolean;                                          | Deprecated|
| system.brightness | SetBrightnessModeOptions | complete?: () => void                                           | Deprecated|
| system.brightness | SetBrightnessModeOptions | fail?: (data: string, code: number) => void;                    | Deprecated|
| system.brightness | SetBrightnessModeOptions | success?: () => void;                                           | Deprecated|
| system.brightness | SetBrightnessModeOptions | mode: number;                                                   | Deprecated|
| system.brightness | GetBrightnessModeOptions | complete?: () => void;                                          | Deprecated|
| system.brightness | GetBrightnessModeOptions | fail?: (data: string, code: number) => void;                    | Deprecated|
| system.brightness | GetBrightnessModeOptions | success?: (data: BrightnessModeResponse) => void;               | Deprecated|
| system.brightness | BrightnessModeResponse   | mode: number;                                                   | Deprecated|
| system.brightness | SetBrightnessOptions     | complete?: () => void                                           | Deprecated|
| system.brightness | SetBrightnessOptions     | fail?: (data: string, code: number) => void;                    | Deprecated|
| system.brightness | SetBrightnessOptions     | success?: () => void;                                           | Deprecated|
| system.brightness | SetBrightnessOptions     | value: number;                                                  | Deprecated|
| system.brightness | GetBrightnessOptions     | complete?: () => void;                                          | Deprecated|
| system.brightness | GetBrightnessOptions     | fail?: (data: string, code: number) => void;                    | Deprecated|
| system.brightness | GetBrightnessOptions     | success?: (data: BrightnessResponse) => void;                   | Deprecated|
| system.brightness | BrightnessResponse       | value: number;                                                  | Deprecated|
| ohos.batteryInfo  | batteryInfo              | ohos.batteryinfo -> ohos.batteryInfo                            | Module name changed |
