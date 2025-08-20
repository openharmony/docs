# Application Package Glossary
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

## E

### ExtensionAbility 

A component that provides extension abilities for specific scenarios (such as service widgets and input methods) in the stage model.

## F

### FA 

Feature Ability, an ability with a UI to interact with users in the FA model.

### FA model

It is the only application development model supported by API version 8 and earlier. Now, the stage model is recommended for application development.

## H

### HAP 

Harmony Ability Package, released with the file name extension .hap, contains all content of an application, including code, resources, third-party libraries, and an application configuration file.

### HAR 

HarmonyOS Archive, released with the file name extension .har, is a static shared package and can be reused in the compilation state. It can contain code, C++ libraries, resources, and configuration files, and is used to share code and resources.

### HSP 

Harmony Shared Package, released with the file name extension .hsp, is a dynamic shared package and can be reused during runtime. It can contain code, C++ libraries, resources, and configuration files, and is used to share code and resources.

## M

### Module

A module is a part of an application. Each module has an independent module.json5 configuration file. In a project, Entry, Feature, HSP, and HAR are application modules.

## P

### PA

Particle Ability, an ability without a UI in the FA model. PAs are invoked to implement FA functionalities. For example, a PA runs in the background to provide the computing capability or acts as a data warehouse to provide the data access capability.

## S

### Stage model

Application model available since API version 9. It provides two types of application components: UIAbility and ExtensionAbility. In this model, classes such as **AbilityStage** and **WindowStage** are provided as the stage of application components and windows. That's why it is named stage model.

## U

### UIAbility

A component in the stage model used to provide UI capabilities for user interaction.

<!--Del-->
## X

### System-level HSP

An HSP preset in the system by the OEM. As the underlying implementation of Kits, it is indirectly depended on by third-party applications and runs in the third-party process space.
<!--DelEnd-->
