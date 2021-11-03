# Overview Template

## Basic Concepts

***[Writing Requirements]***

*Mandatory. Describe basic concepts related to a development task to help developers better understand the task. The table below describes the writing requirements. After finishing the writing, check your content against these requirements one by one.*  

| Requirement| Satisfied or Not|
| -------- | -------- |
| Common concepts in the industry are not described.|  |
| Common terms in the industry, rather than internal terms, are used.|  |


***[Example]***


The XX system provides the audio module for your application to implement audio-related features, including audio playback, recording, and volume management.


It is considered good practice that you understand the following concepts before starting application development:


- Sampling
  Sampling is a process where analog signals are converted into digital signals that can be represented by 0101.

- Sampling rate
  Sampling rate is the number of samples extracted from a continuous signal per second to form a discrete signal. It is measured in Hz. Generally, human hearing range is from 20 Hz to 20 kHz. Common audio sampling rates include 8 kHz, 11.025 kHz, 22.05 kHz, 16 kHz, 37.8 kHz, 44.1 kHz, 48 kHz, 96 kHz, and 192 kHz.

- Channel
  Channels refer to different spatial positions where independent audio signals are recorded or played. The number of channels is the number of audio sources used during audio recording, or the number of speakers used for audio playback.

- Audio frame
  Audio data is in stream form. For the convenience of audio algorithm processing and transmission, it is generally agreed that a data amount in a unit of 2.5 to 60 milliseconds is one audio frame. This unit is called sampling time, and its length is specific to codecs and the application requirements.


## Working Principles

***[Writing Requirements]***

*Optional. You can delete this section if the working principles are simple and the basic concepts in the **Overview** section are enough for understanding.*  

*Describe the implementation principles, for example, the time for calling the APIs and triggering callbacks related to key steps, to help developers better understand the basic operation principles, carry out development tasks, and locate problems.*  

*The table below describes the writing requirements. After finishing the writing, check your content against these requirements one by one.*  

| Requirement| Satisfied or Not|
| -------- | -------- |
| Only principles related to the development task are described.|  |
| Supplementary graphics are used, such as sequence diagrams and flowcharts. The text description is consistent with the figure description.|  |

***[Example 1]***

- Semaphore initialization: The system allocates memory for the semaphores configured (the value of *N* can be configured by users and is limited by the memory), initializes all semaphores to be unused semaphores, and adds them to a linked list for the system to use.

- Semaphore creation: The system obtains a semaphore from the linked list of unused semaphores and assigns an initial value to the semaphore.

- Semaphore request: If the counter value is greater than 0, the system allocates a semaphore, decreases the value by 1, and returns a success message. Otherwise, the system blocks the task and adds the task to the end of a task queue waiting for semaphores. The wait timeout period can be set.

- When a semaphore is released, if there is no task waiting for it, the counter is increased by 1. Otherwise, the first task in the wait queue is woken up.

- Semaphore deletion: The system sets a semaphore in use to the unused state and inserts it to the linked list of unused semaphores.

- Semaphore allows only a specified number of tasks to access a shared resource at a time. When the number of tasks accessing the resource reaches the limit, other tasks will be blocked until the semaphore is released.
  

***[Example 2]***

**Working Principles of Mutexes**

In a multi-task environment, multiple tasks may access the same shared resource. However, certain shared resources are not shared, and can only be accessed exclusively by tasks. A mutex can be used to address this issue.

When non-shared resources are accessed by a task, the mutex is locked. Other tasks will be blocked until the mutex is released by the task. The mutex allows only one task to access the shared resources at a time, ensuring integrity of operations on the shared resources.



## Limitations and Constraints

***[Writing Requirements]***

*Mandatory. Describe the constraints of the development task and the negative impact of the constraints, including but not limited to the following:*

- ***Function Limitations***
  - *Application scope of the function (specify scenarios that are not supported)*
  - *Specification limitations*

- ***Operation Limitations***

  - *Operations on known issues*
  - *Potentially risky operations (such as performance deterioration)*
  - *Operations that may cause performance deterioration*

*The table below describes the writing requirements. After finishing the writing, check your content against these requirements one by one.*

| Requirement| Satisfied or Not|
| -------- | -------- |
| The function limitations or operation restrictions are clearly specified.|  |
| Only constraints that affect task development or user experience are described.|  |
| Operations that are prone to errors are described in the procedure but not described in this section.|  |

***[Example]***

**Limitations and Constraints on Mutexes:**

- Two tasks cannot lock the same mutex. If a task attempts to lock a mutex held by another task, the task will be blocked until the mutex is unlocked.

- Mutexes cannot be used in the interrupt service program.

- When using the LiteOS-A kernel, the xx system must ensure real-time task scheduling and avoid long-time task blocking. Therefore, a mutex must be released as soon as possible.

- When a mutex is held by a task, the task priority cannot be changed by using APIs such as **LOS_TaskPriSet**.
