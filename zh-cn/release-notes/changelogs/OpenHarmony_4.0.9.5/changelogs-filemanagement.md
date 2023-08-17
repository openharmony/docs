# 文件管理子系统ChangeLog
## c1.filemanager.1 fileAccess 模块变更
1. fileAccess 将不支持获取缩略图和媒体资源的部分属性查询。
2. uri格式发生变化，开发者无需解析具体格式。如需获取文件名、路径等属性，使用[fileuri接口](../../../application-dev/reference/apis/js-apis-file-fileuri.md)。
3. 文件访问框架管理的资源范围发生变化，不再支持访问媒体库管理的资源。目前文件访问框架支持以下目录：
- 外部存储目录
- Docs目录
- Download目录
- Desktop目录
- Documents目录
- Share共享盘目录
4. 从文件访问框架获取的uri， 推荐使用[fs接口](../../../application-dev/reference/apis/js-apis-file-fs.md)打开。

**变更影响**
1. getThumbnail 接口下架
2. FILEKEY 图像和音频选项下架

**关键的接口/组件变更**
删除接口如下

| 类名           | 删除接口声明                                                 |
| -------------- | ------------------------------------------------------------ |
| fileAccessHelper | getThumbnail(uri: string, size: image.Size): Promise<image.PixelMap>;|
| fileAccessHelper | getThumbnail(uri: string, size: image.Size, callback: AsyncCallback<image.PixelMap>): void;|

 选项删除
| 枚举类型 | 删除的键值 |
| -------- | ---- |
| FileKey | DURATION = 'duration' |
| FileKey | WIDTH = 'width' |
| FileKey | HEIGHT = 'height' |



