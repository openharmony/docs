# USB Usage Guidelines<a name="EN-US_TOPIC_0000001077367159"></a>


The following procedure uses bulk transfer as an example.

## Procedure<a name="section18816105182315"></a>

1.  Obtain a USB service instance.

```
static OHOS::USB::UsbSrvClient &g_usbClient = OHOS::USB::UsbSrvClient::GetInstance();
```

2.  Obtain the USB device list.

```
std::vector<OHOS::USB::UsbDevice> deviceList;
int32_t ret = g_usbClient.GetDevices(deviceList);
```

3.  Apply for device access permissions.

```
int32_t ret = g_usbClient.RequestRight(device.GetName());
```

4.  Opens the USB device.

```
USBDevicePipe pip;
int32_t et = g_usbClient.OpenDevice(device, pip);
```

5.  Configure the USB interface.

```
ret = g_usbClient.ClaimInterface(pip, interface, true);
**interface** indicates an interface of the USB device in **deviceList**.
```

6.  Transfer data.

```
srvClient.BulkTransfer(pipe, endpoint, vdata, timeout);
```
- **pipe** indicates the pipe for data transfer of the USB device opened. 
- **endpoint** indicates the endpoint for data transfer on the USB device. 
- **vdata** indicates the binary data block to be transferred or read. 
- **timeout** indicates the timeout duration of data transfer.

7.  Close the USB device.

```
ret = g_usbClient.Close(pip);
```
