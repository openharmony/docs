# QoS Development

## **Scenario**

In a multi-processor or multi-tasking OS, resources such as CPUs and memory are shared among processes or tasks. Proper scheduling ensures fair distribution of resources, fast system response, and optimal resource utilization. Prioritizing tasks of applications based on their importance can help the system better schedule tasks. This topic describes how to use the QoS feature and related APIs to adjust the running time of tasks in the OpenHarmony system.

You can customize the attributes for priority-based task scheduling based on the QoS feature.

## Basic Concepts

### QoS

In OpenHarmony, the quality-of-service (QoS) feature allows critical tasks to receive necessary resources to meet performance requirements. You can prioritize tasks with different QoS levels based on their importance. The system then arranges the running time and sequence of each task based on their QoS level
. For example, when multiple tasks need to be executed in the system, the tasks with less interaction with users, such as the background download tasks, can be executed later than the tasks perceived by users, such as animation drawing.

### QoS Level
Currently, OpenHarmony provides six QoS levels in ascending order based on the degree of system-user interaction.

| QoS Level                                                      | Application Scenario                                                        | Load                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| QOS_BACKGROUND | Background tasks invisible to users, such as data synchronization and backup.| It takes several minutes or hours to complete the task.|
| QOS_UTILITY | Tasks that do not require immediate response, such as data download and import.| It takes several seconds or minutes to complete the task.|
| QOS_DEFAULT | Default level.| It takes a few seconds to complete the task.|
| QOS_USER_INITIATED | Tasks triggered by users with observable progress, for example, opening a file.| The task is completed in seconds.|
| QOS_DEADLINE_REQUEST | Tasks that require an immediate response, such as page loading.| The task is done immediately.|
| QOS_USER_INTERACTIVE	 | User interaction tasks (UI thread, interface refreshing, and animation).| The task is instant.|

The QoS level is specified by **QoS_level**, which is an enum defined as follows:
### QoS_Level Declaration
```{.c}
typedef enum QoS_Level {
    /**
     * QoS level for background tasks, such as data synchronization.
     */
    QOS_BACKGROUND,
    /**
     * QoS level for tasks that do not require immediate response, such as download.
     */
    QOS_UTILITY,
    /**
     * Default QoS level.
     */
    QOS_DEFAULT,
    /**
     * QoS level for tasks triggered by users with observable progress, such as opening a file.
     */
    QOS_USER_INITIATED,
    /**
     * QoS level for tasks that require immediate response, such as page loading.
     */
    QOS_DEADLINE_REQUEST,
    /**
     * QoS level for user interaction tasks, such as animation drawing.
     */
    QOS_USER_INTERACTIVE,
} QoS_Level;

```

## Effect
A task with a higher QoS level is allocated more CPU time than a task with a lower QoS level.

## Available APIs

| API                                                      | Description                                                        | Parameter                                                        | Return Value                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| OH_QoS_SetThreadQoS(QoS_Level level) | Set the QoS level for this task.| QoS_Level level | **0** or **–1**|
| OH_QoS_ResetThreadQoS() | Resets the QoS level for this task to default.| N/A| **0** or **–1**|
| OH_QoS_GetThreadQoS(QoS_Level *level) | Obtains the QoS level of this task.| QoS_Level *level | **0** or **–1**|

### Constraints
* The QoS APIs can be used only for the current task.

## Function Description

### OH_QoS_SetThreadQoS

#### Function
```{.c}
int OH_QoS_SetThreadQoS(QoS_Level level);
```

#### Parameters
QoS_Level level
* QoS level to set.

#### Return Value
* Returns **0** if the operation is successful; returns **-1** otherwise.

#### Description
Sets the QoS level for this task.

#### Example
```
#include "qos/qos.h"

int main()
{
    // Set the QoS level of this task to QOS_USER_INITIATED.
    int ret = OH_QoS_SetThreadQoS(QoS_Level::QOS_USER_INITIATED);
    
    if (!ret) { // If ret is 0, the operation is successful.
        printf("set QoS Success.");
    } else { // If ret is not 0, the operation fails.
        printf("set QoS failed.");
    }

    return 0;
}
```

### OH_QoS_ResetThreadQoS

#### Function
```{.c}
int OH_QoS_ResetThreadQoS();
```

#### Parameters
* N/A.

#### Return Value
* Returns **0** if the operation is successful; returns **-1** otherwise.

#### Description
Resets the QoS level of this task to the default level **QOS_DEFAULT**.

#### Example
```
#include "qos/qos.h"

int main()
{
    // Reset the QoS level of this task.
    int ret = OH_QoS_ResetThreadQoS();
    
    if (!ret) { // If ret is 0, the operation is successful.
        printf("reset QoS Success.");
    } else { // If ret is not 0, the operation fails.
        printf("reset QoS failed.");
    }

    return 0;
}
```

### OH_QoS_GetThreadQoS

#### Function
```{.c}
int OH_QoS_GetThreadQoS(QoS_Level *level);
```

#### Parameters
QoS_Level *level
* QoS level set for a task.

#### Return Value
* Returns **0** if the operation is successful; returns **-1** otherwise.

#### Description
Obtains the latest QoS level of this task. If no QoS level is set, **-1** is returned.

#### Example
```
#include "qos/qos.h"

int main()
{
    // Obtain the QoS level of this task.
    QoS_Level level = QoS_Level::QOS_DEFAULT;
    int ret = OH_QoS_GetThreadQoS(&level);

    if (!ret) { // If ret is 0, the operation is successful.
        printf("get QoS level %d Success.", level);
    } else { // If ret is not 0, the operation fails.
        printf("get QoS level failed.");
    }

    return 0;
}
```

## How to Develop
The following walks you through on how to query and modify the QoS level of a task using Node-API interfaces.

**Adding the Dynamic Link Library**

Add the following library to **CMakeLists.txt**.
```txt
libqos.so
```

#### Example
```txt
# the minimum version of CMake.
cmake_minimum_required(VERSION 3.4.1)
project(qos)

set(NATIVERENDER_ROOT_PATH ${CMAKE_CURRENT_SOURCE_DIR})

include_directories(${NATIVERENDER_ROOT_PATH}
                    ${NATIVERENDER_ROOT_PATH}/include)

add_library(entry SHARED hello.cpp)
target_link_libraries(entry PUBLIC libqos.so)
```

**Including the Header File**
```c
#include "qos/qos.h"
```
**Calling QoS APIs**

Use **OHQoSSetThreadQoS()** to set the QoS level for a task, use **OHQoSGetThreadQoS()** to obtain the QoS level set, and use **OHQoSResetThreadQoS()** to reset the QoS level to default.	
