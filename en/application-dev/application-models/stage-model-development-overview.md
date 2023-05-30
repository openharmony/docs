# Stage Model Development Overview


## Basic Concepts

The following figure shows the basic concepts used in the stage model.

**Figure 1** Concepts used in the stage model 
![stage-concepts](figures/stage-concepts.png)

- [UIAbility component](uiability-overview.md) and [ExtensionAbility component](extensionability-overview.md)
  
  The stage model provides two types of application components: UIAbility and ExtensionAbility. Both have specific classes and support object-oriented development.
  
  - UIAbility is a type of application component that provides the UI for user interaction. For example, with UIAbility, the Gallery application can display images in the liquid layout. After a user selects an image, it uses a new UI to display the image details. The user can touch the **Back** button to return to the liquid layout. The lifecycle of the UIAbility component contains the creation, destruction, foreground, and background states. Display-related states are exposed through WindowStage events.
  
  - ExtensionAbility is oriented to specific scenarios. You cannot derive directly from ExtensionAbility. Instead, use the derived classes of ExtensionAbility for your scenarios, such as FormExtensionAbility for widget scenarios, InputMethodExtensionAbility for input method scenarios, and WorkSchedulerExtensionAbility for Work Scheduled task scenarios. For example, to enable a user to create an application widget on the home screen, you must derive FormExtensionAbility, implement the callback functions, and configure the capability in the configuration file. The derived class instances are created by developers and their lifecycles are managed by the system. In the stage model, you must use the derived classes of ExtensionAbility to develop custom services based on your service scenarios.
- [WindowStage](../windowmanager/application-window-stage.md)

  Each UIAbility class instance is bound to a WindowStage class instance, which functions as the window manager in the application process. The WindowStage class instance contains a main window. That is, UIAbility holds a main window through WindowStage, and this window provides an area for ArkUI to render.

- [Context](application-context-stage.md)

  In the stage model, Context and its derived classes provide a variety of resources and capabilities that can be called during the runtime. The UIAbility component and ExtensionAbility derived classes have different Context classes. These classes, which all inherit from the base class Context, provide different capabilities.

- [AbilityStage](abilitystage.md)

  Each HAP of the Entry or Feature type has an AbilityStage class instance during the runtime. When the code in the HAP is loaded to the process for the first time, the system creates an AbilityStage class instance first. Each UIAbility class defined in the HAP is associated with this class instance after instantiation. Through this class instance, you can obtain the runtime information of the UIAbility instances in the HAP.


## How to Develop

During application development based on the stage model, the following tasks are involved in the application model.

**Table 1** Stage model development process

| Task| Introduction| Guide|
| -------- | -------- | -------- |
| Application component development| Use the UIAbility and ExtensionAbility components of the stage model to develop applications.| - [Application- or Component-Level Configuration](application-component-configuration-stage.md)<br>- [UIAbility Component](uiability-overview.md)<br>- [ExtensionAbility Component](extensionability-overview.md)<br>- [AbilityStage Container Component](abilitystage.md)<br>- [Context](application-context-stage.md)<br>- [Component Startup Rules](component-startup-rules.md)|
| Process model| Learn the process model and common IPC modes of the stage model.| - [Common Events](common-event-overview.md)<br>- [Background Services](background-services.md)|
| Thread model| Learn the thread model and common inter-thread communication modes of the stage model.| - [Emitter](itc-with-emitter.md)<br>- [Worker](itc-with-worker.md)|
| Mission management| Learn the basic concepts and typical scenarios of mission management in the stage model.| - [Mission Management Scenarios](mission-management-overview.md)<br>- [Mission Management and Launch Type](mission-management-launch-type.md)<br>- [Page Stack and Mission List](page-mission-stack.md)|
| Application configuration file| Learn the requirements for developing application configuration files in the stage model.| [Application Configuration File](config-file-stage.md)|
