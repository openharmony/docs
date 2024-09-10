# edm工具


Enterprise Device Manager（企业设备管理工具，简称为edm），为设备管理应用提供调试和测试能力，例如激活企业设备管理拓展能力、解除激活企业设备管理拓展能力。

> **说明：**
>
> 在使用本工具前，开发者需要先获取<!--Del-->[<!--DelEnd-->hdc工具<!--Del-->](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md)<!--DelEnd-->，执行hdc shell。


## help
  用于显示edm相关的帮助信息。

  **返回值**：

  返回对应的帮助信息。

  **使用方法**：


  ```bash
  edm help
  ```


## enable-admin
用于激活企业设备管理拓展能力，目标组件必须为[enterpriseAdmin类型的ExtensionAbility](../mdm/mdm-kit-admin.md)。

| 参数 | 参数说明              |
| -------- |-------------------|
| -h/--help | 帮助信息。             |
| -n/--bundle-name | 必选参数，bundleName。 |
| -a/--ability-name | 必选参数，abilityName。 |

  **返回值**：

当激活成功时，返回"enable-admin success."；当激活失败时，返回"error: xxx"，xxx为相应的失败信息。

| 返回值                                                       | 说明                                                         |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| enable-admin success.                                        | 激活成功。                                                   |
| error: command requires option.                              | 未传入bundleName和abilityName。                              |
| error: -n, --bundle-name option requires an argument.        | 传入的bundleName为空。                                       |
| error: -a, --ability-name option requires an argument.       | 传入的abilityName为空。                                      |
| error: unknown option.                                       | 传入了未知的参数。                                           |
| error: -n \<bundle-name> is expected.                        | 未传入bundleName。                                           |
| error: -a \<ability-name> is expected.                       | 未传入abilityName。                                          |
| error: the administrator ability component is invalid.       | 传入的bundleName或者abilityName不正确或者不是enterpriseAdmin类型的ExtensionAbility。 |
| error: failed to enable the administrator application of the device. | 激活失败。                                                   |

  **使用方法**：


  ```bash
  edm enable-admin -n <bundleName> -a <abilityName>
  ```

  **示例**：

```bash
# 激活一个所在应用包名为com.example.mdmsample，类名为EnterpriseAdminAbility的EnterpriseAdminExtensionAbility。
edm enable-admin -n com.example.mdmsample -a com.example.mdmsample.EnterpriseAdminAbility
```


## disable-admin
用于解除激活企业设备管理拓展能力，目标组件必须为[enterpriseAdmin类型的ExtensionAbility](../mdm/mdm-kit-admin.md)。

| 参数             | 参数说明               |
| ---------------- | ---------------------- |
| -h/--help        | 帮助信息。             |
| -n/--bundle-name | 必选参数，bundleName。 |

  **返回值**：

当解除激活成功时，返回"disable-admin success."；当解除激活失败时，返回"error: xxx"，xxx为相应的失败信息。

| 返回值                                                       | 说明                   |
| ------------------------------------------------------------ | ---------------------- |
| disable-admin success.                                       | 解除激活成功。         |
| error: command requires option.                              | 未传入bundleName。     |
| error: -n, --bundle-name option requires an argument.        | 传入的bundleName为空。 |
| error: unknown option.                                       | 传入了未知的参数。     |
| error: -n \<bundle-name> is expected.                        | 未传入bundleName。     |
| error: failed to disable the administrator application of the device. | 解除激活失败。         |

  **使用方法**：


  ```bash
  edm disable-admin -n <bundleName>
  ```

  **示例**：


  ```bash
# 解除激活所在应用包名为com.example.mdmsample的EnterpriseAdminExtensionAbility。
edm disable-admin -n com.example.mdmsample
  ```
