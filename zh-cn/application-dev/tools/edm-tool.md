# edm工具

Enterprise Device Manager（企业设备管理工具，简称为edm），为设备管理应用提供调试和测试能力，例如激活企业设备管理拓展能力、解除激活企业设备管理拓展能力。

## 环境要求

在使用本工具前，开发者需要先获取<!--Del-->[<!--DelEnd-->hdc工具<!--Del-->](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md)<!--DelEnd-->，执行hdc shell。

## edm工具命令列表

| 命令          | 描述                                                         |
| ------------- | ------------------------------------------------------------ |
| help          | 帮助命令，用于查询edm支持的命令信息。                        |
| enable-admin  | 激活命令，用于激活企业设备管理拓展能力，目标组件必须为[enterpriseAdmin类型的ExtensionAbility](../mdm/mdm-kit-admin.md)。 |
| disable-admin | 解除激活命令，用于解除激活企业设备管理拓展能力。             |

## 帮助命令（help）


  ```bash
# 显示帮助信息
edm help
  ```

## 激活命令（enable-admin）


  ```bash
edm enable-admin [-h] [-n bundleName] [-a abilityName] 
  ```

**激活命令参数列表**

| 参数              | 参数说明                |
| ----------------- | ----------------------- |
| -h/--help         | 帮助信息。              |
| -n/--bundle-name  | 必选参数，bundleName。  |
| -a/--ability-name | 必选参数，abilityName。 |

 **示例**：

```bash
# 激活一个所在应用包名为com.example.mdmsample，类名为EnterpriseAdminAbility的EnterpriseAdminExtensionAbility。
edm enable-admin -n com.example.mdmsample -a com.example.mdmsample.EnterpriseAdminAbility
// 执行结果
enable-admin success.
```


## 解除激活命令（disable-admin）

  ```bash
edm disable-admin [-h] [-n bundleName]
  ```

**解除激活命令参数列表**

| 参数             | 参数说明               |
| ---------------- | ---------------------- |
| -h/--help        | 帮助信息。             |
| -n/--bundle-name | 必选参数，bundleName。 |

  **示例**：


  ```bash
# 解除激活所在应用包名为com.example.mdmsample的EnterpriseAdminExtensionAbility。
edm disable-admin -n com.example.mdmsample
// 执行结果
disable-admin success.
  ```

## edm工具错误信息

### error: command requires option.

**错误描述**

未传入bundleName和abilityName。

**可能原因**

未传入bundleName和abilityName。

**处理步骤**

1、如果当前使用的命令是enable-admin，请补充-n \<bundle-name\>和-a \<ability-name\>参数。

2、如果当前使用的命令是disable-admin，请补充-n \<bundle-name\>参数。

### error: -n, --bundle-name option requires an argument.

**错误描述**

传入的bundleName为空。

**可能原因**

传入的bundleName为空。

**处理步骤**

检查-n后的参数，请补充bundleName。

### error: -a, --ability-name option requires an argument.

**错误描述**

 传入的abilityName为空。

**可能原因**

 传入的abilityName为空。

**处理步骤**

检查-a后的参数，请补充abilityName。

### error: unknown option.

**错误描述**

 传入了未知的参数。

**可能原因**

 传入了未知的参数。

**处理步骤**

请确认参数是否在参数列表中。

### error: -n \<bundle-name\> is expected.

**错误描述**

未传入bundleName。

**可能原因**

未传入bundleName。

**处理步骤**

请补充-n \<bundle-name\>。

### error: -a \<ability-name\> is expected.

**错误描述**

未传入abilityName。

**可能原因**

未传入abilityName。

**处理步骤**

请补充-a \<ability-name\>。

### error: the administrator ability component is invalid.

**错误描述**

传入的bundleName或者abilityName不正确或者不是enterpriseAdmin类型的ExtensionAbility。

**可能原因**

1、传入的bundleName不正确。

2、传入的abilityName不正确。

3、传入的不是enterpriseAdmin类型的ExtensionAbility。

**处理步骤**

查询应用的bundleName和enterpriseAdmin类型的ExtensionAbility的abilityName，并将其传入到参数中。

### error: failed to enable the administrator application of the device.

**错误描述**

激活失败。

**可能原因**

1、传入的bundleName不正确。

2、传入的不是enterpriseAdmin类型的ExtensionAbility。

3、存在已激活的正式的enterpriseAdmin类型的ExtensionAbility。

**处理步骤**

1、查询应用的bundleName和enterpriseAdmin类型的ExtensionAbility的abilityName，并将其传入到参数中。

2、请使用未被管控的设备进行调试。

### error: failed to disable the administrator application of the device.

**错误描述**

解除激活失败。

**可能原因**

解除激活失败。

**处理步骤**

查询应用的bundleName，并将其传入到参数中。