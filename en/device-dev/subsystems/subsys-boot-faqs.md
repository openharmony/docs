# FAQs

## System startup interrupted due to "parse failed!" error

**Problem**

During system startup, the error message "\[Init\] InitReadCfg, parse failed! please check file /etc/init.cfg format." is displayed, and the startup is interrupted, as shown in the following figure.

**Figure  1**  Error information<a name="fig15217111545118"></a>  
![](figures/error-information.png "error-information")

**Cause**

During the modification of the  **init.cfg**  file, required commas \(,\) or parentheses are missing or unnecessary ones are added. As a result, the file's JSON format becomes invalid.

**Solution**

Check the  **init.cfg**  file and ensure that its format meets the JSON specifications.

## System automatically restarted again and again

**Problem**

After the image burning is complete, the system keeps restarting.

**Cause**

Each service started by the init process has the  **importance**  attribute, as described in Table 3 in [Job Management](../subsystems/subsys-boot-init-jobs.md).

-   If the attribute value is  **0**, the init process does not need to restart the development board when the current service process exits.
-   If the attribute value is  **1**, the init process needs to restart the development board when the current service process exits.

During the startup of a service whose  **importance**  is  **1**, if the service exits due to a process crash or an error, the init process automatically restarts the development board.

**Solution**

1.  View logs to identify the service that encounters a process crash or exits due to an error, rectify the issue, and then burn the image again.
2.  Alternatively, change the value of  **importance**  to  **0**  for the service that exits due to a process crash or an error, and then burn the image again. In this way, the development board will not be restarted even if the service exits.

## Failed to call the  **SetParameter**  or  **GetParameter**  API with correct parameter values

**Problem**

Calling the  **SetParameter**  or  **GetParameter**  API fails even if correct values are passed to all input parameters.

**Cause**

Permission verification has been enabled for the  **SetParameter**  and  **GetParameter**  APIs. If the UID of the caller is greater than 1000, that is, the caller does not have the permission to call these APIs, API calls will fail even if the parameters are correct.

**Solution**

No action is required.

