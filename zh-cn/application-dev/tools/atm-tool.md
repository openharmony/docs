# atm工具

<!--Kit: Ability Kit-->
<!--Subsystem: Security-->
<!--Owner: @xia-bubai-->
<!--Designer: @linshuqing; @hehehe-li-->
<!--Tester: @leiyuqian-->
<!--Adviser: @zengyawen-->

Access Token Manager (程序访问控制管理工具，简称atm工具)，是用于查询<!--Del-->或设置<!--DelEnd-->应用进程的权限、使用类型等信息的工具，为开发者提供了根据tokenid、包名、进程名等信息进行访问控制管理的能力。

## 环境说明
在使用本工具前，开发者需要先获取[hdc工具](../dfx/hdc.md)，执行hdc shell。

## atm工具命令列表

| 命令                | 描述 |
| ------------------- | -----------|
| help                | 帮助命令，显示atm支持的命令信息。 |
| <!--DelRow-->perm   | 权限命令，为应用进程授予或取消权限。 |
| <!--DelRow-->toggle | 弹窗开关/权限使用记录开关状态命令，设置或获取权限弹窗/权限使用记录开关状态。 此命令仅在root版本下可用。|
| dump                | 查询命令，用于查询访问控制相关数据信息。 |

## 帮助命令

```bash
# 显示帮助信息
atm help
```


<!--Del-->

## 权限命令
```bash
atm perm [-h] [-g -i <token-id> -p <permission-name>] [-c -i <token-id> -p <permission-name>]
```

**权限命令参数列表**
| 参数                                               | 参数说明                  | 
| -------------------------------------------------- | ---------------------- | 
| -h                                        | 帮助信息。 | atm perm支持的命令集合。 |
| -g&nbsp;-i \<token-id\>&nbsp;-p \<permission-name\> | -g、-i、-p均为必选参数，通过应用进程的tokenid授予指定权限。返回是否成功。    | 
| -c&nbsp;-i \<token-id\>&nbsp;-p \<permission-name\> | -c、-i、-p均为必选参数，通过应用进程的tokenid取消指定权限。返回是否成功。    | 

示例：

```bash
# 显示atm perm的帮助信息
atm perm -h

# 为应用进程授予相机权限
atm perm -g -i ********* -p ohos.permission.CAMERA

# 为应用进程取消相机权限
atm perm -c -i ********* -p ohos.permission.CAMERA
```


## 弹窗开关状态命令

```bash
atm toggle [-h] [-r -s -i <user-id> -p <permission-name> -k <status>] [-r -o -i <user-id> -p <permission-name>]
```
**弹窗开关状态命令参数列表**

| 参数                                                           | 参数说明                                | 
| ----------------------------------------------------------------- | ----------------------------------- | 
| -h                                                     | 帮助信息。              | 
| -r&nbsp;-s&nbsp;-i \<user-id\>&nbsp;-p \<permission-name\>&nbsp;-k \<status\> | -r、-s、-i、-p、-k均为必选参数，在指定用户下，设置指定权限的弹窗开关状态为status。返回是否成功。 | 
| -r&nbsp;-o&nbsp;-i \<user-id\>&nbsp;-p \<permission-name\> | -r、-o、-i、-p均为必选参数，在指定用户下，返回指定权限的弹窗开关状态。 | 

示例：

```bash
# 显示atm toggle的帮助信息
atm toggle -h

# 设置用户0下相机权限的弹窗开关状态为开启
atm toggle -r -s -i 0 -p ohos.permission.CAMERA -k 1

# 获取用户0下相机权限的弹窗开关状态
atm toggle -r -o -i 0 -p ohos.permission.CAMERA
```

## 权限使用记录开关状态命令

```bash
atm toggle [-h] [-u -s -i <user-id> -k <status>] [-u -o -i <user-id>]
```
**权限使用记录开关状态命令参数列表**

| 参数                                                           | 参数说明                                | 
| ----------------------------------------------------------------- | ----------------------------------- | 
| -h                                                     | 帮助信息。              | 
| -u&nbsp;-s&nbsp;-i \<user-id\>&nbsp;-k \<status\> | -u、-s、-i、-k均为必选参数，在指定用户下，设置权限使用记录开关状态为status。返回是否成功。 | 
| -u&nbsp;-o&nbsp;-i \<user-id\>&nbsp; | -u、-o、-i均为必选参数，在指定用户下，返回权限使用记录开关状态。 | 

示例：

```bash
# 显示atm toggle的帮助信息
atm toggle -h

# 设置用户0下权限使用记录开关状态为开启
atm toggle -u -s -i 0 -k 1

# 获取用户0下权限使用记录开关状态
atm toggle -u -o -i 0
```

<!--DelEnd-->


## 查询命令

<!--RP1-->
```bash
atm dump [-h] [-t [-i <token-id>] [-b <bundle-name>] [-n <process-name>]] [-r [-i <token-id>] [-p <permission-name>]] [-v [-i <token-id>] [-p <permission-name>]]
```
<!--RP1End-->

下表所列命令中，-t<!--Del-->、-r、-v<!--DelEnd-->为必选参数，-i、-b、-n、-p为可选参数。<!--Del-->对atm dump -r和atm dump -v命令，-i和-p参数可以组合使用；<!--DelEnd-->对atm dump -t命令，-i、-b、-n参数只能单独使用。

| 参数                                          | 参数说明                                                 | 
| ----------------------------------------------- | ---------------------------------------------------- | 
| -d                                     | 必选参数，查询系统中所有的权限定义。                               | 
| -d&nbsp;-p \<permission-name\>              | 可选参数，通过权限名，查询权限定义。                              | 
| -h                                     | 帮助信息。                              | 
| -t                                     | 必选参数，查询系统中所有应用进程信息。                             | 
| -t&nbsp;-i \<token-id\>                     | 可选参数，通过应用进程的tokenid，查询该应用的基本信息以及对应的[权限信息](../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#grantstatus)。             | 
| -t&nbsp;-b \<bundle-name\>                  |  可选参数，通过应用进程的包名bundle-name，查询该应用的基本信息以及对应的[权限信息](../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#grantstatus)。     | 
| -t&nbsp;-n \<process-name\>                 |  可选参数，通过应用进程的进程名process-name，查询该应用的基本信息以及对应的[权限信息](../reference/apis-ability-kit/js-apis-abilityAccessCtrl.md#grantstatus)。  |
| <!--DelRow-->-r                        |  必选参数，查询系统内的所有[权限使用记录](../reference/apis-ability-kit/js-apis-privacyManager-sys.md#permissionusedresponse)。                           | 
| <!--DelRow-->-r&nbsp;-i \<token-id\>        | 可选参数，通过应用进程的tokenid，查询该应用的[权限使用记录](../reference/apis-ability-kit/js-apis-privacyManager-sys.md#permissionusedresponse)。        | 
| <!--DelRow-->-r&nbsp;-p \<permission-name\> | 可选参数，通过权限名，查询该权限的[使用记录](../reference/apis-ability-kit/js-apis-privacyManager-sys.md#permissionusedresponse)。                        |
| <!--DelRow-->-v                                     | 必选参数，查询系统中所有应用进程的权限使用类型。                    | 
| <!--DelRow-->-v&nbsp;-i \<token-id\>                     | 可选参数，通过应用进程的tokenid，查询该应用的权限使用类型。         | 
| <!--DelRow-->-v&nbsp;-p \<permission-name\>              | 可选参数，通过权限名，查询该权限的使用类型。                        | 

示例：

```bash
#查询系统中所有的权限定义
atm dump -d

#按权限名查询权限定义
atm dump -d -p *********
# 执行结果
# {
#     "permissionName": "ohos.permission.KERNEL_ATM_SELF_USE",
#     "grantMode": "SYSTEM_GRANT",
#     "availableLevel": "SYSTEM_CORE",
#     "availableType": "SYSTEM",
#     "distributedSceneEnable": true,
#     "isKernelEffect": true,
#     "hasValue": true,
# }

#显示atm dump的帮助信息
atm dump -h

#查询系统中所有应用进程的tokenid和包名
atm dump -t

#按tokenid查询权限信息
atm dump -t -i *********
# 执行结果
# {
#   "tokenID": 672078897,
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

#按包名查询权限信息
atm dump -t -b ohos.telephony.resources
# 执行结果
# {
#   "tokenID": 537280686,
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

#按进程名查询权限信息
atm dump -t -n *********
```

<!--Del-->
```bash
#查询所有应用的权限使用类型
atm dump -v
#执行结果
# {
#   "tokenId": 537088946,
#   "permissionName": "ohos.permission.GET_INSTALLED_BUNDLE_LIST",
#   "usedType": 0,
# }

#按应用tokenid查询权限使用类型
atm dump -v -i *********

#按权限名查询权限使用类型
atm dump -v -p ohos.permission.CAMERA

#按应用tokenid和权限名查询权限使用类型
atm dump -v -i ********* -p ohos.permission.CAMERA

#查询系统内的所有权限使用记录
atm dump -r
# 执行结果
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

#按应用tokenid查询权限使用记录
atm dump -r -i *********

#按权限名查询权限使用记录
atm dump -r -p ohos.permission.CAMERA

#按应用tokenid和权限名查询权限使用记录
atm dump -r -i ********* -p ohos.permission.CAMERA
```
<!--DelEnd-->