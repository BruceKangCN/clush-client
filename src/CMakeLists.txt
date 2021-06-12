include_directories(ui util)

aux_source_directory(ui FORMS)
aux_source_directory(util UTILS)

add_executable(clush
    main.cpp
    ${FORMS}
    ${UTILS}
)

target_link_libraries(clush PRIVATE Qt6::Widgets Qt6::Network)
