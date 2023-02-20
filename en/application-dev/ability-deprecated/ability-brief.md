# Ability Framework Overview

Ability is the basic abstraction of applications in OpenHarmony.

Each ability is an application component that provides an independent service and is the minimum unit for the system to schedule an application. An application can contain one or more **Ability** instances.

The ability framework model has two forms:

- FA model, which is available for application development using API version 8 and earlier versions. In the FA model, there are PageAbility, ServiceAbility, DataAbility, and FormAbility.
- Stage model, which is introduced since API version 9. In the stage model, there are two classes: UIAbility and ExtensionAbility. ExtensionAbility is further extended to ServiceExtensionAbility, FormExtensionAbility, DataShareExtensionAbility, and more.

Starting from API version 9, the stage model is recommended.

The stage model is designed to make it easier to develop complex applications in the distributed environment. The table below lists the design differences between the two models.

| Item          | FA Model                                                      | Stage Model                                               |
| -------------- | ------------------------------------------------------------ | -------------------------------------------------------- |
| Application component development mode      | Web-like development                    | Object-oriented development            |
| Engine instance      | Each **Ability** instance exclusively occupies a VM instance.              | Multiple **Ability** instances share a VM instance.      |
| Intra-process object sharing| Not supported                                                    | Supported                                                  |
| Bundle description file    | The **config.json** file is used to describe the HAP and component information. Each component must use a fixed file name.| The **module.json5** file is used to describe the HAP and component information. The entry file name can be specified.|
| Component          | Four types of components are provided: PageAbility (used for UI page display), ServiceAbility (used to provide services), DataAbility (used for data sharing), and FormAbility (used to provide widgets).| Two types of components are provided: UIAbility (used for UI page display) and ExtensionAbility (scenario-based service extension).  |

In addition, the following differences exist in the development process:

* Different ability types

  ![favsstage](figures/favsstage.png)

* Different ability lifecycles

  ![lifecycle](figures/lifecycle.png)

For details about the two models, see [FA Model Overview](fa-brief.md) and [Stage Model Overview](stage-brief.md).
