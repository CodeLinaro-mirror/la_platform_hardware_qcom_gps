/*
Copyright (c) Qualcomm Technologies, Inc. and/or its subsidiaries.
SPDX-License-Identifier: BSD-3-Clause-Clear
*/
#ifndef ANDROID_HARDWARE_GNSS_AIDL_GNSSGEOFENCE_H
#define ANDROID_HARDWARE_GNSS_AIDL_GNSSGEOFENCE_H
#include <aidl/android/hardware/gnss/IGnssGeofenceCallback.h>
#include <aidl/android/hardware/gnss/BnGnssGeofence.h>

namespace android {
namespace hardware {
namespace gnss {
namespace aidl {
namespace implementation {
using ::aidl::android::hardware::gnss::IGnssGeofenceCallback;
using ::aidl::android::hardware::gnss::BnGnssGeofence;
using ::std::shared_ptr;
using ::ndk::ScopedAStatus;
class GnssGeofence : public BnGnssGeofence {
public:
  GnssGeofence();
  virtual ~GnssGeofence();

    ScopedAStatus setCallback(const shared_ptr<IGnssGeofenceCallback>& callback) override;
    ScopedAStatus addGeofence(int32_t geofenceId, double latitudeDegrees, double longitudeDegrees,
            double radiusMeters, int32_t lastTransition, int32_t monitorTransitions,
            int32_t notificationResponsivenessMs, int32_t unknownTimerMs) override;
    ScopedAStatus pauseGeofence(int32_t geofenceId) override;
    ScopedAStatus resumeGeofence(int32_t geofenceId, int32_t monitorTransitions) override;
    ScopedAStatus removeGeofence(int32_t geofenceId) override;
private:
    shared_ptr<IGnssGeofenceCallback> mGnssGeofencingCbIface = nullptr;
    AIBinder_DeathRecipient *mDeathRecipient = nullptr;
};
}  // namespace implementation
}  // namespace aidl
}  // namespace gnss
}  // namespace hardware
}  // namespace android
#endif //ANDROID_HARDWARE_GNSS_AIDL_GNSSGEOFENCE_H
