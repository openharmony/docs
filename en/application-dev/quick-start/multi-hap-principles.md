# Multi-HAP Operation Mechanism and Data Communication Modes


The multi-HAP mechanism is used to facilitate modular management for developers. There is no one-to-one mapping between the HAP and the running process of the application. The detailed running mechanism is as follows:


- By default, all UIAbility, ServiceExtensionAbility, and DataShareExtensionAbility components of an application (with the same bundle name) run in the same independent process, and other ExtensionAbility components of the same type run in separate processes.

- The HAP file supports the process configuration through the **process** tag in the **module.json5** (stage model) or **config.json** (FA model) file. This feature is supported only by system applications. If **process** is configured for an HAP file, all components of the HAP file run in an independent process. Multiple HAP files can be configured with the same process, in which case the HAP files run in the same process. For details about the process configuration, see [module.json5 Configuration File](module-configuration-file.md).

- When an application is running, the resources and code of the corresponding HAP file are loaded only when the UIAbility component in the same process is started.


Based on the preceding mechanism, the multi-HAP data communication modes are as follows:


- For details about data communication in the same process, see [Thread Model (Stage Model)](../application-models/thread-model-stage.md).

- For details about cross-process data communication, see [Process Model (Stage Model)](../application-models/process-model-stage.md).

- If multiple HAPs run in the same process, the communication mode between the components of multiple HAP files is the same as that between the components of the same HAP file.
