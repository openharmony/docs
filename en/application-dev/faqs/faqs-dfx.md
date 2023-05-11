# DFX Development

## How do I flush HiLog information to disks?

Applicable to: OpenHarmony 3.2 Beta (API version 9) 

**Symptom**

How do I flush HiLog information to disks?

**Solution**

Run the **hilog -w start -f ckTest -l 1M -n 5 -m zlib -j 11** command.

The log file is saved in the **/data/log/hilog/** directory.

Parameter description:

```
-**-w**: Starts a log flushing task. **start** means to start the task, and **stop** means to stop the task.
-**-f**: Sets the log file name.
-**-l**: Sets the size of a single log file. The unit can be B, KB, MB, or GB.
-**-n**: Sets the maximum number of log files. When the number of log files exceeds the specified value, the earliest log file will be overwritten. The value range is [2,1000].
-**-m**: Specifies the log file compression algorithm.
-**-j**: Specifies the task ID. The value ranges from **10** to **0xffffffffff**.
For more details about parameters, run the **hilog --help** command.
```
