# JSVM-API Secure Shield Mode
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

The Shield mode is a system-level security protection solution designed for users with high security requirements. This mode implements strict function restrictions to significantly enhance system security and effectively defend against various threats to the remote attack surface. In Ken Shield mode, JSVM has added function restrictions. You need to evaluate the availability of your app in Ken Shield mode.

## Enabling Secure Shield Mode

To enable Shield Guard mode, perform the following steps:
1. Go to the phone system settings screen.
2. Select Privacy and Security.
3. Touch Guardian mode and enable it.

## Function Restrictions in Shielded Mode

To reduce the risk of JSVM attacks, the Shield Guard mode implements the following key security restrictions:
- Fully disable the just-in-time compilation (JIT) function, including applications that have obtained ACL permissions.
- Suspended WebAssembly support. (In the current version, WebAssembly depends on the JIT function.)

## Application Compatibility Assessment Guide

When running an application in Guardian mode, you are advised to perform the following compatibility checks:
1. JavaScript performance evaluation:
    - Test the running efficiency of an application in a restricted environment.
    - Optimizing Possible Performance Bottlenecks

2. WebAssembly compatibility check:
    - Static code analysis: Check the invoking of WebAssembly-related APIs in the project and the Wasm dependency on the third-party library.
    - Runtime verification: Perform full function tests in Shield Guard mode.
