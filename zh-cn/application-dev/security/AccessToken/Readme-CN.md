# 程序访问控制

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--SE: @linshuqing; @hehehe-li-->
<!--TSE: @leiyuqian-->

- [访问控制概述](access-token-overview.md)
- 应用权限管控<!--app-permission-mgmt-->
  - [应用权限管控概述](app-permission-mgmt-overview.md)
  - 申请应用权限<!--request-app-permissions-->
    - [选择申请权限的方式](determine-application-mode.md)
    - [声明权限](declare-permissions.md)
    - [向用户申请授权](request-user-authorization.md)
    - [再次向用户申请授权](request-user-authorization-second.md)
    - [向用户申请单次授权](one-time-authorization.md)
    <!--Del-->
    - [申请受限权限](declare-permissions-in-acl.md)
    <!--DelEnd-->
  - [应用权限列表](app-permissions.md)
    - [开放权限（系统授权）](permissions-for-all.md)
    - [开放权限（用户授权）](permissions-for-all-user.md)
    - [受限开放权限](restricted-permissions.md)
    <!--Del-->
    - [可使用ACL申请的系统应用可用权限（系统授权）](permissions-for-system-apps.md)
    - [不可通过ACL申请的系统应用可用权限（系统授权）](permissions-for-system-apps-no-acl.md)
    - [系统应用可用权限（用户授权）](permissions-for-system-apps-user.md)
    <!--DelEnd-->
    - [企业类应用可用权限](permissions-for-enterprise-apps.md)
    - [仅MDM应用可用权限](permissions-for-mdm-apps.md)
  - [应用权限组列表](app-permission-group-list.md)
- 使用安全控件<!--security-components-->
  - [安全控件概述](security-component-overview.md)
  - [使用粘贴控件](pastebutton.md)
  - [使用保存控件](savebutton.md)
