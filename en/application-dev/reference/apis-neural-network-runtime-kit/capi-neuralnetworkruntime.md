# NeuralNetworkRuntime
<!--Kit_Neural Network Runtime Kit--><!--System_AI-->

## Overview

Provides APIs for accelerating the Neural Network Runtime (NNRt) model inference.

**Since**: 9
## Files

| Name| Description|
| -- | -- |
| [neural_network_core.h](capi-neural-network-core-h.md) | Defines APIs for the Neural Network Core module. The AI inference framework uses the native interfaces provided by Neural Network Core to build models and perform inference and computing on acceleration hardware.<br> Some API definitions have been moved from **neural_network_runtime.h** to this file for unified presentation. These APIs are supported since API version 11 and can be used in all later versions.<br>Currently, the APIs of Neural Network Core do not support multi-thread calling.|
| [neural_network_runtime.h](capi-neural-network-runtime-h.md) | Defines APIs for Neural Network Runtime. The AI inference framework uses the native APIs provided by the Neural Network Runtime to construct and build models.<br>Currently, the APIs of Neural Network Runtime do not support multi-thread calling.|
| [neural_network_runtime_type.h](capi-neural-network-runtime-type-h.md) | Defines the structs and enums for NNRt.|
