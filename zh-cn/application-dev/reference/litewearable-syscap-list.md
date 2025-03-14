# 系统能力SystemCapability列表

SysCap，全称SystemCapability，即系统能力，指操作系统中每一个相对独立的特性。

开发者使用某个接口进行开发前，建议先阅读[SysCap使用指南](syscap.md)，了解Syscap的定义和使用指导。再结合下文中的表格判断具体能力集是否支持某个设备，提高开发效率。

> **说明：**
>
> 该列表枚举当前版本LiteWearable设备类型支持的最小系统能力集，开发者可以在sdk中通过liteWearable.json文件查询。
> 开发者使用该列表中的系统能力集对应的API开发当前版本LiteWearable应用时，可直接调用，无需在使用前进行canIUse()隔离判断。

- SystemCapability.ArkUI.ArkUI.Lite
- SystemCapability.Base
- SystemCapability.Location.Location.Lite
- SystemCapability.PowerManager.BatteryManager.Lite
- SystemCapability.FileManagement.File.FileIO.Lite
- SystemCapability.Startup.SystemInfo.Lite
- SystemCapability.PowerManager.DisplayPowerManager.Lite
- SystemCapability.Communication.NFC.CardEmulation
- SystemCapability.Security.Huks.Core
- SystemCapability.DistributedDataManager.Preferences.Core.Lite
- SystemCapability.Sensors.Sensor.Lite
- SystemCapability.Sensors.MiscDevice.Lite
- SystemCapability.Communication.NetStack
- SystemCapability.MiscServices.ScreenLock
- SystemCapability.Security.CryptoFramework
- SystemCapability.Security.CryptoFramework.MessageDigest
- SystemCapability.Security.CryptoFramework.Rand