#  HarmonyAppProvision配置文件说明
在应用的开发过程中，应用的权限、签名信息等需要在HarmonyAppProvision配置文件（该文件在部分文档中也称为profile文件）中声明。

## 配置文件的内部结构
HarmonyAppProvision文件包含version-code对象、version-name对象、uuid对象、type对象、issuer对象、validity对象、bundle-info对象、acls对象、permissions对象、debug-info对象、app-privilege-capabilities对象等部分组成。

| 属性名称     | 含义                                                                                     | 数据类型 | 是否必选 | 是否可缺省 |
| ----------- | ---------------------------------------------------------------------------------------- | -------- | -------- | -------- |
| version-code | 表示HarmonyAppProvision文件格式的版本号，取值范围为二进制32位以内的正整数。 | 数值   | 必选 | 不可缺省                 |
| version-name     | 表示版本号的文字描述，推荐使用三段数字版本号，如A.B.C。        | 字符串   | 必选 | 不可缺省 |
| uuid    | 表示文件的唯一ID号，用于OEM厂商标识HarmonyAppProvision文件，开源社区版本该属性不做强制要求。                       | 字符串     | 必选 | 不可缺省 |
| type | 表示HarmonyAppProvision文件的类型， 系统预定义的文件类型包括：debug（用于应用调试场景）和release（用于应用发布场景） ，开源社区版本该属性值建议为debug。 | 字符串     | 必选 | 不可缺省 |
| app-distribution-type | 表示应用的分发类型，分发类型包括: <li>app_gallery：应用市场分发的应用。 <li> enterprise：企业应用，可以安装到个人设备上。<li> enterprise_mdm：企业MDM应用，只能安装在企业设备上。需要设备管理特权，比如远程锁定，安装普通企业应用等。 <li>enterprise_normal：普通企业应用，只能通过企业MDM应用安装在企业设备上。无需设备管理特权。<li>os_integration：系统预置应用。<li>crowdtesting：众包测试应用。<li>none：其他。 | 字符串 | 必选 | 不可缺省 |
| issuer | 表示HarmonyAppProvision签发者。        | 字符串     | 必选 | 不可缺省 |
| validity    | 表示HarmonyAppProvision文件有效期的信息。参考[validity对象内部结构](#validity对象内部结构)。  | 对象     | 必选 | 不可缺省  |
| bundle-info | 表示应用包以及开发者的信息。参考[bundle-info对象内部结构](#bundle-info对象内部结构)。         | 对象     | 必选 | 不可缺省  |
| acls        | 表示授权的acl权限信息。参考[acls对象内部结构](#acls对象内部结构)。                           | 对象     | 可选 | 可缺省    |
| permissions | 表示允许使用的受限敏感权限信息。参考[permissions对象内部结构](#permissions对象内部结构)。      | 对象     | 可选 | 可缺省    |
| debug-info  | 表示应用调试场景下的额外信息。参考[debug-info对象内部结构](#debug-info对象内部结构)。          | 对象     | 可选 | 可缺省         |
| app-privilege-capabilities | 表示应用包所需要的特权信息。可以参考[应用特权配置指南](../../device-dev/subsystems/subsys-app-privilege-config-guide.md)。   | 字符串数组 | 可选 | 可缺省         |

HarmonyAppProvision文件示例：
```json
{
    "version-code": 1,
    "version-name": "1.0.0",
	"uuid": "string",
	"type": "debug",
	"app-distribution-type": "os_integration",
	"validity": {
		"not-before": 1586422743,
		"not-after": 1617958743
	},
	"bundle-info" : {
		"developer-id": "OpenHarmony",
		"development-certificate": "Base64 string",
		"distribution-certificate": "Base64 string",
		"bundle-name": "com.OpenHarmony.app.test",
		"apl": "normal",
		"app-feature": "hos_normal_app",
		"data-group-ids": [
			"testGroupId1",
			"testGroupId2"
		]
	},
	"acls": {
		"allowed-acls": ["string"]
    },
	"permissions": {
		"restricted-permissions": ["string"]
    },
    "debug-info" : {
	    "device-id-type": "udid",
	    "device-ids": ["string"]
    },
    "app-privilege-capabilities":["AllowAppUsePrivilegeExtension"],
    "issuer": "OpenHarmony"
}

```

### validity对象内部结构

| 属性名称    | 含义                            | 数据类型 | 是否必选 | 是否可缺省 |
| ---------- | ------------------------------- | ------- | ------- | --------- |
| not-before | 表示文件有效期的开始时间，时间表示方式为unix时间戳，非负整数。 | 数值    | 必选 | 不可缺省   |
| not-after  | 表示文件有效期的结束时间，时间表示方式为unix时间戳，非负整数。 | 数值    | 必选 | 不可缺省   |

### bundle-info对象内部结构

**说明：** HarmonyAppProvision文件中的bundle-info对象中bundle-name需要和所签名应用的包名bundleName（config.json/module.json5）保持一致。为了防止同一个HarmonyAppProvision配置文件任意用于不同应用的签名，在应用安装过程中，系统会校验HAP签名信息的bundleName与HAP的配置文件中的bundleName是否一致，如果不一致，HAP无法安装。

| 属性名称                  | 含义                            | 数据类型 | 是否必选 | 是否可缺省 |
| ------------------------ | ------------------------------- | ------- | -------- | --------- |
| developer-id | 表示开发者的唯一ID号，用于OEM厂商标识开发者，开源社区版本该属性不做强制要求。 | 字符串    | 必选 | 不可缺省   |
| development-certificate  | 表示[调试证书](hapsigntool-guidelines.md)的信息。 | 数值    | 当type属性为debug时，该属性必选；否则，该属性可选。   | 不可缺省   |
| distribution-certificate  | 表示[发布证书](hapsigntool-guidelines.md)的信息。 | 数值    | 当type属性为release时，该标签必选；否则，该标签可选。 | 不可缺省   |
| bundle-name  | 表示应用程序的Bundle名称。 | 字符串    | 必选 | 不可缺省   |
| apl  | 表示应用程序的[APL级别](AccessToken/access-token-overview.md)，系统预定义的apl包括：normal、system_basic和system_core。 | 字符串    | 必选 | 不可缺省   |
| app-feature  | 表示应用程序的类型，系统预定义的app-feature包括hos_system_app （系统应用）和hos_normal_app（普通应用）。只有系统应用才允许调用系统API，普通应用调用系统API可能会调用失败或运行异常。 | 字符串    | 必选 | 不可缺省   |
| data-group-ids  | 表示应用程序的dataGroupId集合。在应用程序安装时，每一个dataGroupId都会生成一个目录。若两个应用的data-group-ids存在某个相交的dataGroupId，或者一个ExtensionAbility在其对应的[module.json5](../quick-start/module-configuration-file.md#extensionabilities标签)文件中声明的dataGroupIds和其所在应用的data-group-ids存在某个相交的dataGroupId，那么它们之间可以共享这个dataGroupId生成的共享数据目录。 | 字符串数组    | 可选 | 该标签可缺省，缺省值为空。   |
| app-identifier | 应用的唯一标识，由云端统一分配。该ID在应用全生命周期中不会发生变化，包括版本升级、证书变更、开发者公私钥变更、应用转移等。 | 字符串数组    | 可选 | 该标签可缺省，缺省值为空。   |


### acls对象内部结构
acls对象包含已授权的[ACL权限](AccessToken/permissions-for-system-apps.md)。需要指出的是，开发者仍然需要在[应用包配置文件](../quick-start/module-configuration-file.md#requestpermissions标签)将acls权限信息填写到requestPermissions属性中。

| 属性名称                  | 含义                            | 数据类型 | 是否必选 | 是否可缺省 |
| ------------------------ | ------------------------------- | ------- | ------- | --------- |
| allowed-acls | 表示已授权的[ACL权限](AccessToken/permissions-for-system-apps.md)列表。 | 字符串数组    | 可选 | 不可缺省   |

### permissions对象内部结构
permissions对象包含允许使用的受限敏感权限。不同于acls对象，permissions对象中的权限仅代表应用允许使用该敏感权限，权限最终由用户运行时授权。需要指出的是，开发者仍然需要在[应用包配置文件](../quick-start/module-configuration-file.md#requestpermissions标签)将permissions权限信息填写到requestPermissions属性中。

| 属性名称                  | 含义                            | 数据类型 | 是否必选 | 是否可缺省 |
| ------------------------ | ------------------------------- | ------- | ------- | --------- |
| restricted-permissions | 表示允许使用的[受限敏感权限](AccessToken/permissions-for-all.md#user_grant用户授权权限列表)。 | 字符串数组    | 可选 | 不可缺省   |

### debug-info对象内部结构
debug-info对象包含应用调试场景下的信息，主要是设备管控的信息。

| 属性名称                  | 含义                            | 数据类型 | 是否必选 | 是否可缺省 |
| ------------------------ | ------------------------------- | ------- | ------- | --------- |
| device-id-type | 表示设备ID的类型，当前系统仅提供udid的设备ID类型。 | 字符串    | 可选 | 不可缺省   |
| device-ids | 表示应用调试场景下允许调试的设备ID列表。 | 字符串数组    | 可选 | 不可缺省   |

## 修改HarmonyAppProvision配置文件

当开发者新建一个工程时，应用的类型默认为hos_normal_app（普通应用），APL级别默认为normal。

当需要使用系统API时，开发者需要手动修改app-feature字段为hos_system_app（系统应用）；当需要申请高级别权限时，开发者可能需要修改apl、acl等字段，请根据实际需要，参考[访问控制开发概述](AccessToken/access-token-overview.md)进行修改。


开发者可以参考以下步骤，修改HarmonyAppProvision配置文件。

1. 打开OpenHarmony SDK所在目录（可通过DevEco Studio菜单栏中单击File > Settings > OpenHarmony SDK界面查看 ）。
2. 在SDK目录下，进入Toolchains > {Version} > lib文件夹，打开“UnsignedReleasedProfileTemplate.json”文件。
3. 根据实际需求，修改对应的字段。

完成配置文件修改后，开发者可以参考[Hap包签名工具使用指导](hapsigntool-overview.md)进行应用签名。

<!--no_check-->