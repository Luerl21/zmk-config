if(CONFIG_ZMK_DISPLAY)
  target_sources_ifdef(CONFIG_CUSTOM_WIDGET_OUTPUT_STATUS app PRIVATE widgets/output_status.c)
endif()

zephyr_library()

if(CONFIG_ZMK_DISPLAY)
  if(CONFIG_CUSTOM_WIDGET_OUTPUT_STATUS)
    zephyr_library_sources(widgets/output_status_img.c)
  endif()
endif()

zephyr_library_include_directories(${ZEPHYR_LVGL_MODULE_DIR})
zephyr_library_include_directories(${ZEPHYR_BASE}/lib/gui/lvgl/)
zephyr_library_sources_ifdef(CONFIG_ZMK_DISPLAY custom_status_screen.c)
zephyr_library_sources(${ZEPHYR_BASE}/misc/empty_file.c)
zephyr_library_include_directories(${CMAKE_SOURCE_DIR}/include)
zephyr_library_include_directories(${ZEPHYR_BASE}/drivers)