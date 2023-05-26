# Process Model Overview (FA Model)


The OpenHarmony process model is shown below.


- All PageAbility, ServiceAbility, DataAbility, and FormAbility components of an application (with the same bundle name) run in an independent process, which is **Main process** in green in the figure.

- WebView has an independent rendering process, which is **Render process** in yellow in the figure.

  **Figure 1** Process model 

  ![process-model-fa](figures/process-model-fa.png)


OpenHarmony provides two inter-process communication (IPC) mechanisms.


- [Common Events](common-event-fa.md): This mechanism is used in one-to-many communication scenarios. Multiple subscribers may receive events at the same time.

- [Background Services](rpc.md): This mechanism is implemented through [ServiceAbility](serviceability-overview.md).

