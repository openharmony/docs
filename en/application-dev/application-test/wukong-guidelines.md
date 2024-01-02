# wukong User Guide

## Introduction

wukong is a built-in command line tool that implements application stability test capabilities such as random event injection, component injection, exception capture, report generation, and data traversal of abilities. This tool allows you to conduct stability tests on the system or applications by simulating user behavior.<br>
wukong provides two types of testing: random testing and special testing. In random testing, test inputs are generated randomly. Available features include shell startup, whole application startup, multiple injection modes, random seeds setting, run log printing, and report generation. In special testing, specific application components are tested. Available features include shell startup, sequential traversal and screenshot, sleep and wakeup test, recording and playback, run log printing, and report generation.

## Principles

The following figure shows the wukong component architecture and the responsibilities of sub-modules.
 ![](figures/wukongRandomTestFlow.png)

- Command line parsing: Obtain and parse parameters using commands.
- Operating environment management: Initialize the overall operating environment of wukong using commands.
- System API management: Check and obtain the specified mgr, and register the callback function of the Faultlogger for the controller and DFX.
- Random event generation: Use the **random** function to generate a sequence of random numbers with the specified seed value to generate an event.
- Event injection: Inject events of supported types to the system. This feature depends on the window, multi-mode, and security subsystems.
- Exception capture and processing and report generation: Obtain exception information with the DFX subsystem during application running, record log, and generate reports.

## Constraints

1. The wukong tool is built in the system since API version 9.

2. In API versions earlier than 9, you need to build the tool and push it to the target device. The procedure is as follows:

   ```
    // Build code.
     ./build.sh --product-name rk3568 --build-target wukong

   // Push the tool to the target device.
    hdc shell mount -o rw,remount /
    hdc file send wukong /
    hdc shell chmod a+x /wukong
    hdc shell mv /wukong /bin/
   ```

3. When the PC is connected to one or more target devices, you can run test commands.

## Random Testing

1. Open the shell.<br>If you are testing one device, run **hdc shell**. If you are testing multiple devices, run **hdc -t sn shell**, where **sn** indicates the device ID, which can be obtained by running **hdc list targets**.

2. Run the random test command. An example command is as follows:
  ```
   # wukong exec -s 10 -i 1000 -a 0.28 -t 0.72 -c 100
  ```
  The parameters in the command are described as follows.
  | Command          | Value          | Description                                          |
  | -------------- | -------------- | ---------------------------------------------- |
  | wukong exec | -           | Works as the main command.                            |
  | -s     | 10           | Sets the random seed. The value 10 is the seed value.           |
  | -i  | 1000           | Sets the application startup interval to 1000 ms.|
  | -a  | 0.28          | Sets the proportion of the random application startup test to 28%.         |
  | -t  | 0.72           | Sets the proportion of the random touch test to 72%.   |
  | -c  | 100           | Sets the number of execution times to 100.               |

## Special Testing

1. Open the shell.<br>If you are testing one device, run **hdc shell**. If you are testing multiple devices, run **hdc -t sn shell**, where **sn** indicates the device ID, which can be obtained by running **hdc list targets**.
2. Run the special test command. An example command is as follows:

  ```bash
   # wukong special -C [bundlename] -p
  ```
 The parameters in the command are described as follows.
 | Command          | Value          | Description                                          |
 | -------------- |-------------- | ---------------------------------------------- |
 | wukong special | -  | Works as the main command.                            |
 | -C [bundlename]    |[bundlename] | Sets the bundle name of the application for the sequential traversal test.           |
 | -p | p  | Indicates a screenshot.                            |

## Viewing the Test Result

**Test Result Output Path**

After the test commands are executed, the test result is automatically generated. You can obtain the test result in the following directory:
- For IDE versions earlier than September 22, 2022: /data/local/wukong/report/xxxxxxxx_xxxxxx/
- For IDE versions later than September 22, 2022: /data/local/tmp/wukong/report/xxxxxxxx_xxxxxx/

**Test Report Directories**

| Type                                | Description              |
| ------------------------------------ | ------------------ |
| exception/                           | Stores exception files generated during the test.|
| screenshot/                          | Stores screenshots of the sequential traversal test. |
| wukong_report.csv                    | Stores the test report summary.      |

**Execution Log**

You can view the wukong execution log in the path below:
```
 reports/xxxxxxxx_xxxxxx/wukong.log
```
