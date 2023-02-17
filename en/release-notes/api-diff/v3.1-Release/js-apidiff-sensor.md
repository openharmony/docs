# JS API Changes of the Pan-Sensor Subsystem

The table below lists the APIs changes of the pan-sensor subsystem in OpenHarmony 3.1 Release over OpenHarmony 3.0 LTS.

## API Changes

| Module| Class| Method/Attribute/Enumeration/Constant| Change Type|
|---|---|---|---|
| ohos.vibrator | VibratorStopMode | VIBRATOR_STOP_MODE_PRESET = "preset" | Added|
| ohos.vibrator | VibratorStopMode | VIBRATOR_STOP_MODE_TIME = "time" | Added|
| ohos.vibrator | EffectId | EFFECT_CLOCK_TIMER = "haptic.clock.timer" | Added|
| ohos.vibrator | vibrator | stop(stopMode: VibratorStopMode): Promise\<void>;<br>stop(stopMode: VibratorStopMode, callback?: AsyncCallback\<void>): void; | Added|
| ohos.vibrator | vibrator | vibrate(duration: number, callback?: AsyncCallback\<void>): void;<br>vibrate(duration: number): Promise\<void>;<br>vibrate(effectId: EffectId): Promise\<void>;<br>vibrate(effectId: EffectId, callback?: AsyncCallback\<void>): void; | Added|
| ohos.sensor | WearDetectionResponse | value: number; | Added|
| ohos.sensor | HeartRateResponse | heartRate: number; | Added|
| ohos.sensor | BarometerResponse | pressure: number; | Added|
| ohos.sensor | AmbientTemperatureResponse | temperature: number; | Added|
| ohos.sensor | PedometerDetectionResponse | scalar: number; | Added|
| ohos.sensor | HumidityResponse | humidity: number; | Added|
| ohos.sensor | PedometerResponse | steps: number; | Added|
| ohos.sensor | MagneticFieldUncalibratedResponse | biasZ: number; | Added|
| ohos.sensor | MagneticFieldUncalibratedResponse | biasY: number; | Added|
| ohos.sensor | MagneticFieldUncalibratedResponse | biasX: number; | Added|
| ohos.sensor | MagneticFieldUncalibratedResponse | z: number; | Added|
| ohos.sensor | MagneticFieldUncalibratedResponse | y: number; | Added|
| ohos.sensor | MagneticFieldUncalibratedResponse | x: number; | Added|
| ohos.sensor | MagneticFieldResponse | z: number; | Added|
| ohos.sensor | MagneticFieldResponse | y: number; | Added|
| ohos.sensor | MagneticFieldResponse | x: number; | Added|
| ohos.sensor | HallResponse | status: number; | Added|
| ohos.sensor | LightResponse | intensity: number; | Added|
| ohos.sensor | ProximityResponse | distance: number; | Added|
| ohos.sensor | SignificantMotionResponse | scalar: number; | Added|
| ohos.sensor | GyroscopeUncalibratedResponse | biasZ: number; | Added|
| ohos.sensor | GyroscopeUncalibratedResponse | biasY: number; | Added|
| ohos.sensor | GyroscopeUncalibratedResponse | biasX: number; | Added|
| ohos.sensor | GyroscopeUncalibratedResponse | z: number; | Added|
| ohos.sensor | GyroscopeUncalibratedResponse | y: number; | Added|
| ohos.sensor | GyroscopeUncalibratedResponse | x: number; | Added|
| ohos.sensor | GyroscopeResponse | z: number; | Added|
| ohos.sensor | GyroscopeResponse | y: number; | Added|
| ohos.sensor | GyroscopeResponse | x: number; | Added|
| ohos.sensor | RotationVectorResponse | w: number; | Added|
| ohos.sensor | RotationVectorResponse | z: number; | Added|
| ohos.sensor | RotationVectorResponse | y: number; | Added|
| ohos.sensor | RotationVectorResponse | x: number; | Added|
| ohos.sensor | OrientationResponse | gamma: number; | Added|
| ohos.sensor | OrientationResponse | beta: number; | Added|
| ohos.sensor | OrientationResponse | alpha: number; | Added|
| ohos.sensor | GravityResponse | z: number; | Added|
| ohos.sensor | GravityResponse | y: number; | Added|
| ohos.sensor | GravityResponse | x: number; | Added|
| ohos.sensor | AccelerometerUncalibratedResponse | biasZ: number; | Added|
| ohos.sensor | AccelerometerUncalibratedResponse | biasY: number; | Added|
| ohos.sensor | AccelerometerUncalibratedResponse | biasX: number; | Added|
| ohos.sensor | AccelerometerUncalibratedResponse | z: number; | Added|
| ohos.sensor | AccelerometerUncalibratedResponse | y: number; | Added|
| ohos.sensor | AccelerometerUncalibratedResponse | x: number; | Added|
| ohos.sensor | LinearAccelerometerResponse | z: number; | Added|
| ohos.sensor | LinearAccelerometerResponse | y: number; | Added|
| ohos.sensor | LinearAccelerometerResponse | x: number; | Added|
| ohos.sensor | AccelerometerResponse | z: number; | Added|
| ohos.sensor | AccelerometerResponse | y: number; | Added|
| ohos.sensor | AccelerometerResponse | x: number; | Added|
| ohos.sensor | Response | timestamp: number; | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED = 281 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_WEAR_DETECTION = 280 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_HEART_RATE = 278 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_PEDOMETER = 266 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_PEDOMETER_DETECTION = 265 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_SIGNIFICANT_MOTION = 264 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED = 263 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED = 261 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_AMBIENT_TEMPERATURE = 260 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_ROTATION_VECTOR = 259 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_LINEAR_ACCELERATION = 258 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_GRAVITY = 257 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_ORIENTATION = 256 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_HUMIDITY = 13 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_PROXIMITY = 12 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_HALL = 10 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_BAROMETER = 8 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_MAGNETIC_FIELD = 6 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_AMBIENT_LIGHT = 5 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_GYROSCOPE = 2 | Added|
| ohos.sensor | SensorType | SENSOR_TYPE_ID_ACCELEROMETER = 1 | Added|
| ohos.sensor | Options | interval?: number; | Added|
| ohos.sensor | RotationMatrixResponse | inclination: Array\<number> | Added|
| ohos.sensor | RotationMatrixResponse | rotation: Array\<number>; | Added|
| ohos.sensor | sensor | getDirection(rotationMatrix: Array\<number>, callback: AsyncCallback\<Array\<number>>): void;<br>getDirection(rotationMatrix: Array\<number>): Promise\<Array\<number>>; | Added|
| ohos.sensor | sensor | createQuaternion(rotationVector: Array\<number>, callback: AsyncCallback\<Array\<number>>): void;<br>createQuaternion(rotationVector: Array\<number>): Promise\<Array\<number>>; | Added|
| ohos.sensor | sensor | transformCoordinateSystem(inRotationVector: Array\<number>, coordinates: CoordinatesOptions, callback: AsyncCallback\<Array\<number>>): void;<br>transformCoordinateSystem(inRotationVector: Array\<number>, coordinates: CoordinatesOptions): Promise\<Array\<number>>; | Added|
| ohos.sensor | CoordinatesOptions | y: number; | Added|
| ohos.sensor | CoordinatesOptions | x: number; | Added|
| ohos.sensor | sensor | createRotationMatrix(rotationVector: Array\<number>, callback: AsyncCallback\<Array\<number>>): void;<br>createRotationMatrix(rotationVector: Array\<number>): Promise\<Array\<number>>;<br>createRotationMatrix(gravity: Array\<number>, geomagnetic: Array\<number>, callback: AsyncCallback\<RotationMatrixResponse>): void;<br>createRotationMatrix(gravity: Array\<number>, geomagnetic: Array\<number>,): Promise\<RotationMatrixResponse>; | Added|
| ohos.sensor | sensor | getAngleModify(currentRotationMatrix: Array\<number>, preRotationMatrix: Array\<number>, callback: AsyncCallback\<Array\<number>>): void;<br>getAngleModify(currentRotationMatrix: Array\<number>, preRotationMatrix: Array\<number>): Promise\<Array\<number>>; | Added|
| ohos.sensor | sensor | getGeomagneticDip(inclinationMatrix: Array\<number>, callback: AsyncCallback\<number>): void;<br>getGeomagneticDip(inclinationMatrix: Array\<number>): Promise\<number>; | Added|
| ohos.sensor | sensor | getAltitude(seaPressure: number, currentPressure: number, callback: AsyncCallback\<number>): void;<br>getAltitude(seaPressure: number, currentPressure: number): Promise\<number>; | Added|
| ohos.sensor | sensor | getGeomagneticField(locationOptions: LocationOptions, timeMillis: number, callback: AsyncCallback\<GeomagneticResponse>): void;<br>getGeomagneticField(locationOptions: LocationOptions, timeMillis: number): Promise\<GeomagneticResponse>; | Added|
| ohos.sensor | GeomagneticResponse | totalIntensity: number; | Added|
| ohos.sensor | GeomagneticResponse | levelIntensity: number; | Added|
| ohos.sensor | GeomagneticResponse | deflectionAngle: number; | Added|
| ohos.sensor | GeomagneticResponse | geomagneticDip: number; | Added|
| ohos.sensor | GeomagneticResponse | z: number; | Added|
| ohos.sensor | GeomagneticResponse | y: number; | Added|
| ohos.sensor | GeomagneticResponse | x: number; | Added|
| ohos.sensor | LocationOptions | altitude: number; | Added|
| ohos.sensor | LocationOptions | longitude: number; | Added|
| ohos.sensor | LocationOptions | latitude: number; | Added|
| ohos.sensor | sensor | off(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback?: Callback\<AccelerometerResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, callback?: Callback\<AccelerometerUncalibratedResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback?: Callback\<LightResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback?: Callback\<AmbientTemperatureResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback?: Callback\<BarometerResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback?: Callback\<GravityResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback?: Callback\<GyroscopeResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, callback?: Callback\<GyroscopeUncalibratedResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_HALL, callback?: Callback\<HallResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback?: Callback\<HeartRateResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback?: Callback\<HumidityResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, callback?: Callback\<LinearAccelerometerResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback?: Callback\<MagneticFieldResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, callback?: Callback\<MagneticFieldUncalibratedResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback?: Callback\<OrientationResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback?: Callback\<PedometerResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback?: Callback\<PedometerDetectionResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback?: Callback\<ProximityResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback?: Callback\<RotationVectorResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback?: Callback\<SignificantMotionResponse>): void;<br>off(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback?: Callback\<WearDetectionResponse>): void; | Added|
| ohos.sensor | sensor | once(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: Callback\<AccelerometerResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, callback: Callback\<AccelerometerUncalibratedResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: Callback\<LightResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback: Callback\<AmbientTemperatureResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: Callback\<BarometerResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback: Callback\<GravityResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: Callback\<GyroscopeResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, callback: Callback\<GyroscopeUncalibratedResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_HALL, callback: Callback\<HallResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback: Callback\<HeartRateResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: Callback\<HumidityResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, callback: Callback\<LinearAccelerometerResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: Callback\<MagneticFieldResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, callback: Callback\<MagneticFieldUncalibratedResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: Callback\<OrientationResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: Callback\<PedometerResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback: Callback\<PedometerDetectionResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: Callback\<ProximityResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback: Callback\<RotationVectorResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback: Callback\<SignificantMotionResponse>): void;<br>once(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: Callback\<WearDetectionResponse>): void; | Added|
| ohos.sensor | sensor | on(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER, callback: Callback\<AccelerometerResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_ACCELEROMETER_UNCALIBRATED, callback: Callback\<AccelerometerUncalibratedResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_AMBIENT_LIGHT, callback: Callback\<LightResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_AMBIENT_TEMPERATURE, callback: Callback\<AmbientTemperatureResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_BAROMETER, callback: Callback\<BarometerResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_GRAVITY, callback: Callback\<GravityResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE, callback: Callback\<GyroscopeResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_GYROSCOPE_UNCALIBRATED, callback: Callback\<GyroscopeUncalibratedResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_HALL, callback: Callback\<HallResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_HEART_RATE, callback: Callback\<HeartRateResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_HUMIDITY, callback: Callback\<HumidityResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_LINEAR_ACCELERATION, callback: Callback\<LinearAccelerometerResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD, callback: Callback\<MagneticFieldResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_MAGNETIC_FIELD_UNCALIBRATED, callback: Callback\<MagneticFieldUncalibratedResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_ORIENTATION, callback: Callback\<OrientationResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER, callback: Callback\<PedometerResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_PEDOMETER_DETECTION, callback: Callback\<PedometerDetectionResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_PROXIMITY, callback: Callback\<ProximityResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_ROTATION_VECTOR, callback: Callback\<RotationVectorResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_SIGNIFICANT_MOTION, callback: Callback\<SignificantMotionResponse>, options?: Options): void;<br>on(type: SensorType.SENSOR_TYPE_ID_WEAR_DETECTION, callback: Callback\<WearDetectionResponse>, options?: Options): void; | Added|
