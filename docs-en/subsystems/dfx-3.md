# DFX<a name="EN-US_TOPIC_0000001062565873"></a>

The design for X \(DFX\) subsystem mainly includes design for reliability \(DFR\) and design for testability \(DFT\), providing code maintenance and testing.

As chip resources are limited and hardware platforms are diversified, component-based and customizable DFX frameworks are required for different hardware architectures and resources. DFX provides two types of lightweight frameworks, mini and featured, for hardware platforms powered by RISC-V, Cortex-M, and Cortex-A.

-   mini: This framework is intended for hardware platforms with Cortex-M or equivalent processing capabilities. Specifically, the system memory is generally less than 512 KB, and there is only one lightweight file system that can be used in limited scenarios, or no file system at all. The mini framework complies with the Cortex Microcontroller Software Interface Standard \(CMSIS\). Related APIs are called to record logs about user tasks in buffers, and logging APIs are then asynchronously called to print the logs, as illustrated in the following figure.

**Figure  1**  mini framework architecture<a name="fig470284245214"></a>  


![](figures/en-us_image_0000001064795436.png)

-   featured: This framework is intended for hardware platforms with Cortex-A or equivalent processing capabilities. Specifically, the system memory is generally greater than 512 KB, and there is a comprehensive file system for storing a large amount of data. The featured framework complies with the Portable Operating System Interface \(POSIX\) specifications.

    **Figure  2**  featured framework architecture<a name="fig1073631233910"></a>  
    

    ![](figures/en-us_image_0000001064187438.png)

    As shown in the figure, logs about the user-space processes or kernel tasks are written into the hilogtask and then stored in the ringbuffer. The user-space hilogcat and apphilogcat processes then output logs to the serial port and performs flushing-to-flash.

    The details are as follows:

    1.  hilogtask: kernel task for logging
        -   This is a driver of the kernel. It is initialized during system startup.
        -   Kernel-space or user-space modules call the logging APIs to transfer the formatted log content to the hilogtask and store the content in a ringbuffer.

    2.  apphilogcat: stores logs in user space
        -   This is a user-space process. It reads the log content from the ringbuffer of the kernel and stores the content in the log file.

    3.  hilogcat: command line tool for viewing logs

        This tool reads the log content in the ringbuffer via the kernel driver API, filters the content if required, and then outputs the content to  **stdout**.



