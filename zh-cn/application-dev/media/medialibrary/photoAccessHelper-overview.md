# Media Library Kit 简介

Media Library Kit（媒体文件管理服务）提供了管理相册和媒体文件的能力，包括照片和视频，帮助你的应用快速构建图片视频展示和播放能力。

## 能力范围

通过Media Library Kit，开发者可以管理相册和媒体文件，包括创建相册以及访问、修改相册中的媒体信息等。

面向**所有应用**开放如下能力：

- 选择/保存媒体库资源
  - [使用Picker选择媒体库资源](photoAccessHelper-photoviewpicker.md)
  - [保存媒体库资源](photoAccessHelper-savebutton.md)
- 管理动态照片
  - [访问和管理动态照片资源](photoAccessHelper-movingphoto.md)
  - [使用MovingPhotoView播放动态照片](movingphotoview-guidelines.md)
<!--RP2--><!--RP2End-->

面向**三方应用受限**开放如下能力：

> **注意：**
> 受限开放的能力需要[申请相册管理模块的读写操作权限](photoAccessHelper-preparation.md#申请相册管理模块功能相关权限)。<!--RP1-->这部分权限受限开放。<!--RP1End-->

- [媒体资源（图片、视频）相关](photoAccessHelper-resource-guidelines.md)，包括：
  - 获取指定媒体资源。
  - 获取图片和视频缩略图。
  - 重命名媒体资源。
- [用户相册相关](photoAccessHelper-userAlbum-guidelines.md)，包括：
  - 获取用户相册。
  - 重命名用户相册。
  - 添加图片和视频到用户相册中。
  - 获取用户相册中的图片和视频。
  - 从用户相册中移除图片和视频。
- [系统相册相关](photoAccessHelper-systemAlbum-guidelines.md)，包括：
  - 收藏夹。
  - 视频相册。
- [媒体资源（图片、视频和相册）变更通知相关](photoAccessHelper-notify-guidelines.md)，包括：
  - 注册对指定URI的监听。
  - 取消指定URI的监听。

<!--Del-->
面向**系统应用**开放如下能力：

- 媒体资源增删操作，包括：
  - 创建媒体资源。
  - 将媒体资源放入回收站。
  - 永久删除媒体资源。

- 相册相关操作，包括：
  - 创建用户相册。
  - 删除用户相册。
  - 隐藏相册。
  - 设置收藏和取消收藏。
  - 使用截屏和录屏相册。
<!--DelEnd-->

## 亮点/特征

- 对象化API设计，简洁高效，接入便捷。
- 端云一体化访问管理。
- 安全精准强管控，picker和保存空间自动授权。
- 智能格式转化，框架层统一完成转化。

## 框架原理

媒体库接收用户对媒体资产的获取与变更请求，进行请求合法性检查和权限校验，通过后与数据库进行交互，并返回请求结果。
