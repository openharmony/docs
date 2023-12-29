# Multi-HAP Operation Mechanism and Data Communication Modes


The multi-HAP mechanism is used to facilitate modular management. There is no one-to-one mapping between the HAP and the process in which the application runs. The detailed operation mechanism is as follows:


- By default, all UIAbility, ServiceExtensionAbility, and DataShareExtensionAbility components of an application (with the same bundle name) run in the same independent process (known as the main process), and other ExtensionAbility components of the same type run in their respective processes.

- The process can be specified through the **process** tag in the **module.json5** (stage model) or **config.json** (FA model) file. This configuration is supported only by system applications. If **process** is configured for an HAP file, all components of the HAP file run in this process. Multiple HAP files can be configured with the same process, in which case all the components of these HAP files run in this process. For details about the process configuration, see [module.json5 Configuration File](module-configuration-file.md).

- When an application is running, the resources and code of the corresponding HAP file are loaded only when the UIAbility component in the same process is started.


Based on the preceding mechanism, the following multi-HAP data communication modes are available:


- Data communication in the same process. For details, see [Thread Model (Stage Model)](../application-models/thread-model-stage.md).

- Cross-process data communication. For details, see [Process Model (Stage Model)](../application-models/process-model-stage.md).


If multiple HAPs run in the same process, the communication mode between the components of these HAP files is the same as that between the components of the same HAP file.