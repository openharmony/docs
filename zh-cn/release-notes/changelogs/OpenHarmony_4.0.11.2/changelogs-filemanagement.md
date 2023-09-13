# 文件管理子系统ChangeLog

## c1.filemanager.1 fileAccess模块变更

1. 文件访问框架管理的资源范围发生变化，不再支持访问媒体库管理的资源。目前文件访问框架支持以下目录：
   - 外部存储目录
   - Docs目录
   - Download目录
   - Desktop目录
   - Documents目录
   - Share共享盘目录

   fileAccess将不再支持获取缩略图和媒体资源的部分属性查询。

2. uri格式发生变化，开发者无需解析具体格式。

**变更影响**

基于此前版本开发的应用，请排查是否有使用媒体库的接口操作通过fileAccess获取的uri，将会无法达成预期结果。

**关键的接口/组件变更**

删除接口如下

| 类名           | 删除接口声明                                                 |
| -------------- | ------------------------------------------------------------ |
| fileAccessHelper | getThumbnail(uri: string, size: image.Size, callback: AsyncCallback<image.PixelMap>): void;|

枚举FileKey删除部分值：

| 枚举类型 | 删除的键值 |
| -------- | ---- |
| FileKey | DURATION = 'duration' |
| FileKey | WIDTH = 'width' |
| FileKey | HEIGHT = 'height' |

**适配指导**

fileAccess的接口调用无变化，但接口返回的uri可访问的资源发生变化。

如需获取文件名、路径等属性，请使用[fileuri接口](../../../application-dev/reference/apis/js-apis-file-fileuri.md)。

使用文件访问框架的接口获取的uri，推荐使用[fs接口](../../../application-dev/reference/apis/js-apis-file-fs.md)打开。

