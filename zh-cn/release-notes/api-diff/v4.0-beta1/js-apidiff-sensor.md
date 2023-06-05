| 操作 | 旧版本 | 新版本 | d.ts文件 |
| ---- | ------ | ------ | -------- |
|新增|NA|模块名: ohos.vibrator<br>类名: vibrator<br>方法 or 属性：function stopVibration(callback: AsyncCallback\<void>): void;|@ohos.vibrator.d.ts|
|新增|NA|类名：vibrator<br>方法or属性：function stopVibration(callback: AsyncCallback\<void>): void;|@ohos.vibrator.d.ts|
|新增|NA|模块名: ohos.vibrator<br>类名: vibrator<br>方法 or 属性：function stopVibration(): Promise\<void>;|@ohos.vibrator.d.ts|
|新增|NA|类名：vibrator<br>方法or属性：function stopVibration(): Promise\<void>;|@ohos.vibrator.d.ts|
|新增|NA|模块名: ohos.vibrator<br>类名: vibrator<br>方法 or 属性：function isSupportEffect(effectId: string, callback: AsyncCallback\<boolean>): void;|@ohos.vibrator.d.ts|
|新增|NA|类名：vibrator<br>方法or属性：function isSupportEffect(effectId: string, callback: AsyncCallback\<boolean>): void;|@ohos.vibrator.d.ts|
|新增|NA|模块名: ohos.vibrator<br>类名: vibrator<br>方法 or 属性：function isSupportEffect(effectId: string): Promise\<boolean>;|@ohos.vibrator.d.ts|
|新增|NA|类名：vibrator<br>方法or属性：function isSupportEffect(effectId: string): Promise\<boolean>;|@ohos.vibrator.d.ts|
|新增(权限)|类名：AccelerometerResponse<br>方法 or 属性：x: number;<br>权限:N/A|类名：AccelerometerResponse<br>方法 or 属性：x: number;<br>权限:ohos.permission.ACCELEROMETER|@system.sensor.d.ts|
|新增(权限)|类名：AccelerometerResponse<br>方法 or 属性：y: number;<br>权限:N/A|类名：AccelerometerResponse<br>方法 or 属性：y: number;<br>权限:ohos.permission.ACCELEROMETER|@system.sensor.d.ts|
|新增(权限)|类名：AccelerometerResponse<br>方法 or 属性：z: number;<br>权限:N/A|类名：AccelerometerResponse<br>方法 or 属性：z: number;<br>权限:ohos.permission.ACCELEROMETER|@system.sensor.d.ts|
|新增(权限)|类名：subscribeAccelerometerOptions<br>方法 or 属性：interval: string;<br>权限:N/A|类名：subscribeAccelerometerOptions<br>方法 or 属性：interval: string;<br>权限:ohos.permission.ACCELEROMETER|@system.sensor.d.ts|
|新增(权限)|类名：subscribeAccelerometerOptions<br>方法 or 属性：success: (data: AccelerometerResponse) => void;<br>权限:N/A|类名：subscribeAccelerometerOptions<br>方法 or 属性：success: (data: AccelerometerResponse) => void;<br>权限:ohos.permission.ACCELEROMETER|@system.sensor.d.ts|
|新增(权限)|类名：subscribeAccelerometerOptions<br>方法 or 属性：fail?: (data: string, code: number) => void;<br>权限:N/A|类名：subscribeAccelerometerOptions<br>方法 or 属性：fail?: (data: string, code: number) => void;<br>权限:ohos.permission.ACCELEROMETER|@system.sensor.d.ts|
|新增(权限)|类名：StepCounterResponse<br>方法 or 属性：steps: number;<br>权限:N/A|类名：StepCounterResponse<br>方法 or 属性：steps: number;<br>权限:ohos.permission.ACTIVITY_MOTION|@system.sensor.d.ts|
|新增(权限)|类名：SubscribeStepCounterOptions<br>方法 or 属性：success: (data: StepCounterResponse) => void;<br>权限:N/A|类名：SubscribeStepCounterOptions<br>方法 or 属性：success: (data: StepCounterResponse) => void;<br>权限:ohos.permission.ACTIVITY_MOTION|@system.sensor.d.ts|
|新增(权限)|类名：SubscribeStepCounterOptions<br>方法 or 属性：fail?: (data: string, code: number) => void;<br>权限:N/A|类名：SubscribeStepCounterOptions<br>方法 or 属性：fail?: (data: string, code: number) => void;<br>权限:ohos.permission.ACTIVITY_MOTION|@system.sensor.d.ts|
|新增(权限)|类名：HeartRateResponse<br>方法 or 属性：heartRate: number;<br>权限:N/A|类名：HeartRateResponse<br>方法 or 属性：heartRate: number;<br>权限:ohos.permission.READ_HEALTH_DATA|@system.sensor.d.ts|
|新增(权限)|类名：SubscribeHeartRateOptions<br>方法 or 属性：success: (data: HeartRateResponse) => void;<br>权限:N/A|类名：SubscribeHeartRateOptions<br>方法 or 属性：success: (data: HeartRateResponse) => void;<br>权限:ohos.permission.READ_HEALTH_DATA|@system.sensor.d.ts|
|新增(权限)|类名：SubscribeHeartRateOptions<br>方法 or 属性：fail?: (data: string, code: number) => void;<br>权限:N/A|类名：SubscribeHeartRateOptions<br>方法 or 属性：fail?: (data: string, code: number) => void;<br>权限:ohos.permission.READ_HEALTH_DATA|@system.sensor.d.ts|
|新增(权限)|类名：GyroscopeResponse<br>方法 or 属性：x: number;<br>权限:N/A|类名：GyroscopeResponse<br>方法 or 属性：x: number;<br>权限:ohos.permission.GYROSCOPE|@system.sensor.d.ts|
|新增(权限)|类名：GyroscopeResponse<br>方法 or 属性：y: number;<br>权限:N/A|类名：GyroscopeResponse<br>方法 or 属性：y: number;<br>权限:ohos.permission.GYROSCOPE|@system.sensor.d.ts|
|新增(权限)|类名：GyroscopeResponse<br>方法 or 属性：z: number;<br>权限:N/A|类名：GyroscopeResponse<br>方法 or 属性：z: number;<br>权限:ohos.permission.GYROSCOPE|@system.sensor.d.ts|
|新增(权限)|类名：SubscribeGyroscopeOptions<br>方法 or 属性：interval: string;<br>权限:N/A|类名：SubscribeGyroscopeOptions<br>方法 or 属性：interval: string;<br>权限:ohos.permission.GYROSCOPE|@system.sensor.d.ts|
|新增(权限)|类名：SubscribeGyroscopeOptions<br>方法 or 属性：success: (data: GyroscopeResponse) => void;<br>权限:N/A|类名：SubscribeGyroscopeOptions<br>方法 or 属性：success: (data: GyroscopeResponse) => void;<br>权限:ohos.permission.GYROSCOPE|@system.sensor.d.ts|
|新增(权限)|类名：SubscribeGyroscopeOptions<br>方法 or 属性：fail?: (data: string, code: number) => void;<br>权限:N/A|类名：SubscribeGyroscopeOptions<br>方法 or 属性：fail?: (data: string, code: number) => void;<br>权限:ohos.permission.GYROSCOPE|@system.sensor.d.ts|
