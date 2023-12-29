# Interpretation of the Application Model


## Application Model Overview

Along its evolution, the system has provided two application models:

- Feature Ability (FA) model: This model is supported by API versions 7 and 8, and no longer recommended.

- Stage model: This model is supported since API version 9. It is the mainstream model with a long evolution plan. In this model, classes such as **AbilityStage** and **WindowStage** are provided as the stage of application components and windows. That's why it is named stage model.

The stage model is designed based on the following considerations:  

1. **Designed for complex applications**
   - In the stage model, multiple application components share an ArkTS engine (VM running the programming language ArkTS) instance. This allows application components to share objects and statuses with less memory required.
   - The object-oriented development mode makes the code of complex applications easy to read, maintain, and scale.

2. **Native support for cross-device migration and multi-device collaboration at the application component level**

   The stage model decouples application components from User Interfaces (UIs).

   - The declarative feature of ArkUI allows the UI to be restored based on the data or status saved in application components, which facilitates cross-device migration.

   - Application components support cross-device interaction over Remote Procedure Calls (RPCs).

3. **Support for multiple device types and window forms**

   Application component management and window management are decoupled at the architecture level. This decoupling makes it easy to:

   - Tailor application components. For example, windows can be tailored for devices without screens.

   - Extend the window forms.

   - Use the same application component lifecycle on multiple devices (such as desktop devices and mobile devices).

4. **Well balanced application capabilities and system management costs**

   The stage model redefines the boundary of application capabilities to well balance application capabilities and system management costs.

   - Diverse application components (such as service widgets and input methods) for specific scenarios.
   - Standardized background process management. To deliver a better user experience, the stage model manages background application processes in a more orderly manner. Applications cannot reside in the background randomly, and their background behavior is strictly managed to minimize malicious behavior.


## Differences Between the FA Model and Stage Model

In the FA model, each application component exclusively uses an ArkTS engine instance. However, in the stage model, multiple application components share the same ArkTS engine instance. This allows application components to share objects and statuses with less memory required. With the stage model, you can easily develop complex applications in distributed scenarios.

The table below describes their differences in detail.

**Table 1** Differences between the FA model and stage model

| Item| FA model| Stage model|
| -------- | -------- | -------- |
| **Application component**| 1. Component classification<br>![fa-model-component](figures/fa-model-component.png)<br>- PageAbility: supports user interaction via the UI. For details, see [PageAbility Component Overview](pageability-overview.md).<br>- ServiceAbility: provides background services without the UI. For details, see [ServiceAbility Component Overview](serviceability-overview.md).<br>- DataAbility: provides the data sharing capability without the UI. For details, see [DataAbility Component Overview](dataability-overview.md).<br>2. Development mode<br>Application components are specified by exporting anonymous objects and fixed entry files. You cannot perform derivation. It is inconvenient for capability expansion.| 1. Component classification<br>![stage-model-component](figures/stage-model-component.png)<br>- UIAbility: supports user interaction with the UI. For details, see [UIAbility Component Overview](uiability-overview.md).<br>- ExtensionAbility: provides scenario-specific extension capabilities (such as widget and input methods). For details, see [ExtensionAbility Component Overview](extensionability-overview.md).<br>2. Development mode<br>The object-oriented mode is used to provide open application components as classes. You can derive application components for capability expansion.|
| **Process model**| There are two types of processes:<br>1. Main process<br>2. Render process<br>For details, see [Process Model](process-model-fa.md).| There are three types of processes:<br>1. Main process<br>2. ExtensionAbility process<br>3. Render process<br>For details, see [Process Model](process-model-stage.md).|
| **Thread model**| 1. ArkTS engine instance creation<br>A process can run multiple application component instances, and each application component instance runs in an independent ArkTS engine instance.<br>2. Thread model<br>Each ArkTS engine instance is created on an independent thread (non-main thread). The main thread does not have an ArkTS engine instance.<br>3. Intra-process object sharing: not supported.<br>For details, see [Thread Model](thread-model-fa.md).| 1. ArkTS engine instance creation<br>A process can run multiple application component instances, and all application component instances share one ArkTS engine instance.<br>2. Thread model<br>The ArkTS engine instance is created on the main thread.<br>3. Intra-process object sharing: supported.<br>For details, see [Thread Model](thread-model-stage.md).|
| **Mission management model**| - A mission is created for each PageAbility component instance.<br>- Missions are stored persistently until they are deleted by users or the number of missions exceeds the maximum (customized based on the product configuration).<br>- PageAbility components do not form a stack structure.<br>For details, see [Mission Management Scenarios](mission-management-overview.md).| - A mission is created for each UIAbility component instance.<br>- Missions are stored persistently until they are deleted by users or the number of missions exceeds the maximum (customized based on the product configuration).<br>- UIAbility components do not form a stack structure.<br>For details, see [Mission Management Scenarios](mission-management-overview.md).|
| **Configuration file**| The **config.json** file contains the application, HAP, and application component information.<br>For details, see [Application Configuration File Overview (FA Model)](../quick-start/application-configuration-file-overview-fa.md).| The **app.json5** file contains the application information, and the **module.json5** file contains the HAP and application component information.<br>For details, see [Application Configuration File Overview (Stage Model)](../quick-start/application-configuration-file-overview-stage.md).|
