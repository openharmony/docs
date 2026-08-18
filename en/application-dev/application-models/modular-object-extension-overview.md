# Modular Object Model Overview (C/C++)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @yzkp-->
<!--Designer: @yzkp-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=7b06673b258deafa961ffd39d2e26b733c97c0b3 translatedAt=2026-08-18T01:32:05.899Z pushedAt=2026-08-18T09:08:01.232Z -->

A modular object is a cross-app capability exposure mechanism. An app encapsulates specific functions into an independent functional module through the ModularObjectExtensionAbility component (for the related C API definitions, see [modular_object_extension_ability.h](../reference/apis-ability-kit/capi-modular-object-extension-ability-h.md)) and exposes a Proxy object externally. After other applications obtain the Proxy object, they can invoke these capabilities across processes. For example, a document editing app can provide document processing capabilities, and other applications can invoke these capabilities to implement collaborative document editing; an email app can provide email sending capabilities, and other applications can invoke these capabilities to implement bulk email sending.

In development based on ModularObjectExtensionAbility, you can use the [Taihe](ability-terminology.md#taihe) tool to automatically generate Proxy/Stub code and type library metadata based on interface definitions, shielding the underlying IPC details. The client can also dynamically query and invoke remote interfaces at runtime through ModularObjectDispatcher.

## Basic Concepts

- Server: The app that provides the ModularObjectExtensionAbility component is called the server.

- Client: The app that connects to and invokes the ModularObjectExtensionAbility component is called the client.

- Stub object: an object created by the server, used to receive and process IPC requests sent by the client, as well as the business capability implementation.

- Proxy object: an object held by the client, used to send IPC requests to the server. The client obtains this object by connecting to the ModularObjectExtensionAbility component.

## Working Principles

1. The client connects to the server: The client initiates a connection request through the Connect API, specifying the bundleName, moduleName, and abilityName of the target ModularObjectExtensionAbility. Each connection creates a new ModularObjectExtensionAbility instance on the server.

2. The server returns a Proxy object: After the connection is established, the system loads the .so library of the corresponding Ability on the server and calls the OnNativeExtensionCreate entry function. Then the system triggers the OnCreateFunc and OnConnectFunc callbacks of the server in sequence. The developer returns a Stub object in the OnConnectFunc callback. The system converts the Stub into a Proxy object and returns it to the client.

3. The client communicates with the server through the Proxy: After receiving the Proxy object returned by the server in the OnConnectCallback callback, the client communicates with the server through this object. When communication is no longer needed, the client can disconnect through the Disconnect API. After the connection is disconnected, the system triggers the OnDisconnectFunc and OnDestroyFunc callbacks of the server in sequence.


The following table lists the mapping between the abbreviations and full API names involved in the preceding steps.

| abbreviation | Full API Name |
|---------|-------------|
| Connect | [OH_AbilityRuntime_ConnectModularObjectExtensionAbility](../reference/apis-ability-kit/capi-modular-object-extension-manager-h.md#oh_abilityruntime_connectmodularobjectextensionability) |
| Disconnect | [OH_AbilityRuntime_DisconnectModularObjectExtensionAbility](../reference/apis-ability-kit/capi-modular-object-extension-manager-h.md#oh_abilityruntime_disconnectmodularobjectextensionability) |
| OnNativeExtensionCreate | [OH_AbilityRuntime_OnNativeExtensionCreate](../reference/apis-ability-kit/capi-extension-ability-h.md#oh_abilityruntime_onnativeextensioncreate) |
| OnCreateFunc | [OH_AbilityRuntime_ModObjExtensionAbility_OnCreateFunc](../reference/apis-ability-kit/capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_oncreatefunc) |
| OnConnectFunc | [OH_AbilityRuntime_ModObjExtensionAbility_OnConnectFunc](../reference/apis-ability-kit/capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_onconnectfunc) |
| OnDisconnectFunc | [OH_AbilityRuntime_ModObjExtensionAbility_OnDisconnectFunc](../reference/apis-ability-kit/capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_ondisconnectfunc) |
| OnDestroyFunc | [OH_AbilityRuntime_ModObjExtensionAbility_OnDestroyFunc](../reference/apis-ability-kit/capi-modular-object-extension-ability-h.md#oh_abilityruntime_modobjextensionability_ondestroyfunc) |
| OnConnectCallback | [OH_AbilityRuntime_ConnectOptions_OnConnectCallback](../reference/apis-ability-kit/capi-connect-options-h.md#oh_abilityruntime_connectoptions_onconnectcallback) |
| Proxy | [OHIPCRemoteProxy](../reference/apis-ipc-kit/capi-ohipcparcel-ohipcremoteproxy.md) |
| Stub | [OHIPCRemoteStub](../reference/apis-ipc-kit/capi-ohipcparcel-ohipcremotestub.md) |