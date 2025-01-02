# HiAppEvent Data Processor Library


## Overview

HiAppEvent implements the logging function for OpenHarmony applications. The data processor library provides the event processing capability for HiAppEvent. It needs to be provided by the data processor during device development.

The following figure shows the service flowchart of the HiAppEvent data processor library.

  **Figure 1** Service flowchart of the HiAppEvent data processor library

  ![Service flowchart](../subsystems/figures/hiappevent_extend_so_stream.png)

## Usage Scenarios

After a data processor is added by using HiAppEvent APIs, an application event, once being submitted, will be distributed to the event handler. The event handler then performs proper processing, for example, reporting the event.

## Function Description

The HiAppEvent data processor library provides the event processing capability for the HiAppEvent event handler. Its functions are as follows:

- Initial registration: provides the service logic for initializing the `.so` file when the data processor library is loaded and registers the data processor with HiAppEvent. The following figure shows the initial registration flowchart.

  **Figure 2** Initial registration flowchart

  ![Initial registration](../subsystems/figures/hiappevent_extend_so_inited.png)


- Event reporting: provides APIs related to logging and reporting of application events. The following figure shows the event reporting flowchart.

  **Figure 3** Event reporting flowchart

  ![Event reporting](../subsystems/figures/hiappevent_extend_so_report.png)

- User ID verification: provides APIs for verifying user IDs. See Figure 4 for the user ID verification flowchart.

- User property verification: provides APIs for verifying user properties. See Figure 4 for the user property verification flowchart.

- Event verification: provides APIs for verifying application events. See Figure 4 for the event verification flowchart.

  **Figure 4** Data verification flowchart

  ![Data verification](../subsystems/figures/hiappevent_extend_so_verify.png)

## How to Develop

#### Available APIs

**Table 1** API called by the data processor library

| API                                                                                        | Description                        |
| ---------------------------------------------------------------------------------------------- | ---------------------------- |
| int RegisterProcessor(const std::string& name, std::shared_ptr\<AppEventProcessor\> processor) | Registers a data processor with HiAppEvent.|

**Table 1** APIs implemented by the data processor library

| API                                                                                                                                                                | Description              |
| ---------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ------------------ |
| int OnReport(int64_t processorSeq, const std::vector\<UserId\>& userIds, const std::vector\<UserProperty\>& userProperties, const std::vector\<AppEventInfo\>& events) | Reports events.        |
| int ValidateUserId(const UserId& userId)                                                                                                                               | Verifies user IDs.      |
| int ValidateUserProperty(const UserProperty& userProperty)                                                                                                             | Verifies user properties.|
| int ValidateEvent(const AppEventInfo& event)                                                                                                                           | Verifies events.       |

#### Development Procedure

1. Add the `.so` file initialization method to the `processor_init.cpp` file, and perform initial registration.

   ```c++
      #include "app_event_processor_mgr.h"

      using namespace OHOS::HiviewDFX::HiAppEvent;

      void __attribute__((constructor)) x_init(void)
      {
        ...
        int result = AppEventProcessorMgr::RegisterProcessor("processor_example", new ProcessorExample());
        printf("ProcessorExample OnReport\n");
      }
   ```

2. Define the `ProcessorExample` class, which is inherited from the base class `AppEventProcessor`, in the `processor_example.h` file.

   ```c++
      #include <vector>
      #include "app_event_processor.h"

      using namespace OHOS::HiviewDFX::HiAppEvent;

      class ProcessorExample : public AppEventProcessor {
      public:
          int OnReport(int64_t processorSeq, const std::vector<UserId>& userIds, const std::vector<UserProperty>& userProperties, const std::vector<AppEventInfo>& events) override;
          int ValidateUserId(const UserId& userId) override;
          int ValidateUserProperty(const UserProperty& userProperty) override;
          int ValidateEvent(const AppEventInfo& event) override;
      ...
      };
   ```

3. Implement the `ProcessorExample` class in the `processor_example.cpp` file, and override related functions based on the service logic.

   ```c++
    #include "processor_example.h"

    int ProcessorExample::OnReport(int64_t processorSeq, const std::vector<UserId>& userIds, const std::vector<UserProperty>& userProperties, const std::vector<AppEventInfo>& events)
    {
        ... // Enable specific event processing in the OnReport function.
        printf("ProcessorExample OnReport\n");
        return 0;
    }

    int ProcessorExample::ValidateUserId(const UserId& userId)
    {
        ... // Enable user ID verification in the ValidateUserId function.
        printf("ProcessorExample ValidateUserId\n");
        return 0;
    }

    int ProcessorExample::ValidateUserProperty(const UserProperty& userProperty)
    {
        ... // Enable user property verification in the ValidateUserProperty function.
        printf("ProcessorExample ValidateUserProperty\n");
        return 0;
    }

    int ProcessorExample::ValidateEvent(const AppEventInfo& event)
    {
        ... // Enable event verification in the ValidateEvent function.
        printf("ProcessorExample ValidateEvent\n");
        return 0;
    }
   ```

4. Configure the `ProcessorExample` class in the `build.gn` class file, and compile it with the data processor library.

   ```conf
    sources = [
      ... // Include the required source file.
      "./src/processor_init.cpp",
      "./src/processor_example.cpp",
    ]
    external_deps = [
      ... // Include the required external dependency library.
      "hiappevent:hiappevent_innerapi",
    ]
   ```

## References

For more information about the source code and usage of HiAppEvent, access the [HiAppEvent code repository](https://gitee.com/openharmony/hiviewdfx_hiappevent).
