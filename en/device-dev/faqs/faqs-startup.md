# Startup

## System Startup

### System Startup Interrupted Due to "parse failed!" Error

**Symptom**

During system startup, the error message "[Init] InitReadCfg, parse failed! please check file /etc/init.cfg format." is displayed, and the startup is interrupted, as shown in the following figure.

  **Figure 1** Error information

  ![en-us_image_0000001200053087](figures/en-us_image_0000001200053087.png)

**Possible Cause**

During modification of the **init.cfg** file, required commas (,) or parentheses are missing or unnecessary ones are added. As a result, the file's JSON format becomes invalid.

**Solution**

Check the **init.cfg** file and ensure that its format meets the JSON specifications.


### System Restarted Repeatedly

**Symptom**

After the image burning is complete, the system restarts over and over again.

**Possible Cause**

Each service started by the init process has the **importance** attribute, as described in Table 3 in [init Module](../subsystems/subsys-boot-init.md).

- If the attribute value is **0**, the init process does not need to restart the development board when the current service process exits.

- If the attribute value is **1**, the init process needs to restart the development board when the current service process exits.

During the startup of a service whose **importance** is **1**, if the service exits due to a process crash or an error, the init process automatically restarts the development board.

**Solution**

1. View logs to identify the service that encounters a process crash or exits due to an error, rectify the issue, and then burn the image again.

2. Alternatively, change the value of **importance** to **0** for the service that exits due to a process crash or an error, and then burn the image again. In this way, the development board will not be restarted even if the service exits.


### **SetParameter** or **GetParameter** Failed with Correct Parameters Passed

**Symptom**

Calling **SetParameter** or **GetParameter** fails when correct parameters are passed.

**Possible Cause**

Permission verification has been enabled for **SetParameter** and **GetParameter**. If the UID of the caller is greater than **1000**, that is, the caller does not have the API call permission, calling an API will fail even if correct parameters are passed.

**Solution**

No action is required.


### ueventd Service Failed to Obtain a Socket upon Startup

**Symptom**

After the ueventd service is started, the error message "Failed to get uevent socket, try to create" is displayed, and the error information as shown in the following figure is logged.

  **Figure 2** Failure to obtain a socket

  ![ueventd_socket](figures/ueventd_socket.png)

**Possible Cause**

The ueventd service is started on demand. Upon startup, it first needs to check the environment variables for **fd** of the socket created by the init process. The preceding error information will be displayed if the ueventd service fails to obtain environment variables. The possible causes are as follows:
1. No socket has been configured for the ueventd service in the **.cfg** file. As a result, the init process does not create a socket for the ueventd service, and no socket ID is present in environment variables.
2. If a socket has been configured for the ueventd service in the **.cfg** file, it is probable that the ueventd service is also configured in another **.cfg** file but no socket is designated for it.

**Solution**

For case 1, configure a socket for the ueventd service in the **.cfg** file. For details, see [Development Guidelines](https://gitee.com/openharmony/docs/blob/master/en/device-dev/subsystems/subsys-boot-init.md#development-guidelines).

For case 2, check all **.cfg** files for any duplicate ueventd service and delete it. Retain only one ueventd service with valid configuration.

### ueventd Service Exits Because of a Socket Polling Timeout

**Symptom**

After the ueventd service is started for a period of time, the error message "poll ueventd socket timeout, ueventd exit" is displayed and the ueventd service automatically exits.

**Possible Cause**

The ueventd service is started on demand. When a uevent is reported, the init process receives a socket message and starts the ueventd service to process the message. After processing the message, the ueventd service polls the corresponding socket handle for 30s. If a new socket message is reported within this period of time, the ueventd service continues to process the message. After processing the message, the ueventd service polls the socket handle for 30s once again. If no new socket message is reported within this period of time, the ueventd service exits and returns the socket to the init process for polling. In this case, the preceding error message is displayed.

**Solution**

This is a normal phenomenon and no action is required.

### Service with the ondemand Attribute Failed to Start Because of a Configuration Parsing Error

**Symptom**

The service configuration in JSON format cannot be correctly parsed, and the error message "Service is invalid which has both critical and ondemand attribute" is displayed. When the service is started, the error message "Cannot find service" is displayed.

**Possible Cause**

The service configuration is not in the JSON format. This can result in a **.cfg** file parsing error, leading to a service parsing failure. For a service configured with the **ondemand** attribute, the **critical** attribute is set to **1**, or the first value in the **critical** attribute array is set to **1**. When the **ondemand** attribute is configured, the service is started on demand by default. The service exits when it is idle. However, when the **critical** attribute is configured, the service is regarded as a critical system service and is not allowed to exit. Therefore, a conflict occurs if both attributes are configured the same service.

**Solution**

Check whether the service needs to be started on demand. If not, do not configure the **ondemand** attribute. If yes, do not configure the **critical** attribute along with the **ondemand** attribute. To limit the number of times that a critical service exits abnormally, set the first value in the **critical** attribute array to **0** and then add a limitation on the exit times. For example, **"critical": [0, 15, 5]** means that, if a service exits for more than 15 times within 5s, the service will not be started and the system will not be restarted.


### Parallel Startup Is Not Effective for Services Configured with the ondemand Attribute

**Symptom**

Services configured with the **ondemand** attribute are not started in the parallel startup phase, regardless of whether **start-mode** is set to **boot**, **normal**, or the default value.

**Possible Cause**

Services configured with the **ondemand** attribute are started only when the startup conditions are met. Therefore, parallel startup is not effective for these services.

**Solution**

If you want to add a service to parallel startup, do not configure the **ondemand** attribute for it.

### SA Services Cannot Be Started on Demand

**Symptom**

When an SA service is configured with the **ondemand** attribute, the samgr process does not start the SA service after the SA client sends a request.

**Possible Cause**

At the initial implementation of on-demand startup, **SystemAbilityManager::CheckSystemAbility(int32_t systemAbilityId)** is used for all SA services. To distinguish SA services that are started on demand, **LoadSystemAbility(int32_t systemAbilityId, const sptr& callback)** provided by the samgr process is added. If an SA service is not started on demand, it is probable that the original API is used by mistake.

**Solution**

Use **LoadSystemAbility(int32_t systemAbilityId, const sptr& callback)** for any SA service that needs to be started on demand.

### Improper DAC Configuration

**Symptom**

Improper DAC configuration leads to a configuration error. The error information is as follows:
 ```
4.619955] [pid=1 0][Init][ERROR][init_capability.c:119]service=multimodalinput not support caps = CAP_DC_OVERRIDE caps 41
[ 4.620014] [pid=1 0][Init][ERROR][init_service_manager.c:818]GetServiceSecon secon section not found, skip
[ 4.620216] [pid=1 0][Init][ERROR][init_service_manager.c:818]GetServiceSecon secon section not found, skip
[ 4.620608] [pid=1 0][Init][ERROR][init_capability.c:119]service=mmi_uinput_service  not support caps = CAP_DC_OVERRIDE caps 41
```
**Possible Cause**

1. Max attributes are present in the **caps** configuration.
2. Parsing of attributes carrying CAP and non-CAP prefixes is not supported.
3. The **const** attribute configuration is invalid.

**Solution**

1. Enable parsing of attributes carrying CAP and non-CAP prefixes.
2. Remove max attributes from the **caps** configuration.
3. Add a correct **const** attribute file.

### Invalid critical Attribute Configuration

**Symptom**

The configuration of the **critical** attribute does not take effect.

**Possible Cause**

1. The format of the **critical** attribute is valid.
2. The services configured with the **critical** attribute are not started.
3. The modified configuration file is not effective.

**Solution**

1. Correct the format of the **critical** attribute.
2. Start the services configured with the **critical** attribute.
3. Modify the configuration file based on the device type. The configuration file is **init.cfg** for Hi3516 and **init.without_two_stages.cfg** for RK3568.

### On-demand Startup Not Supported for Socket Processes

**Symptom**

On-demand startup is not supported for socket processes.

**Possible Cause**

The **DISABLE_INIT_TWO_STAGES** macro setting is invalid for on-demand startup of the ueventd process.

**Solution**

Enable **socket** in **startUeventd** so that socket validity check is added to the socket creation function.


### Small System Compilation Alarm

**Symptom**

The alarm information is as follows:

warning: implicit declaration of function 'usleep' is invalid in C99
warning: implicit declaration of function 'setgroups' is invalid in C99

**Possible Cause**

The header file is incorrect or the *GNU***SOURCE** macro is disabled.

**Solution**

Check whether the corresponding header file is correct. If yes, check whether the *GNU***SOURCE** macro is enabled.

## Application Spawning

### Failed to Start appspawn

**Symptom**

During system startup, the system stops at the startup animation and fails to launch the appspawn process.

**Possible Cause**

1. The startup animation does not exit properly.
2. The attempt to start system applications has failed, resulting in a failure to start the appspawn process.

**Solution**

View logs to identify the service that encounters a process crash or exits due to an error, rectify the issue, and then burn the image again.

### Cold Start of Applications Failed

**Symptom**

Applications fail to be started by running the cold start command.
  ```
  aa start -d 12345 -a $name -b $package -C
  ```

**Possible Cause**

1. The cold start does not take effect.
2. The cold start command is incorrect.

**Solution**

1. Enable cold start by setting **param set appspawn.cold.boot true**.
2. Make sure that the cold start command is correct.

### Failed to Create the Application Sandbox

**Symptom**

The system UI freezes at the OpenHarmony startup animation, the calculator application does not respond after being touched, or the font is not displayed properly. The error information in the hilog file is as follows:
 - bind mount `<src-path>` to `<sandbox-path>` failed errno `<errorCode>`
 - private mount to `<sandbox-path>`  failed errno `<errorCode>`
 - symlink failed, `<link-name>`, errno is `<errorCode>`

**Possible Cause**

1. The sandbox creation process is incorrect.
2. The **com.ohos.systemui** sandbox fails to be created.
3. The file on which the application sandbox depends is not configured correctly.

**Solution**

1. Check the error information in the hilog file, and correct the corresponding JSON files.
2. Verify the PID of the application, the code logic of the sandbox creation process, and the JSON configuration.
