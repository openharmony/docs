# 媒体库开发概述

MediaLibrary提供媒体库相关能力，帮助开发者更方便地访问和修改媒体文件，具体分为：

- [媒体资源（音频、视频、图片文件等）相关](medialibrary-resource-guidelines.md)，包括：
  - 查询指定媒体资源
  - 获取图片/视频
  - 获取图片/视频缩略图
  - 创建媒体资源
  - 重命名媒体资源
  - 将媒体资源放入回收站
- [文件路径相关](medialibrary-filepath-guidelines.md)，包括：
  - 获取文件保存的公共目录
  - 沙箱与公共路径间文件的复制
  - 读写文件内容
- [相册相关](medialibrary-album-guidelines.md)，包括：
  - 获取相册中的图片/视频
  - 创建相册
  - 重命名相册

> **说明：**<br/>
> 本开发指导基于API Version 9，仅适用于Stage模型。

应用需要先获取媒体库实例，才能访问和修改用户等个人媒体数据信息。媒体库涉及用户个人数据信息，所以应用需要向用户申请媒体库读写操作权限才能保证功能的正常运行。

开发者在使用MediaLibrary进行功能开发前，请先掌握以下内容：

- [获取媒体库实例](#获取媒体库实例)
- [申请媒体库功能相关权限](#申请媒体库功能相关权限)

## 获取媒体库实例

应用需要使用应用上下文Context通过接口[getMediaLibrary](../reference/apis/js-apis-medialibrary.md#medialibrarygetmedialibrary8)，获取媒体库实例，用于访问和修改用户等个人媒体数据信息（如音频、视频、图片、文档等）。

**开发步骤**

1. 导入mediaLibrary模块以使用媒体库相关接口。
2. 通过getContext获取应用上下文。
3. 获取媒体库实例。

```ts
import mediaLibrary from '@ohos.multimedia.mediaLibrary';

const context = getContext(this);
var media = mediaLibrary.getMediaLibrary(context);
```

## 申请媒体库功能相关权限

媒体库的读写操作需要相应权限，在申请权限前，请保证符合[权限使用的基本原则](../security/accesstoken-overview.md#权限使用的基本原则)。涉及的权限如下表。

| 权限名                         | 说明                                       | 授权方式   |
| ------------------------------ | ------------------------------------------ | ---------- |
| ohos.permission.READ_MEDIA     | 允许应用读取用户外部存储中的媒体文件信息。 | user_grant |
| ohos.permission.WRITE_MEDIA    | 允许应用读写用户外部存储中的媒体文件信息。 | user_grant |
| ohos.permission.MEDIA_LOCATION | 允许应用访问用户媒体文件中的地理位置信息。 | user_grant |

以上权限的授权方式均为user_grant（用户授权），即开发者在module.json5文件中配置对应的权限后，需要使用接口[Context.requestPermissionsFromUser](../reference/apis/js-apis-ability-context.md#abilitycontextrequestpermissionsfromuser)去校验当前用户是否已授权。如果是，应用可以直接访问/操作目标对象；否则需要弹框向用户申请授权。

> **说明：**<br/>即使用户曾经授予权限，应用在调用受此权限保护的接口前，也应该先检查是否有权限。不能把之前授予的状态持久化，因为用户在动态授予后还可以通过“设置”取消应用的权限。

**开发步骤**

1. 在配置文件module.json5中声明权限。在配置文件的“module”标签内，增加“requestPermissions”标签，标签内容请根据实际情况填写。标签说明可参考[访问控制（权限）开发指导](../security/accesstoken-guidelines.md)。

   ```json
   {
       "module": {
           "requestPermissions": [
               {
                   "name": "ohos.permission.MEDIA_LOCATION",
                   "reason": "$string:reason",
                   "usedScene": {
                       "abilities": [
                         "MainAbility"
                       ],
                       "when": "always"
               }
               },
               {
                   "name": "ohos.permission.READ_MEDIA",
                   "reason": "$string:reason",
                   "usedScene": {
                       "abilities": [
                           "MainAbility"
                       ],
                       "when": "always"
                   }
               },
               {
                   "name": "ohos.permission.WRITE_MEDIA",
                   "reason": "$string:reason",
                   "usedScene": {
                       "abilities": [
                           "MainAbility"
                       ],
                       "when": "always"
                   }
               }
           ]
       }
   }    
   ```

2. 调用requestPermissionsFromUser进行权限校验，可以选择需要动态申请获取的权限。

   ```ts
   import Ability from '@ohos.application.Ability'
   
   export default class MainAbility extends Ability {
       onWindowStageCreate(windowStage) {
           var permissions=['ohos.permission.READ_MEDIA','ohos.permission.WRITE_MEDIA']
           var permissionRequestResult;
           this.context.requestPermissionsFromUser(permissions,(err,result) => {
               if(err){
                   console.log('requestPermissionsFromUserError: ' + JSON.stringify(err));
               }else{
                   permissionRequestResult=result;
                   console.log('permissionRequestResult: ' + JSON.stringify(permissionRequestResult));
               }    
           });       
       }
   }
   ```

   