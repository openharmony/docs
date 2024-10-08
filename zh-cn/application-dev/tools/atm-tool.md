# atm工具

Access Token Manager (程序访问控制管理工具，简称atm工具)，是用于查询<!--Del-->或设置<!--DelEnd-->应用进程的权限、使用类型等信息的工具，为开发者提供了根据tokenid、包名、进程名等信息进行访问控制管理的能力。

> **说明：**
>
> 在使用本工具前，开发者需要先获取[hdc工具](../dfx/hdc.md)，执行hdc shell。

atm工具命令列表如下表所示。

| 命令                | 描述 |
| ------------------- | -----------|
| help                | 帮助命令，显示atm支持的命令信息。 |
| <!--DelRow-->perm   | 权限命令，为应用进程授予或取消权限。 |
| <!--DelRow-->toggle | 弹窗开关状态命令，设置或获取权限的弹窗开关状态。 |
| dump                | 查询命令，用于查询访问控制相关数据信息。 |

## 帮助命令
```bash
atm help
```


| 命令     | 描述                      | 返回信息 |
| -------- | ------------------------ | ------|
| atm help | 显示atm工具支持的命令信息。 | atm工具支持的命令集合。 |

示例：

```bash
# 显示帮助信息
atm help
```


<!--Del-->

## 权限命令
```bash
atm perm [-h] [-g -i <token-id> -p <permission-name>] [-c -i <token-id> -p <permission-name>]
```

下表中所列命令的字段均为必选字段。
| 命令                                               | 描述                    | 返回信息 |
| -------------------------------------------------- | ---------------------- | --------|
| atm perm -h                                        | 显示atm perm支持的命令。 | atm perm支持的命令集合。 |
| atm perm -g -i \<token-id\> -p \<permission-name\> | 为应用进程授权。         | 操作是否成功。 |
| atm perm -c -i \<token-id\> -p \<permission-name\> | 为应用进程取消授权。     | 操作是否成功。 |

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
atm toggle [-h] [-s -u <user-id> -p <permission-name> -k <status>] [-o -u <user-id> -p <permission-name>]
```
下表中所列命令的字段均为必选字段。
| 命令                                                              | 描述                                | 返回信息 |
| ----------------------------------------------------------------- | ----------------------------------- | -------|
| atm toggle -h                                                     | 显示atm toggle支持的命令。              | atm toggle支持的命令集合。 |
| atm toggle -s -u \<user-id\> -p \<permission-name\> -k \<status\> | 在指定用户下，设置指定权限的弹窗开关状态为status。 | 操作是否成功。 |
| atm toggle -o -u \<user-id\> -p \<permission-name\>               | 在指定用户下，获取指定权限的弹窗开关状态。 | 弹窗状态为开或关。 |

示例：

```bash
# 显示atm toggle的帮助信息
atm toggle -h

# 设置用户0下相机权限的弹窗开关状态为开启
atm toggle -s -u 0 -p ohos.permission.CAMERA -k 1

# 获取用户0下相机权限的弹窗开关状态
atm toggle -o -u 0 -p ohos.permission.CAMERA
```

<!--DelEnd-->


## 查询命令

<!--RP1-->
```bash
atm dump [-h] [-t [-i <token-id>] [-b <bundle-name>] [-n <process-name>]] [-r [-i <token-id>] [-p <permission-name>]] [-v [-i <token-id>] [-p <permission-name>]]
```
<!--RP1End-->

下表所列命令中，-i,-b,-n,-p为可选字段。对<!--Del-->atm dump -r和<!--DelEnd-->atm dump -v命令，-i和-p字段可以组合使用；对atm dump -t命令，-i,-b,-n命令只能单独使用。

| 命令                                            | 描述                                                  | 返回信息 |
| ----------------------------------------------- | ---------------------------------------------------- | -----|
| atm dump -h                                     | 显示atm dump支持的命令。                              | atm dump支持的命令集合。 |
| atm dump -t                                     | 查询系统中所有应用进程信息。                             | 所有应用的tokenid和包名。 |
| atm dump -t -i \<token-id\>                     | 通过应用进程的tokenid，查询该应用的权限信息。             | 该应用的信息，及应用的权限信息列表。 |
| atm dump -t -b \<bundle-name\>                  | 通过应用进程的包名bundle-name，查询该应用的权限信息。     | 该应用的信息，及应用的权限信息列表。 |
| atm dump -t -n \<process-name\>                 | 通过应用进程的进程名process-name，查询该应用的权限信息。  | 该应用的信息，及应用的权限信息列表。 |
| <!--DelRow-->atm dump -r                        | 查询系统内的所有权限使用记录。                           | 所有应用的信息及各自的权限使用记录列表。 |
| <!--DelRow-->atm dump -r -i \<token-id\>        | 通过应用进程的tokenid，查询该应用的权限使用记录。        | 该应用信息及权限使用记录列表。 |
| <!--DelRow-->atm dump -r -p \<permission-name\> | 通过权限名，查询该权限的使用记录。                        | 该权限的使用记录列表。 |
| atm dump -v                                     | 查询系统中所有应用进程的权限使用类型。                    | 所有应用及各自的权限的使用类型。 |
| atm dump -v -i \<token-id\>                     | 通过应用进程的tokenid，查询该应用的权限使用类型。         | 该应用的权限使用类型。 |
| atm dump -v -p \<permission-name\>              | 通过权限名，查询该权限的使用类型。                        | 该权限在所有应用下的使用类型。 |

示例：

```bash
#显示atm dump的帮助信息
atm dump -h

#查询系统中所有应用进程的tokenid和包名
atm dump -t

#按tokenid查询权限信息
atm dump -t -i *********

#按包名查询权限信息
atm dump -t -b ohos.telephony.resources

#按进程名查询权限信息
atm dump -t -n *********

#查询所有应用的权限使用类型
atm dump -v

#按应用tokenid查询权限使用类型
atm dump -v -i *********

#按权限名查询权限使用类型
atm dump -v -p ohos.permission.CAMERA

#按应用tokenid和权限名查询权限使用类型
atm dump -v -i ********* -p ohos.permission.CAMERA
```

<!--Del-->
```bash
#查询系统内的所有权限使用记录
atm dump -r

#按应用tokenid查询权限使用记录
atm dump -r -i *********

#按权限名查询权限使用记录
atm dump -r -p ohos.permission.CAMERA

#按应用tokenid和权限名查询权限使用记录
atm dump -r -i ********* -p ohos.permission.CAMERA
```
<!--DelEnd-->