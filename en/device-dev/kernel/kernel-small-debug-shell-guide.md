# Shell Command Development

You can perform the following operations to add shell commands:

1. Include header files.

   
   ```
   #include "shell.h"
   #include "shcmd.h"
   ```

2. Register commands. 

   You can register commands either statically or dynamically (with the system running). Generally, common system commands are registered statically, and user commands are registered dynamically.

   - Static registration

     1. Register a command using a macro.

        The prototype of the macro is as follows:

        ```
        SHELLCMD_ENTRY(l, cmdType, cmdKey, paraNum, cmdHook)
        ```

          **Table 1** SHELLCMD_ENTRY parameters

        | Parameter| Description|
        | -------- | -------- |
        | l | Specifies the global variable name passed in static registration. Note that the name cannot be the same as other symbol names in the system.|
        | cmdType | Specifies the command type, which can be any of the following:<br>**CMD_TYPE_EX**: does not support standard command parameters and will mask the command keywords you entered. For example, if you enter **ls /ramfs**, only **/ramfs** will be passed to the registration function and **ls** will be masked.<br>**CMD_TYPE_STD**: supports standard command parameters. All the characters you entered will be passed to the registration function after being parsed. |
        | cmdKey | Specifies the command keyword, which is the name used to access a shell function.|
        | paraNum | Specifies the maximum number of input parameters in the execution function to be called. This parameter is not supported currently.|
        | cmdHook | Specifies the address of the execution function, that is, the function executed by the command.|

        Example:
     
           ```
         SHELLCMD_ENTRY(ls_shellcmd,  CMD_TYPE_EX, "ls", XARGS,  (CMD_CBK_FUNC)osShellCmdLs)
           ```

     
     2. Add options to the **build/mk/liteos_tables_ldflags.mk** file.     
     
        For example, when registering the **ls** command, add **-uls_shellcmd** to the **build/mk/liteos_tables_ldflags.mk** file. **-u** is followed by the first parameter of **SHELLCMD_ENTRY**.

   - Dynamic registration
     
	 The prototype of the function to register is as follows:
	 
	 ```
     UINT32 osCmdReg(CmdT ype cmdType, CHAR *cmdKey, UINT32 paraNum, CmdCallBackFunc cmdProc)
     ```
	 **Table 2** UINT32 osCmdReg parameters
	 | Parameter| Description|
	 | -------- | -------- |
	 | cmdType | Specifies the command type, which can be any of the following:<br>**CMD_TYPE_EX**: does not support standard command parameters and will mask the command keywords you entered. For example, if you enter **ls /ramfs**, only **/ramfs** will be passed to the registration function, and **ls** will be masked.<br>**CMD_TYPE_STD**: supports standard command parameters. All the characters you entered will be passed to the registration function after being parsed.|
	 | cmdKey | Specifies the command keyword, which is the name used to access a shell function.|
	 | paraNum | Specifies the maximum number of input parameters in the execution function to be called. This parameter is not supported currently. The default value is **XARGS(0xFFFFFFFF)**.|
	 | cmdHook | Specifies the address of the execution function, that is, the function executed by the command.|
	 
	 Example:
	 ```
     osCmdReg(CMD_TYPE_EX, "ls", XARGS,  (CMD_CBK_FUNC)osShellCmdLs)
     ```
	 ![icon-note.gif](../public_sys-resources/icon-note.gif) NOTE<br>
	 > The command keyword must be unique. That is, two different commands cannot share the same command keyword. Otherwise, only one command is executed. When executing user commands sharing the same keyword, the shell executes only the first command in the **help** commands.


3. Use the following function prototype to add built-in commands:

   ```
   UINT32 osShellCmdLs(UINT32 argc,  CHAR **argv)
   ```

    **Table 3** osShellCmdLs parameters
   
   | Parameter| Description|
   | -------- | -------- |
   | argc | Specifies the number of parameters in the shell command.|
   | argv | Specifies a pointer array, where each element points to a string. You can determine whether to pass the command keyword to the registration function by specifying the command type.|

4. Enter the shell command in either of the following methods:

   - Enter the shell command using a serial port tool.
   - Enter the shell command using the Telnet tool. For details about how to use Telnet, see [telnet](../kernel/kernel-small-debug-shell-net-telnet.md).
