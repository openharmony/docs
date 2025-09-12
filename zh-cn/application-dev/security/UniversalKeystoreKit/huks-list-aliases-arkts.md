# 查询密钥别名集(ArkTS)

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->

HUKS提供了接口供应用查询密钥别名集。

>**说明：**
> <!--RP1-->轻量级设备<!--RP1End-->不支持查询密钥别名集功能。

## 开发步骤

1. 初始化密钥属性集，用于查询指定密钥别名集TAG。TAG仅支持[HUKS_TAG_AUTH_STORAGE_LEVEL](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_authstoragelevel)。

2. 调用接口[listAliases](../../reference/apis-universal-keystore-kit/js-apis-huks.md#hukslistaliases12)，查询密钥别名集。

```ts
/*
 * 以下查询密钥别名集Promise操作使用为例
 */
import { huks } from '@kit.UniversalKeystoreKit';
import { BusinessError } from "@kit.BasicServicesKit";

/* 1.初始化密钥属性集 */
let queryProperties: Array<huks.HuksParam> = [{
    tag: huks.HuksTag.HUKS_TAG_AUTH_STORAGE_LEVEL,
    value: huks.HuksAuthStorageLevel.HUKS_AUTH_STORAGE_LEVEL_DE
  }
];
let queryOptions: huks.HuksOptions = {
  properties: queryProperties
};

async function listAliases(options: huks.HuksOptions) {
  console.info(`promise: enter listAliases`);
  try {
    await huks.listAliases(options)
      .then((data) => {
        console.info(`promise: listAliases success`);
        for (let i = 0; i < data.keyAliases.length; ++i) {
          console.info(`promise: aliases ${i} : ${data.keyAliases[i]}`);
        }
      }).catch((error: BusinessError) => {
        console.error(`promise: listAliases failed, errCode : ${error.code}, errMsg : ${error.message}`);
      })
  } catch (error) {
    console.error(`promise: listAliases input arg invalid`);
  }
}

async function testListAliases() {
  await listAliases(queryOptions);
}
```