require recipes-core/images/core-image-minimal.bb
EXTRA_IMAGE_FEATURES += "ssh-server-openssh"
IMAGE_INSTALL += "helloworld strace"
