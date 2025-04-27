# 驱动子系统 USB设备HDI接口 Changelog

## UsbTypes.idl行为变更

**访问级别**

公开接口

**变更原因**

USB子系统进行Feature化改造，将原有HDI接口拆分为HOST、Device、Port三种Feature。

**变更影响**

该变更为不兼容变更。

变更前：UsbTypes.idl中的类型分别存放在V1_0、V1_1和V1_2版本的UsbTypes.idl文件中，向下兼容。

变更后：原V1_0、V1_1和V1_2版本UsbTypes.idl文件中的所有类型转移到V2.0版本的UsbTypes.idl文件中，大版本不向下兼容。

**起始API Level**

API 18

**变更发生版本**

从OpenHarmony 5.1.0.48 版本开始。

**变更的接口/组件**

无变更接口

**适配指导**

默认行为变更，无需适配。
