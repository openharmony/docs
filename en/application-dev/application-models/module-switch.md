# Switching of module


When switching an application from the FA model to the stage model, migrate the configurations under **module** in the **config.json** file to **module** in the **module.json5** file.

**Table 1** module comparison

| Field Name in the FA Model| Field Description| Field Name in the Stage Model| Difference|
| -------- | -------- | -------- | -------- |
| mainAbility | Ability displayed on the Service Center icon. When the resident process is started, the **mainAbility** is started.| mainElement | The field name is changed, and the stage mode does not use the period (.) in ability names.|
| package | Package name of the HAP file, which must be unique in the application.| / | The stage model uses **name** to ensure application uniqueness. To ensure a successful switching from the FA model to the stage model, **name** in the stage model must be the same as **package** in the FA model.|
| name | Class name of the HAP file.| / | This configuration is not enabled in the FA model, and the stage model does not have such a field.|
| supportedModes | Modes supported by the application. Currently, only the **drive** mode is defined.| / | This configuration is deprecated in the stage model.|
| moduleName in the distro object| Name of the current HAP file.<br>moduleName in the distro object.| name | The field name is changed.|
| moduleType in the distro object| Type of the HAP file. The value can be **entry** or **feature**. For the HAR type, set this field to **har**.| type | The field name is changed.|
| installationFree in the distro object| Whether the HAP file supports the installation-free feature.| installationFree | The field name is changed.|
| deliveryWithInstall in the distro object| Whether the HAP file is installed with the application.| deliveryWithInstall | The field name is changed.|
| metaData | Metadata of the HAP file.| metadata | For details, see Table 2.|
| abilities | All abilities in the current module.| abilities | For details, see Table 5.|
| js | A set of JS modules developed using ArkUI. Each element in the set represents the information about a JS module.| pages | The stage model retains **pages** under the **module** tag. The window configuration is the lower level of **pages**.|
| shortcuts | Shortcuts of the application.| shortcut_config.json| In the stage model, the **shortcut_config.json** file is defined in **resources/base/profile** in the developer view.|
| reqPermissions | Permissions that the application requests from the system when it is running.| requestPermissions | The field name is changed.|
| colorMode | Color mode of the application.| / | This configuration is not supported in the stage model.|
| distroFilter | Distribution rules of the application.| distributionFilter_config.json| In the stage model, the **distributionFilter_config.json** file is defined in **resources/base/profile** in the developer view.|
| reqCapabilities | Device capabilities required for running the application.| / | This configuration is not supported in the stage model.|
| commonEvents | Common events.| common_event_config.json| In the stage model, the **common_event_config.json** file is defined in **resources/base/profile** in the developer view.|
| entryTheme | Keyword of an internal theme.| / | This configuration is not supported in the stage model.|


**Table 2** metaData comparison

| Field Name in the FA Model| Field Description| Field Name in the Stage Model| Difference|
| -------- | -------- | -------- | -------- |
| parameters | Metadata of the parameters to be passed for calling the ability.| / | This configuration is not supported in the stage model.|
| results | Metadata of the ability return value.| / | This configuration is not supported in the stage model.|
| customizeData | Custom metadata of the parent component. **parameters** and **results** cannot be configured in **application**.| metadata | **For details**, see Table 3.|

**Table 3** Comparison between customizeData under metaData in the FA model and metadata in the stage Model

| Field Name in the FA Model| Field Description| Field Name in the Stage Model| Difference|
| -------- | -------- | -------- | -------- |
| name | Key name that identifies a data item. The value is a string with a maximum of 255 bytes.| name | None.|
| value | Value of the data item. The value is a string with a maximum of 255 bytes.| value | None.|
| extra | Format of the current custom data. The value is the resource value of **extra**.| resource | The field name is changed. For details, see Table 4.|


**Table 4** metaData examples

| Example in the FA Model| Example in the Stage Model|
| -------- | -------- |
| "meteData": {<br>    "customizeDate": [{<br>        "name": "label",<br>        "value": "string",<br>        "extra": "$string:label",<br>    }]<br>} | "meteData": [{<br>    "name": "label",<br>    "value": "string",<br>    "resource": "$string:label",<br>}] |


**Table 5** abilities comparison

| Field Name Under abilities in the FA Model| Field Description| Field Name Under abilities in the Stage Model| Difference|
| -------- | -------- | -------- | -------- |
| process | Name of the process running the application or ability.| / | The stage model does not support configuration of **process** under **abilities**. The configuration of **process** is available under the **module** tag.|
| uri | URI of the ability.| / | This configuration is not supported in the stage model.|
| deviceCapability | Device capabilities required to run the ability.| / | This configuration is not supported in the stage model.|
| metaData | Metadata of the ability.| metadata | For details, see Table 2.|
| type | Ability type.| / | This configuration is not supported in the stage model.|
| grantPermission | Whether permissions can be granted to any data in the ability.| / | The stage model does not support such a configuration under **abilities**.|
| readPermission | Permission required for reading data in the ability. This field applies only to the ability using the Data template.| / | In the stage model, this configuration is available under **extensionAbilities**, but not **abilities**.|
| writePermission | Permission required for writing data to the ability.| / | In the stage model, this configuration is available under **extensionAbilities**, but not **abilities**.|
| configChanges | System configurations that the ability concerns.| / | This configuration is not supported in the stage model.|
| mission | Mission stack of the ability.| / | This configuration is not supported in the stage model.|
| targetAbility | Target ability that this ability alias points to.| / | This configuration is not supported in the stage model.|
| multiUserShared | Whether the ability supports data sharing among multiple users. This field applies only to the ability using the Data template.| / | This configuration is not supported in the stage model.|
| supportPipMode | Whether the ability allows the user to enter the Picture in Picture (PiP) mode. The PiP mode enables the user to watch a video in a small window that hovers on top of a full screen window (main window).| / | This configuration is not supported in the stage model.|
| formsEnabled | Whether the ability can provide widgets.| / | This configuration is not supported in the stage model.|
| forms | Information about the widgets used by the ability. This field is valid only when **formsEnabled** is set to **true**.| form_config.json| In the stage model, the **form_config.json** file is defined in **resources/base/profile** in the developer view.|
| srcLanguage | Programming language used to develop the ability.| / | This configuration is not supported in the stage model.|
| srcPath | Path of the JS component code corresponding to the ability.| srcEntry | Path of the JS code corresponding to the ability.|
| uriPermission | Application data that the ability can access.| / | This configuration is not supported in the stage model.|
