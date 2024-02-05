# 帐号子系统公共事件定义
帐号子系统面向应用发布如下系统公共事件，应用如需订阅系统公共事件，请参考公共事件[接口文档](../js-apis-commonEventManager.md)。

## COMMON_EVENT_USER_ADDED
表示用户已添加到系统中的公共事件的动作。

- 值： usual.event.USER_ADDED
- 订阅者所需权限： ohos.permission.MANAGE_LOCAL_ACCOUNTS

创建系统帐号将会触发事件通知服务发布该系统公共事件，事件携带系统帐号ID。

与这个公共事件相关的接口：createOsAccount、createOsAccountForDomain, 这些为系统API，具体参看[系统帐号接口文档](../js-apis-osAccount.md)。

## COMMON_EVENT_USER_REMOVED
表示用户已从系统中删除的公共事件的动作。

- 值： usual.event.USER_REMOVED
- 订阅者所需权限： ohos.permission.MANAGE_LOCAL_ACCOUNTS

删除系统帐号将会触发事件通知服务发布该系统公共事件，事件携带系统帐号ID。

与这个公共事件相关的接口：removeOsAccount, 为系统API，具体参看[系统帐号接口文档](../js-apis-osAccount.md)。

## COMMON_EVENT_DOMAIN_ACCOUNT_STATUS_CHANGED<sup>10+<sup>
表示域帐号状态发生变化。

- 值：usual.event.DOMAIN_ACCOUNT_STATUS_CHANGED
- 订阅者所需权限： ohos.permission.GET_LOCAL_ACCOUNTS

域帐号认证、删除、令牌更新、令牌失效将会触发事件通知服务发布该系统公共事件，事件携带域帐号名、域名、域帐号状态等信息。

与这个公共事件相关的接口：removeOsAccount、DomainAccountManager.auth、updateAccountToken, 这些为系统API，具体参看[系统帐号接口文档](../js-apis-osAccount.md)。

## COMMON_EVENT_USER_SWITCHED
表示用户切换正在发生的公共事件的动作。

- 值： usual.event.USER_SWITCHED
- 订阅者所需权限： ohos.permission.MANAGE_LOCAL_ACCOUNTS

切换帐号将会触发事件通知服务发布该系统公共事件，事件携带系统帐号ID。

与这个公共事件相关的接口：activateOsAccount, 为系统API，具体参看[系统帐号接口文档](../js-apis-osAccount.md)。

## COMMON_EVENT_USER_INFO_UPDATED<sup>9+<sup>
表示用户信息已更新。

- 值：usual.event.USER_INFO_UPDATED
- 订阅者所需权限：无

分布式帐号信息变更、系统帐号头像信息变更、系统帐号名称变更将会触发事件通知服务发布该系统公共事件，事件携带系统帐号ID。

与这个公共事件相关的接口：setOsAccountName、setOsAccountProfilePhoto, 这些为系统API，setOsAccountDistributedInfon为公共API，具体参看[系统帐号接口文档](../js-apis-osAccount.md)、[分布式帐号接口文档](../js-apis-distributed-account.md)。

## COMMON_EVENT_USER_UNLOCKED
表示设备重启后解锁时，当前用户的凭据加密存储已解锁的公共事件的动作。

- 值： usual.event.USER_UNLOCKED
- 订阅者所需权限： 无

切换到带有锁屏密码的用户，并且首次解锁会发出触发事件通知服务发布该系统公共事件，事件携带系统帐号ID。

与这个公共事件相关的接口：auth, 为系统API, 具体参看[系统帐号接口文档](../js-apis-osAccount.md)

## COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGIN
表示分布式帐号登录成功的动作。

- 值： common.event.DISTRIBUTED_ACCOUNT_LOGIN
- 订阅者所需权限： 无

分布式帐号登录成功时会触发事件通知服务发布该系统公共事件，事件携带系统帐号ID。

与这个公共事件相关的接口：setOsAccountDistributedInfo、updateOsAccountDistributedInfo(已废弃), 这些为公共API, setOsAccountDistributedInfoByLocalId为系统API,
具体参看[分布式帐号接口文档](../js-apis-distributed-account.md)。

## COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOUT
表示分布式帐号登出成功的动作。

- 值： common.event.DISTRIBUTED_ACCOUNT_LOGOUT
- 订阅者所需权限： 无

分布式帐号登出时会触发事件通知服务发布该系统公共事件，事件携带系统帐号ID。

与这个公共事件相关的接口：setOsAccountDistributedInfo、updateOsAccountDistributedInfo(已废弃), 这些为公共API, setOsAccountDistributedInfoByLocalId为系统API,
具体参看[分布式帐号接口文档](../js-apis-distributed-account.md)。

## COMMON_EVENT_DISTRIBUTED_ACCOUNT_TOKEN_INVALID
表示分布式帐号token令牌无效的动作。

- 值： common.event.DISTRIBUTED_ACCOUNT_TOKEN_INVALID
- 订阅者所需权限： 无

分布式帐号的token令牌无效时会触发事件通知服务发布该系统公共事件，事件携带系统帐号ID。

与这个公共事件相关的接口：setOsAccountDistributedInfo、updateOsAccountDistributedInfo(已废弃), 这些为公共API, setOsAccountDistributedInfoByLocalId为系统API, 
具体参看[分布式帐号接口文档](../js-apis-distributed-account.md)。

## COMMON_EVENT_DISTRIBUTED_ACCOUNT_LOGOFF
表示分布式帐号注销的动作。

- 值： common.event.DISTRIBUTED_ACCOUNT_LOGOFF
- 订阅者所需权限： 无

分布式帐号注销成功会时触发事件通知服务发布该系统公共事件，事件携带系统帐号ID。

与这个公共事件相关的接口：setOsAccountDistributedInfo、updateOsAccountDistributedInfo(已废弃), 这些为公共API, setOsAccountDistributedInfoByLocalId为系统API,
具体参看[分布式帐号接口文档](../js-apis-distributed-account.md)。