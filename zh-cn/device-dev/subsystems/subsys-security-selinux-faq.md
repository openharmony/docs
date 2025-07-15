# OpenHarmony SELinux常见问题

## neverallow编译报错处理
**现象描述**

编译SELinux时会进行neverallow检查，当配置的策略不合理时，可能出现违反neverallow规则导致编译报错。

```
neverallow check failed at obj/base/security/selinux_adapter/updater/system.cil:3887 from ../../base/security/selinux_adapter/sepolicy/base/public/domain.te:96
  (neverallow domain dev_parameters_file (file (write)))
    <root>
    allow at obj/base/security/selinux_adapter/updater/system.cil:14124
      (allow init dev_parameters_file (file (write create relabelfrom relabelto)))
```

**可能原因**

配置的策略不合理，违反neverallow，需要重新审视。

**解决方法**

当违反neverallow时，需要审视当前配置的策略合理性，尽量避免违反neverallow。确实应业务需要，必须屏蔽neverallow检查时，将违反neverallow的SELinux类型在neverallow策略中进行豁免，例如：
```text
违反的策略：allow init dev_parameters_file:file { write };
修改前：neverallow domain dev_parameters_file:file 
修改后：neverallow { domain -init } dev_parameters_file:file write;
```

## unrecognized character报错

**现象描述**

编译SELinux时会检查文件是否为unix格式，当配置的策略文件格式不正确时，可能出现编译报错。

```
' on line 3350:rity/selinux_adapter/sepolicy/base/public/domain.te:16:ERROR 'unrecognized character' at token '
allow domain init:process sigchld;
```

**可能原因**

新增的策略文件格式为dos格式。

**解决方法**

使用dos2unix命令转换编译报错中打印的文件：
```text
dos2unix ./sepolicy/base/public/domain.te
```

## unknown type报错
**现象描述**

编译SELinux时会检查SELinux类型是否定义，没定义或者定义位置错误时，会出现编译报错。
```
../../base/security/selinux_adapter/sepolicy/ohos_policy/security/access_token/vendor/access_token.te:2:ERROR 'unknown type accesstoken_data_file' at token ';' on line 10334:
allow accesstoken_service accesstoken_data_file:dir { search add_name open read write remove_name };
#line 1 "../../base/security/selinux_adapter/sepolicy/ohos_policy/security/access_token/vendor/access_token.te"
checkpolicy:  error(s) encountered while parsing configuration
```

**可能原因1 & 解决方法**

SELinux类型未定义。

排查是否有进行定义，如果未定义则需要使用type进行定义，格式如下：
```text
type init, xxx
```

**可能原因2 & 解决方法**

SELinux类型定义在当前策略编译时不可见。比如在system子目录定义某个SELinux类型，在vendor子目录使用这个SELinux类型，由于芯片相关的策略编译时遍历的策略是vendor子目录和public子目录，不会遍历system子目录，所以会出现unknown type问题。
  
排查在当前策略编译时是否不可见，将SELinux类型定义移到编译可见目录下，一般SELinux类型定义位置最好在public子目录下，且文件命名为type.te。
