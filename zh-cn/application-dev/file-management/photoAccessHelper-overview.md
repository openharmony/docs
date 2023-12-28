# 相册管理模块开发概述

PhotoAccessHelper提供相册管理模块相关能力，包括创建相册以及访问、修改相册中的媒体数据信息等，具体分为：

- [媒体资源（图片、视频）相关](photoAccessHelper-resource-guidelines.md)，包括：
  - 获取指定媒体资源
  - 获取图片和视频缩略图
  - 创建媒体资源
  - 重命名媒体资源
  - 将媒体资源放入回收站
- [用户相册相关](photoAccessHelper-userAlbum-guidelines.md)，包括：
  - 创建用户相册
  - 获取用户相册
  - 重命名用户相册
  - 添加图片和视频到用户相册中
  - 获取用户相册中的图片和视频
  - 从用户相册中移除图片和视频
  - 删除用户相册
- [系统相册相关](photoAccessHelper-systemAlbum-guidelines.md)，包括：
  - 收藏夹
  - 视频相册
  - 截屏和录屏相册
- [媒体资源（图片、视频和相册）变更通知相关](photoAccessHelper-notify-guidelines.md)，包括：
  - 注册对指定URI的监听
  - 取消指定URI的监听

> **说明：**
>
> 本开发指导基于API Version 10，仅适用于Stage模型。

应用需要先获取相册管理模块实例，才能访问和修改相册中的媒体数据信息。相册管理模块涉及用户个人数据信息，所以应用需要向用户申请相册管理模块读写操作权限才能保证功能的正常运行。在使用相册管理模块相关接口时如无其他注明则默认在工程代码的pages/index.ets或者其他自创的ets文件中使用。

开发者在使用PhotoAccessHelper进行功能开发前，请先掌握以下内容：

- [相册管理模块开发概述](#相册管理模块开发概述)
  - [获取相册管理模块实例](#获取相册管理模块实例)
  - [申请相册管理模块功能相关权限](#申请相册管理模块功能相关权限)

## 获取相册管理模块实例

应用需要使用应用上下文Context通过接口[getPhotoAccessHelper](../reference/apis/js-apis-photoAccessHelper.md#photoaccesshelpergetphotoaccesshelper)，获取相册管理模块实例，用于访问和修改相册中媒体数据信息（如图片、视频）。

**开发步骤：**

1. 导入photoAccessHelper模块以使用相册管理模块相关接口。
2. 通过getContext获取应用上下文。
3. 获取相册管理模块实例。

```ts
import photoAccessHelper from '@ohos.file.photoAccessHelper';

// 此处获取的photoAccessHelper实例为全局对象，后续文档中使用到的地方默认为使用此处获取的对象，如未添加此段代码报未定义的错误请自行添加。
const context = getContext(this);
let phAccessHelper = photoAccessHelper.getPhotoAccessHelper(context);
```

## 申请相册管理模块功能相关权限

相册管理模块的读写操作需要相应权限，在申请权限前，请保证符合[权限使用的基本原则](../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。涉及的权限如下表。

| 权限名                         | 说明                                       | 授权方式   |
| ------------------------------ | ------------------------------------------ | ---------- |
| ohos.permission.READ_IMAGEVIDEO     | 允许应用读取用户外部存储中的图片和视频媒体文件信息。 | user_grant |
| ohos.permission.WRITE_IMAGEVIDEO    | 允许应用读写用户外部存储中的图片和视频媒体文件信息。 | user_grant |

以上权限的授权方式均为user_grant（用户授权），即开发者在module.json5文件中配置对应的权限后，需要使用接口[abilityAccessCtrl.requestPermissionsFromUser](../reference/apis/js-apis-abilityAccessCtrl.md#requestpermissionsfromuser9)去校验当前用户是否已授权。如果是，应用可以直接访问/操作目标对象；否则需要弹框向用户申请授权。

**开发步骤参考：**

1. [在配置文件module.json5中声明权限](../security/AccessToken/declare-permissions.md)。
2. [向用户申请授权](../security/AccessToken/request-user-authorization.md)。

> **说明：**
>
> 即使用户曾经授予权限，应用在调用受此权限保护的接口前，也应该先检查是否有权限。不能把之前授予的状态持久化，因为用户在动态授予后还可以通过“设置”取消应用的权限。
