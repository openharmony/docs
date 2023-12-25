# arkcompiler子系统ChangeLog

## cl.arkcompiler.1 sdk中ark_asm下线

**访问级别**

其他

**变更原因**

ark_asm工具最初设计是为了配合ts2abc编译生成abc文件。但随着技术演进，一方面该方案由于效率原因已经被其他方案替代；另一方面，ts2abc也已经被es2abc替代下线，因此ark_asm工具一直没有参与到应用编译或开发流程中。ark_asm工具下线后，开发者可以在sdk的toolchains目录下发现如下图所示的变更。

![stack](figures/api11_sdk_toolchains_component_change.png)

**变更影响**

该变更为兼容性变更。由于ark_asm并不参与应用编译或开发流程，升级该版本的sdk后，对开发者不会有任何影响。

**API Level**

11

**变更发生版本**

从Openharmony SDK 4.1.5.5 开始

**变更的接口/组件**

arkcompiler前端编译器中的ark_asm工具下线。

**适配指导**

不会造成任何影响，不需要做适配。