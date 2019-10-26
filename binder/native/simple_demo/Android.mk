LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE    := Server
LOCAL_SRC_FILES := IDemoService.cpp DemoServer.cpp
LOCAL_SHARED_LIBRARIES := libcutils libutils libbinder
LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)

include $(CLEAR_VARS)
LOCAL_MODULE    := Client
LOCAL_SRC_FILES := IDemoService.cpp DemoClient.cpp
LOCAL_SHARED_LIBRARIES := libcutils libutils libbinder
LOCAL_MODULE_TAGS := optional
include $(BUILD_EXECUTABLE)
