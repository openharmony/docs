# Component Startup Rules Within a Device (Stage Model)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @wendel-->
<!--Designer: @wendel-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=e542c6d17cd7e353a93d279eebb76cc8f8a4dd0b translatedAt=2026-08-18T01:30:44.283Z pushedAt=2026-08-18T08:43:17.295Z -->

To ensure system security and user experience, the system restricts apps from displaying pop-up windows at will in the background, waking each other up, and allowing foreground apps to jump to other apps arbitrarily. This document mainly describes the rules for starting [UIAbility](../reference/apis-ability-kit/js-apis-app-ability-uiAbility.md) and [ExtensionAbility](../reference/apis-ability-kit/js-apis-app-ability-extensionAbility.md) within a device.

- Displaying pop-up windows at will when an app is in the background: various advertising pop-up windows.

- Waking each other up when apps are in the background: unreasonably occupying system resources, which increases system power consumption or causes system lag.

- A foreground app jumping to other apps arbitrarily: jumping to the payment page of another app at will.

> **NOTE**
> 
> The component startup rules take effect since API version 9. The effective version of newly added rules is specified separately in each rule. Developers must be familiar with the component startup rules to avoid service exceptions.

## UIAbility Component Startup Rules

### Rules for Starting UIAbility Components Within an App

   A UIAbility app in the background is not allowed to start a UIAbility component.

   > **NOTE**
   >
   > - For 2-in-1 and tablet devices:
   > - Since API version 18, if the app has created a floating window displayed in the foreground, it is not subject to this rule.
   > - Since API version 21, if the app itself has been added to the status bar, it is not subject to this rule.

### Rules for Cross-App Startup of UIAbility Components

   When starting a UIAbility component across apps through [startAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#startability)/[openLink()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#openlink12), only the target component whose **exported** is **true** can be pulled up. A UIAbility app in the background is not allowed to start a UIAbility component.

   > **NOTE**
   >
   > - In the module.json5 configuration file, each UIAbility has an **exported** attribute. For details about the **exported** field, see [abilities](../quick-start/module-configuration-file.md#abilities).
   > - If the **exported** field of the target component is set to **true**, the component can be called by other apps.
   > - If the **exported** field of the target component is set to **false**, the component can be started only within the app.

The following figure shows the specific verification process for starting a component:


## ExtensionAbility Component Startup Rules

When a third-party app uses [connectServiceExtensionAbility()](../reference/apis-ability-kit/js-apis-inner-application-uiAbilityContext.md#connectserviceextensionability) to connect to a ServiceExtensionAbility component across apps, only the target component with **exported** set to **true** can be started. A third-party app cannot start a DataShareExtensionAbility component. For the startup rules of other ExtensionAbility components, see [ExtensionAbility Component](extensionability-overview.md#extensionability-types).