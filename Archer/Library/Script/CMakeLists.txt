project(ScriptLib)


add_library(ScriptLib STATIC IMPORTED GLOBAL)

set_target_properties(ScriptLib PROPERTIES
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/Lib/nethost.lib"
    INTERFACE_INCLUDE_DIRECTORIES "${CMAKE_CURRENT_SOURCE_DIR}"
)
