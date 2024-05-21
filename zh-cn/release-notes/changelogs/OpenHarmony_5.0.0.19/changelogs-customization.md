# 定制子系统变更说明

## cl.customization.1 configPolicy所属kit变更

**访问级别**

系统接口

**变更原因**

接口所属kit由MDM Kit变更为Basic Services Kit。

**变更影响**

该变更为非兼容性变更。

**变更前：** 通过`import MDMKit from '@kit.MDMKit';`或`import configPolicy form '@ohos.configPolicy';`导入configPolicy。

**变更后：** 通过`import BasicServicesKit from '@kit.MBasicServicesKitt';`或`import configPolicy form '@ohos.configPolicy';`导入configPolicy。

**变更发生版本**

从OpenHarmony SDK 5.0.0.19开始。

**适配指导**

通过`import MDMKit from '@kit.MDMKit';`导入configPolicy，需更换使用`import BasicServicesKit from '@kit.BasicServicesKit';`导入configPolicy。