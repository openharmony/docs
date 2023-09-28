# ArkCompiler Subsystem Changelog

## cl.arkcompiler.1 Removal of ts2abc Compiler from SDK

ArkCompiler in the SDK included the ts2abc and es2abc compilers for compilation of .ets and .js files. Since this version, the ts2abc compiler has been removed. You can check the changes shown below in the **ets\build-tools\ets-loader\bin** and **js\build-tools\ets-loader\bin** directories of the SDK.

![stack](figures/api10_sdk_arkcompiler_component_change.png)

**Change Impact**
This change does not affect your development in DevEco Studio. If you use scripts to generate ABC files, use the es2abc compiler instead of es2abc.

**Key API/Component Changes**
The ts2abc related components are removed from the SDK.

**Adaptation Guide**
1. If you are using DevEco Studio for application development, the removal of the ts2abc compiler has no influence.
2. If you are writing scripts to use the ts2abc compiler, you'll need switch to the es2abc compiler. For details about how to use the es2abc compiler and its comparison with the ts2abc compiler, see [Usage Guidelines](https://gitee.com/openharmony/arkcompiler_ets_frontend/blob/master/README.md#usage-guidelines). Assume that **a.js** is the target .js file for compilation. For ABC file generation, which is the most frequently encountered scenario, the compilation commands are as follows:
    - Compilation in script mode
        1. es2abc: es2abc a.js --output a.abc
        2. ts2abc: node --expose-gc pathToIndex/index.js a.js --output a.abc
    - Compilation in module mode
        1. es2abc: es2abc a.js --module --output a.abc
        2. ts2abc: node --expose-gc pathToIndex/index.js a.js --module --output a.abc
