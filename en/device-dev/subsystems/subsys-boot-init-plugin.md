# Plug-in Management

## Overview
### Basic Concepts

 - begetctl

   For details about begetctl, see [begetctl Commands](#table14737791480).

 - bootchart plug-in

   The bootchart plug-in is an open source tool used to evaluate system performance during Linux startup. It automatically collects information such as the CPU usage, disk throughput, and process status, and displays the evaluation result in graphics to facilitate system startup optimization.  

### Constraints

bootchart is available only for the standard system, and begetctl is available for both the small system and the standard system.

## How to Develop
### Parameters
 **Table 1** Description of begetctl commands
| Command| Format and Example| Description|
| :----------  |  :----------  |:--------|
| init group test [stage] | init group test | For details about **stage**, see **ServiceStatus**.|
| param ls [-r] [name] | Displays system parameters.<br>Example:<br>begetctl param ls persist.sys.usb   | N/A|
| param get [name] | Obtains system parameter information.<br>Example:<br>begetctl param get<br>param get| N/A|
| param set name value| Sets system parameters.<br>Example:<br>begetctl param set ohos.servicectrl.display 1<br>param set ohos.servicectrl.display 1| N/A|
| param wait name [value] [timeout] | Waits for system parameters.<br>Example:<br>begetctl param wait persist.sys.usb.config hdc<br>param wait persist.sys.usb.config hdc| The default value of **timeout** is **30**.|
| param dump [verbose] | Dumps system parameter information.<br>Example:<br>begetctl param dump<br>param dump| N/A|
| param shell [name] | Enters the param shell.<br>Example:<br>begetctl param shell<br>param shell| N/A|
| timer_stop servicename | Stops the service timer.<br>Example:<br>begetctl timer_stop appspawn | The value of **servicename** can contain a maximum of 96 characters.|
| timer_start servicename timeout | Starts the service timer.<br>Example:<br>begetctl timer_start appspawn | The value of **servicename** can contain a maximum of 96 characters. The default value of **timeout** is **10**.|
| start_service servicename | Starts a service.<br>Example:<br>begetctl start_service appspawn<br>start_service appspawn| N/A|
| stop_service servicename | Stops a service.<br>Example:<br>begetctl stop_service appspawn<br>stop_service appspawn| N/A|
| service_control start servicename | Starts a service.<br>Example:<br>begetctl service_control start appspawn<br>service_control start appspawn| N/A|
| service_control stop servicename | Stops a service.<br>Example:<br>begetctl service_control stop appspawn<br>service_control stop appspawn | N/A|
| misc_daemon --write_logo xxx.rgb | Writes the startup logo.<br>Example:<br>begetctl misc_daemon --write_logo logo.rgb<br>misc_daemon --write_logo logo.rgb| The maximum size of an RGB file is **1024*2038**. Only Hi3516D V300 is supported.|
| reboot | Restarts the system.<br>Example:<br>begetctl reboot<br>reboot|N/A|
| reboot shutdown | Shuts down the system.<br>Example:<br>begetctl reboot shutdown<br>reboot shutdown|N/A|
| reboot suspend | Suspends the system.<br>Example:<br>begetctl reboot suspend<br>reboot suspend| N/A|
| reboot updater | Restarts the system and enters updater.<br>Example:<br>begetctl reboot updater<br>reboot updater| N/A|
| reboot updater[:options] | Restarts the system and enters updater.<br>Example:<br>begetctl reboot updater<br>reboot updater| N/A|
| reboot flashd | Restarts the system and enters flashd.<br>Example:<br>begetctl reboot flashd<br>reboot flashd| N/A|
| reboot flashd[:options] | Restarts the system and enters flashd.<br>Example:<br>begetctl reboot flashd<br>reboot flashd| N/A|
| reboot charging | Restarts the system and enters charging.<br>Example:<br>begetctl reboot charging<br>reboot charging| N/A|
| reboot loader | Restarts the system and enters the burning mode.<br>Example:<br>begetctl reboot loader<br>reboot loader| N/A|
| bootchart stop | Stops chart analysis.<br>Example:<br>begetctl bootchart stop | Only rk3568 is supported.|
| bootchart start | Starts chart analysis.<br>Example:<br>begetctl bootchart start | N/A|
| bootchart disable | Disables chart analysis.<br>Example:<br>begetctl bootchart disable | N/A|
| bootchart enable | Enables chart analysis.<br>Example:<br>begetctl bootchart enable | N/A|
| sandbox -s service_name | Moves a service into the sandbox.<br>Example:<br>sandbox -s foundation | N/A|
| sandbox -p process_name | Moves a process into the sandbox.<br>Example:<br>sandbox -p /bin/sh | N/A|
| sandbox -n sandbox_name | Enters the configured system or chipset sandbox.<br>Example:<br>sandbox -n system | N/A|
| sandbox -h | sandbox command help | N/A|


## How to Develop

### Available APIs

  **Table 1** Description of APIs
| API| Description|
| ----------  |  ---------- |
| void PluginExecCmdByName(const char *name, const char *cmdContent) | Starts the plug-in by name.|
| void PluginExecCmdByCmdIndex(int index, const char *cmdContent) | Starts the plug-in by index.|
| int PluginExecCmd(const char *name, int argc, const char **argv) | Starts the plug-in by command.|
| int AddCmdExecutor(const char *cmdName, CmdExecutor execCmd) | Adds the plug-in installation command.|

### How to Develop
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
2. Compile the static library **libbootchart_static** and add it to the **static_modules** group.
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
  6. Export the following files from the **/data/bootchart** directory and save them to the **bootchart** folder:<br>
        header<br>
        proc_diskstats.log<br>
        proc_ps.log<br>
        proc_stat.log<br>
  7. Run the <strong>tar -zcvf bootchart.tgz *</strong> command to compress the <strong>bootchart.tgz</strong> file (available only for Linux) and copy the compressed file to the <strong>linux:bootchart-master</strong> directory.
  8. Run the following command in the <strong>bootchart-master</strong> directory:
      ```
      python3 pybootchartgui.py -f pdf bootchart.tgz
      ```

  Expected Result
        <br>A **bootchart.pdf** file is generated in the **bootchart-master** directory.
