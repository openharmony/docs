# Plug-in Management

## Overview
### Basic Concepts
 - Introduction to begetctl

   begetctl is a CLI-based management tool. For details about this functions, see [Description of begetctl Commands](#table14737791480).
 - bootchart plug-in

   The bootchart plug-in is an open source tool used to evaluate system performance during Linux startup. It automatically collects information such as the CPU usage, disk throughput, and process status, and displays the evaluation result in graphics to facilitate system startup optimization. For details about this functions, see [Description of begetctl Commands](#table14737791480).
 - bootevent plug-in

   bootevent is a plug-in that records key startup events of the init process and each service. The recorded information includes the event name, startup time of the service associated with the event, and event occurrence time. By using the exported file for trace parsing, you can then optimize the system startup process.

### Constraints

bootchart and bootevent are available only for the standard system, and begetctl is available for both the small system and the standard system.

## How to Develop
### Parameters
 **Table 1** Description of begetctl commands<a name="table14737791480"></a>
| Command| Description| Format and Example|
| :----------  |  :----------  |:-------------- |
| init group test [stage] | Applies to init module test.| For details about **stage**, see [ServiceStatus](#section001).|
| param ls [-r] [name] | Displays system parameters **dac** and **selinux**.<br> -r: Displays information about all parameters.<br> name: Displays information about specified parameters.| begetctl param ls xxx.xxx or<br>param ls xxx.xxx<br>Example:<br>begetctl param ls persist.sys.usb |
| param get [name] | Obtains system parameter values.| begetctl param get xxxx.xxx or<br>param get xxxx.xxx<br>Example:<br>param get const.product.name|
| param set name value| Sets system parameter values.|begetctl param set xxxx.xxx value or<br> param set xxxx.xxx value <br>Example:<br>begetctl param set ohos.servicectrl.display 1 |
| param wait name [value] [timeout] | Waits for the parameter to be set to a specific value.<br> The default value of **timeout** is **30**.| begetctl param wait xxx.xxx value or<br> wait xxx.xxx value <br>Example:<br>param wait xx.sss 1 |
| param dump [verbose] | Dumps system parameter information.|begetctl param dump <br>or param dump|
| param shell [name] | Enters the parameter shell.|begetctl param shell <br>or param shell|
| param save | Persistently stores all parameters marked with a persistency flag in the workspace.|begetctl param save <br>or param save|
| dump api | Displays information about APIs of the init process.|begetctl dump api |
| getloglevel | Obtains the log level of the init process from<br>**persist.init.debug.loglevel**.<br>0: debug<br> 1: info<br> 2: warning<br> 3: err<br> 4: fatal|begetctl getloglevel |
| setloglevel level | Sets the log level to **info**.<br>The log level ranges from **0** to **4**.<br> 0: debug<br>1: info<br> 2: warning<br> 3: err<br>4: fatal|begetctl setloglevel 1 |
| timer_stop servicename | Stops a service timer.<br>The value of **servicename** can contain a maximum of 96 characters.|begetctl timer_stop servicename | begetctl timer_stop appspawn |
| timer_start servicename timeout | Starts the service timer.<br>The value of **servicename** can contain a maximum of 96 characters.<br>The default value of **timeout** is 10 ms.|begetctl timer_start servicename | begetctl timer_start appspawn|
| start_service servicename | Starts a service.| begetctl start_service servicename or<br>start_service servicename|begetctl start_service appspawn |
| stop_service servicename | Stops a service.|begetctl stop_service servicename or<br> stop_service servicename|begetctl stop_service appspawn |
| service_control start servicename | Starts a service.|begetctl service_control start servicename or<br> service_control start servicename|begetctl service_control start appspawn |
| service_control stop servicename | Stops a service.|begetctl service_control stop servicename or<br> service_control stop servicename|begetctl service_control stop appspawn |
| sandbox -b pid | Accesses the native application sandbox.| begetctl sandbox -b pid|
| sandbox -p process_name | Moves a process into the sandbox.| begetctl sandbox -p /bin/sh |
| sandbox -n sandbox_name | Moves a process into the configured **system** or **chipset** sandbox.| begetctl sandbox -n system|
| sandbox -s service_name | Moves a service into the sandbox.| begetctl sandbox -s service_name |
| sandbox -h | Displays the help information about the sandbox.| begetctl sandbox -h |
| modulectl uninstall moduleName | Uninstalls a dynamic plug-in.| begetctl modulectl uninstall moduleName <br>Example:<br>Uninstall the bootchart:<br> begetctl modulectl uninstall bootchart |
| modulectl install moduleName | Installs a dynamic plug-in.|begetctl modulectl install moduleName <br>Example:<br>Install the bootchart:<br>begetctl modulectl install bootchart |
| modulectl list | Obtains the list of dynamic plug-ins.|begetctl modulectl list |
| misc_daemon --write_logo xxx.rgb | Writes the startup logo.<br>The maximum size of an RGB file is **1024*2038**. Only Hi3516D V300 is supported.|begetctl misc_daemon --write_logo logo.rgb or<br> misc_daemon --write_logo logo.rgb|
| reboot | Restarts the system.|begetctl reboot or<br> reboot|
| reboot shutdown[:options] | Shuts down the system.|begetctl reboot shutdown or<br> reboot shutdown |
| reboot suspend | Suspends a system.|begetctl reboot suspend or<br> reboot suspend |
| reboot updater | Restarts and enters updater.|begetctl reboot updater or<br> reboot updater |
| reboot updater[:options] | Restarts and enters updater.|begetctl reboot updater or<br> reboot updater |
| reboot flashd | Restarts and enters flashd.|begetctl reboot flashd or<br> reboot flashd |
| reboot flashd[:options] | Restarts and enters flashd.|begetctl reboot flashd or<br> reboot flashd |
| reboot charge | Restarts and enters charge.|begetctl reboot charge or<br> reboot charge |
| reboot loader | Restarts and enters loader.|begetctl reboot loader or<br> reboot loader |
| bootevent disable | Disables the bootevent plug-in.|begetctl bootevent disable |
| bootevent enable | Enables the bootevent plug-in.|begetctl bootevent enable |
| dump_service parameter_service trigger | Displays information about all triggers.|begetctl dump_service parameter_service trigger |
| dump_service all | Displays information about all services.|begetctl dump_service all |
| dump_service serviceName | Displays information about a service.|begetctl dump_service param_watcher |
| dump_service loop | Dumps fd information in the service loop.|begetctl dump_service loop|
| bootchart stop | Stops graphics analysis. Only RK3568 is supported.|begetctl bootchart stop |
| bootchart start | Starts graphics analysis.|begetctl bootchart start |
| bootchart disable | Disables graphics analysis.|begetctl bootchart disable |
| bootchart enable | Enables graphics analysis.|begetctl bootchart enable |
| dac uid username | Obtains the UID corresponding to the specified **username**.|begetctl dac uid username <br>Example:<br>begetctl dac uid root|
| dac gid groupname | Obtains the GID corresponding to the specified **groupname** and group members.|begetctl dac gid groupname <br>Example:<br> begetctl dac gid shell |
| get log level | Obtains the log level of the init process from<br>**persist.init.debug.loglevel**.<br>0: debug<br> 1: info<br> 2: warning<br> 3: err<br> 4: fatal|begetctl get log level |
| set log level | Set the log level to **info**.<br>The log level ranges from **0** to **4**.<br> 0: debug<br>1: info<br> 2: warning<br> 3: err<br>4: fatal|begetctl set log level 1 |
| appspawn_time | Obtains the maximum and minimum time for application spawning.| begetctl appspawn_time <br>Example:<br>begetctl appspawn_time|
| dump_nwebspawn | Dumps information about the nwebspawn application.|begetctl dump_nwebspawn <br>Example:<br>Opens Notepad.<br>begetctl dump_nwebspawn |
| dump_appspawn | Dumps information about the appspawn application.|begetctl dump_appspawn<br>Example:<br>begetctl dump_appspawn|

- <a name = "section001"> **ServiceStatus**
```
typedef enum {
    SERVICE_IDLE = 0, // service add
    SERVICE_STARTING, // service start
    SERVICE_STARTED, // 2 service ok running
    SERVICE_READY, // 3 service ok running
    SERVICE_STOPPING,
    SERVICE_STOPPED, // 5
    SERVICE_ERROR,
    SERVICE_SUSPENDED,
    SERVICE_FREEZED,
    SERVICE_DISABLED,
    SERVICE_CRITICAL
} ServiceStatus;
```
### Development Procedure
  Add a plug-in. The following uses bootchart as an example:
1. Install the **.so** file and define an independent file to implement the following functions:
      ```c
      static int bootchartEarlyHook(int stage, int prio, void *cookie)
      {
          char enable[4] = {}; // 4 enable size
          uint32_t size = sizeof(enable);
          SystemReadParam("persist.init.bootchart.enabled", enable, &size);
          if (strcmp(enable, "1") != 0) {
              PLUGIN_LOGI("bootchart disabled.");
              return 0;
          }
          InitModuleMgrInstall("libbootchart");
          PLUGIN_LOGI("bootchart enabled.");
          return 0;
      }
      
      MODULE_CONSTRUCTOR(void)
      {
          // Depends on parameter service
          InitAddPostPersistParamLoadHook(0, bootchartEarlyHook);
      }
      ```     
2. Compile the static library **libbootchart\_static** and add it to the **static\_modules** group.
      ```
      group("static_modules") {
        if (!defined(ohos_lite)) {
          deps = [ ":libbootchart_static" ]
        }
      }
      ```
      
3. Initialize the bootchart plug-in.
      ```c
      static int BootchartInit(void)
      {
          if (g_executorId == -1) {
              g_executorId = AddCmdExecutor("bootchart", DoBootchartCmd);
              PLUGIN_LOGI("BootchartInit executorId %d", g_executorId);
          }
          return 0;
      }
      
      MODULE_CONSTRUCTOR(void)
      {
          PLUGIN_LOGI("DoBootchartStart now ...");
          BootchartInit();
      }
      ```
4. Exit the bootchart plug-in.
      ```c
      MODULE_DESTRUCTOR(void)
      {
          PLUGIN_LOGI("DoBootchartStop now ...");
          DoBootchartStop();
          BootchartExit();
      }
      ```
5. Run the bootchart command.
    ```c
    static int DoBootchartCmd(int id, const char *name, int argc, const char **argv)
    {
        PLUGIN_LOGI("DoBootchartCmd argc %d %s", argc, name);
        ...
        return 0;
    }
    ```

### Development Example
#### Bootchart
  Prerequisites
  1. Prepare the bootchart test environment. Specifically, install Python and pycairo by running **pip install pycairo** on Linux.
  2. Decompress **bootchart-master.tar**.

     tar -zxvf  bootchart-master.tar

  Procedure
  1. Start the system.
  2. Run the **begetctl bootchart enable** command.
  3. Restart the system.
  4. Run the **begetctl bootchart stop** command.
  5. Run the **begetctl bootchart disable** command.
  6. Export the following files from the **/data/service/el0/startup/init/** directory and save them to the **bootchart** folder:<br>
        header<br>
        proc_diskstats.log<br>
        proc_ps.log<br>
        proc_stat.log<br>
  7. Run the **tar -zcvf bootchart.tgz *** command to compress the **bootchart.tgz** file (available only for Linux) and copy the compressed file to the **linux:bootchart-master** directory.
  8. Run the following command in the **bootchart-master** directory:
      ```
      python3 pybootchartgui.py -f pdf bootchart.tgz
      ```

  Expected Result
        <br>A **bootchart.pdf** file is generated in the **bootchart-master** directory.
#### bootevent
1. Configure one or more boot events in the **.cfg** file.

    Configure a single boot event.
    ```json
    bootevents : "bootevent.xxxbootevent",
    ```
    Configure multiple boot events.
    ```json
    bootevents : ["bootevent.xxxbootevent1", "bootevent.xxxbootevent2.xxx"],
    ```
> **Note:** The configured event must start with **bootevent**.
2. Send the boot events.

    Call the **SetParameter** API provided by init process to send the boot events. For example, to send the XXXbootevent1 event configured in the previous step, use the following code:
    ```c
    SetParameter("bootevent.XXXbootevent1", "true");
    ```
3. Enable the bootevent function by running the **begetctl bootevent enable** command.

    - To enable the bootevent function, run the **begetctl bootevent enable** command and restart the system.
    - To disable the bootevent function, run the **begetctl bootevent disable** command and restart the system.
4. Use the exported bootevent file for trace analysis.

    - The exported bootevent file is stored in the **/data/service/el0/startup/init/** directory.
    - It is named in the format of *timestamp***.bootevent**.
    - You can import the file to the trace analysis tool for visual analysis.
