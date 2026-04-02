/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/

#ifndef ANDROID_HARDWARE_GNSS_AIDL_GNSSMEASUREMENTINTERFACE_H
#define ANDROID_HARDWARE_GNSS_AIDL_GNSSMEASUREMENTINTERFACE_H
#include <aidl/android/hardware/gnss/BnGnssMeasurementInterface.h>
#include <aidl/android/hardware/gnss/BnGnssMeasurementCallback.h>

using aidl::android::hardware::gnss::ElapsedRealtime;
using aidl::android::hardware::gnss::GnssClock;
using aidl::android::hardware::gnss::GnssData;
using aidl::android::hardware::gnss::GnssMeasurement;
using aidl::android::hardware::gnss::GnssSignalType;
using aidl::android::hardware::gnss::GnssConstellationType;

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {

using ::aidl::android::hardware::gnss::BnGnssMeasurementInterface;
using ::aidl::android::hardware::gnss::IGnssMeasurementCallback;
using ::aidl::android::hardware::gnss::IGnssMeasurementInterface;
using ::std::shared_ptr;
using ::ndk::ScopedAStatus;

struct GnssMeasurementInterface : public BnGnssMeasurementInterface {
public:
    GnssMeasurementInterface();
    ~GnssMeasurementInterface() {}
    ScopedAStatus setCallback(const shared_ptr<IGnssMeasurementCallback>& callback,
            bool enableFullTracking, bool enableCorrVecOutputs) override;
    ScopedAStatus close() override;

    ScopedAStatus setCallbackWithOptions(const shared_ptr<IGnssMeasurementCallback>& callback,
            const IGnssMeasurementInterface::Options& options) override;

private:
    shared_ptr<IGnssMeasurementCallback> mGnssMeasurementCbIface = nullptr;
    // Synchronization lock for mGnssMeasurementCbIface
    AIBinder_DeathRecipient* mDeathRecipient;

    static void gnssMeasurementDied(void* cookie);
};

}  // namespace implementation
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
#endif //ANDROID_HARDWARE_GNSS_AIDL_GNSSMEASUREMENTINTERFACE_H
