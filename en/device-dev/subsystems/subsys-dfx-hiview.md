# Hiview Development


## Introduction


### Function Overview

Hiview is a module that provides toolkits for device maintenance across different platforms. It consists of the plugin management platform and the service plugins running on the platform. Hiview works in event-driven mode. The core of Hiview is a collection of HiSysEvent stubs distributed in the system. Formatted events are reported to Hiview through the HiSysEvent API for processing. The following figure shows the data interaction process.

**Figure 1** Data interaction between Hiview modules

![Hiview_module_data_interaction](figures/Hiview_module_data_interaction.png)

1. The service process calls the event logging API to report logged event information and writes the information to the node file.
2. SysEventSource of the Hiview process asynchronously reads event information from the node file and distributes the event to SysEventPipeline for processing.
   - The SysEventService plugin verifies events and flushes them to disks.
   - The Faultlogger plugin processes fault-related events.
   - The EventLogger plugin collects event-related log information.
3. On completion of event processing, SysEventPipeline sends the events to the event subscription queue and then dispatches the events to the subscription plugin for processing.
   - FreezeDetector processes screen freezing events.
   - HiCollieCollector processes suspension events.

### Basic Concepts

Before you get started, familiarize yourself with the following concepts:

- Plug-in

  An independent module running in the Hiview process. A plugin is delivered with the Hiview binary file to implement maintenance and fault management functions independently. Plug-ins can be disassembled independently during compilation, and can be hosted on the platform during running and dynamically configured.

- Pipeline

  An ordered set of event processing plugins. Events entering the pipeline are processed by plugins on the pipeline in sequence.

- Event source

  A special plugin that can produce events. Different from common plugins, a special plugin can be bound to a pipeline, and can produce events and distribute them to the pipeline.

- Pipeline group

  A group of pipelines configured on the same event source.

### Working Principles

Hiview supports plugin development on the plugin management platform and provides the required plugin development capabilities. You can add plugins to the Hiview platform to implement HiSysEvent event processing. Before you get started, you're expected to have a basic understanding of plugin working principles.

#### Plug-in Registration

A plugin can be registered in any of the following modes.

| Mode              | Description                                                        |
| ------------------ | ------------------------------------------------------------ |
| Static registration          | Use the **REGISTER(xxx);** macro to register the plugin. Such a plugin cannot be unloaded.|
| Proxy registration          | Use the **REGISTER_PROXY(xxx);** macro to register the plugin. Such a plugin is not loaded upon startup and can be loaded and unloaded dynamically during system running.|
| Proxy registration and loading upon startup| Use the **REGISTER_PROXY_WITH_LOADED(xxx);** macro to register the plugin. Such a plugin is loaded upon startup and can be unloaded and loaded dynamically during system running.|

####  Plug-in Event-Driven Modes

There are two event-driven modes available for plugins: pipeline-driven and subscription-driven. The differences are as follows:

- Pipeline-driven plugins need to be configured on the pipeline. After an event is distributed from an event source to the pipeline, the event traverses the plugins configured on the pipeline in sequence for processing.
- Subscription-driven plugins do not need to be configured on the pipeline. However, a listener needs to be registered with the Hiview platform upon plugin startup, and the plugin needs to implement the event listener function.

#### Plug-in Loading

Depending on your service demand, you can compile all or some plugins into the Hiview binary file.

Multiple plugins can be built into an independent plugin package and preset in the system as an independent **.so** file. One **.so** file corresponds to one **plugin_config** file. For example, **libxxx.z.so** corresponds to the** xxx_plugin_config** file. When the Hiview process starts, it scans for the plugin package (**.so** file) and the corresponding configuration file and loads the plugins in the plugin package.

The plugin package is described as follows:

1. The plugin package runs on the plugin management platform as an independent entity. The plugins, pipelines, or event sources in it provide the same functions as the plugins in the Hiview binary.

2. Plug-ins in the plugin package can be inserted into the Hiview binary pipeline.


3. Subscribers, wherever they are located, can receive events sent by the platform based on the subscription rules.


## Plug-in Development Guide


### When to Use

You can deploy a plugin on the Hiview platform if you want to perform specific service processing on the HiSysEvent events distributed from the event source. The following table describes the APIs used for plugin development.

### Available APIs

The following table lists the APIs related to plugin development. For details about the APIs, see the API Reference.

Table 1 Description of Plugin APIs

| API                                                      | Description                                                        |
| ------------------------------------------------------------ | ------------------------------------------------------------ |
| virtual void OnLoad()                                        | Loads plugins. After plugins are loaded, you can call this API to initialize data.|
| virtual void OnUnload()                                      | Unloads plugins. Before plugins are unloaded, you can call this API to reclaim data.  |
| virtual bool ReadyToLoad()                                   | Checks whether the current plugin can be loaded when the Hiview starts plugin loading.            |
| virtual bool OnEvent(std::shared_ptr\<Event\>& event)        | Implements event processing. You can call this API to receive events distributed by the pipeline or platform perform service processing.|
| virtual bool CanProcessEvent(std::shared_ptr\<Event\> event) | Checks whether an event can traverse backward throughout the entire pipeline. This function takes effect only when the plugin is the first one in the pipeline.|
| HiviewContext* GetHiviewContext()                            | Obtains the context of the Hiview plugin management platform.                          |

**Table 2** Description of Event APIs

| API                | Description                        |
| ---------------------- | ---------------------------- |
| domain_                | Event domain.                    |
| eventName_             | Event name.                    |
| happenTime_            | Time when an event occurs.                |
| jsonExtraInfo_         | Event data in JSON format.          |
| bool IsPipelineEvent() | Whether an event is a pipeline event.    |
| bool HasFinish()       | Whether an event can continue to traverse backward.|

### How to Develop

1. Define a service plugin class, namely, **PluginExample**, which inherits from the **Plugin** class.

   ```c++
   #include "event.h"
   #include "plugin.h"
   
   class PluginExample : public Plugin {
   public:
       bool OnEvent(std::shared_ptr<Event>& event) override;
       void OnLoad() override;
       void OnUnload() override;
   };
   ```

2. In the plugin class implementation code, register the plugin and overwrite the corresponding functions based on the service requirements.

   ```c++
   #include "plugin_factory.h"
   
   // Register the plugin in static registration mode.
   REGISTER(PluginExample);
   
   void PluginExample::OnLoad()
   {
       ... // Initialize plugin resources while the plugin is loaded.
       printf("PluginExample OnLoad \n");
   }
   
   void PluginExample::OnUnload()
   {
       ... // Release plugin resources while the plugin is unloaded.
       printf("PluginExample OnUnload \n");
   }
   
   bool PluginExample::OnEvent(std::shared_ptr<Event>& event)
   {
       ... // Perform specific service processing on the event using the event processing function.
       printf("PluginExample OnEvent \n");
   
       // If the plugin focuses only on events of a certain domain, log only the events of this domain.
       if (event->domain_ == "TEST_DOMAIN") {
           printf("The event data received is %s \n", event->jsonExtraInfo_);
           return true;
       }
   
       return false;
   }
   ```

3. Configure the plugin in the **plugin_build.json** file and compile the plugin with the Hiview binary file.

   ```json
   {
       "plugins": {
           "PluginExample": {
               "path": "plugins/PluginExample",
               "name": "PluginExample"
           }
       },
       "rules": [
           {
               "info": {
                   "loadorder": {
                       "PluginExample": {
                           "loadtime": 0
                       }
                   },
                   "pipelines": {
                       "SysEventPipeline": [
                          PluginExample
                       ]
                   }
               }
           }
       ]
   }
   ```


## Reference

For more information about the source code and usage of HiSysEvent, access the Hiview code repository(https://gitee.com/openharmony/hiviewdfx_hiview).
