# EDM


Enterprise Device Manager (EDM) provides debugging and testing capabilities for device management applications. For example, it can be used to enable or disable extended enterprise device management capabilities.

> **NOTE**
>
> Before using this tool, you must obtain the <!--Del-->[<!--DelEnd-->hdc tool<!--Del-->](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md)<!--DelEnd--> and run the **hdc shell** command.


## help
  Displays help information of EDM.

  **Return value**

  Returns the help information.

  **Method**


  ```bash
  edm help
  ```


## enable-admin
Enables the extended enterprise device management capabilities of a component. The target component must be an [EnterpriseAdminExtensionAbility](../mdm/mdm-kit-admin.md).

| Parameter| Description             |
| -------- |-------------------|
| -h/--help | Help information.            |
| -n/--bundle-name | Bundle name. This parameter is mandatory.|
| -a/--ability-name | Ability name. This parameter is mandatory.|

  **Return value**

Returns "enable-admin success." if the component is enabled; returns "error: xxx" and the corresponding error information otherwise.

| Return value                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| enable-admin success.                                        | The component is enabled.                                                  |
| error: command requires option.                              | **bundleName** and **abilityName** are not passed in.                             |
| error: -n, --bundle-name option requires an argument.        | The input value of **bundleName** is empty.                                      |
| error: -a, --ability-name option requires an argument.       | The input value of **abilityName** is empty.                                     |
| error: unknown option.                                       | An unknown parameter is passed in.                                          |
| error: -n \<bundle-name> is expected.                        | **bundleName** is not passed in.                                          |
| error: -a \<ability-name> is expected.                       | **abilityName** is not passed in.                                         |
| error: the administrator ability component is invalid.       | The input value of **bundleName** or **abilityName** is incorrect, or the component is not an EnterpriseAdminExtensionAbility. |
| error: failed to enable the administrator application of the device. | The component fails to be enabled.                                                  |

  **Method**


  ```bash
  edm enable-admin -n <bundleName> -a <abilityName>
  ```

  **Example**

```bash
# Enable the EnterpriseAdminExtensionAbility whose bundle name is com.example.mdmsample and class name is EnterpriseAdminAbility.
edm enable-admin -n com.example.mdmsample -a com.example.mdmsample.EnterpriseAdminAbility
```


## disable-admin
Disables the extended enterprise device management capabilities of a component. The target component must be an [EnterpriseAdminExtensionAbility](../mdm/mdm-kit-admin.md).

| Parameter            | Description              |
| ---------------- | ---------------------- |
| -h/--help        | Help information.            |
| -n/--bundle-name | Bundle name. This parameter is mandatory.|

  **Return value**

Returns "disable-admin success." if the component is disabled; returns "error: xxx" and the corresponding error information otherwise.

| Return value                                                      | Description                  |
| ------------------------------------------------------------ | ---------------------- |
| disable-admin success.                                       | The component is disabled.        |
| error: command requires option.                              | **bundleName** is not passed in.    |
| error: -n, --bundle-name option requires an argument.        | The input value of **bundleName** is empty.|
| error: unknown option.                                       | An unknown parameter is passed in.    |
| error: -n \<bundle-name> is expected.                        | **bundleName** is not passed in.    |
| error: failed to disable the administrator application of the device. | The component fails to be disabled.        |

  **Method**


  ```bash
  edm disable-admin -n <bundleName>
  ```

  **Example**


  ```bash
# Disable the EnterpriseAdminExtensionAbility whose bundle name is com.example.mdmsample.
edm disable-admin -n com.example.mdmsample
  ```
