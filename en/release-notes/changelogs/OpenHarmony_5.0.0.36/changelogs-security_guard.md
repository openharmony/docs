# Security Subsystem Changelog

## cl.security_guard.1 securityGuard Permission Change

**Access Level**

System API

**Reason for Change**

Redefined the permissions for obtaining detailed security data according to the permission naming specifications, and deleted old permissions.

**Change Impact**

This change is a non-compatible change. After the permission change, the compilation is successful, but the original functionality of the APIs cannot work. When the related API is called, error 201 is thrown.

**Start API Level**

12

**Change Since**

OpenHarmony 5.0.0.36

**Key API/Component Changes**

| API| Permission Before the Change| Permission After the Change|
| ------- | ----- | ------ |
| reportSecurityEvent(securityEvent: SecurityEvent): void | ohos.permission.securityguard.REPORT_SECURITY_INFO| ohos.permission.REPORT_SECURITY_EVENT|
| querySecurityEvent(rules: Array&lt;SecurityEventRule&gt;, querier: Querier): void | ohos.permission.securityguard.REQUEST_SECURITY_EVENT_INFO| ohos.permission.QUERY_SECURITY_EVENT|
| startSecurityEventCollector(rule: CollectorRule): void | ohos.permission.securityguard.REQUEST_SECURITY_EVENT_INFO| ohos.permission.QUERY_SECURITY_EVENT|
| stopSecurityEventCollector(rule: CollectorRule): void | ohos.permission.securityguard.REQUEST_SECURITY_EVENT_INFO| ohos.permission.QUERY_SECURITY_EVENT|
| getModelResult(rule: ModelRule): Promise&lt;ModelResult&gt; | ohos.permission.securityguard.REQUEST_SECURITY_MODEL_RESULT| ohos.permission.QUERY_SECURITY_MODEL_RESULT|
| on(type: 'securityEventOccur', securityEventInfo: SecurityEventInfo, callback: Callback&lt;SecurityEvent&gt;): void | ohos.permission.securityguard.REQUEST_SECURITY_EVENT_INFO| ohos.permission.QUERY_SECURITY_EVENT|
| off(type: 'securityEventOccur', securityEventInfo: SecurityEventInfo, callback?: Callback&lt;SecurityEvent&gt;): void | ohos.permission.securityguard.REQUEST_SECURITY_EVENT_INFO| ohos.permission.QUERY_SECURITY_EVENT|

**Adaptation Guide**

In migration scenarios only, request and configure the following permissions:<br>
ohos.permission.REPORT_SECURITY_EVENT<br>
ohos.permission.QUERY_SECURITY_EVENT<br>
ohos.permission.QUERY_SECURITY_MODEL_RESULT
