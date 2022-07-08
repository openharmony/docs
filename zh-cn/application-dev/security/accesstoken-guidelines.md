# 访问控制开发指导

## 场景介绍

以下示例代码基于此场景假设：应用因为应用核心功能诉求，需要申请权限"ohos.permission.PERMISSION1"和权限"ohos.permission.PERMISSION2"。

- 应用的APL等级为normal。
- 权限"ohos.permission.PERMISSION1"的权限等级为normal，权限类型为system_grant。
- 权限"ohos.permission.PERMISSION2"的权限等级为system_basic, 权限类型为user_grant。

> **注意事项：** 
>
> 当前场景下，应用申请的权限包括了user_grant权限，对这部分user_grant权限，可以先通过权限校验，判断当前调用者是否具备相应权限。
>
> 当权限校验结果显示当前应用尚未被授权该权限时，再通过动态弹框授权方式给用户提供手动授权入口。
>
## 接口说明

以下仅列举本指导使用的接口，更多说明可以查阅[API参考](../reference/apis/js-apis-abilityAccessCtrl.md)。

| 接口名                                                       | 描述                                             |
| ------------------------------------------------------------ | --------------------------------------------------- |
| verifyAccessToken(tokenID: number, permissionName: string): Promise&lt;GrantStatus&gt; | 校验应用是否授予权限，使用Promise方式异步返回结果。 |

## 权限申请声明

### FA模型 config.json文件声明

FA模型中应用需要在config.json文件中对需要的权限逐个进行声明。没有在config.json中声明的权限，应用无法获得此应用授权。

**config.json标签说明：**

| 标签      | 说明                                                         |
| --------- | ------------------------------------------------------------ |
| name      | 权限名称。                                                   |
| reason    | 当申请的权限为user_grant权限时，此字段必填，描述申请权限的原因。 |
| usedScene | 当申请的权限为user_grant权限时，此字段必填，描述权限使用的场景和时机。 |
| abilities | 标识需要使用到该权限的元能力，标签为数组形式。               |
| when      | 标识权限使用的时机，值为"inuse/always"，表示为仅允许前台使用和前后台都可使用。 |

**示例：**

```json
{
    "module" : {
        "reqPermissions":[
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
        ],
    }
}
```

### stage模型 module.json5文件声明

stage模型中应用需要在module.json5文件中对需要的权限逐个进行声明。没有在module.json5中声明的权限，应用无法获得此应用授权。

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
        ],
    }
}
```

## ACL方式声明

如上述示例所示，权限"ohos.permission.PERMISSION2"的权限等级为system_basic，高于应用此时应用的APL等级，用户的最佳做法是使用ACL方式。

在config.json文件声明的基础上，应用还需要在[profile文件](../quick-start/app-provision-structure.md)中声明不满足申请条件部分的权限。该场景中，用户应该在字段"acls"中做声明如下：
```json
{
    "version-name": "1.0.0",
    "version-code": 1,
    "app-distribution-type": "os_integration",
    "uuid": "5027b99e-5f9e-465d-9508-a9e0134ffe18",
    "validity": {
        "not-before": 1594865258,
        "not-after": 1689473258
    },
    "type": "release",
    "bundle-info": {
        "developer-id": "OpenHarmony",
        "distribution-certificate": "-----BEGIN CERTIFICATE-----\nMIICMzCCAbegAwIBAgIEaOC/zDAMBggqhkjOPQQDAwUAMGMxCzAJBgNVBAYTAkNO\nMRQwEgYDVQQKEwtPcGVuSGFybW9ueTEZMBcGA1UECxMQT3Blbkhhcm1vbnkgVGVh\nbTEjMCEGA1UEAxMaT3Blbkhhcm1vbnkgQXBwbGljYXRpb24gQ0EwHhcNMjEwMjAy\nMTIxOTMxWhcNNDkxMjMxMTIxOTMxWjBoMQswCQYDVQQGEwJDTjEUMBIGA1UEChML\nT3Blbkhhcm1vbnkxGTAXBgNVBAsTEE9wZW5IYXJtb255IFRlYW0xKDAmBgNVBAMT\nH09wZW5IYXJtb255IEFwcGxpY2F0aW9uIFJlbGVhc2UwWTATBgcqhkjOPQIBBggq\nhkjOPQMBBwNCAATbYOCQQpW5fdkYHN45v0X3AHax12jPBdEDosFRIZ1eXmxOYzSG\nJwMfsHhUU90E8lI0TXYZnNmgM1sovubeQqATo1IwUDAfBgNVHSMEGDAWgBTbhrci\nFtULoUu33SV7ufEFfaItRzAOBgNVHQ8BAf8EBAMCB4AwHQYDVR0OBBYEFPtxruhl\ncRBQsJdwcZqLu9oNUVgaMAwGCCqGSM49BAMDBQADaAAwZQIxAJta0PQ2p4DIu/ps\nLMdLCDgQ5UH1l0B4PGhBlMgdi2zf8nk9spazEQI/0XNwpft8QAIwHSuA2WelVi/o\nzAlF08DnbJrOOtOnQq5wHOPlDYB4OtUzOYJk9scotrEnJxJzGsh/\n-----END CERTIFICATE-----\n",
        "bundle-name": "com.ohos.permissionmanager",
		"apl": "system_core",
        "app-feature": "hos_system_app"
    },
    "acls": {
        "allowed-acls": [
            "ohos.permission.PERMISSION2"
        ]
    },
    "permissions": {
        "restricted-permissions": []
    },
    "issuer": "pki_internal"
}
```

## 申请授权user_grant权限

在前期的权限声明步骤后，在安装过程中系统会对system_grant类型的权限进行权限预授权，而user_grant类型权限则需要用户进行手动授权。

所以，应用在调用受"ohos.permission.PERMISSION2"权限保护的接口前，需要先校验应用是否已经获取该权限。

如果校验结果显示，应用已经获取了该权限，那么应用可以直接访问该目标接口，否则，应用需要通过动态弹框先申请用户授权，并根据授权结果进行相应处理，处理方式可参考[访问控制开发概述](accesstoken-overview.md)。

> **注意事项：**
>
> 不能把之前授予的状态持久化，每次访问受目标权限保护的接口前，都应该检查权限授权状态，因为用户在动态授予后可能通过设置取消应用的权限。

## 完整示例

对访问者进行权限校验的开发步骤为：

1. 获取ability的上下文context。
2. 调用requestPermissionsFromUser接口进行权限校验。
3. 根据权限校验结果采取对应的措施。

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
