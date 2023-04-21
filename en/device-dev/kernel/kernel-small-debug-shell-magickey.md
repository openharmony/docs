# Magic Key


## When to Use

When the system does not respond, you can use the magic key to check whether the system is suspended by an interrupt lock or view the system task running status.

If interrupts are responded, you can use the magic key to check the task CPU percent (CPUP) and locate the task with the highest CPUP. Generally, the task with a higher priority preempts the CPU resources.


## How to Configure

The magic key depends on the macro **LOSCFG_ENABLE_MAGICKEY**. 

To configure **LOSCFG_ENABLE_MAGICKEY**: 

1. Run the **make menuconfig** command in **kernel/liteos_a**. 
2. Locate the **Debug** option and select **Enable MAGIC KEY**.

This option is selected by default. If it is not selected, the magic key is invalid.

> **NOTE**<br>
> On **menuconfig**, you can move the cursor to **LOSCFG_ENABLE_MAGICKEY** and enter a question mark (?) to view help information.

## How to Use

1. Press **Ctrl+R** to enable the magic key.

   When the UART or USB-to-virtual serial port is connected, press **Ctrl+R**. If "Magic key on" is displayed, the magic key is enabled. To disable it, press **Ctrl+R** again. If "Magic key off" is displayed, the magic key is disabled.

   The functions of the magic key are as follows:

   - **Ctrl+Z**: displays help information about the related magic keys.

   - **Ctrl+T**: displays task information.

   - **Ctrl+P**: allows the system to proactively enter the panic state. After the panic-related information is printed, the system is suspended.

   - **Ctrl+E**: Checks the integrity of the memory pool. If an error is detected, the system displays an error message. If no error is detected, the system displays "system memcheck over, all passed!".
   
   > **NOTE**<br>
   > If magic key is enabled, when special characters need to be entered through the UART or USB-to-virtual serial port, avoid using characters the same as the magic keys. Otherwise, the magic key may be triggered by mistake, causing errors in design.
