# Created by: Grzegorz Blach <gblach@FreeBSD.org>
# $FreeBSD$

PORTNAME=	e17-modules
PORTVERSION=	20130510
PORTREVISION=	2
CATEGORIES=	x11-wm enlightenment
MASTER_SITES=	# Empty
DISTFILES=	# Empty

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Meta-port for Enlightenment modules

NO_BUILD=	yes

MODULES=	alarm cpu deskshow everything-places \
		everything-websearch forecasts mem mpdule net penguins \
		places rmb tclock wlan

.include "../enlightenment/Makefile.plist"

EVERYTHING_WEBSEARCH_PATH=	evry-websearch

.for M in ${MODULES}
OPTIONS_DEFINE+=	${M:tu:S,-,_,g}
OPTIONS_DEFAULT+=	${M:tu:S,-,_,g}
${M:tu:S,-,_,g}_DESC=	Install ${M} module
.endfor

.include <bsd.port.options.mk>

.for M in ${MODULES}
. if !defined(${M:tu:S,-,_,g}_PATH)
${M:tu:S,-,_,g}_PATH=	${M}
. endif
. if ${PORT_OPTIONS:M${M:tu:S,-,_,g}}
RUN_DEPENDS+=	${LOCALBASE}/lib/enlightenment/modules/${${M:tu:S,-,_,g}_PATH}/${ENLIGHTENMENT_ARCH}/module.so:${PORTSDIR}/x11-wm/e-module-${M}
. endif
.endfor

do-install:	# empty

.include <bsd.port.mk>
