# 访问控制授权申请指导

## 场景介绍

以下示例代码基于此场景假设：应用因为应用核心功能诉求，需要申请权限"ohos.permission.PERMISSION1"和权限"ohos.permission.PERMISSION2"。

- 应用的APL等级为normal。
- 权限"ohos.permission.PERMISSION1"的权限等级为normal，权限类型为system_grant。
- 权限"ohos.permission.PERMISSION2"的权限等级为system_basic, 权限类型为user_grant。

> **注意：** 
>
> 当前场景下，应用申请的权限包括了user_grant权限，对这部分user_grant权限，可以先通过权限校验，判断当前调用者是否具备相应权限。
>
> 当权限校验结果显示当前应用尚未被授权该权限时，再通过动态弹框授权方式给用户提供手动授权入口。

应用可申请的权限，可查询[应用权限列表](permission-list.md)

## 接口说明

以下仅列举本指导使用的接口，更多说明可以查阅[API参考](../reference/apis/js-apis-ability-context.md)。

| 接口名                                                       | 描述                                             |
| ------------------------------------------------------------ | --------------------------------------------------- |
| requestPermissionsFromUser(permissions: Array&lt;string&gt;, requestCallback: AsyncCallback&lt;PermissionRequestResult&gt;) : void; | 拉起弹窗请求用户授权。 |

## 权限申请声明

应用需要在工程配置文件中，对需要的权限逐个声明，没有在配置文件中声明的权限，应用将无法获得授权。Ability框架提供了两种模型，分别为FA模型和Stage模型，更多信息可以参考[Ability框架概述](../ability/ability-brief.md)。

不同的Ability框架模型的应用包结构不同，所使用的配置文件不同，请开发者在申请权限时注意区分。

配置文件标签说明如下表。

| 标签      | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| name      | 权限名称。                                                   |
| reason    | 当申请的权限为user_grant权限时，此字段必填，描述申请权限的原因。 |
| usedScene | 当申请的权限为user_grant权限时，此字段必填，描述权限使用的场景和时机。 |
| ability   | 标识需要使用到该权限的Ability，标签为数组形式。   <br/>**适用模型：** FA模型            |
| abilities | 标识需要使用到该权限的Ability，标签为数组形式。   <br/>**适用模型：** Stage模型            |
| when      | 标识权限使用的时机，值为"inuse/always"，表示为仅允许前台使用和前后台都可使用。 |

### FA模型

使用FA模型的应用，需要在config.json文件中声明权限。

**示例：**

```json
{
  "module" : {
    "reqPermissions":[
      {
        "name" : "ohos.permission.PERMISSION1",
        "reason": "$string:reason",
        "usedScene": {
          "ability": [
            "FormAbility"
          ],
          "when":"inuse"
        }
      },
      {
        "name" : "ohos.permission.PERMISSION2",
        "reason": "$string:reason",
        "usedScene": {
          "ability": [
            "FormAbility"
          ],
          "when":"always"
        }
      }
    ]
  }
}
```

### Stage模型

使用Stage模型的应用，需要在module.json5文件中声明权限。

**示例：**

```json
{
  "module" : {
    "requestPermissions":[
      {
        "name" : "ohos.permission.PERMISSION1",
        "reason": "$string:reason",
        "usedScene": {
          "abilities": [
            "FormAbility"
          ],
          "when":"inuse"
        }
      },
      {
        "name" : "ohos.permission.PERMISSION2",
        "reason": "$string:reason",
        "usedScene": {
          "abilities": [
            "FormAbility"
          ],
          "when":"always"
        }
      }
    ]
  }
}
```

## ACL方式声明

如上述示例所示，权限"ohos.permission.PERMISSION2"的权限等级为system_basic，高于此时应用的APL等级，开发者的最佳做法是使用ACL方式。

在配置文件声明的基础上，应用还需要在Profile文件中声明不满足申请条件部分的权限。Profile文件的字段说明可参考[HarmonyAppProvision配置文件的说明](app-provision-structure.md)。

该场景中，开发者应该在字段"acls"中做声明如下：

```json
{
  "acls": {
    "allowed-acls": [
      "ohos.permission.PERMISSION2"
    ]
  }
}
```

## 申请授权user_grant权限

在前期的权限声明步骤后，在安装过程中系统会对system_grant类型的权限进行权限预授权，而user_grant类型权限则需要用户进行手动授权。

所以，应用在调用受"ohos.permission.PERMISSION2"权限保护的接口前，需要先校验应用是否已经获取该权限。

如果校验结果显示，应用已经获取了该权限，那么应用可以直接访问该目标接口，否则，应用需要通过动态弹框先申请用户授权，并根据授权结果进行相应处理，处理方式可参考[访问控制开发概述](accesstoken-overview.md)。

> **注意：**
>
> 不能把之前授予的状态持久化，每次访问受目标权限保护的接口前，都应该调用requestPermissionsFromUser接口请求权限，因为用户在动态授予后可能通过设置取消应用的权限。

## 完整示例

请求用户授权权限的开发步骤为：

1. 获取ability的上下文context。
2. 调用requestPermissionsFromUser接口请求权限。运行过程中，该接口会根据应用是否已获得目标权限决定是否拉起动态弹框请求用户授权。
3. 根据requestPermissionsFromUser接口返回值判断是否已获取目标权限。如果当前已经获取权限，则可以继续正常访问目标接口。

```js
  //ability的onWindowStageCreate生命周期
  onWindowStageCreate() {
    var context = this.context
    let array:Array<string> = ["ohos.permission.PERMISSION2"];
    //requestPermissionsFromUser会判断权限的授权状态来决定是否唤起弹窗
    context.requestPermissionsFromUser(array).then(function(data) {
      console.log("data type:" + typeof(data));
      console.log("data:" + data);
      console.log("data permissions:" + data.permissions);
      console.log("data result:" + data.authResults);
    }, (err) => {
      console.error('Failed to start ability', err.code);
    });
  }

```
> **说明：**
> 动态授权申请接口的使用详见[API参考](../reference/apis/js-apis-ability-context.md)。

## user_grant权限预授权
当前正常情况下，user_grant类型的权限默认不授权，需要时应通过拉起弹框由用户确认是否授予。对于一些预置应用，比如截屏应用，不希望出现弹框，则可以通过预授权的方式完成user_grant类型权限的授权。[预置配置文件](https://gitee.com/openharmony/vendor_hihope/blob/master/rk3568/preinstall-config/install_list_permissions.json)在设备上的路径为system/etc/app/install_list_permission.json，设备开机启动时会读取该配置文件，在应用安装会对在文件中配置的user_grant类型权限授权。当前仅支持预置应用配置该文件。
预授权配置文件字段内容包括bundleName、app_signature、permissions。
1. 这里的权限仅对user_grant类型的权限生效[查看权限等级和类型](permission-list.md)。
2. userCancellable配置为true，表示支持用户取消授权，为false则表示不支持用户取消授权。

```json
[
  {
    "bundleName": "com.ohos.myapplication", // 包名
    "app_signature":[], // 指纹信息
    "permissions":[
      {
        "name":"xxxx", // 权限名，不可缺省
        "userCancellable":false // 用户不可取消授权，不可缺省
      },
      {
        "name":"yyy", // 权限名，不可缺省
        "userCancellable":true // 用户可取消授权，不可缺省
      }
    ]
  }
]
```
## 相关实例

针对访问控制，有以下相关实例可供参考：

- [`AbilityAccessCtrl`：访问权限控制（ArkTS）（API8）（Full SDK）](https://gitee.com/openharmony/applications_app_samples/tree/master/Safety/AbilityAccessCtrl)
- [为应用添加运行时权限（ArkTS）（API 9）](https://gitee.com/openharmony/codelabs/tree/master/Ability/AccessPermission)