# NeuralNetworkRuntime


## 概述

提供Neural Network Runtime加速模型推理的相关接口。

**起始版本：** 9


## 汇总


### 文件

| 名称 | 描述 | 
| -------- | -------- |
| [neural_network_core.h](neural__network__core_8h.md) | Neural Network Core模块接口定义，AI推理框架使用Neural Network Core提供的Native接口，完成模型编译，并在加速硬件上执行推理和计算。 | 
| [neural_network_runtime.h](neural__network__runtime_8h.md) | Neural Network Runtime模块接口定义，AI推理框架使用Neural Network Runtime提供的Native接口，完成模型构建。 | 
| [neural_network_runtime_type.h](neural__network__runtime__type_8h.md) | Neural Network Runtime定义的结构体和枚举值。 | 


### 结构体

| 名称 | 描述 | 
| -------- | -------- |
| struct  [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) | 该结构体用于存储32位无符号整型数组。 | 
| struct  [OH_NN_QuantParam](_o_h___n_n___quant_param.md) | 量化信息。 | 
| struct  [OH_NN_Tensor](_o_h___n_n___tensor.md) | 张量结构体。 | 
| struct  [OH_NN_Memory](_o_h___n_n___memory.md) | 内存结构体。 | 


### 类型定义

| 名称 | 描述 | 
| -------- | -------- |
| typedef struct [OH_NNModel](#oh_nnmodel)  [OH_NNModel](#oh_nnmodel) | 模型句柄。 | 
| typedef struct [OH_NNCompilation](#oh_nncompilation)  [OH_NNCompilation](#oh_nncompilation) | 编译器句柄。 | 
| typedef struct [OH_NNExecutor](#oh_nnexecutor)  [OH_NNExecutor](#oh_nnexecutor) | 执行器句柄。 | 
| typedef struct [NN_QuantParam](#nn_quantparam)  [NN_QuantParam](#nn_quantparam) | 量化参数的句柄。 | 
| typedef struct [NN_TensorDesc](#nn_tensordesc)  [NN_TensorDesc](#nn_tensordesc) | Tensor描述的句柄。 | 
| typedef struct [NN_Tensor](#nn_tensor)  [NN_Tensor](#nn_tensor) | Tensor句柄。 | 
| typedef enum [OH_NN_PerformanceMode](#oh_nn_performancemode)  [OH_NN_PerformanceMode](#oh_nn_performancemode) | 硬件的性能模式。 | 
| typedef enum [OH_NN_Priority](#oh_nn_priority)  [OH_NN_Priority](#oh_nn_priority) | 模型推理任务优先级。 | 
| typedef enum [OH_NN_ReturnCode](#oh_nn_returncode)  [OH_NN_ReturnCode](#oh_nn_returncode) | Neural Network Runtime 定义的错误码类型。 | 
| typedef void(\* [NN_OnRunDone](#nn_onrundone)) (void \*userData, [OH_NN_ReturnCode](#oh_nn_returncode) errCode, void \*outputTensor[], int32_t outputCount) | 异步推理结束后的回调处理函数句柄。 | 
| typedef void(\* [NN_OnServiceDied](#nn_onservicedied)) (void \*userData) | 异步推理执行期间设备驱动服务异常终止时的回调处理函数句柄。 | 
| typedef enum [OH_NN_FuseType](#oh_nn_fusetype)  [OH_NN_FuseType](#oh_nn_fusetype) | Neural Network Runtime 融合算子中激活函数的类型。 | 
| typedef enum [OH_NN_Format](#oh_nn_format)  [OH_NN_Format](#oh_nn_format) | 张量数据的排布类型。 | 
| typedef enum [OH_NN_DeviceType](#oh_nn_devicetype)  [OH_NN_DeviceType](#oh_nn_devicetype) | Neural Network Runtime 支持的设备类型。 | 
| typedef enum [OH_NN_DataType](#oh_nn_datatype)  [OH_NN_DataType](#oh_nn_datatype) | Neural Network Runtime 支持的数据类型。 | 
| typedef enum [OH_NN_OperationType](#oh_nn_operationtype)  [OH_NN_OperationType](#oh_nn_operationtype) | Neural Network Runtime 支持算子的类型。 | 
| typedef enum [OH_NN_TensorType](#oh_nn_tensortype)  [OH_NN_TensorType](#oh_nn_tensortype) | 张量的类型。 | 
| typedef struct [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md)  [OH_NN_UInt32Array](#oh_nn_uint32array) | 该结构体用于存储32位无符号整型数组。 | 
| typedef struct [OH_NN_QuantParam](_o_h___n_n___quant_param.md)  [OH_NN_QuantParam](#oh_nn_quantparam) | 量化信息。 | 
| typedef struct [OH_NN_Tensor](_o_h___n_n___tensor.md)  [OH_NN_Tensor](#oh_nn_tensor) | 张量结构体。 | 
| typedef struct [OH_NN_Memory](_o_h___n_n___memory.md)  [OH_NN_Memory](#oh_nn_memory) | 内存结构体。 | 


### 枚举

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NN_PerformanceMode](#oh_nn_performancemode) {<br/>OH_NN_PERFORMANCE_NONE = 0, OH_NN_PERFORMANCE_LOW = 1, OH_NN_PERFORMANCE_MEDIUM = 2, OH_NN_PERFORMANCE_HIGH = 3,<br/>OH_NN_PERFORMANCE_EXTREME = 4<br/>} | 硬件的性能模式。 | 
| [OH_NN_Priority](#oh_nn_priority) { OH_NN_PRIORITY_NONE = 0, OH_NN_PRIORITY_LOW = 1, OH_NN_PRIORITY_MEDIUM = 2, OH_NN_PRIORITY_HIGH = 3 } | 模型推理任务优先级。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode) {<br/>OH_NN_SUCCESS = 0, OH_NN_FAILED = 1, OH_NN_INVALID_PARAMETER = 2, OH_NN_MEMORY_ERROR = 3,<br/>OH_NN_OPERATION_FORBIDDEN = 4, OH_NN_NULL_PTR = 5, OH_NN_INVALID_FILE = 6, OH_NN_UNAVALIDABLE_DEVICE = 7,<br/>OH_NN_INVALID_PATH = 8, OH_NN_TIMEOUT = 9, OH_NN_UNSUPPORTED = 10, OH_NN_CONNECTION_EXCEPTION = 11,<br/>OH_NN_SAVE_CACHE_EXCEPTION = 12, OH_NN_DYNAMIC_SHAPE = 13, OH_NN_UNAVAILABLE_DEVICE = 14<br/>} | Neural Network Runtime 定义的错误码类型。 | 
| [OH_NN_FuseType](#oh_nn_fusetype) : int8_t { OH_NN_FUSED_NONE = 0, OH_NN_FUSED_RELU = 1, OH_NN_FUSED_RELU6 = 2 } | Neural Network Runtime 融合算子中激活函数的类型。 | 
| [OH_NN_Format](#oh_nn_format) { OH_NN_FORMAT_NONE = 0, OH_NN_FORMAT_NCHW = 1, OH_NN_FORMAT_NHWC = 2, OH_NN_FORMAT_ND = 3 } | 张量数据的排布类型。 | 
| [OH_NN_DeviceType](#oh_nn_devicetype) { OH_NN_OTHERS = 0, OH_NN_CPU = 1, OH_NN_GPU = 2, OH_NN_ACCELERATOR = 3 } | Neural Network Runtime 支持的设备类型。 | 
| [OH_NN_DataType](#oh_nn_datatype) {<br/>OH_NN_UNKNOWN = 0, OH_NN_BOOL = 1, OH_NN_INT8 = 2, OH_NN_INT16 = 3,<br/>OH_NN_INT32 = 4, OH_NN_INT64 = 5, OH_NN_UINT8 = 6, OH_NN_UINT16 = 7,<br/>OH_NN_UINT32 = 8, OH_NN_UINT64 = 9, OH_NN_FLOAT16 = 10, OH_NN_FLOAT32 = 11,<br/>OH_NN_FLOAT64 = 12<br/>} | Neural Network Runtime 支持的数据类型。 | 
| [OH_NN_OperationType](#oh_nn_operationtype) {<br/>OH_NN_OPS_ADD = 1, OH_NN_OPS_AVG_POOL = 2, OH_NN_OPS_BATCH_NORM = 3, OH_NN_OPS_BATCH_TO_SPACE_ND = 4,<br/>OH_NN_OPS_BIAS_ADD = 5, OH_NN_OPS_CAST = 6, OH_NN_OPS_CONCAT = 7, OH_NN_OPS_CONV2D = 8,<br/>OH_NN_OPS_CONV2D_TRANSPOSE = 9, OH_NN_OPS_DEPTHWISE_CONV2D_NATIVE = 10, OH_NN_OPS_DIV = 11, OH_NN_OPS_ELTWISE = 12,<br/>OH_NN_OPS_EXPAND_DIMS = 13, OH_NN_OPS_FILL = 14, OH_NN_OPS_FULL_CONNECTION = 15, OH_NN_OPS_GATHER = 16,<br/>OH_NN_OPS_HSWISH = 17, OH_NN_OPS_LESS_EQUAL = 18, OH_NN_OPS_MATMUL = 19, OH_NN_OPS_MAXIMUM = 20,<br/>OH_NN_OPS_MAX_POOL = 21, OH_NN_OPS_MUL = 22, OH_NN_OPS_ONE_HOT = 23, OH_NN_OPS_PAD = 24,<br/>OH_NN_OPS_POW = 25, OH_NN_OPS_SCALE = 26, OH_NN_OPS_SHAPE = 27, OH_NN_OPS_SIGMOID = 28,<br/>OH_NN_OPS_SLICE = 29, OH_NN_OPS_SOFTMAX = 30, OH_NN_OPS_SPACE_TO_BATCH_ND = 31, OH_NN_OPS_SPLIT = 32,<br/>OH_NN_OPS_SQRT = 33, OH_NN_OPS_SQUARED_DIFFERENCE = 34, OH_NN_OPS_SQUEEZE = 35, OH_NN_OPS_STACK = 36,<br/>OH_NN_OPS_STRIDED_SLICE = 37, OH_NN_OPS_SUB = 38, OH_NN_OPS_TANH = 39, OH_NN_OPS_TILE = 40,<br/>OH_NN_OPS_TRANSPOSE = 41, OH_NN_OPS_REDUCE_MEAN = 42, OH_NN_OPS_RESIZE_BILINEAR = 43, OH_NN_OPS_RSQRT = 44,<br/>OH_NN_OPS_RESHAPE = 45, OH_NN_OPS_PRELU = 46, OH_NN_OPS_RELU = 47, OH_NN_OPS_RELU6 = 48,<br/>OH_NN_OPS_LAYER_NORM = 49, OH_NN_OPS_REDUCE_PROD = 50, OH_NN_OPS_REDUCE_ALL = 51, OH_NN_OPS_QUANT_DTYPE_CAST = 52,<br/>OH_NN_OPS_TOP_K = 53, OH_NN_OPS_ARG_MAX = 54, OH_NN_OPS_UNSQUEEZE = 55, OH_NN_OPS_GELU = 56,<br/>OH_NN_OPS_UNSTACK = 57, OH_NN_OPS_ABS = 58, OH_NN_OPS_ERF = 59, OH_NN_OPS_EXP = 60,<br/>OH_NN_OPS_LESS = 61, OH_NN_OPS_SELECT = 62, OH_NN_OPS_SQUARE = 63, OH_NN_OPS_FLATTEN = 64,<br/>OH_NN_OPS_DEPTH_TO_SPACE = 65, OH_NN_OPS_RANGE = 66, OH_NN_OPS_INSTANCE_NORM = 67, OH_NN_OPS_CONSTANT_OF_SHAPE = 68,<br/>OH_NN_OPS_BROADCAST_TO = 69, OH_NN_OPS_EQUAL = 70, OH_NN_OPS_GREATER = 71, OH_NN_OPS_NOT_EQUAL = 72,<br/>OH_NN_OPS_GREATER_EQUAL = 73, OH_NN_OPS_LEAKY_RELU = 74, OH_NN_OPS_LSTM = 75, OH_NN_OPS_CLIP = 76,<br/>OH_NN_OPS_ALL = 77, OH_NN_OPS_ASSERT = 78, OH_NN_OPS_COS = 79, OH_NN_OPS_LOG = 80,<br/>OH_NN_OPS_LOGICAL_AND = 81, OH_NN_OPS_LOGICAL_NOT = 82, OH_NN_OPS_MOD = 83, OH_NN_OPS_NEG = 84,<br/>OH_NN_OPS_RECIPROCAL = 85, OH_NN_OPS_SIN = 86, OH_NN_OPS_WHERE = 87, OH_NN_OPS_SPARSE_TO_DENSE = 88,<br/>OH_NN_OPS_LOGICAL_OR = 89, OH_NN_OPS_CEIL = 90, OH_NN_OPS_CROP = 91, OH_NN_OPS_DETECTION_POST_PROCESS = 92,<br/>OH_NN_OPS_FLOOR = 93, OH_NN_OPS_L2_NORMALIZE = 94, OH_NN_OPS_LOG_SOFTMAX = 95, OH_NN_OPS_LRN = 96,<br/>OH_NN_OPS_MINIMUM = 97, OH_NN_OPS_RANK = 98, OH_NN_OPS_REDUCE_MAX = 99, OH_NN_OPS_REDUCE_MIN = 100,<br/>OH_NN_OPS_REDUCE_SUM = 101, OH_NN_OPS_ROUND = 102, OH_NN_OPS_SCATTER_ND = 103, OH_NN_OPS_SPACE_TO_DEPTH = 104,<br/>OH_NN_OPS_SWISH = 105, OH_NN_OPS_REDUCE_L2 = 106, OH_NN_OPS_HARD_SIGMOID = 107, OH_NN_OPS_GATHER_ND = 108<br/>} | Neural Network Runtime 支持算子的类型。 | 
| [OH_NN_TensorType](#oh_nn_tensortype) {<br/>OH_NN_TENSOR = 0, OH_NN_ADD_ACTIVATIONTYPE = 1, OH_NN_AVG_POOL_KERNEL_SIZE = 2, OH_NN_AVG_POOL_STRIDE = 3,<br/>OH_NN_AVG_POOL_PAD_MODE = 4, OH_NN_AVG_POOL_PAD = 5, OH_NN_AVG_POOL_ACTIVATION_TYPE = 6, OH_NN_BATCH_NORM_EPSILON = 7,<br/>OH_NN_BATCH_TO_SPACE_ND_BLOCKSIZE = 8, OH_NN_BATCH_TO_SPACE_ND_CROPS = 9, OH_NN_CONCAT_AXIS = 10, OH_NN_CONV2D_STRIDES = 11,<br/>OH_NN_CONV2D_PAD = 12, OH_NN_CONV2D_DILATION = 13, OH_NN_CONV2D_PAD_MODE = 14, OH_NN_CONV2D_ACTIVATION_TYPE = 15,<br/>OH_NN_CONV2D_GROUP = 16, OH_NN_CONV2D_TRANSPOSE_STRIDES = 17, OH_NN_CONV2D_TRANSPOSE_PAD = 18, OH_NN_CONV2D_TRANSPOSE_DILATION = 19,<br/>OH_NN_CONV2D_TRANSPOSE_OUTPUT_PADDINGS = 20, OH_NN_CONV2D_TRANSPOSE_PAD_MODE = 21, OH_NN_CONV2D_TRANSPOSE_ACTIVATION_TYPE = 22, OH_NN_CONV2D_TRANSPOSE_GROUP = 23,<br/>OH_NN_DEPTHWISE_CONV2D_NATIVE_STRIDES = 24, OH_NN_DEPTHWISE_CONV2D_NATIVE_PAD = 25, OH_NN_DEPTHWISE_CONV2D_NATIVE_DILATION = 26, OH_NN_DEPTHWISE_CONV2D_NATIVE_PAD_MODE = 27,<br/>OH_NN_DEPTHWISE_CONV2D_NATIVE_ACTIVATION_TYPE = 28, OH_NN_DIV_ACTIVATIONTYPE = 29, OH_NN_ELTWISE_MODE = 30, OH_NN_FULL_CONNECTION_AXIS = 31,<br/>OH_NN_FULL_CONNECTION_ACTIVATIONTYPE = 32, OH_NN_MATMUL_TRANSPOSE_A = 33, OH_NN_MATMUL_TRANSPOSE_B = 34, OH_NN_MATMUL_ACTIVATION_TYPE = 35,<br/>OH_NN_MAX_POOL_KERNEL_SIZE = 36, OH_NN_MAX_POOL_STRIDE = 37, OH_NN_MAX_POOL_PAD_MODE = 38, OH_NN_MAX_POOL_PAD = 39,<br/>OH_NN_MAX_POOL_ACTIVATION_TYPE = 40, OH_NN_MUL_ACTIVATION_TYPE = 41, OH_NN_ONE_HOT_AXIS = 42, OH_NN_PAD_CONSTANT_VALUE = 43,<br/>OH_NN_SCALE_ACTIVATIONTYPE = 44, OH_NN_SCALE_AXIS = 45, OH_NN_SOFTMAX_AXIS = 46, OH_NN_SPACE_TO_BATCH_ND_BLOCK_SHAPE = 47,<br/>OH_NN_SPACE_TO_BATCH_ND_PADDINGS = 48, OH_NN_SPLIT_AXIS = 49, OH_NN_SPLIT_OUTPUT_NUM = 50, OH_NN_SPLIT_SIZE_SPLITS = 51,<br/>OH_NN_SQUEEZE_AXIS = 52, OH_NN_STACK_AXIS = 53, OH_NN_STRIDED_SLICE_BEGIN_MASK = 54, OH_NN_STRIDED_SLICE_END_MASK = 55,<br/>OH_NN_STRIDED_SLICE_ELLIPSIS_MASK = 56, OH_NN_STRIDED_SLICE_NEW_AXIS_MASK = 57, OH_NN_STRIDED_SLICE_SHRINK_AXIS_MASK = 58, OH_NN_SUB_ACTIVATIONTYPE = 59,<br/>OH_NN_REDUCE_MEAN_KEEP_DIMS = 60, OH_NN_RESIZE_BILINEAR_NEW_HEIGHT = 61, OH_NN_RESIZE_BILINEAR_NEW_WIDTH = 62, OH_NN_RESIZE_BILINEAR_PRESERVE_ASPECT_RATIO = 63,<br/>OH_NN_RESIZE_BILINEAR_COORDINATE_TRANSFORM_MODE = 64, OH_NN_RESIZE_BILINEAR_EXCLUDE_OUTSIDE = 65, OH_NN_LAYER_NORM_BEGIN_NORM_AXIS = 66, OH_NN_LAYER_NORM_EPSILON = 67,<br/>OH_NN_LAYER_NORM_BEGIN_PARAM_AXIS = 68, OH_NN_LAYER_NORM_ELEMENTWISE_AFFINE = 69, OH_NN_REDUCE_PROD_KEEP_DIMS = 70, OH_NN_REDUCE_ALL_KEEP_DIMS = 71,<br/>OH_NN_QUANT_DTYPE_CAST_SRC_T = 72, OH_NN_QUANT_DTYPE_CAST_DST_T = 73, OH_NN_TOP_K_SORTED = 74, OH_NN_ARG_MAX_AXIS = 75,<br/>OH_NN_ARG_MAX_KEEPDIMS = 76, OH_NN_UNSQUEEZE_AXIS = 77, OH_NN_UNSTACK_AXIS = 78, OH_NN_FLATTEN_AXIS = 79,<br/>OH_NN_DEPTH_TO_SPACE_BLOCK_SIZE = 80, OH_NN_DEPTH_TO_SPACE_MODE = 81, OH_NN_RANGE_START = 82, OH_NN_RANGE_LIMIT = 83,<br/>OH_NN_RANGE_DELTA = 84, OH_NN_CONSTANT_OF_SHAPE_DATA_TYPE = 85, OH_NN_CONSTANT_OF_SHAPE_VALUE = 86, OH_NN_BROADCAST_TO_SHAPE = 87,<br/>OH_NN_INSTANCE_NORM_EPSILON = 88, OH_NN_EXP_BASE = 89, OH_NN_EXP_SCALE = 90, OH_NN_EXP_SHIFT = 91,<br/>OH_NN_LEAKY_RELU_NEGATIVE_SLOPE = 92, OH_NN_LSTM_BIDIRECTIONAL = 93, OH_NN_LSTM_HAS_BIAS = 94, OH_NN_LSTM_INPUT_SIZE = 95,<br/>OH_NN_LSTM_HIDDEN_SIZE = 96, OH_NN_LSTM_NUM_LAYERS = 97, OH_NN_LSTM_NUM_DIRECTIONS = 98, OH_NN_LSTM_DROPOUT = 99,<br/>OH_NN_LSTM_ZONEOUT_CELL = 100, OH_NN_LSTM_ZONEOUT_HIDDEN = 101, OH_NN_LSTM_PROJ_SIZE = 102, OH_NN_CLIP_MAX = 103,<br/>OH_NN_CLIP_MIN = 104, OH_NN_ALL_KEEP_DIMS = 105, OH_NN_ASSERT_SUMMARIZE = 106, OH_NN_POW_SCALE = 107,<br/>OH_NN_POW_SHIFT = 108, OH_NN_AVG_POOL_ROUND_MODE = 109, OH_NN_AVG_POOL_GLOBAL = 110, OH_NN_FULL_CONNECTION_HAS_BIAS = 111,<br/>OH_NN_FULL_CONNECTION_USE_AXIS = 112, OH_NN_GELU_APPROXIMATE = 113, OH_NN_MAX_POOL_ROUND_MODE = 114, OH_NN_MAX_POOL_GLOBAL = 115,<br/>OH_NN_PAD_PADDING_MODE = 116, OH_NN_REDUCE_MEAN_REDUCE_TO_END = 117, OH_NN_REDUCE_MEAN_COEFF = 118, OH_NN_REDUCE_PROD_REDUCE_TO_END = 119,<br/>OH_NN_REDUCE_PROD_COEFF = 120, OH_NN_REDUCE_ALL_REDUCE_TO_END = 121, OH_NN_REDUCE_ALL_COEFF = 122, OH_NN_TOP_K_AXIS = 123,<br/>OH_NN_ARG_MAX_TOP_K = 124, OH_NN_ARG_MAX_OUT_MAX_VALUE = 125, OH_NN_QUANT_DTYPE_CAST_AXIS = 126, OH_NN_SLICE_AXES = 127,<br/>OH_NN_TILE_DIMS = 128, OH_NN_CROP_AXIS = 129, OH_NN_CROP_OFFSET = 130, OH_NN_DETECTION_POST_PROCESS_INPUT_SIZE = 131,<br/>OH_NN_DETECTION_POST_PROCESS_SCALE = 132, OH_NN_DETECTION_POST_PROCESS_NMS_IOU_THRESHOLD = 133, OH_NN_DETECTION_POST_PROCESS_NMS_SCORE_THRESHOLD = 134, OH_NN_DETECTION_POST_PROCESS_MAX_DETECTIONS = 135,<br/>OH_NN_DETECTION_POST_PROCESS_DETECTIONS_PER_CLASS = 136, OH_NN_DETECTION_POST_PROCESS_MAX_CLASSES_PER_DETECTION = 137, OH_NN_DETECTION_POST_PROCESS_NUM_CLASSES = 138, OH_NN_DETECTION_POST_PROCESS_USE_REGULAR_NMS = 139,<br/>OH_NN_DETECTION_POST_PROCESS_OUT_QUANTIZED = 140, OH_NN_L2_NORMALIZE_AXIS = 141, OH_NN_L2_NORMALIZE_EPSILON = 142, OH_NN_L2_NORMALIZE_ACTIVATION_TYPE = 143,<br/>OH_NN_LOG_SOFTMAX_AXIS = 144, OH_NN_LRN_DEPTH_RADIUS = 145, OH_NN_LRN_BIAS = 146, OH_NN_LRN_ALPHA = 147,<br/>OH_NN_LRN_BETA = 148, OH_NN_LRN_NORM_REGION = 149, OH_NN_SPACE_TO_DEPTH_BLOCK_SIZE = 150, OH_NN_REDUCE_MAX_KEEP_DIMS = 151,<br/>OH_NN_REDUCE_MAX_REDUCE_TO_END = 152, OH_NN_REDUCE_MAX_COEFF = 153, OH_NN_REDUCE_MIN_KEEP_DIMS = 154, OH_NN_REDUCE_MIN_REDUCE_TO_END = 155,<br/>OH_NN_REDUCE_MIN_COEFF = 156, OH_NN_REDUCE_SUM_KEEP_DIMS = 157, OH_NN_REDUCE_SUM_REDUCE_TO_END = 158, OH_NN_REDUCE_SUM_COEFF = 159,<br/>OH_NN_REDUCE_L2_KEEP_DIMS = 160, OH_NN_REDUCE_L2_REDUCE_TO_END = 161, OH_NN_REDUCE_L2_COEFF = 162<br/>} | 张量的类型。 | 


### 函数

| 名称 | 描述 | 
| -------- | -------- |
| [OH_NNCompilation](#oh_nncompilation) \* [OH_NNCompilation_Construct](#oh_nncompilation_construct) (const [OH_NNModel](#oh_nnmodel) \*model) | 创建[OH_NNCompilation](#oh_nncompilation)类型的编译实例。 | 
| [OH_NNCompilation](#oh_nncompilation) \* [OH_NNCompilation_ConstructWithOfflineModelFile](#oh_nncompilation_constructwithofflinemodelfile) (const char \*modelPath) | 基于离线模型文件创建编译实例。 | 
| [OH_NNCompilation](#oh_nncompilation) \* [OH_NNCompilation_ConstructWithOfflineModelBuffer](#oh_nncompilation_constructwithofflinemodelbuffer) (const void \*modelBuffer, size_t modelSize) | 基于离线模型文件内存创建编译实例。 | 
| [OH_NNCompilation](#oh_nncompilation) \* [OH_NNCompilation_ConstructForCache](#oh_nncompilation_constructforcache) () | 创建一个空的编译实例，以便稍后从模型缓存中恢复。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNCompilation_ExportCacheToBuffer](#oh_nncompilation_exportcachetobuffer) ([OH_NNCompilation](#oh_nncompilation) \*compilation, const void \*buffer, size_t length, size_t \*modelSize) | 将模型缓存写入到指定内存区域。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNCompilation_ImportCacheFromBuffer](#oh_nncompilation_importcachefrombuffer) ([OH_NNCompilation](#oh_nncompilation) \*compilation, const void \*buffer, size_t modelSize) | 从指定内存区域读取模型缓存。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNCompilation_AddExtensionConfig](#oh_nncompilation_addextensionconfig) ([OH_NNCompilation](#oh_nncompilation) \*compilation, const char \*configName, const void \*configValue, const size_t configValueSize) | 为自定义硬件属性添加扩展配置。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNCompilation_SetDevice](#oh_nncompilation_setdevice) ([OH_NNCompilation](#oh_nncompilation) \*compilation, size_t deviceID) | 指定模型编译和计算的硬件。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNCompilation_SetCache](#oh_nncompilation_setcache) ([OH_NNCompilation](#oh_nncompilation) \*compilation, const char \*cachePath, uint32_t version) | 设置编译模型的缓存目录和版本。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNCompilation_SetPerformanceMode](#oh_nncompilation_setperformancemode) ([OH_NNCompilation](#oh_nncompilation) \*compilation, [OH_NN_PerformanceMode](#oh_nn_performancemode) performanceMode) | 设置模型计算的性能模式。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNCompilation_SetPriority](#oh_nncompilation_setpriority) ([OH_NNCompilation](#oh_nncompilation) \*compilation, [OH_NN_Priority](#oh_nn_priority) priority) | 设置模型计算的优先级。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNCompilation_EnableFloat16](#oh_nncompilation_enablefloat16) ([OH_NNCompilation](#oh_nncompilation) \*compilation, bool enableFloat16) | 是否以float16的浮点数精度计算。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNCompilation_Build](#oh_nncompilation_build) ([OH_NNCompilation](#oh_nncompilation) \*compilation) | 执行模型编译。 | 
| void [OH_NNCompilation_Destroy](#oh_nncompilation_destroy) ([OH_NNCompilation](#oh_nncompilation) \*\*compilation) | 销毁Compilation实例。 | 
| [NN_TensorDesc](#nn_tensordesc) \* [OH_NNTensorDesc_Create](#oh_nntensordesc_create) () | 创建一个[NN_TensorDesc](#nn_tensordesc)实例。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNTensorDesc_Destroy](#oh_nntensordesc_destroy) ([NN_TensorDesc](#nn_tensordesc) \*\*tensorDesc) | 释放一个[NN_TensorDesc](#nn_tensordesc)实例。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNTensorDesc_SetName](#oh_nntensordesc_setname) ([NN_TensorDesc](#nn_tensordesc) \*tensorDesc, const char \*name) | 设置[NN_TensorDesc](#nn_tensordesc)的名称。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNTensorDesc_GetName](#oh_nntensordesc_getname) (const [NN_TensorDesc](#nn_tensordesc) \*tensorDesc, const char \*\*name) | 获取[NN_TensorDesc](#nn_tensordesc)的名称。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNTensorDesc_SetDataType](#oh_nntensordesc_setdatatype) ([NN_TensorDesc](#nn_tensordesc) \*tensorDesc, [OH_NN_DataType](#oh_nn_datatype) dataType) | 设置[NN_TensorDesc](#nn_tensordesc)的数据类型。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNTensorDesc_GetDataType](#oh_nntensordesc_getdatatype) (const [NN_TensorDesc](#nn_tensordesc) \*tensorDesc, [OH_NN_DataType](#oh_nn_datatype) \*dataType) | 获取[NN_TensorDesc](#nn_tensordesc)的数据类型。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNTensorDesc_SetShape](#oh_nntensordesc_setshape) ([NN_TensorDesc](#nn_tensordesc) \*tensorDesc, const int32_t \*shape, size_t shapeLength) | 设置[NN_TensorDesc](#nn_tensordesc)的数据形状。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNTensorDesc_GetShape](#oh_nntensordesc_getshape) (const [NN_TensorDesc](#nn_tensordesc) \*tensorDesc, int32_t \*\*shape, size_t \*shapeLength) | 获取[NN_TensorDesc](#nn_tensordesc)的形状。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNTensorDesc_SetFormat](#oh_nntensordesc_setformat) ([NN_TensorDesc](#nn_tensordesc) \*tensorDesc, [OH_NN_Format](#oh_nn_format) format) | 设置[NN_TensorDesc](#nn_tensordesc)的数据布局。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNTensorDesc_GetFormat](#oh_nntensordesc_getformat) (const [NN_TensorDesc](#nn_tensordesc) \*tensorDesc, [OH_NN_Format](#oh_nn_format) \*format) | 获取[NN_TensorDesc](#nn_tensordesc)的数据布局。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNTensorDesc_GetElementCount](#oh_nntensordesc_getelementcount) (const [NN_TensorDesc](#nn_tensordesc) \*tensorDesc, size_t \*elementCount) | 获取[NN_TensorDesc](#nn_tensordesc)的元素个数。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNTensorDesc_GetByteSize](#oh_nntensordesc_getbytesize) (const [NN_TensorDesc](#nn_tensordesc) \*tensorDesc, size_t \*byteSize) | 获取基于[NN_TensorDesc](#nn_tensordesc)的形状和数据类型计算的数据占用字节数。 | 
| [NN_Tensor](#nn_tensor) \* [OH_NNTensor_Create](#oh_nntensor_create) (size_t deviceID, [NN_TensorDesc](#nn_tensordesc) \*tensorDesc) | 从[NN_TensorDesc](#nn_tensordesc)创建一个[NN_Tensor](#nn_tensor)实例。 | 
| [NN_Tensor](#nn_tensor) \* [OH_NNTensor_CreateWithSize](#oh_nntensor_createwithsize) (size_t deviceID, [NN_TensorDesc](#nn_tensordesc) \*tensorDesc, size_t size) | 按照指定内存大小和[NN_TensorDesc](#nn_tensordesc)创建[NN_Tensor](#nn_tensor)实例。 | 
| [NN_Tensor](#nn_tensor) \* [OH_NNTensor_CreateWithFd](#oh_nntensor_createwithfd) (size_t deviceID, [NN_TensorDesc](#nn_tensordesc) \*tensorDesc, int fd, size_t size, size_t offset) | 按照指定共享内存的文件描述符和[NN_TensorDesc](#nn_tensordesc)创建{\@Link NN_Tensor}实例。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNTensor_Destroy](#oh_nntensor_destroy) ([NN_Tensor](#nn_tensor) \*\*tensor) | 销毁一个[NN_Tensor](#nn_tensor)实例。 | 
| [NN_TensorDesc](#nn_tensordesc) \* [OH_NNTensor_GetTensorDesc](#oh_nntensor_gettensordesc) (const [NN_Tensor](#nn_tensor) \*tensor) | 获取[NN_Tensor](#nn_tensor)的[NN_TensorDesc](#nn_tensordesc)实例。 | 
| void \* [OH_NNTensor_GetDataBuffer](#oh_nntensor_getdatabuffer) (const [NN_Tensor](#nn_tensor) \*tensor) | 获取[NN_Tensor](#nn_tensor)数据的内存地址。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNTensor_GetFd](#oh_nntensor_getfd) (const [NN_Tensor](#nn_tensor) \*tensor, int \*fd) | 获取[NN_Tensor](#nn_tensor)数据所在共享内存的文件描述符。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNTensor_GetSize](#oh_nntensor_getsize) (const [NN_Tensor](#nn_tensor) \*tensor, size_t \*size) | 获取[NN_Tensor](#nn_tensor)数据所在共享内存的大小。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNTensor_GetOffset](#oh_nntensor_getoffset) (const [NN_Tensor](#nn_tensor) \*tensor, size_t \*offset) | 获取[NN_Tensor](#nn_tensor)数据所在共享内存上的偏移量。 | 
| [OH_NNExecutor](#oh_nnexecutor) \* [OH_NNExecutor_Construct](#oh_nnexecutor_construct) ([OH_NNCompilation](#oh_nncompilation) \*compilation) | 创建[OH_NNExecutor](#oh_nnexecutor)执行器实例。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNExecutor_GetOutputShape](#oh_nnexecutor_getoutputshape) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t outputIndex, int32_t \*\*shape, uint32_t \*shapeLength) | 获取输出张量的维度信息。 | 
| void [OH_NNExecutor_Destroy](#oh_nnexecutor_destroy) ([OH_NNExecutor](#oh_nnexecutor) \*\*executor) | 销毁执行器实例，释放执行器占用的内存。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNExecutor_GetInputCount](#oh_nnexecutor_getinputcount) (const [OH_NNExecutor](#oh_nnexecutor) \*executor, size_t \*inputCount) | 获取输入张量的数量。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNExecutor_GetOutputCount](#oh_nnexecutor_getoutputcount) (const [OH_NNExecutor](#oh_nnexecutor) \*executor, size_t \*outputCount) | 获取输出张量的数量。 | 
| [NN_TensorDesc](#nn_tensordesc) \* [OH_NNExecutor_CreateInputTensorDesc](#oh_nnexecutor_createinputtensordesc) (const [OH_NNExecutor](#oh_nnexecutor) \*executor, size_t index) | 由指定索引值创建一个输入张量的描述。 | 
| [NN_TensorDesc](#nn_tensordesc) \* [OH_NNExecutor_CreateOutputTensorDesc](#oh_nnexecutor_createoutputtensordesc) (const [OH_NNExecutor](#oh_nnexecutor) \*executor, size_t index) | 由指定索引值创建一个输出张量的描述。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNExecutor_GetInputDimRange](#oh_nnexecutor_getinputdimrange) (const [OH_NNExecutor](#oh_nnexecutor) \*executor, size_t index, size_t \*\*minInputDims, size_t \*\*maxInputDims, size_t \*shapeLength) | 获取所有输入张量的维度范围。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNExecutor_SetOnRunDone](#oh_nnexecutor_setonrundone) ([OH_NNExecutor](#oh_nnexecutor) \*executor, [NN_OnRunDone](#nn_onrundone) onRunDone) | 设置异步推理结束后的回调处理函数。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNExecutor_SetOnServiceDied](#oh_nnexecutor_setonservicedied) ([OH_NNExecutor](#oh_nnexecutor) \*executor, [NN_OnServiceDied](#nn_onservicedied) onServiceDied) | 设置异步推理执行期间设备驱动服务突然死亡时的回调处理函数。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNExecutor_RunSync](#oh_nnexecutor_runsync) ([OH_NNExecutor](#oh_nnexecutor) \*executor, [NN_Tensor](#nn_tensor) \*inputTensor[], size_t inputCount, [NN_Tensor](#nn_tensor) \*outputTensor[], size_t outputCount) | 执行同步推理。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNExecutor_RunAsync](#oh_nnexecutor_runasync) ([OH_NNExecutor](#oh_nnexecutor) \*executor, [NN_Tensor](#nn_tensor) \*inputTensor[], size_t inputCount, [NN_Tensor](#nn_tensor) \*outputTensor[], size_t outputCount, int32_t timeout, void \*userData) | 执行异步推理。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNDevice_GetAllDevicesID](#oh_nndevice_getalldevicesid) (const size_t \*\*allDevicesID, uint32_t \*deviceCount) | 获取对接到 Neural Network Runtime 的硬件ID。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNDevice_GetName](#oh_nndevice_getname) (size_t deviceID, const char \*\*name) | 获取指定硬件的名称。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNDevice_GetType](#oh_nndevice_gettype) (size_t deviceID, [OH_NN_DeviceType](#oh_nn_devicetype) \*deviceType) | 获取指定硬件的类别信息。 | 
| [NN_QuantParam](#nn_quantparam) \* [OH_NNQuantParam_Create](#oh_nnquantparam_create) () | 创建一个[NN_QuantParam](#nn_quantparam)量化参数实例。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNQuantParam_SetScales](#oh_nnquantparam_setscales) ([NN_QuantParam](#nn_quantparam) \*quantParams, const double \*scales, size_t quantCount) | 设置[NN_QuantParam](#nn_quantparam)的缩放系数。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNQuantParam_SetZeroPoints](#oh_nnquantparam_setzeropoints) ([NN_QuantParam](#nn_quantparam) \*quantParams, const int32_t \*zeroPoints, size_t quantCount) | 设置[NN_QuantParam](#nn_quantparam)的零点。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNQuantParam_SetNumBits](#oh_nnquantparam_setnumbits) ([NN_QuantParam](#nn_quantparam) \*quantParams, const uint32_t \*numBits, size_t quantCount) | 设置[NN_QuantParam](#nn_quantparam)的量化位数。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNQuantParam_Destroy](#oh_nnquantparam_destroy) ([NN_QuantParam](#nn_quantparam) \*\*quantParams) | 销毁[NN_QuantParam](#nn_quantparam)实例。 | 
| [OH_NNModel](#oh_nnmodel) \* [OH_NNModel_Construct](#oh_nnmodel_construct) (void) | 创建[OH_NNModel](#oh_nnmodel)类型的模型实例，搭配OH_NNModel模块提供的其他接口，完成模型实例的构造。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNModel_AddTensorToModel](#oh_nnmodel_addtensortomodel) ([OH_NNModel](#oh_nnmodel) \*model, const [NN_TensorDesc](#nn_tensordesc) \*tensorDesc) | 向模型实例中添加张量。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNModel_SetTensorData](#oh_nnmodel_settensordata) ([OH_NNModel](#oh_nnmodel) \*model, uint32_t index, const void \*dataBuffer, size_t length) | 设置张量的数值。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNModel_SetTensorQuantParams](#oh_nnmodel_settensorquantparams) ([OH_NNModel](#oh_nnmodel) \*model, uint32_t index, [NN_QuantParam](#nn_quantparam) \*quantParam) | 设置张量的量化参数，参考[NN_QuantParam](#nn_quantparam)。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNModel_SetTensorType](#oh_nnmodel_settensortype) ([OH_NNModel](#oh_nnmodel) \*model, uint32_t index, [OH_NN_TensorType](#oh_nn_tensortype) tensorType) | 设置张量的类型，参考[OH_NN_TensorType](#oh_nn_tensortype)。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNModel_AddOperation](#oh_nnmodel_addoperation) ([OH_NNModel](#oh_nnmodel) \*model, [OH_NN_OperationType](#oh_nn_operationtype) op, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*paramIndices, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*inputIndices, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*outputIndices) | 向模型实例中添加算子。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) ([OH_NNModel](#oh_nnmodel) \*model, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*inputIndices, const [OH_NN_UInt32Array](_o_h___n_n___u_int32_array.md) \*outputIndices) | 指定模型的输入和输出张量的索引值。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNModel_Finish](#oh_nnmodel_finish) ([OH_NNModel](#oh_nnmodel) \*model) | 完成模型构图。 | 
| void [OH_NNModel_Destroy](#oh_nnmodel_destroy) ([OH_NNModel](#oh_nnmodel) \*\*model) | 销毁模型实例。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNModel_GetAvailableOperations](#oh_nnmodel_getavailableoperations) ([OH_NNModel](#oh_nnmodel) \*model, size_t deviceID, const bool \*\*isSupported, uint32_t \*opCount) | 查询硬件对模型内所有算子的支持情况，通过布尔值序列指示支持情况。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNModel_AddTensor](#oh_nnmodel_addtensor) ([OH_NNModel](#oh_nnmodel) \*model, const [OH_NN_Tensor](_o_h___n_n___tensor.md) \*tensor) | 向模型实例中添加张量。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNExecutor_SetInput](#oh_nnexecutor_setinput) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t inputIndex, const [OH_NN_Tensor](_o_h___n_n___tensor.md) \*tensor, const void \*dataBuffer, size_t length) | 设置模型单个输入的数据。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNExecutor_SetOutput](#oh_nnexecutor_setoutput) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t outputIndex, void \*dataBuffer, size_t length) | 设置模型单个输出的内存。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNExecutor_Run](#oh_nnexecutor_run) ([OH_NNExecutor](#oh_nnexecutor) \*executor) | 执行推理。 | 
| [OH_NN_Memory](_o_h___n_n___memory.md) \* [OH_NNExecutor_AllocateInputMemory](#oh_nnexecutor_allocateinputmemory) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t inputIndex, size_t length) | 在硬件上为单个输入申请共享内存。 | 
| [OH_NN_Memory](_o_h___n_n___memory.md) \* [OH_NNExecutor_AllocateOutputMemory](#oh_nnexecutor_allocateoutputmemory) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t outputIndex, size_t length) | 在硬件上为单个输出申请共享内存。 | 
| void [OH_NNExecutor_DestroyInputMemory](#oh_nnexecutor_destroyinputmemory) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t inputIndex, [OH_NN_Memory](_o_h___n_n___memory.md) \*\*memory) | 释放[OH_NN_Memory](_o_h___n_n___memory.md)实例指向的输入内存。 | 
| void [OH_NNExecutor_DestroyOutputMemory](#oh_nnexecutor_destroyoutputmemory) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t outputIndex, [OH_NN_Memory](_o_h___n_n___memory.md) \*\*memory) | 释放[OH_NN_Memory](_o_h___n_n___memory.md)实例指向的输出内存。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNExecutor_SetInputWithMemory](#oh_nnexecutor_setinputwithmemory) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t inputIndex, const [OH_NN_Tensor](_o_h___n_n___tensor.md) \*tensor, const [OH_NN_Memory](_o_h___n_n___memory.md) \*memory) | 将[OH_NN_Memory](_o_h___n_n___memory.md)实例指向的硬件共享内存，并指定为单个输入使用的内存。 | 
| [OH_NN_ReturnCode](#oh_nn_returncode)[OH_NNExecutor_SetOutputWithMemory](#oh_nnexecutor_setoutputwithmemory) ([OH_NNExecutor](#oh_nnexecutor) \*executor, uint32_t outputIndex, const [OH_NN_Memory](_o_h___n_n___memory.md) \*memory) | 将[OH_NN_Memory](_o_h___n_n___memory.md)实例指向的硬件共享内存，并指定为单个输出使用的内存。 | 


## 类型定义说明


### NN_OnRunDone

```
typedef void(* NN_OnRunDone) (void *userData, OH_NN_ReturnCode errCode, void *outputTensor[], int32_t outputCount)
```

**描述**

异步推理结束后的回调处理函数句柄。

使用参数**userData**来查询希望获取的那次异步推理执行。**userData**与调用异步推理[OH_NNExecutor_RunAsync](#oh_nnexecutor_runasync)接口时 传入的参数**userData**是一致的。使用参数**errCode**（[OH_NN_ReturnCode](#oh_nn_returncode)类型）来获取该次异步推理的返回状态。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userData | 异步推理执行的标识符，与调用异步推理[OH_NNExecutor_RunAsync](#oh_nnexecutor_runasync)接口时传入的参数**userData**一致。 | 
| errCode | 该次异步推理的返回状态（[OH_NN_ReturnCode](#oh_nn_returncode)类型）。 | 
| outputTensor | 异步推理的输出张量，与调用异步推理[OH_NNExecutor_RunAsync](#oh_nnexecutor_runasync)接口时传入的参数**outputTensor**一致。 | 
| outputCount | 异步推理输出张量的数量，与调用异步推理[OH_NNExecutor_RunAsync](#oh_nnexecutor_runasync)接口时传入的参数**outputCount**一致。 | 


### NN_OnServiceDied

```
typedef void(* NN_OnServiceDied) (void *userData)
```

**描述**

异步推理执行期间设备驱动服务异常终止时的回调处理函数句柄。

如果该回调函数被调用，您需要重新编译模型。

使用参数**userData**来查询希望获取的那次异步推理执行。**userData**与调用异步推理[OH_NNExecutor_RunAsync](#oh_nnexecutor_runasync)接口时 传入的参数**userData**是一致的。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| userData | 异步推理执行的标识符，与调用异步推理[OH_NNExecutor_RunAsync](#oh_nnexecutor_runasync)接口时传入的参数**userData**一致。 | 


### NN_QuantParam

```
typedef struct NN_QuantParamNN_QuantParam
```

**描述**

量化参数的句柄。

**起始版本：** 11


### NN_Tensor

```
typedef struct NN_Tensor NN_Tensor
```

**描述**

Tensor句柄。

**起始版本：** 11


### NN_TensorDesc

```
typedef struct NN_TensorDesc NN_TensorDesc
```

**描述**

Tensor描述的句柄。

**起始版本：** 11


### OH_NN_DataType

```
typedef enum OH_NN_DataType OH_NN_DataType
```

**描述**

Neural Network Runtime 支持的数据类型。

**起始版本：** 9


### OH_NN_DeviceType

```
typedef enum OH_NN_DeviceType OH_NN_DeviceType
```

**描述**

Neural Network Runtime 支持的设备类型。

**起始版本：** 9


### OH_NN_Format

```
typedef enum OH_NN_Format OH_NN_Format
```

**描述**

张量数据的排布类型。

**起始版本：** 9


### OH_NN_FuseType

```
typedef enum OH_NN_FuseType OH_NN_FuseType
```

**描述**

Neural Network Runtime 融合算子中激活函数的类型。

**起始版本：** 9


### OH_NN_Memory

```
typedef struct OH_NN_Memory OH_NN_Memory
```

**描述**

内存结构体。

**起始版本：** 9


### OH_NN_OperationType

```
typedef enum OH_NN_OperationType OH_NN_OperationType
```

**描述**

Neural Network Runtime 支持算子的类型。

**起始版本：** 9


### OH_NN_PerformanceMode

```
typedef enum OH_NN_PerformanceMode OH_NN_PerformanceMode
```

**描述**

硬件的性能模式。

**起始版本：** 9


### OH_NN_Priority

```
typedef enum OH_NN_Priority OH_NN_Priority
```

**描述**

模型推理任务优先级。

**起始版本：** 9


### OH_NN_QuantParam

```
typedef struct OH_NN_QuantParam OH_NN_QuantParam
```

**描述**

量化信息。

在量化的场景中，32位浮点型数据根据以下公式量化为定点数据：

![zh-cn_formulaimage_0000001460519245](figures/zh-cn_formulaimage_0000001460519245.png)

其中s和z是量化参数，在OH_NN_QuanParam中通过scale和zeroPoint保存，r是浮点数，q是量化后的结果，q_min是量化后下界，q_max是量化后的上界，计算方式如下：

![zh-cn_formulaimage_0000001460759081](figures/zh-cn_formulaimage_0000001460759081.png)

![zh-cn_formulaimage_0000001460639441](figures/zh-cn_formulaimage_0000001460639441.png)

clamp函数定义如下：

![zh-cn_formulaimage_0000001410679330](figures/zh-cn_formulaimage_0000001410679330.png)

**起始版本：** 9


### OH_NN_ReturnCode

```
typedef enum OH_NN_ReturnCode OH_NN_ReturnCode
```

**描述**

Neural Network Runtime 定义的错误码类型。

**起始版本：** 9


### OH_NN_Tensor

```
typedef struct OH_NN_Tensor OH_NN_Tensor
```

**描述**

张量结构体。

通常用于构造模型图中的数据节点和算子参数，在构造张量时需要明确数据类型、维数、维度信息和量化信息。

**起始版本：** 9


### OH_NN_TensorType

```
typedef enum OH_NN_TensorType OH_NN_TensorType
```

**描述**

张量的类型。

张量通常用于设置模型的输入、输出和算子参数。作为模型（或算子）的输入和输出时，需要将张量类型设置为OH_NN_TENSOR；当张量 作为算子参数时，需要选择除OH_NN_TENSOR以外合适的枚举值，作为张量的类型。假设正在设置OH_NN_OPS_CONV2D 算子的pad参数，则需要将[OH_NN_Tensor](_o_h___n_n___tensor.md)实例的type属性设置为OH_NN_CONV2D_PAD。其他算子参数的设置以此类推，枚举值 的命名遵守 OH_NN_{算子名称}_{属性名} 的格式。

**起始版本：** 9


### OH_NN_UInt32Array

```
typedef struct OH_NN_UInt32Array OH_NN_UInt32Array
```

**描述**

该结构体用于存储32位无符号整型数组。

**起始版本：** 9


### OH_NNCompilation

```
typedef struct OH_NNCompilation OH_NNCompilation
```

**描述**

编译器句柄。

**起始版本：** 9


### OH_NNExecutor

```
typedef struct OH_NNExecutor OH_NNExecutor
```

**描述**

执行器句柄。

**起始版本：** 9


### OH_NNModel

```
typedef struct OH_NNModel OH_NNModel
```

**描述**

模型句柄。

**起始版本：** 9


## 枚举类型说明


### OH_NN_DataType

```
enum OH_NN_DataType
```

**描述**

Neural Network Runtime 支持的数据类型。

**起始版本：** 9

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_NN_UNKNOWN | 张量数据类型未知 | 
| OH_NN_BOOL | 张量数据类型为bool | 
| OH_NN_INT8 | 张量数据类型为int8 | 
| OH_NN_INT16 | 张量数据类型为int16 | 
| OH_NN_INT32 | 张量数据类型为int32 | 
| OH_NN_INT64 | 张量数据类型为int64 | 
| OH_NN_UINT8 | 张量数据类型为uint8 | 
| OH_NN_UINT16 | 张量数据类型为uint16 | 
| OH_NN_UINT32 | 张量数据类型为uint32 | 
| OH_NN_UINT64 | 张量数据类型为uint64 | 
| OH_NN_FLOAT16 | 张量数据类型为float16 | 
| OH_NN_FLOAT32 | 张量数据类型为float32 | 
| OH_NN_FLOAT64 | 张量数据类型为float64 | 


### OH_NN_DeviceType

```
enum OH_NN_DeviceType
```

**描述**

Neural Network Runtime 支持的设备类型。

**起始版本：** 9

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_NN_OTHERS | 不属于CPU、GPU、专用加速器的设备 | 
| OH_NN_CPU | CPU设备 | 
| OH_NN_GPU | GPU设备 | 
| OH_NN_ACCELERATOR | 专用硬件加速器 | 


### OH_NN_Format

```
enum OH_NN_Format
```

**描述**

张量数据的排布类型。

**起始版本：** 9

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_NN_FORMAT_NONE | 当张量没有特定的排布类型时（如标量或矢量），使用本枚举值 | 
| OH_NN_FORMAT_NCHW | 当张量按照NCHW的格式排布数据时，使用本枚举值 | 
| OH_NN_FORMAT_NHWC | 当张量按照NHWC的格式排布数据时，使用本枚举值 | 
| OH_NN_FORMAT_ND<sup>11+</sup> | 当张量按照ND的格式排布数据时，使用本枚举值 | 


### OH_NN_FuseType

```
enum OH_NN_FuseType : int8_t
```

**描述**

Neural Network Runtime 融合算子中激活函数的类型。

**起始版本：** 9

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_NN_FUSED_NONE | 未指定融合激活函数 | 
| OH_NN_FUSED_RELU | 融合relu激活函数 | 
| OH_NN_FUSED_RELU6 | 融合relu6激活函数 | 


### OH_NN_OperationType

```
enum OH_NN_OperationType
```

**描述**

Neural Network Runtime 支持算子的类型。

**起始版本：** 9

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_NN_OPS_ADD | 返回两个输入张量对应元素相加的和的张量。<br/>输入：<br/>- input1，第一个输入的张量，数据类型要求为布尔值或者数字。<br/>- input2，第二个输入的张量，数据类型和形状需要和第一个输入保持一致。<br/>参数：<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>输出：<br/>- output，input1和input2的和，数据形状与输入broadcast之后一样，数据类型与较高精度的输入精度一致。 | 
| OH_NN_OPS_AVG_POOL | 在输入张量上应用 2D 平均池化，仅支持NHWC格式的张量。支持int8量化输入。<br/>如果输入中含有padMode参数：<br/>输入：<br/>- input，一个张量。<br/>参数：<br/>- kernelSize，用来取平均值的kernel大小，是一个长度为2的int数组[kernelHeight，kernelWeight]， 第一个数表示kernel高度，第二个数表示kernel宽度。<br/>- strides，kernel移动的距离，是一个长度为2的int数组[strideHeight，strideWeight]， 第一个数表示高度上的移动步幅，第二个数表示宽度上的移动步幅。<br/>- padMode，填充模式，int类型的可选值，0表示same，1表示valid，并且以最近邻的值填充。 same，输出的高度和宽度与input相同，填充总数将在水平和垂直方向计算，并在可能的情况下均匀分布到顶部 和底部、左侧和右侧。否则，最后一个额外的填充将从底部和右侧完成。 valid，输出的可能最大高度和宽度将在不填充的情况下返回。额外的像素将被丢弃。<br/>- roundMode，边界处理方式，int类型的可选值，当池化核不能完全覆盖输入特征图时， 对输出特征图进行取整的方式，0表示向下取整，1表示向上取整。<br/>- global，bool值，是否对整个输入张量进行平均池化操作。<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>如果输入中含有padList参数：<br/>输入：<br/>- input，一个张量。<br/>参数：<br/>- kernelSize，用来取平均值的kernel大小，是一个长度为2的int数组[kernelHeight，kernelWeight]， 第一个数表示kernel高度，第二个数表示kernel宽度。<br/>- strides，kernel移动的距离，是一个长度为2的int数组[strideHeight，strideWeight]， 第一个数表示高度上的移动步幅，第二个数表示宽度上的移动步幅。<br/>- padList，input周围的填充，是一个长度为4的int数组[top，bottom，left，right]，并且以最近邻的值填充。<br/>- roundMode，边界处理方式，int类型的可选值，当池化核不能完全覆盖输入特征图时， 对输出特征图进行取整的方式，0表示向下取整，1表示向上取整。<br/>- global，bool值，是否对整个输入张量进行平均池化操作。<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>输出：<br/>- output，对input进行平均池化后的结果。 | 
| OH_NN_OPS_BATCH_NORM | 对输入张量做批量归一化，应用一种变换使平均输出保持接近0，输出标准差接近1。<br/>输入：<br/>- input，一个n维的张量，要求形状为[N，...，C]，即第n维是通道数（channel）。<br/>- scale，缩放因子的1D张量，用于缩放归一化的第一个张量。<br/>- offset，用于偏移的1D张量，以移动到归一化的第一个张量。<br/>- mean，总体均值的一维张量，仅用于推理；对于训练，必须为空。<br/>- variance，用于总体方差的一维张量。仅用于推理；对于训练，必须为空。<br/>参数：<br/>- epsilon，数值稳定性的小附加值。<br/>输出：<br/>- output，n维输出张量，其形状和数据类型与input一致。 | 
| OH_NN_OPS_BATCH_TO_SPACE_ND | 将一个4维张量的batch维度按blockSize切分成小块，并将这些小块拼接到空间维度。<br/>输入：<br/>- input，输入张量，维将被切分，拼接回空间维度。<br/>参数：<br/>- blockSize，一个长度为2的数组[heightBlock，weightBlock]，指定切分到空间维度上的block大小。<br/>- crops，一个shape为(2，2)的二维数组[[crop0Start，crop0End]，[crop1Start，crop1End]]， 表示在output的空间维度上截掉部分元素。<br/>输出：<br/>- output，假设input的形状为(n，h，w，c)，output的形状为（n'，h'，w'，c'）： n' = n / (blockSize[0] \* blockSize[1]) h' = h \* blockSize[0] - crops[0][0] - crops[0][1] w' = w \* blockSize[1] - crops[1][0] - crops[1][1] c'= c | 
| OH_NN_OPS_BIAS_ADD | 对给出的输入张量上的各个维度方向上的数据进行偏置。<br/>输入：<br/>- input，输入张量，可为2-5维度。<br/>- bias，参数对应输入维度数量的偏移值。<br/>输出：<br/>- output，根据输入中每个维度方向偏移后的结果。 | 
| OH_NN_OPS_CAST | 对输入张量中的数据类型进行转换。<br/>输入：<br/>- input，输入张量。<br/>- type，转换后的数据类型。<br/>输出：<br/>- output，转换后的张量。 | 
| OH_NN_OPS_CONCAT | 在指定维度上连接张量。<br/>输入：<br/>- input，N个输入张量。<br/>参数：<br/>- axis，指定张量连接的维度。<br/>输出：<br/>- output，输出N个张量沿axis连接的结果。 | 
| OH_NN_OPS_CONV2D | 二维卷积层。<br/>如果输入中含有padMode参数：<br/>输入：<br/>- input，输入张量。<br/>- weight，卷积的权重，要求weight排布为[outChannel，kernelHeight，kernelWidth，inChannel/group]， inChannel必须要能整除group。<br/>- bias，卷积的偏置，是长度为[outChannel]的数组。在量化场景下，bias参数不需要量化参数，其量化 版本要求输入 OH_NN_INT32类型数据，实际量化参数由input和weight共同决定。<br/>参数：<br/>- stride，卷积核在height和weight上的步幅，是一个长度为2的int数组[strideHeight，strideWidth]。<br/>- dilation，表示扩张卷积在height和weight上的扩张率，是一个长度为2的int数组[dilationHeight，dilationWidth]， 值必须大于或等于1，并且不能超过input的height和width。<br/>- padMode，input的填充模式，支持same和valid，int类型，0表示same，1表示valid。 same，输出的高度和宽度与input相同，填充总数将在水平和垂直方向计算，并在可能的情况下均匀分布到顶部和底部、左侧 和右侧。否则，最后一个额外的填充将从底部和右侧完成。 Valid，输出的可能最大高度和宽度将在不填充的情况下返回。额外的像素将被丢弃。<br/>- group，将input按inChannel分组，int类型。group等于1，这是常规卷积；group大于1且小于或等于inChannel，这是分组卷积。<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>如果输入中含有padList参数：<br/>输入：<br/>- input，输入张量。<br/>- weight，卷积的权重，要求weight排布为[outChannel，kernelHeight，kernelWidth，inChannel/group]， inChannel必须要能整除group。<br/>- bias，卷积的偏置，是长度为[outChannel]的数组。在量化场景下，bias 参数不需要量化参数，其量化 版本要求输入 OH_NN_INT32类型数据，实际量化参数由input和weight共同决定。<br/>参数：<br/>- stride，卷积核在height和weight上的步幅，是一个长度为2的int数组[strideHeight，strideWidth]。<br/>- dilation，表示扩张卷积在height和weight上的扩张率，是一个长度为2的int数组[dilationHeight，dilationWidth]。 值必须大于或等于1，并且不能超过input的height和width。<br/>- padList，input周围的填充，是一个长度为4的int数组[top，bottom，left，right]。<br/>- group，将input按inChannel分组，int类型。 group等于1，这是常规卷积。 group等于inChannel，这是depthwiseConv2d，此时group==inChannel==outChannel。 group大于1且小于inChannel，这是分组卷积，outChannel==group。<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>输出：<br/>- output，卷积计算结果。 | 
| OH_NN_OPS_CONV2D_TRANSPOSE | 二维卷积转置。<br/>如果输入中含有padMode参数：<br/>输入：<br/>- input，输入张量。<br/>- weight，卷积的权重，要求weight排布为[outChannel，kernelHeight，kernelWidth，inChannel/group]， inChannel必须要能整除group。<br/>- bias，卷积的偏置，是长度为[outChannel]的数组。在量化场景下，bias 参数不需要量化参数，其量化 版本要求输入 OH_NN_INT32 类型数据，实际量化参数由input和weight共同决定。<br/>- stride，卷积核在height和weight上的步幅，是一个长度为2的int数组[strideHeight，strideWidth]。<br/>参数：<br/>- dilation，表示扩张卷积在height和weight上的扩张率，是一个长度为2的int数组[dilationHeight，dilationWidth]。 值必须大于或等于1，并且不能超过input的height和width。<br/>- padMode，input的填充模式，支持same和valid，int类型，0表示same，1表示valid。 same，输出的高度和宽度与input相同，填充总数将在水平和垂直方向计算，并在可能的情况下均匀分布到顶部和底部、左侧 和右侧。否则，最后一个额外的填充将从底部和右侧完成。 Valid，输出的可能最大高度和宽度将在不填充的情况下返回。额外的像素将被丢弃。<br/>- group，将input按inChannel分组，int类型。group等于1，这是常规卷积；group大于1且小于或等于inChannel，这是分组卷积。<br/>- outputPads，一个整数或元组/2 个整数的列表，指定沿输出张量的高度和宽度的填充量。可以是单个整数，用于为所 有空间维度指定相同的值。沿给定维度的输出填充量必须小于沿同一维度的步幅。<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>如果输入中含有padList参数：<br/>输入：<br/>- input，输入张量。<br/>- weight，卷积的权重，要求weight排布为[outChannel，kernelHeight，kernelWidth，inChannel/group]， inChannel必须要能整除group。<br/>- bias，卷积的偏置，是长度为[outChannel]的数组。在量化场景下，bias 参数不需要量化参数，其量化 版本要求输入 OH_NN_INT32类型数据，实际量化参数由input和weight共同决定。<br/>参数：<br/>- stride，卷积核在height和weight上的步幅，是一个长度为2的int数组[strideHeight，strideWidth]。<br/>- dilation，表示扩张卷积在height和weight上的扩张率，是一个长度为2的int数组[dilationHeight，dilationWidth]。 值必须大于或等于1，并且不能超过input的height和width。<br/>- padList，input周围的填充，是一个长度为4的int数组[top，bottom，left，right]。<br/>- group，将input按inChannel分组，int类型。group等于1，这是常规卷积；group大于1且小于或等于inChannel，这是分组卷积。<br/>- outputPads，一个整数或元组/2 个整数的列表，指定沿输出张量的高度和宽度的填充量。可以是单个整数，用于为所 有空间维度指定相同的值。沿给定维度的输出填充量必须小于沿同一维度的步幅。<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>输出：<br/>- output，卷积转置后的计算结果。 | 
| OH_NN_OPS_DEPTHWISE_CONV2D_NATIVE | 二维深度可分离卷积。<br/>如果输入中含有padMode参数：<br/>输入：<br/>- input，输入张量。<br/>- weight，卷积的权重，要求weight排布为[outChannel，kernelHeight，kernelWidth，1]，outChannel = channelMultiplier \* inChannel。<br/>- bias，卷积的偏置，是长度为[outChannel]的数组。在量化场景下，bias参数不需要量化参数，其量化 版本要求输入 OH_NN_INT32类型数据，实际量化参数由input和weight共同决定。<br/>参数：<br/>- stride，卷积核在height和weight上的步幅，是一个长度为2的int数组[strideHeight，strideWidth]。<br/>- dilation，表示扩张卷积在height和weight上的扩张率，是一个长度为2的int数组[dilationHeight，dilationWidth]。 值必须大于或等于1，并且不能超过input的height和width。<br/>- padMode，input的填充模式，支持same和valid，int类型，0表示same，1表示valid。 same，输出的高度和宽度与input相同，填充总数将在水平和垂直方向计算，并在可能的情况下均匀分布到顶部和底部、左侧 和右侧。否则，最后一个额外的填充将从底部和右侧完成。 Valid，输出的可能最大高度和宽度将在不填充的情况下返回。额外的像素将被丢弃。<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>如果输入中含有padList 参数：<br/>输入：<br/>- input，输入张量。<br/>- weight，卷积的权重，要求weight排布为[outChannel，kernelHeight，kernelWidth，1]，outChannel = channelMultiplier \* inChannel。<br/>- bias，卷积的偏置，是长度为[outChannel]的数组。在量化场景下，bias 参数不需要量化参数，其量化 版本要求输入 OH_NN_INT32 类型数据，实际量化参数由input和weight共同决定。<br/>参数：<br/>- stride，卷积核在height和weight上的步幅，是一个长度为2的int数组[strideHeight，strideWidth]。<br/>- dilation，表示扩张卷积在height和weight上的扩张率，是一个长度为2的int数组[dilationHeight，dilationWidth]。 值必须大于或等于1，并且不能超过input的height和width。<br/>- padList，input周围的填充，是一个长度为4的int数组[top，bottom，left，right]。<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>输出：<br/>- output，卷积计算的结果。 | 
| OH_NN_OPS_DIV | 对输入的两个标量或张量做除法。<br/>输入：<br/>- input1，第一个输入是标量或布尔值或数据类型为数字或布尔值的张量。<br/>- input2，数据类型根据input1的类型，要求有所不同： 当第一个输入是张量时，第二个输入可以是实数或布尔值或数据类型为实数/布尔值的张量。 当第一个输入是实数或布尔值时，第二个输入必须是数据类型为实数/布尔值的张量。<br/>参数：<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>输出：<br/>- output，input1和input2相除的结果。 | 
| OH_NN_OPS_ELTWISE | 设置参数对输入进行product(点乘)、sum(相加减)或max(取大值)。<br/>输入：<br/>- input1，第一个输入张量。<br/>- input2，第二个输入张量。<br/>参数：<br/>- mode，枚举，选择操作方式。<br/>输出：<br/>- output，计算后的结果，output和input1拥有相同的数据类型和形状。 | 
| OH_NN_OPS_EXPAND_DIMS | 在给定维度上为张量添加一个额外的维度。<br/>输入：<br/>- input，输入张量。<br/>- axis，需要添加的维度的index，int32_t类型，值必须在[-dim-1，dim]，且只允许常量值。<br/>输出：<br/>- output，维度拓展后的张量。 | 
| OH_NN_OPS_FILL | 根据指定的维度，创建由一个标量填充的张量。<br/>输入：<br/>- value，填充的标量。<br/>- shape，指定创建张量的形状。<br/>输出：<br/>- output，生成的张量，和value具有相同的数据类型，张量形状由shape参数指定。 |
| OH_NN_OPS_FULL_CONNECTION | 全连接，整个输入作为feature map，进行特征提取。<br/>输入：<br/>- input，全连接的输入张量。<br/>- weight，全连接的权重张量。<br/>- bias，全连接的偏置，在量化场景下，bias 参数不需要量化参数，其量化 版本要求输入OH_NN_INT32类型数据，实际量化参数由input和weight共同决定。<br/>参数：<br/>- hasBias，bool值，是否使用bias偏置。<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>输出：<br/>- output，输出运算后的张量。<br/>如果输入中含有axis参数或useAxis参数：<br/>输入：<br/>- input，全连接的输入张量。<br/>- weight，全连接的权重张量。<br/>- bias，全连接的偏置，在量化场景下，bias 参数不需要量化参数，其量化 版本要求输入 OH_NN_INT32 类型数据，实际量化参数由input和weight共同决定。<br/>参数：<br/>- axis，默认0，input做全连接的轴，从指定轴axis开始，将axis和axis后面的轴展开成一维去做全连接。<br/>- useAxis，bool值，是否使用axis参数，默认false，如果用户设置axis参数，则useAxis自动调整为true； 如果用户设置useAxis为true不指定axis，使用默认axis执行展开全连接，不支持用户同时设置useAxis为false并指定axis参数。<br/>- hasBias，bool值，是否使用bias偏置。<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>输出：<br/>- output，输出运算后的张量。 | 
| OH_NN_OPS_GATHER | 根据指定的索引和轴返回输入张量的切片。<br/>输入：<br/>- input，输入待切片的张量。<br/>- inputIndices，指定input在axis上的索引，是一个int类型的数组，值必须在[0,input.shape[axis])范围内。<br/>- axis，input被切片的轴，int32_t类型的数组，数组长度为1。<br/>输出：<br/>- output，输出切片后的张量。 | 
| OH_NN_OPS_HSWISH | 计算输入的Hardswish激活值。<br/>输入：<br/>- 一个n维输入张量。<br/>输出：<br/>- n维Hardswish激活值，数据类型和shape和input一致。 | 
| OH_NN_OPS_LESS_EQUAL | 对input1和input2，计算每对元素的input1[i]&lt;=input2[i]的结果，i是输入张量中每个元素的索引。<br/>输入：<br/>- input1，可以是实数、布尔值或数据类型是实数/OH_NN_BOOL的张量。<br/>- input2，如果input1是张量，input2可以是实数、布尔值，否则只能是张量，其数据类型是实数/OH_NN_BOOL。<br/>输出：<br/>- output，数据类型为OH_NN_BOOL的张量，使用量化模型时，output的量化参数不可省略，但量化参数的数值不会对输入结果产生影响。 | 
| OH_NN_OPS_MATMUL | 计算input1和input2的内积。<br/>输入：<br/>- input1，n维输入张量。<br/>- input2，n维输入张量。<br/>参数：<br/>- TransposeX，布尔值，是否对input1进行转置。<br/>- TransposeY，布尔值，是否对input2进行转置。<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>输出：<br/>- output，计算得到内积，当type!=OH_NN_UNKNOWN时，output数据类型由type决定；当type==OH_NN_UNKNOWN时， output的数据类型取决于inputX和inputY进行计算时转化的数据类型。 | 
| OH_NN_OPS_MAXIMUM | 计算input1和input2对应元素最大值，input1和input2的输入遵守隐式类型转换规则，使数据类型一致。输入必须 是两个张量或一个张量和一个标量。当输入是两个张量时，它们的数据类型不能同时为OH_NN_BOOL。它们的形状支持 broadcast成相同的大小。当输入是一个张量和一个标量时，标量只能是一个常数。<br/>输入：<br/>- input1，n维输入张量，实数或OH_NN_BOOL类型。<br/>- input2，n维输入张量，实数或OH_NN_BOOL类型。<br/>输出：<br/>- output，n维输出张量，output的shape和数据类型和两个input中精度或者位数高的相同。 | 
| OH_NN_OPS_MAX_POOL | 在输入张量上应用 2D 最大值池化。<br/>如果输入中含有padMode参数：<br/>输入：<br/>- input，一个张量。<br/>参数：<br/>- kernelSize，用来取最大值的kernel大小，是一个长度为2的int数组[kernelHeight，kernelWeight]， 第一个数表示kernel高度，第二个数表示kernel宽度。<br/>- strides，kernel移动的距离，是一个长度为2的int数组[strideHeight，strideWeight]， 第一个数表示高度上的移动步幅，第二个数表示宽度上的移动步幅。<br/>- padMode，填充模式，int类型的可选值，0表示same，1表示valid，并且以最近邻的值填充。 same，输出的高度和宽度与input相同，填充总数将在水平和垂直方向计算，并在可能的情况下均匀分布到顶部 和底部、左侧和右侧。否则，最后一个额外的填充将从底部和右侧完成。 valid，输出的可能最大高度和宽度将在不填充的情况下返回。额外的像素将被丢弃。<br/>- roundMode，边界处理方式，int类型的可选值，当池化核不能完全覆盖输入特征图时， 对输出特征图进行取整的方式，0表示向下取整，1表示向上取整。<br/>- global，bool值，是否对整个输入张量进行平均池化操作。<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>如果输入中含有padList参数：<br/>输入：<br/>- input，一个张量。<br/>参数：<br/>- kernelSize，用来取最大值的kernel大小，是一个长度为2的int数组[kernelHeight，kernelWeight]， 第一个数表示kernel高度，第二个数表示kernel宽度。<br/>- strides，kernel移动的距离，是一个长度为2的int数组[strideHeight，strideWeight]， 第一个数表示高度上的移动步幅，第二个数表示宽度上的移动步幅。<br/>- padList，input周围的填充，是一个长度为4的int数组[top，bottom，left，right]，并且以最近邻的值填充。<br/>- roundMode，边界处理方式，int类型的可选值，当池化核不能完全覆盖输入特征图时， 对输出特征图进行取整的方式，0表示向下取整，1表示向上取整。<br/>- global，bool值，是否对整个输入张量进行平均池化操作。<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>输出：<br/>- output，对input最大值池化后的张量。 | 
| OH_NN_OPS_MUL | 将input1和input2相同的位置的元素相乘得到output。如果input1和input2的shape不同，要求input1和input2可以 通过broadcast扩充成相同的shape进行相乘。<br/>输入：<br/>- input1，一个n维张量。<br/>- input2，一个n维张量。<br/>参数：<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>输出：<br/>- output，input1和input2每个元素的乘积。 | 
| OH_NN_OPS_ONE_HOT | 根据indices指定的位置，生成一个由one-hot向量构成的张量。每个onehot向量中的有效值由onValue决定，其他位置由offValue决定。<br/>输入：<br/>- indices，n维张量。indices中每个元素决定每个one-hot向量，onValue的位置。<br/>- depth，一个整型标量，决定one-hot向量的深度。要求depth&gt;0。<br/>- onValue，一个标量，指定one-hot向量中的有效值。<br/>- offValue，一个标量，指定one-hot向量中除有效位以外，其他位置的值。<br/>参数：<br/>- axis，一个整型标量，指定插入one-hot的维度。 indices的形状是[N，C]，depth的值是D，当axis=0时，output形状为[D，N，C]， indices的形状是[N，C]，depth的值是D，当axis=-1时，output形状为[N，C，D]， indices的形状是[N，C]，depth的值是D，当axis=1时，output形状为[N，D，C]。<br/>输出：<br/>- output，如果indices时n维张量，则output是(n+1)维张量。output的形状由indices和axis共同决定。 | 
| OH_NN_OPS_PAD | 在inputX指定维度的数据前后，添加指定数值进行增广。<br/>输入：<br/>- inputX，一个n维张量，要求inputX的排布为[BatchSize，…]。<br/>- paddings，一个二维张量，指定每一维度增补的长度，shape为[n，2]。paddings[i][0]表示第i维上，需要在inputX前增补的数量； paddings[i][1]表示第i维上，需要在inputX后增补的数量。<br/>参数：<br/>- constantValues，一个常数，数据类型和inputX一致，指定Pad操作补全的数值。<br/>- paddingMode，指定填充模式，OH_NN_INT32类型， 0表示使用常量0填充，1表示镜像填充(不包含对称轴)，2表示镜像填充(包含对称轴)，3为预留填充方式。<br/>输出：<br/>- output，一个n维张量，维数和数据类型和inputX保持一致。shape由inputX和paddings共同决定 output.shape[i] = input.shape[i] + paddings[i][0]+paddings[i][1]。 | 
| OH_NN_OPS_POW | 求input的y次幂，输入必须是两个张量或一个张量和一个标量。当输入是两个张量时，它们的数据类型不能同时为OH_NN_BOOL， 且要求两个张量的shape相同。当输入是一个张量和一个标量时，标量只能是一个常数。<br/>输入：<br/>- input，实数、bool值或张量，张量的数据类型为实数/OH_NN_BOOL。<br/>- y，实数、bool值或张量，张量的数据类型为实数/OH_NN_BOOL。<br/>参数：<br/>- scale，一个OH_NN_FLOAT32标量，表示缩放融合的因子。<br/>- shift，一个OH_NN_FLOAT32标量，表示缩放融合的偏置。<br/>输出：<br/>- output，形状由input和y broadcast后的形状决定。 | 
| OH_NN_OPS_SCALE | 给定一个张量，计算其缩放后的值。<br/>输入：<br/>- input，一个n维张量。<br/>- scale，缩放张量。<br/>- bias，偏置张量。<br/>参数：<br/>- axis，指定缩放的维度。<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>输出：<br/>- output，scale的计算结果，一个n维张量，类型和input一致，shape由axis决定。 | 
| OH_NN_OPS_SHAPE | 输入一个张量，计算其shape。<br/>输入：<br/>- input，一个n维张量。<br/>输出：<br/>- output，输出张量的维度，一个整型数组。 | 
| OH_NN_OPS_SIGMOID | 给定一个张量，计算其sigmoid结果。<br/>输入：<br/>- input，一个n维张量。<br/>输出：<br/>- output，sigmoid的计算结果，一个n维张量，类型和shape和input一致。 | 
| OH_NN_OPS_SLICE | 在input 张量各维度，以begin为起点，截取size长度的切片。<br/>输入：<br/>- input，n维输入张量。<br/>- begin，一组不小于0的整数，指定每个维度上的起始切分点。<br/>- size，一组不小于1的整数，指定每个维度上切片的长度。假设某一维度i，1&lt;=size[i]&lt;=input.shape[i]-begin[i]。<br/>参数：<br/>- axes，指定切片的轴。<br/>输出：<br/>- output，切片得到的n维张量，其TensorType和input一致，shape和size相同。 | 
| OH_NN_OPS_SOFTMAX | 给定一个张量，计算其softmax结果。<br/>输入：<br/>- input，n维输入张量。<br/>参数：<br/>- axis，int64类型，指定计算softmax的维度。整数取值范围为[-n，n)。<br/>输出：<br/>- output，softmax的计算结果，一个n维张量，类型和shape和input一致。 | 
| OH_NN_OPS_SPACE_TO_BATCH_ND | 将4维张量在空间维度上进行切分成blockShape[0] \* blockShape[1]个小块，然后在batch维度上拼接这些小块。<br/>输入：<br/>- input，一个四维张量。<br/>参数：<br/>- blockShape，一对整数，每个整数不小于1。<br/>- paddings，一对数组，每个数组由两个整数组成。组成paddings的4个整数都不小于0。paddings[0][0]和paddings[0][1]指 定了第三个维度上padding的数量，paddings[1][0]和paddings[1][1]指定了第四个维度上padding的数量。<br/>输出：<br/>- output，一个4维张量，数据类型和input一致。shape由input，blockShape和paddings共同决定，假设input shape为[n，c，h，w]，则有 output.shape[0] = n \* blockShape[0] \* blockShape[1] output.shape[1] = c output.shape[2] = (h + paddings[0][0] + paddings[0][1]) / blockShape[0] output.shape[3] = (w + paddings[1][0] + paddings[1][1]) / blockShape[1] 要求(h + paddings[0][0] + paddings[0][1])和(w + paddings[1][0] + paddings[1][1])能被 blockShape[0]和blockShape[1]整除。 | 
| OH_NN_OPS_SPLIT | Split 算子沿 axis 维度将 input 拆分成多个 张量，张量 数量由 outputNum 指定。<br/>输入：<br/>- input，n维张量。<br/>参数：<br/>- outputNum，输出张量的数量，outputNum类型为int。<br/>- sizeSplits，一维张量，指定 张量 沿 axis 轴拆分后，每个 张量 的大小，sizeSplits 类型为 int。 如果 sizeSplits 的数据为空，则 张量 被拆分成大小均等的 张量，此时要求 input.shape[axis] 可以被 outputNum 整除； 如果 sizeSplits 不为空，则要求 sizeSplits 所有元素之和等于 input.shape[axis]。<br/>- axis，指定拆分的维度，axis类型为int。<br/>输出：<br/>- outputs，一组n维张量，每一个张量类型和shape相同，每个张量的类型和input一致。 | 
| OH_NN_OPS_SQRT | 给定一个张量，计算其平方根。<br/>输入：<br/>- input，一个n维张量。<br/>输出：<br/>- output，输入的平方根，一个n维张量，类型和shape和input一致。 | 
| OH_NN_OPS_SQUARED_DIFFERENCE | 计算两个输入的差值并返回差值的平方。SquaredDifference算子支持张量和张量相减。 如果两个张量的TensorType不相同，算子会将低精度的张量转成更高精度的类型。 如果两个张量的shape不同，要求两个张量可以通过broadcast拓展成相同shape的张量。<br/>输入：<br/>- input1，被减数，input1是一个张量，张量的类型可以是OH_NN_FLOAT16、OH_NN_FLOAT32、OH_NN_INT32或OH_NN_BOOL。<br/>- input2，减数，input2是一个张量，张量的类型可以是OH_NN_FLOAT16、OH_NN_FLOAT32、OH_NN_INT32或OH_NN_BOOL。<br/>输出：<br/>- output，两个输入差值的平方。output的shape由input1和input2共同决定，input1和input2的shape相同时， output的shape和input1、input2相同；shape不同时，需要将input1或input2做broadcast操作后，相减得到output。 output的TensorType由两个输入中更高精度的TensorType决定。 | 
| OH_NN_OPS_SQUEEZE | 去除axis中，长度为1的维度。支持int8量化输入假设input的shape为[2，1，1，2，2]，axis为[0,1]， 则output的shape为[2，1，2，2]。第0维到第一维之间，长度为0的维度被去除。<br/>输入：<br/>- input，n维张量。<br/>参数：<br/>- axis，指定删除的维度。axis可以是一个int64_t的整数或数组，整数的取值范围为[-n，n)。<br/>输出：<br/>- output，输出张量。 | 
| OH_NN_OPS_STACK | 将一组张量沿axis维度进行堆叠，堆叠前每个张量的维数为n，则堆叠后output维数为n+1。<br/>输入：<br/>- input，Stack支持传入多个输入n维张量，每个张量要求shape相同且类型相同。<br/>参数：<br/>- axis，一个整数，指定张量堆叠的维度。axis可以是负数，axis取值范围为[-(n+1)，(n+1))。<br/>输出：<br/>- output，将input沿axis维度堆叠的输出，n+1维张量，TensorType和input相同。 | 
| OH_NN_OPS_STRIDED_SLICE | 跨步截取张量。<br/>输入：<br/>- input，n维输入张量。<br/>- begin，一维张量，begin的长度等于n，begin[i]指定第i维上截取的起点。<br/>- end，一维张量，end的长度等于n，end[i]指定第i维上截取的终点。<br/>- strides，一维张量，strides的长度等于n，strides[i]指定第i维上截取的步长。<br/>参数：<br/>- beginMask，一个整数，用于解除begin的限制。将beginMask转成二进制表示，如果binary(beginMask)[i]==1， 则对于第i维，从第一个元素开始，以strides[i]为步长截取元素直到第end[i]-1个元素。<br/>- endMask，一个整数，用于解除end的限制。将endMask转成二进制表示，如果binary(endMask)[i]==1，则对于第i维， 从第begin[i]个元素起，以strides[i]为步长截取元素直到张量边界。<br/>- ellipsisMask，一个整数，用于解除begin和end的限制。将ellipsisMask转成二进制表示，如果binary(ellipsisMask)[i]==1， 则对于第i维，从第一个元素开始，以strides[i]为补偿，截取元素直到张量边界。binary(ellipsisMask)仅允许有一位不为0。<br/>- newAxisMask，一个整数，用于新增维度。将newAxisMask转成二进制表示，如果binary(newAxisMask)[i]==1，则在第i维插入长度为1的新维度。<br/>- shrinkAxisMask，一个整数，用于压缩指定维度。将shrinkAxisMask转成二进制表示，如果binary(shrinkAxisMask)[i]==1， 则舍去第i维所有元素，第i维长度压缩至1。<br/>输出：<br/>- 堆叠运算后的张量，数据类型与input相同。输出维度rank(input[0])+1 维。 | 
| OH_NN_OPS_SUB | 计算两个输入的差值。<br/>输入：<br/>- input1，被减数，input1是一个张量。<br/>- input2，减数，input2是一个张量。<br/>参数：<br/>- activationType，是一个整型常量，且必须是OH_NN_FuseType中含有的值。 在输出之前调用指定的激活。<br/>输出：<br/>- output，两个输入相减的差。output的shape由input1和input2共同决定，当input1和input2的shape相同时，output的shape和input1、input2相同； shape不同时，需要将input1或input2做broadcast操作后，相减得到output。output的TensorType由两个输入中更高精度的TensorType决定。 | 
| OH_NN_OPS_TANH | 计算输入张量的双曲正切值。<br/>输入：<br/>- input，n维张量。<br/>输出：<br/>- output，input的双曲正切，TensorType和张量 shape和input相同。 | 
| OH_NN_OPS_TILE | 以multiples指定的次数拷贝input。<br/>输入：<br/>- input，n维张量。<br/>- multiples，一维张量，指定各个维度拷贝的次数。其长度m不小于input的维数n。<br/>参数：<br/>- dims，1维张量，指定需要复制的维度的索引。<br/>输出：<br/>- output，m维张量，TensorType与input相同。如果input和multiples长度相同， 则output和input维数一致，都是n维张量；如果multiples长度大于n，则用1填充input的维度， 再在各个维度上拷贝相应的次数，得到m维张量。 | 
| OH_NN_OPS_TRANSPOSE | 根据permutation对input进行数据重排。<br/>输入：<br/>- input，n维张量，待重排的张量。<br/>- perm，一维张量，其长度和input的维数一致。<br/>输出：<br/>- output，n维张量，output的TensorType与input相同，shape由input的shape和permutation共同决定。 | 
| OH_NN_OPS_REDUCE_MEAN | keepDims为false时，计算指定维度上的平均值，减少input的维数；当keepDims为true时，计算指定维度上的平均值，保留相应的维度。<br/>输入：<br/>- input，n维输入张量，n&lt;8。<br/>- axis，一维张量，指定计算均值的维度，axis中每个元素的取值范围为[-n，n)。<br/>参数：<br/>- keepDims，布尔值，是否保留维度的标志位。<br/>- reduceToEnd，bool值，是否需要执行reduce操作直到最后一轴。<br/>- coeff，一个OH_NN_FLOAT32标量，表示输出的缩放因子。<br/>输出：<br/>- output，m维输出张量，数据类型和input相同。当keepDims为false时，m&lt;n；当keepDims为true时，m==n。 | 
| OH_NN_OPS_RESIZE_BILINEAR | 采用Bilinear方法，按给定的参数对input进行变形。<br/>输入：<br/>- input，四维输入张量，input中的每个元素不能小于0。input排布必须是[batchSize，height，width，channels]。<br/>参数：<br/>- newHeight，resize之后4维张量的height值。<br/>- newWidth，resize之后4维张量的width值。<br/>- preserveAspectRatio，一个布尔值，指示resize操作是否保持input 张量的height/width比例。<br/>- coordinateTransformMode，一个int32整数，指示Resize操作所使用的坐标变换方法， 目前支持以下方法：0表示“ASYMMETRIC”，1表示“ALIGN_CORNERS”，2表示“HALF_PIXEL”。<br/>- excludeOutside，一个int64浮点数。当excludeOutside=1时，超出input边界的采样权重被置为0，其余权重重新归一化处理。<br/>输出：<br/>- output，n维输出张量，output的shape和数据类型和input相同。 | 
| OH_NN_OPS_RSQRT | 求input平方根的倒数。<br/>输入：<br/>- input，n维输入张量，input中的每个元素不能小于0，n&lt;8。<br/>输出：<br/>- output，n维输出张量，output的shape和数据类型和input相同。 | 
| OH_NN_OPS_RESHAPE | 根据inputShape调整input的形状。<br/>输入：<br/>- input，一个n维输入张量。<br/>- inputShape，一个一维张量，表示输出张量的shape，需要是一个常量张量。<br/>输出：<br/>- output，输出张量，数据类型和input一致，shape由inputShape决定。 | 
| OH_NN_OPS_PRELU | 计算input和weight的PReLU激活值。<br/>输入：<br/>- input，一个n维张量，如果n&gt;=2，则要求inputX的排布为[BatchSize，…，Channels]，第二个维度为通道数。<br/>- weight，一个一维张量。weight的长度只能是1或者等于通道数。当weight长度为1，则input所有通道共享一个权重值。 若weight长度等于通道数，每个通道独享一个权重，若input维数n&lt;2，weight长度只能为1。<br/>输出：<br/>output，input的PReLU激活值。形状和数据类型和input保持一致。 | 
| OH_NN_OPS_RELU | 计算input的Relu激活值。<br/>输入：<br/>- input，一个n维输入张量。<br/>输出：<br/>- output，n维Relu输出张量，数据类型和shape和input一致。 | 
| OH_NN_OPS_RELU6 | 计算input的Relu6激活值，即对input中每个元素x，计算min(max(x，0)，6)。<br/>输入：<br/>- input，一个n维输入张量。<br/>输出：<br/>- output，n维Relu6输出张量，数据类型和shape和input一致。 | 
| OH_NN_OPS_LAYER_NORM | 对一个张量从某一axis开始做层归一化。<br/>输入：<br/>- input，一个n维输入张量。<br/>- gamma，一个m维张量，gamma维度应该与input做归一化部分的shape一致。<br/>- beta，一个m维张量，shape与gamma一样。<br/>参数：<br/>- beginAxis，是一个OH_NN_INT32的标量，指定开始做归一化的轴，取值范围是[1，rank(input))。<br/>- epsilon，是一个OH_NN_FLOAT32的标量，是归一化公式中的微小量，常用值是1e-5。<br/>- beginParamsAxis，指定输入(gamma, beta)需要进行层归一化的开始轴。<br/>输出：<br/>- output，n维输出张量，数据类型和shape和input一致。 | 
| OH_NN_OPS_REDUCE_PROD | 沿着axis指定的维度，计算input的累积值。<br/>输入：<br/>- input，n维输入张量，n&lt;8。<br/>- axis，一维张量，指定计算乘的维度，axis中每个元素的取值范围为[-n，n)。<br/>参数：<br/>- keepDims，布尔值，是否保留维度的标志位。当keepDims为true时，output的维数和input保持一致；当keepDims为false时， output的维数缩减。<br/>- reduceToEnd，bool值，是否需要执行reduce操作直到最后一轴。<br/>- coeff，一个OH_NN_FLOAT32标量，表示输出的缩放因子。<br/>输出：<br/>- output，m维输出张量，数据类型和input相同。当keepDims为false时，m&lt;n；当keepDims为true时，m==n。 | 
| OH_NN_OPS_REDUCE_ALL | 计算指定维度上的逻辑与。当keepDims为false时，减少input的维数；当keepDims为true时，保留相应的维度。<br/>输入：<br/>- n维输入张量，n&lt;8。<br/>- 一维张量，指定计算逻辑与的维度，axis中每个元素的取值范围为[-n，n)。<br/>参数：<br/>- keepDims，布尔值，是否保留维度的标志位。<br/>- reduceToEnd，bool值，是否需要执行reduce操作直到最后一轴。<br/>- coeff，一个OH_NN_FLOAT32标量，表示输出的缩放因子。<br/>输出：<br/>- output，m维输出张量，数据类型和input相同。当keepDims为false时，m&lt;n；当keepDims为true时，m==n。 | 
| OH_NN_OPS_QUANT_DTYPE_CAST | 数据类型转换。<br/>输入：<br/>- input，n维张量，如果是量化类型和浮点类型之间的转换，输入张量应包含量化参数。<br/>参数：<br/>- srcT，定义输入的数据类型。<br/>- dstT，定义输出的数据类型。<br/>- axis，指定提取量化参数的维度，如果输入张量量化参数的size为1，算子功能是层量化转换，该参数不生效； 如果输入张量量化参数的size大于1，算子功能是通道量化转换，该参数生效。<br/>输出：<br/>- output，n维张量，数据类型由dstT决定 输出shape和输入相同。 | 
| OH_NN_OPS_TOP_K | 查找沿最后一个维度的k个最大条目的值和索引。<br/>输入：<br/>- input，n维张量。<br/>- k，指明是得到前k个数据以及其index。<br/>参数：<br/>- sorted，如果为true，按照大到小排序，如果为false，按照小到大排序。<br/>- axis，一个OH_NN_INT32标量，指定需要排序的维度，默认-1，指向最后一个维度。<br/>输出：<br/>- output0,最后一维的每个切片中的k个最大元素。<br/>- output1，输入的最后一个维度内的值的索引。 | 
| OH_NN_OPS_ARG_MAX | 返回跨轴的张量最大值的索引。<br/>输入：<br/>- input，n维张量，输入张量(N，∗)，其中∗意味着任意数量的附加维度。<br/>参数：<br/>- axis，指定求最大值索引的维度。<br/>- keepDims，bool值，是否维持输入张量维度。<br/>- topK，要返回最大值的数量，默认为1，当topK等于1时，将返回输入张量中最大值的索引；当topK大于1时，返回输入张量中前topK个最大值的索引。 如果输入张量中有多个值相同且都是最大值，则返回其中任意一个。<br/>- outMaxValue，是否输出最大值，默认为false。<br/>输出：<br/>- output，张量，轴上输入张量最大值的索引。 | 
| OH_NN_OPS_UNSQUEEZE | 根据输入axis的值。增加一个维度。<br/>输入：<br/>- input，n维张量。<br/>参数：<br/>- axis，指定增加的维度。axis可以是一个整数或一组整数，整数的取值范围为[-n，n)。<br/>输出：<br/>- output，输出张量。 | 
| OH_NN_OPS_GELU | 高斯误差线性单元激活函数。output=0.5∗input∗(1+tanh(input/2))，不支持int量化输入。<br/>输入：<br/>- 一个n维输入张量。<br/>参数：<br/>- approximate，bool值，近似函数的选项，值为true时，近似函数为Tanh函数，值为false时，近似函数为Erf函数。<br/>输出：<br/>- output，n维Relu输出张量，数据类型和shape和input一致。 | 
| OH_NN_OPS_UNSTACK<sup>12+</sup> | 把输入张量按照axis轴分解。<br/>输入：<br/>- input，n维张量。<br/>参数：<br/>- axis，一个OH_NN_INT32标量，指定矩阵分解的轴，取值范围是[-n，n)。<br/>输出：<br/>- output，从输入分解出来的多个张量，每个张量的形状相同。 | 
| OH_NN_OPS_ABS<sup>12+</sup> | 计算输入数据的绝对值。<br/>输入：<br/>- input，n维张量。<br/>输出：<br/>- output，n维张量，形状、数据类型与输入保持一致。 | 
| OH_NN_OPS_ERF<sup>12+</sup> | 高斯误差函数，对输入数据逐元素做误差计算。<br/>输入：<br/>- input，n维张量，维度必须小于8，数据类型仅支持OH_NN_FLOAT32和OH_NN_FLOAT16。<br/>输出：<br/>- output，n维张量，数据类型和形状与输入相同。 | 
| OH_NN_OPS_EXP<sup>12+</sup> | 逐元素计算输入的指数。计算公式为 output = base ^ (shift + scale \* input)，其中要求底数base&gt;0， 默认为-1，表示底数为自然常数e。<br/>输入：<br/>- input，n维张量。<br/>参数：<br/>- base，指数函数的底数，默认-1，表示底数为自然常数e。<br/>- scale，指数的缩放因子，默认1。<br/>- shift，指数的偏置，默认0。<br/>输出：<br/>- output，n维张量，指数函数的输出结果。 | 
| OH_NN_OPS_LESS<sup>12+</sup> | 对input1和input2逐元素计算input1[i]&lt;input2[i]的结果，i是输入张量中每个元素的索引。<br/>输入：<br/>- input1，可以是实数、布尔值或数据类型是实数/OH_NN_BOOL的张量。<br/>- input2，如果input1是张量，input2可以是实数、布尔值，否则只能是张量，其数据类型是实数或OH_NN_BOOL。<br/>输出：<br/>- output，数据类型为OH_NN_BOOL的张量，使用量化模型时，output的量化参数不可省略，但量化参数的数值不会对输入结果产生影响。 | 
| OH_NN_OPS_SELECT<sup>12+</sup> | 根据输入条件逐元素判定输出是从输入1还是输入2中选取值；当条件为true时，从输入1中取元素； 当条件为false时，从输入2中取元素。当条件为张量时，三个输入的形状需要保持一致。<br/>输入：<br/>- condition，判定条件，实数或n维张量。<br/>- input1，待挑选的输入1。<br/>- input2，待挑选的输入2。<br/>输出：<br/>- output，n维张量，形状和数据类型和输入保持一致。 | 
| OH_NN_OPS_SQUARE<sup>12+</sup> | 逐元素计算输入的平方。<br/>输入：<br/>- input，n维张量。<br/>输出：<br/>- output，n维张量，数据类型和形状和输入一致。 | 
| OH_NN_OPS_FLATTEN<sup>12+</sup> | 指定axis轴将输入Tensor扁平化。<br/>输入：<br/>- input，n维张量。<br/>参数：<br/>- axis, 扁平化轴，将输入沿着axis维展平，对于输入维度为(d_0, d_1, ..., d_n)的张量， 输出的维度应为(d_0\*\d_1\*...\*d_(axis-1)， d_axis\*d_(axis+1)\*...\*d_n)。<br/>输出：<br/>- output，展平后的2维张量。 | 
| OH_NN_OPS_DEPTH_TO_SPACE<sup>12+</sup> | 将输入张量的深度数据块重新排列为空间维度。<br/>输入：<br/>- input，4维张量，NHWC或NCHW格式，目前仅支持NHWC，形状为[batchSize, height, width, channels]。<br/>参数：<br/>- blockSize，指定转换的块大小，必须是整数。<br/>- mode，指定转换的方式，0表示"DCR"，1表示"CRD"，"DCR"是深度-列-行顺序重排，"CRD"是列-行-深度顺序重排。<br/>输出：<br/>- output，4维张量，format格式和输入一致， 形状为[batchSize, height \* blockSize, weight \* blockSize, channel / blockSize^2]。 | 
| OH_NN_OPS_RANGE<sup>12+</sup> | 生成一个序列张量，其生成范围为[start, limit)，步长为delta。<br/>输入：<br/>- input，n维张量，输出的数据类型和输入保持一致。<br/>参数：<br/>- start，生成序列的起始数。<br/>- limit，生成序列的截止数，不包括该数值。<br/>- delta，步长，从生成序列范围中按步长跳过部分数据。<br/>输出：<br/>- output，生成的1维序列张量。 | 
| OH_NN_OPS_INSTANCE_NORM<sup>12+</sup> | 对输入的每个通道进行标准化处理，使得输入的每个通道的均值为0，方差为1。<br/>输入：<br/>- input，4维张量。<br/>- scale，1维张量，缩放系数，尺寸和输入的通道数一致。<br/>- bias，1维张量，偏置常量，尺寸和输入的通道数一致。<br/>参数：<br/>- epsilon，加在分母上一个很小的数值，保证计算稳定性。<br/>输出：<br/>- output，4维张量，形状与输入相同。 | 
| OH_NN_OPS_CONSTANT_OF_SHAPE<sup>12+</sup> | 生成一个指定shape的张量。<br/>输入：<br/>- input，1维张量，表示目标张量的shape。<br/>参数：<br/>- dataType，目标张量的数据类型。<br/>- value，目标张量的数值，数据类型为OH_NN_FLOAT32的单元素数组。<br/>输出：<br/>- output，生成的目标张量。 | 
| OH_NN_OPS_BROADCAST_TO<sup>12+</sup> | 把一个张量广播到适配的形状。<br/>输入：<br/>- input，n维张量。<br/>参数：<br/>- shape，1维张量。输出期望的形状。<br/>输出：<br/>- output，广播后的张量。 | 
| OH_NN_OPS_EQUAL<sup>12+</sup> | 对input1和input2逐元素计算input1[i] = input2[i]的结果，i是输入张量中每个元素的索引。<br/>输入：<br/>- input1，可以是实数、布尔值或数据类型是实数/OH_NN_BOOL的张量。<br/>- input2，如果input1是张量，input2可以是实数、布尔值，否则只能是张量，其数据类型是实数或OH_NN_BOOL。<br/>输出：<br/>- output，数据类型为OH_NN_BOOL的张量，使用量化模型时，output的量化参数不可省略，但量化参数的数值不会对输入结果产生影响。 | 
| OH_NN_OPS_GREATER<sup>12+</sup> | 对input1和input2逐元素计算input1[i]&gt;input2[i]的结果，i是输入张量中每个元素的索引。<br/>输入：<br/>- input1，可以是实数、布尔值或数据类型是实数/OH_NN_BOOL的张量。<br/>- input2，如果input1是张量，input2可以是实数、布尔值，否则只能是张量，其数据类型是实数或OH_NN_BOOL。<br/>输出：<br/>- output，数据类型为OH_NN_BOOL的张量，使用量化模型时，output的量化参数不可省略，但量化参数的数值不会对输入结果产生影响。 | 
| OH_NN_OPS_NOT_EQUAL<sup>12+</sup> | 对input1和input2逐元素计算input1[i] != input2[i]的结果，i是输入张量中每个元素的索引。<br/>输入：<br/>- input1，可以是实数、布尔值或数据类型是实数/OH_NN_BOOL的张量。<br/>- input2，如果input1是张量，input2可以是实数、布尔值，否则只能是张量，其数据类型是实数或OH_NN_BOOL。<br/>输出：<br/>- output，数据类型为OH_NN_BOOL的张量，使用量化模型时，output的量化参数不可省略，但量化参数的数值不会对输入结果产生影响。 | 
| OH_NN_OPS_GREATER_EQUAL<sup>12+</sup> | 对input1和input2逐元素计算input1[i]&gt;=input2[i]的结果，i是输入张量中每个元素的索引。<br/>输入：<br/>- input1，可以是实数、布尔值或数据类型是实数/OH_NN_BOOL的张量。<br/>- input2，如果input1是张量，input2可以是实数、布尔值，否则只能是张量，其数据类型是实数或OH_NN_BOOL。<br/>输出：<br/>- output，数据类型为OH_NN_BOOL的张量，使用量化模型时，output的量化参数不可省略，但量化参数的数值不会对输入结果产生影响。 | 
| OH_NN_OPS_LEAKY_RELU<sup>12+</sup> | 计算输入的leakyRelu激活值。<br/>输入：<br/>- input，n维张量。<br/>参数：<br/>- negativeSlope，当输入小于0时的斜率，控制输出的大小，数据类型为OH_NN_FLOAT32。<br/>输出：<br/>- output，n维张量，数据类型和形状和输入一致。 | 
| OH_NN_OPS_LSTM<sup>12+</sup> | 对输入执行长短期记忆(LSTM)网络计算。<br/>输入：<br/>- input，3维张量，形状为[seqLen, batchSize, inputSize]。<br/>- wIh，输入到隐藏层的权重参数，形状为[numDirections\*numLayers, 4\*hiddenSize, inputSize]。<br/>- wHh，隐藏层到隐藏层的权重参数，形状为[numDirections\*numLayers, 4\*hiddenSize, inputSize]。<br/>- bias，输入和隐藏层到隐藏层的偏置，形状为[numDirections\*numLayers, 8\*hiddenSize]。<br/>- hx，单元门的初始隐藏状态，形状为[numDirections\*numLayers, batchSize, hiddenSize]。<br/>- cx，单元门的初始细胞状态，形状为[numDirections\*numLayers, batchSize, hiddenSize]。<br/>参数：<br/>- bidirectional，bool值，是否为双向LSTM。<br/>- hasBias，bool值，单元门是否有偏置。<br/>- inputSize，输入的大小。<br/>- hiddenSize，隐藏层的状态大小。<br/>- numLayers，LSTM的网络层数。<br/>- numDirections，LSTM网络的方向数。<br/>- dropout，除第一层外每层输入被丢弃的概率[0.0, 1.0]。<br/>- zoneoutCell，控制单元保持上次状态的概率，默认为0。<br/>- zoneoutHidden，控制隐藏层状态保持上次的概率，默认为0。<br/>- projSize，如果该值&gt;0，使用LSTM的投影，默认0。<br/>输出：<br/>- output，3维张量，所有输出张量的通道拼接输出，形状为[seqLen, batchSize, numDirections\*realHiddenSize]。<br/>- hy，最后一层隐层的输出张量，形状是[numDirections\*numLayers, batchSize, realHiddenSize]。<br/>- cy，最后一层单元门的输出张量，形状是[numDirections\*numLayers, batchSize, HiddenSize]。 | 
| OH_NN_OPS_CLIP<sup>12+</sup> | 将输入张量的值裁剪到指定的最小值和最大值之间。<br/>输入：<br/>- input，n维张量或者张量的列表或元组，支持任意维度的张量。<br/>参数：<br/>- min，裁剪的最小值限制。<br/>- max，裁剪的最大值限制。<br/>输出：<br/>- output，数值裁剪后的张量，形状和数据类型和输入相同。 | 
| OH_NN_OPS_ALL<sup>12+</sup> | 判断输入中指定维度的所有元素是否都为非0值，如果都为非0值，则对应维度返回true，否则对应维度返回false。<br/>输入：<br/>- input，n维张量，形状为(N, \*)，其中\*表示任意数量的附加维度。<br/>- axis，1维张量，要计算的维度。<br/>参数：<br/>- keepDims，输出张量的维度是否保持。<br/>输出：<br/>- output，1维张量或n维张量，数值类型为OH_NN_BOOL，完成非0判断后的输出张量。 | 
| OH_NN_OPS_ASSERT<sup>12+</sup> | 断言给定条件是否为真，如果给定条件的结果为假，打印data中的张量列表，summarize用来确定要打印的张量的条目数量。<br/>输入：<br/>- condition，评估条件。<br/>- data，当条件为假时需要打印的张量。<br/>参数：<br/>- summarize，打印每个张量的条目数。<br/>输出：<br/>- output，如果条件不为真，返回Error。 | 
| OH_NN_OPS_COS<sup>12+</sup> | 逐元素计算输入数据的余弦值。<br/>输入：<br/>- input，n维张量，数值类型为OH_NN_FLOAT64、OH_NN_FLOAT32或OH_NN_FLOAT16。<br/>输出：<br/>- output，n维张量，形状和数据类型和输入相同。 | 
| OH_NN_OPS_LOG<sup>12+</sup> | 逐元素计算输入的自然对数。<br/>输入：<br/>- input，n维张量，数值必须大于0，数值类型为OH_NN_FLOAT64、OH_NN_FLOAT32或OH_NN_FLOAT16。<br/>输出：<br/>- output，n维张量，形状和数据类型和输入相同。 | 
| OH_NN_OPS_LOGICAL_AND<sup>12+</sup> | 逐元素计算两个输入张量的逻辑与运算。<br/>输入：<br/>- input1，n维张量，数值类型是OH_NN_BOOL。<br/>- input2，n维张量，数值类型是OH_NN_BOOL，形状与input1相同。<br/>输出：<br/>- output，n维张量，逻辑与的计算结果，数值类型是OH_NN_BOOL。 | 
| OH_NN_OPS_LOGICAL_NOT<sup>12+</sup> | 逐元素计算两个输入张量的逻辑非运算。<br/>输入：<br/>- input，n维张量，数值类型是OH_NN_BOOL。<br/>输出：<br/>- output，n维张量，逻辑非的计算结果，数值类型是OH_NN_BOOL。 | 
| OH_NN_OPS_MOD<sup>12+</sup> | 对输入张量做求余运算，input1和input2需要遵循数据类型转换的规则转成一致的数据类型； 输入必须是两个张量或一个张量和一个标量。当输入是两个张量时，数据类型都不能是OH_NN_BOOL， 可以广播为相同的形状；当输入是一个张量和一个标量时，标量输入只能是一个常量数值。<br/>输入：<br/>- input1，被求余的标量或张量，数值型或OH_NN_BOOL类型，或数值类型维数值型的n维张量。<br/>- input2，求余因子；当第一个输入是n维张量时，第二个输入可以是数值型、OH_NN_BOOL类型，或数值类型维数值型的n维张量； 当第一个输入是数值型、OH_NN_BOOL类型时，第二个输入必须是数据类型维数值型的张量。<br/>输出：<br/>- output，n维张量，形状与广播后的输入相同，数据类型为两个输入中精度较高的数据类型。 | 
| OH_NN_OPS_NEG<sup>12+</sup> | 逐元素计算输入的相反数。<br/>输入：<br/>- input，n维张量，数据类型为数值型。<br/>输出：<br/>- output，n维张量，形状和数据类型和输入一致。 | 
| OH_NN_OPS_RECIPROCAL<sup>12+</sup> | 逐元素计算输入的倒数。<br/>输入：<br/>- input，n维张量，数据类型为数值类型为OH_NN_FLOAT64、OH_NN_FLOAT32或OH_NN_FLOAT16。<br/>输出：<br/>- output，n维张量，形状和数据类型和输入一致。 | 
| OH_NN_OPS_SIN<sup>12+</sup> | 逐元素计算输入的正弦值。<br/>输入：<br/>- input，n维张量，数值类型为OH_NN_FLOAT64、OH_NN_FLOAT32或OH_NN_FLOAT16。<br/>输出：<br/>- output，n维张量，形状和数据类型和输入相同。 | 
| OH_NN_OPS_WHERE<sup>12+</sup> | 根据condition从input1和input2中选取合适的元素。<br/>输入：<br/>- condition，判定条件，数值类型为OH_NN_BOOL的n维张量；如果元素是true，则选取input1对应位置的元素， 如果为false，则选取input2对应位置的元素。<br/>- input1，待选择的n维张量。<br/>- input2，待选择的n维张量。<br/>输出：<br/>- output。 | 
| OH_NN_OPS_SPARSE_TO_DENSE<sup>12+</sup> | 将稀疏张量转换为密集张量。<br/>输入：<br/>- indices，2维张量，表示元素在稀疏张量中的位置。<br/>- values，1维张量，表示indices位置上对应的值。<br/>- sparseShape，稀疏张量的形状，由两个正整数组成，形状为(N, C)。<br/>输出：<br/>- output，转换后的张量，数据类型和value相同，形状由参数sparseShape指定。 | 
| OH_NN_OPS_LOGICAL_OR<sup>12+</sup> | 逐元素计算两个输入张量的逻辑或运算。<br/>输入：<br/>- input1，n维张量，数值类型是OH_NN_BOOL。<br/>- input2，n维张量，数值类型是OH_NN_BOOL，形状与输入1相同。<br/>输出：<br/>- output，n维张量，逻辑或的计算结果，数值类型是OH_NN_BOOL。 | 
| OH_NN_OPS_CEIL<sup>12+</sup> | 对输入的每个元素做向上取整。<br/>输入：<br/>- input，n维张量，数据类型为OH_NN_FLOAT64、OH_NN_FLOAT32或OH_NN_FLOAT16。<br/>输出：<br/>- n维张量，形状和数据类型与输入相同。 | 
| OH_NN_OPS_CROP<sup>12+</sup> | 对输入张量根据axis和offset参数裁剪指定shape大小的张量。<br/>输入：<br/>- input，n维待裁剪的张量。<br/>- shape，1维张量，表示要裁剪的张量大小。<br/>参数：<br/>- axis，裁剪区域开始的轴。取值范围为[0,1,...,r-1]，其中r是输入张量的秩，负数表示反向取值。<br/>- offset，裁剪区域的起始偏移量。<br/>输出：<br/>- output，裁剪后的张量。 | 
| OH_NN_OPS_DETECTION_POST_PROCESS<sup>12+</sup> | 对目标检测模型的输出进行后处理。包括对模型输出的边界框、类别概率和分数进行解码， 然后执行非极大值抑制（NMS）以去除重叠的边界框，最终输出检测结果。<br/>输入：<br/>- bbox，模型输出的边界框。<br/>- scores，模型输出的类别得分概率。<br/>- anchors，用于生成检测框的候选框的坐标和大小信息。在目标检测任务中，候选框指在图像中按照一定的规则预设的一系列矩形框， 这些矩形框通常具有不同的大小和长宽比，用于对图像中的目标进行初步的预测和筛选。<br/>参数：<br/>- inputSize，输入张量的尺寸。<br/>- scale，用于将输出图片从归一化的形式转换到原始图像坐标的缩放因子。<br/>- nmsIoUThreshold，非极大值抑制的阈值，用于去除重复的检测框。<br/>- nmsScoreThreshold，置信度阈值，用于过滤低置信度的检测框。<br/>- maxDetections，每张图片最多输出的检测框数量。<br/>- detectionsPerClass，每个类别的最大检测数量。<br/>- maxClassesPerDetection，每个检测框中的最大检测类别数。<br/>- numClasses，检测总类别数量。<br/>- useRegularNms，bool值，是否使用基于IoU阈值的非极大值抑制算法，当为true时，使用基于IoU阈值的NMS算法来过滤重叠的目标框， 保留得分最高的目标框；当为false时，不适用基于IoU阈值的NMS算法，进根据得分对目标框进行排序，保留最高得分的目标框。<br/>- outQuantized，bool值，表示输出是否需要做量化。<br/>输出：<br/>- bboxes，3维张量，内部数组表示目标检测框的坐标值。<br/>- classes，2维张量，内部数值表示每个检测框对应的分类索引。<br/>- confidences，2维张量，内部数值表示检测到的物体的置信度。<br/>- numDetections，检测结果的数量。 | 
| OH_NN_OPS_FLOOR<sup>12+</sup> | 对输入的每个元素做向下取整。<br/>输入：<br/>- input，n维张量，数据类型为OH_NN_FLOAT64、OH_NN_FLOAT32或OH_NN_FLOAT16。<br/>输出：<br/>- n维张量，形状和数据类型与输入相同。 | 
| OH_NN_OPS_L2_NORMALIZE<sup>12+</sup> | 根据指定的axis轴对输入张量做L2-正则化。<br/>输入：<br/>- input，需要做L2正则化的n维张量。<br/>参数：<br/>- axis，做正则化的指定维度，-1表示最后一个维度。<br/>- epsilon，保持计算稳定性，在分母上加上一个很小的数值，默认为1e-6。<br/>- activationType，激活函数类型。<br/>输出：<br/>- output，输出张量，和输入相同的数据类型和形状。 | 
| OH_NN_OPS_LOG_SOFTMAX<sup>12+</sup> | 对输入张量的每个元素做指数运算，然后将运算结果进行归一化处理，最终得到一个概率分布向量。<br/>输入：<br/>- 2维张量，形状为[batchSize，numClasses]，数据类型为OH_NN_FLOAT64、OH_NN_FLOAT32、OH_NN_FLOAT16。<br/>参数：<br/>- axis，指定进行计算的维度。<br/>输出：<br/>- output，2维张量，完成计算后的概率向量。 | 
| OH_NN_OPS_LRN<sup>12+</sup> | 对输入做局部响应归一化操作。<br/>输入：<br/>- input，4维张量，待归一化的输入张量。<br/>参数：<br/>- depthRadius，标量，归一化窗口的半宽。<br/>- bias，偏移量，通常为正避免除零问题，默认为1。<br/>- alpha，比例系数，默认为1。<br/>- beta，指数变量，默认为0.5。<br/>- normRegion，指定归一化的区域，默认0，代表归一化区域为"ACROSS_CHANNELS"，目前仅支持该模式。<br/>输出：<br/>- output，归一化的输出张量，形状和数据类型和输入相同。 | 
| OH_NN_OPS_MINIMUM<sup>12+</sup> | 逐元素计算两个张量的最小值，输入必须是两个张量，或一个张量和一个标量。当输入是两个张量是，数据类型不能同时是bool值， 并且两个要能广播到相同的形状。当输入是一个张量和一个常量时，标量必须是常量。<br/>输入：<br/>- input1，n维张量，数据类型可以是数值类型或bool值。<br/>- input2，n维张量，数据类型可以是数值类型或bool值。<br/>输出：<br/>- output，比较结果张量，形状和数据类型和输入相同。 | 
| OH_NN_OPS_RANK<sup>12+</sup> | 计算张量的秩。<br/>输入：<br/>- input，n维张量。<br/>输出：<br/>- output，0维的int32结果张量，表示输入的秩。 | 
| OH_NN_OPS_REDUCE_MAX<sup>12+</sup> | 计算输入张量在指定维度上的最大值，如果keepDims是false，输出张量的维度将会缩减； 如果keepDims为true，输出张量的维度和输入张量保持不变。<br/>输入：<br/>- input，n维张量，其中n&lt;8。<br/>- axis，用于计算最大值的维度。<br/>参数：<br/>- keepDims，布尔值，是否保留维度的标志位。<br/>- reduceToEnd，bool值，是否需要执行reduce操作直到最后一轴。<br/>- coeff，一个OH_NN_FLOAT32标量，表示输出的缩放因子。<br/>输出：<br/>- output，m维输出张量，数据类型和input相同。当keepDims为false时，m&lt;n；当keepDims为true时，m==n。 | 
| OH_NN_OPS_REDUCE_MIN<sup>12+</sup> | 计算输入张量在指定维度上的最小值，如果keepDims是false，输出张量的维度将会缩减； 如果keepDims为true，输出张量的维度和输入张量保持不变。<br/>输入：<br/>- input，n维张量，其中n&lt;8。<br/>- axis，用于计算最小值的维度。<br/>参数：<br/>- keepDims，布尔值，是否保留维度的标志位。<br/>- reduceToEnd，bool值，是否需要执行reduce操作直到最后一轴。<br/>- coeff，一个OH_NN_FLOAT32标量，表示输出的缩放因子。<br/>输出：<br/>- output，m维输出张量，数据类型和input相同。当keepDims为false时，m&lt;n；当keepDims为true时，m==n。 | 
| OH_NN_OPS_REDUCE_SUM<sup>12+</sup> | 计算输入张量在指定维度上的求和，如果keepDims是false，输出张量的维度将会缩减； 如果keepDims为true，输出张量的维度和输入张量保持不变。<br/>输入：<br/>- input，n维张量，其中n&lt;8。<br/>- axis，用于计算求和的维度。<br/>参数：<br/>- keepDims，布尔值，是否保留维度的标志位。<br/>- reduceToEnd，bool值，是否需要执行reduce操作直到最后一轴。<br/>- coeff，一个OH_NN_FLOAT32标量，表示输出的缩放因子。<br/>输出：<br/>- output，m维输出张量，数据类型和input相同。当keepDims为false时，m&lt;n；当keepDims为true时，m==n。 | 
| OH_NN_OPS_ROUND<sup>12+</sup> | 对输入张量进行四舍五入近似计算数值。<br/>输入：<br/>- input，n维张量。<br/>输出：<br/>- output，结果张量，数据类型和形状和输入一致。 | 
| OH_NN_OPS_SCATTER_ND<sup>12+</sup> | 根据指定的索引将更新值散布到新的Tensor上。<br/>输入：<br/>- indices，指定新张量中散布的索引值，数值类型为OH_NN_INT64或OH_NN_INT32， 索引的秩至少为2，并且indices最后一维的数值小于输入shape的尺寸。<br/>- updates，指定更新的Tensor。<br/>- shape，指定输出张量的形状，数据类型和输入indices相同。<br/>输出：<br/>- output，更新后的张量，数据类型和输入update相同，形状和输入shape相同。 | 
| OH_NN_OPS_SPACE_TO_DEPTH<sup>12+</sup> | 将输入张量的空间维度数据块重新排列为深度维度。<br/>输入：<br/>- input，4维张量，NHWC或NCHW格式，目前仅支持NHWC，形状为[batchSize, height, width, channels]。<br/>参数：<br/>- blockSize，指定转换的块大小，必须是整数。<br/>输出：<br/>- output，4维张量，format格式和输入一致， 形状为[batchSize, height / blockSize, weight / blockSize, channel \* blockSize^2]。 | 
| OH_NN_OPS_SWISH<sup>12+</sup> | 逐元素对输入张量计算Swish激活。<br/>输入：<br/>- input，n维张量。<br/>输出：<br/>- n维张量，数据类型和形状与输入相同。 | 
| OH_NN_OPS_REDUCE_L2<sup>12+</sup> | 计算输入张量在指定维度上的L2范数，如果keepDims是false，输出张量的维度将会缩减； 如果keepDims为true，输出张量的维度和输入张量保持不变。<br/>输入：<br/>- input，n维张量，其中n&lt;8。<br/>- axis，用于计算L2范数的维度。<br/>参数：<br/>- keepDims，布尔值，是否保留维度的标志位。<br/>- reduceToEnd，bool值，是否需要执行reduce操作直到最后一轴。<br/>- coeff，一个OH_NN_FLOAT32标量，表示输出的缩放因子。<br/>输出：<br/>- output，m维输出张量，数据类型和input相同。当keepDims为false时，m&lt;n；当keepDims为true时，m==n。 | 
| OH_NN_OPS_HARD_SIGMOID<sup>12+</sup> | 逐元素对输入张量计算HardSigmoid激活。<br/>输入：<br/>- input，n维张量。<br/>输出：<br/>- n维张量，数据类型和形状与输入相同。 | 
| OH_NN_OPS_GATHER_ND<sup>12+</sup> | 根据索引获取输入张量指定位置上的元素。<br/>输入：<br/>- input，n维张量。<br/>- indices，m维索引张量，其数据类型为OH_NN_INT64或OH_NN_INT32。<br/>输出：<br/>- n维张量，数据类型与输入相同，形状为indices的前(m-1)维和input的后(n-indices最后一维的尺寸)维的拼接。 | 


### OH_NN_PerformanceMode

```
enum OH_NN_PerformanceMode
```

**描述**

硬件的性能模式。

**起始版本：** 9

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_NN_PERFORMANCE_NONE | 无性能模式偏好 | 
| OH_NN_PERFORMANCE_LOW | 低能耗模式 | 
| OH_NN_PERFORMANCE_MEDIUM | 中性能模式 | 
| OH_NN_PERFORMANCE_HIGH | 高性能模式 | 
| OH_NN_PERFORMANCE_EXTREME | 极致性能模式 | 


### OH_NN_Priority

```
enum OH_NN_Priority
```

**描述**

模型推理任务优先级。

**起始版本：** 9

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_NN_PRIORITY_NONE | 无优先级偏好 | 
| OH_NN_PRIORITY_LOW | 低优先级 | 
| OH_NN_PRIORITY_MEDIUM | 中优先级 | 
| OH_NN_PRIORITY_HIGH | 高优先级 | 


### OH_NN_ReturnCode

```
enum OH_NN_ReturnCode
```

**描述**

Neural Network Runtime 定义的错误码类型。

**起始版本：** 9

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_NN_SUCCESS | 操作成功 | 
| OH_NN_FAILED | 操作失败 | 
| OH_NN_INVALID_PARAMETER | 非法参数 | 
| OH_NN_MEMORY_ERROR | 内存相关的错误，包括：内存不足、内存数据拷贝失败、内存申请失败等。 | 
| OH_NN_OPERATION_FORBIDDEN | 非法操作 | 
| OH_NN_NULL_PTR | 空指针异常 | 
| OH_NN_INVALID_FILE | 无效文件 | 
| OH_NN_UNAVALIDABLE_DEVICE | 硬件发生错误，错误可能包含：HDL服务崩溃<br/>**弃用：**从API version 11开始废弃，此接口废弃。<br/>**替代：**推荐使用 OH_NN_UNAVAILABLE_DEVICE。 | 
| OH_NN_INVALID_PATH | 非法路径 | 
| OH_NN_TIMEOUT<sup>11+</sup> | 执行超时 | 
| OH_NN_UNSUPPORTED<sup>11+</sup> | 未支持 | 
| OH_NN_CONNECTION_EXCEPTION<sup>11+</sup> | 连接异常 | 
| OH_NN_SAVE_CACHE_EXCEPTION<sup>11+</sup> | 保存cache异常 | 
| OH_NN_DYNAMIC_SHAPE<sup>11+</sup> | 动态shape | 
| OH_NN_UNAVAILABLE_DEVICE<sup>11+</sup> | 硬件发生错误，错误可能包含：HDL服务崩溃 | 


### OH_NN_TensorType

```
enum OH_NN_TensorType
```

**描述**

张量的类型。

张量通常用于设置模型的输入、输出和算子参数。作为模型（或算子）的输入和输出时，需要将张量类型设置为OH_NN_TENSOR；当张量 作为算子参数时，需要选择除OH_NN_TENSOR以外合适的枚举值，作为张量的类型。假设正在设置OH_NN_OPS_CONV2D 算子的pad参数，则需要将[OH_NN_Tensor](_o_h___n_n___tensor.md)实例的type属性设置为OH_NN_CONV2D_PAD。其他算子参数的设置以此类推，枚举值 的命名遵守 OH_NN_{算子名称}_{属性名} 的格式。

**起始版本：** 9

| 枚举值 | 描述 | 
| -------- | -------- |
| OH_NN_TENSOR | 当张量作为模型（或算子）的输入或输出时，使用本枚举值。 | 
| OH_NN_ADD_ACTIVATIONTYPE | 当张量作为Add算子的activationType参数时，使用本枚举值。 | 
| OH_NN_AVG_POOL_KERNEL_SIZE | 当张量作为AvgPool算子的kernelSize参数时，使用本枚举值。 | 
| OH_NN_AVG_POOL_STRIDE | 当张量作为AvgPool算子的stride参数时，使用本枚举值。 | 
| OH_NN_AVG_POOL_PAD_MODE | 当张量作为AvgPool算子的padMode参数时，使用本枚举值。 | 
| OH_NN_AVG_POOL_PAD | 当张量作为AvgPool算子的pad参数时，使用本枚举值。 | 
| OH_NN_AVG_POOL_ACTIVATION_TYPE | 当张量作为AvgPool算子的activationType参数时，使用本枚举值。 | 
| OH_NN_BATCH_NORM_EPSILON | 当张量作为BatchNorm算子的eosilon参数时，使用本枚举值。 | 
| OH_NN_BATCH_TO_SPACE_ND_BLOCKSIZE | 当张量作为BatchToSpaceND算子的blockSize参数时，使用本枚举值。 | 
| OH_NN_BATCH_TO_SPACE_ND_CROPS | 当张量作为BatchToSpaceND算子的crops参数时，使用本枚举值。 | 
| OH_NN_CONCAT_AXIS | 当张量作为Concat算子的axis参数时，使用本枚举值。 | 
| OH_NN_CONV2D_STRIDES | 当张量作为Conv2D算子的strides参数时，使用本枚举值。 | 
| OH_NN_CONV2D_PAD | 当张量作为Conv2D算子的pad参数时，使用本枚举值。 | 
| OH_NN_CONV2D_DILATION | 当张量作为Conv2D算子的dilation参数时，使用本枚举值。 | 
| OH_NN_CONV2D_PAD_MODE | 当张量作为Conv2D算子的padMode参数时，使用本枚举值。 | 
| OH_NN_CONV2D_ACTIVATION_TYPE | 当张量作为Conv2D算子的activationType参数时，使用本枚举值。 | 
| OH_NN_CONV2D_GROUP | 当张量作为Conv2D算子的group参数时，使用本枚举值。 | 
| OH_NN_CONV2D_TRANSPOSE_STRIDES | 当张量作为Conv2DTranspose算子的strides参数时，使用本枚举值。 | 
| OH_NN_CONV2D_TRANSPOSE_PAD | 当张量作为Conv2DTranspose算子的pad参数时，使用本枚举值。 | 
| OH_NN_CONV2D_TRANSPOSE_DILATION | 当张量作为Conv2DTranspose算子的dilation参数时，使用本枚举值。 | 
| OH_NN_CONV2D_TRANSPOSE_OUTPUT_PADDINGS | 当张量作为Conv2DTranspose算子的outputPaddings参数时，使用本枚举值。 | 
| OH_NN_CONV2D_TRANSPOSE_PAD_MODE | 当张量作为Conv2DTranspose算子的padMode参数时，使用本枚举值。 | 
| OH_NN_CONV2D_TRANSPOSE_ACTIVATION_TYPE | 当张量作为Conv2DTranspose算子的activationType参数时，使用本枚举值。 | 
| OH_NN_CONV2D_TRANSPOSE_GROUP | 当张量作为Conv2DTranspose算子的group参数时，使用本枚举值。 | 
| OH_NN_DEPTHWISE_CONV2D_NATIVE_STRIDES | 当张量作为DepthwiseConv2dNative算子的strides参数时，使用本枚举值。 | 
| OH_NN_DEPTHWISE_CONV2D_NATIVE_PAD | 当张量作为DepthwiseConv2dNative算子的pad参数时，使用本枚举值。 | 
| OH_NN_DEPTHWISE_CONV2D_NATIVE_DILATION | 当张量作为DepthwiseConv2dNative算子的dilation参数时，使用本枚举值。 | 
| OH_NN_DEPTHWISE_CONV2D_NATIVE_PAD_MODE | 当张量作为DepthwiseConv2dNative算子的padMode参数时，使用本枚举值。 | 
| OH_NN_DEPTHWISE_CONV2D_NATIVE_ACTIVATION_TYPE | 当张量作为DepthwiseConv2dNative算子的activationType参数时，使用本枚举值。 | 
| OH_NN_DIV_ACTIVATIONTYPE | 当张量作为Div算子的activationType参数时，使用本枚举值。 | 
| OH_NN_ELTWISE_MODE | 当张量作为Eltwise算子的mode参数时，使用本枚举值。 | 
| OH_NN_FULL_CONNECTION_AXIS | 当张量作为FullConnection算子的axis参数时，使用本枚举值。 | 
| OH_NN_FULL_CONNECTION_ACTIVATIONTYPE | 当张量作为FullConnection算子的activationType参数时，使用本枚举值。 | 
| OH_NN_MATMUL_TRANSPOSE_A | 当张量作为Matmul算子的transposeA参数时，使用本枚举值。 | 
| OH_NN_MATMUL_TRANSPOSE_B | 当张量作为Matmul算子的transposeB参数时，使用本枚举值。 | 
| OH_NN_MATMUL_ACTIVATION_TYPE | 当张量作为Matmul算子的activationType参数时，使用本枚举值。 | 
| OH_NN_MAX_POOL_KERNEL_SIZE | 当张量作为MaxPool算子的kernelSize参数时，使用本枚举值。 | 
| OH_NN_MAX_POOL_STRIDE | 当张量作为MaxPool算子的stride参数时，使用本枚举值。 | 
| OH_NN_MAX_POOL_PAD_MODE | 当张量作为MaxPool算子的padMode参数时，使用本枚举值。 | 
| OH_NN_MAX_POOL_PAD | 当张量作为MaxPool算子的pad参数时，使用本枚举值。 | 
| OH_NN_MAX_POOL_ACTIVATION_TYPE | 当张量作为MaxPool算子的activationType参数时，使用本枚举值。 | 
| OH_NN_MUL_ACTIVATION_TYPE | 当张量作为Mul算子的activationType参数时，使用本枚举值。 | 
| OH_NN_ONE_HOT_AXIS | 当张量作为OneHot算子的axis参数时，使用本枚举值。 | 
| OH_NN_PAD_CONSTANT_VALUE | 当张量作为Pad算子的constantValue参数时，使用本枚举值。 | 
| OH_NN_SCALE_ACTIVATIONTYPE | 当张量作为Scale算子的activationType参数时，使用本枚举值。 | 
| OH_NN_SCALE_AXIS | 当张量作为Scale算子的axis参数时，使用本枚举值。 | 
| OH_NN_SOFTMAX_AXIS | 当张量作为Softmax算子的axis参数时，使用本枚举值。 | 
| OH_NN_SPACE_TO_BATCH_ND_BLOCK_SHAPE | 当张量作为SpaceToBatchND算子的BlockShape参数时，使用本枚举值。 | 
| OH_NN_SPACE_TO_BATCH_ND_PADDINGS | 当张量作为SpaceToBatchND算子的Paddings参数时，使用本枚举值。 | 
| OH_NN_SPLIT_AXIS | 当张量作为Split算子的Axis参数时，使用本枚举值。 | 
| OH_NN_SPLIT_OUTPUT_NUM | 当张量作为Split算子的OutputNum参数时，使用本枚举值。 | 
| OH_NN_SPLIT_SIZE_SPLITS | 当张量作为Split算子的SizeSplits参数时，使用本枚举值。 | 
| OH_NN_SQUEEZE_AXIS | 当张量作为Squeeze算子的Axis参数时，使用本枚举值。 | 
| OH_NN_STACK_AXIS | 当张量作为Stack算子的Axis参数时，使用本枚举值。 | 
| OH_NN_STRIDED_SLICE_BEGIN_MASK | 当张量作为StridedSlice算子的BeginMask参数时，使用本枚举值。 | 
| OH_NN_STRIDED_SLICE_END_MASK | 当张量作为StridedSlice算子的EndMask参数时，使用本枚举值。 | 
| OH_NN_STRIDED_SLICE_ELLIPSIS_MASK | 当张量作为StridedSlice算子的EllipsisMask参数时，使用本枚举值。 | 
| OH_NN_STRIDED_SLICE_NEW_AXIS_MASK | 当张量作为StridedSlice算子的NewAxisMask参数时，使用本枚举值。 | 
| OH_NN_STRIDED_SLICE_SHRINK_AXIS_MASK | 当张量作为StridedSlice算子的ShrinkAxisMask参数时，使用本枚举值。 | 
| OH_NN_SUB_ACTIVATIONTYPE | 当张量作为Sub算子的ActivationType参数时，使用本枚举值。 | 
| OH_NN_REDUCE_MEAN_KEEP_DIMS | 当张量作为ReduceMean算子的keepDims参数时，使用本枚举值。 | 
| OH_NN_RESIZE_BILINEAR_NEW_HEIGHT | 当张量作为ResizeBilinear算子的newHeight参数时，使用本枚举值。 | 
| OH_NN_RESIZE_BILINEAR_NEW_WIDTH | 当张量作为ResizeBilinear算子的newWidth参数时，使用本枚举值。 | 
| OH_NN_RESIZE_BILINEAR_PRESERVE_ASPECT_RATIO | 当张量作为ResizeBilinear算子的preserveAspectRatio参数时，使用本枚举值。 | 
| OH_NN_RESIZE_BILINEAR_COORDINATE_TRANSFORM_MODE | 当张量作为ResizeBilinear算子的coordinateTransformMode参数时，使用本枚举值。 | 
| OH_NN_RESIZE_BILINEAR_EXCLUDE_OUTSIDE | 当张量作为ResizeBilinear算子的excludeOutside参数时，使用本枚举值。 | 
| OH_NN_LAYER_NORM_BEGIN_NORM_AXIS | 当张量作为LayerNorm算子的beginNormAxis参数时，使用本枚举值。 | 
| OH_NN_LAYER_NORM_EPSILON | 当张量作为LayerNorm算子的epsilon参数时，使用本枚举值。 | 
| OH_NN_LAYER_NORM_BEGIN_PARAM_AXIS | 当张量作为LayerNorm算子的beginParamsAxis参数时，使用本枚举值。 | 
| OH_NN_LAYER_NORM_ELEMENTWISE_AFFINE | 当张量作为LayerNorm算子的elementwiseAffine参数时，使用本枚举值。 | 
| OH_NN_REDUCE_PROD_KEEP_DIMS | 当张量作为ReduceProd算子的keepDims参数时，使用本枚举值。 | 
| OH_NN_REDUCE_ALL_KEEP_DIMS | 当张量作为ReduceAll算子的keepDims参数时，使用本枚举值。 | 
| OH_NN_QUANT_DTYPE_CAST_SRC_T | 当张量作为QuantDTypeCast算子的srcT参数时，使用本枚举值。 | 
| OH_NN_QUANT_DTYPE_CAST_DST_T | 当张量作为QuantDTypeCast算子的dstT参数时，使用本枚举值。 | 
| OH_NN_TOP_K_SORTED | 当张量作为Topk算子的Sorted参数时，使用本枚举值。 | 
| OH_NN_ARG_MAX_AXIS | 当张量作为ArgMax算子的axis参数时，使用本枚举值。 | 
| OH_NN_ARG_MAX_KEEPDIMS | 当张量作为ArgMax算子的keepDims参数时，使用本枚举值。 | 
| OH_NN_UNSQUEEZE_AXIS | 当张量作为Unsqueeze算子的Axis参数时，使用本枚举值。 | 
| OH_NN_UNSTACK_AXIS<sup>12+</sup> | 当张量作为Unstack算子的axis参数时，使用本枚举值。 | 
| OH_NN_FLATTEN_AXIS<sup>12+</sup> | 当张量作为Flatten算子的axis参数时，使用本枚举值。 | 
| OH_NN_DEPTH_TO_SPACE_BLOCK_SIZE<sup>12+</sup> | 当张量作为DepthToSpace算子的blockSize参数时，使用本枚举值。 | 
| OH_NN_DEPTH_TO_SPACE_MODE<sup>12+</sup> | 当张量作为DepthToSpace算子的mode参数时，使用本枚举值。 | 
| OH_NN_RANGE_START<sup>12+</sup> | 当张量作为Range算子的start参数时，使用本枚举值。 | 
| OH_NN_RANGE_LIMIT<sup>12+</sup> | 当张量作为Range算子的limit参数时，使用本枚举值。 | 
| OH_NN_RANGE_DELTA<sup>12+</sup> | 当张量作为Range算子的delta参数时，使用本枚举值。 | 
| OH_NN_CONSTANT_OF_SHAPE_DATA_TYPE<sup>12+</sup> | 当张量作为ConstantOfShape算子的dataType参数时，使用本枚举值。 | 
| OH_NN_CONSTANT_OF_SHAPE_VALUE<sup>12+</sup> | 当张量作为ConstantOfShape算子的value参数时，使用本枚举值。 | 
| OH_NN_BROADCAST_TO_SHAPE<sup>12+</sup> | 当张量作为BroadcastTo算子的shape参数时，使用本枚举值。 | 
| OH_NN_INSTANCE_NORM_EPSILON<sup>12+</sup> | 当张量作为InstanceNorm算子的epsilon参数时，使用本枚举值。 | 
| OH_NN_EXP_BASE<sup>12+</sup> | 当张量作为Exp算子的base参数时，使用本枚举值。 | 
| OH_NN_EXP_SCALE<sup>12+</sup> | 当张量作为Exp算子的scale参数时，使用本枚举值。 | 
| OH_NN_EXP_SHIFT<sup>12+</sup> | 当张量作为Exp算子的shift参数时，使用本枚举值。 | 
| OH_NN_LEAKY_RELU_NEGATIVE_SLOPE<sup>12+</sup> | 当张量作为LeakyRelu算子的negativeSlope参数时，使用本枚举值。 | 
| OH_NN_LSTM_BIDIRECTIONAL<sup>12+</sup> | 当张量作为LSTM算子的bidirectional参数时，使用本枚举值。 | 
| OH_NN_LSTM_HAS_BIAS<sup>12+</sup> | 当张量作为LSTM算子的hasBias参数时，使用本枚举值。 | 
| OH_NN_LSTM_INPUT_SIZE<sup>12+</sup> | 当张量作为LSTM算子的inputSize参数时，使用本枚举值。 | 
| OH_NN_LSTM_HIDDEN_SIZE<sup>12+</sup> | 当张量作为LSTM算子的hiddenSize参数时，使用本枚举值。 | 
| OH_NN_LSTM_NUM_LAYERS<sup>12+</sup> | 当张量作为LSTM算子的numLayers参数时，使用本枚举值。 | 
| OH_NN_LSTM_NUM_DIRECTIONS<sup>12+</sup> | 当张量作为LSTM算子的numDirections参数时，使用本枚举值。 | 
| OH_NN_LSTM_DROPOUT<sup>12+</sup> | 当张量作为LSTM算子的dropout参数时，使用本枚举值。 | 
| OH_NN_LSTM_ZONEOUT_CELL<sup>12+</sup> | 当张量作为LSTM算子的zoneoutCell参数时，使用本枚举值。 | 
| OH_NN_LSTM_ZONEOUT_HIDDEN<sup>12+</sup> | 当张量作为LSTM算子的zoneoutHidden参数时，使用本枚举值。 | 
| OH_NN_LSTM_PROJ_SIZE<sup>12+</sup> | 当张量作为LSTM算子的projSize参数时，使用本枚举值。 | 
| OH_NN_CLIP_MAX<sup>12+</sup> | 当张量作为Clip算子的max参数时，使用本枚举值。 | 
| OH_NN_CLIP_MIN<sup>12+</sup> | 当张量作为Clip算子的min参数时，使用本枚举值。 | 
| OH_NN_ALL_KEEP_DIMS<sup>12+</sup> | 当张量作为All算子的keepDims参数时，使用本枚举值。 | 
| OH_NN_ASSERT_SUMMARIZE<sup>12+</sup> | 当张量作为Assert算子的summarize参数时，使用本枚举值。 | 
| OH_NN_POW_SCALE<sup>12+</sup> | 当张量作为Pow算子的scale参数时，使用本枚举值。 | 
| OH_NN_POW_SHIFT<sup>12+</sup> | 当张量作为Pow算子的shift参数时，使用本枚举值。 | 
| OH_NN_AVG_POOL_ROUND_MODE<sup>12+</sup> | 当张量作为AvgPool算子的RoundMode参数时，使用本枚举值。 | 
| OH_NN_AVG_POOL_GLOBAL<sup>12+</sup> | 当张量作为AvgPool算子的global参数时，使用本枚举值。 | 
| OH_NN_FULL_CONNECTION_HAS_BIAS<sup>12+</sup> | 当张量作为FullConnection算子的hasBias参数时，使用本枚举值。 | 
| OH_NN_FULL_CONNECTION_USE_AXIS<sup>12+</sup> | 当张量作为FullConnection算子的useAxis参数时，使用本枚举值。 | 
| OH_NN_GELU_APPROXIMATE<sup>12+</sup> | 当张量作为GeLU算子的approximate参数时，使用本枚举值。 | 
| OH_NN_MAX_POOL_ROUND_MODE<sup>12+</sup> | 当张量作为MaxPool算子的RoundMode参数时，使用本枚举值。 | 
| OH_NN_MAX_POOL_GLOBAL<sup>12+</sup> | 当张量作为MaxPool算子的global参数时，使用本枚举值。 | 
| OH_NN_PAD_PADDING_MODE<sup>12+</sup> | 当张量作为Pad算子的paddingMode参数时，使用本枚举值。 | 
| OH_NN_REDUCE_MEAN_REDUCE_TO_END<sup>12+</sup> | 当张量作为ReduceMean算子的reduceToEnd参数时，使用本枚举值。 | 
| OH_NN_REDUCE_MEAN_COEFF<sup>12+</sup> | 当张量作为ReduceMean算子的coeff参数时，使用本枚举值。 | 
| OH_NN_REDUCE_PROD_REDUCE_TO_END<sup>12+</sup> | 当张量作为ReduceProd算子的reduceToEnd参数时，使用本枚举值。 | 
| OH_NN_REDUCE_PROD_COEFF<sup>12+</sup> | 当张量作为ReduceProd算子的coeff参数时，使用本枚举值。 | 
| OH_NN_REDUCE_ALL_REDUCE_TO_END<sup>12+</sup> | 当张量作为ReduceAll算子的reduceToEnd参数时，使用本枚举值。 | 
| OH_NN_REDUCE_ALL_COEFF<sup>12+</sup> | 当张量作为ReduceAll算子的coeff参数时，使用本枚举值。 | 
| OH_NN_TOP_K_AXIS<sup>12+</sup> | 当张量作为TopK算子的axis参数时，使用本枚举值。 | 
| OH_NN_ARG_MAX_TOP_K<sup>12+</sup> | 当张量作为ArgMax算子的topK参数时，使用本枚举值。 | 
| OH_NN_ARG_MAX_OUT_MAX_VALUE<sup>12+</sup> | 当张量作为ArgMax算子的outMaxValue参数时，使用本枚举值。 | 
| OH_NN_QUANT_DTYPE_CAST_AXIS<sup>12+</sup> | 当张量作为QuantDTypeCast算子的axis参数时，使用本枚举值。 | 
| OH_NN_SLICE_AXES<sup>12+</sup> | 当张量作为Slice算子的axes参数时，使用本枚举值。 | 
| OH_NN_TILE_DIMS<sup>12+</sup> | 当张量作为Tile算子的dims参数时，使用本枚举值。 | 
| OH_NN_CROP_AXIS<sup>12+</sup> | 当张量作为Crop算子的axis参数时，使用本枚举值。 | 
| OH_NN_CROP_OFFSET<sup>12+</sup> | 当张量作为Crop算子的offset参数时，使用本枚举值。 | 
| OH_NN_DETECTION_POST_PROCESS_INPUT_SIZE<sup>12+</sup> | 当张量作为DetectionPostProcess算子的inputSize参数时，使用本枚举值。 | 
| OH_NN_DETECTION_POST_PROCESS_SCALE<sup>12+</sup> | 当张量作为DetectionPostProcess算子的scale参数时，使用本枚举值。 | 
| OH_NN_DETECTION_POST_PROCESS_NMS_IOU_THRESHOLD<sup>12+</sup> | 当张量作为DetectionPostProcess算子的nmsIouThreshold参数时，使用本枚举值。 | 
| OH_NN_DETECTION_POST_PROCESS_NMS_SCORE_THRESHOLD<sup>12+</sup> | 当张量作为DetectionPostProcess算子的nmsScoreThreshold参数时，使用本枚举值。 | 
| OH_NN_DETECTION_POST_PROCESS_MAX_DETECTIONS<sup>12+</sup> | 当张量作为DetectionPostProcess算子的maxDetections参数时，使用本枚举值。 | 
| OH_NN_DETECTION_POST_PROCESS_DETECTIONS_PER_CLASS<sup>12+</sup> | 当张量作为DetectionPostProcess算子的preClass参数时，使用本枚举值。 | 
| OH_NN_DETECTION_POST_PROCESS_MAX_CLASSES_PER_DETECTION<sup>12+</sup> | 当张量作为DetectionPostProcess算子的maxClassPreDetection参数时，使用本枚举值。 | 
| OH_NN_DETECTION_POST_PROCESS_NUM_CLASSES<sup>12+</sup> | 当张量作为DetectionPostProcess算子的numClasses参数时，使用本枚举值。 | 
| OH_NN_DETECTION_POST_PROCESS_USE_REGULAR_NMS<sup>12+</sup> | 当张量作为DetectionPostProcess算子的useRegularNms参数时，使用本枚举值。 | 
| OH_NN_DETECTION_POST_PROCESS_OUT_QUANTIZED<sup>12+</sup> | 当张量作为DetectionPostProcess算子的outQuantized参数时，使用本枚举值。 | 
| OH_NN_L2_NORMALIZE_AXIS<sup>12+</sup> | 当张量作为L2Normalize算子的axis参数时，使用本枚举值。 | 
| OH_NN_L2_NORMALIZE_EPSILON<sup>12+</sup> | 当张量作为L2Normalize算子的epslion参数时，使用本枚举值。 | 
| OH_NN_L2_NORMALIZE_ACTIVATION_TYPE<sup>12+</sup> | 当张量作为L2Normalize算子的activationType参数时，使用本枚举值。 | 
| OH_NN_LOG_SOFTMAX_AXIS<sup>12+</sup> | 当张量作为LogSoftmax算子的axis参数时，使用本枚举值。 | 
| OH_NN_LRN_DEPTH_RADIUS<sup>12+</sup> | 当张量作为LRN算子的depthRadius参数时，使用本枚举值。 | 
| OH_NN_LRN_BIAS<sup>12+</sup> | 当张量作为LRN算子的bias参数时，使用本枚举值。 | 
| OH_NN_LRN_ALPHA<sup>12+</sup> | 当张量作为LRN算子的alpha参数时，使用本枚举值。 | 
| OH_NN_LRN_BETA<sup>12+</sup> | 当张量作为LRN算子的beta参数时，使用本枚举值。 | 
| OH_NN_LRN_NORM_REGION<sup>12+</sup> | 当张量作为LRN算子的normRegion参数时，使用本枚举值。 | 
| OH_NN_SPACE_TO_DEPTH_BLOCK_SIZE<sup>12+</sup> | 当张量作为SpaceToDepth算子的blockSize参数时，使用本枚举值。 | 
| OH_NN_REDUCE_MAX_KEEP_DIMS<sup>12+</sup> | 当张量作为ReduceMax算子的keepDims参数时，使用本枚举值。 | 
| OH_NN_REDUCE_MAX_REDUCE_TO_END<sup>12+</sup> | 当张量作为ReduceMax算子的reduceToEnd参数时，使用本枚举值。 | 
| OH_NN_REDUCE_MAX_COEFF<sup>12+</sup> | 当张量作为ReduceMax算子的coeff参数时，使用本枚举值。 | 
| OH_NN_REDUCE_MIN_KEEP_DIMS<sup>12+</sup> | 当张量作为ReduceMin算子的keepDims参数时，使用本枚举值。 | 
| OH_NN_REDUCE_MIN_REDUCE_TO_END<sup>12+</sup> | 当张量作为ReduceMin算子的reduceToEnd参数时，使用本枚举值。 | 
| OH_NN_REDUCE_MIN_COEFF<sup>12+</sup> | 当张量作为ReduceMin算子的coeff参数时，使用本枚举值。 | 
| OH_NN_REDUCE_SUM_KEEP_DIMS<sup>12+</sup> | 当张量作为ReduceSum算子的keepDims参数时，使用本枚举值。 | 
| OH_NN_REDUCE_SUM_REDUCE_TO_END<sup>12+</sup> | 当张量作为ReduceSum算子的reduceToEnd参数时，使用本枚举值。 | 
| OH_NN_REDUCE_SUM_COEFF<sup>12+</sup> | 当张量作为ReduceSum算子的coeff参数时，使用本枚举值。 | 
| OH_NN_REDUCE_L2_KEEP_DIMS<sup>12+</sup> | 当张量作为ReduceL2算子的keepDims参数时，使用本枚举值。 | 
| OH_NN_REDUCE_L2_REDUCE_TO_END<sup>12+</sup> | 当张量作为ReduceL2算子的reduceToEnd参数时，使用本枚举值。 | 
| OH_NN_REDUCE_L2_COEFF<sup>12+</sup> | 当张量作为ReduceL2算子的coeff参数时，使用本枚举值。 | 


## 函数说明


### OH_NNCompilation_AddExtensionConfig()

```
OH_NN_ReturnCode OH_NNCompilation_AddExtensionConfig (OH_NNCompilation *compilation, const char *configName, const void *configValue, const size_t configValueSize )
```

**描述**

为自定义硬件属性添加扩展配置。

某些设备有自己的特定属性，这些属性尚未在NNRt中打开。该接口为您提供了另一种方式设置设备的这些自定义硬件属性。 您应该从设备供应商的文档查询它们的名称和值，并将它们逐一添加到编译实例中。这些属性将直接传递给设备驱动程序， 如果驱动程序无法解析它们，该接口将返回错误码。

调用[OH_NNCompilation_Build](#oh_nncompilation_build)后，**configName**和**configValue**就可以释放了。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| compilation | 指向[OH_NNCompilation](#oh_nncompilation)实例的指针。 | 
| configName | 配置名称。 | 
| configValue | 保存配置值的地址。 | 
| configValueSize | 配置值的字节大小。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNCompilation_Build()

```
OH_NN_ReturnCode OH_NNCompilation_Build (OH_NNCompilation *compilation)
```

**描述**

执行模型编译。

完成编译配置后，调用该接口执行模型编译。编译实例将模型和编译选项推送至硬件设备进行编译。 在调用该接口后，无法进行额外的编译操作，调用 [OH_NNCompilation_SetDevice](#oh_nncompilation_setdevice)、[OH_NNCompilation_SetCache](#oh_nncompilation_setcache)、 [OH_NNCompilation_SetPerformanceMode](#oh_nncompilation_setperformancemode)、 [OH_NNCompilation_SetPriority](#oh_nncompilation_setpriority)和[OH_NNCompilation_EnableFloat16](#oh_nncompilation_enablefloat16) 接口将返回OH_NN_OPERATION_FORBIDDEN。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| compilation | 指向[OH_NNCompilation](#oh_nncompilation)实例的指针。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNCompilation_Construct()

```
OH_NNCompilation *OH_NNCompilation_Construct (const OH_NNModel *model)
```

**描述**

创建[OH_NNCompilation](#oh_nncompilation)类型的编译实例。

使用OH_NNModel模块完成模型的构造后，借助OH_NNCompilation模块提供的接口，将模型传递到底层硬件完成编译。该接口接受一个 [OH_NNModel](#oh_nnmodel)实例，创建出[OH_NNCompilation](#oh_nncompilation)实例；通过[OH_NNCompilation_SetDevice](#oh_nncompilation_setdevice)接口，设置编译的设备， 最后调用[OH_NNCompilation_Build](#oh_nncompilation_build)完成编译。

除了计算硬件的选择，OH_NNCompilation模块支持模型缓存、性能偏好、优先级设置、float16计算等特性，参考以下接口：

[OH_NNCompilation_SetCache](#oh_nncompilation_setcache)

[OH_NNCompilation_SetPerformanceMode](#oh_nncompilation_setperformancemode)

[OH_NNCompilation_SetPriority](#oh_nncompilation_setpriority)

[OH_NNCompilation_EnableFloat16](#oh_nncompilation_enablefloat16)

调用该接口创建[OH_NNCompilation](#oh_nncompilation)后，[OH_NNModel](#oh_nnmodel)实例就可以释放了。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 指向[OH_NNModel](#oh_nnmodel)实例的指针。 | 

**返回：**

指向[OH_NNCompilation](#oh_nncompilation)实例的指针，如果创建失败就返回NULL。


### OH_NNCompilation_ConstructForCache()

```
OH_NNCompilation *OH_NNCompilation_ConstructForCache ()
```

**描述**

创建一个空的编译实例，以便稍后从模型缓存中恢复。

模型缓存的相关描述参考[OH_NNCompilation_SetCache](#oh_nncompilation_setcache)。

从模型缓存恢复的时间少于使用[OH_NNModel](#oh_nnmodel)进行编译的时间。

应该先调用[OH_NNCompilation_SetCache](#oh_nncompilation_setcache)或[OH_NNCompilation_ImportCacheFromBuffer](#oh_nncompilation_importcachefrombuffer)， 然后调用[OH_NNCompilation_Build](#oh_nncompilation_build)完成恢复。

**起始版本：** 11

**返回：**

指向[OH_NNCompilation](#oh_nncompilation)实例的指针，如果创建失败就返回NULL。


### OH_NNCompilation_ConstructWithOfflineModelBuffer()

```
OH_NNCompilation *OH_NNCompilation_ConstructWithOfflineModelBuffer (const void *modelBuffer, size_t modelSize )
```

**描述**

基于离线模型文件内存创建编译实例。

该接口与传递在线构建模型或离线模型文件路径的方式冲突，您只能选择三种构建接口中的一种。

注意：返回的[OH_NNCompilation](#oh_nncompilation)实例只将**modelBuffer**指针保存在里面，而不是复制其数据。 在销毁[OH_NNCompilation](#oh_nncompilation)实例之前，不应释放**modelBuffer**。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| modelBuffer | 离线模型文件内存。 | 
| modelSize | 离线模型内存大小。 | 

**返回：**

指向[OH_NNCompilation](#oh_nncompilation)实例的指针，如果创建失败就返回NULL。


### OH_NNCompilation_ConstructWithOfflineModelFile()

```
OH_NNCompilation *OH_NNCompilation_ConstructWithOfflineModelFile (const char *modelPath)
```

**描述**

基于离线模型文件创建编译实例。

该接口与传递在线构建模型或离线模型文件内存的方式冲突，您只能选择三种构建接口中的一种。

离线模型是由硬件供应商提供的模型转换器离线编译的模型类型，所以离线模型只能在指定的设备上使用，但离线模型的编译时间通常 远小于构图实例[OH_NNModel](#oh_nnmodel)的编译时间。

在开发过程中需要离线执行编译，并在应用包中部署离线模型。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| modelPath | 离线模型文件路径。 | 

**返回：**

指向[OH_NNCompilation](#oh_nncompilation)实例的指针，如果创建失败就返回NULL。


### OH_NNCompilation_Destroy()

```
void OH_NNCompilation_Destroy (OH_NNCompilation **compilation)
```

**描述**

销毁Compilation实例。

调用[OH_NNCompilation_Construct](#oh_nncompilation_construct)、[OH_NNCompilation_ConstructWithOfflineModelFile](#oh_nncompilation_constructwithofflinemodelfile)、 [OH_NNCompilation_ConstructWithOfflineModelBuffer](#oh_nncompilation_constructwithofflinemodelbuffer)、[OH_NNCompilation_ConstructForCache](#oh_nncompilation_constructforcache) 创建的编译实例需要调用该接口主动销毁。

如果compilation为空指针或者\*compilation为空指针，该接口仅打印警告日志，不执行销毁操作。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| compilation | 指向[OH_NNCompilation](#oh_nncompilation)实例的二级指针。编译实例销毁后，该接口将\*compilation主动设置为空指针。 | 


### OH_NNCompilation_EnableFloat16()

```
OH_NN_ReturnCode OH_NNCompilation_EnableFloat16 (OH_NNCompilation *compilation, bool enableFloat16 )
```

**描述**

是否以float16的浮点数精度计算。

浮点模型默认使用float32精度计算。如果在支持float16精度的硬件上调用该接口，float32浮点数精度的模型将以float16的精度执行计算， 可减少内存占用和执行时间。

该选项对于定点模型是无效的，例如int8类型的定点模型。

在不支持float16精度计算的硬件上调用该接口，将返回OH_NN_UNAVAILABLE_DEVICE错误码。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| compilation | 指向[OH_NNCompilation](#oh_nncompilation)实例的指针。 | 
| enableFloat16 | Float16低精度计算标志位。设置为true时，执行Float16推理；设置为false时，执行float32推理。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNCompilation_ExportCacheToBuffer()

```
OH_NN_ReturnCode OH_NNCompilation_ExportCacheToBuffer (OH_NNCompilation *compilation, const void *buffer, size_t length, size_t *modelSize )
```

**描述**

将模型缓存写入到指定内存区域。

模型缓存的相关描述参考[OH_NNCompilation_SetCache](#oh_nncompilation_setcache)。

注意：模型缓存是编译构建的结果[OH_NNCompilation_Build](#oh_nncompilation_build)，因此必须在[OH_NNCompilation_Build](#oh_nncompilation_build)之后调用该接口。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| compilation | 指向[OH_NNCompilation](#oh_nncompilation)实例的指针。 | 
| buffer | 指向给定内存的指针。 | 
| length | 内存长度。 | 
| modelSize | 模型缓存的字节大小。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNCompilation_ImportCacheFromBuffer()

```
OH_NN_ReturnCode OH_NNCompilation_ImportCacheFromBuffer (OH_NNCompilation *compilation, const void *buffer, size_t modelSize )
```

**描述**

从指定内存区域读取模型缓存。

模型缓存的相关描述参考[OH_NNCompilation_SetCache](#oh_nncompilation_setcache)。

调用[OH_NNCompilation_ImportCacheFromBuffer](#oh_nncompilation_importcachefrombuffer)后，应调用[OH_NNCompilation_Build](#oh_nncompilation_build)完成恢复。

注意：**compilation**只将**buffer**指针保存在里面，而不是复制其数据。 您不能在**compilation**被销毁之前释放内存**buffer**。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| compilation | 指向[OH_NNCompilation](#oh_nncompilation)实例的指针。 | 
| buffer | 指向给定内存的指针。 | 
| modelSize | 模型缓存的字节大小。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNCompilation_SetCache()

```
OH_NN_ReturnCode OH_NNCompilation_SetCache (OH_NNCompilation *compilation, const char *cachePath, uint32_t version )
```

**描述**

设置编译模型的缓存目录和版本。

在支持模型缓存的硬件上，模型在硬件驱动层编译后可以保存为模型缓存文件，下次编译时直接从模型缓存文件读取模型，减少重新编译的耗时。 该接口接受模型缓存路径和版本，根据缓存路径中和版本的不同情况，该接口采取不同的行为：

- 模型缓存路径指定的目录下没有文件： 将编译后的模型缓存到目录下，设置缓存版本等于version。

- 模型缓存路径指定的目录下存在完整的缓存文件，且版本号 == version： 读取路径下的缓存文件，传递到底层硬件中转换为可以执行的模型实例。

- 模型缓存路径指定的目录下存在完整的缓存文件，但版本号 &lt; version： 路径下的缓存文件需要更新，模型在底层硬件完成编译后，覆写路径下的缓存文件，将版本号更新为version。

- 模型缓存路径指定的目录下存在完整的缓存文件，但版本号 &gt; version： 路径下的缓存文件版本高于version，不读取缓存文件，同时返回OH_NN_INVALID_PARAMETER错误码。

- 模型缓存路径指定的目录下的缓存文件不完整或没有缓存文件的访问权限： 返回OH_NN_INVALID_FILE错误码。

- 模型缓存目录不存在，或者没有访问权限： 返回OH_NN_INVALID_PATH错误码。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| compilation | 指向[OH_NNCompilation](#oh_nncompilation)实例的指针。 | 
| cachePath | 模型缓存文件目录，该接口在cachePath目录下为不同的硬件创建模型缓存目录。建议每个模型使用单独的模型缓存目录。 | 
| version | 模型缓存版本。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNCompilation_SetDevice()

```
OH_NN_ReturnCode OH_NNCompilation_SetDevice (OH_NNCompilation *compilation, size_t deviceID )
```

**描述**

指定模型编译和计算的硬件。

编译阶段，需要指定模型编译和执行计算的硬件设备。先调用[OH_NNDevice_GetAllDevicesID](#oh_nndevice_getalldevicesid)获取可用的设备ID， 通过[OH_NNDevice_GetType](#oh_nndevice_gettype)和[OH_NNDevice_GetType](#oh_nndevice_gettype)获取设备信息后，将期望编译执行的 设备ID传入该接口进行设置。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| compilation | 指向[OH_NNCompilation](#oh_nncompilation)实例的指针。 | 
| deviceID | 指定的硬件ID。如果为0，则默认使用当前设备列表中的第1台设备。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNCompilation_SetPerformanceMode()

```
OH_NN_ReturnCode OH_NNCompilation_SetPerformanceMode (OH_NNCompilation *compilation, OH_NN_PerformanceMode performanceMode )
```

**描述**

设置模型计算的性能模式。

Neural Network Runtime 支持为模型计算设置性能模式，满足低功耗到极致性能的需求。如果编译阶段没有调用该接口设置性能模式， 编译实例为模型默认分配OH_NN_PERFORMANCE_NONE模式。在OH_NN_PERFORMANCE_NONE 模式下，硬件按默认的性能模式执行计算。

在不支持性能模式设置的硬件上调用该接口，将返回OH_NN_UNAVAILABLE_DEVICE错误码。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| compilation | 指向[OH_NNCompilation](#oh_nncompilation)实例的指针。 | 
| performanceMode | 指定性能模式，可选的性能模式参考[OH_NN_PerformanceMode](#oh_nn_performancemode)。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNCompilation_SetPriority()

```
OH_NN_ReturnCode OH_NNCompilation_SetPriority (OH_NNCompilation *compilation, OH_NN_Priority priority )
```

**描述**

设置模型计算的优先级。

Neural Network Runtime 支持为模型设置计算优先级，优先级仅作用于相同uid进程创建的模型，不同uid进程、不同设备的优先级不会 相互影响。

在不支持优先级设置的硬件上调用该接口，将返回OH_NN_UNAVAILABLE_DEVICE错误码。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| compilation | 指向[OH_NNCompilation](#oh_nncompilation)实例的指针。 | 
| priority | 指定优先级，可选的优先级参考[OH_NN_Priority](#oh_nn_priority)。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNDevice_GetAllDevicesID()

```
OH_NN_ReturnCode OH_NNDevice_GetAllDevicesID (const size_t **allDevicesID, uint32_t *deviceCount )
```

**描述**

获取对接到 Neural Network Runtime 的硬件ID。

每个硬件存在唯一且固定的ID，该接口通过uin32_t数组返回当前设备上已经对接的硬件ID。

硬件ID通过size_t数组返回，数组的每个元素是单个硬件的ID值。数组内存由内部进行管理，在下次调用该接口前，数据指针将一直有效。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| allDevicesID | 指向size_t数组的指针。要求传入的**\*allDevicesID**为空指针，否则将返回错误码OH_NN_INVALID_PARAMETER。 | 
| deviceCount | uint32_t类型的指针，用于返回**\*allDevicesID**的长度。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNDevice_GetName()

```
OH_NN_ReturnCode OH_NNDevice_GetName (size_t deviceID, const char **name )
```

**描述**

获取指定硬件的名称。

通过deviceID指定计算硬件，获取硬件的名称。硬件ID需要调用[OH_NNDevice_GetAllDevicesID](#oh_nndevice_getalldevicesid)获取。如果deviceID是0， 那么会默认使用设备列表中的第一个设备。

**\*name**是一个C风格的字符串，以**'\0'**作为结束符。

**\*name**必须是一个空指针，否则接口会返回OH_NN_INVALID_PARAMETER错误。例如您应该定义char\* deviceName = NULL， 然后将&amp;deviceName作为参数传入。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| deviceID | 指定硬件ID。如果deviceID是0，那么会默认使用设备列表中的第一个设备。 | 
| name | 指向char数组的指针，保存返回的硬件名称。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNDevice_GetType()

```
OH_NN_ReturnCode OH_NNDevice_GetType (size_t deviceID, OH_NN_DeviceType *deviceType )
```

**描述**

获取指定硬件的类别信息。

通过deviceID指定计算硬件，获取硬件的类别。如果deviceID是0，那么会默认使用设备列表中的第一个设备。目前支持的设备类型有：

- CPU设备：OH_NN_CPU

- GPU设备：OH_NN_GPU

- 机器学习专用加速器：OH_NN_ACCELERATOR

- 不属于以上类型的其他硬件类型：OH_NN_OTHERS

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| deviceID | 指定硬件ID。如果deviceID是0，那么会默认使用设备列表中的第一个设备。 | 
| deviceType | 指向[OH_NN_DeviceType](#oh_nn_devicetype)实例的指针，返回硬件的类别信息。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNExecutor_AllocateInputMemory()

```
OH_NN_Memory *OH_NNExecutor_AllocateInputMemory (OH_NNExecutor *executor, uint32_t inputIndex, size_t length )
```

**描述**

在硬件上为单个输入申请共享内存。

Neural Network Runtime 提供主动申请硬件共享内存的方法。通过指定执行器和输入索引值，该接口在单个输入关联的硬件 上，申请大小为length的共享内存，通过[OH_NN_Memory](_o_h___n_n___memory.md)实例返回。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 
| inputIndex | 输入的索引值，与调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时输入数据的顺序一致。 假设调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时，inputIndices为{1，5，9}，则在申请输入内存时， 三个输入的索引值分别为{0, 1, 2}。 | 
| length | 申请的内存字节。 | 

**返回：**

指向[OH_NN_Memory](_o_h___n_n___memory.md)实例的指针，如果创建失败就返回NULL。


### OH_NNExecutor_AllocateOutputMemory()

```
OH_NN_Memory *OH_NNExecutor_AllocateOutputMemory (OH_NNExecutor *executor, uint32_t outputIndex, size_t length )
```

**描述**

在硬件上为单个输出申请共享内存。

Neural Network Runtime 提供主动申请硬件共享内存的方法。通过指定执行器和输出索引值，该接口在单个输出关联的硬件 上，申请大小为length的共享内存，通过[OH_NN_Memory](_o_h___n_n___memory.md)实例返回。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 
| outputIndex | 输出的索引值，与调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时输出数据的顺序一致。 假设调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时，outputIndices为{4，6，8}，则在申请输出内存时， 三个输出的索引值分别为{0, 1, 2}。 | 
| length | 申请的内存字节。 | 

**返回：**

指向[OH_NN_Memory](_o_h___n_n___memory.md)实例的指针，如果创建失败就返回NULL。


### OH_NNExecutor_Construct()

```
OH_NNExecutor *OH_NNExecutor_Construct (OH_NNCompilation *compilation)
```

**描述**

创建[OH_NNExecutor](#oh_nnexecutor)执行器实例。

该接口接受一个[OH_NNCompilation](#oh_nncompilation)实例，构造一个与硬件关联的模型推理执行器。 通过[OH_NNExecutor_SetInput](#oh_nnexecutor_setinput)设置模型输入数据， 设置输入数据后，调用[OH_NNExecutor_Run](#oh_nnexecutor_run)接口执行推理，最后通过 [OH_NNExecutor_SetOutput](#oh_nnexecutor_setoutput)获取计算结果。

通过[OH_NNCompilation](#oh_nncompilation)实例创建一个[OH_NNExecutor](#oh_nnexecutor)实例后，如果不再使用[OH_NNCompilation](#oh_nncompilation)实例 创建其他[OH_NNExecutor](#oh_nnexecutor)实例，就可以销毁[OH_NNCompilation](#oh_nncompilation)实例了。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| compilation | 指向[OH_NNCompilation](#oh_nncompilation)实例的指针。 | 

**返回：**

指向[OH_NNExecutor](#oh_nnexecutor)实例的指针，如果创建失败就返回NULL。


### OH_NNExecutor_CreateInputTensorDesc()

```
NN_TensorDesc *OH_NNExecutor_CreateInputTensorDesc (const OH_NNExecutor *executor, size_t index )
```

**描述**

由指定索引值创建一个输入张量的描述。

输入张量描述包含了该张量所有类型的属性值。如果索引值**index**达到或超过输入张量的数量，接口将返回错误码。输入张量的数量可以通过 [OH_NNExecutor_GetInputCount](#oh_nnexecutor_getinputcount)获取。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 
| index | 输入张量的索引值。 | 

**返回：**

指向[NN_TensorDesc](#nn_tensordesc)实例的指针，如果创建失败就返回NULL。


### OH_NNExecutor_CreateOutputTensorDesc()

```
NN_TensorDesc *OH_NNExecutor_CreateOutputTensorDesc (const OH_NNExecutor *executor, size_t index )
```

**描述**

由指定索引值创建一个输出张量的描述。

输出张量描述包含了该张量所有类型的属性值。如果索引值**index**达到或超过输出张量的数量，接口将返回错误码。输出张量的数量可以通过 [OH_NNExecutor_GetOutputCount](#oh_nnexecutor_getoutputcount)获取。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 
| index | 输出张量的索引值。 | 

**返回：**

指向[NN_TensorDesc](#nn_tensordesc)实例的指针，如果创建失败就返回NULL。


### OH_NNExecutor_Destroy()

```
void OH_NNExecutor_Destroy (OH_NNExecutor **executor)
```

**描述**

销毁执行器实例，释放执行器占用的内存。

调用[OH_NNExecutor_Construct](#oh_nnexecutor_construct)创建的执行器实例需要调用该接口主动销毁，否则将造成内存泄漏。

如果executor为空指针或者\*executor为空指针，该接口仅打印警告日志，不执行销毁操作。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的二级指针。 | 


### OH_NNExecutor_DestroyInputMemory()

```
void OH_NNExecutor_DestroyInputMemory (OH_NNExecutor *executor, uint32_t inputIndex, OH_NN_Memory **memory )
```

**描述**

释放[OH_NN_Memory](_o_h___n_n___memory.md)实例指向的输入内存。

调用[OH_NNExecutor_AllocateInputMemory](#oh_nnexecutor_allocateinputmemory)创建的内存实例，需要主动调用该接口进行释放，否则将造成内存泄漏。 inputIndex和memory的对应关系需要和创建内存实例时保持一致。

如果memory或\*memory为空指针，该接口仅打印警告日志，不执行释放操作。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 
| inputIndex | 输入的索引值，与调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时输入数据的顺序一致。 假设调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时，inputIndices为{1，5，9}，则在释放输入内存时， 三个输入的索引值分别为{0, 1, 2}。 | 
| memory | 指向[OH_NN_Memory](_o_h___n_n___memory.md)实例的二级指针。共享内存释放后，该接口将\*memory主动设置为空指针。 | 


### OH_NNExecutor_DestroyOutputMemory()

```
void OH_NNExecutor_DestroyOutputMemory (OH_NNExecutor *executor, uint32_t outputIndex, OH_NN_Memory **memory )
```

**描述**

释放[OH_NN_Memory](_o_h___n_n___memory.md)实例指向的输出内存。

调用[OH_NNExecutor_AllocateOutputMemory](#oh_nnexecutor_allocateoutputmemory)创建的内存实例，需要主动调用该接口进行释放，否则将造成内存泄漏。 outputIndex和memory的对应关系需要和创建内存实例时保持一致。

如果memory或\*memory为空指针，该接口仅打印警告日志，不执行释放操作。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 
| outputIndex | 输出的索引值，与调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时输出数据的顺序一致。 假设调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时，outputIndices为{4，6，8}，则在释放输出内存时， 三个输出的索引值分别为{0, 1, 2}。 | 
| memory | 指向[OH_NN_Memory](_o_h___n_n___memory.md)实例的二级指针。共享内存释放后，该接口将\*memory主动设置为空指针。 | 


### OH_NNExecutor_GetInputCount()

```
OH_NN_ReturnCode OH_NNExecutor_GetInputCount (const OH_NNExecutor *executor, size_t *inputCount )
```

**描述**

获取输入张量的数量。

可以先从executor中获取输入张量的数量，然后通过[OH_NNExecutor_CreateInputTensorDesc](#oh_nnexecutor_createinputtensordesc)由指定张量索引创建张量描述。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 
| inputCount | 返回的输入张量数量。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNExecutor_GetInputDimRange()

```
OH_NN_ReturnCode OH_NNExecutor_GetInputDimRange (const OH_NNExecutor *executor, size_t index, size_t **minInputDims, size_t **maxInputDims, size_t *shapeLength )
```

**描述**

获取所有输入张量的维度范围。

当输入张量具有动态形状时，它在不同硬件上支持的维度范围可能是不同的，可以通过该接口获取当前设备上支持的维度范围。 **\*minInputDims**保存了指定输入张量的最小维度（维度数与形状匹配），而**\*maxInputDims**则保存了最大维度。 例如，一个输入张量具有动态形状 [-1, -1, -1, 3]，那么当前设备上它的**\*minInputDims**可以是[1, 10, 10, 3]， 而**\*maxInputDims**可以是[100, 1024, 1024, 3]。

注意：如果索引值**index**达到或超过输入张量的数量，接口将返回错误。输入张量的数量可以通过 [OH_NNExecutor_GetInputCount](#oh_nnexecutor_getinputcount)获取。

作为输出参数，**\*minInputDims**和**\*maxInputDims**不能为空指针，否则会返回错误。 例如您应该定义int32_t\* minInDims = NULL，然后将&amp;minInDims作为参数传入。

您无需释放**\*minInputDims**和**\*maxInputDims**的内存，它会随**executor**一起被释放。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 
| index | 输入张量的索引值。 | 
| minInputDims | 返回的数组的指针，保存了指定输入张量的最小维度（维度数与形状匹配）。 | 
| maxInputDims | 返回的数组的指针，保存了指定输入张量的最大维度（维度数与形状匹配）。 | 
| shapeLength | 返回的输入张量的维度数量，与形状一致。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNExecutor_GetOutputCount()

```
OH_NN_ReturnCode OH_NNExecutor_GetOutputCount (const OH_NNExecutor *executor, size_t *outputCount )
```

**描述**

获取输出张量的数量。

可以先从executor中获取输出张量的数量，然后通过[OH_NNExecutor_CreateOutputTensorDesc](#oh_nnexecutor_createoutputtensordesc)由指定张量索引创建张量描述。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 
| outputCount | 返回的输出张量数量。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNExecutor_GetOutputShape()

```
OH_NN_ReturnCode OH_NNExecutor_GetOutputShape (OH_NNExecutor *executor, uint32_t outputIndex, int32_t **shape, uint32_t *shapeLength )
```

**描述**

获取输出张量的维度信息。

调用[OH_NNExecutor_Run](#oh_nnexecutor_run)完成单次推理后，该接口获取指定输出的维度信息和维数。在动态形状输入、输出的场景中常用。

注意：如果索引值**outputIndex**达到或超过输出张量的数量，接口将返回错误。输出张量的数量可以通过 [OH_NNExecutor_GetOutputCount](#oh_nnexecutor_getoutputcount)获取。

作为输出参数，**\*shape**不能为空指针，否则会返回错误。例如您应该定义int32_t\* tensorShape = NULL，然后将&amp;tensorShape 作为参数传入。

您无需释放**shape**的内存，它会随**executor**一起被释放。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 
| outputIndex | 输出的索引值，与调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时输出数据的顺序一致。 假设调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时，outputIndices为{4，6，8}，则在获取输出张量 维度信息时，三个输出的索引值分别为{0, 1, 2}。 | 
| shape | 指向int32_t数组的指针，数组中的每个元素值，是输出张量在每个维度上的长度。 | 
| shapeLength | uint32_t类型的指针，返回输出的维数。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNExecutor_Run()

```
OH_NN_ReturnCode OH_NNExecutor_Run (OH_NNExecutor *executor)
```

**描述**

执行推理。

在执行器关联的硬件上，执行模型的端到端推理计算。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNExecutor_RunAsync()

```
OH_NN_ReturnCode OH_NNExecutor_RunAsync (OH_NNExecutor *executor, NN_Tensor *inputTensor[], size_t inputCount, NN_Tensor *outputTensor[], size_t outputCount, int32_t timeout, void *userData )
```

**描述**

执行异步推理。

需要先通过[OH_NNTensor_Create](#oh_nntensor_create)、[OH_NNTensor_CreateWithSize](#oh_nntensor_createwithsize)或[OH_NNTensor_CreateWithFd](#oh_nntensor_createwithfd)接口创建 输入和输出张量。然后由[OH_NNTensor_GetDataBuffer](#oh_nntensor_getdatabuffer)获取张量数据指针并向其拷贝输入数据。执行器会通过执行推理产生推理结果， 并将结果写入输出张量中。

如果输出张量具有动态形状，可以通过[OH_NNExecutor_GetOutputShape](#oh_nnexecutor_getoutputshape)接口获取输出张量的实际形状。或者通过 [OH_NNTensor_GetTensorDesc](#oh_nntensor_gettensordesc)接口从输入张量中获取张量描述， 然后通过[OH_NNTensorDesc_GetShape](#oh_nntensordesc_getshape)接口获取实际形状。

该接口是非阻塞式的，调用后会立刻返回，而推理结果、执行返回状态可以通过回调函数[NN_OnRunDone](#nn_onrundone)来获取。 如果设备驱动服务在执行过程中异常终止，可以通过回调函数[NN_OnServiceDied](#nn_onservicedied)来处理。

可以通过接口[OH_NNExecutor_SetOnRunDone](#oh_nnexecutor_setonrundone)和[OH_NNExecutor_SetOnServiceDied](#oh_nnexecutor_setonservicedied)设置回调函数 [NN_OnRunDone](#nn_onrundone)和[NN_OnServiceDied](#nn_onservicedied)。

如果推理时长超过了**timeout**，会立刻终止推理，回调函数[NN_OnRunDone](#nn_onrundone)的**errCode**参数会返回OH_NN_TIMEOUT错误。

**userData**是区分不同次异步执行的标识符，会作为回调函数的第一个参数返回，您可以使用能够区分不同次执行的任意数据作为标识符。

**起始版本：**11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 
| inputTensor | 输入张量的数组。 | 
| inputCount | 输入张量的数量。 | 
| outputTensor | 输出张量的数组。 | 
| outputCount | 输出张量的数量。 | 
| timeout | 异步推理的超时时间（单位ms），例如1000。 | 
| userData | 异步执行的标识符。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNExecutor_RunSync()

```
OH_NN_ReturnCode OH_NNExecutor_RunSync (OH_NNExecutor *executor, NN_Tensor *inputTensor[], size_t inputCount, NN_Tensor *outputTensor[], size_t outputCount )
```

**描述**

执行同步推理。

需要先通过[OH_NNTensor_Create](#oh_nntensor_create)、[OH_NNTensor_CreateWithSize](#oh_nntensor_createwithsize)或[OH_NNTensor_CreateWithFd](#oh_nntensor_createwithfd)接口创建 输入和输出张量。然后由[OH_NNTensor_GetDataBuffer](#oh_nntensor_getdatabuffer)获取张量数据指针并向其拷贝输入数据。执行器会通过执行推理产生推理结果， 并将结果写入输出张量中。

如果输出张量具有动态形状，可以通过[OH_NNExecutor_GetOutputShape](#oh_nnexecutor_getoutputshape)接口获取输出张量的实际形状。或者通过 [OH_NNTensor_GetTensorDesc](#oh_nntensor_gettensordesc)接口从输入张量中获取张量描述， 然后通过[OH_NNTensorDesc_GetShape](#oh_nntensordesc_getshape)接口获取实际形状。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 
| inputTensor | 输入张量的数组。 | 
| inputCount | 输入张量的数量。 | 
| outputTensor | 输出张量的数组。 | 
| outputCount | 输出张量的数量。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNExecutor_SetInput()

```
OH_NN_ReturnCode OH_NNExecutor_SetInput (OH_NNExecutor *executor, uint32_t inputIndex, const OH_NN_Tensor *tensor, const void *dataBuffer, size_t length )
```

**描述**

设置模型单个输入的数据。

该接口将dataBuffer中，长度为length个字节的数据，拷贝到底层硬件的共享内存。inputIndex指定设置的输入，tensor用于设置输入张量的 形状、数据类型、量化参数等信息。

由于Neural Network Runtime支持动态输入形状的模型，在固定形状输入和动态形状输入的场景下，该接口采取不同的处理策略：

- 固定形状输入的场景：tensor各属性必须和构图阶段调用[OH_NNModel_AddTensor](#oh_nnmodel_addtensor)添加的张量保持一致；

- 动态形状输入的场景：在构图阶段，由于动态输入的形状不确定，调用该接口时，要求tensor.dimensions中的每个值必须大于0， 以确定执行计算阶段输入的形状。设置形状时，只允许调整数值为-1的维度。假设在构图阶段，输入A的维度为 [-1, 224, 224, 3]，调用该接口时，只能调整第一个维度的尺寸，如：[3, 224, 224, 3]。调整其他维度将返回 OH_NN_INVALID_PARAMETER。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 
| inputIndex | 输入的索引值，与调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时输入数据的顺序一致。 假设调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时，inputIndices为{1，5，9}，则在设置输入的阶段， 三个输入的索引值分别为{0, 1, 2}。 | 
| tensor | 设置输入数据对应的张量。 | 
| dataBuffer | 指向输入数据的指针。 | 
| length | 数据内存的字节长度。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNExecutor_SetInputWithMemory()

```
OH_NN_ReturnCode OH_NNExecutor_SetInputWithMemory (OH_NNExecutor *executor, uint32_t inputIndex, const OH_NN_Tensor *tensor, const OH_NN_Memory *memory )
```

**描述**

将[OH_NN_Memory](_o_h___n_n___memory.md)实例指向的硬件共享内存，并指定为单个输入使用的内存。

在需要自行管理内存的场景下，该接口将执行输入和[OH_NN_Memory](_o_h___n_n___memory.md)内存实例绑定。执行计算时，底层硬件从内存实例指向的共享内存 中读取输入数据。通过该接口，可以实现设置输入、执行计算、读取输出的并发执行，提升数据流的推理效率。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 
| inputIndex | 输入的索引值，与调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时输入数据的顺序一致。 假设调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时，inputIndices为{1，5，9}，则在指定输入的共享 内存时，三个输入的索引值分别为{0, 1, 2}。 | 
| tensor | 指向[OH_NN_Tensor](_o_h___n_n___tensor.md)的指针，设置单个输入所对应的张量。 | 
| memory | 指向[OH_NN_Memory](_o_h___n_n___memory.md)的指针。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNExecutor_SetOnRunDone()

```
OH_NN_ReturnCode OH_NNExecutor_SetOnRunDone (OH_NNExecutor *executor, NN_OnRunDone onRunDone )
```

**描述**

设置异步推理结束后的回调处理函数。

回调函数的定义详见[NN_OnRunDone](#nn_onrundone)。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 
| onRunDone | 回调函数句柄[NN_OnRunDone](#nn_onrundone)。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNExecutor_SetOnServiceDied()

```
OH_NN_ReturnCode OH_NNExecutor_SetOnServiceDied (OH_NNExecutor *executor, NN_OnServiceDied onServiceDied )
```

**描述**

设置异步推理执行期间设备驱动服务突然死亡时的回调处理函数。

回调函数的定义详见[NN_OnServiceDied](#nn_onservicedied)。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 
| onServiceDied | 回调函数句柄[NN_OnServiceDied](#nn_onservicedied)。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNExecutor_SetOutput()

```
OH_NN_ReturnCode OH_NNExecutor_SetOutput (OH_NNExecutor *executor, uint32_t outputIndex, void *dataBuffer, size_t length )
```

**描述**

设置模型单个输出的内存。

该接口将dataBuffer指向的内存与outputIndex指定的输出绑定，内存的长度由length指定。

调用[OH_NNExecutor_Run](#oh_nnexecutor_run)完成单次模型推理后，Neural Network Runtime将比对dataBuffer指向的内存与 输出数据的长度，根据不同情况，返回不同结果：

- 如果内存大小大于或等于数据长度：则推理后的结果将拷贝至内存，并返回OH_NN_SUCCESS，可以通过访问dataBuffer读取推理结果。

- 如果内存大小小于数据长度：则[OH_NNExecutor_Run](#oh_nnexecutor_run)将返回OH_NN_INVALID_PARAMETER， 并输出日志告知内存太小的信息。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 指向[OH_NNExecutor](#oh_nnexecutor)实例的指针。 | 
| outputIndex | 输出的索引值，与调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时输出数据的顺序一致。 假设调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时，outputIndices为{4，6，8}，则在设置输出内存时， 三个输出的索引值分别为{0, 1, 2}。 | 
| dataBuffer | 指向输出数据的指针。 | 
| length | 数据内存的字节长度。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNExecutor_SetOutputWithMemory()

```
OH_NN_ReturnCode OH_NNExecutor_SetOutputWithMemory (OH_NNExecutor *executor, uint32_t outputIndex, const OH_NN_Memory *memory )
```

**描述**

将[OH_NN_Memory](_o_h___n_n___memory.md)实例指向的硬件共享内存，并指定为单个输出使用的内存。

在需要自行管理内存的场景下，该接口将执行输出和[OH_NN_Memory](_o_h___n_n___memory.md)内存实例绑定。执行计算时，底层硬件将计算结果直接写入内存实例指向 的共享内存。通过该接口，可以实现设置输入、执行计算、读取输出的并发执行，提升数据流的推理效率。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| executor | 执行器。 | 
| outputIndex | 输出的索引值，与调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时输出数据的顺序一致。 假设调用[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)时，outputIndices为{4，6，8}，则在指定输出的共享 内存时，三个输出的索引值分别为{0, 1, 2}。 | 
| memory | 指向[OH_NN_Memory](_o_h___n_n___memory.md)的指针。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNModel_AddOperation()

```
OH_NN_ReturnCode OH_NNModel_AddOperation (OH_NNModel *model, OH_NN_OperationType op, const OH_NN_UInt32Array *paramIndices, const OH_NN_UInt32Array *inputIndices, const OH_NN_UInt32Array *outputIndices )
```

**描述**

向模型实例中添加算子。

该接口向模型实例中添加算子，算子类型由op指定，算子的参数、输入和输出由paramIndices、inputIndices和 outputIndices指定。该接口将对算子参数的属性和输入、输出张量的数量进行校验，这些属性需要在调用 [OH_NNModel_AddTensorToModel](#oh_nnmodel_addtensortomodel)添加张量时正确设置。每个算子期望的参数、输入和输出属性请参考 [OH_NN_OperationType](#oh_nn_operationtype)。

paramIndices、inputIndices和outputIndices中存储的是张量的索引值，每个索引值根据张量添加进模型的顺序决定，正确 设置并添加算子要求准确设置每个张量的索引值。张量的添加参考[OH_NNModel_AddTensorToModel](#oh_nnmodel_addtensortomodel)。

如果添加算子时，添加了额外的参数（非算子需要的参数），该接口返回OH_NN_INVALID_PARAMETER；如果没有设置算子参数， 则算子按默认值设置缺省的参数，默认值请参考[OH_NN_OperationType](#oh_nn_operationtype)。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 指向[OH_NNModel](#oh_nnmodel)实例的指针。 | 
| op | 指定添加的算子类型，取值请参考[OH_NN_OperationType](#oh_nn_operationtype)的枚举值。 | 
| paramIndices | OH_NN_UInt32Array实例的指针，设置算子的参数张量索引。 | 
| inputIndices | OH_NN_UInt32Array实例的指针，指定算子的输入张量索引。 | 
| outputIndices | OH_NN_UInt32Array实例的指针，设置算子的输出张量索引。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNModel_AddTensor()

```
OH_NN_ReturnCode OH_NNModel_AddTensor (OH_NNModel *model, const OH_NN_Tensor *tensor )
```

**描述**

向模型实例中添加张量。

Neural Network Runtime模型中的数据节点和算子参数均由模型的张量构成，该接口根据tensor，向model实 例中添加张量。张量添加的顺序由模型中记录张量的索引值来确定，[OH_NNModel_SetTensorData](#oh_nnmodel_settensordata)、 [OH_NNModel_AddOperation](#oh_nnmodel_addoperation)和[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs) 接口根据该索引值，指定不同的张量。

Neural Network Runtime支持动态形状输入和输出。在添加动态形状的数据节点时，需要将tensor.dimensions中支持动态 变化的维度设置为-1。例如可将一个四维tensor的dimensions设置为[1, -1, 2, 2]，表示其第二个维度支持 动态变化。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 指向[OH_NNModel](#oh_nnmodel)实例的指针。 | 
| tensor | [OH_NN_Tensor](_o_h___n_n___tensor.md)张量的指针，tensor指定了添加到模型实例中张量的属性。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNModel_AddTensorToModel()

```
OH_NN_ReturnCode OH_NNModel_AddTensorToModel (OH_NNModel *model, const NN_TensorDesc *tensorDesc )
```

**描述**

向模型实例中添加张量。

Neural Network Runtime模型中的数据节点和算子参数均由模型的张量构成。该接口根据[NN_TensorDesc](#nn_tensordesc)向model实 例中添加张量，张量添加的顺序是模型中记录张量的索引值。[OH_NNModel_SetTensorData](#oh_nnmodel_settensordata)、 [OH_NNModel_AddOperation](#oh_nnmodel_addoperation)和[OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)接口根据该索引值，指定不同的张量。

Neural Network Runtime支持动态形状的输入和输出张量。在添加动态形状的数据节点时，需要将tensor.dimensions中支持动态 变化的维度设置为-1。例如可将一个四维tensor的dimensions设置为[1, -1, 2, 2]，表示其第二个维度支持 动态变化。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 指向[OH_NNModel](#oh_nnmodel)实例的指针。 | 
| tensorDesc | [NN_TensorDesc](#nn_tensordesc)张量的指针，[NN_TensorDesc](#nn_tensordesc)指定了添加到模型实例中张量的属性。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNModel_Construct()

```
OH_NNModel *OH_NNModel_Construct (void )
```

**描述**

创建[OH_NNModel](#oh_nnmodel)类型的模型实例，搭配OH_NNModel模块提供的其他接口，完成模型实例的构造。

在开始构图前，先调用[OH_NNModel_Construct](#oh_nnmodel_construct)创建模型实例，根据模型的拓扑结构，调用 [OH_NNModel_AddTensorToModel](#oh_nnmodel_addtensortomodel)、[OH_NNModel_AddOperation](#oh_nnmodel_addoperation)和 [OH_NNModel_SetTensorData](#oh_nnmodel_settensordata)方法，填充模型的数据节点和算子节点；然后调用 [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)指定模型的输入和输出；当构造完模型的拓扑结构，调用 [OH_NNModel_Finish](#oh_nnmodel_finish)完成模型的构建。

模型实例使用完毕后，需要调用[OH_NNModel_Destroy](#oh_nnmodel_destroy)销毁模型实例，避免内存泄漏。

**起始版本：** 9

**返回：**

返回一个指向[OH_NNModel](#oh_nnmodel)实例的指针，如果创建失败就返回NULL。


### OH_NNModel_Destroy()

```
void OH_NNModel_Destroy (OH_NNModel **model)
```

**描述**

销毁模型实例。

调用[OH_NNModel_Construct](#oh_nnmodel_construct)创建的模型实例需要调用该接口主动销毁，否则将造成内存泄漏。

如果model为空指针或者\*model为空指针，该接口仅打印警告日志，不执行销毁操作。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 指向[OH_NNModel](#oh_nnmodel)实例的二级指针。模型实例销毁后，该接口会将\*model主动设置为空指针。 | 


### OH_NNModel_Finish()

```
OH_NN_ReturnCode OH_NNModel_Finish (OH_NNModel *model)
```

**描述**

完成模型构图。

完成模型拓扑结构的搭建后，调用该接口指示构图已完成。在调用该接口后，无法进行额外的构图操作，调用 [OH_NNModel_AddTensorToModel](#oh_nnmodel_addtensortomodel)、[OH_NNModel_AddOperation](#oh_nnmodel_addoperation)、 [OH_NNModel_SetTensorData](#oh_nnmodel_settensordata)和 [OH_NNModel_SpecifyInputsAndOutputs](#oh_nnmodel_specifyinputsandoutputs)将返回 OH_NN_OPERATION_FORBIDDEN。

在调用[OH_NNModel_GetAvailableOperations](#oh_nnmodel_getavailableoperations)和[OH_NNCompilation_Construct](#oh_nncompilation_construct)之前，必须先调用该接口完成构图。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 指向[OH_NNModel](#oh_nnmodel)实例的指针。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNModel_GetAvailableOperations()

```
OH_NN_ReturnCode OH_NNModel_GetAvailableOperations (OH_NNModel *model, size_t deviceID, const bool **isSupported, uint32_t *opCount )
```

**描述**

查询硬件对模型内所有算子的支持情况，通过布尔值序列指示支持情况。

查询底层硬件对模型实例内每个算子的支持情况，硬件由deviceID指定，结果将通过isSupported指向的数组表示。如果支持第i个算子，则 (\*isSupported)[i] == true，否则为false。

该接口成功执行后，(\*isSupported)将指向记录算子支持情况的bool数组，数组长度和模型实例的算子数量相等。该数组对应的内存由 Neural Network Runtime管理，在模型实例销毁或再次调用该接口后自动销毁。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 指向[OH_NNModel](#oh_nnmodel)实例的指针。 | 
| deviceID | 指定查询的硬件ID，通过[OH_NNDevice_GetAllDevicesID](#oh_nndevice_getalldevicesid)获取。 | 
| isSupported | 指向bool数组的指针。调用该接口时，要求(\*isSupported)为空指针，否则返回 OH_NN_INVALID_PARAMETER。 | 
| opCount | 模型实例中算子的数量，对应(\*isSupported)数组的长度。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNModel_SetTensorData()

```
OH_NN_ReturnCode OH_NNModel_SetTensorData (OH_NNModel *model, uint32_t index, const void *dataBuffer, size_t length )
```

**描述**

设置张量的数值。

对于具有常量值的张量（如模型的权重），需要在构图阶段使用该接口设置数值。张量的索引值根据张量添加进模型的顺序决定，张量的添加参考 [OH_NNModel_AddTensorToModel](#oh_nnmodel_addtensortomodel)。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 指向[OH_NNModel](#oh_nnmodel)实例的指针。 | 
| index | 张量的索引值。 | 
| dataBuffer | 指向真实数据内存的指针。 | 
| length | 数据内存的长度。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNModel_SetTensorQuantParams()

```
OH_NN_ReturnCode OH_NNModel_SetTensorQuantParams (OH_NNModel *model, uint32_t index, NN_QuantParam *quantParam )
```

**描述**

设置张量的量化参数，参考[NN_QuantParam](#nn_quantparam)。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 指向[OH_NNModel](#oh_nnmodel)实例的指针。 | 
| index | 张量的索引值。 | 
| quantParam | 指向[NN_QuantParam](#nn_quantparam)的指针。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNModel_SetTensorType()

```
OH_NN_ReturnCode OH_NNModel_SetTensorType (OH_NNModel *model, uint32_t index, OH_NN_TensorType tensorType )
```

**描述**

设置张量的类型，参考[OH_NN_TensorType](#oh_nn_tensortype)。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 指向[OH_NNModel](#oh_nnmodel)实例的指针。 | 
| index | 张量的索引值。 | 
| tensorType | 张量类型。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)


### OH_NNModel_SpecifyInputsAndOutputs()

```
OH_NN_ReturnCode OH_NNModel_SpecifyInputsAndOutputs (OH_NNModel *model, const OH_NN_UInt32Array *inputIndices, const OH_NN_UInt32Array *outputIndices )
```

**描述**

指定模型的输入和输出张量的索引值。

模型实例需要指定张量作为端到端的输入和输出张量。注意设置一个张量为输入或输出张量后，就不能再通过调用[OH_NNModel_SetTensorData](#oh_nnmodel_settensordata) 设置张量数据，而需要在执行阶段调用OH_NNExecutor的方法设置输入或输出张量数据。

张量的索引值根据张量添加进模型的顺序决定，张量的添加参考[OH_NNModel_AddTensorToModel](#oh_nnmodel_addtensortomodel)。

暂时不支持异步设置模型输入和输出张量。

**起始版本：** 9

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| model | 指向[OH_NNModel](#oh_nnmodel)实例的指针。 | 
| inputIndices | OH_NN_UInt32Array实例的指针，指定算子的输入张量。 | 
| outputIndices | OH_NN_UInt32Array实例的指针，指定算子的输出张量。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNQuantParam_Create()

```
NN_QuantParam *OH_NNQuantParam_Create ()
```

**描述**

创建一个[NN_QuantParam](#nn_quantparam)量化参数实例。

创建[NN_QuantParam](#nn_quantparam)量化参数实例后，调用[OH_NNQuantParam_SetScales](#oh_nnquantparam_setscales)、[OH_NNQuantParam_SetZeroPoints](#oh_nnquantparam_setzeropoints)或 [OH_NNQuantParam_SetNumBits](#oh_nnquantparam_setnumbits)设置它的属性值，并调用[OH_NNModel_SetTensorQuantParams](#oh_nnmodel_settensorquantparams)将它设置到 [NN_Tensor](#nn_tensor)中。最后再调用[OH_NNQuantParam_Destroy](#oh_nnquantparam_destroy)销毁它，以避免内存泄露。

**起始版本：** 11

**返回：**

指向[NN_QuantParam](#nn_quantparam)实例的指针，如果创建失败就返回NULL。


### OH_NNQuantParam_Destroy()

```
OH_NN_ReturnCode OH_NNQuantParam_Destroy (NN_QuantParam **quantParams)
```

**描述**

销毁[NN_QuantParam](#nn_quantparam)实例。

当设置[NN_QuantParam](#nn_quantparam)实例到一个[NN_Tensor](#nn_tensor)中后，如果不再使用该实例，需要销毁它以避免内存泄漏。

如果**quantParams**或 **\*quantParams**是空指针，那么该接口仅打印警告日志，不会执行销毁操作。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| quantParams | 指向[NN_QuantParam](#nn_quantparam)实例的二级指针。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNQuantParam_SetNumBits()

```
OH_NN_ReturnCode OH_NNQuantParam_SetNumBits (NN_QuantParam *quantParams, const uint32_t *numBits, size_t quantCount )
```

**描述**

设置[NN_QuantParam](#nn_quantparam)的量化位数。

参数**quantCount**是张量中量化参数的数量，例如对于per-channel量化，**quantCount**就是通道数量。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| quantParams | 指向[NN_QuantParam](#nn_quantparam)实例的指针。 | 
| numBits | 张量中所有量化参数的量化位数构成的数组。 | 
| quantCount | 张量中量化参数的数量。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNQuantParam_SetScales()

```
OH_NN_ReturnCode OH_NNQuantParam_SetScales (NN_QuantParam *quantParams, const double *scales, size_t quantCount )
```

**描述**

设置[NN_QuantParam](#nn_quantparam)的缩放系数。

参数**quantCount**是张量中量化参数的数量，例如对于per-channel量化，**quantCount**就是通道数量。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| quantParams | 指向[NN_QuantParam](#nn_quantparam)实例的指针。 | 
| scales | 张量中所有量化参数的缩放系数构成的数组。 | 
| quantCount | 张量中量化参数的数量。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNQuantParam_SetZeroPoints()

```
OH_NN_ReturnCode OH_NNQuantParam_SetZeroPoints (NN_QuantParam *quantParams, const int32_t *zeroPoints, size_t quantCount )
```

**描述**

设置[NN_QuantParam](#nn_quantparam)的零点。

参数**quantCount**是张量中量化参数的数量，例如对于per-channel量化，**quantCount**就是通道数量。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| quantParams | 指向[NN_QuantParam](#nn_quantparam)实例的指针。 | 
| zeroPoints | 张量中所有量化参数的零点构成的数组。 | 
| quantCount | 张量中量化参数的数量。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNTensor_Create()

```
NN_Tensor *OH_NNTensor_Create (size_t deviceID, NN_TensorDesc *tensorDesc )
```

**描述**

从[NN_TensorDesc](#nn_tensordesc)创建一个[NN_Tensor](#nn_tensor)实例。

该接口使用[OH_NNTensorDesc_GetByteSize](#oh_nntensordesc_getbytesize)计算张量数据的字节数，并为其分配设备内存。 设备驱动将直接通过“零拷贝”方式获取张量数据。

注意：该接口会将**tensorDesc**复制到[NN_Tensor](#nn_tensor)中，因此当**tensorDesc**不再使用时， 您应该调用[OH_NNTensorDesc_Destroy](#oh_nntensordesc_destroy)接口销毁它。

如果张量形状是动态的，该接口将返回错误码。

**deviceID**表示所选设备。如果为0，则默认使用设备列表中的第1台设备。

**必须提供tensorDesc**，如果它是空指针，则返回错误码。

当[NN_Tensor](#nn_tensor)实例不再使用时，需要调用[OH_NNTensor_Destroy](#oh_nntensor_destroy)销毁它。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| deviceID | 设备 ID。如果为0，则默认使用当前设备列表中的第1台设备。 | 
| tensorDesc | 指向[NN_TensorDesc](#nn_tensordesc)实例的指针。 | 

**返回：**

指向[NN_Tensor](#nn_tensor)实例的指针，如果创建失败就返回NULL。


### OH_NNTensor_CreateWithFd()

```
NN_Tensor *OH_NNTensor_CreateWithFd (size_t deviceID, NN_TensorDesc *tensorDesc, int fd, size_t size, size_t offset )
```

**描述**

按照指定共享内存的文件描述符和[NN_TensorDesc](#nn_tensordesc)创建{\@Link NN_Tensor}实例。

该接口复用文件描述符**fd**对应的共享内存，**fd**可能来自另一个[NN_Tensor](#nn_tensor)实例。 当调用[OH_NNTensor_Destroy](#oh_nntensor_destroy)接口销毁该接口创建的张量时，不会释放该张量数据的内存。

注意：该接口会将**tensorDesc**复制到[NN_Tensor](#nn_tensor)中。因此当**tensorDesc**不再使用时， 您应该调用[OH_NNTensorDesc_Destroy](#oh_nntensordesc_destroy)接口销毁它。

**deviceID**表示所选设备。如果为0，则默认使用当前设备列表中的第1台设备。

必须提供**tensorDesc**，如果为空指针，则该接口返回错误码。

当[NN_Tensor](#nn_tensor)实例不再使用时，需要调用[OH_NNTensor_Destroy](#oh_nntensor_destroy)销毁它。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| deviceID | 设备 ID，如果为0，则默认使用当前设备列表中的第1台设备。 | 
| tensorDesc | 指向[NN_TensorDesc](#nn_tensordesc)实例的指针。 | 
| fd | 要使用的共享内存的文件描述符。 | 
| size | 要使用的共享内存的大小。 | 
| offset | 要使用的共享内存的偏移量。 | 

**返回：**

指向[NN_Tensor](#nn_tensor)实例的指针，如果创建失败就返回NULL。


### OH_NNTensor_CreateWithSize()

```
NN_Tensor *OH_NNTensor_CreateWithSize (size_t deviceID, NN_TensorDesc *tensorDesc, size_t size )
```

**描述**

按照指定内存大小和[NN_TensorDesc](#nn_tensordesc)创建[NN_Tensor](#nn_tensor)实例。

该接口使用**size**作为张量数据的字节数，并为其分配设备内存。设备将直接通过“零拷贝”方式获取张量数据。

注意，该接口会将**tensorDesc**复制到[NN_Tensor](#nn_tensor)中。因此当**tensorDesc**不再使用时， 您应该调用[OH_NNTensorDesc_Destroy](#oh_nntensordesc_destroy)接口销毁它。

**deviceID**表示所选设备ID，如果为0，则使用第1台设备。

**tensorDesc**必须提供，如果它是空指针，则该接口返回错误码。 **size**必须不小于**tensorDesc**的数据占用字节数（可由[OH_NNTensorDesc_GetByteSize](#oh_nntensordesc_getbytesize)获取）， 否则该接口将返回错误码。如果张量形状是动态的，不会检查**size**。

当[NN_Tensor](#nn_tensor)实例不再使用时，需要调用[OH_NNTensor_Destroy](#oh_nntensor_destroy)销毁它。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| deviceID | 设备ID。如果为0，则默认使用当前设备列表中的第1台设备。 | 
| tensorDesc | 指向[NN_TensorDesc](#nn_tensordesc)实例的指针。 | 
| size | 需要分配的张量数据的大小。 | 

**返回：**

指向[NN_Tensor](#nn_tensor)实例的指针，如果创建失败就返回NULL。


### OH_NNTensor_Destroy()

```
OH_NN_ReturnCode OH_NNTensor_Destroy (NN_Tensor **tensor)
```

**描述**

销毁一个[NN_Tensor](#nn_tensor)实例。

当不再使用[NN_Tensor](#nn_tensor)实例时，需要调用该接口销毁该实例，否则将发生内存泄漏。

如果**tensor**或**\*tensor**为空指针，则该接口将返回错误码，并且不执行销毁操作。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tensor | 指向[NN_Tensor](#nn_tensor)实例的二级指针。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNTensor_GetDataBuffer()

```
void *OH_NNTensor_GetDataBuffer (const NN_Tensor *tensor)
```

**描述**

获取[NN_Tensor](#nn_tensor)数据的内存地址。

您可以从张量数据内存读取/写入数据。数据内存是从设备上的共享内存映射的，因此设备驱动可通过这种“零拷贝”方式直接获取张量数据。

注意：张量数据仅能使用对应共享内存中的[offset, size)一段，其中offset是共享内存上的偏移量，可以通过 [OH_NNTensor_GetOffset](#oh_nntensor_getoffset)获取，而size是共享内存的总大小，可以通过[OH_NNTensor_GetSize](#oh_nntensor_getsize)获取。

如果**Tensor**是空指针，则该接口将会返回空指针。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tensor | 指向[NN_Tensor](#nn_tensor)实例的指针。 | 

**返回：**

指向张量数据内存的指针。如果操作失败，则返回空指针。


### OH_NNTensor_GetFd()

```
OH_NN_ReturnCode OH_NNTensor_GetFd (const NN_Tensor *tensor, int *fd )
```

**描述**

获取[NN_Tensor](#nn_tensor)数据所在共享内存的文件描述符。

文件描述符**fd**对应了一块设备共享内存，可以通过[OH_NNTensor_CreateWithFd](#oh_nntensor_createwithfd)被另外一个[NN_Tensor](#nn_tensor)使用。

如果**tensor**或**fd**为空指针，该接口将返回错误。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tensor | 指向[NN_Tensor](#nn_tensor)实例的指针。 | 
| fd | 返回的共享内存文件描述符。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNTensor_GetOffset()

```
OH_NN_ReturnCode OH_NNTensor_GetOffset (const NN_Tensor *tensor, size_t *offset )
```

**描述**

获取[NN_Tensor](#nn_tensor)数据所在共享内存上的偏移量。

**offset**是张量数据在对应共享内存上的偏移量，可以通过[OH_NNTensor_CreateWithFd](#oh_nntensor_createwithfd)接口，连同共享内存文件描述符、 共享内存总大小一起被另外的[NN_Tensor](#nn_tensor)使用。

注意：张量数据仅能使用文件描述符**fd**对应的共享内存中的[offset, size)一段，其中offset是共享内存上的偏移量，可以通过 [OH_NNTensor_GetOffset](#oh_nntensor_getoffset)获取，而size是共享内存的总大小，可以通过[OH_NNTensor_GetSize](#oh_nntensor_getsize)获取。

如果**tensor**或**offset**为空指针，该接口将返回错误。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tensor | 指向[NN_Tensor](#nn_tensor)实例的指针。 | 
| offset | 返回的张量内存fd的偏移量。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNTensor_GetSize()

```
OH_NN_ReturnCode OH_NNTensor_GetSize (const NN_Tensor *tensor, size_t *size )
```

**描述**

获取[NN_Tensor](#nn_tensor)数据所在共享内存的大小。

**size**与接口[OH_NNTensor_CreateWithSize](#oh_nntensor_createwithsize)和[OH_NNTensor_CreateWithFd](#oh_nntensor_createwithfd)的参数**size**相同， 但对于通过[OH_NNTensor_Create](#oh_nntensor_create)创建的张量，**size**等于张量数据实际占用字节数 （可由[OH_NNTensorDesc_GetByteSize](#oh_nntensordesc_getbytesize)获取）。

注意：张量数据仅能使用文件描述符**fd**对应的共享内存中的[offset, size)一段，其中offset是共享内存上的偏移量，可以通过 [OH_NNTensor_GetOffset](#oh_nntensor_getoffset)获取，而size是共享内存的总大小，可以通过[OH_NNTensor_GetSize](#oh_nntensor_getsize)获取。

如果**tensor**或**size**为空指针，该接口将返回错误。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tensor | 指向[NN_Tensor](#nn_tensor)实例的指针。 | 
| size | 返回的数据所在共享内存的大小。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNTensor_GetTensorDesc()

```
NN_TensorDesc *OH_NNTensor_GetTensorDesc (const NN_Tensor *tensor)
```

**描述**

获取[NN_Tensor](#nn_tensor)的[NN_TensorDesc](#nn_tensordesc)实例。

调用该接口获取指定[NN_Tensor](#nn_tensor)实例的内部[NN_TensorDesc](#nn_tensordesc)实例指针。 您可以从返回的[NN_TensorDesc](#nn_tensordesc)实例中获取各种类型的张量属性，例如名称/数据布局/数据类型/形状等。

您不应销毁返回的[NN_TensorDesc](#nn_tensordesc)实例，因为它指向了[NN_Tensor](#nn_tensor)的内部实例，否则一旦调用[OH_NNTensor_Destroy](#oh_nntensor_destroy) 将会发生双重释放的内存崩溃。

如果**Tensor**是空指针，则该接口将会返回空指针。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tensor | 指向[NN_Tensor](#nn_tensor)实例的指针。 | 

**返回：**

指向[NN_TensorDesc](#nn_tensordesc)实例的指针，如果创建失败就返回NULL。


### OH_NNTensorDesc_Create()

```
NN_TensorDesc *OH_NNTensorDesc_Create ()
```

**描述**

创建一个[NN_TensorDesc](#nn_tensordesc)实例。

[NN_TensorDesc](#nn_tensordesc)描述了各种张量属性，如名称/数据类型/形状/格式等。

可以调用以下接口，基于传入的[NN_TensorDesc](#nn_tensordesc)实例创建[NN_Tensor](#nn_tensor)实例：

[OH_NNTensor_Create](#oh_nntensor_create)

[OH_NNTensor_CreateWithSize](#oh_nntensor_createwithsize)

[OH_NNTensor_CreateWithFd](#oh_nntensor_createwithfd)

注意：该接口会将[NN_TensorDesc](#nn_tensordesc)实例复制到[NN_Tensor](#nn_tensor)中，因此您可以创建多个[NN_Tensor](#nn_tensor)个实例， 并持有相同的[NN_TensorDesc](#nn_tensordesc)实例。当[NN_TensorDesc](#nn_tensordesc)实例不再使用时， 您应该调用[OH_NNTensorDesc_Destroy](#oh_nntensordesc_destroy)接口销毁它。

**起始版本：** 11

**返回：**

指向[NN_TensorDesc](#nn_tensordesc)实例的指针，如果创建失败就返回NULL。


### OH_NNTensorDesc_Destroy()

```
OH_NN_ReturnCode OH_NNTensorDesc_Destroy (NN_TensorDesc **tensorDesc)
```

**描述**

释放一个[NN_TensorDesc](#nn_tensordesc)实例。

当[NN_TensorDesc](#nn_tensordesc)实例不再使用时，需要调用该接口销毁，否则将发生内存泄漏。

如果**tensorDesc**或**\*tensorDesc**为空指针，则该接口将返回错误码，并且不会执行销毁操作。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tensorDesc | 指向[NN_TensorDesc](#nn_tensordesc)实例的二级指针。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNTensorDesc_GetByteSize()

```
OH_NN_ReturnCode OH_NNTensorDesc_GetByteSize (const NN_TensorDesc *tensorDesc, size_t *byteSize )
```

**描述**

获取基于[NN_TensorDesc](#nn_tensordesc)的形状和数据类型计算的数据占用字节数。

调用该接口可基于[NN_TensorDesc](#nn_tensordesc)的形状和数据类型计算得到的数据占用字节数。

如果张量形状是动态可变的，该接口将返回错误码，**byteSize**将为0。

如果需要获取张量数据的元素个数，请调用[OH_NNTensorDesc_GetElementCount](#oh_nntensordesc_getelementcount)。

如果**tensorDesc**或**byteSize**为空指针，则该接口将返回错误码。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tensorDesc | 指向[NN_TensorDesc](#nn_tensordesc)实例的指针。 | 
| byteSize | 返回的数据字节数。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNTensorDesc_GetDataType()

```
OH_NN_ReturnCode OH_NNTensorDesc_GetDataType (const NN_TensorDesc *tensorDesc, OH_NN_DataType *dataType )
```

**描述**

获取[NN_TensorDesc](#nn_tensordesc)的数据类型。

调用该接口获取指定[NN_TensorDesc](#nn_tensordesc)实例的数据类型。

如果**tensorDesc**或**dataType**为空指针，则该接口将返回错误码。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tensorDesc | 指向[NN_TensorDesc](#nn_tensordesc)实例的指针。 | 
| dataType | 返回的张量数据类型。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNTensorDesc_GetElementCount()

```
OH_NN_ReturnCode OH_NNTensorDesc_GetElementCount (const NN_TensorDesc *tensorDesc, size_t *elementCount )
```

**描述**

获取[NN_TensorDesc](#nn_tensordesc)的元素个数。

调用该接口获取指定[NN_TensorDesc](#nn_tensordesc)实例的元素个数。如果需要获取张量数据的字节大小， 请调用[OH_NNTensorDesc_GetByteSize](#oh_nntensordesc_getbytesize)。

如果张量形状是动态可变的，则该接口将返回错误码，**elementCount**将为0。

如果**tensorDesc**或**elementCount**为空指针，则该接口将返回错误码。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tensorDesc | 指向[NN_TensorDesc](#nn_tensordesc)实例的指针。 | 
| elementCount | 张量返回的元素个数。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNTensorDesc_GetFormat()

```
OH_NN_ReturnCode OH_NNTensorDesc_GetFormat (const NN_TensorDesc *tensorDesc, OH_NN_Format *format )
```

**描述**

获取[NN_TensorDesc](#nn_tensordesc)的数据布局。

调用该接口获取指定[NN_TensorDesc](#nn_tensordesc)实例的数据布局[OH_NN_Format](#oh_nn_format)。

如果**tensorDesc**或**format**为空指针，则该接口将返回错误码。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tensorDesc | 指向[NN_TensorDesc](#nn_tensordesc)实例的指针。 | 
| format | 返回的张量数据布局。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNTensorDesc_GetName()

```
OH_NN_ReturnCode OH_NNTensorDesc_GetName (const NN_TensorDesc *tensorDesc, const char **name )
```

**描述**

获取[NN_TensorDesc](#nn_tensordesc)的名称。

调用该接口获取指定[NN_TensorDesc](#nn_tensordesc)实例的名称，**\*name**的值是以**'\0'**结尾的C风格字符串。

如果**tensorDesc**或**name**为空指针，则该接口将返回错误码。 作为输出参数，**\*name**必须为空指针，否则该接口将返回错误码。 例如您应该定义char\* tensorName = NULL，并传递&amp;tensorName作为**name**的参数。

您不需要释放**name**的内存，当**tensorDesc**被销毁时，它会被自动释放。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tensorDesc | 指向[NN_TensorDesc](#nn_tensordesc)实例的指针。 | 
| name | 返回的张量名称。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNTensorDesc_GetShape()

```
OH_NN_ReturnCode OH_NNTensorDesc_GetShape (const NN_TensorDesc *tensorDesc, int32_t **shape, size_t *shapeLength )
```

**描述**

获取[NN_TensorDesc](#nn_tensordesc)的形状。

调用该接口获取指定[NN_TensorDesc](#nn_tensordesc)实例的形状。

如果**tensorDesc**、**shape**或**shapeLength**为空指针，则该接口将返回错误码。 作为输出参数，**\*shape**必须为空指针，否则该接口将返回错误码。 例如您应该定义 int32_t\* tensorShape = NULL，并传递&amp;tensorShape作为**shape**的参数。

您不需要释放**shape**的内存。当**tensorDesc**被销毁时，它会自动释放。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tensorDesc | 指向[NN_TensorDesc](#nn_tensordesc)实例的指针。 | 
| shape | 返回的张量形状列表。 | 
| shapeLength | 返回的形状列表长度。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNTensorDesc_SetDataType()

```
OH_NN_ReturnCode OH_NNTensorDesc_SetDataType (NN_TensorDesc *tensorDesc, OH_NN_DataType dataType )
```

**描述**

设置[NN_TensorDesc](#nn_tensordesc)的数据类型。

[NN_TensorDesc](#nn_tensordesc)实例创建完成后，调用该接口设置张量数据类型。

如果**tensorDesc**为空指针，则该接口将返回错误码。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tensorDesc | 指向[NN_TensorDesc](#nn_tensordesc)实例的指针。 | 
| dataType | 需要设置的张量数据类型。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNTensorDesc_SetFormat()

```
OH_NN_ReturnCode OH_NNTensorDesc_SetFormat (NN_TensorDesc *tensorDesc, OH_NN_Format format )
```

**描述**

设置[NN_TensorDesc](#nn_tensordesc)的数据布局。

[NN_TensorDesc](#nn_tensordesc)实例创建完成后，调用该接口设置张量的数据布局[OH_NN_Format](#oh_nn_format)。

如果**tensorDesc**为空指针，则该接口将返回错误码。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tensorDesc | 指向[NN_TensorDesc](#nn_tensordesc)实例的指针。 | 
| format | 需要设置的张量数据布局。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNTensorDesc_SetName()

```
OH_NN_ReturnCode OH_NNTensorDesc_SetName (NN_TensorDesc *tensorDesc, const char *name )
```

**描述**

设置[NN_TensorDesc](#nn_tensordesc)的名称。

[NN_TensorDesc](#nn_tensordesc)实例创建完成后，调用该接口设置张量的名称，**\*name**的值是以**'\0'**结尾的C风格字符串。

如果**tensorDesc**或**name**为空指针，则该接口将返回错误码。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tensorDesc | 指向[NN_TensorDesc](#nn_tensordesc)实例的指针。 | 
| name | 需要设置的张量名称。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。


### OH_NNTensorDesc_SetShape()

```
OH_NN_ReturnCode OH_NNTensorDesc_SetShape (NN_TensorDesc *tensorDesc, const int32_t *shape, size_t shapeLength )
```

**描述**

设置[NN_TensorDesc](#nn_tensordesc)的数据形状。

[NN_TensorDesc](#nn_tensordesc)实例创建完成后，调用该接口设置张量形状。

如果**tensorDesc**或**shape**为空指针，或**shapeLength**为0，则该接口将返回错误码。

**起始版本：** 11

**参数:**

| 名称 | 描述 | 
| -------- | -------- |
| tensorDesc | 指向[NN_TensorDesc](#nn_tensordesc)实例的指针。 | 
| shape | 需要设置的张量形状列表。 | 
| shapeLength | 需要设置的张量形状列表长度。 | 

**返回：**

函数执行的结果状态。执行成功返回OH_NN_SUCCESS；失败返回具体错误码，具体失败错误码可参考[OH_NN_ReturnCode](#oh_nn_returncode)。
