# Structure of the deviceConfig Tag


The **deviceConfig** tag contains device-specific configuration of the application, including attributes such as **default**, **tv**, **car**, and **wearable**. The **default** configuration applies to all types of devices. You need to declare the peculiar configuration of a specific device type in the associated sub-tag of this type.

## Internal Structure of the deviceConfig Tag

**Table 1** Internal structure of the deviceConfig tag

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| default | Application configuration that provides full access to system capabilities.| Object| Yes (initial value: left empty)|
| tablet | Application configuration specific to tablets.| Object| Yes (initial value: left empty)|
| tv | Application configuration specific to smart TVs.| Object| Yes (initial value: left empty)|
| car | Application configuration specific to telematics devices.| Object| Yes (initial value: left empty)|
| wearable | Application configuration specific to wearables.| Object| Yes (initial value: left empty)|


For details about the attributes of the **deviceConfig** tag, see [Internal Structure of the deviceConfig Attributes](#internal-structure-of-the-deviceconfig-attributes).

## Internal Structure of the deviceConfig Attributes

**Table 2** Internal structure of the deviceConfig attributes

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| process | Name of the process running the application or ability. If the **process** attribute is configured in the **deviceConfig** tag, all abilities of the application run in this process. You can set the **process** attribute for a specific ability in the **abilities** attribute, so that the ability can run in the particular process. The value can contain a maximum of 31 characters.| String| Yes (initial value: left empty)|
| keepAlive | Whether the application is always running. This attribute applies only to system applications and does not take effect for third-party applications. The value **true** means that the application will start during the OS startup and keep alive. If the application process exits, the OS will restart it.| Boolean| Yes (initial value: **false**)|
| supportBackup | Whether the application supports backup and restoration. The value **false** means that the application does not support backup or restoration.| Boolean| Yes (initial value: **false**)|
| compressNativeLibs | During HAP packaging, whether the **libs** libraries are packaged to HAP after being compressed.<br>- **true**: The **libs** libraries are packaged in the HAP file after being compressed.<br>- **false**: The **libs** libraries are stored without being compressed.<br>During application installation, whether the **libs** library needs to be decompressed. (Since API version 16, this field is supported. In earlier versions, the **libs** library is decompressed by default.)<br>- **true**: The **libs** library is decompressed.<br>- **false**: The **libs** library is not decompressed.| Boolean| Yes (During HAP packaging, initial value: **false**; during application installation, initial value: **true**)|
| network | Network security configuration. You can customize the network security settings of the application in the security statement of the configuration file without modifying the application code.| Object| Yes (initial value: left empty)|

## Internal Structure of the network Attribute

**Table 3** Internal structure of the network attribute

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| cleartextTraffic | Whether to allow the application to use plaintext traffic, for example, plaintext HTTP traffic.<br>- **true**: The application is allowed to use plaintext traffic.<br>- **false**: The application is not allowed to use plaintext traffic.| Boolean| Yes (initial value: **false**)|
| securityConfig | Network security configuration of the application.| Object| Yes (initial value: left empty)|

## Internal Structure of the securityConfig Attribute

**Table 4** Internal structure of the securityConfig attribute

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| domainSettings | Security settings of the custom network domain. This attribute allows nested domains. That is, the **domainSettings** object of a network domain can be nested with the **domainSettings** objects of smaller network domains.| Object| Yes (initial value: left empty)|

## Internal Structure of the domainSettings Attribute

**Table 5** Internal structure of the domainSettings attribute

| Name| Description| Data Type| Initial Value Allowed|
| -------- | -------- | -------- | -------- |
| cleartextPermitted | Whether cleartext is allowed in the custom network domain. If both **cleartextTraffic** and **security** are declared, whether cleartext is allowed in the custom network domain is determined by **cleartextPermitted**.<br>- **true**: Cleartext is allowed.<br>- **false**: Cleartext is not allowed.| Boolean| Yes (initial value: left empty)|
| domains | Domain name. This attribute consists of two sub-attributes: **subdomains** and **name**.<br>- **subdomains** (boolean): specifies whether the domain name contains subdomains. If it is set to **true**, the domain naming convention applies to all related domains and subdomains (including the lower-level domains of the subdomains). Otherwise, the convention applies only to exact matches.<br>- **name** (string): indicates the domain name.| Object array| Yes (initial value: left empty)|

Example of the **deviceConfig** tag:

```json
"deviceConfig": {
  "default": {
    "process": "com.example.test.example",
    "supportBackup": false,
    "network": {
      "cleartextTraffic": true,
      "securityConfig": {
        "domainSettings": {
          "cleartextPermitted": true,
          "domains": [
            {
              "subdomains": true,
              "name": "example.ohos.com"
            }
          ]
        }
      }
    }
  }
}
```
