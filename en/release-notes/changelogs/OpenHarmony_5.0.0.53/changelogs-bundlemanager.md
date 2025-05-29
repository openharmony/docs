# Bundle Manager Subsystem Changelog

## cl.bundlemanager.1 Optimized File Quantity Verification in Sharing Scenarios

**Access Level**

Public API

**Reason for Change**

Verification on the number of files is optimized in sharing scenarios.

**Change Impact**

This change is a non-compatible change.

Example:<br>
An application is configured as follows for receiving files in sharing scenarios:

```
{
    "utd": "general.image",
    "maxFileSupported": 3
}
````
Both JPEG and PNG images are of the general.image type. Assume that two JPEG images and two PNG images are to be shared.

Before change:

Neither the number of JPEG images nor the number of PNG images exceeds the value of **maxFileSupported**. Therefore, the application is displayed on the sharing panel.

After change:

The total number of files of the specified type is verified. Since the total number of images is 4, exceeding the value of **maxFileSupported**, the application is not displayed on the sharing panel.

**Start API Level**

11

**Change Since**

OpenHarmony 5.0.0.53

**Key API/Component Changes**

**maxFileSupported** in [module.json5](https://gitee.com/openharmony/docs/blob/master/en/application-dev/quick-start/module-configuration-file.md#skills).

**Adaptation Guide**

The **maxFileSupported** field specifies the maximum number of files of a specified type that can be received or opened at a time. When an application is on the receiving end of sharing various types of files, it must consider the maximum number of files for each type that it can accept.
