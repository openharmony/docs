# 泛Sensor子系统JS API变更

OpenHarmony 3.2 Beta2版本相较于OpenHarmony 3.2 Beta1版本，泛Sensor子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_HEART_BEAT_RATE = 278 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_LINEAR_ACCELEROMETER = 258 | 新增 |
| ohos.sensor | sensor | getSensorLists(callback: AsyncCallback\<Array\<Sensor>>): void;<br>getSensorLists(): Promise\<Array\<Sensor>>; | 新增 |
| ohos.sensor | sensor | getSingleSensor(type: SensorType, callback: AsyncCallback\<Sensor>): void;<br>getSingleSensor(type: SensorType): Promise\<Sensor>; | 新增 |
| ohos.sensor | Sensor | power:number; | 新增 |
| ohos.sensor | Sensor | precision:number; | 新增 |
| ohos.sensor | Sensor | maxRange:number; | 新增 |
| ohos.sensor | Sensor | sensorTypeId:number; | 新增 |
| ohos.sensor | Sensor | hardwareVersion:string; | 新增 |
| ohos.sensor | Sensor | firmwareVersion:string; | 新增 |
| ohos.sensor | Sensor | venderName:string; | 新增 |
| ohos.sensor | Sensor | sensorName:string; | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_HEART_RATE = 278 | 废弃 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_LINEAR_ACCELERATION = 258 | 废弃 |
