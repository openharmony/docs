# multimedia子系统ChangeLog

## cl.multimedia.1 PhotoAccessHelper的getAlbums, 和UserFileManager的getAlbums，getPhotoAlbums接口不再支持获取隐藏相册

API11进一步限制了获取隐藏相册的能力，需要使用getHiddenAlbums接口且申请必要的权限才允许获取隐藏相册。之前的获取相册接口不再允许获取隐藏相册。

**变更影响**

受影响接口为systemapi，变更后获取隐藏相册的查询结果将返回空。

**适配指导**

如开发者需要获取隐藏相册，需要使用API11提供的getHiddenAlbums接口。