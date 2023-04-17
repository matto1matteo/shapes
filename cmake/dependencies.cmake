function(dependency repository tag)
    include(FetchContent)
    message(STATUS "Fetching: ${repository} @ ${tag}")

    if(tag STREQUAL "")
        message(FATAL_ERROR "Invalid tag for ${repository}")
    endif()
    
    FetchContent_Declare(
        Catch2
        GIT_REPOSITORY "${repository}"
        GIT_TAG "${tag}"
        OVERRIDE_FIND_PACKAGE
    )
endfunction()

