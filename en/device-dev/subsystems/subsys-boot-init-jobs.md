# Job Management
## Overview
### Function
A job is a set of commands in the **.cfg** file of the init module. A maximum of 4096 jobs can be added. Jobs can be configured in the [.cfg file](subsys-boot-init-cfg.md). Generally, jobs are executed during initialization to serve the normal startup of services or the initialization of specific basic functions.

### Basic Concepts
A job can be configured in the **init.cfg** file or the custom **.cfg** file of the module. The parser of the init process aggregates commands of the jobs with the same name into one job. For jobs with the same name, the init process only ensures that the commands in the **init.cfg** file are executed in preference. It does not guarantee the execution sequence of commands in other **.cfg** files.
- Common job

  A job executed in a fixed phase during init process startup, for example, pre-init, init, or post-init.
  - pre-init: pre-initialization phase. Key services on which other services depend, such as ueventd, watchdog, and hilogd, are started in this phase. The mounting of data partitions is also done in this phase.
  - init: main phase of the initialization process. In this phase, a large number of commands are executed, and services in the **boot** group (first group) are started concurrently by the **init** group. Some important services related to system functions are also started in this phase.
  - post-init: post-initialization phase. In this phase, the **trigger** command is used to invoke the execution of other phases, which can be regarded as independent phases, or the post-init phase as a whole. In this phase, a large number of commands are executed, and the **normal** group (the second group) is started by the **init** group. Most services configured in the **.cfg** files are started in this phase.

- Custom job (for standard system or higher)

  A job triggered based on specific rules. You can add commands to the job as required and run the **trigger** command to invoke the execution of commands in the job.

- Conditional job (for standard system or higher)

  A job triggered based on specific conditions. You can add conditions to a job so that the job is executed when the conditions are met.

  A condition is a combination of system parameter values and supports operations such as **&&** and **||**, for example, **"condition": "sys.usb.config = none && sys.usb.configfs = 0"**. When defining commands for a job, you can add attributes in the format of **param:xxx** to form different commands.

### Constraints
With the system parameter module, the standard system is able to support basic, conditional, and custom jobs. The small system supports only basic jobs.

## How to Develop
### Use Cases
A job is a command set, where you can manage the commands to be executed. A maximum of 4096 commands can be added to a command set. During the init startup process, the execution of jobs helps ensure normal running of services.

### Parameters

   **Table 1** Command set description
<table border="0" cellpadding="0" cellspacing="0" width="770" style="border-collapse: collapse;table-layout:fixed;width:578pt;border-spacing: 0px;font-variant-ligatures: normal; font-variant-caps: normal;orphans: 2;text-align:start;widows: 2;-webkit-text-stroke-width: 0px; text-decoration-thickness: initial;text-decoration-style: initial;text-decoration-color: initial">
            <tbody>
                <tr height="39" style="height:18.0pt">
                    <th height="24" class="xl6521952" width="140" style="height:18.0pt;width:105pt">
                        Command
                    </td>
                    <th class="xl6521952" width="215" style="border-left:none;width:161pt">
                        Format and Example
                    </td>
                    <th class="xl6521952" width="225" style="border-left:none;width:169pt">
                        Description
                    </td>
                    <th class="xl6521952" width="190" style="border-left:none;width:143pt">
                        Supported System Type
                    </td>
                </tr>
                <tr height="231" style="height:173.25pt">
                    <td height="231" class="xl6621952" width="140" style="height:173.25pt;border-top: none;width:105pt">
                        mkdir
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        mkdir <i>target folder</i> [mode] [owner] [group]<br>Example:<br>mkdir /storage/myDirectory<br>mkdir /storage/myDirectory 0755 root root
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Creates a folder. <strong>mkdir</strong> and the target folder must be separated by only one space. Folders cannot be created recursively.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="277" style="mso-height-source:userset;height:207.75pt">
                    <td height="277" class="xl6621952" width="140" style="height:207.75pt;border-top: none;width:105pt">
                        chmod
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        chmod <i>permission</i> <i>target</i><br>Example:<br>chmod 0600 /storage/myFile.txt<br>chmod 0750 /storage/myDir
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Modifies the permission, which must be in the <strong>0</strong><i>xxx</i> format. <strong>chmod</strong>, <i>permission</i>, and <i>target</i> must be separated by only one space.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="295" style="mso-height-source:userset;height:221.25pt">
                    <td height="295" class="xl6621952" width="140" style="height:221.25pt;border-top: none;width:105pt">
                        chown
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        chown <i>uid</i> <i>gid</i> <i>target</i><br>Example:<br>chown 900 800 /storage/myDir<br>chown 100 100 /storage/myFile.txt
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Modifies the owner group. <strong>chown</strong>, <i>uid</i>, <i>gid</i>, and <i>target</i> must be separated by only one space.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="355" style="mso-height-source:userset;height:266.25pt">
                    <td height="355" class="xl6621952" width="140" style="height:266.25pt;border-top: none;width:105pt">
                        mount
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        mount fileSystemType src dst flags data<br>Example:<br>mount vfat /dev/mmcblk0 /sdc rw,umask=000<br>mount jffs2 /dev/mtdblock3 /storage nosuid
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Mounts devices. Every two parameters must be separated by only one space. <br>For details about <strong>flags</strong>, see the <strong>mountFlagMap[]</strong> array of the <strong>mountFlagMap</strong> function in <strong>base/startup/init/services/init/init_common_cmds.c</strong>. The <strong>data</strong> field is optional.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="238" style="mso-height-source:userset;height:178.5pt">
                    <td height="238" class="xl6621952" width="140" style="height:178.5pt;border-top: none;width:105pt">
                        start
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        start <i>serviceName</i><br>Example:<br>start foundationstart
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Starts services. <i>serviceName</i> must be contained in the <strong>services</strong> array.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="264" style="mso-height-source:userset;height:198.0pt">
                    <td height="264" class="xl6621952" width="140" style="height:198.0pt;border-top: none;width:105pt">
                        export
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        export <i>key value</i><br>Example:<br>export TEST /data/test
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Sets environment variables. <i>key</i> and <i>value</i> respectively indicate the environment variable and its value.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        rm
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        rm <i>filename</i><br>Example:<br>rm /data/testfile
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Deletes a file. <i>filename</i> indicates the absolute file path.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        rmdir
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        rmdir <i>dirname</i><br>Example:<br>rmdir /data/testdir
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Deletes a directory. <i>dirname</i> indicates the absolute path of the directory.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="162" style="height:121.5pt">
                    <td height="162" class="xl6621952" width="140" style="height:121.5pt;border-top: none;width:105pt">
                        write
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        write filename value<br>Example:<br>write /data/testfile 0
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Writes a file. <strong>filename</strong> and <strong>value</strong> respectively indicate the absolute file path and the string to write.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        stop
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        stop <i>servicename</i><br>Example:<br>stop console
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Stops a service. <i>servicename</i> indicates the name of the service to stop.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="280" style="mso-height-source:userset;height:210.0pt">
                    <td height="280" class="xl6621952" width="140" style="height:210.0pt;border-top: none;width:105pt">
                        copy
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        copy <i>oldfile</i> <i>newfile</i><br>Example:<br>copy /data/old /data/new
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Copies a file. <i>oldfile</i> and <i>newfile</i> respectively indicate the old and new absolute file paths.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="382" style="mso-height-source:userset;height:286.5pt">
                    <td height="382" class="xl6621952" width="140" style="height:286.5pt;border-top: none;width:105pt">
                        reset
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        reset <i>servicename</i><br>Example:<br>reset console
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Resets a service. <i>servicename</i> indicates the name of the service to reset. If the service has not been started, this command will start the service. If the service is running, the command will stop the service and then restart it.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="363" style="mso-height-source:userset;height:272.25pt">
                    <td height="363" class="xl6621952" width="140" style="height:272.25pt;border-top: none;width:105pt">
                        reboot
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        reboot <i>subsystem</i><br>Example:<br>reboot updater
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Restarts the system. <i>subsystem</i> is optional. If it is not specified, the device enters the current system upon restarting. If it is specified, the device enters the corresponding subsystem upon restarting. For example, if you run <strong>reboot updater</strong>, the device enters the updater subsystem upon restarting.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        sleep
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        sleep <i>time</i><br>Example:<br>sleep 5
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Enters the sleep mode. <i>time</i> indicates the sleep time. <br>To avoid impact on services, exercise caution when running this command.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        domainname
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        domainname <i>name</i><br>Example:<br>domainname localdomain
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Sets the domain name.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        hostname
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        hostname <i>name</i><br>Example:<br>hostname localhost
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Sets the host name.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="116" style="height:87.0pt">
                    <td height="116" class="xl6621952" width="140" style="height:87.0pt;border-top: none;width:105pt">
                        wait
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        wait <i>filepath</i><br>Example:<br>wait /data/testfile or wait /data/testfile 5
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Waits for commands. The waiting time must not exceed 5 seconds.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        setrlimit
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        setrlimit resource <i>curValue</i> <i>maxValue</i><br>Example:<br>setrlimit RLIMIT_CPU 10 100
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Sets resource usage restrictions. <br>For details, see the <strong>resource[]</strong> array of the <strong>DoSetrlimit</strong> function in <strong>base/startup/init/services/init/init_common_cmds.c</strong>.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="228" style="mso-height-source:userset;height:171.0pt">
                    <td height="228" class="xl6621952" width="140" style="height:171.0pt;border-top: none;width:105pt">
                        exec
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        exec <i>Path of the executable file</i> <i>Parameters passed by the executable file</i><br>Example:<br>exec /system/bin/udevadm trigger
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Runs an executable file. The command must not contain more than 10 parameters.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="162" style="height:121.5pt">
                    <td height="162" class="xl6621952" width="140" style="height:121.5pt;border-top: none;width:105pt">
                        syncexec
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        syncexec <i>Path of the executable file</i> <i>Parameters passed by the executable file</i><br>Example:<br>syncexec /system/bin/udevadm trigger
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Runs an executable file synchronously. The **wait** function will be called to wait for the child process to end. The command must not contain more than 10 parameters.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="231" style="height:173.25pt">
                    <td height="231" class="xl6621952" width="140" style="height:173.25pt;border-top: none;width:105pt">
                        mknode
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        mknod name { b | c } <i>Major</i> <i>Minor</i><br>Example:<br>mknod path b 0644 1 9
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Creates an index node corresponding to a directory entry and a special file.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        makedev
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        makedev <i>major</i> <i>minor</i><br>Example:<br>makedev -v update
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Creates a static device node, which is usually in the <strong>/dev</strong> directory.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="231" style="height:173.25pt">
                    <td height="231" class="xl6621952" width="140" style="height:173.25pt;border-top: none;width:105pt">
                        symlink
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        symlink target <i>link_name</i><br>Example<br>symlink /proc/self/fd/0 /dev/stdin
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Creates a symbolic link.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="139" style="height:104.25pt">
                    <td height="139" class="xl6621952" width="140" style="height:104.25pt;border-top: none;width:105pt">
                        trigger
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        trigger <i>jobName</i><br>Example<br>trigger early-fs
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Triggers a job.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="116" style="height:87.0pt">
                    <td height="116" class="xl6621952" width="140" style="height:87.0pt;border-top: none;width:105pt">
                        insmod
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        insmod <ko name> [-f] [options]<br>Example<br>insmod xxx.ko
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Loads a kernel module file.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="277" style="height:207.75pt">
                    <td height="277" class="xl6621952" width="140" style="height:207.75pt;border-top: none;width:105pt">
                        setparam
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        setparam <i>paramname</i> <i>paramvalue</i><br>Example:<br>setparam sys.usb.config hdc
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Sets system parameters.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="231" style="height:173.25pt">
                    <td height="231" class="xl6621952" width="140" style="height:173.25pt;border-top: none;width:105pt">
                        load_persist_params
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        load persist params<br>Example:<br>load_persist_params&nbsp;
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Loads <strong>persist</strong> parameters. There must be one and only one space after the <strong>load_persist_params</strong> command.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="208" style="height:156.0pt">
                    <td height="208" class="xl6621952" width="140" style="height:156.0pt;border-top: none;width:105pt">
                        load_param
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        load <i>params</i><br>Example:<br>load_param /data/test.normal.para
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Loads the parameters from a file to the memory.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="278" style="mso-height-source:userset;height:208.5pt">
                    <td height="278" class="xl6621952" width="140" style="height:208.5pt;border-top: none;width:105pt">
                        load_access_token_id
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        load_access_token_id&nbsp;
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Writes the access token to the <strong>data/service/el0/access_token/nativetoken.json</strong> file. There is one and only one space after <strong>load_access_token_id</strong>.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="139" style="height:104.25pt">
                    <td height="139" class="xl6621952" width="140" style="height:104.25pt;border-top: none;width:105pt">
                        ifup
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        ifup <i>NIC</i><br>Example:<br>ifup eth0
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Activates the specified NIC.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="208" style="height:156.0pt">
                    <td height="208" class="xl6621952" width="140" style="height:156.0pt;border-top: none;width:105pt">
                        mount_fstab
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        mount_fstab fstab.test<br>Example:<br>mount_fstab /vendor/etc/fstab.test
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Mounts partitions based on the <strong>fstab</strong> file.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="208" style="height:156.0pt">
                    <td height="208" class="xl6621952" width="140" style="height:156.0pt;border-top: none;width:105pt">
                        umount_fstab
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        umount_fstab fstab.test<br>Example:<br>umount_fstab /vendor/etc/fstab.test
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Unmounts partitions based on the <strong>fstab</strong> file.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="162" style="height:121.5pt">
                    <td height="162" class="xl6621952" width="140" style="height:121.5pt;border-top: none;width:105pt">
                        restorecon
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        restorecon <i>file or dir</i><br>Example:<br>restorecon /file
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Reloads the SELinux context.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="254" style="height:190.5pt">
                    <td height="254" class="xl6621952" width="140" style="height:190.5pt;border-top: none;width:105pt">
                        stopAllServices
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        stopAllServices [bool]<br>Example:<br>stopAllServices false<br>stopAllServices
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Stops all services.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="162" style="height:121.5pt">
                    <td height="162" class="xl6621952" width="140" style="height:121.5pt;border-top: none;width:105pt">
                        umount
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        umount <i>path</i><br>Example:<br>umount /vendor
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Unmounts a mounted device.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        sync
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        sync&nbsp;
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Writes data to the disk synchronously. There is only one and only one space after <strong>sync</strong>.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        timer_start
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        timer_start <i>serviceName</i><br>Example:<br>timer_start console
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Starts the service timer.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="185" style="height:138.75pt">
                    <td height="185" class="xl6621952" width="140" style="height:138.75pt;border-top: none;width:105pt">
                        timer_stop
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        timer_stop <i>serviceName</i><br>Example:<br>timer_stop console
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Stops the service timer.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="162" style="height:121.5pt">
                    <td height="162" class="xl6621952" width="140" style="height:121.5pt;border-top: none;width:105pt">
                        init_global_key
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        init_global_key <i>path</i><br>Example:<br>init_global_key /data
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Initializes the encryption key of the data partition file.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="70" style="height:52.5pt">
                    <td height="70" class="xl6621952" width="140" style="height:52.5pt;border-top:none; width:105pt">
                        init_main_user
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        init_main_user
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Encrypts the main user directory.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="162" style="height:121.5pt">
                    <td height="162" class="xl6621952" width="140" style="height:121.5pt;border-top: none;width:105pt">
                        mkswap
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        mkswap <i>file</i><br>Example:<br>mkswap /swapfile1
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Creates a swap partition on a file or device.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="162" style="height:121.5pt">
                    <td height="162" class="xl6621952" width="140" style="height:121.5pt;border-top: none;width:105pt">
                        swapon
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        swapon <i>file</i><br>Example:<br>swapon /swapfile1
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Activates the swap space. 
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="162" style="height:121.5pt">
                    <td height="162" class="xl6621952" width="140" style="height:121.5pt;border-top: none;width:105pt">
                        mksandbox
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        mksandbox <i>fileName</i><br>Example:<br>mksandbox system
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Creates a sandbox.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Standard system
                    </td>
                </tr>
                <tr height="384" style="mso-height-source:userset;height:288.0pt">
                    <td height="384" class="xl6621952" width="140" style="height:288.0pt;border-top: none;width:105pt">
                        loadcfg
                    </td>
                    <td class="xl6621952" width="215" style="border-top:none;border-left:none; width:161pt">
                        loadcfg <i>filePath</i><br>Example:<br>loadcfg /patch/fstab.cfg
                    </td>
                    <td class="xl6621952" width="225" style="border-top:none;border-left:none; width:169pt">
                        Loads other <strong>.cfg</strong> files. The maximum size of the target file (only <strong>/patch/fstab.cfg</strong> supported currently) is 50 KB. Each line in the <strong>/patch/fstab.cfg</strong> file is a command. The command types and formats must comply with their respective requirements mentioned in this table. A maximum of 20 commands are allowed.
                    </td>
                    <td class="xl6621952" width="190" style="border-top:none;border-left:none; width:143pt">
                        Small system
                    </td>
                </tr><!--[endif]-->
            </tbody>
    </table>

### Available APIs
Job management is a part of the init startup process. It is a process-based function that completely serves the init startup process. It does not provide any functional APIs for other modules. It works in a way similar to command group management and does not provide help for other types of management. The following describes the job management APIs.

**Table 2** Description of job parsing APIs
<table border="0" cellpadding="0" cellspacing="0" width="968" style="border-collapse: collapse;table-layout:fixed;width:727pt;orphans: 2;widows: 2;-webkit-text-stroke-width: 0px; text-decoration-thickness: initial;text-decoration-style: initial;text-decoration-color: initial; box-sizing: border-box;border-spacing: 0px;word-break:initial;font-variant-ligatures: normal; font-variant-caps: normal">
            <tbody>
                <tr height="39" style="height:29.25pt;box-sizing: border-box">
                    <th height="39" class="xl6320252" width="249" style="height:29.25pt;width:187pt">
                        API
                    </th>
                    <th class="xl6420252" width="235" style="width:176pt;border-image: initial">
                        Input Parameter
                    </th>
                    <th class="xl6420252" width="106" style="width:80pt;border-image: initial">
                        Return Value
                    </th>
                    <th class="xl6420252" width="200" style="width:150pt;border-image: initial">
                        Description
                    </th>
                    <th class="xl6520252" width="170" style="width:134pt;border-image: initial">
                        Supported System Type
                    </th>
                </tr>
                <tr height="99" style="mso-height-source:userset;height:74.25pt;box-sizing: border-box">
                    <td height="99" class="xl6620252" width="249" style="height:74.25pt;width:187pt; border-image: initial;box-sizing: border-box">
                        void ParseAllJobs(const cJSON *fileRoot)
                    </td>
                    <td class="xl6720252" width="235" style="width:176pt;border-image: initial; box-sizing: border-box">
                        const cJSON *fileRoot
                    </td>
                    <td class="xl6720252" width="106" style="width:80pt;border-image: initial; box-sizing: border-box">
                        void
                    </td>
                    <td class="xl6720252" width="200" style="width:150pt;border-image: initial; box-sizing: border-box">
                        Provides the general entry for parsing jobs.
                    </td>
                    <td class="xl6720252" width="170" style="width:134pt;border-image: initial; box-sizing: border-box">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="147" style="mso-height-source:userset;height:110.25pt;box-sizing: border-box">
                    <td height="147" class="xl6820252" width="249" style="height:110.25pt;width:187pt; border-image: initial;box-sizing: border-box">
                        static void ParseJob(const cJSON <span style="mso-spacerun:yes">&nbsp;</span>*jobItem, Job *resJob)
                    </td>
                    <td class="xl6920252" width="235" style="width:176pt;border-image: initial; box-sizing: border-box">
                        const cJSON *jobItem, Job *resJob
                    </td>
                    <td class="xl6920252" width="106" style="width:80pt;border-image: initial; box-sizing: border-box">
                        void
                    </td>
                    <td class="xl7020252" width="200" style="width:150pt;border-image: initial; box-sizing: border-box">
                        Checks whether a job exists and parses <strong>cmds</strong> in it.
                    </td>
                    <td class="xl6920252" width="170" style="width:134pt;border-image: initial; box-sizing: border-box">
                        Small system
                    </td>
                </tr>
                <tr height="177" style="mso-height-source:userset;height:132.75pt;box-sizing: border-box">
                    <td height="177" class="xl6620252" width="249" style="height:132.75pt;width:187pt; border-image: initial;box-sizing: border-box">
                        int GetCmdLinesFromJson(const cJSON *root, CmdLines **cmdLines)
                    </td>
                    <td class="xl6720252" width="235" style="width:176pt;border-image: initial; box-sizing: border-box">
                        const cJSON *root, CmdLines **cmdLines
                    </td>
                    <td class="xl6720252" width="106" style="width:80pt;border-image: initial; box-sizing: border-box">
                        int
                    </td>
                    <td class="xl6720252" width="200" style="width:150pt">
                        Parses <strong>cmds</strong> in the job. This API is used for the small system. It does not apply to the standard system because the <strong>trigger</strong> command and <strong>condition</strong> attribute are involved.
                    </td>
                    <td class="xl6720252" width="170" style="width:134pt;border-image: initial; box-sizing: border-box">
                        Small and standard systems
                    </td>
                </tr>
                <tr height="171" style="mso-height-source:userset;height:128.25pt;box-sizing: border-box">
                    <td height="171" class="xl6820252" width="249" style="height:128.25pt;width:187pt; border-image: initial;box-sizing: border-box">
                        int ParseTriggerConfig(const cJSON *fileRoot, int (*checkJobValid)(const char *jobName))
                    </td>
                    <td class="xl6920252" width="235" style="width:176pt;border-image: initial; box-sizing: border-box">
                        const cJSON *fileRoot, int (*checkJobValid)(const char *jobName)
                    </td>
                    <td class="xl6920252" width="106" style="width:80pt;border-image: initial; box-sizing: border-box">
                        int
                    </td>
                    <td class="xl6920252" width="200" style="width:150pt;border-image: initial; box-sizing: border-box">
                        Parses the <strong>trigger</strong> command in the job.
                    </td>
                    <td class="xl6920252" width="170" style="width:134pt;border-image: initial; box-sizing: border-box">
                        Standard system
                    </td>
                </tr>
                <tr height="210" style="mso-height-source:userset;height:157.5pt;box-sizing: border-box">
                    <td height="210" class="xl6620252" width="249" style="height:157.5pt;width:187pt; border-image: initial;box-sizing: border-box">
                        static int ParseTrigger_(const TriggerWorkSpace *workSpace, const cJSON *triggerItem, int (*checkJobValid)(const char *jobName))
                    </td>
                    <td class="xl6720252" width="235" style="width:176pt;border-image: initial; box-sizing: border-box">
                        const TriggerWorkSpace *workSpace, const cJSON *triggerItem, int (*checkJobValid)(const char *jobName)
                    </td>
                    <td class="xl6720252" width="106" style="width:80pt;border-image: initial; box-sizing: border-box">
                        int
                    </td>
                    <td class="xl6720252" width="200" style="width:150pt">
                        Obtains the job name, condition attribute, and <strong>cmds</strong> command group. Jobs are stored in a hash table, and commands are stored in a queue structure.
                    </td>
                    <td class="xl6720252" width="170" style="width:134pt;border-image: initial; box-sizing: border-box">
                        Standard system
                    </td>
                </tr><!--[endif]-->
            </tbody>
    </table>

**Table 3** Description of the job triggering APIs
<table border="0" cellpadding="0" cellspacing="0" width="906" style="border-collapse: collapse;table-layout:fixed;width:681pt;box-sizing: border-box;border-spacing: 0px; word-break:initial;font-variant-ligatures: normal;font-variant-caps: normal; orphans: 2;widows: 2;-webkit-text-stroke-width: 0px;text-decoration-thickness: initial; text-decoration-style: initial;text-decoration-color: initial">
            <tbody>
                <tr height="39" style="height:35.25pt;box-sizing: border-box">
                    <th height="47" class="xl6322245" width="239" style="height:35.25pt;width:153pt">
                        API
                    </th>
                    <th class="xl6322245" width="235" style="border-left:none;width:178pt">
                        Input Parameter
                    </th>
                    <th class="xl6322245" width="106" style="border-left:none;width:80pt">
                        Return Value
                    </th>
                    <th class="xl6322245" width="200" style="border-left:none;width:128pt">
                        Description
                    </th>
                    <th class="xl6322245" width="170" style="border-left:none;width:133pt">
                        Supported System Type
                    </th>
                </tr>
                <tr height="257" style="mso-height-source:userset;height:192.75pt;box-sizing: border-box">
                    <td height="257" class="xl6422245" width="204" style="height:192.75pt;border-top: none;width:153pt;box-sizing: border-box">
                        void PostTrigger(EventType type, const char *content, uint32_t contentLen)
                    </td>
                    <td class="xl6422245" width="235" style="border-top:none;border-left:none; width:178pt;box-sizing: border-box">
                        EventType type, const char *content, uint32_t contentLen
                    </td>
                    <td class="xl6422245" width="106" style="border-top:none;border-left:none; width:80pt;box-sizing: border-box">
                        void
                    </td>
                    <td class="xl6422245" width="170" style="border-top:none;border-left:none; width:128pt;box-sizing: border-box">
                        Verifies the validity of the job name and sends a job triggering event.
                    </td>
                    <td class="xl6422245" width="170" style="border-top:none;border-left:none; width:133pt;box-sizing: border-box">
                        Standard system
                    </td>
                </tr>
                <tr height="323" style="height:242.25pt;box-sizing: border-box">
                    <td height="323" class="xl6522245" width="204" style="height:242.25pt;border-top: none;width:153pt;box-sizing: border-box">
                        static void SendTriggerEvent(int type, const char *content, uint32_t contentLen)
                    </td>
                    <td class="xl6522245" width="235" style="border-top:none;border-left:none; width:178pt;box-sizing: border-box">
                        int type, const char *content, uint32_t contentLen
                    </td>
                    <td class="xl6522245" width="106" style="border-top:none;border-left:none; width:80pt;box-sizing: border-box">
                        void
                    </td>
                    <td class="xl6522245" width="170" style="border-top:none;border-left:none; width:128pt;box-sizing: border-box">
                        Performs functions such as system control and starting or stopping of services based on system parameters.
                    </td>
                    <td class="xl6522245" width="170" style="border-top:none;border-left:none; width:133pt;box-sizing: border-box">
                        Standard system
                    </td>
                </tr>
                <tr height="188" style="mso-height-source:userset;height:141.0pt;box-sizing: border-box">
                    <td height="188" class="xl6422245" width="204" style="height:141.0pt;border-top: none;width:153pt;box-sizing: border-box">
                        static void DoTriggerCmd(const struct CmdArgs *ctx)
                    </td>
                    <td class="xl6422245" width="235" style="border-top:none;border-left:none; width:178pt;box-sizing: border-box">
                        const struct CmdArgs *ctx
                    </td>
                    <td class="xl6422245" width="106" style="border-top:none;border-left:none; width:80pt;box-sizing: border-box">
                        void
                    </td>
                    <td class="xl6422245" width="170" style="border-top:none;border-left:none; width:128pt;box-sizing: border-box">
                        Executes the <strong>trigger</strong> command.
                    </td>
                    <td class="xl6422245" width="170" style="border-top:none;border-left:none; width:133pt;box-sizing: border-box">
                        Standard system
                    </td>
                </tr>
                <tr height="258" style="mso-height-source:userset;height:193.5pt;box-sizing: border-box">
                    <td height="258" class="xl6522245" width="204" style="height:193.5pt;border-top: none;width:153pt;box-sizing: border-box">
                        void DoTriggerExec(const char *triggerName)
                    </td>
                    <td class="xl6522245" width="235" style="border-top:none;border-left:none; width:178pt;box-sizing: border-box">
                        const char *triggerName
                    </td>
                    <td class="xl6522245" width="106" style="border-top:none;border-left:none; width:80pt;box-sizing: border-box">
                        void
                    </td>
                    <td class="xl6522245" width="170" style="border-top:none;border-left:none; width:128pt;box-sizing: border-box">
                        Finds a command group based on the job name and pushes the commands in the command group to the execution queue. This API is available only for the standard system. 
                    </td>
                    <td class="xl6522245" width="170" style="border-top:none;border-left:none; width:133pt;box-sizing: border-box">
                        Standard system
                    </td>
                </tr>
                <tr height="254" style="height:190.5pt;box-sizing: border-box">
                    <td height="254" class="xl6422245" width="204" style="height:190.5pt;border-top: none;width:153pt;box-sizing: border-box">
                        void DoJob(const char *jobName)
                    </td>
                    <td class="xl6422245" width="235" style="border-top:none;border-left:none; width:178pt;box-sizing: border-box">
                        const char *jobName
                    </td>
                    <td class="xl6422245" width="118" style="border-top:none;border-left:none; width:80pt;box-sizing: border-box">
                        void
                    </td>
                    <td class="xl6422245" width="170" style="border-top:none;border-left:none; width:128pt;box-sizing: border-box">
                        Matches a job based on the job name and invokes <strong>DoCmdByIndex</strong> to execute the commands in the job.
                    </td>
                    <td class="xl6422245" width="170" style="border-top:none;border-left:none; width:133pt;box-sizing: border-box">
                        Small system
                    </td>
                </tr>
                <tr height="208" style="height:156.0pt;box-sizing: border-box">
                    <td height="208" class="xl6522245" width="204" style="height:156.0pt;border-top: none;width:153pt;box-sizing: border-box">
                        void DoCmdByIndex(int index, const char *cmdContent)
                    </td>
                    <td class="xl6522245" width="235" style="border-top:none;border-left:none; width:178pt;box-sizing: border-box">
                        int index, const char *cmdContent
                    </td>
                    <td class="xl6522245" width="118" style="border-top:none;border-left:none; width:80pt;box-sizing: border-box">
                        void
                    </td>
                    <td class="xl6522245" width="170" style="border-top:none;border-left:none; width:128pt;box-sizing: border-box">
                        Combines parameters and commands.
                    </td>
                    <td class="xl6522245" width="170" style="border-top:none;border-left:none; width:133pt;box-sizing: border-box">
                        Small and standard systems
                    </td>
                </tr><!--[endif]-->
            </tbody>
    </table>

### Development Example
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
