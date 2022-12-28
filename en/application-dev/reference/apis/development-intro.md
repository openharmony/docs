# API Reference Document Description

API references provide the description of APIs used for application development. This topic describes common fields in the API references to help you better use the reference document.

## Version Description

In API references, the earliest versions of APIs and components are specified in the following ways:

- For a new API or component, the version information is provided at the beginning of the reference document. Example: "The initial APIs of this module are supported since API version 7."
- For a new feature of an existing API or component, a superscript is added following the feature. For example, "uid<sup>8+</sup>" indicates that the **uid** attribute is supported since API version 8.

## Ability Framework Model Description

Ability is the minimum unit for the system to schedule applications. An application can contain one or more `Ability` instances. Ability framework models are classified into the FA model and stage model. For details, see [Ability Framework Overview](../../ability/ability-brief.md).

- If all the APIs of a module support only one model, the following description is provided at the beginning of the reference document: "The APIs of this module can be used only in the FA model." or "The APIs of this module can be used only in the stage model."
- If certain APIs of a module support only one model, the following description is provided individually for these APIs: "This API can be used only in the FA model." or "This API can be used only in the stage model."
- If both models are supported, no special description is provided.

## Available APIs

Certain APIs provided by OpenHarmony are system APIs, which can be used only by original equipment manufacturers (OEMs) and cannot be used by non-system applications.

A description regarding system APIs will be provided in the document.

- If all the APIs of a module are system APIs, the following description is provided at the beginning of the reference document: "All the APIs of this module are system APIs."
- If a specific API of a module is a system API, the following description is provided individually for the API: "This is a system API."

Non-system applications are applications whose Ability Privilege Level (APL) is **normal**. The default application level is **normal**.

For details about the APL and how to declare the APL of an application higher than **normal**, see [Access Control Overview - App APLs](../../security/accesstoken-overview.md#app-apls).

The public SDK, which does not include system APIs, is provided as standard in DevEco Studio. To use system APIs, switch to the full SDK. For details on the operation, see [Guide to Switching to Full SDK](../../quick-start/full-sdk-switch-guide.md).

## Permission Description

By default, applications can access limited system resources. However, in some cases, an application needs to access excess data (including personal data) and functions of the system or another application to implement extended functions. For details, see [Access Control Overview](../../security/accesstoken-overview.md).

To call APIs to access these resources, you must apply for the corresponding permissions by following the instructions provided in [Access Control Development](../../security/accesstoken-guidelines.md).

- If an application can call an API only after it has obtained a specific permission, the following description is provided for the API: "**Required permissions**: ohos.permission.xxxx"
- If an application can call an API without any permission, no special description is provided.

To determine whether an application can apply for a specific permission, see [Permission List](../../security/permission-list.md).

## System Capability Description

System capability refers to a relatively independent feature in the operating system. Different devices provide different system capabilities, and multiple APIs implement a system capability. You can determine whether an API can be used based on system capabilities. For details, see [SysCap](../../quick-start/syscap.md).

The following description is provided for each API in the reference document to describe the system capability of the API: "**System capability**: SystemCapability.xxx.xxx"

## Sample Code Language Description

OpenHarmony supports two development languages: JS and TS.

- When a code block is labeled with `js`, the sample code can be used in the JS and ArkTS projects.
- When a code block is labeled with `ts`, the sample code can be used only in the ArkTS project.
