# Default User Agent String

Since API version 11, the default user agent string is as follows for the **Web** component based on the ArkWeb kernel:

Mozilla/5.0 ({deviceType}; {OSName} {OSVersion}) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 ArkWeb/{ArkWeb VersionCode} {Mobile}

| Field.              | Description              | Remarks              |
| ------------------ | ------------------ | ------------------ |
| deviceType         | Device type.          | Obtained through the mapping of the system parameter **const.product.devicetype**.|
| OSName             | OS name of the distribution.| Obtained through the system parameter **const.product.os.dist.name**.|
| OSVersion          | OS version of the distribution.| Obtained through the system parameter **const.ohos.fullname**.|
| ArkWeb VersionCode | ArkWeb version.      |- |
| Mobile (optional)    | Whether the device is a mobile phone.    |- |

Example:

Mozilla/5.0 (Phone; OpenHarmony 4.1) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/114.0.0.0 Safari/537.36 ArkWeb/4.1.6.1 Mobile

You are advised to use the **ArkWeb** keyword to identify whether the device is an OpenHarmony device and whether the web kernel is ArkWeb. You can also use the **deviceType** keyword to identify the device type for page display.
