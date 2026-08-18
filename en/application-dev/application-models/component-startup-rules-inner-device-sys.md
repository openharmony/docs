# Component Startup Rules Within a Device (Stage Model) (System Applications Only)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wendel-->
<!--Designer: @wendel-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=e542c6d17cd7e353a93d279eebb76cc8f8a4dd0b translatedAt=2026-08-18T01:30:50.464Z pushedAt=2026-08-18T08:37:25.367Z -->

To ensure system security and user experience, the system restricts apps from displaying pop-up windows at will in the background state, waking each other up, and foreground applications from jumping at will. For details about the related behaviors, see [Component Startup Rules Within a Device (Stage Model)](./component-startup-rules-inner-device.md). This document mainly describes the constraints on system applications starting [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) and [ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md) within a device.

> **NOTE**
> 
> The component startup rules take effect since API version 9. The version in which a new rule takes effect is described separately in the rule. Developers must be familiar with the component startup rules to avoid service exceptions.

## UIAbility Component Startup Rules

### Rules for Starting UIAbility Components Within an App

   A UIAbility app in the background state is not allowed to start UIAbility components by default. It can apply for the ohos.permission.START_ABILITIES_FROM_BACKGROUND (hereinafter referred to as BACKGROUND) permission to start UIAbility components. For details about how to apply for the permission, see [declare permission](../security/AccessToken/declare-permissions.md).

   | Application State | Permission Requirements |
   | ----------------- | ----------------------- |
   | Foreground app    | None                    |
   | Background app    | BACKGROUND              |

   > **NOTE**
   >
   > - For 2-in-1 and tablet devices:
   > - Since API version 18, if the app has created a floating window displayed in the foreground, it is not subject to this rule.
   > - Since API version 21, if the app itself has been added to the status bar, it is not subject to this rule.

### Rules for Starting UIAbility Components Across Apps

   When starting a UIAbility component across apps through [startAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability)/[openLink()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#openlink12), only the target component with **exported** set to **true** can be started. If the app applies for the **ohos.permission.START_INVISIBLE_ABILITY** permission (hereinafter referred to as INVISIBLE), it is not subject to this rule. A UIAbility app in the background state is not allowed to start a UIAbility component across apps by default, and must apply for the BACKGROUND permission to start the UIAbility component. For details about how to apply for permissions, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

   | Application State | Component Visibility | Permission Requirements |
   | ----------------- | -------------------- | ------------------------ |
   | Foreground app    | exported:true        | None                     |
   | Foreground app    | exported:false       | INVISIBLE permission     |
   | Background app    | exported:true        | BACKGROUND permission    |
   | Background app    | exported:false       | BACKGROUND permission + INVISIBLE permission |

   > **NOTE**
   >
   > - In the module.json5 configuration file, each UIAbility has an **exported** attribute. For details about the **exported** field, see [abilities](../quick-start/module-configuration-file.md#abilities).
   > - If the **exported** field of the target component is set to **true**, the component can be called by other apps.
   > - If the **exported** field of the target component is set to **false**, the component can be started only within the app.

   The following figure shows the specific verification process for starting a component:


   When starting a UIAbility component across apps through the [startAbilityByCall()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startabilitybycall) API, the following three conditions must be met: 1. Apply for the ohos.permission.ABILITY_BACKGROUND_COMMUNICATION permission (hereinafter referred to as CALL). 2. The exported attribute of the target UIAbility component is true. If the INVISIBLE permission is applied for, this rule does not apply. 3. The caller's UIAbility is in the foreground; otherwise, the BACKGROUND permission must be applied for. For details about how to apply for permissions, see [Declaring Permissions](../security/AccessToken/declare-permissions.md).

   | App State | Component Visibility | Permission Requirements                     |
   | --------- | -------------------- | ------------------------------------------- |
   | Foreground App | exported:true  | CALL permission                             |
   | Foreground App | exported:false | INVISIBLE permission + CALL permission      |
   | Background App | exported:true  | BACKGROUND permission + CALL permission     |
   | Background App | exported:false | BACKGROUND permission + INVISIBLE permission + CALL permission |

   The following figure shows the specific verification process for starting a component:


## ExtensionAbility Component Startup Rules

All types of [ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md) components (except [ServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md) and [DataShareExtensionAbility](../reference/apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md)) are started by the corresponding system management service to ensure that their lifecycle is controlled by the system. An ExtensionAbility component is started when it is used and destroyed after use.

- [ServiceExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-serviceExtensionAbility-sys.md) component startup rules:

   When starting a ServiceExtensionAbility component across apps through [startServiceExtensionAbility](../reference/apis-ability-kit/js-apis-inner-application-serviceExtensionContext-sys.md#serviceextensioncontextstartserviceextensionability) or connecting to it across apps through [connectServiceExtensionAbility](../reference/apis-ability-kit/js-apis-inner-application-serviceExtensionContext-sys.md#serviceextensioncontextconnectserviceextensionability), only the target component with exported set to true can be started. If the INVISIBLE permission is applied for, this rule does not apply.

   | App State | Component Visibility | Permission Requirements |
   | --------- | -------------------- | ----------------------- |
   | Foreground app | exported:true  | None                          |
   | Foreground app | exported:false | INVISIBLE permission          |
   | Background app | exported:true  | None                          |
   | Background app | exported:false | INVISIBLE permission          |

   The specific verification process for starting a component is as follows:


- [DataShareExtensionAbility](../reference/apis-arkdata/js-apis-application-dataShareExtensionAbility-sys.md) component startup rules:

   You can start the DataShareExtensionAbility component through the [createDataShareHelper](../reference/apis-arkdata/js-apis-data-dataShare-sys.md#datasharecreatedatasharehelper) API. For details about the operations and restrictions, see [Sharing Data Through DataShareExtensionAbility](../database/share-data-by-datashareextensionability-sys.md).

- Startup rules for other ExtensionAbility components:

For the startup rules of other ExtensionAbility components, see [ExtensionAbility](extensionability-overview.md#extensionability-types).