# 申请授权

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @lidongrui-->
<!--Designer: @ccllee1-->
<!--Tester: @lixueqing513-->
<!--Adviser: @huipeizi-->

应用需要获取用户的隐私信息或使用系统能力时，例如获取位置信息、使用相机拍摄照片或录制视频等，需要向用户申请授权。


在开发过程中，首先需要明确涉及的敏感权限并在config.json中声明需要的权限，同时通过接口requestPermissionsFromUser以动态弹窗的方式向用户申请授权。


在config.json声明需要的权限，在module下添加"reqPermissions"，并写入对应权限。

例如申请访问日历权限：

1. 需要申请`ohos.permission.DISTRIBUTED_DATASYNC`权限，配置方式请参见[声明权限](../security/AccessToken/declare-permissions.md)。
2. 同时需要在应用首次启动时弹窗向用户申请授权，使用方式请参见[向用户申请授权](../security/AccessToken/request-user-authorization.md)。
