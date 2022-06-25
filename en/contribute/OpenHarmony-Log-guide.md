# Logging Guide

## Introduction
In OpenHarmony, HiLog is used to export logs to the log services. Logs record user operations and system running statuses. Logs are an important part of a system, and quality logs are a must for system development.

Logging has a significant negative impact on system performance. Therefore, it is necessary to make logging reasonably simple. Do not log unnecessary information to overwhelm developers.

## Log Level

- **[Rule] Use the appropriate log level based on actual conditions.**

**Note:** The log level must match the log content. The following log levels are available:

FATAL: indicates that a program or functionality is about to crash and the fault cannot be rectified.

ERROR: indicates a program or functional error that affects the normal running or use of the functionality and can be fixed at a high cost, for example, by resetting data.

WARN: indicates a severe, unexpected fault that has little impact on users and can be rectified by the programs themselves or through simple operations.

INFO: used to record key service process nodes and exceptions (for example, no network signal or login failure) that occur during service running. These logs should be recorded by the dominant module in the service to avoid repeated logging conducted by multiple invoked modules or low-level functions.

DEBUG: used to record more detailed process information than INFO logs to help developers analyze service processes and locate faults. DEBUG logs are not recorded in official versions by default. They are available in debug versions or in official versions with the debug function enabled.

## Log Content

- **[Rule] Describe the log content in fluent English (grammatically correct and clear description with no typos).**

**Note:** The log content must be clear and concise so that developers can know what happened by reading the log, instead of analyzing the related code. A syntax- and semantics-compliant log also helps the log analysis tool automatically parse the log. Example:

A log recording "1234" is meaningless to anyone except the coder themselves.

A log recording "Error happened" does not indicate where the error occurred or the cause of the error. Such a log is not helpful for fault locating.

- **[Rule] Do not log privacy information.**

**Note:** Privacy information, such as hardware serial numbers, personal accounts, passwords, and identities, should not be logged. The scope of the privacy information complies with national and regional policies.

- **[Rule] Do not log service-irrelevant information.**

**Note:** Do not log any information irrelevant to the service code, such as the issue number, requirement number, department name, developer name, employee ID, name abbreviation, weather, and mood.

- **[Rule] Do not log repeated information.**

**Note:** Do not print logs with the same content in different places. It would hinder developers in locating the code during fault locating.

- **[Rule] Do not call service interface functions in logs.**

**Note:** Logging should not affect the normal service process. Generally, the impact of log code on the service logic is ignored during fault locating or code walk-through.

- **[Rule] Do not commit logs used during development and debugging to the code repository.**

**Note:** To speed up fault locating, you may print a line of logs for each step in the code or print various variables (which may include privacy information).
You must delete these code lines before committing the final code to the code repository.

- **[Recommendation] Display the log content in one line.**

**Note:** A line usually contains about 100 characters. Try your best not to include more than 160 characters in a log.

## When to Print

- **[Rule] Do not print logs in the normal process of high-frequency code.**

**Note:** Do not print logs for frequently called interface functions in big data processing, high-frequency software and hardware interrupt processing, protocol data stream processing, multimedia audio and video stream processing, display screen refresh processing, and other scenarios where the code keeps running as long as the system does not sleep. However, you can print logs in their error branches. Logs added during development and debugging must be cleared or disabled when code is committed to the code repository.

- **[Rule] Restrict the logging frequency for logs that may be recorded repeatedly.**

**Note:** If it is proved that some log records may occur multiple times, you are advised to restrict the logging frequency to avoid a large number of log copies with identical (or very similar) information.

- **[Rule] Print logs for events that are unlikely to happen.**

**Note:** According to Murphy's Law, anything that can go wrong will go wrong. Always print logs for points that are unlikely to happen.

- **[Recommendation] Generate log strings during logging.**

**Note:** Log strings should be generated as late as possible, best at the time when the log is printed. In this way, the strings will not be generated when the log function is disabled, therefore minimizing the system overhead.

## Log Format


- **[Rule] Log events in the who-does-what format.**

- **[Rule] Log status changes in the format of state\_name:s1-&gt;s2, reason:msg.**

- **[Rule] Log parameter values in the format of name1=value1, name2=value2...**.

- **[Rule] Log successful code execution using the statement "xxx successful".**

- **[Rule] Log code execution failures using the statement "xxx failed. Please xxx." Include possible solutions in the logs.**

  Example: "Connection to the server failed. Please check network configuration."

## Guide for Printing Common Logs

### Process Logs


- **[Recommendation] Log key service process nodes, including the service start point, key condition branch, error processing point, and service end point.**

###  Database Logs

- **[Recommendation] Log database operations and related information.**

**Note:** Common database operations include
Create, Read, Update, Delete (CRUD). The initiator, type, and result (successful or failed) of each operation should be logged. However, the detailed content of the operation and operation result should not be logged to prevent user privacy leakage. The number of returned results can be logged.

- **[Recommendation] Record the operation duration in database operation logs for performance-sensitive services.**

**Note:** For performance-sensitive services, database operations (including reading and writing data) are key performance nodes, and the operation duration should be logged and used as a reference for performance profiling.

- **[Recommendation] Log database job information.**

**Note:** Log the job name, execution content, start time, end time, and execution result.

###  File Logs
- **[Recommendation] Log operations on files and related information.**

**Note:** Common file operations include creating, opening, reading, writing, closing, and deleting files as well as obtaining file attributes. The initiator, type, and result of each operation should be logged. However, the file content should not be logged to prevent user privacy leakage or system vulnerability exposure. The system file name and file handle value can be logged, but the user file name should not.

- **[Recommendation] Print only one log for batch file operations.**

**Note:** For example, if files are deleted in batches, do not record a log for each file deletion. Instead, log the number of deleted files. If the directory where a deleted file is located is created by the system, log the directory name as well.

###  Key Object/Object Pool Logs

**Note:** A key object/object pool may be a class or struct, a queue or stack data structure, or a simple variable of the primitive data type. It plays a key role in the system and is used for system scheduling control, status recording, and information transfer.

- **[Recommendation] Log the operations, results, and status changes of key objects.**

**Note:** Object operations include creating, loading, unloading, and releasing objects. For key object operations, log the operation subject, type, and result. For status operations, log the values before and after the status change.

###  Thread Logs

- **[Recommendation] Log thread operations and related information.**

**Note:** Thread operations include creating, starting, pausing, and terminating threads. Record the operation type, operation result, thread number, and thread name in the log. (A thread name must be set for important threads.)

- **[Recommendation] Logs must be recorded when a thread enters an infinite loop or deadlock.**

**Note:** A mechanism must be provided for detecting deadlocks or infinite loops that occur in threads with logic such as lock waiting, asynchronous processing, and cyclic processing, and logs must be recorded when an error occurs.

- **[Recommendation] Log message processing information for message processing threads.**

**Note:** Log the information such as the message name, processing result, and processing duration. For high-frequency messages, you can record logs only when an error occurs during message processing.

###  Concurrency Control Logs

**Note:** Concurrency control objects may be locks, critical sections, and semaphores.

- **[Recommendation] Log operations on concurrency control objects and related information.**

**Note:** Concurrency control operations include creating, occupying, releasing, and waiting. Log information such as the operation type, operation object name, operation result, and operation location.

###  Shared Memory Logs

**Note:** Shared memory is a common inter-process communication method in software systems. It is used to share or transfer data between modules. The data stored in the shared memory may be configuration data, database data, and the like.

- **[Recommendation] Log operations on the shared memory and related information.**

**Note:** The operations on the shared memory include creating, deleting, setting, querying, and destroying data. Log the operator, operation type, and operation result.

###  Interface Interaction Logs


There are internal and external system interfaces. Internal interfaces refer to the interfaces between subsystems and modules within the system. These interfaces include inter-module message sending interfaces, IPC interfaces, and RPC interfaces.

- **[Recommendation] Record interface interaction information.**

**Note:** Interface interaction information includes the interface caller, message content, processing result, and return value. User privacy information must be excluded from the message content and return value.

### State Machine Logs

- **[Recommendation] Log state machine operations and state change information.**

**Note:** The operations on a state machine include creating, starting, ending, and destroying the state machine as well as changing its state. The state machine is usually driven by external conditions (such as messages and resources). State change information must be logged, such as the state names before and after the state change and the external conditions that cause the change.

###  Other OS Resources
The other OS resources refer to resources that are not mentioned in the preceding sections, such as sockets and timers. OS resources such as files and threads are mentioned before and are not covered in this part.

- **[Recommendation] Log the process and result of socket connection establishment, connection maintenance, disconnection, and causes.**

- **[Recommendation] Log the timer startup, reset, destruction, and timeout processes.**

- **[Recommendation] Comply with the preceding logging principles when using other similar OS resources.**

## HiLog API Usage Specifications


- **[Rule] Each service domain must have an independent domain ID.**

**Note:** Before using the HiLog API to print logs, every service domain must apply for a domain ID from the DFX. The domain ID is used to measure and control the quality of a single service log. You can use the domain ID to filter out your own service logs for analysis. Do not use domain IDs of others. For test code, use the domain ID 0xD000F00.

Range of the domain IDs: **0xD000001\-0xD0FFFFF**

- **[Recommendation] Use the domain ID allocated to your domain based on a certain layer and module granularity.**

**Note:** A domain ID is a 32-bit integer expressed in 16-bit format. The domain ID is the format of 0xD0xxxyy, where D0 is the domain ID, the most significant 12 bits of ***xxx*** are the value allocated by the DFX, and the least significant 8 bits of ***yy*** are for internal use in the service domain. Domain IDs allocated among your service domain must be able to locate your internal organizations or modules and reflect their log quality. The DFX conducts logging control based on the domain IDs to prevent the logging of a single module from affecting other modules in the same service domain. For example, the BT service domain is further divided as follows by module:
	

    APP       | BT-App1 BT-App2
    ---------------------------------------
    Framework | BT-Service1 BT-Service2
    ---------------------------------------
    HAL       | BT-HAL
    ---------------------------------------
    Kernel    | BT-Driver1  BT-Driver2

Therefore, domain IDs allocated to BT can be further divided as follows:
| Domain Name| Domain ID  |
|----|----|
| BT  | 0xD000100  |
| BT-App1  | 0xD000101  |
| BT-App2  | 0xD000102  |
| BT-Service1  | 0xD000103  |
| BT-Service2  | 0xD000104  |
| BT-HAL  | 0xD000105  |
| BT-Driver1  | 0xD000106  |
| BT-Driver2  | 0xD000107  |

- **[Rule] The log service controls the log traffic of each service. Changing the default traffic threshold must be approved by the DFX.**

**Note:** The default log traffic threshold of each domain ID is **10240 Bytes/s** . Any change to the default threshold must be approved by the DFX.

- **[Rule] Correctly set the log formatting privacy tags {public} and {private}**.

**Note:** Privacy parameter IDs {public} and {private} indicate whether the log content of each parameter contains sensitive privacy information. The HiLog API automatically outputs the content of the {public} parameter in plaintext and filters the content of the {private} parameter using &lt;private&gt;. Set privacy parameter IDs only after you analyze the log content. Example:

Source code:


    HiLog.info(LABEL, "Device Name:%{public}s, IP:%{private}s.", DeviceName, ip);


Log output:


    11-11 09:19:00.932 1513 1513 E 00500/Settings: MyPad001, IP:<private>
