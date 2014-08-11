typedef int BOOL;
typedef void* fc2Context;
typedef void* fc2GuiContext;
typedef void* fc2ImageImpl;
typedef void* fc2AVIContext;
typedef void* fc2ImageStatisticsContext;
typedef long unsigned int size_t;
typedef struct _fc2PGRGuid
{
    unsigned int value[4];
} fc2PGRGuid;
typedef enum _fc2Error
{
    FC2_ERROR_UNDEFINED = -1,
    FC2_ERROR_OK,
    FC2_ERROR_FAILED,
    FC2_ERROR_NOT_IMPLEMENTED,
    FC2_ERROR_FAILED_BUS_MASTER_CONNECTION,
    FC2_ERROR_NOT_CONNECTED,
    FC2_ERROR_INIT_FAILED,
    FC2_ERROR_NOT_INTITIALIZED,
    FC2_ERROR_INVALID_PARAMETER,
    FC2_ERROR_INVALID_SETTINGS,
    FC2_ERROR_INVALID_BUS_MANAGER,
    FC2_ERROR_MEMORY_ALLOCATION_FAILED,
    FC2_ERROR_LOW_LEVEL_FAILURE,
    FC2_ERROR_NOT_FOUND,
    FC2_ERROR_FAILED_GUID,
    FC2_ERROR_INVALID_PACKET_SIZE,
    FC2_ERROR_INVALID_MODE,
    FC2_ERROR_NOT_IN_FORMAT7,
    FC2_ERROR_NOT_SUPPORTED,
    FC2_ERROR_TIMEOUT,
    FC2_ERROR_BUS_MASTER_FAILED,
    FC2_ERROR_INVALID_GENERATION,
    FC2_ERROR_LUT_FAILED,
    FC2_ERROR_IIDC_FAILED,
    FC2_ERROR_STROBE_FAILED,
    FC2_ERROR_TRIGGER_FAILED,
    FC2_ERROR_PROPERTY_FAILED,
    FC2_ERROR_PROPERTY_NOT_PRESENT,
    FC2_ERROR_REGISTER_FAILED,
    FC2_ERROR_READ_REGISTER_FAILED,
    FC2_ERROR_WRITE_REGISTER_FAILED,
    FC2_ERROR_ISOCH_FAILED,
    FC2_ERROR_ISOCH_ALREADY_STARTED,
    FC2_ERROR_ISOCH_NOT_STARTED,
    FC2_ERROR_ISOCH_START_FAILED,
    FC2_ERROR_ISOCH_RETRIEVE_BUFFER_FAILED,
    FC2_ERROR_ISOCH_STOP_FAILED,
    FC2_ERROR_ISOCH_SYNC_FAILED,
    FC2_ERROR_ISOCH_BANDWIDTH_EXCEEDED,
    FC2_ERROR_IMAGE_CONVERSION_FAILED,
    FC2_ERROR_IMAGE_LIBRARY_FAILURE,
    FC2_ERROR_BUFFER_TOO_SMALL,
    FC2_ERROR_IMAGE_CONSISTENCY_ERROR,
    FC2_ERROR_FORCE_32BITS = 0x7FFFFFFF
} fc2Error;
typedef enum _fc2BusCallbackType
{
    FC2_BUS_RESET,
    FC2_ARRIVAL,
    FC2_REMOVAL,
    FC2_CALLBACK_TYPE_FORCE_32BITS = 0x7FFFFFFF
} fc2BusCallbackType;
typedef enum _fc2GrabMode
{
    FC2_DROP_FRAMES,
    FC2_BUFFER_FRAMES,
    FC2_UNSPECIFIED_GRAB_MODE,
    FC2_GRAB_MODE_FORCE_32BITS = 0x7FFFFFFF
} fc2GrabMode;
typedef enum _fc2GrabTimeout
{
    FC2_TIMEOUT_NONE = 0,
    FC2_TIMEOUT_INFINITE = -1,
    FC2_TIMEOUT_UNSPECIFIED = -2,
    FC2_GRAB_TIMEOUT_FORCE_32BITS = 0x7FFFFFFF
} fc2GrabTimeout;
typedef enum _fc2BandwidthAllocation
{
    FC2_BANDWIDTH_ALLOCATION_OFF = 0,
    FC2_BANDWIDTH_ALLOCATION_ON = 1,
    FC2_BANDWIDTH_ALLOCATION_UNSUPPORTED = 2,
    FC2_BANDWIDTH_ALLOCATION_UNSPECIFIED = 3,
    FC2_BANDWIDTH_ALLOCATION_FORCE_32BITS = 0x7FFFFFFF
}fc2BandwidthAllocation;
typedef enum _fc2InterfaceType
{
    FC2_INTERFACE_IEEE1394,
    FC2_INTERFACE_USB_2,
    FC2_INTERFACE_USB_3,
 FC2_INTERFACE_GIGE,
    FC2_INTERFACE_UNKNOWN,
    FC2_INTERFACE_TYPE_FORCE_32BITS = 0x7FFFFFFF
} fc2InterfaceType;
typedef enum _fc2DriverType
{
    FC2_DRIVER_1394_CAM,
    FC2_DRIVER_1394_PRO,
    FC2_DRIVER_1394_JUJU,
    FC2_DRIVER_1394_VIDEO1394,
    FC2_DRIVER_1394_RAW1394,
    FC2_DRIVER_USB_NONE,
    FC2_DRIVER_USB_CAM,
    FC2_DRIVER_USB3_PRO,
    FC2_DRIVER_GIGE_NONE,
    FC2_DRIVER_GIGE_FILTER,
    FC2_DRIVER_GIGE_PRO,
    FC2_DRIVER_UNKNOWN = -1,
    FC2_DRIVER_FORCE_32BITS = 0x7FFFFFFF
}fc2DriverType;
typedef enum _fc2PropertyType
{
    FC2_BRIGHTNESS,
    FC2_AUTO_EXPOSURE,
    FC2_SHARPNESS,
    FC2_WHITE_BALANCE,
    FC2_HUE,
    FC2_SATURATION,
    FC2_GAMMA,
    FC2_IRIS,
    FC2_FOCUS,
    FC2_ZOOM,
    FC2_PAN,
    FC2_TILT,
    FC2_SHUTTER,
    FC2_GAIN,
    FC2_TRIGGER_MODE,
    FC2_TRIGGER_DELAY,
    FC2_FRAME_RATE,
    FC2_TEMPERATURE,
    FC2_UNSPECIFIED_PROPERTY_TYPE,
    FC2_PROPERTY_TYPE_FORCE_32BITS = 0x7FFFFFFF
} fc2PropertyType;
typedef enum _fc2FrameRate
{
    FC2_FRAMERATE_1_875,
    FC2_FRAMERATE_3_75,
    FC2_FRAMERATE_7_5,
    FC2_FRAMERATE_15,
    FC2_FRAMERATE_30,
    FC2_FRAMERATE_60,
    FC2_FRAMERATE_120,
    FC2_FRAMERATE_240,
    FC2_FRAMERATE_FORMAT7,
    FC2_NUM_FRAMERATES,
    FC2_FRAMERATE_FORCE_32BITS = 0x7FFFFFFF
} fc2FrameRate;
typedef enum _fc2VideoMode
{
    FC2_VIDEOMODE_160x120YUV444,
    FC2_VIDEOMODE_320x240YUV422,
    FC2_VIDEOMODE_640x480YUV411,
    FC2_VIDEOMODE_640x480YUV422,
    FC2_VIDEOMODE_640x480RGB,
    FC2_VIDEOMODE_640x480Y8,
    FC2_VIDEOMODE_640x480Y16,
    FC2_VIDEOMODE_800x600YUV422,
    FC2_VIDEOMODE_800x600RGB,
    FC2_VIDEOMODE_800x600Y8,
    FC2_VIDEOMODE_800x600Y16,
    FC2_VIDEOMODE_1024x768YUV422,
    FC2_VIDEOMODE_1024x768RGB,
    FC2_VIDEOMODE_1024x768Y8,
    FC2_VIDEOMODE_1024x768Y16,
    FC2_VIDEOMODE_1280x960YUV422,
    FC2_VIDEOMODE_1280x960RGB,
    FC2_VIDEOMODE_1280x960Y8,
    FC2_VIDEOMODE_1280x960Y16,
    FC2_VIDEOMODE_1600x1200YUV422,
    FC2_VIDEOMODE_1600x1200RGB,
    FC2_VIDEOMODE_1600x1200Y8,
    FC2_VIDEOMODE_1600x1200Y16,
    FC2_VIDEOMODE_FORMAT7,
    FC2_NUM_VIDEOMODES,
    FC2_VIDEOMODE_FORCE_32BITS = 0x7FFFFFFF
} fc2VideoMode;
typedef enum _fc2Mode
{
    FC2_MODE_0 = 0,
    FC2_MODE_1,
    FC2_MODE_2,
    FC2_MODE_3,
    FC2_MODE_4,
    FC2_MODE_5,
    FC2_MODE_6,
    FC2_MODE_7,
    FC2_MODE_8,
    FC2_MODE_9,
    FC2_MODE_10,
    FC2_MODE_11,
    FC2_MODE_12,
    FC2_MODE_13,
    FC2_MODE_14,
    FC2_MODE_15,
    FC2_MODE_16,
    FC2_MODE_17,
    FC2_MODE_18,
    FC2_MODE_19,
    FC2_MODE_20,
    FC2_MODE_21,
    FC2_MODE_22,
    FC2_MODE_23,
    FC2_MODE_24,
    FC2_MODE_25,
    FC2_MODE_26,
    FC2_MODE_27,
    FC2_MODE_28,
    FC2_MODE_29,
    FC2_MODE_30,
    FC2_MODE_31,
    FC2_NUM_MODES,
    FC2_MODE_FORCE_32BITS = 0x7FFFFFFF
} fc2Mode;
typedef enum _fc2PixelFormat
{
    FC2_PIXEL_FORMAT_MONO8 = 0x80000000,
    FC2_PIXEL_FORMAT_411YUV8 = 0x40000000,
    FC2_PIXEL_FORMAT_422YUV8 = 0x20000000,
    FC2_PIXEL_FORMAT_444YUV8 = 0x10000000,
    FC2_PIXEL_FORMAT_RGB8 = 0x08000000,
    FC2_PIXEL_FORMAT_MONO16 = 0x04000000,
    FC2_PIXEL_FORMAT_RGB16 = 0x02000000,
    FC2_PIXEL_FORMAT_S_MONO16 = 0x01000000,
    FC2_PIXEL_FORMAT_S_RGB16 = 0x00800000,
    FC2_PIXEL_FORMAT_RAW8 = 0x00400000,
    FC2_PIXEL_FORMAT_RAW16 = 0x00200000,
    FC2_PIXEL_FORMAT_MONO12 = 0x00100000,
    FC2_PIXEL_FORMAT_RAW12 = 0x00080000,
    FC2_PIXEL_FORMAT_BGR = 0x80000008,
    FC2_PIXEL_FORMAT_BGRU = 0x40000008,
    FC2_PIXEL_FORMAT_RGB = FC2_PIXEL_FORMAT_RGB8,
    FC2_PIXEL_FORMAT_RGBU = 0x40000002,
    FC2_PIXEL_FORMAT_BGR16 = 0x02000001,
 FC2_PIXEL_FORMAT_BGRU16 = 0x02000002,
    FC2_PIXEL_FORMAT_422YUV8_JPEG = 0x40000001,
    FC2_NUM_PIXEL_FORMATS = 20,
    FC2_UNSPECIFIED_PIXEL_FORMAT = 0
} fc2PixelFormat;
typedef enum _fc2BusSpeed
{
    FC2_BUSSPEED_S100,
    FC2_BUSSPEED_S200,
    FC2_BUSSPEED_S400,
    FC2_BUSSPEED_S480,
    FC2_BUSSPEED_S800,
    FC2_BUSSPEED_S1600,
    FC2_BUSSPEED_S3200,
    FC2_BUSSPEED_S5000,
    FC2_BUSSPEED_10BASE_T,
    FC2_BUSSPEED_100BASE_T,
    FC2_BUSSPEED_1000BASE_T,
    FC2_BUSSPEED_10000BASE_T,
    FC2_BUSSPEED_S_FASTEST,
    FC2_BUSSPEED_ANY,
    FC2_BUSSPEED_SPEED_UNKNOWN = -1,
    FC2_BUSSPEED_FORCE_32BITS = 0x7FFFFFFF
} fc2BusSpeed;
typedef enum _fc2PCIeBusSpeed
{
 FC2_PCIE_BUSSPEED_2_5,
 FC2_PCIE_BUSSPEED_5_0,
 FC2_PCIE_BUSSPEED_UNKNOWN = -1,
 FC2_PCIE_BUSSPEED_FORCE_32BITS = 0x7FFFFFFF
}fc2PCIeBusSpeed;
typedef enum _fc2ColorProcessingAlgorithm
{
    FC2_DEFAULT,
    FC2_NO_COLOR_PROCESSING,
    FC2_NEAREST_NEIGHBOR_FAST,
    FC2_EDGE_SENSING,
    FC2_HQ_LINEAR,
    FC2_RIGOROUS,
    FC2_IPP,
    FC2_DIRECTIONAL,
    FC2_COLOR_PROCESSING_ALGORITHM_FORCE_32BITS = 0x7FFFFFFF
} fc2ColorProcessingAlgorithm;
typedef enum _fc2BayerTileFormat
{
    FC2_BT_NONE,
    FC2_BT_RGGB,
    FC2_BT_GRBG,
    FC2_BT_GBRG,
    FC2_BT_BGGR,
    FC2_BT_FORCE_32BITS = 0x7FFFFFFF
} fc2BayerTileFormat;
typedef enum _fc2ImageFileFormat
{
    FC2_FROM_FILE_EXT = -1,
    FC2_PGM,
    FC2_PPM,
    FC2_BMP,
    FC2_JPEG,
    FC2_JPEG2000,
    FC2_TIFF,
    FC2_PNG,
    FC2_RAW,
    FC2_IMAGE_FILE_FORMAT_FORCE_32BITS = 0x7FFFFFFF
} fc2ImageFileFormat;
typedef enum _fc2GigEPropertyType
{
    FC2_HEARTBEAT,
    FC2_HEARTBEAT_TIMEOUT
} fc2GigEPropertyType;
typedef enum _fc2StatisticsChannel
{
    FC2_STATISTICS_GREY,
    FC2_STATISTICS_RED,
    FC2_STATISTICS_GREEN,
    FC2_STATISTICS_BLUE,
    FC2_STATISTICS_HUE,
    FC2_STATISTICS_SATURATION,
    FC2_STATISTICS_LIGHTNESS,
    FC2_STATISTICS_FORCE_32BITS = 0x7FFFFFFF
} fc2StatisticsChannel;
typedef enum _fc2OSType
{
 FC2_WINDOWS_X86,
 FC2_WINDOWS_X64,
 FC2_LINUX_X86,
 FC2_LINUX_X64,
 FC2_MAC,
 FC2_UNKNOWN_OS,
    FC2_OSTYPE_FORCE_32BITS = 0x7FFFFFFF
} fc2OSType;
typedef enum _fc2ByteOrder
{
 FC2_BYTE_ORDER_LITTLE_ENDIAN,
 FC2_BYTE_ORDER_BIG_ENDIAN,
    FC2_BYTE_ORDER_FORCE_32BITS = 0x7FFFFFFF
} fc2ByteOrder;
typedef struct _fc2Image
{
    unsigned int rows;
    unsigned int cols;
    unsigned int stride;
    unsigned char* pData;
    unsigned int dataSize;
    unsigned int receivedDataSize;
    fc2PixelFormat format;
    fc2BayerTileFormat bayerFormat;
    fc2ImageImpl imageImpl;
} fc2Image;
typedef struct _fc2SystemInfo
{
 fc2OSType osType;
 char osDescription[ 512];
 fc2ByteOrder byteOrder;
 size_t sysMemSize;
 char cpuDescription[ 512];
 size_t numCpuCores;
 char driverList[ 512];
 char libraryList[ 512];
 char gpuDescription[ 512];
 size_t screenWidth;
 size_t screenHeight;
    unsigned int reserved[16];
} fc2SystemInfo;
typedef struct _fc2Version
{
    unsigned int major;
    unsigned int minor;
    unsigned int type;
    unsigned int build;
} fc2Version;
typedef struct _fc2Config
{
    unsigned int numBuffers;
    unsigned int numImageNotifications;
    unsigned int minNumImageNotifications;
    int grabTimeout;
    fc2GrabMode grabMode;
    fc2BusSpeed isochBusSpeed;
    fc2BusSpeed asyncBusSpeed;
    fc2BandwidthAllocation bandwidthAllocation;
 unsigned int registerTimeoutRetries;
 unsigned int registerTimeout;
    unsigned int reserved[16];
} fc2Config;
typedef struct _fc2PropertyInfo
{
    fc2PropertyType type;
    BOOL present;
    BOOL autoSupported;
    BOOL manualSupported;
    BOOL onOffSupported;
    BOOL onePushSupported;
    BOOL absValSupported;
    BOOL readOutSupported;
    unsigned int min;
    unsigned int max;
    float absMin;
    float absMax;
    char pUnits[512];
    char pUnitAbbr[512];
    unsigned int reserved[8];
} fc2PropertyInfo, fc2TriggerDelayInfo;
typedef struct _Property
{
    fc2PropertyType type;
    BOOL present;
    BOOL absControl;
    BOOL onePush;
    BOOL onOff;
    BOOL autoManualMode;
    unsigned int valueA;
    unsigned int valueB;
    float absValue;
    unsigned int reserved[8];
} fc2Property, fc2TriggerDelay;
typedef struct _fc2TriggerModeInfo
{
    BOOL present;
    BOOL readOutSupported;
    BOOL onOffSupported;
    BOOL polaritySupported;
    BOOL valueReadable;
    unsigned int sourceMask;
    BOOL softwareTriggerSupported;
    unsigned int modeMask;
    unsigned int reserved[8];
} fc2TriggerModeInfo;
typedef struct _fc2TriggerMode
{
    BOOL onOff;
    unsigned int polarity;
    unsigned int source;
    unsigned int mode;
    unsigned int parameter;
    unsigned int reserved[8];
} fc2TriggerMode;
typedef struct _fc2StrobeInfo
{
    unsigned int source;
    BOOL present;
    BOOL readOutSupported;
    BOOL onOffSupported;
    BOOL polaritySupported;
    float minValue;
    float maxValue;
    unsigned int reserved[8];
} fc2StrobeInfo;
typedef struct _fc2StrobeControl
{
    unsigned int source;
    BOOL onOff;
    unsigned int polarity;
    float delay;
    float duration;
    unsigned int reserved[8];
} fc2StrobeControl;
typedef struct _fc2Format7ImageSettings
{
    fc2Mode mode;
    unsigned int offsetX;
    unsigned int offsetY;
    unsigned int width;
    unsigned int height;
    fc2PixelFormat pixelFormat;
    unsigned int reserved[8];
} fc2Format7ImageSettings;
typedef struct _fc2Format7Info
{
    fc2Mode mode;
    unsigned int maxWidth;
    unsigned int maxHeight;
    unsigned int offsetHStepSize;
    unsigned int offsetVStepSize;
    unsigned int imageHStepSize;
    unsigned int imageVStepSize;
    unsigned int pixelFormatBitField;
    unsigned int vendorPixelFormatBitField;
    unsigned int packetSize;
    unsigned int minPacketSize;
    unsigned int maxPacketSize;
    float percentage;
    unsigned int reserved[16];
} fc2Format7Info;
typedef struct _fc2Format7PacketInfo
{
    unsigned int recommendedBytesPerPacket;
    unsigned int maxBytesPerPacket;
    unsigned int unitBytesPerPacket;
    unsigned int reserved[8];
} fc2Format7PacketInfo;
typedef struct _fc2IPAddress
{
    unsigned char octets[4];
} fc2IPAddress;
typedef struct _fc2MACAddress
{
    unsigned char octets[6];
} fc2MACAddress;
typedef struct _fc2GigEProperty
{
    fc2GigEPropertyType propType;
    BOOL isReadable;
    BOOL isWritable;
    unsigned int min;
    unsigned int max;
    unsigned int value;
    unsigned int reserved[8];
} fc2GigEProperty;
typedef struct _fc2GigEStreamChannel
{
    unsigned int networkInterfaceIndex;
    unsigned int hostPost;
    BOOL doNotFragment;
    unsigned int packetSize;
    unsigned int interPacketDelay;
    fc2IPAddress destinationIpAddress;
    unsigned int sourcePort;
    unsigned int reserved[8];
} fc2GigEStreamChannel;
typedef struct _fc2GigEConfig
{
 BOOL enablePacketResend;
 unsigned int timeoutForPacketResend;
 unsigned int maxPacketsToResend;
    unsigned int reserved[8];
} fc2GigEConfig;
typedef struct _fc2GigEImageSettingsInfo
{
    unsigned int maxWidth;
    unsigned int maxHeight;
    unsigned int offsetHStepSize;
    unsigned int offsetVStepSize;
    unsigned int imageHStepSize;
    unsigned int imageVStepSize;
    unsigned int pixelFormatBitField;
    unsigned int vendorPixelFormatBitField;
    unsigned int reserved[16];
} fc2GigEImageSettingsInfo;
typedef struct _fc2GigEImageSettings
{
    unsigned int offsetX;
    unsigned int offsetY;
    unsigned int width;
    unsigned int height;
    fc2PixelFormat pixelFormat;
    unsigned int reserved[8];
} fc2GigEImageSettings;
typedef struct _fc2TimeStamp
{
    long long seconds;
    unsigned int microSeconds;
    unsigned int cycleSeconds;
    unsigned int cycleCount;
    unsigned int cycleOffset;
    unsigned int reserved[8];
} fc2TimeStamp;
typedef struct _fc2ConfigROM
{
    unsigned int nodeVendorId;
    unsigned int chipIdHi;
    unsigned int chipIdLo;
    unsigned int unitSpecId;
    unsigned int unitSWVer;
    unsigned int unitSubSWVer;
    unsigned int vendorUniqueInfo_0;
    unsigned int vendorUniqueInfo_1;
    unsigned int vendorUniqueInfo_2;
    unsigned int vendorUniqueInfo_3;
    char pszKeyword[ 512 ];
    unsigned int reserved[16];
} fc2ConfigROM;
typedef struct _fc2CameraInfo
{
    unsigned int serialNumber;
    fc2InterfaceType interfaceType;
    fc2DriverType driverType;
    BOOL isColorCamera;
    char modelName[ 512];
    char vendorName[ 512];
    char sensorInfo[ 512];
    char sensorResolution[ 512];
    char driverName[ 512];
    char firmwareVersion[ 512];
    char firmwareBuildTime[ 512];
    fc2BusSpeed maximumBusSpeed;
 fc2PCIeBusSpeed pcieBusSpeed;
    fc2BayerTileFormat bayerTileFormat;
    unsigned short busNumber;
    unsigned short nodeNumber;
    unsigned int iidcVer;
    fc2ConfigROM configROM;
    unsigned int gigEMajorVersion;
    unsigned int gigEMinorVersion;
    char userDefinedName[ 512];
    char xmlURL1[ 512];
    char xmlURL2[ 512];
    fc2MACAddress macAddress;
    fc2IPAddress ipAddress;
    fc2IPAddress subnetMask;
    fc2IPAddress defaultGateway;
 unsigned int ccpStatus;
    unsigned int applicationIPAddress;
    unsigned int applicationPort;
    unsigned int reserved[16];
} fc2CameraInfo;
typedef struct _fc2EmbeddedImageInfoProperty
{
    BOOL available;
    BOOL onOff;
} fc2EmbeddedImageInfoProperty;
typedef struct _fc2EmbeddedImageInfo
{
    fc2EmbeddedImageInfoProperty timestamp;
    fc2EmbeddedImageInfoProperty gain;
    fc2EmbeddedImageInfoProperty shutter;
    fc2EmbeddedImageInfoProperty brightness;
    fc2EmbeddedImageInfoProperty exposure;
    fc2EmbeddedImageInfoProperty whiteBalance;
    fc2EmbeddedImageInfoProperty frameCounter;
    fc2EmbeddedImageInfoProperty strobePattern;
    fc2EmbeddedImageInfoProperty GPIOPinState;
    fc2EmbeddedImageInfoProperty ROIPosition;
} fc2EmbeddedImageInfo;
typedef struct _fc2ImageMetadata
{
    unsigned int embeddedTimeStamp;
    unsigned int embeddedGain;
    unsigned int embeddedShutter;
    unsigned int embeddedBrightness;
    unsigned int embeddedExposure;
    unsigned int embeddedWhiteBalance;
    unsigned int embeddedFrameCounter;
    unsigned int embeddedStrobePattern;
    unsigned int embeddedGPIOPinState;
    unsigned int embeddedROIPosition;
    unsigned int reserved[31];
} fc2ImageMetadata;
typedef struct _fc2LUTData
{
    BOOL supported;
    BOOL enabled;
    unsigned int numBanks;
    unsigned int numChannels;
    unsigned int inputBitDepth;
    unsigned int outputBitDepth;
    unsigned int numEntries;
    unsigned int reserved[8];
} fc2LUTData;
typedef struct _fc2PNGOption
{
    BOOL interlaced;
    unsigned int compressionLevel;
    unsigned int reserved[16];
} fc2PNGOption;
typedef struct _fc2PPMOption
{
    BOOL binaryFile;
    unsigned int reserved[16];
} fc2PPMOption ;
typedef struct _fc2PGMOption
{
    BOOL binaryFile;
    unsigned int reserved[16];
} fc2PGMOption;
typedef enum _fc2TIFFCompressionMethod
{
    FC2_TIFF_NONE = 1,
    FC2_TIFF_PACKBITS,
    FC2_TIFF_DEFLATE,
    FC2_TIFF_ADOBE_DEFLATE,
    FC2_TIFF_CCITTFAX3,
    FC2_TIFF_CCITTFAX4,
    FC2_TIFF_LZW,
    FC2_TIFF_JPEG,
} fc2TIFFCompressionMethod;
typedef struct _fc2TIFFOption
{
    fc2TIFFCompressionMethod compression;
    unsigned int reserved[16];
} fc2TIFFOption;
typedef struct _fc2JPEGOption
{
    BOOL progressive;
    unsigned int quality;
    unsigned int reserved[16];
} fc2JPEGOption;
typedef struct _fc2JPG2Option
{
    unsigned int quality;
    unsigned int reserved[16];
} fc2JPG2Option;
typedef struct _fc2AVIOption
{
   float frameRate;
   unsigned int reserved[256];
} fc2AVIOption;
typedef struct _fc2MJPGOption
{
 float frameRate;
 unsigned int quality;
 unsigned int reserved[256];
} fc2MJPGOption;
typedef struct _fc2H264Option
{
 float frameRate;
 unsigned int width;
 unsigned int height;
 unsigned int bitrate;
 unsigned int reserved[256];
} fc2H264Option;
typedef void* fc2CallbackHandle;
typedef void (*fc2BusEventCallback)( void* pParameter, unsigned int serialNumber );
typedef void (*fc2ImageEventCallback)( fc2Image* image, void* pCallbackData );
typedef void (*fc2AsyncCommandCallback)( fc2Error retError, void* pUserData );
 fc2Error
fc2CreateContext(
    fc2Context* pContext );
 fc2Error
fc2CreateGigEContext(
    fc2Context* pContext );
 fc2Error
fc2DestroyContext(
    fc2Context context );
 fc2Error
fc2FireBusReset(
    fc2Context context,
    fc2PGRGuid* pGuid);
 fc2Error
fc2GetNumOfCameras(
    fc2Context context,
    unsigned int* pNumCameras );
 fc2Error
fc2IsCameraControlable(
    fc2Context context,
 fc2PGRGuid* pGuid,
    BOOL* pControlable );
 fc2Error
fc2GetCameraFromIndex(
    fc2Context context,
    unsigned int index,
    fc2PGRGuid* pGuid );
 fc2Error
fc2GetCameraFromSerialNumber(
    fc2Context context,
    unsigned int serialNumber,
    fc2PGRGuid* pGuid );
 fc2Error
fc2GetCameraSerialNumberFromIndex(
    fc2Context context,
    unsigned int index,
    unsigned int* pSerialNumber );
 fc2Error
fc2GetInterfaceTypeFromGuid(
    fc2Context context,
    fc2PGRGuid *pGuid,
    fc2InterfaceType* pInterfaceType );
 fc2Error
fc2GetNumOfDevices(
    fc2Context context,
    unsigned int* pNumDevices );
 fc2Error
fc2GetDeviceFromIndex(
    fc2Context context,
    unsigned int index,
    fc2PGRGuid* pGuid );
 fc2Error
fc2RegisterCallback(
    fc2Context context,
    fc2BusEventCallback enumCallback,
    fc2BusCallbackType callbackType,
    void* pParameter,
    fc2CallbackHandle* pCallbackHandle );
 fc2Error
fc2UnregisterCallback(
    fc2Context context,
    fc2CallbackHandle callbackHandle );
 fc2Error
fc2RescanBus( fc2Context context);
 fc2Error
fc2ForceIPAddressToCamera(
    fc2Context context,
    fc2MACAddress macAddress,
    fc2IPAddress ipAddress,
    fc2IPAddress subnetMask,
    fc2IPAddress defaultGateway );
 fc2Error
fc2ForceAllIPAddressesAutomatically();
 fc2Error
fc2ForceIPAddressAutomatically(unsigned int serialNumber);
 fc2Error
fc2DiscoverGigECameras(
    fc2Context context,
    fc2CameraInfo* gigECameras,
    unsigned int* arraySize );
 fc2Error
fc2WriteRegister(
    fc2Context context,
    unsigned int address,
    unsigned int value);
 fc2Error
fc2WriteRegisterBroadcast(
    fc2Context context,
    unsigned int address,
    unsigned int value);
 fc2Error
fc2ReadRegister(
    fc2Context context,
    unsigned int address,
    unsigned int* pValue );
 fc2Error
fc2WriteRegisterBlock(
    fc2Context context,
    unsigned short addressHigh,
    unsigned int addressLow,
    const unsigned int* pBuffer,
    unsigned int length );
 fc2Error
fc2ReadRegisterBlock(
    fc2Context context,
    unsigned short addressHigh,
    unsigned int addressLow,
    unsigned int* pBuffer,
    unsigned int length );
 fc2Error
fc2Connect(
    fc2Context context,
    fc2PGRGuid* guid );
 fc2Error
fc2Disconnect(
    fc2Context context );
 fc2Error
fc2SetCallback(
    fc2Context context,
    fc2ImageEventCallback pCallbackFn,
    void* pCallbackData);
 fc2Error
fc2StartCapture(
    fc2Context context );
 fc2Error
fc2StartCaptureCallback(
    fc2Context context,
    fc2ImageEventCallback pCallbackFn,
    void* pCallbackData);
 fc2Error
fc2StartSyncCapture(
    unsigned int numCameras,
    fc2Context *pContexts );
 fc2Error
fc2StartSyncCaptureCallback(
    unsigned int numCameras,
    fc2Context *pContexts,
    fc2ImageEventCallback* pCallbackFns,
    void** pCallbackDataArray);
 fc2Error
fc2RetrieveBuffer(
    fc2Context context,
    fc2Image* pImage );
 fc2Error
fc2StopCapture(
    fc2Context context );
 fc2Error
fc2SetUserBuffers(
    fc2Context context,
    unsigned char* const ppMemBuffers,
    int size,
    int nNumBuffers );
 fc2Error
fc2GetConfiguration(
    fc2Context context,
    fc2Config* config );
 fc2Error
fc2SetConfiguration(
    fc2Context context,
    fc2Config* config );
 fc2Error
fc2GetCameraInfo(
    fc2Context context,
    fc2CameraInfo* pCameraInfo );
 fc2Error
fc2GetPropertyInfo(
    fc2Context context,
    fc2PropertyInfo* propInfo );
 fc2Error
fc2GetProperty(
    fc2Context context,
    fc2Property* prop );
 fc2Error
fc2SetProperty(
    fc2Context context,
    fc2Property* prop );
 fc2Error
fc2SetPropertyBroadcast(
    fc2Context context,
    fc2Property* prop );
 fc2Error
fc2GetGPIOPinDirection(
    fc2Context context,
    unsigned int pin,
    unsigned int* pDirection );
 fc2Error
fc2SetGPIOPinDirection(
    fc2Context context,
    unsigned int pin,
    unsigned int direction);
 fc2Error
fc2SetGPIOPinDirectionBroadcast(
    fc2Context context,
    unsigned int pin,
    unsigned int direction);
 fc2Error
fc2GetTriggerModeInfo(
    fc2Context context,
    fc2TriggerModeInfo* triggerModeInfo );
 fc2Error
fc2GetTriggerMode(
    fc2Context context,
    fc2TriggerMode* triggerMode );
 fc2Error
fc2SetTriggerMode(
    fc2Context context,
    fc2TriggerMode* triggerMode );
 fc2Error
fc2SetTriggerModeBroadcast(
    fc2Context context,
    fc2TriggerMode* triggerMode );
 fc2Error
fc2FireSoftwareTrigger(
    fc2Context context );
 fc2Error
fc2FireSoftwareTriggerBroadcast(
    fc2Context context );
 fc2Error
fc2GetTriggerDelayInfo(
    fc2Context context,
    fc2TriggerDelayInfo* triggerDelayInfo );
 fc2Error
fc2GetTriggerDelay(
    fc2Context context,
    fc2TriggerDelay* triggerDelay );
 fc2Error
fc2SetTriggerDelay(
    fc2Context context,
    fc2TriggerDelay* triggerDelay );
 fc2Error
fc2SetTriggerDelayBroadcast(
    fc2Context context,
    fc2TriggerDelay* triggerDelay );
 fc2Error
fc2GetStrobeInfo(
    fc2Context context,
    fc2StrobeInfo* strobeInfo );
 fc2Error
fc2GetStrobe(
    fc2Context context,
    fc2StrobeControl* strobeControl );
 fc2Error
fc2SetStrobe(
    fc2Context context,
    fc2StrobeControl* strobeControl );
 fc2Error
fc2SetStrobeBroadcast(
    fc2Context context,
    fc2StrobeControl* strobeControl );
 fc2Error
fc2GetVideoModeAndFrameRateInfo(
    fc2Context context,
    fc2VideoMode videoMode,
    fc2FrameRate frameRate,
    BOOL* pSupported);
 fc2Error
fc2GetVideoModeAndFrameRate(
    fc2Context context,
    fc2VideoMode* videoMode,
    fc2FrameRate* frameRate );
 fc2Error
fc2SetVideoModeAndFrameRate(
    fc2Context context,
    fc2VideoMode videoMode,
    fc2FrameRate frameRate );
 fc2Error
fc2GetFormat7Info(
    fc2Context context,
    fc2Format7Info* info,
    BOOL* pSupported );
 fc2Error
fc2ValidateFormat7Settings(
    fc2Context context,
    fc2Format7ImageSettings* imageSettings,
    BOOL* settingsAreValid,
    fc2Format7PacketInfo* packetInfo );
 fc2Error
fc2GetFormat7Configuration(
    fc2Context context,
    fc2Format7ImageSettings* imageSettings,
    unsigned int* packetSize,
    float* percentage );
 fc2Error
fc2SetFormat7ConfigurationPacket(
    fc2Context context,
    fc2Format7ImageSettings* imageSettings,
    unsigned int packetSize );
 fc2Error
fc2SetFormat7Configuration(
    fc2Context context,
    fc2Format7ImageSettings* imageSettings,
    float percentSpeed );
 fc2Error
fc2WriteGVCPRegister(
    fc2Context context,
    unsigned int address,
    unsigned int value);
 fc2Error
fc2WriteGVCPRegisterBroadcast(
    fc2Context context,
    unsigned int address,
    unsigned int value);
 fc2Error
fc2ReadGVCPRegister(
    fc2Context context,
    unsigned int address,
    unsigned int* pValue );
 fc2Error
fc2WriteGVCPRegisterBlock(
    fc2Context context,
    unsigned int address,
    const unsigned int* pBuffer,
    unsigned int length );
 fc2Error
fc2ReadGVCPRegisterBlock(
    fc2Context context,
    unsigned int address,
    unsigned int* pBuffer,
    unsigned int length );
 fc2Error
fc2WriteGVCPMemory(
    fc2Context context,
    unsigned int address,
    const unsigned char* pBuffer,
    unsigned int length );
 fc2Error
fc2ReadGVCPMemory(
    fc2Context context,
    unsigned int address,
    unsigned char* pBuffer,
    unsigned int length );
 fc2Error
fc2GetGigEProperty(
        fc2Context context,
        fc2GigEProperty* pGigEProp );
 fc2Error
fc2SetGigEProperty(
    fc2Context context,
    const fc2GigEProperty* pGigEProp );
 fc2Error
fc2QueryGigEImagingMode(
    fc2Context context,
    fc2Mode mode,
    BOOL* isSupported );
 fc2Error
fc2GetGigEImagingMode(
    fc2Context context,
    fc2Mode* mode );
 fc2Error
fc2SetGigEImagingMode(
    fc2Context context,
    fc2Mode mode );
 fc2Error
fc2GetGigEImageSettingsInfo(
    fc2Context context,
    fc2GigEImageSettingsInfo* pInfo );
 fc2Error
fc2GetGigEImageSettings(
    fc2Context context,
    fc2GigEImageSettings* pImageSettings );
 fc2Error
fc2SetGigEImageSettings(
    fc2Context context,
    const fc2GigEImageSettings* pImageSettings );
 fc2Error
fc2GetGigEConfig(
    fc2Context context,
    fc2GigEConfig* pConfig );
 fc2Error
fc2SetGigEConfig(
    fc2Context context,
    const fc2GigEConfig* pConfig );
 fc2Error
fc2GetGigEImageBinningSettings(
    fc2Context context,
    unsigned int* horzBinnningValue,
    unsigned int* vertBinnningValue );
 fc2Error
fc2SetGigEImageBinningSettings(
    fc2Context context,
    unsigned int horzBinnningValue,
    unsigned int vertBinnningValue );
 fc2Error
fc2GetNumStreamChannels(
    fc2Context context,
    unsigned int* numChannels );
 fc2Error
fc2GetGigEStreamChannelInfo(
    fc2Context context,
    unsigned int channel,
    fc2GigEStreamChannel* pChannel );
 fc2Error
fc2SetGigEStreamChannelInfo(
    fc2Context context,
    unsigned int channel,
    fc2GigEStreamChannel* pChannel );
 fc2Error
fc2GetLUTInfo(
    fc2Context context,
    fc2LUTData* pData );
 fc2Error
fc2GetLUTBankInfo(
    fc2Context context,
    unsigned int bank,
    BOOL* pReadSupported,
    BOOL* pWriteSupported );
 fc2Error
fc2GetActiveLUTBank(
    fc2Context context,
    unsigned int* pActiveBank );
 fc2Error
fc2SetActiveLUTBank(
    fc2Context context,
    unsigned int activeBank );
 fc2Error
fc2EnableLUT(
    fc2Context context,
    BOOL on );
 fc2Error
fc2GetLUTChannel(
    fc2Context context,
    unsigned int bank,
    unsigned int channel,
    unsigned int sizeEntries,
    unsigned int* pEntries );
 fc2Error
fc2SetLUTChannel(
    fc2Context context,
    unsigned int bank,
    unsigned int channel,
    unsigned int sizeEntries,
    unsigned int* pEntries );
 fc2Error
fc2GetMemoryChannel(
    fc2Context context,
    unsigned int* pCurrentChannel );
 fc2Error
fc2SaveToMemoryChannel(
    fc2Context context,
    unsigned int channel );
 fc2Error
fc2RestoreFromMemoryChannel(
    fc2Context context,
    unsigned int channel );
 fc2Error
fc2GetMemoryChannelInfo(
    fc2Context context,
    unsigned int* pNumChannels );
 fc2Error
fc2GetEmbeddedImageInfo(
    fc2Context context,
    fc2EmbeddedImageInfo* pInfo );
 fc2Error
fc2SetEmbeddedImageInfo(
    fc2Context context,
    fc2EmbeddedImageInfo* pInfo );
 const char*
fc2GetRegisterString(
    unsigned int registerVal);
 fc2Error
fc2CreateImage(
    fc2Image* pImage );
 fc2Error
fc2DestroyImage(
    fc2Image* image );
 fc2Error
fc2SetDefaultColorProcessing(
    fc2ColorProcessingAlgorithm defaultMethod );
 fc2Error
fc2GetDefaultColorProcessing(
    fc2ColorProcessingAlgorithm* pDefaultMethod );
 fc2Error
fc2SetDefaultOutputFormat(
    fc2PixelFormat format );
 fc2Error
fc2GetDefaultOutputFormat(
    fc2PixelFormat* pFormat );
 fc2Error
fc2DetermineBitsPerPixel(
    fc2PixelFormat format,
    unsigned int* pBitsPerPixel );
 fc2Error
fc2SaveImage(
    fc2Image* pImage,
    const char* pFilename,
    fc2ImageFileFormat format );
 fc2Error
fc2SaveImageWithOption(
    fc2Image* pImage,
    const char* pFilename,
    fc2ImageFileFormat format,
    void* pOption );
 fc2Error
fc2ConvertImage(
    fc2Image* pImageIn,
    fc2Image* pImageOut );
 fc2Error
fc2ConvertImageTo(
    fc2PixelFormat format,
    fc2Image* pImageIn,
    fc2Image* pImageOut );
 fc2Error
fc2GetImageData(
    fc2Image* pImage,
    unsigned char** ppData);
 fc2Error
fc2SetImageData(
    fc2Image* pImage,
    const unsigned char* pData,
    unsigned int dataSize);
 fc2Error
fc2SetImageDimensions(
    fc2Image* pImage,
    unsigned int rows,
    unsigned int cols,
    unsigned int stride,
    fc2PixelFormat pixelFormat,
    fc2BayerTileFormat bayerFormat);
 fc2TimeStamp
fc2GetImageTimeStamp(
    fc2Image* pImage);
 fc2Error
fc2CalculateImageStatistics(
    fc2Image* pImage,
    fc2ImageStatisticsContext* pImageStatisticsContext );
 fc2Error
fc2CreateImageStatistics(
    fc2ImageStatisticsContext* pImageStatisticsContext );
 fc2Error
fc2DestroyImageStatistics(
    fc2ImageStatisticsContext imageStatisticsContext );
 const fc2Error
fc2GetChannelStatus(
 fc2ImageStatisticsContext imageStatisticsContext,
 fc2StatisticsChannel channel,
 BOOL* pEnabled );
 fc2Error
fc2SetChannelStatus(
 fc2ImageStatisticsContext imageStatisticsContext,
 fc2StatisticsChannel channel,
 BOOL enabled );
 fc2Error
fc2GetImageStatistics(
    fc2ImageStatisticsContext imageStatisticsContext,
    fc2StatisticsChannel channel,
    unsigned int* pRangeMin,
    unsigned int* pRangeMax,
    unsigned int* pPixelValueMin,
    unsigned int* pPixelValueMax,
    unsigned int* pNumPixelValues,
    float* pPixelValueMean,
    int** ppHistogram );
 fc2Error
fc2CreateAVI(
    fc2AVIContext* pAVIContext );
 fc2Error
fc2AVIOpen(
    fc2AVIContext AVIContext,
    const char* pFileName,
    fc2AVIOption* pOption );
 fc2Error
fc2MJPGOpen(
    fc2AVIContext AVIContext,
    const char* pFileName,
    fc2MJPGOption* pOption );
 fc2Error
fc2H264Open(
    fc2AVIContext AVIContext,
    const char* pFileName,
    fc2H264Option* pOption );
 fc2Error
fc2AVIAppend(
    fc2AVIContext AVIContext,
    fc2Image* pImage );
 fc2Error
fc2AVIClose(
    fc2AVIContext AVIContext );
 fc2Error
fc2DestroyAVI(
    fc2AVIContext AVIContext );
 fc2Error
fc2GetSystemInfo( fc2SystemInfo* pSystemInfo);
 fc2Error
fc2GetLibraryVersion( fc2Version* pVersion);
 fc2Error
fc2LaunchBrowser( const char* pAddress);
 fc2Error
fc2LaunchHelp( const char* pFileName);
 fc2Error
fc2LaunchCommand( const char* pCommand);
 fc2Error
fc2LaunchCommandAsync(
    const char* pCommand,
    fc2AsyncCommandCallback pCallback,
    void* pUserData );
 const char*
fc2ErrorToDescription(
    fc2Error error);
 fc2Error
fc2GetCycleTime( fc2Context context, fc2TimeStamp* pTimeStamp );
