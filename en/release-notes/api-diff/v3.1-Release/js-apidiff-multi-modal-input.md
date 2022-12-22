# JS API Changes of the Multimodal Input Subsystem

The table below lists the APIs changes of the multimodal input subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.multimodalInput.inputDevice | inputDevice | function getDevice(deviceId: number, callback: AsyncCallback\<InputDeviceData>): void;<br>function getDevice(deviceId: number): Promise\<InputDeviceData>; | Added|
| ohos.multimodalInput.inputDevice | inputDevice | function getDeviceIds(callback: AsyncCallback<Array\<number>>): void;<br>function getDeviceIds(): Promise<Array\<number>>; | Added|
| ohos.multimodalInput.inputDevice | InputDeviceData | axisRanges : Array\<AxisRange>; | Added|
| ohos.multimodalInput.inputDevice | InputDeviceData | sources : Array\<SourceType>; | Added|
| ohos.multimodalInput.inputDevice | InputDeviceData | name: string; | Added|
| ohos.multimodalInput.inputDevice | InputDeviceData | id: number; | Added|
| ohos.multimodalInput.inputDevice | AxisRange | min: number; | Added|
| ohos.multimodalInput.inputDevice | AxisRange | max : number; | Added|
| ohos.multimodalInput.inputDevice | AxisRange | axis : AxisType; | Added|
| ohos.multimodalInput.inputDevice | AxisRange | source: SourceType; | Added|
