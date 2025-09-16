# Introduction to Lancet Kit

Lancet Kit provides the event, log, and tracing analysis tools to help you check the running status of your application for further behavior, fault, security, and statistical analysis.

## Use Scenarios

- Application debugging: provides the HiLog function to help you record and obtain log information for fault analysis.
- Fault locating: provides log, event, and tracing information related to reliability, performance, power consumption, and distributed faults.
- Online monitoring: provides log, event, and tracing APIs to help you record and analyze the running status of your application.

## Available Capabilities

- HiLog: allows you to record and obtain logs.
- HiTraceMeter and HiTraceChain: provide performance tracing and cross-thread and cross-process distributed tracing capabilities.
- HiAppEvent: provides application event logging, which allows you to record fault, behavior, security, and statistical events, subscribe to system events, and set data processors for data upload.
- FaultLogger: manages fault logs and provides a channel for querying fault logs.
- HiDebug: allows you to obtain the usage of applications and system resources.

## Features

**Convenient APM System Setup**
  - Provides HiDebug, HiAppEvent, and HiLog APIs to build an APM SDK on the device side for interconnection with the APM developed by vendors.
  - Provides the functions of customizing application events and subscribing to system events so that you can quickly collect events required for O&M.

**Powerful Exception Handling Mechanism**
  - Provides simplified, standard, and complete exception logs to accurately record exception propagation paths.
  - Provides a comprehensive exception detection mechanism to detect exceptions in real time, notify the application of exceptions, and automatically restart the application.

**Comprehensive Basic Maintenance and Test Capabilities**
  - Classifies logs by level and category, with the support for multiple languages, privacy processing, and traffic control. 
  - Provides a complete event framework and mechanism for event logging, recording, and reporting. 
  - Traces process tracks for performance analysis.
