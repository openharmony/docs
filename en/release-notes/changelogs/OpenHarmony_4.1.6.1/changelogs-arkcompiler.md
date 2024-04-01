# ArkCompiler Subsystem Changelog

## cl.arkcompiler.1 Change in ArkCompiler Internal Implementation

Changed the internal implementation of ArkCompiler.

**Change Since**

OpenHarmony_4.1.6.1

**Reason for Change**

To implement the ECMAScript 2022 class and sendable class features, new bytecodes are required.

**Change Description**

The following bytecodes are added to the class feature:
1. `definefieldbyname`
2. `callruntime.definefieldbyvalue`
3. `callruntime.definefieldbyindex`
4. `callruntime.defineprivateproperty`
5. `callruntime.callinit`
6. `callruntime.createprivateproperty`
7. `callruntime.topropertykey`
8. `ldprivateproperty`
9. `stprivateproperty`
10. `testin`

The following bytecodes are added to the sendable class:
1. `callruntime.definesendableclass`
2. `callruntime.ldsendableclass`

**Change Impact**

The new bytecodes added in SDK OpenHarmony_4.1.6.1 require support from ROM in the same version. Therefore, earlier ROM in API version 11 cannot run the HAPs built by SDK OpenHarmony_4.1.6.1.

If you are using SDK OpenHarmony_4.1.6.1 and ROM in API version 10, you can set the **compatiableSdkVersion: 10** option from DevEco Studio to build a HAP that can run on the ROM.

**Symptom**

If the SDK and ROM do not match, the following errors may occur:

1. jsCrash: `Load file with filename '/data/storage/el1/bundle/entry/ets/module.abc' failed, recordName 'com.example.myapplication/entry/ets/entryability/EntryAbility' not exists` along with hilog: `Unable to open file 'filename' with abc file version 11.0.2.0. Maximum supported abc file version on the current system image is 9.0.0.0. Please upgrade the runtime to supported version or generate byte code with former SDK tools`

2. cppCrash: `Unable to open file 'filename' with abc file version 11.0.2.0. Maximum supported abc file version on the current system image is 11.0.1.0. Please upgrade the system image or use former version of SDK tools to generate abc files`

**Solution**

Update the ROM to OpenHarmony_4.1.6.1 or later.
