# init Configuration File
## Overview
### Function
The init configuration file is in JSON format and is used to configure commands and services required for system startup. Upon system startup, the Init process parses the init configuration file and runs the commands in it to start the corresponding services.
### Basic Concepts
1. Group configuration file: A group configuration file is named in the format of **device.xxxx.group.cfg**. It consists of three parts, **jobs**, **services**, and **groups**. It is available only for the standard system. Such a file is used to configure the jobs and services that can be executed. The partition that holds the file is determined based on the **bootgroup** attribute in cmdline. Currently, the following groups are supported:
    - ​device.boot.group: default configuration, which is used to trigger all jobs and services in the configuration file.
    - device.charge.group: charge mode, which is used to trigger only the allowed jobs and services in the configuration file.

2. Startup configuration file: **init.cfg** file, which consists of three parts, **jobs**, **services**, and **import**.
    - services (for the Linux kernel only): native services supported by the system. For details about the service configuration, see [Service Management](subsys-boot-init-service.md).
    - jobs: collection of commands to be executed. For details about jobs, see [Job Management](subsys-boot-init-jobs.md).
    - import (for the Linux kernel only). command used to import **.cfg** files. It helps reduce the size of **.cfg** files for implementing different functions.

### Constraints
Only the small system and standard system are supported.

## How to Develop
### Use Cases
Upon startup, the init process first initializes the system and then parses the configuration file. The system classifies the configuration files into three types:
1. init.cfg: default configuration file, which is defined by the init process and parsed first.
2. /system/etc/init/*.cfg: configuration file defined by each subsystem.
3. /vendor/etc/init/*.cfg: configuration file defined by vendors.

If you need to add a configuration file, define its content as you want and copy it to the corresponding directory.

### How to Develop
1. Define the configuration file.
    ```
    {
        "import" : [ ],
        "jobs" : [ ],
        "services" : [ ]
    }
    ```

2. Copy the configuration file to the corresponding directory based on the system type.

    For the standard system:
    ```
    ohos_prebuilt_etc("misc.cfg") {
        source = "//base/startup/init_lite/services/etc/misc.cfg"
        relative_install_dir = "init"
        part_name = "init"
      }
    ```
    For the small system:
    ```
    copy("init_configs") {
      sources = [ "init_liteos_a_3516dv300.cfg" ]
      outputs = [ "$root_out_dir/config/init.cfg" ]
    }
    ```

### Development Example
The following is a template for defining a **.cfg** file.
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
1. .cfg file: configuration file written in the JSON format. If the services or commands in it do not take effect, check whether the content format is correct.

2. import: command used to import **.cfg** files. The files are parsed immediately after their path is parsed.

3. example1.cfg: **.cfg** file to be imported.

4. serviceName: service name, which is user-defined.

5. /system/bin/serviceName: full path and parameters of the executable file of the current service, in array format.

6. jobName1: job name, which is user-defined.
