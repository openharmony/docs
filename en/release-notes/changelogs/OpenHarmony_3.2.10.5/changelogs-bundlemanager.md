# Bundle Manager Subsystem ChangeLog

## cl.bundlemanager.1 Changed Underlying Capability by Adding Verification to bundle-name in the Signing Certification During Application Installation

During application installation, the **bundle-name** field in the [signing certificate profile](../../../application-dev/security/app-provision-structure.md) is verified against the bundle name of the application.

If the value of **bundle-name** is different from the value of **bundleName** in the application configuration file, the installation fails and the following error information is displayed:
```
error: verify signature failed.
```

**Change Impact**

For applications using system images of 3.2.10.5 or later, if the **bundle-name** field in the signing certificate profile is different from the bundle name of the application, application installation fails. This change has no impact on applications using system images earlier than 3.2.10.5.

**Key API/Component Changes**

No API or component change is involved.

**Adaptation Guide**
If "error: verify signature failed" is displayed, change **bundle-name** in the signing certificate profile to the bundle name of the application, generate a new signing certificate (with the file name extension .p7b), and sign the application again.

For details about how to use the signing tool and generate a signing certificate, see [hapsigner Guide](../../../application-dev/security/hapsigntool-guidelines.md).

## cl.bundlemanager.2 Changed Underlying Capability by Adding Control over Applications Without Entry Icons

If no entry icon is configured for an application that has not requested the **AllowHideDesktopIcon** privilege, a default icon is displayed on the home screen. Any click on the icon redirects to the application details page. An application is determined to have no entry icon in either of the following scenarios:
1. The **abilities** field is not configured for the application.
2. The **abilities** field is configured for the application, but the **skills** field under the ability of any page type does not contain both **ohos.want.action.home** and **entity.system.home**, as follows:
    ```json
     "skills": [
              {
                "actions": [
                  "ohos.want.action.home"
                ],
                "entities": [
                  "entity.system.home"
                ]
              }
            ]
    ```
If the application installation mode is **hdc_std install** or **bm install**, a default icon is displayed for the application on the home screen.

If your application does not need an icon to be displayed on the home screen, request the **AllowHideDesktopIcon** privilege and configure it in the signing certificate or trustlist (**install_list_capability.json**). For details, see [Application Privilege Configuration Guide](../../../device-dev/subsystems/subsys-app-privilege-config-guide.md).

If your application needs an icon to be displayed on the home screen, select an ability from **abilities** and configure its **skills** field to contain both **ohos.want.action.home** and **entity.system.home**.

**Change Impact**

For applications using system images of 3.2.10.5 and later versions, if no entry icon is configured for an application, the default icon is displayed on the home screen when the application is installed using the CLI. This change has no impact on applications using system images earlier than 3.2.10.5.

**Key API/Component Changes**

No API or component change is involved.

**Adaptation Guide**

If your application does not need an icon to be displayed on the home screen, request the **AllowHideDesktopIcon** privilege and configure it in the signing certificate or trustlist (**install_list_capability.json**). For details, see [Application Privilege Configuration Guide](../../../device-dev/subsystems/subsys-app-privilege-config-guide.md).

If your application needs an icon to be displayed on the home screen, select an ability from **abilities** and configure its **skills** field to contain both **ohos.want.action.home** and **entity.system.home**.

## cl.bundlemanager.3 Changed Underlying Capability by Restricting AllowAppUsePrivilegeExtension, AllowAppMultiProcess, and AllowFormVisibleNotify from Being Configured in the Signing Certificate

The **AllowAppUsePrivilegeExtension**, **AllowAppMultiProcess**, and **AllowFormVisibleNotify** privileges can no longer be configured in the signing certificate. They can be requested only through the trustlist (**install_list_capability.json**). If your application requests these privileges in the signing certificate, the installation may fail or the privileges may be invalid.

If the following error information is displayed, adapt to the new privilege configuration method. For details, see [Application Privilege Configuration Guide](../../../device-dev/subsystems/subsys-app-privilege-config-guide.md).
```
error: install parse profile prop check error.
```

For the XTS or local debugging demo, if the **install_list_capability.json** file on the development board cannot be modified, you can change the bundle name of the application to start with **com.acts.** and request the privileges in the signing certificate.

The **AllowAppUsePrivilegeExtension** privilege is requested by configuring it under the **extensionAbilities** field, with the **type** attribute set to **dataShare** or **service**, in the application configuration file. If this privilege is not configured, the installation fails.

**Change Impact**

For applications using system images of 3.2.10.5 or later, if the required privileges are not requested using the trustlist (**install_list_capability.json**), application installation may fail. This change has no impact on applications using system images earlier than 3.2.10.5.

**Key API/Component Changes**

No API or component change is involved.

**Adaptation Guide**

If the following error information is displayed, adapt to the new privilege configuration method. For details, see [Application Privilege Configuration Guide](../../../device-dev/subsystems/subsys-app-privilege-config-guide.md).

```
error: install parse profile prop check error.
```

For the XTS or local debugging demo, if the **install_list_capability.json** file on the development board cannot be modified, you can change the bundle name of the application to start with **com.acts.** and request the privileges in the signing certificate.

## cl.bundlemanager.4 Changed Underlying Capability by Not Decompressing the HAP During HAP Installation

The HAP will no longer be decompressed during installation. After the installation is complete, only the HAP file exists in the installation directory. As a result, the application must use the standard resource management interface, rather than a combined path, to access a resource file.

**Change Impact**

If the application uses a combined path to access a resource file, the access fails. It must use the resource management interface.

**Key API/Component Changes**

No API or component change is involved.

**Adaptation Guide**

The resource management subsystem provides the JS interface for accessing resource files. Reference: [Accessing Resource Files](../../../application-dev/reference/apis/js-apis-resource-manager.md#getrawfilecontent9)