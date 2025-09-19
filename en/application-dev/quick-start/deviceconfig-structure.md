# Structure of the deviceConfig Tag
<!--Kit: Ability Kit-->
<!--Subsystem: BundleManager-->
<!--Owner: @wanghang904-->
<!--Designer: @hanfeng6-->
<!--Tester: @kongjing2-->
<!--Adviser: @Brilliantry_Rui-->

The **deviceConfig** tag contains device-specific configuration of the application, including attributes such as **default**, **tv**, **car**, and **wearable**. The configuration in the **default** tag applies to all common devices. If a specific configuration is required for other device types, you need to configure in the corresponding tag.

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
| keepAlive | Whether the application keeps running. This attribute applies only to system applications and does not take effect for third-party applications.<br>- **true**: The application keeps running. The system starts the application upon its startup and restarts the application when the application exits.<br>- **false**: The application does not keep running. The system neither starts the application upon its startup nor restarts the application when the application exits.| Boolean| Yes (initial value: **false**)|
| supportBackup | Whether the application supports backup and restoration.<br>- **true**: Yes<br>- **false**: No| Boolean| Yes (initial value: **false**)|
| compressNativeLibs | Whether libraries are stored in the HAP after being compressed during HAP packaging.<br>- **true**: Libraries are stored in the HAP file after being compressed.<br>- **false**: Libraries are stored without being compressed.<br>Whether libraries need to be decompressed during application installation. (Since API version 16, this field is supported. In earlier versions, libraries are decompressed by default.)<br>- **true**: Libraries need to be decompressed.<br>- **false**: Libraries do not need to be decompressed.| Boolean| Yes (During HAP packaging, initial value: **false**; during application installation, initial value: **true**)|
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
| cleartextPermitted | Whether cleartext is allowed in the custom network domain. If both **cleartextTraffic** and **securityConfig** exist, the value of **cleartextPermitted** is used.<br>- **true**: Cleartext is allowed.<br>- **false**: Cleartext is not allowed.| Boolean| Yes (initial value: **false**)|
| domains | Domain name. This attribute consists of two sub-attributes: **subdomains** and **name**.<br>- **subdomains** (boolean): whether the domain name contains subdomains. If it is set to **true**, the domain naming convention applies to all related domains and subdomains (including the lower-level domains of the subdomains). Otherwise, the convention applies only to exact matches.<br>- **name** (string): domain name.| Object array| Yes (initial value: left empty)|

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
