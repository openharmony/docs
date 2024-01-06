# ArkCompiler Subsystem Changelog

## cl.arkcompiler.1 Removal of ark_asm from SDK

**Access Level**

Other

**Change Reason**

The ark_asm tool was originally designed to compile and generate abc files with ts2abc. However, with the evolution of technology, on the one hand, this solution has been replaced by other solutions due to efficiency reasons; on the other hand, ts2abc has also been replaced and offline by es2abc, so the ark_asm tool has not been involved in the application compilation or development process. After the ark_asm tool is offline, developers can find the changes as shown in the figure below in the toolchains directory of the sdk.

![stack](figures/api11_sdk_toolchains_component_change.png)

**Change Impact**

This change is a compatibility change. Since ark_asm does not participate in the application compilation or development process, upgrading this version of the SDK will not have any impact on developers.

**API Level**

11

**Change Version**

Starting with Openharmony SDK 4.1.5.5

**Change API/Component**

The ark_asm tool in the arkcompiler front-end compiler is offline.

**Adaptation Guide**

It will not cause any impact and no adaptation is required.