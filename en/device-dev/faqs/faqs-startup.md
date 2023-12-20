# Startup

## System Startup

### Device Startup Interrupted Due to "parse failed!" Error

**Symptom**

During device startup, the error message "[Init] InitReadCfg, parse failed! please check file /etc/init.cfg format." is displayed, and the startup is interrupted, as shown in the following figure.

  **Figure 1** Error information

  ![en-us_image_0000001200053087](figures/en-us_image_0000001200053087.png)

**Possible Cause**

The content of the **init.cfg** file does not comply with the JSON specifications.

**Solution**

Check the **init.cfg** file and ensure that its format meets the JSON specifications.


### Device Restarted Repeatedly

**Symptom**

The device restarts over and over again upon startup. 

**Possible Cause**

Each service started by the init process has the **importance** attribute, as described in [Parameters](../subsystems/subsys-boot-init-service.md#description-of-service-process-configuration-files).

- If the attribute value is **0**, the init process does not need to restart the device when the current service process exits.

- If the attribute value is **1**, the init process needs to restart the device when the current service process exits.

**Solution**

1. View logs to identify the service that encounters a process crash or exits due to an error, rectify the issue, and then burn the image again.

2. Change the value of **importance** to **0** for the service that exits due to a process crash or an error, and then burn the image again.


### **SetParameter** or **GetParameter** Failed with Correct Parameters Passed

**Symptom**

Calling **SetParameter** or **GetParameter** fails when correct parameters are passed.

**System Type**

liteos-a

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

1. For case 1, configure a socket for the ueventd service in the **.cfg** file. For details, see [Socket Configuration for the ueventd Service](../subsystems/subsys-boot-init-service.md#description-of-service-process-configuration-files).
2. For case 2, check all **.cfg** files for any duplicate ueventd service and delete it. Retain only one ueventd service with valid configuration.

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

When the **ondemand** attribute is configured, a service is started on demand by default. This attribute, however, is mutually exclusive with the **critical** attribute. If both of them are configured, a conflict will occur, resulting in a failure to resolve the service.

**Solution**

1. If a service does not need to be started on demand, leave the **ondemand** attribute unspecified.
2. If a service needs to be started on demand, leave the **critical** attribute unspecified or disable the **critical** attribute after you configure the **ondemand** attribute.

### Parallel Startup Is Not Effective for Services Configured with the ondemand Attribute

**Symptom**

Services configured with the **ondemand** attribute are not started in the parallel startup phase, regardless of the **start-mode** settings.

**Possible Cause**

Services configured with the **ondemand** attribute are started only when the startup conditions are met. Therefore, parallel startup is not effective for these services.

**Solution**

If you want to add a service to parallel startup, do not configure the **ondemand** attribute for it.

### SA Services Cannot Be Started on Demand

**Symptom**

When an SA service is configured with the **ondemand** attribute, the samgr process does not start the SA service after the SA client sends a request.

**Possible Cause**

At the initial implementation of on-demand startup for SA services, **SystemAbilityManager::CheckSystemAbility(int32_t systemAbilityId)** is used for all SA services. To distinguish SA services that are started on demand, **LoadSystemAbility(int32_t systemAbilityId, const sptr& callback)** provided by the samgr process is added. If an SA service is not started on demand, it is probable that the original API is used by mistake.

**Solution**

Use **LoadSystemAbility(int32_t systemAbilityId, const sptr& callback)** for any SA service that needs to be started on demand.

### Improper caps Configuration

**Symptom**

Improper caps configuration leads to a configuration error. The error information is as follows:
 ```
4.619955] [pid=1 0][Init][ERROR][init_capability.c:119]service=multimodalinput not support caps = CAP_DC_OVERRIDE caps 41
[ 4.620014] [pid=1 0][Init][ERROR][init_service_manager.c:818]GetServiceSecon secon section not found, skip
[ 4.620216] [pid=1 0][Init][ERROR][init_service_manager.c:818]GetServiceSecon secon section not found, skip
[ 4.620608] [pid=1 0][Init][ERROR][init_capability.c:119]service=mmi_uinput_service  not support caps = CAP_DC_OVERRIDE caps 41
 ```
**Possible Cause**

1. The caps configuration is not supported by the kernel.
2. The configuration in the **.cfg** file is incorrect.

**System Version**

OpenHarmony-3.0-LTS

**Solution**

1. For case 1, leave **caps** unspecified.
2. For case 2, correctly configure **caps** by referring to the definition of the **capStrCapNum** data structure in **base/startup/init/services/init/init_capability.c**.

### Sandbox Not Enabled

**Symptom**

After **hdc shell param get const.sandbox** is run, it is found that the value of **const.sandbox** is not **enable**.

**Possible Cause**

None.

**Solution**

Set **const.sandbox** to **enable** in **base/startup/init/services/etc/param/ohos.para**. For details, see [Sandbox Management](../subsystems/subsys-boot-init-sandbox.md).

### How to Check the Sandbox Mounting Status

**Symptom**

None.

**Possible Cause**

None.

**Solution**

Enter the hdc shell mode on the device. Then, run the **sandbox -s service_name** command to move the current service to the sandbox, and run shell commands such as **ls** to view the sandbox directory. For details, see the [sandbox command description](../subsystems/subsys-boot-init-plugin.md).

### Timestamp in the Ready Phase of Some Bootevent Events Is 0

**Symptom**

In manual bootevent mode, after device startup is completed and the **dump_service all bootevent** command is executed, the timestamps in the ready phase of some events are 0.

**Possible Cause**

1. The service does not send the bootevent event.
2. The service sends the bootevent event, but does not have the related permission.

**Solution**

1. For case 1, make sure the related service sends the bootevent in the code.
2. For case 2, make sure the service has the permission to set the bootevent parameter.

### Failed to Boot from Partition A/B

**Symptom**

After the image is burnt, the system cannot be started, and information similar to the following can be found in the serial port log:

```
wait for file:/dev/block/platform/fe310000.sdhci/by-name/system_b failed after 5 second.
Mount /dev/block/platform/fe310000.sdhci/by-name/system_b to /usr failed 2
```

**Possible Cause**

As indicated by the log, partition B is used as the boot partition. However, it is not found during startup, resulting in the startup failure. This issue occurs because the active slot value in the misc partition is set to 2 (partition B), but partition B is not burnt.

**Solution**

1. Clear the misc partition by burning the corresponding partition with an empty misc image, erase the active slot value, and restart the system from the default partition.
2. Burn the **system_b** and **vendor_b** images to the development board by using the partition table configured with partition B. Then, the development board can boot from partition B.

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

1. Cold start is not enabled.
2. The parameter of the cold start command is incorrect.
3. The socket request times out.
4. SELinux is enabled.

**Solution**

1. For case 1, run **param get startup.appspawn.cold.boot** to check the cold start switch and run **param set startup.appspawn.cold.boot 1** to enable cold start.
2. For case 2, correct the parameter of the cold start command.
3. For case 3, run the **param set persist.appspawn.client.timeout 5** command to set the timeout period to 5.
4. For case 4, run the **setenforce 0** command to disable SELinux.

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

For details, see How to Develop in [Application Sandbox Development Procedure](../subsystems/subsys-boot-appspawn.md).
