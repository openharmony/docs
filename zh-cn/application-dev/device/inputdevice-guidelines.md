# 输入设备开发指导

## 场景介绍

输入设备管理提供设备热插拔监听、查询指定设备的键盘类型等能力。使用场景例如：当用户需要输入文本时，输入法会根据当前是否插入了物理键盘来决定是否弹出虚拟键盘，开发者可以通过监听设备热插拔判断是否有物理键盘插入。

## 导入模块

```js
import inputDevice from '@ohos.multimodalInput.inputDevice';
```

## 接口说明

输入设备管理常用接口如下表所示，接口详细介绍请参考[ohos.multimodalInput.inputDevice文档](../reference/apis/js-apis-inputdevice.md)。

| 实例名 | 接口名  | 说明 |
| ----------- | ------------------------------------------------------------ | -------------------------- |
| inputDevice | function getDeviceList(callback: AsyncCallback\<Array\<number>>): void; | 获取输入设备列表。 |
| inputDevice | function getKeyboardType(deviceId: number, callback: AsyncCallback\<KeyboardType>): void; | 获取输入设备的键盘类型。 |
| inputDevice | function on(type: "change", listener: Callback\<DeviceListener>): void; | 监听输入设备的热插拔事件。 |
| inputDevice | function off(type: "change", listener?: Callback\<DeviceListener>): void; | 取消监听输入设备的热插拔事件。 |

## 虚拟键盘弹出检测

当用户需要输入文本时，输入法会根据当前是否插入了物理键盘来决定是否弹出虚拟键盘，开发者可以通过监听设备热插拔，判断是否有物理键盘插入。

## 开发步骤

1. 调用getDeviceList方法查询所有连接的输入设备，调用getKeyboardType方法遍历所有连接的设备，判断是否有物理键盘，若有则标记已有物理键盘连接，该步骤确保监听设备热插拔之前，检测所有插入的输入设备。
2. 调用on接口监听输入设备热插拔事件，若监听到有物理键盘插入，则标记已有物理键盘连接；若监听到有物理键盘拔掉，则标记没有物理键盘连接。
3. 文本框进行输入时，判断是否有物理键盘连接，如果有物理键盘则不弹出虚拟键盘，如果没有物理键盘则弹出虚拟键盘。


```js
import inputDevice from '@ohos.multimodalInput.inputDevice';

let isPhysicalKeyboardExist = true;
try {
  // 1.获取设备列表，判断是否有物理键盘连接
  inputDevice.getDeviceList().then(data => {
    for (let i = 0; i < data.length; ++i) {
      inputDevice.getKeyboardType(data[i]).then(res => {
        if (type == inputDevice.KeyboardType.ALPHABETIC_KEYBOARD) {
          // 物理键盘已连接
          isPhysicalKeyboardExist = true;
        }
      });
    }
  });
  // 2.监听设备热插拔
  inputDevice.on("change", (data) => {
    console.log(`Device event info: ${JSON.stringify(data)}`);
    inputDevice.getKeyboardType(data.deviceId, (error, type) => {
      console.log("The keyboard type is: " + type);
      if (type == inputDevice.KeyboardType.ALPHABETIC_KEYBOARD && data.type == 'add') {
        // 物理键盘已插入
        isPhysicalKeyboardExist = true;
      } else if (type == inputDevice.KeyboardType.ALPHABETIC_KEYBOARD && data.type == 'remove') {
        // 物理键盘已拔掉
        isPhysicalKeyboardExist = false;
      }
    });
  });
} catch (error) {
  console.log(`Execute failed, error: ${JSON.stringify(error, [`code`, `message`])}`);
}
  // 3.根据isPhysicalKeyboardExist的值决定虚拟键盘是否弹出
  // TODO
```
