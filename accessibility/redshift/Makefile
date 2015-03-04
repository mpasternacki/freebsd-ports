# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	redshift
PORTVERSION=	1.10
PORTREVISION=	1
CATEGORIES=	accessibility
MASTER_SITES=	https://github.com/jonls/redshift/releases/download/v${PORTVERSION}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	feld@FreeBSD.org
COMMENT=	Adjusts the color temperature of your screen

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/geoclue-2.0.pc:${PORTSDIR}/net/geoclue

USES=		gmake pkgconfig tar:xz
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes

CONFIGURE_ARGS+=	--disable-wingdi
MAKE_ENV+=	PYTHON_VERSION=${PYTHON_VERSION}

OPTIONS_DEFINE=	GNOME GUI NLS RANDR VIDMODE
OPTIONS_DEFAULT=RANDR
OPTIONS_SUB=	yes

GNOME_DESC=	GNOME clock support
GUI_DESC=	Tray icon
RANDR_DESC=	Support RANDR for changing colors
VIDMODE_DESC=	Support VIDMODE for changing colors (NVIDIA)

NLS_USES=		gettext iconv
NLS_CONFIGURE_ON=	${ICONV_CONFIGURE_ARG} \
			--with-libintl-prefix=${LOCALBASE}
NLS_CONFIGURE_OFF=	--disable-nls

RANDR_USE=		XORG=xrandr
RANDR_CONFIGURE_ENABLE=	randr

VIDMODE_CONFIGURE_ENABLE=	vidmode

GUI_USES=		python:3.4
GUI_CONFIGURE_ENABLE=	gui
GUI_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}gobject3>0:${PORTSDIR}/devel/py3-gobject3 \
			${PYTHON_PKGNAMEPREFIX}xdg>0:${PORTSDIR}/devel/py-xdg
GUI_PLIST_SUB=		PYTHON_SUFFIX=${PYTHON_SUFFIX}

GNOME_CONFIGURE_ENABLE=	gnome-clock
GNOME_USE=		GNOME=glib20,gconf2

.include <bsd.port.mk>
