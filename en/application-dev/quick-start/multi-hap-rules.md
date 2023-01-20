# Multi-HAP Usage Rules


- The App Pack cannot be directly installed on the device. It is only a unit that is released to AppGallery.

- All HAP files in the App Pack must share the same **bundleName** value in the configuration files.

- All HAP files in the App Pack must share the same **versionCode** value in the configuration files.

- In an application, each type of device supports only one HAP of the entry type. Each application can contain zero, one, or more HAP files of the feature type.

- Each HAP file in the App Pack must have **moduleName** configured. The **moduleName** value corresponding to all HAP files of the same device type must be unique.

- The signing certificates of all HAP files in the same application must be the same. Applications are released to the application market in the form of App Pack after being signed. Before distribution, the application market splits an App Pack into HAP files and resigns them to ensure the consistency of all HAP file signing certificates. Before installing HAP files on a device through the CLI or DevEco Studio for debugging, you must ensure that their signing certificates are the same. Otherwise, the installation will fail.
