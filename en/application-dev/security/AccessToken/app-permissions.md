# Application Permissions

The way to request permissions varies, depending on the scope of the permissions and the authorization mode.

The system provides the following permissions. You can determine the appropriate way to apply for the permissions based on actual situation.

- [Open system_grant permissions](permissions-for-all.md)
  
   The permissions are available to all applications and granted by the system. After an application requests this type of permissions, the system automatically grants the permissions to the application when the application is installed.

- [Open user_grant permissions](permissions-for-all-user.md)

   The permissions are available to all applications and granted by the user. After an application requests this type of permissions, the permissions must be authorized by the user in a dialog box during the running of the application.

- [Permissions for enterprise applications](permissions-for-enterprise-apps.md)

   The permissions are available only to normal enterprise applications, mobile device management (MDM) applications<!--Del-->, and system applications<!--DelEnd-->. The applications with the distribution type (**app-distribution-type**) of **enterprise_normal** (normal enterprise application) or **enterprise_mdm** (MDM application) can request this type of permissions. When requesting such a permission, you need to determine the authorization mode first.

- [Permissions for MDM applications](permissions-for-mdm-apps.md)

  The permissions are available only to [MDM](../../mdm/mdm-kit-intro.md) applications. When requesting such a permission, you need to determine the authorization mode first.

<!--Del-->
- [Permissions for system applications](permissions-for-system-apps.md)

   The permissions are available only to system applications and system services. The permissions can be classified into the following types:

   1. system_grant permissions that can be requested via the Access Control List (ACL):

       The permissions can be requested via the [ACL](declare-permissions-in-acl.md) and are authorized by the system. The ACL allows a system application or system service to have permissions beyond its Ability Privilege Level (APL). When the application is installed, the system automatically grants the requested permissions to the application.
   2. system_grant permissions that cannot be requested via the ACL:

       You need to quey the application's APL and determine whether the application can request the permissions. When the application is installed, the system automatically grants the requested permissions to the application.

   3. user_grant permissions that can be requested via the ACL:

       The permissions can be requested via the [ACL](declare-permissions-in-acl.md) and must be authorized by the user. After an application requests this type of permissions via the ACL, the permissions must be authorized by the user in a dialog box during the running of the application.

<!--DelEnd-->
