# Media Library Kit 简介

Media Library Kit提供了管理相册和媒体文件的能力，包括照片和视频，帮助你的应用快速构建图片视频展示和播放能力。

## 能力范围
通过Media Library Kit, 开发者可以管理相册和媒体文件，包括创建相册以及访问、修改相册中的媒体信息等，其中对三方应用开放的能力有：
- [媒体资源（图片、视频）相关](photoAccessHelper-resource-guidelines.md)，包括：
  - 获取指定媒体资源
  - 获取图片和视频缩略图
  - 创建媒体资源（安全控件）
  - 重命名媒体资源
- [用户相册相关](photoAccessHelper-userAlbum-guidelines.md)，包括：
  - 获取用户相册
  - 重命名用户相册
  - 添加图片和视频到用户相册中
  - 获取用户相册中的图片和视频
  - 从用户相册中移除图片和视频
- [系统相册相关](photoAccessHelper-systemAlbum-guidelines.md)，包括：
  - 收藏夹
  - 视频相册
  - 截屏和录屏相册
- [媒体资源（图片、视频和相册）变更通知相关](photoAccessHelper-notify-guidelines.md)，包括：
  - 注册对指定URI的监听
  - 取消指定URI的监听

还为系统应用开放如下能力：
- 媒体资源增删操作，包括：
  - 创建媒体资源
  - 将媒体资源放入回收站
  - 永久删除媒体资源
- 相册相关操作，包括：
  - 创建用户相册
  - 删除用户相册
  - 隐藏相册
  - 设置收藏和取消收藏


## 亮点/特征

- 对象化API设计，简洁高效，接入便捷。
- 端云一体化访问管理。
- 安全精准强管控，picker和保存空间自动授权。
- 智能格式转化，框架层统一完成转化。

## 框架原理

媒体库接收用户对媒体资产的获取与变更请求，进行请求合法性检查和权限校验，通过后与数据库进行交互，并返回请求结果。

## 约束与限制

相册管理模块涉及用户个人数据信息，所以应用需要向用户申请相册管理模块读写操作权限才能保证功能的正常运行。
在申请权限前，请保证符合[权限使用的基本原则](../security/AccessToken/app-permission-mgmt-overview.md#权限使用的基本原则)。涉及的权限如下表。申请方式请参考[向用户申请授权](../security/AccessToken/request-user-authorization.md)。

| 权限名                         | 说明                                       | 授权方式   |
| ------------------------------ | ------------------------------------------ | ---------- |
| ohos.permission.READ_IMAGEVIDEO     | 允许应用读取用户外部存储中的图片和视频媒体文件信息。 | user_grant |
| ohos.permission.WRITE_IMAGEVIDEO    | 允许应用读写用户外部存储中的图片和视频媒体文件信息。 | user_grant |
