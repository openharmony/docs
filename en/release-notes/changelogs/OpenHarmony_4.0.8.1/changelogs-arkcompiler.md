# ArkCompiler Subsystem Changelog

## cl.ArkCompiler.1 type compileMode uses es2abc by default

The composition of ArkCompiler in sdk has ts2abc compiler and es2abc compiler, supporting compilation of ets/ts/js files.<br>
Compilation Mode Introduction:<br>
​&emsp;Non-type compilation: convert ets/ts sourceCode into js sourceCode, and use ArkCompiler compiler es2abc to generate bytecode. <br>
​&emsp;type compilation: convert ets/ts sourceCode into ts sourceCode, and use ArkCompiler compiler ts2abc (previous version)/es2abc (enabled in this version) to generate bytecode. <br>
Application Project hvigor version:<br>
​&emsp;hvigorVersion field and @ohos/hvigor-ohos-plugin field in dependencies of hvigor-config.json5 file in the hvigor directory of the application project.<br>
Enable type compilation:<br>
​&emsp;When the hvigor version is greater than or equal to 2.6.0-rc.9.s, the type compilation mode is used by default, or in the build-profile.json5 file of the same level directory as the application sourceCode (src directory), configure the "aotCompileMode": "type" option under the buildOption tag<br>

When type compilation is enabled and this version of the SDK is used, the ArkCompiler compiler es2abc will be used by default to compile the ts sourceCode to generate bytecode, and it is not recommended to use the old version SDK with ts2abc enabled for type compilation.<br>

**Change Impact**<br>
With DevEco Studio development, after the type compilation mode is enabled and the new version of the SDK is used, due to the change of the compilation mode and the change of the ArkCompiler compiler, application compilation failures and runtime crashes may occur.<br>

**Key API/Component Changes**<br>
type compileMode uses arkcompiler frontend compiler es2abc by default<br>

**Adaptation Guide**
1. When the hvigor version is greater than or equal to 2.6.0-rc.9.s, the developer needs to configure "aotCompileMode": "" in the build-profile.json5 file to switch to the original compilation mode (not type).
