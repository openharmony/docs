# API Reference Document Description

API references provide the description of APIs used for application development. This topic describes common fields in the API references to help you better use the reference document.

## Version Description

In API references, the earliest versions of APIs and components are specified in the following ways:

- For a new API or component, the version information is provided at the beginning of the reference document. Example: "The initial APIs of this module are supported since API version 7."
- For a new feature of an existing API or component, a superscript is added following the feature. For example, "uid<sup>8+</sup>" indicates that the **uid** attribute is supported since API version 8.

## System Capability Description

System capability refers to a relatively independent feature in the operating system. Different devices provide different system capabilities, and multiple APIs implement a system capability. You can determine whether an API can be used based on system capabilities. For details, see [SystemCapability](syscap.md).

The following description is provided for each API in the reference document to describe the system capability of the API: "**System capability**: SystemCapability.xxx.xxx"

<!--Del-->
- You can use the [SystemCapability List](syscap-list.md) to query the devices supported by a specific capability set.<!--DelEnd-->
- You can call the **canIUse** API to [check whether an API is available](syscap.md#checking-whether-an-api-is-available).
- The performance of a SysCap may vary by device type. You can [check the differences between devices with a specific SysCap](syscap.md#checking-the-differences-between-devices-with-a-specific-syscap).
<!--RP2--><!--RP2End-->

<!--RP1--><!--RP1End-->

## Service Widget Description

A [service widget](../form/formkit-overview.md) (also called widget) is a set of UI components that display important information or operations specific to an application or atomic service. It provides users with direct access to a desired service, without the need to open the application first.
- For APIs that can be used in ArkTS widgets, the following description will be added: "Widget capability: This API can be used in ArkTS widgets since API version *x*."
- For APIs that cannot be used in ArkTS widgets, no special description is provided.

## Permission Description

By default, applications can access limited system resources. However, in some cases, an application needs to access excess data (including personal data) and functions of the system or another application to implement extended functions. For details, see [Application Permission Management Overview](../security/AccessToken/app-permission-mgmt-overview.md).

To call APIs to access these resources, you must apply for the corresponding permissions by following the instructions provided in [Workflow for Requesting Permissions](../security/AccessToken/determine-application-mode.md).

- If an application can call an API only after it has obtained a specific permission, the following description is provided for the API: "**Required permissions**: ohos.permission.xxxx"
- If an application can call an API without any permission, no special description is provided.

## Application Model Description

Along its evolution, the system has provided two application models: FA model and stage model.

- If all the APIs of a module support only one model, the following description is provided at the beginning of the reference document: "The APIs of this module can be used only in the FA model." or "The APIs of this module can be used only in the stage model."
- If certain APIs of a module support only one model, the following description is provided individually for these APIs: "This API can be used only in the FA model." or "This API can be used only in the stage model."
- If both models are supported, no special description is provided.

<!--Del-->
## Available APIs

Certain APIs provided by OpenHarmony are system APIs, which can be used only by original equipment manufacturers (OEMs) and cannot be used by common applications.

A description regarding system APIs will be provided in the document.

- If all the APIs of a module are system APIs, the following description is provided at the beginning of the reference document: "All the APIs of this module are system APIs."
- If a specific API of a module is a system API, the following description is provided individually for the API: "This is a system API."

A common application is an application whose application type is **hos_normal_app** in the HarmonyAppProvision configuration file. **hos_normal_app** is the default value for project creation.

The public SDK, which does not include system APIs, is provided as standard in DevEco Studio. To use the system APIs, you must:

- Switch the public SDK to the full SDK by following the instructions provided in [Switching to Full SDK](../faqs/full-sdk-switch-guide.md).
- Change the value of **app-feature** in the HarmonyAppProvision configuration file to **hos_system_app** (indicating a system application). For details, see [HarmonyAppProvision Configuration File](../security/app-provision-structure.md).
<!--DelEnd-->

## Deprecated API Description

A deprecated API is an API no longer recommended and is marked with the <sup>deprecated</sup> superscript.

While deprecated APIs can still be implemented in the five API levels immediately following the version when the API is deprecated, this is not recommended.

- Do not use deprecated APIs in new code. If possible, rewrite old code by replacing the deprecated APIs with their substitutes.
- If no substitute is available, change the implementation mode by referring to the deprecation description and changelog.
