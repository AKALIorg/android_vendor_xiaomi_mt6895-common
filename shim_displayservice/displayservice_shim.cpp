// See displayservice_shim.h
#include "displayservice_shim.h"

namespace android {
namespace frameworks {
namespace displayservice {
namespace V1_0 {

Return<void> IEventCallback::interfaceChain(IBase::interfaceChain_cb _hidl_cb) {
    hidl_vec<hidl_string> chain;
    chain.resize(2);
    chain[0] = "android.frameworks.displayservice@1.0::IEventCallback";
    chain[1] = "android.hidl.base@1.0::IBase";
    _hidl_cb(chain);
    return Void();
}

Return<void> IEventCallback::debug(const hidl_handle& /*fd*/,
                                   const hidl_vec<hidl_string>& /*options*/) {
    return Void();
}

Return<void> IEventCallback::interfaceDescriptor(IBase::interfaceDescriptor_cb _hidl_cb) {
    _hidl_cb("android.frameworks.displayservice@1.0::IEventCallback");
    return Void();
}

Return<void> IEventCallback::ping() {
    return Void();
}

Return<void> IEventCallback::getHashChain(IBase::getHashChain_cb _hidl_cb) {
    ::android::hardware::hidl_array<uint8_t, 32> hashchain;
    for (size_t i = 0; i < 32; i++) hashchain[i] = 0;
    hidl_vec< ::android::hardware::hidl_array<uint8_t, 32>> out;
    out.resize(1);
    out[0] = hashchain;
    _hidl_cb(out);
    return Void();
}

Return<void> IEventCallback::setHALInstrumentation() {
    return Void();
}

Return<bool> IEventCallback::linkToDeath(
    const sp<::android::hardware::hidl_death_recipient>& /*recipient*/,
    uint64_t /*cookie*/) {
    return false;
}

Return<void> IEventCallback::getDebugInfo(IBase::getDebugInfo_cb _hidl_cb) {
    DebugInfo info = {};
    info.pid = -1;
    info.ptr = 0;
    info.arch = DebugInfo::Architecture::IS_64BIT;
    _hidl_cb(info);
    return Void();
}

Return<void> IEventCallback::notifySyspropsChanged() {
    return Void();
}

Return<bool> IEventCallback::unlinkToDeath(
    const sp<::android::hardware::hidl_death_recipient>& /*recipient*/) {
    return false;
}

// No display service on this device - callers null-check the result.
sp<IDisplayService> IDisplayService::getService(const std::string& /*serviceName*/,
                                                bool /*getStub*/) {
    return nullptr;
}

// Force emission of sp<> destructors referenced by prebuilt blobs.
}  // namespace V1_0
}  // namespace displayservice
}  // namespace frameworks
}  // namespace android

namespace android {
template class sp<frameworks::displayservice::V1_0::IEventCallback>;
template class sp<frameworks::displayservice::V1_0::IDisplayService>;
template class sp<frameworks::displayservice::V1_0::IDisplayEventReceiver>;
}  // namespace android
