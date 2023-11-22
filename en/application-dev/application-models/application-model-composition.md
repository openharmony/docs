# Elements of the Application Model


An application model is the abstraction of capabilities required by an application. It provides components and mechanisms required for running the application. You can develop applications based on a unified set of models, which makes your development simpler and more efficient.


The application model consists of the following elements:


- Application component
   
   An application component is the basic unit and entry for the running of an application. When a user starts, uses, or exits an application, the application component transits in different states. This is called the application component lifecycle. The application component provides lifecycle callbacks, through which you can detect application [status changes](uiability-lifecycle.md). When writing an application, you needs to compile application components and their lifecycle callbacks, and configure related information in the application configuration file. In this way, the operating system creates an application component instance based on the configuration file during running, and schedules the lifecycle callbacks to execute your code.
- Process model

   The process model defines how application processes are created, destroyed, and communicate with each other.

- Thread model

   The thread model defines how a thread in an application process is created and destroyed, how the main thread and UI thread are created, and how the threads communicate with each other.

- Mission Management Model (for System Applications Only)

   The mission management model defines how a mission is created and destroyed, and the relationship between missions and application components. A mission is a record about the use of an application component instance. Each time a user starts an application component instance, a mission is generated. For example, when a user starts a video application, the video application mission is displayed on the **Recents** page. When the user clicks the mission, the system switches the mission to the foreground. If the video editing feature in the video application is coded based on an application component, an application component instance for video editing is created when the user starts video editing. In this case, both the video application mission and video editing mission are displayed on **Recents**.

- Configuration file

   The configuration file contains information about the application's configuration, components, and permissions, as well as custom information. The information will be provided for the compiler, application market, and operating system in the build, distribution, and running phases.
