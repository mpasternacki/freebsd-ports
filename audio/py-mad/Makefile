# Created by: Hye-Shik Chang
# $FreeBSD$

PORTNAME=	mad
PORTVERSION=	0.8
DISTVERSIONPREFIX=	version/
CATEGORIES=	audio python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python module that provides the MPEG Audio Decoder interface

LICENSE=	LGPL20 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libmad.so:${PORTSDIR}/audio/libmad

USE_GITHUB=	yes
GH_ACCOUNT=	jaqx0r
GH_PROJECT=	pymad

USES=		python:2
USE_PYTHON=	distutils autoplist pythonprefix

do-configure:
	@cd ${WRKSRC} && ${MAKE_ENV} ${PYTHON_CMD} config_unix.py \
		--prefix ${LOCALBASE}

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/madmodule.so

.include <bsd.port.mk>
