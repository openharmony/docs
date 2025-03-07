# OpenHarmony SELinux Check

## Introduction

OpenHarmony provides a set of SELinux policy checks to complement the cases that may not be covered by the **neverallow** check and manual review.


## Checking for Regular Expressions in Secondary Directories of /data in file_contexts 

### When to Use

In the **/data** partition, there are a large number of application files and user files. Frequent access to these files may cause fragmentation. However, labelling the files may comprise system performance. To solve this problem, the secondary directories under **/data** cannot contain regular expressions. The check scans the **file_contexts** file to check for regular expressions.

### Error Information

The error "Regex is not allowed in the secondary directory under data" will be reported during the compilation if any regular expression is found in the secondary directories of **/data** in **file_contexts**. The error information is as follows:
```text
Regex is not allowed in the secondary directory under data, check '/data/log(/.*)?' failed in file out/rk3568/obj/base/security/selinux_adapter/file_contexts:214
 There are two solutions:
 1. Add '/data/log(/.*)?' to whitelist file 'data_regex_whitelist.txt' under 'base/security/selinux_adapter/sepolicy';
 2. Modify '/data/log(/.*)?' to remove the regular expression
```

### Block Reason

The regular expression **log(/.*)?** is detected in the secondary directory of **/data**.
```text
/data/log(/.*)?                 u:object_r:data_log:s0
```

### Solution

You can use either of the following methods to solve the problem:

- Method 1: Add **/data/log/(.*)** to the **data_regex_whitelist.txt** file in the **//base/security/selinux_adapter/sepolicy/** directory.<br>

    > **NOTE**<br>Before modifying the file, carefully review the modification to avoid security risks.

- Method 2: Modify the regular expression. For example, modify the regular expression as follows:
    ```text
    /data/log                       u:object_r:data_log:s0
    /data/log/(.*)?                 u:object_r:data_log:s0
    ```

## Checking for Partition Labels in file_contexts

### When to Use

Partition labels are labels of the first-level directory under the root directory. Partition labels include the following:
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

Avoid using partition labels for paths in **file_contexts**, which may pose security risks on subdirectories in the root directory.

### Error Information

The error "partition label is not allow to use" will be reported during the compilation if improper use of partition labels is found in **file_contexts**. The error information is as follows:

```
partition label is not allow to use, check '/data/log u:object_r:data_file:s0' failed in file out/rk3568/obj/base/security/selinux_adapter/file_contexts:213
 There are two solutions:
 1. Add '/data/log u:object_r:data_file:s0' to whitelist file 'partition_label_use_whitelist.txt' under 'base/security/selinux_adapter/sepolicy';
 2. Change '/data/log u:object_r:data_file:s0' to avoid using label in ['u:object_r:dev_file:s0', 'u:object_r:etc_file:s0', 'u:object_r:lib_file:s0', 'u:object_r:config_file:s0', 'u:object_r:updater_file:s0', 'u:object_r:system_file:s0', 'u:object_r:sys_prod_file:s0', 'u:object_r:chip_prod_file:s0', 'u:object_r:vendor_file:s0', 'u:object_r:data_file:s0', 'u:object_r:module_update_file:s0']
```

### Block Reason

The partition label **u:object_r:data_file:s0** is configured for **/data/log**.
```text
/data/log   u:object_r:data_file:s0
```

### Solution

You can use either of the following methods to solve the problem:

- Method 1: Add the path and label **/data/log u:object_r:data_file:s0** to the **partition_label_use_whitelist.txt** file in the **//base/security/selinux_adapter/sepolicy/** directory.

    > **NOTE**<br>Before modifying the file, carefully review the modification to avoid security risks.

- Method 2: Modify the label of **/data/log**. For example, modify the label as follows:
    ```text
    /data/log    u:object_r:data_log:s0
    ```

## Checking for High-Risk Permission Groups

### When to Use

When a pair of subject and object have different SELinux permissions, an attack path may be formed. This check is used to check user version policies and developer mode policies. The check items are configured in the **base/security/selinux_adapter/scripts/selinux_check/config/perm_group.json** file.
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

**check_rules** specifies all the check items. Each check item contains the following fields:

- **name**: name of the check item.
- **description**: description of the check item.
- **perm_group**: list of permissions to check. **perm_group** consists of **tclass** and **perm**. **tclass** specifies the type of the object to access. If it is set to **\***, it indicates all types. **perm** specifies the permission of the operation.

### Error Information

The error "check rule 'xxx' in user mode failed" will be reported during the compilation if incorrect permission configuration is found. 'xxx' indicates the name of the check item. The error information is as follows:
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

### Block Reason

The subject **appspawn** and the object **appspawn_exec** have permissions **execute** and **execute_no_trans** in the user version and developer mode policies.
```text
allow appspawn appspawn_exec:file { execute execute_no_trans };
```

### Solution

You can use either of the following methods to solve the problem:

- Method 1: Add the subject and object to the **user** or **developer** field in the **perm_group_whitelist.json** file in **//base/security/selinux_adapter/sepolicy/**.

    > **NOTE**<br>Before modifying the file, carefully review the modification to avoid security risks.

    The following is an example of the file:

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

    **whitelist** specifies all the permission group check items that are allowed. Each item contains the following fields:

    - **name**: name of the allowed check item, that is, the name of the check item.
    - **user**: policy allowed for the user version.
    - **developer**: policy allowed for the developer mode.

    The following table provides the rules for determine where you should add the subject and object.

    **Table 1** Rules for determining the entry of the subject and object

    | Violate User Version Policy | Violate Developer Mode Policy | Entry Field                                                  |
    | --------------------------- | ----------------------------- | ------------------------------------------------------------ |
    | Yes                         | Yes                           | user                                                         |
    | No                          | Yes                           | developer                                                    |
    | Yes                         | No                            | user. In addition, delete the subject and object from the **developer** field. |

- Method 2: Modify the policy to avoid the violation.

### Deleting Redundant Policies from a Whitelist File

If the whitelist file still contains the policy that has been deleted, the error "remove the following unnecessary whitelists in rule 'xxx' part 'user'" will be reported in the compilation. 'xxx' indicates the name of the check item intercepted. The error information is as follows:
```text
        check rule 'execute and execute_no_trans' failed in whitelist file 'perm_group_whitelist.json'
        remove the following unnecessary whitelists in rule 'execute and execute_no_trans' part 'user':
                appspawn appspawn_exec
        check rule 'execute and execute_no_trans' failed in whitelist file 'perm_group_whitelist.json'
        remove the following unnecessary whitelists in rule 'execute and execute_no_trans' part 'developer':
                appspawn appspawn_exec
```

To solve the problem, you need to delete the redundant policy from the **perm_group_whitelist.json** file in **//base/security/selinux_adapter/sepolicy/**. The following is an example of the file:
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
In the **perm_group_whitelist.json** file, locate **execute and execute_no_trans**, and delete **appspawn appspawn_exec** from the **user** field.

**Table 2** Rules for deleting redundant policy from the whitelist file
| User Version Whitelist Redundant | Developer Mode Whitelist Redundant | Field to Delete |
| -------- | -------- | -------- |
| Yes | Yes | user |
| No | Yes | developer |
| Yes | No | user |


## Checking for Invalid Policy Baseline of Critical Processes

### When to Use

The SELinux policies of OpenHarmony critical processes, such as shell and console, must be protected against unauthorized deletion and addition, which may cause system unavailability or security risks. The baseline policies of the critical process *xx* are defined in the *xx***.baseline** file in **//base/security/selinux_adapter/sepolicy/**. The following is an example of the **sh** (SElinux label) baseline:
```text
(allow sh vendor_file (dir (search)))

developer_only(`
(allow sh system_lib_file (dir (search)))
')
```

The policy enclosed in **developer_only** applies to the developer mode only. Other policies apply to both the user version and the developer mode.

### Error Information

The error "check 'xxx' baseline in user mode failed" will be reported in the compilation if a policy is added or deleted for a critical process. 'xxx' indicates the SELinux label of the process. The error information is as follows:
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

### Block Reason

The policy **allow sh vendor_file:dir search;**, that is, **(allow sh vendor_file (dir (search)))** in the CIL format, is added for the shell process (labelled **sh**), which violates the process baseline for the user version and developer mode. The expected baseline in the CIL format is **(allow sh vendor_file (dir ()))**.

### Solution

You can use either of the following methods to solve the problem:

- Method 1: Add the policy (in the CLI format) indicated by **actual rule** in the error message to the baseline file *xx*.**baseline** in **//base/security/selinux_adapter/sepolicy/** as a new baseline. In the file name, *xx* indicates the process label.

    > **NOTE**<br>Before modifying the baseline file, carefully review the modification to avoid security risks.

    The following table provides the rules for modifying the policy baseline.

    **Table 3** Rules for modifying the policy baseline for critical processes

    | User Version Baseline Error | Developer Mode Baseline Error | Update Policy in developer_only |
    | -------- | -------- | -------- |
    | Yes | Yes | No |
    | No | Yes | Yes |
    | Yes | No | Move the policy out of **developer_only**. |

- Method 2: Modify the policy to avoid baseline violation.

### Deleting Redundant Policies from a Baseline File

If the baseline file still contains the policy that has been deleted, the error "check 'xx' baseline in user mode failed" will be reported in the compilation. 'xx' indicates the process label intercepted. The error information is as follows:
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

Delete the policy from the baseline file, for example, **sh.baseline** in **//base/security/selinux_adapter/sepolicy/**.

Delete the redundant policy, for example, **(allow sh rootfs (dir (search)))**, and ensure that the actual policy is the same as the expected one. The following table provides the rules for deleting redundant policies from the baseline file.

**Table 4** Rules for deleting redundant policies from the baseline file
| User Version Baseline Redundant | Developer Mode Baseline Redundant | Field to Delete |
| -------- | -------- | -------- |
| Yes | Yes | Policy outside **developer_only** |
| No | Yes | Policy in **developer_only** |
| Yes | No | Policy outside **developer_only** |

## Checking ioctl Permission Policies

### When to Use

For **ioctl**, you need to restrict **ioctlcmd** based on AVC logs in addition to configuring **allow** rules. Granting all permissions for **ioctlcmd** violates the least privilege principle.

### Error Information

The error "check ioctl rule in user mode failed." will be reported during the compilation if the **allow** rule contains the access permission to **ioctl** but the **ioctl** permissions are not restricted.
```text
 check ioctl rule in user mode failed.
 violation list (allow scontext tcontext:tclass ioctl)
    allow wifi_host data_service_el1_file:file ioctl;
    allow wifi_host dev_hdfwifi:chr_file ioctl;
    allow write_updater updater_block_file:blk_file ioctl;
 please add "allowxperm" rule based on the above list.
```

### Block Reason

The **allow scontext tcontext:tclass ioctl** rule allows all **ioctl** permissions for **tcontext:tclass**, which violates the least privilege principle. Specific **allowxperm** rules need to be added to implement fine-grained control over the **ioctl** permissions.

### Solution

You can use either of the following methods to solve the problem:
- Method 1: Restrict **ioctlcmd** of **ioctl** based on the AVC log. For example, the AVC log is as follows:
    ```text
    #avc:  denied  { ioctl } for  pid=1 comm="init" path="/data/app/el1/bundle/public" dev="mmcblk0p11" ino=652804 ioctlcmd=0x6613 scontext=u:r:init:s0 tcontext=u:object_r:data_app_el1_file:s0 tclass=dir permissive=0
    ```
    Based on the AVC log, set the SELinux policy as follows:
    ```text
    allow init data_app_el1_file:dir { ioctl };
    ```
    In addition, based on "ioctlcmd=0x6613" in the AVC log, add **allowxperm** to further restrict the **ioctl** permissions for the same user or developer mode.
    ```text
    allowxperm init data_app_el1_file:dir ioctl { 0x6613 };
    ```
    
- Method 2: Add "scontext tcontext tclass" to the **whitelist ioctl_xperm_whitelist.json** file in **//base/security/selinux_adapter/sepolicy/**.
  
    > **NOTE**<br>Before modifying the whitelist file, carefully review the modification to avoid security risks.
    
    In the AVC log, **user mode** indicates that the policy is the baseline shared by the user and developer modes, and **developer mode** indicates that the policy is used only as the baseline in developer mode and is added to the whitelist.
    
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


## Checking Permissions on the Permissive Subject Type

### When to Use

The **permissive** subject type allows access to all objects, which violates the least privilege principle.

### Error Information

The error "check permissive rule in user mode failed." will be reported during the compilation if the policy file contains "permissive scontext;".
```text
 check permissive rule in user mode failed.
 violation list (scontext):
    sa_subsys_dfx_service
 There are two solutions:
    1. Add the above list to whitelist file 'permissive_whitelist.json' under 'base/security/selinux_adapter/sepolicy' in 'user' mode.
    2. Change the policy to avoid violating rule.
```

### Block Reason

The rules contain new **permissive** subject type.

### Solution

You can use either of the following methods to solve the problem:
- Method 1: Delete unnecessary **permissive** definitions.

- Method 2: Add the subject type **scontext** to the **permissive_whitelist.json** file in **//base/security/selinux_adapter/sepolicy/**.
  
    > **NOTE**<br>Before modifying the whitelist file, carefully review the modification to avoid security risks.
    
    In the AVC log, **user mode** indicates that the policy is the baseline shared by the user and developer modes, and **developer mode** indicates that the policy is used only as the baseline in developer mode and is added to the whitelist.
    
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
