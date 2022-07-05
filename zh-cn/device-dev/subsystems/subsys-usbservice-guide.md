# USB服务子系统使用指导<a name="ZH-CN_TOPIC_0000001077367159"></a>


下面使用步骤以bulktransfer为例。

使用步骤<a name="section18816105182315"></a>

1. 获取usb service实例

   ```cpp
   static OHOS::USB::UsbSrvClient &g_usbClient = OHOS::USB::UsbSrvClient::GetInstance();
   ```

2. 获取usb设备列表

  ```cpp
  std::vector<OHOS::USB::UsbDevice> deviceList;
  int32_t ret = g_usbClient.GetDevices(deviceList);
  ```

3. 申请设备权限

  ```cpp
  int32_t ret = g_usbClient.RequestRight(device.GetName());
  ```

4. 打开设备

  ```cpp
  USBDevicePipe pip;
  int32_t et = g_usbClient.OpenDevice(device, pip);
  ```

5. 配置设备接口

  ```cpp
  ret = g_usbClient.ClaimInterface(pip, interface, true);
  interface为deviceList中device的interface。
  ```

6. 数据传输

  ```cpp
  srvClient.BulkTransfer(pipe, endpoint, vdata, timeout);
  ```
  pipe为打开设备后的数据传输通道，endpoint为device中数据传输的端点，vdata是需要传输或读取的二进制数据块，timeout为传输超时时长。

7. 关闭设备
 
  ```cpp
  ret = g_usbClient.Close(pip);
  ```
