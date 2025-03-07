# Introduction to Ability Kit

Ability Kit provides an application model for application development and running. The application model is the abstraction of capabilities required by an application. It provides components and mechanisms required for running the application. You can develop applications based on a unified set of models, which makes your development simpler and more efficient.

## Use Scenarios

- Multi-module development: You can use different types of modules (HAP, HAR, and HSP) to develop an application. The HAP is used to implement application features, and the HAR and HSP are used to share code and resources.
- Intra-application interaction: Redirection is allowed between components of an application. For example, in a payment application, you may need to start the payment UIAbility from the entry UIAbility.
- Inter-application interaction: An application can start another application to complete a task or operation. For example, in an application, you can start a browser application to open a website or a file application to browse or edit a file.
- Cross-device hopping: Your application delivers a better user experience through cross-device migration and multi-device collaboration. For example, you migrate a video playback task from a tablet to a smart TV.

## Capability Scope

- Provides APIs to create or destroy an application process, and schedule the application lifecycle.
- Provides an entry to run application components, schedule the application component lifecycle, and enable interaction between components.
- Provides APIs to listen for application context and system environment changes.
- Provides APIs to continue an application on another device.
- Provides capabilities such as multi-package, shared package, and application information configuration. For details, see [Application Package Overview](../quick-start/application-package-overview.md).
- Provides access control capabilities. For details, see [Access Control Overview](../security/AccessToken/access-token-overview.md).
<!--RP1-->
<!--RP1End-->

## Highlights

1. **Designed for complex applications**
   - In the stage model, multiple application components share an ArkTS engine (VM running the programming language ArkTS) instance. This allows application components to share objects and statuses with less memory required.
   - The object-oriented development mode makes the code of complex applications easy to read, maintain, and scale.
   - Modular development is supported.

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

## Relationship with Related Kits

ArkUI: The UIAbility component of Ability Kit can use the components, events, animations, and status management capabilities provided by ArkUI.

ArkTS: provides language runtime capabilities for Ability Kit.
