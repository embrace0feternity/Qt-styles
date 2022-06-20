function(generateExecution targetName)
    set(debugInfo 1)
    message("-- Start generate target execution")

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
    add_executable(${targetName} ${${prefix}_srcs})

    includeLibsNDirs(${targetName} ${prefix}_libs ${prefix}_includeDirs)

    if (NOT ${prefix}_optimization)
        set(${prefix}_optimization -O2)
    endif()

    setFlags(${targetName} ${${prefix}_optimization} ${${prefix}_wErr} ${${prefix}_wAll} ${${prefix}_externalFlags})

    unset(debugInfo)
endfunction()
