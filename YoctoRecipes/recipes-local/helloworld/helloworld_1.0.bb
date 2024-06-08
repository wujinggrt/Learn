DESCRIPTION = "A hello program!"
PRIORITY = "optional"
SECTION = "examples"

LICENSE = "GPLv2"
LIC_FILES_CHKSUM = "file://${COMMON_LICENSE_DIR}/GPL-2.0-or-later;md5=fed54355545ffd980b814dab4a3b312c"

SRC_URI = "file://helloworld.c"

S = "${WORKDIR}"

do_compile() {
		${CC} ${CFLAGS} ${LDFLAGS} helloworld.c -o helloworld
}

do_install() {
		install -d ${D}${bindir}
		install -m 0755 helloworld ${D}${bindir}
}
