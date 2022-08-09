# Shell


The shell provided by the OpenHarmony kernel supports commonly used debugging commands. You can also add and customize commands to the shell of the OpenHarmony kernel to address your service needs. The common debugging commands include the following:


- System commands: commands used to query information, such as system tasks, semaphores, system software timers, CPU usage, and interrupts.

- File commands: commands used to manage files and directories, such as **ls** and **cd**.

- Network commands: commands used to query the IP addresses of other devices connected to the development board, querying the IP address of the local device, testing network connectivity, and setting the access point (AP) and station (STA) modes of the development board.

  For details about the process of adding commands, see [Shell Command Development](../kernel/kernel-small-debug-shell-guide.md) and [Shell Command Programming Example](../kernel/kernel-small-debug-shell-build.md).


 **Precautions**

Note the following when using shell:

- You can use the **exec** command to run executable files.

- The shell supports English input by default. To delete the Chinese characters entered in UTF-8 format, press the backspace key for three times.

- When entering shell commands, file names, and directory names, you can press **Tab** to enable automatic completion. If there are multiple completions, multiple items are printed based on the same characters they have. If more than 24 lines of completions are available, the system displays the message "Display all num possibilities?(y/n)", asking you to determine whether to print all items. You can enter **y** to print all items or enter **n** to exit the printing. If more than 24 lines are printed after your selection, the system displays "--More--". In this case, you can press **Enter** to continue the printing or press **q** (or **Ctrl+c**) to exit.

- The shell working directory is separated from the system working directory. You can run commands such as **cd** and **pwd** on the shell to perform operations on the shell working directory, and run commands such as **chdir** and **getcwd** to perform operations on the system working directory. Pay special attention when an input parameter in a file system operation command is a relative path.

- Before using network shell commands, you need to call the **tcpip_init** function to initialize the network and set up the Telnet connection. By default, the kernel does not call **tcpip_init**.

- You are not advised to run shell commands to perform operations on device files in the **/dev** directory, which may cause unexpected results.

- The shell functions do not comply with the POSIX standards and are used only for debugging.
  > ![icon-notice.gif](public_sys-resources/icon-notice.gif) **NOTICE**<br>
  > The shell functions are used for debugging only and can be enabled only in the Debug version (by enabling  **LOSCFG_DEBUG_VERSION** using **menuconfig**).
