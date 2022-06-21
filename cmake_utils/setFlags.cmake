function(setFlags targetName optimization wErr wAll)
    message(STATUS "Set flags: OK")

    if (${wErr})
        set(compileOptions -Werror -pedantic-errors)
    endif()
    if (${wAll})
        list(APPEND compileOptions -Wall -Wpedantic -Wextra)
    endif()

    list(APPEND compileOptions ${compileOption} -Wcast-align -Wcast-qual
            -Wduplicated-branches -Wfloat-equal -Wsign-conversion #in C this flag looks like -Wconversion
        ${ARGN})

    target_compile_options(${targetName} PRIVATE $<$<CONFIG:Debug>:${compileOptions} -g3>)
    target_compile_options(${targetName} PRIVATE $<$<CONFIG:Release>:${compileOptions} ${optimization}>)
endfunction()
