# 设备转动控制开发指南

## 接口介绍

机械设备管理公开API接口使用指导请参见[MechanicManager  API参考](../reference/apis-mechanicManager-kit/js-apis-mechanicManager.md)。
机械设备管理系统API接口使用指导请参见[MechanicManager  API参考](../reference/apis-mechanicManager-kit/js-apis-mechanicManager-sys.md)。

| 接口名                                                               | 描述                       |
| -------------------------------------------------------------------- | -------------------------- |
|on(type: 'attachStateChange', callback: Callback\<AttachStateChangeInfo>): void | 注册attachStateChange事件的回调监听，等待连接状态变化。|
|off(type: 'attachStateChange', callback?: Callback\<AttachStateChangeInfo>): void | 取消注册attachStateChange事件的回调监听。|
|getAttachedMechDevices(): MechInfo[] | 获取已连接的机械体设备列表。|
|setUserOperation(operation: Operation, mac: string, params: string): void | 设置用户操作。|
|setCameraTrackingEnabled(isEnabled: boolean): void | 启用或禁用摄像头跟踪。|
|getCameraTrackingEnabled(): boolean | 检查是否启用了摄像头跟踪。|
|getCameraTrackingLayout(): CameraTrackingLayout | 获取此机械设备摄像头跟踪布局。|
|rotate(mechId: int, angles: RotationAngles, duration: int): Promise\<Result> | 将机械体设备旋转到相对角度。|
|rotateToEulerAngles(mechId: int, angles: EulerAngles, duration: int): Promise\<Result> | 将机械体设备旋转到绝对角度。|
|getMaxRotationTime(mechId: int): int | 获取机械体设备的最大连续旋转持续时间。|
|getMaxRotationSpeed(mechId: int): RotationSpeed | 获取机械设备的最大旋转速度。|
|stopMoving(mechId: int): Promise\<void> | 停止机械体设备的移动。|
|getCurrentAngles(mechId: int): EulerAngles | 获取机械体设备的当前角度。|
|getRotationLimits(mechId: int): RotationLimits | 获取指定机械体设备相对于参考点的最大旋转角度。|
|getRotationAxesStatus(mechId: int): RotationAxesStatus | 获取旋转轴的状态。|
|on(type: 'rotationAxesStatusChange', callback: Callback\<RotationAxesStateChangeInfo>): void | 注册rotationAxesStatusChange事件的回调监听。|
|off(type: 'rotationAxesStatusChange', callback?: Callback\<RotationAxesStateChangeInfo>): void | 取消注册rotationAxesStatusChange事件的回调监听。 |

## 开发步骤

### 开发准备

1. 一台支持MechanicKit协议的机械体配件设备。

2. 一部搭载OpenHarmony系统的设备。

3. 机械体配件设备与OpenHarmony主设备完成蓝牙连接。

### 管理设备连接状态

#### 导入机械设备管理模块文件

```ts
import mechanicManager from '@kit.MechanicKit';
```

#### 获取已连接的机械设备列表

```ts
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

#### 监听设备连接状态变化

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

#### 处理设备连接和断开事件

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

#### 取消监听

```ts
// 取消特定回调的监听
mechanicManager.off('attachStateChange', attachStateChangeCallback);

// 或者取消所有 attachStateChange 监听
mechanicManager.off('attachStateChange');
```

#### 控制设备转动

##### 查询设备当前状态和限制

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

#### 执行相对角度旋转

```ts
//执行转动控制前需要先关闭跟踪拍摄功能
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

    // 获取旋转限位
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

#### 以指定速度持续转动

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
    const duration = Math.min(maxTime, 5000); // 持续时间：不超过最大持续时间，最多5秒

    // 执行旋转
    const result = await mechanicManager.rotateBySpeed(mechId, speed, duration);
    console.info(`Rotation by speed result: ${result}`);
  } catch (err) {
    console.error('Failed to rotate by speed:', err);
  }
}
```

#### 监听旋转轴状态变化

```ts
const rotationAxesCallback = (info: mechanicManager.RotationAxesStateChangeInfo) => {
  console.log('Rotating Axes state change:', info);
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

#### 停止设备运动

```ts
async function stopDeviceMoving() {
  try {
    const mechId = savedMechanicIds[0];
    await mechanicManager.stopMoving(mechId);
    console.log('The device has stopped moving');
  } catch (err) {
    console.error('Failed to stop device movement:', err);
  }
}
```

### 调试验证

为了确保机械设备管理功能正常工作，请按照以下步骤进行调试验证：

**环境准备**

1. 确保机械体配件设备设备与OpenHarmony设备通过蓝牙成功配对并建立连接。
2. 将OpenHarmony设备正确放置在机械体配件设备上。

**功能验证步骤**

1. **设备列表查询**：调用 `getAttachedMechDevices` 接口查询当前已连接的机械体配件设备列表，验证设备是否正确识别。
2. **设备转动控制**：调用 `setCameraTrackingEnabled` 关闭跟踪功能，通过 `getCameraTrackingEnabled` 验证状态，调用 `rotate` 或 `rotateBySpeed` 控制设备转动。

**验证结果说明**

- 如果 `getAttachedMechDevices` 返回包含机械体配件设备信息的设备列表，表示设备识别正常。
- 如果调用 `rotate` 或 `rotateBySpeed` 按预期开始转动，表示转动控制正常。
