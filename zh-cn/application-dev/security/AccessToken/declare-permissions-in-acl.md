# 申请使用受限权限

受限开放的权限通常是不允许三方应用申请的。当应用在申请权限来访问必要的资源时，发现部分权限的等级比应用APL等级高，开发者可以选择通过ACL方式来解决等级不匹配的问题，从而使用受限权限。

举例说明，如果应用需要使用全局悬浮窗，需要申请ohos.permission.SYSTEM_FLOAT_WINDOW权限，该权限属于system_basic等级。如果应用需要截取屏幕图像，则需要申请ohos.permission.CAPTURE_SCREEN权限，该权限属于system_core等级。此时，normal应用需要跨级别申请该权限。

本节提供两种方式供应用调试阶段使用。两种方式均不可用于发布上架应用市场，如果需要开发商用版本的应用，请在对应的应用市场进行发布证书和签名文件的申请。

- 方式一：通过DevEco Studio完成[ACL方式跨级别申请权限](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-signing)。

- 方式二：直接修改HarmonyAppProvision配置文件。
  1. 打开HarmonyAppProvision配置文件，即SDK目录下的“Sdk/openharmony/_{Version} _/toolchains /lib/UnsgnedReleasedProfileTemplate.json”文件。
  2. 修改 "acls" &gt; "allowed-acls" 字段。

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

  3. 重新进行应用签名。
