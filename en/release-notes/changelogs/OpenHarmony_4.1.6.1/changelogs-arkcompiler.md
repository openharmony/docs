# Arkcompiler Subsystem changelog

## cl.arkcompiler.1 Changes in Implementation of Arkcompiler ets_frontend and ets_runtime

Changes in Implementation of Arkcompiler ets_frontend and ets_runtime

**Change Since**

OpenHarmony_4.1.6.1

**Reason for Change**

To implements ECMA2022 class new features and sendable class, add some bytecodes.

**Change Description**

Added bytecodes for class:
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

Added bytecodes for sendable class:
1. `callruntime.definesendableclass`
2. `callruntime.ldsendableclass`

**Change Impact**

Because SDK Version OpenHarmony_4.1.6.1 adds bytecodes that need ROM the same version to support，older ROMs in API11 can't run the haps built by SDK Version OpenHarmony_4.1.6.1.

If using SDK Version OpenHarmony_4.1.6.1 and ROM in API10，developers can config `compatiableSdkVersion: 10` option in IDE to build hap which can run on the ROM.

**Phenomenon**

If don't use SDK and ROM in pairs, may lead to one of the following errors:

1. jsCrash: `Load file with filename '/data/storage/el1/bundle/entry/ets/module.abc' failed, recordName 'com.example.myapplication/entry/ets/entryability/EntryAbility' not exists` with hilog: `Unable to open file 'filename' with abc file version 11.0.2.0. Maximum supported abc file version on the current system image is 9.0.0.0. Please upgrade the runtime to supported version or generate byte code with former SDK tools`

2. cppCrash: `Unable to open file 'filename' with abc file version 11.0.2.0. Maximum supported abc file version on the current system image is 11.0.1.0. Please upgrade the system image or use former version of SDK tools to generate abc files`

**How to Solve**

If develops have problem that SDK and ROM in API11 are not compatible , please update ROM to OpenHarmony_4.1.6.1 and above.