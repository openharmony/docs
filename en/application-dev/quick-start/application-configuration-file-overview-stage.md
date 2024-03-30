# Overview of Application Configuration Files in Stage Model


Each application project must have configuration files in its code directory. These configuration files provide basic application information for build tools, operating systems, and application markets.


In the code directory of an application project developed in stage model, there are two types of configuration files: one **app.json5** file and one or more **module.json5** files.


The [app.json5](app-configuration-file.md) file contains the following contents:


- Application-wide configuration, including the bundle name, developer, and version number.

- Device-specific configuration.


The [module.json5](module-configuration-file.md) file contains the following contents:


- Basic module configuration, such as the name, type, description, and supported device types of the module.

- Information about the [application components](../application-models/stage-model-development-overview.md), including the descriptions of the UIAbility and ExtensionAbility components.

- Information about the permissions required during application running.
