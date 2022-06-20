function(debugPrint msg)
    if(debugInfo)
        message("${msg}")
    endif()
endfunction()

function(validateVariables srcs)
    debugPrint("-- Validate variables:")
    if (NOT ${srcs})
        message(FATAL_ERROR "No srcs have been provide!")
    endif()
    message("\tStatus: OK")

endfunction()
