# $FreeBSD$

PORTNAME=	mx
PORTVERSION=	1.4.7.20130610
CATEGORIES=	x11-toolkits

MAINTAINER=	maciej@pasternacki.net
COMMENT=	Widget toolkit using Clutter

LICENSE=	LGPL21

BUILD_DEPENDS=	intltoolize:${PORTSDIR}/textproc/intltool
LIB_DEPENDS=	libclutter-glx-1.0.so:${PORTSDIR}/graphics/clutter

USE_GITHUB=	yes
GH_ACCOUNT=	clutter-project
GH_TAGNAME=	${GH_COMMIT}
GH_COMMIT=	24efb0c

USES=		gmake libtool pathfix pkgconfig
USE_AUTOTOOLS=	libtoolize aclocal autoheader automake autoconf
USE_GNOME=	glib20 gdkpixbuf2 intltool introspection
USE_GL=		gl
# USE_XORG=       glproto
USE_LDCONFIG=	yes
AUTOMAKE_ARGS=	--add-missing
GNU_CONFIGURE=	yes
PATHFIX_MAKEFILEIN=	Makefile.am

OPTIONS_DEFINE=		NLS
OPTIONS_SUB=		yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}

post-patch:
	${CP} ${PATCHDIR}/gtk-doc.make ${WRKSRC}/gtk-doc.make
	cd ${WRKSRC} && intltoolize --force --copy --automake

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmx-1.0.so.*.*.*
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmx-gtk-1.0.so.*.*.*

.include <bsd.port.mk>
