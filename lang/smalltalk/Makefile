# Created by: gpalmer
# $FreeBSD$

PORTNAME=	smalltalk
PORTVERSION=	3.2.5
PORTREVISION=	6
CATEGORIES=	lang
MASTER_SITES=	GNU

MAINTAINER=	johans@FreeBSD.org
COMMENT=	GNU Smalltalk

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip \
		gawk:${PORTSDIR}/lang/gawk
LIB_DEPENDS=	libgdbm.so:${PORTSDIR}/databases/gdbm \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo \
		libcairo.so:${PORTSDIR}/graphics/cairo

OPTIONS_DEFINE=	TK PGSQL SDL
OPTIONS_DEFAULT=TK PGSQL SDL
OPTIONS_SUB=	yes
TK_USES=	tk:84
TK_CONFIGURE_WITH=tcl=${LOCALBASE}/lib/tcl8.4 tk=${LOCALBASE}/lib/tk8.4
PGSQL_USES=	pgsql
SDL_USE=	SDL=image,mixer,sdl,sound,ttf

USES=		gmake iconv libtool makeinfo pkgconfig shebangfix tar:xz
USE_GNOME=	pango
USE_SQLITE=	yes
USE_XORG=	ice xi xmu
USE_GL=		gl glut
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_prog_EMACS=no ac_cv_prog_AWK=gawk
CONFIGURE_ARGS=	--enable-generational-gc=no \
		--enable-gtk=no \
		--localstatedir="${PREFIX}/var" \
		--with-emacs=no \
		--with-gmp=no
USE_LDCONFIG=	yes
SHEBANG_LANG=	sed
sed_OLD_CMD=	/bin/sed
sed_CMD=	${SED}
SHEBANG_FILES=	packages/vfs/deb packages/vfs/mailfs \
		examples/pepe.sed examples/xml.sed
PLIST_SUB=	VERSION="${PORTVERSION}"
PORTDATA=	*

INFO=		gst gst-base gst-libs

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

BROKEN_sparc64=	Fails to install on sparc64

post-patch:
	@${REINPLACE_CMD} -e 's/ia64-\*-\* /&|amd64-*-* /' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's/lrintl (truncl/lroundl (truncl/' \
		${WRKSRC}/libgst/prims.def \
		${WRKSRC}/libgst/prims.inl
	@${REINPLACE_CMD} -e '/^ac_include/s/\\$$/#include <wctype.h> \\/' \
		${WRKSRC}/snprintfv/configure

post-build:
	@${SED} -e 's|@bindir@|${PREFIX}/bin|g' \
		${WRKSRC}/gst-mode.el.in > ${WRKSRC}/gst-mode.el

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/gtk
	@${INSTALL_DATA} ${WRKSRC}/*.el ${STAGEDIR}${PREFIX}/share/emacs/site-lisp
	@ls -1 ${STAGEDIR}${PREFIX}/bin/gst* |grep -v config|xargs ${STRIP_CMD}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/smalltalk/*.so
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libgst.so

.include <bsd.port.mk>
