# 引导启动配置文件
## 概述
### 功能简介
Init配置文件基于JSON格式，用来配置系统启动时必要的命令和服务。Init在系统启动时解析配置文件，并根据配置文件执行对应的命令，启动相应的服务。
### 基本概念
1. 分组配置文件（device.xxxx.group.cfg）（标准系统支持），文件由jobs、services和groups组成。用来限制能够执行的jobs和service。根据cmdline中的bootgroup属性决定当前的分区。当前支持下列分组：
    - ​device.boot.group 系统默认配置，触发执行配置文件中的所有的job和服务。
    - device.charge.group  charge模式，限制只启动改文件中允许的job和服务。

2. 启动配置文件（init.cfg），文件由jobs、services和import组成。
    - services（linux内核支持）， 用于配置系统支持的native服务，服务具体配置参考 **[服务管理](subsys-boot-init-service.md)**。
    - jobs， 配置等待执行命令集合，jobs具体参考 **[jobs管理](subsys-boot-init-jobs.md)**。
    - import（linux内核支持），import是导入cfg文件，目的是减少cfg大小，分离不同的功能。

### 约束与限制
仅支持小型系统和标准系统。

## 开发指导
### 场景介绍
init进程启动时，首先完成系统初始化工作，然后开始解析配置文件。系统在解析配置文件时，会将配置文件分成三类：
1. init.cfg默认配置文件，由init系统定义，优先解析。
2. /system/etc/init/*.cfg各子系统定义的配置文件。
3. /vendor/etc/init/*.cfg厂商定义的配置文件。

当需要添加配置文件时，用户可以根据需要定义自己的配置文件，并拷贝到相应的目录下。

### 开发步骤
1. 定义配置文件。
    ```
    {
        "import" : [ ],
        "jobs" : [ ],
        "services" : [ ]
    }
    ```

2. 根据具体的系统拷贝配置到相应的目录。

    标准系统下：
    ```
    ohos_prebuilt_etc("misc.cfg") {
        source = "//base/startup/init/services/etc/misc.cfg"
        relative_install_dir = "init"
        part_name = "init"
      }
    ```
    小型系统下：
    ```
    copy("init_configs") {
      sources = [ "init_liteos_a_3516dv300.cfg" ]
      outputs = [ "$root_out_dir/config/init.cfg" ]
    }
    ```

### 开发实例
下述为cfg文件编写模板。
```
{
    "import" : [
            "/etc/example1.cfg",
            "/etc/example2.cfg"
    ],
    "jobs" : [{
            "name" : "jobName1",
            "cmds" : [
                "start serviceName",
                "mkdir dir1"
            ]
        }, {
            "name" : "jobName2",
            "cmds" : [
                "chmod 0755 dir1",
                "chown root root dir1"
            ]
        }
    ],
    "services" : [{
            "name" : "serviceName",
            "path" : ["/system/bin/serviceName"]
        }
    ]
}
```
1. cfg文件是严格按照JSON格式编写的，当添加服务或命令未生效时，可以优先排查添加内容的格式是否正确。

2. 对于import解析，在解析完成一个import中的cfg文件路径时，会立即解析该cfg文件。

3. example1.cfg 需要导入的cfg文件。

4. serviceName：service名称， 用户自定义。

5. /system/bin/serviceName: 当前服务的可执行文件全路径和参数， 数组形式。

6. jobName1：job名称， 用户自定义。
