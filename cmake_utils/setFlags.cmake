function(setFlags targetName optimization wErr wAll)
    message(STATUS "Set flags: OK")
    message("wErr = ${wErr}")
    message("wAll = ${wAll}")
    if (${wErr})
        message("compile wErr")
        set(compileOptions -Werror -pedantic-errors)
    endif()
    if (${wAll})
        message("compile wAll")
        list(APPEND compileOptions -Wall -Wpedantic -Wextra)
    endif()

    message("1. compileOptions are ${compileOptions}")
    list(APPEND compileOptions ${compileOption} -Wcast-align -Wcast-qual
            -Wduplicated-branches -Wfloat-equal -Wsign-conversion #in C this flag looks like -Wconversion
        ${ARGN})
    message("2. compileOptions are ${compileOptions}")
    target_compile_options(${targetName} PRIVATE $<$<CONFIG:Debug>:${compileOptions} -g3>)
    target_compile_options(${targetName} PRIVATE $<$<CONFIG:Release>:${compileOptions} ${optimization}>)
endfunction()