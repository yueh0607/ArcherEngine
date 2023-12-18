

project(ArcherEditor)


aux_source_directory(. EDITOR_SRC)
add_executable(ArcherEditor ${EDITOR_SRC})


target_link_libraries(ArcherEditor PRIVATE ScriptLib)

