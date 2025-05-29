# Job Management
## Overview
### Function
A job is a set of commands in the **.cfg** file of the init module. A maximum of 4096 jobs can be added. Jobs can be configured in the [.cfg file](subsys-boot-init-cfg.md). Generally, jobs are executed during initialization to serve the normal startup of services or the initialization of specific basic functions.

### Basic Concepts
A job can be configured in the **init.cfg** file or the custom **.cfg** file of the module. The parser of the init process aggregates commands of the jobs with the same name into one job. For jobs with the same name, the init process only ensures that the commands in the **init.cfg** file are executed in preference. It does not guarantee the execution sequence of commands in other **.cfg** files.
- Basic job

  A job executed in a fixed phase during init process startup, for example, pre-init, init, or post-init.
  - pre-init: pre-initialization phase. Key services on which other services depend, such as ueventd, watchdog, and hilogd, are started in this phase. The mounting of data partitions is also done in this phase.
  - init: main phase of the initialization process. In this phase, a large number of commands are executed, and services in the **boot** group (first group) are started concurrently by the **init** group. Some important services related to system functions are also started in this phase.
  - post-init: post-initialization phase. In this phase, the **trigger** command is used to invoke the execution of other phases, which can be regarded as independent phases, or the post-init phase as a whole. In this phase, a large number of commands are executed, and the **normal** group (the second group) is started by the **init** group. Most services configured in the **.cfg** files are started in this phase.

- Custom job (for standard system or higher)

  A job triggered based on specific rules. You can add commands to the job as required and run the **trigger** command to invoke the execution of commands in the job.

- Conditional job (for standard system or higher)

  A job triggered based on specific conditions. You can add conditions to a job so that the job is executed when the conditions are met.

  A condition is a combination of system parameter values. It supports operations such as **&&** and **||** as well as matching of any parameter values by using the wildcard character (*).

  Generally, you can configure a condition in the format shown below:

  ```
  "condition" : "sys.usb.config = none && sys.usb.configfs = 0",
  ```

  If you need to enable parameter checking in the boot phase, configure the condition as follows:

  ```
  "condition" : "boot && const.debuggable=1",
  ```

  When defining commands for a job, you can add attributes in the format of **param:xxx** to form different commands.

### Constraints
With the system parameter module, the standard system is able to support basic, conditional, and custom jobs. The small system supports only basic jobs.

## How to Develop
### Use Cases
A job is a command set, where you can manage the commands to be executed. A maximum of 4096 commands can be added to a command set. During the init startup process, the execution of jobs helps ensure normal running of services.

### Parameter Description

   **Table 1** Command set description
   | Command| Format and Example| Description|
   | -------- | -------- | -------- |
   | mkdir | mkdir \<i>target folder</i> \<i>[mode]</i> \<i>[owner]</i> \<i>[group]</i><br>Example:<br/>mkdir /storage/myDirectory<br>mkdir /storage/myDirectory 0755 root root| Creates a folder. <strong>mkdir</strong> and the target folder must be separated by only one space.<br>System type: small system and standard system|
   | chmod | chmod \<i>permission</i> \<i>target</i><br>Example:<br/>chmod 0600 /storage/myFile.txt<br>chmod&nbsp;0750&nbsp;/storage/myDir | Modifies the permission, which must be in the <strong>0</strong>\<i>xxx</i> format. <strong>chmod</strong>, \<i>permission</i>, and \<i>target</i> must be separated by only one space.<br>System type: small system and standard system|
   | chown | chown \<i>uid</i> \<i>gid</i> \<i>target</i><br>Example:<br/>chown 900 800 /storage/myDir<br>chown&nbsp;100&nbsp;100&nbsp;/storage/myFile.txt | Modifies the owner group. <strong>chown</strong>, <strong>uid</strong>, <strong>gid</strong>, and \<i>target</i> must be separated by only one space.<br>System type: small system and standard system|
   | mount | mount&nbsp;fileSystemType&nbsp;src&nbsp;dst&nbsp;flags&nbsp;[data]<br>Example:<br/>mount vfat /dev/mmcblk0 /sdc rw,umask=000<br>mount&nbsp;jffs2&nbsp;/dev/mtdblock3&nbsp;/storage&nbsp;nosuid | Mounts devices. Every two parameters must be separated by only one space. For details about <strong>flags</strong>, see the <strong>mountFlagMap[]</strong> function in <strong>base/startup/init/services/init/init\_common\_cmds.c</strong>. The <strong>data</strong> field is optional.<br>System type: small system and standard system|
   | start | start&nbsp;serviceName<br>Example: start foundation| Starts services. \<i>serviceName</i> must be contained in the <strong>services</strong> array.<br>System type: small system and standard system|
   | export | export key value<br>Example:<br>export TEST /data/test| Sets environment variables. <strong>key</strong> and <strong>value</strong> respectively indicate the environment variable and its value.<br>System type: small system and standard system|
   | rm | rm filename<br>Example:<br>rm /data/testfile| Deletes a file. \<i>filename</i> indicates the absolute file path.<br>System type: small system and standard system|
   | rmdir | rmdir dirname<br>Example:<br>rmdir /data/testdir| Deletes a directory. \<i>dirname</i> indicates the absolute path of the directory.<br>System type: small system and standard system|
   | write | write filename value<br>Example:<br>write /data/testfile 0| Writes a file. <strong>filename</strong> and <strong>value</strong> respectively indicate the absolute file path and the string to write.<br>System type: small system and standard system|
   | stop | stop serviceName<br>Example:<br>stop console| Stops a service. \<i>servicenamei> indicates the name of the service to stop.<br>System type: small system and standard system|
   | copy | copy oldfile newfile<br>Example:<br>copy /data/old /data/new| Copies a file. \<i>oldfile</i> and \<i>newfile</i> respectively indicate the old and new absolute file paths.<br>System type: small system and standard system|
   | reset | reset serviceName<br>Example:<br>reset console| Resets a service. \<i>servicename</i> indicates the name of the service to reset. If the service has not been started, this command will start the service. If the service is running, the command will stop the service and then restart it.<br>System type: small system and standard system|
   | reboot | reboot [subsystem]<br>Example:<br>reboot updater| Restarts the system. <strong>subsystem</strong> is optional. If it is not specified, the device enters the current system upon restarting. If it is specified, the device enters the corresponding subsystem upon restarting. For example, if you run <strong>reboot updater</strong>, the device enters the updater subsystem upon restarting.<br>System type: small system and standard system|
   | sleep | sleep time<br>Example:<br>sleep 5| Enters the sleep mode. \<i>time</i> indicates the sleep time, which must not exceed 5 seconds.<br>To avoid impact on services, exercise caution when running this command.<br>System type: small system and standard system|
   | domainname | domainname name<br>Example:<br>domainname localdomain| Sets the domain name.<br>System type: small system and standard system|
   | hostname | hostname name<br>Example:<br>hostname localhost| Sets the host name.<br>System type: small system and standard system|
   | wait | wait filepath [time]<br>Example:<br>wait /data/testfile or wait /data/testfile 5| Waits for commands. \<i>time</i> indicates the waiting time, which must not exceed 5 seconds.<br>System type: small system and standard system|
   | setrlimit | setrlimit resource curValue maxValue<br>Example:<br>setrlimit RLIMIT_CPU 10 100| Sets resource usage restrictions.<br>System type: small system and standard system|
   | write | write path content<br>Example:<br>write /proc/sys/kernel/sysrq 0| Writes a file.<br>System type: small system and standard system|
   | exec | exec \<i>Path of the executable file</i> \<i>Parameters passed by the executable file</i><br>Example:<br>exec /system/bin/mkdir /data/test.txt| Runs an executable file. This command is called by the system.<br>System type: small system and standard system|
   | syncexec | syncexec \<i>Path of the executable file</i> \<i>Parameters passed by the executable file</i><br>Example:<br>syncexec /system/bin/udevadm trigger| Runs an executable file synchronously. The **wait** function will be called to wait for the child process to end. The command must not contain more than 10 parameters.<br>System type: standard system
   | mknode |mknode name { b \| c } Major Minor<br>Example:<br>mknode path b 0644 1 9| Creates an index node corresponding to a directory entry and a special file.<br>System type: standard system|
   | makedev | makedev major minor<br>Example:<br>makedev -v update| Creates a static device node, which is usually in the <strong>/dev</strong> directory.<br>System type: standard system|
   | symlink | symlink target link_name<br>Example:<br>symlink /proc/self/fd/0 /dev/stdin| Creates a symbolic link.<br>System type: standard system|
   | trigger | trigger jobName<br>Example:<br>trigger early-fs| Triggers a job.<br>System type: standard system|
   | insmod | insmod [-f] [options]<br>Example:<br>insmod xxx.ko| Loads a kernel module file.<br>System type: standard system|
   | setparam | setparam paramName paramValue<br>Example:<br>setparam sys.usb.config hdc| Sets system parameters.<br>System type: standard system|
   | load_persist_params | load persist params<br>Example:<br>load_persist_params | Loads <strong>persist</strong> parameters. There must be one and only one space after the <strong>load_persist_params</strong> command.<br>System type: standard system|
   | load_param | load params<br>Example:<br>load_param /data/test.normal.para| Loads the parameters from a file to the memory.<br>System type: standard system|
   | load_access_token_id | load_access_token_id | Writes the access token to the <strong>data/service/el0/access_token/nativetoken.json</strong> file. There is one and only one space after <strong>load_access_token_id</strong>.<br>System type: standard system|
   | ifup | ifup \<i>NIC</i><br>Example:<br>ifup eth0| Activates the specified NIC.<br>System type: standard system|
   | mount_fstab | mount_fstab fstab.test<br>Example:<br>mount_fstab /vendor/etc/fstab.test| Mounts partitions based on the <strong>fstab</strong> file.<br>System type: standard system|
   | umount_fstab | umount_fstab  fstab.test<br>Example:<br>umount_fstab /vendor/etc/fstab.test| Unmounts partitions based on the <strong>fstab</strong> file.<br>System type: standard system|
   | restorecon | restorecon file or dir<br>Example:<br>restorecon /file| Reloads the SELinux context.<br>System type: standard system|
   | stopAllServices | stopAllServices [bool]<br>Example:<br>stopAllServices false or stopAllServices| Stops all services. The maximum response time is 10 ms by default.<br>System type: standard system|
   | umount |umount path<br>Example:<br>umount /vendor| Unmounts a mounted device.<br>System type: standard system|
   | sync | sync | Writes data to the disk synchronously. There is only one and only one space after <strong>sync</strong>.<br>System type: standard system|
   | timer_start | timer_start serviceName<br>Example:<br>timer_start console| Starts the service timer.<br>System type: standard system|
   | timer_stop | timer_stop serviceName<br>Example:<br>timer_stop console| Stops a service timer.<br>System type: standard system|
   | init_global_key | init_global_key path<br>Example:<br>init_global_key /data| Initializes the encryption key of the data partition file.<br>System type: standard system|
   | init_main_user | init_main_user| Encrypts the main user directory.<br>System type: standard system|
   | mkswap | mkswap file<br>Example:<br>mkswap /swapfile1| Creates a swap partition on a file or device.<br>System type: standard system|
   | swapon | swapon file <br>Example:<br>swapon /swapfile1| Activates the swap space. <br>System type: standard system|
   | mksandbox | mksandbox fileName<br>Example:<br>mksandbox system| Creates a sandbox.<br>System type: standard system|
   | loadcfg | loadcfg&nbsp;filePath<br>Example:<br>loadcfg /patch/fstab.cfg| Loads other <strong>.cfg</strong> files. The maximum size of the target file (only <strong>/patch/fstab.cfg</strong> supported currently) is 50 KB. Each line in the <strong>/patch/fstab.cfg</strong> file is a command. The command types and formats must comply with their respective requirements mentioned in this table. A maximum of 20 commands are allowed.<br>System type: small system|

### Available APIs
Job management is a part of the init startup process. It is a process-based function that completely serves the init startup process. It does not provide any functional APIs for other modules. It works in a way similar to command group management and does not provide help for other types of management. The following describes the job management APIs.

**Table 2** Description of job parsing APIs
| API| Function| Supported System Type|
|:--------|:-----|:------|
|void ParseAllJobs(const cJSON *fileRoot)|Provides the general entry for parsing jobs.| Small and standard systems|
|static void ParseJob(const cJSON *jobItem, Job *resJob)|Checks whether a job exists and parses <strong>cmds</strong> in it.| Small system|
|int GetCmdLinesFromJson(const cJSON *root, CmdLines **cmdLines)| Parses <strong>cmds</strong> in the job. This API is used for the small system.<br>It does not apply to the standard system because the <strong>trigger</strong> command and <strong>condition</strong> attribute are involved.| Small and standard systems|
|int ParseTriggerConfig(const cJSON *fileRoot, <br>int (*checkJobValid)(const char *jobName))|Parses the <strong>trigger</strong> command in the job.| Standard system|
|static int ParseTrigger_(const TriggerWorkSpace *workSpace,<br>const cJSON *triggerItem, <br>int (*checkJobValid)(const char *jobName))|Obtains the job name, condition attribute, and <strong>cmds</strong> command group.<br>Jobs are stored in a hash table, and commands are stored in a queue structure.| Standard system|

**Table 3** Description of the job triggering APIs
| API| Function| Supported System Type|
|:--------|:-----|:------|
|void PostTrigger(EventType type, const char *content, uint32_t contentLen)|Verifies the validity of the job name and sends a job triggering event.| Standard system|
|static void SendTriggerEvent(int type, const char *content, uint32_t contentLen)|Performs functions such as system control and starting or stopping of services based on system parameters.| Standard system|
|static void DoTriggerCmd(const struct CmdArgs *ctx)|Executes the <strong>trigger</strong> command.| Standard system|
|void DoTriggerExec(const char *triggerName)| Finds a command group based on the job name and pushes the commands in the command group to the execution queue. <br> | Standard system|
|void DoJob(const char *jobName)|Matches a job based on the job name and invokes <strong>DoCmdByIndex</strong><br>to execute the commands in the job.| Small system|
|void DoCmdByIndex(int index, const char *cmdContent)|Combines parameters and commands.| Small and standard systems|

### Example
The following is the template for configuring <strong>jobs</strong> in the <strong>.cfg</strong> file. You can use it to verify the job management function.
```
{
    "jobs" : [{     // Basic job
            "name" : "stage1",
            "cmds" : [
                "start service1",
                "mkdir dir1"
            ]
        }, {        // Conditional job
            "name" : "param:test.name1=0",
            "condition" : "test.name1=0",
            "cmds" : [
                "chmod 0755 dir1",
                "chown root root dir1"
            ]
        }, {        // Custom job
            "name" : "param:test.name2=*",
            "condition" : "test.name2=*",
            "cmds" : [
                "chmod 0644 dir1",
                "chown system system dir1"
            ]
        }
    ]
}
```
The differences in job configuration are described as follows:

1. <strong>name</strong> and <strong>cmds</strong> are mandatory for a job, and <strong>cmds</strong> must contain commands supported by the system.

2. <strong>condition</strong> is an optional attribute of a job. It indicates that the job is triggered only when the specified condition is met; that is, the job will not be invoked in a specific phase by the code or the <strong>trigger</strong> command.

3. The job name must comply with the specified rules. For a job whose condition is a system parameter, its name is prefixed with <strong>param:</strong>.

4. Commands in a renamed job can be executed only after being triggered by the <strong>trigger</strong> command in other executable job command groups. By default, the <strong>trigger</strong> command is executed in the post-init phase.

5. An existing job name can be used in different files. Jobs with the same name are regarded as the same job. When jobs with the same name are executed, the commands in these jobs are executed together.

6. For a conditional job, a condition is usually a system parameter. You can set a specific value so that the job is triggered when the condition is met. You can also set the value to an asterisk (*) so that the job is triggered whenever the condition is met, regardless of the parameter value.

7. For the small system, the commands in a job cannot be triggered by the <strong>trigger</strong> command in the post-init phase.
