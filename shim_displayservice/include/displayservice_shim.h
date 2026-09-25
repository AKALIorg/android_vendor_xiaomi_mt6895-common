// Shim for android.frameworks.displayservice@1.0 (removed in A17).
// libmtkcam_hal_android_app_cbadaptor.so links 15 symbols from it:
// IEventCallback HIDL boilerplate + IDisplayService::getService.
// Display-hint events are non-essential for camera bringup: getService
// returns null (callers null-check) and callbacks return empty data.
#pragma once

#include <android/hidl/base/1.0/IBase.h>

namespace android {
namespace frameworks {
namespace displayservice {
namespace V1_0 {

using ::android::hardware::hidl_handle;
using ::android::hardware::hidl_string;
using ::android::hardware::hidl_vec;
using ::android::hardware::Return;
using ::android::hardware::Void;
using ::android::hidl::base::V1_0::DebugInfo;
using ::android::hidl::base::V1_0::IBase;
using ::android::sp;

struct IEventCallback : public IBase {
    Return<void> interfaceChain(IBase::interfaceChain_cb _hidl_cb) override;
    Return<void> debug(const hidl_handle& fd,
                       const hidl_vec<hidl_string>& options) override;
    Return<void> interfaceDescriptor(IBase::interfaceDescriptor_cb _hidl_cb) override;
    Return<void> ping() override;
    Return<void> getHashChain(IBase::getHashChain_cb _hidl_cb) override;
    Return<void> setHALInstrumentation() override;
    Return<bool> linkToDeath(const sp<::android::hardware::hidl_death_recipient>& recipient,
                             uint64_t cookie) override;
    Return<void> getDebugInfo(IBase::getDebugInfo_cb _hidl_cb) override;
    Return<void> notifySyspropsChanged() override;
    Return<bool> unlinkToDeath(const sp<::android::hardware::hidl_death_recipient>& recipient) override;
};

struct IDisplayService : public IBase {
    static sp<IDisplayService> getService(const std::string& serviceName = "default",
                                          bool getStub = false);
};

struct IDisplayEventReceiver : public IBase {};

}  // namespace V1_0
}  // namespace displayservice
}  // namespace frameworks
}  // namespace android
