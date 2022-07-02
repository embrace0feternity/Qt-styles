function(generateLibrary targetName)
    message("")
    message("-- Start generate target ${targetName} (static library)")

    set(prefix arg)
    set(noValue wErr wAll)
    set(oneValue optimization)
    set(multiValue srcs includeDirs libs externalFlags)

    cmake_parse_arguments(${prefix}
        "${noValue}"
        "${oneValue}"
        "${multiValue}"
        ${ARGN})

    debugPrint("-- Get all variables:")
    foreach(arg IN LISTS noValue oneValue multiValue)
        debugPrint("\t${arg} = ${${prefix}_${arg}}")
    endforeach()

    validateVariables(${prefix}_srcs)
    add_library(${targetName} ${${prefix}_srcs})

    includeLibsNDirs(${targetName} ${prefix}_libs ${prefix}_includeDirs)

    if (NOT ${prefix}_optimization)
        set(${prefix}_optimization -O2)
    endif()

    setFlags(${targetName} ${${prefix}_optimization} ${${prefix}_wErr} ${${prefix}_wAll} ${${prefix}_externalFlags})

    get_target_property(compilerFlags ${targetName} COMPILE_OPTIONS)
    debugPrint("\tCompilerFlags: ${compilerFlags}")
endfunction()
