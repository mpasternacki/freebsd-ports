# $FreeBSD$

PORTNAME=	jitsi-devel
PORTVERSION=	2.8.${GH_TAGNAME}
CATEGORIES=	net-im
MASTER_SITES=	GH \
	https://codeload.github.com/jitsi/libjitsi/tar.gz/${LIBJITSI_TAG}?dummy=/:libjitsi \
	https://dl.dropboxusercontent.com/u/1067829/:dropbox

MAINTAINER=	maciej@pasternacki.net
COMMENT=	Development version of Jitsi IM

DIST_SUBDIR=	${PORTNAME}
DISTFILES=	jitsi-${GH_TAGNAME}.tar.gz \
	libjitsi-${LIBJITSI_TAG}.tar.gz:libjitsi \
	ice4j-r${ICE4J_REV}.tar.gz:dropbox
PATCH_WRKSRC=	${WRKDIR}

BUILD_DEPENDS=	\
	unbound>=1.5.0:${PORTSDIR}/dns/unbound \
	v4l_compat>=1.0.20120501:${PORTSDIR}/multimedia/v4l_compat

USE_GITHUB=	yes
GH_ACCOUNT=	jitsi
GH_PROJECT=	jitsi
GH_TAGNAME=	5439

LIBJITSI_TAG=	604
ICE4J_REV=	497

USE_JAVA=	yes
JAVA_VERSION=	1.8

USE_ANT=	yes
USE_GCC=	yes

post-extract:
	cp ${FILESDIR}/local.properties ${WRKDIR}/jitsi-${GH_TAGNAME}
	cp ${FILESDIR}/local.properties ${WRKDIR}/libjitsi-${LIBJITSI_TAG}

pre-patch:
	ln -sv jitsi-${GH_TAGNAME} ${WRKDIR}/jitsi
	ln -sv libjitsi-${LIBJITSI_TAG} ${WRKDIR}/libjitsi

${WRKDIR}/bin/gcc:
	mkdir ${WRKDIR}/bin
	ln -s `which ${CC}` ${WRKDIR}/bin/gcc
	ln -s `which ${CXX}` ${WRKDIR}/bin/g++

LIBJITSI_NATIVE = jawtrenderer g722 screencapture speex video4linux2 pulseaudio portaudio
# LIBJITSI_NATIVE += opus ffmpeg
JITSI_NATIVE = hid hwaddressretriever globalshortcut unbound
#TODO JITSI_NATIVE += sysactivity
#TODO LIBJITSI_NATIVE += libvpx sctp

native.subdir := freebsd${ARCH:S/i386//:S/amd/-/:S/x86_/-/}
jitsi.sodir = ${WRKDIR}/jitsi-${GH_TAGNAME}/lib/native/${native.subdir}
libjitsi.sodir = ${WRKDIR}/libjitsi-${LIBJITSI_TAG}/lib/native/${native.subdir}
libjitsi.jawtrenderer.soname = libjnawtrenderer.so

.for .lib. in ${LIBJITSI_NATIVE}
libjitsi.${.lib.}.soname ?= libjn${.lib.}.so
libjitsi.jni.so += ${libjitsi.sodir}/${libjitsi.${.lib.}.soname}
jitsi.jni.so += ${jitsi.sodir}/${libjitsi.${.lib.}.soname}

${libjitsi.sodir}/${libjitsi.${.lib.}.soname}: ${WRKDIR}/bin/gcc
	cd ${WRKDIR}/libjitsi-${LIBJITSI_TAG} && ${SETENV} ${MAKE_ENV} PATH=${WRKDIR}/bin:$$PATH ${ANT} ${.lib.}
	touch ${libjitsi.sodir}/${libjitsi.${.lib.}.soname}

${jitsi.sodir}/${libjitsi.${.lib.}.soname}: ${libjitsi.sodir}/${libjitsi.${.lib.}.soname}
	cp -v ${libjitsi.sodir}/${libjitsi.${.lib.}.soname} ${jitsi.sodir}/
.endfor

.for .lib. in ${JITSI_NATIVE}
jitsi.${.lib.}.soname ?= libjn${.lib.}.so
jitsi.jni.so += ${jitsi.sodir}/${jitsi.${.lib.}.soname}

${jitsi.sodir}/${jitsi.${.lib.}.soname}: ${WRKDIR}/bin/gcc
	cd ${BUILD_WRKSRC} && ${SETENV} ${MAKE_ENV} PATH=${WRKDIR}/bin:$$PATH ${ANT} ${.lib.}
	touch ${jitsi.sodir}/${jitsi.${.lib.}.soname}
.endfor

${WRKDIR}/ice4j/ice4j.jar:
	( cd ${WRKDIR}/ice4j && ${SETENV} ${MAKE_ENV} ${ANT} ; )

do-build: ${WRKDIR}/ice4j/ice4j.jar ${jitsi.jni.so}
	install ${WRKDIR}/ice4j/ice4j.jar ${WRKSRC}/lib/installer-exclude

.include <bsd.port.mk>
