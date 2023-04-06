# 泛Sensor子系统JS API变更

OpenHarmony 3.1 Release版本相较于OpenHarmony 3.0 LTS版本，泛Sensor子系统的API变更如下:

## 接口变更

| 模块名 | 类名 | 方法/属性/枚举/常量 | 变更类型 |
|---|---|---|---|
| ohos.vibrator | VibratorStopMode | VIBRATOR_STOP_MODE_PRESET = "preset" | 新增 |
| ohos.vibrator | VibratorStopMode | VIBRATOR_STOP_MODE_TIME = "time" | 新增 |
| ohos.vibrator | EffectId | EFFECT_CLOCK_TIMER = "haptic.clock.timer" | 新增 |
| ohos.vibrator | vibrator | stop(stopMode: VibratorStopMode): Promise\<void>;<br>stop(stopMode: VibratorStopMode, callback?: AsyncCallback\<void>): void; | 新增 |
| ohos.vibrator | vibrator | vibrate(duration: number, callback?: AsyncCallback\<void>): void;<br>vibrate(duration: number): Promise\<void>;<br>vibrate(effectId: EffectId): Promise\<void>;<br>vibrate(effectId: EffectId, callback?: AsyncCallback\<void>): void; | 新增 |
| ohos.sensor | WearDetectionResponse | value: number; | 新增 |
| ohos.sensor | HeartRateResponse | heartRate: number; | 新增 |
| ohos.sensor | BarometerResponse | pressure: number; | 新增 |
| ohos.sensor | AmbientTemperatureResponse | temperature: number; | 新增 |
| ohos.sensor | PedometerDetectionResponse | scalar: number; | 新增 |
| ohos.sensor | HumidityResponse | humidity: number; | 新增 |
| ohos.sensor | PedometerResponse | steps: number; | 新增 |
| ohos.sensor | MagneticFieldUncalibratedResponse | biasZ: number; | 新增 |
| ohos.sensor | MagneticFieldUncalibratedResponse | biasY: number; | 新增 |
| ohos.sensor | MagneticFieldUncalibratedResponse | biasX: number; | 新增 |
| ohos.sensor | MagneticFieldUncalibratedResponse | z: number; | 新增 |
| ohos.sensor | MagneticFieldUncalibratedResponse | y: number; | 新增 |
| ohos.sensor | MagneticFieldUncalibratedResponse | x: number; | 新增 |
| ohos.sensor | MagneticFieldResponse | z: number; | 新增 |
| ohos.sensor | MagneticFieldResponse | y: number; | 新增 |
| ohos.sensor | MagneticFieldResponse | x: number; | 新增 |
| ohos.sensor | HallResponse | status: number; | 新增 |
| ohos.sensor | LightResponse | intensity: number; | 新增 |
| ohos.sensor | ProximityResponse | distance: number; | 新增 |
| ohos.sensor | SignificantMotionResponse | scalar: number; | 新增 |
| ohos.sensor | GyroscopeUncalibratedResponse | biasZ: number; | 新增 |
| ohos.sensor | GyroscopeUncalibratedResponse | biasY: number; | 新增 |
| ohos.sensor | GyroscopeUncalibratedResponse | biasX: number; | 新增 |
| ohos.sensor | GyroscopeUncalibratedResponse | z: number; | 新增 |
| ohos.sensor | GyroscopeUncalibratedResponse | y: number; | 新增 |
| ohos.sensor | GyroscopeUncalibratedResponse | x: number; | 新增 |
| ohos.sensor | GyroscopeResponse | z: number; | 新增 |
| ohos.sensor | GyroscopeResponse | y: number; | 新增 |
| ohos.sensor | GyroscopeResponse | x: number; | 新增 |
| ohos.sensor | RotationVectorResponse | w: number; | 新增 |
| ohos.sensor | RotationVectorResponse | z: number; | 新增 |
| ohos.sensor | RotationVectorResponse | y: number; | 新增 |
| ohos.sensor | RotationVectorResponse | x: number; | 新增 |
| ohos.sensor | OrientationResponse | gamma: number; | 新增 |
| ohos.sensor | OrientationResponse | beta: number; | 新增 |
| ohos.sensor | OrientationResponse | alpha: number; | 新增 |
| ohos.sensor | GravityResponse | z: number; | 新增 |
| ohos.sensor | GravityResponse | y: number; | 新增 |
| ohos.sensor | GravityResponse | x: number; | 新增 |
| ohos.sensor | AccelerometerUncalibratedResponse | biasZ: number; | 新增 |
| ohos.sensor | AccelerometerUncalibratedResponse | biasY: number; | 新增 |
| ohos.sensor | AccelerometerUncalibratedResponse | biasX: number; | 新增 |
| ohos.sensor | AccelerometerUncalibratedResponse | z: number; | 新增 |
| ohos.sensor | AccelerometerUncalibratedResponse | y: number; | 新增 |
| ohos.sensor | AccelerometerUncalibratedResponse | x: number; | 新增 |
| ohos.sensor | LinearAccelerometerResponse | z: number; | 新增 |
| ohos.sensor | LinearAccelerometerResponse | y: number; | 新增 |
| ohos.sensor | LinearAccelerometerResponse | x: number; | 新增 |
| ohos.sensor | AccelerometerResponse | z: number; | 新增 |
| ohos.sensor | AccelerometerResponse | y: number; | 新增 |
| ohos.sensor | AccelerometerResponse | x: number; | 新增 |
| ohos.sensor | Response | timestamp: number; | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED = 281 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_WEAR_DETECTION = 280 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_HEART_RATE = 278 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_PEDOMETER = 266 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_PEDOMETER_DETECTION = 265 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_SIGNIFICANT_MOTION = 264 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED = 263 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED = 261 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_AMBIENT_TEMPERATURE = 260 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_ROTATION_VECTOR = 259 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_LINEAR_ACCELERATION = 258 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_GRAVITY = 257 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_ORIENTATION = 256 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_HUMIDITY = 13 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_PROXIMITY = 12 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_HALL = 10 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_BAROMETER = 8 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_MAGNETIC_FIELD = 6 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_AMBIENT_LIGHT = 5 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_GYROSCOPE = 2 | 新增 |
| ohos.sensor | SensorType | SENSOR_TYPE_ID_ACCELEROMETER = 1 | 新增 |
| ohos.sensor | Options | interval?: number; | 新增 |
| ohos.sensor | RotationMatrixResponse | inclination: Array\<number> | 新增 |
| ohos.sensor | RotationMatrixResponse | rotation: Array\<number>; | 新增 |
| ohos.sensor | sensor | getDirection(rotationMatrix: Array\<number>, callback: AsyncCallback\<Array\<number>>): void;<br>getDirection(rotationMatrix: Array\<number>): Promise\<Array\<number>>; | 新增 |
| ohos.sensor | sensor | createQuaternion(rotationVector: Array\<number>, callback: AsyncCallback\<Array\<number>>): void;<br>createQuaternion(rotationVector: Array\<number>): Promise\<Array\<number>>; | 新增 |
| ohos.sensor | sensor | transformCoordinateSystem(inRotationVector: Array\<number>, coordinates: CoordinatesOptions, callback: AsyncCallback\<Array\<number>>): void;<br>transformCoordinateSystem(inRotationVector: Array\<number>, coordinates: CoordinatesOptions): Promise\<Array\<number>>; | 新增 |
| ohos.sensor | CoordinatesOptions | y: number; | 新增 |
| ohos.sensor | CoordinatesOptions | x: number; | 新增 |
| ohos.sensor | sensor | createRotationMatrix(rotationVector: Array\<number>, callback: AsyncCallback\<Array\<number>>): void;<br>createRotationMatrix(rotationVector: Array\<number>): Promise\<Array\<number>>;<br>createRotationMatrix(gravity: Array\<number>, geomagnetic: Array\<number>, callback: AsyncCallback\<RotationMatrixResponse>): void;<br>createRotationMatrix(gravity: Array\<number>, geomagnetic: Array\<number>,): Promise\<RotationMatrixResponse>; | 新增 |
| ohos.sensor | sensor | getAngleModify(currentRotationMatrix: Array\<number>, preRotationMatrix: Array\<number>, callback: AsyncCallback\<Array\<number>>): void;<br>getAngleModify(currentRotationMatrix: Array\<number>, preRotationMatrix: Array\<number>): Promise\<Array\<number>>; | 新增 |
| ohos.sensor | sensor | getGeomagneticDip(inclinationMatrix: Array\<number>, callback: AsyncCallback\<number>): void;<br>getGeomagneticDip(inclinationMatrix: Array\<number>): Promise\<number>; | 新增 |
| ohos.sensor | sensor | getAltitude(seaPressure: number, currentPressure: number, callback: AsyncCallback\<number>): void;<br>getAltitude(seaPressure: number, currentPressure: number): Promise\<number>; | 新增 |
| ohos.sensor | sensor | getGeomagneticField(locationOptions: LocationOptions, timeMillis: number, callback: AsyncCallback\<GeomagneticResponse>): void;<br>getGeomagneticField(locationOptions: LocationOptions, timeMillis: number): Promise\<GeomagneticResponse>; | 新增 |
| ohos.sensor | GeomagneticResponse | totalIntensity: number; | 新增 |
| ohos.sensor | GeomagneticResponse | levelIntensity: number; | 新增 |
| ohos.sensor | GeomagneticResponse | deflectionAngle: number; | 新增 |
| ohos.sensor | GeomagneticResponse | geomagneticDip: number; | 新增 |
| ohos.sensor | GeomagneticResponse | z: number; | 新增 |
| ohos.sensor | GeomagneticResponse | y: number; | 新增 |
| ohos.sensor | GeomagneticResponse | x: number; | 新增 |
| ohos.sensor | LocationOptions | altitude: number; | 新增 |
| ohos.sensor | LocationOptions | longitude: number; | 新增 |
| ohos.sensor | LocationOptions | latitude: number; | 新增 |
| ohos.sensor | sensor | off(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback?: Callback\<AccelerometerResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, callback?: Callback\<AccelerometerUncalibratedResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback?: Callback\<LightResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback?: Callback\<AmbientTemperatureResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback?: Callback\<BarometerResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback?: Callback\<GravityResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback?: Callback\<GyroscopeResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, callback?: Callback\<GyroscopeUncalibratedResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_HALL, callback?: Callback\<HallResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback?: Callback\<HeartRateResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback?: Callback\<HumidityResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, callback?: Callback\<LinearAccelerometerResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback?: Callback\<MagneticFieldResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, callback?: Callback\<MagneticFieldUncalibratedResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback?: Callback\<OrientationResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback?: Callback\<PedometerResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback?: Callback\<PedometerDetectionResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback?: Callback\<ProximityResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback?: Callback\<RotationVectorResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback?: Callback\<SignificantMotionResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback?: Callback\<WearDetectionResponse>): void; | 新增 |
| ohos.sensor | sensor | once(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: Callback\<AccelerometerResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, callback: Callback\<AccelerometerUncalibratedResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: Callback\<LightResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback: Callback\<AmbientTemperatureResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: Callback\<BarometerResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback: Callback\<GravityResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: Callback\<GyroscopeResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, callback: Callback\<GyroscopeUncalibratedResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_HALL, callback: Callback\<HallResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback: Callback\<HeartRateResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: Callback\<HumidityResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, callback: Callback\<LinearAccelerometerResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: Callback\<MagneticFieldResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, callback: Callback\<MagneticFieldUncalibratedResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: Callback\<OrientationResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: Callback\<PedometerResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback: Callback\<PedometerDetectionResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: Callback\<ProximityResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback: Callback\<RotationVectorResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback: Callback\<SignificantMotionResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: Callback\<WearDetectionResponse>): void; | 新增 |
| ohos.sensor | sensor | on(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: Callback\<AccelerometerResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, callback: Callback\<AccelerometerUncalibratedResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: Callback\<LightResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback: Callback\<AmbientTemperatureResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: Callback\<BarometerResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback: Callback\<GravityResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: Callback\<GyroscopeResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, callback: Callback\<GyroscopeUncalibratedResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_HALL, callback: Callback\<HallResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback: Callback\<HeartRateResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: Callback\<HumidityResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, callback: Callback\<LinearAccelerometerResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: Callback\<MagneticFieldResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, callback: Callback\<MagneticFieldUncalibratedResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: Callback\<OrientationResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: Callback\<PedometerResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback: Callback\<PedometerDetectionResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: Callback\<ProximityResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback: Callback\<RotationVectorResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback: Callback\<SignificantMotionResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: Callback\<WearDetectionResponse>, options?: Options): void; | 新增 |