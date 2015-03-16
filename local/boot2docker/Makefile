# $FreeBSD$

PORTNAME=	boot2docker
PORTVERSION=	1.5.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${DISTVERSION}/ \
		https://get.docker.com/builds/FreeBSD/x86_64/:DOCKER
DIST_SUBDIR=	${PORTNAME}-${DISTVERSION}

DISTFILES=	boot2docker.iso
EXTRACT_ONLY=
NO_WRKSUBDIR=	YES
NO_BUILD=	YES

MAINTAINER=	maciej@pasternacki.net
COMMENT=	Sets up bhyve VM running boot2docker

OPTIONS_DEFINE=	DOCKER
OPTIONS_DEFAULT=
OPTIONS_SUB=	yes
DOCKER_DESC=	Include Docker client binary
USE_RC_SUBR=	${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOCKER}
DISTFILES+=	docker-${PORTVERSION}.tgz:DOCKER
EXTRACT_ONLY+=	docker-${PORTVERSION}.tgz
.endif

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/boot2docker.iso ${STAGEDIR}${DATADIR}/boot2docker.iso
#	${INSTALL_SCRIPT} ${FILESDIR}/bootlocal.sh ${STAGEDIR}${DATADIR}/bootlocal.sh
#	${INSTALL_SCRIPT} ${FILESDIR}/boot2docker.rc ${STAGEDIR}${PREFIX}/etc/rc.d/boot2docker
.if ${PORT_OPTIONS:MDOCKER}
	${INSTALL_PROGRAM} ${WRKSRC}/usr/local/bin/docker ${STAGEDIR}${PREFIX}/bin
.endif

.include <bsd.port.mk>
