if(WITH_CHANNEL_GFXREDIR)
  set(OPTION_DEFAULT ON)
  set(OPTION_CLIENT_DEFAULT OFF)
  set(OPTION_SERVER_DEFAULT ON)

  define_channel_options(
    NAME
    "gfxredir"
    TYPE
    "dynamic"
    DESCRIPTION
    "Graphics Redirection Virtual Channel Extension"
    SPECIFICATIONS
    "[MS-RDPXXXX]"
    DEFAULT
    ${OPTION_DEFAULT}
    CLIENT_DEFAULT
    ${OPTION_CLIENT_DEFAULT}
    SERVER_DEFAULT
    ${OPTION_SERVER_DEFAULT}
  )
endif()
