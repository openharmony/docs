# Stage Model Overview

## Design Ideas

The stage model is designed to provide a better application development mode in the distributed environment.

The following figure shows the design ideas of the stage model.

![stagedesign](figures/stagedesign.png)

The stage model is designed based on the following considerations:

- Efficient management of application processes

   As the device memory becomes larger, the number of processes concurrently running in the system increases. If the number of concurrent processes reaches several hundreds, the overall power consumption and performance of the system will be adversely affected without effective management measures. To restrict the behavior of background processes, the stage model uses four measures: transient task, continuous task, agent task, and Work Scheduler task. With these measures, foreground processes will obtain guaranteed resources, thereby delivering a better user experience.

- Native support for cross-device migration and multi-device collaboration

   OpenHarmony is a native distributed OS. Its application framework must be designed for easier component migration and collaboration across devices. The stage model achieves this design objective by providing features such as separation between ability and UI as well as integration of UI display and service capabilities.

- Different window forms for various device types

   The stage model redefines the ability lifecycle. In terms of architecture, the component manager and window manager are decoupled. This facilitates adaptation between window forms and device types.

## Basic Concepts

The following figure shows the basic concepts in the stage model.

![stageconcept](figures/stageconcept.png)

-  **HAP**: basic unit for building, distributing, and loading OpenHarmony applications. Each HAP corresponds to a module in the development state. In an application, **moduleName** uniquely identifies a module.
-  **Bundle**: an OpenHarmony application identified by **appid**. A bundle can contain multiple HAP files. Each application has a **bundleName**. However, **bundleName** must be used together with **appid** and other information to uniquely identify an application.
-  **AbilityStage**: runtime object of an HAP. It is created when the HAP is loaded to the process for the first time and is visible to developers in the runtime.
-  **Application**: runtime object of a bundle. It is invisible to developers in the runtime.
-  **Context**: base class that provides APIs in the runtime to obtain information such as the bundle name, module name, and path. The **Context** classes of the Ability and ExtensionAbility components inherit from this class.
-  **Ability**: provides lifecycle callbacks, holds the ability context, and supports cross-device component migration and multi-device collaboration.
-  **ExtensionAbility**: general name of scenario-based Extension abilities. The system defines multiple scenario-based **ExtensionAbility** classes, each of which has its own **ExtensionContext**.
-  **WindowStage**: local window manager.
-  **Window**: application window, which holds an ArkUI engine instance.
-  **ArkUI Page**: UI developed based on ArkUI.


## Lifecycle

The ability and ability stage are key objects in the application lifecycle.

For details about the lifecycle differences between the stage model and FA model, see [Ability Framework Overview](ability-brief.md). This section focuses on the ability lifecycle transition and the scheduling relationships between the ability, ability stage, and window stage.

![stageabilitylifecyclecallback](figures/stageabilitylifecyclecallback.png)

To implement device adaptation and multi-window scalability, OpenHarmony decouples the component manager from the window manager.

The ability lifecycle defined in the stage model includes only the creation, destruction, foreground, and background states. The gain focus and lose focus states that are closely related to UI are defined in the window stage. This implements weak coupling between the abilities and windows. On the service side, the window manager notifies the component manager of the foreground and background state changes, so the component manager only senses the foreground and background state changes but not the focus changes.

There are two lifecycle states related to the window stage in **Ability**: **onWindowStageCreate** and **onWindowStageDestroy**. They are valid only for devices with the display capability. **onWindowStageCreate** is invoked when a window stage is created, where you can call **loadContent** to set pages to be loaded for the ability. **onWindowStageDestroy** is invoked when the window stage is destroyed, where you can release resources.


## Ability Instances and Missions

Abilities can be started in any of the following modes:

* **Singleton**: For each type of ability, only one instance exists in the application process. **Ability1** in the figure below is started in singleton mode.
* **Standard**: Each time **startAbility** is called, an instance of the specified ability type is created in the application process. **Ability2** in the figure below is started in standard mode.
* **Specified**: Before creating an **Ability** instance, you can create a key for the instance. Each time **startAbility** is called, the system asks the application which ability instance (corresponding to a key) will be used. **Ability3** in the figure below is started in specified mode.

Each **Ability** instance corresponds to a mission in **Recents**.

The mission corresponding to an ability instance has a snapshot of the ability instance. After the ability instance is destroyed, the ability class information and snapshot are retained in the mission until the user deletes the information or the storage space reaches the upper limit.

 ![AbilityComponentInstanceMission](figures/AbilityComponentInstanceMission.png)

## ExtensionAbility Mechanism

Different from the ability used for UI display, ExtensionAbility provides a restricted running environment.

ExtensionAbility has the following features:

- Its process runs independently from the main process but shares the same storage sandbox with the main process. There is no inter-process communication (IPC) between the ExtensionAbility process and the main process.

- It has an independent context that provides scenario-specific APIs.

- It is created by the system, rather than by applications.

- The lifecycles of the ExtensionAbility component and process are managed by the system.

The following figure uses the widget an example. **FormExtensionAbility** is the base class. You can inherit from this class to provide widget information. The lifecycle of the **FormExtensionAbility** instance and that of the ExtensionAbility process where the instance is located are managed by a system service named **FormManagerService**.

![ExtensionAbility](figures/ExtensionAbility.png)

## Process Model

OpenHarmony forces strong control policies on application processes. No APIs are provided to configure multiple processes. All application processes are created and managed by the system.

The processes of an application can be classified into three types:

- Main process: runs the **UIAbility** component, UI, and service logic.

- Extension process: runs classes derived from **ExtensionAbility** in the application. The lifecycle of this process is managed by a scenario-specific system service.

- Render process: created for the WebView and used to load the WebView rendering library.

  The following figure shows the process model of an application.

  ![stageprocessmodel](figures/stageprocessmodel.png)

## Application Package Structure

For details about the project directory structure of the stage model, see [OpenHarmony Project Overview](https://developer.harmonyos.com/en/docs/documentation/doc-guides/ohos-project-overview-0000001218440650#section56487581904).

For details about how to configure the application package structure of the stage model, see [Application Package Structure Configuration File (Stage Model)](../quick-start/stage-structure.md).
