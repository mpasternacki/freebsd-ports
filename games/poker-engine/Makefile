# Created by: ijliao
# $FreeBSD$

PORTNAME=	poker-engine
PORTVERSION=	1.3.6
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://download.gna.org/pokersource/sources/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python library that implements poker rules

LICENSE=	GPLv3 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/bin/rsync:${PORTSDIR}/net/rsync \
		${PYTHON_SITELIBDIR}/pokereval.py:${PORTSDIR}/games/py-poker-eval \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/libxslt.py:${PORTSDIR}/textproc/py-libxslt
RUN_DEPENDS=	${LOCALBASE}/bin/rsync:${PORTSDIR}/net/rsync \
		${PYTHON_SITELIBDIR}/pokereval.py:${PORTSDIR}/games/py-poker-eval \
		${PYTHON_SITELIBDIR}/libxml2.py:${PORTSDIR}/textproc/py-libxml2 \
		${PYTHON_SITELIBDIR}/libxslt.py:${PORTSDIR}/textproc/py-libxslt

USES=		gettext gmake pkgconfig python:2
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e \
		's|{datadir}/pkgconfig|(prefix)/libdata/pkgconfig|g' \
		${WRKSRC}/Makefile.in

test:
	@cd ${WRKSRC} && ${MAKE_CMD} check

.include <bsd.port.mk>
