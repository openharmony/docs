# Process Model (Stage Model)


The process model is shown below.


- All UIAbility, ServiceExtensionAbility, and DataShareExtensionAbility components of an application (with the same bundle name) run in an independent process, which is **Main process** in green in the figure.
- All ExtensionAbility components of the same type (except ServiceExtensionAbility and DataShareExtensionAbility) of an application (with the same bundle name) run in an independent process, such as **FormExtensionAbility process**, **InputMethodExtensionAbility process**, and other **ExtensionAbility process** in blue in the figure.
- WebView has an independent render process, which is **Render process** in yellow in the figure.

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

 <!--no_check--> 