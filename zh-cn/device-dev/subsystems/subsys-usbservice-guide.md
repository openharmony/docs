# USB服务子系使用指导<a name="ZH-CN_TOPIC_0000001077367159"></a>

-   [使用步骤](#section18816105182315)

下面使用步骤以sensorTypeId为0的传感器为例，其他类型的传感器使用方式类似。

## 使用步骤<a name="section18816105182315"></a>

1.  获取usb service实例

```
auto &srvClient = UsbSrvClient::GetInstance();
```

2.  获取usb设备列表

```
std::vector<UsbDevice> deviceList;
int32_t ret = srvClient.GetDevices(deviceList);
```

3.  申请设备权限

```
UsbDevice device = deviceList.front();
int32_t ret = UsbSrvClient.RequestRight(device.GetName());
```

4.  打开设备

```
USBDevicePipe pip;
int32_t ret = srvClient.OpenDevice(dev, pip);
```

5.  配置设备接口

```
srvClient.ClaimInterface(pip, interface, force);
interface为deviceList中device的interface。
```

6.  数据传输

```
srvClient.BulkTransfer(pipe, endpoint, vdata, timeout);
```
pipe为打开设备后的数据传输通道，endpoint为device中数据传输的端点，vdata是需要传输或读取的二进制数据块，timeout为传输超时时长.

7.  关闭设备

```
srvClient.Close(pipe);
```
