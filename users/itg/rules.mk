SRC += itg.c

ifneq ("$(wildcard $(USER_PATH)/secrets.c)","")
  SRC += secrets.c
endif

ifeq ($(strip $(NO_SECRETS)), yes)
    OPT_DEFS += -DNO_SECRETS
endif

STENO_ENABLE = yes
VIRTSER_ENABLE = yes
FORCE_NKRO = yes
MOUSEKEY_ENABLE = no