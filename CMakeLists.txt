# Standard CMake boilerplate. ParaView's `find_package` requires at least 3.8.
cmake_minimum_required(VERSION 3.8)
project(sharedlibrary)
# These two lines are required in order to set up installation directories
# (which also control build directory locations) and enable shared builds
# (CMake's default is for a static build).
include(GNUInstallDirs)
set(BUILD_SHARED_LIBS ON)
# Find ParaView. This will bring in ParaView's CMake API and imported targets.
find_package(ParaView REQUIRED)
# Scan the plugin file in order to set up internal data structures for building
# plugins.
paraview_plugin_scan(
  # The `paraview.plugin` file describing the plugin.
  PLUGIN_FILES "${CMAKE_CURRENT_SOURCE_DIR}/Plugin/paraview.plugin"
  # A result variable for the (enabled) plugins found during the scan.
  PROVIDES_PLUGINS plugins
  # Enable plugins during this scan by default.
  ENABLE_BY_DEFAULT ON)
# Build the plugins discovered during the scan.
paraview_plugin_build(
  PLUGINS ${plugins})

add_executable(plugin_load main.cxx)
target_link_libraries (plugin_load PRIVATE ParaView::pqApplicationComponents)
