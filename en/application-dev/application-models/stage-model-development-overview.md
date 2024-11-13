# Stage Model Development Overview


## Basic Concepts

The following figure illustrates the stage model.

**Figure 1** Stage model

![stage-concepts](figures/stage-concepts.png)


- [AbilityStage](abilitystage.md)

  Each [HAP](../quick-start/hap-package.md) of the Entry or Feature type has an instance of the **AbilityStage** class at runtime. When the code in the [HAP](../quick-start/hap-package.md) is loaded to a process for the first time, the system creates an **AbilityStage** instance first.
  
- [UIAbility](uiability-overview.md) and [ExtensionAbility](extensionability-overview.md) components
  
  The stage model provides two types of application components: UIAbility and ExtensionAbility. Both have specific classes and support object-oriented development.
  
  - UIAbility is a type of application component that provides the UI for user interaction. For example, with UIAbility, the Gallery application can display images in the liquid layout. After a user selects an image, it uses a new UI to display the image details. The user can touch the **Back** button to return to the liquid layout. The lifecycle of the UIAbility component contains the **Create**, **Destroy**, **Foreground**, and **Background** states. Display-related states are exposed through WindowStage events.
  
  - ExtensionAbility is used for specific scenarios. You cannot derive directly from ExtensionAbility. Instead, use the derived classes of ExtensionAbility for your scenarios, such as FormExtensionAbility for widget scenarios, InputMethodExtensionAbility for input method scenarios, and WorkSchedulerExtensionAbility for deferred task scenarios. For example, to enable a user to create an application widget on the home screen, you must derive a class from FormExtensionAbility, implement callbacks, and configure the capability in the configuration file. The derived class instances are created by applications and their lifecycles are managed by the system. In the stage model, you must use the derived classes of ExtensionAbility to develop custom services of third-party applications based on your service scenarios.
- [WindowStage](../windowmanager/application-window-stage.md)

  Each UIAbility instance is bound to a WindowStage instance, which functions as the window manager in the application process. The WindowStage class instance contains a main window. That is, a UIAbility instance holds a main window through WindowStage, and this window provides a rendering area for ArkUI.

- [Context](application-context-stage.md)

  In the stage model, Context and its derived classes provide a variety of resources and capabilities that can be called during the runtime. The UIAbility component and ExtensionAbility derived classes have different Context classes. These classes, which all inherit from the base class Context, provide different capabilities.




## How to Develop

During application development based on the stage model, the following tasks are involved in the application model.

**Table 1** Stage model development process

| Task| Description| Guide|
| -------- | -------- | -------- |
| Application component development| Use the UIAbility and ExtensionAbility components of the stage model to develop your application.| - [Application- or Component-Level Configuration](application-component-configuration-stage.md)<br>- [UIAbility Component](uiability-overview.md)<br>- [ExtensionAbility Component](extensionability-overview.md)<br>- [AbilityStage Container Component](abilitystage.md)<br>- [Context](application-context-stage.md)<br>- [Component Startup Rules](component-startup-rules.md)|
| Process model development| Learn the process model and common IPC modes of the stage model.| [Process Model Overview](process-model-stage.md)|
| Thread model development| Learn the thread model and common inter-thread communication modes of the stage model.| [Thread Model Overview](thread-model-stage.md)|
| Configuration file development| Learn the requirements for developing application configuration files in the stage model.| [Application Configuration File](config-file-stage.md)|
