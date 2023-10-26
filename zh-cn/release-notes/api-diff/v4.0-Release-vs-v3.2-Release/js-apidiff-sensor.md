| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|类名：sensor;<br>方法or属性：function on(type: SensorId.COLOR, callback: Callback\<ColorResponse>, options?: Options): void;|@ohos.sensor.d.ts|
|新增|NA|类名：sensor;<br>方法or属性：function on(type: SensorId.SAR, callback: Callback\<SarResponse>, options?: Options): void;|@ohos.sensor.d.ts|
|新增|NA|类名：sensor;<br>方法or属性：function off(type: SensorId.COLOR, callback?: Callback\<ColorResponse>): void;|@ohos.sensor.d.ts|
|新增|NA|类名：sensor;<br>方法or属性：function off(type: SensorId.SAR, callback?: Callback\<SarResponse>): void;|@ohos.sensor.d.ts|
|新增|NA|类名：SensorId;<br>方法or属性：COLOR = 14|@ohos.sensor.d.ts|
|新增|NA|类名：SensorId;<br>方法or属性：SAR = 15|@ohos.sensor.d.ts|
|新增|NA|类名：ColorResponse;<br>方法or属性：lightIntensity: number;|@ohos.sensor.d.ts|
|新增|NA|类名：ColorResponse;<br>方法or属性：colorTemperature: number;|@ohos.sensor.d.ts|
|新增|NA|类名：SarResponse;<br>方法or属性：absorptionRatio: number;|@ohos.sensor.d.ts|
|新增|NA|类名：vibrator;<br>方法or属性：function stopVibration(callback: AsyncCallback\<void>): void;|@ohos.vibrator.d.ts|
|新增|NA|类名：vibrator;<br>方法or属性：function stopVibration(): Promise\<void>;|@ohos.vibrator.d.ts|
|新增|NA|类名：vibrator;<br>方法or属性：function isSupportEffect(effectId: string, callback: AsyncCallback\<boolean>): void;|@ohos.vibrator.d.ts|
|新增|NA|类名：vibrator;<br>方法or属性：function isSupportEffect(effectId: string): Promise\<boolean>;|@ohos.vibrator.d.ts|
|新增|NA|类名：HapticFileDescriptor;<br>方法or属性：fd: number;|@ohos.vibrator.d.ts|
|新增|NA|类名：HapticFileDescriptor;<br>方法or属性：offset?: number;|@ohos.vibrator.d.ts|
|新增|NA|类名：HapticFileDescriptor;<br>方法or属性：length?: number;|@ohos.vibrator.d.ts|
|废弃版本有变化|类名：sensor;<br>方法or属性：function getGeomagneticField(locationOptions: LocationOptions, timeMillis: number): Promise\<GeomagneticResponse>;<br>旧版本信息：|类名：sensor;<br>方法or属性：function getGeomagneticField(locationOptions: LocationOptions, timeMillis: number): Promise\<GeomagneticResponse>;<br>新版本信息：9<br>代替接口： sensor#getGeomagneticInfo|@ohos.sensor.d.ts|
|废弃版本有变化|类名：sensor;<br>方法or属性：function getAltitude(seaPressure: number, currentPressure: number): Promise\<number>;<br>旧版本信息：|类名：sensor;<br>方法or属性：function getAltitude(seaPressure: number, currentPressure: number): Promise\<number>;<br>新版本信息：9<br>代替接口： sensor#getDeviceAltitude|@ohos.sensor.d.ts|
|废弃版本有变化|类名：sensor;<br>方法or属性：function getGeomagneticDip(inclinationMatrix: Array\<number>): Promise\<number>;<br>旧版本信息：|类名：sensor;<br>方法or属性：function getGeomagneticDip(inclinationMatrix: Array\<number>): Promise\<number>;<br>新版本信息：9<br>代替接口： sensor#getInclination|@ohos.sensor.d.ts|
|废弃版本有变化|类名：sensor;<br>方法or属性：function getAngleModify(currentRotationMatrix: Array\<number>, preRotationMatrix: Array\<number>): Promise\<Array\<number>>;<br>旧版本信息：|类名：sensor;<br>方法or属性：function getAngleModify(currentRotationMatrix: Array\<number>, preRotationMatrix: Array\<number>): Promise\<Array\<number>>;<br>新版本信息：9<br>代替接口： sensor#getAngleVariation|@ohos.sensor.d.ts|
|废弃版本有变化|类名：sensor;<br>方法or属性：function createRotationMatrix(rotationVector: Array\<number>): Promise\<Array\<number>>;<br>旧版本信息：|类名：sensor;<br>方法or属性：function createRotationMatrix(rotationVector: Array\<number>): Promise\<Array\<number>>;<br>新版本信息：9<br>代替接口： sensor#getRotationMatrix|@ohos.sensor.d.ts|
|废弃版本有变化|类名：sensor;<br>方法or属性：function createRotationMatrix(gravity: Array\<number>, geomagnetic: Array\<number>,): Promise\<RotationMatrixResponse>;<br>旧版本信息：|类名：sensor;<br>方法or属性：function createRotationMatrix(gravity: Array\<number>, geomagnetic: Array\<number>,): Promise\<RotationMatrixResponse>;<br>新版本信息：9<br>代替接口： sensor#getRotationMatrix|@ohos.sensor.d.ts|
|废弃版本有变化|类名：sensor;<br>方法or属性：function transformCoordinateSystem(inRotationVector: Array\<number>, coordinates: CoordinatesOptions): Promise\<Array\<number>>;<br>旧版本信息：|类名：sensor;<br>方法or属性：function transformCoordinateSystem(inRotationVector: Array\<number>, coordinates: CoordinatesOptions): Promise\<Array\<number>>;<br>新版本信息：9<br>代替接口： sensor#transformRotationMatrix|@ohos.sensor.d.ts|
|废弃版本有变化|类名：sensor;<br>方法or属性：function createQuaternion(rotationVector: Array\<number>): Promise\<Array\<number>>;<br>旧版本信息：|类名：sensor;<br>方法or属性：function createQuaternion(rotationVector: Array\<number>): Promise\<Array\<number>>;<br>新版本信息：9<br>代替接口： sensor#getQuaternion|@ohos.sensor.d.ts|
|废弃版本有变化|类名：sensor;<br>方法or属性：function getDirection(rotationMatrix: Array\<number>): Promise\<Array\<number>>;<br>旧版本信息：|类名：sensor;<br>方法or属性：function getDirection(rotationMatrix: Array\<number>): Promise\<Array\<number>>;<br>新版本信息：9<br>代替接口： sensor#getOrientation|@ohos.sensor.d.ts|
|废弃版本有变化|类名：vibrator;<br>方法or属性：function vibrate(duration: number): Promise\<void>;<br>旧版本信息：|类名：vibrator;<br>方法or属性：function vibrate(duration: number): Promise\<void>;<br>新版本信息：9<br>代替接口： vibrator#startVibration|@ohos.vibrator.d.ts|
|废弃版本有变化|类名：vibrator;<br>方法or属性：function vibrate(effectId: EffectId, callback?: AsyncCallback\<void>): void;<br>旧版本信息：|类名：vibrator;<br>方法or属性：function vibrate(effectId: EffectId, callback?: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： vibrator#startVibration|@ohos.vibrator.d.ts|
|废弃版本有变化|类名：vibrator;<br>方法or属性：function stop(stopMode: VibratorStopMode, callback?: AsyncCallback\<void>): void;<br>旧版本信息：|类名：vibrator;<br>方法or属性：function stop(stopMode: VibratorStopMode, callback?: AsyncCallback\<void>): void;<br>新版本信息：9<br>代替接口： vibrator#stopVibration|@ohos.vibrator.d.ts|
|错误码有变化|类名：vibrator;<br>方法or属性：function startVibration(effect: VibrateEffect, attribute: VibrateAttribute, callback: AsyncCallback\<void>): void;<br>旧版本信息：201,401,14600101|类名：vibrator;<br>方法or属性：function startVibration(effect: VibrateEffect, attribute: VibrateAttribute, callback: AsyncCallback\<void>): void;<br>新版本信息：201,401,801,14600101|@ohos.vibrator.d.ts|
|错误码有变化|类名：vibrator;<br>方法or属性：function startVibration(effect: VibrateEffect, attribute: VibrateAttribute): Promise\<void>;<br>旧版本信息：201,401,14600101|类名：vibrator;<br>方法or属性：function startVibration(effect: VibrateEffect, attribute: VibrateAttribute): Promise\<void>;<br>新版本信息：201,401,801,14600101|@ohos.vibrator.d.ts|
|权限有变化|类名：vibrator;<br>方法or属性：function vibrate(duration: number): Promise\<void>;<br>旧版本信息：|类名：vibrator;<br>方法or属性：function vibrate(duration: number): Promise\<void>;<br>新版本信息：ohos.permission.VIBRATE|@ohos.vibrator.d.ts|
|权限有变化|类名：vibrator;<br>方法or属性：function vibrate(effectId: EffectId, callback?: AsyncCallback\<void>): void;<br>旧版本信息：|类名：vibrator;<br>方法or属性：function vibrate(effectId: EffectId, callback?: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.VIBRATE|@ohos.vibrator.d.ts|
|权限有变化|类名：vibrator;<br>方法or属性：function stop(stopMode: VibratorStopMode, callback?: AsyncCallback\<void>): void;<br>旧版本信息：|类名：vibrator;<br>方法or属性：function stop(stopMode: VibratorStopMode, callback?: AsyncCallback\<void>): void;<br>新版本信息：ohos.permission.VIBRATE|@ohos.vibrator.d.ts|
|权限有变化|类名：AccelerometerResponse;<br>方法or属性：x: number;<br>旧版本信息：|类名：AccelerometerResponse;<br>方法or属性：x: number;<br>新版本信息：ohos.permission.ACCELEROMETER|@system.sensor.d.ts|
|权限有变化|类名：GyroscopeResponse;<br>方法or属性：x: number;<br>旧版本信息：|类名：GyroscopeResponse;<br>方法or属性：x: number;<br>新版本信息：ohos.permission.GYROSCOPE|@system.sensor.d.ts|
|权限有变化|类名：AccelerometerResponse;<br>方法or属性：y: number;<br>旧版本信息：|类名：AccelerometerResponse;<br>方法or属性：y: number;<br>新版本信息：ohos.permission.ACCELEROMETER|@system.sensor.d.ts|
|权限有变化|类名：GyroscopeResponse;<br>方法or属性：y: number;<br>旧版本信息：|类名：GyroscopeResponse;<br>方法or属性：y: number;<br>新版本信息：ohos.permission.GYROSCOPE|@system.sensor.d.ts|
|权限有变化|类名：AccelerometerResponse;<br>方法or属性：z: number;<br>旧版本信息：|类名：AccelerometerResponse;<br>方法or属性：z: number;<br>新版本信息：ohos.permission.ACCELEROMETER|@system.sensor.d.ts|
|权限有变化|类名：GyroscopeResponse;<br>方法or属性：z: number;<br>旧版本信息：|类名：GyroscopeResponse;<br>方法or属性：z: number;<br>新版本信息：ohos.permission.GYROSCOPE|@system.sensor.d.ts|
|权限有变化|类名：subscribeAccelerometerOptions;<br>方法or属性：interval: string;<br>旧版本信息：|类名：subscribeAccelerometerOptions;<br>方法or属性：interval: string;<br>新版本信息：ohos.permission.ACCELEROMETER|@system.sensor.d.ts|
|权限有变化|类名：SubscribeGyroscopeOptions;<br>方法or属性：interval: string;<br>旧版本信息：|类名：SubscribeGyroscopeOptions;<br>方法or属性：interval: string;<br>新版本信息：ohos.permission.GYROSCOPE|@system.sensor.d.ts|
|权限有变化|类名：subscribeAccelerometerOptions;<br>方法or属性：success: (data: AccelerometerResponse) => void;<br>旧版本信息：|类名：subscribeAccelerometerOptions;<br>方法or属性：success: (data: AccelerometerResponse) => void;<br>新版本信息：ohos.permission.ACCELEROMETER|@system.sensor.d.ts|
|权限有变化|类名：subscribeAccelerometerOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：subscribeAccelerometerOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：ohos.permission.ACCELEROMETER|@system.sensor.d.ts|
|权限有变化|类名：SubscribeStepCounterOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：SubscribeStepCounterOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：ohos.permission.ACTIVITY_MOTION|@system.sensor.d.ts|
|权限有变化|类名：SubscribeHeartRateOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：SubscribeHeartRateOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：ohos.permission.READ_HEALTH_DATA|@system.sensor.d.ts|
|权限有变化|类名：SubscribeGyroscopeOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：SubscribeGyroscopeOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：ohos.permission.GYROSCOPE|@system.sensor.d.ts|
|权限有变化|类名：StepCounterResponse;<br>方法or属性：steps: number;<br>旧版本信息：|类名：StepCounterResponse;<br>方法or属性：steps: number;<br>新版本信息：ohos.permission.ACTIVITY_MOTION|@system.sensor.d.ts|
|权限有变化|类名：SubscribeStepCounterOptions;<br>方法or属性：success: (data: StepCounterResponse) => void;<br>旧版本信息：|类名：SubscribeStepCounterOptions;<br>方法or属性：success: (data: StepCounterResponse) => void;<br>新版本信息：ohos.permission.ACTIVITY_MOTION|@system.sensor.d.ts|
|权限有变化|类名：HeartRateResponse;<br>方法or属性：heartRate: number;<br>旧版本信息：|类名：HeartRateResponse;<br>方法or属性：heartRate: number;<br>新版本信息：ohos.permission.READ_HEALTH_DATA|@system.sensor.d.ts|
|权限有变化|类名：SubscribeHeartRateOptions;<br>方法or属性：success: (data: HeartRateResponse) => void;<br>旧版本信息：|类名：SubscribeHeartRateOptions;<br>方法or属性：success: (data: HeartRateResponse) => void;<br>新版本信息：ohos.permission.READ_HEALTH_DATA|@system.sensor.d.ts|
|权限有变化|类名：SubscribeGyroscopeOptions;<br>方法or属性：success: (data: GyroscopeResponse) => void;<br>旧版本信息：|类名：SubscribeGyroscopeOptions;<br>方法or属性：success: (data: GyroscopeResponse) => void;<br>新版本信息：ohos.permission.GYROSCOPE|@system.sensor.d.ts|
|权限有变化|类名：VibrateOptions;<br>方法or属性：mode?: 'long' \| 'short';<br>旧版本信息：|类名：VibrateOptions;<br>方法or属性：mode?: 'long' \| 'short';<br>新版本信息：ohos.permission.VIBRATE|@system.vibrator.d.ts|
|权限有变化|类名：VibrateOptions;<br>方法or属性：success: () => void;<br>旧版本信息：|类名：VibrateOptions;<br>方法or属性：success: () => void;<br>新版本信息：ohos.permission.VIBRATE|@system.vibrator.d.ts|
|权限有变化|类名：VibrateOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>旧版本信息：|类名：VibrateOptions;<br>方法or属性：fail?: (data: string, code: number) => void;<br>新版本信息：ohos.permission.VIBRATE|@system.vibrator.d.ts|
|权限有变化|类名：VibrateOptions;<br>方法or属性：complete?: () => void;<br>旧版本信息：|类名：VibrateOptions;<br>方法or属性：complete?: () => void;<br>新版本信息：ohos.permission.VIBRATE|@system.vibrator.d.ts|
|type有变化|类名：Sensor;<br>方法or属性：sensorName:string;<br>旧版本信息：|类名：Sensor;<br>方法or属性：sensorName:string;<br>新版本信息：string|@ohos.sensor.d.ts|
|type有变化|类名：Sensor;<br>方法or属性：vendorName:string;<br>旧版本信息：|类名：Sensor;<br>方法or属性：vendorName:string;<br>新版本信息：string|@ohos.sensor.d.ts|
|type有变化|类名：Sensor;<br>方法or属性：firmwareVersion:string;<br>旧版本信息：|类名：Sensor;<br>方法or属性：firmwareVersion:string;<br>新版本信息：string|@ohos.sensor.d.ts|
|type有变化|类名：Sensor;<br>方法or属性：hardwareVersion:string;<br>旧版本信息：|类名：Sensor;<br>方法or属性：hardwareVersion:string;<br>新版本信息：string|@ohos.sensor.d.ts|
|type有变化|类名：Sensor;<br>方法or属性：sensorId:number;<br>旧版本信息：|类名：Sensor;<br>方法or属性：sensorId:number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：Sensor;<br>方法or属性：maxRange:number;<br>旧版本信息：|类名：Sensor;<br>方法or属性：maxRange:number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：Sensor;<br>方法or属性：minSamplePeriod:number;<br>旧版本信息：|类名：Sensor;<br>方法or属性：minSamplePeriod:number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：Sensor;<br>方法or属性：maxSamplePeriod:number;<br>旧版本信息：|类名：Sensor;<br>方法or属性：maxSamplePeriod:number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：Sensor;<br>方法or属性：precision:number;<br>旧版本信息：|类名：Sensor;<br>方法or属性：precision:number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：Sensor;<br>方法or属性：power:number;<br>旧版本信息：|类名：Sensor;<br>方法or属性：power:number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GeomagneticResponse;<br>方法or属性：x: number;<br>旧版本信息：|类名：GeomagneticResponse;<br>方法or属性：x: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：CoordinatesOptions;<br>方法or属性：x: number;<br>旧版本信息：|类名：CoordinatesOptions;<br>方法or属性：x: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：AccelerometerResponse;<br>方法or属性：x: number;<br>旧版本信息：|类名：AccelerometerResponse;<br>方法or属性：x: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：LinearAccelerometerResponse;<br>方法or属性：x: number;<br>旧版本信息：|类名：LinearAccelerometerResponse;<br>方法or属性：x: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：AccelerometerUncalibratedResponse;<br>方法or属性：x: number;<br>旧版本信息：|类名：AccelerometerUncalibratedResponse;<br>方法or属性：x: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GravityResponse;<br>方法or属性：x: number;<br>旧版本信息：|类名：GravityResponse;<br>方法or属性：x: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：RotationVectorResponse;<br>方法or属性：x: number;<br>旧版本信息：|类名：RotationVectorResponse;<br>方法or属性：x: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GyroscopeResponse;<br>方法or属性：x: number;<br>旧版本信息：|类名：GyroscopeResponse;<br>方法or属性：x: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GyroscopeUncalibratedResponse;<br>方法or属性：x: number;<br>旧版本信息：|类名：GyroscopeUncalibratedResponse;<br>方法or属性：x: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：MagneticFieldResponse;<br>方法or属性：x: number;<br>旧版本信息：|类名：MagneticFieldResponse;<br>方法or属性：x: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：MagneticFieldUncalibratedResponse;<br>方法or属性：x: number;<br>旧版本信息：|类名：MagneticFieldUncalibratedResponse;<br>方法or属性：x: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GeomagneticResponse;<br>方法or属性：y: number;<br>旧版本信息：|类名：GeomagneticResponse;<br>方法or属性：y: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：CoordinatesOptions;<br>方法or属性：y: number;<br>旧版本信息：|类名：CoordinatesOptions;<br>方法or属性：y: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：AccelerometerResponse;<br>方法or属性：y: number;<br>旧版本信息：|类名：AccelerometerResponse;<br>方法or属性：y: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：LinearAccelerometerResponse;<br>方法or属性：y: number;<br>旧版本信息：|类名：LinearAccelerometerResponse;<br>方法or属性：y: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：AccelerometerUncalibratedResponse;<br>方法or属性：y: number;<br>旧版本信息：|类名：AccelerometerUncalibratedResponse;<br>方法or属性：y: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GravityResponse;<br>方法or属性：y: number;<br>旧版本信息：|类名：GravityResponse;<br>方法or属性：y: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：RotationVectorResponse;<br>方法or属性：y: number;<br>旧版本信息：|类名：RotationVectorResponse;<br>方法or属性：y: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GyroscopeResponse;<br>方法or属性：y: number;<br>旧版本信息：|类名：GyroscopeResponse;<br>方法or属性：y: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GyroscopeUncalibratedResponse;<br>方法or属性：y: number;<br>旧版本信息：|类名：GyroscopeUncalibratedResponse;<br>方法or属性：y: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：MagneticFieldResponse;<br>方法or属性：y: number;<br>旧版本信息：|类名：MagneticFieldResponse;<br>方法or属性：y: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：MagneticFieldUncalibratedResponse;<br>方法or属性：y: number;<br>旧版本信息：|类名：MagneticFieldUncalibratedResponse;<br>方法or属性：y: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GeomagneticResponse;<br>方法or属性：z: number;<br>旧版本信息：|类名：GeomagneticResponse;<br>方法or属性：z: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：AccelerometerResponse;<br>方法or属性：z: number;<br>旧版本信息：|类名：AccelerometerResponse;<br>方法or属性：z: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：LinearAccelerometerResponse;<br>方法or属性：z: number;<br>旧版本信息：|类名：LinearAccelerometerResponse;<br>方法or属性：z: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：AccelerometerUncalibratedResponse;<br>方法or属性：z: number;<br>旧版本信息：|类名：AccelerometerUncalibratedResponse;<br>方法or属性：z: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GravityResponse;<br>方法or属性：z: number;<br>旧版本信息：|类名：GravityResponse;<br>方法or属性：z: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：RotationVectorResponse;<br>方法or属性：z: number;<br>旧版本信息：|类名：RotationVectorResponse;<br>方法or属性：z: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GyroscopeResponse;<br>方法or属性：z: number;<br>旧版本信息：|类名：GyroscopeResponse;<br>方法or属性：z: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GyroscopeUncalibratedResponse;<br>方法or属性：z: number;<br>旧版本信息：|类名：GyroscopeUncalibratedResponse;<br>方法or属性：z: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：MagneticFieldResponse;<br>方法or属性：z: number;<br>旧版本信息：|类名：MagneticFieldResponse;<br>方法or属性：z: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：MagneticFieldUncalibratedResponse;<br>方法or属性：z: number;<br>旧版本信息：|类名：MagneticFieldUncalibratedResponse;<br>方法or属性：z: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GeomagneticResponse;<br>方法or属性：geomagneticDip: number;<br>旧版本信息：|类名：GeomagneticResponse;<br>方法or属性：geomagneticDip: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GeomagneticResponse;<br>方法or属性：deflectionAngle: number;<br>旧版本信息：|类名：GeomagneticResponse;<br>方法or属性：deflectionAngle: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GeomagneticResponse;<br>方法or属性：levelIntensity: number;<br>旧版本信息：|类名：GeomagneticResponse;<br>方法or属性：levelIntensity: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GeomagneticResponse;<br>方法or属性：totalIntensity: number;<br>旧版本信息：|类名：GeomagneticResponse;<br>方法or属性：totalIntensity: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：LocationOptions;<br>方法or属性：latitude: number;<br>旧版本信息：|类名：LocationOptions;<br>方法or属性：latitude: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：LocationOptions;<br>方法or属性：longitude: number;<br>旧版本信息：|类名：LocationOptions;<br>方法or属性：longitude: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：LocationOptions;<br>方法or属性：altitude: number;<br>旧版本信息：|类名：LocationOptions;<br>方法or属性：altitude: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：RotationMatrixResponse;<br>方法or属性：rotation: Array\<number>;<br>旧版本信息：|类名：RotationMatrixResponse;<br>方法or属性：rotation: Array\<number>;<br>新版本信息：Array\<number>|@ohos.sensor.d.ts|
|type有变化|类名：RotationMatrixResponse;<br>方法or属性：inclination: Array\<number><br>旧版本信息：|类名：RotationMatrixResponse;<br>方法or属性：inclination: Array\<number><br>新版本信息：Array\<number>|@ohos.sensor.d.ts|
|type有变化|类名：Options;<br>方法or属性：interval?: number;<br>旧版本信息：|类名：Options;<br>方法or属性：interval?: number;<br>新版本信息：?number|@ohos.sensor.d.ts|
|type有变化|类名：Response;<br>方法or属性：timestamp: number;<br>旧版本信息：|类名：Response;<br>方法or属性：timestamp: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：AccelerometerUncalibratedResponse;<br>方法or属性：biasX: number;<br>旧版本信息：|类名：AccelerometerUncalibratedResponse;<br>方法or属性：biasX: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GyroscopeUncalibratedResponse;<br>方法or属性：biasX: number;<br>旧版本信息：|类名：GyroscopeUncalibratedResponse;<br>方法or属性：biasX: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：MagneticFieldUncalibratedResponse;<br>方法or属性：biasX: number;<br>旧版本信息：|类名：MagneticFieldUncalibratedResponse;<br>方法or属性：biasX: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：AccelerometerUncalibratedResponse;<br>方法or属性：biasY: number;<br>旧版本信息：|类名：AccelerometerUncalibratedResponse;<br>方法or属性：biasY: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GyroscopeUncalibratedResponse;<br>方法or属性：biasY: number;<br>旧版本信息：|类名：GyroscopeUncalibratedResponse;<br>方法or属性：biasY: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：MagneticFieldUncalibratedResponse;<br>方法or属性：biasY: number;<br>旧版本信息：|类名：MagneticFieldUncalibratedResponse;<br>方法or属性：biasY: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：AccelerometerUncalibratedResponse;<br>方法or属性：biasZ: number;<br>旧版本信息：|类名：AccelerometerUncalibratedResponse;<br>方法or属性：biasZ: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：GyroscopeUncalibratedResponse;<br>方法or属性：biasZ: number;<br>旧版本信息：|类名：GyroscopeUncalibratedResponse;<br>方法or属性：biasZ: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：MagneticFieldUncalibratedResponse;<br>方法or属性：biasZ: number;<br>旧版本信息：|类名：MagneticFieldUncalibratedResponse;<br>方法or属性：biasZ: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：OrientationResponse;<br>方法or属性：alpha: number;<br>旧版本信息：|类名：OrientationResponse;<br>方法or属性：alpha: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：OrientationResponse;<br>方法or属性：beta: number;<br>旧版本信息：|类名：OrientationResponse;<br>方法or属性：beta: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：OrientationResponse;<br>方法or属性：gamma: number;<br>旧版本信息：|类名：OrientationResponse;<br>方法or属性：gamma: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：RotationVectorResponse;<br>方法or属性：w: number;<br>旧版本信息：|类名：RotationVectorResponse;<br>方法or属性：w: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：SignificantMotionResponse;<br>方法or属性：scalar: number;<br>旧版本信息：|类名：SignificantMotionResponse;<br>方法or属性：scalar: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：PedometerDetectionResponse;<br>方法or属性：scalar: number;<br>旧版本信息：|类名：PedometerDetectionResponse;<br>方法or属性：scalar: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：ProximityResponse;<br>方法or属性：distance: number;<br>旧版本信息：|类名：ProximityResponse;<br>方法or属性：distance: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：LightResponse;<br>方法or属性：intensity: number;<br>旧版本信息：|类名：LightResponse;<br>方法or属性：intensity: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：HallResponse;<br>方法or属性：status: number;<br>旧版本信息：|类名：HallResponse;<br>方法or属性：status: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：PedometerResponse;<br>方法or属性：steps: number;<br>旧版本信息：|类名：PedometerResponse;<br>方法or属性：steps: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：HumidityResponse;<br>方法or属性：humidity: number;<br>旧版本信息：|类名：HumidityResponse;<br>方法or属性：humidity: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：AmbientTemperatureResponse;<br>方法or属性：temperature: number;<br>旧版本信息：|类名：AmbientTemperatureResponse;<br>方法or属性：temperature: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：BarometerResponse;<br>方法or属性：pressure: number;<br>旧版本信息：|类名：BarometerResponse;<br>方法or属性：pressure: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：HeartRateResponse;<br>方法or属性：heartRate: number;<br>旧版本信息：|类名：HeartRateResponse;<br>方法or属性：heartRate: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：WearDetectionResponse;<br>方法or属性：value: number;<br>旧版本信息：|类名：WearDetectionResponse;<br>方法or属性：value: number;<br>新版本信息：number|@ohos.sensor.d.ts|
|type有变化|类名：vibrator;<br>方法or属性：type VibrateEffect = VibrateTime \| VibratePreset \| VibrateFromFile;<br>旧版本信息：|类名：vibrator;<br>方法or属性：type VibrateEffect = VibrateTime \| VibratePreset \| VibrateFromFile;<br>新版本信息：VibrateTime \| VibratePreset \| VibrateFromFile|@ohos.vibrator.d.ts|
|函数有变化|类名：vibrator;<br>方法or属性：type VibrateEffect = VibrateTime \| VibratePreset;|类名：vibrator;<br>方法or属性：type VibrateEffect = VibrateTime \| VibratePreset \| VibrateFromFile;|@ohos.vibrator.d.ts|
