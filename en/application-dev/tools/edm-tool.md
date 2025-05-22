# EDM

Enterprise Device Manager (edm) provides debugging and testing capabilities for device management applications. For example, it can be used to enable or disable extended enterprise device management capabilities.

## Environment Setup

Before using this tool, you must obtain the <!--Del-->[<!--DelEnd-->hdc tool<!--Del-->](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md)<!--DelEnd--> and run the **hdc shell** command.

## edm Commands

| Command         | Description                                                        |
| ------------- | ------------------------------------------------------------ |
| help          | Displays the commands supported by the edm tool.                       |
| enable-admin  | Enables the extended enterprise device management capabilities of a component. The target component must be an [EnterpriseAdminExtensionAbility](../mdm/mdm-kit-admin.md).|
| disable-admin | Disables the extended enterprise device management capabilities of a component.            |

## help Command


  ```bash
# Display the help information.
edm help
  ```

## enable-admin Command


  ```bash
# Display the help information.
edm enable-admin -h
# Enable the extended enterprise device management capabilities.
edm enable-admin -n <bundleName> -a <abilityName> [-t <adminType>]
  ```

**Parameters in the enable-admin command**

| Parameter             | Description                                                    |
| ----------------- | ------------------------------------------------------------ |
| -h/--help         | Help information.                                                  |
| -n/--bundle-name  | Bundle name. This parameter is mandatory.                                      |
| -a/--ability-name | Ability name. This parameter is mandatory.                                     |
| -t/--admin-type   | Admin type. This parameter is optional.<br>The value can be:<br>**super**: a super device management application.<br>**byod**: a BYOD device management application.<br>The default value is **super**.|

 **Example**

```bash
# Enable the EnterpriseAdminExtensionAbility whose bundle name is com.example.mdmsample and class name is EnterpriseAdminAbility.
edm enable-admin -n com.example.mdmsample -a com.example.mdmsample.EnterpriseAdminAbility
# Execution result.
enable-admin success.
```


## disable-admin Command

  ```bash
# Display the help information.
edm disable-admin -h
# Disable the extended enterprise device management capabilities.
edm disable-admin -n <bundleName>
  ```

**Parameters in the disable-admin command**

| Parameter            | Description              |
| ---------------- | ---------------------- |
| -h/--help        | Help information.            |
| -n/--bundle-name | Bundle name. This parameter is mandatory.|

  **Example**


  ```bash
# Disable the EnterpriseAdminExtensionAbility whose bundle name is com.example.mdmsample.
edm disable-admin -n com.example.mdmsample
# Execution result.
disable-admin success.
  ```

## Error Messages

### error: command requires option

**Symptom**

**bundleName** and **abilityName** are not passed in.

**Possible Causes**

**bundleName** and **abilityName** are not passed in.

**Solution**

1. If the **enable-admin** command is used, add the **-n \<bundle-name\>** and **-a \<ability-name\>** parameters.

2. If the **disable-admin** command is used, add the **-n \<bundle-name\>** parameter.

### error: -n, --bundle-name option requires an argument

**Symptom**

The input value of **bundleName** is empty.

**Possible Causes**

The input value of **bundleName** is empty.

**Solution**

Check the parameters following **-n** and add **bundleName**.

### error: -a, --ability-name option requires an argument

**Symptom**

 The input value of **abilityName** is empty.

**Possible Causes**

 The input value of **abilityName** is empty.

**Solution**

Check the parameters following **-a** and add **abilityName**.

### error: unknown option

**Symptom**

 An unknown parameter is passed in.

**Possible Causes**

 An unknown parameter is passed in.

**Solution**

Check whether the parameter is in the parameter list.

### error: -n \<bundle-name\> is expected

**Symptom**

**bundleName** is not passed in.

**Possible Causes**

**bundleName** is not passed in.

**Solution**

Add **-n \<bundle-name\>** to the command.

### error: -a \<ability-name\> is expected

**Symptom**

**abilityName** is not passed in.

**Possible Causes**

**abilityName** is not passed in.

**Solution**

Add **-a \<ability-name\>** to the command.

### error: the administrator ability component is invalid

**Symptom**

The input value of **bundleName** or **abilityName** is incorrect, or the component is not an EnterpriseAdminExtensionAbility. 

**Possible Causes**

1. The bundleName is incorrect.

2. The input abilityName is incorrect.

3. The component is not an **EnterpriseAdminExtensionAbility**.

**Solution**

Obtain the **bundleName** of the application and the **abilityName** of the **EnterpriseAdminExtensionAbility**, and pass them to the parameter.

### error: failed to enable the administrator application of the device

**Symptom**

The component fails to be enabled.

**Possible Causes**

1. The bundleName is incorrect.

2. The component is not an **EnterpriseAdminExtensionAbility**.

3. An activated **EnterpriseAdminExtensionAbility** exists.

**Solution**

1. Obtain the **bundleName** of the application and the **abilityName** of the **EnterpriseAdminExtensionAbility**, and pass them to the parameter.

2. Use an uncontrolled device for debugging.

### error: failed to disable the administrator application of the device

**Symptom**

The component fails to be disabled.

**Possible Causes**

1. The component is not activated.

2. The component is not activated by running the hdc command.

3. The deactivation fails.

**Solution**

Obtain the **bundleName** of the application that can be deactivated by the hdc command and pass the **bundleName** to the parameter.
