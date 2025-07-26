# OpenHarmony SELinux支持MCS

## MCS背景介绍

Multi-Category Security(MCS)是SELinux强制访问控制的一种模式，通过类别(Category)划分资源访问权限，确保进程仅能访问与其类别相匹配的资源。

## MCS开关配置
当前MCS默认为开启状态，需要关闭MCS时，可在selinux_adapter部件里配置selinux_adapter_mcs_enable=false。

## MCS安全级别配置

  为应用进程和应用数据目录添加MCS配置，需要保证MCS开关开启。

  然后在`sehap_contexts`配置文件中按需配置levelFrom和user，如果未配置user，默认为user=u。示例如下：
  ```text
  apl=normal debuggable=true domain=debug_hap type=debug_hap_data_file levelFrom=all user=o
  ```

  配置user时，如果user未定义，需要先在users策略文件里定义。示例如下：
  ```text
  user o roles { r } level s0 range s0 - s0:c0.x1279;
  ```

  也可以在`product_config`配置文件中，配置默认levelFrom和user，如果未配置user，默认为user=u。示例如下：

  ```text
  defaultLevelFrom=user
  defaultUser=o
  ```

  配置levelFrom时，安全级别可选配置如下：

 | levelFrom | 释义 | level级别 |
 | -------- | ---- | ------------- |
 | app | 根据appId确认级别。 | "s0:x%u,x%u,x%u", appId & 0xff, 256 + (appId>>8 & 0xff), 512 + (appId>>16 & 0xff)|
 | user | 根据userId确认级别。 | "s0:x%u,x%u", 768 + (userId & 0xff), 1024 + (userId>>8 & 0xff) |
 | all | 根据进程appId和userId确认级别。 | "s0:x%u,x%u,x%u,x%u,x%u", appId & 0xff, 256 + (appId>>8 & 0xff), 512 + (appId>>16 & 0xff), 768 + (userId & 0xff), 1024 + (userId>>8 & 0xff) |

## MCS生效验证

开启MCS并配置安全级别后，使用命令`ps -efZ`查询MCS配置状况。示例如下：
```text
o:r:normal_hap:s0:x55,x334,x512,x868,x1024
```

进入应用数据目录，使用命令`ls -lZ`查询应用数据目录MCS配置状况。示例如下：
```text
o:object_r:normal_hap_data_file:s0:x55,x334,x512,x868,x1024
```