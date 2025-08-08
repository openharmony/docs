# Application Permissions

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--SE: @linshuqing; @hehehe-li-->
<!--TSE: @leiyuqian-->

The way to request permissions varies, depending on its applicable scope and authorization mode. Determine the appropriate way to request permissions based on actual situation.

The system provides the following permissions: 

- [Open system_grant permissions](permissions-for-all.md)
  
   The permissions are available to all applications and granted by the system. The permissions requested by an application are automatically granted when the application is installed.

- [Open user_grant permissions](permissions-for-all-user.md)

   The permissions are available to all applications and granted by the user. The permissions requested by an application must be authorized by the user in a dialog box during the running of the application.

- [Restricted permissions](restricted-permissions.md)

   Restricted permissions are system_basic permission that can be granted to normal applications.

- [Permissions for enterprise applications](permissions-for-enterprise-apps.md)

   The permissions are available only to normal enterprise applications, mobile device management (MDM) applications<!--Del-->, and system applications<!--DelEnd-->. The applications with the distribution type (**app-distribution-type**) of **enterprise_normal** (normal enterprise application) or **enterprise_mdm** (MDM application) can request this type of permissions. When requesting such a permission, you need to determine the authorization mode first.

- [Permissions for MDM applications](permissions-for-mdm-apps.md)

  The permissions are available only to [MDM](../../mdm/mdm-kit-intro.md) applications. When requesting such a permission, you need to determine the authorization mode first.

<!--Del-->
- [Permissions for system applications](permissions-for-system-apps.md)

   The permissions for system applications are classified into the following types:

   1. [system_grant permissions available to system applications via ACL](permissions-for-system-apps.md):

       The permissions can be requested via [ACL](declare-permissions-in-acl.md). The ACL allows a system application or system service to have permissions beyond its Ability Privilege Level (APL). The requested permissions will be automatically granted when the application is installed.
   2. [system_grant non-ACL permissions for system applications](permissions-for-system-apps-no-acl.md):

       The permissions cannot be requested via ACL. You need to quey the application's APL and determine whether the application can request the permissions. The requested permissions will be automatically granted when the application is installed.

   3. [user_grant permissions available to system applications via ACL](permissions-for-system-apps-user.md):

       The permissions can be requested via [ACL](declare-permissions-in-acl.md). The ACL allows a system application or system service to have permissions beyond its APL. The permissions requested by an application must be authorized by the user in a dialog box during the running of the application.

<!--DelEnd-->
