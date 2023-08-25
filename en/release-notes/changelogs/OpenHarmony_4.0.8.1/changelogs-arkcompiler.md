# ArkCompiler Subsystem Changelog

## cl.ArkCompiler.1 Change of Default Compiler to es2abc in Type Compilation

In the SDK, ArkCompiler has two compilers that support ets/ts/js compilation: ts2abc compiler and es2abc compiler.

Introduction to compilation modes:

- Non-type compilation: converts ArkTS/TS source code into JS source code, and uses the ArkCompiler compiler es2abc to generate bytecode.

- Type compilation: converts ArkTS/TS source code into TS source code, and uses the ArkCompiler compiler ts2abc (in earlier versions)/es2abc (enabled in this version) to generate bytecode.

You can check the hvigor version of the application project in the following fields:
​**hvigorVersion** field and **@ohos/hvigor-ohos-plugin** field under **dependencies** in the **hvigor-config.json5** file in the **hvigor** directory of the application project

Enable type compilation:

If the hvigor version is 2.6.0-rc.9.s or later, the type compilation mode is enabled by default. You can also manually enable this mode by setting **aotCompileMode** to **type** under the **buildOption** tag in the **build-profile.json5** file at the same level directory as the application source code (**src** directory).

When type compilation is enabled and the SDK of this version is used, the ArkCompiler compiler es2abc is used by default. The earlier version SDK with ts2abc enabled is not recommended for type compilation.

**Change Impact**
In DevEco Studio, when the type compilation mode is enabled and the SDK of this version is used, the change in the compilation mode and ArkCompiler compiler may result in application compilation failures and runtime crashes.

**Key API/Component Changes**
In type compilation mode, the ArkCompiler compiler es2abc is used by default.

**Adaptation Guide**

If the hvigor version is 2.6.0-rc.9.s or later, to switch to the original compilation mode (non-type), you need to set **aotCompileMode** in the **build-profile.json5** file.