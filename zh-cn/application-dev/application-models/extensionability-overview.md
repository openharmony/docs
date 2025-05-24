# ExtensionAbility组件


[ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md)是为应用提供的扩展能力。借助各种类型的ExtensionAbility组件，应用可以将自定义的功能扩展到自身以外，实现与其他应用或系统更好的交互。系统会在合适的时机拉起特定的ExtensionAbility组件，例如在桌面添加卡片时拉起应用自定义的服务卡片。

通常，各类型的ExtensionAbility组件均由相应的系统服务统一管理，例如[InputMethodExtensionAbility](../reference/apis-ime-kit/js-apis-inputmethod-extension-ability.md)组件由输入法管理服务统一管理。在完成相应的任务之后，ExtensionAbility组件会及时退出。

ExtensionAbility组件均由系统定义，开发者只能使用（包括实现和访问）系统已定义的类型。它的类型由[ExtensionAbilityType](../reference/apis-ability-kit/js-apis-bundleManager.md#extensionabilitytype)标识。

当前系统已定义的ExtensionAbility类型如下表所示。

> 说明：
> 
> - “是否允许三方应用实现”是指：对于一类ExtensionAbility，三方应用能否继承该ExtensionAbility父类实现自己的业务逻辑。
> - “是否有独立Extension沙箱”是指：ExtensionAbility的沙箱是否与主应用沙箱相对独立，不可互相访问。

| ExtensionAbility类型                 | 功能描述 | 是否允许三<br/>方应用实现                  | 是否有独立<br/>Extension沙箱 |
|--------------------------------------|---------|-------------------------------------------|-----------------------|
| [FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md)  | 卡片扩展能力，用于提供[服务卡片](../form/formkit-overview.md)的相关能力。|  是 | 否 |
| [WorkSchedulerExtensionAbility](../reference/apis-backgroundtasks-kit/js-apis-WorkSchedulerExtensionAbility.md) | 延时任务扩展能力，用于提供[延迟任务](../task-management/work-scheduler.md)的相关能力。      | 是 | 否 |
| [InputMethodExtensionAbility](../reference/apis-ime-kit/js-apis-inputmethod-extension-ability.md) | 输入法扩展能力，用于实现[输入法应用](../inputmethod/ime-kit-intro.md)的开发。      | 是 | 是 |
| [ServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md)| 后台服务扩展能力，提供后台运行并对外提供相应能力。 |否| 否 |
| [AccessibilityExtensionAbility](../reference/apis-accessibility-kit/js-apis-application-accessibilityExtensionAbility.md)|[无障碍服务扩展能力](../accessibility/accessibilityextensionability.md)，支持访问与操作前台界面。| 是| 否 |
| [DataShareExtensionAbility](../reference/apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md)| 数据共享扩展能力，用于对外提供数据读写服务| 否| 否 |
| [StaticSubscriberExtensionAbility](../reference/apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md)|静态广播扩展能力，用于处理静态事件，比如开机事件|否| 否 |
| [WallpaperExtensionAbility](../reference/apis-basic-services-kit/js-apis-WallpaperExtensionAbility-sys.md)|壁纸扩展能力，用于实现桌面壁纸|否| 否 |
| [BackupExtensionAbility](../reference/apis-core-file-kit/js-apis-application-backupExtensionAbility.md) | 数据备份扩展能力，用于提供[备份及恢复应用数据](../file-management/app-file-backup-overview.md)的能力。      | 是 | 否 |
| [WindowExtensionAbility](../reference/apis-arkui/js-apis-application-windowExtensionAbility-sys.md)|界面组合扩展能力，允许系统应用进行跨应用的界面拉起和嵌入。| 否| 否 |
| [EnterpriseAdminExtensionAbility](../reference/apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md)|[企业设备管理扩展能力](../mdm/mdm-kit-admin.md)，提供企业管理时处理管理事件的能力，<br/>比如设备上应用安装事件、锁屏密码输入错误次数过多事件等。|是| 否 |
| [PrintExtensionAbility](../reference/apis-basic-services-kit/js-apis-app-ability-PrintExtensionAbility.md)|文件打印扩展能力，提供应用打印照片、文档等办公场景。|是| 否 |
| [ShareExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-shareExtensionAbility.md) | 分享扩展组件，用于提供分享模板服务扩展的能力。 | 是 | 否 |
| PushExtensionAbility|推送扩展能力，提供推送场景化消息能力。|是| 否 |
| [DriverExtensionAbility](../reference/apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md)   | 驱动扩展能力，用于提供[驱动相关扩展框架](../device/driver/driverextensionability.md)。      | 是 | 否 |
| [ActionExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-actionExtensionAbility.md)|自定义服务扩展能力，为开发者提供基于UIExtension的自定义操作业务模板。|是| 否 |
| [AdsServiceExtensionAbility](../reference/apis-ads-kit/js-apis-adsserviceextensionability.md)|广告服务扩展能力，对外提供后台自定义广告业务服务。|是| 否 |
| [EmbeddedUIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md) | EMBEDDED_UI类型的ExtensionAbility组件，用于提供[跨进程界面嵌入](embeddeduiextensionability.md)的能力。 | 是 | 否 |
|InsightIntentUIExtensionAbility|为开发者提供能被小艺意图调用，以窗口形态呈现内容的扩展能力|是| 否 |
| [FenceExtension](../reference/apis-location-kit/js-apis-app-ability-FenceExtensionAbility.md) | FENCE类型的ExtensionAbility组件，用于提供<!--RP1-->[地理围栏](../device/location/fenceExtensionAbility.md)<!--RP1End-->扩展的能力。 | 是 | 否 |
| AssetAccelerationExtensionAbility|资源预下载扩展能力，提供在设备闲时状态，进行后台资源预下载的能力。|是| 否 |
| [DistributedExtensionAbility](../reference/apis-distributedservice-kit/js-apis-distributedExtensionAbility.md)|提供分布式相关扩展能力，提供分布式创建、销毁、连接的生命周期回调。|是| 否 |


## 访问指定类型的ExtensionAbility组件

所有类型的[ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md)组件均不能被应用直接启动，而是由相应的系统管理服务拉起，以确保其生命周期受系统管控，使用时拉起，使用完销毁。ExtensionAbility组件的调用方无需关心目标ExtensionAbility组件的生命周期。

  以[InputMethodExtensionAbility](../reference/apis-ime-kit/js-apis-inputmethod-extension-ability.md)组件为例进行说明，如下图所示，调用方应用发起对InputMethodExtensionAbility组件的调用，此时将先调用输入法管理服务，由输入法管理服务拉起InputMethodExtensionAbility组件，返回给调用方，同时开始管理其生命周期。

**图1** 使用InputMethodExtensionAbility组件

![ExtensionAbility-start](figures/ExtensionAbility-start.png)


## 实现指定类型的ExtensionAbility组件

以实现卡片[FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md)为例进行说明。卡片框架提供了FormExtensionAbility基类，开发者通过派生此基类（如MyFormExtensionAbility），实现回调（如创建卡片的onCreate()回调、更新卡片的[onUpdateForm()](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#onupdateform)回调等）来实现具体卡片功能，具体见开发指导见[服务卡片](../form/formkit-overview.md)。

卡片FormExtensionAbility实现方不用关心使用方何时去请求添加、删除卡片，FormExtensionAbility实例及其所在的[ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md)进程的整个生命周期，都是由卡片管理系统服务FormManagerService进行调度管理。

![form_extension](figures/form_extension.png)


> **说明：**
> 通常，同一应用内的所有同类型的ExtensionAbility运行在同一独立进程，跟UIAbility组件不在同一进程。有一些例外场景：
> - ServiceExtensionAbility、DataShareExtensionAbility跟UIAbility是同进程的。
> - 部分ExtensionAbility类型可以通过配置[extensionProcessMode](../quick-start/module-configuration-file.md#extensionAbilities标签)实现不同的进程模型。
