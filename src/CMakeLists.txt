file(GLOB_RECURSE SOURCES "*.c" "*.h")
add_library(TacticalElements SHARED ${SOURCES})
target_include_directories(TacticalElements PRIVATE "${CMAKE_SOURCE_DIR}/include")
set_target_properties(TacticalElements PROPERTIES OUTPUT_NAME TacticalElements)