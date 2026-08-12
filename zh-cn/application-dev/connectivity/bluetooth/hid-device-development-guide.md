# HID设备调用指南

<!--Kit: Connectivity Kit-->
<!--Subsystem: Communication-->
<!--Owner: @enjoy_sunshine-->
<!--Designer: @tangjia15-->
<!--Tester: @wangfeng517-->
<!--Adviser: @zhang_yixin13-->

## 简介
本指南主要提供了基于人机接口设备协议（Human Interface Device Profile，[HID](terminology.md#hid)）实现将设备模拟为蓝牙键盘、鼠标、游戏手柄等输入设备的开发指导。在HID设备通信模型中，依据设备角色的不同，可区分为[HID host](terminology.md#hid-host)和[HID device](terminology.md#hid-device)。本指南将重点阐述如何为应用提供HID设备能力，连接其他蓝牙HID主机（如电脑、平板、手机等）并进行数据交互的实现方法。

## 实现原理
HID设备作为输入能力的提供方，需要先为本机应用注册HID设备能力，并声明其功能类型（如键盘、鼠标等）及对应的HID报告描述符。

HID设备在获取到HID主机的设备地址后，即可主动向已配对的HID主机发起连接。HID主机地址可以通过查找设备流程获取，详见[查找设备](br-discovery-development-guide.md)。连接成功后，HID设备即可通过建立的通道向主机主动发送HID报告（如键盘按键、鼠标移动等数据）。主机接收到报告后，会将其解析为标准输入事件。

HID设备或HID主机均可主动断开连接。应用需要根据实际场景决定由哪一端执行断开操作。

## 开发步骤

### 申请蓝牙权限
需要申请权限ohos.permission.ACCESS_BLUETOOTH。如何配置和申请权限，请参考[声明权限](../../security/AccessToken/declare-permissions.md)和[向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

### 导入所需API模块
导入baseProfile、hid和common模块。
```ts
import { baseProfile, hid, common } from '@kit.ConnectivityKit';
```

### 设备端

**1. 注册HID设备**<br>
应用首先完成HID设备能力注册。系统接收注册请求后，会将应用与蓝牙底层的HID设备角色绑定，并在服务发现协议中发布对应的HID服务记录。注册结果通过回调函数返回，成功注册后应用即进入可连接状态，等待后续操作。
```ts
let descriptors: Uint8Array = new Uint8Array([
    // 描述符示例，需要遵循USB HID规范
    0x05, 0x01,        // 指定设备类别为通用桌面控制
    0x09, 0x06,        // 具体设备为键盘
    0xA1, 0x01,        // 应用集合开始
    
    // 按键字段定义
    0x05, 0x07,        // 切换到键盘/键区
    0x19, 0x00,        // 定义最小按键码为0（无按键）
    0x29, 0x01,        // 定义最大按键码为1（只支持2个值）
    0x15, 0x00,        // 逻辑最小值0（数据范围下限）
    0x25, 0x01,        // 逻辑最大值1（数据范围上限）
    0x75, 0x08,        // 每个字段八位
    0x95, 0x01,        // 只有一个字段
    0x81, 0x00,        // 定义输入字段：数据字段，值为按键数组
    
    // 结束设备定义
    0xC0               // 应用集合结束
]);
// 以键盘为例
let sdp: hid.HidDeviceSdp = {
    "name": "testName",
    "description": "testDescription",
    "provider": "testProvider",
    "subclass": hid.Subclass.SUBCLASS_KEYBOARD,
    "descriptors": descriptors,
};
let inqos: hid.HidDeviceQos = {
    "serviceType": hid.ServiceType.SERVICE_BEST_EFFORT,
    "tokenRate": 0,
    "tokenBucketSize": 0,
    "peakBandwidth": 0,
    "latency": -1,
    "delayVariation": -1,
};

let outqos: hid.HidDeviceQos = {};
function registerStateCallback(callback: boolean) {
    console.info(`state: ${callback}`);
}

try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.registerHidDevice(sdp, inqos, outqos, registerStateCallback)
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

**2. 向HID主机发起连接**<br>

应用通过查找设备流程搜索到目标设备后，即可发起连接。系统接收到连接请求后，会检查目标设备是否支持HID主机角色并已建立必要的安全配对。验证通过后，系统自动建立HID控制通道和中断数据传输通道。连接建立成功后，应用会收到连接状态回调通知，此时HID设备与主机之间已建立完整的协议链路，具备报告传输能力。

```ts
function onConnectionStateChangedevent(callback: baseProfile.StateChangeParam) {
    let StateChangeParam = callback;
    console.info(`deviceId: ${StateChangeParam.deviceId}, state: ${StateChangeParam.state}`);
}

let device: common.BluetoothAddress = {
    "address": "11:22:33:44:55:66",
    "addressType": common.BluetoothAddressType.REAL,
}
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.onConnectionStateChange(onConnectionStateChangedevent); // 订阅连接状态回调事件
    hidDevice.connect(device);
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

**3. 传输数据**<br>

**3.1 发送数据**<br>
连接建立后，应用可与HID主机进行数据交互。[sendReport](../../reference/apis-connectivity-kit/js-apis-bluetooth-hid.md#sendreport23)用于主动向主机发送输入报告（如按键事件、坐标数据），[replyReport](../../reference/apis-connectivity-kit/js-apis-bluetooth-hid.md#replyreport23)用于响应主机发送的获取报告请求，返回当前设备状态或特性数据；[reportError](../../reference/apis-connectivity-kit/js-apis-bluetooth-hid.md#reporterror23)用于在报告传输失败或格式错误时向主机通知异常情况。

```ts
let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();

let reportData: Uint8Array = new Uint8Array([0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77]);
let id: number = 0;
try {
    hidDevice.sendReport(id, reportData);  // 发送输入报告
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}

let type = hid.ReportType.REPORT_TYPE_INPUT;
let replyData: Uint8Array = new Uint8Array([0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77]);
try {
    hidDevice.replyReport(type, id, replyData);  // 响应获取报告请求
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}

let error = hid.ErrorReason.RSP_SUCCESS;
try {
    hidDevice.reportError(error);  // 报告异常情况
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

**3.2 接收数据**<br>
HID设备可以通过订阅相关的事件实时响应HID主机的各类请求以及接收发送的数据。
- GET_REPORT事件：表示HID主机发起的数据读取请求，用于获取HID设备的状态信息。
- SET_REPORT事件：表示HID主机发起的数据写入请求，用于向HID设备发送控制指令。
- SET_PROTOCOL事件：表示HID主机发起的协议模式切换请求。
- 中断数据接收事件：处理HID主机通过中断通道发送的实时数据。
- 虚拟链路状态事件：处理虚拟链路状态变化通知。
```ts
function onGetReportReceiveEvent(callback: hid.GetReportData) {
    console.info(`type: ${callback.type}, id: ${callback.id}, bufferSize: ${callback.bufferSize}`);
}

function onSetReportReceiveEvent(callback: hid.SetReportData) {
    console.info(`type: ${callback.type}, id: ${callback.id}, dataSize: ${callback.data.length}`);
}

function onInterruptDataReceiveEvent(callback: hid.InterruptData) {
    console.info(`id: ${callback.id}, dataSize: ${callback.data.length}`);
}

function onSetProtocolReceiveEvent(callback: hid.ProtocolData) {
    console.info(`protocol: ${callback.protocol}`);
}

function onVirtualCableUnplugReceiveEvent() {
    console.info(`onVirtualCableUnplug`);
}

try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.onGetReport(onGetReportReceiveEvent);    // 订阅GET_REPORT事件
    hidDevice.onSetReport(onSetReportReceiveEvent); // 订阅SET_REPORT事件
    hidDevice.onInterruptDataReceived(onInterruptDataReceiveEvent); // 订阅中断数据接收事件
    hidDevice.onSetProtocol(onSetProtocolReceiveEvent); // 订阅SET_PROTOCOL事件
    hidDevice.onVirtualCableUnplug(onVirtualCableUnplugReceiveEvent);   // 订阅虚拟链路状态
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

**4. 断开连接**<br>
应用可主动断开与当前HID主机的连接。连接断开后，系统会释放相关协议通道资源，应用将收到连接状态变更回调。此时应用可选择重新连接其他主机或保持就绪状态等待新连接。
```ts
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.disconnect();
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```

**5. 解除注册HID设备**<br>
当应用不再需要提供HID设备能力时，可主动解除注册。该操作会从系统蓝牙服务中移除HID设备角色绑定，清空服务发现记录，并释放所有相关资源。解除注册后，应用将无法再被识别为HID设备，所有现有连接会被强制断开，且无法建立新连接。

```ts
try {
    let hidDevice: hid.HidDeviceProfile = hid.createHidDeviceProfile();
    hidDevice.unregisterHidDevice();
} catch (err) {
    console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
}
```
## 完整示例

### 设备端
```ts
import { baseProfile, hid, common } from '@kit.ConnectivityKit';

class HidDeviceManager {
    device: common.BluetoothAddress = {
        "address": "11:22:33:44:55:66",
        "addressType": common.BluetoothAddressType.REAL,
    }
    descriptors: Uint8Array = new Uint8Array([
        // 描述符示例，需要遵循USB HID规范
        0x05, 0x01,        // 指定设备类别为通用桌面控制
        0x09, 0x06,        // 具体设备为键盘
        0xA1, 0x01,        // 应用集合开始

        // 按键字段定义
        0x05, 0x07,        // 切换到键盘/键区
        0x19, 0x00,        // 定义最小按键码为0（无按键）
        0x29, 0x01,        // 定义最大按键码为1（只支持2个值）
        0x15, 0x00,        // 逻辑最小值0（数据范围下限）
        0x25, 0x01,        // 逻辑最大值1（数据范围上限）
        0x75, 0x08,        // 每个字段八位
        0x95, 0x01,        // 只有一个字段
        0x81, 0x00,        // 定义输入字段：数据字段，值为按键数组

        // 结束设备定义
        0xC0               // 应用集合结束
    ]);
    // 以键盘为例
    sdp: hid.HidDeviceSdp = {
        "name": "testName",
        "description": "testDescription",
        "provider": "testProvider",
        "subclass": hid.Subclass.SUBCLASS_KEYBOARD,
        "descriptors": this.descriptors,
    };
    inqos: hid.HidDeviceQos = {
        "serviceType": hid.ServiceType.SERVICE_BEST_EFFORT,
        "tokenRate": 0,
        "tokenBucketSize": 0,
        "peakBandwidth": 0,
        "latency": -1,
        "delayVariation": -1,
    };
    outqos: hid.HidDeviceQos = {};
    hidDevice: hid.HidDeviceProfile | undefined = undefined;

// 注册HID Device
  public registerHidDevice() {
    this.hidDevice = hid.createHidDeviceProfile();  // 构造HID Device，后续的交互都需要使用该实例
    try {
        this.hidDevice.registerHidDevice(this.sdp, this.inqos, this.outqos, this.registerStateCallback);
        this.hidDevice.onGetReport(this.onGetReportReceiveEvent);    // 订阅GET_REPORT事件
        this.hidDevice.onSetReport(this.onSetReportReceiveEvent); // 订阅SET_REPORT事件
        this.hidDevice.onInterruptDataReceived(this.onInterruptDataReceiveEvent); // 订阅中断数据接收事件
        this.hidDevice.onSetProtocol(this.onSetProtocolReceiveEvent); // 订阅SET_PROTOCOL事件
        this.hidDevice.onVirtualCableUnplug(this.onVirtualCableUnplugReceiveEvent);   // 订阅虚拟链路状态
        this.hidDevice.onConnectionStateChange(this.onConnectionStateChangedevent); // 订阅连接状态
    } catch (err) {
        console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    }
  }

  // 取消注册HID Device
  public unregisterHidDevice() {
    if (!this.hidDevice) {
        console.error('hid device not exist');
        return;
    }
    try {
        this.hidDevice.unregisterHidDevice();
        this.hidDevice.offGetReport(this.onGetReportReceiveEvent);    // 取消订阅GET_REPORT事件
        this.hidDevice.offSetReport(this.onSetReportReceiveEvent); // 取消订阅SET_REPORT事件
        this.hidDevice.offInterruptDataReceived(this.onInterruptDataReceiveEvent); // 取消订阅中断数据接收事件
        this.hidDevice.offSetProtocol(this.onSetProtocolReceiveEvent); // 取消订阅SET_PROTOCOL事件
        this.hidDevice.offVirtualCableUnplug(this.onVirtualCableUnplugReceiveEvent);   // 取消订阅虚拟链路状态
        this.hidDevice.offConnectionStateChange(this.onConnectionStateChangedevent); // 取消订阅连接状态
    } catch (err) {
        console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    }
  }

    registerStateCallback = (callback: boolean) => {
        console.info(`state: ${callback}`);
    };

    onGetReportReceiveEvent = (callback: hid.GetReportData) => {
        console.info(`type: ${callback.type}, id: ${callback.id}, bufferSize: ${callback.bufferSize}`);
    };


    onSetReportReceiveEvent = (callback: hid.SetReportData) => {
        console.info(`type: ${callback.type}, id: ${callback.id}, dataSize: ${callback.data.length}`);
    };

    onInterruptDataReceiveEvent = (callback: hid.InterruptData) =>  {
        console.info(`id: ${callback.id}, dataSize: ${callback.data.length}`);
    };

    onSetProtocolReceiveEvent = (callback: hid.ProtocolData) => {
        console.info(`protocol: ${callback.protocol}`);
    };

    onVirtualCableUnplugReceiveEvent = () => {
        console.info(`onVirtualCableUnplug`);
    };

    onConnectionStateChangedevent = (callback : baseProfile.StateChangeParam) => {
        let StateChangeParam = callback;
        console.info(`deviceId: ${StateChangeParam.deviceId}, state: ${StateChangeParam.state}`);
    };

  // 连接HID主机
  public hidConnect(device: common.BluetoothAddress) {
    if (!this.hidDevice) {
        console.error('hid device not exist');
        return;
    }
    try {
        this.hidDevice.connect(device);
    } catch (err) {
        console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    }
  }

  // 断开HID连接
  public hidDisconnect() {
    if (!this.hidDevice) {
        console.error('hid device not exist');
        return;
    }
    try {
        this.hidDevice.disconnect();
    } catch (err) {
        console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    }
  }

  // 发送报告
  public hidSendReport() {
    if (!this.hidDevice) {
        console.error('hid device not exist');
        return;
    }
    let reportData: Uint8Array = new Uint8Array([0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77]);
    let id: number = 0;
    try {
        this.hidDevice.sendReport(id, reportData);
    } catch (err) {
        console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    }
  }

  // 回复报告
  public hidReplyReport() {
    if (!this.hidDevice) {
        console.error('hid device not exist');
        return;
    }
    let type = hid.ReportType.REPORT_TYPE_INPUT;
    let id: number = 0;
    let reportData: Uint8Array = new Uint8Array([0x00, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77]);
    try {
        this.hidDevice.replyReport(type, id, reportData);
    } catch (err) {
        console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    }
  }

  // 报告错误
  public hidReportError() {
    if (!this.hidDevice) {
        console.error('hid device not exist');
        return;
    }
    let error = hid.ErrorReason.RSP_SUCCESS;
    try {
        this.hidDevice.reportError(error);
    } catch (err) {
        console.error(`errCode: ${err.code}, errMessage: ${err.message}`);
    }
  }
}

let hidDeviceServerManager = new HidDeviceManager();
export default hidDeviceServerManager as HidDeviceManager;
```