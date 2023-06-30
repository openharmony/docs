# Interpretation of the Application Model


## Application Model Overview

Along its evolution, OpenHarmony has provided two application models:

- Feature Ability (FA) model. This model is supported by OpenHarmony API version 7 and 8. It is no longer recommended.

- Stage model. This model is supported since OpenHarmony API version 9. It is recommended and will evolve for a long time. In this model, classes such as **AbilityStage** and **WindowStage** are provided as the stage of application components and windows. That's why it is named stage model.

The stage model is designed based on the following considerations, which make it become the recommended model:

1. **Designed for complex applications**
   - In the stage model, multiple application components share an ArkTS engine (VM running the programming language ArkTS) instance, making it easy for application components to share objects and status while requiring less memory.
   - The object-oriented development mode makes the code of complex applications easy to read, maintain, and scale.

2. **Native support for [cross-device migration](hop-cross-device-migration.md) and [multi-device collaboration](hop-multi-device-collaboration.md) at the application component level**

   The stage model decouples application components from User Interfaces (UIs).

   - In cross-device migration scenarios, after the system migrates application component data or status between devices, it can use the declarative feature of ArkUI to restore the UI based on the data or status saved in the application components.

   - In multi-device collaboration scenarios, application components can initiate Remote Procedure Calls (RPCs) and support interaction with cross-device application components.

3. **Support for multiple device types and window forms**

   Application component management and window management are decoupled at the architecture level. This decoupling makes it:

   - Easy to tailor application components. For example, windows can be tailored for devices without screens.

   - Easy to extend the window forms.

   - Possible for application components to use the same lifecycle on multiple devices (such as desktop devices and mobile devices).

4. **Well balanced application capabilities and system management costs**

   The stage model redefines the boundary of application capabilities to well balance application capabilities and system management costs.

   - Diverse application components (such as service widgets and input methods) for specific scenarios.
   - Standardized background process management. To deliver a better user experience, the stage model manages background application processes in a more orderly manner. Applications cannot reside in the background randomly, and their background behavior is strictly managed to minimize malicious behavior.


## Differences Between the FA Model and Stage Model

In the stage model, multiple application components share the same ArkTS engine instance. In the FA model, each application component exclusively uses an ArkTS engine instance. This is their biggest difference. In the stage model, application components can easily share objects and status while requiring less memory. Therefore, you are advised to use the stage model when developing complex applications in distributed scenarios.

The table below describes their differences in detail.

**Table 1** Differences between the FA model and stage model

| Item| FA model| Stage model|
| -------- | -------- | -------- |
| **Application component**| 1. Component classification<br>![fa-model-component](figures/fa-model-component.png)<br>- PageAbility: has the UI and supports user interaction For details, see [PageAbility Component Overview](pageability-overview.md).<br>- ServiceAbility: provides background services and has no UI. For details, see [ServiceAbility Component Overview](serviceability-overview.md).<br>- DataAbility: provides the data sharing capability and has no UI. For details, see [DataAbility Component Overview](dataability-overview.md).<br>2. Development mode<br>Application components are specified by exporting anonymous objects and fixed entry files. You cannot perform derivation. It is inconvenient for capability expansion.| 1. Component classification<br>![stage-model-component](figures/stage-model-component.png)<br>- UIAbility: has the UI and supports user interaction. For details, see [UIAbility Component Overview](uiability-overview.md).<br>- ExtensionAbility: provides extension capabilities (such as widget and input methods) for specific scenarios. For details, see [ExtensionAbility Component Overview](extensionability-overview.md).<br>2. Development mode<br>The object-oriented mode is used to provide open application components as classes. You can derive application components for capability expansion.|
| **Process model**| There are two types of processes:<br>1. Main process<br>2. Rendering process<br>For details, see [Process Model Overview (FA Model)](process-model-fa.md). | There are three types of processes:<br>1. Main process<br>2. ExtensionAbility process<br>3. Rendering process<br>For details, see [Process Model Overview (Stage Model)](process-model-stage.md). |
| **Thread model**| 1. ArkTS engine instance creation<br>A process can run multiple application component instances, and each application component instance runs in an independent ArkTS engine instance.<br>2. Thread model<br>Each ArkTS engine instance is created on an independent thread (non-main thread). The main thread does not have an ArkTS engine instance.<br>3. Intra-process object sharing: not supported.<br>For details, see [Thread Model Overview (FA Model)](thread-model-fa.md). | 1. ArkTS engine instance creation<br>A process can run multiple application component instances, and all application component instances share one ArkTS engine instance.<br>2. Thread model<br>The ArkTS engine instance is created on the main thread.<br>3. Intra-process object sharing: supported.<br>For details, see [Thread Model Overview (Stage Model)](thread-model-stage.md). |
| **Mission management model**| - A mission is created for each PageAbility component instance.<br>- Missions are stored persistently until the number of missions exceeds the maximum (customized based on the product configuration) or users delete missions.<br>- PageAbility components do not form a stack structure.<br>For details, see [Mission Management Scenarios](mission-management-overview.md).| - A mission is created for each UIAbility component instance.<br>- Missions are stored persistently until the number of missions exceeds the maximum (customized based on the product configuration) or users delete missions.<br>- UIAbility components do not form a stack structure.<br>For details, see [Mission Management Scenarios](mission-management-overview.md).|
| **Application configuration file**| The **config.json** file is used to describe the application, HAP, and application component information.<br>For details, see [Application Configuration File Overview (FA Model)](../quick-start/application-configuration-file-overview-fa.md).| The **app.json5** file is used to describe the application information, and the **module.json5** file is used to describe the HAP and application component information.<br>For details, see [Application Configuration File Overview (Stage Model)](../quick-start/application-configuration-file-overview-stage.md).|
