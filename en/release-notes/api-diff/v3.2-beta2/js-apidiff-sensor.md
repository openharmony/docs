# JS API Changes of the Pan-Sensor Subsystem

The table below lists the APIs changes of the pan-sensor subsystem in OpenHarmony 3.2 Beta2 over OpenHarmony 3.2 Beta1.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_HEART_BEAT_RATE = 278 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_LINEAR_ACCELEROMETER = 258 | Added|
| ohos.sensor | sensor | getSensorLists(callback: AsyncCallback\<Array\<Sensor>>): void;<br>getSensorLists(): Promise\<Array\<Sensor>>; | Added|
| ohos.sensor | sensor | getSingleSensor(type: SensorType, callback: AsyncCallback\<Sensor>): void;<br>getSingleSensor(type: SensorType): Promise\<Sensor>; | Added|
| ohos.sensor | Sensor | power:number; | Added|
| ohos.sensor | Sensor | precision:number; | Added|
| ohos.sensor | Sensor | maxRange:number; | Added|
| ohos.sensor | Sensor | sensorTypeId:number; | Added|
| ohos.sensor | Sensor | hardwareVersion:string; | Added|
| ohos.sensor | Sensor | firmwareVersion:string; | Added|
| ohos.sensor | Sensor | venderName:string; | Added|
| ohos.sensor | Sensor | sensorName:string; | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_HEART_RATE = 278 | Deprecated|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_LINEAR_ACCELERATION = 258 | Deprecated|
