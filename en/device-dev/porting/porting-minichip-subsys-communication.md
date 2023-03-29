# Porting the Communication Subsystem


The communication subsystem porting process involves Wi-Fi and Bluetooth adaptation. Vendors need to perform adaptation based on the chip conditions.


## Procedure

To implement Wi-Fi adaptation, perform the following steps:

Path: **foundation/communication/wifi_lite/BUILD.gn**

```
group("wifi") {
  deps = [ "$ohos_board_adapter_dir/hals/communication/wifi_lite/wifiservice:wifiservice" ]
}
```

As shown above, the .c file of the vendor adaptation interfaces is stored in the **$ohos_board_adapter_dir/hals/communication/wifi_lite/wifiservice** directory, where the target in the **BUILD.gn** file is **wifiservice**. Table 1, Table 2, and Table 3 list the Wi-Fi interfaces that need to be adapted by vendors. Table 4 and Table 5 list the Bluetooth interfaces.

**Table 1** wifi_device.h

| API| Description|
| -------- | -------- |
| EnableWifi | Enables the Wi-Fi STA mode.|
| DisableWifi | Disables the Wi-Fi STA mode.|
| IsWifiActive | Check whether the Wi-Fi STA mode is enabled.|
| Scan | Scans for hotspots.|
| GetScanInfoList | Obtains the list of all found hotspots.|
| AddDeviceConfig | Adds the information about the hotspot to be connected.|
| GetDeviceConfigs | Obtains the information about the connected hotspot.|
| RemoveDevice | Deletes the information about a specified hotspot.|
| ConnectTo | Connects to a specified hotspot.|
| Disconnect | Severs the Wi-Fi connection. |
| GetLinkedInfo | Obtains hotspot connection information.|
| RegisterWifiEvent | Registers a callback for a specified Wi-Fi event.|
| UnRegisterWifiEvent | Deregisters the callback previously registered for a specified Wi-Fi event.|
| GetDeviceMacAddress | Obtains the device MAC address.|
| AdvanceScan | Starts Wi-Fi scanning based on specified parameters.|

**Table 2** wifi_hotspot_config.h

| API| Description|
| -------- | -------- |
| SetBand | Sets the frequency band of the hotspot.|
| GetBand |Obtains the frequency band of the hotspot.|

**Table 3** wifi_hotspot.h

| API| Description|
| -------- | -------- |
| EnableHotspot | Enables AP hotspot mode.|
| DisableHotspot | Disables AP hotspot mode.|
| SetHotspotConfig | Configures settings for a specified hotspot.|
| GetHotspotConfig | Obtains settings of a specified hotspot.|
| IsHotspotActive | Checks whether AP hotspot mode is enabled.|
| GetStationList | Obtains a list of STAs connected to the hotspot.|
| GetSignalLevel | Obtains the signal level of the specified received signal strength indicator (RSSI) and frequency band indicator.|
| DisassociateSta | Disconnects from the STA that matches the specified MAC address.|
| AddTxPowerInfo | Sends the hotspot power to the beacon.|

**Table 4** ohos_bt_gatt.h

| API| Description|
| -------- | -------- |
| InitBtStack | Initializes the Bluetooth protocol stack.|
| EnableBtStack | Enables the Bluetooth protocol stack.|
| DisableBtStack | Disables the Bluetooth protocol stack.|
| SetDeviceName | Sets the Bluetooth device name.|
| BleSetAdvData | Sets the data to advertise.|
| BleStartAdv | Starts advertising.|
| BleStartAdvEx | Transfers the constructed advertising data and parameters to enable Bluetooth advertising.|
| BleStopAdv | Stops sending advertising messages.|
| BleUpdateAdv | Updates the advertising parameters.|
| BleSetSecurityIoCap | Sets the Bluetooth I/O capability to NONE and pairing mode to justworks.|
| BleSetSecurityAuthReq | Sets whether Bluetooth pairing is required.|
| BleGattSecurityRsp | Responds to a secure connection request.|
| ReadBtMacAddr | Obtains the device MAC address.|
| BleSetScanParameters | Sets scan parameters.|
| BleStartScan | Starts scanning|
| BleStopScan | Stops scanning.|
| BleGattRegisterCallbacks | Registers a callback for GAP and GATT events.|

**Table 5** ohos_bt_gatt_server.h

| API| Description|
| -------- | -------- |
| BleGattsRegister | Registers with the GATT server using the specified application UUID.|
| BleGattsUnRegister | Deregisters from the GATT server.|
| BleGattsDisconnect | Disconnects the GATT server from the client.|
| BleGattsAddService | Adds a service.|
| BleGattsAddIncludedService | Adds an included service to a specified service.|
| BleGattsAddCharacteristic | Adds a feature to a specified service.|
| BleGattsAddDescriptor | Adds a descriptor to a specified feature.|
| BleGattsStartService | Start a service.|
| BleGattsStopService | Stops a service.|
| BleGattsDeleteService | Deletes a service.|
| BleGattsClearServices | Clears all services.|
| BleGattsSendResponse | Sends a response to the client that receives the read or write request.|
| BleGattsSendIndication | Sends Bluetooth data from the device to the application.|
| BleGattsSetEncryption | Sets the encryption type of the GATT connection.|
| BleGattsRegisterCallbacks | Registers a GATT server callback.|
| BleGattsStartServiceEx | Creates a GATT service based on the passed service list.|
| BleGattsStopServiceEx | Stops the GATT service based on the passed handle .|

> ![icon-note.gif](public_sys-resources/icon-note.gif) **NOTE**
>
> The APIs may vary according to the version. Adapt the APIs according to the specific file of the current version.


## Example

1. Add the communication subsystem to the **config.json** file.

   Path: **vendor/MyVendorCompany/MyProduct/config.json**

   The sample code is as follows:

   
   ```
   { 
       "subsystem": "communication", 
       "components": [ 
           { "component": "wifi_lite", "features":[] }
       ] 
   },
   ```

2. Add an adaptation file.

   In the **vendor/MyVendorCompany/MyProduct/config.json** file, set **ohos_board_adapter_dir** to **//vendor/MyVendorCompany/MyProduct/adapter**.

   In the **ohos_board_adapter_dir** directory, adapt the Wi-Fi and Bluetooth APIs based on the aforementioned header files.
