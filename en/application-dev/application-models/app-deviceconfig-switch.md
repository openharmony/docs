# Switching of app and deviceConfig


To help you better maintain the configuration of application-level attributes, OpenHarmony has extracted the **app** and **deviceConfig** tags from the **config.json** file to the **app.json5** file and changed certain tag names in the stage model.

**Table 1** Comparison of the app tag in the configuration files

| Configuration Item| app in config.json| app in app.json5|
| -------- | -------- | -------- |
| Internal version number of an application| "version": {<br>    "code": 1,<br>} | "versionCode":&nbsp;1&nbsp;, |
| Text description of the version number, which is displayed to users| "version": {<br>    "name": "1.0.0",<br>} | "versionName"&nbsp;:&nbsp;"1.0.0"&nbsp;, |
| Earliest compatible version of the application| "version": {<br>    "minCompatibleVersionCode":  1,<br>} | "minCompatibleVersionCode"&nbsp;:&nbsp;1&nbsp;, |
| Minimum API version required for application running| "apiVersion": {<br>    "compatible":  7,<br>}            | "minAPIVersion"&nbsp;:&nbsp;7&nbsp;, |
| Target API version required for application running| "apiVersion": {<br>    "target":  8,<br>} | "targetApiVersion"&nbsp;:&nbsp;8&nbsp;, |
| Type of the target API version required for application running| "apiVersion": {<br>    "releaseType":  Release,<br>} | "apiReleaseType":&nbsp;"Release"&nbsp;, |


OpenHarmony has reconstructed the [deviceConfig](../quick-start/deviceconfig-structure.md) tag of the **config.json** file in the **app.json5** file. It has integrated the fields related to device information under **deviceConfig** into the **app** tag of the [app.json5](../quick-start/app-configuration-file.md) file.

**Table 2** Comparison of the deviceConfig tag in the configuration files

| deviceConfig in the FA Model| Description| Stage Model| Difference|
| -------- | -------- | -------- | -------- |
| deviceConfig| Device information.| / | This tag is no longer available in the stage model. In the stage model, device information is configured under the **app** tag.|
| process | Name of the process running the application or UIAbility. If the **process** attribute is configured in the **deviceConfig** tag, all UIAbilities of the application run in this process. You can set the **process** attribute for a specific UIAbility in the **abilities** attribute, so that the UIAbility can run in the particular process.| / | The stage model does not support the configuration of process names.|
| keepAlive | Whether the application is always running. This attribute applies only to system applications and does not take effect for third-party applications.| / | The stage model does not support changing of the model control mode for system applications.|
| supportBackup | Whether the application supports data backup and restore.| / | This configuration is not supported in the stage model.|
| compressNativeLibs | Whether the **libs** libraries are packaged in the HAP file after being compressed.| / | This configuration is not supported in the stage model.|
| network | Network security configuration.| / | This configuration is not supported in the stage model.|
