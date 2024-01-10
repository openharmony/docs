# Multi-HAP Usage Rules


- The App Pack cannot be directly installed on a device. It is only used as a form of application to be released to the application market.

- When packing HAP files into an App Pack, ensure that the settings of **bundleName**, **versionCode**, and other related fields are consistent across JSON files of the HAP files. Otherwise, the HAP validity check will fail. For details, see [HAP Validity Check During APP Packing](../tools/packing-tool.md#packing-commands-for-app-files).

- In an App Pack, each type of device supports only one HAP file of the entry type but zero, one, or more HAP files of the feature type.

- Each HAP file in the App Pack must have **moduleName** configured. Among HAP files of the same device type, the **moduleName** value must be unique.

- The signing certificates of all HAP files in the same application must be the same. Applications are released to the application market in the form of App Pack after being signed. Before distribution, the application market splits an App Pack into HAP files and resigns them to ensure the consistency of HAP file signing certificates. Before installing HAP files on a device through the CLI or DevEco Studio for debugging, ensure that their signing certificates are the same. Otherwise, the installation will fail.
