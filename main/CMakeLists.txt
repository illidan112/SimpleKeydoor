file(GLOB SRCES "*.c" )
idf_component_register(SRCS ${SRCES}
                    INCLUDE_DIRS "inc")
