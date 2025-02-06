# Process Model (Stage Model)


The process model is shown below.


- Generally, all UIAbility, ServiceExtensionAbility, and DataShareExtensionAbility components of an application (with the same bundle name) run in an independent process, which is **Main process** in green in the figure.
- All ExtensionAbility components of the same type (except ServiceExtensionAbility and DataShareExtensionAbility) of an application (with the same bundle name) run in an independent process, such as **FormExtensionAbility process**, **InputMethodExtensionAbility process**, and other **ExtensionAbility process** in blue in the figure.
- WebView has an independent render process, which is **Render process** in yellow in the figure.

> **NOTE**
>
> For 2-in-1 devices, you can set a specific HAP or UIAbility to run in an independent process.
> - To enable a HAP to run in an independent process, set the **isolationMode** field in the **module.json5** file to **isolationOnly** (running only in an independent process) or **isolationFirst** (running in an independent process preferentially).
> - To enable a UIAbility to run in an independent process, set the **isolationProcess** field in the **module.json5** file to **true** and return a unique process ID in the [onNewProcessRequest](../reference/apis-ability-kit/js-apis-app-ability-abilityStage.md) callback.

**Figure 1** Process model

![process-model](figures/process-model.png)

> **NOTE**
>
> - You can create ServiceExtensionAbility and DataShareExtensionAbility only for system applications.
> - To view information about all running processes, run the **hdc shell** command to enter the shell CLI of the device, and run the **ps -ef** command.

A system application can apply for multi-process permissions (as shown in the following figure) and configure a custom process for an HAP. UIAbility, DataShareExtensionAbility, and ServiceExtensionAbility in the HAP run in the custom process. Different HAPs run in different processes by configuring different process names.

**Figure 2** Multi-process

![multi-process](figures/multi-process.png)


The system provides the following inter-process communication (IPC) mechanism:


[Common Events](../basic-services/common-event/common-event-overview.md): This mechanism is used in one-to-many communication scenarios. Multiple subscribers may receive events at the same time.

