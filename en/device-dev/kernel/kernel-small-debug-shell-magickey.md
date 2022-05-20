# Magic Key


## When to Use<a name="section2350114718546"></a>

When the system does not respond, you can use the magic key to check whether the system is locked and interrupted \(the magic key also does not respond\) or view the system task running status.

If an interrupt is responded, you can use the magic key to check the task CPU usage \(**cpup**\) and find out the task with the highest CPU usage. Generally, the task with a higher priority preempts the CPU resources.

## How to Use<a name="section3305151511559"></a>

1.  Configure the macro  **LOSCFG\_ENABLE\_MAGICKEY**.

The magic key depends on the  **LOSCFG\_ENABLE\_MAGICKEY**  macro. Before using the magic key, select  **Enable MAGIC KEY**  on  **menuconfig**.

**Enable MAGIC KEY**:  **Debug**  ---\>  **Enable MAGIC KEY**

The magic key cannot be used if this macro is disabled.

>![](../public_sys-resources/icon-note.gif) **NOTE:** 
>On  **menuconfig**, you can move the cursor to  **LOSCFG\_ENABLE\_MAGICKEY**  and type a question mark \(?\) to view help information.

2. Press  **Ctrl+R**  to enable the magic key.

When the UART or USB-to-virtual serial port is connected, press  **Ctrl+R**. If "Magic key on" is displayed, the magic key is enabled.

To disable the magic key, press  **Ctrl+R**  again. If "Magic key off" is displayed, the magic key is disabled.

You can use the magic key combinations as follows:

-   **Ctrl+Z**: displays help information about the related magic keys.

-   **Ctrl+T**: displays task information.

-   **Ctrl+P**: allows the system to proactively enter the panic state. After the panic-related information is printed, the system is suspended.

-   **Ctrl+E**: Checks the integrity of the memory pool. If an error is detected, the system displays an error message. If no error is detected, the system displays "system memcheck over, all passed!".


>![](../public_sys-resources/icon-notice.gif) **NOTICE:** 
>If magic key is enabled, when special characters need to be entered through the UART or USB-to-virtual serial port, avoid using characters the same as the magic keys. Otherwise, the magic key may be triggered by mistake, causing errors in the original design.

