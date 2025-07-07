# 智能拍摄跟踪开发指南

为了帮助开发者更好地理解和应用 MechanicKit，本指南将提供智能拍摄跟踪的实现方式。
通过场景化的示例，开发者可以快速上手 MechanicKit，构建出功能丰富的设备交互应用。

## 接口介绍

机械设备管理API的接口使用指导请参见[MechanicManager  API参考](../reference/apis-mechanicManager-kit/js-apis-mechanicManager.md)。

| 接口名                                                               | 描述                       |
| -------------------------------------------------------------------- | -------------------------- |
|on(type: 'attachStateChange', callback: Callback\<AttachStateChangeInfo>): void | 注册attachStateChange事件的回调监听，等待连接状态变化。|
|off(type: 'attachStateChange', callback?: Callback\<AttachStateChangeInfo>): void | 取消注册attachStateChange事件的回调监听。|
|getAttachedMechDevices(): MechInfo[] | 获取已连接的机械体设备列表。|
|setCameraTrackingEnabled(isEnabled: boolean): void | 启用或禁用摄像头跟踪。|
|getCameraTrackingEnabled(): boolean | 检查是否启用了摄像头跟踪。|
|on(type: 'trackingStateChange', callback: Callback\<TrackingEventInfo>): void | 注册trackingStateChange事件的回调监听。|
|off(type: 'trackingStateChange', callback?: Callback\<TrackingEventInfo>): void | 取消注册trackingStateChange事件的回调监听。|
|setCameraTrackingLayout(trackingLayout: CameraTrackingLayout): void | 设置摄像头跟踪布局。|
|getCameraTrackingLayout(): CameraTrackingLayout | 获取此机械设备摄像头跟踪布局。|
|on(type: 'rotationAxesStatusChange', callback: Callback\<RotationAxesStateChangeInfo>): void | 注册rotationAxesStatusChange事件的回调监听。|
|off(type: 'rotationAxesStatusChange', callback?: Callback\<RotationAxesStateChangeInfo>): void | 取消注册rotationAxesStatusChange事件的回调监听。 |

## 开发步骤

### 开发准备

1. 一台支持MechanicKit协议的机械体配件设备。

2. 一部搭载OpenHarmony系统且相机驱动支持目标检测的设备。

3. 机械体配件设备与OpenHarmony主设备完成蓝牙连接。

### 管理设备连接状态

1. 导入机械设备管理模块文件

```ts
import mechanicManager from '@kit.MechanicKit';
```

2. 获取已连接的机械设备列表

```ts
import mechanicManager from '@ohos.distributedHardware.mechanicManager';

let savedMechanicIds: int[] = [];

try {
  const devices = mechanicManager.getAttachedMechDevices();
  console.log('Connected devices:', devices);

  devices.forEach(device => {
    console.log(`Device ID: ${device.mechId}`);
    console.log(`Device Name: ${device.mechName}`);
    console.log(`Device Type: ${device.mechDeviceType}`);

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

3. 监听设备连接状态变化

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

4. 处理设备连接和断开事件

```ts
function handleDeviceAttached(mechInfo: mechanicManager.MechInfo) {
  console.log(`New device is connected: ${mechInfo.mechName} (ID: ${mechInfo.mechId})`);
  savedMechanicIds.push(mechInfo.mechId);
  // To do sth.
}

function handleDeviceDetached(mechInfo: mechanicManager.MechInfo) {
  console.log(`Device disconnected: ${mechInfo.mechName} (ID: ${mechInfo.mechId})`);
  savedMechanicIds.filter(id => id !== mechInfo.mechId);
  // To do sth.
}
```

5. 取消监听

```ts
// 取消特定回调的监听
mechanicManager.off('attachStateChange', attachStateChangeCallback);

// 或者取消所有 attachStateChange 监听
mechanicManager.off('attachStateChange');
```

### 控制设备智能跟踪拍摄

1. 启用摄像头智能跟踪功能

```ts
try {
  //检查前判断savedMechIds不为空
  // 检查跟踪状态
  const isEnabled = mechanicManager.getCameraTrackingEnabled();

  if (isEnabled == false) {
    // 开启摄像头跟踪
    mechanicManager.setCameraTrackingEnabled(true);
    console.log('Camera tracking enabled');
  }

  console.log('Is tracking currently enabled:', isEnabled);
} catch (err) {
  console.error('Failed to enable camera tracking:', err);
}
```

2. 监听跟踪变化

```ts
const trackingStateCallback = (eventInfo : mechanicManager.TrackingEventInfo) => {
  switch (eventInfo.event) {
    case mechanicManager.TrackingEvent.CAMERA_TRACKING_USER_ENABLED:
      console.log('The user has enabled camera tracking');
      handleTrackingEnabled();
      break;
    case mechanicManager.TrackingEvent.CAMERA_TRACKING_USER_DISABLED:
      console.log('The user has disabled camera tracking');
      handleTrackingDisabled();
      break;
    case mechanicManager.TrackingEvent.CAMERA_TRACKING_LAYOUT_CHANGED:
      console.log('Tracking layout has changed');
      handleLayoutChanged();
      break;
  }
};

// 注册跟踪状态监听
mechanicManager.on('trackingStateChange', trackingStateCallback);
```

3. 处理跟踪事件

```ts
function handleTrackingEnabled() {
  console.log('Handling trace enable events');
  // 可以在此处更新UI状态
  updateTrackingUI(true);
}

function handleTrackingDisabled() {
  console.log('Handling trace disabled events');
  // 可以在此处更新UI状态
  updateTrackingUI(false);
}

function handleLayoutChanged() {
  try {
    const newLayout = mechanicManager.getCameraTrackingLayout();
    console.log('New Tracking Layout:', newLayout);
    // 根据新布局更新UI
    updateLayoutUI(newLayout);
  } catch (err) {
    console.error('Failed to get new layout:', err);
  }
}

function updateTrackingUI(enabled: boolean) {
  // 更新UI显示跟踪状态
  // To do sth.
  console.log('Update tracking UI status:', enabled);
}

function updateLayoutUI(layout : mechanicManager.CameraTrackingLayout) {
  // 更新UI显示布局状态
  // To do sth.
  console.log('Update layout UI:', layout);
}
```

4. 取消监听

```ts
// 取消跟踪状态监听
mechanicManager.off('trackingStateChange', trackingStateCallback);

// 或者取消所有跟踪状态监听
mechanicManager.off('trackingStateChange');
```

### 调试验证

为了确保机械设备管理功能正常工作，请按照以下步骤进行调试验证：

**环境准备**

1. 确保机械体配件设备设备与OpenHarmony设备通过蓝牙成功配对并建立连接。
2. 将OpenHarmony设备正确放置在机械体配件设备上。

**功能验证步骤**

1. **设备列表查询**：调用 `getAttachedMechDevices` 接口查询当前已连接的机械体配件设备列表，验证设备是否正确识别。
2. **智能拍摄跟踪**：调用 `setCameraTrackingEnabled` 启用跟踪功能，通过 `getCameraTrackingEnabled` 验证状态，测试机械体配件设备是否能跟随目标自动旋转。

**验证结果说明**

- 如果 `getAttachedMechDevices` 返回包含机械体配件设备信息的设备列表，表示设备识别正常。
- 如果 `getCameraTrackingEnabled` 返回结果为真，表示智能拍摄跟踪启用成功。