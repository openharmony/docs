# ExtensionAbility Component


[ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md) components are application components for specific scenarios. Each ExtensionAbility component corresponds to a specific real-world scenario. For example, [FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md) is used for widget scenarios, [InputMethodExtensionAbility](../reference/apis-ime-kit/js-apis-inputmethod-extension-ability.md) is used for input method scenarios, and [WorkSchedulerExtensionAbility](../reference/apis-backgroundtasks-kit/js-apis-WorkSchedulerExtensionAbility.md) is used for deferred task scenarios. You can use ExtensionAbility components of different types in your application to add new capabilities and interact more deeply with the system or other applications.

All types of ExtensionAbility components are defined by the system and are usually managed by the corresponding system services in a unified manner. For example, the [InputMethodExtensionAbility](../reference/apis-ime-kit/js-apis-inputmethod-extension-ability.md) component is managed by the input method management service. You cannot directly inherit from ExtensionAbility components. Instead, you can only implement or access the provided [ExtensionAbility types](../reference/apis-ability-kit/js-apis-bundleManager.md#extensionabilitytype).

## ExtensionAbility Types

The table below lists the ExtensionAbility types defined in the system.

> **NOTE**
> 
> - The column **Allow Third-Party Apps to Implement** specifies whether third-party applications can inherit from this ExtensionAbility to implement their own service logic.
> - The column **Allow Independent ExtensionAbility Sandbox** specifies whether this ExtensionAbility runs in a sandbox separate from the main application's, preventing direct access between them.

| ExtensionAbility Type                | Description| Allow Third-Party Apps<br>to Implement                 | Allow Independent<br>ExtensionAbility Sandbox|
|--------------------------------------|---------|-------------------------------------------|-----------------------|
| [FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md)  | Provides extended capabilities related to [service widgets](../form/formkit-overview.md).|  Yes| No|
| [WorkSchedulerExtensionAbility](../reference/apis-backgroundtasks-kit/js-apis-WorkSchedulerExtensionAbility.md) | Provides extended capabilities related to [deferred tasks](../task-management/work-scheduler.md).     | Yes| No|
| [InputMethodExtensionAbility](../reference/apis-ime-kit/js-apis-inputmethod-extension-ability.md) | Provides extended capabilities related to [input method applications](../inputmethod/ime-kit-intro.md).     | Yes| Yes|
| <!--Del-->[<!--DelEnd-->ServiceExtensionAbility<!--Del-->](../reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md)<!--DelEnd-->| Provides extended capabilities related to background services.<br>Third-party applications can connect to this ExtensionAbility and communicate with it.|No| No|
| [AccessibilityExtensionAbility](../reference/apis-accessibility-kit/js-apis-application-accessibilityExtensionAbility.md)|Provides extended capabilities related to accessibility services, supporting access and operation of the foreground UI.| Yes| No|
| <!--Del-->[<!--DelEnd-->DataShareExtensionAbility<!--Del-->](../reference/apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md)<!--DelEnd-->| Provides extended capabilities related to data sharing, providing data reading and writing services.<br>Third-party applications can connect to this ExtensionAbility for data reading and writing.| No| No|
|<!--DelRow-->[StaticSubscriberExtensionAbility](../reference/apis-basic-services-kit/js-apis-application-staticSubscriberExtensionAbility-sys.md)|Provides extended capabilities related to static broadcast, used to handle static events such as startup events. Third-party application cannot access this ExtensionAbility.|No| No|
|<!--DelRow-->[WallpaperExtensionAbility](../reference/apis-basic-services-kit/js-apis-WallpaperExtensionAbility-sys.md)|Provides extended capabilities to implement wallpapers displayed on home screen. Third-party application cannot access this ExtensionAbility.|No| No|
| [BackupExtensionAbility](../reference/apis-core-file-kit/js-apis-application-backupExtensionAbility.md) | Provides extended capabilities for [data backup and restore](../file-management/app-file-backup-overview.md).     | Yes| No|
|<!--DelRow-->[WindowExtensionAbility](../reference/apis-arkui/js-apis-application-windowExtensionAbility-sys.md)|Provides extended capabilities that allow system applications to pull up and embed UIs of other applications. Third-party application cannot access this ExtensionAbility.| No| No|
| [EnterpriseAdminExtensionAbility](../reference/apis-mdm-kit/js-apis-EnterpriseAdminExtensionAbility.md)|Provides extended capabilities to handle management events during [enterprise management](../mdm/mdm-kit-admin.md).<br>Example events are application installation events on the device and excessive incorrect lock screen password input events.|Yes| No|
| [PrintExtensionAbility](../reference/apis-basic-services-kit/js-apis-app-ability-PrintExtensionAbility.md)|Provides extended capabilities for printing photos and documents in office scenarios.|Yes| No|
| [ShareExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-shareExtensionAbility.md) | Provides extended capabilities related to the share template service.| Yes| No|
| [DriverExtensionAbility](../reference/apis-driverdevelopment-kit/js-apis-app-ability-driverExtensionAbility.md)   | Provides extended capabilities for [driver development](../device/driver/driverextensionability.md).     | Yes| No|
| [ActionExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-actionExtensionAbility.md)| Provides extended capabilities for custom operation service templates.|Yes| No|
| <!--RP3-->[AdsServiceExtensionAbility](../reference/apis-ads-kit/js-apis-adsserviceextensionability.md)<!--RP3End-->| Provides extended capabilities related to background custom ad services.|Yes| No|
| [EmbeddedUIExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-embeddedUIExtensionAbility.md) | Provides extended capabilities for [UI embedding across processes](embeddeduiextensionability.md).| Yes| No|
| [FenceExtensionAbility](../reference/apis-location-kit/js-apis-app-ability-FenceExtensionAbility.md) | Provides extended capabilities for the <!--RP1-->[geofence](../device/location/fenceExtensionAbility.md)<!--RP1End-->.| Yes| No|
| [DistributedExtensionAbility](../reference/apis-distributedservice-kit/js-apis-distributedExtensionAbility.md)|Provides extended capabilities and lifecycle callbacks for distributed ability creation, destruction, and connection.|Yes| No|
| [AppServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-appServiceExtensionAbility.md) | Provides extended capabilities for the application background service, which provides lifecycle callbacks for creating, destroying, connecting to, and disconnecting from the application background service.| Yes| No|
|<!--DelRow-->[SelectionExtensionAbility](../reference/apis-basic-services-kit/js-apis-selectionInput-selectionExtensionAbility-sys.md) | Provides extended capabilities for the word selection service, which provides lifecycle callbacks for connecting to and disconnecting from the system application background service. Third-party application cannot access this ExtensionAbility.| No| No|
<!--RP2--><!--RP2End-->

> **NOTE**
> 
> Unless otherwise configured, all ExtensionAbility instances of the same type within an application (with the same bundle name) share a single process. Exceptions:
>
> - ServiceExtensionAbility (only for system applications), DataShareExtensionAbility (only for system applications), and all UIAbility instances run in the same independent process (main process).
> - The UIExtensionAbility and its child classes ExtensionAbility can specify a separate process via the [extensionProcessMode](../quick-start/module-configuration-file.md#extensionabilities) field in the **module.json5** file.

## Accessing ExtensionAbility of the Specified Type

Each type of [ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md) component is started by the corresponding system management service, rather than applications, so that its lifecycle is under system control. The caller of the ExtensionAbility component does not need to care about its lifecycle.

The following uses [InputMethodExtensionAbility](../reference/apis-ime-kit/js-apis-inputmethod-extension-ability.md) as an example. As shown in the figure below, when an application calls the InputMethodExtensionAbility component, the input method management service is called first. The input method management service starts the InputMethodExtensionAbility component, returns the component to the application, and starts to manage its lifecycle.

**Figure 1** Using the InputMethodExtensionAbility component

![ExtensionAbility-start](figures/ExtensionAbility-start.png)


## Implementing ExtensionAbility of the Specified Type

The following uses [FormExtensionAbility](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md) as an example. The widget framework provides the base class **FormExtensionAbility**. You can derive this base class to create your own class (for example, **MyFormExtensionAbility**) and implement the callbacks, such as **onCreate()** and [onUpdateForm()](../reference/apis-form-kit/js-apis-app-form-formExtensionAbility.md#formextensionabilityonupdateform), to provide specific widget features. For details, see [Service Widget](../form/formkit-overview.md).

You do not need to care when to add or delete a widget. The lifecycle of the FormExtensionAbility instance and the lifecycle of the [ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md) process where the FormExtensionAbility instance is located are scheduled and managed by FormManagerService.

![form_extension](figures/form_extension.png)

<!--no_check-->