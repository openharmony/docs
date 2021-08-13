# Basic Concepts<a name="EN-US_TOPIC_0000001078716892"></a>

An interrupt is a signal to the processor emitted by hardware or software indicating an event that needs immediate attention. An interrupt alerts the processor to a high-priority condition requiring the interruption of the current code being executed by the processor. When a hardware interrupt is triggered, the interrupt handler is located based on the interrupt ID and then executed to handle the interrupt.

By using the interrupt mechanism, the CPU responds to the interrupt request from a peripheral only when required, and execute other tasks when the peripherals do not require the CPU. In this way, the CPU does not need to spend a lot of time in waiting and querying the peripheral status, which effectively improves the real-time performance and execution efficiency of the system.

The following describes the concepts related to interrupts:

-   Interrupt ID

    Identifies an interrupt request signal. The computer locates the device that sends the interrupt request based on the interrupt ID.

-   Interrupt request

    A process in which an electrical pulse signal is sent to the CPU, alerting the CPU to a high-priority event requiring the interruption of the current code being executed by the CPU.

-   Interrupt priority

    Prioritizes the sources that trigger interrupts based on the importance and urgency of interrupt events, so that the CPU can respond to and handle all interrupts in a timely manner.

-   Interrupt handler

    A program executed by the CPU to respond to the interrupt request from a peripheral. Each device that triggers an interrupt has its own interrupt handler.

-   Interrupt triggering

    The interrupt source sends an interrupt signal to the interrupt controller. The interrupt controller arbitrates all pending interrupts, determines the priority, and sends the interrupt signal to the CPU. When an interrupt source generates an interrupt signal, the interrupt trigger is set to  **1**, alerting the CPU to respond to the interrupt.

-   Interrupt vector

    Entry address of an interrupt handler.

-   Interrupt vector table

    An area for storing interrupt vectors. It stores the mapping between interrupt vectors and interrupt IDs.


