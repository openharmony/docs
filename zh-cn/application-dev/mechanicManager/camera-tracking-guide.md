# 智能拍摄跟踪开发指南

从API version 20开始，支持使用机械设备管理。在视频录制和直播等应用场景中，开发者希望为拥有机械体配件设备的用户提供更丰富的拍摄体验，如人脸智能跟踪和自动构图等专业拍摄功能。

智能拍摄跟踪，可以通过机械体配件设备实现人脸跟踪和物体追踪等自动化拍摄功能，提升拍摄质量和用户体验，帮助开发者构建出更智能、更高效的拍摄解决方案。

## 接口介绍

机械设备管理API的接口使用指导请参见[MechanicManager  API参考](../reference/apis-mechanic-kit/js-apis-mechanicManager.md)。

| 接口名                                                               | 描述                       |
| -------------------------------------------------------------------- | -------------------------- |
|on(type: 'attachStateChange', callback: Callback\<AttachStateChangeInfo>): void | 注册attachStateChange事件的回调监听，等待连接状态变化。<br>**说明**：从API version 20开始支持。|
|off(type: 'attachStateChange', callback?: Callback\<AttachStateChangeInfo>): void | 取消注册attachStateChange事件的回调监听。<br>**说明**：从API version 20开始支持。|
|getAttachedMechDevices(): MechInfo[] | 获取已连接的机械体设备列表。<br>**说明**：从API version 20开始支持。|
|setCameraTrackingEnabled(isEnabled: boolean): void | 启用或禁用摄像头跟踪。<br>**说明**：从API version 20开始支持。|
|getCameraTrackingEnabled(): boolean | 检查是否启用了摄像头跟踪。<br>**说明**：从API version 20开始支持。|
|on(type: 'trackingStateChange', callback: Callback\<TrackingEventInfo>): void | 注册trackingStateChange事件的回调监听。<br>**说明**：从API version 20开始支持。|
|off(type: 'trackingStateChange', callback?: Callback\<TrackingEventInfo>): void | 取消注册trackingStateChange事件的回调监听。<br>**说明**：从API version 20开始支持。|
|setCameraTrackingLayout(trackingLayout: CameraTrackingLayout): void | 设置摄像头跟踪布局。<br>**说明**：从API version 20开始支持。|
|getCameraTrackingLayout(): CameraTrackingLayout | 获取此机械设备摄像头跟踪布局。<br>**说明**：从API version 20开始支持。|
|on(type: 'rotationAxesStatusChange', callback: Callback\<RotationAxesStateChangeInfo>): void | 注册rotationAxesStatusChange事件的回调监听。<br>**说明**：从API version 20开始支持。|
|off(type: 'rotationAxesStatusChange', callback?: Callback\<RotationAxesStateChangeInfo>): void | 取消注册rotationAxesStatusChange事件的回调监听。<br>**说明**：从API version 20开始支持。|

## 开发步骤

### 开发准备

1. 一台支持MechanicKit协议的机械体配件设备。

2. 机械体配件设备与开发设备完成蓝牙连接。

### 管理设备连接状态

动态管理设备连接状态，确保设备连接或断开时应用能及时响应。

1. 导入机械设备管理模块文件。

    ```ts
    import mechanicManager from '@kit.MechanicKit';
    ```

2. 获取已连接的机械设备列表。

    ```ts
    let savedMechanicIds: number[] = [];

    try {
    const devices = mechanicManager.getAttachedMechDevices();
    console.info('Connected devices:', devices);

    devices.forEach(device => {
        console.info(`Device ID: ${device.mechId}`);
        console.info(`Device Name: ${device.mechName}`);
        console.info(`Device Type: ${device.mechDeviceType}`);
        
    //保存设备类型为GIMBAL_DEVICE的设备的MechId
        if (device.mechDeviceType === mechanicManager.MechDeviceType.GIMBAL_DEVICE) {
        savedMechanicIds.push(device.mechId);
        console.info(`GIMBAL_TYPE device saved ID: ${device.mechId}`);
        } else {
        console.info(`Skip non-gimbal devices: ${device.mechId}`);
        }
    });

    console.info('List of saved gimbal device IDs:', savedMechanicIds);
    } catch (err) {
    console.error('Error getting attached devices:', err);
    }
    ```

3. 监听设备连接状态变化。

    ```ts
    const attachStateChangeCallback = (info: mechanicManager.AttachStateChangeInfo) => {
    if (info.state === mechanicManager.AttachState.ATTACHED) {
        console.info('Device attached:', info.mechInfo);
        // 处理设备连接逻辑
        handleDeviceAttached(info.mechInfo);
    } else if (info.state === mechanicManager.AttachState.DETACHED) {
        console.info('Device detached:', info.mechInfo);
        // 处理设备断开逻辑
        handleDeviceDetached(info.mechInfo);
    }
    };

    // 注册监听
    mechanicManager.on('attachStateChange', attachStateChangeCallback);
    ```

4. 处理设备连接和断开事件。

    ```ts
    function handleDeviceAttached(mechInfo: mechanicManager.MechInfo) {
    console.info(`New device is connected: ${mechInfo.mechName} (ID: ${mechInfo.mechId})`);
    savedMechanicIds.push(mechInfo.mechId);
    // To do sth.
    }

    function handleDeviceDetached(mechInfo: mechanicManager.MechInfo) {
    console.info(`Device disconnected: ${mechInfo.mechName} (ID: ${mechInfo.mechId})`);
    savedMechanicIds.filter(id => id !== mechInfo.mechId);
    // To do sth.
    }
    ```

5. 取消监听。

    ```ts
    // 取消特定回调的监听
    mechanicManager.off('attachStateChange', attachStateChangeCallback);
    ```

### 控制设备智能跟踪拍摄

开启智能拍摄功能，机械体设备将自动识别人脸进行跟踪拍摄。

1. 启用摄像头智能跟踪功能。

    ```ts
    try {
    //检查前判断savedMechIds不为空
    // 检查跟踪状态
    const isEnabled = mechanicManager.getCameraTrackingEnabled();

    if (isEnabled == false) {
        // 开启摄像头跟踪
        mechanicManager.setCameraTrackingEnabled(true);
        console.info('Camera tracking enabled');
    }

    console.info('Is tracking currently enabled:', isEnabled);
    } catch (err) {
    console.error('Failed to enable camera tracking:', err);
    }
    ```

2. 监听跟踪变化。

    ```ts
    const trackingStateCallback = (eventInfo : mechanicManager.TrackingEventInfo) => {
    switch (eventInfo.event) {
        case mechanicManager.TrackingEvent.CAMERA_TRACKING_USER_ENABLED:
        console.info('The user has enabled camera tracking');
        handleTrackingEnabled();
        break;
        case mechanicManager.TrackingEvent.CAMERA_TRACKING_USER_DISABLED:
        console.info('The user has disabled camera tracking');
        handleTrackingDisabled();
        break;
        case mechanicManager.TrackingEvent.CAMERA_TRACKING_LAYOUT_CHANGED:
        console.info('Tracking layout has changed');
        handleLayoutChanged();
        break;
    }
    };

    // 注册跟踪状态监听
    mechanicManager.on('trackingStateChange', trackingStateCallback);
    ```

3. 处理跟踪事件。

    ```ts
    function handleTrackingEnabled() {
    console.info('Handling trace enable events');
    // 可以在此处更新UI状态
    updateTrackingUI(true);
    }

    function handleTrackingDisabled() {
    console.info('Handling trace disabled events');
    // 可以在此处更新UI状态
    updateTrackingUI(false);
    }

    function handleLayoutChanged() {
    try {
        const newLayout = mechanicManager.getCameraTrackingLayout();
        console.info('New Tracking Layout:', newLayout);
        // 根据新布局更新UI
        updateLayoutUI(newLayout);
    } catch (err) {
        console.error('Failed to get new layout:', err);
    }
    }

    function updateTrackingUI(enabled: boolean) {
    // 更新UI显示跟踪状态
    // To do sth.
    console.info('Update tracking UI status:', enabled);
    }

    function updateLayoutUI(layout : mechanicManager.CameraTrackingLayout) {
    // 更新UI显示布局状态
    // To do sth.
    console.info('Update layout UI:', layout);
    }
    ```

4. 取消监听。

    ```ts
    // 取消跟踪状态监听
    mechanicManager.off('trackingStateChange', trackingStateCallback);

    // 或者取消所有跟踪状态监听
    mechanicManager.off('trackingStateChange');
    ```

### 调试验证

为了确保机械设备管理功能正常工作，请按照以下步骤进行调试验证：

**建立连接**

1. 确保机械体配件设备与开发设备通过蓝牙成功配对并建立连接。
2. 将开发设备正确放置在机械体配件设备上。

**功能验证步骤**

1. **设备列表查询**：调用 `getAttachedMechDevices` 接口查询当前已连接的机械体配件设备列表，验证设备是否正确识别。
2. **智能拍摄跟踪**：调用 `setCameraTrackingEnabled` 启用摄像头智能跟踪功能，通过 `getCameraTrackingEnabled` 验证状态，测试机械体配件设备是否能跟随目标自动旋转。

**验证结果说明**

- 如果 `getAttachedMechDevices` 返回包含机械体配件设备信息的设备列表，表示设备识别正常。
- 如果 `getCameraTrackingEnabled` 返回结果为真，表示智能拍摄跟踪启用成功。