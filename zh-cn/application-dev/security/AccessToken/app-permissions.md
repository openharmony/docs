# 应用权限列表

根据权限的开放范围和授权方式不同，申请对应权限的方式也不同。

系统当前存在以下权限列表，开发者可根据实际需求进行检索，并确定对应权限的申请方式。

- [开放权限（系统授权）](permissions-for-all.md)
  
   所有应用可申请。应用申请了此类权限后，系统将在用户安装应用时，自动把相应权限授予给应用。

- [开放权限（用户授权）](permissions-for-all-user.md)

   所有应用可申请。应用申请了此类权限后，还需要在应用动态运行时，通过发送弹窗的方式请求用户授权。

- [受限开放权限](restricted-permissions.md)

   面向普通应用开放的system_basic权限。

- [企业类应用可用权限](permissions-for-enterprise-apps.md)

   仅面向企业普通应用、MDM应用<!--Del-->、系统应用<!--DelEnd-->开放。分发类型（app-distribution-type）为enterprise_normal（企业普通应用）、enterprise_mdm（MDM应用）的应用可申请。应用在申请时，需确认其授权方式，按照合适的方式申请。

- [MDM应用可用权限](permissions-for-mdm-apps.md)

  仅[MDM](../../mdm/mdm-kit-intro.md)应用可申请。应用在申请时，需确认其授权方式，按照合适的方式申请。

<!--Del-->
- [系统应用可用权限](permissions-for-system-apps.md)

   此列表中的权限仅面向系统应用开放，分为三类：

   1. [可通过ACL跨级别申请的系统授权权限](permissions-for-system-apps.md)：

       应用可通过[ACL](declare-permissions-in-acl.md)的方式，跨级别申请。符合条件的应用申请了此类权限后，系统将在用户安装应用时，自动把相应权限授予给应用。
   2. [不可通过ACL跨级别申请的系统授权权限](permissions-for-system-apps-no-acl.md)：

       应用需查询权限自身的APL级别，判断是否可申请。符合条件的应用申请了此类权限后，系统将在用户安装应用时，自动把相应权限授予给应用。

   3. [可通过ACL跨级别申请的用户授权权限](permissions-for-system-apps-user.md)：

       应用可通过[ACL](declare-permissions-in-acl.md)的方式，跨级别申请。应用申请了此类权限后，还需要在应用动态运行时，通过发送弹窗的方式请求用户授权。

<!--DelEnd-->
