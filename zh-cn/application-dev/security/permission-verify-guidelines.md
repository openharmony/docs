# 访问控制权限校验指导

## 场景介绍

应用在提供对外功能服务接口时，可以根据接口涉数据的敏感程度或所涉能力的安全威胁影响，在系统定义的权限列表中[权限定义列表](permission-list.md)选择合适的权限限制当前接口的开放范围，对接口访问者进行权限校验。

## 接口说明

以下仅列举本指导使用的接口，更多说明可以查阅[API参考](../reference/apis/js-apis-abilityAccessCtrl.md)。

checkAccessToken(tokenID: number, permissionName: Permissions): Promise&lt;GrantStatus&gt;

| 参数名   | 类型                 | 必填 | 说明                                       |
| -------- | -------------------  | ---- | ------------------------------------------ |
| tokenID   |  number   | 是   | 要校验的目标应用的身份标识。可通过应用的[ApplicationInfo](../reference/apis/js-apis-bundleManager-applicationInfo.md)获得。             |
| permissionName | Permissions | 是   | 需要校验的权限名称，合法的权限名取值可在[系统权限定义列表](permission-list.md)中查询。 |


## 完整示例

进行权限校验的开发步骤为：

1. 获取调用者的身份标识：tokenId。
   > **说明：**<br>
   > 获取访问者身份标识tokenId的方法 getCallingTokenId 可参考[API参考](../reference/apis/js-apis-rpc.md)。
2. 待校验的权限名：ohos.permission.ACCELEROMETER。
3. 使用checkAccessToken接口对当前调用者进行权限校验。
4. 根据权限校验结果采取对应的措施。

```js
  import abilityAccessCtrl from '@ohos.abilityAccessCtrl'
  import rpc from '@ohos.rpc'

  class Stub extends rpc.RemoteObject {
      onRemoteRequest(code, data, reply, option) {
          let callerTokenId = rpc.IPCSkeleton.getCallingTokenId();
          console.log("RpcServer: getCallingTokenId result: " + callerTokenId);
          var atManager = abilityAccessCtrl.createAtManager();
          try {
              atManager.checkAccessToken(callerTokenId, "ohos.permission.ACCELEROMETER").then((data) => {
                  console.log(`checkAccessToken success, data->${JSON.stringify(data)}`);
              }).catch((err) => {
                  console.log(`checkAccessToken fail, err->${JSON.stringify(err)}`);
              });
          } catch(err) {
              console.log(`catch err->${JSON.stringify(err)}`);
          }
          return true;
      }
  }

```