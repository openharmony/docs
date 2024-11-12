# atm工具

Access Token Manager (程序访问控制管理工具，简称atm工具)，是用于查询<!--Del-->或设置<!--DelEnd-->应用进程的权限、使用类型等信息的工具，为开发者提供了根据tokenid、包名、进程名等信息进行访问控制管理的能力。

## 环境说明
在使用本工具前，开发者需要先获取[hdc工具](../dfx/hdc.md)，执行hdc shell。

## atm工具命令列表

| 命令                | 描述 |
| ------------------- | -----------|
| help                | 帮助命令，显示atm支持的命令信息。 |
| <!--DelRow-->perm   | 权限命令，为应用进程授予或取消权限。 |
| <!--DelRow-->toggle | 弹窗开关状态命令，设置或获取权限的弹窗开关状态。 |
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
| -h                                        | 帮助信息 | atm perm支持的命令集合。 |
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
atm toggle [-h] [-s -u <user-id> -p <permission-name> -k <status>] [-o -u <user-id> -p <permission-name>]
```
**弹窗开关状态命令参数列表**

| 参数                                                           | 参数说明                                | 
| ----------------------------------------------------------------- | ----------------------------------- | 
| -h                                                     | 帮助信息。              | 
| -s&nbsp;-u \<user-id\>&nbsp;-p \<permission-name\>&nbsp;-k \<status\> | -c、-i、-p、-k均为必选参数，在指定用户下，设置指定权限的弹窗开关状态为status。返回是否成功。 | 
| -o&nbsp;-u \<user-id\>&nbsp;-p \<permission-name\> | -o、-u、-p均为必选参数，在指定用户下，返回指定权限的弹窗开关状态。 | 

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

下表所列命令中，-t、<!--Del-->-r、<!--DelEnd-->-v为必选参数，-i、-b、-n、-p为可选参数。对<!--Del-->atm dump -r和<!--DelEnd-->atm dump -v命令，-i和-p参数可以组合使用；对atm dump -t命令，-i、-b、-n参数只能单独使用。

| 参数                                          | 参数说明                                                 | 
| ----------------------------------------------- | ---------------------------------------------------- | 
| -h                                     | 帮助信息。                              | 
| -t                                     | 必选参数，查询系统中所有应用进程信息。                             | 
| -t&nbsp;-i \<token-id\>                     | 可选参数，通过应用进程的tokenid，查询该应用的基本信息以及对应的权限信息。             | 
| -t&nbsp;-b \<bundle-name\>                  |  可选参数，通过应用进程的包名bundle-name，查询该应用的基本信息以及对应的权限信息。     | 
| -t&nbsp;-n \<process-name\>                 |  可选参数，通过应用进程的进程名process-name，查询该应用的基本信息以及对应的权限信息。  |
| <!--DelRow-->-r                        |  必选参数，查询系统内的所有权限使用记录。                           | 
| <!--DelRow-->-r&nbsp;-i \<token-id\>        | 可选参数，通过应用进程的tokenid，查询该应用的权限使用记录。        | 
| <!--DelRow-->-r&nbsp;-p \<permission-name\> | 可选参数，通过权限名，查询该权限的使用记录。                        |
| -v                                     | 必选参数，查询系统中所有应用进程的权限使用类型。                    | 
| -v&nbsp;-i \<token-id\>                     | 可选参数，通过应用进程的tokenid，查询该应用的权限使用类型。         | 
| -v&nbsp;-p \<permission-name\>              | 可选参数，通过权限名，查询该权限的使用类型。                        | 

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