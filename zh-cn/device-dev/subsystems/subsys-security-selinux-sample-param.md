# OpenHarmony SELinux新增参数策略配置方法

## 适用场景

新增系统参数，期望使用SELinux进行访问管控，对参数配置独立SELinux标签，参数定义参考[系统参数规范](subsys-boot-init-sysparam.md)。

## 配置指导

参数和参数标签的对应关系是在parameter_contexts文件内，参数名以"."结尾表示通配参数，否则表示固定参数。

通配参数标签映射方法，表示以`'init.svc.'`开头的参数的标签都是`u:object_r:init_svc_param:s0`：
```text
init.svc. u:object_r:init_svc_param:s0
```
固定参数标签映射方法，表示参数`'const.secure'`的标签是`u:object_r:secure_param:s0`：
```text
const.secure u:object_r:secure_param:s0
```

当使用通配参数标签映射方法时，按最合适的前缀进行匹配，如parameter_contexts同时存在标签映射：
```text
init. u:object_r:init_param:s0
init.svc. u:object_r:init_svc_param:s0
```
那么：
- 参数`init.a`的标签是`u:object_r:init_param:s0`。
- 参数`init.svc`的标签是`u:object_r:init_param:s0`。
- 参数`init.svc.a`的标签是`u:object_r:init_svc_param:s0`。


以新增前缀为init.svc.的参数标签init_svc_param为例，流程如下：

1. 在parameter_contexts文件内，新增映射关系。
    ```text
    init.svc. u:object_r:init_svc_param:s0
    ```

2. 在type.te中定义对应的init_svc_param，使对应的标签合法。
    ```text
    type init_svc_param, parameter_attr;
    ```
