BUILD_SYSTEM_DIR := buildsystem
include $(BUILD_SYSTEM_DIR)/top.mk

include build.mk
include Ditto/build.mk
include Postform/libpostform/build.mk
