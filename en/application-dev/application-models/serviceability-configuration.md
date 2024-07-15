# ServiceAbility Configuration


Similar to a PageAbility, a ServiceAbility is configured in **abilities** under **module** of the **config.json** file. The difference between a ServiceAbility and PageAbility lies in the **type** and **backgroundModes** fields.


**Table 1** ServiceAbility configuration items

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| type | Type of the ability. The value **service** indicates that the ability is developed based on the Service template.| String| No|
| backgroundModes | Background service type of the ability. You can assign multiple background service types to a specific ability. This field applies only to the ability using the Service template. The value can be:<br>**dataTransfer**: service for downloading, backing up, sharing, or transferring data from the network or peer devices.<br>**audioPlayback**: audio playback service.<br>**audioRecording**: audio recording service.<br>**pictureInPicture**: picture in picture (PiP) and small-window video playback services.<br>**voip**: voice/video call and VoIP services.<br>**location**: location and navigation services.<br>**bluetoothInteraction**: Bluetooth scanning, connection, and transmission services.<br>**wifiInteraction**: WLAN scanning, connection, and transmission services.<br>**screenFetch**: screen recording and screenshot services.<br>**multiDeviceConnection**: multi-device interconnection service.| String array| Yes (initial value: left empty)|


For details about the configuration items, see [Internal Structure of module](../quick-start/module-structure.md).
