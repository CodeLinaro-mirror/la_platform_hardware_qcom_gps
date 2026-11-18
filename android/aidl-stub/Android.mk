
LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := android.hardware.gnss-aidl-impl-qti-stub

LOCAL_VENDOR_MODULE := true
LOCAL_MODULE_RELATIVE_PATH := hw

LOCAL_SRC_FILES := \
    Gnss.cpp \
    GnssConfiguration.cpp \
    GnssPowerIndication.cpp \
    GnssMeasurementInterface.cpp \
    GnssBatching.cpp \
    GnssGeofence.cpp \
    AGnss.cpp \
    AGnssRil.cpp \
    GnssDebug.cpp \
    GnssAntennaInfo.cpp \
    MeasurementCorrectionsInterface.cpp \
    GnssVisibilityControl.cpp

LOCAL_SHARED_LIBRARIES := \
    libbase \
    libbinder_ndk \
    android.hardware.gnss-V4-ndk \
    liblog \
    libcutils \
    libutils

LOCAL_CFLAGS += $(GNSS_CFLAGS)

include $(BUILD_SHARED_LIBRARY)

include $(CLEAR_VARS)
LOCAL_MODULE := android.hardware.gnss-aidl-service-qti-stub
LOCAL_VENDOR_MODULE := true
LOCAL_MODULE_RELATIVE_PATH := hw
LOCAL_SRC_FILES := \
    service.cpp

LOCAL_SHARED_LIBRARIES := \
    liblog \
    libcutils \
    libbase \
    libutils \
    libbinder_ndk

LOCAL_SHARED_LIBRARIES += \
    android.hardware.gnss-V4-ndk \
    android.hardware.gnss-aidl-impl-qti-stub

LOCAL_CFLAGS += $(GNSS_CFLAGS)

include $(BUILD_EXECUTABLE)
