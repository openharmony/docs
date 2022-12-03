# 申请授权


应用需要获取用户的隐私信息或使用系统能力时，例如获取位置信息、使用相机拍摄照片或录制视频等，需要向用户申请授权。


在开发过程中，首先需要明确涉及的敏感权限并在config.json中声明需要的权限，同时通过接口requestPermissionsFromUser以动态弹窗的方式向用户申请授权。


在config.json声明需要的权限，在module下添加"reqPermissions"，并写入对应权限。


如申请访问日历权限，需要申请`ohos.permission.READ_CALENDAR`权限，配置方式请参阅[访问控制授权申请指导](../security/accesstoken-guidelines.md#stage%E6%A8%A1%E5%9E%8B)。


  对应config.json文件的示例代码如下所示：

```json
{
  "module": {
    // ...
    "reqPermissions": [
      {
        "name": "ohos.permission.READ_CALENDAR"
        // ...
      }
    ]
  }
}
```


通过动态弹窗向用户申请授权：

```ts
import featureAbility from '@ohos.ability.featureAbility';

let context = featureAbility.getContext();  
let permissions: Array<string> = ['ohos.permission.READ_CALENDAR']
context.requestPermissionsFromUser(permissions, 1).then((data) => {    
    console.info("Succeed to request permission from user with data: " + JSON.stringify(data))
}).catch((error) => {    
    console.info("Failed to request permission from user with error: " + JSON.stringify(error))
})
```
