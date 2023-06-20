# ExtensionAbility Overview


The ExtensionAbility component is used for specific scenarios such as widget development and input method development.


An [ExtensionAbility type](../reference/apis/js-apis-bundleManager.md#extensionabilitytype) is provided for every specific scenario. All types of ExtensionAbility components are managed by the corresponding system services in a unified manner. For example, the InputMethodExtensionAbility component is managed by the input method management service. The following ExtensionAbility types are supported:


- [FormExtensionAbility](../reference/apis/js-apis-app-form-formExtensionAbility.md): ExtensionAbility component of the form type, which provides APIs related to widgets.

- [WorkSchedulerExtensionAbility](../reference/apis/js-apis-WorkSchedulerExtensionAbility.md): ExtensionAbility component of the work_scheduler type, which provides callbacks for Work Scheduler tasks.

- [InputMethodExtensionAbility](../reference/apis/js-apis-inputmethod.md): ExtensionAbility component of the input_method type, which is used to develop input method applications.

- [ServiceExtensionAbility](../reference/apis/js-apis-app-ability-serviceExtensionAbility.md): ExtensionAbility component of the service type, which provides APIs related to background services.

- [AccessibilityExtensionAbility](../reference/apis/js-apis-application-accessibilityExtensionAbility.md): ExtensionAbility component of the accessibility type, which provides APIs related to the accessibility feature.

- [DataShareExtensionAbility (for system applications only)](../reference/apis/js-apis-application-dataShareExtensionAbility.md): ExtensionAbility component of the data_share type, which provides APIs for data sharing.

- [StaticSubscriberExtensionAbility](../reference/apis/js-apis-application-staticSubscriberExtensionAbility.md): ExtensionAbility component of the static_subscriber type, which provides APIs for static broadcast.

- [WindowExtensionAbility (for system applications only)](../reference/apis/js-apis-application-windowExtensionAbility.md): ExtensionAbility component of the window type, which allows a system application to be embedded in and displayed over another application.

- [EnterpriseAdminExtensionAbility](../reference/apis/js-apis-EnterpriseAdminExtensionAbility.md): ExtensionAbility component of the enterprise_admin type, which provides APIs for processing enterprise management events, such as application installation events on devices and events indicating too many incorrect screen-lock password attempts.

> **NOTE**
> 
>- Third-party applications cannot implement ServiceExtensionAbility, DataShareExtensionAbility, StaticSubscriberExtensionAbility, or WindowExtensionAbility. They can use other types of ExtensionAbility components that have been defined.
> 
>- To implement transaction processing in the background for a third-party application, use background tasks rather than ServiceExtensionAbility. For details, see [Background Task](../task-management/background-task-overview.md).


## Using ExtensionAbility of the Specified Type

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
>
> For example, if an application has one UIAbility component, one ServiceExtensionAbility component, one DataShareExtensionAbility component, two FormExtensionAbility components, and one ImeExtensionAbility component, there will be three processes when the application is running.
>
> - UIAbility, ServiceExtensionAbility, and DataShareExtensionAbility run in an independent process.
>
> - The two FormExtensionAbility components run in an independent process.
>
> - The two ImeExtensionAbility components run in an independent process.
