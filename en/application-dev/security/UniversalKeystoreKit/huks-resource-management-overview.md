# Resource Management Overview and Specifications

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=f7243bd9bbc19d6bb1c1a460201c8c6cbf7dc7b6 translatedAt=2026-08-13T08:26:24.814Z pushedAt=2026-08-13T10:26:54.785Z -->

It is agreed that **resourceId** is used to uniquely identify a resource in external key management extensions (such as UKey). Currently, **resourceId** can be obtained in the following two ways:

- **Obtained from the certificate management service**: Returned through [openAuthorizeDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22). Each certificate chain corresponds to one **resourceId**. This applies to scenarios that require certificate selection, such as mutual SSL authentication in browsers.

- **Obtained through the getResourceId API**: Starting from API version 26.0.0, you can obtain it through the [getResourceId](../../reference/apis-universal-keystore-kit/js-apis-huksExternalCrypto.md#huksexternalcryptogetresourceid) API. This applies to scenarios that do not require certificate selection, such as key generation and key import.

After the app obtains the **resourceId**, it must [open the resource](huks-open-close-resource-arkts.md#opening-a-resource) before performing subsequent key operations. After the operations are complete, it must [close the resource](huks-open-close-resource-arkts.md#closing-a-resource). This API calls back [onClearUkeyPinAuthState](../../reference/apis-universal-keystore-kit/js-apis-CryptoExtensionAbility.md#onclearukeypinauthstate) to clear the PIN authentication state associated with the resource, and calls back [onFinishSession](../../reference/apis-universal-keystore-kit/js-apis-CryptoExtensionAbility.md#onfinishsession) to clear the session handle associated with the resource.

> **NOTE**
>
> 1. Before operating a key, the resource must be opened. To perform high-permission operations such as private key signing, you must complete the PIN verification. Otherwise, the resource state may become abnormal.
> 2. After the operations are complete, you must manually close the resource to avoid resource leakage.