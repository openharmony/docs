# 3.2 beta3相对于3.2 beta2变更详细说明

## 包管理子系统

Beta3版本上增加了预置应用特权管控能力，可以分为两部分：预置应用权限管控和预置应用的配置方法。
应用特权是指应用所具备的一些高等级的特殊能力，比如限制应用不可被卸载、应用内数据不可被删除等。
OpenHarmony提供通用的应用特权和可由设备厂商针对不同设备单独配置的应用特权。OpenHarmony支持在不同产品上对预置应用进行差异化配置，设备厂商可根据需要对预置应用进行配置。此外，OpenHarmony根据GetCfgDirList获得系统支持的预置目录，如system、chipset、sys_prod、chip_prod；并且按照返回的顺序越靠后优先级越高，如chip_prod的优先级高于system的优先级。

### 预置应用安装方式变更

当前预置应用的安装方式由自动扫描目录/system/app下面的hap安装，变更为通过白名单配置方式安装。在install_list.json中配置app-dir的hap才会被自动安装，并成为预置应用。

**变更影响**

不涉及js及native接口，对开发应用无影响。

**关键的接口/组件变更**

无

**适配指导**

在[/system/etc/app/install_list.json](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/install_list.json)文件中配置相关字段，app_dir表示hap所在的目录，removable表示hap安装后是否可卸载。如下所示：

```json
{
    "install_list" : [
        {
            "app_dir" : "/system/app/com.ohos.systemui",
            "removable" : false
        },
        {
            "app_dir" : "/system/app/demo.hap",
            "removable" : true
        }
    ]
}
```

### 通用应用特权管控变更

通用的应用特权是指应用在不同设备类型上都可以获得的特权，可分为以下几种：
| 权限 | 描述                                                       |
| ---------------- | ------------------------------------------------------------ |
| AllowAppDataNotCleared | 是否允许应用数据被删除 |
| AllowAppMultiProcess | 是否允许应用多进程 |
| AllowAppDesktopIconHide | 是否允许隐藏桌面图标 |
| AllowAbilityPriorityQueried | 是否允许Ability配置查询优先级     |
| AllowAbilityExcludeFromMissions | 是否允许Ability不在任务栈中显示 |
| AllowAppUsePrivilegeExtension | 是否允许应用使用ServiceExtension、DataExtension |
| AllowFormVisibleNotify | 是否允许桌面卡片可见 |

上述特权之前通过config.json或者module.json进行配置，并结合是否为预置应用和系统应用进行区分，本次变更为根据签名证书和预置白名单的方式进行配置，其它方式均无效。

**变更影响**

不涉及js及native接口，如果开发的应用中使用上述特权，那就需要应用开发者申请对应的特权，申请及配置方式可参考[应用配置指南](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/subsystems/subsys-app-privilege-config-guide.md)。

**关键的接口/组件变更**

无

**适配指导**

可参考[应用配置指南](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/subsystems/subsys-app-privilege-config-guide.md)

```json
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

### 产品化应用特权管控变更
除了通用应用特权外，设备厂商还可以为各类设备额外定义允许配置的特权项，包括：

| 权限                  | 类型     | 默认值 | 描述                                              |
| --------------------- | -------- | ------ | ------------------------------------------------- |
| removable             | bool     | true   | 是否允许应用被卸载，仅预置应用生效                |
| keepAlive             | bool     | false  | 是否允许应用常驻                                  |
| singleton             | bool     | false  | 是否允许应用安装到单用户下(U0)                    |
| allowCommonEvent      | string[] | -      | 是否允许静态广播拉起                              |
| associatedWakeUp      | bool     | false  | 是否允许FA模型应用被关联唤醒                      |
| runningResourcesApply | bool     | false  | 是否允许应用运行资源申请（CPU、事件通知、蓝牙等） |

上述特权之前通过config.json或者module.json进行配置，并结合是否为预置应用和系统应用进行区分，本次变更为根据预置白名单[install_list_capability.json](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/install_list_capability.json)的方式进行配置，其它方式均无效。

**变更影响**

不涉及js及native接口，如果开发的应用中使用上述特权，那就需要应用开发者申请对应的特权，可参考[配置方式](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/subsystems/subsys-app-privilege-config-guide.md#%E9%85%8D%E7%BD%AE%E6%96%B9%E5%BC%8F-1)。

**关键的接口/组件变更**

无

**适配指导**

可参考[配置方式](https://gitee.com/openharmony/docs/blob/master/zh-cn/device-dev/subsystems/subsys-app-privilege-config-guide.md#%E9%85%8D%E7%BD%AE%E6%96%B9%E5%BC%8F-1)

```json
{
    "install_list": [
        {
            "bundleName": "com.example.kikakeyboard",
            "singleton": true, // 应用安装到单用户下
            "keepAlive": true, // 应用常驻
            "runningResourcesApply": true, // 运行资源申请（CPU、事件通知、蓝牙等）
            "associatedWakeUp": true, // FA模型应用被关联唤醒
            "app_signature" : ["8E93863FC32EE238060BF69A9B37E2608FFFB21F93C862DD511CBAC"], // 当配置的证书指纹和hap的证书指纹一致才生效
            "allowCommonEvent": ["usual.event.SCREEN_ON", "usual.event.THERMAL_LEVEL_CHANGED"]
        }
}
```

### 预授权白名单增加指纹信息校验

预授权文件[install_list_permissions.json](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/install_list_permissions.json)在开发板上的路径由system/etc/permission变更为system/etc/app/。新增字段app_signature，表示hap的指纹信息，可以配置多个指纹信息。在授权时，指纹信息匹配成功才能授权。

**变更影响**

不涉及js及native接口，如果开发的应用中使用了预授权能力，需要在预授权文件中增加指纹信息，未配置会导致预授权失败。

**关键的接口/组件变更**

无

**适配指导**
可参考：
```json
{
[
    {
        "bundleName" : "com.ohos.screenshot",
        "app_signature" : ["8E93863FC32EE238060BF69A9B37E2608FFFB21F93C862DD511CBAC9F30024B5"],
        "permissions" : [
            {
                "name" : "ohos.permission.MEDIA_LOCATION",
                "userCancellable" : true
            },
            {
                "name" : "ohos.permission.READ_MEDIA",
                "userCancellable" : true
            },
            {
                "name" : "ohos.permission.WRITE_MEDIA",
                "userCancellable" : true
            }
        ]
    }
}
```

## ArkUI子系统

### 修复FA模型下编译构建release hap模式的公共模块变量共享问题

两个页面依赖同一个文件的对象（foodData）时，当页面A修改了这个对象，当页面B读取这个对象时，获取到的是页面A修改后的值，从而实现了公共模块对象共享。

**变更影响**

FA模型下的公共模块变量共享之前是作为需求交付的，在中间某个版本开始，编译release的hap该功能缺失，编译debug的hap一直是正常的，在830版本修复了编译release hap模式下的公共模块变量共享功能。

不影响应用编译，无需适配接口。

**关键的接口/组件变更**

无

### 状态变量多种数据类型声明使用限制。

状态变量比如@State、@Provide、 @Link和@Consume等，定义数据类型时，只能同时由简单数据类型或对象引用数据类型其中一种构成。

示例：

```ts
@Entry
@Component
struct Index {
  //错误写法: @State message: string | Resource = 'Hello World'
  @State message: string = 'Hello World'

  build() {
    Row() {
      Column() {
        Text(`${ this.message }`)
          .fontSize(50)
          .fontWeight(FontWeight.Bold)
      }
      .width('100%')
    }
    .height('100%')
  }
}
```

**变更影响**

当定义的状态变量类型中同时包含简单类型和对象引用数据类型时，编译报错提示不支持。

**关键的接口/组件变更**

当定义的状态变量类型中同时包含简单类型和对象引用数据类型时，需修改为只含有其中一种，如上述示例代码所示。

## 全球化子系统

### 针对color.json中颜色值，增加合法性校验

针对color.json中颜色值，增加合法性校验，其校验规则如下：

- 使用十六进制颜色码，格式如下：
    - #rgb：red(0-f) green(0-f) blue(0-f)
    - #argb：transparency(0-f) red(0-f) green(0-f) blue(0-f)
    - #rrggbb： red(00-ff) green(00-ff) blue(00-ff)
    - #aarrggbb： transparency(00-ff) red(00-ff) green(00-ff) blue(00-ff)
- 使用$引用应用中已定义的资源，格式如下：
    - $color:xxx

**变更影响**

不符合上述校验规则，将在编译时报错。

**关键的接口/组件变更**

无

## 电源管理子系统

### 修改@ohos.batteryinfo.d.ts文件名

API声明文件@ohos.batteryinfo.d.ts，变更其文件名为@ohos.batteryInfo.d.ts。

**变更影响**

JS/TS 引用该声明时，由`import batteryInfo from '@ohos.batteryinfo';` 变为`import batteryInfo from '@ohos.batteryInfo';`

**关键的接口/组件变更**

无

### 修改runninglock.d.ts文件名

API声明文件@ohos.runninglock.d.ts，变更其文件名为@ohos.runningLock.d.ts。

**变更影响**

JS/TS 引用该声明时，由`import runningLock from '@ohos.runninglock';` 变为`import runningLock from '@ohos.runningLock';`

**关键的接口/组件变更**

无