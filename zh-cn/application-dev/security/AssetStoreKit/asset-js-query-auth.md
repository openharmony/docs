# 查询需要用户认证的关键资产(ArkTS)

## 接口介绍

接口文档链接：

[preQuery(query: AssetMap): Promise\<Uint8Array>](../reference/apis/js-apis-asset.md#asset.prequery)

[query(query: AssetMap): Promise\<Array\<AssetMap>>](../reference/apis/js-apis-asset.md#asset.query)

[postQuery(handle: AssetMap): Promise\<void>](../reference/apis/js-apis-asset.md#asset.postquery)

preQuery参数列表

| 属性名称（Tag）        | 属性内容（Value）                                             | 是否必选  | 说明                                             |
| --------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------ |
| ALIAS                 | 类型为Uint8Array，长度为1-256字节                            | 可选     | 关键资产别名，每条关键资产的唯一索引;            |
| ACCESSIBILITY         | 类型为number，取值范围详见[Accessibility](../reference/apis/js-apis-asset.md#accessibility) | 可选     | 基于锁屏状态的访问控制                                     |
| REQUIRE_PASSWORD_SET  | 类型为bool                                                   | 可选     | 是否仅在设置了锁屏密码的情况下，可访问关键资产     |
| AUTH_TYPE             | 类型为number，取值范围详见[AuthType](../reference/apis/js-apis-asset.md#authtype) | 可选     | 访问关键资产所需的用户认证类型                   |
| AUTH_VALIDITY_PERIOD  | 类型为number，取值范围：1-600，单位为秒                      | 可选     | 用户认证的有效期                                 |
| SYNC_TYPE             | 类型为number，取值范围详见[SyncType](../reference/apis/js-apis-asset.md#synctype) | 可选     | 关键资产支持的同步类型                           |
| IS_PERSISTENT         | 类型为bool                                                   | 可选     | 在应用卸载时是否需要保留关键资产                 |
| DATA_LABEL_CRITICAL_1 | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护 |
| DATA_LABEL_CRITICAL_2 | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护 |
| DATA_LABEL_CRITICAL_3 | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护 |
| DATA_LABEL_CRITICAL_4 | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护 |
| DATA_LABEL_NORMAL_1   | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护 |
| DATA_LABEL_NORMAL_2   | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护 |
| DATA_LABEL_NORMAL_3   | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护 |
| DATA_LABEL_NORMAL_4   | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护 |

query参数列表

| 属性名称（Tag）        | 属性内容（Value）                                             | 是否必选  | 说明                                             |
| --------------------- | ------------------------------------------------------------ | -------- | ------------------------------------------------ |
| ALIAS                 | 类型为Uint8Array，长度为1-256字节                            | 必选     | 关键资产别名，每条关键资产的唯一索引;           |
| AUTH_CHALLENGE        | 类型为Uint8Array，长度为32字节                               | 必选     | 用户认证的挑战值                              |
| AUTH_TOKEN            | 类型为Uint8Array，长度为148字节                              | 必选     | 用户认证通过的授权令牌                         |
| RETURN_TYPE           | 类型为number，asset.ReturnType.ALL                           | 必选     | 关键资产查询返回的结果类型                    |
| ACCESSIBILITY         | 类型为number，取值范围详见[Accessibility](../reference/apis/js-apis-asset.md#accessibility) | 可选     | 基于锁屏状态的访问控制                                     |
| REQUIRE_PASSWORD_SET  | 类型为bool                                                   | 可选     | 是否仅在设置了锁屏密码的情况下，可访问关键资产     |
| AUTH_TYPE             | 类型为number，取值范围详见[AuthType](../reference/apis/js-apis-asset.md#authtype) | 可选     | 访问关键资产所需的用户认证类型                   |
| SYNC_TYPE             | 类型为number，取值范围详见[SyncType](../reference/apis/js-apis-asset.md#synctype) | 可选     | 关键资产支持的同步类型                           |
| IS_PERSISTENT         | 类型为bool                                                   | 可选     | 在应用卸载时是否需要保留关键资产                 |
| DATA_LABEL_CRITICAL_1 | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护 |
| DATA_LABEL_CRITICAL_2 | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护 |
| DATA_LABEL_CRITICAL_3 | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护 |
| DATA_LABEL_CRITICAL_4 | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且有完整性保护 |
| DATA_LABEL_NORMAL_1   | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护 |
| DATA_LABEL_NORMAL_2   | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护 |
| DATA_LABEL_NORMAL_3   | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护 |
| DATA_LABEL_NORMAL_4   | 类型为Uint8Array，长度为1-512字节                            | 可选     | 关键资产附属信息，内容由业务自定义且无完整性保护 |

postQuery参数列表

| 属性名称（Tag）      | 属性内容（Value）               | 是否必选  | 说明                 |
| ------------------- | ------------------------------ | -------- | -------------------- |
| AUTH_CHALLENGE      | 类型为Uint8Array，长度为32字节 | 必选     | 用户认证的挑战值 |

## 代码示例

查询别名是demo_alias且需要用户认证的关键资产。

```typescript
import { asset } from '@kit.AssetStoreKit';
import util from '@ohos.util';
import userAuth from '@ohos.userIAM.userAuth';

function stringToArray(str: string): Uint8Array {
  let textEncoder = new util.TextEncoder();
  return textEncoder.encodeInto(str);
}

function arrayToString(arr: Uint8Array): string {
  let textDecoder = util.TextDecoder.create("utf-8", { ignoreBOM: true });
  let str = textDecoder.decodeWithStream(arr, { stream: false })
  return str;
}

async function userAuthenticate(challenge: Uint8Array): Promise<Uint8Array> {
  return new Promise((resolve, reject) => {
    const authParam: userAuth.AuthParam = {
      challenge: challenge,
      authType: [userAuth.UserAuthType.PIN],
      authTrustLevel: userAuth.AuthTrustLevel.ATL1,
    };
    const widgetParam: userAuth.WidgetParam = { title: '请输入锁屏密码' };
    try {
      let userAuthInstance = userAuth.getUserAuthInstance(authParam, widgetParam);
      userAuthInstance.on('result', {
        onResult(result) {
          if (result.result == userAuth.UserAuthResultCode.SUCCESS) {
            console.info(`User identity authentication succeeded.`);
            resolve(result.token);
          } else {
            console.error(`User identity authentication failed.`);
            reject();
          }
        }
      });
      userAuthInstance.start();
    } catch (error) {
      console.error(`User identity authentication failed.`);
      reject();
    }
  })
}

function preQueryAsset(): Promise<Uint8Array> {
  return new Promise((resolve, reject) => {
    try {
      let query: asset.AssetMap = new Map();
      query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
      asset.preQuery(query).then((challenge: Uint8Array) => {
        resolve(challenge);
      }).catch(() => {
        reject();
      })
    } catch (error) {
      console.error(`Failed to pre-query Asset.`);
      reject();
    }
  });
}

async function postQueryAsset(challenge: Uint8Array) {
  let handle: asset.AssetMap = new Map();
  handle.set(asset.Tag.AUTH_CHALLENGE, challenge);
  try {
    await asset.postQuery(handle);
    console.info(`Succeeded in post-querying Asset.`);
  } catch (error) {
    console.error(`Failed to post-query Asset.`);
  }
}

async function queryAsset() {
  // step1. 调用asset.preQuery获取挑战值
  preQueryAsset().then(async (challenge: Uint8Array) => {
    try {
      // step2. 传入挑战值，拉起用户认证框
      let authToken: Uint8Array = await userAuthenticate(challenge);
      // step3 用户认证通过后，传入挑战值和授权令牌，查询关键资产明文
      let query: asset.AssetMap = new Map();
      query.set(asset.Tag.ALIAS, stringToArray('demo_alias'));
      query.set(asset.Tag.RETURN_TYPE, asset.ReturnType.ALL);
      query.set(asset.Tag.AUTH_CHALLENGE, challenge);
      query.set(asset.Tag.AUTH_TOKEN, authToken);
      let res: Array<asset.AssetMap> = await asset.query(query);
      for (let i = 0; i < res.length; i++) {
        // parse the secret.
        let secret: Uint8Array = res[i].get(asset.Tag.SECRET) as Uint8Array;
        // parse uint8array to string
        let secretStr: string = arrayToString(secret);
      }
      // step4. 关键资产明文查询成功后，需要调用asset.postQuery进行查询的后置处理。
      postQueryAsset(challenge);
    } catch (error) {
      // step5. preQuery成功，后续操作失败，也需要调用asset.postQuery进行查询的后置处理。
      postQueryAsset(challenge);
    }
  }).catch (() => {
    console.error(`Failed to pre-query Asset.`);
  })
}
```

## 约束和限制

无