# 开发准备

应用需要先获取相册管理模块实例，才能访问和修改相册中的媒体数据信息。相册管理模块涉及用户个人数据信息，应用需向用户申请相册管理模块读写权限，才能保证功能的正常运行。在使用相册管理模块相关接口时，如无其他注明则默认在工程代码的pages/index.ets或者其他自创的ets文件中使用。

## 获取相册管理模块实例

应用需要使用应用上下文Context通过接口[getPhotoAccessHelper](../../reference/apis-media-library-kit/arkts-apis-photoAccessHelper-f.md#photoaccesshelpergetphotoaccesshelper)，获取相册管理模块实例，用于访问和修改相册中的媒体数据信息，如图片和视频。

**开发步骤**

1. 导入photoAccessHelper模块以使用相册管理模块相关接口。
2. 通过getContext获取应用上下文。
3. 获取相册管理模块实例。

```ts
import { photoAccessHelper } from '@kit.MediaLibraryKit';
import { common } from '@kit.AbilityKit';

// 此处获取的photoAccessHelper实例为全局对象，后续文档中使用到的地方默认为使用此处获取的对象，如未添加此段代码报未定义的错误请自行添加。
// 请在组件内获取context，确保this.getUiContext().getHostContext()返回结果为UIAbilityContext
@Entry
@Component
struct Index {
  @State outputText: string = '支持的类型为：\n';
  build() {
    Row() {
      Button("example").onClick(async () => {
        let context: Context = this.getUIContext().getHostContext() as common.UIAbilityContext;
        let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
      }).width('100%')
    }
    .height('90%')
  }
}
```

## 申请相册管理模块功能相关权限

相册管理模块的读写操作需要相应权限，在申请权限前，请保证符合[权限使用的基本原则](../../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。涉及的权限如下表。

| 权限名                         | 说明                                       | 授权方式   |
| ------------------------------ | ------------------------------------------ | ---------- |
| ohos.permission.READ_IMAGEVIDEO     | 允许应用读取媒体库的图片和视频媒体文件信息。 | user_grant |
| ohos.permission.WRITE_IMAGEVIDEO    | 允许应用读写媒体库的图片和视频媒体文件信息。 | user_grant |

以上权限的授权方式均为user_grant（用户授权），即开发者在module.json5文件中配置对应的权限后，需要使用接口[abilityAccessCtrl.requestPermissionsFromUser](../../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)去校验当前用户是否已授权。如果已授权，应用可以直接访问/操作目标对象；否则需要弹框向用户申请授权。

**开发步骤**
<!--RP1-->
1. 上述权限均为受控权限，申请前需要额外申请ACL白名单，请参考[声明ACL权限](../../security/AccessToken/declare-permissions-in-acl.md)。 
<!--RP1End-->
2. [在配置文件module.json5中声明权限](../../security/AccessToken/declare-permissions.md)。
3. [向用户申请授权](../../security/AccessToken/request-user-authorization.md)。

> **说明：**
>
> 即使用户曾经授予权限，应用在调用受此权限保护的接口前，也应该先检查是否有权限。不能把之前授予的状态持久化，因为用户在动态授予后还可以通过“设置”取消应用的权限。
