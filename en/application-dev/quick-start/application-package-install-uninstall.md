# Application Installation, Uninstall, and Update

This topic describes how to install, uninstall, and update an application.

## Installing or Uninstalling an Application
You can install and uninstall applications by running debug commands. For details, see the [compilation, release, and deployment process](./application-package-structure-stage.md#package-structure-in-the-release-phase).

**Figure 1** Process of installing and uninstalling an application (applicable to developers)

![hap-intall-uninstall](figures/hap-install-uninstall-developer.png)


When an application has been released to the application market, consumers can install or uninstall the application on their device through the application market.

**Figure 2** Process of installing and uninstalling an application (applicable to consumers)

![hap-intall-uninstall](figures/hap-install-uninstall-user.png)

## Updating an Application


For developers, to update an application, you need to first update the **versionCode** field in the [app.json5](./app-configuration-file.md#appjson5-configuration-file) file, package the application using DevEco Studio, and release the application in the AppGallery. For users, the application may be updated in the following approaches:

- [On the AppGallery](https://developer.huawei.com/consumer/en/doc/harmonyos-guides-V14/store-update-V14?catalogVersion=V14): The application market notifies the user of an available update, and the user can install the update by following the onscreen instructions.
- [In the application](https://developer.huawei.com/consumer/en/doc/AppGallery-connect-Guides/appgallerykit-app-update-0000001055118286): When the application for which an update is available starts up, the AppGallery notifies the user of the update, and the user can install the update by following the onscreen instructions.

