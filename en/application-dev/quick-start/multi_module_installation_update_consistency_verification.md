# Consistency Verification for Application Installation and Update

As applications become more and more complex, they are split into multiple modules for development and maintenance. Different teams are responsible for one or more modules. During application installation and update, consistency verification is performed on different fields to ensure application security and validity. This topic describes the consistency verification rules for signing certificates and configuration files during multi-module installation or update.

>
> **NOTE**
>
> If the values of the **versionCode** field in the [app.json5 configuration file](./app-configuration-file.md) are the same, the installed or updated packages are of the same version.
>
> During application packaging, validity verification is performed. For details, see [Packing Tool](../../application-dev/tools/packing-tool.md).

## Consistency Verification for Signing Certificate

|Field|Description|Consistency Verification for Installations|Consistency Verification for Updates|
|--|--|--|--|
|appId|Application ID. The value is in the format of base64-encoded *bundleName*_*public key*.|Yes|Either **appId** or **appIdentifier** is the same.|
|appIdentifier|Unique ID of the application. It is the [app ID](https://developer.huawei.com/consumer/en/doc/app/agc-help-createharmonyapp-0000001945392297), which is a random string, allocated by AppGallery Connect during the creation of the application. This ID does not change along the application lifecycle, including version updates, certificate changes, public and private key changes, and application transfers.|Yes|Either **appId** or **appIdentifier** is the same.|
|appDistributionType|<!--RP1-->Application distribution type specified in the [signing certificate](../security/app-provision-structure.md).<!--RP1End-->|Yes|No consistency verification is performed when an application is updated to a later version.|
|appProvisionType|[Profile types](https://developer.huawei.com/consumer/en/doc/app/agc-help-add-debugprofile-0000001914423102), which are classified into debug and release. Debug profile is used for debugging a local application or atomic service, and release profile is used for releasing an application or atomic service on the AppGallery.|Yes|No consistency verification is performed when an application is updated to a later version.|
|apl|Application [APLs](../security/AccessToken/app-permission-mgmt-overview.md#basic-concepts-in-the-permission-mechanism), which are classified into three levels: normal, system_basic, and system_core.|Yes|No consistency verification is performed when an application is updated to a later version.|


## Consistency Verification for Configuration File

|Field|Description|Consistency Verification for Installations|Consistency Verification for Updates|
|--|--|--|--|
|bundleName|Bundle name. This field comes from the [app.json5 configuration file](./app-configuration-file.md).|Yes|Yes|
|versionCode|Version code of the application. This field comes from the [app.json5 configuration file](./app-configuration-file.md).|Yes|Yes|
|apiReleaseType|Release type of the SDK used to run an application. An uninstalled application contains multiple module packages. When the modules are installed one by one, consistency verification is not performed. This field comes from the [app.json5 configuration file](./app-configuration-file.md).|No|Yes|
|<!--DelRow--> singleton|Whether an application is installed for a single user (User 0).|No|Yes|
|<!--DelRow--> appType|Application type, which specifies the third-party application or system application.|Yes|Yes|
|<!--DelRow--> isStage|Whether an application is in the stage model.|Yes. The FA model and stage model cannot be changed in the same version.|No|
|targetBundleName|Target bundle name. The application with this field has the overlay feature. This field comes from the [app.json5 configuration file](./app-configuration-file.md).|Yes|Yes|
|targetPriority|Priority of the target application. This field comes from the [app.json5 configuration file](./app-configuration-file.md).|Yes|Yes|
|bundleType|Bundle type. This field comes from the [app.json5 configuration file](./app-configuration-file.md).|Yes|Yes|
|installationFree|Whether installation-free is supported. This field comes from the [module.json5 configuration file](./module-configuration-file.md).|Yes|Yes|
|debug|Whether the application can be debugged. This field comes from the [app.json5 configuration file](./app-configuration-file.md).|Yes|No|
|moduleType|Module type. This field comes from the **type** field in the [module.json5 configuration file](./module-configuration-file.md).|Yes. In the same version, the module name of the entry type cannot be modified.|Yes|
