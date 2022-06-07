# 多模输入子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，多模输入子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.multimodalInput.inputDevice | inputDevice | function getDevice(deviceId: number, callback: AsyncCallback\<InputDeviceData>): void;<br>function getDevice(deviceId: number): Promise\<InputDeviceData>; | 新增 |
| ohos.multimodalInput.inputDevice | inputDevice | function getDeviceIds(callback: AsyncCallback<Array\<number>>): void;<br>function getDeviceIds(): Promise<Array\<number>>; | 新增 |
| ohos.multimodalInput.inputDevice | InputDeviceData | axisRanges : Array\<AxisRange>; | 新增 |
| ohos.multimodalInput.inputDevice | InputDeviceData | sources : Array\<SourceType>; | 新增 |
| ohos.multimodalInput.inputDevice | InputDeviceData | name: string; | 新增 |
| ohos.multimodalInput.inputDevice | InputDeviceData | id: number; | 新增 |
| ohos.multimodalInput.inputDevice | AxisRange | min: number; | 新增 |
| ohos.multimodalInput.inputDevice | AxisRange | max : number; | 新增 |
| ohos.multimodalInput.inputDevice | AxisRange | axis : AxisType; | 新增 |
| ohos.multimodalInput.inputDevice | AxisRange | source: SourceType; | 新增 |
