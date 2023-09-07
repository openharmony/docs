# 文件管理子系统ChangeLog
## c1.filemanager.1 fileAccess 模块变更
fileAccess 将不支持获取缩略图和媒体资源的部分查询

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



