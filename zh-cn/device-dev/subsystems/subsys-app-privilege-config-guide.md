# 应用特权配置指南

应用特权是指应用所具备的一些高等级的特殊能力，比如限制应用不可被卸载、应用内数据不可被删除等。

OpenHarmony提供通用的应用特权和可由设备厂商针对不同设备单独配置的应用特权。当签名证书中配置的特权与白名单(install_list_capability.json)中特权相同时，以白名单的配置为主。

注：应当注意不要滥用应用特权，避免造成用户反感甚至对用户造成侵权。

## 通用应用特权

### 简介

通用的应用特权是指应用在不同设备类型上都可以获得的特权，可分为以下几种：

| 权限 | 描述                                                       |
| ---------------- | ------------------------------------------------------------ |
| AllowAppDataNotCleared | 是否允许应用数据被删除 |
| AllowAppDesktopIconHide | 是否允许隐藏桌面图标 |
| AllowAbilityPriorityQueried | 是否允许Ability配置查询优先级     |
| AllowAbilityExcludeFromMissions | 是否允许Ability不在任务栈中显示 |

### 配置方式

1. 在[HarmonyAppProvision文件](../../application-dev/security/app-provision-structure.md)中添加字段”app-privilege-capabilities“，按需配置通用权限能力。
2. 使用签名工具对HarmonyAppProvision文件重新签名，生成p7b文件
3. 使用p7b文件签名hap

参考：[应用签名](https://gitee.com/openharmony/developtools_hapsigner#hap%E5%8C%85%E7%AD%BE%E5%90%8D%E5%B7%A5%E5%85%B7 )

### 示例

```
{
    "version-name": "1.0.0",
    ...
    "bundle-info": {
        "developer-id": "OpenHarmony",
        ...
    },
    "issuer": "pki_internal",
    "app-privilege-capabilities": ["AllowAppDataNotCleared", "AllowAppDesktopIconHide"] // 应用的数据不允许被删除且允许隐藏桌面图标
}
```



## 可由设备厂商配置的特权

### 简介

除了通用应用特权外，设备厂商还可以为各类设备额外定义允许配置的特权项，包括：

| 权限                  | 类型     | 默认值 | 描述                                              |
| --------------------- | -------- | ------ | ------------------------------------------------- |
| removable             | bool     | true   | 是否允许应用被卸载，仅预置应用生效                |
| keepAlive             | bool     | false  | 是否允许应用常驻                                  |
| singleton             | bool     | false  | 是否允许应用安装到单用户下(U0)                    |
| allowCommonEvent      | string[] | -      | 是否允许静态广播拉起                              |
| associatedWakeUp      | bool     | false  | 是否允许FA模型应用被关联唤醒                      |
| runningResourcesApply | bool     | false  | 是否允许应用运行资源申请（CPU、事件通知、蓝牙等） |
| allowAppDataNotCleared | bool | false|是否允许应用数据被删除 |
| allowAppMultiProcess | bool | false| 是否允许应用多进程 |
| allowAppDesktopIconHide | bool | false| 是否允许隐藏桌面图标 |
| allowAbilityPriorityQueried | bool | false| 是否允许Ability配置查询优先级     |
| allowAbilityExcludeFromMissions | bool | false| 是否允许Ability不在任务栈中显示 |
| allowAppUsePrivilegeExtension | bool | false|是否允许应用使用ServiceExtension、DataExtension |
| allowFormVisibleNotify | bool | false| 是否允许桌面卡片可见 |

### 配置方式

按需在[产品配置文件](https://gitee.com/openharmony/vendor_hihope/tree/master/rk3568/preinstall-config)中配置。

### 示例

#### install_list_capability.json中配置

```
{
    "install_list": [
        {
            "bundleName": “com.example.kikakeyboard”,
            "singleton": true, // 应用安装到单用户下
            "keepAlive": true, // 应用常驻
            "runningResourcesApply": true, // 运行资源申请（CPU、事件通知、蓝牙等）
            "associatedWakeUp": true, // FA模型应用被关联唤醒
            "app_signature" : [“8E93863FC32EE238060BF69A9B37E2608FFFB21F93C862DD511CBAC”], // 当配置的证书指纹和hap的证书指纹一致才生效
            "allowCommonEvent": [“usual.event.SCREEN_ON”, “usual.event.THERMAL_LEVEL_CHANGED”],
            "allowAppDataNotCleared": true, // 不允许应用数据被删除
            "allowAppMultiProcess": true, //允许应用多进程
            "allowAppDesktopIconHide": true, //允许隐藏桌面图标
            "allowAbilityPriorityQueried": true, //允许Ability配置查询优先级
            "allowAbilityExcludeFromMissions": true, // 允许Ability不在任务栈中显示
            "allowAppUsePrivilegeExtension": true, // 允许应用使用ServiceExtension、DataExtension
            "allowFormVisibleNotify": true // 允许桌面卡片可见
        },
}
```

**证书指纹获取**

**步骤一、证书存放在HarmonyAppProvision文件的distribution-certificate字段下，新建profile.cer文件，将证书的内容拷贝到profile.cer文件中**

示例

```
{
    ...
    "bundle-info": {
        "distribution-certificate": "-----BEGIN CERTIFICATE----\nMIICMzCCAbegAwIBAgIEaOC/zDAMBggqhkjOPQQDAwUAMk..." /证书的内容
        ...
    }
    ...
}
```

**步骤二、将profile.cer内容换行和去掉换行符**

示例

```
-----BEGIN CERTIFICATE-----
MIICMzCCAbegAwIBAgIEaOC/zDAMBggqhkjOPQQDAwUAMGMxCzAJBgNVBAYTAkNO
MRQwEgYDVQQKEwtPcGVuSGFybW9ueTEZMBcGA1UECxMQT3Blbkhhcm1vbnkgVGVh
bTEjMCEGA1UEAxMaT3Blbkhhcm1vbnkgQXBwbGljYXRpb24gQ0EwHhcNMjEwMjAy
MTIxOTMxWhcNNDkxMjMxMTIxOTMxWjBoMQswCQYDVQQGEwJDTjEUMBIGA1UEChML
T3Blbkhhcm1vbnkxGTAXBgNVBAsTEE9wZW5IYXJtb255IFRlYW0xKDAmBgNVBAMT
H09wZW5IYXJtb255IEFwcGxpY2F0aW9uIFJlbGVhc2UwWTATBgcqhkjOPQIBBggq
hkjOPQMBBwNCAATbYOCQQpW5fdkYHN45v0X3AHax12jPBdEDosFRIZ1eXmxOYzSG
JwMfsHhUU90E8lI0TXYZnNmgM1sovubeQqATo1IwUDAfBgNVHSMEGDAWgBTbhrci
FtULoUu33SV7ufEFfaItRzAOBgNVHQ8BAf8EBAMCB4AwHQYDVR0OBBYEFPtxruhl
cRBQsJdwcZqLu9oNUVgaMAwGCCqGSM49BAMDBQADaAAwZQIxAJta0PQ2p4DIu/ps
LMdLCDgQ5UH1l0B4PGhBlMgdi2zf8nk9spazEQI/0XNwpft8QAIwHSuA2WelVi/o
zAlF08DnbJrOOtOnQq5wHOPlDYB4OtUzOYJk9scotrEnJxJzGsh/
-----END CERTIFICATE-----
```

**步骤三、使用keytool工具打印对应的证书指纹**

示例

```
keytool -printcert -file profile.cer
result:
所有者: CN=OpenHarmony Application Release, OU=OpenHarmony Team, O=OpenHarmony, C=CN
发布者: CN=OpenHarmony Application CA, OU=OpenHarmony Team, O=OpenHarmony, C=CN
序列号: 68e0bfcc
生效时间: Tue Feb 02 20:19:31 CST 2021, 失效时间: Fri Dec 31 20:19:31 CST 2049
证书指纹:
         SHA1: E3:E8:7C:65:B8:1D:02:52:24:6A:06:A4:3C:4A:02:39:19:92:D1:F5
         SHA256: 8E:93:86:3F:C3:2E:E2:38:06:0B:F6:9A:9B:37:E2:60:8F:FF:B2:1F:93:C8:62:DD:51:1C:BA:C9:F3:00:24:B5 // 证书指纹，去掉冒号，最终结果为8E93863FC32EE238060BF69A9B37E2608FFFB21F93C862DD511CBAC9F30024B5
...
```



#### install_list.json中配置

```
{
     "install_list" : [
        {
            "app_dir" : "/system/app/com.ohos.launcher",
            "removable" : true // 应用是否可卸载
        }
     ]
}
```



