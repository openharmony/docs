# 蓝牙设置开发指导

## 简介
蓝牙设置主要提供了开启蓝牙、关闭蓝牙、获取蓝牙状态的方法，帮助开发者实现基本蓝牙功能。

## 场景介绍
主要场景有：

- 开启、关闭蓝牙

## 接口说明

完整的JS API说明以及示例代码请参考：[access接口](../../reference/apis-connectivity-kit/js-apis-bluetooth-access.md)。

具体接口说明如下表。

| 接口名                             | 功能描述                                                                       |
| ---------------------------------- | ------------------------------------------------------------------------------ |
| enableBluetooth()                  | 开启蓝牙。                                                                       |
| disableBluetooth()                 | 关闭蓝牙。                                                                       |
| getState()                         | 获取蓝牙开关状态。                                                                |
| on(type: 'stateChange')            | 订阅蓝牙设备开关状态事件。                                                         |
| off(type: 'stateChange')           | 取消订阅蓝牙设备开关状态事件。                                                     |


## 主要场景开发步骤

### 开启、关闭蓝牙
1. 导入所需的access模块。
2. 需要SystemCapability.Communication.Bluetooth.Core系统能力。
3. 需要申请权限ohos.permission.ACCESS_BLUETOOTH。
4. 开启蓝牙。
5. 关闭蓝牙。
6. 示例代码：

    ```ts
    import { access } from '@kit.ConnectivityKit';
    import { AsyncCallback, BusinessError } from '@kit.BasicServicesKit';

    // 开启蓝牙
    access.enableBluetooth();
    access.on('stateChange', (data) => {
      let btStateMessage = '';
      switch (data) {
        case 0:
          btStateMessage += 'STATE_OFF';
          break;
        case 1:
          btStateMessage += 'STATE_TURNING_ON';
          break;
        case 2:
          btStateMessage += 'STATE_ON';
          break;
        case 3:
          btStateMessage += 'STATE_TURNING_OFF';
          break;
        case 4:
          btStateMessage += 'STATE_BLE_TURNING_ON';
          break;
        case 5:
          btStateMessage += 'STATE_BLE_ON';
          break;
        case 6:
          btStateMessage += 'STATE_BLE_TURNING_OFF';
          break;
        default:
          btStateMessage += 'unknown status';
          break;
      }
      if (btStateMessage == 'STATE_ON') {
        access.off('stateChange');
      }
      console.info("bluetooth status: " + btStateMessage);
    })

    // 关闭蓝牙
    access.disableBluetooth();
    access.on('stateChange', (data) => {
      let btStateMessage = '';
      switch (data) {
        case 0:
          btStateMessage += 'STATE_OFF';
          break;
        case 1:
          btStateMessage += 'STATE_TURNING_ON';
          break;
        case 2:
          btStateMessage += 'STATE_ON';
          break;
        case 3:
          btStateMessage += 'STATE_TURNING_OFF';
          break;
        case 4:
          btStateMessage += 'STATE_BLE_TURNING_ON';
          break;
        case 5:
          btStateMessage += 'STATE_BLE_ON';
          break;
        case 6:
          btStateMessage += 'STATE_BLE_TURNING_OFF';
          break;
        default:
          btStateMessage += 'unknown status';
          break;
      }
      if (btStateMessage == 'STATE_OFF') {
        access.off('stateChange');
      }
      console.info("bluetooth status: " + btStateMessage);
    })
    ```

6. 错误码请参见[蓝牙服务子系统错误码](../../reference/apis-connectivity-kit/errorcode-bluetoothManager.md)。
7. 如何验证：
执行开启蓝牙代码，记录日志“bluetooth status: STATE_ON”，则表示开启蓝牙成功。执行关闭蓝牙代码，记录日志“bluetooth status: STATE_OFF”，则表示蓝牙关闭成功。