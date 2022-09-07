# 文件管理开发常见问题



## 调用媒体库getAlbums方法，没有收到返回，也没有捕获到异常是为什么

适用于：OpenHarmony SDK 3.2.5.3版本，API9 Stage模型

getAlbums方法需要权限：ohos.permission.READ_MEDIA，从[OpenHarmony权限定义列表](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/security/permission-list.md)查询知道ohos.permission.READ_MEDIA权限是需要用户授权。

1. 在module.json5中配置权限：
     
   ```
   "requestPermissions": [
     {
       "name": "ohos.permission.READ_MEDIA"
     }
   ]
   ```

2. 在MainAbility.ts -&gt; onWindowStageCreate页面加载前需要增加用户授权代码：
     
   ```
   private requestPermissions() {
   let permissionList: Array<string> = [
     "ohos.permission.READ_MEDIA"
   ];
   this.context.requestPermissionsFromUser(permissionList)
     .then(data => {
       console.info(`request permission data result = ${data.authResults}`)
     })
     .catch(err => {
       console.error(`fail to request permission error:${err}`)
     })
   }
   ```
