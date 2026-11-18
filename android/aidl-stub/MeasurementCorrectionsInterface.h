/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/
#ifndef ANDROID_HARDWARE_GNSS_AIDL_GNSSMEASUREMENTCORRECTIONS_H
#define ANDROID_HARDWARE_GNSS_AIDL_GNSSMEASUREMENTCORRECTIONS_H

#include <aidl/android/hardware/gnss/measurement_corrections/IMeasurementCorrectionsCallback.h>
#include <aidl/android/hardware/gnss/measurement_corrections/MeasurementCorrections.h>
#include <aidl/android/hardware/gnss/measurement_corrections/BnMeasurementCorrectionsInterface.h>

namespace android {
namespace hardware {
namespace gnss {
namespace measurement_corrections {
namespace aidl {
namespace implementation {
using ::aidl::android::hardware::gnss::measurement_corrections::BnMeasurementCorrectionsInterface;
using ::aidl::android::hardware::gnss::measurement_corrections::IMeasurementCorrectionsCallback;
using ::aidl::android::hardware::gnss::measurement_corrections::MeasurementCorrections;
using ::std::shared_ptr;
using ::ndk::ScopedAStatus;
class MeasurementCorrectionsInterface : public BnMeasurementCorrectionsInterface {
public:
MeasurementCorrectionsInterface();
virtual ~MeasurementCorrectionsInterface();

ScopedAStatus setCorrections(const MeasurementCorrections& in_corrections) override;
ScopedAStatus setCallback(const shared_ptr<IMeasurementCorrectionsCallback>& in_callback) override;

private:
shared_ptr<IMeasurementCorrectionsCallback> mMeasurementCorrectionsCbIface = nullptr;
AIBinder_DeathRecipient *mDeathRecipient = nullptr;
};
}
}  // namespace aidl
}  // namespace measurement_corrections
}  // namespace gnss
}  // namespace hardware
}  // namespace android
#endif //ANDROID_HARDWARE_GNSS_AIDL_GNSSMEASUREMENTCORRECTIONS_H
