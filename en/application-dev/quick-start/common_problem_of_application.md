# FAQs About Application Packages
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

## How do I obtain the fingerprint in the signature information?

* Call an API.

You can call [bundleManager.getBundleInfoForSelf](../reference/apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself) to obtain the bundle information, which contains the signature information, and signature information in turn contains fingerprint information.

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
try {
  bundleManager.getBundleInfoForSelf(bundleFlags).then((bundleInfo:bundleManager.BundleInfo) => {
    console.info('testTag', 'getBundleInfoForSelf successfully. fingerprint: %{public}s', bundleInfo.signatureInfo.fingerprint);
  }).catch((err: BusinessError) => {
    console.error('testTag', 'getBundleInfoForSelf failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  console.error('testTag', 'getBundleInfoForSelf failed: %{public}s', message);
}
```

* Use [Bundle Manager](../tools/bm-tool.md) (bm).

```shell
hdc shell
# Replace **com.example.myapplication** with the actual bundle name.
bm dump -n com.example.myapplication | grep fingerprint 
```

![alt text](figures/get_fingerprint.png)

* Use the **keytool**. For details, see [Generating a Signing Certificate Fingerprint](https://developer.huawei.com/consumer/en/doc/AppGallery-connect-Guides/appgallerykit-preparation-game-0000001055356911#section147011294331).

## What is appIdentifier?

**appIdentifier**, generated during application signing, is a field in the <!--RP1-->[profile](../security/app-provision-structure.md)<!--RP1End--> and is the unique identifier of an application. There are two ways to generate an application identifier:

1. Randomly generate the **appIdentifier** field through [automatic signing](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section18815157237) on DevEco Studio. Signing on different devices or re-signing will result in different values of **appIdentifier**.
<!--RP2-->
2. Manually configure the signature. The **appIdentifier** field here is the same as the **app-identifier** field in the [HarmonyAppProvision configuration file](../security/app-provision-structure.md). For details, see [hapsigner Guide](../security/hapsigntool-guidelines.md).
<!--RP2End-->

Therefore, manual signing is recommended in scenarios where **appIdentifier** must remain unchanged, such as cross-device debugging, cross-application interaction debugging, or multi-user development with a shared key. For details, see [Use Cases for Automatic and Manual Signing](https://developer.huawei.com/consumer/en/doc/harmonyos-guides/ide-signing#section54361623194519).

## How do I obtain appIdentifier from application information?

* You can call [bundleManager.getBundleInfoForSelf](../reference/apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself) to obtain the bundle information, which contains the signature information, and signature information in turn contains the **appIdentifier**.

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
try {
  bundleManager.getBundleInfoForSelf(bundleFlags).then((bundleInfo:bundleManager.BundleInfo) => {
    console.info('testTag', 'getBundleInfoForSelf successfully. appIdentifier: %{public}s', bundleInfo.signatureInfo.appIdentifier);
  }).catch((err: BusinessError) => {
    console.error('testTag', 'getBundleInfoForSelf failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  console.error('testTag', 'getBundleInfoForSelf failed: %{public}s', message);
}
```

* Use the [bm](../tools/bm-tool.md) tool.

```shell
hdc shell
# Replace **com.example.myapplication** with the actual bundle name.
bm dump -n com.example.myapplication | grep appIdentifier
```

![alt text](figures/get_appIdentifier.png)


## What Is appId?

**appId**, the unique identifier of an application, consists of a bundle name, underscore (_), and Base64-encoded public key of the certificate. Since it changes with the public key of the signing certificate, you are advised to use [appIdentifier](#what-is-appidentifier) as the unique identifier of an application.

## How do I obtain appId from application information?

* You can call [bundleManager.getBundleInfoForSelf](../reference/apis-ability-kit/js-apis-bundleManager.md#bundlemanagergetbundleinfoforself) to obtain the bundle information, which contains the signature information, and signature information in turn contains the **appId**.

```ts
import { bundleManager } from '@kit.AbilityKit';
import { BusinessError } from '@kit.BasicServicesKit';
import { hilog } from '@kit.PerformanceAnalysisKit';

let bundleFlags = bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_APPLICATION | bundleManager.BundleFlag.GET_BUNDLE_INFO_WITH_SIGNATURE_INFO;
try {
  bundleManager.getBundleInfoForSelf(bundleFlags).then((bundleInfo:bundleManager.BundleInfo) => {
    console.info('testTag', 'getBundleInfoForSelf successfully. appId: %{public}s', bundleInfo.signatureInfo.appId);
  }).catch((err: BusinessError) => {
    console.error('testTag', 'getBundleInfoForSelf failed. Cause: %{public}s', err.message);
  });
} catch (err) {
  let message = (err as BusinessError).message;
  console.error('testTag', 'getBundleInfoForSelf failed: %{public}s', message);
}
```

* Use the [bm](../tools/bm-tool.md) tool.

```shell
hdc shell
# Replace **com.example.myapplication** with the actual bundle name.
dump -n ohos.app.hap.myapplication |grep '"appId":'
```
![alt text](figures/get_appId.png)
