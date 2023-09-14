# This file will be configured to contain variables for CPack. These variables
# should be set in the CMake list file of the project before CPack module is
# included. The list of available CPACK_xxx variables and their associated
# documentation may be obtained using
#  cpack --help-variable-list
#
# Some variables are common to all generators (e.g. CPACK_PACKAGE_NAME)
# and some are specific to a generator
# (e.g. CPACK_NSIS_EXTRA_INSTALL_COMMANDS). The generator specific variables
# usually begin with CPACK_<GENNAME>_xxxx.


set(CPACK_BUILD_SOURCE_DIRS "Z:/AndroidStudioProjects/Skity/example/Android/app/src/main/jni;Z:/AndroidStudioProjects/Skity/example/Android/app/.cxx/cmake/debug/armeabi-v7a")
set(CPACK_CMAKE_GENERATOR "Ninja")
set(CPACK_COMPONENTS_ALL "Unspecified;headers;pkgconfig")
set(CPACK_COMPONENT_HEADERS_DEPENDS "libraries")
set(CPACK_COMPONENT_HEADERS_DESCRIPTION "C/C++ header files for use with FreeType")
set(CPACK_COMPONENT_HEADERS_DISPLAY_NAME "C/C++ Headers")
set(CPACK_COMPONENT_HEADERS_GROUP "Development")
set(CPACK_COMPONENT_LIBRARIES_DESCRIPTION "Library used to build programs which use FreeType")
set(CPACK_COMPONENT_LIBRARIES_DISPLAY_NAME "Libraries")
set(CPACK_COMPONENT_LIBRARIES_GROUP "Development")
set(CPACK_COMPONENT_UNSPECIFIED_HIDDEN "TRUE")
set(CPACK_COMPONENT_UNSPECIFIED_REQUIRED "TRUE")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_FILE "Z:/android/sdk/cmake/3.18.1/share/cmake-3.18/Templates/CPack.GenericDescription.txt")
set(CPACK_DEFAULT_PACKAGE_DESCRIPTION_SUMMARY "Project built using CMake")
set(CPACK_GENERATOR "TGZ")
set(CPACK_INSTALL_CMAKE_PROJECTS "Z:/AndroidStudioProjects/Skity/example/Android/app/.cxx/cmake/debug/armeabi-v7a;Project;ALL;/")
set(CPACK_INSTALL_PREFIX "C:/Program Files (x86)/Project")
set(CPACK_MODULE_PATH "Z:/AndroidStudioProjects/Skity/third_party/freetype/builds/cmake")
set(CPACK_NSIS_DISPLAY_NAME "Project 2.13.0")
set(CPACK_NSIS_INSTALLER_ICON_CODE "")
set(CPACK_NSIS_INSTALLER_MUI_ICON_CODE "")
set(CPACK_NSIS_INSTALL_ROOT "$PROGRAMFILES")
set(CPACK_NSIS_PACKAGE_NAME "Project 2.13.0")
set(CPACK_NSIS_UNINSTALL_NAME "Uninstall")
set(CPACK_OUTPUT_CONFIG_FILE "Z:/AndroidStudioProjects/Skity/example/Android/app/.cxx/cmake/debug/armeabi-v7a/CPackConfig.cmake")
set(CPACK_PACKAGE_DEFAULT_LOCATION "/")
set(CPACK_PACKAGE_DESCRIPTION_FILE "Z:/AndroidStudioProjects/Skity/third_party/freetype/README")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "The FreeType font rendering library.")
set(CPACK_PACKAGE_FILE_NAME "Project-2.13.0-Android")
set(CPACK_PACKAGE_INSTALL_DIRECTORY "Project 2.13.0")
set(CPACK_PACKAGE_INSTALL_REGISTRY_KEY "Project 2.13.0")
set(CPACK_PACKAGE_NAME "Project")
set(CPACK_PACKAGE_RELOCATABLE "true")
set(CPACK_PACKAGE_VENDOR "Humanity")
set(CPACK_PACKAGE_VERSION "2.13.0")
set(CPACK_PACKAGE_VERSION_MAJOR "2")
set(CPACK_PACKAGE_VERSION_MINOR "13")
set(CPACK_PACKAGE_VERSION_PATCH "0")
set(CPACK_RESOURCE_FILE_LICENSE "Z:/AndroidStudioProjects/Skity/third_party/freetype/LICENSE.TXT")
set(CPACK_RESOURCE_FILE_README "Z:/android/sdk/cmake/3.18.1/share/cmake-3.18/Templates/CPack.GenericDescription.txt")
set(CPACK_RESOURCE_FILE_WELCOME "Z:/android/sdk/cmake/3.18.1/share/cmake-3.18/Templates/CPack.GenericWelcome.txt")
set(CPACK_SET_DESTDIR "OFF")
set(CPACK_SOURCE_GENERATOR "TBZ2;TGZ;TXZ;TZ")
set(CPACK_SOURCE_OUTPUT_CONFIG_FILE "Z:/AndroidStudioProjects/Skity/example/Android/app/.cxx/cmake/debug/armeabi-v7a/CPackSourceConfig.cmake")
set(CPACK_SOURCE_RPM "OFF")
set(CPACK_SOURCE_TBZ2 "ON")
set(CPACK_SOURCE_TGZ "ON")
set(CPACK_SOURCE_TXZ "ON")
set(CPACK_SOURCE_TZ "ON")
set(CPACK_SOURCE_ZIP "OFF")
set(CPACK_SYSTEM_NAME "Android")
set(CPACK_TOPLEVEL_TAG "Android")
set(CPACK_WIX_SIZEOF_VOID_P "4")

if(NOT CPACK_PROPERTIES_FILE)
  set(CPACK_PROPERTIES_FILE "Z:/AndroidStudioProjects/Skity/example/Android/app/.cxx/cmake/debug/armeabi-v7a/CPackProperties.cmake")
endif()

if(EXISTS ${CPACK_PROPERTIES_FILE})
  include(${CPACK_PROPERTIES_FILE})
endif()
