# Requesting Restricted Permissions

Generally, restricted permissions are unavailable to third-party applications. If an application with a lower APL requires a permission of a higher APL, you can declare the required permissions in the Access Control List (ACL).

For example, if a normal application needs to use the global floating window and capture screen images, it needs the ohos.permission.SYSTEM_FLOAT_WINDOW permission (which is of the system_basic level) and the ohos.permission.CAPTURE_SCREEN permission (which is of the system_core level). To enable the normal application to have the system_basic and system_core permissions, you must use the ACL.

The methods provided in this topic apply only for the applications in the debug phase. If you need to develop an application of the commercial version, apply for a release certificate and signing file in the app market.

- Method 1: Use DevEco Studio to [request permissions in the ACL](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides-V5/ide-signing-V5).

- Method 2: Declare the required permissions in the HarmonyAppProvision configuration file.
  1. Open the **Sdk/openharmony/_{Version} _/toolchains /lib/UnsgnedReleasedProfileTemplate.json** file in the SDK directory.
  2. Add the permissions in the **"acls"** &gt; **"allowed-acls"** field.

      ```json
      {
        // ...
        "acls":{
          "allowed-acls":[
            "ohos.permission.WRITE_AUDIO",
            "ohos.permission.CAPTURE_SCREEN"
          ]
        }
      }
      ```

  3. Sign the application again.
