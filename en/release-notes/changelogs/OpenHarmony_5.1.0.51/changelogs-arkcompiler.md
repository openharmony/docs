# ArkCompiler Changelog

## cl.arkcompiler.1 JIT Is Disabled by Default and Requires Permission Certificate and Approval to Enable

**Access Level**

Public API

**Reason for Change**

The Just In Time (JIT) compilation feature, which compiles code on-the-fly during execution, can pose risks of arbitrary code injection. To safeguard application security and uphold the integrity of the OpenHarmony ecosystem, the system now defaults to disabling the JIT functionality in the JSVM. Instead, it executes JS code through interpretation.

**Impact of the Change**

This change requires application adaptation.

Before the change:
JIT is enabled by default.

After the change:
JIT is disabled by default and can only be enabled after obtaining a permission certificate. Without JIT, wasm interfaces that rely on JIT fail to execute, and there may be performance differences between JIT and interpretation in specific scenarios.

**Start API Level**

API 11

**Change Since**

OpenHarmony SDK 5.1.0.51

**Key API/Component Changes**

| API                         | Impact                                                         |
| ------------------------------- | --------------------------------------------------------------- |
| OH\_JSVM\_CompileWasmModule   | Returns JIT\_MODE\_EXPECTED status code without JIT permission.                     |
| OH\_JSVM\_CompileWasmFunction | Returns JIT\_MODE\_EXPECTED status code without JIT permission.                     |
| OH\_JSVM\_CreateWasmCache     | Returns JIT\_MODE\_EXPECTED status code without JIT permission.                     |
| OH\_JSVM\_RunScript           | Fails to execute scripts containing wasm without JIT permission and may exhibit performance differences in specific scenarios.|

**Adaptation Guide**

For new applications that wish to use JIT, you must submit an application for the **ohos.permission.kernel.ALLOW_EXECUTABLE_FORT_MEMORY** restricted ACL permission to the AppGallery Connect (AGC). In your application materials, specify the exact scenarios in which the JIT functionality of the JSVM engine will be used. Once the permission is approved, you can update your profile certificate from the AGC website and repackage your application for release. For details, see [Requesting Restricted Permissions](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/declare-permissions-in-acl-V5).

Precautions
1. If restricted permissions are only declared in the configuration file without a permission profile, the application installation will fail.
2. If the error "The ohos.permission.kernel.ALLOW_EXECUTABLE_FORT_MEMORY permission under requestPermissions must be a value that is predefined within the SDK or a custom one that you have included under definePermissions." is displayed during the compilation process, update the OpenHarmony SDK to the latest version (5.0.2.125 or later).
