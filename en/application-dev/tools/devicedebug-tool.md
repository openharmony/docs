# devicedebug


devicedebug provides the capability of sending signals to applications for debugging purposes. Currently, signals can be sent only to processes of debuggable applications managed by AMS to terminate these processes.

> **NOTE**
>
> Before using this tool, you must obtain <!--Del-->[<!--DelEnd-->hdc<!--Del-->](../../device-dev/subsystems/subsys-toolchain-hdc-guide.md)<!--DelEnd--> and run the **hdc shell** command.

**Table 1** devicedebug commands

| Command| Description|
| -------- | -------- |
| help/-h | Displays the commands supported by the devicedebug tool.|
| kill | Kills a process with a specified PID.|


## Help Command
```bash
devicedebug help
```

**Table 2** Help command

| Command   | Description      |
| ------- | ---------- |
| devicedebug help | Displays the commands supported by devicedebug.|

Example:

```bash
# Display the help information.
devicedebug help
```


## Kill Command

```bash
devicedebug kill
```
Sends a signal carrying a PID to an application process. After receiving the signal, the application terminates the corresponding process.

**Table 3** Kill command parameters
  | Command| Description|
  | -------- |-------------------|
  | help/-h | Help information.|
  | -\<signal\> \<pid\> |  **signal** indicates the kill signal, which is used to kill a process with a specified PID. This field is mandatory.| 



Example:
  ```bash
  # Kill the 12111 process using signal 9.
  devicedebug kill -9 12111
  ```
