# Using MindSpore Lite for Model Conversion

## Basic Concepts

- MindSpore Lite: a built-in AI inference engine of OpenHarmony that provides inference deployment for deep learning models.

- Neural Network Runtime (NNRt): a bridge that connects the upper-layer AI inference framework to the bottom-layer acceleration chip to implement cross-chip inference and computing of AI models.

- Common neural network model: network models commonly used for AI applications, including MindSpore, ONNX, TensorFlow, and CAFFE.

- Offline models: network models obtained using the offline model conversion tool of the AI hardware vendor. The hardware vendor is responsible for parsing and inference of offline models.

## When to Use

The deployment process is as follows:
1. Use the MindSpore Lite model conversion tool to convert the original model (for example, ONNX or CAFFE) to a .ms model file. You can check the supported operators against the [MindSpore Lite Kit operator list](mindspore-lite-supported-operators.md) to ensure that the model conversion is successful.
2. Call APIs of the MindSpore Lite inference engine to perform [model inference](mindspore-lite-guidelines.md).

## Obtaining the Model Conversion Tool

You can obtain the MindSpore Lite model conversion tool in either of the following ways:

### Download

| Component                                                   | Hardware Platform| OS    | URL                                                        | SHA-256                                                      |
| ------------------------------------------------------- | -------- | ------------ | ------------------------------------------------------------ | ------------------------------------------------------------ |
| On-device inference and training benchmark tool, converter tool, and cropper tool| CPU      | Linux-x86_64 | [mindspore-lite-2.3.0-linux-x64.tar.gz](https://ms-release.obs.cn-north-4.myhuaweicloud.com/2.3.0/MindSpore/lite/release/linux/x86_64/mindspore-lite-2.3.0-linux-x64.tar.gz) | 060d698a171b52c38b64c8d65927816daf4b81d8e2b5069718aeb91a9f8a154c |

### Source Code Building

> **NOTE**
>
> - The build option that supports PyTorch model conversion is disabled by default. Therefore, the downloaded installation package does not support PyTorch model conversion and can be obtained only by source code building.
>
> - If the transpose and convolution operators are fused in the model, you need to obtain the model through source code compilation. Otherwise, an alarm similar to the following may be displayed: node infer shape failed, node is Default/Conv2DFusion-xxx.
>
> - If the NPU backend is used for inference, you need to determine whether to [disable the fusion of clip operators](#disabling-the-fusion-of-specified-operators) and obtain the model conversion tool through source code compilation. Otherwise, an error similar to the following may be reported: BuildKirinNPUModel# Create full model kernel failed.

1. The environment requirements are as follows:

   - System environment: Linux x86_64 (Ubuntu 18.04.02LTS recommended)
   - C++ build dependencies:
     -  GCC >= 7.3.0
     -  CMake >= 3.18.3
     -  Git >= 2.28.0

2. Obtain the [MindSpore Lite source code](https://gitee.com/openharmony/third_party_mindspore).
   The complete source code of MindSpore Lite is available at `mindspore-src/source/`.

3. Start building.

   To obtain the conversion tool that supports PyTorch model conversion, run `export MSLITE_ENABLE_CONVERT_PYTORCH_MODEL=on && export LIB_TORCH_PATH="/home/user/libtorch"` before you begin model building. Add the libtorch environment variable `export LD_LIBRARY_PATH="/home/user/libtorch/lib:${LD_LIBRARY_PATH}"` before conversion. You can download the libtorch package of the CPU version and decompress it to `/home/user/libtorch`.

   ```bash
   cd mindspore-src/source/
   bash build.sh -I x86_64 -j 8
   ```

   After the building is complete, you can obtain the MindSpore Lite release package from `output/` in the root directory of the source code. The conversion tool is available at `tools/converter/converter/` after decompression.

## Configure environment variables.

After obtaining the model conversion tool, you need to add the dynamic link library (DLL) required by the conversion tool to the environment variable `LD_LIBRARY_PATH`.

```bash
export LD_LIBRARY_PATH=${PACKAGE_ROOT_PATH}/tools/converter/lib:${LD_LIBRARY_PATH}
```

${PACKAGE_ROOT_PATH} indicates the path where the MindSpore Lite release package is decompressed.


## Parameter Description

The MindSpore Lite model conversion tool provides multiple parameter settings. You can use them as required. In addition, you can run `./converter_lite --help` to obtain the help information in real time.
The following describes the parameters in detail.


|        Name       | Mandatory           | Description                                                    | Value Range                                        |
| :----------------: | ------------------- | ------------------------------------------------------------ | ------------------------------------------------ |
|       --help       | No                 | Displays all help information.                                          | -                                                |
|       --fmk        | Yes                 | Original format of the input model. This parameter can be set to **MSLITE** only when the MS model is converted to micro code.| MINDIR, CAFFE, TFLITE, TF, ONNX, PYTORCH, or MSLITE|
|    --modelFile     | Yes                 | Path of the input model.                                            | -                                                |
|    --outputFile    | Yes                 | Path of the output model. You do not need to add an extension because the extension `.ms` is automatically generated.           | -                                                |
|    --weightFile    | Yes for CAFFE model conversion| Path of the model weight file.                                    | -                                                |
|    --configFile    | No                 | 1) Path of the quantization configuration file after training. 2) Path of the extended function configuration file.| -                                                |
|       --fp16       | No                 | Whether to store the weights of float32 data as float16 data during model serialization.<br>The default value is **off**.| on or off                                         |
|    --inputShape    | No                 | Set the input dimensions of the model. Make sure that the sequence of the input dimensions is the same as that of the original model. The model structure can be further optimized for some specific models, but the dynamic shape feature will be unavailable for the converted model. Separate each input name and shape by a colon (:), and separate each pair of input name and shape by a semicolon (;). In addition, enclose them with double quotation marks (""). For example, set this parameter to **"inTensorName_1: 1,32,32,4;inTensorName_2:1,64,64,4;"**.| -                                                |
| --inputDataFormat  | No                 | Input format of the exported model. This parameter is valid only for 4D input.<br>The default value is **NHWC**.| NHWC or NCHW                                      |
|  --inputDataType   | No                 | Data type of the input tensor of the quantization model. This parameter is valid only when the quantization parameters (**scale** and **zero point**) are configured for the input tensor. The data type is the same as that of the input tensor of the original model by default.<br>The default value is **DEFAULT**.| FLOAT32, INT8, UINT8, or DEFAULT                   |
|  --outputDataType  | No                 | Data type of the output tensor of the quantization model. This parameter is valid only when the quantization parameters (**scale** and **zero point**) are configured for the output tensor. The data type is the same as that of the output tensor of the original model by default.<br>The default value is **DEFAULT**.| FLOAT32, INT8, UINT8, or DEFAULT                   |
| --outputDataFormat | No                 | Output format of the exported model. This parameter is valid only for 4D input.                | NHWC or NCHW                                      |

> **NOTE**
> - The parameter name and value are separated by an equal sign (=) and no space is allowed between them.
> - Generally, a CAFFE model has two files: the model structure `*.prototxt`, which corresponds to the `--modelFile` parameter, and the model weight `*.caffemodel`, which corresponds to the `--weightFile` parameter.

## Example

The following conversion command uses the CAFFE model LeNet as an example.

```bash
./converter_lite --fmk=CAFFE --modelFile=lenet.prototxt --weightFile=lenet.caffemodel --outputFile=lenet
```
In this example, the CAFFE model is used. Therefore, you need to specify two input files: model structure and model weight. In addition, add other mandatory parameters, that is, fmk type and output path.
The command output is as follows:

```bash
CONVERT RESULT SUCCESS:0
```
This indicates that the CAFFE model is successfully converted to the MindSpore Lite model. A new file named **lenet.ms** is generated in the specified path.

## (Optional) Offline Model Conversion

If you want to reduce the loading delay to meet the requirements of the deployment scenario, you can use offline model-based inference as an alternative. The operation procedure is as follows:

During inference, MindSpore Lite directly sends the offline model to the AI hardware connected to NNRt. This way, the model can be loaded without the need for online image composition, greatly reducing the model loading delay. In addition, MindSpore Lite can provide additional hardware-specific information to assist the AI hardware in model inference.

### Constraints

- Offline model inference can only be implemented at the NNRt backend. The AI hardware needs to connect to NNRt and support offline model inference.
- The offline model conversion tool can be obtained only through source code building.
- During offline model conversion, `fmk` must be set to `THIRDPARTY`.
- The offline model comes as a black box and cannot be directly parsed by the conversion tool to obtain its input and output tensor information. Therefore, you need to manually configure the tensor information in the extended configuration file of the conversion tool.

### Description of the Extended Configuration File

An example of the extended configuration is as follows:
- `[third_party_model]` in the first line is a fixed keyword that indicates the section of offline model configuration.
- The following lines exhibit the name, data type, shape, and memory format of the input and output tensors of the model respectively. Each field occupies a line and is expressed in the key-value pair format. The sequence of fields is not limited.
- Among the fields, data type and shape are mandatory, and other parameters are optional.
- Extended parameters are also provided. They are used to encapsulate custom configuration of the offline model into an .ms file in the key-value pair format. The .ms file is passed to the AI hardware by NNRt during inference.

```text
[third_party_model]
input_names=in_0;in_1
input_dtypes=float32;float32
input_shapes=8,256,256;8,256,256,3
input_formats=NCHW;NCHW
output_names=out_0
output_dtypes=float32
output_shapes=8,64
output_formats=NCHW
extended_parameters=key_foo:value_foo;key_bar:value_bar
```

Field description:

- `input_names` (optional): model input name, which is in the string format. If multiple names are specified, use a semicolon (;) to separate them.
- `input_dtypes` (mandatory): model input data type, which is in the type format. If multiple data types are specified, use a semicolon (;) to separate them.
- `input_shapes` (mandatory): model input shape, which is in the integer array format. If multiple input shapes are specified, use a semicolon (;) to separate them.
- `input_formats` (optional): model input memory format, which is in the string format. If multiple formats are specified, use a semicolon (;) to separate them. The default value is NHWC.
- `output_names` (optional): model output name, which is in the string format. If multiple names are specified, use a semicolon (;) to separate them.
- `output_dtypes` (mandatory): model output data type, which is in the type format. If multiple data types are specified, use a semicolon (;) to separate them.
- `output_shapes` (mandatory): model output shape, which is in the integer array format. If multiple output shapes are specified, use a semicolon (;) to separate them.
- `output_formats` (optional): model output memory format, which is in the string format. If multiple formats are specified, use a semicolon (;) to separate them. The default value is NHWC.
- `extended_parameters` (optional): custom configuration of the inference hardware, which is in the key-value pair format. It is passed to the AI hardware through the NNRt backend during inference.

## Appendix

### Disabling the Fusion of Specified Operators

If you need to disable the fusion of specified operators, create a configuration file, for example, **converter.cfg**, and configure and file content as follows:

```ini
[registry]
# If **disable_fusion** is set to **off**, you can configure **fusion_blacklists** to disable the fusion of specified operators. If **disable_fusion** is set to **on**, the fusion of operators is disabled, and **fusion_blacklists** does not take effect. The default value of **disable_fusion** is **off**.
disable_fusion=off
# To disable the fusion of multiple operators, separate the operators with commas (,).
fusion_blacklists=ConvActivationFusion,MatMulActivationFusion,clip_convert_activation_pass
```

When running the converter, set **configFile** to **converter.cfg**.

The following lists the operators for which fusion can be disabled:

- AddConcatActivationFusion
- SqueezeFusion
- TransposeFusion
- ReshapeReshapeFusion 
- ConvBiasaddFusion 
- ConvBatchNormFusion 
- ConvScaleFusion 
- GroupNormFusion 
- TfNormFusion 
- OnnxLayerNormFusion 
- OnnxLayerNormFusion2 
- BatchMatMulFusion 
- BatchNormToScaleFusion 
- SigmoidMulFusion 
- ActivationFusion 
- ConvActivationFusion 
- ConvTupleGetItemFusion 
- ConvTupleActivationFusion  
- TfliteLstmCellFusion 
- TfLstmCellFusion 
- TfBidirectionGruFusion 
- TfGeLUFusion 
- OnnxGeLUFusion 
- TfliteRelPosMultiHeadAttentionFusion  
- GLUFusion 
- ConstFoldPass 
- AffineFusion 
- AffineActivationFusion 
- ConvConvFusion 
- ConvPadFusion 
- MatMulAddFusion 
- MatMulMulFusion 
- TransposeMatMulFusion 
- MulAddFusion 
- ScaleActivationFusion 
- ScaleScaleFusion 
- FullConnectedFusion 
- FullconnectedAddFusion 
- TensorDotFusion 
- MatMulActivationFusion 
- clip_convert_activation_pass  
