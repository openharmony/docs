# ExtensionAbility组件
<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yewei0794-->
<!--Designer: @jsjzju-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->


[ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md)组件是一种面向特定场景的应用组件。每一个具体场景对应一个不同类型的ExtensionAbility，例如用于卡片场景的[FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md)，用于输入法场景的[InputMethodExtensionAbility](../reference/apis-ime-kit/js-apis-inputmethod-extension-ability.md)，用于延时任务场景的[WorkSchedulerExtensionAbility](../reference/apis-backgroundtasks-kit/js-apis-WorkSchedulerExtensionAbility.md)等。开发者通过使用不同类型的ExtensionAbility组件，可以扩展和丰富应用功能，更好地与其他应用或系统开展交互。

不同类型ExtensionAbility组件均由系统定义，且通常由相应的系统服务统一管理（例如[InputMethodExtensionAbility](../reference/apis-ime-kit/js-apis-inputmethod-extension-ability.md)组件由输入法管理服务统一管理）。开发者不能直接继承ExtensionAbility组件，只能使用（包括实现或访问）已定义的[ExtensionAbility类型](../reference/apis-ability-kit/js-apis-bundleManager.md#extensionabilitytype)。

## ExtensionAbility类型说明

当前系统已定义的ExtensionAbility类型如下表所示。

> **说明：**
> 
> - “是否允许三方应用实现”是指：三方应用能否继承该类型ExtensionAbility实现自己的业务逻辑。
> - “是否有独立Extension沙箱”是指：该类型ExtensionAbility的沙箱是否与主应用沙箱相对独立、不可互相访问。

| ExtensionAbility类型                 | 功能描述 | 是否允许三<br/>方应用实现                  | 是否有独立<br/>Extension沙箱 |
|--------------------------------------|---------|-------------------------------------------|-----------------------|
| [FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md)  | 卡片扩展能力，用于提供[服务卡片](../form/formkit-overview.md)的相关能力。|  是 | 否 |
| [WorkSchedulerExtensionAbility](../reference/apis-backgroundtasks-kit/js-apis-WorkSchedulerExtensionAbility.md) | 延时任务扩展能力，用于提供[延迟任务](../task-management/work-scheduler.md)的相关能力。      | 是 | 否 |
| [InputMethodExtensionAbility](../reference/apis-ime-kit/js-apis-inputmethod-extension-ability.md) | 输入法扩展能力，用于实现[输入法应用](../inputmethod/ime-kit-intro.md)的开发。      | 是 | 是 |
| <!--Del-->[<!--DelEnd-->ServiceExtensionAbility<!--Del-->](../reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md)<!--DelEnd-->| 后台服务扩展能力，提供后台运行并对外提供相应能力。<br/>三方应用可以连接该ExtensionAbility，并进行通信。 |否| 否 |
| [AccessibilityExtensionAbility](../reference/apis-accessibility-kit/js-apis-application-accessibilityExtensionAbility.md)|无障碍服务扩展能力，支持访问与操作前台界面。| 是| 否 |
| <!--Del-->[<!--DelEnd-->DataShareExtensionAbility<!--Del-->](../reference/apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md)<!--DelEnd-->| 数据共享扩展能力，用于对外提供数据读写服务。<br/>三方应用可以连接该ExtensionAbility，进行数据读写。| 否| 否 |
|<!--DelRow-->[StaticSubscriberExtensionAbility](../reference/apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md)|静态广播扩展能力，用于处理静态事件，比如开机事件。三方应用无法访问。|否| 否 |
|<!--DelRow-->[WallpaperExtensionAbility](../reference/apis-basic-services-kit/js-apis-WallpaperExtensionAbility-sys.md)|壁纸扩展能力，用于实现桌面壁纸。三方应用无法访问。|否| 否 |
| [BackupExtensionAbility](../reference/apis-core-file-kit/js-apis-application-backupExtensionAbility.md) | 数据备份扩展能力，用于提供[备份及恢复应用数据](../file-management/app-file-backup-overview.md)的能力。      | 是 | 否 |
|<!--DelRow-->[WindowExtensionAbility](../reference/apis-arkui/js-apis-application-windowExtensionAbility-sys.md)|界面组合扩展能力，允许系统应用进行跨应用的界面拉起和嵌入。三方应用无法访问。| 否| 否 |
| [EnterpriseAdminExtensionAbility](../reference/apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md)|[企业设备管理扩展能力](../mdm/mdm-kit-admin.md)，提供企业管理时处理管理事件的能力，<br/>比如设备上应用安装事件、锁屏密码输入错误次数过多事件等。|是| 否 |
| [PrintExtensionAbility](../reference/apis-basic-services-kit/js-apis-app-ability-PrintExtensionAbility.md)|文件打印扩展能力，提供应用打印照片、文档等办公场景。|是| 否 |
| [ShareExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-shareExtensionAbility.md) | 分享扩展组件，用于提供分享模板服务扩展的能力。 | 是 | 否 |
| [DriverExtensionAbility](../reference/apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md)   | 驱动扩展能力，用于提供[驱动相关扩展框架](../device/driver/driverextensionability.md)。      | 是 | 否 |
| [ActionExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-actionExtensionAbility.md)| 自定义服务扩展能力，为开发者提供基于UIExtension的自定义操作业务模板。|是| 否 |
| <!--RP3-->[AdsServiceExtensionAbility](../reference/apis-ads-kit/js-apis-adsserviceextensionability.md)<!--RP3End-->| 广告服务扩展能力，对外提供后台自定义广告业务服务。|是| 否 |
| [EmbeddedUIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md) | 嵌入式UI扩展能力，提供[跨进程界面嵌入](embeddeduiextensionability.md)的能力。 | 是 | 否 |
| [FenceExtensionAbility](../reference/apis-location-kit/js-apis-app-ability-FenceExtensionAbility.md) | 地理围栏扩展能力，用于提供<!--RP1-->[地理围栏](../device/location/fenceExtensionAbility.md)<!--RP1End-->扩展的能力。 | 是 | 否 |
| [DistributedExtensionAbility](../reference/apis-distributedservice-kit/js-apis-distributedExtensionAbility.md)|分布式扩展能力，提供分布式创建、销毁、连接的生命周期回调。|是| 否 |
| [AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md) | 应用后台服务扩展能力，提供应用后台服务的创建、销毁、连接、断开等生命周期回调。 | 是 | 否 |
|<!--DelRow-->[SelectionExtensionAbility](../reference/apis-basic-services-kit/js-apis-selectionInput-selectionExtensionAbility-sys.md) | 划词扩展能力，提供系统应用后台服务的连接和断开等生命周期回调。三方应用无法访问。 | 否 | 否 |
| [FaultLogExtensionAbility](../reference/apis-performance-analysis-kit/js-apis-hiviewdfx-FaultLogExtensionAbility.md) | 提供故障延迟通知的能力。| 是 | 否 |
| [WebNativeMessagingExtensionAbility](../reference/apis-arkweb/arkts-apis-web-webNativeMessagingExtensionAbility.md) | Web插件对接能力。提供插件对接native应用能力。 | 是 | 否 |
<!--RP2--><!--RP2End-->

> **说明：**
> 
> 通常情况下，应用中（同一Bundle名称）所有同一类型的ExtensionAbility均运行在同一个独立进程。以下为例外场景：
>
> - ServiceExtensionAbility（仅系统应用涉及）、DataShareExtensionAbility（仅系统应用涉及）与所有UIAbility均运行在同一个独立进程（主进程）。
> - UIExtensionAbility以及继承该类型的ExtensionAbility可以通过module.json5配置文件中的[extensionProcessMode](../quick-start/module-configuration-file.md#extensionabilities标签)字段，配置进程运行模式。

## 访问指定类型的ExtensionAbility组件

所有类型的[ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md)组件均不能被应用直接启动，而是由相应的系统管理服务拉起，以确保其生命周期受系统管控，使用时拉起，使用完销毁。ExtensionAbility组件的调用方无需关心目标ExtensionAbility组件的生命周期。

  以[InputMethodExtensionAbility](../reference/apis-ime-kit/js-apis-inputmethod-extension-ability.md)组件为例进行说明，如下图所示，调用方应用发起对InputMethodExtensionAbility组件的调用，此时将先调用输入法管理服务，由输入法管理服务拉起InputMethodExtensionAbility组件，返回给调用方，同时开始管理其生命周期。

**图1** 使用InputMethodExtensionAbility组件

![ExtensionAbility-start](figures/ExtensionAbility-start.png)


## 实现指定类型的ExtensionAbility组件

以实现卡片[FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md)为例进行说明。卡片框架提供了FormExtensionAbility基类，开发者通过派生此基类（如MyFormExtensionAbility），实现回调（如创建卡片的onCreate()回调、更新卡片的[onUpdateForm()](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform)回调等）来实现具体卡片功能，具体见开发指导见[服务卡片](../form/formkit-overview.md)。

卡片FormExtensionAbility实现方不用关心使用方何时去请求添加、删除卡片，FormExtensionAbility实例及其所在的[ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md)进程的整个生命周期，都是由卡片管理系统服务FormManagerService进行调度管理。

![form_extension](figures/form_extension.png)
