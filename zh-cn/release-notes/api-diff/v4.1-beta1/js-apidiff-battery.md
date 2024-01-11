| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增API|NA|文件名：api\@ohos.brightness.d.ts；<br>类名：brightness；<br>API声明：function setValue(value: number, continuous: boolean): void;<br>差异内容：function setValue(value: number, continuous: boolean): void;|api\@ohos.brightness.d.ts|
|新增API|NA|文件名：api\@ohos.batteryInfo.d.ts；<br>类名：batteryInfo；<br>API声明：function setBatteryConfig(sceneName: string, sceneValue: string): number;<br>差异内容：function setBatteryConfig(sceneName: string, sceneValue: string): number;|api\@ohos.batteryInfo.d.ts|
|新增API|NA|文件名：api\@ohos.batteryInfo.d.ts；<br>类名：batteryInfo；<br>API声明：function getBatteryConfig(sceneName: string): string;<br>差异内容：function getBatteryConfig(sceneName: string): string;|api\@ohos.batteryInfo.d.ts|
|新增API|NA|文件名：api\@ohos.batteryInfo.d.ts；<br>类名：batteryInfo；<br>API声明：function isBatteryConfigSupported(sceneName: string): boolean;<br>差异内容：function isBatteryConfigSupported(sceneName: string): boolean;|api\@ohos.batteryInfo.d.ts|
|新增API|NA|文件名：api\@ohos.thermal.d.ts；<br>类名：ThermalLevel；<br>API声明：ESCAPE = 7<br>差异内容：ESCAPE = 7|api\@ohos.thermal.d.ts|
|起始版本有变化|文件名：api\@ohos.batteryInfo.d.ts；<br>类名：global；<br>API声明： declare namespace batteryInfo<br>差异内容：6|文件名：api\@ohos.batteryInfo.d.ts；<br>类名：global；<br>API声明： declare namespace batteryInfo<br>差异内容：-1|api\@ohos.batteryInfo.d.ts|
|起始版本有变化|文件名：api\@ohos.charger.d.ts；<br>类名：global；<br>API声明： declare namespace charger<br>差异内容：10|文件名：api\@ohos.charger.d.ts；<br>类名：global；<br>API声明： declare namespace charger<br>差异内容：-1|api\@ohos.charger.d.ts|
|起始版本有变化|文件名：api\@system.battery.d.ts；<br>类名：global；<br>API声明： export interface BatteryResponse<br>差异内容：3|文件名：api\@system.battery.d.ts；<br>类名：global；<br>API声明： export interface BatteryResponse<br>差异内容：-1|api\@system.battery.d.ts|
|起始版本有变化|文件名：api\@system.brightness.d.ts；<br>类名：global；<br>API声明： export interface BrightnessResponse<br>差异内容：3|文件名：api\@system.brightness.d.ts；<br>类名：global；<br>API声明： export interface BrightnessResponse<br>差异内容：-1|api\@system.brightness.d.ts|
