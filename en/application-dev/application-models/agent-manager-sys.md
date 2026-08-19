# Using the Agent Service Provided by the AgentExtensionAbility Component (System Applications Only)

<!--Kit: Ability Kit-->
<!--Subsystem: Ability-->
<!--Owner: @littlejerry1-->
<!--Designer: @ccllee1-->
<!--Tester: @liangchengguang-->
<!--Adviser: @HelloCrease-->
<!-- md-trans-meta sourceCommit=79e2b0709a488b07e5881d61578e00850aa4f234 translatedAt=2026-08-18T01:28:28.515Z pushedAt=2026-08-18T03:43:20.782Z -->

## Overview

Since API version 24, system apps can use the [connectAgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentManager-sys.md#agentmanagerconnectagentextensionability) method in agentManager to connect to the [AgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md) component implemented by another app and use the agent service it provides. System apps and agents can perform bidirectional communication and bidirectional security authentication.

> **NOTE**
>
> In this document, the connected [AgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md) is referred to as the server, and the component that connects to the [AgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md) is referred to as the client.

## Overview of Client-Server Interaction

The following figure shows the interaction process between the client and the server:


1. Establishing a connection

    The client can call the [connectAgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentManager-sys.md#agentmanagerconnectagentextensionability) method in agentManager to connect to the [AgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md) of the server (specify the target service to connect to in the [Want](../reference/apis-ability-kit/js-apis-app-ability-want.md) object).

    After the connection is successfully established, the [onConnect()](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md#onconnect) method of the server is triggered, in which the [Want](../reference/apis-ability-kit/js-apis-app-ability-want.md) object passed by the client and the client's [AgentHostProxy](../reference/apis-ability-kit/js-apis-inner-application-agentHostProxy.md) object are received.

2. Sending and Receiving Data

    The client calls the [connectAgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentManager-sys.md#agentmanagerconnectagentextensionability) method to connect to the server and receives the returned [AgentProxy](../reference/apis-ability-kit/js-apis-inner-application-agentProxy-sys.md) object. The client can use the [sendData()](../reference/apis-ability-kit/js-apis-inner-application-agentProxy-sys.md#senddata) method of the [AgentProxy](../reference/apis-ability-kit/js-apis-inner-application-agentProxy-sys.md) object to send data to the server.

    In the [onData()](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md#ondata) method, the server can receive the data sent by the client and the [AgentHostProxy](../reference/apis-ability-kit/js-apis-inner-application-agentHostProxy.md) object, and can send data to the client by calling the [sendData()](../reference/apis-ability-kit/js-apis-inner-application-agentHostProxy.md#senddata) method of [AgentHostProxy](../reference/apis-ability-kit/js-apis-inner-application-agentHostProxy.md).

    The client receives the data sent by the server through the [onData()](../reference/apis-ability-kit/js-apis-inner-application-agentExtensionConnectCallback-sys.md#ondata) method in [AgentExtensionConnectCallback](../reference/apis-ability-kit/js-apis-inner-application-agentExtensionConnectCallback-sys.md).

3. Security authentication (optional)

    The client connects to the server by calling [connectAgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentManager-sys.md#agentmanagerconnectagentextensionability) and receives the returned [AgentProxy](../reference/apis-ability-kit/js-apis-inner-application-agentProxy-sys.md) object. The client can use the [authorize()](../reference/apis-ability-kit/js-apis-inner-application-agentProxy-sys.md#authorize) method of the [AgentProxy](../reference/apis-ability-kit/js-apis-inner-application-agentProxy-sys.md) object to send a security authentication request to the server.

    In the [onAuth()](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md#onauth) method, the server can receive the security authentication request sent by the client and the [AgentHostProxy](../reference/apis-ability-kit/js-apis-inner-application-agentHostProxy.md) object, and can send a security authentication request to the client through the [authorize()](../reference/apis-ability-kit/js-apis-inner-application-agentHostProxy.md#authorize) method of [AgentHostProxy](../reference/apis-ability-kit/js-apis-inner-application-agentHostProxy.md).

    The client receives the security authentication request sent by the server through the [onAuth()](../reference/apis-ability-kit/js-apis-inner-application-agentExtensionConnectCallback-sys.md#onauth) method of [AgentExtensionConnectCallback](../reference/apis-ability-kit/js-apis-inner-application-agentExtensionConnectCallback-sys.md).

4. Disconnecting

    When the client calls the [connectAgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentManager-sys.md#agentmanagerconnectagentextensionability) method to connect to the server, it can save the [AgentProxy](../reference/apis-ability-kit/js-apis-inner-application-agentProxy-sys.md) object returned by the server. The client can call the [disconnectAgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentManager-sys.md#agentmanagerdisconnectagentextensionability) method to use the saved [AgentProxy](../reference/apis-ability-kit/js-apis-inner-application-agentProxy-sys.md) object to disconnect from the server.

## Connecting to and Disconnecting from AgentExtensionAbility

- Use [connectAgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentManager-sys.md#agentmanagerconnectagentextensionability) to establish a connection with [AgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md).

    <!-- @[agent_manager_one](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ConnectAgentExtension/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    import { common, Want, agentManager } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    @Entry
    @Component
    struct Index {
      comProxy: common.AgentProxy | null = null;
      connectCallback: common.AgentExtensionConnectCallback = {
        onData: (data: string) => {
          console.info(`onData, data: ${data}.`);
        },
        onAuth: (handShakeData: string): void => {
          console.info(`onData, data: ${handShakeData}.`);
        },
        onDisconnect: () => {
          console.info(`onDisconnect.`);
          this.comProxy = null;
        }
      }
    
      build() {
        Column() {
          Row() {
            // Create the connection button.
            Button('connect ability')
              .enabled(true)
              .onClick(() => {
                let connectWant: Want = {
                  bundleName: 'com.sample.agentextensionability',
                  abilityName: 'AgentExtAbility',
                };
                let agentId: string = 'weather_assistant_001';
                try {
                  // Connect to AgentExtensionAbility.
                  agentManager.connectAgentExtensionAbility(connectWant, agentId, this.connectCallback)
                    .then((proxy: common.AgentProxy) => {
                      this.comProxy = proxy;
                      // ...
                    })
                    .catch((err: BusinessError) => {
                      console.error(`connectAgentExtensionAbility failed, err code: ${err.code}, err msg: ${err.message}.`);
                    });
                } catch (err) {
                  let code = (err as BusinessError).code;
                  let msg = (err as BusinessError).message;
                  console.error(`connectAgentExtensionAbility failed, err code: ${code}, err msg: ${msg}.`);
                }
              })
            // ...
          }
        }
      }
    }
    ```

- Use [disconnectAgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentManager-sys.md#agentmanagerdisconnectagentextensionability) to disconnect from [AgentExtensionAbility](../reference/apis-ability-kit/js-apis-app-agent-agentExtensionAbility.md).

    <!-- @[agent_manager_two](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ConnectAgentExtension/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    import { common, Want, agentManager } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    @Entry
    @Component
    struct Index {
      comProxy: common.AgentProxy | null = null;
      connectCallback: common.AgentExtensionConnectCallback = {
        onData: (data: string) => {
          console.info(`onData, data: ${data}.`);
        },
        onAuth: (handShakeData: string): void => {
          console.info(`onData, data: ${handShakeData}.`);
        },
        onDisconnect: () => {
          console.info(`onDisconnect.`);
          this.comProxy = null;
        }
      }
    
      build() {
        Column() {
          Row() {
            // ...
            // Create the disconnect button.
            Button('disconnect ability')
              .enabled(true)
              .onClick(() => {
                try{
                  // this.agentProxy is the proxy object saved during connection.
                  agentManager.disconnectAgentExtensionAbility(this.comProxy).then(() => {
                    console.info(`disconnectAgentExtensionAbility success.`);
                  }).catch((error: BusinessError) => {
                    console.error(`disconnectAgentExtensionAbility failed, err code: ${error.code}, err msg: ${error.message}.`);
                  });
                } catch (err) {
                  let code = (err as BusinessError).code;
                  let msg = (err as BusinessError).message;
                  console.error(`connectAgentExtensionAbility failed, err code: ${code}, err msg: ${msg}.`);
                }
              })
          }
        }
      }
    }
    ```

## Two-Way Communication Between Client and Server

- Client sends and receives data

    <!-- @[agent_manager_three](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ConnectAgentExtension/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    import { common, Want, agentManager } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    @Entry
    @Component
    struct Index {
      comProxy: common.AgentProxy | null = null;
      connectCallback: common.AgentExtensionConnectCallback = {
        onData: (data: string) => {
          console.info(`onData, data: ${data}.`);
        },
        onAuth: (handShakeData: string): void => {
          console.info(`onData, data: ${handShakeData}.`);
        },
        onDisconnect: () => {
          console.info(`onDisconnect.`);
          this.comProxy = null;
        }
      }
    
      build() {
        Column() {
          Row() {
            // Create the connection button.
            Button('connect ability')
              .enabled(true)
              .onClick(() => {
                let connectWant: Want = {
                  bundleName: 'com.sample.agentextensionability',
                  abilityName: 'AgentExtAbility',
                };
                let agentId: string = 'weather_assistant_001';
                try {
                  // Connect to AgentExtensionAbility.
                  agentManager.connectAgentExtensionAbility(connectWant, agentId, this.connectCallback)
                    .then((proxy: common.AgentProxy) => {
                      this.comProxy = proxy;
                      let data = 'test data';
                      try {
                        this.comProxy.sendData(data);
                      } catch (err) {
                        let code = (err as BusinessError).code;
                        let msg = (err as BusinessError).message;
                        console.error(`sendData failed, err code: ${code}, err msg: ${msg}.`);
                      }
                      // ...
                    })
                    .catch((err: BusinessError) => {
                      console.error(`connectAgentExtensionAbility failed, err code: ${err.code}, err msg: ${err.message}.`);
                    });
                } catch (err) {
                  let code = (err as BusinessError).code;
                  let msg = (err as BusinessError).message;
                  console.error(`connectAgentExtensionAbility failed, err code: ${code}, err msg: ${msg}.`);
                }
              })
            // ...
          }
        }
      }
    }
    ```

- Server sends and receives data

  For details, see [Sending and Receiving Data Using the AgentExtensionAbility Component](agent-extension-ability.md#sending-and-receiving-data-using-the-agentextensionability-component).

## Two-Way Security Authentication Between Client and Server

- The client processes and sends security authentication requests

    <!-- @[agent_manager_four](https://gitcode.com/openharmony/applications_app_samples/blob/master/code/DocsSample/Ability/ConnectAgentExtension/entry/src/main/ets/pages/Index.ets) -->

    ``` TypeScript
    import { common, Want, agentManager } from '@kit.AbilityKit';
    import { BusinessError } from '@kit.BasicServicesKit';
    
    @Entry
    @Component
    struct Index {
      comProxy: common.AgentProxy | null = null;
      connectCallback: common.AgentExtensionConnectCallback = {
        onData: (data: string) => {
          console.info(`onData, data: ${data}.`);
        },
        onAuth: (handShakeData: string): void => {
          console.info(`onData, data: ${handShakeData}.`);
        },
        onDisconnect: () => {
          console.info(`onDisconnect.`);
          this.comProxy = null;
        }
      }
    
      build() {
        Column() {
          Row() {
            // Create the connection button.
            Button('connect ability')
              .enabled(true)
              .onClick(() => {
                let connectWant: Want = {
                  bundleName: 'com.sample.agentextensionability',
                  abilityName: 'AgentExtAbility',
                };
                let agentId: string = 'weather_assistant_001';
                try {
                  // Connect to AgentExtensionAbility.
                  agentManager.connectAgentExtensionAbility(connectWant, agentId, this.connectCallback)
                    .then((proxy: common.AgentProxy) => {
                      this.comProxy = proxy;
                      // ...
                      let authorizeData = 'authorize data';
                      try {
                        this.comProxy.authorize(authorizeData);
                      } catch (err) {
                        let code = (err as BusinessError).code;
                        let msg = (err as BusinessError).message;
                        console.error(`sendData failed, err code: ${code}, err msg: ${msg}.`);
                      }
                    })
                    .catch((err: BusinessError) => {
                      console.error(`connectAgentExtensionAbility failed, err code: ${err.code}, err msg: ${err.message}.`);
                    });
                } catch (err) {
                  let code = (err as BusinessError).code;
                  let msg = (err as BusinessError).message;
                  console.error(`connectAgentExtensionAbility failed, err code: ${code}, err msg: ${msg}.`);
                }
              })
            // ...
          }
        }
      }
    }
    ```

- The server processes and sends security authentication requests

  For details, see [Using the AgentExtensionAbility Component to Receive and Send Security Authentication Requests](agent-extension-ability.md#using-the-agentextensionability-component-to-receive-and-send-security-authentication-requests).