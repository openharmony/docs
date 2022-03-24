# 访问控制开发指导

## 场景介绍

当应用申请的权限需要用户授权，即申请的权限为user_grant权限时，可以通过权限校验，判断当前调用者是否具备相应权限。

## 接口说明
接口的具体说明可以查阅[API参考](../reference/apis/js-apis-abilityAccessCtrl.md)
| 接口名                                                       | 描述             |
| ------------------------------------------------------------ | ---------------- |
| verifyAccessToken(tokenID: number, permissionName: string): Promise&lt;GrantStatus&gt; | 校验应用是否授予权限，使用Promise方式异步返回结果。 |

## 开发步骤
对访问者进行权限校验的开发步骤为：

1. 获取调用者的身份标识: tokenId
2. 识别需要校验的权限: permissionNameUser
3. 对当前调用者进行权限校验

代码示例如下：

```js
  import {describe, beforeEach, afterEach, it, expect} from 'deccjsunit/index'
  import abilityAccessCtrl from '@ohos.abilityAccessCtrl'
  import bundle from '@ohos.bundle'

  async requestPermission() {
    var permissionNameUser = "ohos.permission.ALPHA";
    var bundleFlag = 0;
    var tokenID = undefined;
    var userID = 100;
    var appInfo = await bundle.getApplicationInfo('ohos.acts.security.access_token.normal', bundleFlag, userID);
    tokenID = appInfo.accessTokenId;
    console.log("AccessTokenTest accessTokenId:" + appInfo.accessTokenId + ", name:" + appInfo.name
        + ", bundleName:" + appInfo.bundleName)
    var atManager = abilityAccessCtrl.createAtManager();
    var result = await atManager.verifyAccessToken(tokenID, permissionNameUser);
    if (result == abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED) {
        // 执行操作
    } else {
        // 申请动态授权，使用接口：requestPermissionsFromUser
    }
  }

```
> **说明：**
动态授权申请接口的使用详见[API参考](../reference/apis/js-apis-ability-context.md)