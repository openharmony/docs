# arkcompiler子系统变更说明

## cl.arkcompiler.1 arkcompiler内部实现变更

arkcompiler内部实现变更

**引入版本**

OpenHarmony_4.1.6.1

**变更原因**

为实现ECMA2022 class新特性和sendable class特性，需新增字节码

**变更说明**

class 特性新增字节码：
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

sendable class新增字节码：
1. `callruntime.definesendableclass`
2. `callruntime.ldsendableclass`

**变更影响**

OpenHarmony SDK版本4.1.6.1增加新字节码，相关字节码实现需要对应版本ROM来支持。如果使用API11版本的ROM，4.1.6.1版本之前的ROM无法运行4.1.6.1版本SDK编译出的应用。

如果使用API 10版本的ROM以及4.1.6.1版本的SDK，开发者仍然可以通过IDE界面配置`compatiableSdkVersion: 10`选项，编译生成可以运行在API10 ROM上的应用。

**现象**

如未配套使用SDK和ROM，可能导致下列错误之一：

1. jsCrash: `Load file with filename '/data/storage/el1/bundle/entry/ets/module.abc' failed, recordName 'com.example.myapplication/entry/ets/entryability/EntryAbility' not exists` 伴随着hilog: `Unable to open file 'filename' with abc file version 11.0.2.0. Maximum supported abc file version on the current system image is 9.0.0.0. Please upgrade the runtime to supported version or generate byte code with former SDK tools`

2. cppCrash: `Unable to open file 'filename' with abc file version 11.0.2.0. Maximum supported abc file version on the current system image is 11.0.1.0. Please upgrade the system image or use former version of SDK tools to generate abc files`

**如何解决**

如遇到API11 SDK和ROM版本不匹配导致应用无法运行问题，请升级ROM版本至OpenHarmony_4.1.6.1及以上。
