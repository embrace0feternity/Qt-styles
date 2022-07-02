function(includeLibsNDirs targetName libs includeDirs)
    message(STATUS "Link libraries and include directories:")
    if (${libs})
        target_link_libraries(${targetName} PRIVATE ${${libs}})
    endif()
    if (${includeDirs})
        target_include_directories(${targetName} PRIVATE ${${includeDirs}})
    endif()

    if (debugInfo)
        debugPrint("\tYou are link next libs:")
        foreach(arg IN LISTS ${libs})
            debugPrint("\t\t${arg}")
        endforeach()
        debugPrint("\tYou are include next directories:")
        foreach(arg IN LISTS ${includeDirs})
            debugPrint("\t\t${arg}")
        endforeach()
        debugPrint("\tStatus: OK")
    else()
        message("\tStatus: OK")
    endif()

    set_target_properties(${targetName} PROPERTIES
        MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
        MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
        MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    )


endfunction()
