set(Boost_USE_MULTITHREADED OFF)
find_package(Boost 1.64 COMPONENTS unit_test_framework program_options system log REQUIRED)
find_package(Git QUIET)
find_package(FairRoot REQUIRED)

link_directories(${FAIRROOT_LIBRARY_DIR})
set(FAIRROOT_LIBRARIES Base FairMQ BaseMQ)

o2_define_bucket(
        NAME
        o2_sample_device

        DEPENDENCIES
        ${Boost_LOG_LIBRARY}
        ${Boost_THREAD_LIBRARY}
        ${Boost_SYSTEM_LIBRARY}
        ${Boost_PROGRAM_OPTIONS_LIBRARY}
        ${Boost_LOG_DEBUG}
        ${FAIRROOT_LIBRARIES}
        pthread

        SYSTEMINCLUDE_DIRECTORIES
        ${Boost_INCLUDE_DIRS}
        ${FAIRROOT_INCLUDE_DIR}
        ${FAIRROOT_INCLUDE_DIR}/fairmq
)
