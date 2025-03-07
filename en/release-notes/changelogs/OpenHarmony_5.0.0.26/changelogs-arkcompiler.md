# ArkCompiler Subsystem Changelog

## cl.arkcompiler.1 New Naming Rules of ArkTS Bytecode Functions

**Access Level**

Others

**Reason for Change**

To help you accurately distinguish different functions, new function naming rules are introduced.

**Change Impact**

Before the change, only the original function name is used, and **hash** is used to distinguish functions with the same name. It is difficult to tell the differences. After the change, the concept of scope label is introduced so that functions can be accurately identified. The bytecode file generated after the change cannot run on the VM of an earlier version.

**Start API Level**

API version 12

**Change Since**

OpenHarmony SDK 5.0.0.26

**Key API/Component Changes**

N/A

**Adaptation Guide**

No adaptation is required. For details, see [Naming Rules of ArkTS Bytecode Functions](../../../application-dev/quick-start/arkts-bytecode-function-name.md).
