# Application Configuration Files (Stage Model)
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

Each application project must have configuration files in its code directory. These configuration files provide basic application information for build tools, operating systems, and application markets.


In the code directory of an application project developed in stage model, there are two types of configuration files: one **app.json5** file and one or more **module.json5** files.

>
> **NOTE**
>
> After the compilation, the contents of **app.json5** and **module.json5** in the build product of a single module will merge into a **module.json** file. For details, see [Package Structure in the Build Phase](application-package-structure-stage.md#package-structure-in-the-build-phase).
>

The [app.json5](app-configuration-file.md) file contains the following information:


- Application-wide configuration, including the bundle name, developer, and version number

- Device-specific configuration


The [module.json5](module-configuration-file.md) file contains the following information:


- Basic module configuration, such as the name, type, description, and supported device types of the module

- Application component information, including the descriptions of the [UIAbility](module-configuration-file.md#abilities) and [ExtensionAbility](module-configuration-file.md#extensionabilities) components

- Information about the permissions required during application running
