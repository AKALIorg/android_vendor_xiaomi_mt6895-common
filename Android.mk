#
# Automatically generated file. DO NOT MODIFY
#

LOCAL_PATH := $(call my-dir)

# MTK prebuilt framework jars as make prebuilts (NOT bp dex_import):
# A14-era bytecode fails A17 dex2oat verification, and dex_import has no
# dexpreopt toggle in this soong version. BUILD_PREBUILT honors
# LOCAL_DEX_PREOPT := false. Jars still install to system(_ext)/framework
# for ImsService etc. (runtime uses-library, unaffected).
# NOTE: setup-makefiles.py regenerates this file + Android.bp - re-apply on re-extract.
define mtk-framework-jar
include $(CLEAR_VARS)
LOCAL_MODULE := $(1)
LOCAL_MODULE_OWNER := xiaomi
LOCAL_SRC_FILES := proprietary/$(2)/framework/$(1).jar
LOCAL_MODULE_CLASS := JAVA_LIBRARIES
LOCAL_MODULE_SUFFIX := .jar
LOCAL_MODULE_PATH := $(3)/framework
LOCAL_DEX_PREOPT := false
LOCAL_ENFORCE_USES_LIBRARIES := false
include $(BUILD_PREBUILT)
endef

$(eval $(call mtk-framework-jar,mediatek-telecom-common,system,$(TARGET_OUT)))
$(eval $(call mtk-framework-jar,mediatek-telephony-base,system,$(TARGET_OUT)))
$(eval $(call mtk-framework-jar,mediatek-telephony-common,system,$(TARGET_OUT)))
$(eval $(call mtk-framework-jar,mediatek-ims-extension-plugin,system_ext,$(TARGET_OUT_SYSTEM_EXT)))
