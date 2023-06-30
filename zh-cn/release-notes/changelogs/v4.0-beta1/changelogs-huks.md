# HUKS子系统ChangeLog

OpenHarmony 4.0.6.1 版本相较于OpenHarmony 之前的版本，HUKS的API使用权限变更如下。

## cl.huks.1 attestKeyItem接口使用权限变更

attestKeyItem是基于设备证书链封装业务公钥对用户指定的密钥进行证明，如果设备证书随意导出涉及用户隐私风险，所以此接口需要增加系统权限管控。

**变更影响**

对于不具备system权限或者ohos.permission.ACCESS_IDS权限的应用，无法正常使用attestKeyItem接口。

**关键的接口/组件变更**

- 涉及接口

  attestKeyItem(keyAlias: string, options: HuksOptions, callback: AsyncCallback\<HuksReturnResult\>): void;
  attestKeyItem(keyAlias: string, options: HuksOptions): Promise\<HuksReturnResult\>;

- 变更前：

  只针对传入ATTESTATION_ID相关TAG的应用校验AccessToken权限，其它情况无接口权限的限制。


- 变更后：

  只有具备system权限的系统应用或者申请了ohos.permission.ACCESS_IDS权限的普通应用才能正常使用attestKeyItem接口。

**适配指导**

已经具备system权限的应用则可以正常使用attestKeyItem接口，其余普通应用需申请ohos.permission.ACCESS_IDS权限即可，申请方法参考[ACL权限配置说明](https://gitee.com/openharmony/docs/blob/master/zh-cn/application-dev/security/accesstoken-overview.md#%E8%AE%BF%E9%97%AE%E6%8E%A7%E5%88%B6%E5%88%97%E8%A1%A8acl%E8%AF%B4%E6%98%8E)。

## cl.huks.2 HUKS解决派生密钥/协商密钥的存储/导出问题

变更之前，派生密钥/协商密钥既支持存储，又支持导出，存在安全风险；

变更之后，应用在派生密钥/协商密钥时需传入HuksKeyStorageType中定义的类型。应用只能选择存储，或者选择导出。若不传入，则默认同时支持存储和导出，存在安全问题，不推荐业务使用。

**变更影响**

影响已发布的JS接口，接口行为发生变更。

**关键的接口/组件变更**

发布的JS接口不变， 传入接口的参数集合发生变更。

**适配指导**

接口使用的示例代码可参考[HUKS-guidelines](../../../application-dev/security/huks-guidelines.md)和[HUKS API](../../../application-dev/reference/apis/js-apis-huks.md)。
