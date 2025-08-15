# 申请受限权限

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--Designer: @linshuqing; @hehehe-li-->
<!--Tester: @leiyuqian-->
<!--Adviser: @zengyawen-->

受限权限通常不允许第三方应用申请。当应用需要访问必要资源时，如果发现某些权限的等级高于应用权限等级（APL），开发者可以通过ACL方式来解决等级不匹配的问题，从而使用受限权限。

举例说明：应用需要使用全局悬浮窗时，需申请ohos.permission.SYSTEM_FLOAT_WINDOW权限（system_basic等级）；需要截取屏幕图像时，需申请ohos.permission.CAPTURE_SCREEN权限（system_core等级）。此时，normal应用需要跨级别申请该权限。

本节提供两种调试方法。这两种方式均不可用于发布上架应用市场。如需发布商用版本，请在对应的应用市场申请发布证书和签名文件。

- 方式一：通过DevEco Studio完成[ACL方式跨级别申请权限](https://developer.huawei.com/consumer/cn/doc/harmonyos-guides/ide-signing)。

- 方式二：直接修改HarmonyAppProvision配置文件。
  1. 打开HarmonyAppProvision配置文件，即SDK目录下的“Sdk/openharmony/_{Version} _/toolchains /lib/UnsgnedReleasedProfileTemplate.json”文件。
  2. 在配置文件中添加需要使用的受限权限。

      - 不携带权限数据的受限权限可通过修改 "acls" &gt; "allowed-acls" 字段来添加。
      - 携带权限数据的受限权限可通过修改 "app-services-capabilities" 字段添加。

        ```json
        {
          // ...
          "acls":{
            "allowed-acls":[
              "ohos.permission.WRITE_AUDIO",
              "ohos.permission.CAPTURE_SCREEN"
            ]
          },
          "app-services-capabilities": {
              "ohos.permission.ACCESS_DDK_DRIVERS": "..."
          }
        }
        ```

  3. 重新对应用进行签名。
