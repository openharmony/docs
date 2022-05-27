# Common Fault Locating Methods

## Locating the Fault Based on Exception Information<a name="section695838161711"></a>

When the system is suspended unexpectedly, information about key registers is displayed on the serial port, as shown in the following figure. The information can be used to locate the function where the exception occurs and the related call stack.

**Figure  1**  Exception information
![](figures/exception-information.png "exception-information")

The exception information in the preceding figure is described as follows:

①: indicates that the exception is in kernel mode.

②: indicates the exception type. The value of  **far**  is the address accessed by the CPU when the exception occurs.

③: The  **pc**  value indicates the location of the instruction being executed when the exception occurs. The  **klr**  value indicates the next instruction to be executed. \(Note: You do not need to pay attention to the value of  **klr**  if  **traceback 0 lr**  in ④ has a value.\)

④: The  **lr**  values indicate the locations of the instructions to be executed by the program counter in sequence in normal cases.

You also need to check the  **OHOS\_Image.asm**  file \(assembly file corresponding to the burnt system image  **OHOS\_Image.bin**\) in the  **out**  directory to determine the locations of the instructions corresponding to  **pc**  and  **lr**. Based on the locations of the instructions, determine the functions using the instructions and the functions where  **lr**s are located in sequence. In this way, you can obtain the function call relationships when the exception occurs.

## Checking Memory Pool Integrity

You may not directly locate the fault only with the exception information. Sometimes, the fault cannot be located due to incorrect register values. If you suspect that the fault is caused by heap memory overwriting, you can call  **LOS\_MemIntegrityCheck**  to check the memory pool integrity. The  **LOS\_MemIntegrityCheck**  function traverses all nodes in the dynamic memory pool of the system. If all nodes are normal, the function returns  **0**  and no information is printed. Otherwise, error information is printed. This function uses  **\(VOID \*\)OS\_SYS\_MEM\_ADDR**  as the input parameter.

Generally,  **LOS\_MemIntegrityCheck**  is called before and after the suspected service logic code to locate the heap memory overwriting. If the service code is correct,  **LOS\_MemIntegrityCheck**  can be called successfully. By doing this, you can improve the troubleshooting efficiency.

## Locating Memory Overwriting for a Global Variable

If the memory of a global variable is illegally accessed, locate the address of the global variable in the  **OHOS\_Image.map**  file and pay special attention to the variables recently used before the address. There is a high probability that memory overwriting occurs when the preceding variables \(especially variables of the array type or variables that are forcibly converted to other types\) are used.

