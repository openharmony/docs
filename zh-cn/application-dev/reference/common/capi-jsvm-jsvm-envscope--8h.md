# JSVM_EnvScope__*
<!--Kit: Common Basic Capability-->
<!--Subsystem: arkcompiler-->
<!--Owner: @yuanxiaogou; @string_sz-->
<!--SE: @knightaoko-->
<!--TSE: @test_lzz-->

## 概述

表示用于控制附加到当前虚拟机实例的环境。只有当线程通过OH_JSVM_OpenEnvScope进入该环境的JSVM_EnvScope后，该环境才对线程的虚拟机实例可用。

**起始版本：** 11

**相关模块：** [JSVM](capi-jsvm.md)

**所在头文件：** [jsvm_types.h](capi-jsvm-types-h.md)

