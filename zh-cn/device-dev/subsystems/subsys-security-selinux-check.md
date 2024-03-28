# OpenHarmony SELinux Check问题处理指导

## 概述

为规范OpenHarmony SELinux策略配置，针对neverallow检查无法覆盖到的场景和人工审核容易遗漏的问题，OpenHarmony提供了一套SELinux策略检查工具。


## file_contexts中data分区二级目录使用正则表达式检查

### 检查说明

data分区为可读写分区，大部分进程的数据文件和用户的文件存放在data分区，文件数量庞大，容易出现碎片化问题。为避免data分区打标签性能问题，需要限制data分区的二级目录不能存在正则表达式，该检查主要扫描`file_contexts`文件。

### 编译拦截

在`file_contexts`中，data分区二级目录使用正则表达式，会触发编译报错，关键报错信息`Regex is not allowed in the secondary directory under data`，报错如下：
```text
Regex is not allowed in the secondary directory under data, check '/data/log(/.*)?' failed in file out/rk3568/obj/base/security/selinux_adapter/file_contexts:214
 There are two solutions:
 1. Add '/data/log(/.*)?' to whitelist file 'data_regex_whitelist.txt' under 'base/security/selinux_adapter/sepolicy';
 2. Modify '/data/log(/.*)?' to remove the regular expression
```

### 拦截原因

说明以下`file_contexts`中的定义是非法的，因为`log(/.*)?`是正则表达式，且在data的第二级目录：
```text
/data/log(/.*)?                 u:object_r:data_log:s0
```

### 修复方法

主要有两种修复方式：

- 方式一：将不满足的路径`/data/log/(.*)?`添加到`//base/security/selinux_adapter/sepolicy/`下的白名单文件`data_regex_whitelist.txt`中，修改该白名单需要评估安全性和合理性，审慎修改。
- 方式二：修改data二级目录中不合理的正则表达式，以满足要求，例如，改成以下形式，则是合法的：
    ```text
    /data/log                       u:object_r:data_log:s0
    /data/log/(.*)?                 u:object_r:data_log:s0
    ```

## file_contexts中使用一级目录标签检查

### 检查说明

一级目录标签是指根路径下的子目录使用的标签，主要有：
```text
u:object_r:dev_file:s0
u:object_r:etc_file:s0
u:object_r:lib_file:s0
u:object_r:config_file:s0
u:object_r:updater_file:s0
u:object_r:system_file:s0
u:object_r:sys_prod_file:s0
u:object_r:chip_prod_file:s0
u:object_r:vendor_file:s0
u:object_r:data_file:s0
u:object_r:module_update_file:s0
```

`file_contexts`中禁止使用一级目录标签来定义路径标签，避免配置不合理的SELinux权限，对根路径的子目录产生影响，构成安全隐患。

### 编译拦截

在`file_contexts`配置中，不合理的使用一级目录标签，会触发编译报错，关键报错信息`partition label is not allow to use`，报错如下：

```
partition label is not allow to use, check '/data/log u:object_r:data_file:s0' failed in file out/rk3568/obj/base/security/selinux_adapter/file_contexts:213
 There are two solutions:
 1. Add '/data/log u:object_r:data_file:s0' to whitelist file 'partition_label_use_whitelist.txt' under 'base/security/selinux_adapter/sepolicy';
 2. Change '/data/log u:object_r:data_file:s0' to avoid using label in ['u:object_r:dev_file:s0', 'u:object_r:etc_file:s0', 'u:object_r:lib_file:s0', 'u:object_r:config_file:s0', 'u:object_r:updater_file:s0', 'u:object_r:system_file:s0', 'u:object_r:sys_prod_file:s0', 'u:object_r:chip_prod_file:s0', 'u:object_r:vendor_file:s0', 'u:object_r:data_file:s0', 'u:object_r:module_update_file:s0']
```

### 拦截原因

说明以下`file_contexts`中的定义是非法的，因为为`/data/log`配置了标签`u:object_r:data_file:s0`，该标签属于一级目录标签：
```text
/data/log   u:object_r:data_file:s0
```

### 修复方法

主要有两种修复方式：

- 方式一：将不满足的路径及标签`'/data/log   u:object_r:data_file:s0'`添加到`//base/security/selinux_adapter/sepolicy/`下的白名单文件`partition_label_use_whitelist.txt`中，修改该白名单需要评估安全性和合理性，审慎修改。
- 方式二：更改`/data/log`的不合理标签，使用自定义标签，以满足要求，例如，改成以下形式，则是合法的：
    ```text
    /data/log    u:object_r:data_log:s0
    ```

## 使用高危组合权限检查

### 检查说明

当某一对主体和客体同时拥有几个不同的SELinux权限时，可能形成一种攻击路径。此检查项主要检查user版本策略和开发者模式策略。检查项的配置文件在`base/security/selinux_adapter/scripts/selinux_check/config/perm_group.json`，形式如下：
```json
{
    "check_rules": [
        {
            "name": "execute and execute_no_trans",
            "description": "process label should transform while execute a file",
            "perm_group": [
                {
                    "tclass": "*",
                    "perm": "execute execute_no_trans"
                }
            ]
        }
    ]
}
```

其中，`check_rules`表示所有权限组合检查项列表，每一个检查项中包括`name`、`description`、`perm_group`三个字段，`name`表示检查项的名称，`description`表示检查项描述，`perm_group`表示详细的可能存在攻击路径的权限列表，其中`tclass`表示操作类型，`perm`表示该操作类型下的权限，`tclass`可以填具体操作类型，也可以填`*`，填`*`表示会检查所有包括`perm`中权限的操作类型。

### 编译拦截

不合理的权限配置，会触发编译报错，关键报错信息`check rule 'xxx' in user mode failed`，这里的`xxx`表示被拦截的检查项`name`，报错如下：
```text
        check rule 'execute and execute_no_trans' in user mode failed, process label should transform while execute a file
        violation list (scontext tcontext):
                appspawn appspawn_exec
        There are two solutions:
        1. Add the above list to whitelist file 'perm_group_whitelist.json' under 'base/security/selinux_adapter/sepolicy' in 'user' part of 'execute and execute_no_trans'
        2. Change the policy to avoid violating rule 'execute and execute_no_trans'

        check rule 'execute and execute_no_trans' in developer mode failed, process label should transform while execute a file
        violation list (scontext tcontext):
                appspawn appspawn_exec
        There are two solutions:
        3. Add the above list to whitelist file 'perm_group_whitelist.json' under 'base/security/selinux_adapter/sepolicy' in 'developer' part of 'execute and execute_no_trans'
        4. Change the policy to avoid violating rule 'execute and execute_no_trans'
```

### 拦截原因

上述报错是因为，在user策略和开发者策略中，主体`appspawn`和客体`appspawn_exec`，都同时拥有`execute`和`execute_no_trans`权限：
```text
allow appspawn appspawn_exec:file { execute execute_no_trans };
```

### 修复方法

主要有两种修复方式：

- 方式一：将不合理的主体和客体组合添加到`//base/security/selinux_adapter/sepolicy/`下的白名单文件`perm_group_whitelist.json`中，修改该白名单需要评估合理性，审慎添加，该文件如下：
    ```text
    {
        "whitelist": [
            {
                "name": "execute and execute_no_trans",
                "user": [
                    "appspawn appspawn_exec"
                ],
                "developer": [
                ]
            }
        ]
    }
    ```
    其中，`whitelist`表示所有权限组合检查项白名单列表，每一个检查项白名单中包括`name`、`user`、`developer`三个字段，`name`表示检查项白名单的名称，与检查项`name`对应，`user`表示检查项白名单中的`user`策略白名单，`developer`表示检查项白名单中的开发者策略白名单。白名单的填写位置参考下表：

    **表1** 主客体组合权限检查项白名单字段与报错对应关系

    | 违反user策略 | 违反developer策略 | 写入字段位置 |
    | -------- | -------- | -------- |
    | 是 | 是 | user |
    | 否 | 是 | developer |
    | 是 | 否 | user，且需删除当前主客体在developer字段中的白名单 |

- 方式二：修改不合理的策略，以满足要求，例如，更改方案，避免同时申请这两个权限。

### 删除冗余的白名单

当整改了不合理的权限组合配置后，删除了不合理的策略，但是未同时删除白名单时，也会触发编译报错，关键报错信息`remove the following unnecessary whitelists in rule 'xxx' part 'user'`，这里的`xxx`表示被拦截的检查项`name`，报错如下：
```text
        check rule 'execute and execute_no_trans' failed in whitelist file 'perm_group_whitelist.json'
        remove the following unnecessary whitelists in rule 'execute and execute_no_trans' part 'user':
                appspawn appspawn_exec
        check rule 'execute and execute_no_trans' failed in whitelist file 'perm_group_whitelist.json'
        remove the following unnecessary whitelists in rule 'execute and execute_no_trans' part 'developer':
                appspawn appspawn_exec
```

需要同时删除白名单，将`//base/security/selinux_adapter/sepolicy/`下的白名单文件`perm_group_whitelist.json`中的相关白名单删除，该文件如下：
```text
{
    "whitelist": [
        {
            "name": "execute and execute_no_trans",
            "user": [
                "appspawn appspawn_exec"
            ],
            "developer": [
            ]
        }
    ]
}
```
这里根据报错，要删除检查项`"execute and execute_no_trans"`下的`user`字段的白名单`"appspawn appspawn_exec"`，另外，其他冗余白名单报错的删除位置参考下表：

**表2** 主客体组合权限检查项冗余白名单字段与报错对应关系
| user白名单冗余 | developer白名单冗余 | 删除白名单字段位置 |
| -------- | -------- | -------- |
| 是 | 是 | user |
| 否 | 是 | developer |
| 是 | 否 | user |


## 篡改高危进程基线检查

### 检查说明

OpenHarmony中存在一些高危进程，例如shell、console，这些进程的SELinux策略需要有管控，避免随意删除和新增，造成系统不可用或引入安全隐患。对于这些高危进程xx，其基线策略在`//base/security/selinux_adapter/sepolicy/`下的`xx.baseline`文件中。以sh基线为例，形式如下：
```text
(allow sh vendor_file (dir (search)))

developer_only(`
(allow sh system_lib_file (dir (search)))
')
```

其中被developer_only括起来的策略，表示该策略仅作为开发者模式下的基线；否则，表示该策略是user和开发者模式共用的基线。

### 编译拦截

新增和删除高危进程策略，都会触发编译报错，关键报错信息`check 'xxx' baseline in user mode failed`，xxx表示高危进程标签，报错如下：
```text
        check 'sh' baseline in user mode failed
                expect rule: (allow sh vendor_file (dir ())); actual rule: (allow sh vendor_file (dir (search)))
        There are two solutions:
        1. Add the above actual rule to baseline file 'sh.baseline' under 'base/security/selinux_adapter/sepolicy'
        2. Change the policy to satisfy expect rule

        check 'sh' baseline in developer mode failed
                expect rule: (allow sh vendor_file (dir ())); actual rule: (allow sh vendor_file (dir (search)))
        There are two solutions:
        1. Add the above actual rule to baseline file 'sh.baseline' under 'base/security/selinux_adapter/sepolicy' and add developer_only
        2. Change the policy to satisfy expect rule
```

### 拦截原因

上述报错是因为，新增了sh的策略`"allow sh vendor_file:dir search;"`，对应的cil形式为`"(allow sh vendor_file (dir (search)))"`，同时违反了user和developer下的进程基线，期望的cil形式基线是`"(allow sh vendor_file (dir ()))"`。

### 修复方法

主要有两种修复方式：

- 方式一：将报错中`"actual rule"`字段的cil策略，作为新基线添加到`//base/security/selinux_adapter/sepolicy/`下的基线文件`xx.baseline`中，`xx`为违反基线的进程标签。修改该基线文件需要评估安全性和合理性，审慎修改。其中，基线的填写位置参考下表：

    **表3** 篡改高危进程基线检查基线更新位置与报错对应关系
    | user基线报错 | developer基线报错 | 更新基线是否需要在developer_only内 |
    | -------- | -------- | -------- |
    | 是 | 是 | 否 |
    | 否 | 是 | 是 |
    | 是 | 否 | 将developer_only内的基线挪到外部 |

- 方式二：修改不合理的策略，以满足要求，例如，更改方案，避免违反基线。

### 删除冗余的基线

当整改了不合理的基线策略后，删除了不合理的策略，但是未同时删除基线时，也会触发编译报错，关键报错信息`check 'xxx' baseline in user mode failed`，xxx表示高危进程标签，报错如下：
```
        check 'sh' baseline in user mode failed
                expect rule: (allow sh rootfs (dir (search))); actual rule: (allow sh rootfs (dir ()))
        There are two solutions:
        1. Add the above actual rule to baseline file 'sh.baseline' under 'base/security/selinux_adapter/sepolicy'
        2. Change the policy to satisfy expect rule

        check 'sh' baseline in developer mode failed
                expect rule: (allow sh rootfs (dir (search))); actual rule: (allow sh rootfs (dir ()))
        There are two solutions:
        1. Add the above actual rule to baseline file 'sh.baseline' under 'base/security/selinux_adapter/sepolicy' and add developer_only
        2. Change the policy to satisfy expect rule
```

需要同时删除基线，将`//base/security/selinux_adapter/sepolicy/`下的基线文件`sh.baseline`中的相关基线删除。

这里根据报错，要删除基线`"(allow sh rootfs (dir (search)))"`，另外，以符合`"actual rule"`，其他冗余基线报错的删除位置参考下表：

**表4** 篡改高危进程基线检查冗余基线与报错对应关系
| user基线冗余 | developer基线冗余 | 删除基线字段位置 |
| -------- | -------- | -------- |
| 是 | 是 | developer_only外 |
| 否 | 是 | developer_only内 |
| 是 | 否 | developer_only外 |

## ioctl的权限策略检查

### 检查说明

涉及配置ioctl相关的SELinux策略时，除了配置allow规则以外，还需要根据avc日志对ioctl的ioctlcmd进行限制，否则会导致所有的ioctlcmd权限都被开放，不满足权限最小化原则。

### 编译拦截

配置的 allow 规则访问权限包含了 ioctl，但未限定 ioctl 权限参数时，会触发编译报错，关键报错信息`check ioctl rule in user mode failed.`，报错如下：
```text
 check ioctl rule in user mode failed.
 violation list (allow scontext tcontext:tclass ioctl)
    allow wifi_host data_service_el1_file:file ioctl;
    allow wifi_host dev_hdfwifi:chr_file ioctl;
    allow write_updater updater_block_file:blk_file ioctl;
 please add "allowxperm" rule based on the above list.
```

### 拦截原因

仅添加`allow scontext tcontext:tclass ioctl`规则会导致主体有对tcontext:tclass所有ioctl的权限，权限过大被编译拦截，需添加具体的allowxperm对ioctl权限精细化管控，达到权限最小化。

### 修复方法

主要有两种修复方式：
- 方式一：根据avc日志对ioctl的ioctlcmd进行限制。例如，有下面的avc日志：
    ```text
    #avc:  denied  { ioctl } for  pid=1 comm="init" path="/data/app/el1/bundle/public" dev="mmcblk0p11" ino=652804 ioctlcmd=0x6613 scontext=u:r:init:s0 tcontext=u:object_r:data_app_el1_file:s0 tclass=dir permissive=0
    ```
    根据该avc日志配置了允许ioctl的SELinux策略：
    ```text
    allow init data_app_el1_file:dir { ioctl };
    ```
    同时，还需要根据avc日志中的`ioctlcmd=0x6613`字段，在相同user或开发者模式基线下添加allowxperm，进一步限制ioctl的开放范围：
    ```text
    allowxperm init data_app_el1_file:dir ioctl { 0x6613 };
    ```
    
- 方式二：将拦截日志中的 "scontext tcontext tclass" 字符添加到`//base/security/selinux_adapter/sepolicy/`下白名单 `ioctl_xperm_whitelist.json` 中，修改该白名单需要评估合理性。
    拦截日志中 `user mode` 表示该策略是user和开发者模式共用的基线，另外 `developer mode` 则表示该策略仅作为开发者模式下的基线，相应添加到白名单列表中。
    ```text
    {
        "whitelist": {
            "user": [
                "wifi_host data_service_el1_file file"
            ],
            "developer": [
            ]
        }
    }
    ```


## permissive 主体类型的权限检查

### 检查说明

增加 permissive 的主体类型，会放开其访问所有客体的权限，不满足权限最小化原则。

### 编译拦截

在策略文件中增加 `permissive scontext;` 后，会触发编译报错，关键报错信息 `check permissive rule in user mode failed.`，报错如下：
```text
 check permissive rule in user mode failed.
 violation list (scontext):
    sa_subsys_dfx_service
 There are two solutions:
    1. Add the above list to whitelist file 'permissive_whitelist.json' under 'base/security/selinux_adapter/sepolicy' in 'user' mode.
    2. Change the policy to avoid violating rule.
```

### 拦截原因

规则中存在新增的 permissive 主体类型。

### 修复方法

主要有两种修复方式：
- 方式一：删除不必要的 permissive 定义。
- 方式二：添加主体类型scontext到 `//base/security/selinux_adapter/sepolicy/` 下白名单 `permissive_whitelist.json` 中，修改该白名单需要评估合理性。
    拦截日志中 `user mode` 表示该策略是user和开发者模式共用的基线，另外 `developer mode` 则表示该策略仅作为开发者模式下的基线，相应添加到白名单文件。
    ```text
    {
        "whitelist": {
            "user": [
                "sa_subsys_dfx_service"
            ],
            "developer": [
            ]
        }
    }
    ```