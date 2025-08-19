# OpenHarmony SELinux开发说明

## 策略目录结构

OpenHarmony SELinux策略文件存放在`//base/security/selinux_adapter/sepolicy/ohos_policy`路径下，在该目录下策略按以下规范存放：
```text
├── 子系统
│   └── 部件
│       ├── public
│       │   └── type1.te
│       ├── vendor
│       │   └── type2.te
│       └── system
│           └── type3.te
```
系统相关策略存放在system目录下，芯片相关策略存放在vendor目录下，系统和芯片共用的策略存放在public目录下。

## 通用策略文件介绍

通用策略文件，是指设备开发者进行SELinux策略配置时，涉及修改的文件。

| 文件名 | 文件说明 |
| -------- | -------- |
| *.te | SELinux策略文件，用于定义类型、配置allow策略、配置neverallow策略。 |
| file_contexts | 实体文件标签映射文件，体现实体文件路径与标签的映射关系。 |
| virtfs_contexts | 虚拟文件标签映射文件，体现虚拟文件路径与标签的映射关系。 |
| sehap_contexts | 应用标签映射文件，体现应用关键信息与应用进程标签、应用数据目录标签的映射关系。 |
| parameter_contexts | 参数标签映射文件，体现参数与标签的映射关系。 |
| service_contexts | SA服务标签映射文件，体现SA服务与标签的映射关系。 |
| hdf_service_contexts | HDF服务标签映射文件，体现HDF服务与标签的映射关系。 |

## 基础策略文件介绍

基础策略文件，是指SELinux基础框架的SELinux策略文件，一般不涉及修改。

| 文件名 | 文件说明 |
| -------- | -------- |
| security_classes | class定义。 |
| initial_sids | sid定义。 |
| access_vectors | class支持的具体permission列表。 |
| glb_perm_def.spt | class和permission的全局宏定义，可用于简化策略语句。 |
| glb_never_def.spt | neverallow的全局宏定义，可用于简化策略语句。 |
| mls | 分层安全级别定义。 |
| glb_te_def.spt | te规则的全局宏定义，可用于简化策略语句。 |
| attributes | 一些通用集合，在定义策略类型时可以指定到特定的集合，则该策略类型会继承该集合的权限。 |
| glb_roles.spt | roles定义。 |
| users | users定义。 |
| initial_sid_contexts | sid的初始标签。 |
| fs_use | 各类型文件系统的默认标签。 |

## avc日志信息

当系统行为被SELinux拦截时，会在内核日志和hilog中打印相关的`avc denied`日志，格式如下：
```text
audit: type=1400 audit(1502458430.566:4): avc:  denied  { open } for  pid=1658 comm="setenforce" path="/sys/fs/selinux/enforce" dev="selinuxfs" ino=4 scontext=u:r:hdcd:s0 tcontext=u:object_r:selinuxfs:s0 tclass=file permissive=1
```

其中：
  - `open`，表示当前执行的操作权限。
  - `pid=1658`，表示主体进程`pid`为1658。
  - `comm="setenforce"`，表示主体进程名为`setenforce`。
  - `path="/sys/fs/selinux/enforce"`，表示被访问客体为`/sys/fs/selinux/enforce`。
  - `dev="selinuxfs"`，表示被访问客体属于selinuxfs这一文件系统。
  - `ino=4`，表示文件节点编号为4。
  - `scontext=u:r:hdcd:s0`，表示主体SELinux标签为`u:r:hdcd:s0`。
  - `tcontext=u:object_r:selinuxfs:s0`，表示被访问客体SELinux标签为`u:object_r:selinuxfs:s0`。
  - `tclass=file`，表示当前执行file的操作类型。
  - `permissive=1`，表示当前SELinux处于宽容模式，只告警不拦截。另外，当`permissive=0`时，表示强制模式，会告警并拦截。

开发者可以使用关键字`avc denied`来过滤日志，对于影响业务的avc告警，可以利用告警提供的信息来编写相应的SELinux策略，例如：
```text
audit: type=1400 audit(1502458430.566:4): avc:  denied  { open } for  pid=1658 comm="setenforce" path="/sys/fs/selinux/enforce" dev="selinuxfs" ino=4 scontext=u:r:hdcd:s0 tcontext=u:object_r:selinuxfs:s0 tclass=file permissive=1
```

对应TE规则为：
```text
allow hdcd selinuxfs:file open;
```

## 策略格式

SELinux策略，又称SELinux规则，通常以allow或neverallow开头，表示允许或禁止某种行为。在设备上使能SELinux时，SELinux会拦截所有未经allow规则授权的行为，配置allow规则可以放行，neverallow规则主要是拦截危险规则的配置。通常allow规则如下:
```text
allow subject object:class permissions;
```
  表示允许`subject`对`object`进行`class`中的`permissions`操作，其中：
  - `subject`表示主体，通常为进程的SELinux类型，如`init`。
  - `object`表示客体，通常为系统资源的SELinux类型，如`data_file`。
  - `class`表示要执行的操作的类型，如文件操作file、目录操作dir、套接字操作socket。
  - `permissions`表示要执行的具体操作，如对文件file的open、read、write。

同理，
```text
neverallow subject object:class permissions;
```
表示不允许`subject`对`object`进行`class`中的`permissions`操作。

## 策略宏隔离

在考虑设备开发者便利的同时，需要兼顾商用设备安全性，因此OpenHarmony SELinux提供了策略隔离宏，决定在不同版本上策略是否生效。OpenHarmony SELinux中支持对仅在root版本生效的策略做宏隔离，宏名称为`debug_only`。在用于设备开发者调试的root版本中，也就是在版本编译命令中指定`--build-variant root`时，宏开启。在用于商用发布的user版本中，也就是在版本编译命令中指定`--build-variant user`时，宏关闭。该宏的使用方法参考如下:
```text
debug_only(`
    allow ueventd init:fd use;
')
```

另外，OpenHarmony SELinux中也支持对开发者模式的策略做宏隔离，宏名称为`developer_only`，该宏默认开启。开发者模式策略是指，为便于使用user版本进行调试开发的开发者，需要开放的一些用于调试的SELinux策略。开发者模式宏的使用方法参考如下:
```text
developer_only(`
    allow sh init:fd use;
')
```

| 隔离宏 | root版本 | root版本开发者模式 | user版本 | user版本开发者模式 |
| -------- | -------- | -------- | -------- | -------- |
| 未隔离的策略 | 生效 | 生效 | 生效 | 生效 |
| debug_only隔离的策略 | 生效 |生效 | 不生效 | 不生效 |
| developer_only隔离的策略 | 不生效 | 生效 | 不生效 | 生效 |
