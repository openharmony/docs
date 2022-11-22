# 访问控制权限校验指导

## 场景介绍

应用在提供对外功能服务接口时，可以根据接口涉数据的敏感程度或所涉能力的安全威胁影响，在系统定义的权限列表中[权限定义列表](permission-list.md)选择合适的权限限制当前接口的开放范围，对接口访问者进行权限校验。

## 接口说明

以下仅列举本指导使用的接口，更多说明可以查阅[API参考](../reference/apis/js-apis-ability-context.md)。

| 接口名                                                       | 描述                                             |
| ------------------------------------------------------------ | --------------------------------------------------- |
| verifyAccessToken(tokenID: number, permissionName: string): Promise&lt;GrantStatus&gt; | 校验指定的应用进程是否已被授权指定的权限。 |


## 完整示例

进行权限校验的开发步骤为：

1. 获取调用者的身份标识：tokenId。
2. 待校验的权限名：ohos.permission.PERMISSION。
3. 使用verifyAccessToken接口对当前调用者进行权限校验。
4. 根据权限校验结果采取对应的措施。

```js
  import abilityAccessCtrl from '@ohos.abilityAccessCtrl'
  import rpc from '@ohos.rpc'

  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          let callerTokenId = rpc.IPCSkeleton.getCallingTokenId();
          console.log("RpcServer: getCallingTokenId result: " + callerTokenId);
          var atManager = abilityAccessCtrl.createAtManager();
          var result = await atManager.verifyAccessToken(tokenID, "ohos.permission.PERMISSION");
          if (result == abilityAccessCtrl.GrantStatus.PERMISSION_GRANTED) {
            // 允许访问者调用当前应用提供的接口
          } else {
            // 不允许访问者调用当前应用提供的接口
          }
          return true;
      }
  }

```
> **说明：**
> 获取访问者身份标识tokenId的方法 getCallingTokenId 可参考[API参考](../reference/apis/js-apis-rpc.md)。