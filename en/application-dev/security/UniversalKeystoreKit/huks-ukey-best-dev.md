# UKey Process Example

<!--Kit: Universal Keystore Kit-->
<!--Subsystem: Security-->
<!--Owner: @wutiantian-gitee-->
<!--Designer: @HighLowWorld-->
<!--Tester: @wxy1234564846-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=f7243bd9bbc19d6bb1c1a460201c8c6cbf7dc7b6 translatedAt=2026-08-13T08:25:48.081Z pushedAt=2026-08-13T10:20:24.725Z -->

## Development Modes

Currently, the following development modes are available for two-way SSL authentication:

### Browser Uses System ArkWeb Capabilities and a Custom Client

1. The application on the device calls the certificate management capability to open the certificate selection dialog box, waits for the user to select a certificate, and obtains the [keyUri](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certreference22) as the resource ID.

2. The application listens to the PIN authentication callback, processes the event, and calls the certificate management capability to open the PIN authentication dialog box.

3. The certificate management capability returns the authentication result to the application on the device, and the application returns the result to the ArkWeb component.

### Browser Uses a Custom Web Component and a Custom Client

1. The application on the device calls the certificate management capability to open the certificate selection dialog box, waits for the user to select a certificate, obtains the [keyUri](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certreference22) as the resource ID, and transparently passes it to the **Web** component.

2. The **Web** component obtains the certificate data through certificate management, uses the [keyUri](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certreference22) as the resource ID to call the resource opening API of the HUKS, and queries the PIN authentication status.

3. Perform the following operations based on the authentication result:

   - If the authentication is not performed, the application on the device needs to start PIN authentication. In this case, the application receives the authentication request, processes the event, and calls the certificate management capability to open the PIN authentication dialog box. After obtaining the authentication result, the application returns the result to the **Web** component and then performs the authenticated process.

   - If the authentication is successful, the **Web** component can directly call the [initSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksinitsession9)/[updateSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksupdatesession9)/[finishSession](../../reference/apis-universal-keystore-kit/js-apis-huks.md#huksfinishsession9) APIs of HUKS for signing.

> **NOTE**
>
> To call the three-stage capabilities of the underlying extension, the parameters passed must contain [OH_HUKS_TAG_KEY_CLASS](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_tag), with its value set to [OH_HUKS_KEY_CLASS_EXTENSION](../../reference/apis-universal-keystore-kit/capi-native-huks-type-h.md#oh_huks_keyclasstype).

## Example

The following is an example of using the system capability for two-way SSL authentication in a browser.

1. The application on the device calls the certificate management capability to open the certificate selection dialog box [certificateManagerDialog.openAuthorizeDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenauthorizedialog22) and waits for the user to select a certificate.

   ```ts
   import { certificateManagerDialog, certificateManager } from '@kit.DeviceCertificateKit';
   import { BusinessError } from '@kit.BasicservicesKit';
   import { common } from '@kit.AbilityKit';
   import { UIContext } from '@kit.ArkUI';

   /* context is application context information, which is obtained by the caller. The context here is only an example. */
   let context: common.Context = new UIContext().getHostContext() as common.Context;
   let certTypes: Array<certificateManagerDialog.CertificateType> = [
     certificateManagerDialog.CertificateType.CREDENTIAL_USER,
     certificateManagerDialog.CertificateType.CREDENTIAL_APP,
     certificateManagerDialog.CertificateType.CREDENTIAL_UKEY
   ];
   let certPurpose: certificateManager.CertificatePurpose = certificateManager.CertificatePurpose.PURPOSE_DEFAULT;
   let authorizeRequest: certificateManagerDialog.AuthorizeRequest = { certTypes: certTypes, certPurpose: certPurpose };
   try {
     certificateManagerDialog.openAuthorizeDialog(context, authorizeRequest).then((certReference: certificateManagerDialog.CertReference) => {
       /* Record the keyUri obtained in the certificate selection dialog box for future use.*/
       let keyUri = certReference.keyUri;
       console.info('Succeeded in opening authorize dialog.');
     }).catch((err: BusinessError) => {
       console.error(`Failed to open authorize dialog. Code: ${err.code}, message: ${err.message}`);
     });
   } catch (err) {
     let error = err as BusinessError;
     console.error(`Failed to open authorize dialog. Code: ${error.code}, message: ${error.message}`);
   }
   ```

2. The **Web** component parses the certificate, calls the HUKS to open the resource, and queries the PIN authentication status.

   First, call the NDK API of certificate management, OH_CertManager_GetUkeyCertificate](../../reference/apis-device-certificate-kit/capi-cm-native-api-h.md#oh_certmanager_getukeycertificate), to parse the certificate selected by the user and obtain the corresponding certificate data.

   Next, use **keyUri** selected by the user as the resource ID to call the HUKS NDK API, [OH_Huks_OpenResource](../../reference/apis-universal-keystore-kit/capi-native-huks-external-crypto-api-h.md#oh_huks_openresource) to open the resource.

   Finally, call the HUKS NDK API [OH_Huks_GetUkeyPinAuthState](../../reference/apis-universal-keystore-kit/capi-native-huks-external-crypto-api-h.md#oh_huks_getukeypinauthstate) to query the PIN authentication status.

   ```c
   #include "huks/native_huks_external_crypto_api.h"
   #include "huks/native_huks_param.h"
   #include <device_certificate/certmanager/cm_native_api.h>
   #include <device_certificate/certmanager/cm_native_type.h>
   #include "napi/native_api.h"
   #include <string.h>
   
   /* 1. Call the NDK API of certificate management to parse the certificate selected by the user and obtain the corresponding certificate data. */
   static napi_value GetUkeyCert(napi_env env, napi_callback_info info) 
   {
       size_t argc = 1;
       napi_value argv[1] = { nullptr };
       napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
       if (argc != 1) {
           return nullptr;
       }
       /* Obtain the keyUri length. */
       size_t length = 0;
       napi_get_value_string_utf8(env, argv[0], nullptr, 0, &length);
       /* Obtain the value of keyUri.*/
       char *keyUriBuffer = static_cast<char*>(malloc(length + 1));
       size_t result = 0;
       napi_get_value_string_utf8(env, argv[0], keyUriBuffer, length + 1, &result);
       OH_CM_Blob keyUri = { static_cast<uint32_t>(length + 1), (uint8_t*)keyUriBuffer };

       /* Define input parameter UkeyInfo. */
       OH_CM_UkeyInfo ukeyInfo = { OH_CM_CERT_PURPOSE_SIGN }; /* USB credential attributes. The value is omitted here. */

       /* Obtain the UKey certificate details corresponding to keyUri. */
       OH_CM_CredentialDetailList credentialList = { 0, nullptr };
       int32_t ret = OH_CertManager_GetUkeyCertificate(&keyUri, &ukeyInfo, &credentialList);

       /* Release the memory after the call is complete. */
       OH_CertManager_FreeUkeyCertificate(&credentialList);
       free(keyUriBuffer);
       /* Return the call result. */
       napi_value retNapi;
       napi_create_int32(env, ret, &retNapi);
       return retNapi;
   }

   /* 2. Call the NDK API of HUKS to open the resource based on the keyUri selected by the user as resourceId. */
   OH_Huks_Result InitParamSet(struct OH_Huks_ExternalCryptoParamSet **paramSet,
       const struct OH_Huks_ExternalCryptoParam *params, uint32_t paramCount)
   {
       OH_Huks_Result ret = OH_Huks_InitExternalCryptoParamSet(paramSet);
       if (ret.errorCode != OH_HUKS_SUCCESS) {
           return ret;
       }
       ret = OH_Huks_AddExternalCryptoParams(*paramSet, params, paramCount);
       if (ret.errorCode != OH_HUKS_SUCCESS) {
           OH_Huks_FreeExternalCryptoParamSet(paramSet);
           return ret;
       }
       ret = OH_Huks_BuildExternalCryptoParamSet(paramSet);
       if (ret.errorCode != OH_HUKS_SUCCESS) {
           OH_Huks_FreeExternalCryptoParamSet(paramSet);
           return ret;
       }
       return ret;
   }

   static struct OH_Huks_ExternalCryptoParam g_openResourceParamsTest[] = {};

   static napi_value OpenResource(napi_env env, napi_callback_info info)
   {
       size_t argc = 1;
       napi_value argv[1] = { nullptr };
       napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
       if (argc != 1) {
           return nullptr;
       }
       /* Obtain the keyUri length. */
       size_t length = 0;
       napi_get_value_string_utf8(env, argv[0], nullptr, 0, &length);
       /* Obtain the value of keyUri.*/
       char *keyUriBuffer = static_cast<char*>(malloc(length + 1));
       size_t result = 0;
       napi_get_value_string_utf8(env, argv[0], keyUriBuffer, length + 1, &result);
       OH_Huks_Blob resourceId = {.size = static_cast<uint32_t>(length), .data = (uint8_t*)keyUriBuffer};

       struct OH_Huks_ExternalCryptoParamSet *openResourceParamSet = nullptr;
       OH_Huks_Result ohResult;
       do {
           ohResult = InitParamSet(&openResourceParamSet, g_openResourceParamsTest,
               sizeof(g_openResourceParamsTest) / sizeof(OH_Huks_ExternalCryptoParam));
           if (ohResult.errorCode != OH_HUKS_SUCCESS) {
               break;
           }
           ohResult = OH_Huks_OpenResource(&resourceId, openResourceParamSet);
           if (ohResult.errorCode != OH_HUKS_SUCCESS) {
               break;
           }
       } while (0);
       free(keyUriBuffer);
       OH_Huks_FreeExternalCryptoParamSet(&openResourceParamSet);

       OH_Huks_Result res = OH_Huks_OpenResource(&resourceId, openResourceParamSet);
       napi_value ret;
       napi_create_int32(env, res.errorCode, &ret);
       return ret;
   }

   /* 3. Call the NDK API of the HUKS to query the PIN authentication status. */
   static struct OH_Huks_ExternalCryptoParam g_getPinStateParamsTest[] = {};

   static napi_value GetUkeyPinAuthState(napi_env env, napi_callback_info info) 
   {
       size_t argc = 1;
       napi_value argv[1] = { nullptr };
       napi_get_cb_info(env, info, &argc, argv, nullptr, nullptr);
       if (argc != 1) {
           return nullptr;
       }
       /* Obtain the keyUri length. */
       size_t length = 0;
       napi_get_value_string_utf8(env, argv[0], nullptr, 0, &length);
       /* Obtain the value of keyUri.*/
       char *keyUriBuffer = static_cast<char*>(malloc(length + 1));
       size_t result = 0;
       napi_get_value_string_utf8(env, argv[0], keyUriBuffer, length + 1, &result);
       OH_Huks_Blob resourceId = {.size = static_cast<uint32_t>(length), .data = (uint8_t*)keyUriBuffer};

       struct OH_Huks_ExternalCryptoParamSet *pinStateParamSet = nullptr;
       OH_Huks_ExternalPinAuthState authState = OH_HUKS_EXT_CRYPTO_PIN_NO_AUTH;
       OH_Huks_Result ohResult;
       do {
           ohResult = InitParamSet(&pinStateParamSet, g_getPinStateParamsTest,
               sizeof(g_getPinStateParamsTest) / sizeof(OH_Huks_ExternalCryptoParam));
           if (ohResult.errorCode != OH_HUKS_SUCCESS) {
               break;
           }
           ohResult = OH_Huks_GetUkeyPinAuthState(&resourceId, pinStateParamSet, &authState);
           if (ohResult.errorCode != OH_HUKS_SUCCESS) {
               break;
           }
       } while (0);
       free(keyUriBuffer);
       OH_Huks_FreeExternalCryptoParamSet(&pinStateParamSet);

       napi_value ret;
       napi_create_int32(env, ohResult.errorCode, &ret);
       return ret;
   }

   /* 4. Define and register APIs. */
   static napi_value Init(napi_env env, napi_value exports)
   {
       napi_property_descriptor desc[] = {
           { "getUkeyCert", nullptr, GetUkeyCert, nullptr, nullptr, nullptr, napi_default, nullptr },
           { "openResource", nullptr, OpenResource, nullptr, nullptr, nullptr, napi_default, nullptr },
           { "getUkeyPinAuthState", nullptr, GetUkeyPinAuthState, nullptr, nullptr, nullptr, napi_default, nullptr },
       };
       napi_define_properties(env, exports, sizeof(desc) / sizeof(desc[0]), desc);
       return exports;
   }

   static napi_module demoModule = {
       .nm_version =1,
       .nm_flags = 0,
       .nm_filename = nullptr,
       .nm_register_func = Init,
       .nm_modname = "hello",
       .nm_priv = ((void*)0),
       .reserved = { 0 },
   };
   extern "C" __attribute__((constructor)) void RegisterHelloModule(void)
   {
       napi_module_register(&demoModule);
   }
   ```

   The corresponding d.ts API declaration is as follows:

   ```ts
   export function getUkeyCert(keyUri: string): number;

   export function openResource(keyUri: string): number;

   export function getUkeyPinAuthState(keyUri: string): number;
   ```

   The API call method is as follows:

   ```ts
   import testNapi from "libentry.so";
   @Entry
   @Component
   struct Index {
       /* Obtain the value through the certificate dialog box API.*/
       @State keyUri: string = 'Hello World';
       build() {
           Row() {
           Column() {
               Text('Hello World')
               .fontSize(50)
               .fontWeight(FontWeight.Bold)
               .onClick(() => {
                   testNapi.getUkeyCert(keyUri);
                   testNapi.openResource(keyUri);
                   testNapi.getUkeyPinAuthState(keyUri);
               })
           }
           .width('100%')
           }
           .height('100%')
       }
   }
   ```

3. Perform the following operations based on the authentication result:

   If the authentication is not performed, the application needs to start PIN authentication. In this case, the device application receives the authentication request, processes the event, and calls the certificate management capability to open the PIN authentication dialog box [certificateManagerDialog.openUkeyAuthDialog](../../reference/apis-device-certificate-kit/js-apis-certManagerDialog.md#certificatemanagerdialogopenukeyauthdialog22). After obtaining the authentication result, the application returns the result to the **Web** component and then performs the authenticated process.

   ```ts
   /* Open the PIN authentication dialog box through certificate management. */
   import { certificateManagerDialog } from '@kit.DeviceCertificateKit';
   import { BusinessError } from '@kit.BasicServicesKit';
   import { common } from '@kit.AbilityKit';
   import { UIContext } from '@kit.ArkUI';

   /* context is application context information, which is obtained by the caller. The context here is only an example. */
   let context: common.Context = new UIContext().getHostContext() as common.Context;
   /* keyUri is the unique identifier of the credential. The value has been recorded in step 1. The value here is only an example. */
   let keyUri: string = "testKeyAlias";
   let ukeyAuthRequest: certificateManagerDialog.UkeyAuthRequest = { keyUri: keyUri };
   try {
     certificateManagerDialog.openUkeyAuthDialog(context, ukeyAuthRequest)
       .then(() => {
         console.info('Succeeded in opening ukey authorization dialog.');
       }).catch((err: BusinessError) => {
         console.error(`Failed to open ukey authorization dialog. Code: ${err.code}, message: ${err.message}`);
       });
   } catch (err) {
     let error = err as BusinessError;
     console.error(`Failed to open ukey authorization dialog. Code: ${error.code}, message: ${error.message}`);
   }
   ```

   If the authentication is successful, the **Web** component can directly call the three-stage HUKS APIs for signing.

   ```c
   /* Call the three-stage HUKS APIs to obtain the signed data.*/
   #include "huks/native_huks_api.h"
   #include "huks/native_huks_param.h"
   #include "napi/native_api.h"
   #include <string.h>

   OH_Huks_Result InitParamSet(struct OH_Huks_ParamSet **paramSet,
       const struct OH_Huks_Param *params, uint32_t paramCount)
   {
       OH_Huks_Result ret = OH_Huks_InitParamSet(paramSet);
       if (ret.errorCode != OH_HUKS_SUCCESS) {
           return ret;
       }
       ret = OH_Huks_AddParams(*paramSet, params, paramCount);
       if (ret.errorCode != OH_HUKS_SUCCESS) {
           OH_Huks_FreeParamSet(paramSet);
           return ret;
       }
       ret = OH_Huks_BuildParamSet(paramSet);
       if (ret.errorCode != OH_HUKS_SUCCESS) {
           OH_Huks_FreeParamSet(paramSet);
           return ret;
       }
       return ret;
   }

   static struct OH_Huks_Param g_signParamsTest[] = {
       {
           .tag = OH_HUKS_TAG_ALGORITHM,
           .uint32Param = OH_HUKS_ALG_RSA
       }, {
           .tag = OH_HUKS_TAG_PURPOSE,
           .uint32Param = OH_HUKS_KEY_PURPOSE_SIGN
       }, {
           .tag = OH_HUKS_TAG_KEY_SIZE,
           .uint32Param = OH_HUKS_RSA_KEY_SIZE_2048
       }, {
           .tag = OH_HUKS_TAG_PADDING,
           .uint32Param = OH_HUKS_PADDING_PSS
       }, {
           .tag = OH_HUKS_TAG_DIGEST,
           .uint32Param = OH_HUKS_DIGEST_SHA384
       }, {
           .tag = OH_HUKS_TAG_KEY_CLASS,
           .uint32Param = OH_HUKS_KEY_CLASS_EXTENSION
       }
   };

   static const uint32_t RSA_COMMON_SIZE = 1024;
   static const char *DATA_TO_SIGN = "testData";
   // The value of keyAlias can be obtained by referring to the method of obtaining the value of resourceId in step 2. The value of keyAlias here is only an example.
   static const char *KEY_ALIAS = "testKeyAlias";

   static napi_value Sign(napi_env env, napi_callback_info info)
   {
       // Assume that **g_keyAlias** is the obtained resource ID.
       struct OH_Huks_Blob keyAlias = {
           (uint32_t)strlen(KEY_ALIAS),
           (uint8_t *)KEY_ALIAS
       };
       struct OH_Huks_Blob inData = {
           (uint32_t)strlen(DATA_TO_SIGN),
           (uint8_t *)DATA_TO_SIGN
       };
       struct OH_Huks_ParamSet *signParamSet = nullptr;
       OH_Huks_Result ohResult;
       do {
           ohResult = InitParamSet(&signParamSet, g_signParamsTest, sizeof(g_signParamsTest) / sizeof(OH_Huks_Param));
           if (ohResult.errorCode != OH_HUKS_SUCCESS) {
               break;
           }
           // Init
           uint8_t handleS[sizeof(uint64_t)] = {0};
           struct OH_Huks_Blob handleSign = { (uint32_t)sizeof(uint64_t), handleS };
           ohResult = OH_Huks_InitSession(&keyAlias, signParamSet, &handleSign, nullptr);
           if (ohResult.errorCode != OH_HUKS_SUCCESS) {
               break;
           }
           // Finish
           uint8_t outDataS[RSA_COMMON_SIZE] = {0};
           struct OH_Huks_Blob outDataSign = { RSA_COMMON_SIZE, outDataS };
           ohResult = OH_Huks_FinishSession(&handleSign, signParamSet, &inData, &outDataSign);
           if (ohResult.errorCode != OH_HUKS_SUCCESS) {
               break;
           }
       } while (0);
       OH_Huks_FreeParamSet(&signParamSet);
       
       napi_value ret;
       napi_create_int32(env, ohResult.errorCode, &ret);
       return ret;
   }
   ```