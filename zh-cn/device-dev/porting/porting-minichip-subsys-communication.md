# 移植通信子系统


通信子系统目前涉及Wi-Fi和蓝牙适配，厂商应当根据芯片自身情况进行适配。


## 移植指导

Wi-Fi编译文件内容如下：

  路径：“foundation/communication/wifi_lite/BUILD.gn”
  
```
group("wifi") {
  deps = [ "$ohos_board_adapter_dir/hals/communication/wifi_lite/wifiservice:wifiservice" ]
}
```

从中可以看到厂商适配相关接口的.c文件存放目录应为“$ohos_board_adapter_dir/hals/communication/wifi_lite/wifiservice”，且该目录下BUILD.gn文件中的目标应为“wifiservice”。需要厂商适配的Wi-Fi接口见表1 、表2 和表3，蓝牙接口见表4和表5。

  **表1** wifi_device.h

| 接口 | 作用 | 
| -------- | -------- |
| EnableWifi | 启用Wi-Fista模式。 | 
| DisableWifi | 禁用Wi-Fi&nbsp;sta模式。 | 
| IsWifiActive | 检查Wi-Fi&nbsp;sta模式是否启用。 | 
| Scan | 扫描热点信息。 | 
| GetScanInfoList | 获取所有扫描到的热点列表。 | 
| AddDeviceConfig | 配置连接到的热点信息。 | 
| GetDeviceConfigs | 获取配置连接到的热点信息。 | 
| RemoveDevice | 删除指定的热点配置信息。 | 
| ConnectTo | 接到指定的热点。 | 
| Disconnect | 断开Wi-Fi连接。 | 
| GetLinkedInfo | 获取热点连接信息。 | 
| RegisterWifiEvent | 为指定的Wi-Fi事件注册回调。 | 
| UnRegisterWifiEvent | 取消注册以前为指定Wi-Fi事件注册的回调。 | 
| GetDeviceMacAddress | 获取设备的MAC地址。 | 
| AdvanceScan | 根据指定参数启动Wi-Fi扫描。 | 

  **表2** wifi_hotspot_config.h

| 接口 | 作用 | 
| -------- | -------- | 
| SetBand | 设置该热点的频段。 | 
| GetBand | 获取该热点的频段。 | 

  **表3** wifi_hotspot.h

| 接口 | 作用 | 
| -------- | -------- |
| EnableHotspot | 启用Ap热点模式。 | 
| DisableHotspot | 禁用Ap热点模式。 | 
| SetHotspotConfig | 设置指定的热点配置。 | 
| GetHotspotConfig | 获取指定的热点配置。 | 
| IsHotspotActive | 检查Ap热点模式是否启用。 | 
| GetStationList | 获取连接到此热点的一系列STA。 | 
| GetSignalLevel | 获取指定接收信号强度指示器（RSSI）和频带指示的信号电平。 | 
| DisassociateSta | 使用指定的MAC地址断开与STA的连接。 | 
| AddTxPowerInfo | 将hotspot功率发送到beacon。 | 

  **表4** ohos_bt_gatt.h

| 接口 | 作用 | 
| -------- | -------- |
| InitBtStack | 初始化蓝牙协议栈。 | 
| EnableBtStack | 使能蓝牙协议栈。 | 
| DisableBtStack | 禁用蓝牙协议栈。 | 
| SetDeviceName | 设置蓝牙设备名称。 | 
| BleSetAdvData | 设置广播数据。 | 
| BleStartAdv | 开始广播。 | 
| BleStartAdvEx | 传入构建好的广播数据，参数，开启蓝牙广播。 | 
| BleStopAdv | 停止发送广播。 | 
| BleUpdateAdv | 更新advertising参数。 | 
| BleSetSecurityIoCap | 设置蓝牙的IO能力为NONE，配对方式为justworks。 | 
| BleSetSecurityAuthReq | 设置蓝牙是否需要配对绑定。 | 
| BleGattSecurityRsp | 响应安全连接请求。 | 
| ReadBtMacAddr | 获取设备MAC地址。 | 
| BleSetScanParameters | 设置扫描参数。 | 
| BleStartScan | 开始扫描。 | 
| BleStopScan | 停止扫描。 | 
| BleGattRegisterCallbacks | 注册gap,GATT事件回调函数。 | 

  **表5** ohos_bt_gatt_server.h

| 接口 | 作用 | 
| -------- | -------- |
| BleGattsRegister | 使用指定的应用程序UUID注册GATT服务器。 | 
| BleGattsUnRegister | 断开GATT服务器与客户端的连接。 | 
| BleGattsDisconnect | 断开GATT服务器与客户端的连接。 | 
| BleGattsAddService | 添加了一个服务。 | 
| BleGattsAddIncludedService | 将包含的服务添加到指定的服务。 | 
| BleGattsAddCharacteristic | 向指定的服务添加特征。 | 
| BleGattsAddDescriptor | 将描述符添加到指定的特征。 | 
| BleGattsStartService | 启动一个服务。 | 
| BleGattsStopService | 停止服务。 | 
| BleGattsDeleteService | 删除一个服务。 | 
| BleGattsClearServices | 清除所有服务。 | 
| BleGattsSendResponse | 向接收到读取或写入请求的客户端发送响应。 | 
| BleGattsSendIndication | 设备侧向APP发送蓝牙数据。 | 
| BleGattsSetEncryption | 设置GATT连接的加密类型。 | 
| BleGattsRegisterCallbacks | 注册GATT服务器回调。 | 
| BleGattsStartServiceEx | 根据传入的服务列表，创建gatt服务。 | 
| BleGattsStopServiceEx | 传入gatt服务句柄，停止gatt服务。 | 

> ![icon-note.gif](public_sys-resources/icon-note.gif) **说明：**
> 不同版本接口可能存在差异，需要根据当前版本的具体文件进行适配。


## 适配实例

1. 在“config.json”中添加communication子系统。
   路径：“vendor/MyVendorCompany/MyProduct/config.json”

   修改如下：

     
   ```
   { 
       "subsystem": "communication", 
       "components": [ 
           { "component": "wifi_lite", "features":[] }
       ] 
   },
   ```

2. 添加适配文件。

   在“vendor/MyVendorCompany/MyProduct/config.json”文件中，通常将配置“ohos_board_adapter_dir”配置为 “//vendor/MyVendorCompany/MyProduct/adapter”。

   在“ohos_board_adapter_dir”目录下根据上述适配指导中提到的头文件，适配Wi-Fi、蓝牙接口。
