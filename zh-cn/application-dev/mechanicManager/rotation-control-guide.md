# 设备转动控制开发指南
<!--Kit: Mechanic Kit-->
<!--Subsystem: Mechanic-->
<!--Owner: @hobbycao-->
<!--Designer: @saga2025-->
<!--Tester: @zhaodengqi-->
<!--Adviser: @foryourself-->

从API version 20开始，支持使用机械体设备控制器，提供更丰富的拍摄体验，如控制设备转动（仅限系统应用）。

使用手机作为控制终端，可以通过精确的参数设置调整云台或机械臂等设备的角度和运动轨迹，帮助快速构建控制机械体设备的应用。

## 接口介绍

机械体设备管理公开API接口使用指导请参见[MechanicManager API参考](../reference/apis-mechanic-kit/js-apis-mechanicManager.md)。
机械体设备管理系统API接口使用指导请参见[MechanicManager API参考](../reference/apis-mechanic-kit/js-apis-mechanicManager-sys.md)。

| 接口名                                                               | 描述                       |
| -------------------------------------------------------------------- | -------------------------- |
|on(type: 'attachStateChange', callback: Callback\<AttachStateChangeInfo>): void | 注册attachStateChange事件的回调监听，等待连接状态变化。<br>**说明**：从API version 20开始支持。|
|off(type: 'attachStateChange', callback?: Callback\<AttachStateChangeInfo>): void | 取消注册attachStateChange事件的回调监听。<br>**说明**：从API version 20开始支持。|
|getAttachedMechDevices(): MechInfo[] | 获取已连接的机械体设备列表。<br>**说明**：从API version 20开始支持。|
|setUserOperation(operation: Operation, mac: string, params: string): void | 设置用户操作。<br>**说明**：从API version 20开始支持。|
|setCameraTrackingEnabled(isEnabled: boolean): void | 启用或禁用摄像头跟踪。<br>**说明**：从API version 20开始支持。|
|getCameraTrackingEnabled(): boolean | 检查是否启用了摄像头跟踪。<br>**说明**：从API version 20开始支持。|
|getCameraTrackingLayout(): CameraTrackingLayout | 获取此机械体设备摄像头跟踪布局。<br>**说明**：从API version 20开始支持。|
|rotate(mechId: number, angles: RotationAngles, duration: number): Promise\<Result> | 将机械体设备旋转到相对角度。<br>**说明**：从API version 20开始支持。|
|rotateToEulerAngles(mechId: number, angles: EulerAngles, duration: number): Promise\<Result> | 将机械体设备旋转到绝对角度。<br>**说明**：从API version 20开始支持。|
|getMaxRotationTime(mechId: number): number | 获取机械体设备的最大连续旋转持续时间。<br>**说明**：从API version 20开始支持。|
|getMaxRotationSpeed(mechId: number): RotationSpeed | 获取机械体设备的最大旋转速度。<br>**说明**：从API version 20开始支持。|
|stopMoving(mechId: number): Promise\<void> | 停止机械体设备的移动。<br>**说明**：从API version 20开始支持。|
|getCurrentAngles(mechId: number): EulerAngles | 获取机械体设备的当前角度。<br>**说明**：从API version 20开始支持。|
|getRotationLimits(mechId: number): RotationLimits | 获取指定机械体设备相对于参考点的最大旋转角度。<br>**说明**：从API version 20开始支持。|
|getRotationAxesStatus(mechId: number): RotationAxesStatus | 获取旋转轴的状态。<br>**说明**：从API version 20开始支持。|
|on(type: 'rotationAxesStatusChange', callback: Callback\<RotationAxesStateChangeInfo>): void | 注册rotationAxesStatusChange事件的回调监听。<br>**说明**：从API version 20开始支持。|
|off(type: 'rotationAxesStatusChange', callback?: Callback\<RotationAxesStateChangeInfo>): void | 取消注册rotationAxesStatusChange事件的回调监听。<br>**说明**：从API version 20开始支持。|

## 开发步骤

### 开发准备

1. 一台支持Mechanic Kit协议的机械体设备。
2. 若要验证智能跟踪功能，主设备的摄像头驱动需要支持人脸检测功能。
3. 更新SDK到API 20或以上，具体操作参见[更新指南](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-software-install)。
4. 机械体设备与主设备完成蓝牙连接状态。

### 管理设备连接状态

管理设备连接状态，确保设备连接或断开时应用及时响应。

1. 导入机械体设备管理模块。

    ```ts
    import mechanicManager from '@kit.MechanicKit';
    ```

2. 获取已连接的机械体设备列表。

    ```ts
    let savedMechanicIds: number[] = [];

    try {
    const devices = mechanicManager.getAttachedMechDevices();
    console.log('Connected devices:', devices);

    devices.forEach(device => {
        console.log(`Device ID: ${device.mechId}`);
        console.log(`Device Name: ${device.mechName}`);
        console.log(`Device Type: ${device.mechDeviceType}`);

    //保存设备类型为 GIMBAL_DEVICE 的设备的 MechId。
        if (device.mechDeviceType === mechanicManager.MechDeviceType.GIMBAL_DEVICE) {
        savedMechanicIds.push(device.mechId);
        console.log(`GIMBAL_TYPE device saved ID: ${device.mechId}`);
        } else {
        console.log(`Skip non-gimbal devices: ${device.mechId}`);
        }
    });

    console.log('List of saved gimbal device IDs:', savedMechanicIds);
    } catch (err) {
    console.error('Error getting attached devices:', err);
    }
    ```

3. 监听设备的连接状态。

    ```ts
    const attachStateChangeCallback = (info: mechanicManager.AttachStateChangeInfo) => {
    if (info.state === mechanicManager.AttachState.ATTACHED) {
        console.log('Device attached:', info.mechInfo);
        // 处理设备连接逻辑
        handleDeviceAttached(info.mechInfo);
    } else if (info.state === mechanicManager.AttachState.DETACHED) {
        console.log('Device detached:', info.mechInfo);
        // 处理设备断开逻辑
        handleDeviceDetached(info.mechInfo);
    }
    };

    // 注册监听
    mechanicManager.on('attachStateChange', attachStateChangeCallback);
    ```

4. 处理设备连接与断开的事件。

    ```ts
    mechanicManager.on('attachStateChange', attachStateChangeCallback);

    function handleDeviceAttached(mechInfo: mechanicManager.MechInfo) {
    console.log(`New device is connected: ${mechInfo.mechName} (ID: ${mechInfo.mechId})`);
    savedMechanicIds.push(mechInfo.mechId);
    // To do sth.
    }

    function handleDeviceDetached(mechInfo:  mechanicManager.MechInfo) {
    console.log(`Device disconnected: ${mechInfo.mechName} (ID: ${mechInfo.mechId})`);
    savedMechanicIds.filter(id => id !== mechInfo.mechId);
    // To do sth.
    }
    ```

5. 取消监听操作。

    ```ts
    // 取消特定回调的监听
    mechanicManager.off('attachStateChange', attachStateChangeCallback);
    ```

### 控制设备转动

精准控制机械体设备转动，如角度调整和运动轨迹控制等，帮助开发者实现灵活的机械体设备操作功能。

1. 查询设备当前状态及其限制条件。

    ```ts
    try {
    // 初始化设备功能，例如获取设备状态
    const devices = mechanicManager.getAttachedMechDevices();
    console.log('Connected devices:', devices);

    devices.forEach(device => {
        console.log(`Device ID: ${device.mechId}`);
        console.log(`Device Name: ${device.mechName}`);
        console.log(`Device Type: ${device.mechDeviceType}`);
    });

    // 注册设备连接状态监听
    const attachStateChangeCallback = (info: mechanicManager.AttachStateChangeInfo) => {
        if (info.state === mechanicManager.AttachState.ATTACHED) {
        console.log('Device attached:', info.mechInfo);
        } else if (info.state === mechanicManager.AttachState.DETACHED) {
        console.log('Device detached:', info.mechInfo);
        }
    };
    mechanicManager.on('attachStateChange', attachStateChangeCallback);
    // 获取当前角度
    const currentAngles = mechanicManager.getCurrentAngles(savedMechanicIds[0]);
    console.log('current angle:', currentAngles);

    // 获取旋转限制
    const rotationLimits = mechanicManager.getRotationLimits(savedMechanicIds[0]);
    console.log('Rotation limit:', rotationLimits);

    // 获取最大旋转速度
    const maxSpeed = mechanicManager.getMaxRotationSpeed(savedMechanicIds[0]);
    console.log('Maximum rotation speed:', maxSpeed);

    // 获取速度控制最大持续时间
    const maxTime = mechanicManager.getMaxRotationTime(savedMechanicIds[0]);
    console.log('Maximum spin time:', maxTime);
    } catch (err) {
    console.error('Failed to query device status:', err);
    }
    ```

2. 执行相对角度的旋转控制，以调整设备的位置。

    ```ts
    //在执行转动控制之前，需要先关闭跟踪拍摄功能。
    mechanicManager.setCameraTrackingEnabled(false);

    async function rotateByRelativeAngles() {
    try {
        const mechId = savedMechanicIds[0]; // 设备ID

        // 查询当前角度
        const currentAngles = mechanicManager.getCurrentAngles(mechId);
        if (!currentAngles || currentAngles.yaw === undefined || currentAngles.pitch === undefined ||
        currentAngles.roll === undefined) {
        console.error('Failed to retrieve current angles or angles are undefined.');
        return;
        }

        // 获取旋转限制
        const rotationLimits = mechanicManager.getRotationLimits(mechId);
        if (!rotationLimits || rotationLimits.negativeYawMax === undefined || rotationLimits.positiveYawMax === undefined ||
        rotationLimits.negativePitchMax === undefined || rotationLimits.positivePitchMax === undefined ||
        rotationLimits.negativeRollMax === undefined || rotationLimits.positiveRollMax === undefined) {
        console.error('Failed to retrieve rotation limits or limits are undefined.');
        return;
        }
        console.log('Rotation limits:', rotationLimits);

        // 定义目标角度并确保类型正确
        const angles: mechanicManager.RotationAngles = {
        yaw: Math.PI / 4, // 偏航角：45度
        pitch: Math.PI / 6, // 俯仰角：30度
        roll: 0            // 横滚角：0度
        };

        // 检查目标角度是否超出限位
        if (
        currentAngles.yaw + (angles.yaw ?? 0) > rotationLimits.negativeYawMax ||
            currentAngles.yaw + (angles.yaw ?? 0) < rotationLimits.positiveYawMax ||
            currentAngles.pitch + (angles.pitch ?? 0) > rotationLimits.negativePitchMax ||
            currentAngles.pitch + (angles.pitch ?? 0) < rotationLimits.positivePitchMax ||
            currentAngles.roll + (angles.roll ?? 0) > rotationLimits.negativeRollMax ||
            currentAngles.roll + (angles.roll ?? 0) < rotationLimits.positiveRollMax
        ) {
        console.error('Target angles exceed rotation limits.');
        return;
        }

        const duration = 2000; // 旋转持续时间：2秒

        // 执行旋转
        const result = await mechanicManager.rotate(mechId, angles, duration);
        console.info(`Rotation Result: ${result}`);
    } catch (err) {
        console.error('Failed to rotate relative angle:', err);
    }
    }
    ```

3. 以指定速度持续转动，直至任务完成。

    ```ts
    async function rotateBySpeed() {
    try {
        const mechId = savedMechanicIds[0]; // 假设使用第一个设备

        // 获取速度控制最大持续时间
        const maxTime = mechanicManager.getMaxRotationTime(mechId);
        console.log('Maximum spin time:', maxTime);

        // 获取最大旋转速度
        const maxSpeed = mechanicManager.getMaxRotationSpeed(mechId);
        if (!maxSpeed || maxSpeed.yawSpeed === undefined || maxSpeed.pitchSpeed === undefined || maxSpeed.rollSpeed === undefined) {
        console.error('Failed to retrieve maximum rotation speed or speed values are undefined.');
        return;
        }
        console.log('Maximum rotation speed:', maxSpeed);
        // 定义旋转速度和持续时间
        const speed : mechanicManager.RotationSpeed = {
        yawSpeed: maxSpeed.yawSpeed / 2,    // 偏航速度：最大速度的一半
        pitchSpeed: maxSpeed.pitchSpeed / 2, // 俯仰速度：最大速度的一半
        rollSpeed: maxSpeed.rollSpeed / 2    // 横滚速度：最大速度的一半
        };
        const duration = Math.min(maxTime, 5000); // 持续时间：最多5秒

        // 执行旋转
        const result = await mechanicManager.rotateBySpeed(mechId, speed, duration);
        console.info(`Rotation by speed result: ${result}`);
    } catch (err) {
        console.error('Failed to rotate by speed:', err);
    }
    }
    ```

4. 监听旋转轴状态变化。

    ```ts
    const rotationAxesCallback = (info: mechanicManager.RotationAxesStateChangeInfo) => {
    console.log('Rotation Axes state change:', info);
    const mechId = info.mechId;
    const status = info.status;

    console.log(`Device ${mechId} status update:`);
    console.log(`- Yaw  axes enabled: ${status.yawEnabled}`);
    console.log(`- Pitch axes enabled: ${status.pitchEnabled}`);
    console.log(`- Roll axes enabled: ${status.rollEnabled}`);

    if (status.yawLimited !== undefined) {
        console.log(`- Yaw axis restriction state: ${status.yawLimited}`);
    }
    };

    // 注册监听
    mechanicManager.on('rotationAxesStatusChange', rotationAxesCallback);
    ```

5. 停止设备运动。

    ```ts
    async function stopDeviceMoving() {
    try {
        const mechId = savedMechanicIds[0];
        await mechanicManager.stopMoving(mechId);
        console.log('The device has ceased moving.');
    } catch (err) {
        console.error('Failed to stop device movement:', err);
    }
    }
    ```

### 调试验证

为了确保机械体设备管理功能正常，按以下步骤进行调试验证：

**建立连接**

1. 确保机械体设备与开发设备通过蓝牙配对并连接。
2. 将开发设备放置在机械体设备上，确保两者正确连接。

**功能验证步骤**

1. **设备列表查询**：调用 `getAttachedMechDevices` 接口查询当前已连接的机械体设备列表，并验证机械体设备是否正确识别。
2. **设备转动控制**：调用 `setCameraTrackingEnabled` 关闭跟踪功能，并通过 `getCameraTrackingEnabled` 验证状态；调用 `rotate` 或 `rotateBySpeed` 控制机械体设备转动。

**验证结果说明**

- 如果 `getAttachedMechDevices` 返回包含机械体设备信息的列表，表示设备识别正常。
- 如果调用 `rotate` 或 `rotateBySpeed` 后设备按预期开始转动，表示设备转动正常。
