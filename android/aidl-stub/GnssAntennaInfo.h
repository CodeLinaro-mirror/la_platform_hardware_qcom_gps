/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/
#ifndef ANDROID_HARDWARE_GNSS_AIDL_GNSSANTENNAINFO_H
#define ANDROID_HARDWARE_GNSS_AIDL_GNSSANTENNAINFO_H
#include <aidl/android/hardware/gnss/IGnssAntennaInfoCallback.h>
#include <aidl/android/hardware/gnss/BnGnssAntennaInfo.h>

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {
using ::aidl::android::hardware::gnss::BnGnssAntennaInfo;
using ::aidl::android::hardware::gnss::IGnssAntennaInfoCallback;
using ::std::shared_ptr;
using ::ndk::ScopedAStatus;
class GnssAntennaInfo : public BnGnssAntennaInfo {
public:
    GnssAntennaInfo();

    virtual ScopedAStatus setCallback(const shared_ptr<IGnssAntennaInfoCallback>& callback)
            override;
    virtual ScopedAStatus close() override;
private:
    shared_ptr<IGnssAntennaInfoCallback> mGnssAntennaInfoCbIface = nullptr;
    AIBinder_DeathRecipient *mDeathRecipient = nullptr;
};
}
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
#endif //ANDROID_HARDWARE_GNSS_AIDL_GNSSANTENNAINFO_H
