# multimedia变更说明

## cl.multimedia.1 PhotoAccessHelper的getAlbums, 和UserFileManager的getAlbums，getPhotoAlbums接口变更

**访问级别**

系统接口

**变更原因**

出于用户隐私保护需求，API11进一步限制了获取隐藏相册的能力，需要使用getHiddenAlbums接口且申请必要的权限才允许获取隐藏相册。之前的获取相册接口不再允许获取隐藏相册。

**变更影响**

该变更为非兼容性变更。上述接口将不支持获取隐藏相册。只影响systemapi，需要图库做对应适配，对三方应用没有影响。

*起始 API Level*

11，接口起始level

**变更发生版本**

从OpenHarmony SDK <4.1.6.7> 开始