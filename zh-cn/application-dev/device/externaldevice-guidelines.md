# 扩展外设管理开发指导


## 场景介绍

扩展外设主要是指通过物理接口连入主设备的配件设备，如手写板、打印机和扫描仪等。应用通过扩展外设管理能力可以查询绑定扩展外设，从而使用扩展外设驱动提供的定制能力来使用扩展外设，如打印机的配套软件。


## 接口说明

扩展外设管理主要提供的功能有：查询扩展外设列表、绑定和解绑查询到的设备。

扩展外设管理开放能力如下，具体请查阅[API参考文档](../reference/apis/js-apis-driver-deviceManager.md)。

**表1** 扩展外设管理开放能力接口

| 接口名                                                                                                                                                      | 描述                                                                                    |
| ----------------------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------- |
| queryDevices(busType?: number): Array&lt;Readonly&lt;Device&gt;&gt;                                                                                         | 查询扩展外设列表                                                                        |
| bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;, callback: AsyncCallback&lt;{deviceId: number, remote: rpc.IRemoteObject}&gt;): void | 绑定设备，绑定成功后返回设备驱动的IRemoteObject通信对象，通过该对象与设备驱动进行交互。 |
| bindDevice(deviceId: number, onDisconnect: AsyncCallback&lt;number&gt;): Promise&lt;{deviceId: number, remote: rpc.IRemoteObject}&gt;                       | 绑定设备的Promise形式。                                                                 |
| unbindDevice(deviceId: number, callback: AsyncCallback&lt;number&gt;): void                                                                                 | 解绑设备。                                                                              |
| unbindDevice(deviceId: number): Promise&lt;number&gt;                                                                                                       | 解绑设备的Promise形式。                                                                              |


## 开发步骤

应用可通过查询绑定扩展外设，从而使用扩展外设的定制驱动能力。开发示例如下：


1. 查询设备列表。

  ```js
  var matchDevice;
  try {
    let devices = deviceManager.queryDevices(deviceManager.BusType.USB);
    for (let item of devices) {
      let device = item as deviceManager.USBDevice;
      // 通过productId和vendorId来匹配要使用的USB设备
      if (device.productId == 1234 && device.vendorId === 2345) {
        matchDevice = device;
        break;
      }
    }
  } catch (error) {
    console.error('Failed to query device. Code is ${error.code}, message is ${error.message}');
  }
  if (!matchDevice) {
    console.error('No match device');
    return;
  }
  ```

2. 绑定相应的设备。

  ```js
  var remoteObject;
  try {
    deviceManager.bindDevice(matchDevice.deviceId, (error, data) => {
      console.error('Device is disconnected');
    }, (error, data) => {
      if (error) {
        console.error('bindDevice async fail. Code is ${error.code}, message is ${error.message}');
        return;
      }
      console.info('bindDevice success');
      remoteObject = data.remote;
    });
  } catch (error) {
    console.error('bindDevice fail. Code is ${error.code}, message is ${error.message}');
  }
   ```

3. 绑定成功后使用设备驱动能力。

  ```js
  let option = new rpc.MessageOption();
  let data = rpc.MessageSequence.create();
  let repy = rpc.MessageSequence.create();
  data.writeString('hello');
  let code = 1;
  // code和data内容取决于驱动提供的接口
  remoteObject.sendMessageRequest(code, data, reply, option)
    .then(result => {
      console.info('sendMessageRequest finish.');
    }).catch(error => {
      console.error('sendMessageRequest fail. code:' + error.code);
    });
  ```

4. 设备使用完成，解绑设备。

  ```js
  try {
    deviceManager.unbindDevice(matchDevice.deviceId, (error, data) => {
      if (error) {
        console.error('unbindDevice async fail. Code is ${error.code}, message is ${error.message}');
        return;
      }
      console.info('unbindDevice success');
    });
  } catch (error) {
    console.error('unbindDevice fail. Code is ${error.code}, message is ${error.message}');
  }
  ```
