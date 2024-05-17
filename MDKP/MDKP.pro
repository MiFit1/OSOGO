TEMPLATE = subdirs
SUBDIRS = \
    MDKP \
    Tests
MDKP.subdir = src/MDKP
Tests.subdir = src/Tests
Tests.depends = MDKP


