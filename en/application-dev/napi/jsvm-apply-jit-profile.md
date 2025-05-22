# Requesting the JIT Profile for JSVMs

Using just-in-time (JIT) compilation may pose security risks of arbitrary code injection. To protect application security and maintain a pure OpenHarmony ecosystem, the JIT feature is disabled for JSVMs by default. If you need to use this feature, you must request the ohos.permission.kernel.ALLOW_EXECUTABLE_FORT_MEMORY permission in the ACL with a clear rationale for using JIT on JSVMs from AppGallery Connect (AGC). After the permission request is approved by AGC, you can update the profile in AGC and repack and release the application. For details, see [Requesting Restricted Permissions](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/declare-permissions-in-acl-V5).


## Precautions
- If restricted permissions are only declared in the configuration file without a permission profile, the application installation will fail.
- If the error "The ohos.permission.kernel.ALLOW_EXECUTABLE_FORT_MEMORY permission under requestPermissions must be a value that is predefined within the SDK or a custom one that you have included under definePermissions." is displayed during the compilation process, update the OpenHarmony SDK to the latest version (5.0.2.125 or later).
