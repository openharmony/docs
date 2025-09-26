# JSVM-API Secure Shield Mode
<!--Kit: NDK Development-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--Designer: @knightaoko-->
<!--Tester: @test_lzz-->
<!--Adviser: @fang-jinxu-->

The Secure Shield mode is a system-level security protection solution designed for users with high security requirements. This mode strictly restricts functionalities to significantly enhance system security and effectively defend against threats through the remote attack surface. In Secure Shield mode, the functionalities of JSVM are restricted. You need to evaluate the application availability in Secure Shield mode.

## Enabling Secure Shield Mode

To enable Secure Shield mode, perform the following steps:
1. Go to system settings on your phone.
2. Select **Privacy and security**.
3. Touch **Secure Shield mode** and enable it.

## Functionality Restrictions in Shield Guard Mode

To reduce the risk of JSVM attacks, Secure Shield mode will implement the following key security restrictions:
- All Just-In-Time (JIT) compilation functionalities are disabled, including those for applications that have obtained ACL permissions.
- WebAssembly support is suspended (WebAssembly in the current version depends on JIT).

## Application Compatibility Evaluation

When running an application in Secure Shield mode, you are advised to perform the following compatibility checks:
1. JavaScript performance evaluation:
    - Test the running efficiency of the application in the restricted environment.
    - Optimize possible performance bottlenecks.

2. WebAssembly compatibility check:
    - Static code analysis: Check the WebAssembly API calls in the project and the Wasm dependency of the third-party library.
    - Runtime verification: Perform full-functionality tests in Secure Shield mode.
