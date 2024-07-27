# 安全子系统变更说明

## cl.security_guard.1 securityGuard接口权限变更

**访问级别**

系统接口。

**变更原因**

根据权限命名规范，变更获取风险详细数据的权限，重新定义新权限的同时，删除旧权限。

**变更影响**

该变更为非兼容性变更，接口权限变更后，接口仍能编译成功，但是接口原本的功能无法正常使用，调用接口会抛出201错误码。

**起始API Level**

12

**变更发生的版本**

从OpenHarmony 5.0.0.36开始。

**变更的接口**

| 接口声明 | 变更前 | 变更后 |
| ------- | ----- | ------ |
| reportSecurityEvent(securityEvent: SecurityEvent): void | 需要ohos.permission.securityguard.REPORT_SECURITY_INFO权限 | 需要ohos.permission.REPORT_SECURITY_EVENT权限 |
| querySecurityEvent(rules: Array&lt;SecurityEventRule&gt;, querier: Querier): void | 需要ohos.permission.securityguard.REQUEST_SECURITY_EVENT_INFO权限 | 需要ohos.permission.QUERY_SECURITY_EVENT权限 |
| startSecurityEventCollector(rule: CollectorRule): void | 需要ohos.permission.securityguard.REQUEST_SECURITY_EVENT_INFO权限 | 需要ohos.permission.QUERY_SECURITY_EVENT权限 |
| stopSecurityEventCollector(rule: CollectorRule): void | 需要ohos.permission.securityguard.REQUEST_SECURITY_EVENT_INFO权限 | 需要ohos.permission.QUERY_SECURITY_EVENT权限 |
| getModelResult(rule: ModelRule): Promise&lt;ModelResult&gt; | 需要ohos.permission.securityguard.REQUEST_SECURITY_MODEL_RESULT权限 | 需要ohos.permission.QUERY_SECURITY_MODEL_RESULT权限 |
| on(type: 'securityEventOccur', securityEventInfo: SecurityEventInfo, callback: Callback&lt;SecurityEvent&gt;): void | 需要ohos.permission.securityguard.REQUEST_SECURITY_EVENT_INFO权限 | 需要ohos.permission.QUERY_SECURITY_EVENT权限 |
| off(type: 'securityEventOccur', securityEventInfo: SecurityEventInfo, callback?: Callback&lt;SecurityEvent&gt;): void | 需要ohos.permission.securityguard.REQUEST_SECURITY_EVENT_INFO权限 | 需要ohos.permission.QUERY_SECURITY_EVENT权限 |

**适配指导**

业务申请并配置如下权限，仅用于迁移场景使用：<br>
ohos.permission.REPORT_SECURITY_EVENT<br>
ohos.permission.QUERY_SECURITY_EVENT<br>
ohos.permission.QUERY_SECURITY_MODEL_RESULT