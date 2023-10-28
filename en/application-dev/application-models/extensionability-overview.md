# ExtensionAbility Overview


The ExtensionAbility component is used for specific scenarios such as widget development and input method development.


The system defines an [ExtensionAbility type](../reference/apis/js-apis-bundleManager.md#extensionabilitytype) for every specific scenario. You can use (implement and access) only the types that have been defined. All types of ExtensionAbility components are managed by the corresponding system services in a unified manner. For example, the InputMethodExtensionAbility component is managed by the input method management service.

The table below lists the ExtensionAbility types defined in the system.

**NOTE**

- The column **Allow Third-Party Apps to Implement** specifies whether third-party applications can inherit the **ExtensionAbility** parent class and implement their own service logic for a type of ExtensionAbility. The value **Y** means that third-party applications can implement their own service logic for a type of ExtensionAbility, **N** means the opposite.
- The column **Allow Third-Party Apps to Access** specifies whether third-party applications can access external services provided by a type of ExtensionAbility. The value **Y** means that third-party applications can access external services provided by a certain type of ExtensionAbility, **N** means that they cannot access external services, and **NA** means that no external services are provided.

System applications are not restricted. They can implement all the ExtensionAbility types defined in the system and access external services provided by all the ExtensionAbility types.

| Supported ExtensionAbility Type                | Description| Allow Third-Party Apps to Implement                 | Allow Third-Party Apps to Access                                                |
| ------------------------ | -------- | ------------------------------------------------------------ | ------------------------------------------------------------ |
| [FormExtensionAbility](../reference/apis/js-apis-app-form-formExtensionAbility.md)                 | ExtensionAbility component of the form type, which provides APIs related to [widgets](service-widget-overview.md).     | Y | N |
| [WorkSchedulerExtensionAbility](../reference/apis/js-apis-WorkSchedulerExtensionAbility.md) | ExtensionAbility component of the work_scheduler type, which provides callbacks for [deferred tasks](../task-management/work-scheduler.md).     | Y | NA |
| [InputMethodExtensionAbility](../reference/apis/js-apis-inputmethod.md) | ExtensionAbility component of the input_method type, which is used to develop [input method applications](inputmethodextentionability.md).     | Y | Y |
| [AccessibilityExtensionAbility](../reference/apis/js-apis-application-accessibilityExtensionAbility.md) | ExtensionAbility component of the accessibility type, which provides APIs related to the [accessibility feature](accessibilityextensionability.md).     | Y | NA |
| [ServiceExtensionAbility](../reference/apis/js-apis-app-ability-serviceExtensionAbility.md) | ExtensionAbility component of the service type, which provides APIs related to [background services](serviceextensionability.md) for system applications. To implement background transaction processing for non-system applications, use [background tasks](../task-management/background-task-overview.md).     | N | Y |
| [DataShareExtensionAbility](../reference/apis/js-apis-application-dataShareExtensionAbility.md) | ExtensionAbility component of the data_share type, which provides APIs for [data sharing](../database/share-data-by-datashareextensionability.md).     | N | Y |
| [StaticSubscriberExtensionAbility](../reference/apis/js-apis-application-staticSubscriberExtensionAbility.md) | ExtensionAbility component of the static_subscriber type, which provides APIs for [static subscription to common events](common-event-static-subscription.md).     | N | NA |
| [WindowExtensionAbility](../reference/apis/js-apis-application-windowExtensionAbility.md) | ExtensionAbility component of the window type, which provides [window extension](windowextensionability.md) APIs for system applications so that a system application can be embedded in and displayed over another application.     | N | NA |
| [EnterpriseAdminExtensionAbility](../reference/apis/js-apis-EnterpriseAdminExtensionAbility.md)            | ExtensionAbility component of the enterprise_admin type, which provides APIs for managing [enterprise device events](enterprise-extensionAbility.md), such as application installation events on devices and events indicating too many incorrect screen-lock password attempts.     | N | NA|
| [DriverExtensionAbility](../reference/apis/js-apis-app-ability-driverExtensionAbility.md)            | ExtensionAbility component of the driver type, which provides the [driver-related extension framework](driverextensionability.md).     | Y | Y |



## Accessing ExtensionAbility of the Specified Type

Each type of ExtensionAbility component is started by the corresponding system management service, rather than applications, so that its lifecycle is under system control. The caller of the ExtensionAbility component does not need to care about its lifecycle.

The following uses [InputMethodExtensionAbility](../reference/apis/js-apis-inputmethod.md) as an example. As shown in the figure below, when an application calls the InputMethodExtensionAbility component, the input method management service is called first. The input method management service starts the InputMethodExtensionAbility component, returns the component to the application, and starts to manage its lifecycle.

**Figure 1** Using the InputMethodExtensionAbility component

![ExtensionAbility-start](figures/ExtensionAbility-start.png)


## Implementing ExtensionAbility of the Specified Type

The following uses [FormExtensionAbility](../reference/apis/js-apis-app-form-formExtensionAbility.md) as an example. The widget framework provides the base class [FormExtensionAbility](../reference/apis/js-apis-app-form-formExtensionAbility.md). You can derive this base class to create your own class (for example, **MyFormExtensionAbility**) and implement the callbacks, such as **onCreate()** and **onUpdateForm()**, to provide specific widget features. For details, see [FormExtensionAbility](service-widget-overview.md).

You do not need to care when to add or delete a widget. The lifecycle of the FormExtensionAbility instance and the lifecycle of the ExtensionAbility process where the FormExtensionAbility instance is located are managed by FormManagerService.

![form_extension](figures/form_extension.png)


> **NOTE**
>
> For an application, all ExtensionAbility components of the same type run in an independent process, whereas the UIAbility, ServiceExtensionAbility, and DataShareExtensionAbility components run in another independent process. For details, see [Process Model (Stage Model)](process-model-stage.md).
