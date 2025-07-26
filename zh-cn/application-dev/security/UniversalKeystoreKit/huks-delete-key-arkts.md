# 密钥删除(ArkTS)

为保证数据安全性，当不需要使用该密钥时，应该删除密钥。

## 开发步骤

以删除HKDF256密钥为例。

1. 确定密钥别名keyAlias，密钥别名最大长度为128字节。

2. 初始化密钥属性集。用于删除时指定[密钥的属性TAG](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_tag)，当删除单个时，TAG字段可传空。

3. 调用接口[deleteKeyItem](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksdeletekeyitem9)，删除密钥。

```ts
/*
 * 以下以HKDF256密钥的Promise操作使用为例
 */
import { huks } from '@kit.UniversalKeystoreKit';

/* 1.确定密钥别名 */
let keyAlias = "test_Key";
/* 2.构造空对象 */
let huksOptions: huks.HuksOptions = {
  properties: []
}

class throwObject {
  isThrow = false;
}

function deleteKeyItem(keyAlias: string, huksOptions: huks.HuksOptions, throwObj: throwObject) {
  return new Promise<void>((resolve, reject) => {
    try {
      huks.deleteKeyItem(keyAlias, huksOptions, (error, data) => {
        if (error) {
          reject(error);
        } else {
          resolve(data);
        }
      });
    } catch (error) {
      throwObj.isThrow = true;
      throw (error as Error);
    }
  });
}

/* 3.删除密钥*/
async function publicDeleteKeyFunc(keyAlias: string, huksOptions: huks.HuksOptions) {
  console.info(`enter promise deleteKeyItem`);
  let throwObj: throwObject = { isThrow: false };
  try {
    await deleteKeyItem(keyAlias, huksOptions, throwObj)
      .then((data) => {
        console.info(`promise: deleteKeyItem key success, data = ${JSON.stringify(data)}`);
      })
      .catch((error: Error) => {
        if (throwObj.isThrow) {
          throw (error as Error);
        } else {
          console.error(`promise: deleteKeyItem failed, ${JSON.stringify(error)}`);
        }
      });
  } catch (error) {
    console.error(`promise: deleteKeyItem input arg invalid, ${JSON.stringify(error)}`);
  }
}

async function testDerive() {
  await publicDeleteKeyFunc(keyAlias, huksOptions);
}
```
