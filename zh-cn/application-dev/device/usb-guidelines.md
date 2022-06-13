# USB服务开发指导



## 场景介绍

Host模式下，可以获取到已经连接的设备列表，并根据需要打开和关闭设备、控制设备权限、进行数据传输等。


## 接口说明

USB服务主要提供的功能有：查询USB设备列表、批量数据传输、控制命令传输、权限控制等。

USB类开放能力如下，具体请查阅[API参考文档](../reference/apis/js-apis-usb.md)。

**表1** USB类的开放能力接口

| 接口名 | 描述 |
| -------- | -------- |
| hasRight(deviceName:&nbsp;string):&nbsp;boolean | 如果“使用者”（如各种App或系统）有权访问设备则返回true；无权访问设备则返回false。 |
| requestRight(deviceName:&nbsp;string):&nbsp;Promise&lt;boolean&gt; | 请求给定软件包的临时权限以访问设备。 |
| connectDevice(device:&nbsp;USBDevice):&nbsp;Readonly&lt;USBDevicePipe&gt; | 根据getDevices()返回的设备信息打开USB设备。 |
| getDevices():&nbsp;Array&lt;Readonly&lt;USBDevice&gt;&gt; | 返回USB设备的列表。 |
| setConfiguration(pipe:&nbsp;USBDevicePipe,&nbsp;config:&nbsp;USBConfig):&nbsp;number | 设置设备的配置。 |
| setInterface(pipe:&nbsp;USBDevicePipe,&nbsp;iface:&nbsp;USBInterface):&nbsp;number | 设置设备的接口。 |
| claimInterface(pipe:&nbsp;USBDevicePipe,&nbsp;iface:&nbsp;USBInterface,&nbsp;force?:&nbsp;boolean):&nbsp;number | 获取接口。 |
| function&nbsp;bulkTransfer(pipe:&nbsp;USBDevicePipe,&nbsp;endpoint:&nbsp;USBEndpoint,&nbsp;buffer:&nbsp;Uint8Array,&nbsp;timeout?:&nbsp;number):&nbsp;Promise&lt;number&gt; | 批量传输。 |
| closePipe(pipe:&nbsp;USBDevicePipe):&nbsp;number | 关闭设备消息控制通道。 |
| releaseInterface(pipe:&nbsp;USBDevicePipe,&nbsp;iface:&nbsp;USBInterface):&nbsp;number | 释放接口。 |
| getFileDescriptor(pipe:&nbsp;USBDevicePipe):&nbsp;number | 获取文件描述符。 |
| getRawDescriptor(pipe:&nbsp;USBDevicePipe):&nbsp;Uint8Array | 获取原始的USB描述符。 |
| controlTransfer(pipe:&nbsp;USBDevicePipe,&nbsp;contrlparam:&nbsp;USBControlParams,&nbsp;timeout?:&nbsp;number):&nbsp;Promise&lt;number&gt; | 控制传输。 |


## 开发步骤

USB设备可作为Host设备连接Device设备进行数据传输。开发示例如下：


1. 获取设备列表。
   ```js
   // 导入usb接口api包。
   import usb from '@ohos.usb';
   // 获取设备列表。
   var deviceList = usb.getDevices();
   /*
   deviceList结构示例
   [
     {
       name: "1-1",
       serial: "",
       manufacturerName: "",
       productName: "",
       version: "",
       vendorId: 7531,
       productId: 2,
       clazz: 9,
       subclass: 0,
       protocol: 1,
       devAddress: 1,
       busNum: 1,
       configs: [
         {
           id: 1,
           attributes: 224,
           isRemoteWakeup: true,
           isSelfPowered: true,
           maxPower: 0,
           name: "1-1",
           interfaces: [
             {
               id: 0,
               protocol: 0,
               clazz: 9,
               subclass: 0,
               alternateSetting: 0,
               name: "1-1",
               endpoints: [
                 {
                   address: 129,
                   attributes: 3,
                   interval: 12,
                   maxPacketSize: 4,
                   direction: 128,
                   number: 1,
                   type: 3,
                   interfaceId: 0,
                 },
               ],
             },
           ],
         },
       ],
     },
   ],
   */
   ```

2. 获取设备操作权限。
   ```js
   var deviceName = deviceList[0].name;
   // 申请操作指定的device的操作权限。
   usb.requestRight(deviceName).then(hasRight => {
     console.info("usb device request right result: " + hasRight);
   }).catch(error => {
     console.info("usb device request right failed : " + error);
   });
   ```

3. 打开Device设备。
   ```js
   // 打开设备，获取数据传输通道。
   var pipe = usb.connectDevice(deviceList[0]);
   /*
    打开对应接口，在设备信息（deviceList）中选取对应的interface。
   interface1为设备配置中的一个接口。
   */
   usb.claimInterface(pipe , interface1, true); 
   ```

4. 数据传输。
   ```js
   /*
    读取数据，在device信息中选取对应数据接收的endpoint来做数据传输
   （endpoint.direction == 0x80）；dataUint8Array是要读取的数据，类型为Uint8Array。
   */
   
   usb.bulkTransfer(pipe, inEndpoint, dataUint8Array, 15000).then(dataLength => {
   if (dataLength >= 0) {
     console.info("usb readData result Length : " + dataLength);
     var resultStr = this.ab2str(dataUint8Array); // uint8数据转string。
     console.info("usb readData buffer : " + resultStr);
   } else {
     console.info("usb readData failed : " + dataLength);
   }
   }).catch(error => {
   console.info("usb readData error : " + JSON.stringify(error));
   });
   // 发送数据，在device信息中选取对应数据发送的endpoint来做数据传输。（endpoint.direction == 0）
   usb.bulkTransfer(pipe, endpoint, dataUint8Array, 15000).then(dataLength => {
     if (dataLength >= 0) {
       console.info("usb writeData result write length : " + dataLength);
     } else {
       console.info("writeData failed");
     }
   }).catch(error => {
     console.info("usb writeData error : " + JSON.stringify(error));
   });
   ```

5. 释放接口，关闭设备。
   ```js
   usb.releaseInterface(pipe, interface1);
   usb.closePipe(pipe);
   ```
