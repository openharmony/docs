# acm工具

<!--Kit: Basic Services Kit-->
<!--Subsystem: Account-->
<!--Owner: @steven-q-->
<!--Designer: @JiDong-CS1-->
<!--Tester: @zhaimengchao-->
<!--Adviser: @zengyawen-->

Account Manager（账号管理工具，简称acm）是实现账号创建、删除、查询等功能的工具，acm为开发者提供基本的管理本地账号的能力，例如：创建账号、删除账号等。

> **说明：**
>
> 在使用本工具前，开发者需要先获取[hdc工具](../dfx/hdc.md)，执行hdc shell。


**acm工具命令列表**

| 命令 | 描述 |
| -------- | -------- |
| help | 帮助命令，用于显示acm支持的命令信息。 |
| create | 创建命令，用于创建账号。注：需要root之后才能使用该命令。 |
| delete | 删除命令，用于删除账号。注：需要root之后才能使用该命令。 |
| dump | 查询命令，用于查询账号的相关信息。注：需要root之后才能使用该命令。 |
| switch | 切换命令，用于切换账号。注：需要root之后才能使用该命令。 |
| deactivate | 注销命令，用于注销账号。注：需要root之后才能使用该命令。 |
| set | 设置约束命令，用于设置账号的约束。注：需要root之后才能使用该命令。 |


## help

**使用方法：**

```bash
acm help
```

**显示信息**

显示acm相关的帮助信息。


## create

**使用方法：**

```bash
# 显示帮助命令
acm create -h
# 创建一个指定名字与类型的账号
acm create -n <accountName> -t <accountType> [-s <shortName>] [-d <disallowed-pre-install-hap-bundles>] [-p <allowed-pre-install-hap-bundles>]
```

**显示信息**

当账号创建成功时，显示"create the local account successfully."；当创建失败时，显示相应的失败信息。

**创建命令参数列表**

| 参数                                | 描述                       |
| ----------------------------------- | -------------------------- |
| -h | 可选参数。显示create支持的命令信息。 |
| -n | 必选参数。指定新账号的名字。 |
| -t | 必选参数。指定新账号的账号类型。账号类型分为admin（管理员账号）、normal（普通账号）、guest（访客账号）、private（隐私账号）。 |
| -s | 可选参数。指定新账号的短名。 |
| -d | 可选参数。指定新账号被禁止的预置应用列表。 |
| -p | 可选参数。指定新账号被允许的预置应用列表。 |


## delete

**使用方法：**

```bash
# 显示帮助命令
acm delete -h
# 删除指定id的账号
acm delete -i <accountId>
```

**显示信息**

当删除账号成功时，显示"delete the local account successfully."；当删除失败时，显示相应的失败信息。

**删除命令参数列表**

| 参数                                | 描述                       |
| ----------------------------------- | -------------------------- |
| -h | 可选参数。显示delete支持的命令信息。 |
| -i | 必选参数。指定将要删除的账号id。 |


## dump

**使用方法：**

```bash
# 显示帮助命令
acm dump -h
# 查询所有账号的信息
acm dump -a
# 查询指定账号id的账号信息
acm dump -i <accountId>
```

**显示信息**

当查询成功时，显示相应的账号信息；当查询失败时，显示相应的失败信息。

**查询命令参数列表**

| 参数                                | 描述                       |
| ----------------------------------- | -------------------------- |
| -h | 可选参数。显示dump支持的命令信息。 |
| -a | 必选参数。表示查询所有账号的账号信息。 |
| -i | 必选参数。指定账号id，用于查询相应id的账号信息。 |


## switch

**使用方法：**

```bash
# 显示帮助命令
acm switch -h
# 切换到指定id的账号
acm switch -i <accountId> [-d <displayId>]
```

**显示信息**

当切换账号成功时，显示"switch the local account successfully."；当切换失败时，显示相应的失败信息。

**切换命令参数列表**

| 参数                                | 描述                       |
| ----------------------------------- | -------------------------- |
| -h | 可选参数。显示switch支持的命令信息。 |
| -i | 必选参数。指定要切换到的账号的账号id。 |
| -d | 可选参数。指定要切换到的目标屏幕ID（displayId）。 |


## deactivate

**使用方法：**

```bash
# 显示帮助命令
acm deactivate -h
# 注销所有账号
acm deactivate -a
# 注销指定账号id的账号
acm deactivate -i <accountId>
```

**显示信息**

当注销账号成功时，显示"deactivate the local account successfully."；当注销失败时，显示相应的失败信息。

**注销命令参数列表**

| 参数                                | 描述                       |
| ----------------------------------- | -------------------------- |
| -h | 可选参数。显示deactivate支持的命令信息。 |
| -a | 必选参数。表示注销所有账号。 |
| -i | 必选参数。指定账号id，用于注销相应id的账号。 |


## set

**使用方法：**

```bash
# 显示帮助命令
acm set -h
# 设置指定id的账号的约束
acm set -i <accountId> -c <constraints> [-e]
```

**显示信息**

当约束设置成功时，显示"set constraints for the local account successfully."；当设置失败时，显示相应的失败信息。

**设置约束命令参数列表**

| 参数                                | 描述                       |
| ----------------------------------- | -------------------------- |
| -h | 可选参数。显示set支持的命令信息。 |
| -i | 必选参数。指定账号id。 |
| -c | 必选参数。指定要设置的约束集合，集合中每个约束用','分隔。查看约束的详细信息请查询[账号约束列表](../reference/apis-basic-services-kit/js-apis-osAccount.md#系统账号约束列表)。 |
| -e | 可选参数。(加上/不加上)该选项表示(添加/删除)约束。 |
