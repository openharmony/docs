# Requesting the JIT Profile for JSVM-APIs
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

Using just-in-time (JIT) compilation may pose security risks of arbitrary code injection. To protect application security and maintain a pure OpenHarmony ecosystem, the JIT feature is disabled for JSVMs by default. If you need to use this feature, you must request the ohos.permission.kernel.ALLOW_EXECUTABLE_FORT_MEMORY permission in the ACL with a clear rationale for employing JIT on JSVMs from AppGallery Connect (AGC). After the permission request is approved by AGC, you can update the profile in AGC and repack and release the application. For details, see [Requesting Restricted Permissions](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V5/declare-permissions-in-acl-V5).


## Precautions
1. If the corresponding permission certificate is not applied for but the permission is declared in the configuration file, the application will fail to be installed.
2. If the error "The ohos.permission.kernel.ALLOW_EXECUTABLE_FORT_MEMORY permission under requestPermissions must be a value that is predefined within the SDK or a custom one that you have included under definePermissions." is displayed during the compilation process, update the OpenHarmony SDK to the latest version (5.0.2.125 or later).
3. When the Shield mode is enabled, the operating system disables the JIT function globally. This restriction applies to all applications, including privileged applications that have obtained the ACL permission. For details about the technical implementation, see [JSVM Shield Mode](jsvm-secure-shield-mode.md).
