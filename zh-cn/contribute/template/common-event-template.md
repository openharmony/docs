# 系统公共事件定义

## 写作要求

1. Public接口、系统接口分为两个文档独立维护。

    - Public接口：zh-cn/application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions.md
    - 系统接口：zh-cn/application-dev/reference/apis-basic-services-kit/common_event/commonEventManager-definitions-sys.md

    > 说明：
    >
    > 当前很多接口为系统接口，但是在的d.ts文件中没有打@systemAapi标签，只是有类似下面的文字说明，甚至没有任何说明，需要提单修改。 
    > - This API can be called only by system applications. 
    > - This common event can be triggered only by system. 
    > - This is a protected common event that can only be sent by system. 

2. Kit名称作为二级标题，事件名称作为三级标题。




## 模板：xxx Kit

### 事件名称<sup>版本号+</sup>

描述事件含义与功能。

说明事件触发场景/触发条件。

**系统接口：** 此接口为系统接口。

**系统能力：** SystemCapability.Notification.CommonEvent

**订阅者所需权限：** xxx

**原子化服务API：** 从API version xx开始，该接口支持在原子化服务中使用。

**取值：** "xxx"




## 示例：Ability Kit

### COMMON_EVENT_BOOT_COMPLETED<sup>9+</sup>

表示用户已完成引导并加载系统。

在设备上指定用户已完成引导并加载系统，将会触发事件通知服务发布该系统公共事件。

**系统接口：** 此接口为系统接口。

**订阅者所需权限：** ohos.permission.RECEIVER_STARTUP_COMPLETED（该权限仅系统应用可申请）

**系统能力：** SystemCapability.Notification.CommonEvent

**取值：** "usual.event.BOOT_COMPLETED"

