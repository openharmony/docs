# Access Token Manager

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--Designer: @linshuqing; @hehehe-li-->
<!--Tester: @leiyuqian-->
<!--Adviser: @zengyawen-->
<!-- md-trans-meta sourceCommit=2845f22b3a6c7c573421bce7ff3e32f73246613d translatedAt=2026-07-20T10:51:34.900Z pushedAt=2026-07-21T07:51:44.679Z -->

Access Token Manager (atm) is a tool used to query and set the information such as permission and usage type of an application process. It provides the capability of access control based on the token ID, bundle name, and process name.

## Environment Setup
Before using this tool, you must obtain [hdc](../dfx/hdc.md) and run the **hdc shell** command.

## Commands

| Command               | Description|
| ------------------- | -----------|
| help                | Displays the commands supported by the atm tool.|
| perm                | Grants or revokes a permission for an application process, or resets the user_grant permission status. Starting from API version 26.0.0, <!--Del-->on non‑root devices, <!--DelEnd-->this command <!--Del-->only <!--DelEnd-->supports these operations for debug‑signed applications.|
| <!--DelRow-->toggle | Sets or obtains the toggle status of the permission dialog box or permission usage records. This command is available only for the root version.|
| dump                | Obtains access control data.|

## help

```bash
# Displays the help information.
atm help
```


## perm
```bash
atm perm [-h] [-g -i <token-id> -p <permission-name>] [-c -i <token-id> -p <permission-name>] [-r -i <token-id>] [-r -b <bundle-name>]
```

In the commands listed in the following table, -g, -c, and -r are mandatory parameters and can be used only independently. For the **atm perm -g** and **atm perm -c** commands, the **-i** and **-p** parameters are mandatory. For the **atm perm -r** command, the **-i** and **-b** parameters can be used only separately, and the **-p** parameter is not supported. The **-b** parameter can be used only together with the **-r** parameter.

**Parameters**
| Parameter                                              | Description                 | 
| -------------------------------------------------- | ---------------------- | 
| -h                                        | Displays help information. Commands supported by the **atm perm** command.|
| -g&nbsp;-i \<token-id\>&nbsp;-p \<permission-name\> | Grants a specified permission to an application based on the token ID of the application process. The **-g**, **-i**, and **-p** parameters are mandatory. The return value indicates whether the operation is successful.   | 
| -c&nbsp;-i \<token-id\>&nbsp;-p \<permission-name\> | Revokes a specified permission from an application based on the token ID of the application process. The **-c**, **-i**, and **-p** parameters are mandatory. The return value indicates whether the operation is successful.   | 
| -r&nbsp;-i \<token-id\> | Resets the user_grant permission status based on the token ID of the application process. The **-r** and **-i** parameters are mandatory. The return value indicates whether the operation is successful.<br>**Note**: This parameter is supported since API version 26.0.0.|
| -r&nbsp;-b \<bundle-name\> | Resets the user_grant permission status via the bundle name of the application process (for all applications sharing the same bundle name). **-r** and **-b** are both mandatory. The return value indicates whether the operation is successful.<br>**Note**: This parameter is supported since API version 26.0.0.|

Example:

```bash
# Display the help information about the atm perm command.
atm perm -h

# Grant the camera permission to an application process.
atm perm -g -i ********* -p ohos.permission.CAMERA

# Revoke the camera permission for an application process.
atm perm -c -i ********* -p ohos.permission.CAMERA

# Resets the user_grant permission status of a specified application process.
atm perm -r -i *********

# Resets the user_grant permission status of a application process in the specified bundle.
atm perm -r -b com.ohos.bundlename
```


<!--Del-->

## toggle

```bash
atm toggle [-h] [-r -s -i <user-id> -p <permission-name> -k <status>] [-r -o -i <user-id> -p <permission-name>]
```
**Parameters**

| Parameter                                                          | Description                               | 
| ----------------------------------------------------------------- | ----------------------------------- | 
| -h                                                     | Displays help information.             | 
| -r&nbsp;-s&nbsp;-i \<user-id\>&nbsp;-p \<permission-name\>&nbsp;-k \<status\> | Sets the toggle status (specified by status) of a specified permission of a specified user. The **-r**, **-s**, **-i**, **-p** and **-k** parameters are mandatory. The return value indicates whether the operation is successful.| 
| -r&nbsp;-o&nbsp;-i \<user-id\>&nbsp;-p \<permission-name\> | Obtains the toggle status of a specified permission for a specified user. The **-r**, **-o**, **-i**, and **-p** parameters are mandatory.| 

Example:

```bash
# Display the help information about the atm toggle command.
atm toggle -h

# Enable the camera permission for user 0.
atm toggle -r -s -i 0 -p ohos.permission.CAMERA -k 1

# Obtain the toggle state of the camera permission for user 0.
atm toggle -r -o -i 0 -p ohos.permission.CAMERA
```

## toggle

```bash
atm toggle [-h] [-u -s -i <user-id> -k <status>] [-u -o -i <user-id>]
```
**Parameters**

| Parameter                                                          | Description                               | 
| ----------------------------------------------------------------- | ----------------------------------- | 
| -h                                                     | Displays help information.             | 
| -u&nbsp;-s&nbsp;-i \<user-id\>&nbsp;-k \<status\> | Sets the toggle status (specified by **status**) of the permission usage records. The **-u**, **-s**, **-i** and **-k** parameters are mandatory. The return value indicates whether the operation is successful.| 
| -u&nbsp;-o&nbsp;-i \<user-id\>&nbsp; | Obtains the toggle status of the permission usage records for a specified user. The **-u**, **-o**, and **-i** parameters are mandatory.| 

Example:

```bash
# Display the help information about the atm toggle command.
atm toggle -h

# Enable the toggle status of the permission usage records for user 0.
atm toggle -u -s -i 0 -k 1

# Obtain the toggle status of the permission usage records of user 0.
atm toggle -u -o -i 0
```

<!--DelEnd-->


## dump

<!--RP1-->
```bash
atm dump [-h] [-d [-p <permission-name>]] [-t [-i <token-id>] [-b <bundle-name>] [-n <process-name>] [-p <permission-name>]] [-r [-i <token-id>] [-p <permission-name>]] [-v [-i <token-id>] [-p <permission-name>]]
```
<!--RP1End-->

In the following table, **-d**<!--Del-->, **-r**, **-v**,<!--DelEnd--> and **-t** are mandatory, and **-i**, **-b**, **-n**, and **-p** are optional. <!--Del-->For the **atm dump -r** and **atm dump -v** commands, the **-i** and **-p** parameters can be used together. <!--DelEnd-->For the **atm dump -t** command, the **-i**, **-b**, **-n**, and **-p** parameters can be used only separately.

| Parameter                                         | Description                                                | 
| ----------------------------------------------- | ---------------------------------------------------- | 
| -h                                     | Displays help information.                             | 
| -d                                     | Queries all permission definitions in the system. This parameter is mandatory.                              | 
| -d&nbsp;-p \<permission-name\>              | Queries the permission definition based on the permission name. This parameter is optional.                             | 
| -t                                     | Queries token IDs of all processes in the system. This parameter is mandatory.                            | 
| -t&nbsp;-i \<token-id\>                     | Queries basic process information and the corresponding [GrantStatus](../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#grantstatus) based on the token ID of a process. This parameter is optional.            | 
| -t&nbsp;-b \<bundle-name\>                  |  Queries the basic information about an application and the corresponding [GrantStatus](../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#grantstatus) based on the bundle name of the application process. This parameter is optional.    | 
| -t&nbsp;-n \<process-name\>                 |  Queries basic process information and the corresponding [GrantStatus](../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#grantstatus) based on the process name. This parameter is optional. |
| -t&nbsp;-p \<permission-name\>                 |  Queries the token ID of the application process that applies for a specified permission. This parameter is optional.<br>**Note**: This parameter is supported since API version 26.0.0. |
| <!--DelRow-->-r                        |  Queries all [PermissionUsedResponse](../reference/apis-ability-kit/js-apis-privacyManager-sys.md#permissionusedresponse) records in the system. This parameter is mandatory.                          | 
| <!--DelRow-->-r&nbsp;-i \<token-id\>        | Queries the [PermissionUsedResponse](../reference/apis-ability-kit/js-apis-privacyManager-sys.md#permissionusedresponse) records of an application based on the token ID of the application process. This parameter is optional.       | 
| <!--DelRow-->-r&nbsp;-p \<permission-name\> | Queries the [PermissionUsedResponse](../reference/apis-ability-kit/js-apis-privacyManager-sys.md#permissionusedresponse) records based on the permission name. This parameter is optional.                       |
| <!--DelRow-->-v                                     | Queries the permission usage types of all application processes in the system. This parameter is mandatory.                   | 
| <!--DelRow-->-v&nbsp;-i \<token-id\>                     | Queries the permission usage type of an application based on the token ID of the application process. This parameter is optional.        | 
| <!--DelRow-->-v&nbsp;-p \<permission-name\>              | Queries the usage types of a permission based on the specified permission name. This parameter is optional.                       | 

Example:

```bash
#Query all permission definitions in the system.
atm dump -d

#Query the permission definition by permission name.
atm dump -d -p *********
# Command output:
# {
#     "permissionName": "ohos.permission.KERNEL_ATM_SELF_USE",
#     "grantMode": "SYSTEM_GRANT",
#     "availableLevel": "SYSTEM_CORE",
#     "availableType": "SYSTEM",
#     "distributedSceneEnable": true,
#     "isKernelEffect": true,
#     "hasValue": true,
# }

#Display the help information about the atm dump command.
atm dump -h

#Query the token IDs of all processes in the system.
atm dump -t

#Query the permission information based on the token ID.
atm dump -t -i *********
# Command output:
# {
#   "tokenId": 672078897,
#   "processName": "samgr",
#   "apl": 2,
#   "permStateList": [
#     {
#       "permissionName": "ohos.permission.DISTRIBUTED_DATASYNC",
#       "grantStatus": 0,
#       "grantFlag": 4,
#     }
#   ]
# }

#Query the permission information based on the bundle name.
atm dump -t -b ohos.telephony.resources
# Command output:
# {
#   "tokenId": 537280686,
#   "tokenAttr": 1,
#   "ver": 1,
#   "userId": 100,
#   "bundleName": "ohos.telephony.resources",
#   "instIndex": 0,
#   "dlpType": 0,
#   "isRemote": false,
#   "isPermDialogForbidden": false,
#   "permStateList": [
#     {
#       "permissionName": "ohos.permission.DISTRIBUTED_DATASYNC",
#       "grantStatus": 0,
#       "grantFlag": 4,
#     }
#   ]
# }

#Query the token IDs and bundle names of all application processes that apply for a specified permission.
atm dump -t -p ohos.permission.CAMERA
# Command output:
# Permission: ohos.permission.CAMERA
# Total Tokens: 1

# 537538306: com.ohos.camera


#Query the permission information based on the process name.
atm dump -t -n *********
```

<!--Del-->
```bash
#Query the permission types of all applications.
atm dump -v
#Command output:
# {
#   "tokenId": 537088946,
#   "permissionName": "ohos.permission.GET_INSTALLED_BUNDLE_LIST",
#   "usedType": 0,
# }

#Query the permission usage types based on the token ID.
atm dump -v -i *********

#Query the permission usage types based on the permission name.
atm dump -v -p ohos.permission.CAMERA

#Query the permission usage types based on the token ID and permission name.
atm dump -v -i ********* -p ohos.permission.CAMERA

#Query all permission usage records in the system.
atm dump -r
# Command output:
# {
#   "beginTime": 1501837281916,
#   "endTime": 1501837281916,
#   "bundleRecords": [
#     {
#       "tokenId": 537088946,
#       "isRemote": false,
#       "bundleName": "com.ohos.permissionmanager",
#       "permissionRecords": [
#         {
#           "permissionName": "ohos.permission.GET_INSTALLED_BUNDLE_LIST",
#           "accessCount": 1,
#           "secAccessCount": 0,
#           "rejectCount": 0,
#           "lastAccessTime": 1501837281916,
#           "lastRejectTime": 0,
#           "lastAccessDuration": 0,
#           "accessRecords": [
#             {
#               "status": 1,
#               "lockScreenStatus": 1,
#               "timestamp": 1501837281916,
#               "duration": 0,
#               "count": 1,
#               "usedType": 0
#             },
#           ]
#           "rejectRecords": [
#           ]
#         },
#       ]
#     }
#   ]
# }

#Query the permission usage records based on the token ID.
atm dump -r -i *********

#Query the permission usage records based on the permission name.
atm dump -r -p ohos.permission.CAMERA

#Query the permission usage records based on the token ID and permission name.
atm dump -r -i ********* -p ohos.permission.CAMERA
```
<!--DelEnd-->